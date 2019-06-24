#ifndef UIFormaSpiskaObjectBasePrivH
#define UIFormaSpiskaObjectBasePrivH
#include "IMainInterface.h"
#include "IDMObjectBasePriv.h"
#include "IDMObjectBaseGrp.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaSpiskaObjectBasePriv)) IFormaSpiskaObjectBasePriv : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IDMObjectBasePriv * DM = {read = get_DM , write = set_DM};
   virtual IDMObjectBasePriv * get_DM(void)=0;
   virtual void set_DM(IDMObjectBasePriv * DM)=0;

   __property IDMObjectBaseGrp * DMGrp = {read = get_DMGrp , write = set_DMGrp};
   virtual IDMObjectBaseGrp * get_DMGrp(void)=0;
   virtual void set_DMGrp(IDMObjectBaseGrp * DMGrp)=0;

   __property __int64 IdGrpUser = {read = get_IdGrpUser , write = set_IdGrpUser};
   virtual __int64 get_IdGrpUser(void)=0;
   virtual void set_IdGrpUser(__int64 IdGrpUser)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property int NumApplication = {read = get_NumApplication , write = set_NumApplication};
   virtual int get_NumApplication(void)=0;
   virtual void set_NumApplication(int NumApplication)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaSpiskaObjectBasePriv __uuidof(IFormaSpiskaObjectBasePriv)
#endif
