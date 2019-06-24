//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop
#include "UFormaDocVosvratPokForCashier.h"
#include "IDMSprPrice.h"
#include "IDMSprFirm.h"
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
#pragma link "cxContainer"
#pragma link "cxDBEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxCalendar"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaDocVosvratPokForCashier::TFormaDocVosvratPokForCashier(TComponent* Owner)
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
bool TFormaDocVosvratPokForCashier::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.DMDocVosvratPok.1",IID_IDMDocVosvratPok,
							(void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceDocT;
DBTextFNameUser->DataSource=DM->DataSourceDocAll;
SumDocDBText->DataSource=DM->DataSourceDocAll;
NameFirmcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameSkladcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NumDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PrefiksNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
DescrcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;

NameDogovorcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;


Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора

VibTovarId=0;
VibTovarIdGrp=0;
ActionOperation=aoNO;

flObrabatChangePrice=false;
flObrabatChangeRoznPrice=false;
flObrabatChangeOperation=false;

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

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice,
									 (void**)&DMSprRTypePrice);
DMSprRTypePrice->Init(InterfaceMainObject,InterfaceImpl);

DMSprRTypePrice->OpenTable();
TypeRPriceComboBox->Properties->Items->Clear();
TypeRPriceComboBox->Properties->Items->Add("Не задан");
DMSprRTypePrice->Table->First();
while (!DMSprRTypePrice->Table->Eof)
		{
		TypeRPriceComboBox->Properties->Items->Add(DMSprRTypePrice->TableNAME_TPRICE->AsString);
		DMSprRTypePrice->Table->Next();
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
int TFormaDocVosvratPokForCashier::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------

void TFormaDocVosvratPokForCashier::UpdateForm(void)
{

Prosmotr=DM->Prosmotr;
if (Prosmotr==true)
        {
        ProsmotrLabel->Visible=true;
        }
else
        {
        ProsmotrLabel->Visible=false;
        }

flObrabatChangePrice=false;
flObrabatChangeRoznPrice=false;
flObrabatChangeOperation=false;
TypePriceComboBox->ItemIndex=DMSprTypePrice->GetIndexTypePricePoId(glStrToInt64(DM->DocIDTPRICE_DVPOK->AsString));
TypeRPriceComboBox->ItemIndex=DMSprRTypePrice->GetIndexTypePricePoId(glStrToInt64(DM->DocIDRTPRICE_DVPOK->AsString));
OperComboBox->ItemIndex=DM->DocOPER_DVPOK->AsInteger;
flObrabatChangePrice=true;
flObrabatChangeRoznPrice=true;
flObrabatChangeOperation=true;
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocVosvratPokForCashier::FormClose(TObject *Sender,
      TCloseAction &Action)
{

if(Ed)Ed->kanRelease();
if(Nom)Nom->kanRelease();

if(Klient)Klient->kanRelease();

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
DMSprTypePrice->kanRelease();
DMSprRTypePrice->kanRelease();
Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}

}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPokForCashier::ReadShtrihCodEvent(int number, UnicodeString sh)
{
UnicodeString s=sh;
//надо учитывать что считан может быть и весовой код
IDMSprNom * DMSprNom;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&DMSprNom);
DMSprNom->Init(InterfaceMainObject,InterfaceImpl);
int id_nom=DMSprNom->FindPoShtrihCodu(s);

if (id_nom!=0)
        {
		DMSprNom->IdTypePrice=glStrToInt64(DM->DocIDTPRICE_DVPOK->AsString);
        DMSprNom->OpenElement(id_nom);
        DM->AddDocNewString();

        DM->DocT->Edit();
		DM->DocTIDNOM_DVPOKT->AsString=DMSprNom->ElementIDNOM->AsString;
		DM->DocTNAMENOM->AsString=DMSprNom->ElementNAMENOM->AsString;
		DM->DocTKOL_DVPOKT->AsInteger=1;
		DM->DocTIDED_DVPOKT->AsString=DMSprNom->ElementIDOSNEDNOM->AsString;
        DM->DocTNAMEED->AsString=DMSprNom->OsnEdNAMEED->AsString;
		DM->DocTKF_DVPOKT->AsFloat=DMSprNom->OsnEdKFED->AsFloat;
		//DM->DocTPRICE_DVPOKT->AsFloat=DMSprNom->ElementZNACH_PRICE->AsFloat
		//						*DM->DocTKF_DVPOKT->AsFloat;
        DM->DocT->Post();

		cxGrid1->SetFocus();
		cxGrid1DBTableView1KOL_DVPOKT->Selected=true;

        }
else
        {
        ShowMessage("Товар со штрих кодом "+s+" не найден!");
        return;
        }

DMSprNom->kanRelease();

UpdateForm();


}
//---------------------------------------------------------------
int TFormaDocVosvratPokForCashier::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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
				DM->DocTIDNOM_DVPOKT->AsString=Nom->DM->ElementIDNOM->AsString;
				DM->DocTNAMENOM->AsString=Nom->DM->ElementNAMENOM->AsString;
				DM->DocTKOL_DVPOKT->AsInteger=1;
				DM->DocTIDED_DVPOKT->AsString=Nom->DM->ElementIDOSNEDNOM->AsString;
                DM->DocTNAMEED->AsString=Nom->DM->OsnEdNAMEED->AsString;
				DM->DocTKF_DVPOKT->AsFloat=Nom->DM->OsnEdKFED->AsFloat;
			   //	DM->DocTPRICE_DVPOKT->AsFloat=Nom->DM->ElementZNACH_PRICE->AsFloat;
                DM->DocT->Post();
				cxGrid1->SetFocus();
				cxGrid1DBTableView1KOL_DVPOKT->Selected=true;
				VibTovarId=glStrToInt64(Nom->DM->ElementIDNOM->AsString);
				VibTovarIdGrp=glStrToInt64(Nom->DM->ElementIDGRPNOM->AsString);
                }
        Nom=0;
        }

if (number_procedure_end==Edinica)
        {
		if (type_event==1)
                {
                DM->DocT->Edit();
				DM->DocTIDED_DVPOKT->AsString=Ed->DM->ElementIDED->AsString;
                DM->DocTNAMEED->AsString=Ed->DM->Element->FieldByName("NAMEED")->AsString;
				DM->DocTKF_DVPOKT->AsFloat=Ed->DM->ElementKFED->AsFloat;
			  //	TDMSprPrice *dm_price=new TDMSprPrice(Application);
			  //	dm_price->FindElement(DM->DocIDTPRICE_DVPOK->AsInteger,
			  //							DM->DocTIDNOM_DVPOKT->AsInteger);
			  //	DM->DocTPRICE_DVPOKT->AsFloat=dm_price->ElementZNACH_PRICE->AsFloat
			  //									*DM->DocTKF_DVPOKT->AsFloat;
			  //	delete dm_price;
                DM->DocT->Post();
                }
        Ed=0;
        }




if (number_procedure_end==KlientRekvisit)
        {
		if (type_event==1)
                {
                DM->DocAll->Edit();
				DM->DocAllIDKLDOC->AsString=Klient->DM->ElementIDKLIENT->AsString;
				DM->DocAllNAMEKLIENT->AsString=Klient->DM->Element->FieldByName("NAMEKLIENT")->AsString;
                DM->DocAll->Post();
                }
        Klient=0;
        }


if (number_procedure_end==ViborDogovor)
        {
		if(type_event==1)
                {
                DM->DocAll->Edit();
				DM->DocAllIDDOGDOC->AsString=FormaSpiskaSprDogovor->DM->TableID_SDOG->AsString;
                DM->DocAllNAME_SDOG->AsString=FormaSpiskaSprDogovor->DM->TableNAME_SDOG->AsString;
                DM->DocAll->Post();
                }
        FormaSpiskaSprDogovor=0;
		 }


        ActionOperation=aoNO;
		EditRekvisit=NO;


return -1;

}
//---------------------------------------------------------------------------

//----------------------------------------------------------------------------
void  TFormaDocVosvratPokForCashier::OpenFSSprNom()
{
if(Prosmotr==true) return;
if (Nom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaViborSprNom.1",IID_IFormaViborSprNom,
													(void**)&Nom);
		Nom->Init(InterfaceMainObject,InterfaceImpl);
		Nom->Vibor=true;
		Nom->NumberProcVibor=Tovar;
		Nom->DM->IdTypePrice=glStrToInt64(DM->DocIDRTPRICE_DVPOK->AsString);
//        Nom->SpisokTypePrice->ItemIndex=Nom->DM->GetIndexTypePrice()-1;
//		Nom->HintLabel->Caption="Выберите номенклатуру для документа Возврат от покупателя №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		//Nom->IdNom=glStrToInt64(DM->DocTIDNOM_DVPOKT->AsString);
		Nom->UpdateForm();
		}
}
//----------------------------------------------------------------------------
void TFormaDocVosvratPokForCashier:: OpenFSSprEd()
{
if(Prosmotr==true) return;
if (Ed==NULL)
        {

		InterfaceGlobalCom->kanCreateObject("Oberon.FormaViborSprEd.1",IID_IFormaViborSprEd,
													(void**)&Ed);
		Ed->Init(InterfaceMainObject,InterfaceImpl);
		Ed->Vibor=true;
		Ed->NumberProcVibor=Edinica;
		Ed->IdNom=glStrToInt64(DM->DocTIDNOM_DVPOKT->AsString);
		Ed->DM->OpenTable(DM->DocTIDNOM_DVPOKT->AsInteger);
//        Ed->LabelNom->Caption="Единицы номенклатуры: "+DM->DocTNAMENOM->AsString;
//		Ed->HintLabel->Caption="Выберите единицу номенклатуры для документа Приходная накладная №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;


		}
}

//----------------------------------------------------------------------------
void __fastcall TFormaDocVosvratPokForCashier::ToolButtonInsertClick(TObject *Sender)
{
if(Prosmotr==true) return;
ActionOperation=aoAddNewString;
OpenFSSprNom();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPokForCashier::ToolButtonDeleteClick(TObject *Sender)
{
if(Prosmotr==true) return;
DM->DeleteStringDoc();

}
//---------------------------------------------------------------------------




void  TFormaDocVosvratPokForCashier::OpenFormSpiskaSprKlient(void)
{
if(Prosmotr==true) return;
if (Klient==NULL)
		{

		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&Klient);
		Klient->Init(InterfaceMainObject,InterfaceImpl);
		Klient->Vibor=true;
		Klient->NumberProcVibor=KlientRekvisit;
//		Klient->HintLabel->Caption="Выберите поставщика для документа Возврат от покупателя №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		Klient->IdKlient=glStrToInt64(DM->DocAllIDKLDOC->AsString);
		Klient->UpdateForm();
		}



}
//-----------------------------------------------------------------------------





//---------------------------------------------------------------------------
void TFormaDocVosvratPokForCashier::OpenPrintForm(void)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
porNumStr=1;


//шапка
PrintForm->SS->EndUpdate();
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
void TFormaDocVosvratPokForCashier::OutputZagolovokReport(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numRow=1;
numCol=2;


prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";
prForm->SS->RowsAutoHeight=true;
        TcxSSHeader *cHeader;

        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 10;
        cHeader->Size[2] = 40;
        cHeader->Size[3] = 300;
        cHeader->Size[4] = 60;
        cHeader->Size[5] = 80;
        cHeader->Size[6] = 60;
        cHeader->Size[7] = 70;
		cHeader->Size[8] = 80;
IDMSprFirm *dm_firm;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
													(void**)&dm_firm);
		dm_firm->Init(InterfaceMainObject,InterfaceImpl);
dm_firm->OpenElement(glStrToInt64(DM->DocAllIDFIRMDOC->AsString));
cell = prForm->SS->ActiveSheet->GetCellObject(2, 1);
cell->Text=dm_firm->ElementFNAMEFIRM->AsString
		+", ИНН "+dm_firm->ElementINNFIRM->AsString;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Адрес: "+dm_firm->ElementPADRFIRM->AsString;
delete cell;
numRow++;

dm_firm->kanRelease();



cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Склад: "+DM->DocAllNAMESKLAD->AsString;
delete cell;
numRow++; numRow++;


cell = prForm->SS->ActiveSheet->GetCellObject(3, numRow);
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="Возврат от покупателя №"+DM->DocAllNUMDOC->AsString+" от "
                +DateToStr(DM->DocAllPOSDOC->AsDateTime);
delete cell;
numRow++; numRow++;

IDMSprKlient * dm_klient;
		InterfaceGlobalCom->kanCreateObject(ProgId_DMSprKlient,IID_IDMSprKlient,
													(void**)&dm_klient);
		dm_klient->Init(InterfaceMainObject,InterfaceImpl);
dm_klient->OpenElement(glStrToInt64(DM->DocAllIDKLDOC->AsString));

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Покупатель: "+dm_klient->ElementFNAME->AsString+", ИНН "+dm_klient->ElementINNKLIENT->AsString;
delete cell;
numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Адрес: "+dm_klient->ElementADRKLIENT->AsString;
delete cell;
numRow++;

dm_klient->kanRelease();
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Основание: "+DM->DocDESCR_DVPOK->AsString;
delete cell;
numRow++;
numRow++;

//заголовок таблицы
numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="№";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Наименование";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Кол-во";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Единица";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="К";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Цена";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Сумма";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;
}
//------------------------------------------------------------------------------
void TFormaDocVosvratPokForCashier::OutputString(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=2;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IntToStr(porNumStr);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTNAMENOM->AsString;
//cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTKOL_DVPOKT->AsString;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTNAMEED->AsString;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTKF_DVPOKT->AsFloat,ffFixed,10,3);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTRPRICE_DVPOKT->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTRSUM_DVPOKT->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
}


//------------------------------------------------------------------------------
void TFormaDocVosvratPokForCashier::OutputPodavalReport(TSheetEditor *prForm)
{
numRow++;
numCol=8;
TcxSSCellObject *cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Text="Всего: "+FloatToStrF(DM->DocAllSUMDOC->AsFloat,ffFixed,10,2);
delete cell;
 numRow++;
numCol=8;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Text="Сумма НДС: 0.00 ";
delete cell;
numRow++;

numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haLEFT;
cell->Text="Всего наименований "+IntToStr(DM->DocT->RecordCount)+
                " на сумму "+FloatToStrF(DM->DocAllSUMDOC->AsFloat, ffFixed,10,2);
delete cell;
numRow++;

numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="("+glCurrencyPropis(DM->DocAllSUMDOC->AsFloat)+" )";
delete cell;
numRow++;

for (int i=2;i<=8;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(i, numRow);
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        }
numRow++;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Сдал  __________________________ ";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(8, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Text="Принял  __________________________ ";
delete cell;
}
//---------------------------------------------------------------
//----------------------------------------------------------------------------






void __fastcall TFormaDocVosvratPokForCashier::NumberDocKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocVosvratPokForCashier::DescrDBEditKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocVosvratPokForCashier::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("DocVosvratPok");
}
//---------------------------------------------------------------------------





void __fastcall TFormaDocVosvratPokForCashier::ToolButton5Click(TObject *Sender)
{
DM->DocT->Post();	
}
//---------------------------------------------------------------------------


void TFormaDocVosvratPokForCashier::OpenFormSpiskaSprDogovor(void)
{
if (glStrToInt64(DM->DocAllIDKLDOC->AsString)==0)
        {
        ShowMessage("Выберите контрагента!");
        return;
        }

if (FormaSpiskaSprDogovor==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprDogovor.1",IID_IFormaSpiskaSprDogovor,
													(void**)&FormaSpiskaSprDogovor);
		FormaSpiskaSprDogovor->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprDogovor->IdKlient=glStrToInt64(DM->DocAllIDKLDOC->AsString);
        FormaSpiskaSprDogovor->Vibor=true;
		FormaSpiskaSprDogovor->DM->OpenTable(glStrToInt64(DM->DocAllIDKLDOC->AsString));
//		FormaSpiskaSprDogovor->LabelKlient->Caption="Контрагент: "+DM->DocAllNAMEKLIENT->AsString;
		FormaSpiskaSprDogovor->NumberProcVibor=ViborDogovor;
        }
}
//-----------------------------------------------------------------------------







void __fastcall TFormaDocVosvratPokForCashier::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if(Prosmotr==true) return;
        OpenFSSprNom();
        EditRekvisit=Tovar;

}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPokForCashier::cxGrid1DBTableView1NAMEEDPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if(Prosmotr==true) return;

        OpenFSSprEd();
        EditRekvisit=Edinica;

}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPokForCashier::TypePriceComboBoxPropertiesChange(
      TObject *Sender)
{
if(flObrabatChangePrice==false) return;
   UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPokForCashier::TypeRPriceComboBoxPropertiesChange(
      TObject *Sender)
{
if(flObrabatChangeRoznPrice==false) return;

UpdateForm();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPokForCashier::OperComboBoxPropertiesChange(
      TObject *Sender)
{
if(flObrabatChangeOperation==false) return;
DM->Doc->Edit();
DM->DocOPER_DVPOK->AsInteger=OperComboBox->ItemIndex;
DM->Doc->Post();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPokForCashier::NameDogovorcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprDogovor();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPokForCashier::cxDBButtonEdit1PropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprKlient();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPokForCashier::PosDoccxDBDateEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocVosvratPokForCashier::ActionCloseExecute(TObject *Sender)

{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPokForCashier::ActionOKExecute(TObject *Sender)
{
if(Prosmotr==true) return;
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

void __fastcall TFormaDocVosvratPokForCashier::ActionDvRegExecute(TObject *Sender)

{
if(Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{
		if (DM->DvRegDoc()==true)
				{
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

void __fastcall TFormaDocVosvratPokForCashier::ActionSaveExecute(TObject *Sender)

{
if(Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{

		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPokForCashier::ActionPrintExecute(TObject *Sender)

{
OpenPrintForm() ;
}
//---------------------------------------------------------------------------

