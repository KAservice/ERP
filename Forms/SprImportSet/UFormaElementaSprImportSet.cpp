//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprImportSet.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxCheckBox"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxEdit"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxTextEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxGraphics"
#pragma link "cxMaskEdit"
#pragma link "cxMemo"
#pragma link "cxCalc"
#pragma link "cxLabel"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaElementaSprImportSet::TFormaElementaSprImportSet(TComponent* Owner)
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
bool TFormaElementaSprImportSet::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprImportSet.1",IID_IDMSprImportSet, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
TypeObrcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;
StrParamcxDBMemo->DataBinding->DataSource=DM->DataSourceElement;

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
void __fastcall TFormaElementaSprImportSet::FormClose(TObject *Sender,
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
int TFormaElementaSprImportSet::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaElementaSprImportSet::UpdateForm(void)
{
TypeSearchcxComboBox->ItemIndex=DM->ElementTYPE_SEARCH_SIMPORTSET->AsInteger;

}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprImportSet::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprImportSet");	
}
//---------------------------------------------------------------------------




void __fastcall TFormaElementaSprImportSet::NamecxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------




void __fastcall TFormaElementaSprImportSet::TypeObrcxDBCalcEditKeyPress(
      TObject *Sender, char &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprImportSet::StrParamcxDBMemoKeyPress(
      TObject *Sender, char &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprImportSet::TypeSearchcxComboBoxPropertiesValidate(
      TObject *Sender, Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
DM->Element->Edit();
DM->ElementTYPE_SEARCH_SIMPORTSET->AsInteger=TypeSearchcxComboBox->ItemIndex;
DM->Element->Post();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprImportSet::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprImportSet::ActionOKExecute(TObject *Sender)
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
int TFormaElementaSprImportSet::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{


return -1;
}
//-----------------------------------------------------------------------------
