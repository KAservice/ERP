//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UREM_FormaElementaSprKKT.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxCalc"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxLabel"
#pragma link "cxPC"
#pragma link "cxButtonEdit"
#pragma link "cxGroupBox"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxGraphics"
#pragma link "cxButtons"
#pragma link "cxMemo"
#pragma link "cxImageComboBox"
#pragma link "cxDBLookupComboBox"
#pragma link "cxDBLookupEdit"
#pragma link "cxLookupEdit"
#pragma link "cxClasses"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxFilter"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "cxDBLabel"
#pragma link "cxCalendar"
#pragma link "cxSpinEdit"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TREM_FormaElementaSprKKT::TREM_FormaElementaSprKKT(TComponent* Owner)
		: TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
TypeEvent=0;
}
//---------------------------------------------------------------------------
bool TREM_FormaElementaSprKKT::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMSprKKT.1",IID_IREM_DMSprKKT,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

NameModelcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
SerNumbercxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;

SvkGRcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
SvkSOcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
RegNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
ReleasecxDBDateEdit->DataBinding->DataSource=DM->DataSourceElement;
VvodcxDBDateEdit->DataBinding->DataSource=DM->DataSourceElement;
NumContractcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
DateContractcxDBDateEdit->DataBinding->DataSource=DM->DataSourceElement;
SumContractcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;
EklzSerNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
EklzRegNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
EklzActcxDBDateEdit->DataBinding->DataSource=DM->DataSourceElement;

PasNumVercxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
PasNumPascxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
PasNumPUcxDBSpinEdit->DataBinding->DataSource=DM->DataSourceElement;
PasNumSPcxDBSpinEdit->DataBinding->DataSource=DM->DataSourceElement;
PasNumSPPOcxDBSpinEdit->DataBinding->DataSource=DM->DataSourceElement;
PasNumFPcxDBSpinEdit->DataBinding->DataSource=DM->DataSourceElement;
PasNumFPPOcxDBSpinEdit->DataBinding->DataSource=DM->DataSourceElement;
PasNumDoPocxDBSpinEdit->DataBinding->DataSource=DM->DataSourceElement;
PasPppcxDBSpinEdit->DataBinding->DataSource=DM->DataSourceElement;
PasDorcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
PasPrimcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;

PrimcxDBMemo->DataBinding->DataSource=DM->DataSourceElement;

DM_Connection->GetPrivForm(GCPRIV_FormaDocCheck);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_FormaElementaSprKKT::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprKKT::FormClose(TObject *Sender,
      TCloseAction &Action)
{

if(FormaSpiskaSprKlient)FormaSpiskaSprKlient->kanRelease();
if(REM_FormaSpiskaSprModel)REM_FormaSpiskaSprModel->kanRelease();

//получим ICallBack для передачи события в вызывающую форму
if(InterfaceOwnerObject)
	{
	IkanCallBack * i_callback=0;
	InterfaceOwnerObject->kanQueryInterface(IID_IkanCallBack,(void**)&i_callback);
	if (i_callback)
		{
		i_callback->kanExternalEvent(InterfaceImpl,ClsIdImpl,TypeEvent,NumberProcVibor);
		}
	i_callback->kanRelease();
	}

DM->kanRelease();
Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void TREM_FormaElementaSprKKT::UpdateForm(void)
{


}
//---------------------------------------------------------------------------
int TREM_FormaElementaSprKKT::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ER_Klient)
	{
	if (type_event==1)
		{
		EndViborOwner();
		}
	FormaSpiskaSprKlient=0;
	}

if (number_procedure_end==ER_Model)
	{
	if (type_event==1)
		{
		EndViborModel();
		}
	REM_FormaSpiskaSprModel=0;
	}
return -1;
}
//-----------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprKKT::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("REM_SprKKT");
}

//-----------------------------------------------------------------------------






void __fastcall TREM_FormaElementaSprKKT::ActionCloseElementExecute(TObject *Sender)
{
Close();	
}

//---------------------------------------------------------------------------
void TREM_FormaElementaSprKKT::ViborOwner(void)
{
if (FormaSpiskaSprKlient==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
												 (void**)&FormaSpiskaSprKlient);
	FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
	FormaSpiskaSprKlient->NumberProcVibor=ER_Klient;
	FormaSpiskaSprKlient->Vibor=true;
	FormaSpiskaSprKlient->UpdateForm();
	}

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprKKT::EndViborOwner(void)
{

	DM->Element->Edit();
	DM->ElementIDKLIENT_REM_SKKT->AsString=FormaSpiskaSprKlient->DM->TableIDKLIENT->AsString;
	DM->ElementOWNER_NAME->AsString=FormaSpiskaSprKlient->DM->TableNAMEKLIENT->AsString;
	DM->Element->Post();

FormaSpiskaSprKlient=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprKKT::NameKlientcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborOwner();
}
//---------------------------------------------------------------------------
void TREM_FormaElementaSprKKT::ViborModel(void)
{
if (REM_FormaSpiskaSprModel==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaSpSprModel.1",IID_IREM_FormaSpiskaSprModel,
												 (void**)&REM_FormaSpiskaSprModel);
	REM_FormaSpiskaSprModel->Init(InterfaceMainObject,InterfaceImpl);
	REM_FormaSpiskaSprModel->NumberProcVibor=ER_Model;
	REM_FormaSpiskaSprModel->Vibor=true;
	REM_FormaSpiskaSprModel->UpdateForm();
	}

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprKKT::EndViborModel(void)
{

	DM->Element->Edit();
	DM->ElementIDMODEL_REM_SKKT->AsString=REM_FormaSpiskaSprModel->DM->TableID_REM_SMODEL->AsString;
	DM->ElementNAME_REM_SMODEL->AsString=REM_FormaSpiskaSprModel->DM->TableNAME_REM_SMODEL->AsString;
	DM->Element->Post();

REM_FormaSpiskaSprModel=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//-----------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprKKT::NameModelcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborModel();	
}
//---------------------------------------------------------------------------



void __fastcall TREM_FormaElementaSprKKT::ActionSaveElementExecute(TObject *Sender)

{
if (DM->SaveElement()==true)
	{

	UpdateForm();

	}
else
	{
	ShowMessage("Ошибка при записи!"+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprKKT::ActionOKExecute(TObject *Sender)
{

if (DM->SaveElement()==true)
	{
	Close();
	}
else
	{
	ShowMessage("Ошибка при записи!"+DM->TextError);
	}
}
//---------------------------------------------------------------------------

