//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop


//---------------------------------------------------------------------------
#include "UFormaDocPer.h"
#include "IDMSprFirm.h"
#include "IDMSprNom.h"
#include "IDMSprPrice.h"
#include "IDMDocPrihNakl.h"
#include "IDMQueryRead.h"
#include "IDMRegGoods.h"


#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//----------------------------------------------------------------------------
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
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxDBEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxLabel"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaDocPer::TFormaDocPer(TComponent* Owner)
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
bool TFormaDocPer::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPer.1",IID_IDMDocPer,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи
flObrabatChangeTypePrice=false;

NameUserDBText->DataSource=DM->DataSourceDocAll;
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceDocT;

NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameSkladcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NumDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameProjectcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameBusinessOpercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PrefiksNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;


NameSkladPolcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
PrimcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;



ActionOperation=aoNO;

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice,
												 (void**)&DMSprRoznTypePrice);
DMSprRoznTypePrice->Init(InterfaceMainObject,InterfaceImpl);

DMSprRoznTypePrice->OpenTable();
RoznTypePriceComboBox->Properties->Items->Clear();
RoznTypePriceComboBox->Properties->Items->Add("Не задан");
DMSprRoznTypePrice->Table->First();
while (!DMSprRoznTypePrice->Table->Eof)
        {
		RoznTypePriceComboBox->Properties->Items->Add(DMSprRoznTypePrice->TableNAME_TPRICE->AsString);
        DMSprRoznTypePrice->Table->Next();
		}

//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
												 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);

DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaDocPerImpl),false);
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
int TFormaDocPer::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaDocPer::UpdateForm(void)
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
flObrabatChangeTypePrice=false;
RoznTypePriceComboBox->ItemIndex=DMSprRoznTypePrice->GetIndexTypePricePoId(glStrToInt64(DM->DocIDRTPRICE_DPER->AsString));
flObrabatChangeTypePrice=true;


//if (DM->SkladPolRozn==true || DM->SkladOtprRozn==true)
//	{
//	cxGrid1DBTableView1PRICEPERT->Visible=true;
//	cxGrid1DBTableView1SUMPERT->Visible=true;
//
//	}
//else
//	{
//	cxGrid1DBTableView1PRICEPERT->Visible=false;
//	cxGrid1DBTableView1SUMPERT->Visible=false;
//
//	}
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocPer::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokFirm)SpisokFirm->kanRelease();
if(SpisokSklad)SpisokSklad->kanRelease();
if(SpisokNom)SpisokNom->kanRelease();
if(SpisokEd)SpisokEd->kanRelease();
if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
if(SpisokBusinessOper)SpisokBusinessOper->kanRelease();
if(SpisokProject)SpisokProject->kanRelease();

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
DMSprRoznTypePrice->kanRelease();
Action=caFree;
}
//---------------------------------------------------------------------------




void TFormaDocPer::OpenFormSpiskaSprEd(void)
{
if (Prosmotr==true) return;
if (SpisokEd==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
												 (void**)&SpisokEd);
		SpisokEd->Init(InterfaceMainObject,InterfaceImpl);
		SpisokEd->NumberProcVibor=ER_Ed;
		SpisokEd->Vibor=true;
		SpisokEd->DM->OpenTable(glStrToInt64(DM->DocTIDNOMPERT->AsString));
//        SpisokEd->LabelNom->Caption="Единицы номенклатуры: "+DM->DocTNAMENOM->AsString;
//		SpisokEd->HintLabel->Caption="Выберите единицу номенклатуры для документа Перемещение №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;

        }
}
//-----------------------------------------------------------------------------
void TFormaDocPer::OpenFormSpiskaSprNom(void)
{
if (Prosmotr==true) return;
if (SpisokNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
												 (void**)&SpisokNom);
		SpisokNom->Init(InterfaceMainObject,InterfaceImpl);
		SpisokNom->NumberProcVibor=ER_Nom;
		SpisokNom->Vibor=true;
		SpisokNom->DM->IdTypePrice=glStrToInt64(DM->DocIDRTPRICE_DPER->AsString);
		SpisokNom->IdNom=glStrToInt64(DM->DocTIDNOMPERT->AsString);
        SpisokNom->UpdateForm();
//        SpisokNom->HintLabel->Caption="Выберите номенклатуру для документа Перемещение №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
        }

}

//---------------------------------------------------------------------------
int TFormaDocPer::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{


if (number_procedure_end==ER_Nom)//EditRekvisit==ViborTovar)
        {

		if (type_event==1)
                {
                if (ActionOperation==aoAddNewString)
                        {
						DM->AddDocNewString();
                        }
				DM->DocT->Edit();
				DM->DocTIDNOMPERT->AsString=SpisokNom->DM->ElementIDNOM->AsString;
				DM->DocTNAMENOM->AsString=SpisokNom->DM->ElementNAMENOM->AsString;
				DM->DocTTNOM->AsInteger=SpisokNom->DM->ElementTNOM->AsInteger;
				DM->DocTKOLPERT->AsFloat=1;
				DM->DocTIDEDPERT->AsString=SpisokNom->DM->ElementIDBASEDNOM->AsString;
				DM->DocTNAMEED->AsString=SpisokNom->DM->BasEdNAMEED->AsString;
				DM->DocTKFPERT->AsFloat=SpisokNom->DM->BasEdKFED->AsFloat;

				if (DM->SkladOtprRozn==false && DM->SkladPolRozn==false)
					{  //с оптового на оптовый
					DM->DocTPRICEPERT->AsFloat=0;
					}

				if (DM->SkladOtprRozn==true && DM->SkladPolRozn==true)
					{ //с розничного на розничный //цена со склада  отправителя
					DM->DocTPRICEPERT->AsFloat=SpisokNom->DM->TableZNACH_PRICE->AsFloat
							*DM->DocTKFPERT->AsFloat;
					}

				if (DM->SkladOtprRozn==true && DM->SkladPolRozn==false)
					{ //с розничного на оптовый  цена со склада  отправителя
					DM->DocTPRICEPERT->AsFloat=SpisokNom->DM->TableZNACH_PRICE->AsFloat
							*DM->DocTKFPERT->AsFloat;
					}  

				if (DM->SkladOtprRozn==false && DM->SkladPolRozn==true)
					{  //с оптового на розничный
					//если склад получатель розничный, а отправитель оптовый, то из справочника
					IDMSprPrice * DMSprPrice;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
												 (void**)&DMSprPrice);
					DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);

						DMSprPrice->FindElement( glStrToInt64(DM->DocIDRTPRICE_DPER->AsString),
											 glStrToInt64(DM->DocTIDNOMPERT->AsString));
						DM->DocTPRICEPERT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
                                                        DM->DocTKFPERT->AsFloat;
					delete DMSprPrice;
					}




				DM->DocT->Post();
                }
		SpisokNom=0;
		cxGrid1->SetFocus();
		cxGrid1DBTableView1KOLPERT->Selected=true;
        }

if (number_procedure_end==ER_Ed)//EditRekvisit==ViborEdinica)
        {
		if (type_event==1)
                {
                DM->DocT->Edit();
				DM->DocTIDEDPERT->AsString=SpisokEd->DM->ElementIDED->AsString;
                DM->DocTNAMEED->AsString=SpisokEd->DM->ElementNAMEED->AsString;
                DM->DocTKFPERT->AsFloat=SpisokEd->DM->ElementKFED->AsFloat;
                DM->DocT->Post();
                }
		SpisokEd=0;
		cxGrid1->SetFocus();
		cxGrid1DBTableView1PRICEPERT->Selected=true;		
        }

if (number_procedure_end==ER_Firm)//EditRekvisit==ViborFirm)
        {
		if (type_event==1)
                {
                DM->DocAll->Edit();
				DM->DocAllIDFIRMDOC->AsString=SpisokFirm->DM->ElementIDFIRM->AsString;
				DM->DocAllNAMEFIRM->AsString=SpisokFirm->DM->ElementNAMEFIRM->AsString;
                DM->DocAll->Post();
                }
		SpisokFirm=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
        }

if (number_procedure_end==ER_Sklad)//EditRekvisit==ViborSklad)
        {
		if (type_event==1)
                {
                DM->DocAll->Edit();
				DM->DocAllIDSKLDOC->AsString=SpisokSklad->DM->ElementIDSKLAD->AsString;
				DM->DocAllNAMESKLAD->AsString=SpisokSklad->DM->ElementNAMESKLAD->AsString;
				DM->DocAll->Post();
				UpdateForm();
                }
		SpisokSklad=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
        }

if (number_procedure_end==ER_SkladPol)//EditRekvisit==ViborSkladPol)
        {
		if (type_event==1)
                {
                DM->Doc->Edit();
				DM->DocIDSKLPOLPER->AsString=SpisokSklad->DM->ElementIDSKLAD->AsString;
                DM->DocNAMESKLAD->AsString=SpisokSklad->DM->ElementNAMESKLAD->AsString;
				DM->Doc->Post();
				UpdateForm();
                }
		SpisokSklad=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
        }


if (number_procedure_end==ER_InfBase)//EditRekvisit==ViborInfBase)
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


if (number_procedure_end==ER_Project)
		{
		if (type_event==1)
				{
				EndViborProject()  ;
				}
		SpisokProject=0;
		}

if (number_procedure_end==ER_BusinessOper)
		{
		if (type_event==1)
				{
				EndViborBusinessOper()  ;
				}
		SpisokBusinessOper=0;
		}

if (number_procedure_end==ER_NomSoSklada)
		{
		if (type_event==1)    //выбор сделан
			{
			EndViborNomSoSklada();
			}
		SpisokNom=0;
		}

ActionOperation=aoNO;
return -1;
}
//-----------------------------------------------------------------------------







void TFormaDocPer::OpenFormSpiskaSprFirm(void)
{
if (Prosmotr==true) return;
if (SpisokFirm==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
												 (void**)&SpisokFirm);
		SpisokFirm->Init(InterfaceMainObject,InterfaceImpl);
		SpisokFirm->NumberProcVibor=ER_Firm;
		SpisokFirm->Vibor=true;
//        SpisokFirm->HintLabel->Caption="Выберите фирму для документа Перемещение №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
        }

}
//---------------------------------------------------------------------------
void TFormaDocPer::OpenFormSpiskaSprSklad(void)
{
if (Prosmotr==true) return;
if (SpisokSklad==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
												 (void**)&SpisokSklad);
		SpisokSklad->Init(InterfaceMainObject,InterfaceImpl);
		SpisokSklad->NumberProcVibor=ER_Sklad;
		SpisokSklad->Vibor=true;
//        SpisokSklad->HintLabel->Caption="Выберите склад-отправитель для документа Перемещение №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
        }

}
//---------------------------------------------------------------------------
void TFormaDocPer::OpenFormSpiskaSprSkladPol(void)
{
if (Prosmotr==true) return;
if (SpisokSklad==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
												 (void**)&SpisokSklad);
		SpisokSklad->Init(InterfaceMainObject,InterfaceImpl);
		SpisokSklad->NumberProcVibor=ER_SkladPol;
		SpisokSklad->Vibor=true;
//        SpisokSklad->HintLabel->Caption="Выберите склад-получатель для документа Перемещение №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
        }

}
//--------------------------------------------------------------------------





void __fastcall TFormaDocPer::AddNewStringClick(TObject *Sender)
{
if (Prosmotr==true) return;
DM->AddDocNewString();
OpenFormSpiskaSprNom();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPer::DeleteStringClick(TObject *Sender)
{
if (Prosmotr==true) return;
DM->DeleteStringDoc();
}
//---------------------------------------------------------------------------


void TFormaDocPer::OpenPrintForm(void)
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
RoznSumDoc=0;

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
void TFormaDocPer::OutputZagolovokReport(TSheetEditor *prForm)
{
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

numRow=1;
numCol=2;
TcxSSCellObject *cell;
IDMSprFirm *Firma;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
												 (void**)&Firma);
		Firma->Init(InterfaceMainObject,InterfaceImpl);
Firma->OpenElement(DM->DocAllIDFIRMDOC->AsInteger);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=Firma->ElementFNAMEFIRM->AsString
        +" ИНН "+Firma->ElementINNFIRM->AsString;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Адрес: "+Firma->ElementPADRFIRM->AsString;
delete cell;
numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Склад: "+DM->DocAllNAMESKLAD->AsString;
delete cell;
numRow++;numRow++;

Firma->kanRelease();


cell = prForm->SS->ActiveSheet->GetCellObject(3, numRow);
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="ПЕРЕМЕЩЕНИЕ  №"+DM->DocAllNUMDOC->AsString+" от "
                +DateToStr(DM->DocAllPOSDOC->AsDateTime);
delete cell;
numRow++; numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Склад-получатель: "+DM->DocNAMESKLAD->AsString;
delete cell;

numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Основание: "+DM->DocPRIMPER->AsString;
delete cell;
numRow++;
numRow++;

//заголовок таблицы
numCol=2;
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
cell->Text = "Кол-во";
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
cell->Text="Цена";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Сумма";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;

}
//------------------------------------------------------------------------------
void TFormaDocPer::OutputString(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=2;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = IntToStr(porNumStr);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = DM->DocTNAMENOM->AsString;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = DM->DocTKOLPERT->AsString;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = DM->DocTNAMEED->AsString;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(DM->DocTKFPERT->AsFloat,ffFixed,10,3);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

IDMSprPrice * dm_price;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
												 (void**)&dm_price);
dm_price->Init(InterfaceMainObject,InterfaceImpl);
dm_price->FindElement(glStrToInt64(DM->DocIDRTPRICE_DPER->AsString), glStrToInt64(DM->DocTIDNOMPERT->AsString));
double price=dm_price->ElementZNACH_PRICE->AsFloat*DM->DocTKFPERT->AsFloat;
double sum=price*DM->DocTKOLPERT->AsFloat;
RoznSumDoc=RoznSumDoc+sum;
dm_price->kanRelease();

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(price,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(sum,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

}


//------------------------------------------------------------------------------
void TFormaDocPer::OutputPodavalReport(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
cell = prForm->SS->ActiveSheet->GetCellObject(7, numRow);
cell->Text="Всего";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(8, numRow);
cell->Text=FloatToStrF(RoznSumDoc,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numRow++;numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="ВСЕГО: "+glCurrencyPropis(RoznSumDoc);
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
delete cell;

numRow++;numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text = "Отпустил ______________________ ";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(4, numRow);
cell->Text = "Получил  _______________________ ";
numRow++;numRow++;


}
//------------------------------------------------------------------------------
void TFormaDocPer::OpenFormSpiskaSprInfBase(void)
{
if (Prosmotr==true) return;
if (DM->DocAllIDBASE_GALLDOC->ReadOnly==true) return;
if (FormaSpiskaSprInfBase==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprInfBase.1",IID_IFormaSpiskaSprInfBase,
												 (void**)&FormaSpiskaSprInfBase);
		FormaSpiskaSprInfBase->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprInfBase->NumberProcVibor=ER_InfBase;
		FormaSpiskaSprInfBase->Vibor=true;
        FormaSpiskaSprInfBase->DM->OpenTable();
        }
}
//---------------------------------------------------------------------

void __fastcall TFormaDocPer::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("DocPer");	
}
//---------------------------------------------------------------------------



void __fastcall TFormaDocPer::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;

		OpenFormSpiskaSprNom();

}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPer::cxGrid1DBTableView1NAMEEDPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;

        OpenFormSpiskaSprEd();

}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPer::RoznTypePriceComboBoxPropertiesChange(
      TObject *Sender)
{
if(flObrabatChangeTypePrice==false) return;

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

if ( RoznTypePriceComboBox->ItemIndex!=0)
		{
		DMSprRoznTypePrice->Table->First();
		DMSprRoznTypePrice->Table->MoveBy(RoznTypePriceComboBox->ItemIndex-1);
		DM->Doc->Edit();
		DM->DocIDRTPRICE_DPER->AsInteger=DMSprRoznTypePrice->TableID_TPRICE->AsInt64;
		DM->Doc->Post();
		}
else
	{
	ShowMessage("Тип цен должен быть задан обязательно!");
	UpdateForm();
	return;
	}

////проверим есть ли строки
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
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDRTPRICE_DPER->AsString),
											 glStrToInt64(DM->DocTIDNOMPERT->AsString));
						DM->DocTPRICEPERT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKFPERT->AsFloat;
						DM->DocT->Post();
						DM->DocT->Next();
						}
				DMSprPrice->kanRelease();
				}
		}


}
//---------------------------------------------------------------------------



void __fastcall TFormaDocPer::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprFirm();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPer::NameInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprInfBase();	
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocPer::NameSkladPolcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprSkladPol();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPer::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprSklad();
}
//---------------------------------------------------------------------------






void __fastcall TFormaDocPer::ActionAddRecordExecute(TObject *Sender)
{
if (Prosmotr==true) return;
ActionOperation=aoAddNewString;
OpenFormSpiskaSprNom();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPer::ActionDeleteRecordExecute(TObject *Sender)
{
if (Prosmotr==true) return;
DM->DeleteStringDoc();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPer::NumDoccxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPer::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocPer::PrimcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------
void TFormaDocPer::CreateDocNaOsnPrihNakl(__int64 id_doc_osn)
{
IDMDocPrihNakl *pn;
InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPrihNakl.1",IID_IDMDocPrihNakl,
												 (void**)&pn);
pn->Init(InterfaceMainObject,InterfaceImpl);
pn->OpenDoc(id_doc_osn);

DM->NewDoc();

DM->DocAll->Edit();
DM->DocAllIDFIRMDOC->AsString=pn->DocAllIDFIRMDOC->AsString;
DM->DocAllNAMEFIRM->AsString=pn->DocAllNAMEFIRM->AsString;
DM->DocAllIDSKLDOC->AsString=pn->DocAllIDSKLDOC->AsString;
DM->DocAllNAMESKLAD->AsString=pn->DocAllNAMESKLAD->AsString;
DM->DocAll->Post();

DM->Doc->Edit();
if (pn->SkladRozn==true)
	{
	DM->DocIDRTPRICE_DPER->AsString=pn->DocIDRTPRICE_DPRN->AsString;
	}
DM->DocPRIMPER->AsString="На основании Приходной накладной №"+
                            pn->DocAllNUMDOC->AsString+" от "+
							pn->DocAllPOSDOC->AsString;
DM->Doc->Post();

pn->DocT->First();
while (!pn->DocT->Eof)
	{
	DM->DocT->Insert();
	DM->DocTIDNOMPERT->AsString=pn->DocTIDNOMPRNT->AsString;
	DM->DocTNAMENOM->AsString=pn->DocTNAMENOM->AsString;
	DM->DocTIDEDPERT->AsString=pn->DocTIDEDPRNT->AsString;
	DM->DocTNAMEED->AsString=pn->DocTNAMEED->AsString;
	DM->DocTKFPERT->AsFloat=pn->DocTKFPRNT->AsFloat;
	DM->DocTKOLPERT->AsFloat=pn->DocTKOLPRNT->AsFloat;
	if (pn->SkladRozn==true)
		{
		DM->DocTPRICEPERT->AsFloat=pn->DocTRPRICE_DPRNT->AsFloat;
		}
	
	DM->DocT->Post();
	pn->DocT->Next();
	}

	
pn->kanRelease();
UpdateForm();
Show();
}
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaDocPer::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaDocPer::RunExternalModule(__int64 id_module, int type_module)
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
void __fastcall TFormaDocPer::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPer::ActionOKExecute(TObject *Sender)
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

void __fastcall TFormaDocPer::ActionSaveExecute(TObject *Sender)
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

void __fastcall TFormaDocPer::ActionDvRegExecute(TObject *Sender)
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

void __fastcall TFormaDocPer::ActionPrintExecute(TObject *Sender)
{
OpenPrintForm();
}
//---------------------------------------------------------------------------
void TFormaDocPer::OpenFormSpiskaSprProject(void)
{
if (Prosmotr==true) return;
if (SpisokProject==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprProject.1",IID_IFormaSpiskaSprProject,
													(void**)&SpisokProject);
		SpisokProject->Init(InterfaceMainObject,InterfaceImpl);
		SpisokProject->NumberProcVibor=ER_Project;
		SpisokProject->Vibor=true;
		SpisokProject->UpdateForm();

		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocPer::EndViborProject(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDPROJECT_GALLDOC->AsString=SpisokProject->DM->TableID_SPROJECT->AsString;
	DM->DocAllNAME_SPROJECT->AsString=SpisokProject->DM->TableNAME_SPROJECT->AsString;
	DM->DocAll->Post();




}
//----------------------------------------------------------------------------
void TFormaDocPer::OpenFormSpiskaSprBusinessOper(void)
{
if (Prosmotr==true) return;
if (SpisokBusinessOper==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprBusinessOper,IID_IFormaSpiskaSprBusinessOper,
													(void**)&SpisokBusinessOper);
		SpisokBusinessOper->Init(InterfaceMainObject,InterfaceImpl);
		SpisokBusinessOper->NumberProcVibor=ER_BusinessOper;
		SpisokBusinessOper->Vibor=true;
		SpisokBusinessOper->UpdateForm();
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocPer::EndViborBusinessOper(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDBUSINOP_GALLDOC->AsString=SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString;
	DM->DocAllNAME_SBUSINESS_OPER->AsString=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;
	DM->DocAll->Post();

}
//----------------------------------------------------------------------------
void __fastcall TFormaDocPer::NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprBusinessOper();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocAll->Edit();
		DM->DocAllIDBUSINOP_GALLDOC->Clear();
		DM->DocAll->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPer::NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprProject();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocAll->Edit();
		DM->DocAllIDPROJECT_GALLDOC->Clear();
		DM->DocAll->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPer::ToolButtonAddSebestClick(TObject *Sender)
{
UnicodeString zapros="select sum(rgostnom.sumostnom) as sebest,    \
							sum(rgostnom.kolostnom) as kolost      \
						from rgostnom                                \
						where rgostnom.idfirmostnom=:PARAM_IDFIRM    \
								and  rgostnom.idsklostnom=:PARAM_IDSKLAD \
								and rgostnom.idnomostnom=:PARAM_IDNOM";

IDMQueryRead * DMQueryRead;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&DMQueryRead);
DMQueryRead->Init(InterfaceMainObject,0);
DMQueryRead->pFIBQ->Close();
DMQueryRead->pFIBQ->SQL->Clear();
DMQueryRead->pFIBQ->SQL->Add(zapros);



DM->DocT->First();

while(!DM->DocT->Eof)
	{
	DMQueryRead->pFIBQ->Close();
	DMQueryRead->pFIBQ->ParamByName("PARAM_IDFIRM")->AsString=DM->DocAllIDFIRMDOC->AsString;
	DMQueryRead->pFIBQ->ParamByName("PARAM_IDSKLAD")->AsString=DM->DocAllIDSKLDOC->AsString;
	DMQueryRead->pFIBQ->ParamByName("PARAM_IDNOM")->AsString=DM->DocTIDNOMPERT->AsString;
	DMQueryRead->pFIBQ->ExecQuery();
	DM->DocT->Edit();
	if (DMQueryRead->pFIBQ->FieldByName("KOLOST")->AsFloat > 0.001)
		{
		DM->DocTSEB_PRICE_DPERT->AsFloat=DMQueryRead->pFIBQ->FieldByName("sebest")->AsFloat
										/DMQueryRead->pFIBQ->FieldByName("KOLOST")->AsFloat;
		}
	else
		{
		DM->DocTSEB_PRICE_DPERT->AsFloat=0;
		}
	DM->DocT->Post();
	DM->DocT->Next();
	}

DMQueryRead->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPer::ToolButtonAddNomSoSkladaClick(TObject *Sender)
{
ActionOperation=aoAddNewString;
ViborNomSoSklada();
}
//---------------------------------------------------------------------------
void TFormaDocPer::ViborNomSoSklada(void)
{
if (Prosmotr==true)
	{
	ShowMessage("Документ открыт только для просмотра!");
	return;
	}
if (SpisokNom==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&SpisokNom);
		SpisokNom->Init(InterfaceMainObject,InterfaceImpl);
		SpisokNom->Vibor=true;
		SpisokNom->DM->IdTypePrice=glStrToInt64(DM->DocIDRTPRICE_DPER->AsString);
		SpisokNom->IdNom=glStrToInt64(DM->DocTIDNOMPERT->AsString);
		SpisokNom->UpdateForm();
		SpisokNom->NumberProcVibor=ER_NomSoSklada;
		}
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocPer::EndViborNomSoSklada(void)
{



		IDMRegGoods * reg;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMRegGoods.1",IID_IDMRegGoods,
													(void**)&reg);
		reg->Init(InterfaceMainObject,InterfaceImpl);
						reg->GetOstatokPoPrice(glStrToInt64(DM->DocAllIDFIRMDOC->AsString),
									glStrToInt64(DM->DocAllIDSKLDOC->AsString),
									glStrToInt64(SpisokNom->DM->ElementIDNOM->AsString));
						reg->TableOst->First();
						while(!reg->TableOst->Eof)
							{
							DM->DocT->Append();
							DM->DocT->Edit();
							DM->DocTIDNOMPERT->AsString=SpisokNom->DM->ElementIDNOM->AsString;
							DM->DocTNAMENOM->AsString=SpisokNom->DM->ElementNAMENOM->AsString;
							DM->DocTTNOM->AsInteger=SpisokNom->DM->ElementTNOM->AsInteger;

							DM->DocTIDEDPERT->AsString=SpisokNom->DM->ElementIDBASEDNOM->AsString;
							DM->DocTNAMEED->AsString=SpisokNom->DM->BasEdNAMEED->AsString;

							DM->DocTKFPERT->AsFloat=SpisokNom->DM->OsnEdKFED->AsFloat;
							DM->DocTKOLPERT->AsFloat=reg->TableOst->FieldByName("KOLOST")->AsFloat;
							DM->DocTPRICEPERT->AsFloat=reg->TableOst->FieldByName("RPRICE_RGGOODS")->AsFloat;
							DM->DocT->Post();
							reg->TableOst->Next();
							}
						reg->kanRelease();

		SpisokNom=0;
		cxGrid1->SetFocus();
		cxGrid1DBTableView1KOLPERT->Selected=true;

}
//-----------------------------------------------------------------------------
void __fastcall TFormaDocPer::cxGrid1DBTableView1NAC_SUM_EDPropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
double procent=(double)VarAsType(DisplayValue,varDouble);
DM->DocT->Edit();
DM->DocTPRICEPERT->AsFloat=DM->DocTSEB_PRICE_DPERT->AsFloat*((100+procent)/100);
DM->DocT->Post();
}
//---------------------------------------------------------------------------

