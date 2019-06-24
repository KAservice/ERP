//---------------------------------------------------------------------------


#pragma hdrstop

#include "UPrintPriceNumber1.h"
#include "IDMSprNom.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)



//-------------------------------------------------------------------
TPrintPriceNumber1::TPrintPriceNumber1()
{


}
//-----------------------------------------------------------------------------
TPrintPriceNumber1::~TPrintPriceNumber1()
{


}
//----------------------------------------------------------------------------
bool TPrintPriceNumber1::Init(void)
{
bool result=false;



//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;
return result;
}
//-----------------------------------------------------------------------------
void TPrintPriceNumber1::CreatePrice1(void)
{
//
SE=new TSheetEditor(Application);
SE->SS->RowsAutoHeight=false;
if (!SE) return;
KolNaPage=0;
KolNaString=0;
x = 1;
y = 1;
SE->SS->BeginUpdate();
NumberPage=1;
SE->SS->ActiveSheet->Caption= "Стр."+IntToStr(NumberPage);
PrintPriceNumber1_OutputZagolovok();


for (int i=0; i<List->Count;i++)
        {
        ElementSpiska=(TElementSpiskaPrintPrice*)List->Items[i];
        if (ElementSpiska->Grp==true)
                {
                PrintPriceNumber1_OutputGrp();
                }
        else
                {
				IDMSprNom * DMSprNom;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&DMSprNom);
				DMSprNom->Init(InterfaceMainObject,0);
				DMSprNom->IdTypePrice=IdTypePrice;
                DMSprNom->OpenElement(ElementSpiska->Id);

                PrintPriceNumber1_OutputElement(DMSprNom->ElementNAMENOM->AsString,
                                        DMSprNom->ElementCODENOM->AsString,
                                         FloatToStrF(DMSprNom->ElementZNACH_PRICE->AsFloat,ffFixed,10,2),
                                         ElementSpiska->NameEd);


                DMSprNom->kanRelease();
                }


        }

SE->SS->EndUpdate();
SE->Show();


}
//----------------------------------------------------------------------------
void TPrintPriceNumber1::PrintPriceNumber1_OutputGrp(void)
{
IDMSprNom * DMSprNom;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&DMSprNom);
DMSprNom->Init(InterfaceMainObject,0);
DMSprNom->IdTypePrice=IdTypePrice;
DMSprNom->OpenTable(ElementSpiska->Id,false);
DMSprNom->Table->First();
while (!DMSprNom->Table->Eof)
        {
        PrintPriceNumber1_OutputElement(DMSprNom->TableNAMENOM->AsString,
                                        DMSprNom->TableCODENOM->AsString,
                                         FloatToStrF(DMSprNom->TableZNACH_PRICE->AsFloat,ffFixed,10,2),
                                         DMSprNom->TableNAMEED->AsString);

        DMSprNom->Table->Next();
        }

DMSprNom->kanRelease();

}
//-----------------------------------------------------------------------------
void TPrintPriceNumber1::PrintPriceNumber1_OutputZagolovok(void)
{


        TcxSSHeader *cHeader;
        cHeader = SE->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 75;
        cHeader->Size[2] = 75;
        cHeader->Size[3] = 75;
        cHeader->Size[4] = 10;
        cHeader->Size[5] = 75;
        cHeader->Size[6] = 75;
        cHeader->Size[7] = 75;
        cHeader->Size[8] = 10;
        cHeader->Size[9] = 75;
        cHeader->Size[10] = 75;
        cHeader->Size[11] = 75;



}
//-----------------------------------------------------------------------------
void TPrintPriceNumber1::PrintPriceNumber1_OutputElement(AnsiString name,
                                                AnsiString code,
                                                AnsiString price,
                                                AnsiString name_ed)
{
        if (KolNaString==3)      //новая строка
                {
                KolNaString=0;
                x=1;
                y=y+9;
                }

		if (KolNaPage==12)   //новая страница
				{
				NumberPage++;
				SE->SS->AddSheetPage("Стр."+IntToStr(NumberPage));
				SE->SS->ActivePage++;
				PrintPriceNumber1_OutputZagolovok();

				KolNaString=0;
				KolNaPage=0;
				x = 1;
				y = 1;
				}

        int tek_y=y;

        
        TRect rect;
        rect.Left = x;
        rect.Top = y;
        rect.Right = x+2;
        rect.Bottom = y;
        SE->SS->ActiveSheet->SetMergedState(rect, true);

        TcxSSCellObject *cell;
        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Text = NameFirm;
        cell->Style->HorzTextAlign = haCENTER;
        cell->Style->VertTextAlign = vaCENTER;
        cell->Style->Font->Name = "Times New Roman";
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsUnderline;
        delete cell;
        y++;
//-----------------следующая строка ------------------------------------------

        rect.Left = x;
        rect.Top = y;
        rect.Right = x+2;
        rect.Bottom = y+1;
        SE->SS->ActiveSheet->SetMergedState(rect, true);

        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
		cell->Text = name;
        cell->Style->HorzTextAlign = haCENTER;
        cell->Style->VertTextAlign = vaCENTER;
        cell->Style->Font->Name = "Times New Roman";
        cell->Style->Font->Size = 14;
        cell->Style->WordBreak = true;
        cell->Style->Font->Style = TFontStyles() << fsBold;
		SE->SS->ActiveSheet->Rows->Size[y]=40;
		SE->SS->ActiveSheet->Rows->Size[y+1]=40;
        delete cell;
        y++;
        y++;
        x++;
//-----------------следующая строка ------------------------------------------

        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Text = "Код: "+code;
        cell->Style->HorzTextAlign = haCENTER;
       // cell->Style->VertTextAlign = vaCENTER;
        cell->Style->Font->Name = "Times New Roman";
        cell->Style->Font->Size = 14;
        cell->Style->Font->Style = TFontStyles() << fsBold;
		SE->SS->ActiveSheet->Rows->Size[y]=30;
		delete cell;
        y++;
        x--;
//-----------------следующая строка ------------------------------------------

        rect.Left = x;
        rect.Top = y;
        rect.Right = x+1;
        rect.Bottom = y;
        SE->SS->ActiveSheet->SetMergedState(rect, true);

        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Text = " "+glCommaToPixel(price);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->VertTextAlign = vaBOTTOM;
        cell->Style->Font->Name = "Times New Roman";
        cell->Style->Font->Size = 18;
		cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        x++;
        x++;

        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Text ="за "+ name_ed;
        cell->Style->HorzTextAlign = haLEFT;
        cell->Style->VertTextAlign = vaBOTTOM;
        cell->Style->Font->Name = "Times New Roman";
        cell->Style->Font->Size = 10;
        SE->SS->ActiveSheet->Rows->Size[y]=30;
        delete cell;
        y++;
        x=x-2;

 //-----------------следующая строка ------------------------------------------
        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Text = "Подпись _____________";
        cell->Style->HorzTextAlign = haLEFT;
        cell->Style->Font->Name = "Times New Roman";
        cell->Style->Font->Size = 8;
        delete cell;
        x=x+4;


        y=tek_y;
        KolNaString++;
        KolNaPage++;
}
//-----------------------------------------------------------------------------
