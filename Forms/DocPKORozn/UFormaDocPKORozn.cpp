//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

//----------------------------------------------------------------------------
#include "UFormaDocPKORozn.h"
#include "USheetEditor.h"
#include "IDMSprFirm.h"
#include "IDMSprKlient.h"
#include "IFiskReg.h"
#include "IDMSprOborud.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxEdit"
#pragma link "cxLabel"
#pragma link "cxPC"
#pragma link "cxTextEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxGraphics"
#pragma link "cxMaskEdit"
#pragma link "cxCalc"
#pragma link "cxButtonEdit"
#pragma link "cxCalendar"
#pragma link "cxImageComboBox"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaDocPKORozn::TFormaDocPKORozn(TComponent* Owner)
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
bool TFormaDocPKORozn::Init(void)
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


InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPKORozn.1",IID_IDMDocPKORozn,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи


DBTextFNameUser->DataSource=DM->DataSourceDocAll;


NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameKKMcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
NumDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameDogovorcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PrOtcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
OsncxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
PrimcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
SumDoccxDBCalcEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameProjectcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameBusinessOpercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PrefiksNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;

ModelcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
SavNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
RegNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
NKLcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
NCheckcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
OpercxDBImageComboBox->DataBinding->DataSource=DM->DataSourceDoc;
NameCardcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;

flObrabatChangeOperation=false;


//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
												 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaDocPKORoznImpl),false);
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
int TFormaDocPKORozn::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaDocPKORozn::UpdateForm(void)
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

}
//---------------------------------------------------------------------------
void __fastcall TFormaDocPKORozn::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokFirm)SpisokFirm->kanRelease();
if(SpisokKlient)SpisokKlient->kanRelease();
if(SpisokKKM)SpisokKKM->kanRelease();
if(FormaSpiskaSprDogovor)FormaSpiskaSprDogovor->kanRelease();
if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
if(FormaSpiskaSprDiscountCard)FormaSpiskaSprDiscountCard->kanRelease();
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

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}

}
//---------------------------------------------------------------------------

int TFormaDocPKORozn::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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
                DM->DocPROT_DPKOROZN->AsString=SpisokKlient->DM->ElementFNAME->AsString;
                DM->Doc->Post();
                }
        SpisokKlient=0;
        }

if (number_procedure_end==ER_Kassa)//EditRekvisit==ViborKKM)
        {
		if (type_event==1)
                {
                DM->Doc->Edit();
				DM->DocIDKKM_DPKOROZN->AsString=SpisokKKM->DM->ElementIDKKM->AsString;
                DM->DocNAMEKKM->AsString=SpisokKKM->DM->ElementNAMEKKM->AsString;
                DM->Doc->Post();
                }
        SpisokKKM=0;
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
		}


if (number_procedure_end==ER_Card)
	{
	if(type_event==1)
		{
        EndViborCard();
		}
	FormaSpiskaSprDiscountCard=0;
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



void TFormaDocPKORozn::OpenFormSpiskaSprFirm(void)
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
void TFormaDocPKORozn::OpenFormSpiskaSprKlient(void)
{
if (Prosmotr==true) return;
if(SpisokKlient==0)
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
void TFormaDocPKORozn::OpenFormSpiskaSprKKM(void)
{
if (Prosmotr==true) return;
if(SpisokKKM==0)
	{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKKM.1",IID_IFormaSpiskaSprKKM,
													(void**)&SpisokKKM);
		SpisokKKM->Init(InterfaceMainObject,InterfaceImpl);
		SpisokKKM->NumberProcVibor= ER_Kassa;
        SpisokKKM->Vibor=true;
	}

}
//--------------------------------------------------------------------------



void TFormaDocPKORozn::PrintDoc(void)
{
TSheetEditor *prForm=new TSheetEditor(Application);
if (!prForm) return;
numRow=1;
numCol=1;

prForm->SS->BeginUpdate();

prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";
prForm->SS->RowsAutoHeight=true;
        TcxSSHeader *cHeader;

        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 10;
        cHeader->Size[2] = 50;
        cHeader->Size[3] = 30;
        cHeader->Size[4] = 80;
        cHeader->Size[5] = 70;
        cHeader->Size[6] = 60;
        cHeader->Size[7] = 40;
        cHeader->Size[8] = 40;
        cHeader->Size[9] = 30;
        cHeader->Size[10] =30;
        cHeader->Size[11] = 50;
        cHeader->Size[12] = 5;
        cHeader->Size[13] = 5;
        cHeader->Size[14] = 3;
        cHeader->Size[15] = 200;

TcxSSCellObject *cell;
cell = prForm->SS->ActiveSheet->GetCellObject(11, 0);
cell->Text="Унифицированная форма № КО-1";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 6;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(13, 0);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(11,1);
cell->Text="Утверждена постановлением Госкомстата";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 6;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(13, 1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(11, 2);
cell->Text="России от 18.08.98 г. № 88";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 6;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(13, 2);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

numRow=3;
numCol=10;

        TRect rect;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+1;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Text="Коды";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(13, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

numRow++;
numCol=10;

        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+1;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="0310001";
cell->Style->HorzTextAlign = haCENTER;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(13, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

numRow++;
numCol=2;

        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+5;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

IDMSprFirm * DMSFirm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
												 (void**)&DMSFirm);
DMSFirm->Init(InterfaceMainObject,InterfaceImpl);
DMSFirm->OpenElement(glStrToInt64(DM->DocAllIDFIRMDOC->AsString));

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text=DMSFirm->ElementFNAMEFIRM->AsString;
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
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
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(13, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

numCol=10;

        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+1;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(13, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

numCol=2;
numRow++;

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
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(13, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;


numCol=10;

        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+1;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(13, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

numRow++;
prForm->SS->ActiveSheet->Rows->Size[numRow]=10;
cell = prForm->SS->ActiveSheet->GetCellObject(13, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;
numRow++;


numCol=8;

        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+1;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);


cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Номер документа";
cell->Style->Font->Size = 8;
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+1;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);


cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Дата составления";
cell->Style->Font->Size = 8;
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(13, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

numRow++;

numCol=8;

        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+1;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);


cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocAllNUMDOC->AsString;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;

        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+1;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);


cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DateToStr(DM->DocAllPOSDOC->AsDateTime);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(13, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

numRow++;
prForm->SS->ActiveSheet->Rows->Size[numRow]=10;
cell = prForm->SS->ActiveSheet->GetCellObject(13, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;
numRow++;

numCol=2;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol;
        rect.Bottom = numRow+1;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Text = "Дебет";
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol;
        rect.Bottom = numRow+1;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
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
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text = "Кредит";
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol+1, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol+2, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text = "Код струк- турного под- разделения";
cell->Style->Font->Size = 8;
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol+1, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text = "Корреспон- дирующий счет, субсчет";
cell->Style->Font->Size = 8;
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol+2, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text = "Код аналити- ческого учета";
cell->Style->Font->Size = 8;
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
delete cell;

numCol++;numCol++;numCol++;

        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+1;
        rect.Bottom = numRow+1;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Text = "Сумма руб.коп.";
cell->Style->Font->Size = 8;
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol+1, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol+1, numRow+1);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

numCol++;numCol++;

        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+1;
        rect.Bottom = numRow+1;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Text = "Код";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol+1, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol+1, numRow+1);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

numCol++;numCol++;

        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol;
        rect.Bottom = numRow+1;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(13, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(13, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

numRow++;numRow++;

numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
cell->Text = "50.1";
delete cell;

numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;

        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+1;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
cell->Style->HorzTextAlign = haRIGHT;
cell->Text=FloatToStrF(DM->DocAllSUMDOC->AsFloat, ffFixed,14,2);
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;

delete cell;
numCol++;

        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+1;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(13, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;


numRow++;

numCol=2;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+9;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Принято от "+DM->DocPROT_DPKOROZN->AsString;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(13, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

numRow++;

numCol=2;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+9;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Основание: "+DM->DocOSN_DPKOROZN->AsString;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(13, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

numRow++;

numCol=2;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+9;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Сумма: "+glCurrencyPropis(DM->DocAllSUMDOC->AsFloat);
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(13, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

numRow++;

numCol=2;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+9;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Приложение: "+DM->DocPRIM_DPKOROZN->AsString;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(13, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(13, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;
numRow++;

numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Главный бухгалтер";
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
delete cell;

numCol++; numCol++;numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;

numCol++;numCol++;

        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+3;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text=DMSFirm->ElementBUHFIRM->AsString;
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
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
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(13, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

numRow++;
prForm->SS->ActiveSheet->Rows->Size[numRow]=15;
cell = prForm->SS->ActiveSheet->GetCellObject(13, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

numCol=5;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+1;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="подпись";
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaTOP;
delete cell;

numCol=8;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+3;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="расшифровка подписи";
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaTOP;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(13, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(13, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Получил кассир";
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 10;
delete cell;

numCol++; numCol++;numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

//numCol++;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;

numCol++;numCol++;

        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+3;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text=DMSFirm->ElementKASFIRM->AsString;
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
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
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(13, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

numRow++;
prForm->SS->ActiveSheet->Rows->Size[numRow]=15;
cell = prForm->SS->ActiveSheet->GetCellObject(13, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

numCol=5;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+1;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="подпись";
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaTOP;
delete cell;

numCol=8;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+3;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="расшифровка подписи";
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaTOP;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(13, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

//cell = prForm->SS->ActiveSheet->GetCellObject(9,26);
//cell->Text=DMSFirm->ElementBUHFIRM->AsString;
//delete cell;

//cell = prForm->SS->ActiveSheet->GetCellObject(9,28);
//cell->Text=DMSFirm->ElementKASFIRM->AsString;
//delete cell;

//квитанция

numCol=15;
numRow=0;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol;
        rect.Bottom = numRow+2;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DMSFirm->ElementFNAMEFIRM->AsString;
cell->Style->Font->Size = 8;
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaTOP;
delete cell;

numRow++;numRow++;numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(15,numRow);
cell->Text=DMSFirm->ElementINNFIRM->AsString+"/"+DMSFirm->ElementKPPFIRM->AsString;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol,numRow);
cell->Text="КВИТАНЦИЯ";
cell->Style->HorzTextAlign = haCENTER;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol,numRow);
cell->Text="к приходному кассовому ордеру";
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
numRow++;



cell = prForm->SS->ActiveSheet->GetCellObject(numCol,numRow);
cell->Text="№"+DM->DocAllNUMDOC->AsString+" от "+DateToStr(DM->DocAllPOSDOC->AsDateTime);
cell->Style->HorzTextAlign = haCENTER;
delete cell;

numRow++;

        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol;
        rect.Bottom = numRow+1;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);


cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Принято от "+DM->DocPROT_DPKOROZN->AsString;
cell->Style->WordBreak = true;
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;

numRow++; numRow++; 

        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol;
        rect.Bottom = numRow+2;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Основание: "+DM->DocOSN_DPKOROZN->AsString;
cell->Style->WordBreak = true;
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->VertTextAlign = vaCENTER;
delete cell;

numRow++; numRow++; numRow++;


cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Сумма: "+FloatToStrF(DM->DocAllSUMDOC->AsFloat, ffFixed,14,2);
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->VertTextAlign = vaBOTTOM;
cell->Style->Font->Size = 10;
delete cell;

numRow++;

        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol;
        rect.Bottom = numRow+2;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(15,numRow);
cell->Text=glCurrencyPropis(DM->DocAllSUMDOC->AsFloat);
cell->Style->WordBreak = true;
cell->Style->Font->Size = 8;
cell->Style->VertTextAlign = vaTOP;
delete cell;
numRow++; numRow++;numRow++;


cell = prForm->SS->ActiveSheet->GetCellObject(numCol,numRow);
cell->Text=DateToStr(DM->DocAllPOSDOC->AsDateTime);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Style = TFontStyles() << fsBold;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol,numRow);
cell->Text="М.П.(штампа)";
cell->Style->Font->Size = 8;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol,numRow);
cell->Text="Главный бухгалтер";
cell->Style->Font->Size = 8;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol,numRow);
cell->Text=DMSFirm->ElementBUHFIRM->AsString;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Font->Size = 8;
delete cell;
numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol,numRow);
cell->Text="расшифровка подписи";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
delete cell;
numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol,numRow);
cell->Text="Кассир";
cell->Style->Font->Size = 8;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol,numRow);
cell->Text=DMSFirm->ElementKASFIRM->AsString;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Font->Size = 8;
delete cell;
numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol,numRow);
cell->Text="расшифровка подписи";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
delete cell;


prForm->SS->EndUpdate();
prForm->Show();



DMSFirm->kanRelease();
}
//---------------------------------------------------------------------------
void TFormaDocPKORozn::OpenFormSpiskaSprInfBase(void)
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


void TFormaDocPKORozn::OpenFormSpiskaSprDogovor(void)
{
if (DM->DocAllIDKLDOC->AsInteger==0)
        {
        ShowMessage("Выберите контрагента!");
        return;
        }

if (FormaSpiskaSprDogovor==NULL)
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

void __fastcall TFormaDocPKORozn::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("DocPKORozn");
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TFormaDocPKORozn::PrintCheckFR(void)
{
if (Prosmotr==true) return;
if (FormaViborFR==NULL)
        {
		FormaViborFR=new TFormaViborFR(Application);
		FormaViborFR->DM_Connection=DM_Connection;
		FormaViborFR->Init();
		if (!FormaViborFR) return;
		FormaViborFR->IdArm=glStrToInt64(DM_Connection->ARMInfoID_SARM->AsString);
		FormaViborFR->Vibor=true;
		FormaViborFR->UpdateForm();
		FormaViborFR->FOnCloseForm=EndViborFR;
		if (FormaViborFR->DM->Table->RecordCount<=1)
			{
			FormaViborFR->OutReady=true;
			FormaViborFR->Close();
			}
		else
			{
			FormaViborFR->ShowModal();
			}
		} 
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocPKORozn::EndViborFR(TObject *Sender)
{

if (FormaViborFR->OutReady==true)
	{
	FormaViborFR->Visible=false;
	IDMSprOborud *DMSprOborud;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMSprOborud.1",IID_IDMSprOborud,
												 (void**)&DMSprOborud);
	DMSprOborud->Init(InterfaceMainObject,InterfaceImpl);
	DMSprOborud->OpenElement(FormaViborFR->DM->TableID_OBORUD->AsInt64);
	if (DMSprOborud->ElementID_OBORUD->AsInteger>0)
		{
		IFiskReg *fr;
		InterfaceGlobalCom->kanCreateObject("Oberon.FiskReg.1",IID_IFiskReg,
												 (void**)&fr);
		fr->Init(InterfaceMainObject,InterfaceImpl);
		fr->Modul=DMSprOborud->ElementMODUL_SOBORUD->AsString;
		fr->Number=1;
		fr->InitDevice();
		int number_port=0;
		if (DMSprOborud->ElementCOMNAME_OBORUD->AsString!="")
			{
			number_port=StrToFloat(DMSprOborud->ElementCOMNAME_OBORUD->AsString);
			}
		AnsiString baud_rate=DMSprOborud->ElementBAUDRATE_OBORUD->AsString;

		AnsiString password=DMSprOborud->GetParameter("password");
		if(fr->Connect(number_port, baud_rate, password)==true)
			{}
		else
			{
			ShowMessage("Ошибка при подключении фискального регистратора: "+fr->TextError);
			FormaViborFR=0;
			return;
			}

		try
			{
				if(fr->ProvVosmPrintCheck()==false)
					{
					throw Exception("Нет возможности напечатать чек! "+fr->TextError);
					}

				fr->OpenNoFiscalCheck();


				if (DMSprOborud->GetParameter("STR_ZAG_1")!="")
							{
							fr->PrintString(DMSprOborud->GetParameter("STR_ZAG_1"),1,0,0,true,false, false);
							}

				if (DMSprOborud->GetParameter("STR_ZAG_2")!="")
							{
							fr->PrintString(DMSprOborud->GetParameter("STR_ZAG_2"),1,0,0,true,false, false);
							}

				if (DMSprOborud->GetParameter("STR_ZAG_3")!="")
							{
							fr->PrintString(DMSprOborud->GetParameter("STR_ZAG_3"),1,0,0,true,false, false);
							}

				fr->PrintString(" ",1,0,0,true,false, false);


				fr->PrintLine();//("------------------------------------",1,0,0,true,false);
				fr->PrintString(DM->DocOSN_DPKOROZN->AsString,1,0,1,true,false, true);

				fr->PrintLine();//("------------------------------------",1,0,0,true,false);
				fr->PrintString(DM->DocAllFNAME_USER->AsString,1,0,0,true,false, false);

				fr->CloseNoFiscalCheck();

				if (DMSprOborud->GetParameter("UCH")=="YES")
					{
							//0 продажа 1 возврат
							if(fr->PrintNoFiscalCheck(DM->DocAllSUMDOC->AsFloat,  //сумма продажи
													1,                            //отдел
													DM->DocAllSUMDOC->AsFloat,       //наличные
													0,     //банковская карта
													0,     //платежная карта
													0,	   //кредит
													0)==true)
								{}
							else {}

					}
				else
					{
							//0 продажа 1 возврат
							if(fr->PrintFiscalCheck(DM->DocAllSUMDOC->AsFloat,  //сумма продажи
													1,                            //отдел
													DM->DocAllSUMDOC->AsFloat,       //наличные
													0,     //банковская карта
													0,     //платежная карта
													0,	   //кредит
													0)==true)
								{}
							else {}
					}
			//получим номер чека
			fr->GetSostKKM();
			DM->Doc->Edit();
			DM->DocNKL_DPKOROZN->AsInteger=fr->NumberKL;
			DM->DocNCHECK_DPKOROZN->AsInteger=fr->NumberCheck;
			DM->DocREGNUM_DPKOROZN->AsString=fr->RegNumberKKM;
			DM->DocSAVNUM_DPKOROZN->AsString=fr->SerialNumberKKM;
			DM->DocMODEL_DPKOROZN->AsString=fr->ModelKKM;
			DM->Doc->Post();
			}
		catch(Exception &exception)
			{
			ShowMessage("Ошибка! "+exception.Message);
			}
		fr->Disconnect();
		fr->kanRelease();
		}
	else
		{
		ShowMessage("На данном рабочем месте нет подключенных фискальных регистраторов! ");
		}
	DMSprOborud->kanRelease();
	}
FormaViborFR=0;
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocPKORozn::cxButtonprintCheckNaFRClick(TObject *Sender)
{
if (DM->DocNCHECK_DPKOROZN->AsInteger>0)
	{
	String V="Кассовый чек уже пробит! Пробить ещё один?";
	String Z="Внимание!";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
				{
				PrintCheckFR();
				}
	}
else
	{
	PrintCheckFR();
	}
}
//---------------------------------------------------------------------------







void __fastcall TFormaDocPKORozn::nameDogovorcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprDogovor();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPKORozn::NameKlientcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprKlient();	
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocPKORozn::NameKKMcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprKKM();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPKORozn::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprFirm();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPKORozn::NameInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprInfBase();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPKORozn::NumDoccxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPKORozn::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPKORozn::PrOtcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPKORozn::OsncxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPKORozn::PrimcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocPKORozn::SumDoccxDBCalcEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void TFormaDocPKORozn::ViborCard(void)
{ 
if (Prosmotr==true) return;
if (FormaSpiskaSprDiscountCard==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprDiscountCard.1",IID_IFormaSpiskaSprDiscountCard,
													(void**)&FormaSpiskaSprDiscountCard);
		FormaSpiskaSprDiscountCard->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprDiscountCard->NumberProcVibor=ER_Card;
		FormaSpiskaSprDiscountCard->IdKlient=glStrToInt64(DM->DocAllIDKLDOC->AsString);
		FormaSpiskaSprDiscountCard->DM->OpenTable(DM->DocAllIDKLDOC->AsInteger);
		//FormaSpiskaSprDiscountCard->LabelKlient->Caption="Контрагент: "+DM->DocAllNAMEKLIENT->AsString;
		FormaSpiskaSprDiscountCard->NameKlient=DM->DocAllNAMEKLIENT->AsString;
		FormaSpiskaSprDiscountCard->Vibor=true;
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocPKORozn::EndViborCard(void)
{

	DM->Doc->Edit();
	DM->DocIDCARD_DPKOROZN->AsString=FormaSpiskaSprDiscountCard->DM->TableID_SDISCOUNT_CARD->AsString;
	DM->DocNAME_SDISCOUNT_CARD->AsString=FormaSpiskaSprDiscountCard->DM->TableNAME_SDISCOUNT_CARD->AsString;
    DM->Doc->Post();


}
//----------------------------------------------------------------------------
void __fastcall TFormaDocPKORozn::NameCardcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborCard();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaDocPKORozn::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaDocPKORozn::RunExternalModule(__int64 id_module, int type_module)
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
void __fastcall TFormaDocPKORozn::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPKORozn::ActionOKExecute(TObject *Sender)
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

void __fastcall TFormaDocPKORozn::ActionDvRegExecute(TObject *Sender)
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

void __fastcall TFormaDocPKORozn::ActionSaveExecute(TObject *Sender)
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

void __fastcall TFormaDocPKORozn::ActionPrintExecute(TObject *Sender)
{
PrintDoc();
}
//---------------------------------------------------------------------------
void TFormaDocPKORozn::OpenFormSpiskaSprProject(void)
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
void __fastcall TFormaDocPKORozn::EndViborProject(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDPROJECT_GALLDOC->AsString=SpisokProject->DM->TableID_SPROJECT->AsString;
	DM->DocAllNAME_SPROJECT->AsString=SpisokProject->DM->TableNAME_SPROJECT->AsString;
	DM->DocAll->Post();




}
//----------------------------------------------------------------------------
void TFormaDocPKORozn::OpenFormSpiskaSprBusinessOper(void)
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
void __fastcall TFormaDocPKORozn::EndViborBusinessOper(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDBUSINOP_GALLDOC->AsString=SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString;
	DM->DocAllNAME_SBUSINESS_OPER->AsString=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;
	DM->DocAll->Post();

}
//----------------------------------------------------------------------------
void __fastcall TFormaDocPKORozn::NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
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

void __fastcall TFormaDocPKORozn::NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
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

