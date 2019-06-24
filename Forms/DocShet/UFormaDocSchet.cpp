//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaDocSchet.h"
#include "UDM.h"
#include "IDMSprPrice.h"
#include "IDMSprBank.h"
#include "IFormaDocReal.h"
#include "IFormaDocRealRozn.h"
#include "IFormaDocCheck.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
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
__fastcall TFormaDocSchet::TFormaDocSchet(TComponent* Owner)
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
bool TFormaDocSchet::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.DMDocSchet.1",IID_IDMDocSchet, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceDocT;
DBTextFNameUser->DataSource=DM->DataSourceDocAll;

NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameBSchetcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameSkladcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NumDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PrimcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
PrefiksNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;

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


Prosmotr=false;    //только просмотр
NoEdit=false;
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи
VibTovarId=0;
VibTovarIdGrp=0;

ActionOperation=aoNO;

//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaDocSchetImpl),false);
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
//---------------------------------------------------------------------------
int TFormaDocSchet::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaDocSchet::UpdateForm(void)
{

Prosmotr=DM->Prosmotr;
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
flObrabatChangeTypePrice=false;
TypePriceComboBox->ItemIndex=DMSprTypePrice->GetIndexTypePricePoId(DM->DocIDTPRICESCH->AsInt64);
flObrabatChangeTypePrice=true;
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocSchet::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(Ed)Ed->kanRelease();
if(Nom)Nom->kanRelease();
if(Firma)Firma->kanRelease();
if(Sklad)Sklad->kanRelease();
if(Klient)Klient->kanRelease();
if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
if(FormSpiskaSprBSchet)FormSpiskaSprBSchet->kanRelease();


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

DMSprTypePrice->kanRelease();
DMTableExtPrintForm->kanRelease();
DM->kanRelease();
Action=caFree;
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocSchet::FormActivate(TObject *Sender)
{
//if (glScaner) glScaner->ReadSh=ReadShtrihCodEvent;
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocSchet::FormDeactivate(TObject *Sender)
{
//if(glScaner) glScaner->ReadSh=0;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TFormaDocSchet::ReadShtrihCodEvent(int number, UnicodeString sh)
{
AnsiString s=sh;
//надо учитывать что считан может быть и весовой код
IDMSprNom * DMSprNom;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&DMSprNom);
DMSprNom->Init(InterfaceMainObject,InterfaceImpl);
int id_nom=DMSprNom->FindPoShtrihCodu(s);

if (id_nom!=0)
		{
		DMSprNom->IdTypePrice=glStrToInt64(DM->DocIDTPRICESCH->AsString);
        DMSprNom->OpenElement(id_nom);
        DM->AddDocNewString();

        DM->DocT->Edit();
		DM->DocTIDNOMSCHT->AsString=DMSprNom->ElementIDNOM->AsString;
        DM->DocTNAMENOM->AsString=DMSprNom->ElementNAMENOM->AsString;
		DM->DocTTNOM->AsInteger=DMSprNom->ElementTNOM->AsInteger;
		DM->DocTKOLSCHT->AsInteger=1;
		DM->DocTKFSCHT->AsFloat=DMSprNom->OsnEdKFED->AsFloat;
		DM->DocTPRICESCHT->AsFloat=DMSprNom->ElementZNACH_PRICE->AsFloat;

		DM->DocTIDEDSCHT->AsString=DMSprNom->ElementIDOSNEDNOM->AsString;
        DM->DocTNAMEED->AsString=DMSprNom->OsnEdNAMEED->AsString;

        DM->DocT->Post();

		cxGrid1->SetFocus();
        //DBGrid1->SelectedField=DM->DocTKOLSCHT;

        }
else
        {
        ShowMessage("Товар со штрих кодом "+s+" не найден!");
        return;
        }

DMSprNom->kanRelease();

//UpdateForm();


}
//---------------------------------------------------------------

//---------------------------------------------------------------------------
int TFormaDocSchet::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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
				DM->DocTIDNOMSCHT->AsString=VibTovarId=glStrToInt64(Nom->DM->ElementIDNOM->AsString);
				VibTovarIdGrp=glStrToInt64(Nom->DM->ElementIDGRPNOM->AsString);
                DM->DocTNAMENOM->AsString=Nom->DM->ElementNAMENOM->AsString;
                DM->DocTTNOM->AsInteger=Nom->DM->ElementTNOM->AsInteger;
                DM->DocTKOLSCHT->AsInteger=1;
				DM->DocTIDEDSCHT->AsString=Nom->DM->ElementIDOSNEDNOM->AsString;
                DM->DocTNAMEED->AsString=Nom->DM->OsnEdNAMEED->AsString;
                DM->DocTKFSCHT->AsFloat=Nom->DM->OsnEdKFED->AsFloat;
				IDMSprPrice * DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
				DMSprPrice->FindElement( glStrToInt64(DM->DocIDTPRICESCH->AsString),
											 glStrToInt64(DM->DocTIDNOMSCHT->AsString));
                DM->DocTPRICESCHT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
                                                        DM->DocTKFSCHT->AsFloat;
				DMSprPrice->kanRelease();
                DM->DocT->Post();
                }
		Nom=0;
		cxGrid1->SetFocus();
		cxGrid1DBTableView1KOLSCHT->Selected=true;
        }

if (number_procedure_end==Edinica)
        {
		if (type_event==1)
                {
                DM->DocT->Edit();
				DM->DocTIDEDSCHT->AsString=Ed->DM->ElementIDED->AsString;
                DM->DocTNAMEED->AsString=Ed->DM->ElementNAMEED->AsString;
                DM->DocTKFSCHT->AsFloat=Ed->DM->ElementKFED->AsFloat;
               // DM->DocTSUMSCHT->AsFloat=DM->DocTKOLSCHT->AsFloat*
                //        DM->DocTKFSCHT->AsFloat*DM->DocTPRICESCHT->AsFloat;
				IDMSprPrice * DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDTPRICESCH->AsString),
											 glStrToInt64(DM->DocTIDNOMSCHT->AsString));
						DM->DocTPRICESCHT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
                                                        DM->DocTKFSCHT->AsFloat;
				DMSprPrice->kanRelease();

                DM->DocT->Post();
                }
		Ed=0;
		cxGrid1->SetFocus();
		cxGrid1DBTableView1PRICESCHT->Selected=true;
        }

if (number_procedure_end==FirmaRekvisit)
        {
		if (type_event==1)
                {
                DM->DocAll->Edit();
				DM->DocAllIDFIRMDOC->AsString=Firma->DM->ElementIDFIRM->AsString;
                DM->DocAllNAMEFIRM->AsString=Firma->DM->ElementNAMEFIRM->AsString;
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
                DM->DocAllNAMESKLAD->AsString=Sklad->DM->ElementNAMESKLAD->AsString;
                DM->DocAll->Post();
                }
		Sklad=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
        }

if (number_procedure_end==KlientRekvisit)
        {
		if (type_event==1)
                {
                DM->DocAll->Edit();
				DM->DocAllIDKLDOC->AsString=Klient->DM->ElementIDKLIENT->AsString;
                DM->DocAllNAMEKLIENT->AsString=Klient->DM->ElementNAMEKLIENT->AsString;
				DM->DocAll->Post();

				if (glStrToInt64(Klient->DM->ElementIDTPRICEKLIENT->AsString)!=0)
					{
					TypePriceComboBox->ItemIndex=
						DMSprTypePrice->GetIndexTypePricePoId(glStrToInt64(Klient->DM->ElementIDTPRICEKLIENT->AsString));
					}


                }
		Klient=0;
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

 if (number_procedure_end==ViborBankSchet)
        {
		if (type_event==1)
				{
                DM->Doc->Edit();
				DM->DocIDBSCHET_DSCH->AsString=FormSpiskaSprBSchet->DM->TableIDBSCHET->AsString;
                DM->DocNAMEBSCHET->AsString=FormSpiskaSprBSchet->DM->TableNAMEBSCHET->AsString;
                DM->Doc->Post();
                }
		FormSpiskaSprBSchet=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
        }

ActionOperation=aoNO;
EditRekvisit=NO;
return -1;
}
//---------------------------------------------------------------------------
void  TFormaDocSchet::OpenFormSpiskaSprNom()
{
 if (Prosmotr==true) return;
if (Nom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&Nom);
		Nom->Init(InterfaceMainObject,InterfaceImpl);
        Nom->Vibor=true;
		Nom->NumberProcVibor=Tovar;
		Nom->IdNom=glStrToInt64(DM->DocTIDNOMSCHT->AsString);
		Nom->UpdateForm();
        }
}
//----------------------------------------------------------------------------
void TFormaDocSchet:: OpenFormSpiskaSprEd()
{
if (Prosmotr==true) return;
if (Ed==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&Ed);
		Ed->Init(InterfaceMainObject,InterfaceImpl);
        Ed->Vibor=true;
		Ed->NumberProcVibor=Edinica;
		Ed->DM->OpenTable(glStrToInt64(DM->DocTIDNOMSCHT->AsString));
        }
}
//---------------------------------------------------------------------------
void    TFormaDocSchet::OpenFormSpiskaSprFirm(void)
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
		}

}
//---------------------------------------------------------------------------
void  TFormaDocSchet::OpenFormSpiskaSprSklad(void)
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
        }

}
//---------------------------------------------------------------------------
void  TFormaDocSchet::OpenFormSpiskaSprKlient(void)
{
if (Prosmotr==true) return;
if (Klient==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&Klient);
		Klient->Init(InterfaceMainObject,InterfaceImpl);
		Klient->Vibor=true;
		Klient->NumberProcVibor=KlientRekvisit;
		Klient->IdKlient=glStrToInt64(DM->DocAllIDKLDOC->AsString);
		Klient->UpdateForm();
        }
}
//-----------------------------------------------------------------------------
//******************************************************************************
//-----------------------------------------------------------------------------

void TFormaDocSchet::OpenFormSpiskaSprInfBase(void)
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


void TFormaDocSchet::OpenFormSpiskaSprBSchet(void)
{
InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprBankSchet.1",IID_IFormaSpiskaSprBankSchet,
													(void**)&FormSpiskaSprBSchet);
FormSpiskaSprBSchet->Init(InterfaceMainObject,InterfaceImpl);
FormSpiskaSprBSchet->IdFirm=glStrToInt64(DM->DocAllIDFIRMDOC->AsString);
FormSpiskaSprBSchet->DM->IdFirm=glStrToInt64(DM->DocAllIDFIRMDOC->AsString);
FormSpiskaSprBSchet->DM->OpenTable();
//FormSpiskaSprBSchet->LabelFirma->Caption="Фирма: "+DM->DocAllNAMEFIRM->AsString;
FormSpiskaSprBSchet->NumberProcVibor=ViborBankSchet;
FormSpiskaSprBSchet->Vibor=true;



}
//------------------------------------------------------------------------

void TFormaDocSchet::OpenPrintForm(void)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
porNumStr=1;


//шапка
PrintForm->SS->BeginUpdate();
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
void TFormaDocSchet::OutputZagolovokReport(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numRow=0;
numCol=1;

prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";
prForm->SS->RowsAutoHeight=true;
        TcxSSHeader *cHeader;

        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 10;
        cHeader->Size[2] = 40;
		cHeader->Size[3] = 250;
        cHeader->Size[4] = 60;
        cHeader->Size[5] = 80;
        cHeader->Size[6] = 60;
        cHeader->Size[7] = 70;
        cHeader->Size[8] = 80;


cell = prForm->SS->ActiveSheet->GetCellObject(4, numRow);
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haCENTER;
cell->Text="Внимание! Оплата данного счета означает согласие с условиями поставки товара. Уведомление об оплате";
delete cell;
numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(4, numRow);
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haCENTER;
cell->Text="обязательно, в противном случае не гарантируется наличие товара на складе. Товар отпускается по факту";
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(4, numRow);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Text="прихода денег на р/с Поставщика, самовывозом, при наличии доверенности и паспорта.";
delete cell;
numRow++;

TRect rect;
		rect.Left = 2;
		rect.Top = numRow;
		rect.Right = 8;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haCENTER;
cell->Text="Образец заполнения платежного поручения";
delete cell;
numRow++;
prForm->SS->ActiveSheet->Rows->Size[numRow]=5;
numRow++;

IDMSprFirm *DMSprFirm;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
													(void**)&DMSprFirm);
DMSprFirm->Init(InterfaceMainObject,InterfaceImpl);
DMSprFirm->OpenElement(DM->DocAllIDFIRMDOC->AsInt64);
IDMSprBankSchet * DMSprBSchet;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprBankSchet.1",IID_IDMSprBankSchet,
													(void**)&DMSprBSchet);
DMSprBSchet->Init(InterfaceMainObject,InterfaceImpl);
DMSprBSchet->OpenElement(DM->DocIDBSCHET_DSCH->AsInt64);
IDMSprBank * DMSprBank;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprBank.1",IID_IDMSprBank,
													(void**)&DMSprBank);
DMSprBank->Init(InterfaceMainObject,InterfaceImpl);
DMSprBank->OpenElement(DMSprBSchet->ElementIDBANKBSCHET->AsInt64);


numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 10;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="ИНН "+DMSprFirm->ElementINNFIRM->AsString+
        "                 КПП"+DMSprFirm->ElementKPPFIRM->AsString;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Text="Cч. №";
delete cell;
numCol++;


		rect.Left = numCol;
		rect.Top = numRow;
		rect.Right = numCol+2;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Text=DMSprBSchet->ElementNUMBSCHET->AsString;
cell->Style->HorzTextAlign = haLEFT;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Text=DMSprBSchet->ElementNUMBSCHET->AsString;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
numCol++;
numRow++; 

//***************************

numCol=2;
		rect.Left = numCol;
		rect.Top = numRow;
		rect.Right = numCol+2;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);

String Text="";

		Text=Trim(DMSprFirm->ElementFNAMEFIRM->AsString);
		cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
		cell->Text=Text;
		cell->Style->HorzTextAlign = haLEFT;
		cell->Style->WordBreak = true;
		prForm->SS->ActiveSheet->Rows->Size[numRow]=60;
		delete cell;
		//***************************
        cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        delete cell;
        cell = prForm->SS->ActiveSheet->GetCellObject(5, numRow);
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        delete cell;
        cell = prForm->SS->ActiveSheet->GetCellObject(8, numRow);
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        delete cell;
        numRow++;



//новая строка
numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="Получатель";
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
numCol++;
numRow++;

//***************************
int num_row=numRow;
		numCol=2;
		rect.Left = numCol;
		rect.Top = numRow;
		rect.Right = numCol+2;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);


				Text=Trim(DMSprBank->ElementNAMEBANK->AsString)+" г."+Trim(DMSprBank->ElementGORBANK->AsString);
				cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
				cell->Text=Text;
				cell->Style->WordBreak = true;
				cell->Style->HorzTextAlign = haLEFT;
				delete cell;
				prForm->SS->ActiveSheet->Rows->Size[numRow]=60;

		//***************************
        cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        delete cell;

        cell = prForm->SS->ActiveSheet->GetCellObject(5, numRow);
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        delete cell;

        cell = prForm->SS->ActiveSheet->GetCellObject(8, numRow);
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        delete cell;
        numRow++;

//********************************************
//********************************************
//вставим БИК
cell = prForm->SS->ActiveSheet->GetCellObject(5, num_row);
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="БИК";
delete cell;

		rect.Left = 6;
		rect.Top = num_row ;
		rect.Right = 8;
		rect.Bottom = num_row;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(6, num_row);
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Text=DMSprBank->ElementBIKBANK->AsString;
delete cell;

//новая строка
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="Банк получателя";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(3, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;


cell = prForm->SS->ActiveSheet->GetCellObject(4, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(5, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="Сч. №";
delete cell;


		rect.Left = 6;
		rect.Top = numRow;
		rect.Right = 8;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(6, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text=DMSprBank->ElementKSBANK->AsString;
cell->Style->HorzTextAlign = haLEFT;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(7, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(8, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

numRow++;
prForm->SS->ActiveSheet->Rows->Size[numRow]=5;
numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(3, numRow);
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haLEFT;
cell->Text="Счет №"+DM->DocAllNUMDOC->AsString+
        " от "+DateToStr(DM->DocAllPOSDOC->AsDateTime);
delete cell;
numRow++;

for (int i=2;i<=8;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(i, numRow);
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        }
prForm->SS->ActiveSheet->Rows->Size[numRow]=5;
numRow++;
prForm->SS->ActiveSheet->Rows->Size[numRow]=5;
numRow++;

//Поставщик
//***************************

if (DMSprFirm->ElementTYPEFIRM->AsInteger==0)
        { //организация
Text="ПОСТАВЩИК: "+Trim(DMSprFirm->ElementFNAMEFIRM->AsString)+
                ". Адрес: "+DMSprFirm->ElementUADRFIRM->AsString+
                ". Телефон: "+DMSprFirm->ElementTELFIRM->AsString;
        }
else
        { //предприниматель
Text="ПОСТАВЩИК: "+Trim(DMSprFirm->ElementFNAMEFIRM->AsString)+
                ". Свидетельство №"+DMSprFirm->ElementNUMDOCREGFIRM->AsString+
                " от "+DMSprFirm->ElementDATEDOCREGFIRM->AsString+
                ". Телефон: "+DMSprFirm->ElementTELFIRM->AsString;
        }

		rect.Left = 3;
		rect.Top = numRow;
		rect.Right = 8;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);

		numCol=3;
		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
		cell->Style->WordBreak = true;
		cell->Text=Text;
		delete cell;
		prForm->SS->ActiveSheet->Rows->Size[numRow]=60;

//				numCol++;
//		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//		cell->Style->WordBreak = true;
//		cell->Text="";
//		delete cell;
//				numCol++;
//		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//		cell->Style->WordBreak = true;
//		cell->Text="";
//		delete cell;
//				numCol++;
//		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//		cell->Style->WordBreak = true;
//		cell->Text="";
//		delete cell;
//				numCol++;
//		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//		cell->Style->WordBreak = true;
//		cell->Text="";
//				delete cell;
//				numCol++;
//		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//		cell->Style->WordBreak = true;
//		cell->Text="";
//		delete cell;
//        numCol++;
//		cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//		cell->Text="1";
//		delete cell;


//********************************************


DMSprFirm->kanRelease();
DMSprBSchet->kanRelease();
DMSprBank->kanRelease();
numRow++;
//Покупатель
//***************************

IDMSprKlient * DMSprKlient;
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprKlient,IID_IDMSprKlient,
													(void**)&DMSprKlient);
DMSprKlient->Init(InterfaceMainObject,InterfaceImpl);
DMSprKlient->OpenElement(glStrToInt64(DM->DocAllIDKLDOC->AsString));
Text="ПОКУПАТЕЛЬ: "+Trim(DMSprKlient->ElementFNAME->AsString)+
                " ИНН: "+DMSprKlient->ElementINNKLIENT->AsString+
                " Адрес: "+DMSprKlient->ElementADRKLIENT->AsString+
                " Телефон:"+DMSprKlient->ElementTELKLIENT->AsString;
DMSprKlient->kanRelease();

		rect.Left = 3;
		rect.Top = numRow;
		rect.Right = 8;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
		cell = prForm->SS->ActiveSheet->GetCellObject(3, numRow);
		cell->Text=Text;
		cell->Style->WordBreak = true;
		prForm->SS->ActiveSheet->Rows->Size[numRow]=60;
		delete cell;
		//***************************


//********************************************
numRow++;
prForm->SS->ActiveSheet->Rows->Size[numRow]=5;
numRow++;
//*************************************************************************
//заголовок таблицы
numCol=1;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
delete cell;

numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="№";
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
void TFormaDocSchet::OutputString(TSheetEditor *prForm)
{
numCol=2;
TcxSSCellObject *cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IntToStr(porNumStr);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTNAMENOM->AsString;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->WordBreak = true;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTKOLSCHT->AsString;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTNAMEED->AsString;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTKFSCHT->AsFloat,ffFixed,10,3);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->HorzTextAlign = haRIGHT;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTPRICESCHT->AsFloat,ffFixed,10,2);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->HorzTextAlign = haRIGHT;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTSUMSCHT->AsFloat,ffFixed,10,2);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->HorzTextAlign = haRIGHT;
delete cell;
numCol++;
}


//------------------------------------------------------------------------------
void TFormaDocSchet::OutputPodavalReport(TSheetEditor *prForm)
{
prForm->SS->ActiveSheet->Rows->Size[numRow]=5;
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
prForm->SS->ActiveSheet->Rows->Size[numRow]=5;
numRow++;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Руководитель __________________________ ";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(8, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Text="Бухгалтер  __________________________ ";
delete cell;
}
//---------------------------------------------------------------

void __fastcall TFormaDocSchet::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("DocSchetNaOpl");
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocSchet::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;

		OpenFormSpiskaSprNom();

}
//---------------------------------------------------------------------------

void __fastcall TFormaDocSchet::cxGrid1DBTableView1NAMEEDPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;

		OpenFormSpiskaSprEd();

}
//---------------------------------------------------------------------------


void __fastcall TFormaDocSchet::cxButtonRealClick(TObject *Sender)
{
DM->SaveDoc();
//проверим а нет ли уже счета
DM->pFIBQ->Close();
DM->pFIBQ->SQL->Clear();
DM->pFIBQ->SQL->Add("select IDDOC from GALLDOC where TDOC='REA'");
DM->pFIBQ->SQL->Add(" and IDDOCOSNDOC="+IntToStr(DM->DocAllIDDOC->AsInt64));
DM->pFIBQ->ExecQuery();

IFormaDocReal* doc;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocReal.1",IID_IFormaDocReal,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceImpl);
if (!doc) return;

if (DM->pFIBQ->RecordCount!=0)
        {
		 //откроем документ
		doc->DM->OpenDoc(DM->pFIBQ->FieldByName("IDDOC")->AsInt64);
		}
else
		{
//создадим документ
doc->DM->NewDoc();
doc->DM->DocAll->Edit();
doc->DM->DocAllIDDOCOSNDOC->AsString=DM->DocAllIDDOC->AsString;
doc->DM->DocAllIDBASE_GALLDOC->AsString=DM->DocAllIDBASE_GALLDOC->AsString;
doc->DM->DocAllNAME_SINFBASE_OBMEN->AsString=DM->DocAllNAME_SINFBASE_OBMEN->AsString;
doc->DM->DocAllIDFIRMDOC->AsString=DM->DocAllIDFIRMDOC->AsString;
doc->DM->DocAllNAMEFIRM->AsString=DM->DocAllNAMEFIRM->AsString;
doc->DM->DocAllIDSKLDOC->AsInteger=DM->DocAllIDSKLDOC->AsInteger;
doc->DM->DocAllNAMESKLAD->AsString=DM->DocAllNAMESKLAD->AsString;
doc->DM->DocAllIDKLDOC->AsString=DM->DocAllIDKLDOC->AsString;
doc->DM->DocAllNAMEKLIENT->AsString=DM->DocAllNAMEKLIENT->AsString;
doc->DM->DocAll->Post();

doc->DM->Doc->Edit();
doc->DM->DocIDTPRICEREA->AsString=DM->DocIDTPRICESCH->AsString;
doc->DM->DocPRIMREA->AsString="Счет №"+DM->DocAllNUMDOC->AsString+
						" от "+ DM->DocAllPOSDOC->AsString;
doc->DM->DocIDGRPOLREA->AsString=DM->DocAllIDKLDOC->AsString;
doc->DM->DocNAMEKLIENT->AsString=DM->DocAllNAMEKLIENT->AsString;
doc->DM->DocIDBSCHETREA->AsString=DM->DocIDBSCHET_DSCH->AsString;
doc->DM->DocNAMEBSCHET->AsString=DM->DocNAMEBSCHET->AsString;
doc->DM->Doc->Post();

DM->DocT->First();
while(!DM->DocT->Eof)
        {
		doc->DM->DocT->Insert();
		doc->DM->DocTIDNOMREAT->AsString=DM->DocTIDNOMSCHT->AsString;
		doc->DM->DocTNAMENOM->AsString=DM->DocTNAMENOM->AsString;
		doc->DM->DocTIDEDREAT->AsString=DM->DocTIDEDSCHT->AsString;
		doc->DM->DocTNAMEED->AsString=DM->DocTNAMEED->AsString;
		doc->DM->DocTKOLREAT->AsFloat=DM->DocTKOLSCHT->AsFloat;
		doc->DM->DocTKFREAT->AsFloat=DM->DocTKFSCHT->AsFloat;
		doc->DM->DocTPRICEREAT->AsFloat=DM->DocTPRICESCHT->AsFloat;
		doc->DM->DocT->Post();
		DM->DocT->Next();
		}
		}
doc->UpdateForm();

DM->pFIBQ->Close();	
}
//---------------------------------------------------------------------------





void __fastcall TFormaDocSchet::TypePriceComboBoxPropertiesChange(
      TObject *Sender)
{
if(flObrabatChangeTypePrice==false)return;
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

if ( TypePriceComboBox->ItemIndex!=0)
		{
		DMSprTypePrice->Table->First();
		DMSprTypePrice->Table->MoveBy(TypePriceComboBox->ItemIndex-1);
		DM->Doc->Edit();
		DM->DocIDTPRICESCH->AsString=DMSprTypePrice->TableID_TPRICE->AsString;
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
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDTPRICESCH->AsString),
											 glStrToInt64(DM->DocTIDNOMSCHT->AsString));
						DM->DocTPRICESCHT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKFSCHT->AsFloat;
						DM->DocT->Post();
						DM->DocT->Next();
						}
				DMSprPrice->kanRelease();
				}
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocSchet::NameKlientcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprKlient(); 	
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocSchet::NameBSchetcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprBSchet();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocSchet::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprFirm();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocSchet::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprSklad();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocSchet::NameInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprInfBase();  	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocSchet::ActionAddStringExecute(TObject *Sender)
{
if (Prosmotr==true) return;
ActionOperation=aoAddNewString;
OpenFormSpiskaSprNom();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocSchet::ActionDeleteStringExecute(TObject *Sender)
{
if (Prosmotr==true) return;
DM->DeleteStringDoc();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocSchet::NumDoccxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocSchet::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocSchet::PrimcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaDocSchet::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaDocSchet::RunExternalModule(__int64 id_module, int type_module)
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

void __fastcall TFormaDocSchet::ActionCloseExecute(TObject *Sender)
{
DM->CloseDoc();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocSchet::ActionOKExecute(TObject *Sender)
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

void __fastcall TFormaDocSchet::ActionDvRegExecute(TObject *Sender)
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

void __fastcall TFormaDocSchet::ActionSaveExecute(TObject *Sender)
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

void __fastcall TFormaDocSchet::ActionPrintExecute(TObject *Sender)
{
OpenPrintForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocSchet::ToolButtonCreateRealClick(TObject *Sender)
{
DM->SaveDoc();
//проверим а нет ли уже счета
DM->pFIBQ->Close();
DM->pFIBQ->SQL->Clear();
DM->pFIBQ->SQL->Add("select IDDOC from GALLDOC where TDOC='REA'");
DM->pFIBQ->SQL->Add(" and IDDOCOSNDOC="+IntToStr(DM->DocAllIDDOC->AsInt64));
DM->pFIBQ->ExecQuery();

IFormaDocReal* doc;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocReal.1",IID_IFormaDocReal,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceImpl);
if (!doc) return;

if (DM->pFIBQ->RecordCount!=0)
        {
		 //откроем документ
		doc->DM->OpenDoc(DM->pFIBQ->FieldByName("IDDOC")->AsInt64);
		}
else
		{
//создадим документ
doc->DM->NewDoc();
doc->DM->DocAll->Edit();
doc->DM->DocAllIDDOCOSNDOC->AsString=DM->DocAllIDDOC->AsString;
doc->DM->DocAllIDBASE_GALLDOC->AsString=DM->DocAllIDBASE_GALLDOC->AsString;
doc->DM->DocAllNAME_SINFBASE_OBMEN->AsString=DM->DocAllNAME_SINFBASE_OBMEN->AsString;
doc->DM->DocAllIDFIRMDOC->AsString=DM->DocAllIDFIRMDOC->AsString;
doc->DM->DocAllNAMEFIRM->AsString=DM->DocAllNAMEFIRM->AsString;
doc->DM->DocAllIDSKLDOC->AsInteger=DM->DocAllIDSKLDOC->AsInteger;
doc->DM->DocAllNAMESKLAD->AsString=DM->DocAllNAMESKLAD->AsString;
doc->DM->DocAllIDKLDOC->AsString=DM->DocAllIDKLDOC->AsString;
doc->DM->DocAllNAMEKLIENT->AsString=DM->DocAllNAMEKLIENT->AsString;
doc->DM->DocAll->Post();

doc->DM->Doc->Edit();
doc->DM->DocIDTPRICEREA->AsString=DM->DocIDTPRICESCH->AsString;
doc->DM->DocPRIMREA->AsString="Счет №"+DM->DocAllNUMDOC->AsString+
						" от "+ DM->DocAllPOSDOC->AsString;
doc->DM->DocIDGRPOLREA->AsString=DM->DocAllIDKLDOC->AsString;
doc->DM->DocNAMEKLIENT->AsString=DM->DocAllNAMEKLIENT->AsString;
doc->DM->DocIDBSCHETREA->AsString=DM->DocIDBSCHET_DSCH->AsString;
doc->DM->DocNAMEBSCHET->AsString=DM->DocNAMEBSCHET->AsString;
doc->DM->Doc->Post();

DM->DocT->First();
while(!DM->DocT->Eof)
		{
		doc->DM->DocT->Append();
		doc->DM->DocTIDNOMREAT->AsString=DM->DocTIDNOMSCHT->AsString;
		doc->DM->DocTNAMENOM->AsString=DM->DocTNAMENOM->AsString;
		doc->DM->DocTIDEDREAT->AsString=DM->DocTIDEDSCHT->AsString;
		doc->DM->DocTNAMEED->AsString=DM->DocTNAMEED->AsString;
		doc->DM->DocTKOLREAT->AsFloat=DM->DocTKOLSCHT->AsFloat;
		doc->DM->DocTKFREAT->AsFloat=DM->DocTKFSCHT->AsFloat;
		doc->DM->DocTPRICEREAT->AsFloat=DM->DocTPRICESCHT->AsFloat;
		doc->DM->DocT->Post();
		DM->DocT->Next();
		}
		}
doc->UpdateForm();

DM->pFIBQ->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocSchet::ToolButtonCreateRealRoznClick(TObject *Sender)
{
DM->SaveDoc();
//проверим а нет ли уже счета
DM->pFIBQ->Close();
DM->pFIBQ->SQL->Clear();
DM->pFIBQ->SQL->Add("select IDDOC from GALLDOC where TDOC='REALROZN'");
DM->pFIBQ->SQL->Add(" and IDDOCOSNDOC="+IntToStr(DM->DocAllIDDOC->AsInt64));
DM->pFIBQ->ExecQuery();

IFormaDocRealRozn* doc;
InterfaceGlobalCom->kanCreateObject(ProgId_FormaDocRealRozn,IID_IFormaDocRealRozn,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceImpl);
if (!doc) return;

if (DM->pFIBQ->RecordCount!=0)
        {
		 //откроем документ
		doc->DM->OpenDoc(DM->pFIBQ->FieldByName("IDDOC")->AsInt64);
		}
else
		{
//создадим документ
doc->DM->NewDoc();
doc->DM->DocAll->Edit();
doc->DM->DocAllIDDOCOSNDOC->AsString=DM->DocAllIDDOC->AsString;
doc->DM->DocAllIDBASE_GALLDOC->AsString=DM->DocAllIDBASE_GALLDOC->AsString;
doc->DM->DocAllNAME_SINFBASE_OBMEN->AsString=DM->DocAllNAME_SINFBASE_OBMEN->AsString;
doc->DM->DocAllIDFIRMDOC->AsString=DM->DocAllIDFIRMDOC->AsString;
doc->DM->DocAllNAMEFIRM->AsString=DM->DocAllNAMEFIRM->AsString;
doc->DM->DocAllIDSKLDOC->AsInteger=DM->DocAllIDSKLDOC->AsInteger;
doc->DM->DocAllNAMESKLAD->AsString=DM->DocAllNAMESKLAD->AsString;
doc->DM->DocAllIDKLDOC->AsString=DM->DocAllIDKLDOC->AsString;
doc->DM->DocAllNAMEKLIENT->AsString=DM->DocAllNAMEKLIENT->AsString;
doc->DM->DocAll->Post();

doc->DM->Doc->Edit();
doc->DM->DocIDTPRICE_DREALROZN->AsString=DM->DocIDTPRICESCH->AsString;
doc->DM->DocPRIM_DREALROZN->AsString="Счет №"+DM->DocAllNUMDOC->AsString+
						" от "+ DM->DocAllPOSDOC->AsString;
doc->DM->Doc->Post();

DM->DocT->First();
while(!DM->DocT->Eof)
        {
		doc->DM->DocT->Append();
		doc->DM->DocTIDNOM_DREALROZNT->AsString=DM->DocTIDNOMSCHT->AsString;
		doc->DM->DocTNAMENOM->AsString=DM->DocTNAMENOM->AsString;
		doc->DM->DocTIDED_DREALROZNT->AsString=DM->DocTIDEDSCHT->AsString;
		doc->DM->DocTNAMEED->AsString=DM->DocTNAMEED->AsString;
		doc->DM->DocTKOL_DREALROZNT->AsFloat=DM->DocTKOLSCHT->AsFloat;
		doc->DM->DocTKF_DREALROZNT->AsFloat=DM->DocTKFSCHT->AsFloat;
		doc->DM->DocTPRICE_DREALROZNT->AsFloat=DM->DocTPRICESCHT->AsFloat;
		doc->DM->DocT->Post();
		DM->DocT->Next();
		}
		}
doc->UpdateForm();

DM->pFIBQ->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocSchet::ToolButtonCreateCheckClick(TObject *Sender)
{
DM->SaveDoc();
//проверим а нет ли уже счета
DM->pFIBQ->Close();
DM->pFIBQ->SQL->Clear();
DM->pFIBQ->SQL->Add("select IDDOC from GALLDOC where TDOC='CHK'");
DM->pFIBQ->SQL->Add(" and IDDOCOSNDOC="+IntToStr(DM->DocAllIDDOC->AsInt64));
DM->pFIBQ->ExecQuery();

IFormaDocCheck* doc;
InterfaceGlobalCom->kanCreateObject(ProgId_FormaDocCheck,IID_IFormaDocCheck,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceImpl);
if (!doc) return;

if (DM->pFIBQ->RecordCount!=0)
        {
		 //откроем документ
		doc->DM->OpenDoc(DM->pFIBQ->FieldByName("IDDOC")->AsInt64);
		}
else
		{
//создадим документ
doc->DM->NewDoc();
doc->DM->DocAll->Edit();
doc->DM->DocAllIDDOCOSNDOC->AsString=DM->DocAllIDDOC->AsString;
doc->DM->DocAllIDBASE_GALLDOC->AsString=DM->DocAllIDBASE_GALLDOC->AsString;
doc->DM->DocAllNAME_SINFBASE_OBMEN->AsString=DM->DocAllNAME_SINFBASE_OBMEN->AsString;
doc->DM->DocAllIDFIRMDOC->AsString=DM->DocAllIDFIRMDOC->AsString;
doc->DM->DocAllNAMEFIRM->AsString=DM->DocAllNAMEFIRM->AsString;
doc->DM->DocAllIDSKLDOC->AsInteger=DM->DocAllIDSKLDOC->AsInteger;
doc->DM->DocAllNAMESKLAD->AsString=DM->DocAllNAMESKLAD->AsString;
doc->DM->DocAllIDKLDOC->AsString=DM->DocAllIDKLDOC->AsString;
doc->DM->DocAllNAMEKLIENT->AsString=DM->DocAllNAMEKLIENT->AsString;
doc->DM->DocAll->Post();

doc->DM->Doc->Edit();
doc->DM->DocIDTPRICE->AsString=DM->DocIDTPRICESCH->AsString;
doc->DM->DocPRIMCHK->AsString="Счет №"+DM->DocAllNUMDOC->AsString+
						" от "+ DM->DocAllPOSDOC->AsString;
doc->DM->DocIDBSCHET_DCHK->AsString=DM->DocIDBSCHET_DSCH->AsString;
doc->DM->DocNAMEBSCHET->AsString=DM->DocNAMEBSCHET->AsString;
doc->DM->Doc->Post();

DM->DocT->First();
while(!DM->DocT->Eof)
		{
		doc->DM->DocT->Append();
		doc->DM->DocTIDNOMCHKT->AsString=DM->DocTIDNOMSCHT->AsString;
		doc->DM->DocTNAMENOM->AsString=DM->DocTNAMENOM->AsString;
		doc->DM->DocTIDEDCHKT->AsString=DM->DocTIDEDSCHT->AsString;
		doc->DM->DocTNAMEED->AsString=DM->DocTNAMEED->AsString;
		doc->DM->DocTKOLCHKT->AsFloat=DM->DocTKOLSCHT->AsFloat;
		doc->DM->DocTKFCHKT->AsFloat=DM->DocTKFSCHT->AsFloat;
		doc->DM->DocTPRICECHKT->AsFloat=DM->DocTPRICESCHT->AsFloat;
		doc->DM->DocT->Post();
		DM->DocT->Next();
		}
		}
doc->UpdateForm();

DM->pFIBQ->Close();
}
//---------------------------------------------------------------------------

