//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaReportDvDoc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"

extern String glGetNameDoc(String StrCodeDoc);
//---------------------------------------------------------------------------
__fastcall TFormaReportDvDoc::TFormaReportDvDoc(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaReportDvDoc::FormCreate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportDvDoc::FormClose(TObject *Sender,
      TCloseAction &Action)
{
IBQ->Active=false;
Action=caFree;
}
//---------------------------------------------------------------------------
void TFormaReportDvDoc::CreateReportDvDoc(__int64 id_doc)
{
IdDoc=id_doc;
AnsiString zapros=" select TDOC, POSDOC, NUMDOC from GALLDOC where IDDOC=:PARAM_IDDOC";
IBQ->Active=false;
IBQ->SelectSQL->Clear();
IBQ->SelectSQL->Add(zapros);
IBQ->ParamByName("PARAM_IDDOC")->AsInt64=IdDoc;
IBQ->Active=true;

TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

x=1;
y=1;

PrintForm->SS->BeginUpdate();

OutputZagolovokReport(PrintForm);




OutputPodvalReport(PrintForm);

PrintForm->SS->EndUpdate();
Close();

}
//----------------------------------------------------------------------------
void TFormaReportDvDoc::OutputZagolovokReport(TSheetEditor *prForm)
{
prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";
prForm->SS->RowsAutoHeight=true;

TcxSSCellObject *cell;
x=1; y=1;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "Движения документа по регистрам "+glGetNameDoc(IBQ->FieldByName("TDOC")->AsString)
                +" №"+IBQ->FieldByName("NUMDOC")->AsString
                +" от "+IBQ->FieldByName("POSDOC")->AsString;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[y]=25;
delete cell;
y++;

}
//----------------------------------------------------------------------------
void TFormaReportDvDoc::OutputPodvalReport(TSheetEditor *prForm)
{




}
//----------------------------------------------------------------------------
void TFormaReportDvDoc::OutputZagolovokRegOstNom(TSheetEditor *prForm)
{
y++;
TcxSSCellObject *cell;
x=2;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text ="Регистр \"Остатки партий номенклатуры \"";
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 12;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[y]=25;
delete cell;
y++;
//порядковый номер строки
x=2;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text ="№";
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//тип движения
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text ="Дв.";
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//ID строки документа
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text ="Строка";
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text ="Кол-во";
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text ="Сумма";
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//фирма
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text ="Фирма";
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//склад
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text ="Склад";
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text ="Номенклатура";
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//код партии
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text ="Код парт.";
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//документ партии
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text ="Док. партии";
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
y++;

}
//---------------------------------------------------------------------------
void TFormaReportDvDoc::OutputStringRegOstNom(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
String S="";
x=2;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text =IntToStr(porNumStr);
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//тип движения
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
if (DvRegOstNomTDV_OSTNOMDV->AsInteger==0){S="+";}
if (DvRegOstNomTDV_OSTNOMDV->AsInteger==1){S="-";}
cell->Text =S;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//строка документа
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text =DvRegOstNomIDSTRDOC_OSTNOMDV->AsString;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text =DvRegOstNomIDSTRDOC_OSTNOMDV->AsString;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text =DvRegOstNomIDSTRDOC_OSTNOMDV->AsString;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//фирма
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text =DvRegOstNomIDSTRDOC_OSTNOMDV->AsString;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//склад
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text =DvRegOstNomIDSTRDOC_OSTNOMDV->AsString;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text =DvRegOstNomIDSTRDOC_OSTNOMDV->AsString;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//код партии
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text =DvRegOstNomIDSTRDOC_OSTNOMDV->AsString;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//документ партии
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text =DvRegOstNomIDSTRDOC_OSTNOMDV->AsString;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
y++;


}
//--------------------------------------------------------------------------
void TFormaReportDvDoc::OutputPodvalRegOstNom(TSheetEditor *prForm)
{


}
//---------------------------------------------------------------------
