#ifndef UHOT_FormaElementaSprPrOsnUslugImplH
#define UHOT_FormaElementaSprPrOsnUslugImplH
#include "IHOT_FormaElementaSprPrOsnUslug.h"
#include "UHOT_FormaElementaSprPrOsnUslug.h"
//---------------------------------------------------------------
class __declspec(uuid("{5FB67103-EB90-4373-854A-970BAB0C10A4}")) THOT_FormaElementaSprPrOsnUslugImpl : public IHOT_FormaElementaSprPrOsnUslug, IkanCallBack
{
public:
   THOT_FormaElementaSprPrOsnUslugImpl();
   ~THOT_FormaElementaSprPrOsnUslugImpl();
   THOT_FormaElementaSprPrOsnUslug * Object;
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

//IHOT_FormaElementaSprPrOsnUslug
   virtual IHOT_DMSprPrOsnUslug * get_DM(void);
   virtual void set_DM(IHOT_DMSprPrOsnUslug * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void UpdateForm(void);
};
#define CLSID_THOT_FormaElementaSprPrOsnUslugImpl __uuidof(THOT_FormaElementaSprPrOsnUslugImpl)
#endif
