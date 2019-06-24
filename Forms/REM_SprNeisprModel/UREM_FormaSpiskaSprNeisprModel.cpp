//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_FormaSpiskaSprNeisprModel.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IREM_FormaElementaSprNeisprModel.h"
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
__fastcall TREM_FormaSpiskaSprNeisprModel::TREM_FormaSpiskaSprNeisprModel(TComponent* Owner)
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
bool TREM_FormaSpiskaSprNeisprModel::Init(void)
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


InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprNeisprModel,IID_IREM_DMSprNeisprModel,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
Vibor=false;
HintLabel->Caption="";

DM_Connection->GetPrivForm(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_FormaSpiskaSprNeisprModel::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TREM_FormaSpiskaSprNeisprModel::UpdateForm(void)
{
DM->OpenTable(IdModel);

}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprNeisprModel::FormClose(TObject *Sender,
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
int TREM_FormaSpiskaSprNeisprModel::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
DM->OpenTable(IdModel);
return -1;
}
//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprNeisprModel::OpenFormElement()
{
IREM_FormaElementaSprNeisprModel * FormaElementa;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaElementaSprNeisprModel,IID_IREM_FormaElementaSprNeisprModel,
												 (void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
if (!FormaElementa) return;
FormaElementa->DM->OpenElement(glStrToInt64(DM->TableID_REM_SNEISPMODEL->AsString));
FormaElementa->UpdateForm();

}
//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprNeisprModel::OpenFormNewElement()
{
IREM_FormaElementaSprNeisprModel * FormaElementa;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaElementaSprNeisprModel,IID_IREM_FormaElementaSprNeisprModel,
												 (void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
if (!FormaElementa) return;
FormaElementa->DM->NewElement(IdModel);
FormaElementa->UpdateForm();


}
//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprNeisprModel::DeleteElement()
{
DM->DeleteElement(glStrToInt64(DM->TableID_REM_SNEISPMODEL->AsString));
DM->OpenTable(IdModel);
}
//--------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprNeisprModel::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprNeisprModel::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprNeisprModel::ToolButtonDeleteClick(TObject *Sender)
{
DeleteElement();
}
//---------------------------------------------------------------------------




void __fastcall TREM_FormaSpiskaSprNeisprModel::ActionOpenHelpExecute(TObject *Sender)
{
//Application->HelpJump("Spr/SprEd");
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprNeisprModel::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
        {
		DM->OpenElement(glStrToInt64(DM->TableID_REM_SNEISPMODEL->AsString));
		TypeEvent=1;
        Close();
        }
else
        {
        OpenFormElement();
        }	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprNeisprModel::ActionCloseExecute(TObject *Sender)

{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

