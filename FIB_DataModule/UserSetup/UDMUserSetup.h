//---------------------------------------------------------------------------

#ifndef UDMUserSetupH
#define UDMUserSetupH
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
class TDMUserSetup : public TDataModule
{
__published:	// IDE-managed Components
	void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
TkanIniFile * Ini;
bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
	__fastcall TDMUserSetup(TComponent* Owner);

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

	void SaveSetup(AnsiString form_name,AnsiString name_setup, AnsiString value);
	AnsiString LoadSetup(AnsiString form_name, AnsiString name_setup);

	void SaveSetupBool(AnsiString form_name,AnsiString name_setup, bool value);
	bool LoadSetupBool(AnsiString form_name, AnsiString name_setup);

	void SaveSetupInt(AnsiString form_name,AnsiString name_setup, int value);
	int LoadSetupInt(AnsiString form_name, AnsiString name_setup);

	void SaveSetupInt64(AnsiString form_name,AnsiString name_setup, __int64 value);
	__int64 LoadSetupInt64(AnsiString form_name, AnsiString name_setup);


};
//---------------------------------------------------------------------------
extern PACKAGE TDMUserSetup *DMUserSetup;
//---------------------------------------------------------------------------
#endif
