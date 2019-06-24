#ifndef UHOT_FormaSpiskaSprCelPriesdaImplH
#define UHOT_FormaSpiskaSprCelPriesdaImplH
#include "IHOT_FormaSpiskaSprCelPriesda.h"
#include "UHOT_FormaSpiskaSprCelPriesda.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_THOT_FormaSpiskaSprCelPriesdaImpl)) THOT_FormaSpiskaSprCelPriesdaImpl : public IHOT_FormaSpiskaSprCelPriesda, IkanCallBack
{
public:
   THOT_FormaSpiskaSprCelPriesdaImpl();
   ~THOT_FormaSpiskaSprCelPriesdaImpl();
   THOT_FormaSpiskaSprCelPriesda * Object;
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

//IHOT_FormaSpiskaSprCelPriesda
   virtual IHOT_DMSprCelPriesda * get_DM(void);
   virtual void set_DM(IHOT_DMSprCelPriesda * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void UpdateForm(void);
};
#define CLSID_THOT_FormaSpiskaSprCelPriesdaImpl __uuidof(THOT_FormaSpiskaSprCelPriesdaImpl)
#endif
