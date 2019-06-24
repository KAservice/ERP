//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UFormaSpiskaSprDocKlient.h"
#include "IFormaElementaSprDocKlient.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
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
__fastcall TFormaSpiskaSprDocKlient::TFormaSpiskaSprDocKlient(TComponent* Owner)
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
bool TFormaSpiskaSprDocKlient::Init(void)
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
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprDocKlient.1",IID_IDMSprDocKlient, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
HintLabel->Caption="";

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
int TFormaSpiskaSprDocKlient::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprDocKlient::UpdateForm(void)
{
DM->OpenTable(IdKlient);

}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprDocKlient::FormClose(TObject *Sender,
      TCloseAction &Action)
{
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

//--------------------------------------------------------------------------
void TFormaSpiskaSprDocKlient::OpenFormElement()
{
IFormaElementaSprDocKlient * FormaElementa;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprDocKlient.1",IID_IFormaElementaSprDocKlient, (void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
FormaElementa->DM->OpenElement(glStrToInt64(DM->TableID_SDOCKLIENT->AsString));
FormaElementa->UpdateForm();
FormaElementa->Vibor=true;
FormaElementa->NumberProcVibor=1;
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprDocKlient::OpenFormNewElement()
{
IFormaElementaSprDocKlient * FormaElementa;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprDocKlient.1",IID_IFormaElementaSprDocKlient, (void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
FormaElementa->DM->NewElement(IdKlient);
FormaElementa->UpdateForm();
FormaElementa->Vibor=true;
FormaElementa->NumberProcVibor=1;
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprDocKlient::DeleteElement()
{
DM->DeleteElement(glStrToInt64(DM->TableID_SDOCKLIENT->AsString));
DM->OpenTable(IdKlient);
}
//--------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprDocKlient::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprDocKlient::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprDocKlient::ToolButtonDeleteClick(TObject *Sender)
{
DeleteElement();
}
//---------------------------------------------------------------------------




void __fastcall TFormaSpiskaSprDocKlient::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprDoc");	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprDocKlient::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
		{
		TypeEvent=1;
		DM->OpenElement(glStrToInt64(DM->TableID_SDOCKLIENT->AsString));
        Close();
        }
else
		{
        OpenFormElement();
		}
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprDocKlient::cxGrid1DBTableView1KeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if (Key==VK_RETURN)
		{
if (Vibor==true)
		{
		TypeEvent=1;
        DM->OpenElement(glStrToInt64(DM->TableID_SDOCKLIENT->AsString));
        Close();
        }
else
        {
        OpenFormElement();
		}
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprDocKlient::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------
int TFormaSpiskaSprDocKlient::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
DM->OpenTable(IdKlient);
return -1;
}
//-----------------------------------------------------------------------------
