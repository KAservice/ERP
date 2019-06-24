//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprDiscountAuto.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxEdit"
#pragma link "cxTextEdit"
#pragma link "cxButtonEdit"
#pragma link "cxCalc"
#pragma link "cxCalendar"
#pragma link "cxCheckBox"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxSpinEdit"
#pragma link "cxTimeEdit"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxGroupBox"
#pragma link "cxRadioGroup"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma link "cxImageComboBox"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaElementaSprDiscountAuto::TFormaElementaSprDiscountAuto(TComponent* Owner)
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
bool TFormaElementaSprDiscountAuto::Init(void)
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


InterfaceGlobalCom->kanCreateObject("Oberon.DMSprDiscountAuto.1",IID_IDMSprDiscountAuto, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

PrSkcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;
ActcxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;
NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NachcxDBDateEdit->DataBinding->DataSource=DM->DataSourceElement;
ConcxDBDateEdit->DataBinding->DataSource=DM->DataSourceElement;
SummacxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;
DaycxDBSpinEdit->DataBinding->DataSource=DM->DataSourceElement;
TimeNachcxDBTimeEdit->DataBinding->DataSource=DM->DataSourceElement;
TimeConcxDBTimeEdit->DataBinding->DataSource=DM->DataSourceElement;
NameVidNomcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameGrpNomcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameSkladcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;

NumSkidkicxDBRadioGroup->DataBinding->DataSource=DM->DataSourceElement;
TypeActioncxDBImageComboBox->DataBinding->DataSource=DM->DataSourceElement;
MessagecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
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
int TFormaElementaSprDiscountAuto::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprDiscountAuto::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprVidNom)FormaSpiskaSprVidNom->kanRelease();
if(FormaSpiskaSprSklad)FormaSpiskaSprSklad->kanRelease();
if(FormaSpiskaSprGrpNom) FormaSpiskaSprGrpNom->kanRelease();

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
void TFormaElementaSprDiscountAuto::UpdateForm(void)
{



}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprDiscountAuto::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprDiscountAuto");
}
//---------------------------------------------------------------------------
int TFormaElementaSprDiscountAuto::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ER_VidNom)
		{
		if (type_event==1)
				{
				EndViborVidNom();
				}
		FormaSpiskaSprVidNom=0;
		}


if (number_procedure_end==ER_Sklad)
		{
		if (type_event==1)
				{
				EndViborSklad();
				}
		FormaSpiskaSprSklad=0;
		}

if (number_procedure_end==ER_GrpNom)
		{
		if (type_event==1)
				{
				EndViborGrpNom();
				}
		FormaSpiskaSprGrpNom=0;
		}

return -1;
}
//----------------------------------------------------------------------------
void TFormaElementaSprDiscountAuto::ViborVidNom(void)
{

if (FormaSpiskaSprVidNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprVidNom.1",IID_IFormaSpiskaSprVidNom,
													(void**)&FormaSpiskaSprVidNom);
		FormaSpiskaSprVidNom->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprVidNom->NumberProcVibor=ER_VidNom;
		FormaSpiskaSprVidNom->Vibor=true;
		FormaSpiskaSprVidNom->UpdateForm();
		}

}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprDiscountAuto::EndViborVidNom(void)
{

	DM->Element->Edit();
	DM->ElementIDVIDNOM_SDISCOUNT_AUTO->AsString=FormaSpiskaSprVidNom->DM->TableID_SVIDNOM->AsString;
	DM->ElementNAME_SVIDNOM->AsString=FormaSpiskaSprVidNom->DM->TableNAME_SVIDNOM->AsString;
	DM->Element->Post();

}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprDiscountAuto::NameVidNomcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{

switch (AButtonIndex)
	{
	case 0:
		{
		ViborVidNom();
		}break;
	case 1:
		{
		DM->ElementNAME_SVIDNOM->Clear();
		DM->ElementIDVIDNOM_SDISCOUNT_AUTO->Clear();
		}break;
	}
}
//---------------------------------------------------------------------------
void TFormaElementaSprDiscountAuto::ViborSklad(void)
{

if (FormaSpiskaSprSklad==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&FormaSpiskaSprSklad);
		FormaSpiskaSprSklad->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprSklad->NumberProcVibor=ER_Sklad;
		FormaSpiskaSprSklad->Vibor=true;
		}

}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprDiscountAuto::EndViborSklad(void)
{

	DM->Element->Edit();
	DM->ElementIDSKLAD_SDISCOUNT_AUTO->AsString=FormaSpiskaSprSklad->DM->TableIDSKLAD->AsString;
	DM->ElementNAMESKLAD->AsString=FormaSpiskaSprSklad->DM->TableNAMESKLAD->AsString;
	DM->Element->Post();

}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprDiscountAuto::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborSklad();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprDiscountAuto::ActionOKExecute(TObject *Sender)
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

void __fastcall TFormaElementaSprDiscountAuto::ActionCloseExecute(TObject *Sender)

{
Close();
}
//---------------------------------------------------------------------------
void TFormaElementaSprDiscountAuto::OpenFormSpiskaSprGrpNom(void)
{
if (FormaSpiskaSprGrpNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprGrpNom.1",IID_IFormaSpiskaSprGrpNom,
													(void**)&FormaSpiskaSprGrpNom);
		FormaSpiskaSprGrpNom->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprGrpNom->Vibor=true;
		FormaSpiskaSprGrpNom->NumberProcVibor=ER_GrpNom;
		FormaSpiskaSprGrpNom->UpdateForm();
		}
}
//-----------------------------------------------------------------------------
void __fastcall TFormaElementaSprDiscountAuto::NameGrpNomcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprGrpNom();
		}break;
	case 1:
		{
		DM->Element->Edit();
		DM->ElementNAMEGN->Clear();
		DM->ElementIDGRPNOM_SDISCOUNT_AUTO->Clear();
		DM->Element->Post();
		}break;
	}
}
//---------------------------------------------------------------------------
void TFormaElementaSprDiscountAuto::EndViborGrpNom(void)
{

	DM->Element->Edit();
	DM->ElementIDGRPNOM_SDISCOUNT_AUTO->AsString=FormaSpiskaSprGrpNom->DMGrp->ElementIDGN->AsString;
	DM->ElementNAMEGN->AsString=FormaSpiskaSprGrpNom->DMGrp->ElementNAMEGN->AsString;
	DM->Element->Post();

}
//-----------------------------------------------------------------------------
