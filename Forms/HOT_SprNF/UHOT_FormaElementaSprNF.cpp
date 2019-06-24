//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UHOT_FormaElementaSprNF.h"
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
#pragma link "cxDBEdit"
#pragma link "cxEdit"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxTextEdit"
#pragma link "cxButtonEdit"
#pragma link "cxMaskEdit"
#pragma link "cxCalc"
#pragma link "cxCalendar"
#pragma link "cxDropDownEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall THOT_FormaElementaSprNF::THOT_FormaElementaSprNF(TComponent* Owner)
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
bool THOT_FormaElementaSprNF::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMSprNF.1",IID_IHOT_DMSprNF,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NameCatNomcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameObjectcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
KolMestcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;
PosIncxDBDateEdit->DataBinding->DataSource=DM->DataSourceElement;
PosOutcxDBDateEdit->DataBinding->DataSource=DM->DataSourceElement;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int THOT_FormaElementaSprNF::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaElementaSprNF::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if (HOT_FormaSpiskaSprCatNom>0) HOT_FormaSpiskaSprCatNom->kanRelease();
if(HOT_FormaSpiskaSprObject>0) HOT_FormaSpiskaSprObject->kanRelease();

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
int THOT_FormaElementaSprNF::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ER_Cat)
	{
	if(type_event==1)
		{
		EndViborCatNom();
		}
	HOT_FormaSpiskaSprCatNom=0;
	}

if (number_procedure_end==ER_Object)
	{
	if(type_event==1)
		{
		EndViborObject();
		}
	HOT_FormaSpiskaSprObject=0;
	}
return -1;
}
//-------------------------------------------------------------------------
void THOT_FormaElementaSprNF::UpdateForm(void)
{
//


}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaElementaSprNF::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("Hotel/Spr/SprNF");
}
//---------------------------------------------------------------------------




void __fastcall THOT_FormaElementaSprNF::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborCatNom();
}
//---------------------------------------------------------------------------
void THOT_FormaElementaSprNF::ViborCatNom(void)
{
if (HOT_FormaSpiskaSprCatNom>0) return;

InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprCatNom.1",IID_IHOT_FormaSpiskaSprCatNom,
												 (void**)&HOT_FormaSpiskaSprCatNom);
HOT_FormaSpiskaSprCatNom->Init(InterfaceMainObject,InterfaceImpl);
if (!HOT_FormaSpiskaSprCatNom) return;
//настройка формы
HOT_FormaSpiskaSprCatNom->Vibor=true;
HOT_FormaSpiskaSprCatNom->NumberProcVibor=ER_Cat;

}
//--------------------------------------------------------------------------
void __fastcall THOT_FormaElementaSprNF::EndViborCatNom(void)
{

	DM->Element->Edit();
	DM->ElementIDCAT_HOT_SNF->AsInt64=HOT_FormaSpiskaSprCatNom->DM->TableID_HOT_SCATNOM->AsInt64;
	DM->ElementNAME_HOT_SCATNOM->AsString=HOT_FormaSpiskaSprCatNom->DM->TableNAME_HOT_SCATNOM->AsString;
	DM->Element->Post();

}
//---------------------------------------------------------------------------
void THOT_FormaElementaSprNF::ViborObject(void)
{
if (HOT_FormaSpiskaSprObject>0) return;

InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprObject.1",IID_IHOT_FormaSpiskaSprObject,
												 (void**)&HOT_FormaSpiskaSprObject);
HOT_FormaSpiskaSprObject->Init(InterfaceMainObject,InterfaceImpl);
if (!HOT_FormaSpiskaSprObject) return;
//настройка формы
HOT_FormaSpiskaSprObject->Vibor=true;
HOT_FormaSpiskaSprObject->NumberProcVibor=ER_Object;


}
//--------------------------------------------------------------------------
void __fastcall THOT_FormaElementaSprNF::EndViborObject(void)
{

	DM->Element->Edit();
	DM->ElementIDOB_HOT_SNF->AsInt64=HOT_FormaSpiskaSprObject->DM->TableID_HOT_SOBJECT->AsInt64;
	DM->ElementNAME_HOT_SOBJECT->AsString=HOT_FormaSpiskaSprObject->DM->TableNAME_HOT_SOBJECT->AsString;
	DM->Element->Post();

}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaElementaSprNF::NameObjectcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborObject();
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaElementaSprNF::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaElementaSprNF::ActionOKExecute(TObject *Sender)
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

