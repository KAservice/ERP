//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaSpiskaSprXMessageObmen.h"
#include "UDM.h"

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
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaSpiskaSprXMessageObmen::TFormaSpiskaSprXMessageObmen(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprXMessageObmen::FormCreate(TObject *Sender)
{
DM=new TDMXMessageObmen(Application);
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
Vibor=false;
OutReady=false;

PosCon=Date()+1;
PosNach=PosCon-10;
DM->PosNach=PosNach;
DM->PosCon=PosCon;
DM->OpenTable(0);
LabelOtbor->Caption="";

}
//---------------------------------------------------------------------------
void TFormaSpiskaSprXMessageObmen::UpdateForm(void)
{
if (Otbor==true)
        {
        DM->OpenTable(IdBase);
        LabelOtbor->Caption="Инф. база: "+NameInfBase;
        }
else
        {
        DM->OpenTable(0);
        LabelOtbor->Caption="";
        }

}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprXMessageObmen::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaViborPerioda)FormaViborPerioda->Close();
if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->Close();
try {if(FOnCloseForm) FOnCloseForm(this); } catch (...){}
delete DM;
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprXMessageObmen::EndEdit(TObject *Sender)
{
if (IdDochForm!=NULL)
        {

        if (ViborRekv==ViborPerioda)
                {
                if(FormaViborPerioda->OutReady==true)
                        {
                        PosNach=FormaViborPerioda->DateTimePicker1->DateTime;
                        PosCon=FormaViborPerioda->DateTimePicker2->DateTime;
                        DM->PosNach=PosNach;
                        DM->PosCon=PosCon;
                        LabelInterval->Caption=DateTimeToStr(PosNach)+" - "+DateTimeToStr(PosCon);
                        }
				FormaViborPerioda=0;
                }

        if (ViborRekv==ViborInfBase)
                {
				if (FormaSpiskaSprInfBase->OutReady==true)
                        {
						IdBase=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsInt64;
                        NameInfBase=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;
						}
                FormaSpiskaSprInfBase=0;
                }


        IdDochForm=NULL;
        ViborRekv=NO;
        }

DM->OpenTable(0);
}
//--------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprXMessageObmen::ToolButton1Click(
      TObject *Sender)
{
ShowMessage("Количество обновляемых записей: "+
        IntToStr(DM->GetCountUpdateRecord(DM->TableID_XMESSAGE_OBMEN->AsInt64)));
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprXMessageObmen::ToolButton3Click(
      TObject *Sender)
{
if (IdDochForm==NULL)
        {
        FormaViborPerioda=new TFormaViborPerioda(Application);
        FormaViborPerioda->IdRodForm=Handle;
        IdDochForm=FormaViborPerioda->Handle;
        ViborRekv=ViborPerioda;
        FormaViborPerioda->DateTimePicker1->DateTime=PosNach;
        FormaViborPerioda->DateTimePicker2->DateTime=PosCon;
        FormaViborPerioda->Time1->Time=FormaViborPerioda->DateTimePicker1->Time;
        FormaViborPerioda->Time2->Time=FormaViborPerioda->DateTimePicker2->Time;
        FormaViborPerioda->FOnCloseForm=EndEdit;
        FormaViborPerioda->ShowModal();

        }
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprXMessageObmen::ToolButtonViborInfBaseClick(
      TObject *Sender)
{
if (IdDochForm==NULL)
        {
        FormaSpiskaSprInfBase=new TFormaSpiskaSprInfBase(Application);
        if (!FormaSpiskaSprInfBase) return;
        FormaSpiskaSprInfBase->FOnCloseForm=EndEdit;
        FormaSpiskaSprInfBase->IdRodForm=Handle;
        FormaSpiskaSprInfBase->Vibor=true;
        IdDochForm=FormaSpiskaSprInfBase->Handle;
        ViborRekv=ViborInfBase;
        FormaSpiskaSprInfBase->DM->OpenTable();
        FormaSpiskaSprInfBase->Show();
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprXMessageObmen::ToolButtonOtborClick(
      TObject *Sender)
{

if (ToolButtonOtbor->Down==true)  // включить отбор
        {
        Otbor=true;
        }
else
        {
        Otbor=false;
        }

UpdateForm();
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprXMessageObmen::CreateReport(void)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;





PrintForm->SS->BeginUpdate();

OutputZagolovokReport(PrintForm);

DM->Table->First();
while (!DM->Table->Eof)
        {
        OutputStringReport(PrintForm);
        DM->Table->Next();
        }

OutputPodavalReport(PrintForm);

PrintForm->SS->EndUpdate();
PrintForm->Show();


}
//----------------------------------------------------------------------------
void TFormaSpiskaSprXMessageObmen::OutputZagolovokReport(TSheetEditor *prForm)
{
prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";

        TcxSSHeader *cHeader;
        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 30;
        cHeader->Size[2] = 150;
        cHeader->Size[3] = 70;
        cHeader->Size[4] = 150;
        cHeader->Size[5] = 100;
        cHeader->Size[6] = 100;
        cHeader->Size[7] = 100;


numRow=1;
numCol=1;

TcxSSCellObject *cell;
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text = "Журнал сообщений  с  "+DateTimeToStr(PosNach)
                        +" по "+DateTimeToStr(PosCon);
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;
numRow++;
numRow++;


numCol=1;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "№";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//дата
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->WordBreak = true;
cell->Text = "Дата";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//тип
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Тип";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//Инф. база
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Инф. база";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//GID
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "GID";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//Результат
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Рез.";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//Кол записей
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Кол. записей";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numCol++;
numRow++;

}

//---------------------------------------------------------------------------
void TFormaSpiskaSprXMessageObmen::OutputStringReport(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = IntToStr(DM->Table->RecNo);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//дата
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = DM->TablePOS_XMESSAGE_OBMEN->AsString;
//cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//тип
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (DM->TableOUT_XMESSAGE_OBMEN->AsInteger==1)
        {
        cell->Text = "Исх.";
        }

if (DM->TableOUT_XMESSAGE_OBMEN->AsInteger==2)
        {
        cell->Text = "Вход.";
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//инф. база
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = DM->TableNAME_SINFBASE_OBMEN->AsString;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;

cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//GID
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text = DM->TableGID_XMESSAGE_OBMEN->AsString;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//результ.
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (DM->TableKOLERR_XMESSAGE_OBMEN->AsInteger==-1)
        {
        cell->Text ="ОК";
        }
else
        {
        cell->Text ="Ошибка!";
        cell->Style->Font->FontColor=2;
        }


cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//кол записей
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = IntToStr(DM->GetCountUpdateRecord(DM->TableID_XMESSAGE_OBMEN->AsInt64));

cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;


}
//----------------------------------------------------------------------------
void TFormaSpiskaSprXMessageObmen::OutputPodavalReport(TSheetEditor *prForm)
{


}
//----------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprXMessageObmen::ToolButtonPrintFormClick(
      TObject *Sender)
{
CreateReport();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprXMessageObmen::ToolButtonSortPoDateClick(
      TObject *Sender)
{
DM->Sort=DM->PoDate;
UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprXMessageObmen::ToolButtonSortPoGidClick(
      TObject *Sender)
{
DM->Sort=DM->PoGid;
UpdateForm();
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprXMessageObmen::cxGrid1DBTableView1KOLERR_XMESSAGE_OBMENCustomDrawCell(
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

		if (ATextToDraw==-1)
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

