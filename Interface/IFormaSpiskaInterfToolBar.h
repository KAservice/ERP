#ifndef UIFormaSpiskaInterfToolBarH
#define UIFormaSpiskaInterfToolBarH
#include "IMainInterface.h"
#include "IDMInterfToolBar.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaSpiskaInterfToolBar)) IFormaSpiskaInterfToolBar : public IMainInterface
{
public:
   __property IDMInterfToolBar * DM = {read = get_DM , write = set_DM};
   virtual IDMInterfToolBar * get_DM(void)=0;
   virtual void set_DM(IDMInterfToolBar * DM)=0;

   __property __int64 IdGrpUser = {read = get_IdGrpUser , write = set_IdGrpUser};
   virtual __int64 get_IdGrpUser(void)=0;
   virtual void set_IdGrpUser(__int64 IdGrpUser)=0;

   __property int NumApplication = {read = get_NumApplication , write = set_NumApplication};
   virtual int get_NumApplication(void)=0;
   virtual void set_NumApplication(int NumApplication)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaSpiskaInterfToolBar __uuidof(IFormaSpiskaInterfToolBar)
#endif
