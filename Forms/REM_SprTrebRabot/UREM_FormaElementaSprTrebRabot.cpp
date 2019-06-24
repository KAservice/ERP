//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_FormaElementaSprTrebRabot.h"
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
__fastcall TREM_FormaElementaSprTrebRabot::TREM_FormaElementaSprTrebRabot(TComponent* Owner)
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
bool TREM_FormaElementaSprTrebRabot::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprTrebRabot,IID_IREM_DMSprTrebRabot,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);


NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NameTypRabotcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;



DM_Connection->GetPrivForm(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_FormaElementaSprTrebRabot::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprTrebRabot::FormClose(TObject *Sender,
      TCloseAction &Action)
{

if (FormaSpiskaSprTypRabot>0) FormaSpiskaSprTypRabot->kanRelease();


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
void TREM_FormaElementaSprTrebRabot::UpdateForm(void)
{
//


}
//----------------------------------------------------------------------------

int TREM_FormaElementaSprTrebRabot::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

if ( number_procedure_end==VR_ViborTypRabot)
	{
	if (type_event==1)
		{
		EndViborTypRabot();
		}
	FormaSpiskaSprTypRabot=0;
	}
return -1;
}
//-----------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprTrebRabot::ActionOpenHelpExecute(TObject *Sender)
{
//Application->HelpJump("Spr/SprEd");
}
//---------------------------------------------------------------------------






void __fastcall TREM_FormaElementaSprTrebRabot::ActionCloseExecute(TObject *Sender)

{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprTrebRabot::ActionOKExecute(TObject *Sender)

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
void TREM_FormaElementaSprTrebRabot::ViborTypRabot(void)
{
if (FormaSpiskaSprTypRabot>0) return;

InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprTypRabot,IID_IREM_FormaSpiskaSprTypRabot,
												 (void**)&FormaSpiskaSprTypRabot);
FormaSpiskaSprTypRabot->Init(InterfaceMainObject,InterfaceImpl);
FormaSpiskaSprTypRabot->flVibor=true;
FormaSpiskaSprTypRabot->NumberProcVibor=VR_ViborTypRabot;
FormaSpiskaSprTypRabot->IdElement=glStrToInt64(DM->ElementIDTYPRABOT_REM_STREBRABOT->AsString);
FormaSpiskaSprTypRabot->UpdateForm();

}
//--------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprTrebRabot::EndViborTypRabot(void)
{

	DM->Element->Edit();
	DM->ElementIDTYPRABOT_REM_STREBRABOT->AsString=FormaSpiskaSprTypRabot->DM->TableID_REM_STYPRABOT->AsString;
	DM->ElementNAME_REM_STYPRABOT->AsString=FormaSpiskaSprTypRabot->DM->TableNAME_REM_STYPRABOT->AsString;
	DM->Element->Post();

}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprTrebRabot::NameNomcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborTypRabot();
}
//---------------------------------------------------------------------------

