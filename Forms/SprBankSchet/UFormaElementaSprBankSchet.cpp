//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprBankSchet.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtonEdit"
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxEdit"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxDBLabel"
#pragma link "cxLabel"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaElementaSprBankSchet::TFormaElementaSprBankSchet(TComponent* Owner)
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
bool TFormaElementaSprBankSchet::Init(void)
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
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprBankSchet.1",IID_IDMSprBankSchet,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);


NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NameBankcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;

IdBSchetcxDBLabel->DataBinding->DataSource=DM->DataSourceElement;
PrefiksNumDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;

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
int TFormaElementaSprBankSchet::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprBankSchet::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokBank)SpisokBank->kanRelease();
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
void __fastcall TFormaElementaSprBankSchet::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprBSchet");
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprBankSchet::NameBankcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (SpisokBank==0)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprBank.1",IID_IFormaSpiskaSprBank,
													(void**)&SpisokBank);
		SpisokBank->Init(InterfaceMainObject,InterfaceImpl);
        SpisokBank->Vibor=true;
		SpisokBank->NumberProcVibor=1;
        }	
}
//---------------------------------------------------------------------------



void __fastcall TFormaElementaSprBankSchet::NamecxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
 if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprBankSchet::NumcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprBankSchet::ActionOKExecute(TObject *Sender)
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

void __fastcall TFormaElementaSprBankSchet::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
int TFormaElementaSprBankSchet::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{
if (number_procedure_end==1)
	{
	if (type_event==1)    //����� ������
		{
		DM->Element->Edit();
		DM->ElementIDBANKBSCHET->AsString=SpisokBank->DM->TableIDBANK->AsString;
		DM->ElementNAMEBANK->AsString=SpisokBank->DM->Element->FieldByName("NAMEBANK")->AsString;
		DM->Element->Post();
		}
	SpisokBank=0;
	}
FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//-----------------------------------------------------------------------------
