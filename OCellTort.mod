TITLE OCellChann  
: Cell model from  Tort et al. (2007)
: Programmed by Adriano Tort, CBD, BU, 2008

UNITS {
        (mA) = (milliamp)
        (mV) = (millivolt)
}
 
NEURON {
	SUFFIX Ocellchann
	NONSPECIFIC_CURRENT ina
	NONSPECIFIC_CURRENT ik
	NONSPECIFIC_CURRENT ia
	NONSPECIFIC_CURRENT ih
	NONSPECIFIC_CURRENT celldrive,celldrivenoise
	NONSPECIFIC_CURRENT il
	GLOBAL gna, ena, gk, ek, ga, ea, gh, eh, gl, el
	RANGE drive,drivenoise 
}
 
PARAMETER {
        v				(mV)
        celsius			(degC)
        gna= 0.030		(mho/cm2)
        ena= 90			(mV)
        gk= 0.023		(mho/cm2)
        ek= -100		(mV)
        ga= 0.016		(mho/cm2)
        ea= -90			(mV)
        gh= 0.012		(mho/cm2)
        eh= -32.9		(mV)
 	v50=-84			(mV)
	gl= 0.00005		(mho/cm2)
        el= -70			(mV)
	drive=-0.003	(mA/cm2)
	drivenoise =0	(mA/cm2)
}
 
 
STATE {
	m
	h 
	n
	a
	b
	r
}
 
 
ASSIGNED {
	celldrive		(mA/cm2)
	celldrivenoise	(mA/cm2)
	
	ina		(mA/cm2) 
 	minf
	mtau    (ms)
	hinf
	htau	(ms)
	
	ik		(mA/cm2)
	ninf
	ntau	(ms)
	il		(mA/cm2)
	
	ia		(mA/cm2) 
 	ainf
	atau    (ms)
	binf
	btau    (ms)
	
	ih		(mA/cm2) 
 	rinf
	rtau    (ms)
}
 
 
BREAKPOINT {
        SOLVE states METHOD cnexp
		celldrive = -drive
		celldrivenoise = -drivenoise
        
		ik=gk*n*n*n*n*(v-ek)
		ina=gna*m*m*m*h*(v-ena)
		il=gl*(v-el)
        ia=ga*a*b*(v-ea)
        ih=gh*r*(v-eh)      
}
 
 
DERIVATIVE states { 
       rates(v)
	   m'= (minf- m)/ mtau 
	   h'= (hinf- h)/ htau 
	   n'= (ninf- n)/ ntau 
	   a'= (ainf- a)/ atau
	   b'= (binf- b)/ btau
       r'= (rinf- r)/ rtau 
}

INITIAL { 
	rates(v)
	m=minf
	h=hinf
	n=ninf
	a=ainf
	b=binf
	r=rinf
}

PROCEDURE rates(v (mV)) {
LOCAL alpha, beta
UNITSOFF 

	alpha = -0.1*(v+38)/(exp(-(v+38)/10)-1)
	beta = 4*exp(-(v+65)/18)
	mtau = 1/(alpha+beta)
	minf = alpha*mtau	
		
	alpha = 0.07*exp(-(v+63)/20)
  	beta =  1/(1+exp(-(v+33)/10))
	htau = 1/(alpha+beta)
	hinf = alpha*htau	
	
	alpha = 0.018*(v-25)/(1-exp(-(v-25)/25))
  	beta =  0.0036*(v-35)/(exp((v-35)/12)-1)
	ntau = 1/(alpha+beta)
	ninf = alpha*ntau
	
	atau=5
	ainf=1/(1+exp(-(v+14)/16.6))
	btau=1/(0.000009/exp((v-26)/18.5)+0.014/(0.2+exp(-(v+70)/11)))
	binf=1/(1+exp((v+71)/7.3))
	
	rinf=1/(1+exp((v-v50)/10.2))
	rtau=(1/(exp(-14.59-0.086*v)+exp(-1.87+0.0701*v))) 
	
UNITSON
}
