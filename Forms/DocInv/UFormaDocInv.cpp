//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop



#include "UFormaDocInv.h"
#include "IFormaDocSpisNom.h"
#include "IFormaDocOstNom.h"
//#include "IDMRegOstNom.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IFormaRunExternalModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxClasses"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "cxButtonEdit"
#pragma link "cxCalc"
#pragma link "cxContainer"
#pragma link "cxDBEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxCalendar"
#pragma link "cxLabel"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaDocInv::TFormaDocInv(TComponent* Owner)
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
void __fastcall TFormaDocInv::FormCreate(TObject *Sender)
{
NewElement=false;  // новый элемент
Prosmotr=false;    //только просмотр
NoEdit=false;
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи
VibTovarId=0;
VibTovarIdGrp=0;
IdTypePrice=0;
ActionOperation=aoNO;


}
//--------------------------------------------------------------------------
bool TFormaDocInv::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.DMDocInv.1",IID_IDMDocInv, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

//ПРИВЕЛЕГИИ
DM_Connection->GetPrivForm(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;


InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice, (void**)&DMSprPrice);
DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceDocT;

NameInfcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameSkladcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NumDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;

PrimcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
NameInvcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;

NameUserDBText->DataSource=DM->DataSourceDocAll;
PrefiksNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;

flObrabatChangeTypeInv=false;
flObrabatChangeTypePrice=false;


InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice, (void**)&DMSprTypePrice);
DMSprTypePrice->Init(InterfaceMainObject,InterfaceImpl);
DMSprTypePrice->OpenTable();
TypePriceComboBox->Properties->Items->Clear();
TypePriceComboBox->Properties->Items->Add("Не задан");
DMSprTypePrice->Table->First();
while (!DMSprTypePrice->Table->Eof)
		{
		TypePriceComboBox->Properties->Items->Add(DMSprTypePrice->TableNAME_TPRICE->AsString);
		DMSprTypePrice->Table->Next();
		}

//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaDocInvImpl),false);
DMTableExtPrintForm->Table->First();
while (!DMTableExtPrintForm->Table->Eof)
		{
		TMenuItem *menu=new TMenuItem(PopupMenuExtModule);
		menu->Caption=DMTableExtPrintForm->TableNAME_EXTPRINT_FORM->AsString;
		menu->OnClick = PopupMenuExtModuleClick;
		PopupMenuExtModule->Items->Add(menu);
		//static_cast<TPopupMenu*>(Sender)->Items->Add(Item);
		DMTableExtPrintForm->Table->Next();
		}

UpdateForm();
result=true;

return result;
}
//----------------------------------------------------------------------------
int TFormaDocInv::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaDocInv::UpdateForm(void)
{
Prosmotr=DM->Prosmotr;
NoEdit=DM->NoEdit;

if (Prosmotr==true)
        {
        ProsmotrLabel->Visible=true;
		cxGrid1DBTableView1->OptionsData->Editing=false;
        }
else
        {
        ProsmotrLabel->Visible=false;
		cxGrid1DBTableView1->OptionsData->Editing=true;
        }

if (NoEdit==true)
        {
		cxGrid1DBTableView1->OptionsData->Editing=false;
        }
else
        {
		cxGrid1DBTableView1->OptionsData->Editing=true;
        }

flObrabatChangeTypeInv=false;
flObrabatChangeTypePrice=false;
TypePriceComboBox->ItemIndex=DMSprTypePrice->GetIndexTypePricePoId(glStrToInt64(DM->DocIDTPRICE_INV->AsString));
TypeInvComboBox->ItemIndex=DM->DocTYPE_INV->AsInteger;
flObrabatChangeTypeInv=true;
flObrabatChangeTypePrice=true;
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocInv::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(Nom)Nom->kanRelease();
if(Firma)Firma->kanRelease();
if(Sklad)Sklad->kanRelease();
if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
if(FormaSpiskaSprInv)FormaSpiskaSprInv->kanRelease();

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
//delete SpisokGrp;
DMTableExtPrintForm->kanRelease();
DM->kanRelease();
DMSprPrice->kanRelease();
Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
int TFormaDocInv::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==Tovar)
        {
		if (type_event==1)
                {
				if (ActionOperation==aoAddNewString)
                        {
                        DM->AddDocNewString();
                        }
                DM->DocT->Edit();
				DM->DocTIDNOM_INVT->AsString=Nom->DM->ElementIDNOM->AsString;
                DM->DocTCODENOM->AsInteger=Nom->DM->ElementCODENOM->AsInteger;
                DM->DocTNAMENOM->AsString=Nom->DM->ElementNAMENOM->AsString;
                DM->DocTTNOM->AsInteger=Nom->DM->ElementTNOM->AsInteger;

				DM->DocTIDED_INVT->AsString=glStrToInt64(Nom->DM->ElementIDBASEDNOM->AsString);
                DM->DocTNAMEED->AsString=Nom->DM->BasEdNAMEED->AsString;
                DM->DocTKF_INVT->AsFloat=Nom->DM->BasEdKFED->AsFloat;

				IDMSprPrice * DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDTPRICE_INV->AsString),
											 glStrToInt64(DM->DocTIDNOM_INVT->AsString));
                        DM->DocTPRICE_INVT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
                                                        DM->DocTKF_INVT->AsFloat;
				DMSprPrice->kanRelease();

                DM->DocT->Post();

				VibTovarId=glStrToInt64(Nom->DM->ElementIDNOM->AsString);
				VibTovarIdGrp=glStrToInt64(Nom->DM->ElementIDGRPNOM->AsString);
                }
		Nom=0;
		cxGrid1DBTableView1KOLFAKT_INVT->Selected=true;
		cxGrid1->SetFocus();
        }

if (number_procedure_end==Edinica)
        {

        }

if (number_procedure_end==FirmaRekvisit)
        {
		if (type_event==1)
                {
                DM->DocAll->Edit();
				DM->DocAllIDFIRMDOC->AsString=Firma->DM->ElementIDFIRM->AsString;
                DM->DocAllNAMEFIRM->AsString=Firma->DM->Element->FieldByName("NAMEFIRM")->AsString;
                DM->DocAll->Post();
                }
		Firma=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
        }

if (number_procedure_end==SkladRekvisit)
        {
		if (type_event==1)
                {
				DM->DocAll->Edit();
				DM->DocAllIDSKLDOC->AsString=Sklad->DM->ElementIDSKLAD->AsString;
                DM->DocAllNAMESKLAD->AsString=Sklad->DM->Element->FieldByName("NAMESKLAD")->AsString;
                DM->DocAll->Post();
                }
		Sklad=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
        }

if (number_procedure_end==ViborInfBase)
        {
		if (type_event==1)
                {
                DM->DocAll->Edit();
				DM->DocAllIDBASE_GALLDOC->AsString=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsInt64;
                DM->DocAllNAME_SINFBASE_OBMEN->AsString=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;
                DM->DocAll->Post();
                }
		FormaSpiskaSprInfBase=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}

if (number_procedure_end==ViborInv)
        {
		if (type_event==1)
                {
				DM->Doc->Edit();
				DM->DocIDINV_INV->AsString=FormaSpiskaSprInv->DM->TableID_SINV->AsInt64;
				DM->DocNAME_SINV->AsString=FormaSpiskaSprInv->DM->TableNAME_SINV->AsString;
				DM->Doc->Post();
                }
		FormaSpiskaSprInv=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}

ActionOperation=aoNO;
EditRekvisit=NO;
return -1;
}
//----------------------------------------------------------------------------
void  TFormaDocInv::OpenFSSprNom()
{
if (Prosmotr==true) return;
if (Nom==NULL)
        { 
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&Nom);
		Nom->Init(InterfaceMainObject,InterfaceImpl);
		Nom->Vibor=true;
		Nom->NumberProcVibor=Tovar;
//		Nom->HintLabel->Caption="Выберите номенклатуру для документа Инвентаризация №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		Nom->IdNom=glStrToInt64(DM->DocTIDNOM_INVT->AsString);
		Nom->DM->IdTypePrice=glStrToInt64(DM->DocIDTPRICE_INV->AsString);
        Nom->UpdateForm();

        }
}

//----------------------------------------------------------------------------





void    TFormaDocInv::OpenFormSpiskaSprFirm(void)
{
if (Prosmotr==true) return;
if (Firma==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&Firma);
		Firma->Init(InterfaceMainObject,InterfaceImpl);
		Firma->Vibor=true;
		Firma->NumberProcVibor=FirmaRekvisit;
        Firma->DM->OpenTable();
//        Firma->HintLabel->Caption="Выберите фирму для документа Инвентаризация №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		}

}
//---------------------------------------------------------------------------
void  TFormaDocInv::OpenFormSpiskaSprSklad(void)
{
if (Prosmotr==true) return;
if (Sklad==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&Sklad);
		Sklad->Init(InterfaceMainObject,InterfaceImpl);
		Sklad->Vibor=true;
		Sklad->NumberProcVibor=SkladRekvisit;
		Sklad->DM->OpenTable();
//		Sklad->HintLabel->Caption="Выберите склад для документа Инвентаризация №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		}

}
//-----------------------------------------------------------------------------
void __fastcall TFormaDocInv::ButtonVibFirmClick(TObject *Sender)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprFirm();
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocInv::AddNewStringClick(TObject *Sender)
{
if (Prosmotr==true) return;
ActionOperation=aoAddNewString;
OpenFSSprNom();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocInv::DeleteStringClick(TObject *Sender)
{
if (Prosmotr==true) return;
DM->DeleteStringDoc();
}

//----------------------------------------------------------------------------

void TFormaDocInv::OpenPrintForm(void)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
porNumStr=1;

PrintForm->SS->BeginUpdate();
//шапка
OutputZagolovokReport(PrintForm);

//таблица

DM->DocT->First();
while(!DM->DocT->Eof)
        {

        OutputString(PrintForm);numRow++; porNumStr++;

        DM->DocT->Next();
        }

OutputPodavalReport(PrintForm);
PrintForm->SS->EndUpdate();
PrintForm->Show();
}
//---------------------------------------------------------------------------
void TFormaDocInv::OutputZagolovokReport(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";
prForm->SS->RowsAutoHeight=true;

        TcxSSHeader *cHeader;
        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 40;
        cHeader->Size[2] = 70;
        cHeader->Size[3] = 200;
        cHeader->Size[4] = 70;
        cHeader->Size[5] = 80;
        cHeader->Size[6] = 50;
        cHeader->Size[7] = 80;
        cHeader->Size[8] = 80;

numRow=2;
numCol=1;


cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = DM->DocAllFNAMEFIRM->AsString
        +" ИНН "+DM->DocAllINNFIRM->AsString;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="Адрес: "+DM->DocAllPADRFIRM->AsString;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="Склад: "+DM->DocAllNAMESKLAD->AsString;
delete cell;
numRow++; numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol+1, numRow);
cell->Text ="Инвентаризация №"+DM->DocAllNUMDOC->AsString+" от "
                +DateToStr(DM->DocAllPOSDOC->AsDateTime);
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;
numRow++; numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="Тип цен: "+TypePriceComboBox->Text;
delete cell;
numRow++;

//заголовок таблицы
numCol=1;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "№";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//код
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Код";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Наименование";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Цена";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Единица";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "К";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="Кол. уч.";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="Кол. факт.";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;
}
//------------------------------------------------------------------------------
void TFormaDocInv::OutputString(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text =IntToStr(porNumStr);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;


cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text =DM->DocTCODENOM->AsString;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->WordBreak = true;
//cell->Style->Font->Size = 8;
cell->Text =DM->DocTNAMENOM->AsString;
cell->Style->HorzTextAlign = haLEFT;
//cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text =FloatToStrF(DM->DocTPRICE_INVT->AsFloat, ffFixed, 15,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text =DM->DocTNAMEED->AsString;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text =FloatToStrF(DM->DocTKF_INVT->AsFloat,ffFixed,10,3);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

if (DM->DocTKOLUCH_INVT->AsFloat!=0)
		{
		cell->Text=FloatToStrF(DM->DocTKOLUCH_INVT->AsFloat,ffFixed,10,3);
		}
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
if( DM->DocTKOLFAKT_INVT->AsFloat!=0)
        {
		cell->Text=FloatToStrF(DM->DocTKOLFAKT_INVT->AsFloat,ffFixed,10,3);
		}
delete cell;
numCol++;


}


//------------------------------------------------------------------------------
void TFormaDocInv::OutputPodavalReport(TSheetEditor *prForm)
{
numRow++;
numCol=1;
TcxSSCellObject *cell;
numRow++;numRow++;


cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Комиссия     ______________________________________________ ";
delete cell;
numRow++;numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="             ______________________________________________ ";
delete cell;
numRow++;numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="             ______________________________________________ ";
delete cell;
numRow++;numRow++;

}
//---------------------------------------------------------------


void __fastcall TFormaDocInv::ToolButtonOstatkiClick(TObject *Sender)
{
//if (Prosmotr==true) return;
//TDMRegOstNom *dm=new TDMRegOstNom(Application);
//dm->DM_Connection=DM_Connection;
//dm->Init();
//DM->DocT->First();
//while(!DM->DocT->Eof)
//		{
//		dm->IdFirm=glStrToInt64(DM->DocAllIDFIRMDOC->AsString);
//		dm->IdSklad=glStrToInt64(DM->DocAllIDSKLDOC->AsString);
//		dm->IdNom=glStrToInt64(DM->DocTIDNOM_INVT->AsString);
//		dm->GetOstatok();
//		DM->DocT->Edit();
//        DM->DocTKOLUCH_INVT->AsFloat=
//								dm->OstatokKOLOST->AsFloat;
//        DM->DocT->Post();
//        DM->DocT->Next();
//		}
//
//delete dm;
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocInv::ToolButtonCreateDocSpisClick(TObject *Sender)
{
IFormaDocSpisNom *DocSpis;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocSpisNom.1",IID_IFormaDocSpisNom,
													(void**)&DocSpis);
DocSpis->Init(InterfaceMainObject,InterfaceImpl);
if (!DocSpis) return;
DocSpis->DM->NewDoc();

DocSpis->DM->DocAll->Edit();
DocSpis->DM->DocAllIDFIRMDOC->AsString=DM->DocAllIDFIRMDOC->AsString;
DocSpis->DM->DocAllNAMEFIRM->AsString=DM->DocAllNAMEFIRM->AsString;
DocSpis->DM->DocAllIDSKLDOC->AsString=DM->DocAllIDSKLDOC->AsString;
DocSpis->DM->DocAllNAMESKLAD->AsString=DM->DocAllNAMESKLAD->AsString;
DocSpis->DM->DocAllIDDOCOSNDOC->AsString=DM->DocAllIDDOC->AsString;
DocSpis->DM->DocAllPOSDOC->AsDateTime=DM->DocAllPOSDOC->AsDateTime+0.00005;
DocSpis->DM->DocAll->Post();

DocSpis->DM->Doc->Edit();
DocSpis->DM->DocPRIMSPN->AsString="Списание недостач Инвентаризации №"
                +DM->DocAllNUMDOC->AsString+" от "
                +DM->DocAllPOSDOC->AsString;
DocSpis->DM->Doc->Post();

//DM->DocT->First();
//while(!DM->DocT->Eof)
//        {
//        if(DM->DocTKOLUCH_INVT->AsFloat-DM->DocTKOLFAKT_INVT->AsFloat>0)
//                {
//                DocSpis->DM->AddDocNewString();
//                DocSpis->DM->DocT->Edit();
//                DocSpis->DM->DocTIDNOMSPNT->AsInteger=DM->DocTIDNOM_INVT->AsInteger;
//                DocSpis->DM->DocTNAMENOM->AsString=DM->DocTNAMENOM->AsString;
//                DocSpis->DM->DocTIDEDSPNT->AsInteger=DM->DocTIDED_INVT->AsInteger;
//                DocSpis->DM->DocTNAMEED->AsString=DM->DocTNAMEED->AsString;
//                DocSpis->DM->DocTKFSPNT->AsFloat=DM->DocTKF_INVT->AsFloat;
//                DocSpis->DM->DocTKOLSPNT->AsFloat=DM->DocTKOLUCH_INVT->AsFloat
//                                -DM->DocTKOLFAKT_INVT->AsFloat;
//                DocSpis->DM->DocT->Post();
//                }
//
//        DM->DocT->Next();
//        }
//
//DocSpis->EditFirm->Text=DM->DocAllNAMEFIRM->AsString;
//DocSpis->EditSklad->Text=DM->DocAllNAMESKLAD->AsString;
//DocSpis->PosDoc->DateTime=DocSpis->DM->DocAllPOSDOC->AsDateTime;
DocSpis->UpdateForm();


}
//---------------------------------------------------------------------------

void __fastcall TFormaDocInv::ToolButtonCreateDocOstNomClick(
      TObject *Sender)
{
IFormaDocOstNom *DocOstNom;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocOstNom.1",IID_IFormaDocOstNom,
													(void**)&DocOstNom);
DocOstNom->Init(InterfaceMainObject,InterfaceImpl);
if (!DocOstNom) return;
DocOstNom->DM->NewDoc();

DocOstNom->DM->DocAll->Edit();
DocOstNom->DM->DocAllIDFIRMDOC->AsString=DM->DocAllIDFIRMDOC->AsString;
DocOstNom->DM->DocAllNAMEFIRM->AsString=DM->DocAllNAMEFIRM->AsString;
DocOstNom->DM->DocAllIDSKLDOC->AsString=DM->DocAllIDSKLDOC->AsString;
DocOstNom->DM->DocAllNAMESKLAD->AsString=DM->DocAllNAMESKLAD->AsString;
DocOstNom->DM->DocAllIDDOCOSNDOC->AsString=DM->DocAllIDDOC->AsString;
DocOstNom->DM->DocAllPOSDOC->AsDateTime=DM->DocAllPOSDOC->AsDateTime+0.0001;
DocOstNom->DM->DocAll->Post();

DocOstNom->DM->Doc->Edit();
DocOstNom->DM->DocPRIMOSN->AsString="Ввод излишков Инвентаризации №"
				+DM->DocAllNUMDOC->AsString+" от "
				+DM->DocAllPOSDOC->AsString;
DocOstNom->DM->Doc->Post();

//DM->DocT->First();
//while(!DM->DocT->Eof)
//		{
//		if(DM->DocTKOLFAKT_INVT->AsFloat-DM->DocTKOLUCH_INVT->AsFloat>0)
//				{
//				DocOstNom->DM->AddDocNewString();
//				DocOstNom->DM->DocT->Edit();
//				DocOstNom->DM->DocTIDNOMOSNT->AsInteger=DM->DocTIDNOM_INVT->AsInteger;
//				DocOstNom->DM->DocTNAMENOM->AsString=DM->DocTNAMENOM->AsString;
//				DocOstNom->DM->DocTIDEDOSNT->AsInteger=DM->DocTIDED_INVT->AsInteger;
//				DocOstNom->DM->DocTNAMEED->AsString=DM->DocTNAMEED->AsString;
//				DocOstNom->DM->DocTKFOSNT->AsFloat=DM->DocTKF_INVT->AsFloat;
//				DocOstNom->DM->DocTKOLOSNT->AsFloat=DM->DocTKOLFAKT_INVT->AsFloat
//								- DM->DocTKOLUCH_INVT->AsFloat;
//				DocOstNom->DM->DocT->Post();
//				}
//
//		DM->DocT->Next();
//		}
//
//DocOstNom->EditFirma->Text=DM->DocAllNAMEFIRM->AsString;
//DocOstNom->EditSklad->Text=DM->DocAllNAMESKLAD->AsString;
//DocOstNom->PosDoc->DateTime=DocOstNom->DM->DocAllPOSDOC->AsDateTime;

DocOstNom->UpdateForm();

}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void TFormaDocInv::OpenPrintFormPrice(void)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
porNumStr=1;
PrintForm->SS->BeginUpdate();

//шапка
OutputZagolovokReportPrice(PrintForm);

//таблица
SummaReport=0;
DM->DocT->First();
while(!DM->DocT->Eof)
        {

        OutputStringPrice(PrintForm);numRow++; porNumStr++;

        DM->DocT->Next();
        }

OutputPodavalReportPrice(PrintForm);
PrintForm->SS->EndUpdate();
PrintForm->Show();
}
//---------------------------------------------------------------------------
void TFormaDocInv::OutputZagolovokReportPrice(TSheetEditor *prForm)
{
prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";
prForm->SS->RowsAutoHeight=true;

        TcxSSHeader *cHeader;
        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 40;
        cHeader->Size[2] = 200;
        cHeader->Size[3] = 80;
        cHeader->Size[4] = 60;
        cHeader->Size[5] = 80;
        cHeader->Size[6] = 80;
        cHeader->Size[7] = 80;
        cHeader->Size[8] = 100;
        //delete  cHeader;
numRow=2;
numCol=1;

TcxSSCellObject *cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = DM->DocAllFNAMEFIRM->AsString
        +" ИНН "+DM->DocAllINNFIRM->AsString;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Адрес: "+DM->DocAllPADRFIRM->AsString;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Склад: "+DM->DocAllNAMESKLAD->AsString;
delete cell;
numRow++; numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Инвентаризация №"+DM->DocAllNUMDOC->AsString+" от "
                +DateToStr(DM->DocAllPOSDOC->AsDateTime);
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;
numRow++; numRow++;



//заголовок таблицы
numCol=1;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "№";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Наименование";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Единица";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "К";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Кол. уч.";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Кол. факт.";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Цена";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Сумма факт.";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;
}
//------------------------------------------------------------------------------
void TFormaDocInv::OutputStringPrice(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = IntToStr(porNumStr);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = DM->DocTNAMENOM->AsString;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaJUSTIFY;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = DM->DocTNAMEED->AsString;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(DM->DocTKF_INVT->AsFloat,ffFixed,10,3);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (DM->DocTKOLUCH_INVT->AsFloat!=0)
        {
		cell->Text=FloatToStrF(DM->DocTKOLUCH_INVT->AsFloat,ffFixed,10,3);
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if( DM->DocTKOLFAKT_INVT->AsFloat!=0)
        {
		cell->Text=FloatToStrF(DM->DocTKOLFAKT_INVT->AsFloat,ffFixed,10,3);
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//цена
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);

		if(DM->DocTPRICE_INVT->AsFloat>0)
                {
				cell->Text=FloatToStrF(DM->DocTPRICE_INVT->AsFloat,ffFixed,10,2);
				}
		cell->Style->HorzTextAlign = haRIGHT;
		cell->Style->VertTextAlign = vaCENTER;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		cell->Style->Borders->Edges [eTop]->Style=lsThin;
		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
		numCol++;

		//сумма
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		if( DM->DocTSUMF_INVT->AsFloat>0)
                {
				cell->Text=FloatToStrF(DM->DocTSUMF_INVT->AsFloat,ffFixed,10,2);
				SummaReport=SummaReport+DM->DocTSUMF_INVT->AsFloat;
                }
		cell->Style->HorzTextAlign = haRIGHT;
		cell->Style->VertTextAlign = vaCENTER;
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
		cell->Style->Borders->Edges [eRight]->Style=lsThin;
		cell->Style->Borders->Edges [eTop]->Style=lsThin;
		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
				numCol++;

}


//------------------------------------------------------------------------------
void TFormaDocInv::OutputPodavalReportPrice(TSheetEditor *prForm)
{
numCol=1;

TcxSSCellObject *cell;
numCol=1;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Всего";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//цена
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(SummaReport,ffFixed,10,2);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="ВСЕГО: "+glCurrencyPropis(SummaReport);
cell->Style->Font->Size = 10;
delete cell;
numRow++;numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Комиссия     ______________________________________________ ";
delete cell;
numRow++;numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="             ______________________________________________ ";
delete cell;
numRow++;numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="             ______________________________________________ ";
delete cell;
numRow++;numRow++;

}
//---------------------------------------------------------------



void TFormaDocInv::OpenFormSpiskaSprInfBase(void)
{
if (Prosmotr==true) return;
if (DM->DocAllIDBASE_GALLDOC->ReadOnly==true) return;
if (FormaSpiskaSprInfBase==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprInfBase.1",IID_IFormaSpiskaSprInfBase,
													(void**)&FormaSpiskaSprInfBase);
		FormaSpiskaSprInfBase->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprInfBase->Vibor=true;
		FormaSpiskaSprInfBase->NumberProcVibor=ViborInfBase;
        FormaSpiskaSprInfBase->DM->OpenTable();
        }
}
//---------------------------------------------------------------------
void __fastcall TFormaDocInv::AddAllTovarToolButtonClick(TObject *Sender)
{
if (Prosmotr==true) return;
DM->pFIBQ->Close();
DM->pFIBQ->SQL->Clear();
DM->pFIBQ->SQL->Add( "select IDNOM, CODENOM, NAMENOM, TNOM, IDED, KFED, NAMEED");
DM->pFIBQ->SQL->Add( " from   SNOM");
DM->pFIBQ->SQL->Add( " left outer join SED on IDBASEDNOM=IDED");
DM->pFIBQ->SQL->Add( " where TNOM=0");
DM->pFIBQ->SQL->Add( " order by NAMENOM");

DM->pFIBQ->ExecQuery();

while(!DM->pFIBQ->Eof)
        {
        DM->AddDocNewString();
        DM->DocT->Edit();

				DM->DocTIDNOM_INVT->AsString=DM->pFIBQ->FieldByName("IDNOM")->AsInt64;
				DM->DocTCODENOM->AsInteger=DM->pFIBQ->FieldByName("CODENOM")->AsInteger;
				DM->DocTNAMENOM->AsString=DM->pFIBQ->FieldByName("NAMENOM")->AsString;
				DM->DocTTNOM->AsInteger=DM->pFIBQ->FieldByName("TNOM")->AsInteger;

				DM->DocTIDED_INVT->AsString=DM->pFIBQ->FieldByName("IDED")->AsInt64;
				DM->DocTNAMEED->AsString=DM->pFIBQ->FieldByName("NAMEED")->AsString;
				DM->DocTKF_INVT->AsFloat=DM->pFIBQ->FieldByName("KFED")->AsFloat;

				IDMSprPrice * DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
				DMSprPrice->FindElement( glStrToInt64(DM->DocIDTPRICE_INV->AsString),
											 glStrToInt64(DM->DocTIDNOM_INVT->AsString));
                DM->DocTPRICE_INVT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
                                                        DM->DocTKF_INVT->AsFloat;
                DMSprPrice->kanRelease();

        DM->DocT->Post();
		DM->pFIBQ->Next();
        }

DM->pFIBQ->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocInv::AddOstatkiToolButtonClick(TObject *Sender)
{
if (Prosmotr==true) return;
DM->pFIBQ->Close();
DM->pFIBQ->SQL->Clear();
DM->pFIBQ->SQL->Add( "select IDNOM, CODENOM, NAMENOM, IDED, NAMEED, KFED, sum(rgostnom.kolostnom)");
DM->pFIBQ->SQL->Add( " from rgostnom");
DM->pFIBQ->SQL->Add( " left outer join SNOM on IDNOM=rgostnom.idnomostnom");
DM->pFIBQ->SQL->Add( " left outer join sed on sed.ided=snom.idbasednom");
DM->pFIBQ->SQL->Add( " where rgostnom.idsklostnom='"+DM->DocAllIDSKLDOC->AsString+"'");
DM->pFIBQ->SQL->Add( " group by IDNOM, CODENOM, NAMENOM, IDED, NAMEED, KFED");
DM->pFIBQ->SQL->Add( " order by NAMENOM");


DM->pFIBQ->ExecQuery();

while(!DM->pFIBQ->Eof)
        {
        DM->AddDocNewString();
        DM->DocT->Edit();

				DM->DocTIDNOM_INVT->AsString=DM->pFIBQ->FieldByName("IDNOM")->AsInt64;
				DM->DocTCODENOM->AsInteger=DM->pFIBQ->FieldByName("CODENOM")->AsInteger;
				DM->DocTNAMENOM->AsString=DM->pFIBQ->FieldByName("NAMENOM")->AsString;
                //DM->DocTTNOM->AsInteger=DM->IBQ->FieldByName("TNOM")->AsInteger;

				DM->DocTIDED_INVT->AsString=DM->pFIBQ->FieldByName("IDED")->AsInt64;
				DM->DocTNAMEED->AsString=DM->pFIBQ->FieldByName("NAMEED")->AsString;
				DM->DocTKF_INVT->AsFloat=DM->pFIBQ->FieldByName("KFED")->AsFloat;
				DM->DocTKOLUCH_INVT->AsFloat= DM->pFIBQ->FieldByName("SUM")->AsFloat;
				IDMSprPrice * DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDTPRICE_INV->AsString),
                                             glStrToInt64(DM->DocTIDNOM_INVT->AsString));
                        DM->DocTPRICE_INVT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
                                                        DM->DocTKF_INVT->AsFloat;
				DMSprPrice->kanRelease();



        DM->DocT->Post();
		DM->pFIBQ->Next();
        }

DM->pFIBQ->Close();
}
//---------------------------------------------------------------------------


void TFormaDocInv::OpenPrintFormPoGrp(void)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
porNumStr=1;

PrintForm->SS->BeginUpdate();
//шапка
OutputZagolovokReport(PrintForm);

//таблица
DM->IBQPoGrp->Active=false;
DM->IBQPoGrp->ParamByName("PARAM_IDDOC")->AsString=DM->DocAllIDDOC->AsString;
DM->IBQPoGrp->Active=true;

int id_tec_grp=0;

DM->IBQPoGrp->First();
while(!DM->IBQPoGrp->Eof)
        {
		if (id_tec_grp==DM->IBQPoGrpIDGN->AsInt64)
                {
                porNumStr++;
                }
        else      //новая группа
                {
                OutputStringGroupReportPoGrp(PrintForm);
				id_tec_grp=DM->IBQPoGrpIDGN->AsInt64;
                }

        OutputStringReportPoGrp(PrintForm);
        DM->IBQPoGrp->Next();
        }

OutputPodavalReport(PrintForm);
PrintForm->SS->EndUpdate();
DM->IBQPoGrp->Active=false;
PrintForm->Show();



}
//---------------------------------------------------------------------------
void TFormaDocInv::OutputStringGroupReportPoGrp(TSheetEditor *prForm)
{
porNumStr=1;
TcxSSCellObject *cell;
numCol=1;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;


cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="";
cell->Style->HorzTextAlign = haLEFT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->WordBreak = true;
cell->Style->Font->Size = 10;
cell->Text =DM->IBQPoGrpNAMEGN->AsString;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Style = TFontStyles() << fsBold;
//cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="";
cell->Style->HorzTextAlign = haLEFT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
cell->Text="";

delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="";
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;

numRow++;
}
//---------------------------------------------------------------------------
void TFormaDocInv::OutputStringReportPoGrp(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text =IntToStr(porNumStr);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;


cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text =DM->IBQPoGrpCODENOM->AsString;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->WordBreak = true;
//cell->Style->Font->Size = 8;
cell->Text =DM->IBQPoGrpNAMENOM->AsString;
cell->Style->HorzTextAlign = haLEFT;
//cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text =FloatToStrF(DM->IBQPoGrpPRICE_INVT->AsFloat, ffFixed, 15,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text =DM->IBQPoGrpNAMEED->AsString;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text =FloatToStrF(DM->IBQPoGrpKF_INVT->AsFloat,ffFixed,10,3);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

if (DM->IBQPoGrpKOLUCH_INVT->AsFloat!=0)
        {
        cell->Text=FloatToStrF(DM->IBQPoGrpKOLUCH_INVT->AsFloat,ffFixed,10,3);
        }
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
if( DM->IBQPoGrpKOLFAKT_INVT->AsFloat!=0)
        {
        cell->Text=FloatToStrF(DM->IBQPoGrpKOLFAKT_INVT->AsFloat,ffFixed,10,3);
        }
delete cell;
numCol++;


numRow++;
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocInv::VibGrpComboBoxChange(TObject *Sender)
{
if(DM->ChangeTable==true)
        {
        String V="Записать измененения документа?";
        String Z="Записать";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
                {
                DM->SaveDoc();
                }
        }

__int64 id_doc=glStrToInt64(DM->DocAllIDDOC->AsString);

DM->OpenDoc(id_doc);
//UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocInv::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("DocInv");	
}
//---------------------------------------------------------------------------
void TFormaDocInv::OpenFormSpiskaSprSprInv(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprInv==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprInv.1",IID_IFormaSpiskaSprInv,
													(void**)&FormaSpiskaSprInv);
		FormaSpiskaSprInv->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprInv->Vibor=true;
		FormaSpiskaSprInv->NumberProcVibor=ViborInv;
		FormaSpiskaSprInv->UpdateForm();
		}
}
//-----------------------------------------------------------------------------


void __fastcall TFormaDocInv::ToolButtonAddDataRevClick(TObject *Sender)
{
DM->AddDataRev();	
}
//---------------------------------------------------------------------------





void __fastcall TFormaDocInv::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;

		OpenFSSprNom();
		EditRekvisit=Tovar;

}
//---------------------------------------------------------------------------

void __fastcall TFormaDocInv::NamecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprFirm();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocInv::cxDBButtonEdit1PropertiesButtonClick(
	  TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprSklad();
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocInv::TypeInvcxComboBoxPropertiesChange(TObject *Sender)
{
if (flObrabatChangeTypeInv==false) return;
DM->Doc->Edit();
DM->DocTYPE_INV->AsInteger=TypeInvComboBox->ItemIndex;
DM->Doc->Post();
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocInv::NameInvcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprSprInv();		
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocInv::NameInfcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprInfBase();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocInv::cxButtonPoGrpClick(TObject *Sender)
{
OpenPrintFormPoGrp() ;	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocInv::cxButtonPrintFaktOstClick(TObject *Sender)
{
OpenPrintFormPrice() ;	
}
//---------------------------------------------------------------------------







void __fastcall TFormaDocInv::TypePriceComboBoxPropertiesChange(TObject *Sender)
{
if (flObrabatChangeTypePrice==false) return;
FindNextControl(ActiveControl,true,true,false)->SetFocus();

 if (Prosmotr==true)
        {
		UpdateForm();
         return;
		}

if (NoEdit==true)
        {
		UpdateForm();
         return;
		}

if (DM->IdGrpNom!=0)
        {
		TypePriceComboBox->ItemIndex=DMSprTypePrice->GetIndexTypePricePoId(glStrToInt64(DM->DocIDTPRICE_INV->AsString))-1;
        ShowMessage("Изменять тип цен можно только при отключенной фильтрации по группам номенклатуры!");
		return;
        }

if ( TypePriceComboBox->ItemIndex!=0)
		{
        DMSprTypePrice->Table->First();
		DMSprTypePrice->Table->MoveBy(TypePriceComboBox->ItemIndex-1);
        DM->Doc->Edit();
		DM->DocIDTPRICE_INV->AsInteger=DMSprTypePrice->TableID_TPRICE->AsInt64;
		DM->Doc->Post();
		}
else
	{
	ShowMessage("Тип цен должен быть задан обязательно!");
	UpdateForm();
	return;
	}

//проверим есть ли строки
if(DM->DocT->RecordCount>0)
		{
        String V="В табличной части документа есть строки. Пересчитать цены?";
		String Z="Пересчитать цены?";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
				{
				IDMSprPrice * DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
				DM->DocT->First();
				while(!DM->DocT->Eof)
						{
						DM->DocT->Edit();
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDTPRICE_INV->AsString),
											 glStrToInt64(DM->DocTIDNOM_INVT->AsString));
						DM->DocTPRICE_INVT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKF_INVT->AsFloat;
						DM->DocT->Post();
						DM->DocT->Next();
						}
				DMSprPrice->kanRelease();
				}
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocInv::NumDoccxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocInv::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocInv::PrimcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocInv::ActionInsertRecordExecute(TObject *Sender)
{
if (Prosmotr==true) return;
ActionOperation=aoAddNewString;
OpenFSSprNom();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocInv::ActionDeleteRecordExecute(TObject *Sender)
{
if (Prosmotr==true) return;
DM->DeleteStringDoc();	
}
//---------------------------------------------------------------------------


void TFormaDocInv::OpenPrintFormPoGrpPrice(void)
{
AllSumNedostacha=0;
AllSumIslishek=0;
AllSumFact=0;
AllSumUch=0;
AllResult=0;

TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
porNumStr=1;
numRowGrp=0;

PrintForm->SS->BeginUpdate();
//шапка
OutputZagolovokReportPoGrpPrice(PrintForm);

//таблица
DM->IBQPoGrp->Active=false;
DM->IBQPoGrp->ParamByName("PARAM_IDDOC")->AsString=DM->DocAllIDDOC->AsString;
DM->IBQPoGrp->Active=true;

int id_tec_grp=0;

DM->IBQPoGrp->First();
while(!DM->IBQPoGrp->Eof)
        {
		if (id_tec_grp==DM->IBQPoGrpIDGN->AsInt64)
                {
                porNumStr++;
                }
        else      //новая группа
				{
				OutputStringItogiGroupReportPoGrpPrice(PrintForm);
				OutputStringGroupReportPoGrpPrice(PrintForm);

				GrpSumNedostacha=0;
				GrpSumIslishek=0;
				GrpSumFact=0;
				GrpSumUch=0;
				GrpResult=0;
				id_tec_grp=DM->IBQPoGrpIDGN->AsInt64;
                }

        OutputStringReportPoGrpPrice(PrintForm);
        DM->IBQPoGrp->Next();
		}
		
OutputStringItogiGroupReportPoGrpPrice(PrintForm);
OutputPodavalReportPoGrpPrice(PrintForm);
PrintForm->SS->EndUpdate();
DM->IBQPoGrp->Active=false;
PrintForm->Show();



}
//---------------------------------------------------------------------------
void TFormaDocInv::OutputZagolovokReportPoGrpPrice(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
prForm->SS->DefaultStyle->Font->Size=8;
prForm->SS->DefaultStyle->Font->Name="Arial";
prForm->SS->RowsAutoHeight=true;

        TcxSSHeader *cHeader;
        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 40;
		cHeader->Size[2] = 50;
        cHeader->Size[3] = 180;
        cHeader->Size[4] = 70;
        cHeader->Size[5] = 80;
        cHeader->Size[6] = 50;
		cHeader->Size[7] = 60;
		cHeader->Size[8] = 60;
		cHeader->Size[9] = 60;
		cHeader->Size[10] = 60;
		cHeader->Size[11] = 60;
		cHeader->Size[12] = 60;
		cHeader->Size[13] = 60;
		cHeader->Size[14] = 60;
		cHeader->Size[15] = 60;

numRow=2;
numCol=1;


cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = DM->DocAllFNAMEFIRM->AsString
        +" ИНН "+DM->DocAllINNFIRM->AsString;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="Адрес: "+DM->DocAllPADRFIRM->AsString;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="Склад: "+DM->DocAllNAMESKLAD->AsString;
delete cell;
numRow++; numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol+1, numRow);
cell->Text ="Инвентаризация №"+DM->DocAllNUMDOC->AsString+" от "
				+DateToStr(DM->DocAllPOSDOC->AsDateTime);
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;
numRow++; numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="Тип цен: "+TypePriceComboBox->Text;
delete cell;
numRow++;

//заголовок таблицы
numCol=1;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "№";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//код
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Код";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Наименование";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Цена";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Единица";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "К";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="Кол. уч.";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="Кол. факт.";
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="Сумма. уч.";
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="Сумма факт.";
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="Недостача кол.";
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="Недостача сум.";
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="Излишек кол.";
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="Излишек  сум.";
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="Результат";
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
numRow++;
}

//---------------------------------------------------------------------------
void TFormaDocInv::OutputStringGroupReportPoGrpPrice(TSheetEditor *prForm)
{
porNumStr=1;
TcxSSCellObject *cell;
numCol=1;

numRowGrp=numRow;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;


cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="";
cell->Style->HorzTextAlign = haLEFT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->WordBreak = true;
//cell->Style->Font->Size = 10;
cell->Text =DM->IBQPoGrpNAMEGN->AsString;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Style = TFontStyles() << fsBold;
//cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="";
cell->Style->HorzTextAlign = haLEFT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
cell->Text="";

delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="";
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="";
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="";
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="";
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="";
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="";
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="";
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="";
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
numRow++;


//заголовок таблицы
numCol=1;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "№";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//код
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Код";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Наименование";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Цена";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Единица";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "К";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="Кол. уч.";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="Кол. факт.";
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="Сумма. уч.";
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="Сумма факт.";
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="Недостача кол.";
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="Недостача сум.";
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="Излишек кол.";
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="Излишек  сум.";
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="Результат";
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
numRow++;
}
//---------------------------------------------------------------------------
void TFormaDocInv::OutputStringReportPoGrpPrice(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text =IntToStr(porNumStr);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;


cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text =DM->IBQPoGrpCODENOM->AsString;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->WordBreak = true;
cell->Style->Font->Size = 8;
cell->Text =DM->IBQPoGrpNAMENOM->AsString;
cell->Style->HorzTextAlign = haLEFT;
//cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text =FloatToStrF(DM->IBQPoGrpPRICE_INVT->AsFloat, ffFixed, 15,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text =DM->IBQPoGrpNAMEED->AsString;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text =FloatToStrF(DM->IBQPoGrpKF_INVT->AsFloat,ffFixed,10,3);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//кол уч
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

if (DM->IBQPoGrpKOLUCH_INVT->AsFloat!=0)
        {
		cell->Text=FloatToStrF(DM->IBQPoGrpKOLUCH_INVT->AsFloat,ffFixed,10,3);
        }
delete cell;
numCol++;

//кол факт
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
if( DM->IBQPoGrpKOLFAKT_INVT->AsFloat!=0)
		{
		cell->Text=FloatToStrF(DM->IBQPoGrpKOLFAKT_INVT->AsFloat,ffFixed,10,3);
		}
delete cell;
numCol++;

//сумма уч
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

cell->Text=FloatToStrF(DM->IBQPoGrpKOLUCH_INVT->AsFloat*
				DM->IBQPoGrpPRICE_INVT->AsFloat,ffFixed,10,2);

AllSumUch=AllSumUch+DM->IBQPoGrpKOLUCH_INVT->AsFloat*
				DM->IBQPoGrpPRICE_INVT->AsFloat;
GrpSumUch=GrpSumUch+DM->IBQPoGrpKOLUCH_INVT->AsFloat*
				DM->IBQPoGrpPRICE_INVT->AsFloat;
delete cell;
numCol++;



//сумма факт
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

cell->Text=FloatToStrF(DM->IBQPoGrpKOLFAKT_INVT->AsFloat*
				DM->IBQPoGrpPRICE_INVT->AsFloat,ffFixed,10,2);

AllSumFact=AllSumFact+DM->IBQPoGrpKOLFAKT_INVT->AsFloat*
				DM->IBQPoGrpPRICE_INVT->AsFloat;
GrpSumFact=GrpSumFact+DM->IBQPoGrpKOLFAKT_INVT->AsFloat*
				DM->IBQPoGrpPRICE_INVT->AsFloat;

delete cell;
numCol++;

double kol=0;
double sum_ned=0;

if (glCompareDoubleValue(DM->IBQPoGrpKOLUCH_INVT->AsFloat,
						 DM->IBQPoGrpKOLFAKT_INVT->AsFloat,
						 4)==1)
	{ //недостача
	kol=DM->IBQPoGrpKOLUCH_INVT->AsFloat-
						DM->IBQPoGrpKOLFAKT_INVT->AsFloat;

	sum_ned=DM->IBQPoGrpKOLUCH_INVT->AsFloat*
				DM->IBQPoGrpPRICE_INVT->AsFloat-
				DM->IBQPoGrpKOLFAKT_INVT->AsFloat*
				DM->IBQPoGrpPRICE_INVT->AsFloat;
	AllSumNedostacha=AllSumNedostacha+sum_ned;
	GrpSumNedostacha=GrpSumNedostacha+sum_ned;

	}

//недостача кол
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

if (kol!=0)
	{
	cell->Text=FloatToStrF(kol,ffFixed,10,3);
	}
delete cell;
numCol++;
//недостача сум
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

if (sum_ned!=0)
	{
	cell->Text=FloatToStrF(sum_ned,ffFixed,10,2);
	}
delete cell;
numCol++;


kol=0;
double sum_isl=0;

if (glCompareDoubleValue(DM->IBQPoGrpKOLFAKT_INVT->AsFloat,
						 DM->IBQPoGrpKOLUCH_INVT->AsFloat,
						 4)==1)
	{ //излишек
	kol=DM->IBQPoGrpKOLFAKT_INVT->AsFloat-
					DM->IBQPoGrpKOLUCH_INVT->AsFloat;

	sum_isl=DM->IBQPoGrpKOLFAKT_INVT->AsFloat*
				DM->IBQPoGrpPRICE_INVT->AsFloat-
				DM->IBQPoGrpKOLUCH_INVT->AsFloat*
				DM->IBQPoGrpPRICE_INVT->AsFloat;

	AllSumIslishek=AllSumIslishek+sum_isl;
	GrpSumIslishek=GrpSumIslishek+sum_isl;
	}

//излишек кол
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

if (kol!=0)
	{
	cell->Text=FloatToStrF(kol,ffFixed,10,3);
	}
delete cell;
numCol++;

//излишек сумм
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

if (sum_isl!=0)
	{
	cell->Text=FloatToStrF(sum_isl,ffFixed,10,2);
	}
delete cell;
numCol++;

double sum_res=0;

sum_res=sum_isl-sum_ned;
AllResult=AllResult+sum_res;
GrpResult=GrpResult+sum_res;

//результат сумм
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

if (sum_res!=0)
	{
	cell->Text=FloatToStrF(sum_res,ffFixed,10,2);
	}
delete cell;
numCol++;

numRow++;
}
//---------------------------------------------------------------------------
void TFormaDocInv::OutputStringItogiGroupReportPoGrpPrice(TSheetEditor *prForm)
{
if (numRowGrp==0) return;
TcxSSCellObject *cell;
if(GrpSumUch!=0)
        {
		cell = prForm->SS->ActiveSheet->GetCellObject(9, numRowGrp);
		cell->Text = FloatToStrF(GrpSumUch,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
		//cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(GrpSumFact!=0)
        {
		cell = prForm->SS->ActiveSheet->GetCellObject(10, numRowGrp);
		cell->Text = FloatToStrF(GrpSumFact,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
		//cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(GrpSumNedostacha!=0)
        {
		cell = prForm->SS->ActiveSheet->GetCellObject(12, numRowGrp);
		cell->Text = FloatToStrF(GrpSumNedostacha,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
		//cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(GrpSumIslishek!=0)
		{
		cell = prForm->SS->ActiveSheet->GetCellObject(14, numRowGrp);
		cell->Text = FloatToStrF(GrpSumIslishek,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        //cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
		}

if(GrpResult!=0)
		{
		cell = prForm->SS->ActiveSheet->GetCellObject(15, numRowGrp);
		cell->Text = FloatToStrF(GrpResult,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        //cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
		}

prForm->SS->ActiveSheet->Rows->Size[numRowGrp] = 30;



}
//----------------------------------------------------------------------------
void TFormaDocInv::OutputPodavalReportPoGrpPrice(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
TRect rect;
numCol=1;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;


cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haLEFT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="Всего:";
cell->Style->HorzTextAlign = haLEFT;
//cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haLEFT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//кол уч
rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol+1;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Уч.:"+FloatToStrF(AllSumUch,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

delete cell;
numCol++;   

//кол факт
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//сумма уч
rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol+1;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Факт.:"+FloatToStrF(AllSumFact,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;


delete cell;
numCol++;

//сумма факт
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

delete cell;
numCol++;

//недостача кол

rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol+1;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(AllSumNedostacha,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;


delete cell;
numCol++;
//недостача сум
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;



delete cell;
numCol++;

//излишек кол

rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol+1;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(AllSumIslishek,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

delete cell;
numCol++;

//излишек сумм
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

numCol++;

//рез сумм
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(AllResult,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

delete cell;
numCol++;


numCol=1;

numRow++;numRow++;


cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Комиссия     ______________________________________________ ";
delete cell;
numRow++;numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="             ______________________________________________ ";
delete cell;
numRow++;numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="             ______________________________________________ ";
delete cell;
numRow++;numRow++;

}
//---------------------------------------------------------------
//----------------------------------------------------------------------------
void __fastcall TFormaDocInv::cxButton1Click(TObject *Sender)
{
OpenPrintFormPoGrpPrice() ;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaDocInv::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaDocInv::RunExternalModule(__int64 id_module, int type_module)
{
IFormaRunExternalModule * module;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaRunExternalModule.1",IID_IFormaRunExternalModule,
													(void**)&module);
module->Init(InterfaceMainObject,InterfaceImpl);
module->IdModule=id_module;
module->TypeTable=1;

module->ClearModule();
module->LoadModule();


//добавляем текущий модуль
//TScriptDMDocRealRozn * scr_doc;
if (type_module==1 || type_module==2)
	{
//
//	//надо добавить класс TScriptDMDocRealRozn
//	//методы для работы с документом
//	scr_doc=new TScriptDMDocRealRozn();
//	scr_doc->AddClassesInScript(module);
//	//надо добавить текущий DM
//	scr_doc->DM=DM;
//	module->fsScript1->AddObject("TecDMDocRealRozn",scr_doc);
	}


//надо добавить переменные модуля, как минимум  IDDOC
module->SetInt64Variables("glIdDoc", glStrToInt64(DM->DocAllIDDOC->AsString));

module->ExecuteModule();

}
//---------------------------------------------------------------------------
void __fastcall TFormaDocInv::ActionDvRegExecute(TObject *Sender)
{
if (Prosmotr==true) return;
__int64 id_doc=glStrToInt64(DM->DocAllIDDOC->AsString);
if (DM->SaveDoc()==true)
		{
		if (DM->DvRegDoc()==true)
				{
				DM->OpenDoc(id_doc);
				}
		else
			{
			ShowMessage("Ошибка при проведении документа: "+DM->TextError);
			}
		UpdateForm();
		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocInv::ActionCloseExecute(TObject *Sender)
{
		DM->DocAll->CancelUpdates();
		DM->Doc->CancelUpdates();
		DM->DocT->CancelUpdates();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocInv::ActionOKExecute(TObject *Sender)
{
if (Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{
		if (DM->DvRegDoc()==true)
				{
				Close();
				}
		else
			{
			ShowMessage("Ошибка при проведении документа: "+DM->TextError);
			}
		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocInv::ActionPrintExecute(TObject *Sender)
{
OpenPrintForm() ;
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocInv::ActionSaveExecute(TObject *Sender)
{
if (Prosmotr==true) return;

if (DM->SaveDoc()==true)
		{
		 UpdateForm();
		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------
void TFormaDocInv::NewDoc(void){}
void TFormaDocInv::OpenDoc(void){}
bool TFormaDocInv::SaveDoc(void) {return true;}
bool TFormaDocInv::DvRegDoc(void){return true;}
bool TFormaDocInv::CancelDvDoc(void){return true;}

