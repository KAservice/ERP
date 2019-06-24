#ifndef UFormaSpiskaSprProducerEdImplH
#define UFormaSpiskaSprProducerEdImplH
#include "IFormaSpiskaSprProducerEd.h"
#include "UFormaSpiskaSprProducerEd.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaSpiskaSprProducerEdImpl)) TFormaSpiskaSprProducerEdImpl : public IFormaSpiskaSprProducerEd, IkanCallBack
{
public:
   TFormaSpiskaSprProducerEdImpl();
   ~TFormaSpiskaSprProducerEdImpl();
   TFormaSpiskaSprProducerEd * Object;
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

//IFormaSpiskaSprProducerEd
   virtual IDMSprProducerEd * get_DM(void);
   virtual void set_DM(IDMSprProducerEd * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdProducerNom(void);
   virtual void set_IdProducerNom(__int64 IdProducerNom);

   virtual __int64 get_IdProducerTypePrice(void);
   virtual void set_IdProducerTypePrice(__int64 IdProducerTypePrice);

   virtual UnicodeString get_HeaderText(void);
   virtual void set_HeaderText(UnicodeString HeaderText);

   virtual void UpdateForm();
};
#define CLSID_TFormaSpiskaSprProducerEdImpl __uuidof(TFormaSpiskaSprProducerEdImpl)
#endif
