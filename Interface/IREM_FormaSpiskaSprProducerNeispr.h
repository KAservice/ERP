#ifndef UIREM_FormaSpiskaSprProducerNeisprH
#define UIREM_FormaSpiskaSprProducerNeisprH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMSprProducerNeispr.h"
#include "IREM_DMSprProducerNeisprGrp.h"
class __declspec(uuid(Global_IID_IREM_FormaSpiskaSprProducerNeispr)) IREM_FormaSpiskaSprProducerNeispr : public IMainInterface
{
public:
   __property IREM_DMSprProducerNeispr* DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprProducerNeispr* get_DM(void)=0;
   virtual void set_DM(IREM_DMSprProducerNeispr* DM)=0;

   __property IREM_DMSprProducerNeisprGrp* DMGrp = {read = get_DMGrp , write = set_DMGrp};
   virtual IREM_DMSprProducerNeisprGrp* get_DMGrp(void)=0;
   virtual void set_DMGrp(IREM_DMSprProducerNeisprGrp* DMGrp)=0;

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
#define IID_IREM_FormaSpiskaSprProducerNeispr __uuidof(IREM_FormaSpiskaSprProducerNeispr)
#endif
