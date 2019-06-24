//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_FormaSpiskaSprKomplModel.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IREM_FormaElementaSprKomplModel.h"
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
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxButtons"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TREM_FormaSpiskaSprKomplModel::TREM_FormaSpiskaSprKomplModel(TComponent* Owner)
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
bool TREM_FormaSpiskaSprKomplModel::Init(void)
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


InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprKomplModel,IID_IREM_DMSprKomplModel,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
Vibor=false;
HintLabel->Caption="";

DM_Connection->GetPrivForm(GCPRIV_FormaDocCheck);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_FormaSpiskaSprKomplModel::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TREM_FormaSpiskaSprKomplModel::UpdateForm(void)
{
DM->OpenTable(IdModel);

}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprKomplModel::FormClose(TObject *Sender,
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
//---------------------------------------------------------------------------
int TREM_FormaSpiskaSprKomplModel::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
DM->OpenTable(IdModel);
return -1;
}
//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprKomplModel::OpenFormElement()
{
IREM_FormaElementaSprKomplModel * FormaElementa;
InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaElSprKomplModel.1",IID_IREM_FormaElementaSprKomplModel,
												 (void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
if (!FormaElementa) return;
FormaElementa->DM->OpenElement(glStrToInt64(DM->TableID_REM_SKOMPLMODEL->AsString));
FormaElementa->UpdateForm();

}
//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprKomplModel::OpenFormNewElement()
{
IREM_FormaElementaSprKomplModel * FormaElementa;
InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaElSprKomplModel.1",IID_IREM_FormaElementaSprKomplModel,
												 (void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
if (!FormaElementa) return;
FormaElementa->DM->NewElement(IdModel);
FormaElementa->UpdateForm();


}
//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprKomplModel::DeleteElement()
{
DM->DeleteElement(glStrToInt64(DM->TableID_REM_SKOMPLMODEL->AsString));
DM->OpenTable(IdModel);
}
//--------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprKomplModel::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprKomplModel::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprKomplModel::ToolButtonDeleteClick(TObject *Sender)
{
DeleteElement();
}
//---------------------------------------------------------------------------




void __fastcall TREM_FormaSpiskaSprKomplModel::ActionOpenHelpExecute(TObject *Sender)
{
//Application->HelpJump("Spr/SprEd");
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprKomplModel::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
        {
        DM->OpenElement(glStrToInt64(DM->TableID_REM_SKOMPLMODEL->AsString));
		TypeEvent=1;
        Close();
        }
else
        {
        OpenFormElement();
        }	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprKomplModel::ActionCloseExecute(TObject *Sender)

{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

