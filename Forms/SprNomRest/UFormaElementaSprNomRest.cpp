//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprNomRest.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "pFIBDatabase"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxButtonEdit"
#pragma link "cxCalc"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxMemo"
#pragma link "cxTextEdit"
#pragma link "cxCalendar"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma link "cxPC"
#pragma link "cxLabel"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaElementaSprNomRest::TFormaElementaSprNomRest(TComponent* Owner)
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
bool TFormaElementaSprNomRest::Init(void)
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
SaveElement=false;


InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNomRest.1",IID_IDMSprNomRest, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

KFEdDBText->DataSource=DM->DataSourceElement;

NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NomercxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
PoscxDBDateEdit->DataBinding->DataSource=DM->DataSourceElement;
VihodcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
MPrigcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
SostKrcxDBMemo->DataBinding->DataSource=DM->DataSourceElement;
KolEdProdcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;
NameEdcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameEdFactorcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameProducecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameLossFactorcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
TehnologcxDBMemo->DataBinding->DataSource=DM->DataSourceElement;
SrokcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
VidcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
TempcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
ApperancecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
ColourcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
TastecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
SmellcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
ConsistencecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
MDSVcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
MDGcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
MIScxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
KMAMcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
BGKPcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
ECOLIcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
KPScxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
PROTEUScxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
PMScxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;


//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;
return result;
}
//----------------------------------------------------------------------
int TFormaElementaSprNomRest::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaElementaSprNomRest::UpdateForm(void)
{
LabelNom->Caption=NameNom;

}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNomRest::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprMPrig)FormaSpiskaSprMPrig->kanRelease();
if(FormaSpiskaSprEd)FormaSpiskaSprEd->kanRelease();
if(SostavProd)SostavProd->kanRelease();
if(FormaSpiskaSprProduce)FormaSpiskaSprProduce->kanRelease();
if(FormaSpiskaSprLossFactor)FormaSpiskaSprLossFactor->kanRelease();


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
int TFormaElementaSprNomRest::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
		if (number_procedure_end==ER_MPrig)//ViborMPrig)
                {
                DM->Element->Edit();
				DM->ElementIDMPRIG_NOMREST->AsInt64=FormaSpiskaSprMPrig->DM->ElementID_MPRIG->AsInt64;
                DM->ElementNAME_MPRIG->AsString=FormaSpiskaSprMPrig->DM->ElementNAME_MPRIG->AsString;
                DM->Element->Post();
                FormaSpiskaSprMPrig=0;
                }


		if (number_procedure_end==ER_EdProd)//ViborEdProd)
                {
				DM->Element->Edit();
				DM->ElementIDEDPROD_NOMREST->AsInt64=
						FormaSpiskaSprEd->DM->ElementIDED->AsInt64;
				DM->ElementNAMEED->AsString=FormaSpiskaSprEd->DM->Element->FieldByName("NAMEED")->AsString;
				DM->Element->Post();
				FormaSpiskaSprEd=0;
				}

		if (number_procedure_end==ER_Sostav)//EditSostav)
				{

				SostavProd=0;
				}

if (number_procedure_end==ER_EdFactor)
		{
		if (type_event==1)
				{
				EndViborEdFactor()  ;
				}
		FormaSpiskaSprEd=0;
		}

if (number_procedure_end==ER_Produce)
		{
		if (type_event==1)
				{
				EndViborProduce()  ;
				}
		FormaSpiskaSprProduce=0;
		}

if (number_procedure_end==ER_LossFactor)
		{
		if (type_event==1)
				{
				EndViborLossFactor()  ;
				}
		FormaSpiskaSprLossFactor=0;
		}

FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//-----------------------------------------------------------------------------


void TFormaElementaSprNomRest::OpenFormSpiskaSprMPrig(void)
{

if (FormaSpiskaSprMPrig==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprMPrig.1",IID_IFormaSpiskaSprMPrig,
													(void**)&FormaSpiskaSprMPrig);
		FormaSpiskaSprMPrig->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprMPrig->Vibor=true;
		FormaSpiskaSprMPrig->DM->OpenTable();
		//FormaSpiskaSprMPrig->HintLabel->Caption="Выберите место изготовления: "+DM->ElementNAMENOM->AsString;
		FormaSpiskaSprMPrig->NumberProcVibor=ER_MPrig;
        }

}
//-----------------------------------------------------------------------------
void  TFormaElementaSprNomRest::PrintTehnologKart(void)
{
ISheetEditor  *PrintForm;
		InterfaceGlobalCom->kanCreateObject("Oberon.SheetEditor.1",IID_ISheetEditor,
													(void**)&PrintForm);

numRow=1;
numCol=1;
porNumStr=1;

WORD Year;
WORD Month;
WORD Day;
DecodeDate(Now(),Year,Month,Day);

DM->IBQ->Active=false;
DM->IBQ->ParamByName("PARAM_IDNOMREST")->AsInteger=DM->ElementID_NOMREST->AsInt64;
DM->IBQ->ParamByName("PARAM_MONTH")->AsInteger=Month;
DM->IBQ->Active=true;

PrintForm->BeginUpdate();
//шапка
OutputZagolovokReport(PrintForm);

//таблица

DM->IBQ->First();
while(!DM->IBQ->Eof)
        {

        OutputString(PrintForm);numRow++;
        porNumStr++;

        DM->IBQ->Next();
        }

OutputPodavalReport(PrintForm);
PrintForm->EndUpdate();
}
//------------------------------------------------------------------------------
void TFormaElementaSprNomRest::OutputString(ISheetEditor *prForm)
{

numCol=2;
//порядковый номер строки
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(IntToStr(porNumStr));
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;
//списывать
prForm->TecCell_GetObject(numCol, numRow);
if (DM->IBQSPIS_SPROD->AsInteger==1){prForm->TecCell_SetText("Да");}
else{prForm->TecCell_SetText("Нет");}
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;
//номенклатура
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(DM->IBQNAMENOM->AsString);
prForm->TecCell_SetFontSize(14);
prForm->TecCell_SetFontStyle(TFontStyles() << fsBold);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;
//вес брутто
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(FloatToStr(DM->IBQBKOL_SPROD->AsFloat*
                                DM->IBQSEZKF->AsFloat
								*DM->IBQSEZKF_SPROD->AsFloat));
prForm->TecCell_SetFontSize(14);
prForm->TecCell_SetFontStyle(TFontStyles() << fsBold);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;
//вес нетто
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(FloatToStr(DM->IBQNKOL_SPROD->AsFloat*DM->IBQSEZKF->AsFloat
										   *DM->IBQSEZKF_SPROD->AsFloat));
prForm->TecCell_SetFontSize(14);
prForm->TecCell_SetFontStyle(TFontStyles() << fsBold);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

}

//---------------------------------------------------------------------------
void TFormaElementaSprNomRest::OutputZagolovokReport(ISheetEditor *prForm)
{

prForm->SetColumnWidth(0,10);
prForm->SetColumnWidth(1,10);
prForm->SetColumnWidth(2,50);
prForm->SetColumnWidth(3,50);
prForm->SetColumnWidth(4,400);
prForm->SetColumnWidth(5,70);
prForm->SetColumnWidth(6,70);


numRow=1;
numCol=6;
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Утверждаю");
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
prForm->TecCell_DeleteObject();
numRow++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText( "Директор ___________________");
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
prForm->TecCell_DeleteObject();
numRow++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(  "____________________________");
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
prForm->TecCell_DeleteObject();
numRow++; numRow++;

numCol=4;
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(  "Технологическая карта ");
prForm->TecCell_SetFontSize(14);
prForm->TecCell_SetFontStyle(TFontStyles() << fsBold);
prForm->TecCell_DeleteObject();
numRow++; numRow++;

numCol=2;
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText( "Блюдо: "+DM->ElementNAMENOM->AsString);
prForm->TecCell_DeleteObject();
numRow++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText( "Номер по сборнику: "+DM->ElementNOMER_NOMREST->AsString);
prForm->TecCell_DeleteObject();
numRow++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Выход: "+DM->ElementVIH_NOMREST->AsString);
prForm->TecCell_DeleteObject();
numRow++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Срок реализации: "+DM->ElementSROK_NOMREST->AsString);
prForm->TecCell_DeleteObject();
numRow++;numRow++;


numCol=2;

//порядковый номер строки 
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("№");
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;
//списывать
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Дв.");
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;
//номенклатура
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Наименование");
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;
//вес брутто
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Брутто");
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;
//вес нетто
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Нетто");
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;


numRow++;
}
//------------------------------------------------------------------------------
void TFormaElementaSprNomRest::OutputPodavalReport(ISheetEditor *prForm)
{

numRow++;
numCol=2;
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Технология приготовления:");
prForm->TecCell_DeleteObject();

numRow++; numRow++;


for (int i=0;i<TehnologcxDBMemo->Lines->Count;i++)
        {
		prForm->TecCell_GetObject(numCol, numRow);
		prForm->TecCell_SetText(TehnologcxDBMemo->Lines->Strings[i]);
		prForm->TecCell_DeleteObject();
        numRow++;
        }

        numRow++; numRow++;numRow++;

        numCol=4;
		prForm->TecCell_GetObject(numCol, numRow);
		prForm->TecCell_SetText("Калькулятор:  ___________________________________");
		prForm->TecCell_DeleteObject();

numRow++; numRow++;



}
//---------------------------------------------------------------





void __fastcall TFormaElementaSprNomRest::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprNomRest");	
}
//---------------------------------------------------------------------------


void __fastcall TFormaElementaSprNomRest::cxButtonSostClick(TObject *Sender)
{
if (DM->flSaveElement==false)
        {
                ShowMessage( "Необходимо записать элемент!" );
                return;

        }
if (SostavProd==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSostProd.1",IID_IFormaSpiskaSprSostProd,
													(void**)&SostavProd);
		SostavProd->NameNom=NameNom;
		SostavProd->KolEdProd=DM->ElementKOLEDPROD_NOMREST->AsFloat;
		SostavProd->NameEdProd=DM->ElementNAMEED->AsString;
		SostavProd->KFEdProd=DM->ElementKFED->AsFloat;
		SostavProd->Init(InterfaceMainObject,InterfaceImpl);
		SostavProd->Vibor=false;
		SostavProd->IdNom=DM->ElementIDNOM_NOMREST->AsInt64;
		SostavProd->IdNomRest=DM->ElementID_NOMREST->AsInt64;
		SostavProd->DM->KolEdProd=DM->ElementKOLEDPROD_NOMREST->AsInt64;
        SostavProd->DM->KFEdProd=DM->ElementKFED->AsFloat;
        SostavProd->DM->Pos=Now();
		SostavProd->DM->OpenTable(DM->ElementID_NOMREST->AsInt64);

		SostavProd->NumberProcVibor=ER_Sostav;
		}
}
//---------------------------------------------------------------------------





void __fastcall TFormaElementaSprNomRest::NameEdcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (FormaSpiskaSprEd==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&FormaSpiskaSprEd);
		FormaSpiskaSprEd->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprEd->Vibor=true;
		FormaSpiskaSprEd->IdNom=DM->ElementIDNOM_NOMREST->AsInt64;
		FormaSpiskaSprEd->DM->OpenTable(DM->ElementIDNOM_NOMREST->AsInt64);
		//FormaSpiskaSprEd->LabelNom->Caption=DM->ElementNAMENOM->AsString;
		//FormaSpiskaSprEd->HintLabel->Caption="Выберите единицу продукции";
		FormaSpiskaSprEd->NumberProcVibor=ER_EdProd;
		}	
}
//---------------------------------------------------------------------------



void __fastcall TFormaElementaSprNomRest::MPrigcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprMPrig();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNomRest::NamecxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNomRest::PoscxDBDateEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNomRest::NomercxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNomRest::VihodcxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNomRest::SrokcxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNomRest::KolEdProdcxDBCalcEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNomRest::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNomRest::ActionOKExecute(TObject *Sender)
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

void __fastcall TFormaElementaSprNomRest::ActionSaveExecute(TObject *Sender)
{
if (DM->SaveElement()==true)
		{
		SaveElement=true;
		}
else
	{
	ShowMessage("Ошибка при записи элемента справочника: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNomRest::ActionPrintExecute(TObject *Sender)
{
PrintTehnologKart();
}
//---------------------------------------------------------------------------
void TFormaElementaSprNomRest::ViborEdFactor(void)
{
if (FormaSpiskaSprEd==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&FormaSpiskaSprEd);
		FormaSpiskaSprEd->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprEd->Vibor=true;
		FormaSpiskaSprEd->IdNom=DM->ElementIDNOM_NOMREST->AsInt64;
		FormaSpiskaSprEd->DM->OpenTable(DM->ElementIDNOM_NOMREST->AsInt64);
		//FormaSpiskaSprEd->LabelNom->Caption=DM->ElementNAMENOM->AsString;
		//FormaSpiskaSprEd->HintLabel->Caption="Выберите единицу продукции";
		FormaSpiskaSprEd->NumberProcVibor=ER_EdFactor;
		}

}
//---------------------------------------------------------------------------
void TFormaElementaSprNomRest::EndViborEdFactor(void)
{

DM->Element->Edit();
DM->ElementIDEDFACTOR_SNOMREST->AsInt64=
						FormaSpiskaSprEd->DM->ElementIDED->AsInt64;
DM->ElementNAME_ED_FACTOR->AsString=FormaSpiskaSprEd->DM->ElementNAMEED->AsString;
DM->Element->Post();

}
//---------------------------------------------------------------------------
void TFormaElementaSprNomRest::OpenFormaSpiskaSprProduce(void)
{
if (FormaSpiskaSprProduce==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprProduce,IID_IFormaSpiskaSprProduce,
													(void**)&FormaSpiskaSprProduce);
		FormaSpiskaSprProduce->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprProduce->Vibor=true;
		FormaSpiskaSprProduce->UpdateForm();
		FormaSpiskaSprProduce->NumberProcVibor=ER_Produce;
		}

}
//---------------------------------------------------------------------------
void TFormaElementaSprNomRest::OpenFormaSpiskaSprLossFactor(void)
{
if (FormaSpiskaSprLossFactor==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprLossFactor,IID_IFormaSpiskaSprLossFactor,
													(void**)&FormaSpiskaSprLossFactor);
		FormaSpiskaSprLossFactor->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprLossFactor->Vibor=true;
		FormaSpiskaSprLossFactor->UpdateForm();
		FormaSpiskaSprLossFactor->NumberProcVibor=ER_LossFactor;
		}

}
//---------------------------------------------------------------------------
void TFormaElementaSprNomRest::EndViborProduce(void)
{
DM->Element->Edit();
DM->ElementIDPRODUCE_SNOMREST->AsInt64=
						glStrToInt64(FormaSpiskaSprProduce->DM->ElementID_SPRODUCE->AsString);
DM->ElementNAME_SPRODUCE->AsString=FormaSpiskaSprProduce->DM->ElementNAME_SPRODUCE->AsString;
DM->Element->Post();

}
//---------------------------------------------------------------------------
void TFormaElementaSprNomRest::EndViborLossFactor(void)
{
DM->Element->Edit();
DM->ElementIDLOSSFACTOR_SNOMREST->AsInt64=
						glStrToInt64(FormaSpiskaSprLossFactor->DM->ElementID_SLOSS_FACTOR->AsString);
DM->ElementNAME_SLOSS_FACTOR->AsString=FormaSpiskaSprLossFactor->DM->ElementNAME_SLOSS_FACTOR->AsString;
DM->Element->Post();

}
//---------------------------------------------------------------------------



void __fastcall TFormaElementaSprNomRest::NameEdFactorcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborEdFactor();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNomRest::NameProducecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
OpenFormaSpiskaSprProduce();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNomRest::NameLossFactorcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
OpenFormaSpiskaSprLossFactor();
}
//---------------------------------------------------------------------------

