#ifndef UFormaSpiskaSprCountryImplH
#define UFormaSpiskaSprCountryImplH
#include "IFormaSpiskaSprCountry.h"
#include "UFormaSpiskaSprCountry.h"
//---------------------------------------------------------------
class __declspec(uuid("{8D3C3555-0D12-4818-A03D-29F173A0AB23}")) TFormaSpiskaSprCountryImpl : public IFormaSpiskaSprCountry, IkanCallBack
{
public:
   TFormaSpiskaSprCountryImpl();
   ~TFormaSpiskaSprCountryImpl();
   TFormaSpiskaSprCountry * Object;
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

//IFormaSpiskaSprCountry
   virtual IDMSprCountry * get_DM(void);
   virtual void set_DM(IDMSprCountry * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);


   virtual void OpenFormElement(void);
   virtual void OpenFormNewElement(void);
   virtual void DeleteElement(void);
   virtual void UpdateForm(void);
};
#define CLSID_TFormaSpiskaSprCountryImpl __uuidof(TFormaSpiskaSprCountryImpl)
#endif
