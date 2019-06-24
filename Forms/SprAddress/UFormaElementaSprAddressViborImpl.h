#ifndef UFormaElementaSprAddressViborImplH
#define UFormaElementaSprAddressViborImplH
#include "IFormaElementaSprAddressVibor.h"
#include "UFormaElementaSprAddressVibor.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaElementaSprAddressViborImpl)) TFormaElementaSprAddressViborImpl : public IFormaElementaSprAddressVibor, IkanCallBack
{
public:
   TFormaElementaSprAddressViborImpl();
   ~TFormaElementaSprAddressViborImpl();
   TFormaElementaSprAddressVibor * Object;
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

//IFormaElementaSprAddressVibor
   virtual IDMSprAddressRegion * get_DM_Region(void);
   virtual void set_DM_Region(IDMSprAddressRegion * DM_Region);

   virtual IDMSprAddressRayon * get_DM_Rayon(void);
   virtual void set_DM_Rayon(IDMSprAddressRayon * DM_Rayon);

   virtual IDMSprAddressNasPunkt * get_DM_NasPunkt(void);
   virtual void set_DM_NasPunkt(IDMSprAddressNasPunkt * DM_NasPunkt);

   virtual IDMSprAddressStreet * get_DM_Street(void);
   virtual void set_DM_Street(IDMSprAddressStreet * DM_Street);

   virtual IDMSprAddressDom * get_DM_Dom(void);
   virtual void set_DM_Dom(IDMSprAddressDom * DM_Dom);

   virtual IDMSprAddressStroen * get_DM_Stroen(void);
   virtual void set_DM_Stroen(IDMSprAddressStroen * DM_Stroen);

   virtual IDMSprAddressKV * get_DM_KV(void);
   virtual void set_DM_KV(IDMSprAddressKV * DM_KV);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaElementaSprAddressViborImpl __uuidof(TFormaElementaSprAddressViborImpl)
#endif
