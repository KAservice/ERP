#ifndef UIFormaElementaSprCustomerMainMenuGrpH
#define UIFormaElementaSprCustomerMainMenuGrpH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprCustomerMainMenuGrp.h"
class __declspec(uuid(Global_IID_IFormaElementaSprCustomerMainMenuGrp)) IFormaElementaSprCustomerMainMenuGrp : public IMainInterface
{
public:
   __property IDMSprCustomerMainMenuGrp* DM = {read = get_DM , write = set_DM};
   virtual IDMSprCustomerMainMenuGrp* get_DM(void)=0;
   virtual void set_DM(IDMSprCustomerMainMenuGrp* DM)=0;

};
#define IID_IFormaElementaSprCustomerMainMenuGrp __uuidof(IFormaElementaSprCustomerMainMenuGrp)
#endif
