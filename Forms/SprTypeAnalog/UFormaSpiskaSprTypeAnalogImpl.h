#ifndef UFormaSpiskaSprTypeAnalogImplH
#define UFormaSpiskaSprTypeAnalogImplH
#include "IFormaSpiskaSprTypeAnalog.h"
#include "UFormaSpiskaSprTypeAnalog.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaSpiskaSprTypeAnalogImpl)) TFormaSpiskaSprTypeAnalogImpl : public IFormaSpiskaSprTypeAnalog, IkanCallBack
{
public:
   TFormaSpiskaSprTypeAnalogImpl();
   ~TFormaSpiskaSprTypeAnalogImpl();
   TFormaSpiskaSprTypeAnalog * Object;
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

//IFormaSpiskaSprTypeAnalog
   virtual IDMSprTypeAnalog * get_DM(void);
   virtual void set_DM(IDMSprTypeAnalog * DM);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual UnicodeString get_HeaderText(void);
   virtual void set_HeaderText(UnicodeString HeaderText);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaSpiskaSprTypeAnalogImpl __uuidof(TFormaSpiskaSprTypeAnalogImpl)
#endif
