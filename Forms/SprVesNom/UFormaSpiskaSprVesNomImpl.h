#ifndef UFormaSpiskaSprVesNomImplH
#define UFormaSpiskaSprVesNomImplH
#include "IFormaSpiskaSprVesNom.h"
#include "UFormaSpiskaSprVesNom.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaSpiskaSprVesNomImpl)) TFormaSpiskaSprVesNomImpl : public IFormaSpiskaSprVesNom, IkanCallBack
{
public:
   TFormaSpiskaSprVesNomImpl();
   ~TFormaSpiskaSprVesNomImpl();
   TFormaSpiskaSprVesNom * Object;
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

//IFormaSpiskaSprVesNom
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IDMSprVesNom* get_DM(void);
   virtual void set_DM(IDMSprVesNom* DM);

   virtual IDMSprGrpVesNom* get_DMGrp(void);
   virtual void set_DMGrp(IDMSprGrpVesNom* DMGrp);

   virtual __int64 get_IdScale(void);
   virtual void set_IdScale(__int64 IdScale);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual __int64 get_IdTypePrice(void);
   virtual void set_IdTypePrice(__int64 IdTypePrice);

   virtual __int64 get_IdVesNom(void);
   virtual void set_IdVesNom(__int64 IdVesNom);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual bool get_Podbor(void);
   virtual void set_Podbor(bool Podbor);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaSpiskaSprVesNomImpl __uuidof(TFormaSpiskaSprVesNomImpl)
#endif
