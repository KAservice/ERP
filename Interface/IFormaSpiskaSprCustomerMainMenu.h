#ifndef UIFormaSpiskaSprCustomerMainMenuH
#define UIFormaSpiskaSprCustomerMainMenuH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprCustomerMainMenu.h"
#include "IDMSprCustomerMainMenuGrp.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprCustomerMainMenu)) IFormaSpiskaSprCustomerMainMenu : public IMainInterface
{
public:
   __property IDMSprCustomerMainMenu * DM = {read = get_DM , write = set_DM};
   virtual IDMSprCustomerMainMenu * get_DM(void)=0;
   virtual void set_DM(IDMSprCustomerMainMenu * DM)=0;

   __property IDMSprCustomerMainMenuGrp * DMGrp = {read = get_DMGrp , write = set_DMGrp};
   virtual IDMSprCustomerMainMenuGrp * get_DMGrp(void)=0;
   virtual void set_DMGrp(IDMSprCustomerMainMenuGrp * DMGrp)=0;

   __property __int64 IdGrpUser = {read = get_IdGrpUser , write = set_IdGrpUser};
   virtual __int64 get_IdGrpUser(void)=0;
   virtual void set_IdGrpUser(__int64 IdGrpUser)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property __int64 IdAccount = {read = get_IdAccount , write = set_IdAccount};
   virtual __int64 get_IdAccount(void)=0;
   virtual void set_IdAccount(__int64 IdAccount)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaSpiskaSprCustomerMainMenu __uuidof(IFormaSpiskaSprCustomerMainMenu)
#endif
