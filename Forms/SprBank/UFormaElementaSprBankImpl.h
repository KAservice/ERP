#ifndef UFormaElementaSprBankImplH
#define UFormaElementaSprBankImplH
#include "IFormaElementaSprBank.h"
#include "UFormaElementaSprBank.h"
//---------------------------------------------------------------
class __declspec(uuid("{9D36FEE5-1706-4AB6-897B-81ADEA5A80C6}"))TFormaElementaSprBankImpl : public IFormaElementaSprBank, IkanCallBack
{
public:
   TFormaElementaSprBankImpl();
   ~TFormaElementaSprBankImpl();
   TFormaElementaSprBank * Object;
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

//IFormaElementaSprBank
   virtual IDMSprBank * get_DM(void);
   virtual void set_DM(IDMSprBank * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);



};
#define CLSID_TFormaElementaSprBankImpl __uuidof(TFormaElementaSprBankImpl)
#endif
