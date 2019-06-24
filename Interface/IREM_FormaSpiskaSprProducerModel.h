#ifndef UIREM_FormaSpiskaSprProducerModelH
#define UIREM_FormaSpiskaSprProducerModelH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMSprProducerModel.h"
#include "IREM_DMSprProducerModelGrp.h"
class __declspec(uuid(Global_IID_IREM_FormaSpiskaSprProducerModel)) IREM_FormaSpiskaSprProducerModel : public IMainInterface
{
public:
   __property IREM_DMSprProducerModel* DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprProducerModel* get_DM(void)=0;
   virtual void set_DM(IREM_DMSprProducerModel* DM)=0;

   __property IREM_DMSprProducerModelGrp* DMGrp = {read = get_DMGrp , write = set_DMGrp};
   virtual IREM_DMSprProducerModelGrp* get_DMGrp(void)=0;
   virtual void set_DMGrp(IREM_DMSprProducerModelGrp* DMGrp)=0;

   __property bool flVibor = {read = get_flVibor , write = set_flVibor};
   virtual bool get_flVibor(void)=0;
   virtual void set_flVibor(bool flVibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property bool flPodbor = {read = get_flPodbor , write = set_flPodbor};
   virtual bool get_flPodbor(void)=0;
   virtual void set_flPodbor(bool flPodbor)=0;

   __property __int64 IdGroupElement = {read = get_IdGroupElement , write = set_IdGroupElement};
   virtual __int64 get_IdGroupElement(void)=0;
   virtual void set_IdGroupElement(__int64 IdGroupElement)=0;

   __property UnicodeString NameGroupElement = {read = get_NameGroupElement , write = set_NameGroupElement};
   virtual UnicodeString get_NameGroupElement(void)=0;
   virtual void set_NameGroupElement(UnicodeString NameGroupElement)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   __property bool flAllElement = {read = get_flAllElement , write = set_flAllElement};
   virtual bool get_flAllElement(void)=0;
   virtual void set_flAllElement(bool flAllElement)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IREM_FormaSpiskaSprProducerModel __uuidof(IREM_FormaSpiskaSprProducerModel)
#endif
