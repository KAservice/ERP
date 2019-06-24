//---------------------------------------------------------------------------


#pragma hdrstop

#include "UPrintPriceNumber5.h"
#include "IDMSprNom.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)

//-------------------------------------------------------------------
TPrintPriceNumber5::TPrintPriceNumber5()
{


}
//-----------------------------------------------------------------------------
TPrintPriceNumber5::~TPrintPriceNumber5()
{


}
//-----------------------------------------------------------------------
bool TPrintPriceNumber5::Init(void)
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
void TPrintPriceNumber5::CreatePrice(void)
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
                                         ElementSpiska->NameEd,
										 DMSprNom->ElementNAME_SCOUNTRY->AsString);


				DMSprNom->kanRelease();
				}


		}

SE->SS->EndUpdate();
SE->Show();


}
//----------------------------------------------------------------------------
void TPrintPriceNumber5::PrintPriceNumber_OutputGrp(void)
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
		DMSprNom->OpenElement(DMSprNom->TableIDNOM->AsInteger);
        PrintPriceNumber_OutputElement(DMSprNom->TableNAMENOM->AsString,
                                        DMSprNom->TableCODENOM->AsString,
										 FloatToStrF(DMSprNom->TableZNACH_PRICE->AsFloat,ffFixed,10,2),
										 DMSprNom->TableNAMEED->AsString,
										 DMSprNom->ElementNAME_SCOUNTRY->AsString);

		DMSprNom->Table->Next();
		}

DMSprNom->kanRelease();
}
//-----------------------------------------------------------------------------
void TPrintPriceNumber5::PrintPriceNumber_OutputZagolovok(void)
{


		TcxSSHeader *cHeader;
        cHeader = SE->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
		cHeader->Size[1] = 78;
		cHeader->Size[2] = 78;
		cHeader->Size[3] = 78;
		cHeader->Size[4] = 10;
		cHeader->Size[5] = 78;
		cHeader->Size[6] = 78;
		cHeader->Size[7] = 78;
        cHeader->Size[8] = 10;
		cHeader->Size[9] = 78;
		cHeader->Size[10] = 78;
        cHeader->Size[11] = 78;




}
//-----------------------------------------------------------------------------
void TPrintPriceNumber5::PrintPriceNumber_OutputElement(AnsiString name,
												AnsiString code,
                                                AnsiString price,
												AnsiString name_ed,
												AnsiString country)
{
        if (KolNaString==3)      //новая строка
                {
				KolNaString=0;
                x=1;
				y=y+8;
				SE->SS->ActiveSheet->Rows->Size[y]=20;
                y++;
                }

		if (KolNaPage==9)   //новая страница
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
		SE->SS->ActiveSheet->Rows->Size[y]=60;
		y++;

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
		cell->Style->Font->Style = TFontStyles() << fsUnderline << fsBold;;
		cell->Style->Borders->Edges [eTop]->Style=lsThick;
        cell->Style->Borders->Edges [eLeft]->Style=lsThick;
		SE->SS->ActiveSheet->Rows->Size[y]=18;
		cell->Style->Brush->BackgroundColor = 14;
		delete cell;
        cell = SE->SS->ActiveSheet->GetCellObject(x+1, y);
		cell->Style->Borders->Edges [eTop]->Style=lsThick;
		cell->Style->Brush->BackgroundColor = 14;
		delete cell;
		cell = SE->SS->ActiveSheet->GetCellObject(x+2, y);
        cell->Style->Borders->Edges [eRight]->Style=lsThick;
		cell->Style->Borders->Edges [eTop]->Style=lsThick;
		cell->Style->Brush->BackgroundColor = 14;
		delete cell;
        y++;
//-----------------следующая строка ------------------------------------------

        rect.Left = x;
		rect.Top = y;
        rect.Right = x+2;
        rect.Bottom = y+1;
		SE->SS->ActiveSheet->SetMergedState(rect, true);

		cell = SE->SS->ActiveSheet->GetCellObject(x, y);
		cell->Style->Borders->Edges [eLeft]->Style=lsThick;
        cell->Text = name;
        cell->Style->HorzTextAlign = haCENTER;
		cell->Style->VertTextAlign = vaCENTER;
        cell->Style->Font->Name = "Times New Roman";
		cell->Style->Font->Size = 20;
		cell->Style->WordBreak = true;
		cell->Style->Font->Style = TFontStyles() << fsBold << fsUnderline;
		delete cell;
		cell = SE->SS->ActiveSheet->GetCellObject(x+2, y);
		cell->Style->Borders->Edges [eRight]->Style=lsThick;
		delete cell;
		SE->SS->ActiveSheet->Rows->Size[y]=50;
		SE->SS->ActiveSheet->Rows->Size[y+1]=50;
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
		cell->Text = "Код: "+code;
		cell->Style->HorzTextAlign = haLEFT;
		cell->Style->Font->Size = 16;
		delete cell;
		cell = SE->SS->ActiveSheet->GetCellObject(x+2, y);
        cell->Style->Borders->Edges [eRight]->Style=lsThick;
		delete cell;

		cell = SE->SS->ActiveSheet->GetCellObject(x+2, y);
		cell->Text = name_ed+"    ";
		cell->Style->HorzTextAlign = haRIGHT;
       // cell->Style->VertTextAlign = vaCENTER;
        cell->Style->Font->Name = "Times New Roman";
		cell->Style->Font->Size = 16;
//		cell->Style->Font->Style = TFontStyles() << fsBold;
        SE->SS->ActiveSheet->Rows->Size[y]=20;
		delete cell;


		y++;

//-----------------следующая строка ------------------------------------------

        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
		cell->Style->Borders->Edges [eLeft]->Style=lsThick;
		cell->Style->Brush->BackgroundColor = 14;
		delete cell;
		cell = SE->SS->ActiveSheet->GetCellObject(x+1, y);
		AnsiString str=glConvertString(price, ".", "=");
		cell->Text = glConvertString(str, ",", "=");
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->VertTextAlign = vaCENTER;
		cell->Style->Font->Name = "Times New Roman";
		cell->Style->Font->Size = 40;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		cell->Style->Brush->BackgroundColor = 14;
		delete cell;
		cell = SE->SS->ActiveSheet->GetCellObject(x+2, y);
		cell->Style->Borders->Edges [eRight]->Style=lsThick;
		cell->Style->Brush->BackgroundColor = 14;
		delete cell;

		SE->SS->ActiveSheet->Rows->Size[y]=60;
		y++;
//-----------------------------
		cell = SE->SS->ActiveSheet->GetCellObject(x, y);
		cell->Style->Borders->Edges [eLeft]->Style=lsThick;
//		cell->Style->Borders->Edges [eBottom]->Style=lsThick;
		delete cell;
		cell = SE->SS->ActiveSheet->GetCellObject(x+1, y);
//		cell->Style->Borders->Edges [eBottom]->Style=lsThick;
		cell->Text =country;
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->VertTextAlign = vaCENTER;
		cell->Style->Font->Name = "Times New Roman";
		cell->Style->Font->Size = 12;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		delete cell;
		cell = SE->SS->ActiveSheet->GetCellObject(x+2, y);
		cell->Style->Borders->Edges [eRight]->Style=lsThick;
//		cell->Style->Borders->Edges [eBottom]->Style=lsThick;
		delete cell;
		SE->SS->ActiveSheet->Rows->Size[y]=18;
        y++;
 //-----------------следующая строка ------------------------------------------

		cell = SE->SS->ActiveSheet->GetCellObject(x, y);
		cell->Style->Borders->Edges [eLeft]->Style=lsThick;
		cell->Style->Borders->Edges [eBottom]->Style=lsThick;
		delete cell;
		cell = SE->SS->ActiveSheet->GetCellObject(x+1, y);
		cell->Style->Borders->Edges [eBottom]->Style=lsThick;
		cell->Text ="Годен до_______________ ";
		cell->Style->HorzTextAlign = haCENTER;
		cell->Style->VertTextAlign = vaBOTTOM;
		cell->Style->Font->Name = "Times New Roman";
		cell->Style->Font->Size = 10;
		delete cell;
		cell = SE->SS->ActiveSheet->GetCellObject(x+2, y);
		cell->Style->Borders->Edges [eRight]->Style=lsThick;
		cell->Style->Borders->Edges [eBottom]->Style=lsThick;
		delete cell;
		SE->SS->ActiveSheet->Rows->Size[y]=18;
		x=x+4;


		y=tek_y;
		KolNaString++;
		KolNaPage++;
}
//-----------------------------------------------------------------------------