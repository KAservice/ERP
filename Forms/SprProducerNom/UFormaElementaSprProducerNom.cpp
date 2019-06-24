//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprProducerNom.h"
#include "IDMSprProducerTypePrice.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxCalc"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxLabel"
#pragma link "cxPC"
#pragma link "cxButtonEdit"
#pragma link "cxGroupBox"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxGraphics"
#pragma link "cxButtons"
#pragma link "cxMemo"
#pragma link "cxImageComboBox"
#pragma link "cxDBLookupComboBox"
#pragma link "cxDBLookupEdit"
#pragma link "cxLookupEdit"
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
#pragma link "cxDBLabel"
#pragma link "cxCalendar"
#pragma link "cxCheckBox"
#pragma link "cxSpinEdit"
#pragma link "cxCurrencyEdit"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TFormaElementaSprProducerNom::TFormaElementaSprProducerNom(TComponent* Owner)
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
bool TFormaElementaSprProducerNom::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_DMSprProducerNom,IID_IDMSprProducerNom, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);


CodecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
ArtcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NameNomcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
KrNamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
FNamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;




TNomcxDBImageComboBox->DataBinding->DataSource=DM->DataSourceElement;

DostupnocxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;
CodeNomcxDBLabel->DataBinding->DataSource=DM->DataSourceElement;
BarCodecxDBLabel->DataBinding->DataSource=DM->DataSourceElement;
ArtNomcxDBLabel->DataBinding->DataSource=DM->DataSourceElement;
NameNomcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
ModelcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
CodeAnalogcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
PriceZakupcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;
PricecxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;

IamcxDBDateEdit->DataBinding->DataSource=DM->DataSourceElement;
LocationcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
RepairCodecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;

Art2cxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
Angl_NamecxDBMemo->DataBinding->DataSource=DM->DataSourceElement;

//цены
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprProducerPrice,IID_IDMSprProducerPrice, (void**)&DMPrice);
DMPrice->Init(InterfaceMainObject,InterfaceImpl);
cxGrid1DBTableView1->DataController->DataSource=DMPrice->DataSourceTable;



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
int  TFormaElementaSprProducerNom::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaSprProducerNom::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprEd)FormaSpiskaSprEd->kanRelease();
if(FormaSpiskaSprPrice)FormaSpiskaSprPrice->kanRelease();
if (FormaSpiskaSprNom>0) FormaSpiskaSprNom->kanRelease();


DM->kanRelease();
DMPrice->kanRelease();

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

Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void TFormaElementaSprProducerNom::UpdateForm(void)
{
DMPrice->OpenTable(glStrToInt64(DM->ElementID_SPRNOM->AsString ));
//DMPrice->IdBasEd=glStrToInt64(DM->ElementIDBASED_SPRNOM->AsString);


NameGrpLabel->Caption=NameGrpNom;
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprProducerNom::FormActivate(TObject *Sender)
{
//if (glScaner) if(glScaner->ConnectScaner) glScaner->ReadSh=ReadShtrihCodEvent;
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprProducerNom::FormDeactivate(TObject *Sender)
{
//if (glScaner) if(glScaner->ConnectScaner) glScaner->ReadSh=0;
}

//----------------------------------------------------------------------------
int TFormaElementaSprProducerNom::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{




		if (number_procedure_end==VR_ViborSpisokEd)
                {
                FormaSpiskaSprEd=0;
                }


		if (number_procedure_end==VR_ViborSpisokPrice)
                {
                FormaSpiskaSprPrice=0;
                }

		if (number_procedure_end==VR_ViborBasEd)
				{
				if (type_event==1)    //выбор сделан
					{
					EndEditBasEd();
					}
				FormaElementaSprEd=0;
				}

if ( number_procedure_end==VR_ViborNom)
	{
	if (type_event==1)
		{
		EndViborNom();
		}
	FormaSpiskaSprNom=0;
	}

FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//-----------------------------------------------------------------------------
void __fastcall TFormaElementaSprProducerNom::NameNomKeyPress(TObject *Sender,
      char &Key)
{
if(Key==VK_RETURN)
        {
        DM->Element->Edit();
		DM->ElementFNAME_SPRNOM->AsString=DM->ElementNAME_SPRNOM->AsString;
		DM->ElementKRNAME_SPRNOM->AsString=DM->ElementNAME_SPRNOM->AsString;
        DM->Element->Post();
        }
}
//---------------------------------------------------------------------------


void __fastcall TFormaElementaSprProducerNom::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprProducerNom");
}

//-----------------------------------------------------------------------------




void __fastcall TFormaElementaSprProducerNom::cxButtonPriceClick(TObject *Sender)
{

if (FormaSpiskaSprPrice==0)
        {
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprProducerPrice,IID_IFormaSpiskaSprProducerPrice,
													 (void**)&FormaSpiskaSprPrice);
		FormaSpiskaSprPrice->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprPrice->IdNom=glStrToInt64(DM->ElementID_SPRNOM->AsString);
		FormaSpiskaSprPrice->DM->OpenTable(glStrToInt64(DM->ElementID_SPRNOM->AsString));
		FormaSpiskaSprPrice->HeaderText="Цены номенклатуры: "
						+DM->ElementNAME_SPRNOM->AsString;
		FormaSpiskaSprPrice->UpdateForm();
		FormaSpiskaSprPrice->NumberProcVibor=VR_ViborSpisokPrice;
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprProducerNom::cxButtonEdClick(TObject *Sender)
{

if (FormaSpiskaSprEd==0)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprProducerEd,IID_IFormaSpiskaSprProducerEd,
													 (void**)&FormaSpiskaSprEd);
		FormaSpiskaSprEd->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprEd->IdProducerNom=glStrToInt64(DM->ElementID_SPRNOM->AsString);
		FormaSpiskaSprEd->DM->OpenTable(glStrToInt64(DM->ElementID_SPRNOM->AsString));
		FormaSpiskaSprEd->HeaderText="Единицы номенклатуры: "+DM->ElementNAME_SPRNOM->AsString;
		FormaSpiskaSprEd->IdProducerTypePrice=IdProducerTypePrice;
        FormaSpiskaSprEd->UpdateForm();
		FormaSpiskaSprEd->NumberProcVibor=VR_ViborSpisokEd;
		}


}
//---------------------------------------------------------------------------











void __fastcall TFormaElementaSprProducerNom::NameBasEdPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{

//if (FormaSpiskaSprEd==NULL)
//		{
//		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
//													 (void**)&FormaSpiskaSprEd);
//		FormaSpiskaSprEd->Init(InterfaceMainObject,InterfaceImpl);
//		FormaSpiskaSprEd->IdNom=glStrToInt64(DM->ElementIDNOM->AsString);
//		FormaSpiskaSprEd->DM->OpenTable(glStrToInt64(DM->ElementIDNOM->AsString));
//		//FormaSpiskaSprEd->LabelNom->Caption=DM->Element->FieldByName("NAMENOM")->AsString;
//		//FormaSpiskaSprEd->HintLabel->Caption="Выберите базовую единицу";
//		FormaSpiskaSprEd->NumberProcVibor=4;
//		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprProducerNom::CodecxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprProducerNom::ArtcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


 
//редактирование базовой единицы

void TFormaElementaSprProducerNom::EditBasEd(void)
{
if (FormaElementaSprEd==0)
	{
	InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprProducerEd,IID_IFormaElementaSprProducerEd,
													 (void**)&FormaElementaSprEd);
	FormaElementaSprEd->Init(InterfaceMainObject,InterfaceImpl);
	FormaElementaSprEd->DM->OpenElement(glStrToInt64(DM->ElementIDBASED_SPRNOM->AsString));
	FormaElementaSprEd->UpdateForm();
	FormaElementaSprEd->NumberProcVibor=VR_ViborBasEd;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprProducerNom::EndEditBasEd(void)
{

//DM->OpenEd();
//DMPrice->UpdateSpisokEd(glStrToInt64(DM->ElementIDNOM->AsString));
FormaElementaSprEd=0;
}
//----------------------------------------------------------------------------


void __fastcall TFormaElementaSprProducerNom::ToolButtonAddPriceClick(TObject *Sender)
{
DMPrice->Table->Append();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprProducerNom::ToolButtonDeletePriceClick(
      TObject *Sender)
{
DMPrice->Table->Delete();	
}
//---------------------------------------------------------------------------


void __fastcall TFormaElementaSprProducerNom::cxButtonEditBasEdClick(TObject *Sender)
{
EditBasEd();
}
//---------------------------------------------------------------------------






void __fastcall TFormaElementaSprProducerNom::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprProducerNom::ActionOKExecute(TObject *Sender)
{
if (DM->SaveElement()==true)
	{
	if (DMPrice->SaveIsmen()==true)
		{
		Close();
		}
	else
		{
		ShowMessage("Ошибка при записи справочника цен! "+DMPrice->TextError);
		}
	}
else
	{
	ShowMessage("Ошибка при записи!"+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprProducerNom::ActionSaveExecute(TObject *Sender)
{
if (DM->SaveElement()==true)
	{
	if (DMPrice->SaveIsmen()==true)
		{
		UpdateForm();
		}
	else
		{
		ShowMessage("Ошибка при записи справочника цен! "+DMPrice->TextError);
		}
	}
else
	{
	ShowMessage("Ошибка при записи!"+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprProducerNom::KrNamecxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaElementaSprProducerNom::NameNomcxDBTextEditKeyPress(TObject *Sender,
          wchar_t &Key)
{
if(Key==VK_RETURN)
	{
	DM->Element->Edit();
	DM->ElementFNAME_SPRNOM->AsString=DM->ElementNAME_SPRNOM->AsString;
	UnicodeString t=DM->ElementNAME_SPRNOM->AsString;
	DM->ElementKRNAME_SPRNOM->AsString=Trim(t).SetLength(39);
	DM->Element->Post();
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprProducerNom::FNamecxDBTextEditKeyPress(TObject *Sender, wchar_t &Key)

{
if(Key==VK_RETURN)
	{
	DM->Element->Edit();
	UnicodeString t=DM->ElementFNAME_SPRNOM->AsString;
	DM->ElementKRNAME_SPRNOM->AsString=Trim(t).SetLength(39);
	DM->Element->Post();
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaElementaSprProducerNom::NameNomcxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
		DM->ElementIDNOM_SPRNOM->Clear();
		DM->Element->Post();
		}break;
	}
}
//---------------------------------------------------------------------------
void TFormaElementaSprProducerNom::ViborNom(void)
{
if (FormaSpiskaSprNom>0) return;

InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
												 (void**)&FormaSpiskaSprNom);
FormaSpiskaSprNom->Init(InterfaceMainObject,InterfaceImpl);
FormaSpiskaSprNom->Vibor=true;
FormaSpiskaSprNom->NumberProcVibor=VR_ViborNom;
FormaSpiskaSprNom->IdNom=glStrToInt64(DM->ElementIDNOM_SPRNOM->AsString);
FormaSpiskaSprNom->UpdateForm();

}
//--------------------------------------------------------------------------
void __fastcall TFormaElementaSprProducerNom::EndViborNom(void)
{

	DM->Element->Edit();
	DM->ElementIDNOM_SPRNOM->AsString=FormaSpiskaSprNom->DM->TableIDNOM->AsString;
	DM->ElementNAMENOM->AsString=FormaSpiskaSprNom->DM->TableNAMENOM->AsString;
	DM->ElementCODENOM->AsString=FormaSpiskaSprNom->DM->TableCODENOM->AsString;
	DM->ElementARTNOM->AsString=FormaSpiskaSprNom->DM->TableARTNOM->AsString;
	DM->Element->Post();

}
//---------------------------------------------------------------------------
