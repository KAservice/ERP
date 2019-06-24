#ifndef UFormaSpiskaSprNumTelImplH
#define UFormaSpiskaSprNumTelImplH
#include "IFormaSpiskaSprNumTel.h"
#include "UFormaSpiskaSprNumTel.h"
//---------------------------------------------------------------
class __declspec(uuid("{11D4583E-C1E6-47DA-9484-ABA0F6EB94EB}"))TFormaSpiskaSprNumTelImpl : public IFormaSpiskaSprNumTel, IkanCallBack
{
public:
   TFormaSpiskaSprNumTelImpl();
   ~TFormaSpiskaSprNumTelImpl();
   TFormaSpiskaSprNumTel * Object;
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

//IFormaSpiskaSprNumTel
   virtual IDMSprNumTel * get_DM(void);
   virtual void set_DM(IDMSprNumTel * DM);

   virtual __int64 get_IdKlient(void);
   virtual void set_IdKlient(__int64 IdKlient);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void OpenFormElement();
   virtual void OpenFormNewElement();
   virtual void DeleteElement();
   virtual void UpdateForm();
};
#define CLSID_TFormaSpiskaSprNumTelImpl __uuidof(TFormaSpiskaSprNumTelImpl)
#endif
