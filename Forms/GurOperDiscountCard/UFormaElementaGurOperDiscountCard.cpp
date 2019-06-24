//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaGurOperDiscountCard.h"
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
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaElementaGurOperDiscountCard::TFormaElementaGurOperDiscountCard(TComponent* Owner)
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
bool TFormaElementaGurOperDiscountCard::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.DMGurOperDiscountCard.1",IID_IDMGurOperDiscountCard, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

PoscxDBDateEdit->DataBinding->DataSource=DM->DataSourceElement;
NameSkladcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameCardcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
SumcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;

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
int TFormaElementaGurOperDiscountCard::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaGurOperDiscountCard::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprKlient)FormaSpiskaSprKlient->kanRelease();
if(FormaSpiskaSprSklad)FormaSpiskaSprSklad->kanRelease();
if(FormaSpiskaSprDiscountCard)FormaSpiskaSprDiscountCard->kanRelease();

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
void TFormaElementaGurOperDiscountCard::UpdateForm(void)
{
//
}
//---------------------------------------------------------------------------
int TFormaElementaGurOperDiscountCard::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{


		if (number_procedure_end==ER_Klient)
				{
				if(type_event==1)
						{
						EndViborKlient();
						}
				FormaSpiskaSprKlient=0;
				}

		if (number_procedure_end==ER_Sklad)
				{
				if(type_event==1)
						{
						EndViborSklad();
						}
				FormaSpiskaSprSklad=0;
				}

		if (number_procedure_end==ER_Card)
				{
				if(type_event==1)
						{
						EndViborDiscountCard();
						}
				FormaSpiskaSprDiscountCard=0;
				}
return -1;
}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaGurOperDiscountCard::EndViborKlient(void)
{

	DM->Element->Edit();
	DM->ElementIDKLIENT_GUROPER_DCARD->AsInt64=FormaSpiskaSprKlient->DM->TableIDKLIENT->AsInt64;
	DM->ElementNAMEKLIENT->AsString=FormaSpiskaSprKlient->DM->TableNAMEKLIENT->AsString;
	DM->Element->Post();

}
//----------------------------------------------------------------------------
void TFormaElementaGurOperDiscountCard::ViborKlient(void)
{
if (FormaSpiskaSprKlient==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
										(void**)&FormaSpiskaSprKlient);
	FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
	//настройка формы
	FormaSpiskaSprKlient->Vibor=true;
	FormaSpiskaSprKlient->NumberProcVibor=ER_Klient;
	FormaSpiskaSprKlient->UpdateForm();
	}
}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaGurOperDiscountCard::EndViborSklad(void)
{

	DM->Element->Edit();
	DM->ElementIDSKLAD_GUROPER_DCARD->AsInt64=glStrToInt64(FormaSpiskaSprSklad->DM->TableIDSKLAD->AsString);
	DM->ElementNAMESKLAD->AsString=FormaSpiskaSprSklad->DM->TableNAMESKLAD->AsString;
	DM->Element->Post();

}
//----------------------------------------------------------------------------
void TFormaElementaGurOperDiscountCard::ViborSklad(void)
{
if (FormaSpiskaSprSklad==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
										(void**)&FormaSpiskaSprSklad);
	FormaSpiskaSprSklad->Init(InterfaceMainObject,InterfaceImpl);
	if (!FormaSpiskaSprSklad) return;
	//настройка формы
	FormaSpiskaSprSklad->Vibor=true;
	FormaSpiskaSprSklad->NumberProcVibor=ER_Sklad;
	}
}
//----------------------------------------------------------------------------



void __fastcall TFormaElementaGurOperDiscountCard::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("GurOperDiscountCard");
}
//---------------------------------------------------------------------------




void __fastcall TFormaElementaGurOperDiscountCard::cxDBButtonEdit1PropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborKlient();
}
//---------------------------------------------------------------------------
void TFormaElementaGurOperDiscountCard::ViborDiscountCard(void)
{
if (FormaSpiskaSprDiscountCard==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprDiscountCard.1",IID_IFormaSpiskaSprDiscountCard,
										(void**)&FormaSpiskaSprDiscountCard);
	FormaSpiskaSprSklad->Init(InterfaceMainObject,InterfaceImpl);
	FormaSpiskaSprDiscountCard->Vibor=true;
	FormaSpiskaSprDiscountCard->IdKlient=DM->ElementIDKLIENT_GUROPER_DCARD->AsInt64;
	FormaSpiskaSprDiscountCard->DM->OpenTable(DM->ElementIDKLIENT_GUROPER_DCARD->AsInt64);
	//FormaSpiskaSprDiscountCard->LabelKlient->Caption="Контрагент: "+DM->ElementNAMEKLIENT->AsString;
	FormaSpiskaSprDiscountCard->NameKlient=DM->TableNAMEKLIENT->AsString;
	FormaSpiskaSprDiscountCard->NumberProcVibor=ER_Card;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaGurOperDiscountCard::EndViborDiscountCard(void)
{

	DM->Element->Edit();
	DM->ElementIDCARD_GUROPER_DCARD->AsString=FormaSpiskaSprDiscountCard->DM->TableID_SDISCOUNT_CARD->AsString;
	DM->ElementNAME_SDISCOUNT_CARD->AsString=FormaSpiskaSprDiscountCard->DM->TableNAME_SDISCOUNT_CARD->AsString;
	DM->Element->Post();

}
//------------------------------------------------------------------------------
void __fastcall TFormaElementaGurOperDiscountCard::NameVidcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborDiscountCard();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaGurOperDiscountCard::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborSklad();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaGurOperDiscountCard::ActionCloseExecute(TObject *Sender)

{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaGurOperDiscountCard::ActionOKExecute(TObject *Sender)

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

void __fastcall TFormaElementaGurOperDiscountCard::ActionSaveExecute(TObject *Sender)

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

