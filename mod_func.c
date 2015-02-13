#include <stdio.h>
#include "hocdec.h"
#define IMPORT extern __declspec(dllimport)
IMPORT int nrnmpi_myid, nrn_nobanner_;

modl_reg(){
	//nrn_mswindll_stdio(stdin, stdout, stderr);
    if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
	fprintf(stderr, "Additional mechanisms from files\n");

fprintf(stderr," ECellOlufsen.mod");
fprintf(stderr," IcellWangBuzsaki.mod");
fprintf(stderr," OCellTort.mod");
fprintf(stderr," nmda.mod");
fprintf(stderr, "\n");
    }
_ECellOlufsen_reg();
_IcellWangBuzsaki_reg();
_OCellTort_reg();
_nmda_reg();
}
