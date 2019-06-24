#ifndef UIDMProgramSetupH
#define UIDMProgramSetupH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IDMProgramSetup)) IDMProgramSetup : public IMainInterface
{
public:
   virtual void SaveSetup(UnicodeString group_name,UnicodeString name_setup, UnicodeString value)=0;
   virtual UnicodeString LoadSetup(UnicodeString group_name, UnicodeString name_setup)=0;
   virtual void SaveSetupBool(UnicodeString group_name,UnicodeString name_setup, bool value)=0;
   virtual bool LoadSetupBool(UnicodeString group_name, UnicodeString name_setup)=0;
   virtual void SaveSetupInt(UnicodeString group_name,UnicodeString name_setup, int value)=0;
   virtual int LoadSetupInt(UnicodeString group_name, UnicodeString name_setup)=0;
   virtual void SaveSetupInt64(UnicodeString group_name,UnicodeString name_setup, __int64 value)=0;
   virtual __int64 LoadSetupInt64(UnicodeString group_name, UnicodeString name_setup)=0;
};
#define IID_IDMProgramSetup __uuidof(IDMProgramSetup)
#endif
