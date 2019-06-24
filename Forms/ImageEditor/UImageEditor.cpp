//---------------------------------------------------------------------------
#include "glPCH.h"
#include <vcl.h>
#pragma hdrstop

#include "UImageEditor.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxBkgnd"
#pragma link "dxPrnDev"
#pragma link "dxPrnPg"
#pragma link "dxPSCompsProvider"
#pragma link "dxPSCore"
#pragma link "dxPSEdgePatterns"
#pragma link "dxPSEngn"
#pragma link "dxPSFillPatterns"
#pragma link "dxPSGlbl"
#pragma link "dxPSGraphicLnk"
//#pragma link "dxPSImgLnk"
#pragma link "dxPSUtl"
#pragma link "dxWrap"
#pragma link "dxPSImgLnk"
//#pragma link "dxPSImgLnk"
#pragma link "dxPSImgLnk"
#pragma link "dxPSImgLnk"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TImageEditor::TImageEditor(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TImageEditor::FormCreate(TObject *Sender)
{
///
}
//---------------------------------------------------------------------------
void __fastcall TImageEditor::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TImageEditor::tbsPreeViewClick(TObject *Sender)
{
dxComponentPrinter1->ReportLink[0]->Preview(true);         
}
//---------------------------------------------------------------------------
void __fastcall TImageEditor::tbsPrintClick(TObject *Sender)
{
dxComponentPrinter1->ReportLink[0]->Print(true, NULL);        
}
//---------------------------------------------------------------------------
void __fastcall TImageEditor::tbsPageSetupClick(TObject *Sender)
{
dxComponentPrinter1->ReportLink[0]->PageSetup();          
}
//---------------------------------------------------------------------------

void __fastcall TImageEditor::cxButtonCloseClick(TObject *Sender)
{
Close();	
}
//---------------------------------------------------------------------------

