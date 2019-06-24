//---------------------------------------------------------------------------

#ifndef UDataModuleMainH
#define UDataModuleMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "FIBDatabase.hpp"
#include "pFIBDatabase.hpp"
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class TDataModuleMain : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBDatabase *pFIBDatabase;
	TpFIBTransaction *pFIBTrMain;
	TImageList *ImageList1;
	void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDataModuleMain(TComponent* Owner);

	bool Error;
	AnsiString TextError;
	AnsiString NameUser;
	AnsiString ConnectString;
	AnsiString PasswordUser;
	bool Connect(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDataModuleMain *DataModuleMain;
//---------------------------------------------------------------------------
#endif
