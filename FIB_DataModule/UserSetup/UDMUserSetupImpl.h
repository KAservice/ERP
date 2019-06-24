#ifndef UDMUserSetupImplH
#define UDMUserSetupImplH
#include "IDMUserSetup.h"
#include "UDMUserSetup.h"
//---------------------------------------------------------------
class __declspec(uuid("{CD93B222-0575-42D9-885F-6A48903668B4}")) TDMUserSetupImpl : public IDMUserSetup
{
public:
   TDMUserSetupImpl();
   ~TDMUserSetupImpl();
   TDMUserSetup * Object;
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

//IDMUserSetup
   virtual void SaveSetup(AnsiString form_name,AnsiString name_setup, AnsiString value);
   virtual AnsiString LoadSetup(AnsiString form_name, AnsiString name_setup);
   virtual void SaveSetupBool(AnsiString form_name,AnsiString name_setup, bool value);
   virtual bool LoadSetupBool(AnsiString form_name, AnsiString name_setup);
   virtual void SaveSetupInt(AnsiString form_name,AnsiString name_setup, int value);
   virtual int LoadSetupInt(AnsiString form_name, AnsiString name_setup);
   virtual void SaveSetupInt64(AnsiString form_name,AnsiString name_setup, __int64 value);
   virtual __int64 LoadSetupInt64(AnsiString form_name, AnsiString name_setup);
};
#define CLSID_TDMUserSetupImpl __uuidof(TDMUserSetupImpl)
#endif
