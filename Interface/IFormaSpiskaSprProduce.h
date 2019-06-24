#ifndef UIFormaSpiskaSprProduceH
#define UIFormaSpiskaSprProduceH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprProduce.h"
#include "IDMSprGrpProduce.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprProduce)) IFormaSpiskaSprProduce : public IMainInterface
{
public:
   __property IDMSprProduce* DM = {read = get_DM , write = set_DM};
   virtual IDMSprProduce* get_DM(void)=0;
   virtual void set_DM(IDMSprProduce* DM)=0;

   __property IDMSprGrpProduce * DMGrp = {read = get_DMGrp , write = set_DMGrp};
   virtual IDMSprGrpProduce * get_DMGrp(void)=0;
   virtual void set_DMGrp(IDMSprGrpProduce * DMGrp)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaSpiskaSprProduce __uuidof(IFormaSpiskaSprProduce)
#endif
