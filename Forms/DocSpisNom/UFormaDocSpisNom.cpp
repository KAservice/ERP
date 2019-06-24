//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop
//-------------------------------------------------------------------------
#include "UFormaDocSpisNom.h"
#include "IDMSprFirm.h"
#include "IObjectBarCode.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IDMQueryRead.h"
#include "IAsyncExternalEvent.h"
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
__fastcall TFormaDocSpisNom::TFormaDocSpisNom(TComponent* Owner)
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
bool TFormaDocSpisNom::Init(void)
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

EditRekvisit=NO;
InterfaceGlobalCom->kanCreateObject("Oberon.DMDocSpisNom.1",IID_IDMDocSpisNom, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи


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

PrimcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;

ActionOperation=aoNO;

flObrabatChangeTypePrice=false;

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice, (void**)&DMSprTypeRPrice);
DMSprTypeRPrice->Init(InterfaceMainObject,InterfaceImpl);
DMSprTypeRPrice->OpenTable();
TypeRPriceComboBox->Properties->Items->Clear();
TypeRPriceComboBox->Properties->Items->Add("Не задан");
DMSprTypeRPrice->Table->First();
while (!DMSprTypeRPrice->Table->Eof)
		{
		TypeRPriceComboBox->Properties->Items->Add(DMSprTypeRPrice->TableNAME_TPRICE->AsString);
        DMSprTypeRPrice->Table->Next();
		}

//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaDocSpisNomImpl),false);
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
//--------------------------------------------------------------------------
void TFormaDocSpisNom::UpdateForm(void)
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

if (glStrToInt64(DM->DocAllIDDOCOSNDOC->AsString) > 0)
	{
	DocOsnLabel->Caption="Документ основание: "+glGetNameDoc(DM->DocOsnTDOC->AsString)
				+" №"+DM->DocOsnNUMDOC->AsString+" от "+DM->DocOsnPOSDOC->AsString;
	}
else
	{
    DocOsnLabel->Caption="";
	}

if (DM->SkladRozn==true)
	{
	cxGrid1DBTableView1RPRICE_DSPNT->Visible=true;
	cxGrid1DBTableView1RSUM_DSPNT->Visible=true;
	TypeRPriceLabel->Visible=true;
	TypeRPriceComboBox->Visible=true;
	}
else
	{
	cxGrid1DBTableView1RPRICE_DSPNT->Visible=false;
	cxGrid1DBTableView1RSUM_DSPNT->Visible=false;
	TypeRPriceLabel->Visible=false;
	TypeRPriceComboBox->Visible=false;
	}

flObrabatChangeTypePrice=false;
TypeRPriceComboBox->ItemIndex=DMSprTypeRPrice->GetIndexTypePricePoId(DM->DocIDRTPRICE_DSPN->AsInt64);
flObrabatChangeTypePrice=true;

}
//---------------------------------------------------------------------------
int TFormaDocSpisNom::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocSpisNom::FormClose(TObject *Sender,
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

DMSprTypeRPrice->kanRelease();
DMTableExtPrintForm->kanRelease();
DM->kanRelease();
Action=caFree;
}
//---------------------------------------------------------------------------




void TFormaDocSpisNom::OpenFormSpiskaSprEd(void)
{
if (Prosmotr==true) return;
if (SpisokEd==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&SpisokEd);
		SpisokEd->Init(InterfaceMainObject,InterfaceImpl);
		SpisokEd->Vibor=true;
		SpisokEd->NumberProcVibor=ViborEdinica;
		SpisokEd->DM->OpenTable(glStrToInt64(DM->DocTIDNOMSPNT->AsString));
//        SpisokEd->LabelNom->Caption="Единицы номенклатуры: "+DM->DocTNAMENOM->AsString;
//		SpisokEd->HintLabel->Caption="Выберите единицу номенклатуры для документа АКТ списания№"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
        }
}
//-----------------------------------------------------------------------------
void TFormaDocSpisNom::OpenFormSpiskaSprNom(void)
{
if (SpisokNom==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&SpisokNom);
		SpisokNom->Init(InterfaceMainObject,InterfaceImpl);
		SpisokNom->Vibor=true;
		SpisokNom->NumberProcVibor=ViborTovar;
//        SpisokNom->HintLabel->Caption="Выберите номенклатуру для документа Акт списания №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		SpisokNom->IdNom=glStrToInt64(DM->DocTIDNOMSPNT->AsString);
        SpisokNom->UpdateForm();
        }
}

//---------------------------------------------------------------------------
int TFormaDocSpisNom::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ViborTovar)
        {

		if (type_event==1)
                {

				if (ActionOperation==aoAddNewString)
                        {
                        DM->AddDocNewString();
                        }
                DM->DocT->Edit();
				DM->DocTIDNOMSPNT->AsString=SpisokNom->DM->ElementIDNOM->AsString;
                DM->DocTNAMENOM->AsString=SpisokNom->DM->ElementNAMENOM->AsString;
                DM->DocTTNOM->AsInteger=SpisokNom->DM->ElementTNOM->AsInteger;
                DM->DocTKOLSPNT->AsFloat=1;
				DM->DocTIDEDSPNT->AsString=SpisokNom->DM->ElementIDBASEDNOM->AsString;
                DM->DocTNAMEED->AsString=SpisokNom->DM->BasEdNAMEED->AsString;
				DM->DocTKFSPNT->AsFloat=SpisokNom->DM->BasEdKFED->AsFloat;

				if (DM->SkladRozn==true)
					{
					IDMSprPrice * DMSprPrice;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
					DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDRTPRICE_DSPN->AsString),
											 glStrToInt64(DM->DocTIDNOMSPNT->AsString));
						DM->DocTRPRICE_DSPNT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKFSPNT->AsFloat;
					DMSprPrice->kanRelease();
					}
				else
					{
					DM->DocTRPRICE_DSPNT->AsFloat=0;
					}

                DM->DocT->Post();
                }
		SpisokNom=0;
		cxGrid1->SetFocus();
		cxGrid1DBTableView1KOLSPNT->Selected=true;
        }

if (number_procedure_end==ViborEdinica)
        {
		if (type_event==1)
                {
                DM->DocT->Edit();
				DM->DocTIDEDSPNT->AsString=SpisokEd->DM->ElementIDED->AsString;
				DM->DocTNAMEED->AsString=SpisokEd->DM->ElementNAMEED->AsString;
                DM->DocTKFSPNT->AsFloat=SpisokEd->DM->ElementKFED->AsFloat;
                DM->DocT->Post();
                }
		SpisokEd=0;
		cxGrid1->SetFocus();
		cxGrid1DBTableView1PRICESPNT->Selected=true;
        }

if (number_procedure_end==ViborFirm)
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

if (number_procedure_end==ViborSklad)
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


ActionOperation=aoNO;
EditRekvisit=NO;
return -1;
}

//---------------------------------------------------------------------------







//---------------------------------------------------------------------------
void TFormaDocSpisNom::OpenFormSpiskaSprFirm(void)
{
if (SpisokFirm==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&SpisokFirm);
		SpisokFirm->Init(InterfaceMainObject,InterfaceImpl);
        SpisokFirm->Vibor=true;
		SpisokFirm->NumberProcVibor=ViborFirm;
        }

}
//---------------------------------------------------------------------------
void TFormaDocSpisNom::OpenFormSpiskaSprSklad(void)
{
if (SpisokSklad==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&SpisokSklad);
		SpisokSklad->Init(InterfaceMainObject,InterfaceImpl);
		SpisokSklad->Vibor=true;
		SpisokSklad->NumberProcVibor=ViborSklad;
        }

}
//--------------------------------------------------------------------------




//---------------------------------------------------------------------------
void TFormaDocSpisNom::OpenPrintForm(void)
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
void TFormaDocSpisNom::OutputZagolovokReport(TSheetEditor *prForm)
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
TcxSSCellObject *cell;
numRow=2;
numCol=2;

IDMSprFirm *Firma;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
													(void**)&Firma);
Firma->Init(InterfaceMainObject,InterfaceImpl);
Firma->OpenElement(glStrToInt64(DM->DocAllIDFIRMDOC->AsString));
cell = prForm->SS->ActiveSheet->GetCellObject(2, 1);
cell->Text=Firma->ElementFNAMEFIRM->AsString
        +" ИНН "+Firma->ElementINNFIRM->AsString;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Адрес: "+Firma->ElementPADRFIRM->AsString;
delete cell;
numRow++;

Firma->kanRelease();

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Склад: "+DM->DocAllNAMESKLAD->AsString;
delete cell;
numRow++; numRow++;


cell = prForm->SS->ActiveSheet->GetCellObject(3, numRow);
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="АКТ списания №"+DM->DocAllNUMDOC->AsString+" от "
                +DateToStr(DM->DocAllPOSDOC->AsDateTime);
delete cell;
numRow++; numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Основание: "+DM->DocPRIMSPN->AsString;
delete cell;
numRow++;
numRow++;

//заголовок таблицы
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
if (DM->SkladRozn==true)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text="Розн. цена";
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
	cell->Text="Розн. сумма";
	cell->Style->HorzTextAlign = haCENTER;
	cell->Style->Font->Size = 10;
	cell->Style->Font->Style = TFontStyles() << fsBold;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	numCol++;
	}
numRow++;
RoznSummaForPrint=0;
}
//------------------------------------------------------------------------------
void TFormaDocSpisNom::OutputString(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=2;

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
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTKOLSPNT->AsString;
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
cell->Text=FloatToStrF(DM->DocTKFSPNT->AsFloat,ffFixed,10,3);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTPRICESPNT->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTSUMSPNT->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

if (DM->SkladRozn==true)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text=FloatToStrF(DM->DocTRPRICE_DSPNT->AsFloat,ffFixed,10,2);
	cell->Style->HorzTextAlign = haRIGHT;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	numCol++;

	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text=FloatToStrF(DM->DocTRSUM_DSPNT->AsFloat,ffFixed,10,2);
	cell->Style->HorzTextAlign = haRIGHT;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	numCol++;
	RoznSummaForPrint=RoznSummaForPrint+ DM->DocTRSUM_DSPNT->AsFloat;
	}
}


//------------------------------------------------------------------------------
void TFormaDocSpisNom::OutputPodavalReport(TSheetEditor *prForm)
{
//numRow++;
TcxSSCellObject *cell;
cell = prForm->SS->ActiveSheet->GetCellObject(7, numRow);
cell->Text="Всего";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 10;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(8, numRow);
cell->Text=FloatToStrF(DM->DocAllSUMDOC->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 10;
delete cell;

if (DM->SkladRozn==true)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(10, numRow);
	cell->Text=FloatToStrF(RoznSummaForPrint,ffFixed,10,2);
	cell->Style->HorzTextAlign = haRIGHT;
	cell->Style->Font->Size = 10;
	delete cell;
	}



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
void  TFormaDocSpisNom::PrintPoGrp(void)
{
TSheetEditor  *prForm=new TSheetEditor(Application);
if (!prForm) return;

numRow=1;
numCol=1;
porNumStr=1;
int porNumStrGrp=1;
TcxSSCellObject *cell;

//шапка
prForm->SS->BeginUpdate();
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


numRow=2;
numCol=1;

IDMSprFirm *Firma;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
													(void**)&Firma);
Firma->Init(InterfaceMainObject,InterfaceImpl);
Firma->OpenElement(DM->DocAllIDFIRMDOC->AsInt64);
cell = prForm->SS->ActiveSheet->GetCellObject(2, 1);
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
cell->Text="Акт списания №"+DM->DocAllNUMDOC->AsString+" от "
                +DateToStr(DM->DocAllPOSDOC->AsDateTime);
delete cell;
numRow++; numRow++;


cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Основание: "+DM->DocPRIMSPN->AsString;
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

//группы

DM->Grp->Active=false;
DM->Grp->ParamByName("PARAM_IDDOC")->AsInt64=DM->DocAllIDDOC->AsInt64;
DM->Grp->Active=true;

DM->Grp->First();
while(!DM->Grp->Eof)
        {
        numCol=2;
        //порядковый номер строки
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Text=IntToStr(porNumStrGrp);
        cell->Style->Brush->BackgroundColor=34;
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
        cell->Text=DM->GrpNAMEGN->AsString;
        cell->Style->Brush->BackgroundColor=34;
        cell->Style->HorzTextAlign = haCENTER;
        cell->Style->Font->Size = 10;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;
        //количество
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Text="";
        cell->Style->Brush->BackgroundColor=34;
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
        cell->Text="";
        cell->Style->Brush->BackgroundColor=34;
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
        cell->Text="";
        cell->Style->Brush->BackgroundColor=34;
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
        cell->Text="";
        cell->Style->Brush->BackgroundColor=34;
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
        cell->Text=FloatToStrF(DM->GrpSUMMA->AsFloat,ffFixed,10,2);
        cell->Style->Brush->BackgroundColor=34;
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 10;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;
        numRow++;
        // получим расшифровку группы
		if ( glStrToInt64(DM->GrpIDGN->AsString)==0)
                {
                String ZaprosEl="select  NAMENOM, NAMEED, SUM(SUMSPNT)  AS SUMMA, SUM(KFSPNT*KOLSPNT)  AS SUMKOL";
                ZaprosEl=ZaprosEl+" from  DSPNT ";
                ZaprosEl=ZaprosEl+" left outer join SNOM on IDNOMSPNT=IDNOM";
                ZaprosEl=ZaprosEl+" left outer join SGRPNOM on IDGRPNOM=IDGN";
                ZaprosEl=ZaprosEl+" left outer join SED on IDBASEDNOM=IDED";
                ZaprosEl=ZaprosEl+" where (IDDOCSPNT=:PARAM_IDDOC)";
                ZaprosEl=ZaprosEl+" and  (IDGN IS NULL) ";
                ZaprosEl=ZaprosEl+" group by NAMENOM, NAMEED ";
				DM->El->SelectSQL->Clear();
                DM->El->SelectSQL->Add(ZaprosEl);
				DM->El->ParamByName("PARAM_IDDOC")->AsString=DM->DocAllIDDOC->AsString;
                }
        else
                {
                DM->El->Active=false;
				DM->El->ParamByName("PARAM_IDDOC")->AsString=DM->DocAllIDDOC->AsString;
				DM->El->ParamByName("PARAM_IDGN")->AsString=DM->GrpIDGN->AsString;
                }

        DM->El->Active=true;
        porNumStr=1;
        DM->El->First();
        while(!DM->El->Eof)
                {
                numCol=2;
                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
                cell->Text=IntToStr(porNumStr);
                cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numCol++;
                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
                cell->Text=DM->ElNAMENOM->AsString;
                cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numCol++;  
                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
                cell->Text=DM->ElSUMKOL->AsString;
                cell->Style->HorzTextAlign = haRIGHT;
                cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numCol++;
                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
                cell->Text=DM->ElNAMEED->AsString;
                cell->Style->HorzTextAlign = haCENTER;
                cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numCol++;
                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
                cell->Text="1";
                cell->Style->HorzTextAlign = haCENTER;
                cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numCol++;
				cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
				if (DM->ElSUMKOL->AsFloat!=0)
					{
					cell->Text=FloatToStrF(DM->ElSUMMA->AsFloat/
								DM->ElSUMKOL->AsFloat,ffFixed,10,2);
					}
                cell->Style->HorzTextAlign = haRIGHT;
                cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numCol++;
                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
                cell->Text=FloatToStrF(DM->ElSUMMA->AsFloat,ffFixed,10,2);
                cell->Style->HorzTextAlign = haRIGHT;
                cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                porNumStr++;
                numRow++;
                DM->El->Next();
                }

        porNumStrGrp++;
        DM->Grp->Next();
        }
        
cell = prForm->SS->ActiveSheet->GetCellObject(7, numRow);
//cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Text="Всего";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(8, numRow);
//cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Text=FloatToStrF(DM->DocAllSUMDOC->AsFloat,ffFixed,10,2);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numRow++;numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
//cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
//cell->Style->HorzTextAlign = haRIGHT;
cell->Text="ВСЕГО: "+glCurrencyPropis(DM->DocAllSUMDOC->AsFloat);
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
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

DM->Grp->Active=false;
DM->El->Active=false;
prForm->SS->EndUpdate();
prForm->Show();
}
//---------------------------------------------------------------------------
void TFormaDocSpisNom::OpenFormSpiskaSprInfBase(void)
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

void __fastcall TFormaDocSpisNom::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("DocSpisNom");
}
//---------------------------------------------------------------------------




void __fastcall TFormaDocSpisNom::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;

		OpenFormSpiskaSprNom();
		EditRekvisit=ViborTovar;

}
//---------------------------------------------------------------------------

void __fastcall TFormaDocSpisNom::cxGrid1DBTableView1NAMEEDPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;

		OpenFormSpiskaSprEd();
		EditRekvisit=ViborEdinica;

}
//---------------------------------------------------------------------------

void __fastcall TFormaDocSpisNom::cxButtonPoGrpClick(TObject *Sender)
{
PrintPoGrp();	
}
//---------------------------------------------------------------------------






void __fastcall TFormaDocSpisNom::TypeRPriceComboBoxPropertiesChange(
      TObject *Sender)
{

if(flObrabatChangeTypePrice==false) return;
FindNextControl(ActiveControl,true,true,false)->SetFocus();


 if (Prosmotr==true)
		{
		UpdateForm();
		 return;
		}

if ( TypeRPriceComboBox->ItemIndex!=0)
		{
		DMSprTypeRPrice->Table->First();
		DMSprTypeRPrice->Table->MoveBy(TypeRPriceComboBox->ItemIndex-1);
		DM->Doc->Edit();
		DM->DocIDRTPRICE_DSPN->AsString=DMSprTypeRPrice->TableID_TPRICE->AsString;
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
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDRTPRICE_DSPN->AsString),
											 glStrToInt64(DM->DocTIDNOMSPNT->AsString));
						DM->DocTRPRICE_DSPNT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKFSPNT->AsFloat;
						DM->DocT->Post();
						DM->DocT->Next();
						}
				DMSprPrice->kanRelease();
				}
		}
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocSpisNom::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprSklad();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocSpisNom::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprFirm(); 	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocSpisNom::NameInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprInfBase();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocSpisNom::ActionAddStringExecute(TObject *Sender)
{
if (Prosmotr==true) return;
ActionOperation=aoAddNewString;
OpenFormSpiskaSprNom();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocSpisNom::ActionDeleteStringExecute(TObject *Sender)
{
if (Prosmotr==true) return;
DM->DeleteStringDoc();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocSpisNom::NumDoccxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocSpisNom::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocSpisNom::PrimcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------



void __fastcall TFormaDocSpisNom::FormActivate(TObject *Sender)
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

void __fastcall TFormaDocSpisNom::FormDeactivate(TObject *Sender)
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
void __fastcall TFormaDocSpisNom::ReadShtrihCodEvent(int number, UnicodeString sh)
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
ob_bar->IdTypePrice=glStrToInt64(DM->DocIDRTPRICE_DSPN->AsString);
ob_bar->ObrabotatShtrihCod(sh);

if (ob_bar->OutReady==true)
	{
	DM->AddDocNewString();
	DM->DocT->Edit();

	DM->DocTIDNOMSPNT->AsString = dm_nom->ElementIDNOM->AsString;
	//DM->DocTCODENOM->AsInteger=dm_nom->ElementCODENOM->AsInteger;
	DM->DocTNAMENOM->AsString=dm_nom->ElementNAMENOM->AsString;
	DM->DocTTNOM->AsInteger=dm_nom->ElementTNOM->AsInteger;

	DM->DocTIDEDSPNT->AsString = dm_ed->ElementIDED->AsString;
	DM->DocTNAMEED->AsString = dm_ed->ElementNAMEED->AsString;
	DM->DocTKFSPNT->AsFloat = dm_ed->ElementKFED->AsFloat;

	DM->DocTKOLSPNT->AsFloat=ob_bar->Kol;

	//получим цену
	IDMSprPrice * dm_price;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
		dm_price->Init(InterfaceMainObject,InterfaceImpl);
		DM->DocTRPRICE_DSPNT->AsFloat=dm_price->GetValuePrice(
						glStrToInt64(DM->DocIDRTPRICE_DSPN->AsString),                     //тип цен
						glStrToInt64(DM->DocTIDNOMSPNT->AsString),  //номенклатура
						glStrToInt64(DM->DocTIDEDSPNT->AsString),    // единица
						DM->DocTKFSPNT->AsFloat,                   // коэффициент единицы
						glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString)); //базовая единица
	dm_price->kanRelease();

	DM->DocT->Post();

	VibTovarId=glStrToInt64(dm_nom->ElementIDNOM->AsString);
	VibTovarIdGrp=glStrToInt64(dm_nom->ElementIDGRPNOM->AsString);

	cxGrid1->Focused();
	cxGrid1->SetFocus();
	cxGrid1DBTableView1KOLSPNT->Focused=true;
	cxGrid1DBTableView1KOLSPNT->Selected=true;
	}
ob_bar->kanRelease();
dm_nom->kanRelease();
dm_ed->kanRelease();
}
//-----------------------------------------------------------------------------
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaDocSpisNom::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaDocSpisNom::RunExternalModule(__int64 id_module, int type_module)
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
void __fastcall TFormaDocSpisNom::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocSpisNom::ActionOKExecute(TObject *Sender)
{
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

void __fastcall TFormaDocSpisNom::ActionSaveExecute(TObject *Sender)
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

void __fastcall TFormaDocSpisNom::ActionDvRegExecute(TObject *Sender)
{
if (Prosmotr==true) return;
__int64 id_doc=DM->DocAllIDDOC->AsInt64;
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

void __fastcall TFormaDocSpisNom::ActionPrintExecute(TObject *Sender)
{
OpenPrintForm();
}
//---------------------------------------------------------------------------
void TFormaDocSpisNom::OpenFormSpiskaSprProject(void)
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
void __fastcall TFormaDocSpisNom::EndViborProject(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDPROJECT_GALLDOC->AsString=SpisokProject->DM->TableID_SPROJECT->AsString;
	DM->DocAllNAME_SPROJECT->AsString=SpisokProject->DM->TableNAME_SPROJECT->AsString;
	DM->DocAll->Post();




}
//----------------------------------------------------------------------------
void TFormaDocSpisNom::OpenFormSpiskaSprBusinessOper(void)
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
void __fastcall TFormaDocSpisNom::EndViborBusinessOper(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDBUSINOP_GALLDOC->AsString=SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString;
	DM->DocAllNAME_SBUSINESS_OPER->AsString=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;
	DM->DocAll->Post();

}
//----------------------------------------------------------------------------


void __fastcall TFormaDocSpisNom::NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
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

void __fastcall TFormaDocSpisNom::NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
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

void __fastcall TFormaDocSpisNom::ToolButtonAddOstSoSkladaClick(TObject *Sender)
{
UnicodeString zapros="select IDNOM, CODENOM, NAMENOM, IDED, NAMEED, KFED,rggoods.rprice_rggoods, sum(rggoods.kol_rggoods) as KOL    \
						from rggoods                                                                  \
						left outer join SNOM on IDNOM=rggoods.idnom_rggoods                           \
						left outer join sed on sed.ided=snom.idbasednom                               \
						where rggoods.idsklad_rggoods=:PARAM_IDSKLAD                                  \
										and rggoods.idfirm_rggoods=:PARAM_IDFIRM                              \
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
DMQueryRead->pFIBQ->ExecQuery();

while(!DMQueryRead->pFIBQ->Eof)
	{
	DM->AddDocNewString();
	DM->DocT->Edit();

	DM->DocTIDNOMSPNT->AsString=DMQueryRead->pFIBQ->FieldByName("IDNOM")->AsString;
	//DM->DocTCODENOM->AsInteger=DMQueryRead->pFIBQ->FieldByName("CODENOM")->AsInteger;
	DM->DocTNAMENOM->AsString=DMQueryRead->pFIBQ->FieldByName("NAMENOM")->AsString;

	DM->DocTIDEDSPNT->AsString=DMQueryRead->pFIBQ->FieldByName("IDED")->AsString;
	DM->DocTNAMEED->AsString=DMQueryRead->pFIBQ->FieldByName("NAMEED")->AsString;
	DM->DocTKFSPNT->AsFloat=DMQueryRead->pFIBQ->FieldByName("KFED")->AsFloat;
	DM->DocTKOLSPNT->AsFloat=DMQueryRead->pFIBQ->FieldByName("KOL")->AsFloat;
	DM->DocTPRICESPNT->AsFloat=DMQueryRead->pFIBQ->FieldByName("rprice_rggoods")->AsFloat;

    DM->DocT->Post();
	DMQueryRead->pFIBQ->Next();
	}


DMQueryRead->kanRelease();
}
//---------------------------------------------------------------------------

