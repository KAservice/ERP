#ifndef UFormaSpiskaSprBVNomTouchImplH
#define UFormaSpiskaSprBVNomTouchImplH
#include "IFormaSpiskaSprBVNomTouch.h"
#include "UFormaSpiskaSprBVNomTouch.h"
//---------------------------------------------------------------
class __declspec(uuid("{52548E8F-C37D-467F-8E6F-5A54C7223FE9}")) TFormaSpiskaSprBVNomTouchImpl : public IFormaSpiskaSprBVNomTouch, IkanCallBack
{
public:
   TFormaSpiskaSprBVNomTouchImpl();
   ~TFormaSpiskaSprBVNomTouchImpl();
   TFormaSpiskaSprBVNomTouch * Object;
   int NumRefs;
   bool flDeleteObject;
   void DeleteImpl(void);

   //IUnknown
   virtual int kanQueryInterface(REFIID id_interface,void ** ppv);
   virtual int kanAddRef(void);
   virtual int kanRelease(void);

   //IMainInterface
   virtual int  get_CodeError(void);
   virtual void set_CodeError(int CodeError);
   virtual UnicodeString  get_TextError(void);
   virtual void set_TextError(UnicodeString  TextError);
   virtual int Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object);
   virtual int Done(void);

   //IkanCallBack  
   virtual int kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end);

//IFormaSpiskaSprBVNomTouch
   virtual TpFIBDataSet * get_Grp(void);
   virtual void set_Grp(TpFIBDataSet * Grp);

   virtual TpFIBDataSet * get_El(void);
   virtual void set_El(TpFIBDataSet * El);

   virtual TFIBIntegerField * get_ElCODE_BVNOM(void);
   virtual void set_ElCODE_BVNOM(TFIBIntegerField * ElCODE_BVNOM);

   virtual TFIBIntegerField * get_ElTNOM(void);
   virtual void set_ElTNOM(TFIBIntegerField * ElTNOM);

   virtual TFIBBCDField * get_GrpID_GBVNOM(void);
   virtual void set_GrpID_GBVNOM(TFIBBCDField * GrpID_GBVNOM);

   virtual TFIBBCDField * get_GrpIDGRP_GBVNOM(void);
   virtual void set_GrpIDGRP_GBVNOM(TFIBBCDField * GrpIDGRP_GBVNOM);

   virtual TFIBBCDField * get_GrpIDPOD_GBVNOM(void);
   virtual void set_GrpIDPOD_GBVNOM(TFIBBCDField * GrpIDPOD_GBVNOM);

   virtual TFIBBCDField * get_ElID_BVNOM(void);
   virtual void set_ElID_BVNOM(TFIBBCDField * ElID_BVNOM);

   virtual TFIBBCDField * get_ElIDPOD_BVNOM(void);
   virtual void set_ElIDPOD_BVNOM(TFIBBCDField * ElIDPOD_BVNOM);

   virtual TFIBBCDField * get_ElIDNOM_BVNOM(void);
   virtual void set_ElIDNOM_BVNOM(TFIBBCDField * ElIDNOM_BVNOM);

   virtual TFIBBCDField * get_ElIDGRP_BVNOM(void);
   virtual void set_ElIDGRP_BVNOM(TFIBBCDField * ElIDGRP_BVNOM);

   virtual TFIBBCDField * get_ElIDBASEDNOM(void);
   virtual void set_ElIDBASEDNOM(TFIBBCDField * ElIDBASEDNOM);

   virtual TFIBWideStringField * get_ElNAMENOM(void);
   virtual void set_ElNAMENOM(TFIBWideStringField * ElNAMENOM);

   virtual TFIBWideStringField * get_ElKRNAMENOM(void);
   virtual void set_ElKRNAMENOM(TFIBWideStringField * ElKRNAMENOM);

   virtual TFIBWideStringField * get_GrpNAME_GBVNOM(void);
   virtual void set_GrpNAME_GBVNOM(TFIBWideStringField * GrpNAME_GBVNOM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual bool get_MnVibor(void);
   virtual void set_MnVibor(bool MnVibor);

   virtual bool get_ZaprosEd(void);
   virtual void set_ZaprosEd(bool ZaprosEd);

   virtual __int64 get_IdFirm(void);
   virtual void set_IdFirm(__int64 IdFirm);

   virtual __int64 get_IdSklad(void);
   virtual void set_IdSklad(__int64 IdSklad);

   virtual __int64 get_IdNom(void);
   virtual void set_IdNom(__int64 IdNom);

   virtual __int64 get_IdEd(void);
   virtual void set_IdEd(__int64 IdEd);

   virtual String get_NameEd(void);
   virtual void set_NameEd(String NameEd);

   virtual double get_KFEd(void);
   virtual void set_KFEd(double KFEd);

   virtual double get_Kol(void);
   virtual void set_Kol(double Kol);

   virtual __int64 get_IdPod(void);
   virtual void set_IdPod(__int64 IdPod);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

};
#define CLSID_TFormaSpiskaSprBVNomTouchImpl __uuidof(TFormaSpiskaSprBVNomTouchImpl)
#endif
