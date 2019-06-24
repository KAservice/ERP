#ifndef UIFormaSpiskaSprVidImageH
#define UIFormaSpiskaSprVidImageH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprVidImage.h"
#include "IDMSprVidImageGrp.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprVidImage)) IFormaSpiskaSprVidImage : public IMainInterface
{
public:
   __property IDMSprVidImage* DM = {read = get_DM , write = set_DM};
   virtual IDMSprVidImage* get_DM(void)=0;
   virtual void set_DM(IDMSprVidImage* DM)=0;

   __property IDMSprVidImageGrp * DMGrp = {read = get_DMGrp , write = set_DMGrp};
   virtual IDMSprVidImageGrp * get_DMGrp(void)=0;
   virtual void set_DMGrp(IDMSprVidImageGrp * DMGrp)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 IdGrpElement = {read = get_IdGrpElement , write = set_IdGrpElement};
   virtual __int64 get_IdGrpElement(void)=0;
   virtual void set_IdGrpElement(__int64 IdGrpElement)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaSpiskaSprVidImage __uuidof(IFormaSpiskaSprVidImage)
#endif
