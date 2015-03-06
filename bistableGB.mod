TITLE Tristable model of AMPA receptor plasticity

COMMENT
-----------------------------------------------------------------------------
  Implementation of Graupner and Brunel's bistable model of synaptic 
  plasticity (PNAS 109(20):3991-3996, 2012.
  
  Reads internal calcium concentration (from compartment it is inserted in).
  
  Provides a state variable A that is a measure of the percentage of inserted
  AMPA receptors from fixed available pool (on scale of 0 to 1).
  
  Noise term not implemented.
  
  BPG 25-10-12

-----------------------------------------------------------------------------
ENDCOMMENT

INDEPENDENT {t FROM 0 TO 1 WITH 1 (ms)}

NEURON {
	SUFFIX BistableGB
	USEION ca READ cai
	RANGE p, p0, A
	GLOBAL tau, ps, gp, gd, thp, thd, tp, td
}

UNITS {
	(nA) = (nanoamp)
	(mV) = (millivolt)
	(pS) = (picosiemens)
	(umho) = (micromho)
	(mM) = (milli/liter)
	(uM) = (micro/liter)
}

PARAMETER {
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
	cai (mM)	: calcium concentration
	C1 (uM)	: calcium in uM
}

STATE {
	p	: synaptic efficacy (0 to 1)
	A	: membrane-bound AMPA receptors
}

INITIAL {
	p=p0
	A=heavi(p-ps)
}

BREAKPOINT {
	SOLVE states METHOD cnexp
}

DERIVATIVE states {
	
	C1 = 1000*cai

	p' = (-p*(1-p)*(ps-p)+gp*(1-p)*heavi(C1-thp)-gd*p*heavi(C1-thd))/tau

: suggested way to capture actual dynamics of AMPA changes	
	A' = heavi(p-ps)*(1-A)/tp - heavi(ps-p)*A/td

}

FUNCTION heavi(x (uM)) (1) {
	heavi = 0
	if (x>0) {
	  heavi = 1
	}
}

