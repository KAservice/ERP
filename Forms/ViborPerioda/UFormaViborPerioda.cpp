//---------------------------------------------------------------------------
#include "glPCH.h"
#pragma hdrstop

#include "UFormaViborPerioda.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaViborPerioda::TFormaViborPerioda(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborPerioda::FormCreate(TObject *Sender)
{
OutReady=false;

DateTimePicker2->Date=Date();
unsigned short Year;
unsigned short Month;
unsigned short Day;
DateTimePicker2->Date.DecodeDate(&Year,&Month,&Day);
DateTimePicker1->Date=DateTimePicker2->Date-Day+1;

Time1->Time=DateTimePicker1->Time;
Time2->Time=DateTimePicker2->Time;
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborPerioda::FormClose(TObject *Sender,
      TCloseAction &Action)
{
try {if(FOnCloseForm) FOnCloseForm(this); } catch (...){}
Action=caFree;
}
//---------------------------------------------------------------------------




void __fastcall TFormaViborPerioda::Time1Change(TObject *Sender)
{
DateTimePicker1->Time=Time1->Time;
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborPerioda::Time2Change(TObject *Sender)
{
DateTimePicker2->Time=Time2->Time;  
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborPerioda::DateTimePicker1KeyPress(
      TObject *Sender, char &Key)
{
if (Key==VK_RETURN)
        {
        OutReady=true;
        Close();
        }        
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborPerioda::Time1KeyPress(TObject *Sender,
      char &Key)
{
if (Key==VK_RETURN)
        {
        OutReady=true;
        Close();
        }         
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborPerioda::DateTimePicker2KeyPress(
      TObject *Sender, char &Key)
{
if (Key==VK_RETURN)
        {
        OutReady=true;
        Close();
        }         
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborPerioda::Time2KeyPress(TObject *Sender,
      char &Key)
{
if (Key==VK_RETURN)
        {
        OutReady=true;
        Close();
        }         
}
//---------------------------------------------------------------------------





void __fastcall TFormaViborPerioda::ActionOKExecute(TObject *Sender)
{
OutReady=true;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborPerioda::ActionCloseExecute(TObject *Sender)
{
OutReady=false;
Close();
}
//---------------------------------------------------------------------------

