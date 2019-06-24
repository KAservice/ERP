//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaPanelButtonTouch.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaPanelButtonTouch::TFormaPanelButtonTouch(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaPanelButtonTouch::FormClose(TObject *Sender,
      TCloseAction &Action)
{
try {if(FOnCloseForm) FOnCloseForm(this); } catch (...){}
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TFormaPanelButtonTouch::BitBtnCloseClick(TObject *Sender)
{
PressButton=NO;
Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormaPanelButtonTouch::BitBtn1Click(TObject *Sender)
{
PressButton=DelButton;
Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormaPanelButtonTouch::BitBtn2Click(TObject *Sender)
{
PressButton=XButton;
Close();        
}
//---------------------------------------------------------------------------
void __fastcall TFormaPanelButtonTouch::BitBtn3Click(TObject *Sender)
{
PressButton=ZButton;
Close();        
}
//---------------------------------------------------------------------------
