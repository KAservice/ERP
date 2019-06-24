//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UREM_FormaElementaSprProducerRabota.h"
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
#pragma link "cxDropDownEdit"
#pragma link "cxImageComboBox"
#pragma link "cxSpinEdit"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TREM_FormaElementaSprProducerRabota::TREM_FormaElementaSprProducerRabota(TComponent* Owner)
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
bool TREM_FormaElementaSprProducerRabota::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprProducerRabota,IID_IREM_DMSprProducerRabota, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);



IdcxDBLabel->DataBinding->DataSource=DM->DataSourceElement;
NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NameEngcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;

cxDBTextEditCODE_REM_SPRRABOTA->DataBinding->DataSource=DM->DataSourceElement;
cxDBSpinEditLEVEL_REM_SPRRABOTA->DataBinding->DataSource=DM->DataSourceElement;
cxDBTextEditLEVEL_STR_REM_SPRRABOTA->DataBinding->DataSource=DM->DataSourceElement;
cxDBImageComboBoxTYPECLIENT_REM_SPRRABOTA->DataBinding->DataSource=DM->DataSourceElement;
cxDBImageComboBoxTYPEPRODUCT_REM_SPRRABOTA->DataBinding->DataSource=DM->DataSourceElement;
cxDBButtonEditNAMENOM->DataBinding->DataSource=DM->DataSourceElement;


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
int TREM_FormaElementaSprProducerRabota::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TREM_FormaElementaSprProducerRabota::UpdateForm(void)
{



}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprProducerRabota::FormClose(TObject *Sender,
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
void __fastcall TREM_FormaElementaSprProducerRabota::ActionOpenHelpExecute(
      TObject *Sender)
{
//
}
//---------------------------------------------------------------------------



void __fastcall TREM_FormaElementaSprProducerRabota::NamecxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprProducerRabota::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprProducerRabota::ActionOKExecute(TObject *Sender)
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
int TREM_FormaElementaSprProducerRabota::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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
void TREM_FormaElementaSprProducerRabota::ViborNom(void)
{
if (FormaSpiskaSprNom>0) return;

InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprNom,IID_IFormaSpiskaSprNom,
												 (void**)&FormaSpiskaSprNom);
FormaSpiskaSprNom->Init(InterfaceMainObject,InterfaceImpl);
FormaSpiskaSprNom->Vibor=true;
FormaSpiskaSprNom->NumberProcVibor=VR_Nom;
FormaSpiskaSprNom->IdNom=glStrToInt64(DM->ElementIDNOM_REM_SPRRABOTA->AsString);
FormaSpiskaSprNom->UpdateForm();

}
//--------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprProducerRabota::EndViborNom(void)
{

	DM->Element->Edit();
	DM->ElementIDNOM_REM_SPRRABOTA->AsString=FormaSpiskaSprNom->DM->TableIDNOM->AsString;
	DM->ElementNAMENOM->AsString=FormaSpiskaSprNom->DM->TableNAMENOM->AsString;
	DM->Element->Post();

}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprProducerRabota::cxDBButtonEditNAMENOMPropertiesButtonClick(TObject *Sender,
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
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->Element->Edit();
		DM->ElementIDNOM_REM_SPRRABOTA->Clear();
		DM->Element->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

