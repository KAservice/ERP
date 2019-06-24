//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_FormaElementaSprDefectModelNeispr.h"
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
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma link "cxButtonEdit"
#pragma link "cxDBLabel"
#pragma link "cxLabel"
#pragma link "cxMaskEdit"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TREM_FormaElementaSprDefectModelNeispr::TREM_FormaElementaSprDefectModelNeispr(TComponent* Owner)
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
bool TREM_FormaElementaSprDefectModelNeispr::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprDefectModelNeispr,IID_IREM_DMSprDefectModelNeispr,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);


NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NameTypDefectcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
DescrcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
CodeTypDefectcxDBLabel->DataBinding->DataSource=DM->DataSourceElement;

DM_Connection->GetPrivForm(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_FormaElementaSprDefectModelNeispr::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprDefectModelNeispr::FormClose(TObject *Sender,
      TCloseAction &Action)
{

if (FormaSpiskaSprTypDefect>0) FormaSpiskaSprTypDefect->kanRelease();
if (FormaSpiskaSprTrebRabot>0) FormaSpiskaSprTrebRabot->kanRelease();
if (FormaSpiskaSprTrebUslov>0) FormaSpiskaSprTrebUslov->kanRelease();

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
//----------------------------------------------------------------------------
void TREM_FormaElementaSprDefectModelNeispr::UpdateForm(void)
{
//


}
//----------------------------------------------------------------------------

int TREM_FormaElementaSprDefectModelNeispr::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

if ( number_procedure_end==VR_ViborTypDefect)
	{
	if (type_event==1)
		{
		EndViborTypDefect();
		}
	FormaSpiskaSprTypDefect=0;
	}

if ( number_procedure_end==VR_ViborTrebRabot)
	{
	if (type_event==1)
		{
		EndViborTrebRabot();
		}
	FormaSpiskaSprTrebRabot=0;
	}

if ( number_procedure_end==VR_ViborTrebUslov)
	{
	if (type_event==1)
		{
		EndViborTrebUslov();
		}
	FormaSpiskaSprTrebUslov=0;
	}
return -1;
}
//-----------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprDefectModelNeispr::ActionOpenHelpExecute(TObject *Sender)
{
//Application->HelpJump("Spr/SprEd");
}
//---------------------------------------------------------------------------






void __fastcall TREM_FormaElementaSprDefectModelNeispr::ActionCloseExecute(TObject *Sender)

{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprDefectModelNeispr::ActionOKExecute(TObject *Sender)

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
void TREM_FormaElementaSprDefectModelNeispr::ViborTypDefect(void)
{
if (FormaSpiskaSprTypDefect>0) return;

InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprTypDefect,IID_IREM_FormaSpiskaSprTypDefect,
												 (void**)&FormaSpiskaSprTypDefect);
FormaSpiskaSprTypDefect->Init(InterfaceMainObject,InterfaceImpl);
FormaSpiskaSprTypDefect->flVibor=true;
FormaSpiskaSprTypDefect->NumberProcVibor=VR_ViborTypDefect;
FormaSpiskaSprTypDefect->IdElement=glStrToInt64(DM->ElementIDTDEF_REM_SDEFECT_MODNE->AsString);
FormaSpiskaSprTypDefect->UpdateForm();

}
//--------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprDefectModelNeispr::EndViborTypDefect(void)
{

	DM->Element->Edit();
	DM->ElementIDTDEF_REM_SDEFECT_MODNE->AsString=FormaSpiskaSprTypDefect->DM->TableID_REM_STYPDEFECT->AsString;
	DM->ElementNAME_REM_STYPDEFECT->AsString=FormaSpiskaSprTypDefect->DM->TableNAME_REM_STYPDEFECT->AsString;
	DM->Element->Post();

}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprDefectModelNeispr::NameNomcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborTypDefect();
}
//---------------------------------------------------------------------------
void TREM_FormaElementaSprDefectModelNeispr::ViborTrebRabot(void)
{
if (FormaSpiskaSprTrebRabot>0) return;

InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprTrebRabot,IID_IREM_FormaSpiskaSprTrebRabot,
												 (void**)&FormaSpiskaSprTrebRabot);
FormaSpiskaSprTrebRabot->Init(InterfaceMainObject,InterfaceImpl);
FormaSpiskaSprTrebRabot->IdDefectModelNeispr=glStrToInt64(DM->ElementID_REM_SDEFECT_MODNE->AsString);
FormaSpiskaSprTrebRabot->NumberProcVibor=VR_ViborTrebRabot;
FormaSpiskaSprTrebRabot->UpdateForm();

}
//--------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprDefectModelNeispr::EndViborTrebRabot(void)
{
//

}
//-----------------------------------------------------------------------------
void TREM_FormaElementaSprDefectModelNeispr::ViborTrebUslov(void)
{
if (FormaSpiskaSprTrebUslov>0) return;

InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprTrebUslov,IID_IREM_FormaSpiskaSprTrebUslov,
												 (void**)&FormaSpiskaSprTrebUslov);
FormaSpiskaSprTrebUslov->Init(InterfaceMainObject,InterfaceImpl);
FormaSpiskaSprTrebUslov->IdDefectModelNeispr=glStrToInt64(DM->ElementID_REM_SDEFECT_MODNE->AsString);
FormaSpiskaSprTrebUslov->NumberProcVibor=VR_ViborTrebUslov;
FormaSpiskaSprTrebUslov->UpdateForm();

}
//--------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprDefectModelNeispr::EndViborTrebUslov(void)
{
//

}
//-----------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprDefectModelNeispr::cxButtonTrebUslovClick(TObject *Sender)

{
ViborTrebUslov();
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaElementaSprDefectModelNeispr::cxButtonTrebRabotClick(TObject *Sender)

{
ViborTrebRabot();
}
//---------------------------------------------------------------------------

