//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprCustomerUser.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxCalc"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxLabel"
#pragma link "cxPC"
#pragma link "cxButtonEdit"
#pragma link "cxGroupBox"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxGraphics"
#pragma link "cxButtons"
#pragma link "cxMemo"
#pragma link "cxImageComboBox"
#pragma link "cxDBLookupComboBox"
#pragma link "cxDBLookupEdit"
#pragma link "cxLookupEdit"
#pragma link "cxClasses"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxFilter"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "cxDBLabel"
#pragma link "cxCalendar"
#pragma link "cxCheckBox"
#pragma link "cxSpinEdit"
#pragma link "cxCurrencyEdit"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TFormaElementaSprCustomerUser::TFormaElementaSprCustomerUser(TComponent* Owner)
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
bool TFormaElementaSprCustomerUser::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_DMSprCustomerUser,IID_IDMSprCustomerUser,
							(void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);



NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
PasswordcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
LogincxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;


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
int  TFormaElementaSprCustomerUser::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaSprCustomerUser::FormClose(TObject *Sender,
      TCloseAction &Action)
{




DM->kanRelease();


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

Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void TFormaElementaSprCustomerUser::UpdateForm(void)
{

NameGrpLabel->Caption=NameGrp;
}
//---------------------------------------------------------------------------


int TFormaElementaSprCustomerUser::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{

		if (number_procedure_end==ER_EditKlient)
				{
				if (type_event==1)
					{

					}
				//FormaSpiskaSprInfBlockSostav=0;
				}


FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//-----------------------------------------------------------------------------









void __fastcall TFormaElementaSprCustomerUser::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprCustomerUser::ActionOKExecute(TObject *Sender)
{
if (DM->SaveElement()==true)
	{
    Close();
	}
else
	{
	ShowMessage("������ ��� ������!"+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprCustomerUser::ActionSaveExecute(TObject *Sender)
{
if (DM->SaveElement()==true)
	{

	}
else
	{
	ShowMessage("������ ��� ������!"+DM->TextError);
	}
}
//---------------------------------------------------------------------------



void __fastcall TFormaElementaSprCustomerUser::KeyWordscxDBTextEditKeyPress(TObject *Sender,
          wchar_t &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------






void __fastcall TFormaElementaSprCustomerUser::cxButton1Click(TObject *Sender)
{
DM->Element->Edit();
DM->ElementPASSWORD_CUST_USER->AsString="40BD001563085FC35165329EA1FF5C5ECBDBBEEF";
DM->Element->Post();
}
//---------------------------------------------------------------------------

