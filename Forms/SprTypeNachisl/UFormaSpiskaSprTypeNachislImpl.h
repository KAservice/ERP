#ifndef UFormaSpiskaSprTypeNachislImplH
#define UFormaSpiskaSprTypeNachislImplH
#include "IFormaSpiskaSprTypeNachisl.h"
#include "UFormaSpiskaSprTypeNachisl.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaSpiskaSprTypeNachislImpl)) TFormaSpiskaSprTypeNachislImpl : public IFormaSpiskaSprTypeNachisl, IkanCallBack
{
public:
   TFormaSpiskaSprTypeNachislImpl();
   ~TFormaSpiskaSprTypeNachislImpl();
   TFormaSpiskaSprTypeNachisl * Object;
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

//IFormaSpiskaSprTypeNachisl
   virtual IDMSprTypeNachisl * get_DM(void);
   virtual void set_DM(IDMSprTypeNachisl * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaSpiskaSprTypeNachislImpl __uuidof(TFormaSpiskaSprTypeNachislImpl)
#endif
