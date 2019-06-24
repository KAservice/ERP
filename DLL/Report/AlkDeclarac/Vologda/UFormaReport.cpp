//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


//--------------------------------------------------------------------------
#include "UFormaReport.h"
#include "inifiles.hpp"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "UDM.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"

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
#pragma link "cxGridBandedTableView"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBBandedTableView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxGridChartView"
#pragma link "cxGridDBChartView"
#pragma link "cxPC"
#pragma link "dxBkgnd"
#pragma link "dxPrnDev"
#pragma link "dxPrnPg"
#pragma link "dxPSCompsProvider"
#pragma link "dxPSCore"
#pragma link "dxPScxCommon"
#pragma link "dxPScxGrid6Lnk"
#pragma link "dxPSEdgePatterns"
#pragma link "dxPSEngn"
#pragma link "dxPSFillPatterns"
#pragma link "dxPSGlbl"
#pragma link "dxPSUtl"
#pragma link "dxWrap"

#pragma link "cxExportC14"
#include "cxGridExportLink.hpp"
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "cxCheckBox"
#pragma link "cxLabel"
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxDBLookupComboBox"
#pragma link "cxDBLookupEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxLookupEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxCalc"
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaReport::TFormaReport(TComponent* Owner)
	: TForm(Owner)
{

FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//---------------------------------------------------------------------------
bool TFormaReport::Init(void)
{
bool result=false;

if (InterfaceMainObject>0)
	{
	//получим соединение
	IConnectionInterface * i_connection;
	InterfaceMainObject->kanQueryInterface(IID_IConnectionInterface,(void**)&i_connection);
	DM_Connection=i_connection->GetFibConnection();
	i_connection->kanRelease();

	//получим интерфейс COM системы для создания новых объектов
	IMainCOMInterface * i_com;
	InterfaceMainObject->kanQueryInterface(IID_IMainCOMInterface,(void**)&i_com);
	InterfaceGlobalCom=i_com->GetCOM();
	i_com->kanRelease();
	}


//Устанвливаем DataBase
ReportDataSet->Database=DM_Connection->pFIBData;
pFIBTransaction1->DefaultDatabase=DM_Connection->pFIBData;
SpisokFirm->Database=DM_Connection->pFIBData;
SpisokSklad->Database=DM_Connection->pFIBData;
SpisokGrp->Database=DM_Connection->pFIBData;
ReportPoNom->Database=DM_Connection->pFIBData;
GrpDataSet->Database=DM_Connection->pFIBData;
SpisokGrpKlient->Database=DM_Connection->pFIBData;
SpisokKlient->Database=DM_Connection->pFIBData;
KlientDataSet->Database=DM_Connection->pFIBData;
ReportRasdel1->Database=DM_Connection->pFIBData;
ReportRasdel2->Database=DM_Connection->pFIBData;
Query->Database=DM_Connection->pFIBData;


//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
result=true;


AlcGrpFileName="AlcGroup.ini";
ProducerFileName="Producer.ini";
PostFileName="Samplier.ini";


UpdateForm();

return result;
}

//---------------------------------------------------------------------------
int TFormaReport::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------


void TFormaReport::UpdateForm(void)
{
SpisokFirm->Active=false;
SpisokSklad->Active=false;
SpisokGrp->Active=false;
SpisokGrpKlient->Active=false;
SpisokKlient->Active=false;
SpisokFirm->Active=true;
SpisokSklad->Active=true;
SpisokGrp->Active=true;
SpisokGrpKlient->Active=true;
SpisokKlient->Active=true;

PosNachcxDateEdit->Date=Date()-DayOf(Date())+1;
PosConcxDateEdit->Date=Date()+EncodeTime(23,59,59,999);
}
//---------------------------------------------------------------------------
void __fastcall TFormaReport::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
SpisokFirm->Active=false;
SpisokSklad->Active=false;
SpisokGrp->Active=false;
ReportDataSet->Active=false;
ReportPoNom->Active=false;
GrpDataSet->Active=false;
KlientDataSet->Active=false;
SpisokGrpKlient->Active=false;
SpisokKlient->Active=false;
ReportRasdel1->Active=false;
ReportRasdel2->Active=false;

if(prForm)prForm->Close();

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}


Action=caFree; 
}
//----------------------------------------------------------------------------
int TFormaReport::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{



return -1;
}
//-----------------------------------------------------------------------------
void __fastcall TFormaReport::cxButtonCloseClick(TObject *Sender)
{
Close();	
}
//----------------------------------------------------------------------------

void __fastcall TFormaReport::ActionPreeViewExecute(TObject *Sender)
{

if (cxPageControl1->ActivePage->PageIndex==0)
	{
	dxComponentPrinter1->ReportLink[0]->Preview(true);
	}

if (cxPageControl1->ActivePage->PageIndex==1)
	{
	dxComponentPrinter1->ReportLink[1]->Preview(true);
	}

}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::ActionPageSetupExecute(TObject *Sender)
{


if (cxPageControl1->ActivePage->PageIndex==0)
	{
	dxComponentPrinter1->ReportLink[0]->PageSetup();
	}

if (cxPageControl1->ActivePage->PageIndex==1)
	{
	dxComponentPrinter1->ReportLink[1]->PageSetup();
	}

}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::ActionPrintExecute(TObject *Sender)
{
if (cxPageControl1->ActivePage->PageIndex==0)
	{
	dxComponentPrinter1->ReportLink[0]->Print(false, NULL);
	}

if (cxPageControl1->ActivePage->PageIndex==1)
	{
	dxComponentPrinter1->ReportLink[1]->Print(false, NULL);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::ActionExportExcelExecute(TObject *Sender)
{

if (cxPageControl1->ActivePage->PageIndex==0)
	{
	if (SaveDialog1->Execute())
		{
		ExportGridToExcel(SaveDialog1->FileName, cxGrid1, true, true,true, "xls");
		}     
	}

if (cxPageControl1->ActivePage->PageIndex==1)
	{
	if (SaveDialog1->Execute())
		{
		ExportGridToExcel(SaveDialog1->FileName, cxGrid2, true, true,true, "xls");
		}     
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::cxButtonRunReportPoGrpClick(TObject *Sender)
{
SpisokFirm->First();
SpisokFirm->MoveBy(NameFirmcxLookupComboBox->ItemIndex);

SpisokSklad->First();
SpisokSklad->MoveBy(NameSkladcxLookupComboBox->ItemIndex);

SpisokGrp->First();
SpisokGrp->MoveBy(NameGrpcxLookupComboBox->ItemIndex);


if (cxPageControl1->ActivePage->PageIndex==0)
	{
	ReportDataSet->Active=false;
	ReportDataSet->ParamByName("PARAM_POSNACH")->AsDateTime=PosNachcxDateEdit->Date;
	ReportDataSet->ParamByName("PARAM_POSCON")->AsDateTime=PosConcxDateEdit->Date;
	ReportDataSet->ParamByName("PARAM_IDFIRM")->AsString=SpisokFirmIDFIRM->AsString;
	ReportDataSet->ParamByName("PARAM_IDSKLAD")->AsString=SpisokSkladIDSKLAD->AsString;
	ReportDataSet->ParamByName("PARAM_IDGRP")->AsString=SpisokGrpIDGN->AsString;
	ReportDataSet->Active=true;
	cxGrid1DBBandedTableView1->Bands->Items[0]->Caption=
			"Фирма: "+SpisokFirmNAMEFIRM->AsString+
			". Склад: "+SpisokSkladNAMESKLAD->AsString +
			". Группа: "+SpisokGrpNAMEGN->AsString+".";

	}

if (cxPageControl1->ActivePage->PageIndex==1)
	{  
	ReportPoNom->Active=false;
	ReportPoNom->ParamByName("PARAM_POSNACH")->AsDateTime=PosNachcxDateEdit->Date;
	ReportPoNom->ParamByName("PARAM_POSCON")->AsDateTime=PosConcxDateEdit->Date;
	ReportPoNom->ParamByName("PARAM_IDFIRM")->AsString=SpisokFirmIDFIRM->AsString;
	ReportPoNom->ParamByName("PARAM_IDSKLAD")->AsString=SpisokSkladIDSKLAD->AsString;
	ReportPoNom->ParamByName("PARAM_IDGRP")->AsString=SpisokGrpIDGN->AsString;
	ReportPoNom->Active=true;
	cxGrid2DBBandedTableView1->Bands->Items[0]->Caption=
			"Фирма: "+SpisokFirmNAMEFIRM->AsString+
			". Склад: "+SpisokSkladNAMESKLAD->AsString +
			". Группа: "+SpisokGrpNAMEGN->AsString+".";

	}

}
//---------------------------------------------------------------------------
/// АЛКОГОЛЬНЫЕ ГРУППЫ
//-----------------------------------------------------------------------------

void __fastcall TFormaReport::AlcGrpRefreshToolButtonClick(TObject *Sender)
{
TcxCustomDataController *dc_table = AlcGrpcxGridTableView1->DataController;
AnsiString file_ini=ExtractFileDir(Application->ExeName)+"\\"+AlcGrpFileName;
TIniFile * ini=new TIniFile(file_ini);

dc_table->BeginUpdate();
	for (int i=dc_table->RecordCount;i>0;i--)
		{
		dc_table->DeleteRecord(i-1);
		}
dc_table->EndUpdate();


TStringList * str_list=new TStringList;
ini->ReadSections(str_list);

for (int i=0;i<str_list->Count;i++)
	{

	dc_table->AppendRecord();
	dc_table->Values[dc_table->RowCount-1][AlcGrpcxGridTableView1NAME->Index] =
										str_list->Strings[i];

	}

delete str_list;
delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::AlcGrpAddToolButtonClick(TObject *Sender)
{
TcxCustomDataController *dc = AlcGrpcxGridTableView1->DataController;
dc->AppendRecord();
dc->Values[dc->RowCount-1][AlcGrpcxGridTableView1NAME->Index] = " ";

}
//---------------------------------------------------------------------------


void __fastcall TFormaReport::AlcGrpDeleteToolButtonClick(TObject *Sender)
{
TcxCustomDataController *dc = AlcGrpcxGridTableView1->DataController;
AnsiString file_ini=ExtractFileDir(Application->ExeName)+"\\"+AlcGrpFileName;
TIniFile * ini=new TIniFile(file_ini);
AnsiString name_alc_grp=dc->Values[dc->FocusedRowIndex][AlcGrpcxGridTableView1NAME->Index];
ini->EraseSection(name_alc_grp);
delete ini;

dc->DeleteFocused();
}
//---------------------------------------------------------------------------
// ТОВАРНЫЕ ГРУППЫ
//---------------------------------------------------------------------------
AnsiString TFormaReport::DeleteSymbol(AnsiString s)
{
AnsiString result="";

for (int i=1;i<=s.Length();i++)
	{
	if (s[i]=='=')
		{
		break;
		}
	else
		{
		result=result+s[i];
		}
	}

return result;
}
//----------------------------------------------------------------------------
void __fastcall TFormaReport::TovGrpRefreshToolButtonClick(TObject *Sender)
{
UpdateSpisokTovGrp();
}
//---------------------------------------------------------------------------
void TFormaReport::UpdateSpisokTovGrp(void)
{
TcxCustomDataController *dc_table = TovGrpcxGridTableView1->DataController;
TcxCustomDataController *dc_table_alc_grp = AlcGrpcxGridTableView1->DataController;
AnsiString name_section=dc_table_alc_grp->Values[dc_table_alc_grp->FocusedRowIndex][AlcGrpcxGridTableView1NAME->Index];

AnsiString file_ini=ExtractFileDir(Application->ExeName)+"\\"+AlcGrpFileName;
TIniFile * ini=new TIniFile(file_ini);

dc_table->BeginUpdate();
	for (int i=dc_table->RecordCount;i>0;i--)
		{
		dc_table->DeleteRecord(i-1);
		}
dc_table->EndUpdate();

if (name_section!="")
	{
	TStringList * str_list=new TStringList;
	ini->ReadSectionValues(name_section, str_list);

	for (int i=0;i<str_list->Count;i++)
		{
		AnsiString name_key=DeleteSymbol(str_list->Strings[i]);
		dc_table->AppendRecord();
		dc_table->Values[dc_table->RowCount-1][TovGrpcxGridTableView1ID->Index] =
					name_key;

		GrpDataSet->Active=false;
		GrpDataSet->ParamByName("PARAM_IDGRP")->AsString=name_key;
		GrpDataSet->Active=true;
		dc_table->Values[dc_table->RowCount-1][TovGrpcxGridTableView1NAME->Index] =
					GrpDataSetNAMEGN->AsString;
		}

	delete str_list;
	}
delete ini;

}
//---------------------------------------------------------------------------
void __fastcall TFormaReport::TovGrpAddToolButtonClick(TObject *Sender)
{
SpisokGrp->First();
SpisokGrp->MoveBy(NameGrpcxLookupComboBox->ItemIndex);

TcxCustomDataController *dc = TovGrpcxGridTableView1->DataController;
dc->AppendRecord();
dc->Values[dc->RowCount-1][TovGrpcxGridTableView1NAME->Index] =
									SpisokGrpNAMEGN->AsString;
dc->Values[dc->RowCount-1][TovGrpcxGridTableView1ID->Index] =
									SpisokGrpIDGN->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::TovGrpSaveToolButtonClick(TObject *Sender)
{
TcxCustomDataController *dc_table = TovGrpcxGridTableView1->DataController;
TcxCustomDataController *dc_table_alc_grp = AlcGrpcxGridTableView1->DataController;
AnsiString name_section=dc_table_alc_grp->Values[dc_table_alc_grp->FocusedRowIndex][AlcGrpcxGridTableView1NAME->Index];


AnsiString file_ini=ExtractFileDir(Application->ExeName)+"\\"+AlcGrpFileName;
TIniFile * ini=new TIniFile(file_ini);

ini->EraseSection(name_section);

for (int i=0; i<dc_table->RowCount; i++)
	{
	AnsiString name_tov_grp=dc_table->Values[i][TovGrpcxGridTableView1NAME->Index];
	AnsiString id_tov_grp=dc_table->Values[i][TovGrpcxGridTableView1ID->Index];
	ini->WriteString(name_section,id_tov_grp,name_tov_grp);
	}

delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::TovGrpDeleteToolButtonClick(TObject *Sender)
{
TcxCustomDataController *dc = TovGrpcxGridTableView1->DataController;
TcxCustomDataController *dc_table_alc_grp = AlcGrpcxGridTableView1->DataController;
AnsiString name_section=dc_table_alc_grp->Values[dc_table_alc_grp->FocusedRowIndex][AlcGrpcxGridTableView1NAME->Index];


AnsiString file_ini=ExtractFileDir(Application->ExeName)+"\\"+AlcGrpFileName;
TIniFile * ini=new TIniFile(file_ini);
AnsiString id_tov_grp=dc->Values[dc->FocusedRowIndex][TovGrpcxGridTableView1ID->Index];
ini->DeleteKey(name_section, id_tov_grp);
delete ini; 

dc->DeleteFocused();
}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::AlcGrpcxGridTableView1CellClick(
      TcxCustomGridTableView *Sender,
      TcxGridTableDataCellViewInfo *ACellViewInfo, TMouseButton AButton,
      TShiftState AShift, bool &AHandled)
{
UpdateSpisokTovGrp();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::cxLookupComboBox1PropertiesValidate(
      TObject *Sender, Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
SpisokGrpKlient->First();
SpisokGrpKlient->MoveBy(cxLookupComboBox1->ItemIndex);

SpisokKlient->Active=false;
SpisokKlient->ParamByName("PARAM_IDGRP")->AsString=
		SpisokGrpKlientIDGRPKL->AsString;
SpisokKlient->Active=true;	
}
//---------------------------------------------------------------------------
//ПРОИЗВОДИТЕЛИ ОБЛАСТИ
//---------------------------------------------------------------------------
void TFormaReport::UpdateSpisokProducer(void)
{
TcxCustomDataController *dc_table = ProducercxGridTableView->DataController;

AnsiString file_ini=ExtractFileDir(Application->ExeName)+"\\"+ProducerFileName;
TIniFile * ini=new TIniFile(file_ini);

dc_table->BeginUpdate();
	for (int i=dc_table->RecordCount;i>0;i--)
		{
		dc_table->DeleteRecord(i-1);
		}
dc_table->EndUpdate();

	TStringList * str_list=new TStringList;
	ini->ReadSections(str_list);

	for (int i=0;i<str_list->Count;i++)
		{
		AnsiString name_key=DeleteSymbol(str_list->Strings[i]);
		dc_table->AppendRecord();
		dc_table->Values[dc_table->RowCount-1][ProducercxGridTableViewID->Index] =
					name_key;

		KlientDataSet->Active=false;
		KlientDataSet->ParamByName("PARAM_ID")->AsString=name_key;
		KlientDataSet->Active=true;
		dc_table->Values[dc_table->RowCount-1][ProducercxGridTableViewNAME->Index] =
					KlientDataSetNAMEKLIENT->AsString;
		}

	delete str_list;

delete ini;

}
//----------------------------------------------------------------------------
void __fastcall TFormaReport::ProducerAddToolButtonClick(TObject *Sender)
{
SpisokKlient->First();
SpisokKlient->MoveBy(NameKlientcxLookupComboBox->ItemIndex);

TcxCustomDataController *dc = ProducercxGridTableView->DataController;
dc->AppendRecord();
dc->Values[dc->RowCount-1][ProducercxGridTableViewNAME->Index] =
									SpisokKlientNAMEKLIENT->AsString;
dc->Values[dc->RowCount-1][ProducercxGridTableViewID->Index] =
									SpisokKlientIDKLIENT->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::ProducerDeleteToolButtonClick(TObject *Sender)
{
TcxCustomDataController *dc = ProducercxGridTableView->DataController;
AnsiString file_ini=ExtractFileDir(Application->ExeName)+"\\"+ProducerFileName;
TIniFile * ini=new TIniFile(file_ini);
AnsiString name_section=dc->Values[dc->FocusedRowIndex][ProducercxGridTableViewID->Index];
ini->EraseSection(name_section);
delete ini;

dc->DeleteFocused();
}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::ProducerRefreshToolButtonClick(TObject *Sender)
{
UpdateSpisokProducer();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::ProducerSaveToolButtonClick(TObject *Sender)
{
TcxCustomDataController *dc_table = ProducercxGridTableView->DataController;

AnsiString file_ini=ExtractFileDir(Application->ExeName)+"\\"+ProducerFileName;
TIniFile * ini=new TIniFile(file_ini);

for (int i=0; i<dc_table->RowCount; i++)
	{
	AnsiString name_section=dc_table->Values[i][ProducercxGridTableViewID->Index];
	AnsiString name_key=dc_table->Values[i][ProducercxGridTableViewNAME->Index];
	ini->WriteString(name_section,name_key,"");
	}

delete ini;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//ПОСТАВЩИКИ ОБЛАСТИ
//---------------------------------------------------------------------------
void TFormaReport::UpdateSpisokPost(void)
{
TcxCustomDataController *dc_table = PostcxGridTableView->DataController;

AnsiString file_ini=ExtractFileDir(Application->ExeName)+"\\"+PostFileName;
TIniFile * ini=new TIniFile(file_ini);

dc_table->BeginUpdate();
	for (int i=dc_table->RecordCount;i>0;i--)
		{
		dc_table->DeleteRecord(i-1);
		}
dc_table->EndUpdate();

	TStringList * str_list=new TStringList;
	ini->ReadSections(str_list);

	for (int i=0;i<str_list->Count;i++)
		{
		AnsiString name_key=DeleteSymbol(str_list->Strings[i]);
		dc_table->AppendRecord();
		dc_table->Values[dc_table->RowCount-1][PostcxGridTableViewID->Index] =
					name_key;

		KlientDataSet->Active=false;
		KlientDataSet->ParamByName("PARAM_ID")->AsString=name_key;
		KlientDataSet->Active=true;
		dc_table->Values[dc_table->RowCount-1][PostcxGridTableViewNAME->Index] =
					KlientDataSetNAMEKLIENT->AsString;
		}

	delete str_list;

delete ini;

}
//----------------------------------------------------------------------------
void __fastcall TFormaReport::ToolButton13Click(TObject *Sender)
{
UpdateSpisokPost();		
}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::ToolButton9Click(TObject *Sender)
{
SpisokKlient->First();
SpisokKlient->MoveBy(NameKlientcxLookupComboBox->ItemIndex);

TcxCustomDataController *dc = PostcxGridTableView->DataController;
dc->AppendRecord();
dc->Values[dc->RowCount-1][PostcxGridTableViewNAME->Index] =
									SpisokKlientNAMEKLIENT->AsString;
dc->Values[dc->RowCount-1][PostcxGridTableViewID->Index] =
									SpisokKlientIDKLIENT->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::ToolButton11Click(TObject *Sender)
{
TcxCustomDataController *dc = PostcxGridTableView->DataController;
AnsiString file_ini=ExtractFileDir(Application->ExeName)+"\\"+PostFileName;
TIniFile * ini=new TIniFile(file_ini);
AnsiString name_section=dc->Values[dc->FocusedRowIndex][PostcxGridTableViewID->Index];
ini->EraseSection(name_section);
delete ini;

dc->DeleteFocused();
}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::ToolButton12Click(TObject *Sender)
{
TcxCustomDataController *dc_table = PostcxGridTableView->DataController;

AnsiString file_ini=ExtractFileDir(Application->ExeName)+"\\"+PostFileName;
TIniFile * ini=new TIniFile(file_ini);

for (int i=0; i<dc_table->RowCount; i++)
	{
	AnsiString name_section=dc_table->Values[i][PostcxGridTableViewID->Index];
	AnsiString name_key=dc_table->Values[i][PostcxGridTableViewNAME->Index];
	ini->WriteString(name_section,name_key,"");
	}

delete ini;
}
//---------------------------------------------------------------------------
void TFormaReport::CreateReportRasdel1(void)
{
TcxCustomDataController *dc = Rasdel1cxGridTableView1->DataController;
AnsiString file_ini=ExtractFileDir(Application->ExeName)+"\\"+AlcGrpFileName;
TIniFile * ini=new TIniFile(file_ini);

dc->BeginUpdate();
	for (int i=dc->RecordCount;i>0;i--)
		{
		dc->DeleteRecord(i-1);
		}
dc->EndUpdate();


TStringList * str_list=new TStringList;
ini->ReadSections(str_list);


SpisokFirm->First();
SpisokFirm->MoveBy(NameFirmcxLookupComboBox->ItemIndex);

SpisokSklad->First();
SpisokSklad->MoveBy(NameSkladcxLookupComboBox->ItemIndex);

for (int i=0;i<str_list->Count;i++)
	{
	double no=0;
	double f_no=0;
	double prih=0;
	double f_prih=0;
	double rash=0;
	double f_rash=0;
	double co=0;
	double f_co=0;

	TStringList * str_id=new TStringList;
	ini->ReadSectionValues(str_list->Strings[i], str_id);

	for (int j=0;j<str_id->Count;j++)
		{
		ReportRasdel1->Active=false;
		ReportRasdel1->ParamByName("PARAM_POSNACH")->AsDateTime=PosNachcxDateEdit->Date;
		ReportRasdel1->ParamByName("PARAM_POSCON")->AsDateTime=PosConcxDateEdit->Date;
		ReportRasdel1->ParamByName("PARAM_IDFIRM")->AsString=SpisokFirmIDFIRM->AsString;
		ReportRasdel1->ParamByName("PARAM_IDSKLAD")->AsString=SpisokSkladIDSKLAD->AsString;
		ReportRasdel1->ParamByName("PARAM_IDGRP")->AsString=DeleteSymbol(str_id->Strings[j]);
		ReportRasdel1->Active=true;


	
		ReportRasdel1->First();
		while (!ReportRasdel1->Eof)
			{
			no=no+ReportRasdel1OUT_NACHOSTKOL->AsFloat;
			f_no=f_no+ReportRasdel1OUT_NACHOSTKOL_FISED->AsFloat;
			prih=prih+ReportRasdel1OUT_PRIHODKOL->AsFloat;
			f_prih=f_prih+ReportRasdel1OUT_PRIHODKOL_FISED->AsFloat;
			rash=rash+ReportRasdel1OUT_RASHODKOL->AsFloat;
			f_rash=f_rash+ReportRasdel1OUT_RASHODKOL_FISED->AsFloat;
			co=co+ReportRasdel1OUT_CONOSTKOL->AsFloat;
			f_co=f_co+ReportRasdel1OUT_CONOSTKOL_FISED->AsFloat;

			ReportRasdel1->Next();
			}
		}
	delete str_id;

	dc->AppendRecord();
	dc->Values[dc->RowCount-1][Rasdel1cxGridTableView1NAMEGRP->Index] =
										str_list->Strings[i];
	dc->Values[dc->RowCount-1][Rasdel1cxGridTableView1NACHOST->Index] = no;
	dc->Values[dc->RowCount-1][Rasdel1cxGridTableView1FISED_NACHOST->Index] = f_no;
	dc->Values[dc->RowCount-1][Rasdel1cxGridTableView1PRIHOD->Index] = prih;
	dc->Values[dc->RowCount-1][Rasdel1cxGridTableView1FISED_PRIHOD->Index] = f_prih;
	dc->Values[dc->RowCount-1][Rasdel1cxGridTableView1RASHOD->Index] = rash;
	dc->Values[dc->RowCount-1][Rasdel1cxGridTableView1FISED_RASHOD->Index] = f_rash;
	dc->Values[dc->RowCount-1][Rasdel1cxGridTableView1CONOST->Index] = co;
	dc->Values[dc->RowCount-1][Rasdel1cxGridTableView1FISED_CONOST->Index] = f_co;
	}
 

delete ini;
delete str_list;

}
//---------------------------------------------------------------------------
void __fastcall TFormaReport::cxButtonCreateRasdel1Click(TObject *Sender)
{
CreateReportRasdel1();

}
//---------------------------------------------------------------------------
void TFormaReport::CreateReportRasdel2(void)
{

TcxCustomDataController *dc = Rasdel2cxGridTableView1->DataController;
AnsiString file_ini=ExtractFileDir(Application->ExeName)+"\\"+AlcGrpFileName;
TIniFile * ini=new TIniFile(file_ini);

dc->BeginUpdate();
	for (int i=dc->RecordCount;i>0;i--)
		{
		dc->DeleteRecord(i-1);
		}
dc->EndUpdate();


TStringList * str_list=new TStringList;
ini->ReadSections(str_list);


SpisokFirm->First();
SpisokFirm->MoveBy(NameFirmcxLookupComboBox->ItemIndex);

SpisokSklad->First();
SpisokSklad->MoveBy(NameSkladcxLookupComboBox->ItemIndex);

for (int i=0;i<str_list->Count;i++)
	{
//	double no=0;
//	double f_no=0;
//	double prih=0;
//	double f_prih=0;
//	double rash=0;
//	double f_rash=0;
//	double co=0;
//	double f_co=0;

	TStringList * str_id=new TStringList;
	ini->ReadSectionValues(str_list->Strings[i], str_id);

	for (int j=0;j<str_id->Count;j++)
		{
		ReportRasdel2->Active=false;
		ReportRasdel2->ParamByName("PARAM_POSNACH")->AsDateTime=PosNachcxDateEdit->Date;
		ReportRasdel2->ParamByName("PARAM_POSCON")->AsDateTime=PosConcxDateEdit->Date;
		ReportRasdel2->ParamByName("PARAM_IDFIRM")->AsString=SpisokFirmIDFIRM->AsString;
		ReportRasdel2->ParamByName("PARAM_IDSKLAD")->AsString=SpisokSkladIDSKLAD->AsString;
		ReportRasdel2->ParamByName("PARAM_IDGRP")->AsString=DeleteSymbol(str_id->Strings[j]);
		ReportRasdel2->Active=true;


	
		ReportRasdel2->First();
		while (!ReportRasdel2->Eof)
			{

			dc->AppendRecord();
			dc->Values[dc->RowCount-1][Rasdel2cxGridTableView1NAMEGRP->Index] =
										str_list->Strings[i];
			dc->Values[dc->RowCount-1][Rasdel2cxGridTableView1NAME_POST->Index] =
										ReportRasdel2OUT_NAMEPOST->AsString;

			AnsiString id=ReportRasdel2OUT_IDPOST->AsString;
			if (id=="")
				{
				dc->Values[dc->RowCount-1][Rasdel2cxGridTableView1IDPOST->Index] =  "0";
				}
			else
				{
				dc->Values[dc->RowCount-1][Rasdel2cxGridTableView1IDPOST->Index] =  id;
				}

			dc->Values[dc->RowCount-1][Rasdel2cxGridTableView1NAME_PRODUCER->Index] =
										ReportRasdel2OUT_NAME_PRODUCER->AsString;

			id=ReportRasdel2OUT_IDPRODUCER->AsString;
			if (id=="")
				{
				dc->Values[dc->RowCount-1][Rasdel2cxGridTableView1IDPRODUCER->Index] =  "0";
				}
			else
				{
				dc->Values[dc->RowCount-1][Rasdel2cxGridTableView1IDPRODUCER->Index] =  id;
				}
				
			dc->Values[dc->RowCount-1][Rasdel2cxGridTableView1PRIHOD->Index] =
										ReportRasdel2OUT_PRIHODKOL->AsFloat;
			dc->Values[dc->RowCount-1][Rasdel2cxGridTableView1FISED_PRIHOD->Index] =
										ReportRasdel2OUT_PRIHODKOL_FISED->AsFloat;;
			ReportRasdel2->Next();
			}
		}
	delete str_id;


	}





delete ini;
delete str_list;

}
//----------------------------------------------------------------------------
void __fastcall TFormaReport::cxButtonCreateRasdel2Click(TObject *Sender)
{
CreateReportRasdel2();
}
//---------------------------------------------------------------------------

void __fastcall TFormaReport::cxButtonPrintRasdel2Click(TObject *Sender)
{
if (prForm!=0) return;

VsegoKolBasEd_Vol=0;
VsegoKolBasEd_NoVol=0;
VsegoKolFisEd_Vol=0;
VsegoKolFisEd_NoVol=0;

CreateReportRasdel2();


prForm=new TSheetEditor2(Application);

prForm->SS->BeginUpdate();
prForm->FOnCloseForm=EventCloseFormPrint;


numCol=1;
numRow=1;

TStringList * producer_list=GetSpisokProducer();
TStringList * supplier_list=GetSpisokSupplier();

OutputHeader();

//пункт 1 поставщики - производители Вологодской области
//*******************************************************
OutputPunkt1(producer_list);

OutputPunkt2(supplier_list,producer_list);

OutputPunkt3(supplier_list,producer_list);

OutputPunkt4(supplier_list,producer_list);

OutputVsegoRasdel5();

OutputItogoRasdel6();

OutputPodval();

prForm->SS->EndUpdate();

delete producer_list;
delete supplier_list;
}
//---------------------------------------------------------------------------
TStringList * TFormaReport::GetSpisokProducer(void)
{
TStringList * str_list=new TStringList;

AnsiString file_ini=ExtractFileDir(Application->ExeName)+"\\"+ProducerFileName;
TIniFile * ini=new TIniFile(file_ini);

ini->ReadSections(str_list);

delete ini;


return str_list;
}
//---------------------------------------------------------------------------
TStringList * TFormaReport::GetSpisokSupplier(void)
{
TStringList * str_list=new TStringList;

AnsiString file_ini=ExtractFileDir(Application->ExeName)+"\\"+PostFileName;
TIniFile * ini=new TIniFile(file_ini);

ini->ReadSections(str_list);

delete ini;


return str_list;
}
//---------------------------------------------------------------------------
TStringList * TFormaReport::GetSpisokSupplierNoVolObl(void)
{
TStringList * str_list=new TStringList;

TStringList * producer_list=GetSpisokProducer();
TStringList * supplier_list=GetSpisokSupplier();

TcxCustomDataController *dc = Rasdel2cxGridTableView1->DataController;


for (int i=0;i<dc->RecordCount;i++)
	{
	__int64 tec_klient = dc->Values[i][Rasdel2cxGridTableView1IDPOST->Index];
	bool add=true;
	//проверяем на производителя
	for (int j=0;j<producer_list->Count;j++)
		{
		__int64 id_producer=0;

		if (producer_list->Strings[j]!="")
			{
			id_producer=StrToInt64(producer_list->Strings[j]);
			}

		if (tec_klient==id_producer)
			{
			add=false;
			}
		}

	//проверяем на поставщика области
	for (int j=0;j<supplier_list->Count;j++)
		{
		__int64 id_supplier=0;

		if (supplier_list->Strings[j]!="")
			{
			id_supplier=StrToInt64(supplier_list->Strings[j]);
			}

		if (tec_klient==id_supplier)
			{
			add=false;
			}
		}

	if (add==true)
		{//проверяем а нет ли уже такого клиента
		for (int j=0;j<str_list->Count;j++)
			{
			__int64 id_supplier_no_obl=0;
			if (str_list->Strings[j]!="")
				{
				id_supplier_no_obl=StrToInt64(str_list->Strings[j]);
				}

			if  (tec_klient==id_supplier_no_obl)
				{
				 add=false;
				}

			}

		}

	if (add==true)
		{
		//ShowMessage("+  "+IntToStr(tec_klient));
		str_list->Add(IntToStr(tec_klient));
		}

	}

return str_list;
}
//---------------------------------------------------------------------------
AnsiString TFormaReport::GetNameKlient(AnsiString id)
{
AnsiString result="";
if (id!="")
	{
	KlientDataSet->Active=false;
	KlientDataSet->ParamByName("PARAM_ID")->AsString=StrToInt64(id);
	KlientDataSet->Active=true;
	result = KlientDataSetNAMEKLIENT->AsString;
	KlientDataSet->Active=false;
	}
return result;
}
//---------------------------------------------------------------------------
void __fastcall TFormaReport::EventCloseFormPrint(TObject *Sender)
{
prForm=0;

}
//----------------------------------------------------------------------------
void TFormaReport::OutputHeader(void)
{
TcxSSCellObject *cell;
TcxSSHeader *cHeader;

prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";
prForm->SS->RowsAutoHeight=true;


		cHeader = prForm->SS->ActiveSheet->Cols;
		cHeader->Size[0] = 30;
		cHeader->Size[1] = 30;
		cHeader->Size[2] = 200;
		cHeader->Size[3] = 100;
		cHeader->Size[4] = 100;
		cHeader->Size[5] = 100;
		cHeader->Size[6] = 100;


TRect rect;

numCol=4;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Раздел II";
delete cell;
numRow++;

numCol=1;
//************ 1 column *******************************
rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol;
rect.Bottom = numRow+2;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="№  п/п";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Text="";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+2);
cell->Text="";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+3);
cell->Text="1";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//************ 2 column *******************************
rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol;
rect.Bottom = numRow+2;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Поставщики";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Text="";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+2);
cell->Text="";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+3);
cell->Text="2";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//************ 3 column *******************************
rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol+3;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Поступило продукции";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol+1, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol+2, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol+3, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;


rect.Left = numCol;
rect.Top = numRow+1;
rect.Right = numCol+1;
rect.Bottom = numRow+1;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Text="бутылок";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol+1, numRow+1);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+2);
cell->Text="произведенной на территории Вологодской области";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+3);
cell->Text="3";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
numCol++;

//************ column 4 ***************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+2);
cell->Text="ввезенной из-за пределов Вологдской области (за исключением продукции, произведенной в области)";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+3);
cell->Text="4";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
numCol++;


//***************** column 5

rect.Left = numCol;
rect.Top = numRow+1;
rect.Right = numCol+1;
rect.Bottom = numRow+1;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Text="литров";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol+1, numRow+1);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+2);
cell->Text="произведенной на территории Вологодской области";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+3);
cell->Text="5";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
numCol++;

//************ column 4 ***************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+2);
cell->Text="ввезенной из-за пределов Вологдской области (за исключением продукции, произведенной в области)";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+3);
cell->Text="6";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
numCol++;


numRow++;
numRow++;
numRow++;
numRow++;

}
//---------------------------------------------------------------------------
void TFormaReport::OutputPunkt1(TStringList * producer_list)
{
TcxCustomDataController *dc = Rasdel2cxGridTableView1->DataController;
TcxSSCellObject *cell;

numCol=1;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text="1";
	cell->Style->HorzTextAlign = haCENTER;
	cell->Style->Font->Size = 10;
	cell->Style->WordBreak = true;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	numCol++;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Style->WordBreak = true;
	cell->Style->Font->Size = 10;
	cell->Text="Организации, осуществляющие производство алкогольной продукции на территории Вологодской области";
//	cell->Style->HorzTextAlign = haCENTER;


	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
    numCol++;
		//бутылок произведено на терр. Вологодской области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="";
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		cell->Style->Borders->Edges [eTop]->Style=lsThin;
		delete cell;
		numCol++;
		//бутылок ввезено из-за пределов области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="X";
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		cell->Style->Borders->Edges [eTop]->Style=lsThin;
		delete cell;
		numCol++;
		//литров произведено на терр Вологодской обл.
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="";
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		cell->Style->Borders->Edges [eTop]->Style=lsThin;
		delete cell;
		numCol++;
		//ввезено из-за пределов области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="X";
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		cell->Style->Borders->Edges [eTop]->Style=lsThin;
		delete cell;
		numCol++;

	numRow++;
	double all_kol_bas_ed=0;
	double all_kol_fis_ed=0;
for (int i=0;i<producer_list->Count;i++)
	{
	//считаем сколько куплено у этого производителя
	double kol_bas_ed=0;
	double kol_fis_ed=0;
	__int64 id_producer=0;

	if (producer_list->Strings[i]!="")
		{
		id_producer=StrToInt64(producer_list->Strings[i]);
		}

	for (int i=0;i<dc->RecordCount;i++)
		{  //сколько куплено у производителей
		__int64 tec_klient = dc->Values[i][Rasdel2cxGridTableView1IDPOST->Index];
	   //	ShowMessage(IntToStr(tec_klient)+"  -  "+ IntToStr(id_producer));
		if (id_producer==tec_klient)
			{
			double tek_kol_bas_ed=dc->Values[i][Rasdel2cxGridTableView1PRIHOD->Index];
			double tek_kol_fis_ed=dc->Values[i][Rasdel2cxGridTableView1FISED_PRIHOD->Index];
			kol_bas_ed=kol_bas_ed+tek_kol_bas_ed;
			kol_fis_ed=kol_fis_ed+tek_kol_fis_ed;
			all_kol_bas_ed=all_kol_bas_ed+tek_kol_bas_ed;
			all_kol_fis_ed=all_kol_fis_ed+tek_kol_fis_ed;
			VsegoKolBasEd_Vol=VsegoKolBasEd_Vol+tek_kol_bas_ed;
			VsegoKolFisEd_Vol=VsegoKolFisEd_Vol+tek_kol_fis_ed;
			}
		}

		if (kol_fis_ed < 0.001  && kol_bas_ed < 0.001)
			{

			}
		else
			{
		numCol=1;
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="";
		//	cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//наименование клиента
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text=GetNameKlient(producer_list->Strings[i]);
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 8;
		cell->Style->WordBreak = true;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//бутылок произведено на терр. Вологодской области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text=FloatToStrF(kol_bas_ed,ffFixed,15,0);
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//бутылок ввезено из-за пределов области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="X";
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//литров произведено на терр Вологодской обл.
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text=FloatToStrF(kol_fis_ed,ffFixed,15,0);
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//ввезено из-за пределов области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="X";
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;

		numRow++;
		}
	}

	numCol=1;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text="";
//	cell->Style->HorzTextAlign = haCENTER;
	cell->Style->Font->Size = 10;
	cell->Style->WordBreak = true;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	//cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	numCol++;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text="ВСЕГО:";
	cell->Style->HorzTextAlign = haCENTER;
	cell->Style->Font->Style = TFontStyles() << fsBold;
	cell->Style->Font->Size = 10;
	cell->Style->WordBreak = true;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	//cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	numCol++;
		//бутылок произведено на терр. Вологодской области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text=FloatToStrF(all_kol_bas_ed,ffFixed,15,0);
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//бутылок ввезено из-за пределов области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="X";
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//литров произведено на терр Вологодской обл.
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text=FloatToStrF(all_kol_fis_ed,ffFixed,15,0);
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//ввезено из-за пределов области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="X";
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
numRow++;

}
//------------------------------------------------------------------------------
void TFormaReport::OutputPunkt2(TStringList * supplier_list, TStringList * producer_list)
{
//2 оптовые базы Вологодской области

//TcxCustomDataController *dc = Rasdel2cxGridTableView1->DataController;
TcxSSCellObject *cell;
numCol=1;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text="2";
	cell->Style->HorzTextAlign = haCENTER;
	cell->Style->Font->Size = 10;
	cell->Style->WordBreak = true;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	numCol++;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Style->WordBreak = true;
	cell->Style->Font->Size = 10;
	cell->Text="Оптовые организации, зарегистрированные на территории Вологодской области";
//	cell->Style->HorzTextAlign = haCENTER;


	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	numCol++;
		//бутылок произведено на терр. Вологодской области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="";
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		cell->Style->Borders->Edges [eTop]->Style=lsThin;
		delete cell;
		numCol++;
		//бутылок ввезено из-за пределов области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="X";
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		cell->Style->Borders->Edges [eTop]->Style=lsThin;
		delete cell;
		numCol++;
		//литров произведено на терр Вологодской обл.
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="";
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		cell->Style->Borders->Edges [eTop]->Style=lsThin;
		delete cell;
		numCol++;
		//ввезено из-за пределов области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="X";
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		cell->Style->Borders->Edges [eTop]->Style=lsThin;
		delete cell;
		numCol++;

	numRow++;

	AllPunkt2BasEd=0;
	AllPunkt2FisEd=0;

for (int i=0;i<supplier_list->Count;i++)
	{
	//считаем сколько куплено у этого поставщика
	__int64 id_supplier=0;

	if (supplier_list->Strings[i]!="")
		{
		id_supplier=StrToInt64(supplier_list->Strings[i]);
		}

//	for (int i=0;i<dc->RecordCount;i++)
//		{
//		__int64 tec_klient = dc->Values[i][Rasdel2cxGridTableView1IDPOST->Index];
//	   //	ShowMessage(IntToStr(tec_klient)+"  -  "+ IntToStr(id_producer));
//		if (id_supplier==tec_klient)
//			{
//			kol_bas_ed=kol_bas_ed+ReportRasdel2OUT_PRIHODKOL->AsFloat;
//			kol_fis_ed=kol_fis_ed+ReportRasdel2OUT_PRIHODKOL_FISED->AsFloat;
//			all_kol_bas_ed=all_kol_bas_ed+ReportRasdel2OUT_PRIHODKOL->AsFloat;
//			all_kol_fis_ed=all_kol_fis_ed+ReportRasdel2OUT_PRIHODKOL_FISED->AsFloat;
//
//			}
//		}
		int num_row_name_post=numRow;
		numCol=1;
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="";
		//	cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//наименование клиента
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text=GetNameKlient(supplier_list->Strings[i]);
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 8;
		cell->Style->WordBreak = true;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//бутылок произведено на терр. Вологодской области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="";
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//бутылок ввезено из-за пределов области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="X";
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//литров произведено на терр Вологодской обл.
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="";
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//ввезено из-за пределов области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="X";
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;

		AllPunkt2BasEdPoPost=0;
		AllPunkt2FisEdPoPost=0;
		numRow++;
		OutputPunkt2PoProducer(id_supplier,producer_list );

		if (AllPunkt2BasEdPoPost < 0.001 &&  AllPunkt2FisEdPoPost < 0.001)
			{
			numRow=num_row_name_post;
			}
		else
		{
		cell = prForm->SS->ActiveSheet->GetCellObject(3, num_row_name_post);
		cell->Text=FloatToStrF(AllPunkt2BasEdPoPost,ffFixed,15,0);
		delete cell;
		cell = prForm->SS->ActiveSheet->GetCellObject(5, num_row_name_post);
		cell->Text=FloatToStrF(AllPunkt2FisEdPoPost,ffFixed,15,0);
		delete cell;
        }
   //	numRow++;

	}

	//всего по разделу 2
	numCol=1;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text="";
//	cell->Style->HorzTextAlign = haCENTER;
	cell->Style->Font->Size = 10;
	cell->Style->WordBreak = true;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	//cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	numCol++;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text="ВСЕГО:";
	cell->Style->HorzTextAlign = haCENTER;
	cell->Style->Font->Style = TFontStyles() << fsBold;
	cell->Style->Font->Size = 10;
	cell->Style->WordBreak = true;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	//cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	numCol++;
		//бутылок произведено на терр. Вологодской области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text=FloatToStrF(AllPunkt2BasEd,ffFixed,15,0);
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//бутылок ввезено из-за пределов области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="X";
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//литров произведено на терр Вологодской обл.
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text=FloatToStrF(AllPunkt2FisEd,ffFixed,15,0);
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//ввезено из-за пределов области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="X";
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;


numRow++;
}
//-----------------------------------------------------------------------------
void TFormaReport::OutputPunkt2PoProducer(__int64 id_supplier, TStringList * producer_list )
{
TcxCustomDataController *dc = Rasdel2cxGridTableView1->DataController;
TcxSSCellObject *cell;

for (int i=0;i<producer_list->Count;i++)
	{
	//считаем сколько куплено у этого производителя
	double kol_bas_ed=0;
	double kol_fis_ed=0;
	__int64 id_producer=0;

	if (producer_list->Strings[i]!="")
		{
		id_producer=StrToInt64(producer_list->Strings[i]);
		}

	for (int i=0;i<dc->RecordCount;i++)
		{  //сколько произведено в Вологодской области
		__int64 tec_klient = dc->Values[i][Rasdel2cxGridTableView1IDPOST->Index];
		__int64 tec_producer=dc->Values[i][Rasdel2cxGridTableView1IDPRODUCER->Index];
	   //	ShowMessage(IntToStr(tec_klient)+"  -  "+ IntToStr(id_producer));
		if (id_supplier==tec_klient && id_producer==tec_producer)
			{
			double tek_kol_bas_ed=dc->Values[i][Rasdel2cxGridTableView1PRIHOD->Index];
			double tek_kol_fis_ed=dc->Values[i][Rasdel2cxGridTableView1FISED_PRIHOD->Index];
			kol_bas_ed=kol_bas_ed+tek_kol_bas_ed;
			kol_fis_ed=kol_fis_ed+tek_kol_fis_ed;
			AllPunkt2BasEd=AllPunkt2BasEd+tek_kol_bas_ed;
			AllPunkt2FisEd=AllPunkt2FisEd+tek_kol_fis_ed;
			AllPunkt2BasEdPoPost=AllPunkt2BasEdPoPost+tek_kol_bas_ed;
			AllPunkt2FisEdPoPost=AllPunkt2FisEdPoPost+tek_kol_fis_ed;
			VsegoKolBasEd_Vol=VsegoKolBasEd_Vol+tek_kol_bas_ed;
			VsegoKolFisEd_Vol=VsegoKolFisEd_Vol+tek_kol_fis_ed;
			}
		}
		if (kol_bas_ed < 0.001 && kol_fis_ed < 0.001)
			{

			}
		else
			{
		numCol=1;
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="";
		//	cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//наименование клиента
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text=GetNameKlient(producer_list->Strings[i]);
		cell->Style->HorzTextAlign = haRIGHT;
		cell->Style->Font->Size = 8;
		cell->Style->WordBreak = true;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//бутылок произведено на терр. Вологодской области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text=FloatToStrF(kol_bas_ed,ffFixed,15,0);
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//бутылок ввезено из-за пределов области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="X";
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//литров произведено на терр Вологодской обл.
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text=FloatToStrF(kol_fis_ed,ffFixed,15,0);
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//ввезено из-за пределов области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="X";
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;

	numRow++;
		}
	}     //перебор производителей

//numRow++;
}
//----------------------------------------------------------------------------
void TFormaReport::OutputPunkt3(TStringList * supplier_list, TStringList * producer_list)
{
//2 оптовые базы Вологодской области

//TcxCustomDataController *dc = Rasdel2cxGridTableView1->DataController;
TcxSSCellObject *cell;
numCol=1;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text="3";
	cell->Style->HorzTextAlign = haCENTER;
	cell->Style->Font->Size = 10;
	cell->Style->WordBreak = true;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	numCol++;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Style->WordBreak = true;
	cell->Style->Font->Size = 10;
	cell->Text="Оптовые организации, зарегистрированные на территории Вологодской области";
//	cell->Style->HorzTextAlign = haCENTER;


	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	numCol++;
		//бутылок произведено на терр. Вологодской области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="X";
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		cell->Style->Borders->Edges [eTop]->Style=lsThin;
		delete cell;
		numCol++;
		//бутылок ввезено из-за пределов области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="";
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		cell->Style->Borders->Edges [eTop]->Style=lsThin;
		delete cell;
		numCol++;
		//литров произведено на терр Вологодской обл.
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="X";
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		cell->Style->Borders->Edges [eTop]->Style=lsThin;
		delete cell;
		numCol++;
		//ввезено из-за пределов области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="";
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		cell->Style->Borders->Edges [eTop]->Style=lsThin;
		delete cell;
		numCol++;

	numRow++;

	AllPunkt3BasEd=0;
	AllPunkt3FisEd=0;

for (int i=0;i<supplier_list->Count;i++)
	{
	//считаем сколько куплено у этого поставщика
	__int64 id_supplier=0;

	if (supplier_list->Strings[i]!="")
		{
		id_supplier=StrToInt64(supplier_list->Strings[i]);
		}

//	for (int i=0;i<dc->RecordCount;i++)
//		{
//		__int64 tec_klient = dc->Values[i][Rasdel2cxGridTableView1IDPOST->Index];
//	   //	ShowMessage(IntToStr(tec_klient)+"  -  "+ IntToStr(id_producer));
//		if (id_supplier==tec_klient)
//			{
//			kol_bas_ed=kol_bas_ed+ReportRasdel2OUT_PRIHODKOL->AsFloat;
//			kol_fis_ed=kol_fis_ed+ReportRasdel2OUT_PRIHODKOL_FISED->AsFloat;
//			all_kol_bas_ed=all_kol_bas_ed+ReportRasdel2OUT_PRIHODKOL->AsFloat;
//			all_kol_fis_ed=all_kol_fis_ed+ReportRasdel2OUT_PRIHODKOL_FISED->AsFloat;
//
//			}
//		}
		int num_row_name_post=numRow;
		numCol=1;
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="";
		//	cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//наименование клиента
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text=GetNameKlient(supplier_list->Strings[i]);
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 8;
		cell->Style->WordBreak = true;
	   //	cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//бутылок произведено на терр. Вологодской области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="X";
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
	   //	cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//бутылок ввезено из-за пределов области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="";
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
	   //	cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//литров произведено на терр Вологодской обл.
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="X";
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		//cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//ввезено из-за пределов области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="";
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		//cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;

		AllPunkt3BasEdPoPost=0;
		AllPunkt3FisEdPoPost=0;
		numRow++;
		OutputPunkt3PoProducer(id_supplier,producer_list );

		if ( AllPunkt3BasEdPoPost < 0.001 && AllPunkt3FisEdPoPost < 0.001)
			{
            numRow=num_row_name_post;
			}
		else
			{
		cell = prForm->SS->ActiveSheet->GetCellObject(4, num_row_name_post);
		cell->Text=FloatToStrF(AllPunkt3BasEdPoPost,ffFixed,15,0);
		delete cell;
		cell = prForm->SS->ActiveSheet->GetCellObject(6, num_row_name_post);
		cell->Text=FloatToStrF(AllPunkt3FisEdPoPost,ffFixed,15,0);
		delete cell;
			}
   //	numRow++;

	}

	//всего по разделу 2
	numCol=1;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text="";
//	cell->Style->HorzTextAlign = haCENTER;
	cell->Style->Font->Size = 10;
	cell->Style->WordBreak = true;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	//cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	numCol++;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text="ВСЕГО:";
	cell->Style->HorzTextAlign = haCENTER;
	cell->Style->Font->Style = TFontStyles() << fsBold;
	cell->Style->Font->Size = 10;
	cell->Style->WordBreak = true;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	//cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	numCol++;
		//бутылок произведено на терр. Вологодской области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="X";
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//бутылок ввезено из-за пределов области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text=FloatToStrF(AllPunkt3BasEd,ffFixed,15,0);
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//литров произведено на терр Вологодской обл.
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="X";
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//ввезено из-за пределов области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text= FloatToStrF(AllPunkt3FisEd,ffFixed,15,0);
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;


numRow++;
}
//-----------------------------------------------------------------------------
void TFormaReport::OutputPunkt3PoProducer(__int64 id_supplier, TStringList * producer_list )
{
TcxCustomDataController *dc = Rasdel2cxGridTableView1->DataController;
TcxSSCellObject *cell;


for (int i=0;i<dc->RecordCount;i++)
	{  //сколько произведено в Вологодской области
	__int64 tec_klient = dc->Values[i][Rasdel2cxGridTableView1IDPOST->Index];
	__int64 tec_producer=dc->Values[i][Rasdel2cxGridTableView1IDPRODUCER->Index];
	if (id_supplier==tec_klient)
		{
		bool add=true; //Вологодская обл.
		for (int i=0;i<producer_list->Count;i++)
			{ //перебираем производителей Вологодской области
			__int64 id_producer=0;
			if (producer_list->Strings[i]!="")
				{
				id_producer=StrToInt64(producer_list->Strings[i]);
				}

			if (id_producer==tec_producer)
				{
				add=false;//Вологодская область
				}
			}

		if (add==true)
			{
			double tek_kol_bas_ed=dc->Values[i][Rasdel2cxGridTableView1PRIHOD->Index];
			double tek_kol_fis_ed=dc->Values[i][Rasdel2cxGridTableView1FISED_PRIHOD->Index];
			AllPunkt3BasEd=AllPunkt3BasEd+tek_kol_bas_ed;  //всех поставщиков Вологодской области
			AllPunkt3FisEd=AllPunkt3FisEd+tek_kol_fis_ed;
			AllPunkt3BasEdPoPost=AllPunkt3BasEdPoPost+tek_kol_bas_ed; //    конкретного поставщика Вологодской области
			AllPunkt3FisEdPoPost=AllPunkt3FisEdPoPost+tek_kol_fis_ed; //
			VsegoKolBasEd_NoVol=VsegoKolBasEd_NoVol+tek_kol_bas_ed;
			VsegoKolFisEd_NoVol=VsegoKolFisEd_NoVol+tek_kol_fis_ed;

			}
		}
    }
//numRow++;
}
//----------------------------------------------------------------------------
void TFormaReport::OutputPunkt4(TStringList * supplier_list, TStringList * producer_list)
{
KolBasEd_Vol=0;
KolBasEd_NoVol=0;
KolFisEd_Vol=0;
KolFisEd_NoVol=0;
OutputZagStringRasdel4();

TcxCustomDataController *dc = Rasdel2cxGridTableView1->DataController;
TStringList * klient_list=GetSpisokSupplierNoVolObl();

//перебираем всех поставщиков
for (int i=0;i<klient_list->Count;i++)
	{//получим текущего поставщика
	__int64 id_tec_post=0;
	if (klient_list->Strings[i]!="")
		{
		id_tec_post=StrToInt64(klient_list->Strings[i]);
		}

	NameKlient=GetNameKlient(id_tec_post);
	PoPost_KolBasEd_Vol=0;
	PoPost_KolBasEd_NoVol=0;
	PoPost_KolFisEd_Vol=0;
	PoPost_KolFisEd_NoVol=0;

	//рассчитаем его поступления
	for (int j=0;j<dc->RecordCount;j++)
		{

		__int64 tec_klient = dc->Values[j][Rasdel2cxGridTableView1IDPOST->Index];
		__int64 tec_producer=dc->Values[j][Rasdel2cxGridTableView1IDPRODUCER->Index];

		if (tec_klient==id_tec_post)
			{ //запись этого поставщика
			//перебираем производителей Вологодской области
			bool vol_obl=false;
			for (int k=0;k<producer_list->Count;k++)
				{
				__int64 id_producer=0;
				if (producer_list->Strings[k]!="")
					{
					id_producer=StrToInt64(producer_list->Strings[k]);
					}

				if (id_producer==tec_producer)
					{
					vol_obl=true;//Вологодская область
					}
				}

			double tek_kol_bas_ed=dc->Values[j][Rasdel2cxGridTableView1PRIHOD->Index];
			double tek_kol_fis_ed=dc->Values[j][Rasdel2cxGridTableView1FISED_PRIHOD->Index];				
			if (vol_obl==true)
				{ //ВОЛОГОДСКАЯ ОБЛ.

				PoPost_KolBasEd_Vol=PoPost_KolBasEd_Vol+tek_kol_bas_ed;
				PoPost_KolFisEd_Vol=PoPost_KolFisEd_Vol+tek_kol_fis_ed;
				KolBasEd_Vol=KolBasEd_Vol+tek_kol_bas_ed;
				KolFisEd_Vol=KolFisEd_Vol+tek_kol_fis_ed;
				VsegoKolBasEd_Vol=VsegoKolBasEd_Vol+tek_kol_bas_ed;
				VsegoKolFisEd_Vol=VsegoKolFisEd_Vol+tek_kol_fis_ed;
				}
			else
				{ //НЕ ВОЛОГ. ОБЛАСТЬ
				PoPost_KolBasEd_NoVol=PoPost_KolBasEd_NoVol+tek_kol_bas_ed;
				PoPost_KolFisEd_NoVol=PoPost_KolFisEd_NoVol+tek_kol_fis_ed;
				KolBasEd_NoVol=KolBasEd_NoVol+tek_kol_bas_ed;
				KolFisEd_NoVol=KolFisEd_NoVol+tek_kol_fis_ed;
				VsegoKolBasEd_NoVol=VsegoKolBasEd_NoVol+tek_kol_bas_ed;
				VsegoKolFisEd_Vol=VsegoKolFisEd_Vol+tek_kol_fis_ed;
				}



			}
		}

	OutputStringRasdel4();

	}

OutputPodvalStringRasdel4();	
}
//------------------------------------------------------------------------------
void TFormaReport::OutputStringRasdel4(void)
{
TcxSSCellObject *cell;
if (PoPost_KolBasEd_Vol < 0.001 &&  PoPost_KolBasEd_NoVol < 0.001
		&&  PoPost_KolFisEd_Vol < 0.001 &&  PoPost_KolFisEd_NoVol < 0.001)
	{
	}
else
	{
		numCol=1;
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="";
		//	cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//наименование клиента
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text=NameKlient;
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 8;
		cell->Style->WordBreak = true;
	   //	cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//бутылок произведено на терр. Вологодской области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text=FloatToStrF(PoPost_KolBasEd_Vol,ffFixed,15,0);
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
	   //	cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//бутылок ввезено из-за пределов области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text=FloatToStrF(PoPost_KolBasEd_NoVol,ffFixed,15,0);
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
	   //	cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//литров произведено на терр Вологодской обл.
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text=FloatToStrF(PoPost_KolFisEd_Vol,ffFixed,15,0);
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		//cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//ввезено из-за пределов области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text=FloatToStrF(PoPost_KolFisEd_NoVol,ffFixed,15,0);
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		//cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;

numRow++;
	}
}
//-----------------------------------------------------------------------------
void TFormaReport::OutputZagStringRasdel4(void)
{
TcxSSCellObject *cell;
numCol=1;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text="4";
	cell->Style->HorzTextAlign = haCENTER;
	cell->Style->Font->Size = 10;
	cell->Style->WordBreak = true;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	numCol++;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Style->WordBreak = true;
	cell->Style->Font->Size = 10;
	cell->Text="Оптовые организации, зарегистрированные за пределами Вологодской области";
//	cell->Style->HorzTextAlign = haCENTER;


	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	numCol++;
		//бутылок произведено на терр. Вологодской области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="";
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		cell->Style->Borders->Edges [eTop]->Style=lsThin;
		delete cell;
		numCol++;
		//бутылок ввезено из-за пределов области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="";
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		cell->Style->Borders->Edges [eTop]->Style=lsThin;
		delete cell;
		numCol++;
		//литров произведено на терр Вологодской обл.
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="";
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		cell->Style->Borders->Edges [eTop]->Style=lsThin;
		delete cell;
		numCol++;
		//ввезено из-за пределов области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text="";
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		cell->Style->Borders->Edges [eTop]->Style=lsThin;
		delete cell;
		numCol++;

	numRow++;
}
//----------------------------------------------------------------------------
void TFormaReport::OutputPodvalStringRasdel4(void)
{
TcxSSCellObject *cell;
	//всего по разделу 2
	numCol=1;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text="";
//	cell->Style->HorzTextAlign = haCENTER;
	cell->Style->Font->Size = 10;
	cell->Style->WordBreak = true;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	//cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	numCol++;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text="ВСЕГО:";
	cell->Style->HorzTextAlign = haCENTER;
	cell->Style->Font->Style = TFontStyles() << fsBold;
	cell->Style->Font->Size = 10;
	cell->Style->WordBreak = true;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	//cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	numCol++;
		//бутылок произведено на терр. Вологодской области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text=FloatToStrF(KolBasEd_Vol,ffFixed,15,0);
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//бутылок ввезено из-за пределов области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text=FloatToStrF(KolBasEd_NoVol,ffFixed,15,0);
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//литров произведено на терр Вологодской обл.
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text=FloatToStrF(KolFisEd_Vol,ffFixed,15,0);
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//ввезено из-за пределов области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text= FloatToStrF(KolFisEd_NoVol,ffFixed,15,0);
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 10;
		cell->Style->WordBreak = true;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		//cell->Style->Borders->Edges [eTop]->Style=lsThin;
		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;


numRow++;

}
//-----------------------------------------------------------------------------
void TFormaReport::OutputVsegoRasdel5(void)
{
TcxSSCellObject *cell;
	//всего
	numCol=1;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text="5";
	cell->Style->HorzTextAlign = haCENTER;
	cell->Style->Font->Size = 10;
	cell->Style->WordBreak = true;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	numCol++;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text="ВСЕГО:";
	//cell->Style->HorzTextAlign = haCENTER;
	cell->Style->Font->Style = TFontStyles() << fsBold;
	cell->Style->Font->Size = 12;
	cell->Style->WordBreak = true;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	numCol++;
		//бутылок произведено на терр. Вологодской области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text=FloatToStrF(VsegoKolBasEd_Vol,ffFixed,15,0);
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Font->Size = 12;
		cell->Style->WordBreak = true;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		cell->Style->Borders->Edges [eTop]->Style=lsThin;
		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//бутылок ввезено из-за пределов области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text=FloatToStrF(VsegoKolBasEd_NoVol,ffFixed,15,0);
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 12;
		cell->Style->WordBreak = true;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		cell->Style->Borders->Edges [eTop]->Style=lsThin;
		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//литров произведено на терр Вологодской обл.
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text=FloatToStrF(VsegoKolFisEd_Vol,ffFixed,15,0);
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 12;
		cell->Style->WordBreak = true;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		cell->Style->Borders->Edges [eTop]->Style=lsThin;
		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//ввезено из-за пределов области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text= FloatToStrF(VsegoKolFisEd_NoVol,ffFixed,15,0);
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 12;
		cell->Style->WordBreak = true;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		cell->Style->Borders->Edges [eTop]->Style=lsThin;
		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;


numRow++;

}
//------------------------------------------------------------------------------
void TFormaReport::OutputItogoRasdel6(void)
{
TcxSSCellObject *cell;
TRect rect;

	//всего
	numCol=1;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text="6";
	cell->Style->HorzTextAlign = haCENTER;
	cell->Style->Font->Size = 10;
	cell->Style->WordBreak = true;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	numCol++;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text="ИТОГО:";
	//cell->Style->HorzTextAlign = haCENTER;
	cell->Style->Font->Style = TFontStyles() << fsBold;
	cell->Style->Font->Size = 12;
	cell->Style->WordBreak = true;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	numCol++;
		rect.Left = numCol;
		rect.Top = numRow;
		rect.Right = numCol+1;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
		//бутылок произведено на терр. Вологодской области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text=FloatToStrF(VsegoKolBasEd_Vol+VsegoKolBasEd_NoVol,ffFixed,15,0);
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Font->Size = 12;
		cell->Style->WordBreak = true;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		//cell->Style->Borders->Edges [eRight]->Style=lsThin;
		cell->Style->Borders->Edges [eTop]->Style=lsThin;
		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//бутылок ввезено из-за пределов области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		//cell->Text=FloatToStrF(VsegoKolBasEd_NoVol,ffFixed,15,0);
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 12;
		cell->Style->WordBreak = true;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		cell->Style->Borders->Edges [eTop]->Style=lsThin;
		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		rect.Left = numCol;
		rect.Top = numRow;
		rect.Right = numCol+1;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);		
		//литров произведено на терр Вологодской обл.
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Text=FloatToStrF(VsegoKolFisEd_Vol+VsegoKolFisEd_NoVol,ffFixed,15,0);
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 12;
		cell->Style->WordBreak = true;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		//cell->Style->Borders->Edges [eRight]->Style=lsThin;
		cell->Style->Borders->Edges [eTop]->Style=lsThin;
		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;
		//ввезено из-за пределов области
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		//cell->Text= FloatToStrF(VsegoKolFisEd_NoVol,ffFixed,15,0);
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->Font->Size = 12;
		cell->Style->WordBreak = true;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		cell->Style->Borders->Edges [eTop]->Style=lsThin;
		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;


numRow++;

}
//------------------------------------------------------------------------------
void TFormaReport::OutputPodval(void)
{
TcxSSCellObject *cell;
TRect rect;

numRow++;
numRow++;

	numCol=2;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text="Руководитель организации";
	cell->Style->Font->Size = 10;
	delete cell;
	numCol++;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	cell->Text="";
	delete cell;
	numCol++;
	numCol++;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	cell->Text="";
	delete cell;
	numCol++;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	cell->Text="";
	delete cell;

	numRow++;
	numCol=3;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text="Подпись";
	cell->Style->Font->Size = 8;
	cell->Style->VertTextAlign = vaTOP;
	cell->Style->HorzTextAlign = haCENTER;
	delete cell;
	numCol++;
	numCol++;
		rect.Left = numCol;
		rect.Top = numRow;
		rect.Right = numCol+1;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	cell->Text="ФИО";
	cell->Style->HorzTextAlign = haCENTER;
	cell->Style->VertTextAlign = vaTOP;
	cell->Style->Font->Size = 8;
	delete cell;
	numCol++;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	cell->Text="";
	delete cell;

	numRow++;

	numCol=2;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text="Главный бухгалтер";
	cell->Style->Font->Size = 10;
	delete cell;
	numCol++;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	cell->Text="";
	delete cell;
	numCol++;
	numCol++;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	cell->Text="";
	delete cell;
	numCol++;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	cell->Text="";
	delete cell;

	numRow++;
	numCol=3;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text="Подпись";
	cell->Style->Font->Size = 8;
	cell->Style->VertTextAlign = vaTOP;
	cell->Style->HorzTextAlign = haCENTER;
	delete cell;
	numCol++;
	numCol++;
		rect.Left = numCol;
		rect.Top = numRow;
		rect.Right = numCol+1;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	cell->Text="ФИО";
	cell->Style->HorzTextAlign = haCENTER;
	cell->Style->VertTextAlign = vaTOP;
	cell->Style->Font->Size = 8;
	delete cell;
	numCol++;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	cell->Text="";
	delete cell;

	numRow++;
	numCol=2;
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text=" М.П.";
	delete cell;
	numRow++;
	numRow++;

		numCol=2;
		rect.Left = numCol;
		rect.Top = numRow;
		rect.Right = numCol+4;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text="    раздел II декларации заполняется на отдельных бланках по организации в целом";
	delete cell;
	numRow++;
		numCol=2;
		rect.Left = numCol;
		rect.Top = numRow;
		rect.Right = numCol+4;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text="и раздельно по каждому территориально обособленному объекту";
	delete cell;
		numRow++;
		numCol=2;
		rect.Left = numCol;
		rect.Top = numRow;
		rect.Right = numCol+4;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text="    Х - графа не заполняется";
	delete cell;
}
//-----------------------------------------------------------------------------

void __fastcall TFormaReport::cxButtonPrintRasdel1Click(TObject *Sender)
{
CreateReportRasdel1();


numCol=1;
numRow=1;

Rasdel1_NachOstBasEd=0;
Rasdel1_PrihodBasEd=0;
Rasdel1_RashodBasEd=0;
Rasdel1_ConOstBasEd=0;

Rasdel1_NachOstFisEd=0;
Rasdel1_PrihodFisEd=0;
Rasdel1_RashodFisEd=0;
Rasdel1_ConOstFisEd=0;

prForm=new TSheetEditor2(Application);

prForm->SS->BeginUpdate();
prForm->FOnCloseForm=EventCloseFormPrint;


Rasdel1_OutputHeader();

TcxCustomDataController *dc = Rasdel1cxGridTableView1->DataController;

for (int i=0;i<dc->RecordCount;i++)
	{
	Rasdel1_OutputString(i);

	Rasdel1_NachOstBasEd=Rasdel1_NachOstBasEd+
								dc->Values[i][Rasdel1cxGridTableView1NACHOST->Index];
	Rasdel1_PrihodBasEd=Rasdel1_PrihodBasEd+
								dc->Values[i][Rasdel1cxGridTableView1PRIHOD->Index];
	Rasdel1_RashodBasEd=Rasdel1_RashodBasEd+
								dc->Values[i][Rasdel1cxGridTableView1RASHOD->Index];
	Rasdel1_ConOstBasEd=Rasdel1_ConOstBasEd+
								dc->Values[i][Rasdel1cxGridTableView1CONOST->Index];

	Rasdel1_NachOstFisEd=Rasdel1_NachOstFisEd+
								dc->Values[i][Rasdel1cxGridTableView1FISED_NACHOST->Index];
	Rasdel1_PrihodFisEd=Rasdel1_PrihodFisEd+
								dc->Values[i][Rasdel1cxGridTableView1FISED_PRIHOD->Index];
	Rasdel1_RashodFisEd=Rasdel1_RashodFisEd	+
								dc->Values[i][Rasdel1cxGridTableView1FISED_RASHOD->Index];
	Rasdel1_ConOstFisEd=Rasdel1_ConOstFisEd+
								dc->Values[i][Rasdel1cxGridTableView1FISED_CONOST->Index];
	}


Rasdel1_OutputFooter();

prForm->SS->EndUpdate();
}
//---------------------------------------------------------------------------
void TFormaReport::Rasdel1_OutputHeader(void)
{
SpisokFirm->First();
SpisokFirm->MoveBy(NameFirmcxLookupComboBox->ItemIndex);

SpisokSklad->First();
SpisokSklad->MoveBy(NameSkladcxLookupComboBox->ItemIndex);

Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select * from SFIRM where IDFIRM="+IntToStr(glStrToInt64(SpisokFirmIDFIRM->AsString)));
Query->ExecQuery();


//if (pFIBQ->FieldByName("TSKLAD")->AsInteger==1)


prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";
prForm->SS->RowsAutoHeight=true;


TcxSSHeader *cHeader;
		cHeader = prForm->SS->ActiveSheet->Cols;
		cHeader->Size[0] = 30;
		cHeader->Size[1] = 200;

TcxSSCellObject *cell;
TRect rect;


numCol=1;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Данные об организации:";
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 10;
delete cell;
numRow++;

prForm->SS->ActiveSheet->Rows->Size[numRow]=30;
numCol=1;
		rect.Left = numCol;
		rect.Top = numRow;
		rect.Right = numCol+1;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Наименование";
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 8;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
		rect.Left = numCol;
		rect.Top = numRow;
		rect.Right = numCol+4;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=Query->FieldByName("FNAMEFIRM")->AsString;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numRow++;



numCol=1;
		rect.Left = numCol;
		rect.Top = numRow;
		rect.Right = numCol+1;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="ИНН, ОКПО";
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 8;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
		rect.Left = numCol;
		rect.Top = numRow;
		rect.Right = numCol+4;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="ИНН "+Query->FieldByName("INNFIRM")->AsString+"  ОКПО "+
				Query->FieldByName("OKPOSFIRM")->AsString;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numRow++;

numCol=1;
prForm->SS->ActiveSheet->Rows->Size[numRow]=30;
		rect.Left = numCol;
		rect.Top = numRow;
		rect.Right = numCol+1;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Юридический адрес, телефон, e-mail, (адрес государственной регистрации)";
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 8;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
		rect.Left = numCol;
		rect.Top = numRow;
		rect.Right = numCol+4;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=Query->FieldByName("UADRFIRM")->AsString+"  Телефон: "+
				Query->FieldByName("TELFIRM")->AsString;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numRow++;

numCol=1;
		rect.Left = numCol;
		rect.Top = numRow;
		rect.Right = numCol+1;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Серия, номер, дата получения, срок действия лицензии, кем выдана";
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 8;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
prForm->SS->ActiveSheet->Rows->Size[numRow]=30;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
		rect.Left = numCol;
		rect.Top = numRow;
		rect.Right = numCol+4;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numRow++;
numRow++;

numCol=4;
		rect.Left = numCol;
		rect.Top = numRow;
		rect.Right = numCol+2;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="ДЕКЛАРАЦИЯ";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 16;
delete cell;

numRow++;
numCol=1;
		rect.Left = numCol;
		rect.Top = numRow;
		rect.Right = numCol+3;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="о розничной продаже алкогольной продукции за ";
cell->Style->HorzTextAlign = haRIGHT;
delete cell;

numCol=5;
		rect.Left = numCol;
		rect.Top = numRow;
		rect.Right = numCol+3;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;
numCol=5;
		rect.Left = numCol;
		rect.Top = numRow;
		rect.Right = numCol+3;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="(отчетный период: 1 квартал, полугодие, 9 месяцев, год)";
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaTOP;
delete cell;

numRow++;
numRow++;

numCol=4;
		rect.Left = numCol;
		rect.Top = numRow;
		rect.Right = numCol+2;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Раздел I";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 12;
delete cell;

numRow++;

numCol=2;
		rect.Left = numCol;
		rect.Top = numRow;
		rect.Right = numCol+5;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select * from SSKLAD where IDSKLAD="+IntToStr(glStrToInt64(SpisokSkladIDSKLAD->AsString)));
Query->ExecQuery();
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=Query->FieldByName("NAMESKLAD")->AsString+", "+
								Query->FieldByName("ADRSKLAD")->AsString;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numRow++;
numCol=2;
		rect.Left = numCol;
		rect.Top = numRow;
		rect.Right = numCol+5;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="(наименование и местонахождение территориально обособленного объекта)*";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
delete cell;


numRow++;
numRow++;
//табличная часть
prForm->SS->ActiveSheet->Rows->Size[numRow]=40;
numCol=1;
		rect.Left = numCol;
		rect.Top = numRow;
		rect.Right = numCol;
		rect.Bottom = numRow+1;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Вид продукции";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
		rect.Left = numCol+1;
		rect.Top = numRow;
		rect.Right = numCol;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Остаток на начало отчетного периода";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

		rect.Left = numCol+1;
		rect.Top = numRow;
		rect.Right = numCol;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Поступило продукции за отчетный период";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

		rect.Left = numCol+1;
		rect.Top = numRow;
		rect.Right = numCol;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Реализовано продукции за отчетный период";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

		rect.Left = numCol+1;
		rect.Top = numRow;
		rect.Right = numCol;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Остаток на конец отчетного периода";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;
numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="бутылок";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="литров";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="бутылок";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="литров";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="бутылок";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="литров";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="бутылок";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="литров";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;
numCol=1;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="1";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="2";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="3";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="4";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="5";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="6";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="7";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="8";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="9";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;

Query->Close();
}
//---------------------------------------------------------------------------
void TFormaReport::Rasdel1_OutputString(int index_string)
{
TcxSSCellObject *cell;
TcxCustomDataController *dc = Rasdel1cxGridTableView1->DataController;

numCol=1;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=dc->Values[index_string][Rasdel1cxGridTableView1NAMEGRP->Index];
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
double val=dc->Values[index_string][Rasdel1cxGridTableView1NACHOST->Index];
cell->Text=FloatToStrF(val,ffFixed,15,0);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
val=dc->Values[index_string][Rasdel1cxGridTableView1FISED_NACHOST->Index];
cell->Text=FloatToStrF(val,ffFixed,15,0);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
val=dc->Values[index_string][Rasdel1cxGridTableView1PRIHOD->Index];
cell->Text=FloatToStrF(val,ffFixed,15,0);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
val=dc->Values[index_string][Rasdel1cxGridTableView1FISED_PRIHOD->Index];
cell->Text=FloatToStrF(val,ffFixed,15,0);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
val=dc->Values[index_string][Rasdel1cxGridTableView1RASHOD->Index];
cell->Text=FloatToStrF(val,ffFixed,15,0);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
val=dc->Values[index_string][Rasdel1cxGridTableView1FISED_RASHOD->Index];
cell->Text=FloatToStrF(val,ffFixed,15,0);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
val=dc->Values[index_string][Rasdel1cxGridTableView1CONOST->Index];
cell->Text=FloatToStrF(val,ffFixed,15,0);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
val=dc->Values[index_string][Rasdel1cxGridTableView1FISED_CONOST->Index];
cell->Text=FloatToStrF(val,ffFixed,15,0);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;


numRow++;
}
//----------------------------------------------------------------------------
void TFormaReport::Rasdel1_OutputFooter(void)
{
TcxSSCellObject *cell;



numCol=1;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="ВСЕГО";
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(Rasdel1_NachOstBasEd,ffFixed,15,0);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(Rasdel1_NachOstFisEd,ffFixed,15,0);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(Rasdel1_PrihodBasEd,ffFixed,15,0);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(Rasdel1_PrihodFisEd,ffFixed,15,0);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(Rasdel1_RashodBasEd,ffFixed,15,0);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(Rasdel1_RashodFisEd,ffFixed,15,0);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(Rasdel1_ConOstBasEd,ffFixed,15,0);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(Rasdel1_ConOstFisEd,ffFixed,15,0);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;

numCol=1;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="* - раздел I декларации заполняется на отдельных бланках по организации в целом и раздельно по каждому территориально обособленному объекту";
cell->Style->Font->Size =8;

delete cell;
}
//----------------------------------------------------------------------------
