//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDataModuleMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "pFIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"

TDataModuleMain * glDM;
//---------------------------------------------------------------------------
__fastcall TDataModuleMain::TDataModuleMain(TComponent* Owner)
	: TDataModule(Owner)
{
Database->Connected=false;
}
//---------------------------------------------------------------------------
void __fastcall TDataModuleMain::DataModuleCreate(TObject *Sender)
{
//	
}
//---------------------------------------------------------------------------
void __fastcall TDataModuleMain::DataModuleDestroy(TObject *Sender)
{
UserDataSet->Active=false;
if (Database->Connected)
	{
	Database->CloseDataSets();
	Database->Connected=false;
	}
}
//---------------------------------------------------------------------------

bool TDataModuleMain::GlobConnect(void)
{
bool Res=false;

try
		{
			Database->Connected=false;
			Database->DBName=ConnectString;
			Database->DBParams->Clear();
			Database->DBParams->Add(" user_name="+NameUser);
			Database->DBParams->Add(" lc_ctype=UTF8");
			Database->DBParams->Add(" password="+PasswordUser);
			Database->Connected=true;

			UserDataSet->Active=false;
			UserDataSet->ParamByName("PARAM_NAME")->AsString=NameUser;
			UserDataSet->Active=true;

        Res=true;

		}
catch (Exception &exception)
		{
		Error=true;
		TextError=exception.Message;
		Res=false;
		Database->Connected=false;
        }

return Res;
}
//----------------------------------------------------------------------------