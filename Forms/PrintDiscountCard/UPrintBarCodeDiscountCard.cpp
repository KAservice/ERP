//---------------------------------------------------------------------------


#pragma hdrstop

#include "UPrintBarCodeDiscountCard.h"
#include "UDM.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
extern UnicodeString GetBinareStructEAN13(UnicodeString sh_code);
//-------------------------------------------------------------------
TPrintBarCodeDiscountCard::TPrintBarCodeDiscountCard()
{


}
//-----------------------------------------------------------------------------
TPrintBarCodeDiscountCard::~TPrintBarCodeDiscountCard()
{


}
//----------------------------------------------------------------------------
void TPrintBarCodeDiscountCard::CreateBarCode(void)
{
LineWidth=1;
LineHeight=30;

AnsiString binare_struct=GetBinareStructEAN13(BarCodeValue);

TImageEditor *ImageEditor=new TImageEditor(Application);

ImageEditor->Image1->Width=160;
ImageEditor->Image1->Height=90;

ImageEditor->Image1->Canvas->Font->Style<<fsBold;
ImageEditor->Image1->Canvas->Font->Color=clBlack;
ImageEditor->Image1->Canvas->TextOut(2,1,TopString);

ImageEditor->Image1->Canvas->Pen->Width=LineWidth;

x=2; y=15;

for (int i=1; i<=binare_struct.Length(); i++)
        {
        if (binare_struct[i]=='2')
				{
                ImageEditor->Image1->Canvas->MoveTo(x,y);
				ImageEditor->Image1->Canvas->LineTo(x,y+LineHeight+5);
                }

		if (binare_struct[i]=='1')
                {
                ImageEditor->Image1->Canvas->MoveTo(x,y);
                ImageEditor->Image1->Canvas->LineTo(x,y+LineHeight);
				}

		x=x+LineWidth;

		}

x=2;
y=y+LineHeight+7;
ImageEditor->Image1->Canvas->Font->Size=10;
ImageEditor->Image1->Canvas->TextOut(x,y,BarCodeValue);
x=2;
y=y+15;
ImageEditor->Image1->Canvas->Font->Size=8;
ImageEditor->Image1->Canvas->TextOut(x,y,BottomString);

ImageEditor->Show();
}
//----------------------------------------------------------------------------