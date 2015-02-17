TITLE CellDrive  
: Cell drive current (B. Graham 16-2-15)

UNITS {
        (mA) = (milliamp)
        (mV) = (millivolt)
}
 
NEURON {
	SUFFIX Celldrive
	NONSPECIFIC_CURRENT celldrive, celldrivenoise
	RANGE drive,drivenoise 
}
 
PARAMETER {
        v			(mV)
        celsius			(degC)
	drive=0			(mA/cm2)
	drivenoise =0		(mA/cm2)
}
  
ASSIGNED {
	celldrive		(mA/cm2)
	celldrivenoise		(mA/cm2)
}
 
BREAKPOINT {
	celldrive = -drive
	celldrivenoise = -drivenoise
}
 
INITIAL { 
	celldrive = -drive
	celldrivenoise = -drivenoise
}

