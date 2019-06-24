//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDataModuleMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "pFIBDatabase"
#pragma resource "*.dfm"
TDataModuleMain *glDM;
//---------------------------------------------------------------------------
__fastcall TDataModuleMain::TDataModuleMain(TComponent* Owner)
	: TDataModule(Owner)
{
pFIBDatabase->Connected=false;
}
//---------------------------------------------------------------------------
void __fastcall TDataModuleMain::DataModuleCreate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void __fastcall TDataModuleMain::DataModuleDestroy(TObject *Sender)
{
if (pFIBDatabase->Connected)
	{
	pFIBDatabase->CloseDataSets();
	pFIBDatabase->Connected=false;
	}
}
//---------------------------------------------------------------------------
bool TDataModuleMain::Connect(void)
{
bool result=false;
try
		{
		pFIBDatabase->Connected=false;
		pFIBDatabase->DBName=ConnectString;
		pFIBDatabase->DBParams->Clear();
		pFIBDatabase->DBParams->Add(" user_name="+NameUser);
		pFIBDatabase->DBParams->Add(" lc_ctype=UTF8");
		pFIBDatabase->DBParams->Add(" password="+PasswordUser);
		pFIBDatabase->Connected=true;
		result=true;
        }
catch (Exception &exception)
		{
		Error=true;
		TextError=exception.Message;
		result=false;
		pFIBDatabase->Connected=false;
        }

return result;
}
//---------------------------------------------------------------------------
