//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UREM_FormaElementaSprTypRabot.h"
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
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma link "cxButtonEdit"
#pragma link "cxDBLabel"
#pragma link "cxLabel"
#pragma link "cxMaskEdit"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TREM_FormaElementaSprTypRabot::TREM_FormaElementaSprTypRabot(TComponent* Owner)
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
bool TREM_FormaElementaSprTypRabot::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprTypRabot,IID_IREM_DMSprTypRabot, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);



IdcxDBLabel->DataBinding->DataSource=DM->DataSourceElement;
NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NameNomcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
DescrcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NameEngcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
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
int TREM_FormaElementaSprTypRabot::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TREM_FormaElementaSprTypRabot::UpdateForm(void)
{



}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprTypRabot::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if (FormaSpiskaSprNom>0) FormaSpiskaSprNom->kanRelease();



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
void __fastcall TREM_FormaElementaSprTypRabot::ActionOpenHelpExecute(
      TObject *Sender)
{
//
}
//---------------------------------------------------------------------------



void __fastcall TREM_FormaElementaSprTypRabot::NamecxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprTypRabot::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprTypRabot::ActionOKExecute(TObject *Sender)
{
if (DM->SaveElement()==true)
		{
		TypeEvent=1;
		Close();
		}
else
	{
	ShowMessage("Ошибка при записи элемента справочника: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------
int TREM_FormaElementaSprTypRabot::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

if ( number_procedure_end==VR_Nom)
	{
	if (type_event==1)
		{
		EndViborNom();
		}
	FormaSpiskaSprNom=0;
	}
return -1;
}
//---------------------------------------------------------------------------
void TREM_FormaElementaSprTypRabot::ViborNom(void)
{
if (FormaSpiskaSprNom>0) return;

InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
												 (void**)&FormaSpiskaSprNom);
FormaSpiskaSprNom->Init(InterfaceMainObject,InterfaceImpl);
FormaSpiskaSprNom->Vibor=true;
FormaSpiskaSprNom->NumberProcVibor=VR_Nom;
FormaSpiskaSprNom->IdNom=glStrToInt64(DM->ElementIDNOM_REM_STYPRABOT->AsString);
FormaSpiskaSprNom->UpdateForm();

}
//--------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprTypRabot::EndViborNom(void)
{

	DM->Element->Edit();
	DM->ElementIDNOM_REM_STYPRABOT->AsString=FormaSpiskaSprNom->DM->TableIDNOM->AsString;
	DM->ElementNAMENOM->AsString=FormaSpiskaSprNom->DM->TableNAMENOM->AsString;
	DM->ElementNAME_REM_STYPRABOT->AsString=FormaSpiskaSprNom->DM->TableNAMENOM->AsString;
	DM->Element->Post();

}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprTypRabot::NameNomcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborNom();
}
//---------------------------------------------------------------------------

