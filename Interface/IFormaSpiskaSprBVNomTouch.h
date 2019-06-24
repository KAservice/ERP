#ifndef UIFormaSpiskaSprBVNomTouchH
#define UIFormaSpiskaSprBVNomTouchH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{FF83C670-2851-42AC-9214-8A33BF5A7CD8}")) IFormaSpiskaSprBVNomTouch : public IMainInterface
{
public:
   __property TpFIBDataSet * Grp = {read = get_Grp , write = set_Grp};
   virtual TpFIBDataSet * get_Grp(void)=0;
   virtual void set_Grp(TpFIBDataSet * Grp)=0;

   __property TpFIBDataSet * El = {read = get_El , write = set_El};
   virtual TpFIBDataSet * get_El(void)=0;
   virtual void set_El(TpFIBDataSet * El)=0;

   __property TFIBIntegerField * ElCODE_BVNOM = {read = get_ElCODE_BVNOM , write = set_ElCODE_BVNOM};
   virtual TFIBIntegerField * get_ElCODE_BVNOM(void)=0;
   virtual void set_ElCODE_BVNOM(TFIBIntegerField * ElCODE_BVNOM)=0;

   __property TFIBIntegerField * ElTNOM = {read = get_ElTNOM , write = set_ElTNOM};
   virtual TFIBIntegerField * get_ElTNOM(void)=0;
   virtual void set_ElTNOM(TFIBIntegerField * ElTNOM)=0;

   __property TFIBBCDField * GrpID_GBVNOM = {read = get_GrpID_GBVNOM , write = set_GrpID_GBVNOM};
   virtual TFIBBCDField * get_GrpID_GBVNOM(void)=0;
   virtual void set_GrpID_GBVNOM(TFIBBCDField * GrpID_GBVNOM)=0;

   __property TFIBBCDField * GrpIDGRP_GBVNOM = {read = get_GrpIDGRP_GBVNOM , write = set_GrpIDGRP_GBVNOM};
   virtual TFIBBCDField * get_GrpIDGRP_GBVNOM(void)=0;
   virtual void set_GrpIDGRP_GBVNOM(TFIBBCDField * GrpIDGRP_GBVNOM)=0;

   __property TFIBBCDField * GrpIDPOD_GBVNOM = {read = get_GrpIDPOD_GBVNOM , write = set_GrpIDPOD_GBVNOM};
   virtual TFIBBCDField * get_GrpIDPOD_GBVNOM(void)=0;
   virtual void set_GrpIDPOD_GBVNOM(TFIBBCDField * GrpIDPOD_GBVNOM)=0;

   __property TFIBBCDField * ElID_BVNOM = {read = get_ElID_BVNOM , write = set_ElID_BVNOM};
   virtual TFIBBCDField * get_ElID_BVNOM(void)=0;
   virtual void set_ElID_BVNOM(TFIBBCDField * ElID_BVNOM)=0;

   __property TFIBBCDField * ElIDPOD_BVNOM = {read = get_ElIDPOD_BVNOM , write = set_ElIDPOD_BVNOM};
   virtual TFIBBCDField * get_ElIDPOD_BVNOM(void)=0;
   virtual void set_ElIDPOD_BVNOM(TFIBBCDField * ElIDPOD_BVNOM)=0;

   __property TFIBBCDField * ElIDNOM_BVNOM = {read = get_ElIDNOM_BVNOM , write = set_ElIDNOM_BVNOM};
   virtual TFIBBCDField * get_ElIDNOM_BVNOM(void)=0;
   virtual void set_ElIDNOM_BVNOM(TFIBBCDField * ElIDNOM_BVNOM)=0;

   __property TFIBBCDField * ElIDGRP_BVNOM = {read = get_ElIDGRP_BVNOM , write = set_ElIDGRP_BVNOM};
   virtual TFIBBCDField * get_ElIDGRP_BVNOM(void)=0;
   virtual void set_ElIDGRP_BVNOM(TFIBBCDField * ElIDGRP_BVNOM)=0;

   __property TFIBBCDField * ElIDBASEDNOM = {read = get_ElIDBASEDNOM , write = set_ElIDBASEDNOM};
   virtual TFIBBCDField * get_ElIDBASEDNOM(void)=0;
   virtual void set_ElIDBASEDNOM(TFIBBCDField * ElIDBASEDNOM)=0;

   __property TFIBWideStringField * ElNAMENOM = {read = get_ElNAMENOM , write = set_ElNAMENOM};
   virtual TFIBWideStringField * get_ElNAMENOM(void)=0;
   virtual void set_ElNAMENOM(TFIBWideStringField * ElNAMENOM)=0;

   __property TFIBWideStringField * ElKRNAMENOM = {read = get_ElKRNAMENOM , write = set_ElKRNAMENOM};
   virtual TFIBWideStringField * get_ElKRNAMENOM(void)=0;
   virtual void set_ElKRNAMENOM(TFIBWideStringField * ElKRNAMENOM)=0;

   __property TFIBWideStringField * GrpNAME_GBVNOM = {read = get_GrpNAME_GBVNOM , write = set_GrpNAME_GBVNOM};
   virtual TFIBWideStringField * get_GrpNAME_GBVNOM(void)=0;
   virtual void set_GrpNAME_GBVNOM(TFIBWideStringField * GrpNAME_GBVNOM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property bool MnVibor = {read = get_MnVibor , write = set_MnVibor};
   virtual bool get_MnVibor(void)=0;
   virtual void set_MnVibor(bool MnVibor)=0;

   __property bool ZaprosEd = {read = get_ZaprosEd , write = set_ZaprosEd};
   virtual bool get_ZaprosEd(void)=0;
   virtual void set_ZaprosEd(bool ZaprosEd)=0;

   __property __int64 IdFirm = {read = get_IdFirm , write = set_IdFirm};
   virtual __int64 get_IdFirm(void)=0;
   virtual void set_IdFirm(__int64 IdFirm)=0;

   __property __int64 IdSklad = {read = get_IdSklad , write = set_IdSklad};
   virtual __int64 get_IdSklad(void)=0;
   virtual void set_IdSklad(__int64 IdSklad)=0;

   __property __int64 IdNom = {read = get_IdNom , write = set_IdNom};
   virtual __int64 get_IdNom(void)=0;
   virtual void set_IdNom(__int64 IdNom)=0;

   __property __int64 IdEd = {read = get_IdEd , write = set_IdEd};
   virtual __int64 get_IdEd(void)=0;
   virtual void set_IdEd(__int64 IdEd)=0;

   __property String NameEd = {read = get_NameEd , write = set_NameEd};
   virtual String get_NameEd(void)=0;
   virtual void set_NameEd(String NameEd)=0;

   __property double KFEd = {read = get_KFEd , write = set_KFEd};
   virtual double get_KFEd(void)=0;
   virtual void set_KFEd(double KFEd)=0;

   __property double Kol = {read = get_Kol , write = set_Kol};
   virtual double get_Kol(void)=0;
   virtual void set_Kol(double Kol)=0;

   __property __int64 IdPod = {read = get_IdPod , write = set_IdPod};
   virtual __int64 get_IdPod(void)=0;
   virtual void set_IdPod(__int64 IdPod)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

};
#define IID_IFormaSpiskaSprBVNomTouch __uuidof(IFormaSpiskaSprBVNomTouch)
#endif
