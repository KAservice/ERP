//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaSpiskaSprPriceSchedule.h"
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
#pragma link "cxDBLookupComboBox"
#pragma link "cxCalc"
#pragma link "cxCalendar"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaSpiskaSprPriceSchedule::TFormaSpiskaSprPriceSchedule(TComponent* Owner)
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
bool TFormaSpiskaSprPriceSchedule::Init(void)
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
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPriceSchedule.1",IID_IDMSprPriceSchedule, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
Vibor=false;

TcxLookupComboBoxProperties  *  AProperties;
AProperties=(TcxLookupComboBoxProperties *) cxGrid1DBTableView1IDTYPE_SPRICE_SCHEDULE->GetProperties();
AProperties->ListSource=DM->DataSourceTypePrice;
AProperties=(TcxLookupComboBoxProperties *) cxGrid1DBTableView1IDED_SPRICE_SCHEDULE->GetProperties();
AProperties->ListSource=DM->DataSourceSpisokEd;

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
int TFormaSpiskaSprPriceSchedule::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprPriceSchedule::FormClose(TObject *Sender,
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

//--------------------------------------------------------------------------
void TFormaSpiskaSprPriceSchedule::UpdateForm(void)
{

LabelNom->Caption=HeaderText;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprPriceSchedule::ToolButtonNewClick(TObject *Sender)
{
DM->Table->Append();
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprPriceSchedule::ToolButtonDeleteClick(TObject *Sender)
{
DM->Table->Delete();
}
//---------------------------------------------------------------------------



void __fastcall TFormaSpiskaSprPriceSchedule::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprPriceSchedule");
}
//---------------------------------------------------------------------------



void __fastcall TFormaSpiskaSprPriceSchedule::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
        {
        Close();
		}
}
//---------------------------------------------------------------------------



void __fastcall TFormaSpiskaSprPriceSchedule::cxGrid1DBTableView1KeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if (Key==VK_RETURN)
		{
if (Vibor==true)
        {
        Close();
		}
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprPriceSchedule::ActionCloseExecute(TObject *Sender)

{
DM->CancelIsmen();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprPriceSchedule::ActionOKExecute(TObject *Sender)
{
DM->SaveIsmen();
Close();
}
//---------------------------------------------------------------------------
int TFormaSpiskaSprPriceSchedule::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{
DM->OpenTable(IdNom);
return -1;
}
//-----------------------------------------------------------------------------
