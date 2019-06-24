//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaSpiskaSprOborud.h"

#include "IFormaElementaSprOborud.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IkasFormSpr.h"
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
#pragma link "cxCheckBox"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaSpiskaSprOborud::TFormaSpiskaSprOborud(TComponent* Owner)
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
bool TFormaSpiskaSprOborud::Init(void)
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
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprOborud.1",IID_IDMSprOborud, (void**)&DM);

DM->Init(InterfaceMainObject,InterfaceImpl);
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;

Vibor=false;


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
int TFormaSpiskaSprOborud::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprOborud::UpdateForm(void)
{
DM->OpenTable(IdKKM);
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprOborud::FormClose(TObject *Sender,
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

int TFormaSpiskaSprOborud::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
DM->OpenTable(IdKKM);
return -1;
}
//-----------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprOborud::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprOborud::ToolButtonDeleteClick(TObject *Sender)
{
DeleteElement();
}
//---------------------------------------------------------------------------

void TFormaSpiskaSprOborud::OpenFormElement()
{
IFormaElementaSprOborud * FormaElementa;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprOborud.1",IID_IFormaElementaSprOborud,
													(void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
FormaElementa->DM->OpenElement(glStrToInt64(DM->TableID_OBORUD->AsString));
FormaElementa->UpdateForm();
FormaElementa->NumberProcVibor=1;
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprOborud::OpenFormNewElement()
{
IFormaElementaSprOborud * FormaElementa;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprOborud.1",IID_IFormaElementaSprOborud,
													(void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
FormaElementa->DM->NewElement(IdKKM);
FormaElementa->NumberProcVibor=1;
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprOborud::DeleteElement()
{
DM->DeleteElement(glStrToInt64(DM->TableID_OBORUD->AsString));
DM->OpenTable(IdKKM);
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprOborud::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprOborud::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprOborud");
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprOborud::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
		{
		DM->OpenElement(glStrToInt64(DM->TableID_OBORUD->AsString));
		TypeEvent=1;
		Close();
		}
else
		{
		OpenFormElement();
		}
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprOborud::cxGrid1DBTableView1KeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if (Key==VK_RETURN)
		{
if (Vibor==true)
		{
		DM->OpenElement(glStrToInt64(DM->TableID_OBORUD->AsString));
		TypeEvent=1;
		Close();
		}
else
		{
		OpenFormElement();
		}
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprOborud::ActionCloseExecute(TObject *Sender)
{
if(Vibor!=true)
        {
        TypeEvent=0;
        Close();
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprOborud::ToolButtonOpenSpisokParamClick(TObject *Sender)

{
IkasFormSpr * spr_param=0;

InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprOborudParam,IID_IkasFormSpr,
													(void**)&spr_param);
spr_param->Init(InterfaceMainObject,InterfaceImpl);
spr_param->IdOwner=glStrToInt64(DM->TableID_OBORUD->AsString);
spr_param->UpdateForm();

}
//---------------------------------------------------------------------------

