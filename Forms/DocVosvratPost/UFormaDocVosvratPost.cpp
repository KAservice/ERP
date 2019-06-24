//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop


#include "UFormaDocVosvratPost.h"
#include "IDMSprPrice.h"
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
#pragma link "cxContainer"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxDBEdit"
#pragma link "cxCalendar"
#pragma link "cxLabel"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaDocVosvratPost::TFormaDocVosvratPost(TComponent* Owner)
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
bool TFormaDocVosvratPost::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.DMDocVosvratPost.1",IID_IDMDocVosvratPost,
							(void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);



Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи

DBTextFNameUser->DataSource=DM->DataSourceDocAll;
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceDocT;

NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameSkladcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NumDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameProjectcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameBusinessOpercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PrefiksNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;

PrimcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
NumDocPostcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
PosDocPostcxDBDateEdit->DataBinding->DataSource=DM->DataSourceDoc;


NameBSchetcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
NameGrPolcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
NameRaschScetKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
NameRaschSchetGrpolcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;



DocOsncxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
ActionOperation=aoNO;


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

//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaDocVosvratPostImpl),false);
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
int TFormaDocVosvratPost::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void TFormaDocVosvratPost::UpdateForm(void)
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
flObrabatChangeRTypePrice=false;
TypePriceComboBox->ItemIndex=DMSprTypePrice->GetIndexTypePricePoId(glStrToInt64(DM->DocIDTPRICE_DVPO->AsString));
TypeRPriceComboBox->ItemIndex=DMSprRTypePrice->GetIndexTypePricePoId(glStrToInt64(DM->DocIDRTPRICE_DVPO->AsString));
flObrabatChangeTypePrice=true;
flObrabatChangeRTypePrice=true;


if (DM->SkladRozn==true)
	{
	cxGrid1DBTableView1RPRICE_DVPOT->Visible=true;
	cxGrid1DBTableView1RSUM_DVPOT->Visible=true;
	TypeRPriceComboBox->Visible=true;
	RTPriceLabel->Visible=true;
	}
else
	{
	cxGrid1DBTableView1RPRICE_DVPOT->Visible=false;
	cxGrid1DBTableView1RSUM_DVPOT->Visible=false;
	TypeRPriceComboBox->Visible=false;
	RTPriceLabel->Visible=false;
	}

}
//---------------------------------------------------------------------------
void __fastcall TFormaDocVosvratPost::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokFirm)SpisokFirm->kanRelease();
if(SpisokSklad)SpisokSklad->kanRelease();
if(SpisokKlient)SpisokKlient->kanRelease();
if(SpisokNom)SpisokNom->kanRelease();
if(SpisokEd)SpisokEd->kanRelease();
if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
if(FormaGurAllDoc)FormaGurAllDoc->kanRelease();
if(SpisokBusinessOper)SpisokBusinessOper->kanRelease();
if(SpisokProject)SpisokProject->kanRelease();
if(FormaSpiskaSprRaschSchet)FormaSpiskaSprRaschSchet->kanRelease();
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

DMSprRTypePrice->kanRelease();
DMSprTypePrice->kanRelease();
DMTableExtPrintForm->kanRelease();
DM->kanRelease();
Action=caFree;
}
//---------------------------------------------------------------------------




void TFormaDocVosvratPost::OpenFormSpiskaSprEd(void)
{
if (Prosmotr==true) return;
if (SpisokEd==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&SpisokEd);
		SpisokEd->Init(InterfaceMainObject,InterfaceImpl);
		SpisokEd->Vibor=true;
		SpisokEd->NumberProcVibor=ViborEdinica;
		SpisokEd->DM->OpenTable(glStrToInt64(DM->DocTIDNOMVPOT->AsString));
		SpisokEd->Vibor=true;
		}
}
//-----------------------------------------------------------------------------
void TFormaDocVosvratPost::OpenFormSpiskaSprNom(void)
{
if (Prosmotr==true) return;
if (SpisokNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&SpisokNom);
		SpisokNom->Init(InterfaceMainObject,InterfaceImpl);
		SpisokNom->NumberProcVibor=ViborTovar;
		SpisokNom->IdNom=glStrToInt64(DM->DocTIDNOMVPOT->AsString);
		SpisokNom->DM->IdTypePrice=glStrToInt64(DM->DocIDTPRICE_DVPO->AsString);
		SpisokNom->UpdateForm();
		SpisokNom->Vibor=true;
        }

}

//---------------------------------------------------------------------------
int TFormaDocVosvratPost::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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
				DM->DocTIDNOMVPOT->AsString=SpisokNom->DM->ElementIDNOM->AsString;
                DM->DocTNAMENOM->AsString=SpisokNom->DM->ElementNAMENOM->AsString;
                DM->DocTTNOM->AsInteger=SpisokNom->DM->ElementTNOM->AsInteger;
                DM->DocTKOLVPOT->AsFloat=1;
				DM->DocTIDEDVPOT->AsString=SpisokNom->DM->ElementIDBASEDNOM->AsString;
                DM->DocTNAMEED->AsString=SpisokNom->DM->BasEdNAMEED->AsString;
                DM->DocTKFVPOT->AsFloat=SpisokNom->DM->BasEdKFED->AsFloat;
				DM->DocTPRICEVPOT->AsFloat=SpisokNom->DM->ElementZNACH_PRICE->AsFloat*
														DM->DocTKFVPOT->AsFloat;


				if (DM->SkladRozn==true)
					{
				IDMSprPrice * DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDRTPRICE_DVPO->AsString),
											 glStrToInt64(DM->DocTIDNOMVPOT->AsString));
						DM->DocTRPRICE_DVPOT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKFVPOT->AsFloat;
				DMSprPrice->kanRelease();
					}
				else
					{
					DM->DocTRPRICE_DVPOT->AsFloat=0;
					}
									
                DM->DocT->Post();
                }
		SpisokNom=0;
		cxGrid1->SetFocus();
		cxGrid1DBTableView1KOLVPOT->Selected=true;
        }

if (number_procedure_end==ViborEdinica)
		{
		if (type_event==1)
				{
				DM->DocT->Edit();
				DM->DocTIDEDVPOT->AsString=SpisokEd->DM->ElementIDED->AsString;
				DM->DocTNAMEED->AsString=SpisokEd->DM->ElementNAMEED->AsString;
				DM->DocTKFVPOT->AsFloat=SpisokEd->DM->ElementKFED->AsFloat;
				DM->DocT->Post();
				}
		SpisokEd=0;
		cxGrid1->SetFocus();
		cxGrid1DBTableView1PRICEVPOT->Selected=true;
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
                }
		SpisokSklad=0;
		UpdateForm();
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
        }

if (number_procedure_end==ViborKlient)
        {
		if (type_event==1)
                {
				DM->DocAll->Edit();
				DM->DocAllIDKLDOC->AsString=SpisokKlient->DM->ElementIDKLIENT->AsString;
                DM->DocAllNAMEKLIENT->AsString=SpisokKlient->DM->ElementNAMEKLIENT->AsString;
                DM->DocAll->Post();
                }
		SpisokKlient=0;
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

if (number_procedure_end==ER_DocOsn)
		{
		if (type_event==1)
				{
				EndViborDocOsn();
				}
		FormaGurAllDoc=0;
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


if (number_procedure_end==ER_GrPol)//EditRekvisit==ViborGrPol)
        {
		if (type_event==1)
                {
                DM->Doc->Edit();
				DM->DocIDGRPOL_DVPO->AsString=SpisokKlient->DM->ElementIDKLIENT->AsString;
                DM->DocNAMEKLIENT->AsString=SpisokKlient->DM->ElementNAMEKLIENT->AsString;
                DM->Doc->Post();
                }
		SpisokKlient=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}



 if (number_procedure_end==ER_BankSchet)//EditRekvisit==ViborBankSchet)
        {
        if (type_event==1)
                {
                DM->Doc->Edit();
				DM->DocIDBSCHET_DVPO->AsString=FormSpiskaSprBSchet->DM->TableIDBSCHET->AsString;
                DM->DocNAMEBSCHET->AsString=FormSpiskaSprBSchet->DM->TableNAMEBSCHET->AsString;
                DM->Doc->Post();
                }
		FormSpiskaSprBSchet=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}

if (number_procedure_end==ER_RaschSchetKlient)
		{
		if (type_event==1)
				{
				EndViborRaschSchetKlient()  ;
				}
		FormaSpiskaSprRaschSchet=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}

if (number_procedure_end==ER_RaschSchetGrpol)
		{
		if (type_event==1)
				{
				EndViborRaschSchetGrpol()  ;
				}
		FormaSpiskaSprRaschSchet=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}

EditRekvisit=NO;

ActionOperation=aoNO;
return -1;
}

//---------------------------------------------------------------------------







void TFormaDocVosvratPost::OpenFormSpiskaSprFirm(void)
{
if (Prosmotr==true) return;
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
void TFormaDocVosvratPost::OpenFormSpiskaSprSklad(void)
{
if (Prosmotr==true) return;
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
void TFormaDocVosvratPost::OpenFormSpiskaSprKlient(void)
{
if (Prosmotr==true) return;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&SpisokKlient);
		SpisokKlient->IdKlient=glStrToInt64(DM->DocAllIDKLDOC->AsString);
		SpisokKlient->Vibor=true;
		SpisokKlient->Init(InterfaceMainObject,InterfaceImpl);
		SpisokKlient->NumberProcVibor=ViborKlient;


}
//--------------------------------------------------------------------------



//---------------------------------------------------------------------------
void TFormaDocVosvratPost::OpenPrintForm(void)
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
void TFormaDocVosvratPost::OutputZagolovokReport(TSheetEditor *prForm)
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
numRow=1;
numCol=1;

IDMSprFirm * dm_spr_firm;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
													(void**)&dm_spr_firm);
		dm_spr_firm->Init(InterfaceMainObject,InterfaceImpl);
dm_spr_firm->OpenElement(glStrToInt64(DM->DocAllIDFIRMDOC->AsString));

cell = prForm->SS->ActiveSheet->GetCellObject(2, 1);
cell->Text=dm_spr_firm->ElementFNAMEFIRM->AsString
		+", ИНН "+dm_spr_firm->ElementINNFIRM->AsString;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Адрес: "+dm_spr_firm->ElementPADRFIRM->AsString;
delete cell;
numRow++;


cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Склад: "+DM->DocAllNAMESKLAD->AsString;
delete cell;
numRow++; numRow++;


cell = prForm->SS->ActiveSheet->GetCellObject(3, numRow);
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="Возврат поставщику №"+DM->DocAllNUMDOC->AsString+" от "
                +DateToStr(DM->DocAllPOSDOC->AsDateTime);
delete cell;
numRow++; numRow++;

IDMSprKlient * dm_spr_klient;
		InterfaceGlobalCom->kanCreateObject(ProgId_DMSprKlient,IID_IDMSprKlient,
													(void**)&dm_spr_klient);
		dm_spr_klient->Init(InterfaceMainObject,InterfaceImpl);
dm_spr_klient->OpenElement(glStrToInt64(DM->DocAllIDKLDOC->AsString));

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Поставщик: "+dm_spr_klient->ElementFNAME->AsString+", ИНН "+dm_spr_klient->ElementINNKLIENT->AsString;
delete cell;
numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Адрес: "+dm_spr_klient->ElementADRKLIENT->AsString;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Основание: "+DM->DocPRIMVPO->AsString;
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

dm_spr_firm->kanRelease();
dm_spr_klient->kanRelease();
}
//------------------------------------------------------------------------------
void TFormaDocVosvratPost::OutputString(TSheetEditor *prForm)
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
cell->Text=DM->DocTKOLVPOT->AsString;
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
cell->Text=FloatToStrF(DM->DocTKFVPOT->AsFloat,ffFixed,10,3);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTPRICEVPOT->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTSUMVPOT->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
}


//------------------------------------------------------------------------------
void TFormaDocVosvratPost::OutputPodavalReport(TSheetEditor *prForm)
{
TcxSSCellObject *cell;

cell = prForm->SS->ActiveSheet->GetCellObject(7, numRow);
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Text="Всего";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(8, numRow);
cell->Style->Font->Size = 10;
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
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="ВСЕГО: "+glCurrencyPropis(DM->DocAllSUMDOC->AsFloat);
delete cell;
numRow++;numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Сдал:  _________________________ ";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(5, numRow);
cell->Text="Принял  ________________________ ";
delete cell;
numRow++;numRow++;

}
//---------------------------------------------------------------
void TFormaDocVosvratPost::OpenFormSpiskaSprInfBase(void)
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

void __fastcall TFormaDocVosvratPost::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("DocVosvratPost");	
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocVosvratPost::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
 if (Prosmotr==true) return;

		OpenFormSpiskaSprNom();
		EditRekvisit=ViborTovar;

}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPost::cxGrid1DBTableView1NAMEEDPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;

		OpenFormSpiskaSprEd();
		EditRekvisit=ViborEdinica;

}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPost::TypePriceComboBoxPropertiesChange(
      TObject *Sender)
{
if(flObrabatChangeTypePrice==false) return;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
 if (Prosmotr==true)
		{
		UpdateForm();
		 return;
		}

if ( TypePriceComboBox->ItemIndex!=0)
		{
		DMSprTypePrice->Table->First();
		DMSprTypePrice->Table->MoveBy(TypePriceComboBox->ItemIndex-1);
		DM->Doc->Edit();
		DM->DocIDTPRICE_DVPO->AsString=DMSprTypePrice->TableID_TPRICE->AsString;
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
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDTPRICE_DVPO->AsString),
											 glStrToInt64(DM->DocTIDNOMVPOT->AsString));
						DM->DocTPRICEVPOT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKFVPOT->AsFloat;
						DM->DocT->Post();
						DM->DocT->Next();
						}
				DMSprPrice->kanRelease();
				}
		}		
}
//---------------------------------------------------------------------------






void __fastcall TFormaDocVosvratPost::NameKlientcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprKlient();	
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocVosvratPost::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprFirm();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPost::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprSklad();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPost::NameInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprInfBase();   	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPost::ActionAddStringExecute(TObject *Sender)
{
if (Prosmotr==true) return;
ActionOperation=aoAddNewString;
OpenFormSpiskaSprNom();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPost::ActionDeleteStringExecute(TObject *Sender)
{
if (Prosmotr==true) return;
DM->DeleteStringDoc();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPost::NumDoccxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPost::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPost::PrimcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocVosvratPost::TypeRPriceComboBoxPropertiesChange(
      TObject *Sender)
{
if(flObrabatChangeRTypePrice==false) return;
FindNextControl(ActiveControl,true,true,false)->SetFocus();

 if (Prosmotr==true)
		{
		UpdateForm();
		 return;
		}

 if ( TypeRPriceComboBox->ItemIndex!=0)
		{
		DMSprRTypePrice->Table->First();
		DMSprRTypePrice->Table->MoveBy(TypeRPriceComboBox->ItemIndex-1);
		DM->Doc->Edit();
		DM->DocIDRTPRICE_DVPO->AsString=DMSprRTypePrice->TableID_TPRICE->AsString;
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
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDRTPRICE_DVPO->AsString),
											 glStrToInt64(DM->DocTIDNOMVPOT->AsString));
						DM->DocTRPRICE_DVPOT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKFVPOT->AsFloat;
						DM->DocT->Post();
						DM->DocT->Next();
						}
				DMSprPrice->kanRelease();
				}
		}
}
//---------------------------------------------------------------------------

void TFormaDocVosvratPost::ViborDocOsn(void)
{

if (Prosmotr==true) return;
if (FormaGurAllDoc==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaGurAllDoc.1",IID_IFormaGurAllDoc,
													(void**)&FormaGurAllDoc);
		FormaGurAllDoc->Init(InterfaceMainObject,InterfaceImpl);
		FormaGurAllDoc->Vibor=true;
		//FormaGurAllDoc->UpdateForm();
		FormaGurAllDoc->NumberProcVibor=ER_DocOsn;
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocVosvratPost::EndViborDocOsn(void)
{


				DM->DocAll->Edit();
				DM->DocAllIDDOCOSNDOC->AsString=FormaGurAllDoc->DM->TableIDDOC->AsString;
				DM->DocAllTDOC_OSN->AsString=FormaGurAllDoc->DM->TableTDOC->AsString;
				DM->DocAllNUMDOC_OSN->AsString=FormaGurAllDoc->DM->TableNUMDOC->AsString;
                DM->DocAllPOSDOC_OSN->AsDateTime=FormaGurAllDoc->DM->TablePOSDOC->AsDateTime;
				DM->DocAll->Post();



}
//----------------------------------------------------------------------------
void __fastcall TFormaDocVosvratPost::cxDBButtonEdit1PropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborDocOsn();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocAll->Edit();
		DM->DocAllIDDOCOSNDOC->Clear();
		DM->DocAllTDOC_OSN->AsString="";
		DM->DocAll->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPost::NumDocPostcxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocVosvratPost::PosDocPostcxDBDateEditKeyPress(
      TObject *Sender, char &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaDocVosvratPost::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaDocVosvratPost::RunExternalModule(__int64 id_module, int type_module)
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
void __fastcall TFormaDocVosvratPost::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPost::ActionOKExecute(TObject *Sender)
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

void __fastcall TFormaDocVosvratPost::ActionDvRegExecute(TObject *Sender)
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

void __fastcall TFormaDocVosvratPost::ActionSaveExecute(TObject *Sender)
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

void __fastcall TFormaDocVosvratPost::ActionPrintExecute(TObject *Sender)
{
OpenPrintForm();
}
//---------------------------------------------------------------------------
void TFormaDocVosvratPost::OpenFormSpiskaSprProject(void)
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
void __fastcall TFormaDocVosvratPost::EndViborProject(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDPROJECT_GALLDOC->AsString=SpisokProject->DM->TableID_SPROJECT->AsString;
	DM->DocAllNAME_SPROJECT->AsString=SpisokProject->DM->TableNAME_SPROJECT->AsString;
	DM->DocAll->Post();




}
//----------------------------------------------------------------------------
void TFormaDocVosvratPost::OpenFormSpiskaSprBusinessOper(void)
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
void __fastcall TFormaDocVosvratPost::EndViborBusinessOper(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDBUSINOP_GALLDOC->AsString=SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString;
	DM->DocAllNAME_SBUSINESS_OPER->AsString=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;
	DM->DocAll->Post();

}
//----------------------------------------------------------------------------
void __fastcall TFormaDocVosvratPost::NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
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

void __fastcall TFormaDocVosvratPost::NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
void TFormaDocVosvratPost::OpenFormSpiskaSprBSchet(void)
{
if (FormSpiskaSprBSchet==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprBankSchet.1",IID_IFormaSpiskaSprBankSchet,
													(void**)&FormSpiskaSprBSchet);
	FormSpiskaSprBSchet->Init(InterfaceMainObject,InterfaceImpl);
	FormSpiskaSprBSchet->NumberProcVibor=ER_BankSchet;
	FormSpiskaSprBSchet->IdFirm=glStrToInt64(DM->DocAllIDFIRMDOC->AsString);
	FormSpiskaSprBSchet->DM->IdFirm=glStrToInt64(DM->DocAllIDFIRMDOC->AsString);
	FormSpiskaSprBSchet->DM->OpenTable();
	//FormSpiskaSprBSchet->LabelFirma->Caption="Фирма: "+DM->DocAllNAMEFIRM->AsString;
	FormSpiskaSprBSchet->Vibor=true;
	}
}
//---------------------------------------------------------------------------
void TFormaDocVosvratPost::OpenFormSpiskaSprGrPol(void)
{
if (Prosmotr==true) return;

if (SpisokKlient==0)
	{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&SpisokKlient);
		SpisokKlient->Init(InterfaceMainObject,InterfaceImpl);
		SpisokKlient->NumberProcVibor=ER_GrPol;
        SpisokKlient->Vibor=true;
	}
}
//-------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TFormaDocVosvratPost::ViborRaschSchetKlient(void)
{

if (FormaSpiskaSprRaschSchet==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprRaschSchet.1",IID_IFormaSpiskaSprRaschSchet,
													(void**)&FormaSpiskaSprRaschSchet);
	FormaSpiskaSprRaschSchet->Init(InterfaceMainObject,InterfaceImpl);
	FormaSpiskaSprRaschSchet->IdKlient=glStrToInt64(DM->DocAllIDKLDOC->AsString);
	FormaSpiskaSprRaschSchet->DM->OpenTable(glStrToInt64(DM->DocAllIDKLDOC->AsString));
	//SpisokRSchet->LabelKlient->Caption="Контрагент: "+DM->ElementNAMEKLIENT->AsString;
	FormaSpiskaSprRaschSchet->NumberProcVibor=ER_RaschSchetKlient;
	FormaSpiskaSprRaschSchet->Vibor=true;
	}

}
//---------------------------------------------------------------------------
void TFormaDocVosvratPost::ViborRaschSchetGrpol(void)
{
if (FormaSpiskaSprRaschSchet==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprRaschSchet.1",IID_IFormaSpiskaSprRaschSchet,
													(void**)&FormaSpiskaSprRaschSchet);
	FormaSpiskaSprRaschSchet->Init(InterfaceMainObject,InterfaceImpl);
	FormaSpiskaSprRaschSchet->IdKlient=glStrToInt64(DM->DocIDGRPOL_DVPO->AsString);
	FormaSpiskaSprRaschSchet->DM->OpenTable(glStrToInt64(DM->DocIDGRPOL_DVPO->AsString));
	//SpisokRSchet->LabelKlient->Caption="Контрагент: "+DM->ElementNAMEKLIENT->AsString;
	FormaSpiskaSprRaschSchet->NumberProcVibor=ER_RaschSchetGrpol;
	FormaSpiskaSprRaschSchet->Vibor=true;
	}


}
//---------------------------------------------------------------------------
void TFormaDocVosvratPost::EndViborRaschSchetKlient(void)
{

	DM->Doc->Edit();
	DM->DocIDRSCHETKLIENT_DVPO->AsString=FormaSpiskaSprRaschSchet->DM->TableIDRSCHET->AsString;
	DM->DocNAME_RSCHET_KLIENT->AsString=FormaSpiskaSprRaschSchet->DM->TableNAMERSCHET->AsString;
	DM->Doc->Post();

}
//---------------------------------------------------------------------------
void TFormaDocVosvratPost::EndViborRaschSchetGrpol(void)
{


	DM->Doc->Edit();
	DM->DocIDRSCHETGRPOL_DVPO->AsString=FormaSpiskaSprRaschSchet->DM->TableIDRSCHET->AsString;
	DM->DocNAME_RSCHET_GRPOL->AsString=FormaSpiskaSprRaschSchet->DM->TableNAMERSCHET->AsString;
	DM->Doc->Post();

}
//---------------------------------------------------------------------------
void __fastcall TFormaDocVosvratPost::NameBSchetcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
OpenFormSpiskaSprBSchet();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPost::NameGrPolcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
OpenFormSpiskaSprGrPol();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPost::NameRaschScetKlientcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborRaschSchetKlient();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->Doc->Edit();
		DM->DocIDRSCHETKLIENT_DVPO->Clear();
		DM->Doc->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPost::NameRaschSchetGrpolcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborRaschSchetGrpol();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->Doc->Edit();
		DM->DocIDRSCHETGRPOL_DVPO->Clear();
		DM->Doc->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

