//---------------------------------------------------------------------------


#pragma hdrstop

#include "UPrintPriceNumber4.h"
#include "IDMSprNom.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)


//-------------------------------------------------------------------
TPrintPriceNumber4::TPrintPriceNumber4()
{


}
//-----------------------------------------------------------------------------
TPrintPriceNumber4::~TPrintPriceNumber4()
{


}
//-----------------------------------------------------------------------
bool TPrintPriceNumber4::Init(void)
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
void TPrintPriceNumber4::CreatePrice(void)
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
                                         FloatToStr(DMSprNom->ElementZNACH_PRICE->AsFloat),
                                         ElementSpiska->NameEd);


				DMSprNom->kanRelease();
				}


        }

SE->SS->EndUpdate();
SE->Show();


}
//----------------------------------------------------------------------------
void TPrintPriceNumber4::PrintPriceNumber_OutputGrp(void)
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
void TPrintPriceNumber4::PrintPriceNumber_OutputZagolovok(void)
{


        TcxSSHeader *cHeader;
        cHeader = SE->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 30;
        cHeader->Size[2] = 30;
        cHeader->Size[3] = 30;
        cHeader->Size[4] = 10;
        cHeader->Size[5] = 30;
        cHeader->Size[6] = 30;
        cHeader->Size[7] = 30;
        cHeader->Size[8] = 10;
        cHeader->Size[9] = 30;
        cHeader->Size[10] = 30;
        cHeader->Size[11] = 30;
        cHeader->Size[12] = 10;
        cHeader->Size[13] = 30;
        cHeader->Size[14] = 30;
        cHeader->Size[15] = 30;
        cHeader->Size[16] = 10;
        cHeader->Size[17] = 30;
        cHeader->Size[18] = 30;
        cHeader->Size[19] = 30;
        cHeader->Size[20] = 10;
        cHeader->Size[21] = 30;
        cHeader->Size[22] = 30;
        cHeader->Size[23] = 30;
        cHeader->Size[24] = 10;
        cHeader->Size[25] = 30;
        cHeader->Size[26] = 30;
        cHeader->Size[27] = 30;

}
//-----------------------------------------------------------------------------
void TPrintPriceNumber4::PrintPriceNumber_OutputElement(AnsiString name,
                                                AnsiString code,
                                                AnsiString price,
                                                AnsiString name_ed)
{
        if (KolNaString==7)      //новая строка
                {
                KolNaString=0;
                x=1;
                y=y+4;
                SE->SS->ActiveSheet->Rows->Size[y]=10;
                y++;
                }

		if (KolNaPage==63)   //новая страница
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
        TcxSSCellObject *cell;
        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Style->Borders->Edges [eLeft]->Style=lsThick;
        cell->Style->Borders->Edges [eTop]->Style=lsThick;
        delete cell;

        cell = SE->SS->ActiveSheet->GetCellObject(x+1, y);
        cell->Style->Borders->Edges [eTop]->Style=lsThick;
        delete cell;

        cell = SE->SS->ActiveSheet->GetCellObject(x+2, y);
        cell->Style->Borders->Edges [eRight]->Style=lsThick;
        cell->Style->Borders->Edges [eTop]->Style=lsThick;
        delete cell;

//-----------------следующая строка ------------------------------------------
        TRect rect;
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
        cell->Style->Font->Size = 10;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        cell->Style->WordBreak = true;
        SE->SS->ActiveSheet->Rows->Size[y]=15;
        SE->SS->ActiveSheet->Rows->Size[y+1]=15;
        delete cell;

        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Style->Borders->Edges [eLeft]->Style=lsThick;
        delete cell;

        cell = SE->SS->ActiveSheet->GetCellObject(x+2, y);
        cell->Style->Borders->Edges [eRight]->Style=lsThick;
        delete cell;

        y++;
//-----------------следующая строка ------------------------------------------
        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Style->Borders->Edges [eLeft]->Style=lsThick;
        delete cell;

        cell = SE->SS->ActiveSheet->GetCellObject(x+2, y);
        cell->Style->Borders->Edges [eRight]->Style=lsThick;
        delete cell;

        y++;
//-----------------следующая строка ------------------------------------------
        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Style->Borders->Edges [eLeft]->Style=lsThick;
        delete cell;

        cell = SE->SS->ActiveSheet->GetCellObject(x+2, y);
        cell->Style->Borders->Edges [eRight]->Style=lsThick;
        delete cell;



        x++;


        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Text = "Код: "+code;
        cell->Style->HorzTextAlign = haCENTER;
       // cell->Style->VertTextAlign = vaCENTER;
        cell->Style->Font->Name = "Times New Roman";
        cell->Style->Font->Size = 8;
 //       cell->Style->Font->Style = TFontStyles() << fsBold;
        SE->SS->ActiveSheet->Rows->Size[y]=15;
        delete cell;


        y++;
        x--;
//-----------------следующая строка ------------------------------------------

        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Style->Borders->Edges [eLeft]->Style=lsThick;
        delete cell;

        cell = SE->SS->ActiveSheet->GetCellObject(x+2, y);
        cell->Style->Borders->Edges [eRight]->Style=lsThick;
        delete cell;

        //rect.Left = x;
        //rect.Top = y;
        //rect.Right = x+1;
        //rect.Bottom = y;
       // SE->SS->ActiveSheet->SetMergedState(rect, true);

        cell = SE->SS->ActiveSheet->GetCellObject(x+1, y);
        cell->Text = " "+price+"руб.";
        cell->Style->HorzTextAlign = haCENTER;
        cell->Style->VertTextAlign = vaCENTER;
        cell->Style->Font->Name = "Times New Roman";
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;

        x++;
        x++;

        //cell = SE->SS->ActiveSheet->GetCellObject(x, y);
       // cell->Text ="за "+ name_ed;
       // cell->Style->HorzTextAlign = haLEFT;
       // cell->Style->VertTextAlign = vaBOTTOM;
       // cell->Style->Font->Name = "Times New Roman";
       // cell->Style->Font->Size = 10;
        SE->SS->ActiveSheet->Rows->Size[y]=20;
        x=x-2;

 //-----------------следующая строка ------------------------------------------

        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Style->Borders->Edges [eLeft]->Style=lsThick;
        cell->Style->Borders->Edges [eBottom]->Style=lsThick;
        delete cell;

        cell = SE->SS->ActiveSheet->GetCellObject(x+1, y);
        cell->Style->Borders->Edges [eBottom]->Style=lsThick;
        delete cell;

        cell = SE->SS->ActiveSheet->GetCellObject(x+2, y);
        cell->Style->Borders->Edges [eRight]->Style=lsThick;
        cell->Style->Borders->Edges [eBottom]->Style=lsThick;
        delete cell;

        x=x+4;
        y=tek_y;
        KolNaString++;
        KolNaPage++;
}
//-----------------------------------------------------------------------------
