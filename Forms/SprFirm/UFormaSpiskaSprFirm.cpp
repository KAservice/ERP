//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaSpiskaSprFirm.h" 
#include "IFormaElementaSprFirm.h"
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
__fastcall TFormaSpiskaSprFirm::TFormaSpiskaSprFirm(TComponent* Owner)
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
bool TFormaSpiskaSprFirm::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
DM->OpenTable();
Vibor=false;

//����������
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;
return result;
}
//---------------------------------------------------------------------------
int TFormaSpiskaSprFirm::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprFirm::FormClose(TObject *Sender, TCloseAction &Action)
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
void __fastcall TFormaSpiskaSprFirm::ToolButtonInsertClick(TObject *Sender)
{
FNewElement();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprFirm::ToolButtonEditClick(TObject *Sender)
{
FOpenElement();
}

//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprFirm::ToolButtonDeleteClick(TObject *Sender)
{
FDeleteElement();
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprFirm::FOpenElement()
{
IFormaElementaSprFirm * forma;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprFirm.1",IID_IFormaElementaSprFirm, (void**)&forma);
forma->Init(InterfaceMainObject,InterfaceImpl);
forma->DM->OpenElement(DM->TableIDFIRM->AsInt64);
forma->UpdateForm();
forma->NumberProcVibor=1;
}
//---------------------------------------------------------------------------

void TFormaSpiskaSprFirm::FNewElement()
{
IFormaElementaSprFirm * forma;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprFirm.1",IID_IFormaElementaSprFirm, (void**)&forma);
forma->Init(InterfaceMainObject,InterfaceImpl);
forma->DM->NewElement();
forma->UpdateForm();
forma->NumberProcVibor=1;
}
//----------------------------------------------------------------------------

void TFormaSpiskaSprFirm::FDeleteElement()
{
DM->DeleteElement(DM->TableIDFIRM->AsInt64);
DM->OpenTable();
}
//----------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprFirm::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprFirm");	
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprFirm::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
		{
		TypeEvent=1;
		DM->OpenElement(DM->TableIDFIRM->AsInt64);
        Close();
        }

else
        {
        FOpenElement();
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprFirm::cxButtonCloseClick(TObject *Sender)
{
TypeEvent=0;
Close();  	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprFirm::cxGrid1DBTableView1KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if (Key==VK_RETURN)
		{
if (Vibor==true)
		{
		TypeEvent=1;
        DM->OpenElement(DM->TableIDFIRM->AsInt64);
        Close();
        }

else
        {
        FOpenElement();
		}
		}	
}
//---------------------------------------------------------------------------
int TFormaSpiskaSprFirm::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{
DM->OpenTable();
return -1;
}
//-----------------------------------------------------------------------------
