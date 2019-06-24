//---------------------------------------------------------------------------


#pragma hdrstop

#include "UReportDiscountDocCheck.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"


//---------------------------------------------------------------------------

#pragma package(smart_init)

//-------------------------------------------------------------------
TReportDiscountDocCheck::TReportDiscountDocCheck()
{

}
//-----------------------------------------------------------------------------
TReportDiscountDocCheck::~TReportDiscountDocCheck()
{


}
//----------------------------------------------------------------------------
//-----------------------------------------------------------------------
bool TReportDiscountDocCheck::Init(void)
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
void TReportDiscountDocCheck::CreateReport(void)
{
porNumStr=0;
porNumStrGrp=0;
SumRealReport=0;
SumSkReport=0;
num_row_firm=0;
SumRealFirm=0;
SumSkFirm=0;
num_row_sklad=0;
SumRealSklad=0;
SumSkSklad=0;
num_row_grp_nom=0;
SumRealGrpNom=0;
SumSkGrpNom=0;


if (AddDoc==true && IdNom==0)
		{
		UnicodeString V="Не выбрана номенклатура! Для построения отчета потребуется время. Продолжить?";
		UnicodeString Z="Внимание!";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
				{
				}
		else
				{
				return;
				}
		}

TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

y=1;
x=1;

porNumStrGrp=1;

PrintForm->SS->BeginUpdate();

OutputZagolovokReport(PrintForm);
CreateReportDiscount(PrintForm);
OutputPodavalReport(PrintForm);

PrintForm->SS->EndUpdate();
PrintForm->Show();


}

//----------------------------------------------------------------------------
void TReportDiscountDocCheck::CreateReportDiscount(TSheetEditor *prForm)
{

DM=new TDMReportDiscountDocCheck(Application);
DM->DM_Connection=DM_Connection;
DM->InterfaceGlobalCom=InterfaceGlobalCom;
DM->InterfaceMainObject=InterfaceMainObject;
DM->Init();
DM->OpenReport(PosNach, PosCon, IdFirm, IdSklad, IdGrp, IdNom, OnlyType, TypeNom);




IdTecFirm=-1;//IBQIDFIRM->AsInteger;
//num_row_firm=numRow;
//NewOutputStringFirm(prForm);


IdTecSklad=-1;//IBQIDSKLAD->AsInteger;
//num_row_sklad=numRow;
//NewOutputStringSklad(prForm);


IdTecGrpNom=-1;//;IBQIDGN->AsInteger;

SumRealReport=0;
SumSkReport=0;

SumRealFirm=0;
SumSkFirm=0;

SumRealSklad=0;
SumSkSklad=0;


SumRealGrpNom=0;
SumSkGrpNom=0;


				while(!DM->DM->pFIBQ->Eof)
                        {
                        //фирма
						if (glStrToInt64(DM->DM->pFIBQ->FieldByName("IDFIRM")->AsString)==IdTecFirm)
                                {   //эта же фирма
								SumRealFirm=SumRealFirm+DM->DM->pFIBQ->FieldByName("SUMREAL")->AsFloat;
								SumSkFirm=SumSkFirm+DM->DM->pFIBQ->FieldByName("SUMSK")->AsFloat;
                                }
                        else
                                {
								OutputStringItogiFirm(prForm);

								OutputStringFirm(prForm);
								IdTecFirm=glStrToInt64(DM->DM->pFIBQ->FieldByName("IDFIRM")->AsString);
                                IdTecSklad=0;
                                IdTecGrpNom=0;

								SumRealFirm=DM->DM->pFIBQ->FieldByName("SUMREAL")->AsFloat;
								SumSkFirm=DM->DM->pFIBQ->FieldByName("SUMSK")->AsFloat;

                                }

                        //склад
						if (glStrToInt64(DM->DM->pFIBQ->FieldByName("IDSKLAD")->AsString)==IdTecSklad)
                                {   //эта же склад
								SumRealSklad=SumRealSklad+DM->DM->pFIBQ->FieldByName("SUMREAL")->AsFloat;
								SumSkSklad=SumSkSklad+DM->DM->pFIBQ->FieldByName("SUMSK")->AsFloat;
                                }
						else
                                {
								OutputStringItogiSklad(prForm);

								OutputStringSklad(prForm);
                                //NewOutputStringGrpNom(prForm);

								IdTecSklad=glStrToInt64(DM->DM->pFIBQ->FieldByName("IDSKLAD")->AsString);
                                IdTecGrpNom=0;
                                
								SumRealSklad=DM->DM->pFIBQ->FieldByName("SUMREAL")->AsFloat;
								SumSkSklad=DM->DM->pFIBQ->FieldByName("SUMSK")->AsFloat;

                                }

                        //группа номенклатуры
						if (glStrToInt64(DM->DM->pFIBQ->FieldByName("IDGN")->AsString)==IdTecGrpNom)
                                {   //этот же группа
								SumRealGrpNom=SumRealGrpNom+DM->DM->pFIBQ->FieldByName("SUMREAL")->AsFloat;
								SumSkGrpNom=SumSkGrpNom+DM->DM->pFIBQ->FieldByName("SUMSK")->AsFloat;
                                }
                        else
                                {

								OutputStringItogiGrpNom(prForm);

								OutputStringGrpNom(prForm);
								IdTecGrpNom=glStrToInt64(DM->DM->pFIBQ->FieldByName("IDGN")->AsString);

								SumRealGrpNom=DM->DM->pFIBQ->FieldByName("SUMREAL")->AsFloat;
								SumSkGrpNom=DM->DM->pFIBQ->FieldByName("SUMSK")->AsFloat;
                                }


						OutputStringNom(prForm);

						SumRealReport=SumRealReport+DM->DM->pFIBQ->FieldByName("SUMREAL")->AsFloat;
						SumSkReport=SumSkReport+DM->DM->pFIBQ->FieldByName("SUMSK")->AsFloat;
                     //   OtrSebRealReport=SumRealReport+IBQNACHOSTSUM->AsFloat;

                        if (AddDoc==true)
                                {
                                CreateReportDoc(prForm);
                                }

                        porNumStrGrp++;
                        porNumStr++;
						DM->DM->pFIBQ->Next();
                        }

OutputStringItogiFirm(prForm);
OutputStringItogiSklad(prForm);
OutputStringItogiGrpNom(prForm);

delete DM;
}
//---------------------------------------------------------------------------
void TReportDiscountDocCheck::OutputZagolovokReport(TSheetEditor *prForm)
{

prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";

        TcxSSHeader *cHeader;
        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 30;
		cHeader->Size[2] = 300;
        cHeader->Size[3] = 70;
        cHeader->Size[4] = 50;
		cHeader->Size[5] = 120;
		cHeader->Size[6] = 120;

y=2;
x=1;

TcxSSCellObject *cell;
cell = prForm->SS->ActiveSheet->GetCellObject(2, y);
cell->Text = "Отчет о скидках  "+DateToStr(PosNach)
						+" по "+DateToStr(PosCon);
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[y]=25;
delete cell;
y++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, y);
		if (OnlyType==true)
                {
				switch (TypeNom)
                        {
                        case 0:
                                {
                                cell->Text ="Только товары";
                                break;
                                }
                        case 1:
                                {
                                cell->Text ="Только услуги";
                                break;
                                }
                        case 2:
                                {
                                cell->Text ="Только продукция";
                                break;
                                }


                        }
                }
        else
                {
                cell->Text ="Все типы номенклатур";
                }
delete cell;
y++;
cell = prForm->SS->ActiveSheet->GetCellObject(2, y);

delete cell;
y++;
y++;


x=1;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "№";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->WordBreak = true;
cell->Text = "Номенклатура";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "Кол.";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//единица
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "Ед.";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "Сумма реал.";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//ссумма скидок
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "Сумма скидок";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

y++;



}
//----------------------------------------------------------------------------
void TReportDiscountDocCheck::OutputStringFirm(TSheetEditor *prForm)
{
num_row_firm=y;

TcxSSCellObject *cell;
x=1;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
x++;

//фирма
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text ="Фирма: "+ DM->DM->pFIBQ->FieldByName("NAMEFIRM")->AsString;
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haLEFT;;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
x++;
//кол
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
x++;
//ед
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
x++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
x++;
//себ
cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
x++;


y++;



}
//----------------------------------------------------------------------------
void TReportDiscountDocCheck::OutputStringItogiFirm(TSheetEditor *prForm)
{
if (num_row_firm==0) return;
TcxSSCellObject *cell;
if(SumRealFirm!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(5, num_row_firm);
        cell->Text = FloatToStrF(SumRealFirm,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(SumSkFirm!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(6, num_row_firm);
		cell->Text = FloatToStrF(SumSkFirm,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

prForm->SS->ActiveSheet->Rows->Size[num_row_firm] = 30;

}
//----------------------------------------------------------------------------
void TReportDiscountDocCheck::OutputStringSklad(TSheetEditor *prForm)
{
num_row_sklad=y;

TcxSSCellObject *cell;
x=1;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
x++;

//склад
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "Склад: "+DM->DM->pFIBQ->FieldByName("NAMESKLAD")->AsString;
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
x++;
//кол
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
x++;
//ед
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
x++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
x++;
//себ
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
x++;

y++;

}
//----------------------------------------------------------------------------
void TReportDiscountDocCheck::OutputStringItogiSklad(TSheetEditor *prForm)
{
if (num_row_sklad==0) return;
TcxSSCellObject *cell;
if(SumRealSklad!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(5, num_row_sklad);
        cell->Text = FloatToStrF(SumRealSklad,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(SumSkSklad!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(6, num_row_sklad);
		cell->Text = FloatToStrF(SumSkSklad,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }
prForm->SS->ActiveSheet->Rows->Size[num_row_sklad] = 30;


}
//----------------------------------------------------------------------------
void TReportDiscountDocCheck::OutputStringGrpNom(TSheetEditor *prForm)
{
num_row_grp_nom=y;

TcxSSCellObject *cell;
x=1;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
///cell->Text = IntToStr(porNumKlient);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
x++;
//группа номенлатура
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = DM->DM->pFIBQ->FieldByName("NAMEGN")->AsString;
cell->Style->Font->Size = 12;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
x++;
//кол
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
x++;
//ед
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
x++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
x++;
//себ
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
x++;
y++;



}
//-----------------------------------------------------------------------------
void TReportDiscountDocCheck::OutputStringItogiGrpNom(TSheetEditor *prForm)
{
if (num_row_grp_nom==0) return;
TcxSSCellObject *cell;
if(SumRealGrpNom!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(5, num_row_grp_nom);
        cell->Text = FloatToStrF(SumRealGrpNom,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 10;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(SumSkGrpNom!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(6, num_row_grp_nom);
		cell->Text = FloatToStrF(SumSkGrpNom,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 10;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

prForm->SS->ActiveSheet->Rows->Size[num_row_grp_nom] = 20;
}
//----------------------------------------------------------------------------
void TReportDiscountDocCheck::OutputStringNom(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
x=1;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//номенлатура
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = DM->DM->pFIBQ->FieldByName("NAMENOM")->AsString;
//cell->Style->HorzTextAlign = haCENTER;
if (AddDoc==true)
        {
        cell->Style->Font->Style = TFontStyles() << fsBold;
        }
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//кол
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
if (DM->DM->pFIBQ->FieldByName("SUMKOL")->AsFloat!=0)
        {
		cell->Text = FloatToStrF(DM->DM->pFIBQ->FieldByName("SUMKOL")->AsFloat,ffFixed,10,3);
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
if (AddDoc==true)
        {
        cell->Style->Font->Style = TFontStyles() << fsBold;
        }
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//ед
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = DM->DM->pFIBQ->FieldByName("NAMEED")->AsString;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
if (AddDoc==true)
        {
        cell->Style->Font->Style = TFontStyles() << fsBold;
        }
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
if (DM->DM->pFIBQ->FieldByName("SUMREAL")->AsFloat!=0)
        {
		cell->Text = FloatToStrF(DM->DM->pFIBQ->FieldByName("SUMREAL")->AsFloat, ffFixed, 10,2);
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
if (AddDoc==true)
        {
        cell->Style->Font->Style = TFontStyles() << fsBold;
        }
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//результ.
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
if (DM->DM->pFIBQ->FieldByName("SUMSK")->AsFloat!=0)
		{
		cell->Text = FloatToStrF(DM->DM->pFIBQ->FieldByName("SUMSK")->AsFloat, ffFixed, 10,2);
		}
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
if (AddDoc==true)
		{
		cell->Style->Font->Style = TFontStyles() << fsBold;
		}
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;


y++;


}
//---------------------------------------------------------------------------
void TReportDiscountDocCheck::OutputPodavalReport(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
x=1;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text ="";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
x++;

//номенлатура
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
x++;

//кол
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Text = FloatToStrF(AllNachOst, ffFixed,15,2);
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
x++;
//ед
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Text = FloatToStrF(AllPrihod, ffFixed,15,2);
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
x++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = FloatToStrF(SumRealReport, ffFixed,15,2);
cell->Style->Font->Size = 12;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
x++;
//себ.
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = FloatToStrF(SumSkReport, ffFixed,15,2);
cell->Style->Font->Size = 12;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
x++;

}

//----------------------------------------------------------------------------
void TReportDiscountDocCheck::CreateReportDoc(TSheetEditor *prForm)
{

DM->OpenReportDoc(PosNach,PosCon,
					DM->DM->pFIBQ->FieldByName("IDFIRM")->AsInteger,
					DM->DM->pFIBQ->FieldByName("IDSKLAD")->AsInteger,
					DM->DM->pFIBQ->FieldByName("IDNOM")->AsInteger);

while(!DM->DMDoc->pFIBQ->Eof)
		{
		OutputStringDoc(prForm);
		DM->DMDoc->pFIBQ->Next();
		}


}
//-----------------------------------------------------------------------------
void TReportDiscountDocCheck::OutputStringDoc(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
x=1;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//номенлатура
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = glGetNameDoc(DM->DMDoc->pFIBQ->FieldByName("TDOC")->AsString)+" №"+
				DM->DMDoc->pFIBQ->FieldByName("NUMDOC")->AsString+" от "+
				DM->DMDoc->pFIBQ->FieldByName("POSDOC")->AsString;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->FontColor=24;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//кол
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
if (DM->DMDoc->pFIBQ->FieldByName("SUMKOL")->AsFloat!=0)
		{
		cell->Text = FloatToStrF(DM->DMDoc->pFIBQ->FieldByName("SUMKOL")->AsFloat,ffFixed,10,3);
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->FontColor=24;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//ед
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = DM->DMDoc->pFIBQ->FieldByName("NAMEED")->AsString;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->FontColor=24;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
if (DM->DMDoc->pFIBQ->FieldByName("SUMREAL")->AsFloat!=0)
        {
		cell->Text = FloatToStrF(DM->DMDoc->pFIBQ->FieldByName("SUMREAL")->AsFloat, ffFixed, 10,2);
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->FontColor=24;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//результ.
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
if (DM->DMDoc->pFIBQ->FieldByName("SUMSK")->AsFloat!=0)
		{
		cell->Text = FloatToStrF(DM->DMDoc->pFIBQ->FieldByName("SUMSK")->AsFloat, ffFixed, 10,2);
		}
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->FontColor=24;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

y++;


}
//-----------------------------------------------------------------------------
