#ifndef UIFormaSpiskaSprStrObjectH
#define UIFormaSpiskaSprStrObjectH
#include "IMainInterface.h"
#include "IDMSprStrObject.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprStrObject))IFormaSpiskaSprStrObject : public IMainInterface
{
public:
   __property IDMSprStrObject * DMGrp = {read = get_DMGrp , write = set_DMGrp};
   virtual IDMSprStrObject * get_DMGrp(void)=0;
   virtual void set_DMGrp(IDMSprStrObject * DMGrp)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;


};
#define IID_IFormaSpiskaSprStrObject __uuidof(IFormaSpiskaSprStrObject)
#endif
