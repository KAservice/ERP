//---------------------------------------------------------------------------


#pragma hdrstop

#include "UHOT_ReportSostNF.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
extern String glGetNameDoc(String StrCodeDoc);
//-------------------------------------------------------------------
THOT_ReportSostNF::THOT_ReportSostNF()
{


}
//-----------------------------------------------------------------------------
THOT_ReportSostNF::~THOT_ReportSostNF()
{


}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
void THOT_ReportSostNF::CreateReport(void)
{

//if (AddDoc==true && IdNom==0)
//		{
//		AnsiString V="Не выбрана номенклатура! Для построения отчета потребуется время. Продолжить?";
//		String Z="Внимание!";
//		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
//				{
//				}
//		else
//				{
//				return;
//				}
//		}

TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

y=1;
x=1;

porNumStrGrp=1;

PrintForm->SS->BeginUpdate();
OutputZagolovokReport(PrintForm);

DMQuerySprNF=new TDMQueryRead (Application);
DMQuerySprNF->pFIBQ->Close();
DMQuerySprNF->pFIBQ->SQL->Clear();
DMQuerySprNF->pFIBQ->SQL->Add("select *");
DMQuerySprNF->pFIBQ->SQL->Add(" from hot_snf");
DMQuerySprNF->pFIBQ->SQL->Add(" left outer join hot_sobject on hot_sobject.id_hot_sobject=hot_snf.idob_hot_snf");
DMQuerySprNF->pFIBQ->SQL->Add(" left outer join hot_scatnom on hot_scatnom.id_hot_scatnom=hot_snf.idcat_hot_snf");
DMQuerySprNF->pFIBQ->SQL->Add(" where");
DMQuerySprNF->pFIBQ->SQL->Add(" hot_snf.posin_hot_snf between :PARAM_POSNACH and :PARAM_POSCON or");
DMQuerySprNF->pFIBQ->SQL->Add(" hot_snf.posout_hot_snf between :PARAM_POSNACH and :PARAM_POSCON or");
DMQuerySprNF->pFIBQ->SQL->Add(" :PARAM_POSNACH between  hot_snf.posin_hot_snf and  hot_snf.posout_hot_snf or");
DMQuerySprNF->pFIBQ->SQL->Add(" :PARAM_POSCON between  hot_snf.posin_hot_snf and  hot_snf.posout_hot_snf");
DMQuerySprNF->pFIBQ->SQL->Add(" order by NAME_HOT_SOBJECT, NAME_HOT_SCATNOM, NAME_HOT_SNF");
DMQuerySprNF->pFIBQ->ParamByName("PARAM_POSNACH")->AsDateTime=PosNach;
DMQuerySprNF->pFIBQ->ParamByName("PARAM_POSCON")->AsDateTime=PosCon;
DMQuerySprNF->pFIBQ->ExecQuery();

int id_object=0;
int id_cat=0;

while(!DMQuerySprNF->pFIBQ->Eof)
	{
	if (id_object==DMQuerySprNF->pFIBQ->FieldByName("IDOB_HOT_SNF")->AsInteger)
		{ //этот же объект
		}
	else
		{//новый объект
		x=0;
		TcxSSCellObject *cell;
		cell = PrintForm->SS->ActiveSheet->GetCellObject(x, y);
		cell->Text = DMQuerySprNF->pFIBQ->FieldByName("NAME_HOT_SOBJECT")->AsString;
		delete cell;
		id_object=DMQuerySprNF->pFIBQ->FieldByName("IDOB_HOT_SNF")->AsInteger;
		y++;
		}

	if (id_cat==DMQuerySprNF->pFIBQ->FieldByName("IDCAT_HOT_SNF")->AsInteger)
		{ //эта же категория
		}
	else
		{//новая категория
		x=0;
		TcxSSCellObject *cell;
		cell = PrintForm->SS->ActiveSheet->GetCellObject(x, y);
		cell->Text = DMQuerySprNF->pFIBQ->FieldByName("NAME_HOT_SCATNOM")->AsString;
		delete cell;
		id_cat=DMQuerySprNF->pFIBQ->FieldByName("IDCAT_HOT_SNF")->AsInteger;
		y++;
		}

	//выводим название номера 
	TcxSSCellObject *cell;
	x=0;
	cell = PrintForm->SS->ActiveSheet->GetCellObject(x, y);
	cell->Text = DMQuerySprNF->pFIBQ->FieldByName("NAME_HOT_SNF")->AsString;
	delete cell;



	OutputReportNomer(PrintForm);
	y++;
	DMQuerySprNF->pFIBQ->Next();
	}

CreateReportSostNF(PrintForm);


OutputPodavalReport(PrintForm);



delete DMQuerySprNF;

PrintForm->SS->EndUpdate();
PrintForm->Show();
}

//----------------------------------------------------------------------------
void THOT_ReportSostNF::OutputReportNomer(TSheetEditor *prForm)
{

DMQuerySostNF=new TDMQueryRead (Application);
DMQuerySostNF->pFIBQ->Close();
DMQuerySostNF->pFIBQ->SQL->Clear();
DMQuerySostNF->pFIBQ->SQL->Add("select *");
DMQuerySostNF->pFIBQ->SQL->Add(" from hot_rgsostnf");
DMQuerySostNF->pFIBQ->SQL->Add(" left outer join hot_sostnf on hot_sostnf.id_hot_sostnf=hot_rgsostnf.idsost_hot_rgsostnf");
DMQuerySostNF->pFIBQ->SQL->Add(" left outer join hot_snf on hot_snf.id_hot_snf=hot_sostnf.idnomer_hot_sostnf");
DMQuerySostNF->pFIBQ->SQL->Add(" where");
DMQuerySostNF->pFIBQ->SQL->Add(" (hot_sostnf.posnach_hot_sostnf between :PARAM_POSNACH and :PARAM_POSCON or");
DMQuerySostNF->pFIBQ->SQL->Add(" hot_sostnf.poscon_hot_sostnf between :PARAM_POSNACH and :PARAM_POSCON or");
DMQuerySostNF->pFIBQ->SQL->Add(" :PARAM_POSNACH between  hot_sostnf.posnach_hot_sostnf and  hot_sostnf.poscon_hot_sostnf or");
DMQuerySostNF->pFIBQ->SQL->Add(" :PARAM_POSCON between  hot_sostnf.posnach_hot_sostnf and  hot_sostnf.poscon_hot_sostnf ) and");
DMQuerySostNF->pFIBQ->SQL->Add("  hot_snf.id_hot_snf=:PARAM_IDNOMER");
DMQuerySostNF->pFIBQ->SQL->Add("  order by hot_sostnf.posnach_hot_sostnf");
DMQuerySostNF->pFIBQ->ParamByName("PARAM_POSNACH")->AsDateTime=PosNach;
DMQuerySostNF->pFIBQ->ParamByName("PARAM_POSCON")->AsDateTime=PosCon;
DMQuerySostNF->pFIBQ->ParamByName("PARAM_IDNOMER")->AsInteger=DMQuerySprNF->pFIBQ->FieldByName("ID_HOT_SNF")->AsInteger;
DMQuerySostNF->pFIBQ->ExecQuery();

while(!DMQuerySostNF->pFIBQ->Eof)
	{
	x=0;
	OutputStringNomer(prForm);
    DMQuerySostNF->pFIBQ->Next();
	}


}
//-----------------------------------------------------------------------------

void THOT_ReportSostNF::OutputStringNomer(TSheetEditor *prForm)
{
TRect rect;

//        rect.Left = x;
//		rect.Top = y;
//		rect.Right = x+6;
//		rect.Bottom = y;
//		SE->SS->ActiveSheet->SetMergedState(rect, true);

int a=DMQuerySostNF->pFIBQ->FieldByName("POSNACH_HOT_SOSTNF")->AsDateTime-PosNach;

if (a<0)
	{
	rect.Left=1;
	}
else
	{
	rect.left=a*4+1;
	}

a=DMQuerySostNF->pFIBQ->FieldByName("POSCON_HOT_SOSTNF")->AsDateTime-PosNach;
if (a<0)
	{
	rect.Right=1;
	}
else
	{
	rect.Right=a*4+1;
	}
		rect.Top = y;
		rect.Bottom = y;
		prForm->SS->ActiveSheet->SetMergedState(rect, true);
		
	TcxSSCellObject *cell;
	cell = prForm->SS->ActiveSheet->GetCellObject(rect.Left, y);
	//cell->Text = DMQuerySprNF->pFIBQ->FieldByName("NAME_HOT_SNF")->AsString;
	cell->Style->Brush->BackgroundColor=34;
	delete cell;


}
//-----------------------------------------------------------------------------
void THOT_ReportSostNF::CreateReportSostNF(TSheetEditor *prForm)
{
//DMQueryRead=new TDMQueryRead(Application);
//DMQueryRead->pFIBQ->Close();
//DMQueryRead->pFIBQ->SQL->Clear();
//DMQueryRead->pFIBQ->SQL->Add(GetTextQuery());
//DMQueryRead->pFIBQ->ParamByName("PARAM_POSNACH")->AsDateTime=PosNach;
//DMQueryRead->pFIBQ->ParamByName("PARAM_POSCON")->AsDateTime=PosCon;
//DMQueryRead->pFIBQ->ExecQuery();
//
//
//IdTecFirm=0;//IBQIDFIRM->AsInteger;
////num_row_firm=numRow;
////NewOutputStringFirm(prForm);
//
//
//IdTecSklad=0;//IBQIDSKLAD->AsInteger;
////num_row_sklad=numRow;
////NewOutputStringSklad(prForm);
//
//
//IdTecGrpNom=0;//;IBQIDGN->AsInteger;
//
//SumRealReport=0;
//SumSkReport=0;
//
//SumRealFirm=0;
//SumSkFirm=0;
//
//SumRealSklad=0;
//SumSkSklad=0;
//
//
//SumRealGrpNom=0;
//SumSkGrpNom=0;
//
//
//				while(!DMQueryRead->pFIBQ->Eof)
//                        {
//						//фирма
//						if (DMQueryRead->pFIBQ->FieldByName("IDFIRM")->AsInteger==IdTecFirm)
//                                {   //эта же фирма
//								SumRealFirm=SumRealFirm+DMQueryRead->pFIBQ->FieldByName("SUMREAL")->AsFloat;
//								SumSkFirm=SumSkFirm+DMQueryRead->pFIBQ->FieldByName("SUMSK")->AsFloat;
//                                }
//						else
//								{
//								OutputStringItogiFirm(prForm);
//
//								OutputStringFirm(prForm);
//								IdTecFirm=DMQueryRead->pFIBQ->FieldByName("IDFIRM")->AsInteger;
//								IdTecSklad=0;
//								IdTecGrpNom=0;
//
//								SumRealFirm=DMQueryRead->pFIBQ->FieldByName("SUMREAL")->AsFloat;
//								SumSkFirm=DMQueryRead->pFIBQ->FieldByName("SUMSK")->AsFloat;
//
//								}
//
//                        //склад
//						if (DMQueryRead->pFIBQ->FieldByName("IDSKLAD")->AsInteger==IdTecSklad)
//								{   //эта же склад
//								SumRealSklad=SumRealSklad+DMQueryRead->pFIBQ->FieldByName("SUMREAL")->AsFloat;
//								SumSkSklad=SumSkSklad+DMQueryRead->pFIBQ->FieldByName("SUMSK")->AsFloat;
//								}
//						else
//								{
//								OutputStringItogiSklad(prForm);
//
//								OutputStringSklad(prForm);
//								//NewOutputStringGrpNom(prForm);
//
//								IdTecSklad=DMQueryRead->pFIBQ->FieldByName("IDSKLAD")->AsInteger;
//								IdTecGrpNom=0;
//                                
//								SumRealSklad=DMQueryRead->pFIBQ->FieldByName("SUMREAL")->AsFloat;
//								SumSkSklad=DMQueryRead->pFIBQ->FieldByName("SUMSK")->AsFloat;
//
//								}
//
//                        //группа номенклатуры
//						if (DMQueryRead->pFIBQ->FieldByName("IDGN")->AsInteger==IdTecGrpNom)
//								{   //этот же группа
//								SumRealGrpNom=SumRealGrpNom+DMQueryRead->pFIBQ->FieldByName("SUMREAL")->AsFloat;
//								SumSkGrpNom=SumSkGrpNom+DMQueryRead->pFIBQ->FieldByName("SUMSK")->AsFloat;
//								}
//                        else
//								{
//
//								OutputStringItogiGrpNom(prForm);
//
//								OutputStringGrpNom(prForm);
//								IdTecGrpNom=DMQueryRead->pFIBQ->FieldByName("IDGN")->AsInteger;
//
//								SumRealGrpNom=DMQueryRead->pFIBQ->FieldByName("SUMREAL")->AsFloat;
//								SumSkGrpNom=DMQueryRead->pFIBQ->FieldByName("SUMSK")->AsFloat;
//								}
//
//
//						OutputStringNom(prForm);
//
//						SumRealReport=SumRealReport+DMQueryRead->pFIBQ->FieldByName("SUMREAL")->AsFloat;
//						SumSkReport=SumSkReport+DMQueryRead->pFIBQ->FieldByName("SUMSK")->AsFloat;
//					 //   OtrSebRealReport=SumRealReport+IBQNACHOSTSUM->AsFloat;
//
//						if (AddDoc==true)
//								{
//								CreateReportDoc(prForm);
//								}
//
//						porNumStrGrp++;
//						porNumStr++;
//						DMQueryRead->pFIBQ->Next();
//						}
//
//OutputStringItogiFirm(prForm);
//OutputStringItogiSklad(prForm);
//OutputStringItogiGrpNom(prForm);
//
//delete DMQueryRead;
}
//---------------------------------------------------------------------------
void THOT_ReportSostNF::OutputZagolovokReport(TSheetEditor *prForm)
{

prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";
//prForm->SS->Pages[0]->Cols->Lock[0] = true;
		TcxSSHeader *cHeader;
	   cHeader = prForm->SS->ActiveSheet->Cols;
//		cHeader->Size[0] = 10;
//        cHeader->Size[1] = 30;
//		cHeader->Size[2] = 300;
//        cHeader->Size[3] = 70;
//		cHeader->Size[4] = 50;
//		cHeader->Size[5] = 120;
//		cHeader->Size[6] = 120;
//
y=0;
x=1;
int kol_columns=PosCon-PosNach;

TDate tek_date=PosNach;

for (int i=0; i<=kol_columns; i++)
	{
	cHeader->Size[x] = 20;
	cHeader->Size[x+1] = 20;
	cHeader->Size[x+2] = 20;
	cHeader->Size[x+3] = 20;
	TcxSSCellObject *cell;
	cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
	cell->Text = DateToStr(tek_date);
	delete cell;
	tek_date++;
	x=x+4;
	}
y++;



//
//TcxSSCellObject *cell;
//cell = prForm->SS->ActiveSheet->GetCellObject(2, y);
//cell->Text = "Отчет о скидках  "+DateToStr(PosNach)
//						+" по "+DateToStr(PosCon);
//cell->Style->HorzTextAlign = haLEFT;
//cell->Style->Font->Size = 16;
//cell->Style->Font->Style = TFontStyles() << fsBold;
//prForm->SS->ActiveSheet->Rows->Size[y]=25;
//delete cell;
//y++;
//
//cell = prForm->SS->ActiveSheet->GetCellObject(2, y);
//		if (OnlyType==true)
//				{
//				switch (TypeNom)
//						{
//                        case 0:
//								{
//                                cell->Text ="Только товары";
//								break;
//                                }
//						case 1:
//                                {
//								cell->Text ="Только услуги";
//                                break;
//								}
//                        case 2:
//								{
//                                cell->Text ="Только продукция";
//								break;
//                                }
//
//
//						}
//                }
//		else
//                {
//				cell->Text ="Все типы номенклатур";
//                }
//delete cell;
//y++;
//cell = prForm->SS->ActiveSheet->GetCellObject(2, y);
//
//delete cell;
//y++;
//y++;
//
//
//x=1;
////порядковый номер строки
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Text = "№";
//cell->Style->Font->Size = 12;
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->VertTextAlign = vaCENTER;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//x++;
//
////номенклатура
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Style->WordBreak = true;
//cell->Text = "Номенклатура";
//cell->Style->Font->Size = 12;
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->VertTextAlign = vaCENTER;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//x++;
////количество
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Text = "Кол.";
//cell->Style->Font->Size = 12;
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->VertTextAlign = vaCENTER;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//x++;
////единица
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Text = "Ед.";
//cell->Style->Font->Size = 12;
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->VertTextAlign = vaCENTER;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//x++;
//
////сумма
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Text = "Сумма реал.";
//cell->Style->Font->Size = 12;
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->VertTextAlign = vaCENTER;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//x++;
////ссумма скидок
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Text = "Сумма скидок";
//cell->Style->Font->Size = 12;
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->VertTextAlign = vaCENTER;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//x++;
//
//y++;



}
//----------------------------------------------------------------------------
void THOT_ReportSostNF::OutputStringFirm(TSheetEditor *prForm)
{
//num_row_firm=y;
//
//TcxSSCellObject *cell;
//x=1;
////порядковый номер строки
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//cell->Style->Brush->BackgroundColor=34;
//delete cell;
//x++;
//
////фирма
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Text ="Фирма: "+ DMQueryRead->pFIBQ->FieldByName("NAMEFIRM")->AsString;
//cell->Style->Font->Size = 16;
//cell->Style->Font->Style = TFontStyles() << fsBold;
//cell->Style->HorzTextAlign = haLEFT;;
//cell->Style->VertTextAlign = vaCENTER;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//cell->Style->Brush->BackgroundColor=34;
//delete cell;
//x++;
////кол
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//cell->Style->Brush->BackgroundColor=34;
//delete cell;
//x++;
////ед
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//cell->Style->Brush->BackgroundColor=34;
//delete cell;
//x++;
////сумма
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//cell->Style->Brush->BackgroundColor=34;
//delete cell;
//x++;
////себ
//cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//cell->Style->Brush->BackgroundColor=34;
//delete cell;
//x++;
//
//
//y++;



}
//----------------------------------------------------------------------------
void THOT_ReportSostNF::OutputStringItogiFirm(TSheetEditor *prForm)
{
//TcxSSCellObject *cell;
//if(SumRealFirm!=0)
//		{
//		cell = prForm->SS->ActiveSheet->GetCellObject(5, num_row_firm);
//		cell->Text = FloatToStrF(SumRealFirm,ffFixed,10,2);
//		cell->Style->HorzTextAlign = haRIGHT;
//		cell->Style->Font->Size = 12;
//        cell->Style->Font->Style = TFontStyles() << fsBold;
//		delete cell;
//        }
//
//if(SumSkFirm!=0)
//        {
//		cell = prForm->SS->ActiveSheet->GetCellObject(6, num_row_firm);
//		cell->Text = FloatToStrF(SumSkFirm,ffFixed,10,2);
//		cell->Style->HorzTextAlign = haRIGHT;
//		cell->Style->Font->Size = 12;
//        cell->Style->Font->Style = TFontStyles() << fsBold;
//		delete cell;
//		}
//
//prForm->SS->ActiveSheet->Rows->Size[num_row_firm] = 30;

}
//----------------------------------------------------------------------------
void THOT_ReportSostNF::OutputStringSklad(TSheetEditor *prForm)
{
//num_row_sklad=y;
//
//TcxSSCellObject *cell;
//x=1;
////порядковый номер строки
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//cell->Style->Brush->BackgroundColor=34;
//delete cell;
//x++;
//
////склад
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Text = "Склад: "+DMQueryRead->pFIBQ->FieldByName("NAMESKLAD")->AsString;
//cell->Style->Font->Size = 16;
//cell->Style->Font->Style = TFontStyles() << fsBold;
//cell->Style->HorzTextAlign = haLEFT;
//cell->Style->VertTextAlign = vaCENTER;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//cell->Style->Brush->BackgroundColor=34;
//delete cell;
//x++;
////кол
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//cell->Style->Brush->BackgroundColor=34;
//delete cell;
//x++;
////ед
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//cell->Style->Brush->BackgroundColor=34;
//delete cell;
//x++;
////сумма
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//cell->Style->Brush->BackgroundColor=34;
//delete cell;
//x++;
////себ
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//cell->Style->Brush->BackgroundColor=34;
//delete cell;
//x++;
//
//y++;

}
//----------------------------------------------------------------------------
void THOT_ReportSostNF::OutputStringItogiSklad(TSheetEditor *prForm)
{
//TcxSSCellObject *cell;
//if(SumRealSklad!=0)
//		{
//		cell = prForm->SS->ActiveSheet->GetCellObject(5, num_row_sklad);
//		cell->Text = FloatToStrF(SumRealSklad,ffFixed,10,2);
//		cell->Style->HorzTextAlign = haRIGHT;
//		cell->Style->Font->Size = 12;
//		cell->Style->Font->Style = TFontStyles() << fsBold;
//		delete cell;
//		}
//
//if(SumSkSklad!=0)
//		{
//		cell = prForm->SS->ActiveSheet->GetCellObject(6, num_row_sklad);
//		cell->Text = FloatToStrF(SumSkSklad,ffFixed,10,2);
//		cell->Style->HorzTextAlign = haRIGHT;
//		cell->Style->Font->Size = 12;
//		cell->Style->Font->Style = TFontStyles() << fsBold;
//		delete cell;
//		}
//prForm->SS->ActiveSheet->Rows->Size[num_row_sklad] = 30;
//

}
//----------------------------------------------------------------------------
void THOT_ReportSostNF::OutputStringGrpNom(TSheetEditor *prForm)
{
//num_row_grp_nom=y;
//
//TcxSSCellObject *cell;
//x=1;
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
/////cell->Text = IntToStr(porNumKlient);
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->VertTextAlign = vaCENTER;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//cell->Style->Brush->BackgroundColor=14;
//delete cell;
//x++;
////группа номенлатура
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Text = DMQueryRead->pFIBQ->FieldByName("NAMEGN")->AsString;
//cell->Style->Font->Size = 12;
//cell->Style->Font->Style = TFontStyles() << fsBold;
//cell->Style->HorzTextAlign = haLEFT;
//cell->Style->VertTextAlign = vaCENTER;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//cell->Style->Brush->BackgroundColor=14;
//delete cell;
//x++;
////кол
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//cell->Style->Brush->BackgroundColor=14;
//delete cell;
//x++;
////ед
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//cell->Style->Brush->BackgroundColor=14;
//delete cell;
//x++;
////сумма
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//cell->Style->Brush->BackgroundColor=14;
//delete cell;
//x++;
////себ
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//cell->Style->Brush->BackgroundColor=14;
//delete cell;
//x++;
//y++;



}
//-----------------------------------------------------------------------------
void THOT_ReportSostNF::OutputStringItogiGrpNom(TSheetEditor *prForm)
{
//TcxSSCellObject *cell;
//if(SumRealGrpNom!=0)
//        {
//        cell = prForm->SS->ActiveSheet->GetCellObject(5, num_row_grp_nom);
//		cell->Text = FloatToStrF(SumRealGrpNom,ffFixed,10,2);
//        cell->Style->HorzTextAlign = haRIGHT;
//		cell->Style->Font->Size = 10;
//        cell->Style->Font->Style = TFontStyles() << fsBold;
//		delete cell;
//		}
//
//if(SumSkGrpNom!=0)
//		{
//		cell = prForm->SS->ActiveSheet->GetCellObject(6, num_row_grp_nom);
//		cell->Text = FloatToStrF(SumSkGrpNom,ffFixed,10,2);
//		cell->Style->HorzTextAlign = haRIGHT;
//		cell->Style->Font->Size = 10;
//		cell->Style->Font->Style = TFontStyles() << fsBold;
//		delete cell;
//		}
//
//prForm->SS->ActiveSheet->Rows->Size[num_row_grp_nom] = 20;
}
//----------------------------------------------------------------------------
void THOT_ReportSostNF::OutputStringNom(TSheetEditor *prForm)
{
//TcxSSCellObject *cell;
//x=1;
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Text = "";
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->VertTextAlign = vaCENTER;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//x++;
////номенлатура
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Text = DMQueryRead->pFIBQ->FieldByName("NAMENOM")->AsString;
////cell->Style->HorzTextAlign = haCENTER;
//if (AddDoc==true)
//		{
//        cell->Style->Font->Style = TFontStyles() << fsBold;
//		}
//cell->Style->VertTextAlign = vaCENTER;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//x++;
////кол
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//if (DMQueryRead->pFIBQ->FieldByName("SUMKOL")->AsFloat!=0)
//        {
//		cell->Text = FloatToStrF(DMQueryRead->pFIBQ->FieldByName("SUMKOL")->AsFloat,ffFixed,10,3);
//        }
//cell->Style->HorzTextAlign = haRIGHT;
//cell->Style->VertTextAlign = vaCENTER;
//if (AddDoc==true)
//        {
//		cell->Style->Font->Style = TFontStyles() << fsBold;
//        }
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//x++;
////ед
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Text = DMQueryRead->pFIBQ->FieldByName("NAMEED")->AsString;
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->VertTextAlign = vaCENTER;
//if (AddDoc==true)
//		{
//        cell->Style->Font->Style = TFontStyles() << fsBold;
//		}
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//x++;
////сумма
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//if (DMQueryRead->pFIBQ->FieldByName("SUMREAL")->AsFloat!=0)
//		{
//		cell->Text = FloatToStrF(DMQueryRead->pFIBQ->FieldByName("SUMREAL")->AsFloat, ffFixed, 10,2);
//		}
//cell->Style->HorzTextAlign = haRIGHT;
//cell->Style->VertTextAlign = vaCENTER;
//if (AddDoc==true)
//		{
//        cell->Style->Font->Style = TFontStyles() << fsBold;
//		}
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//x++;
////результ.
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//if (DMQueryRead->pFIBQ->FieldByName("SUMSK")->AsFloat!=0)
//		{
//		cell->Text = FloatToStrF(DMQueryRead->pFIBQ->FieldByName("SUMSK")->AsFloat, ffFixed, 10,2);
//		}
//cell->Style->HorzTextAlign = haRIGHT;
//cell->Style->VertTextAlign = vaCENTER;
//if (AddDoc==true)
//		{
//		cell->Style->Font->Style = TFontStyles() << fsBold;
//		}
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//x++;
//
//
//y++;


}
//---------------------------------------------------------------------------
void THOT_ReportSostNF::OutputPodavalReport(TSheetEditor *prForm)
{
//TcxSSCellObject *cell;
//x=1;
////порядковый номер строки
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Text ="";
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->VertTextAlign = vaCENTER;
//cell->Style->Font->Style = TFontStyles() << fsBold;
//cell->Style->Borders->Edges [eLeft]->Style=lsThick;
//cell->Style->Borders->Edges [eRight]->Style=lsThick;
//cell->Style->Borders->Edges [eTop]->Style=lsThick;
//cell->Style->Borders->Edges [eBottom]->Style=lsThick;
//delete cell;
//x++;
//
////номенлатура
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Text = "";
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->VertTextAlign = vaCENTER;
//cell->Style->Borders->Edges [eLeft]->Style=lsThick;
//cell->Style->Borders->Edges [eRight]->Style=lsThick;
//cell->Style->Borders->Edges [eTop]->Style=lsThick;
//cell->Style->Borders->Edges [eBottom]->Style=lsThick;
//delete cell;
//x++;
//
////кол
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
////cell->Text = FloatToStrF(AllNachOst, ffFixed,15,2);
//cell->Style->Font->Size = 12;
//cell->Style->HorzTextAlign = haRIGHT;
//cell->Style->VertTextAlign = vaCENTER;
//cell->Style->Borders->Edges [eLeft]->Style=lsThick;
//cell->Style->Borders->Edges [eRight]->Style=lsThick;
//cell->Style->Borders->Edges [eTop]->Style=lsThick;
//cell->Style->Borders->Edges [eBottom]->Style=lsThick;
//delete cell;
//x++;
////ед
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
////cell->Text = FloatToStrF(AllPrihod, ffFixed,15,2);
//cell->Style->Font->Size = 12;
//cell->Style->HorzTextAlign = haRIGHT;
//cell->Style->VertTextAlign = vaCENTER;
//cell->Style->Borders->Edges [eLeft]->Style=lsThick;
//cell->Style->Borders->Edges [eRight]->Style=lsThick;
//cell->Style->Borders->Edges [eTop]->Style=lsThick;
//cell->Style->Borders->Edges [eBottom]->Style=lsThick;
//delete cell;
//x++;
////сумма
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Text = FloatToStrF(SumRealReport, ffFixed,15,2);
//cell->Style->Font->Size = 12;
//cell->Style->Font->Style = TFontStyles() << fsBold;
//cell->Style->HorzTextAlign = haRIGHT;
//cell->Style->VertTextAlign = vaCENTER;
//cell->Style->Borders->Edges [eLeft]->Style=lsThick;
//cell->Style->Borders->Edges [eRight]->Style=lsThick;
//cell->Style->Borders->Edges [eTop]->Style=lsThick;
//cell->Style->Borders->Edges [eBottom]->Style=lsThick;
//delete cell;
//x++;
////себ.
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Text = FloatToStrF(SumSkReport, ffFixed,15,2);
//cell->Style->Font->Size = 12;
//cell->Style->Font->Style = TFontStyles() << fsBold;
//cell->Style->HorzTextAlign = haRIGHT;
//cell->Style->VertTextAlign = vaCENTER;
//cell->Style->Borders->Edges [eLeft]->Style=lsThick;
//cell->Style->Borders->Edges [eRight]->Style=lsThick;
//cell->Style->Borders->Edges [eTop]->Style=lsThick;
//cell->Style->Borders->Edges [eBottom]->Style=lsThick;
//delete cell;
//x++;

}

//---------------------------------------------------------------------------
AnsiString THOT_ReportSostNF::GetTextZaprosDoc(void)
{
//AnsiString zapros=" select";
//zapros=zapros+" galldoc.posdoc,galldoc.iddoc, galldoc.tdoc, galldoc.numdoc, ";
//zapros=zapros+" snom.namenom, snom.tnom,";
//zapros=zapros+" sed.nameed,";
//zapros=zapros+" sum(dchkt.kolchkt * dchkt.kfchkt) as SUMKOL,";
//zapros=zapros+" sum(dchkt.sumchkt) as SUMREAL,";
//zapros=zapros+" sum(dchkt.skchkt) as SUMSK";
//zapros=zapros+" from dchkt";
//zapros=zapros+" left outer join galldoc on dchkt.iddocchkt=galldoc.iddoc";
//zapros=zapros+" left outer join sfirm on galldoc.idfirmdoc=sfirm.idfirm";
//zapros=zapros+" left outer join ssklad on galldoc.idskldoc=ssklad.idsklad";
//zapros=zapros+" left outer join snom on dchkt.idnomchkt=snom.idnom";
//zapros=zapros+" left outer join sgrpnom on snom.idgrpnom=sgrpnom.idgn";
//zapros=zapros+" left outer join sed on snom.idbasednom=sed.ided";
//zapros=zapros+" where dchkt.skchkt!=0  and galldoc.posdoc between :PARAM_POSNACH and :PARAM_POSCON";
//
//zapros=zapros+" and  sfirm.idfirm="+DMQueryRead->pFIBQ->FieldByName("IDFIRM")->AsString;
//zapros=zapros+" and  ssklad.idsklad="+DMQueryRead->pFIBQ->FieldByName("IDSKLAD")->AsString;
//zapros=zapros+" and  dchkt.idnomchkt="+DMQueryRead->pFIBQ->FieldByName("IDNOM")->AsString;
//
//zapros=zapros+" group by ";
//zapros=zapros+" galldoc.posdoc,galldoc.iddoc, galldoc.tdoc, galldoc.numdoc,";
//zapros=zapros+" snom.namenom, snom.tnom,";
//zapros=zapros+" sed.nameed";
//return zapros;
}
//----------------------------------------------------------------------------
void THOT_ReportSostNF::CreateReportDoc(TSheetEditor *prForm)
{
//DMQueryDoc=new TDMQueryRead(Application);
//DMQueryDoc->pFIBQ->SQL->Clear();
//DMQueryDoc->pFIBQ->SQL->Add(GetTextZaprosDoc());
//DMQueryDoc->pFIBQ->ParamByName("PARAM_POSNACH")->AsDateTime=PosNach;
//DMQueryDoc->pFIBQ->ParamByName("PARAM_POSCON")->AsDateTime=PosCon;
//DMQueryDoc->pFIBQ->ExecQuery();
//
////
//while(!DMQueryDoc->pFIBQ->Eof)
//		{
//		OutputStringDoc(prForm);
//		DMQueryDoc->pFIBQ->Next();
//		}
//
//delete DMQueryDoc;
}
//-----------------------------------------------------------------------------
void THOT_ReportSostNF::OutputStringDoc(TSheetEditor *prForm)
{
//TcxSSCellObject *cell;
//x=1;
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Text = "";
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->VertTextAlign = vaCENTER;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//x++;
////номенлатура
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Text = glGetNameDoc(DMQueryDoc->pFIBQ->FieldByName("TDOC")->AsString)+" №"+
//				DMQueryDoc->pFIBQ->FieldByName("NUMDOC")->AsString+" от "+
//				DMQueryDoc->pFIBQ->FieldByName("POSDOC")->AsString;
//cell->Style->HorzTextAlign = haRIGHT;
//cell->Style->VertTextAlign = vaCENTER;
//cell->Style->Font->FontColor=24;
//cell->Style->Font->Size = 8;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//x++;
////кол
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//if (DMQueryDoc->pFIBQ->FieldByName("SUMKOL")->AsFloat!=0)
//		{
//		cell->Text = FloatToStrF(DMQueryDoc->pFIBQ->FieldByName("SUMKOL")->AsFloat,ffFixed,10,3);
//        }
//cell->Style->HorzTextAlign = haRIGHT;
//cell->Style->VertTextAlign = vaCENTER;
//cell->Style->Font->FontColor=24;
//cell->Style->Font->Size = 8;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//x++;
////ед
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Text = DMQueryDoc->pFIBQ->FieldByName("NAMEED")->AsString;
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->VertTextAlign = vaCENTER;
//cell->Style->Font->FontColor=24;
//cell->Style->Font->Size = 8;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//x++;
////сумма
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//if (DMQueryDoc->pFIBQ->FieldByName("SUMREAL")->AsFloat!=0)
//        {
//		cell->Text = FloatToStrF(DMQueryDoc->pFIBQ->FieldByName("SUMREAL")->AsFloat, ffFixed, 10,2);
//        }
//cell->Style->HorzTextAlign = haRIGHT;
//cell->Style->VertTextAlign = vaCENTER;
//cell->Style->Font->FontColor=24;
//cell->Style->Font->Size = 8;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//x++;
////результ.
//cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//if (DMQueryDoc->pFIBQ->FieldByName("SUMSK")->AsFloat!=0)
//		{
//		cell->Text = FloatToStrF(DMQueryDoc->pFIBQ->FieldByName("SUMSK")->AsFloat, ffFixed, 10,2);
//		}
//cell->Style->HorzTextAlign = haRIGHT;
//cell->Style->VertTextAlign = vaCENTER;
//cell->Style->Font->FontColor=24;
//cell->Style->Font->Size = 8;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//x++;
//
//y++;


}
//-----------------------------------------------------------------------------