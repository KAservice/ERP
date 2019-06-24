//---------------------------------------------------------------------------

#ifndef UDMQueryReadH
#define UDMQueryReadH
//---------------------------------------------------------------------------
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
	TpFIBQuery *Query;
	TpFIBTransaction *Transaction;
	void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDMQueryRead(TComponent* Owner);

	bool flError;
	UnicodeString TextError;


	void CloseQuery(void);
	void ClearTextSQL(void);
	void SetTextSQL(UnicodeString text_sql);
	bool SetStringParamQuery(UnicodeString param_name, UnicodeString param_value);
	bool ExecQuery(void);
    bool ExecProc(void);
	//int  RecordCount;
	//bool Eof;
	bool NextRecord(void);

	bool GetRecord(void);
	UnicodeString GetStringValueField(UnicodeString field_name);

	bool StartTransaction(void);
	bool CommitTransaction(void);
	bool RollbackTransaction(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TDMQueryRead *DMQueryRead;
//---------------------------------------------------------------------------
#endif
