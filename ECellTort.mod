TITLE ECell5Chann  
: Cell model from  Migliore (2004)
: Programmed by Adriano Tort, CBD, BU, 2008
: Reproduced from PNAS SI by B. Graham 16-2-15

UNITS {
        (mA) = (milliamp)
        (mV) = (millivolt)
}
 
NEURON {
	SUFFIX Ecell5chann
	NONSPECIFIC_CURRENT celldrive, celldrivenoise
	NONSPECIFIC_CURRENT ina
	NONSPECIFIC_CURRENT ik
	NONSPECIFIC_CURRENT il
	NONSPECIFIC_CURRENT iA
	NONSPECIFIC_CURRENT ih
	GLOBAL gna, gk, ena, ek, gl, el, eA, eh
	RANGE gA, gh, v50, bk, ck, dk, ak, fk
	RANGE drive,drivenoise 
}
 
PARAMETER {
        v			(mV)
        celsius			(degC)
        gna= 0.032		(mho/cm2)
        ena= 55			(mV)
        gk= 0.01		(mho/cm2)
        ek= -90			(mV)
	gl= 0.00003		(mho/cm2)
        el= -70			(mV)
	gA= 0.048		(mho/cm2)
        eA= -90			(mV)
	gh= 0.0001		(mho/cm2)
        eh= -30			(mV)
        mmin = 0.2
        hmin = 0.5
        imin = 10
        nmin = 2
        amin = 0.1
        v50 = -82		(mV)
        bk = 0.8
        ck = 4
        dk = 1.5
        ak = 11			(mV)
        fk = 0.825
	drive=0			(mA/cm2)
	drivenoise =0		(mA/cm2)
}
 
STATE {
	m
	h 
	i
	n
	a
	b
	r
}
 
ASSIGNED {
	celldrive		(mA/cm2)
	celldrivenoise	(mA/cm2)
	
	ina	(mA/cm2) 
 	minf
	mtau    (ms)
	hinf
	htau	(ms)
	iinf
	itau	(ms)
	
	ik	(mA/cm2)
	ninf
	ntau	(ms)
	
	iA	(mA/cm2)
	ainf
	atau	(ms)
	binf
	btau	(ms)
	
	ih	(mA/cm2)
	rinf
	rtau	(ms)
	
	il	(mA/cm2) 
}
 
BREAKPOINT {
        SOLVE states METHOD cnexp
	celldrive = -drive
	celldrivenoise = -drivenoise
        
	ina=gna*m*m*m*h*i*(v-ena)
	ik=gk*n*n*n*n*(v-ek)
	iA=gk*a*b*(v-eA)
	ih=gh*r*(v-eh)
	il=gl*(v-el)      
}
 
DERIVATIVE states { 
       rates(v)
	   m'= (minf- m)/ mtau 
	   h'= (hinf- h)/ htau 
	   i'= (iinf- i)/ itau 
	   n'= (ninf- n)/ ntau 
	   a'= (ainf- a)/ atau 
	   b'= (binf- b)/ btau 
	   r'= (rinf- r)/ rtau 
}


INITIAL { 
	rates(v)
	m=minf
	h=hinf
	i=iinf
	n=ninf
	a=ainf
	b=binf
	r=rinf
}

PROCEDURE rates(v (mV)) {
LOCAL alpha, beta
UNITSOFF 

	alpha = 0.4*(v+30)/(1-exp(-(v+30)/7.2))
	beta = 0.124*(v+30)/(exp((v+30)/7.2)-1)
	minf=alpha/(alpha+beta)
	mtau = 0.5/(alpha+beta)
        if (mtau<mmin) {mtau=mmin}
	
	alpha = 0.03*(v+45)/(1-exp(-(v+45)/1.5))
  	beta =  0.01*(v+45)/(exp((v+45)/1.5)-1)
	hinf = 1/(1+exp((v+50)/4))
	htau = 0.5/(alpha+beta)
        if (htau<hmin) {htau=hmin}
	
	alpha = exp(0.45*(v+66))
  	beta =  exp(0.09*(v+66))
	iinf = (1+bk*exp((v+60)/2))/(1+exp((v+60)/2))
	itau = 3000*beta/(alpha+1)
        if (itau<imin) {itau=imin}
	
	alpha = exp(-0.11*(v-13))
  	beta =  exp(-0.08*(v-13))
	ninf=1/(alpha+1)
	ntau = 50*beta/(alpha+1)
        if (ntau<nmin) {ntau=nmin}
	
	alpha = exp(-0.038*(dk + (1/(1+exp(v+40)/5)))*(v-ak))
	beta = exp(-0.038*(fk + (1/(1+exp(v+40)/5)))*(v-ak))
	ainf=1/(alpha+1)
	atau = ck*beta/(alpha+1)
        if (atau<amin) {atau=amin}

	rinf = 1/(1+exp((v-v50)/10.5))
	rtau = 1/(exp(-14.59-0.086*v)+exp(-1.87+0.0701*v))
	: rinf = 1/(1+exp(0.151*(v-v50)))
	: rtau = exp(0.033*(v+75))/(0.011*(1+exp(0.083*(v+75))))
	
UNITSON
}
