//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprProperties.h"
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
__fastcall TFormaElementaSprProperties::TFormaElementaSprProperties(TComponent* Owner)
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
bool TFormaElementaSprProperties::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_DMSprProperties,IID_IDMSprProperties,
							(void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NameForPrintcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
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
int  TFormaElementaSprProperties::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaSprProperties::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprPropertiesValuesList)FormaSpiskaSprPropertiesValuesList->kanRelease();



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
void TFormaElementaSprProperties::UpdateForm(void)
{

NameGrpLabel->Caption=NameGrp;
}
//---------------------------------------------------------------------------


int TFormaElementaSprProperties::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

		if (number_procedure_end==ER_ViborSpisokZnach)
				{
				if (type_event==1)
					{
					}
				FormaSpiskaSprPropertiesValuesList=0;
				}


FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//-----------------------------------------------------------------------------


void __fastcall TFormaElementaSprProperties::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprProperties");
}

//-----------------------------------------------------------------------------





void __fastcall TFormaElementaSprProperties::cxButtonValuesListClick(TObject *Sender)
{

if (FormaSpiskaSprPropertiesValuesList==0)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprPropertiesValuesList,IID_IFormaSpiskaSprPropertiesValuesList,
													 (void**)&FormaSpiskaSprPropertiesValuesList);
		FormaSpiskaSprPropertiesValuesList->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprPropertiesValuesList->IdProp=glStrToInt64(DM->ElementID_SPROP->AsString);
		FormaSpiskaSprPropertiesValuesList->DM->OpenTable(glStrToInt64(DM->ElementID_SPROP->AsString));
		FormaSpiskaSprPropertiesValuesList->HeaderText="Значения свойства: "+DM->ElementNAME_SPROP->AsString;
		FormaSpiskaSprPropertiesValuesList->UpdateForm();
		FormaSpiskaSprPropertiesValuesList->NumberProcVibor=ER_ViborSpisokZnach;
		}


}
//---------------------------------------------------------------------------


void __fastcall TFormaElementaSprProperties::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprProperties::ActionOKExecute(TObject *Sender)
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

void __fastcall TFormaElementaSprProperties::ActionSaveExecute(TObject *Sender)
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



void __fastcall TFormaElementaSprProperties::NameForPrintcxDBTextEditKeyPress(TObject *Sender,
          wchar_t &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------



void __fastcall TFormaElementaSprProperties::NamecxDBTextEditKeyPress(TObject *Sender,
          wchar_t &Key)
{
if(Key==VK_RETURN)
	{
	DM->Element->Edit();
	DM->ElementNAME_FOR_PRINT_SPROP->AsString=DM->ElementNAME_SPROP->AsString;
	DM->Element->Post();
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

