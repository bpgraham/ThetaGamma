/* Created by Language version: 6.2.0 */
/* VECTORIZED */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib.h"
#undef PI
 
#include "md1redef.h"
#include "section.h"
#include "md2redef.h"

#if METHOD3
extern int _method3;
#endif

#undef exp
#define exp hoc_Exp
extern double hoc_Exp();
 
#define _threadargscomma_ _p, _ppvar, _thread, _nt,
#define _threadargs_ _p, _ppvar, _thread, _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 /* Thread safe. No static _p or _ppvar. */
 
#define t _nt->_t
#define dt _nt->_dt
#define gA _p[0]
#define gh _p[1]
#define v50 _p[2]
#define bk _p[3]
#define ck _p[4]
#define dk _p[5]
#define ak _p[6]
#define fk _p[7]
#define drive _p[8]
#define drivenoise _p[9]
#define celldrive _p[10]
#define celldrivenoise _p[11]
#define ina _p[12]
#define ik _p[13]
#define iA _p[14]
#define ih _p[15]
#define il _p[16]
#define m _p[17]
#define h _p[18]
#define i _p[19]
#define n _p[20]
#define a _p[21]
#define b _p[22]
#define r _p[23]
#define Dm _p[24]
#define Dh _p[25]
#define Di _p[26]
#define Dn _p[27]
#define Da _p[28]
#define Db _p[29]
#define Dr _p[30]
#define minf _p[31]
#define mtau _p[32]
#define hinf _p[33]
#define htau _p[34]
#define iinf _p[35]
#define itau _p[36]
#define ninf _p[37]
#define ntau _p[38]
#define ainf _p[39]
#define atau _p[40]
#define binf _p[41]
#define btau _p[42]
#define rinf _p[43]
#define rtau _p[44]
#define v _p[45]
#define _g _p[46]
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 static int hoc_nrnpointerindex =  -1;
 static Datum* _extcall_thread;
 static Prop* _extcall_prop;
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
 static int _hoc_rates();
 static int _mechtype;
extern int nrn_get_mechtype();
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _extcall_prop = _prop;
 }
 static _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range();
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 ret(1.);
}
 /* connect user functions to hoc names */
 static IntFunc hoc_intfunc[] = {
 "setdata_Ecell5chann", _hoc_setdata,
 "rates_Ecell5chann", _hoc_rates,
 0, 0
};
 /* declare global and static user variables */
#define amin amin_Ecell5chann
 double amin = 0.1;
#define bmin bmin_Ecell5chann
 double bmin = 2;
#define eh eh_Ecell5chann
 double eh = -30;
#define eA eA_Ecell5chann
 double eA = -90;
#define el el_Ecell5chann
 double el = -70;
#define ek ek_Ecell5chann
 double ek = -90;
#define ena ena_Ecell5chann
 double ena = 55;
#define gl gl_Ecell5chann
 double gl = 3e-05;
#define gk gk_Ecell5chann
 double gk = 0.01;
#define gna gna_Ecell5chann
 double gna = 0.032;
#define hmin hmin_Ecell5chann
 double hmin = 0.5;
#define imin imin_Ecell5chann
 double imin = 10;
#define mmin mmin_Ecell5chann
 double mmin = 0.2;
#define nmin nmin_Ecell5chann
 double nmin = 2;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "gna_Ecell5chann", "mho/cm2",
 "ena_Ecell5chann", "mV",
 "gk_Ecell5chann", "mho/cm2",
 "ek_Ecell5chann", "mV",
 "gl_Ecell5chann", "mho/cm2",
 "el_Ecell5chann", "mV",
 "eA_Ecell5chann", "mV",
 "eh_Ecell5chann", "mV",
 "gA_Ecell5chann", "mho/cm2",
 "gh_Ecell5chann", "mho/cm2",
 "v50_Ecell5chann", "mV",
 "ak_Ecell5chann", "mV",
 "drive_Ecell5chann", "mA/cm2",
 "drivenoise_Ecell5chann", "mA/cm2",
 "celldrive_Ecell5chann", "mA/cm2",
 "celldrivenoise_Ecell5chann", "mA/cm2",
 "ina_Ecell5chann", "mA/cm2",
 "ik_Ecell5chann", "mA/cm2",
 "iA_Ecell5chann", "mA/cm2",
 "ih_Ecell5chann", "mA/cm2",
 "il_Ecell5chann", "mA/cm2",
 0,0
};
 static double a0 = 0;
 static double b0 = 0;
 static double delta_t = 0.01;
 static double h0 = 0;
 static double i0 = 0;
 static double m0 = 0;
 static double n0 = 0;
 static double r0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "gna_Ecell5chann", &gna_Ecell5chann,
 "ena_Ecell5chann", &ena_Ecell5chann,
 "gk_Ecell5chann", &gk_Ecell5chann,
 "ek_Ecell5chann", &ek_Ecell5chann,
 "gl_Ecell5chann", &gl_Ecell5chann,
 "el_Ecell5chann", &el_Ecell5chann,
 "eA_Ecell5chann", &eA_Ecell5chann,
 "eh_Ecell5chann", &eh_Ecell5chann,
 "mmin_Ecell5chann", &mmin_Ecell5chann,
 "hmin_Ecell5chann", &hmin_Ecell5chann,
 "imin_Ecell5chann", &imin_Ecell5chann,
 "nmin_Ecell5chann", &nmin_Ecell5chann,
 "amin_Ecell5chann", &amin_Ecell5chann,
 "bmin_Ecell5chann", &bmin_Ecell5chann,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(), nrn_init(), nrn_state();
 static void nrn_cur(), nrn_jacob();
 
static int _ode_count(), _ode_map(), _ode_spec(), _ode_matsol();
 
#define _cvode_ieq _ppvar[0]._i
 /* connect range variables in _p that hoc is supposed to know about */
 static char *_mechanism[] = {
 "6.2.0",
"Ecell5chann",
 "gA_Ecell5chann",
 "gh_Ecell5chann",
 "v50_Ecell5chann",
 "bk_Ecell5chann",
 "ck_Ecell5chann",
 "dk_Ecell5chann",
 "ak_Ecell5chann",
 "fk_Ecell5chann",
 "drive_Ecell5chann",
 "drivenoise_Ecell5chann",
 0,
 "celldrive_Ecell5chann",
 "celldrivenoise_Ecell5chann",
 "ina_Ecell5chann",
 "ik_Ecell5chann",
 "iA_Ecell5chann",
 "ih_Ecell5chann",
 "il_Ecell5chann",
 0,
 "m_Ecell5chann",
 "h_Ecell5chann",
 "i_Ecell5chann",
 "n_Ecell5chann",
 "a_Ecell5chann",
 "b_Ecell5chann",
 "r_Ecell5chann",
 0,
 0};
 
static void nrn_alloc(_prop)
	Prop *_prop;
{
	Prop *prop_ion, *need_memb();
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 47, _prop);
 	/*initialize range parameters*/
 	gA = 0.048;
 	gh = 0.0001;
 	v50 = -82;
 	bk = 0.8;
 	ck = 4;
 	dk = 1.5;
 	ak = 11;
 	fk = 0.825;
 	drive = 0;
 	drivenoise = 0;
 	_prop->param = _p;
 	_prop->param_size = 47;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 1, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 
}
 static _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 _ECellTort_reg() {
	int _vectorized = 1;
  _initlists();
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
  hoc_register_dparam_size(_mechtype, 1);
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 Ecell5chann /cygdrive/c/Documents and Settings/bpg/Desktop/Projects/CortDyn/Subprojects/CA1rhythms/Code/Neuron/ThetaGamma/ECellTort.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "ECell5Chann  ";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static _modl_cleanup(){ _match_recurse=1;}
static rates();
 
static int _ode_spec1(), _ode_matsol1();
 static int _slist1[7], _dlist1[7];
 static int states();
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   rates ( _threadargscomma_ v ) ;
   Dm = ( minf - m ) / mtau ;
   Dh = ( hinf - h ) / htau ;
   Di = ( iinf - i ) / itau ;
   Dn = ( ninf - n ) / ntau ;
   Da = ( ainf - a ) / atau ;
   Db = ( binf - b ) / btau ;
   Dr = ( rinf - r ) / rtau ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 rates ( _threadargscomma_ v ) ;
 Dm = Dm  / (1. - dt*( ( ( ( - 1.0 ) ) ) / mtau )) ;
 Dh = Dh  / (1. - dt*( ( ( ( - 1.0 ) ) ) / htau )) ;
 Di = Di  / (1. - dt*( ( ( ( - 1.0 ) ) ) / itau )) ;
 Dn = Dn  / (1. - dt*( ( ( ( - 1.0 ) ) ) / ntau )) ;
 Da = Da  / (1. - dt*( ( ( ( - 1.0 ) ) ) / atau )) ;
 Db = Db  / (1. - dt*( ( ( ( - 1.0 ) ) ) / btau )) ;
 Dr = Dr  / (1. - dt*( ( ( ( - 1.0 ) ) ) / rtau )) ;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
   rates ( _threadargscomma_ v ) ;
    m = m + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / mtau)))*(- ( ( ( minf ) ) / mtau ) / ( ( ( ( - 1.0) ) ) / mtau ) - m) ;
    h = h + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / htau)))*(- ( ( ( hinf ) ) / htau ) / ( ( ( ( - 1.0) ) ) / htau ) - h) ;
    i = i + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / itau)))*(- ( ( ( iinf ) ) / itau ) / ( ( ( ( - 1.0) ) ) / itau ) - i) ;
    n = n + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / ntau)))*(- ( ( ( ninf ) ) / ntau ) / ( ( ( ( - 1.0) ) ) / ntau ) - n) ;
    a = a + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / atau)))*(- ( ( ( ainf ) ) / atau ) / ( ( ( ( - 1.0) ) ) / atau ) - a) ;
    b = b + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / btau)))*(- ( ( ( binf ) ) / btau ) / ( ( ( ( - 1.0) ) ) / btau ) - b) ;
    r = r + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / rtau)))*(- ( ( ( rinf ) ) / rtau ) / ( ( ( ( - 1.0) ) ) / rtau ) - r) ;
   }
  return 0;
}
 
static int  rates ( _p, _ppvar, _thread, _nt, _lv ) double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt; 
	double _lv ;
 {
   double _lalpha , _lbeta ;
  _lalpha = 0.4 * ( _lv + 30.0 ) / ( 1.0 - exp ( - ( _lv + 30.0 ) / 7.2 ) ) ;
   _lbeta = 0.124 * ( _lv + 30.0 ) / ( exp ( ( _lv + 30.0 ) / 7.2 ) - 1.0 ) ;
   minf = _lalpha / ( _lalpha + _lbeta ) ;
   mtau = 0.5 / ( _lalpha + _lbeta ) ;
   if ( mtau < mmin ) {
     mtau = mmin ;
     }
   _lalpha = 0.03 * ( _lv + 45.0 ) / ( 1.0 - exp ( - ( _lv + 45.0 ) / 1.5 ) ) ;
   _lbeta = 0.01 * ( _lv + 45.0 ) / ( exp ( ( _lv + 45.0 ) / 1.5 ) - 1.0 ) ;
   hinf = 1.0 / ( 1.0 + exp ( ( _lv + 50.0 ) / 4.0 ) ) ;
   htau = 0.5 / ( _lalpha + _lbeta ) ;
   if ( htau < hmin ) {
     htau = hmin ;
     }
   _lalpha = exp ( 0.45 * ( _lv + 66.0 ) ) ;
   _lbeta = exp ( 0.09 * ( _lv + 66.0 ) ) ;
   iinf = ( 1.0 + bk * exp ( ( _lv + 60.0 ) / 2.0 ) ) / ( 1.0 + exp ( ( _lv + 60.0 ) / 2.0 ) ) ;
   itau = 30000.0 * _lbeta / ( _lalpha + 1.0 ) ;
   if ( itau < imin ) {
     itau = imin ;
     }
   _lalpha = exp ( - 0.11 * ( _lv - 13.0 ) ) ;
   _lbeta = exp ( - 0.08 * ( _lv - 13.0 ) ) ;
   ninf = 1.0 / ( _lalpha + 1.0 ) ;
   ntau = 50.0 * _lbeta / ( _lalpha + 1.0 ) ;
   if ( ntau < nmin ) {
     ntau = nmin ;
     }
   _lalpha = exp ( - 0.038 * ( dk + ( 1.0 / ( 1.0 + exp ( _lv + 40.0 ) / 5.0 ) ) ) * ( _lv - ak ) ) ;
   _lbeta = exp ( - 0.038 * ( fk + ( 1.0 / ( 1.0 + exp ( _lv + 40.0 ) / 5.0 ) ) ) * ( _lv - ak ) ) ;
   ainf = 1.0 / ( _lalpha + 1.0 ) ;
   atau = ck * _lbeta / ( _lalpha + 1.0 ) ;
   if ( atau < amin ) {
     atau = amin ;
     }
   binf = 1.0 / ( exp ( 0.11 * ( _lv + 56.0 ) ) + 1.0 ) ;
   btau = 0.26 * ( _lv + 50.0 ) ;
   if ( btau < bmin ) {
     btau = bmin ;
     }
   rinf = 1.0 / ( 1.0 + exp ( ( _lv - v50 ) / 10.5 ) ) ;
   rtau = 1.0 / ( exp ( - 14.59 - 0.086 * _lv ) + exp ( - 1.87 + 0.0701 * _lv ) ) ;
     return 0; }
 
static int _hoc_rates() {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r = 1.;
 rates ( _p, _ppvar, _thread, _nt, *getarg(1) ) ;
 ret(_r);
}
 
static int _ode_count(_type) int _type;{ return 7;}
 
static int _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
     _ode_spec1 (_p, _ppvar, _thread, _nt);
 }}
 
static int _ode_map(_ieq, _pv, _pvdot, _pp, _ppd, _atol, _type) int _ieq, _type; double** _pv, **_pvdot, *_pp, *_atol; Datum* _ppd; { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 7; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static int _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
 _ode_matsol1 (_p, _ppvar, _thread, _nt);
 }}

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  a = a0;
  b = b0;
  h = h0;
  i = i0;
  m = m0;
  n = n0;
  r = r0;
 {
   rates ( _threadargscomma_ v ) ;
   m = minf ;
   h = hinf ;
   i = iinf ;
   n = ninf ;
   a = ainf ;
   b = binf ;
   r = rinf ;
   }
 
}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
 initmodel(_p, _ppvar, _thread, _nt);
}}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   celldrive = - drive ;
   celldrivenoise = - drivenoise ;
   ina = gna * m * m * m * h * i * ( v - ena ) ;
   ik = gk * n * n * n * n * ( v - ek ) ;
   iA = gk * a * b * ( v - eA ) ;
   ih = gh * r * ( v - eh ) ;
   il = gl * ( v - el ) ;
   }
 _current += celldrive;
 _current += celldrivenoise;
 _current += ina;
 _current += ik;
 _current += il;
 _current += iA;
 _current += ih;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
 	}
 _g = (_g - _rhs)/.001;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type) {
 double _break, _save;
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 _break = t + .5*dt; _save = t;
 v=_v;
{
 { {
 for (; t < _break; t += dt) {
   states(_p, _ppvar, _thread, _nt);
  
}}
 t = _save;
 }}}

}

static terminal(){}

static _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(m) - _p;  _dlist1[0] = &(Dm) - _p;
 _slist1[1] = &(h) - _p;  _dlist1[1] = &(Dh) - _p;
 _slist1[2] = &(i) - _p;  _dlist1[2] = &(Di) - _p;
 _slist1[3] = &(n) - _p;  _dlist1[3] = &(Dn) - _p;
 _slist1[4] = &(a) - _p;  _dlist1[4] = &(Da) - _p;
 _slist1[5] = &(b) - _p;  _dlist1[5] = &(Db) - _p;
 _slist1[6] = &(r) - _p;  _dlist1[6] = &(Dr) - _p;
_first = 0;
}
