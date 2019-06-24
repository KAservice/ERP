//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaDialogaReportOtrSpisNom.h"



//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaDialogaReportOtrSpis::TFormaDialogaReportOtrSpis(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaDialogaReportOtrSpis::FormCreate(TObject *Sender)
{
TypePrice->Active=false;
TypePrice->Active=true;

TypePriceComboBox->Items->Clear();
TypePrice->First();
while (!TypePrice->Eof)
        {
        TypePriceComboBox->Items->Add(TypePriceNAME_TPRICE->AsString);
        TypePrice->Next();
        }


DateCon->Date=Date();
unsigned short Year;
unsigned short Month;
unsigned short Day;
DateCon->Date.DecodeDate(&Year,&Month,&Day);
DateNach->Date=DateCon->Date-Day+1;

NameSkladEdit->Text="";
PosNachLabel->Caption=DateTimeToStr(DateNach->DateTime);
PosConLabel->Caption=DateTimeToStr(DateCon->DateTime);
}
//---------------------------------------------------------------------------
void __fastcall TFormaDialogaReportOtrSpis::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Grp->Active=false;
if (SpisokSklad) SpisokSklad->Close();
Action=caFree;
}

//---------------------------------------------------------------------------
void __fastcall TFormaDialogaReportOtrSpis::ButtonCloseClick(
      TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormaDialogaReportOtrSpis::EndEdit(TObject *Sender)
{
if (EditRekvisit==ViborSklad)
        {
        if (SpisokSklad->OutReady==true)
                {
                IdSkl=SpisokSklad->DM->ElementIDSKLAD->AsInteger;
                NameSkladEdit->Text=SpisokSklad->DM->ElementNAMESKLAD->AsString;
                }
        SpisokSklad=0;
        }

EditRekvisit=NO;
IdDochForm=NULL;
}
//---------------------------------------------------------------------------
void TFormaDialogaReportOtrSpis::OpenFormSpiskaSprSklad(void)
{
if (IdDochForm==NULL)
        {
        SpisokSklad=new TFormaSpiskaSprSklad(Application);
        if (!SpisokSklad) return;
        SpisokSklad->IdRodForm=Handle;
        SpisokSklad->Vibor=true;
        IdDochForm=SpisokSklad->Handle;
        EditRekvisit=ViborSklad;
        SpisokSklad->FOnCloseForm=EndEdit;
        SpisokSklad->Show();
        }

}
//----------------------------------------------------------------------------
void __fastcall TFormaDialogaReportOtrSpis::ButtonViborSkladClick(
      TObject *Sender)
{
OpenFormSpiskaSprSklad();
}
//---------------------------------------------------------------------------
void __fastcall TFormaDialogaReportOtrSpis::ButtonRunClick(TObject *Sender)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
SumReport=0;
porNumStrGrp=1;
String ZaprosGrp="";

ZaprosGrp=          " select  NAMEGN, IDGN, SUM(KOL_RGOTRSPIS_DV)  AS SUMKOL , SUM(KOL_RGOTRSPIS_DV*ZNACH_PRICE)  AS SUMM" ;
ZaprosGrp=ZaprosGrp+" from RGOTRSPIS_DV ";
ZaprosGrp=ZaprosGrp+" left outer join SNOM on IDNOM_RGOTRSPIS_DV=IDNOM";
ZaprosGrp=ZaprosGrp+" left outer join SGRPNOM on IDGRPNOM=IDGN";
ZaprosGrp=ZaprosGrp+" left outer join SPRICE on (IDNOM_PRICE=IDNOM and IDTYPE_PRICE=:PARAM_IDTYPE_PRICE)";

if (IdSkl==0)
        {
        ZaprosGrp=ZaprosGrp+" where POSDOC_RGOTRSPIS_DV  between :PARAM_POSNACH and :PARAM_POSCON ";
        }
else
        {
        ZaprosGrp=ZaprosGrp+" where POSDOC_RGOTRSPIS_DV  between :PARAM_POSNACH and :PARAM_POSCON ";
        ZaprosGrp=ZaprosGrp+" and  IDSKL_RGOTRSPIS_DV="+IntToStr(IdSkl);
        }

ZaprosGrp=ZaprosGrp+" group by NAMEGN, IDGN";

Grp->Active=false;
Grp->SelectSQL->Clear();
Grp->SelectSQL->Add(ZaprosGrp);
Grp->ParamByName("PARAM_POSNACH")->AsDateTime=DateNach->DateTime;
Grp->ParamByName("PARAM_POSCON")->AsDateTime=DateCon->DateTime;
Grp->ParamByName("PARAM_IDTYPE_PRICE")->AsInteger=IdTypePrice;
Grp->Active=true;

//шапка
PrintForm->SS->BeginUpdate();
OutputZagolovokReport(PrintForm);

//таблица
SumReport=0;
Grp->First();
while(!Grp->Eof)
        {
        SumReport=SumReport+GrpSUMM->AsFloat;
        OutputStringGrp(PrintForm);numRow++;
        //SumReport=SumReport+GrpSUMMA->AsFloat;
        porNumStr=1;
        El->Active=false;

        String ZaprosEl="select  NAMENOM, NAMEED, ZNACH_PRICE, SUM(KOL_RGOTRSPIS_DV)  AS SUMKOL";
        ZaprosEl=ZaprosEl+" from  RGOTRSPIS_DV ";
        ZaprosEl=ZaprosEl+" left outer join SNOM on IDNOM_RGOTRSPIS_DV=IDNOM";
        ZaprosEl=ZaprosEl+" left outer join SGRPNOM on IDGRPNOM=IDGN";
        ZaprosEl=ZaprosEl+" left outer join SED on IDBASEDNOM=IDED";
        ZaprosEl=ZaprosEl+" left outer join SPRICE on (IDNOM_PRICE=IDNOM and IDTYPE_PRICE=:PARAM_IDTYPE_PRICE)";
        ZaprosEl=ZaprosEl+" where (POSDOC_RGOTRSPIS_DV  between :PARAM_POSNACH and :PARAM_POSCON)";
        ZaprosEl=ZaprosEl+" and  (IDGN=:PARAM_IDGN) ";


        if (IdSkl!=0)
                {
                ZaprosEl=ZaprosEl+" and  IDSKL_RGOTRSPIS_DV="+IntToStr(IdSkl);
                }

        ZaprosEl=ZaprosEl+" group by NAMENOM, NAMEED, ZNACH_PRICE ";

		El->SelectSQL->Clear();
        El->SelectSQL->Add(ZaprosEl);
        El->ParamByName("PARAM_POSNACH")->AsDateTime=DateNach->DateTime;
        El->ParamByName("PARAM_POSCON")->AsDateTime=DateCon->DateTime;
        El->ParamByName("PARAM_IDGN")->AsInteger=GrpIDGN->AsInteger;
        El->ParamByName("PARAM_IDTYPE_PRICE")->AsInteger=IdTypePrice;
        El->Active=true;
        El->First();
        while(!El->Eof)
                {
                OutputString(PrintForm);numRow++;
                porNumStr++;
                El->Next();
                }

        porNumStrGrp++;
        Grp->Next();
        }

OutputPodavalReport(PrintForm);
PrintForm->SS->EndUpdate();
PrintForm->Show();
}

//------------------------------------------------------------------------------
void TFormaDialogaReportOtrSpis::OutputString(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IntToStr(porNumStr);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=ElNAMENOM->AsString;numCol++;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=ElSUMKOL->AsString+" "+ElNAMEED->AsString;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(ElZNACH_PRICE->AsFloat*ElSUMKOL->AsFloat,ffFixed,10,2);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

}
//------------------------------------------------------------------------------
void TFormaDialogaReportOtrSpis::OutputStringGrp(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IntToStr(porNumStrGrp);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=GrpNAMEGN->AsString;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=GrpSUMKOL->AsString;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(GrpSUMM->AsFloat,ffFixed,10,2);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;


}
//---------------------------------------------------------------------------
void TFormaDialogaReportOtrSpis::OutputZagolovokReport(TSheetEditor *prForm)
{
        TcxSSHeader *cHeader;
        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 30;
        cHeader->Size[2] = 200;
        cHeader->Size[3] = 100;
        cHeader->Size[4] = 100;
        cHeader->Size[5] = 100;
        cHeader->Size[6] = 100;

numRow=2;
numCol=3;
TcxSSCellObject *cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Отрицательное списание номенклатуры  за период с "+DateToStr(DateNach->Date)
                        +" по "+DateToStr(DateCon->Date);
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (IdSkl==0)
        {
        cell->Text="Склад: по всем складам. ";
        }
else
        {
        cell->Text="Склад: "+NameSkladEdit->Text;;
        }
delete cell;
numRow++;



numCol=1;

//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="№";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Наименование";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Количество";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//Сумма
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Сумма";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++; 
numRow++;
}
//------------------------------------------------------------------------------
void TFormaDialogaReportOtrSpis::OutputPodavalReport(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Всего: ";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(SumReport,ffFixed,10,2);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
}
//---------------------------------------------------------------

void __fastcall TFormaDialogaReportOtrSpis::ButtonReportPoDocClick(
      TObject *Sender)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
SumReport=0;
porNumStrGrp=1;
String ZaprosGrp="";

ZaprosGrp=          " select  NAMEGN, IDGN, SUM(KOL_RGOTRSPIS_DV)  AS SUMKOL , SUM(KOL_RGOTRSPIS_DV*ZNACH_PRICE)  AS SUMM" ;
ZaprosGrp=ZaprosGrp+" from RGOTRSPIS_DV ";
ZaprosGrp=ZaprosGrp+" left outer join SNOM on IDNOM_RGOTRSPIS_DV=IDNOM";
ZaprosGrp=ZaprosGrp+" left outer join SGRPNOM on IDGRPNOM=IDGN";

ZaprosGrp=ZaprosGrp+" left outer join SPRICE on (IDNOM_PRICE=IDNOM and IDTYPE_PRICE=:PARAM_IDTYPE_PRICE)";

if (IdDoc==0)
        {
        ZaprosGrp=ZaprosGrp+" where POSDOC_RGOTRSPIS_DV  between :PARAM_POSNACH and :PARAM_POSCON ";
        }
else
        {
        ZaprosGrp=ZaprosGrp+" where POSDOC_RGOTRSPIS_DV  between :PARAM_POSNACH and :PARAM_POSCON ";
        ZaprosGrp=ZaprosGrp+" and  IDDOC_RGOTRSPIS_DV="+IntToStr(IdDoc);
        }

ZaprosGrp=ZaprosGrp+" group by NAMEGN, IDGN";

Grp->Active=false;
Grp->SelectSQL->Clear();
Grp->SelectSQL->Add(ZaprosGrp);
Grp->ParamByName("PARAM_POSNACH")->AsDateTime=DateNach->DateTime;
Grp->ParamByName("PARAM_POSCON")->AsDateTime=DateCon->DateTime;
Grp->ParamByName("PARAM_IDTYPE_PRICE")->AsInteger=IdTypePrice;
Grp->Active=true;

//шапка
PrintForm->SS->BeginUpdate();
OutputZagolovokReport(PrintForm);

//таблица
SumReport=0;
Grp->First();
while(!Grp->Eof)
        {
        SumReport=SumReport+GrpSUMM->AsFloat;
        OutputStringGrp(PrintForm);numRow++;
        //SumReport=SumReport+GrpSUMMA->AsFloat;
        porNumStr=1;
        El->Active=false;

        String ZaprosEl="select  NAMENOM, NAMEED, SUM(KOL_RGOTRSPIS_DV)  AS SUMKOL, ZNACH_PRICE";
        ZaprosEl=ZaprosEl+" from  RGOTRSPIS_DV ";
        ZaprosEl=ZaprosEl+" left outer join SNOM on IDNOM_RGOTRSPIS_DV=IDNOM";
        ZaprosEl=ZaprosEl+" left outer join SGRPNOM on IDGRPNOM=IDGN";
        ZaprosEl=ZaprosEl+" left outer join SED on IDBASEDNOM=IDED";
        ZaprosEl=ZaprosEl+" left outer join SPRICE on (IDNOM_PRICE=IDNOM and IDTYPE_PRICE=:PARAM_IDTYPE_PRICE)";
        ZaprosEl=ZaprosEl+" where (POSDOC_RGOTRSPIS_DV  between :PARAM_POSNACH and :PARAM_POSCON)";
        ZaprosEl=ZaprosEl+" and  (IDGN=:PARAM_IDGN) ";


        if (IdDoc!=0)
                {
                ZaprosEl=ZaprosEl+" and  IDDOC_RGOTRSPIS_DV="+IntToStr(IdDoc);
                }

        ZaprosEl=ZaprosEl+" group by NAMENOM, NAMEED, ZNACH_PRICE ";

		El->SelectSQL->Clear();
        El->SelectSQL->Add(ZaprosEl);
        El->ParamByName("PARAM_POSNACH")->AsDateTime=DateNach->DateTime;
        El->ParamByName("PARAM_POSCON")->AsDateTime=DateCon->DateTime;
        El->ParamByName("PARAM_IDGN")->AsInteger=GrpIDGN->AsInteger;
        El->ParamByName("PARAM_IDTYPE_PRICE")->AsInteger=IdTypePrice;
        El->Active=true;
        El->First();
        while(!El->Eof)
                {
                OutputString(PrintForm);numRow++;
                porNumStr++;
                El->Next();
                }

        porNumStrGrp++;
        Grp->Next();
        }

OutputPodavalReport(PrintForm);

if (IdDoc!=0)
        {
        TcxSSCellObject *cell;
        cell = PrintForm->SS->ActiveSheet->GetCellObject(2, 3);
        cell->Text="Документ:  "+LabelDoc->Caption;
        delete cell;
        }
        
PrintForm->SS->EndUpdate();
PrintForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportOtrSpis::TypePriceComboBoxChange(
      TObject *Sender)
{
        TypePrice->First();
        TypePrice->MoveBy(TypePriceComboBox->ItemIndex);
        IdTypePrice=TypePriceID_TPRICE->AsInteger;        
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportOtrSpis::DateNachChange(TObject *Sender)
{
PosNachLabel->Caption=DateTimeToStr(DateNach->DateTime);        
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportOtrSpis::DateConChange(TObject *Sender)
{
PosConLabel->Caption=DateTimeToStr(DateCon->DateTime);        
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportOtrSpis::BitBtnNachPeriodaClick(
      TObject *Sender)
{
if(DateNach->Kind==dtkTime)
        {
        DateNach->Kind=dtkDate;
        }
else
        {
        DateNach->Kind=dtkTime;
        }        
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportOtrSpis::BitBtnConPeriodaClick(
      TObject *Sender)
{
if(DateCon->Kind==dtkTime)
        {
        DateCon->Kind=dtkDate;
        }
else
        {
        DateCon->Kind=dtkTime;
        }        
}
//---------------------------------------------------------------------------

