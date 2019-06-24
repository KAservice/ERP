//---------------------------------------------------------------------------

#pragma hdrstop

#include "UPrintBarCode2.h"
#include "UDMSprNom.h"
#include "UDMSprARM.h"
#include "UDMSprEd.h"


//---------------------------------------------------------------------------

#pragma package(smart_init)

extern UnicodeString CommaToPixel(UnicodeString value);
extern UnicodeString GetBinareStructEAN13(UnicodeString sh_code);
//-------------------------------------------------------------------
TclPrintBarCode2::TclPrintBarCode2()
{


}
//-----------------------------------------------------------------------------
TclPrintBarCode2::~TclPrintBarCode2()
{


}
//----------------------------------------------------------------------------
void TclPrintBarCode2::CreatePrintBarCode(void)
{
Col=1;Row=1;
ImageEditor=new TImageEditor(Application);
ImageEditor->Height=1300+ImageEditor->Panel1->Height;
ImageEditor->Width=720;
ImageEditor->Image1->Height=950;
ImageEditor->Image1->Width=690;//700


start_x=0; start_y=0;

for (int i=0; i<List->Count;i++)
        {
        ElementSpiska=(TElementSpiskaPrintPrice*)List->Items[i];
        if (ElementSpiska->Grp==true)
                {
                PrintBarCode_OutputGrp();
                }
        else
                {
                TDMSprNom * DMSprNom=new TDMSprNom(Application);
                DMSprNom->IdTypePrice=IdTypePrice;
                DMSprNom->OpenElement(ElementSpiska->Id);

                TDMSprEd *DMSprEd=new TDMSprEd(Application);
                DMSprEd->OpenElement(ElementSpiska->IdEd);


                for (int i=0; i<ElementSpiska->Kol; i++)
                        {
                        PrintBarCode_OutputElement(DMSprNom->ElementNAMENOM->AsString,
                                         DMSprNom->ElementCODENOM->AsString,
                                         FloatToStrF(DMSprNom->ElementZNACH_PRICE->AsFloat,ffFixed,10,2),
                                         ElementSpiska->NameEd,
                                         ElementSpiska->Kol,
                                         DMSprEd->ElementSHED->AsString);

                        Col++;Row++;
                        if (Col>=5)
                                {
                                Col=1;
                                start_x=0;
                                start_y=start_y+120;
                                }
                        else
                                {
                                 start_x=start_x+170;
                                }
                        }

                if (Row>=32) break;

                delete DMSprEd;
                delete DMSprNom;
                }

        }


ImageEditor->Show();
}
//----------------------------------------------------------------------------
void TclPrintBarCode2::PrintBarCode_OutputGrp(void)
{
///

}
//-----------------------------------------------------------------------------
void TclPrintBarCode2::PrintBarCode_OutputZagolovok(void)
{


}
//-----------------------------------------------------------------------------
void TclPrintBarCode2::PrintBarCode_OutputElement(AnsiString name,
                                                AnsiString code,
                                                AnsiString price,
                                                AnsiString name_ed,
                                                int kol,
                                                AnsiString bar_code)
{
int LineWidth=1;
int LineHeight=40;
AnsiString binare_struct=GetBinareStructEAN13(bar_code);

x=start_x; y=start_y;
//ImageEditor->Image1->Canvas->Font->Name="Arial";
ImageEditor->Image1->Canvas->Font->Color=clBlack;
if (name.Length()>26)
        {
        name.SetLength(26);
        }
ImageEditor->Image1->Canvas->TextOut(x+10,y+3,name);

ImageEditor->Image1->Canvas->Pen->Width=LineWidth;

y=y+20;
x=x+10;

for (int i=1; i<=binare_struct.Length(); i++)
        {
        if (binare_struct[i]=='2')
                {
                ImageEditor->Image1->Canvas->MoveTo(x,y);
                ImageEditor->Image1->Canvas->LineTo(x,y+LineHeight+20);
                }

        if (binare_struct[i]=='1')
                {
                ImageEditor->Image1->Canvas->MoveTo(x,y);
                ImageEditor->Image1->Canvas->LineTo(x,y+LineHeight);
                }

        x=x+LineWidth;

        }


//ImageEditor->Image1->Canvas->Font->Style<<fsBold;
ImageEditor->Image1->Canvas->Font->Color=clBlack;
ImageEditor->Image1->Canvas->TextOut(x+5,y+(LineHeight/3),"Öåíà");

ImageEditor->Image1->Canvas->Font->Style<<fsBold;
ImageEditor->Image1->Canvas->Font->Color=clBlack;
ImageEditor->Image1->Canvas->Font->Size=12;
ImageEditor->Image1->Canvas->TextOut(x+5,y+LineHeight*2/3,price);


ImageEditor->Image1->Canvas->Font->Size=8;
ImageEditor->Image1->Canvas->TextOut(x+5,y+LineHeight*2/3+20,"Åä. "+name_ed);

ImageEditor->Image1->Canvas->Font->Size=8;
x=start_x+10;
y=y+LineHeight+20;
ImageEditor->Image1->Canvas->TextOut(x,y,bar_code+" / "+code);
//x=start_x+10;
//y=y+20;
//ImageEditor->Image1->Canvas->TextOut(x,y,);



}
//-----------------------------------------------------------------------------