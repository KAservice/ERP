//---------------------------------------------------------------------------

#include "glPCH.h"
#pragma hdrstop

#include "UFormaViborSprDogovor.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxClasses"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxStyles"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaViborSprDogovor::TFormaViborSprDogovor(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
bool TFormaViborSprDogovor::Init(void)
{
bool result=false;

//ÏÐÈÂÅËÅÃÈÈ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
DM=new TDMSprDogovor(Application);
DM->DM_Connection=DM_Connection;
DM->Init();

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
Vibor=false;
OutReady=false;
HintLabel->Caption="";

result=true;
return result;
}
//---------------------------------------------------------------------------
void TFormaViborSprDogovor::UpdateForm(void)
{
DM->OpenTable(IdKlient);

}
//---------------------------------------------------------------------------

void __fastcall TFormaViborSprDogovor::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FOnCloseForm) FOnCloseForm(this);

delete DM;
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TFormaViborSprDogovor::CloseElementSpr(TObject *Sender)
{
DM->OpenTable(IdKlient);
}

//--------------------------------------------------------------------------




void __fastcall TFormaViborSprDogovor::cxButtonCloseClick(TObject *Sender)
{
OutReady=false;
Close();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborSprDogovor::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
		{
		OutReady=true;
		DM->OpenElement(glStrToInt64(DM->TableID_SDOG->AsString));
		Close();
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborSprDogovor::OpenHelpExecute(TObject *Sender)
{
Application->HelpJump("ViborSprDogovor");
}
//---------------------------------------------------------------------------

