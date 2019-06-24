//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaSpiskaSprBankSchet.h"
#include "IDMSprBankSchet.h"
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
//TFSSBSchet *FSSBSchet;
//---------------------------------------------------------------------------
__fastcall TFormaSpiskaSprBankSchet::TFormaSpiskaSprBankSchet(TComponent* Owner)
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
bool TFormaSpiskaSprBankSchet::Init(void)
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
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprBankSchet.1",IID_IDMSprBankSchet, (void**)&DM);

DM->Init(InterfaceMainObject,InterfaceImpl);
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;


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
int TFormaSpiskaSprBankSchet::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprBankSchet::FormClose(TObject *Sender,
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
void TFormaSpiskaSprBankSchet::FOpenElement()
{
IFormaElementaSprBankSchet * forma;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprBankSchet.1",IID_IFormaElementaSprBankSchet, (void**)&forma);

forma->Init(InterfaceMainObject,InterfaceImpl);
forma->DM->OpenElement(glStrToInt64(DM->TableIDBSCHET->AsString));
forma->DM->IdFirm=IdFirm;
}
//----------------------------------------------------------------------------
void TFormaSpiskaSprBankSchet::FNewElement()
{
IFormaElementaSprBankSchet * forma;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprBankSchet.1",IID_IFormaElementaSprBankSchet, (void**)&forma);
forma->Init(InterfaceMainObject,InterfaceImpl);
forma->DM->IdFirm=IdFirm;
forma->DM->NewElement();
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprBankSchet::FDeleteElement()
{
DM->DeleteElement(glStrToInt64(DM->Table->FieldByName("IDBSCHET")->AsString));
DM->OpenTable();

}
//----------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBankSchet::ToolButtonNewClick(TObject *Sender)
{
FNewElement();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBankSchet::ToolButtonEditClick(TObject *Sender)
{
FOpenElement();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBankSchet::ToolButtonDelClick(TObject *Sender)
{
FDeleteElement();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBankSchet::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprBSchet");
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBankSchet::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
        {
		DM->OpenElement(glStrToInt64(DM->TableIDBSCHET->AsString));
		TypeEvent=1;
        Close();
        }
else
        {
        FOpenElement();
        }	
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprBankSchet::cxGrid1DBTableView1KeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if (Key==VK_RETURN)
		{
if (Vibor==true)
        {
        DM->OpenElement(glStrToInt64(DM->TableIDBSCHET->AsString));
        TypeEvent=1;
        Close();
        }
else
        {
        FOpenElement();
		}
		}		
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBankSchet::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------
int TFormaSpiskaSprBankSchet::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
DM->OpenTable();
FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//-----------------------------------------------------------------------------
