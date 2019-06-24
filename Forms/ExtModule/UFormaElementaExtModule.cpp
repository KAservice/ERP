//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaExtModule.h"
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
#pragma link "cxLabel"
#pragma link "cxButtonEdit"
#pragma link "cxCheckBox"
#pragma link "cxDropDownEdit"
#pragma link "cxGraphics"
#pragma link "cxImageComboBox"
#pragma link "cxMaskEdit"
#pragma link "cxClasses"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxFilter"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "cxDBLookupComboBox"
#pragma link "cxGroupBox"
#pragma link "cxRadioGroup"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaElementaExtModule::TFormaElementaExtModule(TComponent* Owner)
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
bool TFormaElementaExtModule::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.DMExtModule.1",IID_IDMExtModule, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject("Oberon.DMExtModulePriv.1",IID_IDMExtModulePriv, (void**)&DMPriv);
DMPriv->Init(InterfaceMainObject,InterfaceImpl);

TypeModulecxDBImageComboBox->DataBinding->DataSource=DM->DataSourceElement;
NameObjectcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
FileNamecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
IspcxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;
cxDBRadioGroupResidence->DataBinding->DataSource=DM->DataSourceElement;

cxGrid1DBTableView1->DataController->DataSource=DMPriv->DataSourceTable;

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
int TFormaElementaExtModule::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaElementaExtModule::UpdateForm(void)
{
DMPriv->OpenTable(IdModule);

}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaExtModule::FormClose(TObject *Sender,
      TCloseAction &Action)
{
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
DMPriv->kanRelease();
Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}

}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaExtModule::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("ExtModule");
}
//---------------------------------------------------------------------------


void __fastcall TFormaElementaExtModule::NamecxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaExtModule::CodecxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaExtModule::FileNamecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if(OpenDialog1->Execute())
        {
        DM->Element->Edit();
        DM->ElementFILE_NAME_EXT_MODULE->AsString=OpenDialog1->FileName;
        DM->Element->Post();
		}
}
//---------------------------------------------------------------------------


void __fastcall TFormaElementaExtModule::ToolButton1Click(TObject *Sender)
{
DMPriv->IdModule=glStrToInt64(DM->ElementID_EXT_MODULE->AsString);
DMPriv->Table->Append();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaExtModule::ToolButton2Click(TObject *Sender)
{
DMPriv->Table->Delete();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaExtModule::cxButtonFileInBlobClick(
      TObject *Sender)
{
if(OpenDialog1->Execute())
		{
		DM->Element->Edit();
		DM->ElementBODY_EXT_MODULE->LoadFromFile(OpenDialog1->FileName);
		DM->Element->Post();
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaExtModule::ActionCloseExecute(TObject *Sender)
{
DMPriv->CancelIsmen();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaExtModule::ActionOKExecute(TObject *Sender)
{
if (DM->SaveElement()==true)
		{
		DMPriv->SaveIsmen();
		Close();
		}
else
	{
	ShowMessage("Ошибка при записи элемента справочника: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------
int TFormaElementaExtModule::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{


return -1;
}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaExtModule::cxButtonBlobInFileClick(TObject *Sender)

{
if(SaveDialog1->Execute())
		{
		DM->ElementBODY_EXT_MODULE->SaveToFile(SaveDialog1->FileName);
		}
}
//---------------------------------------------------------------------------

