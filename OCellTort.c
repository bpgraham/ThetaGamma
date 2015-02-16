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
#define drive _p[0]
#define drivenoise _p[1]
#define celldrive _p[2]
#define celldrivenoise _p[3]
#define ina _p[4]
#define ik _p[5]
#define il _p[6]
#define ia _p[7]
#define ih _p[8]
#define m _p[9]
#define h _p[10]
#define n _p[11]
#define a _p[12]
#define b _p[13]
#define r _p[14]
#define Dm _p[15]
#define Dh _p[16]
#define Dn _p[17]
#define Da _p[18]
#define Db _p[19]
#define Dr _p[20]
#define minf _p[21]
#define mtau _p[22]
#define hinf _p[23]
#define htau _p[24]
#define ninf _p[25]
#define ntau _p[26]
#define ainf _p[27]
#define atau _p[28]
#define binf _p[29]
#define btau _p[30]
#define rinf _p[31]
#define rtau _p[32]
#define v _p[33]
#define _g _p[34]
 
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
 "setdata_Ocellchann", _hoc_setdata,
 "rates_Ocellchann", _hoc_rates,
 0, 0
};
 /* declare global and static user variables */
#define el el_Ocellchann
 double el = -70;
#define eh eh_Ocellchann
 double eh = -32.9;
#define ea ea_Ocellchann
 double ea = -90;
#define ek ek_Ocellchann
 double ek = -100;
#define ena ena_Ocellchann
 double ena = 90;
#define gl gl_Ocellchann
 double gl = 5e-05;
#define gh gh_Ocellchann
 double gh = 0.012;
#define ga ga_Ocellchann
 double ga = 0.016;
#define gk gk_Ocellchann
 double gk = 0.023;
#define gna gna_Ocellchann
 double gna = 0.03;
#define v50 v50_Ocellchann
 double v50 = -84;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "gna_Ocellchann", "mho/cm2",
 "ena_Ocellchann", "mV",
 "gk_Ocellchann", "mho/cm2",
 "ek_Ocellchann", "mV",
 "ga_Ocellchann", "mho/cm2",
 "ea_Ocellchann", "mV",
 "gh_Ocellchann", "mho/cm2",
 "eh_Ocellchann", "mV",
 "v50_Ocellchann", "mV",
 "gl_Ocellchann", "mho/cm2",
 "el_Ocellchann", "mV",
 "drive_Ocellchann", "mA/cm2",
 "drivenoise_Ocellchann", "mA/cm2",
 "celldrive_Ocellchann", "mA/cm2",
 "celldrivenoise_Ocellchann", "mA/cm2",
 "ina_Ocellchann", "mA/cm2",
 "ik_Ocellchann", "mA/cm2",
 "il_Ocellchann", "mA/cm2",
 "ia_Ocellchann", "mA/cm2",
 "ih_Ocellchann", "mA/cm2",
 0,0
};
 static double a0 = 0;
 static double b0 = 0;
 static double delta_t = 0.01;
 static double h0 = 0;
 static double m0 = 0;
 static double n0 = 0;
 static double r0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "gna_Ocellchann", &gna_Ocellchann,
 "ena_Ocellchann", &ena_Ocellchann,
 "gk_Ocellchann", &gk_Ocellchann,
 "ek_Ocellchann", &ek_Ocellchann,
 "ga_Ocellchann", &ga_Ocellchann,
 "ea_Ocellchann", &ea_Ocellchann,
 "gh_Ocellchann", &gh_Ocellchann,
 "eh_Ocellchann", &eh_Ocellchann,
 "v50_Ocellchann", &v50_Ocellchann,
 "gl_Ocellchann", &gl_Ocellchann,
 "el_Ocellchann", &el_Ocellchann,
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
"Ocellchann",
 "drive_Ocellchann",
 "drivenoise_Ocellchann",
 0,
 "celldrive_Ocellchann",
 "celldrivenoise_Ocellchann",
 "ina_Ocellchann",
 "ik_Ocellchann",
 "il_Ocellchann",
 "ia_Ocellchann",
 "ih_Ocellchann",
 0,
 "m_Ocellchann",
 "h_Ocellchann",
 "n_Ocellchann",
 "a_Ocellchann",
 "b_Ocellchann",
 "r_Ocellchann",
 0,
 0};
 
static void nrn_alloc(_prop)
	Prop *_prop;
{
	Prop *prop_ion, *need_memb();
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 35, _prop);
 	/*initialize range parameters*/
 	drive = -0.003;
 	drivenoise = 0;
 	_prop->param = _p;
 	_prop->param_size = 35;
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
 _OCellTort_reg() {
	int _vectorized = 1;
  _initlists();
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
  hoc_register_dparam_size(_mechtype, 1);
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 Ocellchann /cygdrive/c/Documents and Settings/bpg/Desktop/Projects/CortDyn/Subprojects/CA1rhythms/Code/Neuron/ThetaGamma/OCellTort.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "OCellChann  ";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static _modl_cleanup(){ _match_recurse=1;}
static rates();
 
static int _ode_spec1(), _ode_matsol1();
 static int _slist1[6], _dlist1[6];
 static int states();
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   rates ( _threadargscomma_ v ) ;
   Dm = ( minf - m ) / mtau ;
   Dh = ( hinf - h ) / htau ;
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
  _lalpha = - 0.1 * ( _lv + 38.0 ) / ( exp ( - ( _lv + 38.0 ) / 10.0 ) - 1.0 ) ;
   _lbeta = 4.0 * exp ( - ( _lv + 65.0 ) / 18.0 ) ;
   mtau = 1.0 / ( _lalpha + _lbeta ) ;
   minf = _lalpha * mtau ;
   _lalpha = 0.07 * exp ( - ( _lv + 63.0 ) / 20.0 ) ;
   _lbeta = 1.0 / ( 1.0 + exp ( - ( _lv + 33.0 ) / 10.0 ) ) ;
   htau = 1.0 / ( _lalpha + _lbeta ) ;
   hinf = _lalpha * htau ;
   _lalpha = 0.018 * ( _lv - 25.0 ) / ( 1.0 - exp ( - ( _lv - 25.0 ) / 25.0 ) ) ;
   _lbeta = 0.0036 * ( _lv - 35.0 ) / ( exp ( ( _lv - 35.0 ) / 12.0 ) - 1.0 ) ;
   ntau = 1.0 / ( _lalpha + _lbeta ) ;
   ninf = _lalpha * ntau ;
   atau = 5.0 ;
   ainf = 1.0 / ( 1.0 + exp ( - ( _lv + 14.0 ) / 16.6 ) ) ;
   btau = 1.0 / ( 0.000009 / exp ( ( _lv - 26.0 ) / 18.5 ) + 0.014 / ( 0.2 + exp ( - ( _lv + 70.0 ) / 11.0 ) ) ) ;
   binf = 1.0 / ( 1.0 + exp ( ( _lv + 71.0 ) / 7.3 ) ) ;
   rinf = 1.0 / ( 1.0 + exp ( ( _lv - v50 ) / 10.2 ) ) ;
   rtau = ( 1.0 / ( exp ( - 14.59 - 0.086 * _lv ) + exp ( - 1.87 + 0.0701 * _lv ) ) ) ;
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
 
static int _ode_count(_type) int _type;{ return 6;}
 
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
	for (_i=0; _i < 6; ++_i) {
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
  m = m0;
  n = n0;
  r = r0;
 {
   rates ( _threadargscomma_ v ) ;
   m = minf ;
   h = hinf ;
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
   ik = gk * n * n * n * n * ( v - ek ) ;
   ina = gna * m * m * m * h * ( v - ena ) ;
   il = gl * ( v - el ) ;
   ia = ga * a * b * ( v - ea ) ;
   ih = gh * r * ( v - eh ) ;
   }
 _current += ina;
 _current += ik;
 _current += ia;
 _current += ih;
 _current += celldrive;
 _current += celldrivenoise;
 _current += il;

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
 _slist1[2] = &(n) - _p;  _dlist1[2] = &(Dn) - _p;
 _slist1[3] = &(a) - _p;  _dlist1[3] = &(Da) - _p;
 _slist1[4] = &(b) - _p;  _dlist1[4] = &(Db) - _p;
 _slist1[5] = &(r) - _p;  _dlist1[5] = &(Dr) - _p;
_first = 0;
}
