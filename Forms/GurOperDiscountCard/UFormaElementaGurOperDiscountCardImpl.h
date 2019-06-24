#ifndef UFormaElementaGurOperDiscountCardImplH
#define UFormaElementaGurOperDiscountCardImplH
#include "IFormaElementaGurOperDiscountCard.h"
#include "UFormaElementaGurOperDiscountCard.h"
//---------------------------------------------------------------
class __declspec(uuid("{4B728513-940B-4F4F-915C-4B5548D5820C}")) TFormaElementaGurOperDiscountCardImpl :
				public IFormaElementaGurOperDiscountCard, IkanCallBack
{
public:
   TFormaElementaGurOperDiscountCardImpl();
   ~TFormaElementaGurOperDiscountCardImpl();
   TFormaElementaGurOperDiscountCard * Object;
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

//IFormaElementaGurOperDiscountCard
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IDMGurOperDiscountCard * get_DM(void);
   virtual void set_DM(IDMGurOperDiscountCard * DM);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaElementaGurOperDiscountCardImpl __uuidof(TFormaElementaGurOperDiscountCardImpl)
#endif
