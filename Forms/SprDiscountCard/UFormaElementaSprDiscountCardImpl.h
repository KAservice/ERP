#ifndef UFormaElementaSprDiscountCardImplH
#define UFormaElementaSprDiscountCardImplH
#include "IFormaElementaSprDiscountCard.h"
#include "UFormaElementaSprDiscountCard.h"
//---------------------------------------------------------------
class __declspec(uuid("{62489D29-53E7-4F58-85E5-9031FD045F8F}")) TFormaElementaSprDiscountCardImpl : public IFormaElementaSprDiscountCard, IkanCallBack
{
public:
   TFormaElementaSprDiscountCardImpl();
   ~TFormaElementaSprDiscountCardImpl();
   TFormaElementaSprDiscountCard * Object;
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

//IFormaElementaSprDiscountCard
   virtual IDMSprDiscountCard * get_DM(void);
   virtual void set_DM(IDMSprDiscountCard * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);


   virtual void UpdateForm(void);
};
#define CLSID_TFormaElementaSprDiscountCardImpl __uuidof(TFormaElementaSprDiscountCardImpl)
#endif
