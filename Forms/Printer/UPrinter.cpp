//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UPrinter.h"



//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
extern String DopStrL(String Str, String Symbol, int Len);
//---------------------------------------------------------------------------
__fastcall TCheckPrinter::TCheckPrinter(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCheckPrinter::FormCreate(TObject *Sender)
{

Girn=false;
}
//---------------------------------------------------------------------------

void __fastcall TCheckPrinter::FormClose(TObject *Sender, TCloseAction &Action)
{
Action=caFree;
}
//---------------------------------------------------------------------------


bool TCheckPrinter::Connect(void)
{
bool result=false;
if (TypePrinter=="printer_shtrih_500")
        {
        Shtrih500=new TShtrih500(Application);
        Shtrih500->ComName=ComName;
        Shtrih500->TypePrinter=TypeKKM;
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
bool TCheckPrinter::Disconnect(void)
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
bool TCheckPrinter::PrintString(String str)
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
bool TCheckPrinter::PrintLine(void)
{
bool result=false;
String str="-";

if (TypePrinter=="printer_shtrih_500")
        {

                Shtrih500->Girn=Girn;
                Shtrih500->Alignment=Alignment;
                if (Shtrih500->PrintLine(str)==true)
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
bool TCheckPrinter::Cut(int TypeCut)
{
bool result=false;

return result;
}
//-----------------------------------------------------------------------------
void TCheckPrinter::GetSostPrinter(void)
{

}
//-----------------------------------------------------------------------------
bool TCheckPrinter::ProvVosmPrint(void)
{
bool result=false;

return result;
}
//-----------------------------------------------------------------------------

