//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprOborud.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxCheckBox"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxEdit"
#pragma link "cxButtons"
#pragma link "cxDropDownEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxMaskEdit"
#pragma link "cxMemo"
#pragma link "cxPC"
#pragma link "cxTextEdit"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaElementaSprOborud::TFormaElementaSprOborud(TComponent* Owner)
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
bool TFormaElementaSprOborud::Init(void)
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
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprOborud.1",IID_IDMSprOborud, (void**)&DM);

DM->Init(InterfaceMainObject,InterfaceImpl);
OnStartcxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;


NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
CompNamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
ModulcxDBComboBox->DataBinding->DataSource=DM->DataSourceElement;
ComPortcxDBComboBox->DataBinding->DataSource=DM->DataSourceElement;
BaudRatecxDBComboBox->DataBinding->DataSource=DM->DataSourceElement;
StrParcxDBMemo->DataBinding->DataSource=DM->DataSourceElement;
cxDBComboBoxPROGID_SOBORUD->DataBinding->DataSource=DM->DataSourceElement;

ObrabatChangeTypeOborud=false;


//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;


UpdateModul();

result=true;
return result;
}
//---------------------------------------------------------------------------
int TFormaElementaSprOborud::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaElementaSprOborud::UpdateForm(void)
{
ObrabatChangeTypeOborud=false;
int index=0;
for (int i=0;i<TypeOborudComboBox->Properties->Items->Count;i++)
        {

		if (TypeOborudComboBox->Properties->Items->Strings[i]==Trim(DM->ElementTYPE_OBORUD->AsString))
                {
                index=i;
                }
        }

TypeOborudComboBox->ItemIndex=index;

UpdateModel();

index=0;
for (int i=0;i<ModelComboBox->Properties->Items->Count;i++)
        {
        if (ModelComboBox->Properties->Items->Strings[i]==Trim(DM->ElementMODEL_OBORUD->AsString))
                {
                index=i;
                }
        }

ModelComboBox->ItemIndex=index;

ObrabatChangeTypeOborud=true;

UpdateModul();
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprOborud::FormClose(TObject *Sender,
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

Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
int TFormaElementaSprOborud::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

return -1;
}
//-----------------------------------------------------------------------------

void TFormaElementaSprOborud::UpdateModel(void)
{
String type_oborud=TypeOborudComboBox->Text;
ModelComboBox->Properties->Items->Clear();

if (type_oborud=="kkm")
        {

		ModelComboBox->Properties->Items->Add("no");
		ModelComboBox->Properties->Items->Add("kkm_kasbi_02f");
		ModelComboBox->Properties->Items->Add("kkm_amc_100k");
		ModelComboBox->Properties->Items->Add("kkm_amc_200f");
		ModelComboBox->Properties->Items->Add("kkm_shtrih_mk");
        }

if (type_oborud=="fr")
        {
		ModelComboBox->Properties->Items->Add("no");
		ModelComboBox->Properties->Items->Add("fr_shtrih_frk");
		ModelComboBox->Properties->Items->Add("fr_shtrih_combo_frk");
		ModelComboBox->Properties->Items->Add("fr_mercury_msk");

		}

if (type_oborud=="printer")
		{
		ModelComboBox->Properties->Items->Add("no");
		ModelComboBox->Properties->Items->Add("printer_shtrih_500");
		}

if (type_oborud=="scaner")
		{
		ModelComboBox->Properties->Items->Add("no");
		ModelComboBox->Properties->Items->Add("standart");
		}
ModelComboBox->ItemIndex=0;

}
//---------------------------------------------------------------------------
void TFormaElementaSprOborud::UpdateModul(void)
{
UnicodeString type_oborud=TypeOborudComboBox->Text;
ModulcxDBComboBox->Properties->Items->Clear();


if (type_oborud=="fr")
        {
		ModulcxDBComboBox->Properties->Items->Add("kanMercMSK.dll");
		ModulcxDBComboBox->Properties->Items->Add("kanShtrihFRK.dll");

		}

if (type_oborud=="printer")
		{
		ModulcxDBComboBox->Properties->Items->Add("PShtrih500.dll");
		}

if (type_oborud=="scaner")
		{
		ModulcxDBComboBox->Properties->Items->Add("scaner.dll");
		ModelComboBox->Properties->Items->Add("scaner64.dll");
		}

if (type_oborud=="DisplayPok")
		{
		ModulcxDBComboBox->Properties->Items->Add("MercDP04.dll");
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaSprOborud::TypeOborudComboBox_Click(
      TObject *Sender)
{
UpdateModel();
UpdateModul();
}
//---------------------------------------------------------------------------


void __fastcall TFormaElementaSprOborud::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprOborud");	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprOborud::TypeOborudComboBoxPropertiesChange(
      TObject *Sender)
{
if(ObrabatChangeTypeOborud==false) return;
UpdateModel();
UpdateModul();
}
//---------------------------------------------------------------------------





void __fastcall TFormaElementaSprOborud::NamecxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprOborud::CompNamecxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprOborud::ModulcxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprOborud::OnStartcxDBCheckBoxKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprOborud::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprOborud::ActionOKExecute(TObject *Sender)
{
DM->Element->Edit();
DM->ElementTYPE_OBORUD->AsString=TypeOborudComboBox->Text;
DM->ElementMODEL_OBORUD->AsString=ModelComboBox->Text;
DM->Element->Post();

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

