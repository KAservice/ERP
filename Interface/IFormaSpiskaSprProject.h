#ifndef UIFormaSpiskaSprProjectH
#define UIFormaSpiskaSprProjectH
#include "IMainInterface.h"
#include "IDMSprProject.h"
#include "IDMSprGrpProject.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprProject))IFormaSpiskaSprProject : public IMainInterface
{
public:
   __property IDMSprProject* DM = {read = get_DM , write = set_DM};
   virtual IDMSprProject* get_DM(void)=0;
   virtual void set_DM(IDMSprProject* DM)=0;

   __property IDMSprGrpProject * DMGrp = {read = get_DMGrp , write = set_DMGrp};
   virtual IDMSprGrpProject * get_DMGrp(void)=0;
   virtual void set_DMGrp(IDMSprGrpProject * DMGrp)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property __int64 IdProject = {read = get_IdProject , write = set_IdProject};
   virtual __int64 get_IdProject(void)=0;
   virtual void set_IdProject(__int64 IdProject)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   __property bool Podbor = {read = get_Podbor , write = set_Podbor};
   virtual bool get_Podbor(void)=0;
   virtual void set_Podbor(bool Podbor)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;


   virtual void UpdateForm(void)=0;
};
#define IID_IFormaSpiskaSprProject __uuidof(IFormaSpiskaSprProject)
#endif
