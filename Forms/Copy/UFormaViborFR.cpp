//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaViborFR.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
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
#pragma link "cxStyles"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaViborFR::TFormaViborFR(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
bool TFormaViborFR::Init(void)
{
bool result=false;

DM=new TDMViborFR(Application);
DM->DM_Connection=DM_Connection;
DM->Init();

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;

Vibor=false;
OutReady=false;

//ÏÐÈÂÅËÅÃÈÈ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;
return result;
}
//---------------------------------------------------------------------------
void TFormaViborFR::UpdateForm(void)
{
DM->OpenTable(IdArm);
}
//---------------------------------------------------------------------------
void __fastcall TFormaViborFR::FormClose(TObject *Sender,
      TCloseAction &Action)
{

try {if(FOnCloseForm) FOnCloseForm(this); } catch (...){}

delete DM;
Action=caFree;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void __fastcall TFormaViborFR::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
        {
		OutReady=true;
        Close();
        }

}
//---------------------------------------------------------------------------


void __fastcall TFormaViborFR::ActionCloseExecute(TObject *Sender)
{
        OutReady=false;
        Close();
}
//---------------------------------------------------------------------------

