//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UFormaReportDiscountDocCheckForCashier.h"
#include "UReportDiscountDocCheck.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "cxButtonEdit"
#pragma link "cxButtons"
#pragma link "cxCheckBox"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxCalendar"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaReportDiscountDocCheckForCashier::TFormaReportDiscountDocCheckForCashier(TComponent* Owner)
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
bool TFormaReportDiscountDocCheckForCashier::Init(void)
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

DateCon->Date=Date();
DateNach->Date=DateCon->Date-DayOf(DateCon->Date)+1;
DateCon->Date=Date()+EncodeTime(23,59,59,999);

NameGrpNomEdit->Text="";
NameNomEdit->Text="";


IdFirm=glStrToInt64(DM_Connection->ARMInfoIDFIRM_SARM->AsString);
IdSkl=glStrToInt64(DM_Connection->ARMInfoIDSKLAD_SARM->AsString);
LabelNameFirm->Caption="Фирма: "+DM_Connection->ARMInfoNAMEFIRM->AsString;
LabelNameSklad->Caption="Склад: "+DM_Connection->ARMInfoNAMESKLAD->AsString;

 //ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
result=true;

return result;
}
//---------------------------------------------------------------------------
int TFormaReportDiscountDocCheckForCashier::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaReportDiscountDocCheckForCashier::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
if(SpisokGrpNom)SpisokGrpNom->kanRelease();
if(SpisokNom)SpisokNom->kanRelease();

Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//----------------------------------------------------------------------------
void TFormaReportDiscountDocCheckForCashier::OpenFormSpiskaSprNom(void)
{
if (SpisokNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaViborSprNom.1",IID_IFormaViborSprNom,
													(void**)&SpisokNom);
		SpisokNom->Init(InterfaceMainObject,InterfaceImpl);
		SpisokNom->NumberProcVibor=ViborNom;
		SpisokNom->Vibor=true;
		//SpisokNom->DM->IdTypePrice=glStrToInt64(DM->DocIDTPRICE->AsString);
		//SpisokNom->SpisokTypePrice->ItemIndex=SpisokNom->DM->GetIndexTypePrice()-1;
//        SpisokNom->IdNom=DM->DocTIDNOMCHKT->AsInteger;
		SpisokNom->UpdateForm();
		}
}

//---------------------------------------------------------------------------
void TFormaReportDiscountDocCheckForCashier::OpenFormSpiskaSprGrpNom(void)
{
if (SpisokGrpNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprGrpNom.1",IID_IFormaSpiskaSprGrpNom,
													(void**)&SpisokGrpNom);
		SpisokGrpNom->Init(InterfaceMainObject,InterfaceImpl);
		SpisokGrpNom->Vibor=true;
		SpisokGrpNom->NumberProcVibor=ViborGrpNom;
        SpisokGrpNom->UpdateForm();
		}
}
//---------------------------------------------------------------------------
int TFormaReportDiscountDocCheckForCashier::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

if (number_procedure_end==ViborGrpNom)
		{
		if (type_event==1)
                {
				IdGrpNom=glStrToInt64(SpisokGrpNom->DMGrp->ElementIDGN->AsString);
				NameGrpNomEdit->Text=SpisokGrpNom->DMGrp->ElementNAMEGN->AsString;
                IdNom=0;
                NameNomEdit->Text="";
                }
        SpisokGrpNom=0;
        }


if (number_procedure_end==ViborNom)
        {
        if (type_event==1)
                {
                IdNom=glStrToInt64(SpisokNom->DM->TableIDNOM->AsString);
                NameNomEdit->Text=SpisokNom->DM->TableNAMENOM->AsString;
                IdGrpNom=0;
                NameGrpNomEdit->Text="";
                }
        SpisokNom=0;
        }


EditRekvisit=NO;
return -1;
}

//----------------------------------------------------------------------------


void __fastcall TFormaReportDiscountDocCheckForCashier::ActionOpenHelpExecute(
      TObject *Sender)
{
Application->HelpJump("ReportDiscountCheck");
}
//---------------------------------------------------------------------------



void __fastcall TFormaReportDiscountDocCheckForCashier::cxButtonCreateClick(
      TObject *Sender)
{
TReportDiscountDocCheck * report=new TReportDiscountDocCheck();
report->DM_Connection=DM_Connection;
report->InterfaceGlobalCom=InterfaceGlobalCom;
report->InterfaceMainObject=InterfaceMainObject;
report->Init();
report->PosNach=DateNach->Date;
report->PosCon=DateCon->Date;
report->IdFirm=IdFirm;
report->IdSklad=IdSkl;
report->IdGrp=IdGrpNom;
report->IdNom=IdNom;
if (OnlyCheckBox->Checked==true)
	{
	report->OnlyType=true;
	report->TypeNom=TypeNomComboBox->ItemIndex;
	}
else
	{
	report->OnlyType=false;
	}

if (DocCheckBox->Checked==true)
	{
	report->AddDoc=true;
	}
else
	{
	report->AddDoc=false;
	}
report->CreateReport();
delete report;	
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportDiscountDocCheckForCashier::NameNomEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprNom();
		}break;
	case 1:
		{
		IdNom=0;
		NameNomEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportDiscountDocCheckForCashier::NameGrpNomEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprGrpNom();    
		}break;
	case 1:
		{
		IdGrpNom=0;
		NameGrpNomEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportDiscountDocCheckForCashier::ActionCloseExecute(TObject *Sender)

{
Close();
}
//---------------------------------------------------------------------------

