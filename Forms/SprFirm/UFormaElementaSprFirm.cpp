//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprFirm.h"
#include "IFormaSpiskaSprBankSchet.h"
#include "UDM.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
 #include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxEdit"
#pragma link "cxTextEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxGraphics"
#pragma link "cxMaskEdit"
#pragma link "cxDBLabel"
#pragma link "cxLabel"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaElementaSprFirm::TFormaElementaSprFirm(TComponent* Owner)
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
bool TFormaElementaSprFirm::Init(void)
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
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

NamefirmcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
FNamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
UAdrcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
PAdrcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
DircxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
BuhcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
KassircxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
INNcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
KPPcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NumDocRegcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
DateDocRegcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
OKPOcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
OKDPcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
TelcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
IdFirmcxDBLabel->DataBinding->DataSource=DM->DataSourceElement;
KrNamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
PrefiksNumDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
flObrabatChangeType=false;

//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;
return result;
}
//--------------------------------------------------------------------------
int TFormaElementaSprFirm::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaElementaSprFirm::UpdateForm(void)
{
flObrabatChangeType=false;
TypeComboBox->ItemIndex=DM->ElementTYPEFIRM->AsInteger;
flObrabatChangeType=true;
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprFirm::FormClose(TObject *Sender, TCloseAction &Action)
{
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
DM->kanRelease();

Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------



void __fastcall TFormaElementaSprFirm::cxButtonBankSchClick(TObject *Sender)
{
IFormaSpiskaSprBankSchet * forma;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprBankSchet.1",IID_IFormaSpiskaSprBankSchet, (void**)&forma);

forma->Init(InterfaceMainObject,InterfaceImpl);

forma->IdFirm=DM->ElementIDFIRM->AsInt64;
forma->DM->IdFirm=DM->ElementIDFIRM->AsInt64;
forma->DM->OpenTable();
//FSBSchet->LabelFirma->Caption="Фирма: "+DM->ElementNAMEFIRM->AsString;
}
//---------------------------------------------------------------------------




void __fastcall TFormaElementaSprFirm::TypeComboBoxPropertiesChange(
      TObject *Sender)
{
if(flObrabatChangeType==false) return;
DM->Element->Edit();
DM->ElementTYPEFIRM->AsInteger=TypeComboBox->ItemIndex;
DM->Element->Post();

	FindNextControl(ActiveControl,true,true,false)->SetFocus();

}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprFirm::NamefirmcxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprFirm::FNamecxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprFirm::UAdrcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprFirm::PAdrcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprFirm::DircxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprFirm::BuhcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprFirm::KassircxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprFirm::INNcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprFirm::KPPcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprFirm::NumDocRegcxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprFirm::DateDocRegcxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprFirm::OKPOcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprFirm::OKDPcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprFirm::TelcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprFirm::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprFirm");
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprFirm::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprFirm::ActionOKExecute(TObject *Sender)
{
if (DM->SaveElement()==true)
		{
		Close();
		}
else
	{
	ShowMessage("Ошибка при записи элемента справочника: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprFirm::ActionSaveExecute(TObject *Sender)
{
if (DM->SaveElement()==true)
		{

		}
else
	{
	ShowMessage("Ошибка при записи элемента справочника: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------
int TFormaElementaSprFirm::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

return -1;
}
//-----------------------------------------------------------------------------
