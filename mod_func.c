#include <stdio.h>
#include "hocdec.h"
#define IMPORT extern __declspec(dllimport)
IMPORT int nrnmpi_myid, nrn_nobanner_;

modl_reg(){
	//nrn_mswindll_stdio(stdin, stdout, stderr);
    if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
	fprintf(stderr, "Additional mechanisms from files\n");

fprintf(stderr," ANsynGB.mod");
fprintf(stderr," ECellOlufsen.mod");
fprintf(stderr," ECellTort.mod");
fprintf(stderr," IcellWangBuzsaki.mod");
fprintf(stderr," OCellTort.mod");
fprintf(stderr," PT1dstim.mod");
fprintf(stderr," bistableGB.mod");
fprintf(stderr," burststim2.mod");
fprintf(stderr," burststim3.mod");
fprintf(stderr," cad.mod");
fprintf(stderr," cagk.mod");
fprintf(stderr," carF.mod");
fprintf(stderr," celldrive.mod");
fprintf(stderr," exp2synGB.mod");
fprintf(stderr," gclamp.mod");
fprintf(stderr," h.mod");
fprintf(stderr," kadist.mod");
fprintf(stderr," kaprox.mod");
fprintf(stderr," kca.mod");
fprintf(stderr," kdrca1.mod");
fprintf(stderr," km.mod");
fprintf(stderr," na3n.mod");
fprintf(stderr," naxn.mod");
fprintf(stderr," nmda.mod");
fprintf(stderr," nmdaca.mod");
fprintf(stderr, "\n");
    }
_ANsynGB_reg();
_ECellOlufsen_reg();
_ECellTort_reg();
_IcellWangBuzsaki_reg();
_OCellTort_reg();
_PT1dstim_reg();
_bistableGB_reg();
_burststim2_reg();
_burststim3_reg();
_cad_reg();
_cagk_reg();
_carF_reg();
_celldrive_reg();
_exp2synGB_reg();
_gclamp_reg();
_h_reg();
_kadist_reg();
_kaprox_reg();
_kca_reg();
_kdrca1_reg();
_km_reg();
_na3n_reg();
_naxn_reg();
_nmda_reg();
_nmdaca_reg();
}
