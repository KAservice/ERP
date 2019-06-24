//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaGurRoznDoc.h"

#include "IDMSetup.h"
#include "IFormaDocCheckProsmotr.h"
#include "IFormaDocRealRoznForCashier.h"
#include "IFormaDocPKORoznForCashier.h"
#include "IFormaDocRKORoznForCashier.h"

#include "IDMSprARM.h"
#include "IFormaDocVosvratPokForCashier.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IFormaRunExternalModule.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
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
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaGurRoznDoc::TFormaGurRoznDoc(TComponent* Owner)
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
bool TFormaGurRoznDoc::Init(void)
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


InterfaceGlobalCom->kanCreateObject("Oberon.DMGurRoznDoc.1",IID_IDMGurRoznDoc, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;

PosNach=0;
PosCon=Date();
unsigned short Year;
unsigned short Month;
unsigned short Day;
PosCon.DecodeDate(&Year,&Month,&Day);
PosNach=PosCon-Day+1;
PosCon++;
DM->PosNach=PosNach;
DM->PosCon=PosCon;

IdKlient=0;
NameKlient="";
StringTypeDoc="''";

OtborPoKlientu=false;
OtborPoTypeDoc=false;

DM->OtborPoKlient=false;
DM->OtborPoTypeDoc=false;
DM->IdBase=glStrToInt64(DM_Connection->ARMInfoIDBASE_SARM->AsString);
DM->OpenTable();

StrOtborLabel->Caption="";

DM->Table->Last();
Vibor=false;
LabelInterval->Caption=DateTimeToStr(PosNach)+" - "+DateTimeToStr(PosCon);



 //ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject(ProgId_DMTableExtPrintForm,IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);

DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaGurRoznDocImpl),false);
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

result=true;

return result;
}
//---------------------------------------------------------------------------
int TFormaGurRoznDoc::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaGurRoznDoc::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaViborPerioda)FormaViborPerioda->kanRelease();
if(FormaSetupOtbor)FormaSetupOtbor->kanRelease();


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
int TFormaGurRoznDoc::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{


		if (number_procedure_end==ViborPerioda)
                {
				if(type_event==1)
                        {
						PosNach=FormaViborPerioda->PosNach;
                        PosCon=FormaViborPerioda->PosNach;
                        DM->PosNach=PosNach;
                        DM->PosCon=PosCon;
                        LabelInterval->Caption=DateTimeToStr(PosNach)+" - "+DateTimeToStr(PosCon);
                        }
                FormaViborPerioda=0;
                }

		if (number_procedure_end==SetupOtborRekv)
                {
				if(type_event==1)
                        {
                        IdKlient=FormaSetupOtbor->IdKlient;
                        NameKlient=FormaSetupOtbor->NameKlient;
                        StringTypeDoc=FormaSetupOtbor->StringTypeDoc;
                        NameTypeDoc=FormaSetupOtbor->NameTypeDoc;
                        }
                FormaSetupOtbor=0;
                }

        ViborRekv=NO;


DM->UpdateTable();
return -1;
}
//--------------------------------------------------------------------------
void TFormaGurRoznDoc::OpenFormDoc()
{


if(DM->TableTDOC->AsString=="CHK")
		{
		IFormaDocCheckProsmotr * Check;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocCheckProsmotr.1",IID_IFormaDocCheckProsmotr,
													(void**)&Check);
		Check->Init(InterfaceMainObject,InterfaceImpl);
        //настройка формы
		Check->DM->OpenDoc(glStrToInt64(DM->TableIDDOC->AsString));
		Check->UpdateForm();

		}




if(DM->TableTDOC->AsString=="REALROZN")
		{
		IFormaDocRealRoznForCashier * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRealRoznForCashier.1",IID_IFormaDocRealRoznForCashier,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableIDDOC->AsString));
		doc->UpdateForm();
        }

if(DM->TableTDOC->AsString=="PKOROZN")
        {
		IFormaDocPKORoznForCashier * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocPKORoznForCashier.1",IID_IFormaDocPKORoznForCashier,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
        //настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableIDDOC->AsString));
        doc->UpdateForm();
        }

if(DM->TableTDOC->AsString=="RKOROZN")
        {
		IFormaDocRKORoznForCashier * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRKORoznForCashier.1",IID_IFormaDocRKORoznForCashier,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
        //настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableIDDOC->AsString));
		doc->UpdateForm();
        }

if(DM->TableTDOC->AsString=="VPOK")
        {
		IFormaDocVosvratPokForCashier * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocVosvratPokForCashier.1",IID_IFormaDocVosvratPokForCashier,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
        doc->DM->OpenDoc(glStrToInt64(DM->TableIDDOC->AsString));
		//doc->UpdateForm();
		}

}
//----------------------------------------------------------------------------

void __fastcall TFormaGurRoznDoc::FormResize(TObject *Sender)
{
int TecSumWidth=cxGrid1->Width;
StrOtborLabel->Left=cxGrid1->Left+TecSumWidth-StrOtborLabel->Width ;

}

//----------------------------------------------------------------------------
void __fastcall TFormaGurRoznDoc::ToolButtonViborPeriodaClick(
      TObject *Sender)
{
if (FormaViborPerioda==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaViborPerioda.1",IID_IFormaViborPerioda,
													(void**)&FormaViborPerioda);
		FormaViborPerioda->Init(InterfaceMainObject,InterfaceImpl);
		FormaViborPerioda->NumberProcVibor=ViborPerioda;
		FormaViborPerioda->PosNach=PosNach;
		FormaViborPerioda->PosCon=PosCon;
        }
}
//---------------------------------------------------------------------------


void __fastcall TFormaGurRoznDoc::ToolButtonOpenDocClick(TObject *Sender)
{
OpenFormDoc();
}

//--------------------------------------------------------------------------------

void __fastcall TFormaGurRoznDoc::ToolButtonOtborClick(TObject *Sender)
{

AnsiString s="";
if (ToolButtonOtbor->Down==true)  // включить отбор
        {
        DM->OtborVkl=true;

                        if (IdKlient>0) s=s+" Контрагент: "+NameKlient;
                        if (StringTypeDoc!="") s=s+" Тип документов : "+NameTypeDoc;
                        StrOtborLabel->Caption=s;
        }
else
        {
        DM->OtborVkl=false;
        StrOtborLabel->Caption=s;
        }

DM->IdKlient=IdKlient;
DM->StringTypeDoc=StringTypeDoc;

DM->OtborPoKlient=OtborPoKlientu;
DM->OtborPoTypeDoc=OtborPoTypeDoc;
DM->UpdateTable();


}
//---------------------------------------------------------------------------

void __fastcall TFormaGurRoznDoc::ToolButtonParamOtborClick(TObject *Sender)
{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSetOtbGurRoznDoc.1",IID_IFormaSetupOtborGurRoznDoc,
													(void**)&FormaSetupOtbor);
		FormaSetupOtbor->Init(InterfaceMainObject,InterfaceImpl);
		FormaSetupOtbor->NumberProcVibor=SetupOtborRekv;
}
//---------------------------------------------------------------------------

void TFormaGurRoznDoc::OpenPrintForm(void)
{
ISheetEditor *  prForm;
InterfaceGlobalCom->kanCreateObject("Oberon.SheetEditor.1", IID_ISheetEditor,
																	(void**)&prForm);
numRow=1;
numCol=1;
porNumStr=1;
prForm->BeginUpdate();

//шапка
OutputZagolovokReport(prForm);

//таблица
SumSale=0;
SumReturnSale=0;
SumPay=0;
SumReturnPay=0;

DM->Table->First();
while(!DM->Table->Eof)
        {
        if (DM->TableTDOC->AsString=="CHK")
                {
                SumSale=SumSale+DM->TableSUMDOC->AsFloat;
                SumPay=SumPay+DM->TableSUMDOC->AsFloat;
                }

        if (DM->TableTDOC->AsString=="REALROZN")
                {
                SumSale=SumSale+DM->TableSUMDOC->AsFloat;
				}

		if (DM->TableTDOC->AsString=="VPOK")
                {
                SumReturnSale=SumReturnSale+DM->TableSUMDOC->AsFloat;
				}

        if (DM->TableTDOC->AsString=="PKOROZN")
                {
                SumPay=SumPay+DM->TableSUMDOC->AsFloat;
                }

        if (DM->TableTDOC->AsString=="RKOROZN")
                {
                SumReturnPay=SumReturnPay+DM->TableSUMDOC->AsFloat;
                }


        OutputString(prForm); porNumStr++;
        //SumReport=SumReport+DM->TableSUMDOC->AsFloat;
        DM->Table->Next();
        }

OutputPodavalReport(prForm);
prForm->EndUpdate();
}
//------------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TFormaGurRoznDoc::OutputZagolovokReport(ISheetEditor  *prForm)
{
prForm->SetColumnWidth(0,10);
prForm->SetColumnWidth(1,50);
prForm->SetColumnWidth(2,150);
prForm->SetColumnWidth(3,50);
prForm->SetColumnWidth(4,120);
prForm->SetColumnWidth(5,100);
prForm->SetColumnWidth(6,100);
prForm->SetColumnWidth(7,100);
prForm->SetColumnWidth(8,100);

numRow=2;
numCol=1;


prForm->TecCell_GetObject(2, numRow);
prForm->TecCell_SetText( "Отчет по операциям c "+DateTimeToStr(PosNach)
						+" по "+DateTimeToStr(PosCon));
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haLEFT);
prForm->TecCell_SetFontSize(16);
prForm->TecCell_SetFontStyle(TFontStyles() << fsBold);
prForm->SetRowsHeight(numRow,25);
prForm->TecCell_DeleteObject();
numRow++;
numRow++;


numCol=1;
prForm->SetRowsHeight(numRow,40);
//порядковый номер строки
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText( "№");
prForm->TecCell_SetFontSize(10);
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
prForm->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

//номенклатура
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText( "Документ");
prForm->TecCell_SetFontSize(10);
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
prForm->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;
//нач остаток
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText( "Номер");
prForm->TecCell_SetFontSize(10);
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
prForm->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;
//приход
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText( "Дата");
prForm->TecCell_SetFontSize(10);
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
prForm->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

//расход
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText( "Сумма реализации");
prForm->TecCell_SetFontSize(10);
prForm->TecCell_SetWordBreake(true);
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
prForm->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();

numCol++;
//кон. остаток
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText( "Сумма возврата реализации");
prForm->TecCell_SetFontSize(10);
prForm->TecCell_SetWordBreake(true);
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
prForm->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

//расход
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText( "Сумма оплаты");
prForm->TecCell_SetFontSize(10);
prForm->TecCell_SetWordBreake(true);
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
prForm->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();

numCol++;
//кон. остаток
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText( "Сумма возврата оплаты");
prForm->TecCell_SetFontSize(10);
prForm->TecCell_SetWordBreake(true);
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
prForm->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

numRow++;
}

//----------------------------------------------------------------------------
void __fastcall TFormaGurRoznDoc::ToolButtonPrintClick(TObject *Sender)
{
OpenPrintForm();        
}
//------------------------------------------------------------------------------
void TFormaGurRoznDoc::OutputString(ISheetEditor  *prForm)
{

numCol=1;
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(IntToStr(porNumStr));
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
prForm->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;
//документ
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(glGetNameDoc(DM->TableTDOC->AsString));
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
prForm->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

//номер
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(DM->TableNUMDOC->AsString);
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
prForm->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;
//дата
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(DM->TablePOSDOC->AsString);
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
prForm->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;
//реализация
prForm->TecCell_GetObject(numCol, numRow);

if (DM->TableSUMDOC->AsFloat!=0)
        {
        if (DM->TableTDOC->AsString=="CHK")
				{
				prForm->TecCell_SetText(FloatToStrF(DM->TableSUMDOC->AsFloat,ffFixed,10,2));
                }
        if (DM->TableTDOC->AsString=="REALROZN")
				{
				prForm->TecCell_SetText(FloatToStrF(DM->TableSUMDOC->AsFloat,ffFixed,10,2));
                }
        }
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
prForm->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;
//возврат
prForm->TecCell_GetObject(numCol, numRow);
if (DM->TableSUMDOC->AsFloat!=0)
        {
		if (DM->TableTDOC->AsString=="VPOK")
				{
				prForm->TecCell_SetText(FloatToStrF(DM->TableSUMDOC->AsFloat,ffFixed,10,2));
                }
		}
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
prForm->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;
//поступление оплаты
prForm->TecCell_GetObject(numCol, numRow);
if (DM->TableSUMDOC->AsFloat!=0)
		{
        if (DM->TableTDOC->AsString=="CHK")
				{
				prForm->TecCell_SetText(FloatToStrF(DM->TableSUMDOC->AsFloat,ffFixed,10,2));
				}
        if (DM->TableTDOC->AsString=="PKOROZN")
				{
				prForm->TecCell_SetText(FloatToStrF(DM->TableSUMDOC->AsFloat,ffFixed,10,2));
                }
        }
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
prForm->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

//возврат оплаты
prForm->TecCell_GetObject(numCol, numRow);
if (DM->TableSUMDOC->AsFloat!=0)
        {
        if (DM->TableTDOC->AsString=="RKOROZN")
				{
				prForm->TecCell_SetText(FloatToStrF(DM->TableSUMDOC->AsFloat,ffFixed,10,2));
                }
        }
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
prForm->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;


numRow++;
}

//--------------------------------------------------------------------------


void TFormaGurRoznDoc::OutputPodavalReport(ISheetEditor  *prForm)
{
numCol=1;
//порядковый номер строки
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("");
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
prForm->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

//номенлатура
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("");
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
prForm->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

//нач остаток
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("");
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
prForm->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;
//приход
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("");
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
prForm->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;
//расход
prForm->TecCell_GetObject(numCol, numRow);
if (SumSale!=0)
		{
		prForm->TecCell_SetText(FloatToStrF(SumSale,ffFixed,10,2));
		}
prForm->TecCell_SetFontSize(12);
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
prForm->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;
//кон. остаток
prForm->TecCell_GetObject(numCol, numRow);
if (SumReturnSale!=0)
        {
		prForm->TecCell_SetText(FloatToStrF(SumReturnSale,ffFixed,10,2));
        }
prForm->TecCell_SetFontSize(12);
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
prForm->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;
//расход
prForm->TecCell_GetObject(numCol, numRow);
if (SumPay!=0)
		{
		prForm->TecCell_SetText(FloatToStrF(SumPay,ffFixed,10,2));
        }
prForm->TecCell_SetFontSize(12);
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
prForm->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;
//кон. остаток
prForm->TecCell_GetObject(numCol, numRow);
if (SumReturnPay!=0)
		{
		prForm->TecCell_SetText(FloatToStrF(SumReturnPay,ffFixed,10,2));
        }
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
prForm->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;
}
//-----------------------------------------------------------------------------
void __fastcall TFormaGurRoznDoc::ToolButtonRefreshClick(TObject *Sender)
{
DM->UpdateTable();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurRoznDoc::cxGrid1DBTableView1DblClick(TObject *Sender)
{
OpenFormDoc();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurRoznDoc::cxGrid1DBTableView1PRDOCCustomDrawCell(
      TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
      TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone)
{
AnsiString ATextToDraw;
if (dynamic_cast<TcxGridTableDataCellViewInfo *>(AViewInfo) != NULL)
	{
	ATextToDraw = AViewInfo->GridRecord->DisplayTexts[AViewInfo->Item->Index];
	}
else
	{
	ATextToDraw = VarAsType(AViewInfo->Item->Caption, varString);
	}

TRect ARec = AViewInfo->Bounds;
Graphics::TBitmap *ABitmap = new Graphics::TBitmap();
if (ATextToDraw==1)
	{
	ToolBar1->Images->GetBitmap(16,ABitmap);
	}
else
	{
	ToolBar1->Images->GetBitmap(17,ABitmap);
	}
ACanvas->Canvas->FillRect(ARec);
ACanvas->Canvas->Draw((ARec.Left+ARec.Right-ABitmap->Width)/2,ARec.Top,ABitmap);
ABitmap->Free();
ADone = true;		
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurRoznDoc::OpenHelpExecute(TObject *Sender)
{
Application->HelpJump("GurRoznDoc");	
}
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaGurRoznDoc::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaGurRoznDoc::RunExternalModule(__int64 id_module, int type_module)
{
IFormaRunExternalModule * module;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaRunExternalModule.1",IID_IFormaRunExternalModule,
													(void**)&module);
module->Init(InterfaceMainObject,InterfaceImpl);
module->IdModule=id_module;
module->TypeTable=1;

module->ClearModule();
module->LoadModule();

//надо добавить переменные модуля, как минимум  IDDOC
module->SetInt64Variables("glIdDoc", glStrToInt64(DM->TableIDDOC->AsString));

module->SetDateTimeVariables("glPosBegin", PosNach);
module->SetDateTimeVariables("glPosEnd", PosCon);

module->ExecuteModule();
}
//---------------------------------------------------------------------------
