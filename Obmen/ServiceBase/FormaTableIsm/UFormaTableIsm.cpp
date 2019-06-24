//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaTableIsm.h"
#include "UDataModuleMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "cxCheckBox"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
TFormaTableIsm *FormaTableIsm;
//---------------------------------------------------------------------------
__fastcall TFormaTableIsm::TFormaTableIsm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaTableIsm::FormCreate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void __fastcall TFormaTableIsm::FormClose(TObject *Sender, TCloseAction &Action)
{
Action=caFree;
Tables->Active=false;
Fields->Active=false;
}
//---------------------------------------------------------------------------
void TFormaTableIsm::UpdateForm(void)
{
Tables->Active=false;
Fields->Active=false;
Tables->SelectSQL->Clear();

Tables->SelectSQL->Add(" select * from xtism ");
Tables->SelectSQL->Add(" where POS_XTISM between :PARAM_NACH and :PARAM_CON ");

if (OnlyTablecxCheckBox->Checked==true)
	{
	Tables->SelectSQL->Add(" and NAME_TABLE_XTISM='"+NameTable->Text+"'");
	}

if (OnlyUsercxCheckBox->Checked==true)
	{
	Tables->SelectSQL->Add(" and USER_XTISM='"+NameUser->Text+"'");
	}

if (OnlyRecordcxCheckBox->Checked==true)
	{
	Tables->SelectSQL->Add(" and VALUE_FIELD_ID_XTISM='"+NumberRecord->Text+"'");
	}
Tables->ParamByName("PARAM_NACH")->AsDateTime=PosNach->Date;
Tables->ParamByName("PARAM_CON")->AsDateTime=PosCon->Date;
Tables->Active=true;
Fields->Active=true;
}
//-----------------------------------------------------------------------------
void __fastcall TFormaTableIsm::ToolButtonUpdateClick(TObject *Sender)
{
UpdateForm();	
}
//---------------------------------------------------------------------------

