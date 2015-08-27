/* Created by Language version: 6.2.0 */
/* VECTORIZED */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib_ansi.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define _threadargscomma_ _p, _ppvar, _thread, _nt,
#define _threadargs_ _p, _ppvar, _thread, _nt
 
#define _threadargsprotocomma_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt,
#define _threadargsproto_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 /* Thread safe. No static _p or _ppvar. */
 
#define t _nt->_t
#define dt _nt->_dt
#define tau1 _p[0]
#define tau2 _p[1]
#define e _p[2]
#define wmin _p[3]
#define fCa _p[4]
#define tcon _p[5]
#define tcoff _p[6]
#define enmda _p[7]
#define gNmax _p[8]
#define mgconc _p[9]
#define eta _p[10]
#define gamma _p[11]
#define vol _p[12]
#define taurca _p[13]
#define bcap _p[14]
#define cainf _p[15]
#define p0 _p[16]
#define i _p[17]
#define iN _p[18]
#define g _p[19]
#define gN _p[20]
#define camax _p[21]
#define capksum _p[22]
#define capkn _p[23]
#define A _p[24]
#define B _p[25]
#define W _p[26]
#define aN _p[27]
#define bN _p[28]
#define ca _p[29]
#define p _p[30]
#define R _p[31]
#define factor _p[32]
#define facN _p[33]
#define wgtN _p[34]
#define cadrive _p[35]
#define C1 _p[36]
#define caprev _p[37]
#define caprev2 _p[38]
#define DA _p[39]
#define DB _p[40]
#define DW _p[41]
#define DaN _p[42]
#define DbN _p[43]
#define Dca _p[44]
#define Dp _p[45]
#define DR _p[46]
#define v _p[47]
#define _g _p[48]
#define _tsav _p[49]
#define _nd_area  *_ppvar[0]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 static Datum* _extcall_thread;
 static Prop* _extcall_prop;
 /* external NEURON variables */
 /* declaration of user functions */
 static double _hoc_heavi();
 static double _hoc_trackca();
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 extern Prop* nrn_point_prop_;
 static int _pointtype;
 static void* _hoc_create_pnt(_ho) Object* _ho; { void* create_point_process();
 return create_point_process(_pointtype, _ho);
}
 static void _hoc_destroy_pnt();
 static double _hoc_loc_pnt(_vptr) void* _vptr; {double loc_point_process();
 return loc_point_process(_pointtype, _vptr);
}
 static double _hoc_has_loc(_vptr) void* _vptr; {double has_loc_point();
 return has_loc_point(_vptr);
}
 static double _hoc_get_loc_pnt(_vptr)void* _vptr; {
 double get_loc_point_process(); return (get_loc_point_process(_vptr));
}
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _extcall_prop = _prop;
 }
 static void _hoc_setdata(void* _vptr) { Prop* _prop;
 _prop = ((Point_process*)_vptr)->_prop;
   _setdata(_prop);
 }
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 0,0
};
 static Member_func _member_func[] = {
 "loc", _hoc_loc_pnt,
 "has_loc", _hoc_has_loc,
 "get_loc", _hoc_get_loc_pnt,
 "heavi", _hoc_heavi,
 "trackca", _hoc_trackca,
 0, 0
};
#define heavi heavi_ANsynGB
 extern double heavi( _threadargsprotocomma_ double );
 /* declare global and static user variables */
#define gd gd_ANsynGB
 double gd = 300;
#define gp gp_ANsynGB
 double gp = 1600;
#define ps ps_ANsynGB
 double ps = 0.5;
#define td td_ANsynGB
 double td = 20000;
#define tp tp_ANsynGB
 double tp = 20000;
#define thd thd_ANsynGB
 double thd = 1;
#define thp thp_ANsynGB
 double thp = 1.3;
#define tau tau_ANsynGB
 double tau = 700000;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 "tau2", 1e-09, 1e+09,
 "tau1", 1e-09, 1e+09,
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "tau_ANsynGB", "ms",
 "ps_ANsynGB", "1",
 "gp_ANsynGB", "1",
 "gd_ANsynGB", "1",
 "thp_ANsynGB", "uM",
 "thd_ANsynGB", "uM",
 "tp_ANsynGB", "ms",
 "td_ANsynGB", "ms",
 "tau1", "ms",
 "tau2", "ms",
 "e", "mV",
 "wmin", "1",
 "tcon", "ms",
 "tcoff", "ms",
 "enmda", "mV",
 "gNmax", "uS",
 "mgconc", "mM",
 "eta", "/mM",
 "gamma", "/mV",
 "vol", "um3",
 "taurca", "ms",
 "bcap", "1",
 "cainf", "mM",
 "p0", "1",
 "A", "uS",
 "B", "uS",
 "W", "uS",
 "aN", "uS",
 "bN", "uS",
 "ca", "mM",
 "i", "nA",
 "iN", "nA",
 "g", "uS",
 "gN", "uS",
 "camax", "uM",
 "capksum", "uM",
 "capkn", "1",
 0,0
};
 static double A0 = 0;
 static double B0 = 0;
 static double R0 = 0;
 static double W0 = 0;
 static double aN0 = 0;
 static double bN0 = 0;
 static double ca0 = 0;
 static double delta_t = 0.01;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "tau_ANsynGB", &tau_ANsynGB,
 "ps_ANsynGB", &ps_ANsynGB,
 "gp_ANsynGB", &gp_ANsynGB,
 "gd_ANsynGB", &gd_ANsynGB,
 "thp_ANsynGB", &thp_ANsynGB,
 "thd_ANsynGB", &thd_ANsynGB,
 "tp_ANsynGB", &tp_ANsynGB,
 "td_ANsynGB", &td_ANsynGB,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void nrn_cur(_NrnThread*, _Memb_list*, int);
static void  nrn_jacob(_NrnThread*, _Memb_list*, int);
 static void _hoc_destroy_pnt(_vptr) void* _vptr; {
   destroy_point_process(_vptr);
}
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(_NrnThread*, _Memb_list*, int);
static void _ode_matsol(_NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[2]._i
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "6.2.0",
"ANsynGB",
 "tau1",
 "tau2",
 "e",
 "wmin",
 "fCa",
 "tcon",
 "tcoff",
 "enmda",
 "gNmax",
 "mgconc",
 "eta",
 "gamma",
 "vol",
 "taurca",
 "bcap",
 "cainf",
 "p0",
 0,
 "i",
 "iN",
 "g",
 "gN",
 "camax",
 "capksum",
 "capkn",
 0,
 "A",
 "B",
 "W",
 "aN",
 "bN",
 "ca",
 "p",
 "R",
 0,
 0};
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
  if (nrn_point_prop_) {
	_prop->_alloc_seq = nrn_point_prop_->_alloc_seq;
	_p = nrn_point_prop_->param;
	_ppvar = nrn_point_prop_->dparam;
 }else{
 	_p = nrn_prop_data_alloc(_mechtype, 50, _prop);
 	/*initialize range parameters*/
 	tau1 = 0.5;
 	tau2 = 3;
 	e = 0;
 	wmin = 0.2;
 	fCa = 0.1;
 	tcon = 3;
 	tcoff = 150;
 	enmda = 0;
 	gNmax = 1;
 	mgconc = 1;
 	eta = 0.33;
 	gamma = 0.06;
 	vol = 1;
 	taurca = 28.6;
 	bcap = 17;
 	cainf = 0.0001;
 	p0 = 0.5;
  }
 	_prop->param = _p;
 	_prop->param_size = 50;
  if (!nrn_point_prop_) {
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 3, _prop);
  }
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _net_receive(Point_process*, double*, double);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*f)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _ANsynGB_reg() {
	int _vectorized = 1;
  _initlists();
 	_pointtype = point_register_mech(_mechanism,
	 nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init,
	 hoc_nrnpointerindex, 1,
	 _hoc_create_pnt, _hoc_destroy_pnt, _member_func);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
  hoc_register_dparam_size(_mechtype, 3);
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 pnt_receive[_mechtype] = _net_receive;
 pnt_receive_size[_mechtype] = 1;
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 ANsynGB /cygdrive/c/Documents and Settings/bpg/Desktop/Projects/CortDyn/Subprojects/CA1rhythms/Code/Neuron/ThetaGamma/ANsynGB.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double FARADAY = 96485.3;
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int trackca(_threadargsproto_);
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[7], _dlist1[7];
 static int state(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   DA = - A / tau1 ;
   DB = - B / tau2 ;
   DaN = - aN / tcon ;
   DbN = - bN / tcoff ;
   cadrive = - ( 1000000.0 ) * fCa * iN / ( 2.0 * FARADAY * vol ) ;
   if ( cadrive <= 0. ) {
     cadrive = 0. ;
     }
   Dca = cadrive / ( 1.0 + bcap ) + ( cainf - ca ) / taurca ;
   C1 = 1000.0 * ca ;
   Dp = ( - p * ( 1.0 - p ) * ( ps - p ) + gp * ( 1.0 - p ) * heavi ( _threadargscomma_ C1 - thp ) - gd * p * heavi ( _threadargscomma_ C1 - thd ) ) / tau ;
   DR = heavi ( _threadargscomma_ p - ps ) * ( 1.0 - R ) / tp - heavi ( _threadargscomma_ ps - p ) * R / td ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 DA = DA  / (1. - dt*( ( - 1.0 ) / tau1 )) ;
 DB = DB  / (1. - dt*( ( - 1.0 ) / tau2 )) ;
 DaN = DaN  / (1. - dt*( ( - 1.0 ) / tcon )) ;
 DbN = DbN  / (1. - dt*( ( - 1.0 ) / tcoff )) ;
 cadrive = - ( 1000000.0 ) * fCa * iN / ( 2.0 * FARADAY * vol ) ;
 if ( cadrive <= 0. ) {
   cadrive = 0. ;
   }
 Dca = Dca  / (1. - dt*( ( ( ( - 1.0 ) ) ) / taurca )) ;
 C1 = 1000.0 * ca ;
 Dp = Dp  / (1. - dt*( ( ( ((((- 1.0)*(( 1.0 - p )) + (- p)*(( ( - 1.0 ) ))))*(( ps - p )) + (- p * ( 1.0 - p ))*(( ( - 1.0 ) ))) + ((gp)*(( ( - 1.0 ) )))*(heavi ( _threadargscomma_ C1 - thp )) - ((gd)*(1.0))*(heavi ( _threadargscomma_ C1 - thd )) ) ) / tau )) ;
 DR = DR  / (1. - dt*( ( (heavi ( _threadargscomma_ p - ps ))*(( ( - 1.0 ) )) ) / tp - ( (heavi ( _threadargscomma_ ps - p ))*(1.0) ) / td )) ;
 return 0;
}
 /*END CVODE*/
 static int state (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
    A = A + (1. - exp(dt*(( - 1.0 ) / tau1)))*(- ( 0.0 ) / ( ( - 1.0 ) / tau1 ) - A) ;
    B = B + (1. - exp(dt*(( - 1.0 ) / tau2)))*(- ( 0.0 ) / ( ( - 1.0 ) / tau2 ) - B) ;
    aN = aN + (1. - exp(dt*(( - 1.0 ) / tcon)))*(- ( 0.0 ) / ( ( - 1.0 ) / tcon ) - aN) ;
    bN = bN + (1. - exp(dt*(( - 1.0 ) / tcoff)))*(- ( 0.0 ) / ( ( - 1.0 ) / tcoff ) - bN) ;
   cadrive = - ( 1000000.0 ) * fCa * iN / ( 2.0 * FARADAY * vol ) ;
   if ( cadrive <= 0. ) {
     cadrive = 0. ;
     }
    ca = ca + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / taurca)))*(- ( ( cadrive ) / ( 1.0 + bcap ) + ( ( cainf ) ) / taurca ) / ( ( ( ( - 1.0) ) ) / taurca ) - ca) ;
   C1 = 1000.0 * ca ;
    p = p + (1. - exp(dt*(( ( ((((- 1.0)*(( 1.0 - p )) + (- p)*(( ( - 1.0 ) ))))*(( ps - p )) + (- p * ( 1.0 - p ))*(( ( - 1.0 ) ))) + ((gp)*(( ( - 1.0 ) )))*(heavi ( _threadargscomma_ C1 - thp )) - ((gd)*(1.0))*(heavi ( _threadargscomma_ C1 - thd )) ) ) / tau)))*( - p) ;
    R = R + (1. - exp(dt*(( (heavi ( _threadargscomma_ p - ps ))*(( ( - 1.0 ) )) ) / tp - ( (heavi ( _threadargscomma_ ps - p ))*(1.0) ) / td)))*(- ( ( (heavi ( _threadargscomma_ p - ps ))*(( 1.0 )) ) / tp ) / ( ( (heavi ( _threadargscomma_ p - ps ))*(( ( - 1.0) )) ) / tp - ( (heavi ( _threadargscomma_ ps - p ))*(1.0) ) / td ) - R) ;
   }
  return 0;
}
 
double heavi ( _threadargsprotocomma_ double _lx ) {
   double _lheavi;
 _lheavi = 0.0 ;
   if ( _lx > 0.0 ) {
     _lheavi = 1.0 ;
     }
   
return _lheavi;
 }
 
static double _hoc_heavi(void* _vptr) {
 double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   _p = ((Point_process*)_vptr)->_prop->param;
  _ppvar = ((Point_process*)_vptr)->_prop->dparam;
  _thread = _extcall_thread;
  _nt = (_NrnThread*)((Point_process*)_vptr)->_vnt;
 _r =  heavi ( _p, _ppvar, _thread, _nt, *getarg(1) );
 return(_r);
}
 
static int  trackca ( _threadargsproto_ ) {
   if ( C1 > camax ) {
     camax = C1 ;
     }
   if ( C1 < caprev  && caprev > caprev2 ) {
     capksum = capksum + caprev ;
     capkn = capkn + 1.0 ;
     }
   caprev2 = caprev ;
   caprev = C1 ;
    return 0; }
 
static double _hoc_trackca(void* _vptr) {
 double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   _p = ((Point_process*)_vptr)->_prop->param;
  _ppvar = ((Point_process*)_vptr)->_prop->dparam;
  _thread = _extcall_thread;
  _nt = (_NrnThread*)((Point_process*)_vptr)->_vnt;
 _r = 1.;
 trackca ( _p, _ppvar, _thread, _nt );
 return(_r);
}
 
static void _net_receive (_pnt, _args, _lflag) Point_process* _pnt; double* _args; double _lflag; 
{  double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   _thread = (Datum*)0; _nt = (_NrnThread*)_pnt->_vnt;   _p = _pnt->_prop->param; _ppvar = _pnt->_prop->dparam;
  if (_tsav > t){ extern char* hoc_object_name(); hoc_execerror(hoc_object_name(_pnt->ob), ":Event arrived out of order. Must call ParallelContext.set_maxstep AFTER assigning minimum NetCon.delay");}
 _tsav = t; {
   W = ( wmin + ( 1.0 - wmin ) * R ) * _args[0] ;
   A = A + W * factor ;
   B = B + W * factor ;
   aN = aN + wgtN ;
   bN = bN + wgtN ;
   } }
 
static int _ode_count(int _type){ return 7;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
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
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 7; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
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
  A = A0;
  B = B0;
  R = R0;
  W = W0;
  aN = aN0;
  bN = bN0;
  ca = ca0;
  p = p0;
 {
   double _ltp ;
 if ( tau1 / tau2 > .9999 ) {
     tau1 = .9999 * tau2 ;
     }
   A = 0.0 ;
   B = 0.0 ;
   W = 0.0 ;
   _ltp = ( tau1 * tau2 ) / ( tau2 - tau1 ) * log ( tau2 / tau1 ) ;
   factor = - exp ( - _ltp / tau1 ) + exp ( - _ltp / tau2 ) ;
   factor = 1.0 / factor ;
   aN = 0.0 ;
   bN = 0.0 ;
   _ltp = ( tcon * tcoff ) / ( tcoff - tcon ) * log ( tcoff / tcon ) ;
   facN = - exp ( - _ltp / tcon ) + exp ( - _ltp / tcoff ) ;
   wgtN = gNmax / facN ;
   ca = cainf ;
   C1 = 1000.0 * ca ;
   camax = C1 ;
   capksum = 0.0 ;
   capkn = 0.0 ;
   caprev = C1 ;
   caprev2 = C1 ;
   p = p0 ;
   R = heavi ( _threadargscomma_ p - ps ) ;
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
 _tsav = -1e20;
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
   double _ls ;
 trackca ( _threadargs_ ) ;
   g = B - A ;
   i = g * ( v - e ) ;
   _ls = 1.0 / ( 1.0 + eta * mgconc * exp ( - gamma * v ) ) ;
   gN = bN - aN ;
   iN = gN * _ls * ( v - enmda ) ;
   }
 _current += i;
 _current += iN;

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
 _g *=  1.e2/(_nd_area);
 _rhs *= 1.e2/(_nd_area);
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
   state(_p, _ppvar, _thread, _nt);
  
}}
 t = _save;
 }}}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(A) - _p;  _dlist1[0] = &(DA) - _p;
 _slist1[1] = &(B) - _p;  _dlist1[1] = &(DB) - _p;
 _slist1[2] = &(aN) - _p;  _dlist1[2] = &(DaN) - _p;
 _slist1[3] = &(bN) - _p;  _dlist1[3] = &(DbN) - _p;
 _slist1[4] = &(ca) - _p;  _dlist1[4] = &(Dca) - _p;
 _slist1[5] = &(p) - _p;  _dlist1[5] = &(Dp) - _p;
 _slist1[6] = &(R) - _p;  _dlist1[6] = &(DR) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
