/* Created by Language version: 6.2.0 */
/* NOT VECTORIZED */
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
 
#define _threadargscomma_ /**/
#define _threadargs_ /**/
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 static double *_p; static Datum *_ppvar;
 
#define t nrn_threads->_t
#define dt nrn_threads->_dt
#define start _p[0]
#define repeat _p[1]
#define noise _p[2]
#define maxfr _p[3]
#define thfreq _p[4]
#define thphase _p[5]
#define thamp _p[6]
#define plx0 _p[7]
#define plsig _p[8]
#define speed _p[9]
#define maxdist _p[10]
#define ispike _p[11]
#define currate _p[12]
#define curuni _p[13]
#define placefr _p[14]
#define thetafr _p[15]
#define xd _p[16]
#define interval _p[17]
#define event _p[18]
#define on _p[19]
#define _tsav _p[20]
#define _nd_area  *_ppvar[0]._pval
#define donotuse	*_ppvar[2]._pval
#define _p_donotuse	_ppvar[2]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 static int hoc_nrnpointerindex =  2;
 /* external NEURON variables */
 /* declaration of user functions */
 static double _hoc_erand();
 static double _hoc_init_sequence();
 static double _hoc_invl();
 static double _hoc_next_invl();
 static double _hoc_noiseFromRandom();
 static double _hoc_rate();
 static double _hoc_seed();
 static double _hoc_unirand();
 static int _mechtype;
extern int nrn_get_mechtype();
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
 _p = _prop->param; _ppvar = _prop->dparam;
 }
 static _hoc_setdata(_vptr) void* _vptr; { Prop* _prop;
 _prop = ((Point_process*)_vptr)->_prop;
   _setdata(_prop);
 }
 /* connect user functions to hoc names */
 static IntFunc hoc_intfunc[] = {
 0,0
};
 static struct Member_func {
	char* _name; double (*_member)();} _member_func[] = {
 "loc", _hoc_loc_pnt,
 "has_loc", _hoc_has_loc,
 "get_loc", _hoc_get_loc_pnt,
 "erand", _hoc_erand,
 "init_sequence", _hoc_init_sequence,
 "invl", _hoc_invl,
 "next_invl", _hoc_next_invl,
 "noiseFromRandom", _hoc_noiseFromRandom,
 "rate", _hoc_rate,
 "seed", _hoc_seed,
 "unirand", _hoc_unirand,
 0, 0
};
#define erand erand_PT1dStim
#define invl invl_PT1dStim
#define rate rate_PT1dStim
#define unirand unirand_PT1dStim
 extern double erand();
 extern double invl();
 extern double rate();
 extern double unirand();
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 "noise", 0, 1,
 "thamp", 0, 1,
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "start", "ms",
 "repeat", "1",
 "maxfr", "Hz",
 "thfreq", "Hz",
 "plx0", "cm",
 "plsig", "cm",
 "speed", "cm/s",
 "maxdist", "cm",
 "placefr", "Hz",
 "thetafr", "Hz",
 "xd", "cm",
 0,0
};
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(), nrn_init(), nrn_state();
 static void _hoc_destroy_pnt(_vptr) void* _vptr; {
   destroy_point_process(_vptr);
}
 /* connect range variables in _p that hoc is supposed to know about */
 static char *_mechanism[] = {
 "6.2.0",
"PT1dStim",
 "start",
 "repeat",
 "noise",
 "maxfr",
 "thfreq",
 "thphase",
 "thamp",
 "plx0",
 "plsig",
 "speed",
 "maxdist",
 0,
 "ispike",
 "currate",
 "curuni",
 "placefr",
 "thetafr",
 "xd",
 0,
 0,
 "donotuse",
 0};
 
static void nrn_alloc(_prop)
	Prop *_prop;
{
	Prop *prop_ion, *need_memb();
	double *_p; Datum *_ppvar;
  if (nrn_point_prop_) {
	_prop->_alloc_seq = nrn_point_prop_->_alloc_seq;
	_p = nrn_point_prop_->param;
	_ppvar = nrn_point_prop_->dparam;
 }else{
 	_p = nrn_prop_data_alloc(_mechtype, 21, _prop);
 	/*initialize range parameters*/
 	start = 50;
 	repeat = 0;
 	noise = 0;
 	maxfr = 15;
 	thfreq = 5;
 	thphase = 0;
 	thamp = 1;
 	plx0 = 100;
 	plsig = 10;
 	speed = 40;
 	maxdist = 200;
  }
 	_prop->param = _p;
 	_prop->param_size = 21;
  if (!nrn_point_prop_) {
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
  }
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 
}
 static _initlists();
 
#define _tqitem &(_ppvar[3]._pvoid)
 static _net_receive();
 typedef (*_Pfrv)();
 extern _Pfrv* pnt_receive;
 extern short* pnt_receive_size;
 _PT1dstim_reg() {
	int _vectorized = 0;
  _initlists();
 	_pointtype = point_register_mech(_mechanism,
	 nrn_alloc,0, 0, 0, nrn_init,
	 hoc_nrnpointerindex,
	 _hoc_create_pnt, _hoc_destroy_pnt, _member_func,
	 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
  hoc_register_dparam_size(_mechtype, 4);
 add_nrn_artcell(_mechtype, 3);
 add_nrn_has_net_event(_mechtype);
 pnt_receive[_mechtype] = _net_receive;
 pnt_receive_size[_mechtype] = 1;
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 PT1dStim /cygdrive/c/Documents and Settings/bpg/Desktop/Projects/CortDyn/Subprojects/CA1rhythms/Code/Neuron/ThetaGamma/PT1dstim.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double PI = 3.14159;
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static _modl_cleanup(){ _match_recurse=1;}
static init_sequence();
static next_invl();
static noiseFromRandom();
static seed();
 
static int  seed (  _lx )  
	double _lx ;
 {
   set_seed ( _lx ) ;
    return 0; }
 
static double _hoc_seed(_vptr) void* _vptr; {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 seed (  *getarg(1) ) ;
 return(_r);
}
 
static int  init_sequence (  _lt )  
	double _lt ;
 {
   on = 1.0 ;
   event = 0.0 ;
   ispike = 0.0 ;
    return 0; }
 
static double _hoc_init_sequence(_vptr) void* _vptr; {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 init_sequence (  *getarg(1) ) ;
 return(_r);
}
 
double invl (  _lmean )  
	double _lmean ;
 {
   double _linvl;
 if ( _lmean <= 0. ) {
     _lmean = .01 ;
     }
   if ( noise  == 0.0 ) {
     _linvl = _lmean ;
     }
   else {
     _linvl = ( 1. - noise ) * _lmean + noise * _lmean * erand ( _threadargs_ ) ;
     }
   
return _linvl;
 }
 
static double _hoc_invl(_vptr) void* _vptr; {
 double _r;
    _hoc_setdata(_vptr);
 _r =  invl (  *getarg(1) ) ;
 return(_r);
}
 
/*VERBATIM*/
double nrn_random_pick(void* r);
void* nrn_random_arg(int argpos);
 
double erand (  )  {
   double _lerand;
 
/*VERBATIM*/
	if (_p_donotuse) {
		/*
		:Supports separate independent but reproducible streams for
		: each instance. However, the corresponding hoc Random
		: distribution MUST be set to Random.negexp(1)
		*/
		_lerand = nrn_random_pick(_p_donotuse);
	}else{
 _lerand = exprand ( 1.0 ) ;
   
/*VERBATIM*/
	}
 
return _lerand;
 }
 
static double _hoc_erand(_vptr) void* _vptr; {
 double _r;
    _hoc_setdata(_vptr);
 _r =  erand (  ) ;
 return(_r);
}
 
static int  noiseFromRandom (  )  {
   
/*VERBATIM*/
 {
	void** pv = (void**)(&_p_donotuse);
	if (ifarg(1)) {
		*pv = nrn_random_arg(1);
	}else{
		*pv = (void*)0;
	}
 }
  return 0; }
 
static double _hoc_noiseFromRandom(_vptr) void* _vptr; {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 noiseFromRandom (  ) ;
 return(_r);
}
 
static int  next_invl (  )  {
   interval = 1000.0 / maxfr ;
   event = invl ( _threadargscomma_ interval ) ;
    return 0; }
 
static double _hoc_next_invl(_vptr) void* _vptr; {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 next_invl (  ) ;
 return(_r);
}
 
static _net_receive (_pnt, _args, _lflag) Point_process* _pnt; double* _args; double _lflag; 
{    _p = _pnt->_prop->param; _ppvar = _pnt->_prop->dparam;
  if (_tsav > t){ extern char* hoc_object_name(); hoc_execerror(hoc_object_name(_pnt->ob), ":Event arrived out of order. Must call ParallelContext.set_maxstep AFTER assigning minimum NetCon.delay");}
 _tsav = t;   if (_lflag == 1. ) {*(_tqitem) = 0;}
 {
   if ( _lflag  == 0.0 ) {
     if ( _args[0] > 0.0  && on  == 0.0 ) {
       init_sequence ( _threadargscomma_ t ) ;
       next_invl ( _threadargs_ ) ;
       event = event - interval * ( 1. - noise ) ;
       artcell_net_send ( _tqitem, _args, _pnt, t +  event , 1.0 ) ;
       }
     else if ( _args[0] < 0.0 ) {
       on = 0.0 ;
       }
     }
   if ( _lflag  == 3.0 ) {
     if ( on  == - 1.0 ) {
       init_sequence ( _threadargscomma_ t ) ;
       artcell_net_send ( _tqitem, _args, _pnt, t +  0.0 , 1.0 ) ;
       }
     }
   if ( _lflag  == 1.0  && on  == 1.0 ) {
     if ( rate ( _threadargs_ ) / maxfr > unirand ( _threadargs_ ) ) {
       ispike = ispike + 1.0 ;
       net_event ( _pnt, t ) ;
       printf ( "Send event\n" ) ;
       }
     next_invl ( _threadargs_ ) ;
     if ( on  == 1.0 ) {
       artcell_net_send ( _tqitem, _args, _pnt, t +  event , 1.0 ) ;
       }
     }
   } }
 
double rate (  )  {
   double _lrate;
 _lrate = 0.0 ;
   if ( t >= start  && xd < maxdist ) {
     xd = ( t - start ) * speed / 1000.0 ;
     placefr = maxfr * exp ( - pow( ( xd - plx0 ) , 2.0 ) / ( 2.0 * pow( plsig , 2.0 ) ) ) ;
     thetafr = thamp * cos ( ( 2.0 * PI * thfreq * ( t - start ) / 1000.0 ) + ( 2.0 * PI * thphase / 360.0 ) ) + ( 1.0 - thamp ) ;
     _lrate = placefr * thetafr ;
     if ( _lrate < 0.0 ) {
       _lrate = 0.0 ;
       }
     }
   
return _lrate;
 }
 
static double _hoc_rate(_vptr) void* _vptr; {
 double _r;
    _hoc_setdata(_vptr);
 _r =  rate (  ) ;
 return(_r);
}
 
double unirand (  )  {
   double _lunirand;
 _lunirand = scop_random ( ) ;
   
return _lunirand;
 }
 
static double _hoc_unirand(_vptr) void* _vptr; {
 double _r;
    _hoc_setdata(_vptr);
 _r =  unirand (  ) ;
 return(_r);
}

static void initmodel() {
  int _i; double _save;_ninits++;
{
 {
   on = - 1.0 ;
   ispike = 0.0 ;
   xd = 0.0 ;
   interval = 1000.0 / maxfr ;
   placefr = 0.0 ;
   thetafr = 0.0 ;
   if ( noise < 0.0 ) {
     noise = 0.0 ;
     }
   if ( noise > 1.0 ) {
     noise = 1.0 ;
     }
   if ( start >= 0.0 ) {
     event = start + invl ( _threadargscomma_ interval ) - interval * ( 1. - noise ) ;
     if ( event < 0.0 ) {
       event = 0.0 ;
       }
     artcell_net_send ( _tqitem, (double*)0, _ppvar[1]._pvoid, t +  event , 3.0 ) ;
     }
   }

}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _tsav = -1e20;
 initmodel();
}}

static double _nrn_current(double _v){double _current=0.;v=_v;{
} return _current;
}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type){
 double _break, _save;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
 _break = t + .5*dt; _save = t;
 v=_v;
{
}}

}

static terminal(){}

static _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
_first = 0;
}
