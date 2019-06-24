#ifndef UFormaSpiskaSprBankImplH
#define UFormaSpiskaSprBankImplH
#include "IFormaSpiskaSprBank.h"
#include "UFormaSpiskaSprBank.h"
//---------------------------------------------------------------
class __declspec(uuid("{E4216636-8A51-4785-85D1-03845FCF80B3}")) TFormaSpiskaSprBankImpl : public IFormaSpiskaSprBank, IkanCallBack
{
public:
   TFormaSpiskaSprBankImpl();
   ~TFormaSpiskaSprBankImpl();
   TFormaSpiskaSprBank * Object;
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

//IFormaSpiskaSprBank
   virtual IDMSprBank * get_DM(void);
   virtual void set_DM(IDMSprBank * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);



   virtual void OpenFormElement();
   virtual void OpenFormNewElement();
   virtual void DeleteElement();
};
#define CLSID_TFormaSpiskaSprBankImpl __uuidof(TFormaSpiskaSprBankImpl)
#endif
