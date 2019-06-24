//---------------------------------------------------------------------------

#ifndef UDMConnectionH
#define UDMConnectionH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "FIBDatabase.hpp"
#include "pFIBDatabase.hpp"
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
//---------------------------------------------------------------------------
class TDMConnection : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBDatabase *Database;
	TpFIBTransaction *DefaultTransaction;
	TpFIBQuery *Query;
	void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall DataModuleCreate(TObject *Sender);
private:	// User declarations

	UnicodeString TextVipOper;
public:		// User declarations
	__fastcall TDMConnection(TComponent* Owner);

	bool flError;
	UnicodeString TextError;

	UnicodeString ConnectString;

	UnicodeString UserName;
	UnicodeString UserName2;
	UnicodeString Password;
	UnicodeString RoleName;
	UnicodeString CharSet;

	bool ConnectBase(void);
	void DisconnectBase(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TDMConnection *DMConnection;
//---------------------------------------------------------------------------
#endif
