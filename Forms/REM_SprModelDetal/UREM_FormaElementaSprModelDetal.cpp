//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_FormaElementaSprModelDetal.h"
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
__fastcall TREM_FormaElementaSprModelDetal::TREM_FormaElementaSprModelDetal(TComponent* Owner)
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
bool TREM_FormaElementaSprModelDetal::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprModelDetal,IID_IREM_DMSprModelDetal,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

PartNumbercxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
KolcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
DescrcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NameNomcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
CodeNomcxDBLabel->DataBinding->DataSource=DM->DataSourceElement;
ArtikulNomcxDBLabel->DataBinding->DataSource=DM->DataSourceElement;
NameProducerNomcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
CodePrNomcxDBLabel->DataBinding->DataSource=DM->DataSourceElement;
ArtikulPrNomcxDBLabel->DataBinding->DataSource=DM->DataSourceElement;
NameTypUslacxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;


DM_Connection->GetPrivForm(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_FormaElementaSprModelDetal::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprModelDetal::FormClose(TObject *Sender,
      TCloseAction &Action)
{

if (FormaSpiskaSprNom>0) FormaSpiskaSprNom->kanRelease();
if (FormaSpiskaSprTypUslov>0) FormaSpiskaSprTypUslov->kanRelease();
if (FormaSpiskaSprProducerNom>0) FormaSpiskaSprProducerNom->kanRelease();

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
void TREM_FormaElementaSprModelDetal::UpdateForm(void)
{
//


}
//----------------------------------------------------------------------------

int TREM_FormaElementaSprModelDetal::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

if ( number_procedure_end==VR_ViborNom)
	{
	if (type_event==1)
		{
		EndViborNom();
		}
	FormaSpiskaSprNom=0;
	}


if ( number_procedure_end==VR_ViborTypUsla)
	{
	if (type_event==1)
		{
		EndViborTypUsla();
		}
	FormaSpiskaSprTypUslov=0;
	}

if ( number_procedure_end==VR_ViborProducerNom)
	{
	if (type_event==1)
		{
		EndViborProducerNom();
		}
	FormaSpiskaSprProducerNom=0;
	}

return -1;
}
//-----------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprModelDetal::ActionOpenHelpExecute(TObject *Sender)
{
//Application->HelpJump("Spr/SprEd");
}
//---------------------------------------------------------------------------






void __fastcall TREM_FormaElementaSprModelDetal::ActionCloseExecute(TObject *Sender)

{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprModelDetal::ActionOKExecute(TObject *Sender)

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
void TREM_FormaElementaSprModelDetal::ViborNom(void)
{
if (FormaSpiskaSprNom>0) return;

InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
												 (void**)&FormaSpiskaSprNom);
FormaSpiskaSprNom->Init(InterfaceMainObject,InterfaceImpl);
FormaSpiskaSprNom->Vibor=true;
FormaSpiskaSprNom->NumberProcVibor=VR_ViborNom;
FormaSpiskaSprNom->IdNom=glStrToInt64(DM->ElementIDNOM_REM_SMODEL_DETAL->AsString);
FormaSpiskaSprNom->UpdateForm();

}
//--------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprModelDetal::EndViborNom(void)
{

	DM->Element->Edit();
	DM->ElementIDNOM_REM_SMODEL_DETAL->AsString=FormaSpiskaSprNom->DM->TableIDNOM->AsString;
	DM->ElementNAMENOM->AsString=FormaSpiskaSprNom->DM->TableNAMENOM->AsString;
	DM->Element->Post();

}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprModelDetal::NameNomcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{

switch (AButtonIndex)
	{
	case 0:
		{
		ViborNom();
		}break;
	case 1:
		{
		DM->Element->Edit();
		DM->ElementIDNOM_REM_SMODEL_DETAL->Clear();
		DM->Element->Post();
		}break;
	}
}
//---------------------------------------------------------------------------
void TREM_FormaElementaSprModelDetal::ViborTypUsla(void)
{
if (FormaSpiskaSprTypUslov>0) return;

InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprTypUslov,IID_IREM_FormaSpiskaSprTypUslov,
												 (void**)&FormaSpiskaSprTypUslov);
FormaSpiskaSprTypUslov->Init(InterfaceMainObject,InterfaceImpl);
FormaSpiskaSprTypUslov->flVibor=true;
FormaSpiskaSprTypUslov->NumberProcVibor=VR_ViborTypUsla;
FormaSpiskaSprTypUslov->IdElement=glStrToInt64(DM->ElementIDTYPUSLA_REM_SMODEL_DETAL->AsString);
FormaSpiskaSprTypUslov->UpdateForm();

}
//--------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprModelDetal::EndViborTypUsla(void)
{

	DM->Element->Edit();
	DM->ElementIDTYPUSLA_REM_SMODEL_DETAL->AsString=FormaSpiskaSprTypUslov->DM->TableID_REM_STYPUSLOV->AsString;
	DM->ElementNAME_REM_STYPUSLOV->AsString=FormaSpiskaSprTypUslov->DM->TableNAME_REM_STYPUSLOV->AsString;
	DM->Element->Post();

}
///-------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprModelDetal::NameTypUslacxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{

switch (AButtonIndex)
	{
	case 0:
		{
		ViborTypUsla();
		}break;
	case 1:
		{
		DM->Element->Edit();
		DM->ElementIDTYPUSLA_REM_SMODEL_DETAL->Clear();
		DM->Element->Post();
		}break;
	}
}
//---------------------------------------------------------------------------
void TREM_FormaElementaSprModelDetal::ViborProducerNom(void)
{
if (FormaSpiskaSprProducerNom>0) return;

InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprProducerNom,IID_IFormaSpiskaSprProducerNom,
												 (void**)&FormaSpiskaSprProducerNom);
FormaSpiskaSprProducerNom->Init(InterfaceMainObject,InterfaceImpl);
FormaSpiskaSprProducerNom->Vibor=true;
FormaSpiskaSprProducerNom->NumberProcVibor=VR_ViborProducerNom;
//FormaSpiskaSprProducerNom->IdNom=glStrToInt64(DM->ElementIDPRNOM_REM_SMODEL_DETAL->AsString);
//FormaSpiskaSprProducerNom->IdGroupElement=glStrToInt64(DM->ElementIDPRNOM_REM_SMODEL_DETAL->AsString);
FormaSpiskaSprProducerNom->UpdateForm();

}
//--------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprModelDetal::EndViborProducerNom(void)
{

	DM->Element->Edit();
	DM->ElementIDPRNOM_REM_SMODEL_DETAL->AsString=FormaSpiskaSprProducerNom->DM->TableID_SPRNOM->AsString;
	DM->ElementNAME_SPRNOM->AsString=FormaSpiskaSprProducerNom->DM->TableNAME_SPRNOM->AsString;
	DM->Element->Post();

}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprModelDetal::NameProducerNomcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborProducerNom();
		}break;
	case 1:
		{
		DM->Element->Edit();
		DM->ElementIDPRNOM_REM_SMODEL_DETAL->Clear();
		DM->Element->Post();
		}break;
	}
}
//---------------------------------------------------------------------------


