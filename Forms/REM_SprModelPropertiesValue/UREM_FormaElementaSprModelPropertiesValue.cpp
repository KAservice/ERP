//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UREM_FormaElementaSprModelPropertiesValue.h"
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
__fastcall TREM_FormaElementaSprModelPropertiesValue::TREM_FormaElementaSprModelPropertiesValue(TComponent* Owner)
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
bool TREM_FormaElementaSprModelPropertiesValue::Init(void)
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


InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprModelPropertiesValue,IID_IREM_DMSprModelPropertiesValue,
											 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

NamePropcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NamePropValueListcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
ValueTextcxDBMemo->DataBinding->DataSource=DM->DataSourceElement;





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
int TREM_FormaElementaSprModelPropertiesValue::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TREM_FormaElementaSprModelPropertiesValue::UpdateForm(void)
{

}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprModelPropertiesValue::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprProperties)FormaSpiskaSprProperties->kanRelease();
if(FormaSpiskaSprPropertiesValuesList)FormaSpiskaSprPropertiesValuesList->kanRelease();

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





void __fastcall TREM_FormaElementaSprModelPropertiesValue::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprModelPropertiesValue::ActionOKExecute(TObject *Sender)
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
int TREM_FormaElementaSprModelPropertiesValue::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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

		if (number_procedure_end==ER_ViborPropertiesValue)
				{
				if (type_event==1)
					{
					EndViborPropertiesValue();
					}
				FormaSpiskaSprPropertiesValuesList=0;
				}

FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//-----------------------------------------------------------------------------

void TREM_FormaElementaSprModelPropertiesValue::OpenFormaSpiskaSprProperties(void)
{
if (FormaSpiskaSprProperties==0)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprProperties,IID_IFormaSpiskaSprProperties,
														(void**)&FormaSpiskaSprProperties);
		FormaSpiskaSprProperties->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprProperties->Vibor=true;
		FormaSpiskaSprProperties->NumberProcVibor=ER_ViborProperties;
		FormaSpiskaSprProperties->IdElement=glStrToInt64(DM->ElementIDPROP_REM_SMODEL_PROPVAL->AsString);
        FormaSpiskaSprProperties->UpdateForm();
		}


}
//-----------------------------------------------------------------------------
void TREM_FormaElementaSprModelPropertiesValue::EndViborProperties(void)
{
DM->Element->Edit();
DM->ElementIDPROP_REM_SMODEL_PROPVAL->AsString=
						FormaSpiskaSprProperties->DM->TableID_SPROP->AsString;
DM->ElementNAME_SPROP->AsString=
					FormaSpiskaSprProperties->DM->TableNAME_SPROP->AsString;
DM->Element->Post();


}
//-----------------------------------------------------------------------------
void TREM_FormaElementaSprModelPropertiesValue::OpenFormaSpiskaSprPropertiesValuesList(void)
{

if (FormaSpiskaSprPropertiesValuesList==0)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprPropertiesValuesList,IID_IFormaSpiskaSprPropertiesValuesList,
														(void**)&FormaSpiskaSprPropertiesValuesList);
		FormaSpiskaSprPropertiesValuesList->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprPropertiesValuesList->Vibor=true;
		FormaSpiskaSprPropertiesValuesList->NumberProcVibor=ER_ViborPropertiesValue;
		FormaSpiskaSprPropertiesValuesList->IdProp=glStrToInt64(DM->ElementIDPROP_REM_SMODEL_PROPVAL->AsString);
		FormaSpiskaSprPropertiesValuesList->UpdateForm();
		}

}
//-----------------------------------------------------------------------------
void TREM_FormaElementaSprModelPropertiesValue::EndViborPropertiesValue(void)
{
DM->Element->Edit();
DM->ElementIDPVL_REM_SMODEL_PROPVAL->AsString=
						FormaSpiskaSprPropertiesValuesList->DM->TableID_SPROPVALUELIST->AsString;
DM->ElementNAME_SPROPVALUELIST->AsString=
					FormaSpiskaSprPropertiesValuesList->DM->TableNAME_SPROPVALUELIST->AsString;

if (Trim(DM->ElementVALTEXT_REM_SMODEL_PROPVAL->AsString).Length()==0)
	{
	DM->ElementVALTEXT_REM_SMODEL_PROPVAL->AsString=
                       FormaSpiskaSprPropertiesValuesList->DM->TableNAME_SPROPVALUELIST->AsString;
	}
DM->Element->Post();
}
//-----------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprModelPropertiesValue::NamePropcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
OpenFormaSpiskaSprProperties();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprModelPropertiesValue::NamePropValueListcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
OpenFormaSpiskaSprPropertiesValuesList();
}
//---------------------------------------------------------------------------

