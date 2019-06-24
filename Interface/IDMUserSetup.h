#ifndef UIDMUserSetupH
#define UIDMUserSetupH
#include "IMainInterface.h"
class __declspec(uuid("{7146A884-210C-48D2-86DD-50249904889D}")) IDMUserSetup : public IMainInterface
{
public:
   virtual void SaveSetup(AnsiString form_name,AnsiString name_setup, AnsiString value)=0;
   virtual AnsiString LoadSetup(AnsiString form_name, AnsiString name_setup)=0;
   virtual void SaveSetupBool(AnsiString form_name,AnsiString name_setup, bool value)=0;
   virtual bool LoadSetupBool(AnsiString form_name, AnsiString name_setup)=0;
   virtual void SaveSetupInt(AnsiString form_name,AnsiString name_setup, int value)=0;
   virtual int LoadSetupInt(AnsiString form_name, AnsiString name_setup)=0;
   virtual void SaveSetupInt64(AnsiString form_name,AnsiString name_setup, __int64 value)=0;
   virtual __int64 LoadSetupInt64(AnsiString form_name, AnsiString name_setup)=0;
};
#define IID_IDMUserSetup __uuidof(IDMUserSetup)
#endif
