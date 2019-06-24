#ifndef UREM_FormaSpiskaSprTypeRemontImplH
#define UREM_FormaSpiskaSprTypeRemontImplH
#include "IREM_FormaSpiskaSprTypeRemont.h"
#include "UREM_FormaSpiskaSprTypeRemont.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaSpiskaSprTypeRemontImpl))TREM_FormaSpiskaSprTypeRemontImpl : public IREM_FormaSpiskaSprTypeRemont, IkanCallBack
{
public:
   TREM_FormaSpiskaSprTypeRemontImpl();
   ~TREM_FormaSpiskaSprTypeRemontImpl();
   TREM_FormaSpiskaSprTypeRemont * Object;
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

//IREM_FormaSpiskaSprTypeRemont
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
#define CLSID_TREM_FormaSpiskaSprTypeRemontImpl __uuidof(TREM_FormaSpiskaSprTypeRemontImpl)
#endif
