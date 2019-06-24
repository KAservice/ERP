//---------------------------------------------------------------------------

#include "glPCH.h"
#pragma hdrstop

#include "UFormaInputCode.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxTextEdit"
#pragma link "cxCalc"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaInputCode::TFormaInputCode(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaInputCode::FormCreate(TObject *Sender)
{
CodeEdit->Text="";
KolEdit->Text="1";
        
}
//---------------------------------------------------------------------------
void __fastcall TFormaInputCode::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if (Vibor==true)
        {
        try {if(FOnCloseForm) FOnCloseForm(this); } catch (...){}
        }
}
//---------------------------------------------------------------------------
void __fastcall TFormaInputCode::CodeEditKeyPress(TObject *Sender, char &Key)
{
if (Key==VK_RETURN)
		{
		KolEdit->SetFocus();
		}

if (Key==VK_ESCAPE)
		{
		OutReady=false;
		Close();
		}
	
}
//---------------------------------------------------------------------------

void __fastcall TFormaInputCode::KolEditKeyPress(TObject *Sender, char &Key)
{
if (Key==VK_RETURN)
		{
		OutReady=true;
		Code=StrToInt(CodeEdit->Text);
		Close();
		Kol=StrToFloat(KolEdit->Text);
		}

if (Key==VK_ESCAPE)
		{
		OutReady=false;
		Close();
		}	
}
//---------------------------------------------------------------------------

