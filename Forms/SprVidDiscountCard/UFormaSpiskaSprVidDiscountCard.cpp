//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaSpiskaSprVidDiscountCard.h"
#include "IFormaElementaSprVidDiscountCard.h"
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
__fastcall TFormaSpiskaSprVidDiscountCard::TFormaSpiskaSprVidDiscountCard(TComponent* Owner)
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

bool TFormaSpiskaSprVidDiscountCard::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprVidDiscountCard.1",IID_IDMSprVidDiscountCard, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
DM->OpenTable();
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
int TFormaSpiskaSprVidDiscountCard::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprVidDiscountCard::FormClose(TObject *Sender,
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
void TFormaSpiskaSprVidDiscountCard::UpdateForm(void)
{


}

//--------------------------------------------------------------------------
void TFormaSpiskaSprVidDiscountCard::OpenFormElement()
{
IFormaElementaSprVidDiscountCard * f;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaElSprVidDiscountCard.1",IID_IFormaElementaSprVidDiscountCard, (void**)&f);
f->Init(InterfaceMainObject,InterfaceImpl);
f->DM->OpenElement(glStrToInt64(DM->TableID_SVID_DCARD->AsString));
f->UpdateForm();

f->NumberProcVibor=1;
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprVidDiscountCard::OpenFormNewElement()
{
IFormaElementaSprVidDiscountCard * f;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaElSprVidDiscountCard.1",IID_IFormaElementaSprVidDiscountCard, (void**)&f);

f->Init(InterfaceMainObject,InterfaceImpl);
f->DM->NewElement();
f->UpdateForm();

f->NumberProcVibor=1;
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprVidDiscountCard::DeleteElement()
{
DM->DeleteElement(glStrToInt64(DM->TableID_SVID_DCARD->AsString));
DM->OpenTable();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprVidDiscountCard::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprVidDiscountCard::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprVidDiscountCard::ToolButtonDeleteClick(
      TObject *Sender)
{
DeleteElement();        
}
//---------------------------------------------------------------------------



void __fastcall TFormaSpiskaSprVidDiscountCard::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprVidDiscountCard");
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprVidDiscountCard::cxGrid1DBTableView1CellDblClick(
      TcxCustomGridTableView *Sender,
      TcxGridTableDataCellViewInfo *ACellViewInfo, TMouseButton AButton,
      TShiftState AShift, bool &AHandled)
{
if (Vibor==true)
        {
		DM->OpenElement(glStrToInt64(DM->TableID_SVID_DCARD->AsString));
        Close();
        }
else
        {
        OpenFormElement();
		}
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprVidDiscountCard::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{

if (Vibor==true)
		{
		DM->OpenElement(glStrToInt64(DM->TableID_SVID_DCARD->AsString));
		TypeEvent=1;
		Close();
		}
else
		{
		OpenFormElement();
		}

}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprVidDiscountCard::cxGrid1DBTableView1KeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if (Key==VK_RETURN)
		{
if (Vibor==true)
		{
		DM->OpenElement(glStrToInt64(DM->TableID_SVID_DCARD->AsString));
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

void __fastcall TFormaSpiskaSprVidDiscountCard::ActionCloseExecute(TObject *Sender)

{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------
int TFormaSpiskaSprVidDiscountCard::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
DM->OpenTable();
return -1;
}
//-----------------------------------------------------------------------------
