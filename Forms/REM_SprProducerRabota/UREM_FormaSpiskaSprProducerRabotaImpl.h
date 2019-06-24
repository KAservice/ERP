#ifndef UREM_FormaSpiskaSprProducerRabotaImplH
#define UREM_FormaSpiskaSprProducerRabotaImplH
#include "IREM_FormaSpiskaSprProducerRabota.h"
#include "UREM_FormaSpiskaSprProducerRabota.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaSpiskaSprProducerRabotaImpl)) TREM_FormaSpiskaSprProducerRabotaImpl : public IREM_FormaSpiskaSprProducerRabota, IkanCallBack
{
public:
   TREM_FormaSpiskaSprProducerRabotaImpl();
   ~TREM_FormaSpiskaSprProducerRabotaImpl();
   TREM_FormaSpiskaSprProducerRabota * Object;
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

//IREM_FormaSpiskaSprProducerRabota
   virtual IREM_DMSprProducerRabota* get_DM(void);
   virtual void set_DM(IREM_DMSprProducerRabota* DM);

   virtual IREM_DMSprProducerRabotaGrp* get_DMGrp(void);
   virtual void set_DMGrp(IREM_DMSprProducerRabotaGrp* DMGrp);

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
#define CLSID_TREM_FormaSpiskaSprProducerRabotaImpl __uuidof(TREM_FormaSpiskaSprProducerRabotaImpl)
#endif
