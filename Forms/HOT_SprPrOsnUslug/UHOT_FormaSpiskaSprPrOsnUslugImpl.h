#ifndef UHOT_FormaSpiskaSprPrOsnUslugImplH
#define UHOT_FormaSpiskaSprPrOsnUslugImplH
#include "IHOT_FormaSpiskaSprPrOsnUslug.h"
#include "UHOT_FormaSpiskaSprPrOsnUslug.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_THOT_FormaSpiskaSprPrOsnUslImpl))THOT_FormaSpiskaSprPrOsnUslugImpl : public IHOT_FormaSpiskaSprPrOsnUslug, IkanCallBack
{
public:
   THOT_FormaSpiskaSprPrOsnUslugImpl();
   ~THOT_FormaSpiskaSprPrOsnUslugImpl();
   THOT_FormaSpiskaSprPrOsnUslug * Object;
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

//IHOT_FormaSpiskaSprPrOsnUslug
   virtual IHOT_DMSprPrOsnUslug * get_DM(void);
   virtual void set_DM(IHOT_DMSprPrOsnUslug * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

};
#define CLSID_THOT_FormaSpiskaSprPrOsnUslugImpl __uuidof(THOT_FormaSpiskaSprPrOsnUslugImpl)
#endif
