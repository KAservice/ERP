//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

//---------------------------------------------------------------------------
#include "UFormaDocPlatPor.h"
//#include "UPrintFormDocPLP.h"
#include "USheetEditor.h"
#include "IDMSprBankSchet.h"
#include "IDMSprBank.h"
#include "IDMSprRaschSchet.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtonEdit"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxEdit"
#pragma link "cxLabel"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxCalendar"
#pragma link "cxDropDownEdit"
#pragma link "cxGraphics"
#pragma link "cxButtons"
#pragma link "cxCalc"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxImageComboBox"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaDocPlatPor::TFormaDocPlatPor(TComponent* Owner)
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
bool TFormaDocPlatPor::Init(void)
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


InterfaceGlobalCom->kanCreateObject(ProgId_DMDocPlP,IID_IDMDocPlP,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи


DBTextFNameUser->DataSource=DM->DataSourceDocAll;


NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NumDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;
SumDoccxDBCalcEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameProjectcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameBusinessOpercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PrefiksNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;

NameBSchetcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
NameRSchetcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
SrokPlatcxDBDateEdit->DataBinding->DataSource=DM->DataSourceDoc;
OchercxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
NasnPlatcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
OperationcxDBImageComboBox->DataBinding->DataSource=DM->DataSourceDoc;

NalStatuscxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
NalOsncxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
NalNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
NalTPlatcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
NalKBKcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
NalOKATOcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
NalPeriodcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
NalDatecxDBDateEdit->DataBinding->DataSource=DM->DataSourceDoc;

flObrabatChangeOperation=false;
flObrabatChangeVidPlat=false;


//заполним список внешних модулей

InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
												 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaDocPlatPorImpl),false);
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
int TFormaDocPlatPor::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaDocPlatPor::UpdateForm(void)
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

flObrabatChangeVidPlat=false;

VidPlat->ItemIndex=DM->DocVIDPLP->AsInteger;

flObrabatChangeVidPlat=true;

}
//---------------------------------------------------------------------------
void __fastcall TFormaDocPlatPor::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokFirm)SpisokFirm->kanRelease();
if(SpisokKlient)SpisokKlient->kanRelease();
if(SpisokBSchet)SpisokBSchet->kanRelease();
if(SpisokRSchet)SpisokRSchet->kanRelease();
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
Action=caFree;
}
//---------------------------------------------------------------------------

int TFormaDocPlatPor::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

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
        }

if (number_procedure_end==ER_Klient)//EditRekvisit==ViborKlient)
        {
		if (type_event==1)
                {
                DM->DocAll->Edit();
				DM->DocAllIDKLDOC->AsString=SpisokKlient->DM->ElementIDKLIENT->AsString;
				DM->DocAllNAMEKLIENT->AsString=SpisokKlient->DM->ElementNAMEKLIENT->AsString;
                DM->DocAll->Post();
                DM->Doc->Edit();
                DM->Doc->Post();
                }
        SpisokKlient=0;
        }

if (number_procedure_end==ER_BSchet)//EditRekvisit==ViborBSchet)
        {
		if (type_event==1)
                {
				__int64 id_bs=SpisokBSchet->DM->TableIDBSCHET->AsInt64;
                if (id_bs!=0)
                        {
                        DM->Doc->Edit();
						DM->DocIDBSCHPLP->AsString=id_bs;
						DM->DocNAMEBSCHET->AsString=SpisokBSchet->DM->TableNAMEBSCHET->AsString;
                        DM->Doc->Post();
                        }
                }
        SpisokBSchet=0;
        }

if (number_procedure_end==ER_KlientRSchet)//EditRekvisit==ViborRSchet)
        {
		if (type_event==1)
                {
				__int64 id_rs=SpisokRSchet->DM->ElementIDRSCHET->AsInt64;
                if (id_rs)
                        {
                        DM->Doc->Edit();
						DM->DocIDRSCHPLP->AsString=id_rs;
                        DM->DocNAMERSCHET->AsString=SpisokRSchet->DM->ElementNAMERSCHET->AsString;
                        DM->Doc->Post();
                        }
                }
        SpisokRSchet=0;
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

	FindNextControl(ActiveControl,true,true,false)->SetFocus();

return -1;
}

//---------------------------------------------------------------------------



void TFormaDocPlatPor::OpenFormSpiskaSprFirm(void)
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
//--------------------------------------------------------------------------
void TFormaDocPlatPor::OpenFormSpiskaSprKlient(void)
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
void TFormaDocPlatPor::OpenFormSpiskaSprBSchet(void)
{
if (Prosmotr==true) return;
if (SpisokBSchet==0)
	{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprBankSchet.1",IID_IFormaSpiskaSprBankSchet,
													(void**)&SpisokBSchet);
		SpisokBSchet->Init(InterfaceMainObject,InterfaceImpl);
		SpisokBSchet->NumberProcVibor=ER_BSchet;
		SpisokBSchet->Vibor=true;
		SpisokBSchet->DM->IdFirm=glStrToInt64(DM->DocAllIDFIRMDOC->AsString);
        SpisokBSchet->DM->OpenTable();
		//SpisokBSchet->LabelFirma->Caption="Фирма: "+DM->DocAllNAMEFIRM->AsString;
	}
}
//-------------------------------------------------------------------------
void TFormaDocPlatPor::OpenFormSpiskaSprRSchet(void)
{
if (Prosmotr==true) return;
if(SpisokRSchet==0)
	{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprRaschSchet.1",IID_IFormaSpiskaSprRaschSchet,
													(void**)&SpisokRSchet);
		SpisokRSchet->Init(InterfaceMainObject,InterfaceImpl);
		SpisokRSchet->NumberProcVibor=ER_KlientRSchet;
		SpisokRSchet->Vibor=true;
		SpisokRSchet->DM->OpenTable(glStrToInt64(DM->DocAllIDKLDOC->AsString));
        //SpisokRSchet->LabelKlient->Caption="Контрагент: "+DM->DocAllNAMEKLIENT->AsString;
		SpisokRSchet->IdKlient=DM->DocAllIDKLDOC->AsInteger;
	}

}
//--------------------------------------------------------------------------


void  TFormaDocPlatPor::PrintDoc(void)
{
TSheetEditor  *prForm=new TSheetEditor(Application);
if (!prForm) return;
numRow=1;
numCol=1;

TcxSSCellObject *cell;
prForm->SS->BeginUpdate();

prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";
prForm->SS->RowsAutoHeight=false;
prForm->SS->DefaultColWidth=19;
prForm->SS->DefaultRowHeight=16;
prForm->SS->ShowGrid=false;
        TcxSSHeader *cHeader;
        cHeader = prForm->SS->ActiveSheet->Cols;
for(int i=0;i<2;i++)
        {
        cHeader->Size[i] = 10;
        }

numCol=2;
for(int i=0;i<7;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;
        }
numCol++;
for(int i=0;i<8;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;
        }

numCol=33;
TRect rect;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+4;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="0401060";
cell->Style->HorzTextAlign = haCENTER;
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
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;
numCol++;

numRow++;
//************
numCol=2;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+6;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Поступ. в банк плат";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
delete cell;
numCol=10;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+7;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Списано со сч. плат.";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
delete cell;
numRow++;
//*************
cell = prForm->SS->ActiveSheet->GetCellObject(36, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(37, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;
numRow++;
//**************
numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="ПЛАТЕЖНОЕ ПОРУЧЕНИЕ №"+DM->DocAllNUMDOC->AsString;
cell->Style->Font->Size = 10;
delete cell;

numCol=16;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+6;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DateToStr(DM->DocAllPOSDOC->AsDateTime);
cell->Style->HorzTextAlign = haCENTER;
delete cell;

for(int i=0;i<7;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;
        }

numCol=24;
		rect.Left = numCol;
		rect.Top = numRow;
		rect.Right = numCol+6;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=VidPlat->Text;
cell->Style->HorzTextAlign = haCENTER;
delete cell;

for(int i=0;i<7;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;
        }

rect.Left = 36;
rect.Top = numRow-1;
rect.Right = 37;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(36, numRow-1);
cell->Text=DM->DocNALOG_STATUS_PLP->AsString;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(36, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(37, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

numRow++;
//********************************
numCol=16;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+6;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Дата";
cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 8;
delete cell;

numCol=24;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+6;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Вид платежа";
cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Size = 8;
delete cell;

numRow++;
//*********************
numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Сумма";
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Text="прописью";
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(5, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(5, numRow+1);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(5, numRow+2);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

numCol=6;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+31;
        rect.Bottom = numRow+2;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=glCurrencyPropis(DM->DocAllSUMDOC->AsFloat);
cell->Style->WordBreak = true;
delete cell;

numRow=numRow+3;
IDMSprFirm * DMSFirm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
												 (void**)&DMSFirm);
DMSFirm->Init(InterfaceMainObject,InterfaceImpl);
DMSFirm->OpenElement(DM->DocAllIDFIRMDOC->AsInteger);
//**********************
numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="ИНН  "+DMSFirm->ElementINNFIRM->AsString;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
for(int i=0;i<8;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        delete cell;
        numCol++;
        }


cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="КПП  "+DMSFirm->ElementKPPFIRM->AsString;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
for(int i=0;i<8;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        delete cell;
        numCol++;
        }


cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Text="Сумма";
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;
numCol++;

		rect.Left = numCol;
		rect.Top = numRow;
		rect.Right = numCol+12;
		rect.Bottom = numRow;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
AnsiString text=FloatToStrF(DM->DocAllSUMDOC->AsFloat,ffFixed,14,2);
text=glConvertString(text,",","-");
text=glConvertString(text,".","-");
cell->Text=text;
cell->Style->HorzTextAlign = haLEFT;
delete cell;
for(int i=0;i<13;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        delete cell;
        numCol++;
        }

numRow++;
//*****************
numCol=2;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+19;
        rect.Bottom = numRow+3;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DMSFirm->ElementFNAMEFIRM->AsString;
cell->Style->WordBreak = true;
cell->Style->VertTextAlign = vaTOP;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+4);
cell->Text="Плательщик";
//cell->Style->Font->Size = 8;
delete cell;

//горизонтальные линии
numCol=22;
numRow=11;
for(int i=0;i<16;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;
        }


numCol=2;
numRow=14;
for(int i=0;i<23;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;
        }

numCol=2;
numRow=17;
for(int i=0;i<36;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;
        }

numCol=2;
numRow=20;
for(int i=0;i<23;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;
        }

numCol=2;
numRow=21;
for(int i=0;i<20;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;
        }

numCol=22;
numRow=23;
for(int i=0;i<16;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;
        }

numCol=2;
numRow=26;
for(int i=0;i<36;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;
        }

numCol=2;
numRow=27;
for(int i=0;i<36;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;
        }

numCol=2;
numRow=33;
for(int i=0;i<36;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;
        }

//вертикальные линии
numCol=22;
numRow=9;
for(int i=0;i<18;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        delete cell;
        numRow++;
        }

numCol=25;
numRow=9;
for(int i=0;i<18;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        delete cell;
        numRow++;
        }


IDMSprBankSchet * DMSprBankSchet;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprBankSchet.1",IID_IDMSprBankSchet,
												 (void**)&DMSprBankSchet);
DMSprBankSchet->Init(InterfaceMainObject,InterfaceImpl);
DMSprBankSchet->OpenElement(glStrToInt64(DM->DocIDBSCHPLP->AsString));

cell = prForm->SS->ActiveSheet->GetCellObject(22, 12);
cell->Text="Сч. №";
delete cell;

		rect.Left = 25;
		rect.Top = 12;
		rect.Right = 37;
		rect.Bottom = 12;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(25, 12);
cell->Text=DMSprBankSchet->ElementNUMBSCHET->AsString;
cell->Style->HorzTextAlign = haLEFT;
delete cell;

IDMSprBank *DMSprBank;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprBank.1",IID_IDMSprBank,
												 (void**)&DMSprBank);
DMSprBank->Init(InterfaceMainObject,InterfaceImpl);
DMSprBank->OpenElement(DMSprBankSchet->ElementIDBANKBSCHET->AsInt64);

// "Банк плательщика";
numCol=2;
numRow=15;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+19;
        rect.Bottom = numRow+1;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DMSprBank->ElementNAMEBANK->AsString+ " "+DMSprBank->ElementGORBANK->AsString;
cell->Style->WordBreak = true;
cell->Style->VertTextAlign = vaTOP;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+2);
cell->Text="Банк плательщика";
//cell->Style->Font->Size = 8;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(22,15);
cell->Text="БИК";
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(23,15);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(24,15);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(25,15);
cell->Text=DMSprBank->ElementBIKBANK->AsString;
cell->Style->HorzTextAlign = haLEFT;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(22,16);
cell->Text="Сч. №";

delete cell;
		rect.Left = 25;
		rect.Top = 16;
		rect.Right = 37;
		rect.Bottom = 16;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(25,16);
cell->Text=DMSprBank->ElementKSBANK->AsString;
cell->Style->HorzTextAlign = haLEFT;
delete cell;

IDMSprKlient * DMSprKlient;
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprKlient,IID_IDMSprKlient,
												 (void**)&DMSprKlient);
DMSprKlient->Init(InterfaceMainObject,InterfaceImpl);
DMSprKlient->OpenElement(glStrToInt64(DM->DocAllIDKLDOC->AsString));
//в строке не более 60 символов
IDMSprRaschSchet *DMSprRaschSchet;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprRaschSchet.1",IID_IDMSprRaschSchet,
												 (void**)&DMSprRaschSchet);
DMSprRaschSchet->Init(InterfaceMainObject,InterfaceImpl);
DMSprRaschSchet->OpenElement(glStrToInt64(DM->DocIDRSCHPLP->AsString));


//наименование банка
DMSprBank->OpenElement(DMSprRaschSchet->ElementIDBANKRSCHET->AsInt64);

// "Банк получателя";
numCol=2;
numRow=18;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+19;
        rect.Bottom = numRow+1;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DMSprBank->ElementNAMEBANK->AsString+ " "+DMSprBank->ElementGORBANK->AsString;
cell->Style->WordBreak = true;
cell->Style->VertTextAlign = vaTOP;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+2);
cell->Text="Банк получателя";
//cell->Style->Font->Size = 8;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(22,18);
cell->Text="БИК";
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(23,18);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(24,18);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(25,18);
cell->Text=DMSprBank->ElementBIKBANK->AsString;
cell->Style->HorzTextAlign = haLEFT;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(22,19);
cell->Text="Сч. №";
delete cell;

		rect.Left = 25;
		rect.Top = 19;
		rect.Right = 37;
		rect.Bottom = 19;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(25,19);
cell->Text=DMSprBank->ElementKSBANK->AsString;
cell->Style->HorzTextAlign = haLEFT;
delete cell;


cell = prForm->SS->ActiveSheet->GetCellObject(2, 21);
cell->Text="ИНН "+DMSprKlient->ElementINNKLIENT->AsString;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(12, 21);
cell->Text="КПП "+DMSprKlient->ElementKPPKLIENT->AsString;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
delete cell;


cell = prForm->SS->ActiveSheet->GetCellObject(22, 21);
cell->Text="Сч. №";
delete cell;

		rect.Left = 25;
		rect.Top = 21;
		rect.Right = 37;
		rect.Bottom = 21;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(25, 21);
cell->Text=DMSprRaschSchet->ElementNUMRSCHET->AsString;
cell->Style->HorzTextAlign = haLEFT;
delete cell;

//наименование получателя

numCol=2;
numRow=22;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+19;
        rect.Bottom = numRow+3;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DMSprKlient->ElementFNAME->AsString;
cell->Style->WordBreak = true;
cell->Style->VertTextAlign = vaTOP;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+4);
cell->Text="Получатель";
//cell->Style->Font->Size = 8;
delete cell;



cell = prForm->SS->ActiveSheet->GetCellObject(33, 25);
cell->Text=DM->DocOCHPLP->AsString;
delete cell;



numCol=2;
numRow=28;
		rect.Left = numCol;
		rect.Top = numRow;
		rect.Right = numCol+35;
		rect.Bottom = numRow+4;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocNASNPLP->AsString;
cell->Style->WordBreak = true;
cell->Style->VertTextAlign = vaCENTER;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+5);
cell->Text="Назначение платежа";
//cell->Style->Font->Size = 8;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(20, 34);
cell->Text="Подписи";
//cell->Style->Font->Size = 8;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(28, 34);
cell->Text="Отметки банка";
//cell->Style->Font->Size = 8;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(6, 37);
cell->Text="М.П.";
//cell->Style->Font->Size = 8;
delete cell;

numCol=13;
numRow=36;
for(int i=0;i<11;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;
        }

numCol=13;
numRow=39;
for(int i=0;i<11;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;
		}

rect.Left = 2;
rect.Top = 27;
rect.Right = 10;
rect.Bottom = 27;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(2, 27);
cell->Text=DM->DocNALOG_KBK_PLP->AsString;
cell->Style->HorzTextAlign = haCENTER;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(10, 27);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

rect.Left = 11;
rect.Top = 27;
rect.Right = 16;
rect.Bottom = 27;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(11, 27);
cell->Text=DM->DocNALOG_OKATO_PLP->AsString;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(16, 27);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

rect.Left = 17;
rect.Top = 27;
rect.Right = 18;
rect.Bottom = 27;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(17, 27);
cell->Text=DM->DocNALOG_OSN_PLP->AsString;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(18, 27);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

rect.Left = 19;
rect.Top = 27;
rect.Right = 23;
rect.Bottom = 27;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(19, 27);
cell->Text=DM->DocNALOG_PERIOD_PLP->AsString;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(23, 27);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

rect.Left = 24;
rect.Top = 27;
rect.Right = 30;
rect.Bottom = 27;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(24, 27);
cell->Text=DM->DocNALOG_NUM_PLP->AsString;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(30, 27);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;


rect.Left = 31;
rect.Top = 27;
rect.Right = 35;
rect.Bottom = 27;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(31, 27);
cell->Text=DM->DocNALOG_DATE_PLP->AsString;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(35, 27);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

rect.Left = 36;
rect.Top = 27;
rect.Right = 37;
rect.Bottom = 27;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(36, 27);
cell->Text=DM->DocNALOG_TPLAT_PLP->AsString;
cell->Style->HorzTextAlign = haCENTER;
delete cell;


numCol=22;
numRow=24;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+2;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haCENTER;
cell->Text="Вид оп.";
//cell->Style->Font->Size = 8;
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
cell->Style->HorzTextAlign = haCENTER;
cell->Text="01";
delete cell;

numCol=22;
numRow++;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+2;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haCENTER;
cell->Text="Наз. пл.";
//cell->Style->Font->Size = 8;
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

numCol=22;
numRow++;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+2;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haCENTER;
cell->Text="Код";
//cell->Style->Font->Size = 8;
delete cell;

numCol=29;
numRow=24;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+3;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->HorzTextAlign = haCENTER;
cell->Text="Срок плат.";
//cell->Style->Font->Size = 8;
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
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

numRow++;
numCol=29;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+3;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haCENTER;
cell->Text="Очер. плат.";
//cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
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
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;
numRow++;
numCol=29;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+3;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haCENTER;
cell->Text="Рез. поле";
//cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol+3, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;


//PrintForm->F1->ShowGridLines=false;
prForm->SS->EndUpdate();
prForm->Show();

DMSprRaschSchet->kanRelease();
DMSprBankSchet->kanRelease();
DMSprBank->kanRelease();
DMSFirm->kanRelease();
DMSprKlient->kanRelease();
}
//---------------------------------------------------------------------------
void TFormaDocPlatPor::OpenFormSpiskaSprInfBase(void)
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

void __fastcall TFormaDocPlatPor::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("DocPlatPor");
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPlatPor::N1Click(TObject *Sender)
{
ToolBar1->SetFocus();
DM->Doc->Edit();
DM->DocNASNPLP->AsString=DM->DocNASNPLP->AsString+"Сумма:"
			+FloatToStrF(DM->DocAllSUMDOC->AsFloat,ffFixed,15,2)+".";
DM->Doc->Post();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPlatPor::N181Click(TObject *Sender)
{
ToolBar1->SetFocus();
DM->Doc->Edit();
DM->DocNASNPLP->AsString=DM->DocNASNPLP->AsString+"Сумма:"
			+FloatToStrF(DM->DocAllSUMDOC->AsFloat,ffFixed,15,2)
			+". В том числе НДС 18% "
			+FloatToStrF((DM->DocAllSUMDOC->AsFloat/118)*18,ffFixed, 12,2)
			+".";
DM->Doc->Post();
}
//---------------------------------------------------------------------------



void __fastcall TFormaDocPlatPor::NameInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprInfBase();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPlatPor::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprFirm();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPlatPor::NameBSchetcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprBSchet();	
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocPlatPor::NameKlientcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprKlient();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPlatPor::cxDBButtonEdit1PropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprRSchet();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPlatPor::VidPlatPropertiesChange(TObject *Sender)
{
if(flObrabatChangeVidPlat==false) return;
DM->Doc->Edit();
DM->DocVIDPLP->AsInteger=VidPlat->ItemIndex;
DM->Doc->Post();
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------










void __fastcall TFormaDocPlatPor::NumDoccxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPlatPor::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------



void __fastcall TFormaDocPlatPor::SrokPlatcxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPlatPor::OchercxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPlatPor::SumDoccxDBCalcEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPlatPor::NasnPlatcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------



void __fastcall TFormaDocPlatPor::NalStatuscxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPlatPor::NalOsncxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPlatPor::NalNumcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPlatPor::NalTPlatcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPlatPor::NalKBKcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPlatPor::NalOKATOcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPlatPor::NalPeriodcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPlatPor::NalDatecxDBDateEditKeyDown(TObject *Sender,
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
void __fastcall TFormaDocPlatPor::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaDocPlatPor::RunExternalModule(__int64 id_module, int type_module)
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
void __fastcall TFormaDocPlatPor::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPlatPor::ActionOKExecute(TObject *Sender)
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

void __fastcall TFormaDocPlatPor::ActionDvRegExecute(TObject *Sender)
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

void __fastcall TFormaDocPlatPor::ActionSaveExecute(TObject *Sender)
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

void __fastcall TFormaDocPlatPor::ActionPrintExecute(TObject *Sender)
{
PrintDoc();
}
//---------------------------------------------------------------------------
void TFormaDocPlatPor::OpenFormSpiskaSprProject(void)
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
void __fastcall TFormaDocPlatPor::EndViborProject(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDPROJECT_GALLDOC->AsString=SpisokProject->DM->TableID_SPROJECT->AsString;
	DM->DocAllNAME_SPROJECT->AsString=SpisokProject->DM->TableNAME_SPROJECT->AsString;
	DM->DocAll->Post();




}
//----------------------------------------------------------------------------
void TFormaDocPlatPor::OpenFormSpiskaSprBusinessOper(void)
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
void __fastcall TFormaDocPlatPor::EndViborBusinessOper(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDBUSINOP_GALLDOC->AsString=SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString;
	DM->DocAllNAME_SBUSINESS_OPER->AsString=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;
	DM->DocAll->Post();

}
//----------------------------------------------------------------------------
void __fastcall TFormaDocPlatPor::NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
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

void __fastcall TFormaDocPlatPor::NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
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

