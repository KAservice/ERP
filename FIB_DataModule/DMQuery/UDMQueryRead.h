//---------------------------------------------------------------------------

#ifndef UDMQueryReadH
#define UDMQueryReadH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"

//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "FIBDatabase.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBQuery.hpp"
//---------------------------------------------------------------------------
class TDMQueryRead : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBQuery *pFIBQ;
	TpFIBTransaction *pFIBTr;
	TpFIBQuery *Query;
	TpFIBTransaction *Transaction;
	void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDMQueryRead(TComponent* Owner);

	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;

	typedef  void (__closure * TFunctionDeleteImplType)(void);
	TFunctionDeleteImplType FunctionDeleteImpl;
	bool flDeleteImpl;


	bool Init(void);
	UnicodeString TextError;
	int CodeError;

};
//---------------------------------------------------------------------------
extern PACKAGE TDMQueryRead *DMQueryRead;
//---------------------------------------------------------------------------
#endif
