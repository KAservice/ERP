#ifndef UIFormaSpiskaExtModuleH
#define UIFormaSpiskaExtModuleH
#include "IMainInterface.h"
#include "IDMExtModule.h"
#include "IDMExtModuleGrp.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaSpiskaExtModule)) IFormaSpiskaExtModule : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IDMExtModule* DM = {read = get_DM , write = set_DM};
   virtual IDMExtModule* get_DM(void)=0;
   virtual void set_DM(IDMExtModule* DM)=0;

   __property IDMExtModuleGrp * DMGrp = {read = get_DMGrp , write = set_DMGrp};
   virtual IDMExtModuleGrp * get_DMGrp(void)=0;
   virtual void set_DMGrp(IDMExtModuleGrp * DMGrp)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property __int64 IdExtModule = {read = get_IdExtModule , write = set_IdExtModule};
   virtual __int64 get_IdExtModule(void)=0;
   virtual void set_IdExtModule(__int64 IdExtModule)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   virtual void UpdateForm(void)=0;
   virtual void RunExternalModule(void)=0;
};
#define IID_IFormaSpiskaExtModule __uuidof(IFormaSpiskaExtModule)
#endif
