//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaGurDocPer.h"
#include "IFormaDocPer.h"
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
#pragma link "cxDBLabel"
#pragma link "cxLabel"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaGurDocPer::TFormaGurDocPer(TComponent* Owner)
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
bool TFormaGurDocPer::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.DMGurDocPer.1",IID_IDMGurDocPer, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
PrimPercxDBLabel->DataBinding->DataSource=DM->DataSourceTable;

PosCon=Date()+EncodeTime(23,59,59,999);
PosNach=DM_Connection->GetPosNachGurnal();

DM->PosNach=PosNach;
DM->PosCon=PosCon;
DM->OpenTable();
DM->Table->Last();

Vibor=false;
TypeEvent=0;
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

DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaGurDocPerImpl),false);
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
int TFormaGurDocPer::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaGurDocPer::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaViborPerioda)FormaViborPerioda->kanRelease();

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
int TFormaGurDocPer::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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



		ViborRekv=NO;


DM->UpdateTable();
return -1;
}
//--------------------------------------------------------------------------
void TFormaGurDocPer::OpenFormDoc()
{

		IFormaDocPer * Per;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocPer.1",IID_IFormaDocPer,
													(void**)&Per);
		Per->Init(InterfaceMainObject,InterfaceImpl);
		Per->DM->OpenDoc(DM->TableIDDOC->AsInt64);
		Per->UpdateForm();
}
//----------------------------------------------------------------------------


void __fastcall TFormaGurDocPer::ToolButtonDeleteClick(TObject *Sender)
{
DeleteDoc();
}
//---------------------------------------------------------------------------
void TFormaGurDocPer::DeleteDoc(void)
{

		IDMDocPer * Per;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPer.1",IID_IDMDocPer,
													(void**)&Per);
        Per->Init(InterfaceMainObject,InterfaceImpl);
		Per->OpenDoc(glStrToInt64(DM->TableIDDOC->AsString));

        String V="Вы действительно хотите удалить документ Перемещение №"
        +Per->DocAllNUMDOC->AsString+" от "+Per->DocAllPOSDOC->AsString+"?";
        String Z="Подтверждение удаления документа";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }

				if (Per->DeleteDoc(DM->TableIDDOC->AsInt64)==true)
                        {
                        DM->UpdateTable();
                        }
                else
                        {
                        ShowMessage("Не удалось удалить документ! Ошибка:"+Per->TextError);
                        }

		Per->kanRelease();

}

//---------------------------------------------------------------------------
void __fastcall TFormaGurDocPer::ToolButton3Click(TObject *Sender)
{
CanceDvRegDoc();
}
//---------------------------------------------------------------------------
void TFormaGurDocPer::CanceDvRegDoc(void)
{

		IDMDocPer *DMDoc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPer.1",IID_IDMDocPer,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,InterfaceImpl);
        DMDoc->OpenDoc( DM->TableIDDOC->AsInt64);
        DMDoc->CancelDvRegDoc();
		DMDoc->kanRelease();


DM->UpdateTable();

}
//-----------------------------------------------------------------------------
void __fastcall TFormaGurDocPer::ToolButtonViborPeriodaClick(
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

void __fastcall TFormaGurDocPer::ToolButtonNewDocClick(
      TObject *Sender)
{
IFormaDocPer* Per;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocPer.1",IID_IFormaDocPer,
													(void**)&Per);
Per->Init(InterfaceMainObject,InterfaceImpl);
Per->DM->NewDoc();
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurDocPer::ToolButton4Click(TObject *Sender)
{
OpenFormDoc();        
}
//---------------------------------------------------------------------------


void __fastcall TFormaGurDocPer::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("GurPer");
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurDocPer::ToolButtonRefreshClick(TObject *Sender)
{
DM->UpdateTable();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void TFormaGurDocPer::OpenPrintForm(void)
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
void TFormaGurDocPer::OutputZagolovokReport(ISheetEditor *prForm)
{

prForm->SetColumnWidth(0,20);
prForm->SetColumnWidth(1,30);
prForm->SetColumnWidth(2,120);
prForm->SetColumnWidth(3,80);
prForm->SetColumnWidth(4,50);
prForm->SetColumnWidth(5,120);
prForm->SetColumnWidth(6,120);
prForm->SetColumnWidth(7,80);
prForm->SetColumnWidth(8,100);


prForm->DefaultFontSize=8;


numRow=1;
numCol=2;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Реестр документов \"Перемещение\" с "+DateTimeToStr(PosNach)+" по "
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
prForm->TecCell_SetText("Фирма");
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
prForm->TecCell_SetText("Номер");
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
prForm->TecCell_SetText("Склад");
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
prForm->TecCell_SetText("Склад получатель");
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

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Автор");
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
void TFormaGurDocPer::OutputString(ISheetEditor *prForm)
{
numCol=1;


prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(porNumStr);
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
prForm->TecCell_SetText(DM->TableNAMEFIRM->AsString);
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
prForm->TecCell_SetText(DM->TableNAMESKLAD->AsString);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(DM->TableNAMESKLADPOL->AsString);
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

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(DM->TableNAME_USER->AsString);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;
}


//------------------------------------------------------------------------------
void TFormaGurDocPer::OutputPodavalReport(ISheetEditor *prForm)
{
//
numRow++;
numCol=1;


prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Всего документов :"+IntToStr(porNumStr-1)+" на сумму "
				+FloatToStr(SumReport)+"руб.");
prForm->TecCell_DeleteObject();


}
//----------------------------------------------------------------------------
void __fastcall TFormaGurDocPer::ToolButton5Click(TObject *Sender)
{
OpenPrintForm();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurDocPer::cxGrid1DBTableView1DblClick(TObject *Sender)
{
if (Vibor==true)
	{
	TypeEvent=1;
	Close();
	}
else
	{
	OpenFormDoc();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurDocPer::cxGrid1DBTableView1PRDOCCustomDrawCell(
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

void __fastcall TFormaGurDocPer::cxGrid1DBTableView1KeyPress(TObject *Sender,
      char &Key)
{

if (Key==VK_RETURN)
		{
		if (Vibor==true)
			{
			TypeEvent=1;
			Close();
			}
		else
			{
			OpenFormDoc();
			}
		}
}
//---------------------------------------------------------------------------


void __fastcall TFormaGurDocPer::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaGurDocPer::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaGurDocPer::RunExternalModule(__int64 id_module, int type_module)
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
