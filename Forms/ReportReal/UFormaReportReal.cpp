//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UFormaReportReal.h"
#include "math.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaReportReal::TFormaReportReal(TComponent* Owner)
        : TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;

}
//---------------------------------------------------------------------------
bool TFormaReportReal::Init(void)
{
bool result=false;

if (InterfaceMainObject>0)
	{
	//получим соединение
	IConnectionInterface * i_connection;
	InterfaceMainObject->kanQueryInterface(IID_IConnectionInterface,(void**)&i_connection);
	DM_Connection=i_connection->GetFibConnection();
	i_connection->kanRelease();

	//получим интерфейс COM системы для создания новых объектов
	IMainCOMInterface * i_com;
	InterfaceMainObject->kanQueryInterface(IID_IMainCOMInterface,(void**)&i_com);
	InterfaceGlobalCom=i_com->GetCOM();
	i_com->kanRelease();
	}

DateCon->Date=Date()+EncodeTime(23,59,59,999);
DateNach->Date=Date()+EncodeTime(0,0,0,0);
DM=new TDMReportSale(Application);
DM->DM_Connection=DM_Connection;
DM->Init();


IdFirm=glStrToInt64(DM_Connection->ARMInfoIDFIRM_SARM->AsString);
LabelNameFirm->Caption=DM_Connection->ARMInfoNAMEFIRM->AsString;
IdSklad=glStrToInt64(DM_Connection->ARMInfoIDSKLAD_SARM->AsString);
LabelNameSklad->Caption=DM_Connection->ARMInfoNAMESKLAD->AsString;

//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;
return result;
}
//---------------------------------------------------------------------------
int TFormaReportReal::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaReportReal::FormClose(TObject *Sender,
      TCloseAction &Action)
{
delete DM;
Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}


//---------------------------------------------------------------
void TFormaReportReal::CreateReport( TSheetEditor *prForm)
{

DM->OpenReport(DateNach->Date,DateCon->Date, IdFirm , IdSklad);
porNumStr=1;
DM->IBQ->First();

IdTecFirm=glStrToInt64(DM->IBQIDFIRM_RGREAL_DV->AsString);
num_row_firm=numRow;
OutputStringFirm(prForm);


IdTecSklad=glStrToInt64(DM->IBQIDSKLAD_RGREAL_DV->AsString);
num_row_sklad=numRow;
OutputStringSklad(prForm);


IdTecGrpNom=glStrToInt64(DM->IBQIDGN->AsString);
num_row_grp_nom=numRow;
OutputStringGrpNom(prForm);


                while(!DM->IBQ->Eof)
                        {
                        //фирма
						if (glStrToInt64(DM->IBQIDFIRM_RGREAL_DV->AsString)==IdTecFirm)
                                {   //эта же фирма
								SumFirm=SumFirm+DM->IBQSUMREAL->AsFloat;
                                }
                        else
                                {
                                OutputStringItogiFirm(prForm);
                                num_row_firm=numRow;
                                OutputStringFirm(prForm);
								IdTecFirm=glStrToInt64(DM->IBQIDFIRM_RGREAL_DV->AsString);
								SumFirm=DM->IBQSUMREAL->AsFloat;
								}

                        //склад
						if (glStrToInt64(DM->IBQIDSKLAD_RGREAL_DV->AsString)==IdTecSklad)
                                {   //эта же группа
								SumSklad=SumSklad+DM->IBQSUMREAL->AsFloat;
                                }
                        else
                                {
                                OutputStringItogiSklad(prForm);
                                num_row_sklad=numRow;
                                OutputStringSklad(prForm);
								IdTecSklad=glStrToInt64(DM->IBQIDSKLAD_RGREAL_DV->AsString);
								SumSklad=DM->IBQSUMREAL->AsFloat;
                                }

                        //группа номенклатуры
						if (glStrToInt64(DM->IBQIDGN->AsString)==IdTecGrpNom)
                                {   //этот же группа
								SumGrpNom=SumGrpNom+DM->IBQSUMREAL->AsFloat;
                                }
                        else
                                {
                                OutputStringItogiGrpNom(prForm);
                                num_row_grp_nom=numRow;
                                OutputStringGrpNom(prForm);
								IdTecGrpNom=glStrToInt64(DM->IBQIDGN->AsString);
								SumGrpNom=DM->IBQSUMREAL->AsFloat;
                                porNumStr=1;
                                }

                        OutputStringNom(prForm);
                        porNumStr++;

						SumAll=SumAll+DM->IBQSUMREAL->AsFloat;
						DM->IBQ->Next();
                        }

OutputStringItogiFirm(prForm);
OutputStringItogiSklad(prForm);
OutputStringItogiGrpNom(prForm);

}
//---------------------------------------------------------------------------
void TFormaReportReal::OutputZagolovokReport(TSheetEditor *prForm)
{
        TcxSSHeader *cHeader;
        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 50;
        cHeader->Size[2] = 300;
        cHeader->Size[3] = 100;
        cHeader->Size[4] = 100;
        cHeader->Size[5] = 100;
        cHeader->Size[6] = 100;


numRow=2;
numCol=1;

TcxSSCellObject *cell;
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text = "Реализация товаров и услуг "+DateToStr(DateNach->Date)
                        +" по "+DateToStr(DateCon->Date);
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
delete cell;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
numRow++;
numRow++;


numCol=1;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "№";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->WordBreak = true;
cell->Text = "Фирма / Склад / Группа / Номенклатура";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//нач остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Количество";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Единица";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Сумма";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

numRow++;
}

//----------------------------------------------------------------------------
//***************   ФИРМА     *********
//----------------------------------------------------------------------------
void TFormaReportReal::OutputStringFirm(TSheetEditor *prForm)
{
TcxSSBrush *brush;
TcxSSCellObject *cell;
numCol=1;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;

//фирма
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Фирма: "+DM->IBQNAMEFIRM->AsString;
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//нач остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;

numCol++;
numRow++;
}
//----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void TFormaReportReal::OutputStringItogiFirm(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
if(SumFirm!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(5, num_row_firm);
        cell->Text = FloatToStrF(SumFirm,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 16;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }
}
//----------------------------------------------------------------------------
// склад
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
void TFormaReportReal::OutputStringSklad(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
// ном.
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Склад: "+DM->IBQNAMESKLAD->AsString;
cell->Style->Font->Size = 14;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//нач остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
numRow++;
}
//----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void TFormaReportReal::OutputStringItogiSklad(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
if(SumSklad!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(5, num_row_sklad);
        cell->Text = FloatToStrF(SumSklad,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 14;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

}
//-----------------------------------------------------------------------------
//  группа номенклатуры
//-----------------------------------------------------------------------------
void TFormaReportReal::OutputStringGrpNom(TSheetEditor *prForm)
{

TcxSSCellObject *cell;
numCol=1;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text = IntToStr(porNumStrGrp);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
//номенлатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = DM->IBQNAMEGN->AsString;
cell->Style->Font->Size = 12;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
//нач остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
numRow++;
}
//---------------------------------------------------------------------------
void TFormaReportReal::OutputStringItogiGrpNom(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
if(SumGrpNom!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(5, num_row_grp_nom);
        cell->Text = FloatToStrF(SumGrpNom,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

}

//------------------------------------------------------------------------------
void TFormaReportReal::OutputStringNom(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = IntToStr(porNumStr);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//номенлатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = DM->IBQNAMENOM->AsString;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->WordBreak=true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//нач остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->IBQSUMKOL->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->IBQNAMEED->AsString;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (DM->IBQSUMREAL->AsFloat!=0)
        {
        cell->Text=FloatToStrF(DM->IBQSUMREAL->AsFloat,ffFixed,10,2);
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
numRow++;
}

//--------------------------------------------------------------------------


void TFormaReportReal::OutputPodavalReport(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
numCol++;

//номенлатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
numCol++;

//нач остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text = FloatToStrF(AllNachOst, ffFixed,15,2);
cell->Style->Font->Size = 14;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
numCol++;
//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text = FloatToStrF(AllPrihod, ffFixed,15,2);
cell->Style->Font->Size = 14;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
numCol++;
//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(SumAll, ffFixed,15,2);
cell->Style->Font->Size = 14;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;

numCol++;
}
//-----------------------------------------------------------------------------






void __fastcall TFormaReportReal::cxButtonCreateClick(TObject *Sender)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;

porNumStrGrp=1;
porNumStr=1;
SumAll=0;
SumFirm=0;
SumSklad=0;
SumGrpNom=0;

PrintForm->SS->BeginUpdate();

//шапка
OutputZagolovokReport(PrintForm);

//таблица

CreateReport( PrintForm);


OutputPodavalReport(PrintForm);
PrintForm->SS->EndUpdate();
PrintForm->Show();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportReal::OpenHelpExecute(TObject *Sender)
{
Application->HelpJump("ReportRealForCashier");	
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportReal::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
int TFormaReportReal::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{


return -1;
}
