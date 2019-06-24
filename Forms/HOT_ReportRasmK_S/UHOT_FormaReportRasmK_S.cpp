//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UHOT_FormaReportRasmK_S.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtonEdit"
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxLabel"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxClasses"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxPC"
#pragma link "cxStyles"
#pragma link "cxGridBandedTableView"
#pragma link "cxGridDBBandedTableView"
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
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall THOT_FormaReportRasmK_S::THOT_FormaReportRasmK_S(TComponent* Owner)
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
bool THOT_FormaReportRasmK_S::Init(void)
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

PosConcxDateEdit->Date=Date()+EncodeTime(23,59,59,999);
PosNachcxDateEdit->Date=DM_Connection->GetPosNachReport();

DM=new THOT_DMReportRasmK_S(Application);
DM->DM_Connection=DM_Connection;
DM->Init();
NameFirmcxButtonEdit->Text="";

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int THOT_FormaReportRasmK_S::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaReportRasmK_S::FormClose(TObject *Sender,
      TCloseAction &Action)
{
delete DM;
Action=caFree;
 if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
int THOT_FormaReportRasmK_S::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ER_Firm)
		{
		if (type_event==1)
				{
                EndViborFirm();
				}
		FormaSpiskaSprFirm=0;
		}

return -1;
}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaReportRasmK_S::cxButtonCreateClick(TObject *Sender)
{
cxGrid1Level1->Caption="Размещение (койко/сутки) c " +DateTimeToStr(PosNachcxDateEdit->Date)
   +"  по " +DateTimeToStr(PosConcxDateEdit->Date);
DM->OpenReport(PosNachcxDateEdit->Date, PosConcxDateEdit->Date);

}
//---------------------------------------------------------------------------


//----------------------------------------------------------------------------
	   //выбор фирмы

void THOT_FormaReportRasmK_S::ViborFirm(void)
{
if (FormaSpiskaSprFirm==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&FormaSpiskaSprFirm);
	FormaSpiskaSprFirm->Init(InterfaceMainObject,InterfaceImpl);
	FormaSpiskaSprFirm->Vibor=true;
	FormaSpiskaSprFirm->NumberProcVibor=ER_Firm;
	}

}
//-----------------------------------------------------------------------------
void __fastcall THOT_FormaReportRasmK_S::EndViborFirm(void)
{

	IdFirm=FormaSpiskaSprFirm->DM->TableIDFIRM->AsInt64;
	NameFirmcxButtonEdit->Text=FormaSpiskaSprFirm->DM->TableNAMEFIRM->AsString; 


}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaReportRasmK_S::NameFirmcxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborFirm();
		}break;
	case 1:
		{
		IdFirm=0;
		NameFirmcxButtonEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------


void __fastcall THOT_FormaReportRasmK_S::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaReportRasmK_S::ActionPrintExecute(TObject *Sender)
{
dxComponentPrinter1->ReportLink[0]->Preview(true);
}
//---------------------------------------------------------------------------

