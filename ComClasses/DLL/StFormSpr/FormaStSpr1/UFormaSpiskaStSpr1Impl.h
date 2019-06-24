#ifndef UFormaSpiskaStSpr1ImplH
#define UFormaSpiskaStSpr1ImplH
#include "IFormaSpiskaStSpr1.h"
#include "UFormaSpiskaStSpr1.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaSpiskaStSpr1Impl)) TFormaSpiskaStSpr1Impl : public IFormaSpiskaStSpr1, IkanCallBack
{
public:
   TFormaSpiskaStSpr1Impl();
   ~TFormaSpiskaStSpr1Impl();
   TFormaSpiskaStSpr1 * Object;
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

//IFormaSpiskaStSpr1
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual bool CreateObject(UnicodeString name_object);
};
#define CLSID_TFormaSpiskaStSpr1Impl __uuidof(TFormaSpiskaStSpr1Impl)
#endif
