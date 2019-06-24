//---------------------------------------------------------------------------

#ifndef UDMQueryUpdateH
#define UDMQueryUpdateH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "FIBDatabase.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
//----------------------------------------------------------------------------

//---------------------------------------------------------------------------
class TDMQueryUpdate : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBQuery *pFIBQ;
	TpFIBTransaction *pFIBTr;
	void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDMQueryUpdate(TComponent* Owner);

	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
	int CodeError;
	UnicodeString TextError;
	bool Init(void);
	int Done(void);
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


};
//---------------------------------------------------------------------------
extern PACKAGE TDMQueryUpdate *DMQueryUpdate;
//---------------------------------------------------------------------------
#endif
