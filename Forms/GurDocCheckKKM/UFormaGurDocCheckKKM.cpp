//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaGurDocCheckKKM.h"
#include "IFormaDocCheck.h"
//#include "IFormaCreateReportKKM.h"
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
#pragma link "cxContainer"
#pragma link "cxTextEdit"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxClasses"
#pragma link "cxContainer"
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
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxStyles"
#pragma link "cxTextEdit"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaGurDocCheckKKM::TFormaGurDocCheckKKM(TComponent* Owner)
        : TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
TypeEvent=0;

Vibor=false;


IdKKM=0;
NameKKMLabel->Caption="ККМ не выбрана";
NumberKLEdit->Text="0";
Otbor=false;
}
//---------------------------------------------------------------------------
bool TFormaGurDocCheckKKM::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.DMGurDocCheckKKM.1",IID_IDMGurDocCheckKKM, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

PosCon=Date()+EncodeTime(23,59,59,999);
PosNach=DM_Connection->GetPosNachGurnal();

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;

//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

DM->PosNach=PosNach;
DM->PosCon=PosCon;
DM->OpenTable();
DM->Table->Last();
LabelInterval->Caption=DateTimeToStr(PosNach)+" - "+DateTimeToStr(PosCon);




//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject(ProgId_DMTableExtPrintForm,IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);

DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaGurDocCheckKKMImpl),false);
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
int TFormaGurDocCheckKKM::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaGurDocCheckKKM::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaViborPerioda)FormaViborPerioda->kanRelease();
if(FormaSpiskaSprKKM)FormaSpiskaSprKKM->kanRelease();

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
int TFormaGurDocCheckKKM::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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
						PosCon=FormaViborPerioda->PosCon;
                        DM->PosNach=PosNach;
                        DM->PosCon=PosCon;
                        LabelInterval->Caption=DateTimeToStr(PosNach)+" - "+DateTimeToStr(PosCon);
                        }
                FormaViborPerioda=0;

                }

		if (number_procedure_end==ViborKKM)
                {
				if(type_event==1)
                        {
						IdKKM=glStrToInt64(FormaSpiskaSprKKM->DM->ElementIDKKM->AsString);
                        NameKKMLabel->Caption="ККМ: "+FormaSpiskaSprKKM->DM->ElementNAMEKKM->AsString;
                        if (ToolButtonOtbor->Down==true)
                                {
                                DM->IdKKM=IdKKM;
                                DM->NumberKL=(int)StrToFloat(NumberKLEdit->Text);
                                DM->UpdateTable();
                                }
                        else
                                {
                                DM->IdKKM=0;
                                DM->NumberKL=0;
                                DM->UpdateTable();
                                }
                        }
                FormaSpiskaSprKKM=0;

                }


        ViborRekv=NO;


DM->UpdateTable();
return -1;
}
//--------------------------------------------------------------------------
void TFormaGurDocCheckKKM::OpenFormDoc()
{
		IFormaDocCheck * Check;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocCheck.1",IID_IFormaDocCheck,
													(void**)&Check);
		Check->Init(InterfaceMainObject,InterfaceImpl);
		Check->DM->OpenDoc(glStrToInt64(DM->TableIDDOC->AsString));
		//Check->Operation->ItemIndex=Check->DM->DocOPERCHK->AsInteger;
        Check->UpdateForm();

}
//----------------------------------------------------------------------------


void __fastcall TFormaGurDocCheckKKM::ToolButtonDeleteClick(TObject *Sender)
{
DeleteDoc();
}
//---------------------------------------------------------------------------
void TFormaGurDocCheckKKM::DeleteDoc(void)
{
		IDMDocCheck * Check;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocCheck.1",IID_IDMDocCheck,
													(void**)&Check);
		Check->Init(InterfaceMainObject,InterfaceImpl);
        if (!Check) return;
        //настройка формы
		Check->OpenDoc(glStrToInt64(DM->TableIDDOC->AsString));

        String V="Вы действительно хотите удалить документ Чек ККМ №"
        +Check->DocAllNUMDOC->AsString+" от "+Check->DocAllPOSDOC->AsString+"?";
        String Z="Подтверждение удаления документа";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }

                if (Check->DeleteDoc(glStrToInt64(DM->TableIDDOC->AsString))==true)
                        {
                        DM->UpdateTable();
                        }
                else
                        {
                        ShowMessage("Не удалось удалить документ! Ошибка:"+Check->TextError);
                        }

	   Check->kanRelease();

}

//---------------------------------------------------------------------------
void __fastcall TFormaGurDocCheckKKM::ToolButton3Click(TObject *Sender)
{
CanceDvRegDoc();
}
//---------------------------------------------------------------------------
void TFormaGurDocCheckKKM::CanceDvRegDoc(void)
{

		IDMDocCheck *DMDoc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocCheck.1",IID_IDMDocCheck,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,InterfaceImpl);
        DMDoc->OpenDoc( DM->TableIDDOC->AsInteger);
        DMDoc->CancelDvRegDoc();
		DMDoc->kanRelease();


DM->UpdateTable();

}
//-----------------------------------------------------------------------------
void __fastcall TFormaGurDocCheckKKM::ToolButtonViborPeriodaClick(
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
//        FormaViborPerioda->Time1->Time=FormaViborPerioda->DateTimePicker1->Time;
//		FormaViborPerioda->Time2->Time=FormaViborPerioda->DateTimePicker2->Time;
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurDocCheckKKM::ToolButtonNewDocClick(
      TObject *Sender)
{
IFormaDocCheck * Check;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocCheck.1",IID_IFormaDocCheck,
													(void**)&Check);
		Check->Init(InterfaceMainObject,InterfaceImpl);
if (!Check) return;
//настройка формы
Check->DM->NewDoc();
//Check->Operation->ItemIndex=0;

}
//---------------------------------------------------------------------------

void __fastcall TFormaGurDocCheckKKM::ToolButton4Click(TObject *Sender)
{
OpenFormDoc();        
}
//---------------------------------------------------------------------------

void TFormaGurDocCheckKKM::OpenPrintForm(void)
{
ISheetEditor *  PrintForm;
InterfaceGlobalCom->kanCreateObject("Oberon.SheetEditor.1", IID_ISheetEditor,
																	(void**)&PrintForm);

numRow=1;
numCol=1;
porNumStr=1;


//шапка
PrintForm->BeginUpdate();
OutputZagolovokReport(PrintForm);

//таблица
SumReport=0;
DM->Table->First();
while(!DM->Table->Eof)
        {

        OutputString(PrintForm);numRow++; porNumStr++;
        SumReport=SumReport+DM->TableSUMDOC->AsFloat;
        DM->Table->Next();
        }

OutputPodavalReport(PrintForm);
PrintForm->EndUpdate();
}
//---------------------------------------------------------------------------
void TFormaGurDocCheckKKM::OutputZagolovokReport(ISheetEditor *prForm)
{

prForm->SetColumnWidth(0,20);
prForm->SetColumnWidth(1,50);
prForm->SetColumnWidth(2,150);
prForm->SetColumnWidth(3,120);
prForm->SetColumnWidth(4,80);
prForm->SetColumnWidth(5,80);
prForm->SetColumnWidth(6,80);
prForm->SetColumnWidth(7,150);


numRow=1;
numCol=2;


prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Журнал чеков с "+DateTimeToStr(PosNach)+" по "
				+DateTimeToStr(PosCon));
prForm->TecCell_SetFontSize(16);
prForm->TecCell_DeleteObject();
numRow++; numRow++;


//заголовок таблицы
numCol=1;
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("№");
prForm->TecCell_SetFontSize(10);
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
prForm->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Дата");
prForm->TecCell_SetFontSize(10);
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
prForm->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Номер док.");
prForm->TecCell_SetFontSize(10);
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
prForm->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Номер КЛ");
prForm->TecCell_SetFontSize(10);
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
prForm->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Номер чека");
prForm->TecCell_SetFontSize(10);
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
prForm->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("ККМ");
prForm->TecCell_SetFontSize(10);
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
prForm->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Сумма");
prForm->TecCell_SetFontSize(10);
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
//------------------------------------------------------------------------------
void TFormaGurDocCheckKKM::OutputString(ISheetEditor *prForm)
{
numCol=1;


prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(IntToStr(porNumStr));
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(DM->TablePOSDOC->AsString);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(DM->TableNUMDOC->AsString);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(DM->TableNKLCHK->AsString);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(DM->TableNCHECKCHK->AsString);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(DM->TableNAMEKKM->AsString);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(FloatToStrF(DM->TableSUMDOC->AsFloat,ffFixed,10,2));
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;
}


//------------------------------------------------------------------------------
void TFormaGurDocCheckKKM::OutputPodavalReport(ISheetEditor *prForm)
{
//


numCol=1;
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("");
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Всего:");
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("");
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("");
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("");
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("");
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(FloatToStrF(SumReport,ffFixed,10,2));
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

}
//---------------------------------------------------------------
void __fastcall TFormaGurDocCheckKKM::ToolButtonPrintClick(TObject *Sender)
{
OpenPrintForm();
}
//---------------------------------------------------------------------------


void __fastcall TFormaGurDocCheckKKM::ButtonViborKKMClick(TObject *Sender)
{
OpenFormSpiskaSprKKM();
}
//---------------------------------------------------------------------------
void TFormaGurDocCheckKKM::OpenFormSpiskaSprKKM(void)
{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKKM.1",IID_IFormaSpiskaSprKKM,
													(void**)&FormaSpiskaSprKKM);
		FormaSpiskaSprKKM->Init(InterfaceMainObject,InterfaceImpl);
        FormaSpiskaSprKKM->Vibor=true;
		FormaSpiskaSprKKM->NumberProcVibor=ViborKKM;

}
//--------------------------------------------------------------------------
void __fastcall TFormaGurDocCheckKKM::ToolButtonOtborClick(TObject *Sender)
{
if (Otbor==false)
        {
        Otbor=true;
        }
else
        {
        Otbor=false;
        }

if (Otbor==false )
        {
        DM->IdKKM=0;
        DM->NumberKL=0;
        NameKKMLabel->Caption="ККМ не выбрана";
        NumberKLEdit->Text="0";
        DM->UpdateTable();
        ToolButtonOtbor->AllowAllUp=true;
        }

if (Otbor==true)
        {
        DM->IdKKM=IdKKM;
        DM->NumberKL=(int) StrToFloat(NumberKLEdit->Text);
        DM->UpdateTable();
        ToolButtonOtbor->Down=true;
        }


}
//---------------------------------------------------------------------------



void __fastcall TFormaGurDocCheckKKM::ToolButtonCreateDocRepKKMClick(
      TObject *Sender)
{
//TFormaCreateReportKKM * FormaCreateReportKKM=new TFormaCreateReportKKM(Application);
//FormaCreateReportKKM->DM_Connection=DM_Connection;
//FormaCreateReportKKM->Init();
//if (!FormaCreateReportKKM) return;
//FormaCreateReportKKM->Show();
}
//---------------------------------------------------------------------------


void __fastcall TFormaGurDocCheckKKM::ToolButtonrefreshClick(TObject *Sender)
{
DM->UpdateTable();
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurDocCheckKKM::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
OpenFormDoc();
}
//---------------------------------------------------------------------------


void __fastcall TFormaGurDocCheckKKM::cxGrid1DBTableView1PRDOCCustomDrawCell(
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

void __fastcall TFormaGurDocCheckKKM::NumberKLEditKeyPress(TObject *Sender,
      char &Key)
{
if (Key!=VK_RETURN) return;
if (ToolButtonOtbor->Down==true)
		{
		if (NumberKLEdit->Text!="")
				{
				DM->IdKKM=IdKKM;
				DM->NumberKL=(int) StrToFloat(NumberKLEdit->Text);
				DM->UpdateTable();
				}
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurDocCheckKKM::cxGrid1DBTableView1KeyPress(
      TObject *Sender, char &Key)
{
if(Key==VK_RETURN)
	{
	OpenFormDoc();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurDocCheckKKM::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("GurDocCheck");
}
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaGurDocCheckKKM::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaGurDocCheckKKM::RunExternalModule(__int64 id_module, int type_module)
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
void __fastcall TFormaGurDocCheckKKM::cxGrid1DBTableView1OPERCHKCustomDrawCell(TcxCustomGridTableView *Sender,
          TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone)
{
UnicodeString ATextToDraw;
if (dynamic_cast<TcxGridTableDataCellViewInfo *>(AViewInfo) != NULL)
	{
	ATextToDraw = AViewInfo->GridRecord->DisplayTexts[AViewInfo->Item->Index];
	}
else
	{
	ATextToDraw = VarAsType(AViewInfo->Item->Caption, varString);
	}
int oper=0;
if (ATextToDraw!="")
	{
	oper=StrToInt(ATextToDraw);
	}
TRect ARec = AViewInfo->Bounds;
Graphics::TBitmap *ABitmap = new Graphics::TBitmap();
if (oper==1)
	{
	ToolBar1->Images->GetBitmap(17,ABitmap);
	}
ACanvas->Canvas->FillRect(ARec);
ACanvas->Canvas->Draw((ARec.Left+ARec.Right-ABitmap->Width)/2,ARec.Top,ABitmap);
ABitmap->Free();
ADone = true;
}
//---------------------------------------------------------------------------

