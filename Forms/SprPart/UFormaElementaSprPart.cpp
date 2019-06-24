//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprPart.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxEdit"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxTextEdit"
#pragma link "cxCalc"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxGroupBox"
#pragma link "cxCalendar"
#pragma link "cxButtonEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaElementaSprPart::TFormaElementaSprPart(TComponent* Owner)
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
bool TFormaElementaSprPart::Init(void)
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
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPart.1",IID_IDMSprPart, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

NameNom->DataSource=DM->DataSourceElement;
CodePart->DataSource=DM->DataSourceElement;

FirmPart->DataSource=DM->DataSourceElement;
NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
DocPart->DataSource=DM->DataSourceElement;

GTDcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
SertcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
SrokGodncxDBDateEdit->DataBinding->DataSource=DM->DataSourceElement;
PricecxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;


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
int TFormaElementaSprPart::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprPart::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprKlient)FormaSpiskaSprKlient->kanRelease();
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
void __fastcall TFormaElementaSprPart::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprPart");	
}
//---------------------------------------------------------------------------



void __fastcall TFormaElementaSprPart::GTDcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprPart::SertcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprPart::SrokGodncxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprPart::PricecxDBCalcEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------


void TFormaElementaSprPart::ViborSupplier(void)
{

if (FormaSpiskaSprKlient==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&FormaSpiskaSprKlient);
	FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
	FormaSpiskaSprKlient->Vibor=true;
	FormaSpiskaSprKlient->NumberProcVibor=1;
	}
}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaSprPart::EndViborSupplier(void)
{

	DM->Element->Edit();
	DM->ElementIDKLPART->AsInt64=FormaSpiskaSprKlient->DM->TableIDKLIENT->AsInt64;
	DM->ElementNAMEKLIENT->AsString=FormaSpiskaSprKlient->DM->TableNAMEKLIENT->AsString;
	DM->Element->Post();

FormaSpiskaSprKlient=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprPart::NameKlientcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborSupplier();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprPart::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprPart::ActionOKExecute(TObject *Sender)
{
if (DM->SaveElement()==true)
		{
		TypeEvent=1;
		Close();
		}
else
	{
	ShowMessage("������ ��� ������ �������� �����������: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------
int TFormaElementaSprPart::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{
if (number_procedure_end ==1)
		{
		if (type_event ==1)
			{
			EndViborSupplier();
			}
		}

FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//-----------------------------------------------------------------------------
