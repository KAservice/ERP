#ifndef UDMProgramSetupImplH
#define UDMProgramSetupImplH
#include "IDMProgramSetup.h"
#include "UDMProgramSetup.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMProgramSetupImpl)) TDMProgramSetupImpl : public IDMProgramSetup
{
public:
   TDMProgramSetupImpl();
   ~TDMProgramSetupImpl();
   TDMProgramSetup * Object;
   int NumRefs;
   bool flDeleteObject;
   void DeleteImpl(void);

   //IUnknown
   virtual int kanQueryInterface(REFIID id_interface,void ** ppv);
   virtual int kanAddRef(void);
   virtual int kanRelease(void);

   //IMainInterface
   virtual int  get_CodeError(void);
   virtual void set_CodeError(int CodeError);
   virtual UnicodeString  get_TextError(void);
   virtual void set_TextError(UnicodeString  TextError);
   virtual int Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object);
   virtual int Done(void);

//IDMProgramSetup
   virtual void SaveSetup(UnicodeString group_name,UnicodeString name_setup, UnicodeString value);
   virtual UnicodeString LoadSetup(UnicodeString group_name, UnicodeString name_setup);
   virtual void SaveSetupBool(UnicodeString group_name,UnicodeString name_setup, bool value);
   virtual bool LoadSetupBool(UnicodeString group_name, UnicodeString name_setup);
   virtual void SaveSetupInt(UnicodeString group_name,UnicodeString name_setup, int value);
   virtual int LoadSetupInt(UnicodeString group_name, UnicodeString name_setup);
   virtual void SaveSetupInt64(UnicodeString group_name,UnicodeString name_setup, __int64 value);
   virtual __int64 LoadSetupInt64(UnicodeString group_name, UnicodeString name_setup);
};
#define CLSID_TDMProgramSetupImpl __uuidof(TDMProgramSetupImpl)
#endif
