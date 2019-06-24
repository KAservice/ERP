//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UFormaViborPerioda.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaViborPerioda::TFormaViborPerioda(TComponent* Owner)
        : TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
}
//---------------------------------------------------------------------------
bool TFormaViborPerioda::Init(void)
{
bool result=false;

TypeEvent=0;

result=true;

return result;
}
//--------------------------------------------------------------------------
int TFormaViborPerioda::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaViborPerioda::FormCreate(TObject *Sender)
{

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

//получим ICallBack для передачи события в вызывающую форму
if(InterfaceOwnerObject)
	{
	IkanCallBack * i_callback=0;
	InterfaceOwnerObject->kanQueryInterface(IID_IkanCallBack,(void**)&i_callback);
	if (i_callback)
		{
		i_callback->kanExternalEvent(InterfaceImpl,ClsIdImpl,TypeEvent,NumberProcVibor);
		i_callback->kanRelease();
		}
	}


Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------




void __fastcall TFormaViborPerioda::Time1Change(TObject *Sender)
{
DateTimePicker1->Time=Time1->Time;
PosNach=DateTimePicker1->DateTime;
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborPerioda::Time2Change(TObject *Sender)
{
DateTimePicker2->Time=Time2->Time;
PosCon=DateTimePicker2->DateTime;
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborPerioda::DateTimePicker1KeyPress(
      TObject *Sender, char &Key)
{
if (Key==VK_RETURN)
        {
		TypeEvent=1;
        Close();
        }        
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborPerioda::Time1KeyPress(TObject *Sender,
      char &Key)
{
if (Key==VK_RETURN)
        {
		TypeEvent=1;
        Close();
        }         
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborPerioda::DateTimePicker2KeyPress(
      TObject *Sender, char &Key)
{
if (Key==VK_RETURN)
        {
		TypeEvent=1;
        Close();
        }         
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborPerioda::Time2KeyPress(TObject *Sender,
      char &Key)
{
if (Key==VK_RETURN)
        {
		TypeEvent=1;
        Close();
        }         
}
//---------------------------------------------------------------------------





void __fastcall TFormaViborPerioda::ActionOKExecute(TObject *Sender)
{
TypeEvent=1;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborPerioda::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborPerioda::DateTimePicker1Change(TObject *Sender)
{
PosNach=DateTimePicker1->DateTime;
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborPerioda::DateTimePicker2Change(TObject *Sender)
{
PosCon=DateTimePicker2->DateTime;
}
//---------------------------------------------------------------------------

