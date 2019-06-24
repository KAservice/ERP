//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UFormaEditBase.h"
#include "UFormaViborBase.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxTextEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaEditBase::TFormaEditBase(TComponent* Owner)
        : TForm(Owner)
{
OldName="";
}
//---------------------------------------------------------------------------
void __fastcall TFormaEditBase::FormClose(TObject *Sender,
      TCloseAction &Action)
{
try {if(FOnCloseForm) FOnCloseForm(this); } catch (...){}
Action=caFree;        
}
//---------------------------------------------------------------------------

void __fastcall TFormaEditBase::FormCreate(TObject *Sender)
{
NameBase->Text="";
ConnectString->Text="";
NumberARM->Text=0;
}
//---------------------------------------------------------------------------



void __fastcall TFormaEditBase::NameBaseKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaEditBase::ConnectStringKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaEditBase::NumberARMKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaEditBase::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("CreateConnect");		
}
//---------------------------------------------------------------------------

void __fastcall TFormaEditBase::ActionCloseExecute(TObject *Sender)
{
OutReady=false;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaEditBase::ActionOKExecute(TObject *Sender)
{
if (NameBase->Text=="")
		{
		ShowMessage("введите название информационной базы!");
		return;
		}
else
		{
		OutReady=true;
		Close();
		}
}
//---------------------------------------------------------------------------

