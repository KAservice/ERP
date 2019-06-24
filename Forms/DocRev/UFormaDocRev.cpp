//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

//--------------------------------------------------------------------------
#include "UFormaDocRev.h"
#include "IFormaDocSpisNom.h"
#include "IFormaDocOstNom.h"
#include "IObjectBarCode.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IAsyncExternalEvent.h"
#include "IDMQueryRead.h"
#include "IFormaDocPer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtonEdit"
#pragma link "cxCalc"
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
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxContainer"
#pragma link "cxDBEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxCalendar"
#pragma link "cxLabel"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaDocRev::TFormaDocRev(TComponent* Owner)
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
bool TFormaDocRev::Init(void)
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


	//зарегистрируем свой IAsyncExternalEvent в главном модуле для получения событий
	if(InterfaceMainObject)
		{
		IAsyncExternalEvent * interf=0;
		InterfaceMainObject->kanQueryInterface(IID_IAsyncExternalEvent,(void**)&interf);
		if (interf)
			{
			interf->SetInterfaceForAsyncExternalEvent(InterfaceImpl);
			interf->kanRelease();
			}
		}
	}

InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRev.1",IID_IDMDocRev, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice, (void**)&DMSprPrice);
DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceDocT;
NameUserDBText->DataSource=DM->DataSourceDocAll;


NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameSkladcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NumDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PrefiksNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;

NameInvcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
DescrcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;


Prosmotr=false;    //только просмотр
NoEdit=false;
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи
VibTovarId=0;
VibTovarIdGrp=0;
IdTypePrice=0;
ActionOperation=aoNO;

flObrabatChangeTypePrice=false;


InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice,
					 (void**)&DMSprTypePrice);
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
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaDocRevImpl),false);
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


//ПРИВЕЛЕГИИ
DM_Connection->GetPrivForm(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//----------------------------------------------------------------------------
int TFormaDocRev::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void TFormaDocRev::UpdateForm(void)
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
        //ProsmotrLabel->Visible=true;
		cxGrid1DBTableView1->OptionsData->Editing=false;
        }
else
        {
        //ProsmotrLabel->Visible=false;
        cxGrid1DBTableView1->OptionsData->Editing=true;
        }

flObrabatChangeTypePrice=false;
TypePriceComboBox->ItemIndex=DMSprTypePrice->GetIndexTypePricePoId(glStrToInt64(DM->DocIDRTPRICE_DREV->AsString));
flObrabatChangeTypePrice=true;;
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocRev::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(Nom)Nom->kanRelease();
if(Firma)Firma->kanRelease();
if(Sklad)Sklad->kanRelease();
if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
if(FormaSpiskaSprInv)FormaSpiskaSprInv->kanRelease();
if(FormaViborGrpNomSpr)FormaViborGrpNomSpr->kanRelease();

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


DMTableExtPrintForm->kanRelease();
DM->kanRelease();
DMSprPrice->kanRelease();
Action=caFree;
}
//---------------------------------------------------------------------------
int TFormaDocRev::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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
				DM->DocTIDNOM_DREVT->AsString=Nom->DM->ElementIDNOM->AsString;
				DM->DocTCODENOM->AsInteger=Nom->DM->ElementCODENOM->AsInteger;
				DM->DocTNAMENOM->AsString=Nom->DM->ElementNAMENOM->AsString;
				DM->DocTTNOM->AsInteger=Nom->DM->ElementTNOM->AsInteger;

				DM->DocTIDED_DREVT->AsString=Nom->DM->ElementIDBASEDNOM->AsString;
				DM->DocTNAMEED->AsString=Nom->DM->BasEdNAMEED->AsString;
				DM->DocTKF_DREVT->AsFloat=Nom->DM->BasEdKFED->AsFloat;

				IDMSprPrice * DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDRTPRICE_DREV->AsString),
											 glStrToInt64(DM->DocTIDNOM_DREVT->AsString));
						DM->DocTRPRICE_DREVT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKF_DREVT->AsFloat;
				DMSprPrice->kanRelease();

				DM->DocT->Post();

				VibTovarId=glStrToInt64(Nom->DM->ElementIDNOM->AsString);
				VibTovarIdGrp=glStrToInt64(Nom->DM->ElementIDGRPNOM->AsString);
				}
		Nom=0;

		cxGrid1->SetFocus();
		cxGrid1DBTableView1KOL_DREVT->Selected=true;
		}

if (number_procedure_end==Edinica)
        {
		cxGrid1->SetFocus();
		cxGrid1DBTableView1RPRICE_DREVT->Selected=true;
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
				DM->DocAllIDBASE_GALLDOC->AsString=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsString;
                DM->DocAllNAME_SINFBASE_OBMEN->AsString=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;
                DM->DocAll->Post();
                }
		FormaSpiskaSprInfBase=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}

if (number_procedure_end==InvRekvisit)
		{
		if (type_event==1)
				{
				DM->Doc->Edit();
				DM->DocIDINV_DREV->AsString=FormaSpiskaSprInv->DM->TableID_SINV->AsString;
				DM->DocNAME_SINV->AsString=FormaSpiskaSprInv->DM->TableNAME_SINV->AsString;
				DM->Doc->Post();
				}
		FormaSpiskaSprInv=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}

if (number_procedure_end==InputCodeNom)
		{
		if (type_event==1)
				{
				EndInputCodeNom();
				}
		FormaInputCode=0;
		}

if (number_procedure_end==ViborGrpNom)
		{
		if (type_event==1)
				{
				EndViborGrpNom();
				}
		FormaViborGrpNomSpr=0;
		}

if (number_procedure_end==ER_AddAllNomIsGrp)
		{
		if (type_event==1)
				{
				EndViborGrpNomForAddAllNom();
				}
		FormaViborGrpNomSpr=0;
		}

ActionOperation=aoNO;
return -1;
}
//----------------------------------------------------------------------------
void  TFormaDocRev::OpenFSSprNom()
{
if (Prosmotr==true) return;
if (Nom==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&Nom);
		Nom->Init(InterfaceMainObject,InterfaceImpl);
		Nom->NumberProcVibor=Tovar;
		Nom->Vibor=true;
//		Nom->HintLabel->Caption="Выберите номенклатуру для документа Ревизия №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		Nom->IdNom=glStrToInt64(DM->DocTIDNOM_DREVT->AsString);
		Nom->DM->IdTypePrice=glStrToInt64(DM->DocIDRTPRICE_DREV->AsString);
        Nom->UpdateForm();
        }
}

//----------------------------------------------------------------------------





void    TFormaDocRev::OpenFormSpiskaSprFirm(void)
{
if (Prosmotr==true) return;
if (Firma==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&Firma);
		Firma->Init(InterfaceMainObject,InterfaceImpl);
		Firma->NumberProcVibor=FirmaRekvisit;
		Firma->Vibor=true;
        Firma->DM->OpenTable();
//		Firma->HintLabel->Caption="Выберите фирму для документа Ревизия №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
        }

}
//---------------------------------------------------------------------------
void  TFormaDocRev::OpenFormSpiskaSprSklad(void)
{
if (Prosmotr==true) return;
if (Sklad==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&Sklad);
		Sklad->Init(InterfaceMainObject,InterfaceImpl);
		Sklad->NumberProcVibor=SkladRekvisit;
		Sklad->Vibor=true;
        Sklad->DM->OpenTable();
//		Sklad->HintLabel->Caption="Выберите склад для документа Ревизия №"
//        +DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
        }

}
//-----------------------------------------------------------------------------


void __fastcall TFormaDocRev::AddNewStringClick(TObject *Sender)
{
if (Prosmotr==true) return;
ActionOperation=aoAddNewString;
OpenFSSprNom();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRev::DeleteStringClick(TObject *Sender)
{
if (Prosmotr==true) return;
DM->DeleteStringDoc();
}

//----------------------------------------------------------------------------

void TFormaDocRev::OpenPrintForm(void)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
porNumStr=1;
SumDoc=0;

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
void TFormaDocRev::OutputZagolovokReport(TSheetEditor *prForm)
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
cell->Text ="Ревизия №"+DM->DocAllNUMDOC->AsString+" от "
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
cell->Text ="Кол.";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="Сумма";
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
void TFormaDocRev::OutputString(TSheetEditor *prForm)
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
cell->Text =FloatToStrF(DM->DocTRPRICE_DREVT->AsFloat, ffFixed, 15,2);
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
cell->Text =FloatToStrF(DM->DocTKF_DREVT->AsFloat,ffFixed,10,3);
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

if (DM->DocTKOL_DREVT->AsFloat!=0)
        {
		cell->Text=FloatToStrF(DM->DocTKOL_DREVT->AsFloat,ffFixed,10,3);
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
//сумма строки
if( DM->DocTRSUM_DREVT->AsFloat!=0)
		{
		cell->Text=FloatToStrF(DM->DocTRSUM_DREVT->AsFloat,ffFixed,10,3);
		SumDoc=SumDoc+DM->DocTRSUM_DREVT->AsFloat;
		}
delete cell;
numCol++;


}


//------------------------------------------------------------------------------
void TFormaDocRev::OutputPodavalReport(TSheetEditor *prForm)
{
//numRow++;
TcxSSCellObject *cell;
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
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haLEFT;
cell->Text ="Всего";
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
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//сумма строки
cell->Text=FloatToStrF(SumDoc,ffFixed,10,2);

delete cell;
numCol++;

numRow++;numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="ВСЕГО: "+glCurrencyPropis(DM->DocAllSUMDOC->AsFloat);
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

//---------------------------------------------------------------------------
void TFormaDocRev::OpenPrintFormPrice(void)
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
void TFormaDocRev::OutputZagolovokReportPrice(TSheetEditor *prForm)
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
cell->Text = "Ревизия №"+DM->DocAllNUMDOC->AsString+" от "
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
cell->Text = "Кол.";
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
cell->Text = "Кол.";
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
cell->Text = "Розн. цена";
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
void TFormaDocRev::OutputStringPrice(TSheetEditor *prForm)
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
cell->Text = FloatToStrF(DM->DocTKF_DREVT->AsFloat,ffFixed,10,3);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//if (DM->DocTKOLUCH_INVT->AsFloat!=0)
//		{
//		cell->Text=FloatToStrF(DM->DocTKOLUCH_INVT->AsFloat,ffFixed,10,3);
//		}
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if( DM->DocTKOL_DREVT->AsFloat!=0)
        {
		cell->Text=FloatToStrF(DM->DocTKOL_DREVT->AsFloat,ffFixed,10,3);
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

		if(DM->DocTRPRICE_DREVT->AsFloat>0)
                {
				cell->Text=FloatToStrF(DM->DocTRPRICE_DREVT->AsFloat,ffFixed,10,2);
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
		if( DM->DocTRSUM_DREVT->AsFloat>0)
                {
				cell->Text=FloatToStrF(DM->DocTRSUM_DREVT->AsFloat,ffFixed,10,2);
				SummaReport=SummaReport+DM->DocTRSUM_DREVT->AsFloat;
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
void TFormaDocRev::OutputPodavalReportPrice(TSheetEditor *prForm)
{
numCol=1;

TcxSSCellObject *cell;

//заголовок таблицы
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

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);

cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(SummaReport,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="ВСЕГО: "+glCurrencyPropis(DM->DocAllSUMDOC->AsFloat);
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



void TFormaDocRev::OpenFormSpiskaSprInfBase(void)
{
if (Prosmotr==true) return;
if (DM->DocAllIDBASE_GALLDOC->ReadOnly==true) return;
if (FormaSpiskaSprInfBase==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprInfBase.1",IID_IFormaSpiskaSprInfBase,
													(void**)&FormaSpiskaSprInfBase);
		FormaSpiskaSprInfBase->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprInfBase->NumberProcVibor=ViborInfBase;
		FormaSpiskaSprInfBase->Vibor=true;
		FormaSpiskaSprInfBase->DM->OpenTable();
		}
}
//---------------------------------------------------------------------



void TFormaDocRev::OpenPrintFormPoGrp(void)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
porNumStr=1;
SumDoc=0;

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
		if (id_tec_grp==glStrToInt64(DM->IBQPoGrpIDGN->AsString))
                {
                porNumStr++;
                }
        else      //новая группа
                {
                OutputStringGroupReportPoGrp(PrintForm);
				id_tec_grp=glStrToInt64(DM->IBQPoGrpIDGN->AsString);
                }

        OutputStringReportPoGrp(PrintForm);
        DM->IBQPoGrp->Next();
        }

OutputPodavalReportGrp(PrintForm);
PrintForm->SS->EndUpdate();
DM->IBQPoGrp->Active=false;
PrintForm->Show();



}
//---------------------------------------------------------------------------
void TFormaDocRev::OutputStringGroupReportPoGrp(TSheetEditor *prForm)
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
void TFormaDocRev::OutputStringReportPoGrp(TSheetEditor *prForm)
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
cell->Text =FloatToStrF(DM->IBQPoGrpRPRICE_DREVT->AsFloat, ffFixed, 15,2);
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
cell->Text =FloatToStrF(DM->IBQPoGrpKF_DREVT->AsFloat,ffFixed,10,3);
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
if( DM->IBQPoGrpKOL_DREVT->AsFloat!=0)
        {
		cell->Text=FloatToStrF(DM->IBQPoGrpKOL_DREVT->AsFloat,ffFixed,10,3);
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

//сумма строки
if (DM->IBQPoGrpRSUM_DREVT->AsFloat!=0)
		{
		cell->Text=FloatToStrF(DM->IBQPoGrpRSUM_DREVT->AsFloat,ffFixed,10,3);
		SumDoc=SumDoc+ DM->IBQPoGrpRSUM_DREVT->AsFloat;
		}
delete cell;
numCol++;


numRow++;
}
//---------------------------------------------------------------------------
void TFormaDocRev::OutputPodavalReportGrp(TSheetEditor *prForm)
{
numCol=1;

TcxSSCellObject *cell;

//заголовок таблицы
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

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);

cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(SumDoc,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="ВСЕГО: "+glCurrencyPropis(DM->DocAllSUMDOC->AsFloat);
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
//---------------------------------------------------------------------------
void __fastcall TFormaDocRev::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("DocRev");	
}
//---------------------------------------------------------------------------
void TFormaDocRev::OpenFormSpiskaSprInv(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprInv==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprInv.1",IID_IFormaSpiskaSprInv,
													(void**)&FormaSpiskaSprInv);
		FormaSpiskaSprInv->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprInv->NumberProcVibor=InvRekvisit;
		FormaSpiskaSprInv->Vibor=true;
		}
}
//----------------------------------------------------------------------------



void __fastcall TFormaDocRev::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;

		OpenFSSprNom();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRev::cxButtonPoGrpClick(TObject *Sender)
{
OpenPrintFormPoGrp() ;	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRev::cxButtonFaktOstClick(TObject *Sender)
{
OpenPrintFormPrice() ;	
}
//---------------------------------------------------------------------------






void __fastcall TFormaDocRev::TypePriceComboBoxPropertiesChange(TObject *Sender)
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
		TypePriceComboBox->ItemIndex=DMSprTypePrice->GetIndexTypePricePoId(glStrToInt64(DM->DocIDRTPRICE_DREV->AsString))-1;
		ShowMessage("Изменять тип цен можно только при отключенной фильтрации по группам номенклатуры!");
        return;
		}

if ( TypePriceComboBox->ItemIndex!=0)
		{
		DMSprTypePrice->Table->First();
		DMSprTypePrice->Table->MoveBy(TypePriceComboBox->ItemIndex-1);
		DM->Doc->Edit();
		DM->DocIDRTPRICE_DREV->AsString=DMSprTypePrice->TableID_TPRICE->AsString;
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
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDRTPRICE_DREV->AsString),
											  glStrToInt64(DM->DocTIDNOM_DREVT->AsString));
						DM->DocTRPRICE_DREVT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKF_DREVT->AsFloat;
						DM->DocT->Post();
						DM->DocT->Next();
						}
				DMSprPrice->kanRelease();
				}
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRev::NameInvcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprInv();	
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocRev::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprFirm();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRev::NameInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprInfBase();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRev::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprSklad();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRev::ActionAddStringExecute(TObject *Sender)
{
if (Prosmotr==true) return;
ActionOperation=aoAddNewString;
OpenFSSprNom();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRev::ActionDeleteStringExecute(TObject *Sender)
{
if (Prosmotr==true) return;
DM->DeleteStringDoc();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRev::NumDoccxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRev::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocRev::DescrcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocRev::ToolButtonAddOstatkiNomClick(TObject *Sender)
{
DM->AddOstatkiNaSklade( glStrToInt64(DM->DocAllIDFIRMDOC->AsString),  glStrToInt64(DM->DocAllIDSKLDOC->AsString));
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRev::ActionAddNomPoCoduExecute(TObject *Sender)
{
OpenFormInputCodeNom();
}
//---------------------------------------------------------------------------
//ввод кода номенклатуры
void TFormaDocRev::OpenFormInputCodeNom(void)
{
if (Prosmotr==true)
	{
	ShowMessage("Документ открыт только для просмотра!");
	return;
	}
//ActionOperation=aoAddNewString;

if (FormaInputCode==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaInputCode.1",IID_IFormaInputCode,
													(void**)&FormaInputCode);
		FormaInputCode->Init(InterfaceMainObject,InterfaceImpl);
		FormaInputCode->NumberProcVibor=InputCodeNom;
		FormaInputCode->Vibor=true;
		//FormaInputCode->NameSprLabel->Caption="Справочник номенклатура:";
		}
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocRev::EndInputCodeNom(void)
{


		IDMSprNom * dm_nom;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&dm_nom);
		dm_nom->Init(InterfaceMainObject,InterfaceImpl);
	if (dm_nom->FindPoCodu(FormaInputCode->Code)>0)
		{
		DM->AddDocNewString();
		DM->DocT->Edit();
		DM->DocTIDNOM_DREVT->AsString=dm_nom->ElementIDNOM->AsString;
		DM->DocTCODENOM->AsInteger=dm_nom->ElementCODENOM->AsInteger;
		DM->DocTNAMENOM->AsString=dm_nom->ElementNAMENOM->AsString;
		DM->DocTTNOM->AsInteger=dm_nom->ElementTNOM->AsInteger;

		DM->DocTIDED_DREVT->AsString=dm_nom->ElementIDBASEDNOM->AsString;
		DM->DocTNAMEED->AsString=dm_nom->BasEdNAMEED->AsString;
		DM->DocTKF_DREVT->AsFloat=dm_nom->BasEdKFED->AsFloat;
		DM->DocTKOL_DREVT->AsFloat=FormaInputCode->Kol;

						//получим цену
		IDMSprPrice * dm_price;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
		dm_price->Init(InterfaceMainObject,InterfaceImpl);
		DM->DocTRPRICE_DREVT->AsFloat=dm_price->GetValuePrice(
						glStrToInt64(DM->DocIDRTPRICE_DREV->AsString),                     //тип цен
						glStrToInt64(DM->DocTIDNOM_DREVT->AsString),  //номенклатура
						glStrToInt64(DM->DocTIDED_DREVT->AsString),    // единица
						DM->DocTKF_DREVT->AsFloat,                   // коэффициент единицы
						glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString)); //базовая единица
						dm_price->kanRelease();

		DM->DocT->Post();

		VibTovarId=glStrToInt64(dm_nom->ElementIDNOM->AsString);
		VibTovarIdGrp=glStrToInt64(dm_nom->ElementIDGRPNOM->AsString);

		cxGrid1->Focused();
		cxGrid1->SetFocus();
		cxGrid1DBTableView1KOL_DREVT->Focused=true;
		cxGrid1DBTableView1KOL_DREVT->Selected=true;
		}
	else
		{
		ShowMessage("Товар не найден!");
		}
	dm_nom->kanRelease();




}
//-----------------------------------------------------------------------------
void __fastcall TFormaDocRev::FormActivate(TObject *Sender)
{
//зарегистрируем свой IAsyncExternalEvent в главном модуле для получения событий
if(InterfaceMainObject)
	{
	IAsyncExternalEvent * interf=0;
	InterfaceMainObject->kanQueryInterface(IID_IAsyncExternalEvent,(void**)&interf);
	if (interf)
		{
		interf->SetInterfaceForAsyncExternalEvent(InterfaceImpl);
		interf->kanRelease();
		}

	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRev::FormDeactivate(TObject *Sender)
{
//зарегистрируем свой IAsyncExternalEvent в главном модуле для получения событий

if(InterfaceMainObject)
	{
	IAsyncExternalEvent * interf=0;
	InterfaceMainObject->kanQueryInterface(IID_IAsyncExternalEvent,(void**)&interf);
	if (interf)
		{
		interf->SetInterfaceForAsyncExternalEvent(0);
		interf->kanRelease();
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocRev::ReadShtrihCodEvent(int number, UnicodeString sh)
{
if (Prosmotr==true)
	{
	 ShowMessage("Документ открыт только для просмотра!");
	return;
	}
	
AnsiString s=sh;


IObjectBarCode * ob_bar;
InterfaceGlobalCom->kanCreateObject("Oberon.ObjectBarCode.1",IID_IObjectBarCode,
													(void**)&ob_bar);
ob_bar->Init(InterfaceMainObject,InterfaceImpl);

IDMSprNom * dm_nom;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&dm_nom);
dm_nom->Init(InterfaceMainObject,InterfaceImpl);

IDMSprEd * dm_ed;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprEd.1",IID_IDMSprEd,
													(void**)&dm_ed);
dm_ed->Init(InterfaceMainObject,InterfaceImpl);

ob_bar->SprNom=dm_nom;
ob_bar->SprEd=dm_ed;
ob_bar->IdTypePrice=glStrToInt64(DM->DocIDRTPRICE_DREV->AsString);
ob_bar->ObrabotatShtrihCod(sh);

if (ob_bar->OutReady==true)
	{
	DM->AddDocNewString();
	DM->DocT->Edit();

	DM->DocTIDNOM_DREVT->AsString = dm_nom->ElementIDNOM->AsString;
	DM->DocTCODENOM->AsInteger=dm_nom->ElementCODENOM->AsInteger;
	DM->DocTNAMENOM->AsString=dm_nom->ElementNAMENOM->AsString;
	DM->DocTTNOM->AsInteger=dm_nom->ElementTNOM->AsInteger;

	DM->DocTIDED_DREVT->AsString = dm_ed->ElementIDED->AsString;
	DM->DocTNAMEED->AsString = dm_ed->ElementNAMEED->AsString;
	DM->DocTKF_DREVT->AsFloat = dm_ed->ElementKFED->AsFloat;

	DM->DocTKOL_DREVT->AsFloat=ob_bar->Kol;

	//получим цену
	IDMSprPrice * dm_price;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
	dm_price->Init(InterfaceMainObject,InterfaceImpl);
		DM->DocTRPRICE_DREVT->AsFloat=dm_price->GetValuePrice(
						glStrToInt64(DM->DocIDRTPRICE_DREV->AsString),                     //тип цен
						glStrToInt64(DM->DocTIDNOM_DREVT->AsString),  //номенклатура
						glStrToInt64(DM->DocTIDED_DREVT->AsString),    // единица
						DM->DocTKF_DREVT->AsFloat,                   // коэффициент единицы
						glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString)); //базовая единица
	dm_price->kanRelease();

	DM->DocT->Post();

	VibTovarId=glStrToInt64(dm_nom->ElementIDNOM->AsString);
	VibTovarIdGrp=glStrToInt64(dm_nom->ElementIDGRPNOM->AsString);

	cxGrid1->Focused();
	cxGrid1->SetFocus();
	cxGrid1DBTableView1KOL_DREVT->Focused=true;
	cxGrid1DBTableView1KOL_DREVT->Selected=true;
	}
else
	{
     ShowMessage(ob_bar->TextError);
	}
ob_bar->kanRelease();
dm_nom->kanRelease();
dm_ed->kanRelease();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaDocRev::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaDocRev::RunExternalModule(__int64 id_module, int type_module)
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
void __fastcall TFormaDocRev::ActionCloseExecute(TObject *Sender)
{
		DM->DocAll->CancelUpdates();
		DM->Doc->CancelUpdates();
		DM->DocT->CancelUpdates();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRev::ActionOKExecute(TObject *Sender)
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

void __fastcall TFormaDocRev::ActionDvRegExecute(TObject *Sender)
{
if (Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{
		if (DM->DvRegDoc()==true)
				{
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

void __fastcall TFormaDocRev::ActionSaveExecute(TObject *Sender)
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

void __fastcall TFormaDocRev::ActionPrintExecute(TObject *Sender)
{
OpenPrintForm() ;
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRev::ToolButtonAddOstatkiPoGrpClick(TObject *Sender)
{
OpenFormViborGrpNom();
}
//---------------------------------------------------------------------------

void TFormaDocRev::EndViborGrpNom(void)
{

__int64 id_grp = glStrToInt64(FormaViborGrpNomSpr->DMGrp->ElementIDGN->AsString);
UnicodeString name_grp = FormaViborGrpNomSpr->DMGrp->ElementNAMEGN->AsString;

UnicodeString zapros="select IDNOM, CODENOM, NAMENOM, IDED, NAMEED, KFED,rggoods.rprice_rggoods, sum(rggoods.kol_rggoods) as KOL    \
						from rggoods                                                                  \
						left outer join SNOM on IDNOM=rggoods.idnom_rggoods                           \
						left outer join sed on sed.ided=snom.idbasednom                               \
						where rggoods.idsklad_rggoods=:PARAM_IDSKLAD                                  \
										and rggoods.idfirm_rggoods=:PARAM_IDFIRM                              \
										and snom.idgrpnom=:PARAM_IDGRP                                        \
						group by IDNOM, CODENOM, NAMENOM, IDED, NAMEED, KFED, rggoods.rprice_rggoods                          \
						order by NAMENOM";

IDMQueryRead * DMQueryRead;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&DMQueryRead);
DMQueryRead->Init(InterfaceMainObject,0);
DMQueryRead->pFIBQ->Close();
DMQueryRead->pFIBQ->SQL->Clear();
DMQueryRead->pFIBQ->SQL->Add(zapros);
DMQueryRead->pFIBQ->ParamByName("PARAM_IDSKLAD")->AsString=DM->DocAllIDSKLDOC->AsString;
DMQueryRead->pFIBQ->ParamByName("PARAM_IDFIRM")->AsString=DM->DocAllIDFIRMDOC->AsString;
DMQueryRead->pFIBQ->ParamByName("PARAM_IDGRP")->AsString=id_grp;
DMQueryRead->pFIBQ->ExecQuery();

while(!DMQueryRead->pFIBQ->Eof)
	{
	DM->AddDocNewString();
	DM->DocT->Edit();

	DM->DocTIDNOM_DREVT->AsString=DMQueryRead->pFIBQ->FieldByName("IDNOM")->AsString;
	DM->DocTCODENOM->AsInteger=DMQueryRead->pFIBQ->FieldByName("CODENOM")->AsInteger;
	DM->DocTNAMENOM->AsString=DMQueryRead->pFIBQ->FieldByName("NAMENOM")->AsString;

	DM->DocTIDED_DREVT->AsString=DMQueryRead->pFIBQ->FieldByName("IDED")->AsString;
	DM->DocTNAMEED->AsString=DMQueryRead->pFIBQ->FieldByName("NAMEED")->AsString;
	DM->DocTKF_DREVT->AsFloat=DMQueryRead->pFIBQ->FieldByName("KFED")->AsFloat;
	DM->DocTKOL_DREVT->AsFloat=DMQueryRead->pFIBQ->FieldByName("KOL")->AsFloat;
	DM->DocTUCH_KOL_DREVT->AsFloat=DMQueryRead->pFIBQ->FieldByName("KOL")->AsFloat;
	DM->DocTRPRICE_DREVT->AsFloat=DMQueryRead->pFIBQ->FieldByName("rprice_rggoods")->AsFloat;

	DM->DocT->Post();
	DMQueryRead->pFIBQ->Next();
	}


DMQueryRead->kanRelease();
}
//-------------------------------------------------------------------------
void TFormaDocRev::OpenFormViborGrpNom(void)
{
if (FormaViborGrpNomSpr==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprGrpNom.1",IID_IFormaSpiskaSprGrpNom,
													(void**)&FormaViborGrpNomSpr);
		FormaViborGrpNomSpr->Init(InterfaceMainObject,InterfaceImpl);
		FormaViborGrpNomSpr->Vibor=true;
		FormaViborGrpNomSpr->NumberProcVibor=ViborGrpNom;
		FormaViborGrpNomSpr->UpdateForm();
		}

}
//-----------------------------------------------------------------------------
void TFormaDocRev::OpenFormViborGrpNomForAddAllNom(void)
{
if (FormaViborGrpNomSpr==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprGrpNom.1",IID_IFormaSpiskaSprGrpNom,
													(void**)&FormaViborGrpNomSpr);
		FormaViborGrpNomSpr->Init(InterfaceMainObject,InterfaceImpl);
		FormaViborGrpNomSpr->Vibor=true;
		FormaViborGrpNomSpr->NumberProcVibor=ER_AddAllNomIsGrp;
		FormaViborGrpNomSpr->UpdateForm();
		}

}
//-----------------------------------------------------------------------------
void TFormaDocRev::EndViborGrpNomForAddAllNom(void)
{

__int64 id_grp = glStrToInt64(FormaViborGrpNomSpr->DMGrp->ElementIDGN->AsString);
UnicodeString name_grp = FormaViborGrpNomSpr->DMGrp->ElementNAMEGN->AsString;

UnicodeString zapros="select IDNOM, CODENOM, NAMENOM, IDED, NAMEED,                   \
				KFED,rggoods.rprice_rggoods, sum(rggoods.kol_rggoods) as KOL          \
		from snom                                                                     \
		left outer join rggoods on snom.idnom=rggoods.idnom_rggoods                   \
									and rggoods.idsklad_rggoods=:PARAM_IDSKLAD        \
									and rggoods.idfirm_rggoods=:PARAM_IDFIRM          \
		left outer join sed on sed.ided=snom.idbasednom                                \
		where snom.idgrpnom=:PARAM_IDGRP                                               \
		group by IDNOM, CODENOM, NAMENOM, IDED, NAMEED, KFED, rggoods.rprice_rggoods   \
        order by NAMENOM";

IDMQueryRead * DMQueryRead;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&DMQueryRead);
DMQueryRead->Init(InterfaceMainObject,0);
DMQueryRead->pFIBQ->Close();
DMQueryRead->pFIBQ->SQL->Clear();
DMQueryRead->pFIBQ->SQL->Add(zapros);
DMQueryRead->pFIBQ->ParamByName("PARAM_IDSKLAD")->AsString=DM->DocAllIDSKLDOC->AsString;
DMQueryRead->pFIBQ->ParamByName("PARAM_IDFIRM")->AsString=DM->DocAllIDFIRMDOC->AsString;
DMQueryRead->pFIBQ->ParamByName("PARAM_IDGRP")->AsString=id_grp;
DMQueryRead->pFIBQ->ExecQuery();

while(!DMQueryRead->pFIBQ->Eof)
	{
	DM->AddDocNewString();
	DM->DocT->Edit();

	DM->DocTIDNOM_DREVT->AsString=DMQueryRead->pFIBQ->FieldByName("IDNOM")->AsString;
	DM->DocTCODENOM->AsInteger=DMQueryRead->pFIBQ->FieldByName("CODENOM")->AsInteger;
	DM->DocTNAMENOM->AsString=DMQueryRead->pFIBQ->FieldByName("NAMENOM")->AsString;

	DM->DocTIDED_DREVT->AsString=DMQueryRead->pFIBQ->FieldByName("IDED")->AsString;
	DM->DocTNAMEED->AsString=DMQueryRead->pFIBQ->FieldByName("NAMEED")->AsString;
	DM->DocTKF_DREVT->AsFloat=DMQueryRead->pFIBQ->FieldByName("KFED")->AsFloat;
	DM->DocTKOL_DREVT->AsFloat=DMQueryRead->pFIBQ->FieldByName("KOL")->AsFloat;
	DM->DocTUCH_KOL_DREVT->AsFloat=DMQueryRead->pFIBQ->FieldByName("KOL")->AsFloat;
	DM->DocTRPRICE_DREVT->AsFloat=DMQueryRead->pFIBQ->FieldByName("rprice_rggoods")->AsFloat;

	DM->DocT->Post();
	DMQueryRead->pFIBQ->Next();
	}


DMQueryRead->kanRelease();
}
//-------------------------------------------------------------------------
void __fastcall TFormaDocRev::ToolButtonAddAllNomIsGrpClick(TObject *Sender)
{
OpenFormViborGrpNomForAddAllNom();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRev::ToolButtonSetKolNullClick(TObject *Sender)
{
DM->DocT->First();
while (!DM->DocT->Eof)
	{
	DM->DocT->Edit();
    DM->DocTKOL_DREVT->AsFloat=0;
	DM->DocT->Post();
	DM->DocT->Next();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRev::ToolButtonMoveInDocPerClick(TObject *Sender)
{
  //множественный перенос
  IFormaDocPer * doc_per;
  InterfaceGlobalCom->kanCreateObject(ProgId_FormaDocPer,IID_IFormaDocPer,
													(void**)&doc_per);
  doc_per->Init(InterfaceMainObject,InterfaceImpl);
  doc_per->DM->NewDoc();
  doc_per->UpdateForm();

		TcxGridViewData * AViewData=cxGrid1DBTableView1->ViewData;
		for(int i=0;i<AViewData->RowCount;i++)
			{
			if (AViewData->Records[i]->Selected==true)
				{
				doc_per->DM->DocT->Append();
				__int64 id_nom=AViewData->Records[i]->Values[cxGrid1DBTableView1IDNOM_DREVT->Index];
				doc_per->DM->DocTIDNOMPERT->AsString=id_nom;
				__int64 id_ed=AViewData->Records[i]->Values[cxGrid1DBTableView1IDED_DREVT->Index];
				doc_per->DM->DocTIDEDPERT->AsString=id_ed;

				UnicodeString name_nom=AViewData->Records[i]->Values[cxGrid1DBTableView1NAMENOM->Index];
				doc_per->DM->DocTNAMENOM->AsString=name_nom;
				UnicodeString name_ed=AViewData->Records[i]->Values[cxGrid1DBTableView1NAMEED->Index];
				doc_per->DM->DocTNAMEED->AsString=name_ed;

				double kol=AViewData->Records[i]->Values[cxGrid1DBTableView1KOL_DREVT->Index];
				doc_per->DM->DocTKOLPERT->AsFloat=kol;
				double price=AViewData->Records[i]->Values[cxGrid1DBTableView1RPRICE_DREVT->Index];
				doc_per->DM->DocTPRICEPERT->AsFloat=price;
				double kf=AViewData->Records[i]->Values[cxGrid1DBTableView1KF_DREVT->Index];
				doc_per->DM->DocTKFPERT->AsFloat=kf;
				double sum=AViewData->Records[i]->Values[cxGrid1DBTableView1RSUM_DREVT->Index];
				doc_per->DM->DocTSUMPERT->AsFloat=sum;


				doc_per->DM->DocT->Post();
				}
			}
}
//---------------------------------------------------------------------------

