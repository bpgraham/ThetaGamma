TITLE Track peak calcium conc. in a segment
: BPG 5-5-15, adapted from distr.mod by M.Migliore June 2001

UNITS {
	(mA) = (milliamp)
	(mV) = (millivolt)

}

PARAMETER {
	v (mV)
}


NEURON {
	SUFFIX peakca
	USEION ca READ cai	
        RANGE camax, capksum, capkn
}

PARAMETER {
	cai		(mM)
}

ASSIGNED {
	camax	: maximum ca over a run
	capksum	: sum of individual peaks in ca
	capkn	: number of individual peaks
	caprev	: previous ca value
	caprev2	: next previous ca value
}

INITIAL {
	camax=cai
	capksum=0
	capkn=0
	caprev=cai
	caprev2=cai
}


BREAKPOINT {
	if (cai>camax) {camax=cai}
	
	if (cai<caprev && caprev>caprev2) {
		capksum = capksum + caprev
		capkn = capkn + 1
	}
	caprev2 = caprev
	caprev = cai
}
