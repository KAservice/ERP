//---------------------------------------------------------------------------


#pragma hdrstop

#include "UPrintBarCode3.h"
#include "UDM.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
extern UnicodeString GetBinareStructEAN13(UnicodeString sh_code);
//-------------------------------------------------------------------
TPrintBarCode3::TPrintBarCode3()
{


}
//-----------------------------------------------------------------------------
TPrintBarCode3::~TPrintBarCode3()
{


}
//----------------------------------------------------------------------------
void TPrintBarCode3::CreateBarCode(void)
{
LineWidth=2;     //1
LineHeight=30;
x=2;y=2;

TImageEditor *ImageEditor=new TImageEditor(Application);

ImageEditor->Image1->Width=203;   //150
ImageEditor->Image1->Height=150;

ImageEditor->Image1->Canvas->Font->Style<<fsBold;
ImageEditor->Image1->Canvas->Font->Color=clBlack;
ImageEditor->Image1->Canvas->TextOut(x,y,Zagolovok);

y=y+15;
ImageEditor->Image1->Canvas->TextOut(x,y,String2);

//штрих код
ImageEditor->Image1->Canvas->Pen->Width=LineWidth;
y=y+15;
AnsiString binare_struct=GetBinareStructEAN13(BarCodeValue);
for (int i=1; i<=binare_struct.Length(); i++)
        {
        if (binare_struct[i]=='2')
                {
                ImageEditor->Image1->Canvas->MoveTo(x,y);
				ImageEditor->Image1->Canvas->LineTo(x,y+LineHeight+10);
                }

        if (binare_struct[i]=='1')
                {
                ImageEditor->Image1->Canvas->MoveTo(x,y);
                ImageEditor->Image1->Canvas->LineTo(x,y+LineHeight);
                }

        x=x+LineWidth;

		}

x=x+5;

ImageEditor->Image1->Canvas->Font->Color=clBlack;
ImageEditor->Image1->Canvas->Font->Size=8;
ImageEditor->Image1->Canvas->TextOut(x,y+5,"Цена:");

ImageEditor->Image1->Canvas->Font->Color=clBlack;
ImageEditor->Image1->Canvas->Font->Size=12;
ImageEditor->Image1->Canvas->TextOut(x,y+20,PriceNom);

x=2;
y=y+LineHeight+5;
ImageEditor->Image1->Canvas->Font->Size=10;
ImageEditor->Image1->Canvas->TextOut(x,y,BarCodeValue);

y=y+15;
ImageEditor->Image1->Canvas->TextOut(x,y,NameNom);




AnsiString s=StringForPrint;


	TStringList * strings=new TStringList();

	s=WrapText(s,30);
	strings->Text=s;

	for (int i=0;i<strings->Count;i++)
		{
		AnsiString print_str=strings->Strings[i];
		y=y+15;
		ImageEditor->Image1->Canvas->Font->Size=8;
		ImageEditor->Image1->Canvas->TextOut(x,y,print_str);
		}
	delete strings;

y=y+15;
ImageEditor->Image1->Canvas->TextOut(x,y,"Товар сертифицирован");

//установим размер этикетки
ImageEditor->dxComponentPrinter1Link1->PrinterPage->PageSize->Y=40000;
ImageEditor->dxComponentPrinter1Link1->PrinterPage->PageSize->X=57000;
ImageEditor->Show();
}
//----------------------------------------------------------------------------

