//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaDocRealRozn.h"
#include "IDMSprPrice.h"
#include "IDMSprFirm.h"

#include "math.h"
#include "USheetEditor.h"
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
#pragma link "cxContainer"
#pragma link "cxDBEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxMaskEdit"
#pragma link "cxPC"
#pragma link "cxTextEdit"
#pragma link "cxCalendar"
#pragma link "cxLabel"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaDocRealRozn::TFormaDocRealRozn(TComponent* Owner)
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
bool TFormaDocRealRozn::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRealRozn.1",IID_IDMDocRealRozn, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи


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



cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceDocT;
cxGridPayDBTableView1->DataController->DataSource=DM->DataSourcePay;

DBTextFNameUser->DataSource=DM->DataSourceDocAll;


NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameSkladcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameProjectcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameKKMcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameDogcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameBusinessOpercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PrefiksNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;

FirstPaycxDBCalcEdit->DataBinding->DataSource=DM->DataSourceDoc;
PrimcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;


ActionOperation=aoNO;

//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
										 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaDocRealRoznImpl),false);
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
int TFormaDocRealRozn::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaDocRealRozn::UpdateForm(void)
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
TypePriceComboBox->ItemIndex=DMSprTypePrice->GetIndexTypePricePoId(glStrToInt64(DM->DocIDTPRICE_DREALROZN->AsString));
flObrabatChangeTypePrice=true;
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocRealRozn::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokFirm)SpisokFirm->kanRelease();
if(SpisokSklad)SpisokSklad->kanRelease();
if(SpisokKlient)SpisokKlient->kanRelease();
if(SpisokNom)SpisokNom->kanRelease();
if(SpisokEd)SpisokEd->kanRelease();
if(FormaSpiskaSprDogovor)FormaSpiskaSprDogovor->kanRelease();
if(SpisokKKM)SpisokKKM->kanRelease();
if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
if(SpisokProject)SpisokProject->kanRelease();
if(SpisokBusinessOper)SpisokBusinessOper->kanRelease();

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
DMTableExtPrintForm->kanRelease();
DMSprTypePrice->kanRelease();

Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}

}
//---------------------------------------------------------------------------




void TFormaDocRealRozn::OpenFormSpiskaSprEd(void)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;
if (SpisokEd==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&SpisokEd);
		SpisokEd->Init(InterfaceMainObject,InterfaceImpl);
		SpisokEd->NumberProcVibor=ER_Ed;
		SpisokEd->Vibor=true;
		SpisokEd->DM->OpenTable(glStrToInt64(DM->DocTIDNOM_DREALROZNT->AsString));
        }
}
//-----------------------------------------------------------------------------
void TFormaDocRealRozn::OpenFormSpiskaSprNom(void)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;
if (SpisokNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&SpisokNom);
		SpisokNom->Init(InterfaceMainObject,InterfaceImpl);
		SpisokNom->NumberProcVibor=ER_Nom;
        SpisokNom->Vibor=true;
		SpisokNom->DM->IdTypePrice=glStrToInt64(DM->DocIDTPRICE_DREALROZN->AsString);
		SpisokNom->IdNom=glStrToInt64(DM->DocTIDNOM_DREALROZNT->AsString);
		SpisokNom->UpdateForm();
        }

}

//---------------------------------------------------------------------------
int TFormaDocRealRozn::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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
				DM->DocTIDNOM_DREALROZNT->AsString=SpisokNom->DM->ElementIDNOM->AsString;
                DM->DocTNAMENOM->AsString=SpisokNom->DM->ElementNAMENOM->AsString;
                DM->DocTTNOM->AsInteger=SpisokNom->DM->ElementTNOM->AsInteger;
                DM->DocTKOL_DREALROZNT->AsFloat=1;
				DM->DocTIDED_DREALROZNT->AsString=SpisokNom->DM->ElementIDOSNEDNOM->AsString;
                DM->DocTNAMEED->AsString=SpisokNom->DM->OsnEdNAMEED->AsString;
                DM->DocTKF_DREALROZNT->AsFloat=SpisokNom->DM->OsnEdKFED->AsFloat;
				IDMSprPrice * DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDTPRICE_DREALROZN->AsString),
											 glStrToInt64(DM->DocTIDNOM_DREALROZNT->AsString));
                        DM->DocTPRICE_DREALROZNT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
                                                        DM->DocTKF_DREALROZNT->AsFloat;
                DMSprPrice->kanRelease();
                DM->DocT->Post();
                }
		SpisokNom=0;
		cxGrid1->SetFocus();
		cxGrid1DBTableView1KOL_DREALROZNT->Selected=true;
        }

if (number_procedure_end==ER_Ed)//EditRekvisit==ViborEdinica)
        {
		if (type_event==1)
                {
                DM->DocT->Edit();
				DM->DocTIDED_DREALROZNT->AsString=SpisokEd->DM->ElementIDED->AsString;
                DM->DocTNAMEED->AsString=SpisokEd->DM->ElementNAMEED->AsString;
                DM->DocTKF_DREALROZNT->AsFloat=SpisokEd->DM->ElementKFED->AsFloat;
				IDMSprPrice * DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDTPRICE_DREALROZN->AsString),
											 glStrToInt64(DM->DocTIDNOM_DREALROZNT->AsString));
                        DM->DocTPRICE_DREALROZNT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
                                                        DM->DocTKF_DREALROZNT->AsFloat;
                DMSprPrice->kanRelease();

                DM->DocT->Post();
                }
		SpisokEd=0;
		cxGrid1->SetFocus();
		cxGrid1DBTableView1PRICE_DREALROZNT->Selected=true;
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
				}
		SpisokSklad=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
        }

if (number_procedure_end==ER_Klient)//EditRekvisit==ViborKlient)
        {
		if (type_event==1)
                {
                DM->DocAll->Edit();
				DM->DocAllIDKLDOC->AsString=SpisokKlient->DM->ElementIDKLIENT->AsString;
                DM->DocAllNAMEKLIENT->AsString=SpisokKlient->DM->ElementNAMEKLIENT->AsString;
				DM->DocAll->Post();

				if (SpisokKlient->DM->ElementIDTPRICEKLIENT->AsInteger!=0)
					{
					TypePriceComboBox->ItemIndex=
						DMSprTypePrice->GetIndexTypePricePoId(glStrToInt64(SpisokKlient->DM->ElementIDTPRICEKLIENT->AsString));
					}  				
                
                }
		SpisokKlient=0;
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
        
if (number_procedure_end==ER_Dogovor)//EditRekvisit==ViborDogovor)
        {
		if(type_event==1)
                {
                DM->DocAll->Edit();
				DM->DocAllIDDOGDOC->AsString=FormaSpiskaSprDogovor->DM->TableID_SDOG->AsString;
                DM->DocAllNAME_SDOG->AsString=FormaSpiskaSprDogovor->DM->TableNAME_SDOG->AsString;
                DM->DocAll->Post();
                }
		FormaSpiskaSprDogovor=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
         }

if (number_procedure_end==ER_Kassa)//EditRekvisit==ViborKKM)
		{
		if (type_event==1)
				{
                DM->Doc->Edit();
				DM->DocIDKKM_DREALROZN->AsString=SpisokKKM->DM->ElementIDKKM->AsString;
                DM->DocNAMEKKM->AsString=SpisokKKM->DM->ElementNAMEKKM->AsString;
                DM->Doc->Post();
                }
		SpisokKKM=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}


if (number_procedure_end==ER_Project)
		{
		if (type_event==1)
				{
				EndViborProject();
				}
		SpisokProject=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
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
return -1;
}

//---------------------------------------------------------------------------







void TFormaDocRealRozn::OpenFormSpiskaSprFirm(void)
{
if (Prosmotr==true) return;
if (SpisokFirm==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&SpisokFirm);
		SpisokFirm->Init(InterfaceMainObject,InterfaceImpl);
		SpisokFirm->NumberProcVibor=ER_Firm;
		SpisokFirm->Vibor=true;
        }

}

//---------------------------------------------------------------------------
void TFormaDocRealRozn::OpenFormSpiskaSprSklad(void)
{
if (Prosmotr==true) return;
if (SpisokSklad==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&SpisokSklad);
		SpisokSklad->Init(InterfaceMainObject,InterfaceImpl);
		SpisokSklad->NumberProcVibor=ER_Sklad;
		SpisokSklad->Vibor=true;
        }

}
//--------------------------------------------------------------------------
void TFormaDocRealRozn::OpenFormSpiskaSprKlient(void)
{
if (Prosmotr==true) return;
if (SpisokKlient==0)
	{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&SpisokKlient);
		SpisokKlient->Init(InterfaceMainObject,InterfaceImpl);
		SpisokKlient->NumberProcVibor=ER_Klient;
		SpisokKlient->Vibor=true;
		SpisokKlient->IdKlient=glStrToInt64(DM->DocAllIDKLDOC->AsString);
		SpisokKlient->UpdateForm();

	 }
}

//--------------------------------------------------------------------------





void TFormaDocRealRozn::OpenFormSpiskaSprInfBase(void)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;
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

void TFormaDocRealRozn::OpenPrintFormNakl(void)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
porNumStr=1;


//шапка
PrintForm->SS->BeginUpdate();
OutputZagolovokReportNakl(PrintForm);

//таблица

DM->DocT->First();
while(!DM->DocT->Eof)
        {

        OutputStringNakl(PrintForm);numRow++; porNumStr++;

        DM->DocT->Next();
        }

OutputPodavalReportNakl(PrintForm);
PrintForm->SS->EndUpdate();
PrintForm->Show();
}
//---------------------------------------------------------------------------
void TFormaDocRealRozn::OutputZagolovokReportNakl(TSheetEditor *prForm)
{
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



TcxSSCellObject *cell;
numRow=1;
numCol=2;

IDMSprFirm *DMSprFirm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
													(void**)&DMSprFirm);
DMSprFirm->Init(InterfaceMainObject,InterfaceImpl);

DMSprFirm->OpenElement(glStrToInt64(DM->DocAllIDFIRMDOC->AsString));
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DMSprFirm->ElementFNAMEFIRM->AsString+
                "ИНН "+DMSprFirm->ElementINNFIRM->AsString;
delete cell;
numRow++;


cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Адрес: "+DMSprFirm->ElementPADRFIRM->AsString;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Склад: "+DM->DocAllNAMESKLAD->AsString;
delete cell;
numRow++;
numRow++;

DMSprFirm->kanRelease();

cell = prForm->SS->ActiveSheet->GetCellObject(3, numRow);
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="Расходная накладная №"+DM->DocAllNUMDOC->AsString+" от "
                +DateToStr(DM->DocAllPOSDOC->AsDateTime);
delete cell;
numRow++; numRow++;

IDMSprKlient * DMSprKlient;
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprKlient,IID_IDMSprKlient,
													(void**)&DMSprKlient);
DMSprKlient->Init(InterfaceMainObject,InterfaceImpl);
DMSprKlient->OpenElement(glStrToInt64(DM->DocAllIDKLDOC->AsString));
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Покупатель: "+DMSprKlient->ElementFNAME->AsString
                        +", ИНН "+DMSprKlient->ElementINNKLIENT->AsString;
delete cell;
numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Адрес: "+DMSprKlient->ElementADRKLIENT->AsString;
delete cell;
numRow++;

DMSprKlient->kanRelease();

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Основание: "+DM->DocPRIM_DREALROZN->AsString;
delete cell;
numRow++;
numRow++;

//заголовок таблицы
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
void TFormaDocRealRozn::OutputStringNakl(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=2; 

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IntToStr(porNumStr);
cell->Style->Font->Size = 10;
//cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTNAMENOM->AsString;
cell->Style->Font->Size = 10;
//cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTKOL_DREALROZNT->AsString;
cell->Style->Font->Size = 10;
//cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTNAMEED->AsString;
cell->Style->Font->Size = 10;
//cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTKF_DREALROZNT->AsFloat,ffFixed,10,3);
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haRIGHT;
//cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTPRICE_DREALROZNT->AsFloat,ffFixed,10,2);
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haRIGHT;
//cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTSUM_DREALROZNT->AsFloat,ffFixed,10,2);
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haRIGHT;
//cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

}


//------------------------------------------------------------------------------
void TFormaDocRealRozn::OutputPodavalReportNakl(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
cell = prForm->SS->ActiveSheet->GetCellObject(7, numRow);
cell->Text="Всего";
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(8, numRow);
cell->Text=FloatToStrF(DM->DocAllSUMDOC->AsFloat,ffFixed,10,2);
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
numRow++;numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Style->Font->Size = 10;
cell->Text="ВСЕГО: "+glCurrencyPropis(DM->DocAllSUMDOC->AsFloat);
delete cell;
numRow++;numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Отпустил:  _________________________ ";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(5, numRow);
cell->Text="Получил  ________________________ ";
delete cell;
numRow++;numRow++;

}
//---------------------------------------------------------------
void __fastcall TFormaDocRealRozn::ToolButtonPrintNaklClick(
      TObject *Sender)
{
OpenPrintFormNakl();        
}
//---------------------------------------------------------------------------
void TFormaDocRealRozn::OpenFormSpiskaSprDogovor(void)
{
if (glStrToInt64(DM->DocAllIDKLDOC->AsString)==0)
        {
        ShowMessage("Выберите контрагента!");
        return;
        }


if(FormaSpiskaSprDogovor==0)
	{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprDogovor.1",IID_IFormaSpiskaSprDogovor,
													(void**)&FormaSpiskaSprDogovor);
		FormaSpiskaSprDogovor->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprDogovor->NumberProcVibor=ER_Dogovor;
		FormaSpiskaSprDogovor->IdKlient=glStrToInt64(DM->DocAllIDKLDOC->AsString);
        FormaSpiskaSprDogovor->Vibor=true;
		FormaSpiskaSprDogovor->DM->OpenTable(glStrToInt64(DM->DocAllIDKLDOC->AsString));
		//FormaSpiskaSprDogovor->LabelKlient->Caption="Контрагент: "+DM->DocAllNAMEKLIENT->AsString;

	}
}
//-----------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TFormaDocRealRozn::OpenFormSpiskaSprKKM(void)
{
 if (Prosmotr==true) return;
 if (SpisokKKM==0)
	{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKKM.1",IID_IFormaSpiskaSprKKM,
													(void**)&SpisokKKM);
		SpisokKKM->Init(InterfaceMainObject,InterfaceImpl);
		SpisokKKM->NumberProcVibor=ER_Kassa;
		SpisokKKM->Vibor=true;
	}
}
//-----------------------------------------------------------------------------


void __fastcall TFormaDocRealRozn::ToolButtonGreateGrafikPlatClick(
      TObject *Sender)
{
IDMSprDogovor * DMSprDogovor;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprDogovor.1",IID_IDMSprDogovor,
													(void**)&DMSprDogovor);
DMSprDogovor->Init(InterfaceMainObject,InterfaceImpl);
if(DMSprDogovor->OpenElement(glStrToInt64(DM->DocAllIDDOGDOC->AsString))>0)
        {
        switch (DMSprDogovor->ElementWAYPAY_SDOG->AsInteger)
                {
                case 0: //   - 0 свободный
                        {

                        break;
                        }
                case 2:   //   - 2 равными долями каждый месяц в течении отсрочки (отсрочка в месяцах)
                        {
                        double sum_credita=DM->DocAllSUMDOC->AsFloat-
                                DM->DocFIRSTSUM_DREALROZN->AsFloat;
                        if (DMSprDogovor->ElementSROK_SDOG->AsInteger==0)
                                {
                                ShowMessage("Не задан срок кредита!");
                                return;
                                }

                        DM->Pay->First();
                        while(!DM->Pay->Eof)
                                {
                                DM->Pay->Delete();
                                }
                        //первоначальный взнос
                        if( DM->DocFIRSTSUM_DREALROZN->AsFloat>0)
                                {
								DM->Pay->Append();
                                DM->PayDO_DREALROZN_PAY->AsDateTime=DM->DocAllPOSDOC->AsDateTime;
                                DM->PaySUM_DREALROZN_PAY->AsFloat=DM->DocFIRSTSUM_DREALROZN->AsFloat;
                                DM->Pay->Post();
                                }
                        //ежемесячные платежи
                        for(int i=1;i<DMSprDogovor->ElementSROK_SDOG->AsInteger;i++)
                                {
								DM->Pay->Append();
                                DM->PayDO_DREALROZN_PAY->AsDateTime=IncMonth(DM->DocAllPOSDOC->AsDateTime,i);
                                DM->PaySUM_DREALROZN_PAY->AsFloat=floor(sum_credita/DMSprDogovor->ElementSROK_SDOG->AsInteger);
                                DM->Pay->Post();
                                }
                        double sum=0;
                        DM->Pay->First();
                        while(!DM->Pay->Eof)
                                {
                                sum=sum+DM->PaySUM_DREALROZN_PAY->AsFloat;
                                DM->Pay->Next();
                                }
                        sum=sum-DM->DocFIRSTSUM_DREALROZN->AsFloat;
                        //последний платеж
                        DM->Pay->Append();
                        DM->PayDO_DREALROZN_PAY->AsDateTime=IncMonth(DM->DocAllPOSDOC->AsDateTime,DMSprDogovor->ElementSROK_SDOG->AsInteger);
                        DM->PaySUM_DREALROZN_PAY->AsFloat=sum_credita-sum;
                        DM->Pay->Post();
                        PageControl1->ActivePage=TabSheet2;
                        cxGridPay->Focused();
                        break;
                        }
                case 3:   //   //   - 3 в течении отсрочки платежа (отсрочка в днях)
                        {
                        double sum_credita=DM->DocAllSUMDOC->AsFloat-
                                DM->DocFIRSTSUM_DREALROZN->AsFloat;
                        if (DMSprDogovor->ElementSROK_SDOG->AsInteger==0)
                                {
                                ShowMessage("Не задан срок кредита!");
                                return;
                                }

                        DM->Pay->First();
                        while(!DM->Pay->Eof)
                                {
                                DM->Pay->Delete();
                                }
                        //первоначальный взнос
                        if( DM->DocFIRSTSUM_DREALROZN->AsFloat>0)
                                {
								DM->Pay->Append();
                                DM->PayDO_DREALROZN_PAY->AsDateTime=DM->DocAllPOSDOC->AsDateTime;
                                DM->PaySUM_DREALROZN_PAY->AsFloat=DM->DocFIRSTSUM_DREALROZN->AsFloat;
                                DM->Pay->Post();
                                }

                        //последний платеж
						DM->Pay->Append();
                        DM->PayDO_DREALROZN_PAY->AsDateTime=DM->DocAllPOSDOC->AsDateTime+DMSprDogovor->ElementSROK_SDOG->AsInteger;
                        DM->PaySUM_DREALROZN_PAY->AsFloat=sum_credita;
                        DM->Pay->Post();
                        PageControl1->ActivePage=TabSheet2;
                        cxGridPay->Focused();
                        break;
						}

//   - 1 равными долями каждый месяц до указанной даты


//   - 4 до указанной даты
//   - 5 по заданному графику платежей

                }
        }
else
        {
        ShowMessage("Ошибка! Не найден выбранный договор!");

        }

DMSprDogovor->kanRelease();
}
//---------------------------------------------------------------------------


//-----------------------------------------------------------------------------
void __fastcall TFormaDocRealRozn::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaDocRealRozn::RunExternalModule(__int64 id_module, int type_module)
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
if (type_module==1 || type_module==2)
	{
	//надо добавить класс TScriptDMDocRealRozn
	//методы для работы с документом
//	module->AddClassesInScript_DMDocRealRozn();
//	module->ScriptDMDocRealRozn->DM=DM;
//	module->fsScript1->AddObject("TecDMDocRealRozn",module->ScriptDMDocRealRozn);
	}

 //надо добавить переменные модуля, как минимум  IDDOC
 module->SetInt64Variables("glIdDoc", glStrToInt64(DM->DocAllIDDOC->AsString));

	
module->ExecuteModule();
}
//-----------------------------------------------------------------------------

void __fastcall TFormaDocRealRozn::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("DocRealRozn");
}
//---------------------------------------------------------------------------



void __fastcall TFormaDocRealRozn::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;

		OpenFormSpiskaSprNom();


}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRozn::cxGrid1DBTableView1NAMEEDPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;

		OpenFormSpiskaSprEd();

}
//---------------------------------------------------------------------------





void __fastcall TFormaDocRealRozn::NameDogcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprDogovor();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRozn::NameKlientcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;
OpenFormSpiskaSprKlient();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRozn::NameKKMcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprKKM();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRozn::TypePriceComboBoxPropertiesChange(
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
		DM->DocIDTPRICE_DREALROZN->AsString=DMSprTypePrice->TableID_TPRICE->AsString;
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
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDTPRICE_DREALROZN->AsString),
											 glStrToInt64(DM->DocTIDNOM_DREALROZNT->AsString));
						DM->DocTPRICE_DREALROZNT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKF_DREALROZNT->AsFloat;
						DM->DocT->Post();
						DM->DocT->Next();
						}
				delete DMSprPrice;
				}
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRozn::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;
OpenFormSpiskaSprFirm();  	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRozn::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;
OpenFormSpiskaSprSklad();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRozn::NameInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprInfBase();  	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRozn::ActionAddStringExecute(TObject *Sender)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;
ActionOperation=aoAddNewString;
OpenFormSpiskaSprNom();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRozn::ActionDeleteStringExecute(TObject *Sender)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;
DM->DeleteStringDoc();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRozn::NumcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRozn::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocRealRozn::FirstPaycxDBCalcEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRozn::PrimcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void TFormaDocRealRozn::OpenFormSpiskaSprProject(void)
{
if (Prosmotr==true) return;
if (SpisokProject==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprProject.1",IID_IFormaSpiskaSprProject,
													(void**)&SpisokProject);
		SpisokProject->Init(InterfaceMainObject,InterfaceImpl);
		SpisokProject->Vibor=true;
		SpisokProject->UpdateForm();
		SpisokProject->NumberProcVibor=ER_Project;
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocRealRozn::EndViborProject(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDPROJECT_GALLDOC->AsString=SpisokProject->DM->TableID_SPROJECT->AsString;
	DM->DocAllNAME_SPROJECT->AsString=SpisokProject->DM->TableNAME_SPROJECT->AsString;
	DM->DocAll->Post();

}
//----------------------------------------------------------------------------

void __fastcall TFormaDocRealRozn::NameProjectcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
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


void __fastcall TFormaDocRealRozn::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRozn::ActionOKExecute(TObject *Sender)
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

void __fastcall TFormaDocRealRozn::ActionDvRegExecute(TObject *Sender)
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

void __fastcall TFormaDocRealRozn::ActionSaveExecute(TObject *Sender)
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

void TFormaDocRealRozn::OpenFormSpiskaSprBusinessOper(void)
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
void __fastcall TFormaDocRealRozn::EndViborBusinessOper(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDBUSINOP_GALLDOC->AsString=SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString;
	DM->DocAllNAME_SBUSINESS_OPER->AsString=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;
	DM->DocAll->Post();

}
//----------------------------------------------------------------------------

void __fastcall TFormaDocRealRozn::NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
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

