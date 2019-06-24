//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_FormaElementaSprNeisprModel.h"
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
__fastcall TREM_FormaElementaSprNeisprModel::TREM_FormaElementaSprNeisprModel(TComponent* Owner)
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
bool TREM_FormaElementaSprNeisprModel::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprNeisprModel,IID_IREM_DMSprNeisprModel,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);


NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NameNeisprcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
DescrcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NameModelNeisprcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;

DM_Connection->GetPrivForm(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_FormaElementaSprNeisprModel::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprNeisprModel::FormClose(TObject *Sender,
      TCloseAction &Action)
{

if (FormaSpiskaSprNeispr>0) FormaSpiskaSprNeispr->kanRelease();
if (FormaSpiskaSprDefectModelNeispr>0) FormaSpiskaSprDefectModelNeispr->kanRelease();
if (FormaSpiskaSprModel>0) FormaSpiskaSprModel->kanRelease();

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
void TREM_FormaElementaSprNeisprModel::UpdateForm(void)
{
//


}
//----------------------------------------------------------------------------

int TREM_FormaElementaSprNeisprModel::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

if ( number_procedure_end==VR_ViborNeispr)
	{
	if (type_event==1)
		{
		EndViborNeispr();
		}
	FormaSpiskaSprNeispr=0;
	}

if ( number_procedure_end==VR_ViborDefectModelNeispr)
	{
	if (type_event==1)
		{
		EndViborDefectModelNeispr();
		}
	FormaSpiskaSprDefectModelNeispr=0;
	}

if ( number_procedure_end==VR_Model)
	{
	if (type_event==1)
		{
		EndViborModel();
		}
	FormaSpiskaSprModel=0;
	}
return -1;
}
//-----------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprNeisprModel::ActionOpenHelpExecute(TObject *Sender)
{
//Application->HelpJump("Spr/SprEd");
}
//---------------------------------------------------------------------------






void __fastcall TREM_FormaElementaSprNeisprModel::ActionCloseExecute(TObject *Sender)

{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprNeisprModel::ActionOKExecute(TObject *Sender)

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
void TREM_FormaElementaSprNeisprModel::ViborNeispr(void)
{
if (FormaSpiskaSprNeispr>0) return;

InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprNeispr,IID_IREM_FormaSpiskaSprNeispr,
												 (void**)&FormaSpiskaSprNeispr);
FormaSpiskaSprNeispr->Init(InterfaceMainObject,InterfaceImpl);
FormaSpiskaSprNeispr->Vibor=true;
FormaSpiskaSprNeispr->NumberProcVibor=VR_ViborNeispr;
//FormaSpiskaSprNeispr->IdElement=glStrToInt64(DM->ElementIDNEISPR_REM_SNEISPRMODEL->AsString);
FormaSpiskaSprNeispr->UpdateForm();

}
//--------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprNeisprModel::EndViborNeispr(void)
{

	DM->Element->Edit();
	DM->ElementIDNEISPR_REM_SNEISPMODEL->AsString=FormaSpiskaSprNeispr->DM->TableID_REM_SNEISPR->AsString;
	DM->ElementNAME_REM_SNEISPR->AsString=FormaSpiskaSprNeispr->DM->TableNAME_REM_SNEISPR->AsString;
	DM->Element->Post();

}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprNeisprModel::NameNomcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborNeispr();
}
//---------------------------------------------------------------------------
void TREM_FormaElementaSprNeisprModel::ViborDefectModelNeispr(void)
{
if (FormaSpiskaSprDefectModelNeispr>0) return;

InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprDefectModelNeispr,IID_IREM_FormaSpiskaSprDefectModelNeispr,
												 (void**)&FormaSpiskaSprDefectModelNeispr);
FormaSpiskaSprDefectModelNeispr->Init(InterfaceMainObject,InterfaceImpl);
FormaSpiskaSprDefectModelNeispr->Vibor=false;
FormaSpiskaSprDefectModelNeispr->NumberProcVibor=VR_ViborDefectModelNeispr;
FormaSpiskaSprDefectModelNeispr->IdModelNeispr=glStrToInt64(DM->ElementID_REM_SNEISPMODEL->AsString);
//FormaSpiskaSprNeispr->IdElement=glStrToInt64(DM->ElementIDNEISPR_REM_SNEISPRMODEL->AsString);
FormaSpiskaSprDefectModelNeispr->UpdateForm();

}
//--------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprNeisprModel::EndViborDefectModelNeispr(void)
{

///

}
//--------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprNeisprModel::cxButtonDefectClick(TObject *Sender)

{
ViborDefectModelNeispr();
}
//---------------------------------------------------------------------------
void TREM_FormaElementaSprNeisprModel::ViborModel(void)
{
if (FormaSpiskaSprModel>0) return;

InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprModel,IID_IREM_FormaSpiskaSprModel,
												 (void**)&FormaSpiskaSprModel);
FormaSpiskaSprModel->Init(InterfaceMainObject,InterfaceImpl);
FormaSpiskaSprModel->Vibor=true;
FormaSpiskaSprModel->NumberProcVibor=VR_Model;
FormaSpiskaSprModel->IdModel=glStrToInt64(DM->ElementIDMODELNEISPR_REM_SNEISPMODEL->AsString);
FormaSpiskaSprModel->UpdateForm();

}
//--------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprNeisprModel::EndViborModel(void)
{

	DM->Element->Edit();
	DM->ElementIDMODELNEISPR_REM_SNEISPMODEL->AsString=FormaSpiskaSprModel->DM->TableID_REM_SMODEL->AsString;
	DM->ElementNAME_REM_SMODEL->AsString=FormaSpiskaSprModel->DM->TableNAME_REM_SMODEL->AsString;
	DM->Element->Post();

}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprNeisprModel::NameModelNeisprcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborModel();
}
//---------------------------------------------------------------------------

