//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaSpiskaSprInv.h"
#include "IFormaElementaSprInv.h"
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
__fastcall TFormaSpiskaSprInv::TFormaSpiskaSprInv(TComponent* Owner)
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

bool TFormaSpiskaSprInv::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprInv.1",IID_IDMSprInv, (void**)&DM);
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
//--------------------------------------------------------------------------
int TFormaSpiskaSprInv::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprInv::UpdateForm(void)
{
DM->OpenTable();


}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprInv::FormClose(TObject *Sender,
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

void TFormaSpiskaSprInv::OpenFormElement()
{
IFormaElementaSprInv * FormaElementa;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprInv.1",IID_IFormaElementaSprInv, (void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
FormaElementa->DM->OpenElement(DM->TableID_SINV->AsInt64);
FormaElementa->UpdateForm();
FormaElementa->NumberProcVibor=1;
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprInv::OpenFormNewElement()
{
IFormaElementaSprInv * FormaElementa;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprInv.1",IID_IFormaElementaSprInv, (void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
FormaElementa->DM->NewElement();
FormaElementa->UpdateForm();
FormaElementa->NumberProcVibor=1;
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprInv::DeleteElement()
{
DM->DeleteElement(DM->TableID_SINV->AsInt64);
DM->OpenTable();
}
 //----------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprInv::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprInv::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprInv::ToolButtonDeleteClick(
      TObject *Sender)
{
DeleteElement();        
}
//---------------------------------------------------------------------------



void __fastcall TFormaSpiskaSprInv::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprInv");	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprInv::cxGrid1DBTableView1DblClick(TObject *Sender)
{
if (Vibor==true)
		{
		TypeEvent=1;
        DM->OpenElement(DM->TableID_SINV->AsInt64);
        Close();
        }
else
        {
        OpenFormElement();
		}
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprInv::cxGrid1DBTableView1KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if (Key==VK_RETURN)
		{
if (Vibor==true)
        {
		TypeEvent=1;
        DM->OpenElement(DM->TableID_SINV->AsInt64);
        Close();
        }
else
        {
        OpenFormElement();
		}
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprInv::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------
int TFormaSpiskaSprInv::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{
DM->OpenTable();
return -1;
}
//-----------------------------------------------------------------------------
