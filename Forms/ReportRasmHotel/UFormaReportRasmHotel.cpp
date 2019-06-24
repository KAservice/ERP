//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaReportRasmHotel.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaReportRasmHotel::TFormaReportRasmHotel(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaReportRasmHotel::FormCreate(TObject *Sender)
{
DateCon->Date=Date();
unsigned short Year;
unsigned short Month;
unsigned short Day;
DateCon->Date.DecodeDate(&Year,&Month,&Day);
DateNach->Date=DateCon->Date-Day+1;

}
//---------------------------------------------------------------------------
void __fastcall TFormaReportRasmHotel::FormClose(TObject *Sender,
      TCloseAction &Action)
{
IBQRegRasm->Active=false;
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TFormaReportRasmHotel::ButtonCloseClick(
      TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormaReportRasmHotel::EndEdit(TObject *Sender)
{


EditRekvisit=NO;
IdDochForm=NULL;
}

//---------------------------------------------------------------
void __fastcall TFormaReportRasmHotel::ButtonRunClick(
      TObject *Sender)
{
TPrintFormAll  *PrintForm=new TPrintFormAll(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
porNumStrGrp=1;


//шапка
OutputZagolovokReport(PrintForm);
ReportPoNomeramHotel(PrintForm);
OutputPodavalReport(PrintForm);

PrintForm->Show();
}

//---------------------------------------------------------------------------
void TFormaReportRasmHotel::ReportPoNomeramHotel(TPrintFormAll *prForm)
{

        IBQRegRasm->Active=false;
        IBQRegRasm->Active=true;
        porNumStr=1;
        IBQRegRasm->First();
        while(!IBQRegRasm->Eof)
                {
                OutputStringGost(prForm);

                numRow++;
                IBQRegRasm->Next();
                porNumStr++;
                }

}

//---------------------------------------------------------------------------
void TFormaReportRasmHotel::OutputZagolovokReport(TPrintFormAll *prForm)
{
numRow=2;
numCol=1;

prForm->F1->SheetName[1]="Часть1";
prForm->F1->ShowGridLines=false;

prForm->F1->Row=numRow;
prForm->F1->Col=3;
prForm->F1->SetAlignment( 2, 0, 2, 0);
prForm->F1->RowHeight[numRow]=500;
prForm->F1->Text="Текущее размещение гостей "; numRow++;

numCol=2;
prForm->F1->Row=numRow;
prForm->F1->RowHeight[numRow]=500;
//порядковый номер строки
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 2, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text="№";
prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);
prForm->F1->ColWidth[numCol]=500;
numCol++;

//номер
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 2, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text="Номер ";
prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);
prForm->F1->ColWidth[numCol]=1000;
numCol++;
//номер
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 2, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text="Размещение ";
prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);
prForm->F1->ColWidth[numCol]=3000;
numCol++;
//гость
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 2, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text="Гость";
prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);
prForm->F1->ColWidth[numCol]=3000;
numCol++;
//выезд
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 2, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text="Выезд";
prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);
prForm->F1->ColWidth[numCol]=1700;
numCol++;

//мест
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 2, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text="Мест";
prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);
prForm->F1->ColWidth[numCol]=1000;
numCol++;

numRow++;
}

//------------------------------------------------------------------------------
void TFormaReportRasmHotel::OutputStringNomer( TPrintFormAll *prForm)
{

numCol=2;
prForm->F1->Row=numRow;
//порядковый номер строки
prForm->F1->Col=numCol;
prForm->F1->SetFont ( "MS Sans Serif", 14, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text="";
prForm->F1->SetBorder(-1,1,0,1,1,-1,1,1,1,clBlack,1);
//prForm->F1->SetPattern(1,clGray,clSilver);
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);
numCol++;
//номер
prForm->F1->Col=numCol;
//prForm->F1->SetPattern(1,clGray,clSilver);
prForm->F1->SetFont ( "MS Sans Serif", 14, 1, 0, 0, 0, 1, 1, 1 );
//prForm->F1->Text="Дата: "+DateToStr(TekDate);
prForm->F1->SetBorder(-1,0,0,1,1,-1,1,1,1,clBlack,1);
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);
numCol++;
//заезд
prForm->F1->Col=numCol;
//prForm->F1->SetPattern(1,clGray,clSilver);
prForm->F1->SetAlignment( 2, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 14, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text="";
prForm->F1->SetBorder(-1,1,1,1,1,-1,1,1,1,clBlack,1);
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);
numCol++;
//выезд
prForm->F1->Col=numCol;
//prForm->F1->SetPattern(1,clGray,clSilver);
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 14, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text="";
prForm->F1->SetBorder(-1,1,1,1,1,-1,1,1,1,clBlack,1);
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);
numCol++;
//мест
prForm->F1->Col=numCol;
//prForm->F1->SetPattern(1,clGray,clSilver);
prForm->F1->SetFont ( "MS Sans Serif", 14, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text="";
prForm->F1->SetBorder(-1,1,1,1,1,-1,1,1,1,clBlack,1);
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);
numCol++;


}

//------------------------------------------------------------------------------
void TFormaReportRasmHotel::OutputStringGost(TPrintFormAll *prForm)
{

numCol=2;
prForm->F1->Row=numRow;
//порядковый номер строки
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->Text=IntToStr(porNumStr);
prForm->F1->SetFont ( "MS Sans Serif", 8, 0, 0, 0, 0, clNavy, clNavy, 1 );
prForm->F1->SetBorder(-1,1,1,1,0,-1,1,1,1,1,1);
numCol++;

//номер
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 2, 1, 2, 0);
prForm->F1->SetBorder(-1,1,1,1,0,-1,1,1,1,clBlack,1);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, clNavy, clNavy, 1 );
prForm->F1->Text=IBQRegRasmNAME_NOMHOT->AsString+" ("
                        +IBQRegRasmKOLM_NOMHOT->AsString+")";
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);
numCol++;

//номер
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 2, 1, 2, 0);
prForm->F1->SetBorder(-1,1,1,1,0,-1,1,1,1,clBlack,1);
prForm->F1->SetFont ( "MS Sans Serif", 8, 0, 0, 0, 0, clNavy, clNavy, 1 );
prForm->F1->Text=IBQRegRasmNAME_ZRASM->AsString;
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);


numCol++;

//гость
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 2, 1, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 8, 0, 0, 0, 0, clNavy, clNavy, 1 );

        prForm->F1->Text=IBQRegRasmNAMEKLIENT->AsString;

prForm->F1->SetBorder(-1,1,1,1,0,-1,1,1,1,clBlack,1);
numCol++;
//выезд
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 8, 0, 0, 0, 0, clNavy, clNavy, 1 );

prForm->F1->Text=IBQRegRasmPOSCON_RGRASM->AsString;

prForm->F1->SetBorder(-1,1,1,1,0,-1,1,1,1,clBlack,1);
numCol++;



//мест
prForm->F1->Col=numCol;
prForm->F1->SetFont ( "MS Sans Serif", 8, 0, 0, 0, 0, clNavy, clNavy, 1 );

        prForm->F1->Text=IBQRegRasmKOLMEST_RGRASM->AsString;

prForm->F1->SetBorder(-1,1,1,1,0,-1,1,1,1,clBlack,1);
numCol++;


}

//--------------------------------------------------------------------------
void TFormaReportRasmHotel::OutputPodavalReport(TPrintFormAll *prForm)
{

numCol=2;
prForm->F1->Row=numRow;
//порядковый номер строки
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->Text="";
prForm->F1->SetFont ( "MS Sans Serif", 8, 0, 0, 0, 0, clNavy, clNavy, 1 );
prForm->F1->SetBorder(-1,0,0,1,0,-1,1,1,1,1,1);
numCol++;

//номер
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 2, 1, 2, 0);
prForm->F1->SetBorder(-1,0,0,1,0,-1,1,1,1,clBlack,1);
prForm->F1->SetFont ( "MS Sans Serif", 8, 0, 0, 0, 0, clNavy, clNavy, 1 );
prForm->F1->Text="";
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);


numCol++;
//размещение
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 2, 1, 2, 0);
prForm->F1->SetBorder(-1,0,0,1,0,-1,1,1,1,clBlack,1);
prForm->F1->SetFont ( "MS Sans Serif", 8, 0, 0, 0, 0, clNavy, clNavy, 1 );
prForm->F1->Text="";
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);


numCol++;

//заезд
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 8, 0, 0, 0, 0, clNavy, clNavy, 1 );

        prForm->F1->Text="";

prForm->F1->SetBorder(-1,0,0,1,0,-1,1,1,1,clBlack,1);
numCol++;
//выезд
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 8, 0, 0, 0, 0, clNavy, clNavy, 1 );

        prForm->F1->Text="";

prForm->F1->SetBorder(-1,0,0,1,0,-1,1,1,1,clBlack,1);
numCol++;

//мест
prForm->F1->Col=numCol;
prForm->F1->SetFont ( "MS Sans Serif", 8, 0, 0, 0, 0, clNavy, clNavy, 1 );

        prForm->F1->Text="";

prForm->F1->SetBorder(-1,0,0,1,0,-1,1,1,1,clBlack,1);
numCol++;
}
//---------------------------------------------------------------------------

