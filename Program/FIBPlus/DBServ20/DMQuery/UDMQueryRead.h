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
	TpFIBQuery *pFIBQ;
	TpFIBTransaction *pFIBTr;
	void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDMQueryRead(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMQueryRead *DMQueryRead;
//---------------------------------------------------------------------------
#endif
