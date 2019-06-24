#ifndef UFormaSpiskaSprEdTouchImplH
#define UFormaSpiskaSprEdTouchImplH
#include "IFormaSpiskaSprEdTouch.h"
#include "UFormaSpiskaSprEdTouch.h"
//---------------------------------------------------------------
class __declspec(uuid("{05CF09B4-0B7E-46AB-A034-29733F0A29ED}")) TFormaSpiskaSprEdTouchImpl : public IFormaSpiskaSprEdTouch, IkanCallBack
{
public:
   TFormaSpiskaSprEdTouchImpl();
   ~TFormaSpiskaSprEdTouchImpl();
   TFormaSpiskaSprEdTouch * Object;
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

//IFormaSpiskaSprEdTouch
   virtual TpFIBDataSet * get_El(void);
   virtual void set_El(TpFIBDataSet * El);

   virtual TFIBBCDField * get_ElKFED(void);
   virtual void set_ElKFED(TFIBBCDField * ElKFED);

   virtual TFIBIntegerField * get_ElTSHED(void);
   virtual void set_ElTSHED(TFIBIntegerField * ElTSHED);

   virtual TFIBSmallIntField * get_ElNEISPED(void);
   virtual void set_ElNEISPED(TFIBSmallIntField * ElNEISPED);

   virtual TFIBBCDField * get_ElZNACH_PRICE(void);
   virtual void set_ElZNACH_PRICE(TFIBBCDField * ElZNACH_PRICE);

   virtual TFIBBCDField * get_ElIDED(void);
   virtual void set_ElIDED(TFIBBCDField * ElIDED);

   virtual TFIBBCDField * get_ElIDNOMED(void);
   virtual void set_ElIDNOMED(TFIBBCDField * ElIDNOMED);

   virtual TFIBBCDField * get_ElIDOKEIED(void);
   virtual void set_ElIDOKEIED(TFIBBCDField * ElIDOKEIED);

   virtual TFIBWideStringField * get_ElNAMEED(void);
   virtual void set_ElNAMEED(TFIBWideStringField * ElNAMEED);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual UnicodeString get_NameNom(void);
   virtual void set_NameNom(UnicodeString NameNom);

   virtual bool get_MnVibor(void);
   virtual void set_MnVibor(bool MnVibor);

   virtual __int64 get_IdFirm(void);
   virtual void set_IdFirm(__int64 IdFirm);

   virtual __int64 get_IdSklad(void);
   virtual void set_IdSklad(__int64 IdSklad);

   virtual __int64 get_IdNom(void);
   virtual void set_IdNom(__int64 IdNom);

   virtual __int64 get_IdBasEd(void);
   virtual void set_IdBasEd(__int64 IdBasEd);

   virtual __int64 get_IdEd(void);
   virtual void set_IdEd(__int64 IdEd);

   virtual int get_TypeNom(void);
   virtual void set_TypeNom(int TypeNom);

   virtual double get_Kol(void);
   virtual void set_Kol(double Kol);

   virtual __int64 get_IdPod(void);
   virtual void set_IdPod(__int64 IdPod);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual void UpdateForm(void);
   virtual void OpenSpisokEd(void);
   virtual void OpenElement(int Num);
};
#define CLSID_TFormaSpiskaSprEdTouchImpl __uuidof(TFormaSpiskaSprEdTouchImpl)
#endif
