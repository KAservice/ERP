#ifndef UIFormaSpiskaSprLossFactorH
#define UIFormaSpiskaSprLossFactorH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprLossFactor.h"
#include "IDMSprGrpLossFactor.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprLossFactor)) IFormaSpiskaSprLossFactor : public IMainInterface
{
public:
   __property IDMSprLossFactor* DM = {read = get_DM , write = set_DM};
   virtual IDMSprLossFactor* get_DM(void)=0;
   virtual void set_DM(IDMSprLossFactor* DM)=0;

   __property IDMSprGrpLossFactor * DMGrp = {read = get_DMGrp , write = set_DMGrp};
   virtual IDMSprGrpLossFactor * get_DMGrp(void)=0;
   virtual void set_DMGrp(IDMSprGrpLossFactor * DMGrp)=0;

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
#define IID_IFormaSpiskaSprLossFactor __uuidof(IFormaSpiskaSprLossFactor)
#endif
