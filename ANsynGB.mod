COMMENT
Combined AMPA / NMDA synapse.
With calcium-driven AMPA plasticity using Graupner & Brunel model (2012).
BPG 6-3-15
BPG 5-5-15: Code to track peak calcium added
AMPAR
-----
Two state kinetic scheme synapse described by rise time tau1,
and decay time constant tau2. The normalized peak condunductance is 1.
Decay time MUST be greater than rise time.

The solution of A->G->bath with rate constants 1/tau1 and 1/tau2 is
 A = a*exp(-t/tau1) and
 G = a*tau2/(tau2-tau1)*(-exp(-t/tau1) + exp(-t/tau2))
	where tau1 < tau2

If tau2-tau1 -> 0 then we have a alphasynapse.
and if tau1 -> 0 then we have just single exponential decay.

The factor is evaluated in the initial block such that an event of weight 1 generates a
peak conductance of 1.

Because the solution is a sum of exponentials, the coupled equations can be solved as a 
pair of independent equations by the more efficient cnexp method.

NMDAR
-----
Similar to AMPA, but with voltage / magnesium dependent term.

The weight of this component is set directly via parameter gNmax, rather than as
a connection weight (as it is assumed that this weight is not plastic).

The fraction of NMDA current carried by calcium is specified as a parameter.

Plasticity
----------
NMDA calcium current is used to calculate a calcium concentration in a small volume
that assumes the NMDA and AMPARs are colocalised. The "volume" is specified by
a parameter, as is the decay time constant that models calcium clearance by diffusion
and pumps.

This calcium concentration is the driver of AMPAR plasticity. In this case the plasticity
model is that of Graupner & Brunel, PNAS, 2012.

AMPA strength can range from fraction wmin (specified as a parameter) to the total weight
specified for the NetCon.
ENDCOMMENT

NEURON {
	POINT_PROCESS ANsynGB
	RANGE tau1, tau2, tauN1, tauN2, e, i, iN, ca, wmin
	RANGE gNmax, tcon, tcoff, enmda, mgconc, eta, gamma, wN, fCa
	RANGE g, gN, vol, cainf, taurca, bcap
	RANGE p, p0, R, camax, capksum, capkn
	GLOBAL tau, ps, gp, gd, thp, thd, tp, td
	NONSPECIFIC_CURRENT i
	NONSPECIFIC_CURRENT iN
}

UNITS {
	(nA) = (nanoamp)
	(mV) = (millivolt)
	(uS) = (microsiemens)
	(pS) = (picosiemens)
	(umho) = (micromho)
	(mM) = (milli/liter)
	(uM) = (micro/liter)
	FARADAY = (faraday) (coulomb)
}

PARAMETER {
	tau1=.5 (ms) <1e-9,1e9>
	tau2 = 3 (ms) <1e-9,1e9>
	e=0	(mV)
	wmin = 0.2 (1)	: minimum AMPA weight as fraction of weight
	
	fCa = 0.1	: fraction of current is calcium
	tcon = 3 (ms)
	tcoff = 150 (ms)
	enmda = 0 	(mV)
	gNmax = 1	(uS)
	mgconc = 1	(mM)	: magnesium concentration
	eta = 0.33	(/mM)
	gamma = 0.06	(/mV)
	
	vol	= 1	(um3)		: volume of shell
	taurca	= 28.6	(ms)		: rate of calcium removal (Poirazzi)
	bcap	= 17	(1)		: buffer capacity
	cainf	= 100e-6(mM)
	
	p0	= 0.5 (1)	: initial synaptic efficacy
	tau	= 700000 (ms)	: time constant of changes
	ps	= 0.5 (1)	: transition point (unstable state)
	gp	= 1600 (1)	: potentiation rate
	gd	= 300 (1)	: depression rate
	thp	= 1.3 (uM)	: potentiation threshold re cai
	thd	= 1.0 (uM)	: depression threshold re cai
	tp	= 20000 (ms)	: time constant for LTP (eg O'Connor et al 2005)
	td	= 20000 (ms)	: time constant for LTD (eg O'Connor et al 2005)
}

ASSIGNED {
	v (mV)
	i (nA)
	iN (nA)
	g (uS)
	gN (uS)
	factor
	facN
	wgtN (uS)
	cadrive	(mM/ms)
	C1 (uM)	: calcium in uM
	camax (uM)	: maximum ca over a run
	capksum (uM)	: sum of individual peaks in ca
	capkn (1)	: number of individual peaks
	caprev (uM)	: previous ca value
	caprev2(uM)	: next previous ca value
}

STATE {
	A (uS)
	B (uS)
	W (uS)
	aN (uS)
	bN (uS)
	ca (mM)
	p	: synaptic efficacy (0 to 1)
	R	: membrane-bound AMPA receptors
}

INITIAL {
	LOCAL tp
	if (tau1/tau2 > .9999) {
		tau1 = .9999*tau2
	}
	A = 0
	B = 0
	W = 0
	tp = (tau1*tau2)/(tau2 - tau1) * log(tau2/tau1)
	factor = -exp(-tp/tau1) + exp(-tp/tau2)
	factor = 1/factor
	
   	aN = 0  
   	bN = 0 
   	tp = (tcon*tcoff)/(tcoff - tcon) * log(tcoff/tcon)
   	facN = -exp(-tp/tcon) + exp(-tp/tcoff)
   	wgtN = gNmax / facN
   	
   	ca = cainf
	C1 = 1000*ca
	camax=C1
	capksum=0
	capkn=0
	caprev=C1
	caprev2=C1

	p=p0
	R=heavi(p-ps)
}

BREAKPOINT {
	LOCAL s
	
	SOLVE state METHOD cnexp
	trackca()
	
	g = B - A
	i = g*(v - e)

	s = 1.0/(1+eta*mgconc*exp(-gamma*v))
        gN = bN-aN
	iN = gN*s*(v-enmda)
}

DERIVATIVE state {
	A' = -A/tau1
	B' = -B/tau2
	
	aN' = -aN/tcon
	bN' = -bN/tcoff
	
	cadrive =  - (1000000) * fCa * iN / (2 * FARADAY * vol)
	if (cadrive <= 0.) { cadrive = 0.  }   : cannot pump inward 
        ca' = cadrive/(1+bcap) + (cainf-ca)/taurca
: plasticity
	C1 = 1000*ca
	p' = (-p*(1-p)*(ps-p)+gp*(1-p)*heavi(C1-thp)-gd*p*heavi(C1-thd))/tau
: suggested way to capture actual dynamics of AMPA changes	
	R' = heavi(p-ps)*(1-R)/tp - heavi(ps-p)*R/td
}

FUNCTION heavi(x (uM)) (1) {
	heavi = 0
	if (x>0) {
	  heavi = 1
	}
}

PROCEDURE trackca() {
	if (C1>camax) {camax=C1}
	
	if (C1<caprev && caprev>caprev2) {
		capksum = capksum + caprev
		capkn = capkn + 1
	}
	caprev2 = caprev
	caprev = C1
}

NET_RECEIVE(weight (uS)) {
	W = (wmin + (1-wmin)*R)*weight
	A = A + W*factor
	B = B + W*factor
	
	aN = aN+wgtN
	bN = bN+wgtN
}
