//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprMPrig.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxButtonEdit"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaElementaSprMPrig::TFormaElementaSprMPrig(TComponent* Owner)
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
bool TFormaElementaSprMPrig::Init(void)
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
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprMPrig.1",IID_IDMSprMPrig, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);


IDMPrigDBText->DataSource=DM->DataSourceElement;
NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NameOborudcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameSkladcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;


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
int TFormaElementaSprMPrig::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprMPrig::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprSklad)FormaSpiskaSprSklad->kanRelease();
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

//----------------------------------------------------------------------------
int TFormaElementaSprMPrig::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{
if (number_procedure_end==1)    //����� ������
		{
		if (type_event==1)//ViborSklad)
				{
				DM->Element->Edit();
				DM->ElementIDSKLAD_MPRIG->AsInt64=glStrToInt64(FormaSpiskaSprSklad->DM->ElementIDSKLAD->AsString);
				DM->ElementNAMESKLAD->AsString=FormaSpiskaSprSklad->DM->ElementNAMESKLAD->AsString;
				DM->Element->Post();
				FormaSpiskaSprSklad=0;
				}
		}

FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//-----------------------------------------------------------------------------
void TFormaElementaSprMPrig::OpenFormSpiskaSprSklad(void)
{
if (FormaSpiskaSprSklad==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&FormaSpiskaSprSklad);
		FormaSpiskaSprSklad->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprSklad->Vibor=true;
		FormaSpiskaSprSklad->NumberProcVibor=1;
        }
}
//----------------------------------------------------------------------------

void __fastcall TFormaElementaSprMPrig::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprMPrig");
}
//---------------------------------------------------------------------------



void __fastcall TFormaElementaSprMPrig::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprSklad();
}
//---------------------------------------------------------------------------


void __fastcall TFormaElementaSprMPrig::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprMPrig::ActionOKExecute(TObject *Sender)
{
if (DM->SaveElement()==true)
		{
		Close();
		}
else
	{
	ShowMessage("������ ��� ������ �������� �����������: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

