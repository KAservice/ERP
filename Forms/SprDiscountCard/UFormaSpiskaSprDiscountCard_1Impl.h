#ifndef UFormaSpiskaSprDiscountCard_1ImplH
#define UFormaSpiskaSprDiscountCard_1ImplH
#include "IFormaSpiskaSprDiscountCard_1.h"
#include "UFormaSpiskaSprDiscountCard_1.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaSpiskaSprDiscountCard1Impl))TFormaSpiskaSprDiscountCard_1Impl : public IFormaSpiskaSprDiscountCard_1, IkanCallBack
{
public:
   TFormaSpiskaSprDiscountCard_1Impl();
   ~TFormaSpiskaSprDiscountCard_1Impl();
   TFormaSpiskaSprDiscountCard_1 * Object;
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

//IFormaSpiskaSprDiscountCard_1
   virtual IDMSprDiscountCard_1* get_DM(void);
   virtual void set_DM(IDMSprDiscountCard_1* DM);

   virtual IDMSprGrpKlient * get_DMGrp(void);
   virtual void set_DMGrp(IDMSprGrpKlient * DMGrp);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdGrpKlient(void);
   virtual void set_IdGrpKlient(__int64 IdGrpKlient);

   virtual __int64 get_IdDiscountCard(void);
   virtual void set_IdDiscountCard(__int64 IdDiscountCard);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaSpiskaSprDiscountCard_1Impl __uuidof(TFormaSpiskaSprDiscountCard_1Impl)
#endif
