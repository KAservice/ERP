#ifndef UREM_FormaSpiskaSprTypeRemImplH
#define UREM_FormaSpiskaSprTypeRemImplH
#include "IREM_FormaSpiskaSprTypeRem.h"
#include "UREM_FormaSpiskaSprTypeRem.h"
//---------------------------------------------------------------
class __declspec(uuid("{5788AE78-9990-4E81-8A12-77B65E42A028}")) TREM_FormaSpiskaSprTypeRemImpl : public IREM_FormaSpiskaSprTypeRem, IkanCallBack
{
public:
   TREM_FormaSpiskaSprTypeRemImpl();
   ~TREM_FormaSpiskaSprTypeRemImpl();
   TREM_FormaSpiskaSprTypeRem * Object;
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

//IREM_FormaSpiskaSprTypeRem
   virtual IREM_DMSprTypeRemont * get_DM(void);
   virtual void set_DM(IREM_DMSprTypeRemont * DM);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual UnicodeString get_TextMessage(void);
   virtual void set_TextMessage(UnicodeString TextMessage);

   virtual void OpenFormElement();
   virtual void OpenFormNewElement();
   virtual void DeleteElement();
};
#define CLSID_TREM_FormaSpiskaSprTypeRemImpl __uuidof(TREM_FormaSpiskaSprTypeRemImpl)
#endif
