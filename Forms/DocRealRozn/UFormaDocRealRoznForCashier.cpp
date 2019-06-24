//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaDocRealRoznForCashier.h"
#include "IDMSprPrice.h"
#include "IDMSprFirm.h"
#include "IDMSprARM.h"
#include "IFiskReg.h"

#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"

#include "math.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxCalc"
#pragma link "cxButtonEdit"
#pragma link "cxPC"
#pragma link "cxClasses"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "cxLabel"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaDocRealRoznForCashier::TFormaDocRealRoznForCashier(TComponent* Owner)
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
bool TFormaDocRealRoznForCashier::Init(void)
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

EditRekvisit=NO;
InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRealRozn.1",IID_IDMDocRealRozn, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);


Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи

NameBaseDBText->DataSource=DM->DataSourceDocAll;
SumDocDBText->DataSource=DM->DataSourceDocAll;
DBTextFNameUser->DataSource=DM->DataSourceDocAll;

NameTPriceDBText->DataSource=DM->DataSourceDoc;

NameFirmcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameSkladcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameProjectcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NumDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameDogovorcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameKKMcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
FirstSumcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceDoc;
PrimcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
PrefiksNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceDocT;
cxGrid2DBTableView1->DataController->DataSource=DM->DataSourcePay;


ActionOperation=aoNO;


 //ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
result=true;

return result;
}
//--------------------------------------------------------------------------
int TFormaDocRealRoznForCashier::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaDocRealRoznForCashier::UpdateForm(void)
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




}
//---------------------------------------------------------------------------
void __fastcall TFormaDocRealRoznForCashier::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokKlient)SpisokKlient->kanRelease();
if(FormaSpiskaSprDogovor)FormaSpiskaSprDogovor->kanRelease();
if(SpisokNom)SpisokNom->kanRelease();
if(SpisokEd)SpisokEd->kanRelease();
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

DM->kanRelease();
Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}

}
//---------------------------------------------------------------------------


void __fastcall TFormaDocRealRoznForCashier::ToolButtonInsertClick(TObject *Sender)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;
ActionOperation=aoAddNewString;
OpenFormSpiskaSprNom();
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocRealRoznForCashier::ToolButtonDeleteClick(TObject *Sender)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;
DM->DeleteStringDoc();
}

//---------------------------------------------------------------------------
void TFormaDocRealRoznForCashier::OpenFormSpiskaSprEd(void)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;

if (SpisokEd==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaViborSprEd.1",IID_IFormaViborSprEd,
													(void**)&SpisokEd);
		SpisokEd->Init(InterfaceMainObject,InterfaceImpl);
		SpisokEd->NumberProcVibor=ViborEdinica;
		SpisokEd->Vibor=true;
		SpisokEd->DM->OpenTable(glStrToInt64(DM->DocTIDNOM_DREALROZNT->AsString));
		}
}
//-----------------------------------------------------------------------------
void TFormaDocRealRoznForCashier::OpenFormSpiskaSprNom(void)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;

if (SpisokNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaViborSprNom.1",IID_IFormaViborSprNom,
													(void**)&SpisokNom);
		SpisokNom->Init(InterfaceMainObject,InterfaceImpl);
		SpisokNom->NumberProcVibor=ViborTovar;
        SpisokNom->Vibor=true;
		SpisokNom->DM->IdTypePrice=glStrToInt64(DM->DocIDTPRICE_DREALROZN->AsString);
		//SpisokNom->IdNom=glStrToInt64(DM->DocTIDNOM_DREALROZNT->AsString);
		SpisokNom->UpdateForm();
		}

}

//---------------------------------------------------------------------------
int TFormaDocRealRoznForCashier::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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
						DMSprPrice->FindElement( glStrToInt64(DM_Connection->ARMInfoIDTPRICEPOD->AsString),
											 glStrToInt64(DM->DocTIDNOM_DREALROZNT->AsString));
                        DM->DocTPRICE_DREALROZNT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
                                                        DM->DocTKF_DREALROZNT->AsFloat;
                DMSprPrice->kanRelease();
                DM->DocT->Post();
                }
        SpisokNom=0;
        }

if (number_procedure_end==ViborEdinica)
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
						DMSprPrice->FindElement( glStrToInt64(DM_Connection->ARMInfoIDTPRICEPOD->AsString),
											 glStrToInt64(DM->DocTIDNOM_DREALROZNT->AsString));
                        DM->DocTPRICE_DREALROZNT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
                                                        DM->DocTKF_DREALROZNT->AsFloat;
				DMSprPrice->kanRelease();

                DM->DocT->Post();
                }
        SpisokEd=0;
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

if (number_procedure_end==ViborProject)//EditRekvisit==ViborKKM)
		{
		if (type_event==1)
				{
				EndViborProject();
				}
		SpisokProject=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}

ActionOperation=aoNO;
EditRekvisit=NO;
return -1;
}

//---------------------------------------------------------------------------


void TFormaDocRealRoznForCashier::OpenFormSpiskaSprKlient(void)
{
if (Prosmotr==true) return;
if (SpisokKlient==0)
	{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&SpisokKlient);
		SpisokKlient->Init(InterfaceMainObject,InterfaceImpl);
		SpisokKlient->NumberProcVibor=ViborKlient;
		SpisokKlient->Vibor=true;
		SpisokKlient->IdKlient=glStrToInt64(DM->DocAllIDKLDOC->AsString);
		SpisokKlient->UpdateForm();

	 }

}

//--------------------------------------------------------------------------


void TFormaDocRealRoznForCashier::OpenPrintFormNakl(void)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
porNumStr=1;

PrintForm->SS->BeginUpdate();
//шапка
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
void TFormaDocRealRoznForCashier::OutputZagolovokReportNakl(TSheetEditor *prForm)
{
        TcxSSHeader *cHeader;
        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 30;
        cHeader->Size[2] = 200;
        cHeader->Size[3] = 80;
        cHeader->Size[4] = 80;
        cHeader->Size[5] = 80;
        cHeader->Size[6] = 80;
        cHeader->Size[7] = 100;


numRow=1;
numCol=1;

IDMSprFirm *DMSprFirm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
													(void**)&DMSprFirm);
DMSprFirm->Init(InterfaceMainObject,InterfaceImpl);
DMSprFirm->OpenElement(glStrToInt64(DM->DocAllIDFIRMDOC->AsString));

TcxSSCellObject *cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = DMSprFirm->ElementFNAMEFIRM->AsString+
                "ИНН "+DMSprFirm->ElementINNFIRM->AsString;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Адрес: "+DMSprFirm->ElementPADRFIRM->AsString;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Склад: "+DM->DocAllNAMESKLAD->AsString;
delete cell;
numRow++;
numRow++;

DMSprFirm->kanRelease();

numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Расходная накладная №"+DM->DocAllNUMDOC->AsString+" от "
                +DateToStr(DM->DocAllPOSDOC->AsDateTime);
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;
numRow++; numRow++;

numCol=1;
IDMSprKlient * DMSprKlient;
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprKlient,IID_IDMSprKlient,
													(void**)&DMSprKlient);
DMSprKlient->Init(InterfaceMainObject,InterfaceImpl);
DMSprKlient->OpenElement(glStrToInt64(DM->DocAllIDKLDOC->AsString));
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Покупатель: "+DMSprKlient->ElementFNAME->AsString
                        +", ИНН "+DMSprKlient->ElementINNKLIENT->AsString;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Адрес: "+DMSprKlient->ElementADRKLIENT->AsString;
delete cell;
numRow++;

DMSprKlient->kanRelease();

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Основание: "+DM->DocPRIM_DREALROZN->AsString;
delete cell;
numRow++;
numRow++;

//заголовок таблицы
numCol=1;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "№";
cell->Style->Font->Size = 10;
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
cell->Style->Font->Size = 10;
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
cell->Style->Font->Size = 10;
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
cell->Style->Font->Size = 10;
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
cell->Style->Font->Size = 10;
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
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Сумма";
cell->Style->Font->Size = 10;
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
void TFormaDocRealRoznForCashier::OutputStringNakl(TSheetEditor *prForm)
{
numCol=1;
TcxSSCellObject *cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = IntToStr(porNumStr);
cell->Style->Font->Size = 10;
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
cell->Style->Font->Size = 10;
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
cell->Text = DM->DocTKOL_DREALROZNT->AsString;
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = DM->DocTNAMEED->AsString;
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(DM->DocTKF_DREALROZNT->AsFloat,ffFixed,10,3);
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(DM->DocTPRICE_DREALROZNT->AsFloat,ffFixed,10,2);
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(DM->DocTSUM_DREALROZNT->AsFloat,ffFixed,10,2);
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

}


//------------------------------------------------------------------------------
void TFormaDocRealRoznForCashier::OutputPodavalReportNakl(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
//numRow++;
numCol=6;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Всего";
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

numCol=7;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(DM->DocAllSUMDOC->AsFloat,ffFixed,10,2);
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numRow++;numRow++;

numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "ВСЕГО: "+glCurrencyPropis(DM->DocAllSUMDOC->AsFloat);
cell->Style->Font->Size = 10;
delete cell;
numRow++;numRow++;

numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Отпустил:  _________________________ ";
cell->Style->Font->Size = 10;
delete cell;

numCol=5;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Получил  ________________________ ";
cell->Style->Font->Size = 10;
delete cell;
numRow++;numRow++;

}
//---------------------------------------------------------------
void __fastcall TFormaDocRealRoznForCashier::ToolButtonPrintNaklClick(
      TObject *Sender)
{
OpenPrintFormNakl();        
}
//---------------------------------------------------------------------------
void TFormaDocRealRoznForCashier::OpenFormSpiskaSprDogovor(void)
{
if (glStrToInt64(DM->DocAllIDKLDOC->AsString)==0)
		{
		ShowMessage("Выберите контрагента!");
		return;
		}

if(FormaSpiskaSprDogovor==0)
	{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprDogovor.1",IID_IFormaSpiskaSprDogovor,
													(void**)&SpisokEd);
		FormaSpiskaSprDogovor->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprDogovor->NumberProcVibor=ViborDogovor;
		FormaSpiskaSprDogovor->IdKlient=glStrToInt64(DM->DocAllIDKLDOC->AsString);
		FormaSpiskaSprDogovor->Vibor=true;
		FormaSpiskaSprDogovor->DM->OpenTable(glStrToInt64(DM->DocAllIDKLDOC->AsString));
		//FormaSpiskaSprDogovor->LabelKlient->Caption="Контрагент: "+DM->DocAllNAMEKLIENT->AsString;

	}
}
//-----------------------------------------------------------------------------
bool TFormaDocRealRoznForCashier::PrintDocOnFR(void)
{
bool Res=false;
//if(glFR->ConnectFR==false)
//		{
//        ShowMessage("Фискальный регистратор не подключен!");
//        return Res;
//
//        }
//
//
//        if (DM->DocT->RecordCount==0)
//                {
//                ShowMessage("Нет строк в табличной части!");
//				return Res;
//                }
//
//
//if(glFR->ProvVosmPrintCheck()==false)
//		{
//        return Res;
//        }
//
//glFR->OpenNoFiscalCheck();
//
//
//String StrPr="  ";
//
//if (DM_Connection->Arm_GetParameter("STR_ZAG_1")!="")
//		{
//		glFR->PrintString(DM_Connection->Arm_GetParameter("STR_ZAG_1"),1,0,0,true,false, false);
//        }
//
//if (DM_Connection->Arm_GetParameter("STR_ZAG_2")!="")
//		{
//		glFR->PrintString(DM_Connection->Arm_GetParameter("STR_ZAG_2"),1,0,0,true,false, false);
//        }
//
//if (DM_Connection->Arm_GetParameter("STR_ZAG_3")!="")
//		{
//		glFR->PrintString(DM_Connection->Arm_GetParameter("STR_ZAG_3"),1,0,0,true,false, false);
//        }
//
//glFR->PrintString(" ",1,0,0,true,false, false);
//
//
//
//
//glFR->PrintString("Реализация ",3,0,1,true,false, false);
//
//glFR->PrintString("N"+DM->DocAllNUMDOC->AsString
//				+" от "+DateToStr(DM->DocAllPOSDOC->AsDateTime),1,0,1,true,false, false);
//
//glFR->PrintString(" ",1,0,1,true,false, false);
//glFR->PrintString("Покупатель: ",1,0,0,true,false, false);
//glFR->PrintString(DM->DocAllNAMEKLIENT->AsString,1,0,0,true,false, false);
//glFR->PrintString("Договор: ",1,0,0,true,false, false);
//glFR->PrintString(DM->DocAllNAME_SDOG->AsString,1,0,0,true,false, false);
//
//glFR->PrintLine();
//
//DM->DocT->First();
//while(!DM->DocT->Eof)
//        {
//
//		if (glFR->PrintString(DM->DocTNAMENOM->AsString,1,0,0,true,false, false)==true){Res=true;}else{ Res=false;}
//        StrPr="";
//        StrPr=" "+FloatToStrF(DM->DocTPRICE_DREALROZNT->AsFloat,ffFixed,15,2)
//                +" x "+FloatToStr(DM->DocTKOL_DREALROZNT->AsFloat)+" "
//				+DM->DocTNAMEED->AsString+" = "
//                +FloatToStrF(DM->DocTSUM_DREALROZNT->AsFloat,ffFixed,15,2);
//        //StrPr=DopStrL(StrPr," ",35);
//
//		if(glFR->PrintString(StrPr,1,0,2,true,false, false)==true) {Res=true;}else {Res=false;}
//
//		DM->DocT->Next();
//		}
//
//
//
//
//glFR->PrintLine();
//glFR->PrintString(DM->DocAllFNAME_USER->AsString,1,0,0,true,false, false);
//
//
//glFR->PrintString("Подпись продавца ___________________",1,0,0,true,false, false);
//glFR->PrintString(" ",1,0,0,true,false, false);
//glFR->PrintString(" ",1,0,0,true,false, false);
//glFR->PrintString(" ",1,0,0,true,false, false);
//glFR->PrintString("Подпись покупателя __________________",1,0,0,true,false, false);
//glFR->PrintString(" ",1,0,0,true,false, false);
//glFR->PrintString(" ",1,0,0,true,false, false);
//glFR->CloseNoFiscalCheck();
//
//glFR->Cut(1);
return Res;
}
//-----------------------------------------------------------------------------



void __fastcall TFormaDocRealRoznForCashier::ToolButtonPrintOnFRClick(
      TObject *Sender)
{
PrintDocOnFR();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRoznForCashier::ToolButtonAddGrafikPlatClick(
      TObject *Sender)
{
IDMSprDogovor * DMSprDogovor;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprDogovor1",IID_IDMSprDogovor,
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
						cxPageControl1->ActivePage=cxTabSheet2;
						cxGrid2->Focused();
						break;
                        }

//   - 1 равными долями каждый месяц до указанной даты

//   - 3 в течении отсрочки платежа (отсрочка в днях)

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
						cxPageControl1->ActivePage=cxTabSheet2;
						cxGrid2->Focused();
                        break;
                        }
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
//---------------------------------------------------------------------------


void __fastcall TFormaDocRealRoznForCashier::NameKlientcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;
OpenFormSpiskaSprKlient();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRoznForCashier::NameDogovorcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprDogovor();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRoznForCashier::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;

        OpenFormSpiskaSprNom();
        EditRekvisit=ViborTovar;

}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRoznForCashier::cxGrid1DBTableView1NAMEEDPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;

        OpenFormSpiskaSprEd();
        EditRekvisit=ViborEdinica;

}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRoznForCashier::OpenHelpExecute(TObject *Sender)
{
Application->HelpJump("DocRealRozn");	
}
//---------------------------------------------------------------------------
void TFormaDocRealRoznForCashier::OpenFormSpiskaSprProject(void)
{
if (Prosmotr==true) return;
if (SpisokProject==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprProject.1",IID_IFormaSpiskaSprProject,
													(void**)&SpisokProject);
		SpisokProject->Init(InterfaceMainObject,InterfaceImpl);
		SpisokProject->Vibor=true;
		SpisokProject->UpdateForm();
		SpisokProject->NumberProcVibor=ViborProject;
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocRealRoznForCashier::EndViborProject(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDPROJECT_GALLDOC->AsString=SpisokProject->DM->TableID_SPROJECT->AsString;
	DM->DocAllNAME_SPROJECT->AsString=SpisokProject->DM->TableNAME_SPROJECT->AsString;
	DM->DocAll->Post();

FindNextControl(ActiveControl,true,true,false)->SetFocus();

}

//---------------------------------------------------------------------------


void __fastcall TFormaDocRealRoznForCashier::NameProjectcxDBButtonEditPropertiesButtonClick(
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
		DM->DocAll->Edit();
		DM->DocAllIDPROJECT_GALLDOC->Clear();
		DM->DocAll->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRoznForCashier::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRoznForCashier::ActionOKExecute(TObject *Sender)
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

void __fastcall TFormaDocRealRoznForCashier::ActionSaveExecute(TObject *Sender)
{
if (Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{

		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRoznForCashier::ActionDvRegExecute(TObject *Sender)
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
		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------


