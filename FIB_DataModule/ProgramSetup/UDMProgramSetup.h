//---------------------------------------------------------------------------

#ifndef UDMProgramSetupH
#define UDMProgramSetupH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

//---------------------------------------------------------------------------
#include "UkanIniFile.h"
#include "IDMFibConnection.h"

//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
class TDMProgramSetup : public TDataModule
{
__published:	// IDE-managed Components
	void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
TkanIniFile * Ini;
bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
	__fastcall TDMProgramSetup(TComponent* Owner);

	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;
		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;

		bool Init(void);
		int Done(void);

		UnicodeString TextError;


	void SaveSetup(UnicodeString group_name,UnicodeString name_setup, UnicodeString value);
	UnicodeString LoadSetup(UnicodeString group_name, UnicodeString name_setup);

	void SaveSetupBool(UnicodeString group_name,UnicodeString name_setup, bool value);
	bool LoadSetupBool(UnicodeString group_name, UnicodeString name_setup);

	void SaveSetupInt(UnicodeString group_name,UnicodeString name_setup, int value);
	int LoadSetupInt(UnicodeString group_name, UnicodeString name_setup);

	void SaveSetupInt64(UnicodeString group_name,UnicodeString name_setup, __int64 value);
	__int64 LoadSetupInt64(UnicodeString group_name, UnicodeString name_setup);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMProgramSetup *DMProgramSetup;
//---------------------------------------------------------------------------
#endif
