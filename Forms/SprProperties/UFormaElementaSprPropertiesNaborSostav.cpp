//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprPropertiesNaborSostav.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxButtonEdit"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxCalc"
#pragma link "cxDropDownEdit"
#pragma link "cxGraphics"
#pragma link "cxImageComboBox"
#pragma link "cxLookAndFeels"
#pragma link "cxDBRichEdit"
#pragma link "cxMemo"
#pragma link "cxRichEdit"
#pragma link "cxSpinEdit"
#pragma link "cxCheckBox"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaElementaSprPropertiesNaborSostav::TFormaElementaSprPropertiesNaborSostav(TComponent* Owner)
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
bool TFormaElementaSprPropertiesNaborSostav::Init(void)
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


InterfaceGlobalCom->kanCreateObject(ProgId_DMSprPropertiesNaborSostav,IID_IDMSprPropertiesNaborSostav,
											 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

NamePropcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
IndexcxDBSpinEdit->DataBinding->DataSource=DM->DataSourceElement;

Add1cxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;
Add2cxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;
Add3cxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;
Add4cxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;
Add5cxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;

//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;
return result;
}
//----------------------------------------------------------------------------
int TFormaElementaSprPropertiesNaborSostav::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaElementaSprPropertiesNaborSostav::UpdateForm(void)
{

}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprPropertiesNaborSostav::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprProperties)FormaSpiskaSprProperties->kanRelease();

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


void __fastcall TFormaElementaSprPropertiesNaborSostav::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprNomPropertiesValue");
}
//---------------------------------------------------------------------------



void __fastcall TFormaElementaSprPropertiesNaborSostav::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprPropertiesNaborSostav::ActionOKExecute(TObject *Sender)
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
int TFormaElementaSprPropertiesNaborSostav::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

		if (number_procedure_end==ER_ViborProperties)
				{
				if (type_event==1)
					{
					EndViborProperties();
					}
				FormaSpiskaSprProperties=0;
				}


FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//-----------------------------------------------------------------------------

void TFormaElementaSprPropertiesNaborSostav::OpenFormaSpiskaSprProperties(void)
{
if (FormaSpiskaSprProperties==0)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprProperties,IID_IFormaSpiskaSprProperties,
														(void**)&FormaSpiskaSprProperties);
		FormaSpiskaSprProperties->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprProperties->Vibor=true;
		FormaSpiskaSprProperties->NumberProcVibor=ER_ViborProperties;
		FormaSpiskaSprProperties->IdElement=glStrToInt64(DM->ElementIDPROPNABOR_SPROPNABOR_SOST->AsString);
        FormaSpiskaSprProperties->UpdateForm();
		}


}
//-----------------------------------------------------------------------------
void TFormaElementaSprPropertiesNaborSostav::EndViborProperties(void)
{
DM->Element->Edit();
DM->ElementIDPROP_SPROPNABOR_SOST->AsString=
						FormaSpiskaSprProperties->DM->TableID_SPROP->AsString;
DM->ElementNAME_SPROP->AsString=
					FormaSpiskaSprProperties->DM->TableNAME_SPROP->AsString;
DM->Element->Post();


}
//-----------------------------------------------------------------------------

void __fastcall TFormaElementaSprPropertiesNaborSostav::NamePropcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
OpenFormaSpiskaSprProperties();
}
//---------------------------------------------------------------------------


