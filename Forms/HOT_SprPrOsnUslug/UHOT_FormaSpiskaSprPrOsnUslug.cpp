//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UHOT_FormaSpiskaSprPrOsnUslug.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IHOT_FormaElementaSprPrOsnUslug.h"
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
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxDBLabel"
#pragma link "cxLabel"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall THOT_FormaSpiskaSprPrOsnUslug::THOT_FormaSpiskaSprPrOsnUslug(TComponent* Owner)
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


bool THOT_FormaSpiskaSprPrOsnUslug::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMSprPrOsnUslug.1",IID_IHOT_DMSprPrOsnUslug,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;


DM->OpenTable();
Vibor=false;
TypeEvent=1;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int THOT_FormaSpiskaSprPrOsnUslug::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaSpiskaSprPrOsnUslug::FormClose(TObject *Sender,
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
int THOT_FormaSpiskaSprPrOsnUslug::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
DM->UpdateTable();
return -1;
}
//--------------------------------------------------------------------------
void THOT_FormaSpiskaSprPrOsnUslug::OpenFormElement()
{
IHOT_FormaElementaSprPrOsnUslug * f;
InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaElSprPrOsnUslug.1",IID_IHOT_FormaElementaSprPrOsnUslug,
												 (void**)&f);
f->Init(InterfaceMainObject,InterfaceImpl);
f->DM->OpenElement(DM->TableID_HOT_SPROSNUSL->AsInt64);
f->UpdateForm();
}
//--------------------------------------------------------------------------
void THOT_FormaSpiskaSprPrOsnUslug::OpenFormNewElement()
{
IHOT_FormaElementaSprPrOsnUslug * f;
InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaElSprPrOsnUslug.1",IID_IHOT_FormaElementaSprPrOsnUslug,
												 (void**)&f);
f->Init(InterfaceMainObject,InterfaceImpl);
f->DM->NewElement();
f->UpdateForm();
}
//--------------------------------------------------------------------------
void THOT_FormaSpiskaSprPrOsnUslug::DeleteElement()
{
DM->DeleteElement(DM->TableID_HOT_SPROSNUSL->AsInt64);
DM->OpenTable();
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaSpiskaSprPrOsnUslug::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();        
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaSpiskaSprPrOsnUslug::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();        
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaSpiskaSprPrOsnUslug::ToolButtonDeleteClick(
      TObject *Sender)
{
DeleteElement();        
}
//---------------------------------------------------------------------------



void __fastcall THOT_FormaSpiskaSprPrOsnUslug::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("Hotel/Spr/SprPrOsnUslug");
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaSpiskaSprPrOsnUslug::cxGrid1DBTableView1CellDblClick(
      TcxCustomGridTableView *Sender,
      TcxGridTableDataCellViewInfo *ACellViewInfo, TMouseButton AButton,
      TShiftState AShift, bool &AHandled)
{
if (Vibor==true)
		{
		DM->OpenElement(DM->TableID_HOT_SPROSNUSL->AsInt64);
        Close();
        }
else
        {
        OpenFormElement();
		}
}
//---------------------------------------------------------------------------


void __fastcall THOT_FormaSpiskaSprPrOsnUslug::cxGrid1DBTableView1KeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
if (Vibor==true)
        {
        DM->OpenElement(DM->TableID_HOT_SPROSNUSL->AsInt64);
        Close();
        }
else
        {
        OpenFormElement();
		}
		}
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaSpiskaSprPrOsnUslug::ActionCloseExecute(TObject *Sender)

{
Close();
}
//---------------------------------------------------------------------------

