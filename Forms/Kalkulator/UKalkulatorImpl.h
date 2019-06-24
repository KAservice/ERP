#ifndef UKalkulatorImplH
#define UKalkulatorImplH
#include "IKalkulator.h"
#include "UKalkulator.h"
//---------------------------------------------------------------
class __declspec(uuid("{F68E6426-FE4B-455C-933B-3FCF09D7D979}")) TKalkulatorImpl : public IKalkulator, IkanCallBack
{
public:
   TKalkulatorImpl();
   ~TKalkulatorImpl();
   TKalkulator * Object;
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

//IKalkulator
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual double get_Result(void);
   virtual void set_Result(double Result);

};
#define CLSID_TKalkulatorImpl __uuidof(TKalkulatorImpl)
#endif
