#ifndef UFormaElementaSprDiscountAutoImplH
#define UFormaElementaSprDiscountAutoImplH
#include "IFormaElementaSprDiscountAuto.h"
#include "UFormaElementaSprDiscountAuto.h"
//---------------------------------------------------------------
class __declspec(uuid("{26F231D0-C8BE-4C50-82BB-14371E60F8E2}")) TFormaElementaSprDiscountAutoImpl : public IFormaElementaSprDiscountAuto, IkanCallBack
{
public:
   TFormaElementaSprDiscountAutoImpl();
   ~TFormaElementaSprDiscountAutoImpl();
   TFormaElementaSprDiscountAuto * Object;
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

//IFormaElementaSprDiscountAuto
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IDMSprDiscountAuto * get_DM(void);
   virtual void set_DM(IDMSprDiscountAuto * DM);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaElementaSprDiscountAutoImpl __uuidof(TFormaElementaSprDiscountAutoImpl)
#endif
