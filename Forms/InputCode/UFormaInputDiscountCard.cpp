//---------------------------------------------------------------------------
#include "glPCH.h"
#pragma hdrstop

#include "UFormaInputDiscountCard.h"
#include "UDM.h"
#include "UScaner.h"
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
extern TScaner * glScaner;

//---------------------------------------------------------------------------
__fastcall TFormaInputDiscountCard::TFormaInputDiscountCard(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaInputDiscountCard::FormCreate(TObject *Sender)
{
InputTextEdit->Text="";
OutReady=false;
}
//---------------------------------------------------------------------------
void __fastcall TFormaInputDiscountCard::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if (Vibor==true)
        {
        try {if(FOnCloseForm) FOnCloseForm(this); } catch (...){}
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormaInputDiscountCard::InputTextEditKeyPress(TObject *Sender,
      char &Key)
{
if (Key==VK_ESCAPE)
		{
		OutReady=false;
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

void __fastcall TFormaInputDiscountCard::FormActivate(TObject *Sender)
{
if (glScaner)if(glScaner->ConnectScaner) glScaner->ReadSh=ReadShtrihCodEvent;	
}
//---------------------------------------------------------------------------

void __fastcall TFormaInputDiscountCard::ReadShtrihCodEvent(int number, UnicodeString sh)
{
UnicodeString s=sh;

UnicodeString barcode_for_poisk="";

for (int i=1;i<=s.Length();i++)
	{
	if (s[i]=='0' ||  s[i]=='1' || s[i]=='2' ||	 s[i]=='3' || s[i]=='4' ||
	   s[i]=='5' || s[i]=='6' ||  s[i]=='7' ||  s[i]=='8' || s[i]=='9' )
		{
		barcode_for_poisk=barcode_for_poisk+s[i];
		}
	else
		{
		if (barcode_for_poisk.Length()!=0)
			{
            break;
			}
		}
	}


InputTextEdit->Text=barcode_for_poisk;
}
//---------------------------------------------------------------
