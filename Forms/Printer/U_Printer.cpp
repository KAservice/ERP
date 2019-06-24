//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "U_Printer.h"



//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
extern String DopStrL(String Str, String Symbol, int Len);
//---------------------------------------------------------------------------
__fastcall T_Printer::T_Printer(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall T_Printer::FormCreate(TObject *Sender)
{

Girn=false;
}
//---------------------------------------------------------------------------

void __fastcall T_Printer::FormClose(TObject *Sender, TCloseAction &Action)
{
Action=caFree;
}
//---------------------------------------------------------------------------


bool T_Printer::Connect(void)
{
bool result=false;
if (TypePrinter=="printer_shtrih_500")
        {
        Shtrih500=new TShtrih500(Application);
        Shtrih500->ComName=ComName;
        Shtrih500->TypePrinter=TypePrinter;
        if (Shtrih500->Connect()==true)
                {
                result=true;
                }
        else
                {
                result=false;
                }

        }

return result;
}
//---------------------------------------------------------------------------
bool T_Printer::Disconnect(void)
{
bool result=false;
if (TypePrinter=="printer_shtrih_500")
        {
        if (Shtrih500->Disconnect()==true)
                {
                result=true;
                delete  Shtrih500;
                }
        else
                {
                result=false;
                }
        }

return result;
}
//---------------------------------------------------------------------------
bool T_Printer::PrintString(String str)
{
bool result=false;

if (TypePrinter=="printer_shtrih_500")
        {

                Shtrih500->Girn=Girn;
                Shtrih500->Alignment=Alignment;
                if (Shtrih500->PrintString(str)==true)
                        {
                        result=true;
                        }
                else
                        {
                        result=false;
                        }


        }


return result;
}
//-----------------------------------------------------------------------------
bool T_Printer::PrintLine(void)
{
bool result=false;
String str="-";

if (TypePrinter=="printer_shtrih_500")
        {

                Shtrih500->Girn=Girn;
                Shtrih500->Alignment=Alignment;
                if (Shtrih500->PrintLine()==true)
                        {
                        result=true;
                        }
                else
                        {
                        result=false;
                        }


        }

return result;

}
//------------------------------------------------------------------------------
bool T_Printer::Cut(int TypeCut)
{
bool result=false;

return result;
}
//-----------------------------------------------------------------------------
void T_Printer::GetSostPrinter(void)
{

}
//-----------------------------------------------------------------------------
bool T_Printer::ProvVosmPrint(void)
{
bool result=false;

return result;
}
//-----------------------------------------------------------------------------

