//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UHOT_FormaSpiskaSprObject.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"

#include "IHOT_DMSprObject.h"
#include "IHOT_FormaElementaSprObject.h"
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
__fastcall THOT_FormaSpiskaSprObject::THOT_FormaSpiskaSprObject(TComponent* Owner)
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

bool THOT_FormaSpiskaSprObject::Init(void)
{
bool result=false;

if (InterfaceMainObject>0)
	{
	//������� ����������
	IConnectionInterface * i_connection;
	InterfaceMainObject->kanQueryInterface(IID_IConnectionInterface,(void**)&i_connection);
	DM_Connection=i_connection->GetFibConnection();
	i_connection->kanRelease();

	//������� ��������� COM ������� ��� �������� ����� ��������
	IMainCOMInterface * i_com;
	InterfaceMainObject->kanQueryInterface(IID_IMainCOMInterface,(void**)&i_com);
	InterfaceGlobalCom=i_com->GetCOM();
	i_com->kanRelease();
	}

InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMSprObject.1",IID_IHOT_DMSprObject,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
DM->OpenTable();
Vibor=false;
TypeEvent=0;;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int THOT_FormaSpiskaSprObject::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaSpiskaSprObject::FormClose(TObject *Sender,
      TCloseAction &Action)
{
//������� ICallBack ��� �������� ������� � ���������� �����
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
int THOT_FormaSpiskaSprObject::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{
DM->OpenTable();
return -1;
}
//--------------------------------------------------------------------------
void THOT_FormaSpiskaSprObject::OpenFormElement()
{
IHOT_FormaElementaSprObject * f;
InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaElSprObject.1",IID_IHOT_FormaElementaSprObject,
												 (void**)&f);
f->Init(InterfaceMainObject,InterfaceImpl);
f->DM->OpenElement(DM->TableID_HOT_SOBJECT->AsInt64);
f->UpdateForm();
}
//--------------------------------------------------------------------------
void THOT_FormaSpiskaSprObject::OpenFormNewElement()
{
IHOT_FormaElementaSprObject * f;
InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaElSprObject.1",IID_IHOT_FormaElementaSprObject,
												 (void**)&f);
f->Init(InterfaceMainObject,InterfaceImpl);
f->DM->NewElement();
f->UpdateForm();
}
//--------------------------------------------------------------------------
void THOT_FormaSpiskaSprObject::DeleteElement()
{
DM->DeleteElement(DM->TableID_HOT_SOBJECT->AsInt64);
DM->OpenTable();
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaSpiskaSprObject::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();        
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaSpiskaSprObject::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();        
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaSpiskaSprObject::ToolButtonDeleteClick(
      TObject *Sender)
{
DeleteElement();        
}
//---------------------------------------------------------------------------



void __fastcall THOT_FormaSpiskaSprObject::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("Hotel/Spr/Object");
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaSpiskaSprObject::cxGrid1DBTableView1CellDblClick(
      TcxCustomGridTableView *Sender,
      TcxGridTableDataCellViewInfo *ACellViewInfo, TMouseButton AButton,
      TShiftState AShift, bool &AHandled)
{
if (Vibor==true)
        {
		DM->OpenElement(DM->TableID_HOT_SOBJECT->AsInt64);
		TypeEvent=1;
        Close();
        }
else
        {
        OpenFormElement();
		}
}
//---------------------------------------------------------------------------


void __fastcall THOT_FormaSpiskaSprObject::cxGrid1DBTableView1KeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
if (Vibor==true)
        {
		DM->OpenElement(DM->TableID_HOT_SOBJECT->AsInt64);
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

void __fastcall THOT_FormaSpiskaSprObject::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

