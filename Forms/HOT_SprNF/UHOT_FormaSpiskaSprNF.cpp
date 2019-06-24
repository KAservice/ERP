//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UHOT_FormaSpiskaSprNF.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IHOT_FormaElementaSprNF.h"
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
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall THOT_FormaSpiskaSprNF::THOT_FormaSpiskaSprNF(TComponent* Owner)
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

bool THOT_FormaSpiskaSprNF::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMSprNF.1",IID_IHOT_DMSprNF,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);


cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
DM->OpenTable();
Vibor=false;
TypeEvent=0;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int THOT_FormaSpiskaSprNF::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaSpiskaSprNF::FormClose(TObject *Sender,
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
int  THOT_FormaSpiskaSprNF::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{
DM->UpdateTable();
return -1;
}
//--------------------------------------------------------------------------
void THOT_FormaSpiskaSprNF::OpenFormElement()
{
IHOT_FormaElementaSprNF * f;
InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaElSprNF.1",IID_IHOT_FormaElementaSprNF,
												 (void**)&f);
f->Init(InterfaceMainObject,InterfaceImpl);
f->DM->OpenElement(DM->TableID_HOT_SNF->AsInt64);
f->UpdateForm();
}
//--------------------------------------------------------------------------
void THOT_FormaSpiskaSprNF::OpenFormNewElement()
{
IHOT_FormaElementaSprNF * f;
InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaElSprNF.1",IID_IHOT_FormaElementaSprNF,
												 (void**)&f);
f->Init(InterfaceMainObject,InterfaceImpl);
f->DM->NewElement();
f->UpdateForm();

}
//--------------------------------------------------------------------------
void THOT_FormaSpiskaSprNF::DeleteElement()
{
DM->DeleteElement(DM->TableID_HOT_SNF->AsInt64);
DM->OpenTable();
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaSpiskaSprNF::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();        
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaSpiskaSprNF::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();        
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaSpiskaSprNF::ToolButtonDeleteClick(
      TObject *Sender)
{
DeleteElement();        
}
//---------------------------------------------------------------------------



void __fastcall THOT_FormaSpiskaSprNF::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("Hotel/Spr/SprNF");
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaSpiskaSprNF::cxGrid1DBTableView1CellDblClick(
      TcxCustomGridTableView *Sender,
      TcxGridTableDataCellViewInfo *ACellViewInfo, TMouseButton AButton,
      TShiftState AShift, bool &AHandled)
{
if (Vibor==true)
		{
		TypeEvent=1;
		DM->OpenElement(DM->TableID_HOT_SNF->AsInteger);
        Close();
        }
else
        {
        OpenFormElement();
		}
}
//---------------------------------------------------------------------------


void __fastcall THOT_FormaSpiskaSprNF::cxGrid1DBTableView1KeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
if (Vibor==true)
		{
		TypeEvent=1;
        DM->OpenElement(DM->TableID_HOT_SNF->AsInt64);
        Close();
        }
else
        {
		OpenFormElement();
		}
		}
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaSpiskaSprNF::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

