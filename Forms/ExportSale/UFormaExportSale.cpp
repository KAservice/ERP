//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaExportSale.h"
#include "UDM.h"
#include "UDMSprUser.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtonEdit"
#pragma link "cxCalendar"
#pragma link "cxCheckBox"
#pragma link "cxClasses"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxMaskEdit"
#pragma link "cxRadioGroup"
#pragma link "cxStyles"
#pragma link "cxTextEdit"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"


#pragma link "cxExportC11"
#include "cxGridExportLink.hpp"

#pragma link "cxLocalization"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

 extern TDMSprUser * glUser;
//---------------------------------------------------------------------------
__fastcall TFormaExportSale::TFormaExportSale(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaExportSale::FormCreate(TObject *Sender)
{
DM=new TDMExportSale(Application);
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceReport;

ConcxDateEdit->Date=Date()+EncodeTime(23,59,59,999);
NachcxDateEdit->Date=glUser->GetPosNachReport();


IdFirm=glUser->ElementIDFIRM_USER->AsInt64;
NameFirmcxButtonEdit->Text=glUser->ElementNAMEFIRM->AsString;
IdSklad=glUser->ElementIDSKLAD_USER->AsInt64;
NameSkladcxButtonEdit->Text=glUser->ElementNAMESKLAD->AsString;
IdKassa=glUser->ElementIDKASSA_USER->AsInt64;
NameKassacxButtonEdit->Text=glUser->ElementNAMEKKM->AsString;
}
//---------------------------------------------------------------------------
void __fastcall TFormaExportSale::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprFirm)FormaSpiskaSprFirm->Close();
if(FormaSpiskaSprSklad)FormaSpiskaSprSklad->Close();
if(FormaSpiskaSprKassa)FormaSpiskaSprKassa->Close();

Action=caFree;
delete DM;
}
//---------------------------------------------------------------------------
void TFormaExportSale::UpdateForm(void)
{



}
//----------------------------------------------------------------------------
//выбор фирмы
void TFormaExportSale::ViborFirm(void)
{
if (FormaSpiskaSprFirm==0)
		{
		FormaSpiskaSprFirm=new TFormaSpiskaSprFirm(Application);
		if (!FormaSpiskaSprFirm) return;
		FormaSpiskaSprFirm->Vibor=true;
		FormaSpiskaSprFirm->DM->OpenTable();
		FormaSpiskaSprFirm->FOnCloseForm=EndViborFirm;
		FormaSpiskaSprFirm->Show();
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaExportSale::EndViborFirm(TObject *Sender)
{
if (FormaSpiskaSprFirm->OutReady==true)
	{
	IdFirm=FormaSpiskaSprFirm->DM->ElementIDFIRM->AsInt64;
	NameFirmcxButtonEdit->Text=FormaSpiskaSprFirm->DM->ElementNAMEFIRM->AsString;
	}
FormaSpiskaSprFirm=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
//выбор склада
void TFormaExportSale::ViborSklad(void)
{
if (FormaSpiskaSprSklad==NULL)
		{
		FormaSpiskaSprSklad=new TFormaSpiskaSprSklad(Application);
		if (!FormaSpiskaSprSklad) return;
		FormaSpiskaSprSklad->Vibor=true;
		FormaSpiskaSprSklad->DM->OpenTable();
		FormaSpiskaSprSklad->FOnCloseForm=EndViborSklad;
		FormaSpiskaSprSklad->Show();
		}
}
//-----------------------------------------------------------------------------
void __fastcall TFormaExportSale::EndViborSklad(TObject *Sender)
{

if (FormaSpiskaSprSklad->OutReady==true)
	{
	IdSklad=FormaSpiskaSprSklad->DM->ElementIDSKLAD->AsInt64;
	NameSkladcxButtonEdit->Text=FormaSpiskaSprSklad->DM->ElementNAMESKLAD->AsString;
	}
FormaSpiskaSprSklad=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//-----------------------------------------------------------------------------
//выбор кассы
void TFormaExportSale::ViborKassa(void)
{
if (FormaSpiskaSprKassa==NULL)
		{
		FormaSpiskaSprKassa=new TFormaSpiskaSprKKM(Application);
		if (!FormaSpiskaSprKassa) return;
		FormaSpiskaSprKassa->Vibor=true;
		//FormaSpiskaSprKassa->UpdateForm();
		FormaSpiskaSprKassa->FOnCloseForm=EndViborKassa;
		FormaSpiskaSprKassa->Show();
		}
}
//-----------------------------------------------------------------------------
void __fastcall TFormaExportSale::EndViborKassa(TObject *Sender)
{

if (FormaSpiskaSprKassa->OutReady==true)
	{
	IdKassa=FormaSpiskaSprKassa->DM->ElementIDKKM->AsInt64;
	NameKassacxButtonEdit->Text=FormaSpiskaSprKassa->DM->ElementNAMEKKM->AsString;
	}
FormaSpiskaSprKassa=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//-----------------------------------------------------------------------------
void __fastcall TFormaExportSale::NameKassacxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborKassa();
}
//---------------------------------------------------------------------------

void __fastcall TFormaExportSale::NameFirmcxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborFirm();
}
//---------------------------------------------------------------------------

void __fastcall TFormaExportSale::NameSkladcxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborSklad();
}
//---------------------------------------------------------------------------

void __fastcall TFormaExportSale::cxButtonCreateClick(TObject *Sender)
{
DM->Report->Active=false;
DM->Report->ParamByName("PARAM_POS_NACH")->AsDateTime=NachcxDateEdit->Date;
DM->Report->ParamByName("PARAM_POS_CON")->AsDateTime=ConcxDateEdit->Date;
DM->Report->ParamByName("PARAM_IDFIRM")->AsString=IdFirm;
DM->Report->ParamByName("PARAM_IDKKM")->AsString=IdKassa;
DM->Report->ParamByName("PARAM_IDSKLAD")->AsString=IdSklad;
//DM->Report->ParamByName("PARAM_TYPE")->AsInteger=0;
DM->Report->Active=true;
}
//---------------------------------------------------------------------------

void __fastcall TFormaExportSale::cxButtonCloseClick(TObject *Sender)
{
Close();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaExportSale::cxButtonExportTextClick(TObject *Sender)
{
  if (SaveDialog1->Execute())
	{
	ExportGridToText(SaveDialog1->FileName, cxGrid1, true, true, ";", " "," ");
	}

}
//---------------------------------------------------------------------------

void __fastcall TFormaExportSale::cxButtonExportExcelClick(TObject *Sender)
{

  if (SaveDialog1->Execute())
	{
	ExportGridToExcel(SaveDialog1->FileName, cxGrid1, true, true,true, "xls");
	}

}
//---------------------------------------------------------------------------

void __fastcall TFormaExportSale::cxButtonExportHtmlClick(TObject *Sender)
{

  if (SaveDialog1->Execute())
	{
	ExportGridToHTML(SaveDialog1->FileName, cxGrid1, true, true, "html");
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaExportSale::cxButtonExportXMLClick(TObject *Sender)
{
  if (SaveDialog1->Execute())
	{
	ExportGridToXML(SaveDialog1->FileName, cxGrid1, true, true);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaExportSale::PatchcxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
  if (SaveDialog1->Execute())
	{
	PatchcxButtonEdit->Text=SaveDialog1->FileName;
	}
}
//---------------------------------------------------------------------------

