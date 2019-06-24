#ifndef UREM_FormaElementaSprSostImplH
#define UREM_FormaElementaSprSostImplH
#include "IREM_FormaElementaSprSost.h"
#include "UREM_FormaElementaSprSost.h"
//---------------------------------------------------------------
class __declspec(uuid("{86C9E4E7-4F57-4412-A377-896B19673950}")) TREM_FormaElementaSprSostImpl : public IREM_FormaElementaSprSost, IkanCallBack
{
public:
   TREM_FormaElementaSprSostImpl();
   ~TREM_FormaElementaSprSostImpl();
   TREM_FormaElementaSprSost * Object;
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

//IREM_FormaElementaSprSost
   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IREM_DMSprSost * get_DM(void);
   virtual void set_DM(IREM_DMSprSost * DM);

   virtual void UpdateForm(void);
};
#define CLSID_TREM_FormaElementaSprSostImpl __uuidof(TREM_FormaElementaSprSostImpl)
#endif
