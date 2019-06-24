//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprNakSkidok.h"
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
#pragma link "cxGroupBox"
#pragma link "cxRadioGroup"
#pragma link "cxSpinEdit"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaElementaSprNakSkidok::TFormaElementaSprNakSkidok(TComponent* Owner)
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
bool TFormaElementaSprNakSkidok::Init(void)
{
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

bool result=false;

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNakSkidok.1",IID_IDMSprNakSkidok, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

NameVidcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NAmeSkladcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
PeriodcxDBSpinEdit->DataBinding->DataSource=DM->DataSourceElement;
SumcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;
ProcentcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;

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
int  TFormaElementaSprNakSkidok::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprNakSkidok::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprSklad)FormaSpiskaSprSklad->kanRelease();
if(FormaSpiskaSprVidDiscountCard)FormaSpiskaSprVidDiscountCard->kanRelease();

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
}
//---------------------------------------------------------------------------
void TFormaElementaSprNakSkidok::UpdateForm(void)
{
//
}
//---------------------------------------------------------------------------
int TFormaElementaSprNakSkidok::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ER_Sklad)
		{
		if (type_event==1)
				{
				EndViborSklad ();
				}
		FormaSpiskaSprSklad=0;
		}

if (number_procedure_end==ER_VidCard)
		{
		if (type_event==1)
				{
				EndViborVidDiscountCard();
				}
		FormaSpiskaSprVidDiscountCard=0;
		}

return -1;
}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaSprNakSkidok::EndViborSklad(void)
{

	DM->Element->Edit();
	DM->ElementIDSKLAD_SNAK_SKIDOK->AsInt64=glStrToInt64(FormaSpiskaSprSklad->DM->TableIDSKLAD->AsString);
	DM->ElementNAMESKLAD->AsString=FormaSpiskaSprSklad->DM->TableNAMESKLAD->AsString;
	DM->Element->Post();

}
//----------------------------------------------------------------------------
void TFormaElementaSprNakSkidok::ViborSklad(void)
{
if (FormaSpiskaSprSklad==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&FormaSpiskaSprSklad);
	FormaSpiskaSprSklad->Init(InterfaceMainObject,InterfaceImpl);
	//настройка формы
	FormaSpiskaSprSklad->Vibor=true;
	FormaSpiskaSprSklad->NumberProcVibor=ER_Sklad;
	}
}
//----------------------------------------------------------------------------



void __fastcall TFormaElementaSprNakSkidok::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprNakSkidok");
}
//---------------------------------------------------------------------------




void __fastcall TFormaElementaSprNakSkidok::cxDBButtonEdit1PropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborSklad();
}
//---------------------------------------------------------------------------

void TFormaElementaSprNakSkidok::ViborVidDiscountCard(void)
{
if (FormaSpiskaSprVidDiscountCard==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprVidDiscountCard.1",IID_IFormaSpiskaSprVidDiscountCard,
													(void**)&FormaSpiskaSprVidDiscountCard);
	FormaSpiskaSprVidDiscountCard->Init(InterfaceMainObject,InterfaceImpl);
	//настройка формы
	FormaSpiskaSprVidDiscountCard->Vibor=true;
	FormaSpiskaSprVidDiscountCard->NumberProcVibor=ER_VidCard;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprNakSkidok::EndViborVidDiscountCard(void)
{

	DM->Element->Edit();
	DM->ElementIDVID_SNAK_SKIDOK->AsInt64=FormaSpiskaSprVidDiscountCard->DM->TableID_SVID_DCARD->AsInt64;
	DM->ElementNAME_SVID_DCARD->AsString=FormaSpiskaSprVidDiscountCard->DM->TableNAME_SVID_DCARD->AsString;
	DM->Element->Post();

}
//------------------------------------------------------------------------------
void __fastcall TFormaElementaSprNakSkidok::NameVidcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborVidDiscountCard();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNakSkidok::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNakSkidok::ActionOKExecute(TObject *Sender)
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

void __fastcall TFormaElementaSprNakSkidok::ActionSaveExecute(TObject *Sender)
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



