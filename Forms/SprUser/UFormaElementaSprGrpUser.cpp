//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprGrpUser.h"
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
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxDBEdit"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaElementaSprGrpUser::TFormaElementaSprGrpUser(TComponent* Owner)
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

bool TFormaElementaSprGrpUser::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprGrpUser.1",IID_IDMSprGrpUser, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

IdGnDBText->DataSource=DM->DataSourceElement;
NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
RolecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;

ObrabatChangeInterf=false;

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
int TFormaElementaSprGrpUser::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaElementaSprGrpUser::UpdateForm(void)
{
ObrabatChangeInterf=false;
InterfUserComboBox->ItemIndex=DM->ElementINTERF_SGRPUSER->AsInteger;
ObrabatChangeInterf=true;
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprGrpUser::FormClose(TObject *Sender,
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
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprGrpUser::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprUser");
}
//---------------------------------------------------------------------------





void __fastcall TFormaElementaSprGrpUser::InterfUserComboBoxPropertiesChange(
      TObject *Sender)
{
if(ObrabatChangeInterf==false) return;
DM->Element->Edit();
DM->ElementINTERF_SGRPUSER->AsInteger=InterfUserComboBox->ItemIndex;
DM->Element->Post();


}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprGrpUser::NamecxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprGrpUser::RolecxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprGrpUser::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprGrpUser::ActionOKExecute(TObject *Sender)
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
int TFormaElementaSprGrpUser::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{

return -1;
}
//----------------------------------------------------------------------------
