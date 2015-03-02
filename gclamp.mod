COMMENT
Since this is an electrode current, positive values of i depolarize the cell
and in the presence of the extracellular mechanism there will be a change
in vext since i is not a transmembrane current but a current injected
directly to the inside of the cell.
ENDCOMMENT

NEURON {
	POINT_PROCESS GClamp
	RANGE del, dur, amp, erev, g, i
	NONSPECIFIC_CURRENT i
}
UNITS {
	(nA) = (nanoamp)
        (uS) = (microsiemens)
        (mV) = (millivolt)
}

PARAMETER {
	del (ms)
	dur (ms)	<0,1e9>
	amp (nA)
	erev (mV)
	v (mV)
}
ASSIGNED {
	g (uS)
	i (nA) 
	}

INITIAL {
	g = 0
	i = 0
}

BREAKPOINT {
	at_time(del)
	at_time(del+dur)

	if (t < del + dur && t >= del) {
		g = amp
	}else{
		g = 0
	}
	
	i = g*(v-erev)
}
