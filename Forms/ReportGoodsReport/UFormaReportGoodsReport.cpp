//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaReportGoodsReport.h"
#include "UReportGoodsReport.h"
#include "UReportGoodsReportUnion.h"
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
#pragma link "cxCalendar"
#pragma link "cxCheckBox"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaReportGoodsReport::TFormaReportGoodsReport(TComponent* Owner)
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
bool TFormaReportGoodsReport::Init(void)
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

DateCon->Date=Date()+EncodeTime(23,59,59,999);
DateNach->Date=DM_Connection->GetPosNachReport();

NameFirmEdit->Text="";
NameSkladEdit->Text="";


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
int TFormaReportGoodsReport::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void __fastcall TFormaReportGoodsReport::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokSklad) SpisokSklad->kanRelease();
if(SpisokFirm)SpisokFirm->kanRelease();


Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//----------------------------------------------------------------------------
void TFormaReportGoodsReport::OpenFormSpiskaSprFirm(void)
{
if (SpisokFirm==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&SpisokFirm);
		SpisokFirm->Init(InterfaceMainObject,InterfaceImpl);
		SpisokFirm->Vibor=true;
		SpisokFirm->NumberProcVibor=ViborFirm;
		}
}

//---------------------------------------------------------------------------
int TFormaReportGoodsReport::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ViborSklad)
        {
		if (type_event==1)
                {
				IdSkl=glStrToInt64(SpisokSklad->DM->ElementIDSKLAD->AsString);
                NameSkladEdit->Text=SpisokSklad->DM->ElementNAMESKLAD->AsString;
                }
		SpisokSklad=0;
        }

if (number_procedure_end==ViborFirm)
        {
		if (type_event==1)
                {
                IdFirm=SpisokFirm->DM->TableIDFIRM->AsInt64;
                NameFirmEdit->Text=SpisokFirm->DM->TableNAMEFIRM->AsString;
                }
        SpisokFirm=0;
        }

EditRekvisit=NO;
return -1;
}
//---------------------------------------------------------------------------
void TFormaReportGoodsReport::OpenFormSpiskaSprSklad(void)
{
if (SpisokSklad==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&SpisokSklad);
		SpisokSklad->Init(InterfaceMainObject,InterfaceImpl);
		SpisokSklad->Vibor=true;
		SpisokSklad->NumberProcVibor=ViborSklad;
		}

}
//----------------------------------------------------------------------------












void __fastcall TFormaReportGoodsReport::ActionOpenHelpExecute(
      TObject *Sender)
{
Application->HelpJump("Report/ReportGoodsReport");
}
//---------------------------------------------------------------------------



void __fastcall TFormaReportGoodsReport::cxButtonCreateReportClick(
      TObject *Sender)
{
TReportGoodsReport * report=new TReportGoodsReport();
report->DM_Connection=DM_Connection;
report->InterfaceGlobalCom=InterfaceGlobalCom;
report->InterfaceMainObject=InterfaceMainObject;
report->InterfaceOwnerObject=InterfaceImpl;
report->Init();
report->PosNach=DateNach->Date;
report->PosCon=DateCon->Date;
report->IdFirm=IdFirm;
report->IdSklad=IdSkl;


if (GroupCheckPoDateCheckBox->Checked==true)
	{
	report->GroupCheckPoDate=1;
	}
else
	{
	report->GroupCheckPoDate=0;
	}

if (cxCheckBoxSortPoTypeDoc->Checked==true)
	{
	report->SortPoTypeDoc=true;
	}
else
	{
	report->SortPoTypeDoc=false;
	}

report->CreateReport();
delete report;	
}
//---------------------------------------------------------------------------


void __fastcall TFormaReportGoodsReport::NameSkladEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprSklad();
		}break;
	case 1:
		{
		IdSkl=0;
		NameSkladEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportGoodsReport::NameFirmEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprFirm();   
		}break;
	case 1:
		{
		IdFirm=0;
		NameFirmEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportGoodsReport::CreateReportRozncxButtonClick(
      TObject *Sender)
{
TReportGoodsReport * report=new TReportGoodsReport();
report->DM_Connection=DM_Connection;
report->InterfaceGlobalCom=InterfaceGlobalCom;
report->InterfaceMainObject=InterfaceMainObject;
report->InterfaceOwnerObject=InterfaceImpl;
report->Init();
report->PosNach=DateNach->Date;
report->PosCon=DateCon->Date;
report->IdFirm=IdFirm;
report->IdSklad=IdSkl;


if (GroupCheckPoDateCheckBox->Checked==true)
	{
	report->GroupCheckPoDate=1;
	}
else
	{
	report->GroupCheckPoDate=0;
	}

if (cxCheckBoxSortPoTypeDoc->Checked==true)
	{
	report->SortPoTypeDoc=true;
	}
else
	{
	report->SortPoTypeDoc=false;
	}

report->CreateReportRozn();
delete report;
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportGoodsReport::cxButtonCreateReportUnionClick(
      TObject *Sender)
{
TReportGoodsReportUnion * report=new TReportGoodsReportUnion();
report->DM_Connection=DM_Connection;
report->InterfaceGlobalCom=InterfaceGlobalCom;
report->InterfaceMainObject=InterfaceMainObject;
report->InterfaceOwnerObject=InterfaceImpl;
report->Init();
report->PosNach=DateNach->Date;
report->PosCon=DateCon->Date;
report->IdFirm=IdFirm;
report->IdSklad=IdSkl;


if (GroupCheckPoDateCheckBox->Checked==true)
	{
	report->GroupCheckPoDate=1;
	}
else
	{
	report->GroupCheckPoDate=0;
	}

if (cxCheckBoxSortPoTypeDoc->Checked==true)
	{
	report->SortPoTypeDoc=true;
	}
else
	{
	report->SortPoTypeDoc=false;
	}

report->CreateReport();
delete report;
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportGoodsReport::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

