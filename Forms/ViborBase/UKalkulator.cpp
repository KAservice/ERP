//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UKalkulator.h"
#include "UDM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TKalkulator::TKalkulator(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TKalkulator::FormCreate(TObject *Sender)
{
Tablo->Text="";
OutReady=false;        
}
//---------------------------------------------------------------------------
void __fastcall TKalkulator::FormClose(TObject *Sender,
      TCloseAction &Action)
{
try {if(FOnCloseForm) FOnCloseForm(this); } catch (...){}
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TKalkulator::knOKClick(TObject *Sender)
{
OutReady=true;
Result=StrToFloat(Tablo->Text);
Close();
}
//---------------------------------------------------------------------------
void __fastcall TKalkulator::knCClick(TObject *Sender)
{
OutReady=false;
Close();
}
//---------------------------------------------------------------------------
void __fastcall TKalkulator::kn1Click(TObject *Sender)
{
Tablo->Text=Tablo->Text+"1";
}
//---------------------------------------------------------------------------
void __fastcall TKalkulator::kn2Click(TObject *Sender)
{
Tablo->Text=Tablo->Text+"2";
}
//---------------------------------------------------------------------------
void __fastcall TKalkulator::kn3Click(TObject *Sender)
{
Tablo->Text=Tablo->Text+"3";
}
//---------------------------------------------------------------------------
void __fastcall TKalkulator::kn4Click(TObject *Sender)
{
 Tablo->Text=Tablo->Text+"4";
}
//---------------------------------------------------------------------------
void __fastcall TKalkulator::kn5Click(TObject *Sender)
{
 Tablo->Text=Tablo->Text+"5";
}
//---------------------------------------------------------------------------
void __fastcall TKalkulator::kn6Click(TObject *Sender)
{
Tablo->Text=Tablo->Text+"6";
}
//---------------------------------------------------------------------------
void __fastcall TKalkulator::kn7Click(TObject *Sender)
{
Tablo->Text=Tablo->Text+"7";
}
//---------------------------------------------------------------------------
void __fastcall TKalkulator::kn8Click(TObject *Sender)
{
Tablo->Text=Tablo->Text+"8";        
}
//---------------------------------------------------------------------------
void __fastcall TKalkulator::kn9Click(TObject *Sender)
{
Tablo->Text=Tablo->Text+"9";
}
//---------------------------------------------------------------------------
void __fastcall TKalkulator::kn0Click(TObject *Sender)
{
Tablo->Text=Tablo->Text+"0";
}
//---------------------------------------------------------------------------
void __fastcall TKalkulator::knCommaClick(TObject *Sender)
{
Tablo->Text=Tablo->Text+",";
}
//---------------------------------------------------------------------------
