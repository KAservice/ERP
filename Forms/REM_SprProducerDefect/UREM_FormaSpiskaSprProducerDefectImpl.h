#ifndef UREM_FormaSpiskaSprProducerDefectImplH
#define UREM_FormaSpiskaSprProducerDefectImplH
#include "IREM_FormaSpiskaSprProducerDefect.h"
#include "UREM_FormaSpiskaSprProducerDefect.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaSpiskaSprProducerDefectImpl)) TREM_FormaSpiskaSprProducerDefectImpl : public IREM_FormaSpiskaSprProducerDefect, IkanCallBack
{
public:
   TREM_FormaSpiskaSprProducerDefectImpl();
   ~TREM_FormaSpiskaSprProducerDefectImpl();
   TREM_FormaSpiskaSprProducerDefect * Object;
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

//IREM_FormaSpiskaSprProducerDefect
   virtual IREM_DMSprProducerDefect* get_DM(void);
   virtual void set_DM(IREM_DMSprProducerDefect* DM);

   virtual IREM_DMSprProducerDefectGrp* get_DMGrp(void);
   virtual void set_DMGrp(IREM_DMSprProducerDefectGrp* DMGrp);

   virtual bool get_flVibor(void);
   virtual void set_flVibor(bool flVibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual bool get_flPodbor(void);
   virtual void set_flPodbor(bool flPodbor);

   virtual __int64 get_IdGroupElement(void);
   virtual void set_IdGroupElement(__int64 IdGroupElement);

   virtual UnicodeString get_NameGroupElement(void);
   virtual void set_NameGroupElement(UnicodeString NameGroupElement);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual bool get_flAllElement(void);
   virtual void set_flAllElement(bool flAllElement);

   virtual void UpdateForm(void);
};
#define CLSID_TREM_FormaSpiskaSprProducerDefectImpl __uuidof(TREM_FormaSpiskaSprProducerDefectImpl)
#endif
