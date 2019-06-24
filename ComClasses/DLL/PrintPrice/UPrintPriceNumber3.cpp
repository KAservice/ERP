//---------------------------------------------------------------------------


#pragma hdrstop

#include "UPrintPriceNumber3.h"
#include "IDMSprNom.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)


//-------------------------------------------------------------------
TPrintPriceNumber3::TPrintPriceNumber3()
{


}
//-----------------------------------------------------------------------------
TPrintPriceNumber3::~TPrintPriceNumber3()
{


}
//-----------------------------------------------------------------------
bool TPrintPriceNumber3::Init(void)
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
//----------------------------------------------------------------------------
void TPrintPriceNumber3::CreatePrice(void)
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
PrintPriceNumber_OutputZagolovok();


for (int i=0; i<List->Count;i++)
        {
        ElementSpiska=(TElementSpiskaPrintPrice*)List->Items[i];
        if (ElementSpiska->Grp==true)
                {
                PrintPriceNumber_OutputGrp();
                }
        else
                {
				IDMSprNom * DMSprNom;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&DMSprNom);
				DMSprNom->Init(InterfaceMainObject,0);
				DMSprNom->IdTypePrice=IdTypePrice;
                DMSprNom->OpenElement(ElementSpiska->Id);

                PrintPriceNumber_OutputElement(DMSprNom->ElementNAMENOM->AsString,
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
void TPrintPriceNumber3::PrintPriceNumber_OutputGrp(void)
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
        PrintPriceNumber_OutputElement(DMSprNom->TableNAMENOM->AsString,
                                        DMSprNom->TableCODENOM->AsString,
                                         FloatToStr(DMSprNom->TableZNACH_PRICE->AsFloat),
                                         DMSprNom->TableNAMEED->AsString);

        DMSprNom->Table->Next();
		}

DMSprNom->kanRelease();
}
//-----------------------------------------------------------------------------
void TPrintPriceNumber3::PrintPriceNumber_OutputZagolovok(void)
{


        TcxSSHeader *cHeader;
        cHeader = SE->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 120;
        cHeader->Size[2] = 120;
        cHeader->Size[3] = 110;
        cHeader->Size[4] = 10;
        cHeader->Size[5] = 120;
        cHeader->Size[6] = 120;
        cHeader->Size[7] = 110;





}
//-----------------------------------------------------------------------------
void TPrintPriceNumber3::PrintPriceNumber_OutputElement(AnsiString name,
                                                AnsiString code,
                                                AnsiString price,
                                                AnsiString name_ed)
{
        if (KolNaString==2)      //новая строка
                {
                KolNaString=0;
                x=1;
                y=y+6;
                SE->SS->ActiveSheet->Rows->Size[y]=10;
                y++;
                }

		if (KolNaPage==15)   //новая страница
				{
				NumberPage++;
				SE->SS->AddSheetPage("Стр."+IntToStr(NumberPage));
				SE->SS->ActivePage++;
				PrintPriceNumber_OutputZagolovok();

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
        cell->Style->Borders->Edges [eTop]->Style=lsThick;
        cell->Style->Borders->Edges [eLeft]->Style=lsThick;
        SE->SS->ActiveSheet->Rows->Size[y]=25;
        cell = SE->SS->ActiveSheet->GetCellObject(x+1, y);
        cell->Style->Borders->Edges [eTop]->Style=lsThick;

        cell = SE->SS->ActiveSheet->GetCellObject(x+2, y);
        cell->Style->Borders->Edges [eRight]->Style=lsThick;
        cell->Style->Borders->Edges [eTop]->Style=lsThick;
        
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
        cell->Style->Font->Size = 16;
        cell->Style->WordBreak = true;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        SE->SS->ActiveSheet->Rows->Size[y]=30;
        SE->SS->ActiveSheet->Rows->Size[y+1]=30;

        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Style->Borders->Edges [eLeft]->Style=lsThick;

        cell = SE->SS->ActiveSheet->GetCellObject(x+2, y);
        cell->Style->Borders->Edges [eRight]->Style=lsThick;

        y++;
//-----------------следующая строка ------------------------------------------
        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Style->Borders->Edges [eLeft]->Style=lsThick;

        cell = SE->SS->ActiveSheet->GetCellObject(x+2, y);
        cell->Style->Borders->Edges [eRight]->Style=lsThick;

        y++;
//-----------------следующая строка ------------------------------------------
        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Style->Borders->Edges [eLeft]->Style=lsThick;

        cell = SE->SS->ActiveSheet->GetCellObject(x+2, y);
        cell->Style->Borders->Edges [eRight]->Style=lsThick;



        x++;


        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Text = "Код: "+code;
        cell->Style->HorzTextAlign = haCENTER;
       // cell->Style->VertTextAlign = vaCENTER;
        cell->Style->Font->Name = "Times New Roman";
        cell->Style->Font->Size = 16;
 //       cell->Style->Font->Style = TFontStyles() << fsBold;
        SE->SS->ActiveSheet->Rows->Size[y]=20;



        y++;
        x--;
//-----------------следующая строка ------------------------------------------

        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Style->Borders->Edges [eLeft]->Style=lsThick;

        cell = SE->SS->ActiveSheet->GetCellObject(x+2, y);
        cell->Style->Borders->Edges [eRight]->Style=lsThick;

       // rect.Left = x;
      //  rect.Top = y;
      //  rect.Right = x+1;
      //  rect.Bottom = y;
      //  SE->SS->ActiveSheet->SetMergedState(rect, true);

        cell = SE->SS->ActiveSheet->GetCellObject(x+1, y);
        cell->Text = "Цена: "+price+"руб.";
        cell->Style->HorzTextAlign = haCENTER;
        cell->Style->VertTextAlign = vaCENTER;
        cell->Style->Font->Name = "Times New Roman";
        cell->Style->Font->Size = 26;
        cell->Style->Font->Style = TFontStyles() << fsBold;


        x++;
        x++;

       // cell = SE->SS->ActiveSheet->GetCellObject(x, y);
       // cell->Text ="за "+ name_ed;
       // cell->Style->HorzTextAlign = haLEFT;
       // cell->Style->VertTextAlign = vaBOTTOM;
       // cell->Style->Font->Name = "Times New Roman";
      //  cell->Style->Font->Size = 12;
        SE->SS->ActiveSheet->Rows->Size[y]=40;
        y++;
        x=x-2;

 //-----------------следующая строка ------------------------------------------

        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Style->Borders->Edges [eLeft]->Style=lsThick;
        cell->Style->Borders->Edges [eBottom]->Style=lsThick;

        cell = SE->SS->ActiveSheet->GetCellObject(x+1, y);
        cell->Style->Borders->Edges [eBottom]->Style=lsThick;

        cell = SE->SS->ActiveSheet->GetCellObject(x+2, y);
        cell->Style->Borders->Edges [eRight]->Style=lsThick;
        cell->Style->Borders->Edges [eBottom]->Style=lsThick;
        
        cell = SE->SS->ActiveSheet->GetCellObject(x+1, y);
        cell->Text ="Дата "+ DateToStr(Date())+"         Подпись _________";
        cell->Style->HorzTextAlign = haCENTER;
        cell->Style->VertTextAlign = vaCENTER;
        cell->Style->Font->Name = "Times New Roman";
        cell->Style->Font->Size = 10;
        SE->SS->ActiveSheet->Rows->Size[y]=20;

        x=x+4;


        y=tek_y;
        KolNaString++;
        KolNaPage++;
}
//-----------------------------------------------------------------------------
