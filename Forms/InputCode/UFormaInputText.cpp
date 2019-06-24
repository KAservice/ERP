//---------------------------------------------------------------------------
#include "glPCH.h"
#pragma hdrstop

#include "UFormaInputText.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxTextEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaInputText::TFormaInputText(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaInputText::FormCreate(TObject *Sender)
{
InputTextEdit->Text="";
OutReady=false;
}
//---------------------------------------------------------------------------
void __fastcall TFormaInputText::FormClose(TObject *Sender,
      TCloseAction &Action)
{

try {if(FOnCloseForm) FOnCloseForm(this); } catch (...){}
Action=caFree;
}
//---------------------------------------------------------------------------


void __fastcall TFormaInputText::InputTextEditKeyPress(TObject *Sender,
      char &Key)
{
if (Key==VK_ESCAPE)
		{
		OutReady=false;
		InputText="";
		Close();
		}

if (Key==VK_RETURN)
		{
		OutReady=true;
		InputText=InputTextEdit->Text;
		Close();
		}	
}
//---------------------------------------------------------------------------

