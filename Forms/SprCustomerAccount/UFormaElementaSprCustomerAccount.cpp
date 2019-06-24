//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprCustomerAccount.h"
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
__fastcall TFormaElementaSprCustomerAccount::TFormaElementaSprCustomerAccount(TComponent* Owner)
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
bool TFormaElementaSprCustomerAccount::Init(void)
{
bool result=false;
if (InterfaceMainObject>0)
	{
	//получим соединение
	IConnectionInterface * i_connection;
	InterfaceMainObject->kanQueryInterface(IID_IConnectionInterface,(void**)&i_connection);
	DM_Connection=i_connection->GetFibConnection();
	i_connection->kanRelease();

	//получим интерфейс COM системы для создания новых объектов
	IMainCOMInterface * i_com;
	InterfaceMainObject->kanQueryInterface(IID_IMainCOMInterface,(void**)&i_com);
	InterfaceGlobalCom=i_com->GetCOM();
	i_com->kanRelease();
	}

InterfaceGlobalCom->kanCreateObject(ProgId_DMSprCustomerAccount,IID_IDMSprCustomerAccount,
							(void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);


NameUsercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
DescrcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;

PasswordcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
LogincxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;


//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;
return result;
}
//---------------------------------------------------------------------------
int  TFormaElementaSprCustomerAccount::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaSprCustomerAccount::FormClose(TObject *Sender,
      TCloseAction &Action)
{

if(FormaSpiskaSprUser)FormaSpiskaSprUser->kanRelease();


DM->kanRelease();


//получим ICallBack для передачи события в вызывающую форму
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
void TFormaElementaSprCustomerAccount::UpdateForm(void)
{

NameGrpLabel->Caption=NameGrp;
}
//---------------------------------------------------------------------------


int TFormaElementaSprCustomerAccount::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
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







void __fastcall TFormaElementaSprCustomerAccount::cxButtonOpenFormaSpiskaElementClick(TObject *Sender)
{
IFormaSpiskaSprCustomerKlient * FormaSpiskaSprCustomerKlient;

		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprCustomerKlient,IID_IFormaSpiskaSprCustomerKlient,
													 (void**)&FormaSpiskaSprCustomerKlient);
		FormaSpiskaSprCustomerKlient->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprCustomerKlient->IdOwner=glStrToInt64(DM->ElementID_CUST_ACCOUNT->AsString);
		FormaSpiskaSprCustomerKlient->DM->OpenTable(glStrToInt64(DM->ElementID_CUST_ACCOUNT->AsString));
		FormaSpiskaSprCustomerKlient->TextHeader=DM->ElementNAME_CUST_ACCOUNT->AsString;
		FormaSpiskaSprCustomerKlient->UpdateForm();
		FormaSpiskaSprCustomerKlient->NumberProcVibor=ER_EditKlient;



}
//---------------------------------------------------------------------------


void __fastcall TFormaElementaSprCustomerAccount::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprCustomerAccount::ActionOKExecute(TObject *Sender)
{
if (DM->SaveElement()==true)
	{
    Close();
	}
else
	{
	ShowMessage("Ошибка при записи!"+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprCustomerAccount::ActionSaveExecute(TObject *Sender)
{
if (DM->SaveElement()==true)
	{

	}
else
	{
	ShowMessage("Ошибка при записи!"+DM->TextError);
	}
}
//---------------------------------------------------------------------------



void __fastcall TFormaElementaSprCustomerAccount::KeyWordscxDBTextEditKeyPress(TObject *Sender,
          wchar_t &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------






