//---------------------------------------------------------------------------
#include "glPCH.h"
#pragma hdrstop

#include "UAbout.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxLabel"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormAbout::TFormAbout(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormAbout::FormCreate(TObject *Sender)
{
 //
}
//---------------------------------------------------------------------------
void __fastcall TFormAbout::FormClose(TObject *Sender,
      TCloseAction &Action)
{
 //
Action=caFree;
}
//---------------------------------------------------------------------------
void TFormAbout::UpdateForm(void)
{
//


}
//----------------------------------------------------------------------------

void __fastcall TFormAbout::cxLabel2Click(TObject *Sender)
{

ShellExecute(Handle, "open", "http://www.kaserv.ru/",
0, 0, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TFormAbout::cxButtonCloseClick(TObject *Sender)
{
Close(); 	
}
//---------------------------------------------------------------------------

