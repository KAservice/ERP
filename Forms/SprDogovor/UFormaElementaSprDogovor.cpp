//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprDogovor.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"




//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxCalc"
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaElementaSprDogovor::TFormaElementaSprDogovor(TComponent* Owner)
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
bool TFormaElementaSprDogovor::Init(void)
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
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprDogovor.1",IID_IDMSprDogovor, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

IDcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
DatecxDBDateEdit->DataBinding->DataSource=DM->DataSourceElement;
NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
DocxDBDateEdit->DataBinding->DataSource=DM->DataSourceElement;
SrokcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
MaxSumCreditcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;

flObrabatChangeTypePrice=false;
flObrabatSpPogCredita=false;

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice, (void**)&DMSprTypePrice);
DMSprTypePrice->Init(InterfaceMainObject,InterfaceImpl);
DMSprTypePrice->OpenTable();
TypePriceComboBox->Properties->Items->Clear();
DMSprTypePrice->Table->First();
while (!DMSprTypePrice->Table->Eof)
		{
		TypePriceComboBox->Properties->Items->Add(DMSprTypePrice->TableNAME_TPRICE->AsString);
		DMSprTypePrice->Table->Next();
		}



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
void __fastcall TFormaElementaSprDogovor::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprGrafikPlat)FormaSpiskaSprGrafikPlat->kanRelease();
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
int TFormaElementaSprDogovor::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaElementaSprDogovor::UpdateForm(void)
{
flObrabatChangeTypePrice=false;
flObrabatSpPogCredita=false;
WayPayComboBox->ItemIndex=DM->ElementWAYPAY_SDOG->AsInteger;
TypePriceComboBox->ItemIndex=DMSprTypePrice->GetIndexTypePricePoId(glStrToInt64(DM->ElementIDTPRICE_SDOG->AsString))-1;
flObrabatChangeTypePrice=true;
flObrabatSpPogCredita=true;
}
//---------------------------------------------------------------------------

int TFormaElementaSprDogovor::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

if (number_procedure_end==1)
		{

		FormaSpiskaSprGrafikPlat=0;
		}


FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//-----------------------------------------------------------------------------


void __fastcall TFormaElementaSprDogovor::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprDogovor");	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprDogovor::cxButtonGrafikPlatClick(
      TObject *Sender)
{
if (DM->flSaveElement==false)
        {
        ShowMessage("Необходимо записать элемент!");
        return;
        }

if (FormaSpiskaSprGrafikPlat==NULL)
        {

		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprGrafikPlat.1",IID_IFormaSpiskaSprGrafikPlat,
													(void**)&FormaSpiskaSprGrafikPlat);
		FormaSpiskaSprGrafikPlat->Init(InterfaceMainObject,InterfaceImpl);
        FormaSpiskaSprGrafikPlat->Vibor=false;
		FormaSpiskaSprGrafikPlat->IdDogovor=glStrToInt64(DM->ElementID_SDOG->AsString);
		FormaSpiskaSprGrafikPlat->DM->OpenTable(glStrToInt64(DM->ElementID_SDOG->AsString));
		//FormaSpiskaSprGrafikPlat->LabelZagolovok->Caption="Договор: "+DM->ElementNAME_SDOG->AsString;
		FormaSpiskaSprGrafikPlat->NumberProcVibor=1;


		}
}
//---------------------------------------------------------------------------




void __fastcall TFormaElementaSprDogovor::TypePriceComboBoxPropertiesChange(
      TObject *Sender)
{
if(flObrabatChangeTypePrice==false) return;

		DMSprTypePrice->Table->First();
		DMSprTypePrice->Table->MoveBy(TypePriceComboBox->ItemIndex);
		DM->Element->Edit();
		DM->ElementIDTPRICE_SDOG->AsString=DMSprTypePrice->TableID_TPRICE->AsString;
		DM->Element->Post();


	FindNextControl(ActiveControl,true,true,false)->SetFocus();

}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprDogovor::WayPayComboBoxPropertiesChange(
      TObject *Sender)
{
if(flObrabatSpPogCredita==false) return;
DM->Element->Edit();
DM->ElementWAYPAY_SDOG->AsInteger=WayPayComboBox->ItemIndex;
DM->Element->Post();

	FindNextControl(ActiveControl,true,true,false)->SetFocus();

}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprDogovor::DatecxDBDateEditExit(TObject *Sender)
{
DM->Element->Edit();
DM->ElementNAME_SDOG->AsString="Договор №"+DM->ElementNUMBER_SDOG->AsString
		+" от "+DM->ElementDATE_SDOG->AsString;
DM->Element->Post();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprDogovor::NumcxDBTextEditExit(TObject *Sender)
{
DM->Element->Edit();
DM->ElementNAME_SDOG->AsString="Договор №"+DM->ElementNUMBER_SDOG->AsString
		+" от "+DM->ElementDATE_SDOG->AsString;
DM->Element->Post();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprDogovor::NumcxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprDogovor::DatecxDBDateEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprDogovor::NamecxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaElementaSprDogovor::DocxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprDogovor::SrokcxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprDogovor::MaxSumCreditcxDBCalcEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprDogovor::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprDogovor::ActionOKExecute(TObject *Sender)
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

void __fastcall TFormaElementaSprDogovor::ActionSaveExecute(TObject *Sender)
{
if (DM->SaveElement()==true)
		{

		}
else
	{
	ShowMessage("Ошибка при записи элемента справочника: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

