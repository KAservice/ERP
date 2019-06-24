//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaSpiskaSprNakSkidok.h"
#include "IFormaElementaSprNakSkidok.h"
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
#pragma link "cxCheckBox"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaSpiskaSprNakSkidok::TFormaSpiskaSprNakSkidok(TComponent* Owner)
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
bool TFormaSpiskaSprNakSkidok::Init(void)
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


InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNakSkidok.1",IID_IDMSprNakSkidok, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);


cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
Vibor=false;
HintLabel->Caption="";


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
int TFormaSpiskaSprNakSkidok::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprNakSkidok::UpdateForm(void)
{
DM->OpenTable();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprNakSkidok::FormClose(TObject *Sender,
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
int TFormaSpiskaSprNakSkidok::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{
DM->OpenTable();
return -1;
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprNakSkidok::OpenFormElement()
{
IFormaElementaSprNakSkidok * FormaElementa;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprNakSkidok.1",IID_IFormaElementaSprNakSkidok,
													(void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
FormaElementa->DM->OpenElement(DM->TableID_SNAK_SKIDOK->AsInt64);
FormaElementa->UpdateForm();

}
//--------------------------------------------------------------------------
void TFormaSpiskaSprNakSkidok::OpenFormNewElement()
{
IFormaElementaSprNakSkidok * FormaElementa;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprNakSkidok.1",IID_IFormaElementaSprNakSkidok,
													(void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
FormaElementa->DM->NewElement();
FormaElementa->UpdateForm();

}
//--------------------------------------------------------------------------
void TFormaSpiskaSprNakSkidok::DeleteElement()
{
DM->DeleteElement(DM->TableID_SNAK_SKIDOK->AsInt64);
DM->OpenTable();
}
//--------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprNakSkidok::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprNakSkidok::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprNakSkidok::ToolButtonDeleteClick(TObject *Sender)
{
DeleteElement();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprNakSkidok::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprNakSkidok");
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprNakSkidok::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
        {
		TypeEvent=1;
        DM->OpenElement(DM->TableID_SNAK_SKIDOK->AsInt64);
        Close();
        }
else
        {
        OpenFormElement();
		}
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprNakSkidok::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

