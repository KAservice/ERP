//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprDiscountCard.h"

#include "UGlobalConstant.h"
#include "UGlobalFunction.h"

#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxCalc"
#pragma link "cxCalendar"
#pragma link "cxCheckBox"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxButtonEdit"
#pragma link "cxLabel"
#pragma link "cxLookAndFeels"
#pragma link "cxImageComboBox"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaElementaSprDiscountCard::TFormaElementaSprDiscountCard(TComponent* Owner)
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
bool TFormaElementaSprDiscountCard::Init(void)
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
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprDiscountCard.1",IID_IDMSprDiscountCard, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

ActcxDBCheckBox1->DataBinding->DataSource=DM->DataSourceElement;
SinglecxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;
CodecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
TypeCardcxDBImageComboBox->DataBinding->DataSource=DM->DataSourceElement;
SHCodecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
ProcentcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;
NachcxDBDateEdit->DataBinding->DataSource=DM->DataSourceElement;
ConcxDBDateEdit->DataBinding->DataSource=DM->DataSourceElement;
NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameVidcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;

FlDiscontcxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;
FlPlatCardcxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;
FlCreditcxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;
NameDogovorcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;


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
int TFormaElementaSprDiscountCard::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprDiscountCard::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
if(FormaSpiskaSprKlient)FormaSpiskaSprKlient->kanRelease();
if(FormaSpiskaSprVidDiscountCard)FormaSpiskaSprVidDiscountCard->kanRelease();
if(FormaSpiskaSprDogovor) FormaSpiskaSprDogovor->kanRelease();

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
void TFormaElementaSprDiscountCard::UpdateForm(void)
{
//
}
//---------------------------------------------------------------------------
int TFormaElementaSprDiscountCard::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==1)
		{
		if (type_event==1)    //выбор сделан
			{
			EndViborKlient();
			}
		FormaSpiskaSprKlient=0;
		}


if (number_procedure_end==2)
		{
		if (type_event==1)    //выбор сделан
			{
			EndViborVidDiscountCard();
			}
		FormaSpiskaSprVidDiscountCard=0;
		}

if (number_procedure_end==3)
		{
		if (type_event==1)    //выбор сделан
			{
            EndViborDogovor();
			}
        FormaSpiskaSprDogovor=0;
		}

FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//-----------------------------------------------------------------------------
void __fastcall TFormaElementaSprDiscountCard::EndViborKlient(void)
{

	DM->Element->Edit();
	DM->ElementIDKLIENT_SDISCOUNT_CARD->AsString=FormaSpiskaSprKlient->DM->TableIDKLIENT->AsString;
	DM->ElementNAMEKLIENT->AsString=FormaSpiskaSprKlient->DM->TableNAMEKLIENT->AsString;
	DM->Element->Post();


}
//----------------------------------------------------------------------------
void TFormaElementaSprDiscountCard::ViborKlient(void)
{
if (FormaSpiskaSprKlient==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&FormaSpiskaSprKlient);
	FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
	FormaSpiskaSprKlient->Vibor=true;
	FormaSpiskaSprKlient->UpdateForm();
	FormaSpiskaSprKlient->NumberProcVibor=1;
	}
}
//----------------------------------------------------------------------------



void __fastcall TFormaElementaSprDiscountCard::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprDiscountCard");	
}
//---------------------------------------------------------------------------




void __fastcall TFormaElementaSprDiscountCard::cxDBButtonEdit1PropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborKlient();
}
//---------------------------------------------------------------------------
void TFormaElementaSprDiscountCard::ViborVidDiscountCard(void)
{
if (FormaSpiskaSprVidDiscountCard==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprVidDiscountCard.1",IID_IFormaSpiskaSprVidDiscountCard,
													(void**)&FormaSpiskaSprVidDiscountCard);
	FormaSpiskaSprVidDiscountCard->Init(InterfaceMainObject,InterfaceImpl);
	//настройка формы
	FormaSpiskaSprVidDiscountCard->Vibor=true;
	FormaSpiskaSprVidDiscountCard->NumberProcVibor=2;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprDiscountCard::EndViborVidDiscountCard(void)
{

	DM->Element->Edit();
	DM->ElementIDVID_SDISCOUNT_CARD->AsString=FormaSpiskaSprVidDiscountCard->DM->TableID_SVID_DCARD->AsString;
	DM->ElementNAME_SVID_DCARD->AsString=FormaSpiskaSprVidDiscountCard->DM->TableNAME_SVID_DCARD->AsString;
	DM->Element->Post();




}
//------------------------------------------------------------------------------
void __fastcall TFormaElementaSprDiscountCard::NameVidcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborVidDiscountCard();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprDiscountCard::ActcxDBCheckBox1KeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprDiscountCard::CodecxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprDiscountCard::TypecxDBComboBoxPropertiesChange(
      TObject *Sender)
{


	FindNextControl(ActiveControl,true,true,false)->SetFocus();

}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprDiscountCard::SHCodecxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprDiscountCard::NamecxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprDiscountCard::ProcentcxDBCalcEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprDiscountCard::NachcxDBDateEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprDiscountCard::ConcxDBDateEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------
void TFormaElementaSprDiscountCard::ViborDogovor(void)
{
if (FormaSpiskaSprDogovor==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprDogovor.1",IID_IFormaSpiskaSprDogovor,
													(void**)&FormaSpiskaSprDogovor);
	FormaSpiskaSprDogovor->Init(InterfaceMainObject,InterfaceImpl);
	FormaSpiskaSprDogovor->IdKlient=glStrToInt64(DM->ElementIDKLIENT_SDISCOUNT_CARD->AsString);
	FormaSpiskaSprDogovor->DM->OpenTable(glStrToInt64(DM->ElementIDKLIENT_SDISCOUNT_CARD->AsString));
	//FormaSpiskaSprDogovor->LabelKlient->Caption="Контрагент: "+DM->ElementNAMEKLIENT->AsString;
	FormaSpiskaSprDogovor->Vibor=true;
	FormaSpiskaSprDogovor->NumberProcVibor=3;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprDiscountCard::EndViborDogovor(void)
{

	DM->Element->Edit();
	DM->ElementIDDOG_SDISCOUNT_CARD->AsString=FormaSpiskaSprDogovor->DM->TableID_SDOG->AsString;
	DM->ElementNAME_SDOG->AsString=FormaSpiskaSprDogovor->DM->TableNAME_SDOG->AsString;
	DM->Element->Post();

}
//----------------------------------------------------------------------------

void __fastcall TFormaElementaSprDiscountCard::NameDogovorcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborDogovor();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprDiscountCard::ActionCloseExecute(TObject *Sender)

{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprDiscountCard::ActionOKExecute(TObject *Sender)
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

void __fastcall TFormaElementaSprDiscountCard::ActionSaveExecute(TObject *Sender)

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


