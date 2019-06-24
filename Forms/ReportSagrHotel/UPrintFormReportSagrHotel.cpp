//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UPrintFormReportSagrHotel.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPrintFormReportSagrHotel *PrintFormReportSagrHotel;
//---------------------------------------------------------------------------
__fastcall TPrintFormReportSagrHotel::TPrintFormReportSagrHotel(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPrintFormReportSagrHotel::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Action=caFree;        
}
//---------------------------------------------------------------------------
void __fastcall TPrintFormReportSagrHotel::ToolButton2Click(
      TObject *Sender)
{
short Sel;
int a;
int b;
int c;
int d;
F1->GetSelection(Sel,a,b,c,d);
//F1->SetSelection (2, 2, 10, 10);
ShowMessage(IntToStr(Sel)+" "+IntToStr(a)+" "+IntToStr(b)+" "+IntToStr(c)+" "+IntToStr(d));        
}
//---------------------------------------------------------------------------
