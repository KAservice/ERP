//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaTableExtPrintForm.h"
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
#pragma link "cxDropDownEdit"
#pragma link "cxGraphics"
#pragma link "cxImageComboBox"
#pragma link "cxLabel"
#pragma link "cxGroupBox"
#pragma link "cxRadioGroup"
#pragma link "cxCheckGroup"
#pragma link "cxDBCheckGroup"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaElementaTableExtPrintForm::TFormaElementaTableExtPrintForm(TComponent* Owner)
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
bool TFormaElementaTableExtPrintForm::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

ObjectcxDBImageComboBox->DataBinding->DataSource=DM->DataSourceElement;
NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
FileNamecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
TypeModulecxDBImageComboBox->DataBinding->DataSource=DM->DataSourceElement;
cxDBRadioGroupResidence->DataBinding->DataSource=DM->DataSourceElement;
NameModulecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;

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
int TFormaElementaTableExtPrintForm::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaTableExtPrintForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{

if(SpisokProgramModule) SpisokProgramModule->kanRelease();

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
}
//---------------------------------------------------------------------------
void TFormaElementaTableExtPrintForm::UpdateForm(void)
{



}
//---------------------------------------------------------------------------



void __fastcall TFormaElementaTableExtPrintForm::FileNamecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if(OpenDialog1->Execute())
		{
		DM->Element->Edit();
		DM->ElementFILE_NAME_EXTPRINT_FORM->AsString=OpenDialog1->FileName;
		DM->Element->Post();
		}
}
//---------------------------------------------------------------------------


void __fastcall TFormaElementaTableExtPrintForm::cxButtonFileInBlobClick(
      TObject *Sender)
{
if(OpenDialog1->Execute())
		{
		DM->Element->Edit();
		DM->ElementBODY_EXTPRINT_FORM->LoadFromFile(OpenDialog1->FileName);
		DM->Element->Post();
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaTableExtPrintForm::ActionCloseExecute(TObject *Sender)

{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaTableExtPrintForm::ActionOKExecute(TObject *Sender)

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
int TFormaElementaTableExtPrintForm::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{


if (number_procedure_end==ER_ProgramModule)
		{
		if (type_event==1)
				{
				EndViborProgramModule();
				}
		SpisokProgramModule=0;
		}


return -1;
}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaTableExtPrintForm::cxButtonBlobInFileClick(TObject *Sender)

{
if(SaveDialog1->Execute())
		{
		DM->ElementBODY_EXTPRINT_FORM->SaveToFile(SaveDialog1->FileName);
		}
}
//---------------------------------------------------------------------------
void TFormaElementaTableExtPrintForm::ViborProgramModule(void)
{
if (SpisokProgramModule==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprProgramModule,IID_IFormaSpiskaSprProgramModule,
													(void**)&SpisokProgramModule);
		SpisokProgramModule->Init(InterfaceMainObject,InterfaceImpl);
		SpisokProgramModule->Vibor=true;
		SpisokProgramModule->NumberProcVibor=ER_ProgramModule;
		}

}
//---------------------------------------------------------------------------
void TFormaElementaTableExtPrintForm::EndViborProgramModule(void)
{

	DM->Element->Edit();
	DM->ElementGUID_OB_EXTPRINT_FORM->AsString=SpisokProgramModule->DM->TableGUID_PROGRAM_MODULE->AsString;
	DM->ElementNAME_PROGRAM_MODULE->AsString=SpisokProgramModule->DM->TableNAME_PROGRAM_MODULE->AsString;
	DM->Element->Post();
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaTableExtPrintForm::NameModulecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborProgramModule();
}
//---------------------------------------------------------------------------

