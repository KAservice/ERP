#ifndef UFormaElementaSprVidDiscountCardImplH
#define UFormaElementaSprVidDiscountCardImplH
#include "IFormaElementaSprVidDiscountCard.h"
#include "UFormaElementaSprVidDiscountCard.h"
//---------------------------------------------------------------
class __declspec(uuid("{14500EB3-A931-402A-8FF5-BBA4F2CFF141}")) TFormaElementaSprVidDiscountCardImpl : public IFormaElementaSprVidDiscountCard, IkanCallBack
{
public:
   TFormaElementaSprVidDiscountCardImpl();
   ~TFormaElementaSprVidDiscountCardImpl();
   TFormaElementaSprVidDiscountCard * Object;
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

//IFormaElementaSprVidDiscountCard
   virtual IDMSprVidDiscountCard * get_DM(void);
   virtual void set_DM(IDMSprVidDiscountCard * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaElementaSprVidDiscountCardImpl __uuidof(TFormaElementaSprVidDiscountCardImpl)
#endif
