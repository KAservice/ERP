//---------------------------------------------------------------------------


#pragma hdrstop

#include "UReportGoodsReportUnion.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"



//---------------------------------------------------------------------------

#pragma package(smart_init)

//-------------------------------------------------------------------
TReportGoodsReportUnion::TReportGoodsReportUnion()
{


}
//-----------------------------------------------------------------------------
TReportGoodsReportUnion::~TReportGoodsReportUnion()
{


}
//-----------------------------------------------------------------------
bool TReportGoodsReportUnion::Init(void)
{
bool result=false;


SortPoTypeDoc=false;

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
void TReportGoodsReportUnion::CreateReport(void)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

y=1;
x=1;



PrintForm->SS->BeginUpdate();
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
													(void**)&DMSprFirm);
DMSprFirm->Init(InterfaceMainObject,0);
DMSprFirm->OpenElement(IdFirm);

//получим начальный остаток
AnsiString zapros=" select *                 \
from RGOSTNOM_GET_SUM_OSTATOK (            \
 :PARAM_POSDOC,                             \
 :PARAM_IDFIRM,                             \
 :PARAM_IDSKLAD) ";


InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&DMQueryRead);
DMQueryRead->Init(InterfaceMainObject,0);
DMQueryRead->pFIBQ->Close();
DMQueryRead->pFIBQ->SQL->Clear();
DMQueryRead->pFIBQ->SQL->Add(zapros);
DMQueryRead->pFIBQ->ParamByName("PARAM_POSDOC")->AsDateTime=PosNach;
DMQueryRead->pFIBQ->ParamByName("PARAM_IDFIRM")->AsInt64=IdFirm;
DMQueryRead->pFIBQ->ParamByName("PARAM_IDSKLAD")->AsInt64=IdSklad;
DMQueryRead->pFIBQ->ExecQuery();
SumNachOst=DMQueryRead->pFIBQ->FieldByName("OUT_SUM")->AsFloat;
DMQueryRead->pFIBQ->Close();

zapros=" select *             \
 from RGGOODS_GET_SUM_OSTATOK (      \
 :PARAM_POSDOC,                      \
 :PARAM_IDFIRM,                      \
 :PARAM_IDSKLAD) ";

//DMQueryRead=new TDMQueryRead(Application);
//DMQueryRead->DM_Connection=DM_Connection;
//DMQueryRead->Init();
DMQueryRead->pFIBQ->Close();
DMQueryRead->pFIBQ->SQL->Clear();
DMQueryRead->pFIBQ->SQL->Add(zapros);
DMQueryRead->pFIBQ->ParamByName("PARAM_POSDOC")->AsDateTime=PosNach;
DMQueryRead->pFIBQ->ParamByName("PARAM_IDFIRM")->AsInt64=IdFirm;
DMQueryRead->pFIBQ->ParamByName("PARAM_IDSKLAD")->AsInt64=IdSklad;
DMQueryRead->pFIBQ->ExecQuery();
RoznSumNachOst=DMQueryRead->pFIBQ->FieldByName("OUT_SUM")->AsFloat;
DMQueryRead->pFIBQ->Close();
DMQueryRead->kanRelease();


NacSumNachOst=RoznSumNachOst-SumNachOst;

OutputZagolovokReport(PrintForm);
GreateReportPrihod(PrintForm);
OutputZagolovokRashod(PrintForm) ;
GreateReportRashod(PrintForm);
OutputPodvalReport(PrintForm);


DMSprFirm->kanRelease();

PrintForm->SS->EndUpdate();


PrintForm->Show();


}
//---------------------------------------------------------------------------
void TReportGoodsReportUnion::OutputZagolovokReport(TSheetEditor *prForm)
{
prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";

        TcxSSHeader *cHeader;
        cHeader = prForm->SS->ActiveSheet->Cols;
		cHeader->Size[0] = 10;
		cHeader->Size[1] = 200;
		cHeader->Size[2] = 10;
		cHeader->Size[3] = 80;
		cHeader->Size[4] = 20;
		cHeader->Size[5] = 50;
		cHeader->Size[6] = 50;
		cHeader->Size[7] =50;
		cHeader->Size[8] = 50;
		cHeader->Size[9] = 50;
		cHeader->Size[10] = 50;
		cHeader->Size[11] = 20;
		cHeader->Size[12] = 50;

y=0;
x=12;

TcxSSCellObject *cell;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "унифицированная форма № ТОРГ-29 ";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
delete cell;
y++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "Утверждена постановлением Госкомстата ";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
delete cell;
y++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "России от 25.12.98 № 132";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
delete cell;
y++;

x=9;
TRect rect;
rect.Left = x;
rect.Top = y;
rect.Right = x+3;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "Код";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

y++;
x=8;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "Форма по ОКУД  ";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+3;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "0330229";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

y++;
x=1;
rect.Left = x;
rect.Top = y;
rect.Right = x+5;
rect.Bottom = y;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = DMSprFirm->ElementFNAMEFIRM->AsString;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
x++;

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "по ОКПО  ";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+3;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

y++;
x=1;

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

rect.Left = x;
rect.Top = y;
rect.Right = x+3;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

y++;
x=8;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "вид деятельности по ОКДП  ";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+3;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

y++;//***********************
x=8;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "Вид операции ";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+3;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
y++; //******************************
y++; //******************************

x=5;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y+1;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="Номер документа";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y+1;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="Дата составления";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+3;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="отчетный период";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;
x++;

y++;//***********
x=5;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="с";
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="по";
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

y++;//**********************
x=4;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "ТОВАРНЫЙ ОТЧЕТ ";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 16;
delete cell;

x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = DateToStr(PosNach);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = DateToStr(PosCon);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
x++;

y++;//**********************
y++;//**********************
x=9;
rect.Left = x;
rect.Top = y;
rect.Right = x+3;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "Табельный номер";
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

y++;//******************************
x=1;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "Материально-ответственное лицо";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+3;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
delete cell;

y++;//*****************
x=5;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="должность, фамилия, имя, отчество";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaTOP;
cell->Style->Font->Size = 6;
delete cell;

y++;//*********************************
x=1;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y+1;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="Наименование";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+2;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="Документ";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+3;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="Сумма, руб. коп.";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+2;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="Отметки бухг.";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

y++;//*****************************
x=1;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="Дата";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="Номер";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="По себестоимости";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="По розн. цене";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

rect.Left = x;
rect.Top = y;
rect.Right = x+2;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="Наценка";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

y++;//****************
x=1;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="1";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
cell->Text="2";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;

rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
cell->Text="3";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
cell->Text="4";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
cell->Text="5";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="6";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="7";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;

y++;//**********************
x=1;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="Остаток на " +DateToStr(PosNach);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
cell->Style->Font->Style = TFontStyles() << fsBold;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text=FloatToStrF(SumNachOst,ffFixed,15,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Style->Font->Style = TFontStyles() << fsBold;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text=FloatToStrF(RoznSumNachOst,ffFixed,15,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Style->Font->Style = TFontStyles() << fsBold;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text=FloatToStrF(NacSumNachOst,ffFixed,15,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Style->Font->Style = TFontStyles() << fsBold;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

y++;//********************************

x=1;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="ПРИХОД";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

y++;//********************************
}
//---------------------------------------------------------------------------
void TReportGoodsReportUnion::GreateReportPrihod(TSheetEditor *prForm)
{
AnsiString zapros="";
SumPrihod=0;
RoznSumPrihod=0;
NacSumPrihod=0;

zapros=zapros+" select * ";
zapros=zapros+" from report_goodsreport_prihod_full ( ";
zapros=zapros+" :PARAM_POSNACH, ";
zapros=zapros+" :PARAM_POSCON, ";
zapros=zapros+" :PARAM_IDFIRM, ";
zapros=zapros+" :PARAM_IDSKLAD, ";
zapros=zapros+" 0) ";


if (SortPoTypeDoc==true)
	{
	zapros=zapros+" order by OUT_TDOC, OUT_POSDOC ";
	}
else
	{
	zapros=zapros+" order by OUT_POSDOC ";
	}

		InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&DMQueryRead);
DMQueryRead->Init(InterfaceMainObject,0);
DMQueryRead->pFIBQ->Close();
DMQueryRead->pFIBQ->SQL->Clear();
DMQueryRead->pFIBQ->SQL->Add(zapros);
DMQueryRead->pFIBQ->ParamByName("PARAM_IDFIRM")->AsInteger=IdFirm;
DMQueryRead->pFIBQ->ParamByName("PARAM_IDSKLAD")->AsInteger=IdSklad;
DMQueryRead->pFIBQ->ParamByName("PARAM_POSNACH")->AsDateTime=PosNach;
DMQueryRead->pFIBQ->ParamByName("PARAM_POSCON")->AsDateTime=PosCon;
DMQueryRead->pFIBQ->ExecQuery();

while(!DMQueryRead->pFIBQ->Eof)
	{
	OutputStringPrihod(prForm);
	SumPrihod=SumPrihod+DMQueryRead->pFIBQ->FieldByName("OUT_SUM")->AsFloat;
	RoznSumPrihod=RoznSumPrihod+DMQueryRead->pFIBQ->FieldByName("OUT_ROZN_SUM")->AsFloat;
	DMQueryRead->pFIBQ->Next();
	}
DMQueryRead->pFIBQ->Close();
DMQueryRead->kanRelease();
OutputItogiPrihoda(prForm);
}
//-----------------------------------------------------------------------------
void TReportGoodsReportUnion::OutputStringPrihod(TSheetEditor *prForm)
{
x=1;
TRect rect;
TcxSSCellObject *cell;

rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
if (DMQueryRead->pFIBQ->FieldByName("OUT_NAME_KLIENT")->AsString=="")
	{
	cell->Text=glGetNameDoc(DMQueryRead->pFIBQ->FieldByName("OUT_TDOC")->AsString);
	}
else
	{
	cell->Text=glGetNameDoc(DMQueryRead->pFIBQ->FieldByName("OUT_TDOC")->AsString)+
		" ("+DMQueryRead->pFIBQ->FieldByName("OUT_NAME_KLIENT")->AsString+")";
	prForm->SS->ActiveSheet->Rows->Size[y] = 30;
	}
	
cell->Style->WordBreak = true;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text=DateToStr(DMQueryRead->pFIBQ->FieldByName("OUT_POSDOC")->AsDateTime);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;

rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text=DMQueryRead->pFIBQ->FieldByName("OUT_NUMDOC")->AsString;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text=FloatToStrF(DMQueryRead->pFIBQ->FieldByName("OUT_SUM")->AsFloat,ffFixed,15,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text=FloatToStrF(DMQueryRead->pFIBQ->FieldByName("OUT_ROZN_SUM")->AsFloat,ffFixed,15,2);
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text=FloatToStrF(DMQueryRead->pFIBQ->FieldByName("OUT_ROZN_SUM")->AsFloat-
				DMQueryRead->pFIBQ->FieldByName("OUT_SUM")->AsFloat,ffFixed,15,2);
NacSumPrihod=NacSumPrihod+(DMQueryRead->pFIBQ->FieldByName("OUT_ROZN_SUM")->AsFloat-
				DMQueryRead->pFIBQ->FieldByName("OUT_SUM")->AsFloat);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

y++;//********************************



}
//----------------------------------------------------------------------------
void TReportGoodsReportUnion::OutputItogiPrihoda(TSheetEditor *prForm)
{
x=1;
TRect rect;
TcxSSCellObject *cell;

rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="Итого по приходу";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
cell->Style->Font->Style = TFontStyles() << fsBold;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="X";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;

rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="X";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text=FloatToStrF(SumPrihod,ffFixed,15,2);
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text=FloatToStrF(RoznSumPrihod,ffFixed,15,2);
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text=FloatToStrF(NacSumPrihod,ffFixed,15,2);
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
//cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

y++;//********************************

x=1;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="Итого с остатком";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
cell->Style->Font->Style = TFontStyles() << fsBold;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="X";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;

rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="X";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text=FloatToStrF(SumPrihod+SumNachOst,ffFixed,15,2);
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text=FloatToStrF(RoznSumPrihod+RoznSumNachOst,ffFixed,15,2);
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text=FloatToStrF(NacSumPrihod+NacSumNachOst,ffFixed,15,2);
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

y++;//********************************

}
//----------------------------------------------------------------------------
void TReportGoodsReportUnion::OutputZagolovokRashod(TSheetEditor *prForm)
{
y++;y++;
x=1;
TRect rect;
TcxSSCellObject *cell;


rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y+1;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="Наименование";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+2;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="Документ";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+3;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="Сумма, руб. коп.";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+2;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="Отметки бухг.";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

y++;//*****************************
x=1;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="Дата";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="Номер";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="По себестоимости";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="По розн. цене";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

rect.Left = x;
rect.Top = y;
rect.Right = x+2;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="Наценка";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

y++;//****************
x=1;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="1";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
cell->Text="2";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;

rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
cell->Text="3";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
cell->Text="4";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
cell->Text="5";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="6";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="7";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;

y++;//**********************
x=1;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="РАСХОД ";
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

y++;//********************************

}
//-----------------------------------------------------------------------------
void TReportGoodsReportUnion::GreateReportRashod(TSheetEditor *prForm)
{
AnsiString zapros="";
SumRashod=0;

zapros=" select *        \
 from REPORT_GOODSREPORT_RASHOD_FULL (:PARAM_POSNACH,:PARAM_POSCON,:PARAM_IDFIRM,:PARAM_IDSKLAD,:PARAM_PODATE)  ";

if (SortPoTypeDoc==true)
	{
	zapros=zapros+" order by OUT_TDOC, OUT_POSDOC ";
	}
else
	{
	zapros=zapros+" order by OUT_POSDOC ";
	}

InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&DMQueryRead);
DMQueryRead->Init(InterfaceMainObject,0);
DMQueryRead->pFIBQ->Close();
DMQueryRead->pFIBQ->SQL->Clear();
DMQueryRead->pFIBQ->SQL->Add(zapros);
DMQueryRead->pFIBQ->ParamByName("PARAM_IDFIRM")->AsInteger=IdFirm;
DMQueryRead->pFIBQ->ParamByName("PARAM_IDSKLAD")->AsInteger=IdSklad;
DMQueryRead->pFIBQ->ParamByName("PARAM_POSNACH")->AsDateTime=PosNach;
DMQueryRead->pFIBQ->ParamByName("PARAM_POSCON")->AsDateTime=PosCon;
DMQueryRead->pFIBQ->ParamByName("PARAM_PODATE")->AsInteger=GroupCheckPoDate;

DMQueryRead->pFIBQ->ExecQuery();
while(!DMQueryRead->pFIBQ->Eof)
	{
	OutputStringRashod(prForm);
	SumRashod=SumRashod+DMQueryRead->pFIBQ->FieldByName("OUT_SUM")->AsFloat;
	RoznSumRashod=RoznSumRashod+DMQueryRead->pFIBQ->FieldByName("OUT_ROZN_SUM")->AsFloat;
	NacSumRashod=NacSumRashod+(DMQueryRead->pFIBQ->FieldByName("OUT_ROZN_SUM")->AsFloat-
									DMQueryRead->pFIBQ->FieldByName("OUT_SUM")->AsFloat);
	DMQueryRead->pFIBQ->Next();
	}
DMQueryRead->pFIBQ->Close();
DMQueryRead->kanRelease();
}
//----------------------------------------------------------------------------
void TReportGoodsReportUnion::OutputStringRashod(TSheetEditor *prForm)
{
x=1;
TRect rect;
TcxSSCellObject *cell;

rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
if (DMQueryRead->pFIBQ->FieldByName("OUT_NAME_KLIENT")->AsString=="")
	{
	cell->Text=glGetNameDoc(DMQueryRead->pFIBQ->FieldByName("OUT_TDOC")->AsString);
	}
else
	{
	cell->Text=glGetNameDoc(DMQueryRead->pFIBQ->FieldByName("OUT_TDOC")->AsString)+
		" ("+DMQueryRead->pFIBQ->FieldByName("OUT_NAME_KLIENT")->AsString+")";
	prForm->SS->ActiveSheet->Rows->Size[y] = 30;
	}
	
cell->Style->WordBreak = true;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text=DateToStr(DMQueryRead->pFIBQ->FieldByName("OUT_POSDOC")->AsDateTime);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;

rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text=DMQueryRead->pFIBQ->FieldByName("OUT_NUMDOC")->AsString;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text=FloatToStrF(DMQueryRead->pFIBQ->FieldByName("OUT_SUM")->AsFloat,ffFixed,15,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text=FloatToStrF(DMQueryRead->pFIBQ->FieldByName("OUT_ROZN_SUM")->AsFloat,ffFixed,15,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text=FloatToStrF(DMQueryRead->pFIBQ->FieldByName("OUT_ROZN_SUM")->AsFloat-
							DMQueryRead->pFIBQ->FieldByName("OUT_SUM")->AsFloat,ffFixed,15,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

y++;//********************************

}
//----------------------------------------------------------------------------
void TReportGoodsReportUnion::OutputPodvalReport(TSheetEditor *prForm)
{
x=1;
TRect rect;
TcxSSCellObject *cell;

rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="Итого по расходу";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
cell->Style->Font->Style = TFontStyles() << fsBold;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="X";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;

rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="X";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text=FloatToStrF(SumRashod,ffFixed,15,2);
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text=FloatToStrF(RoznSumRashod,ffFixed,15,2);
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text=FloatToStrF(NacSumRashod,ffFixed,15,2);
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
//cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

y++;//********************************

x=1;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="Остаток на "+ DateToStr(PosCon);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
cell->Style->Font->Style = TFontStyles() << fsBold;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="X";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;

rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="X";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text=FloatToStrF(SumNachOst+SumPrihod-SumRashod,ffFixed,15,2);
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text=FloatToStrF(RoznSumNachOst+RoznSumPrihod-RoznSumRashod,ffFixed,15,2);
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text=FloatToStrF(NacSumNachOst+NacSumPrihod-NacSumRashod,ffFixed,15,2);
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
//cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

y++;//***********************
y++;//***********************

x=1;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="Приложение";
cell->Style->Font->Size = 8;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="документов";
cell->Style->Font->Size = 8;
delete cell;

y++;//***********************
y++;//***********************

x=1;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="Отчет с документами принял и проверил";
cell->Style->Font->Size = 8;
delete cell;

x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

y++;//***********************
cell = prForm->SS->ActiveSheet->GetCellObject(3, y);
cell->Text="должность";
cell->Style->Font->Size = 6;
cell->Style->VertTextAlign = vaTOP;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(7, y);
cell->Text="Подпись";
cell->Style->Font->Size = 6;
cell->Style->VertTextAlign = vaTOP;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(11, y);
cell->Text="Расшифровка";
cell->Style->Font->Size = 6;
cell->Style->VertTextAlign = vaTOP;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
y++;//***********************

x=1;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="Материально-ответственное лицо";
cell->Style->Font->Size = 8;
delete cell;

x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;

y++;//***********************
cell = prForm->SS->ActiveSheet->GetCellObject(3, y);
cell->Text="должность";
cell->Style->Font->Size = 6;
cell->Style->VertTextAlign = vaTOP;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(7, y);
cell->Text="Подпись";
cell->Style->Font->Size = 6;
cell->Style->VertTextAlign = vaTOP;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(11, y);
cell->Text="Расшифровка";
cell->Style->Font->Size = 6;
cell->Style->VertTextAlign = vaTOP;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
y++;//***********************

}

//----------------------------------------------------------------------------
void TReportGoodsReportUnion::CreateReportRozn(void)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

y=1;
x=1;



PrintForm->SS->BeginUpdate();
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
													(void**)&DMSprFirm);
DMSprFirm->Init(InterfaceMainObject,0);
DMSprFirm->OpenElement(IdFirm);

//получим начальный остаток
AnsiString zapros="";
double SumTekOst=0;
zapros=zapros+" select sum(rggoods.rprice_rggoods * rggoods.kol_rggoods) ";
zapros=zapros+" from rggoods ";
zapros=zapros+" where rggoods.idfirm_rggoods=:PARAM_IDFIRM and rggoods.idsklad_rggoods=:PARAM_IDSKLAD ";


InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&DMQueryRead);
DMQueryRead->Init(InterfaceMainObject,0);
DMQueryRead->pFIBQ->Close();
DMQueryRead->pFIBQ->SQL->Clear();
DMQueryRead->pFIBQ->SQL->Add(zapros);
DMQueryRead->pFIBQ->ParamByName("PARAM_IDFIRM")->AsInt64=IdFirm;
DMQueryRead->pFIBQ->ParamByName("PARAM_IDSKLAD")->AsInt64=IdSklad;
DMQueryRead->pFIBQ->ExecQuery();
SumTekOst=DMQueryRead->pFIBQ->FieldByName("SUM")->AsFloat;
DMQueryRead->pFIBQ->Close();

double sum_prihod=0;
zapros="";
zapros=zapros+"  select sum(rggoods_dv.rprice_rggoods_dv * rggoods_dv.kol_rggoods_dv) ";
zapros=zapros+" from rggoods_dv             ";
zapros=zapros+" where rggoods_dv.idfirm_rggoods_dv=:PARAM_IDFIRM ";
zapros=zapros+"         and rggoods_dv.idsklad_rggoods_dv=:PARAM_IDSKLAD";
zapros=zapros+"         and rggoods_dv.tdv_rggoods_dv=0 ";
zapros=zapros+" 		and rggoods_dv.posdoc_rggoods_dv>:PARAM_POSDOC ";

DMQueryRead->pFIBQ->SQL->Clear();
DMQueryRead->pFIBQ->SQL->Add(zapros);
DMQueryRead->pFIBQ->ParamByName("PARAM_IDFIRM")->AsInt64=IdFirm;
DMQueryRead->pFIBQ->ParamByName("PARAM_IDSKLAD")->AsInt64=IdSklad;
DMQueryRead->pFIBQ->ParamByName("PARAM_POSDOC")->AsDateTime=PosNach;
DMQueryRead->pFIBQ->ExecQuery();
sum_prihod=DMQueryRead->pFIBQ->FieldByName("SUM")->AsFloat;
DMQueryRead->pFIBQ->Close();

double sum_rashod=0;
zapros="";
zapros=zapros+" select sum(rggoods_dv.rprice_rggoods_dv * rggoods_dv.kol_rggoods_dv) ";
zapros=zapros+" from rggoods_dv             ";
zapros=zapros+" where rggoods_dv.idfirm_rggoods_dv=:PARAM_IDFIRM ";
zapros=zapros+"         and rggoods_dv.idsklad_rggoods_dv=:PARAM_IDSKLAD";
zapros=zapros+"         and rggoods_dv.tdv_rggoods_dv=1";
zapros=zapros+" 		and rggoods_dv.posdoc_rggoods_dv>:PARAM_POSDOC ";

DMQueryRead->pFIBQ->SQL->Clear();
DMQueryRead->pFIBQ->SQL->Add(zapros);
DMQueryRead->pFIBQ->ParamByName("PARAM_IDFIRM")->AsInt64=IdFirm;
DMQueryRead->pFIBQ->ParamByName("PARAM_IDSKLAD")->AsInt64=IdSklad;
DMQueryRead->pFIBQ->ParamByName("PARAM_POSDOC")->AsDateTime=PosNach;
DMQueryRead->pFIBQ->ExecQuery();
sum_rashod=DMQueryRead->pFIBQ->FieldByName("SUM")->AsFloat;
DMQueryRead->pFIBQ->Close();
DMQueryRead->kanRelease();

SumNachOst=SumTekOst+sum_rashod-sum_prihod;

OutputZagolovokReport(PrintForm);
GreateReportPrihodRozn(PrintForm);
OutputZagolovokRashod(PrintForm) ;
GreateReportRashodRozn(PrintForm);
OutputPodvalReport(PrintForm);


DMSprFirm->kanRelease();
PrintForm->SS->EndUpdate();


PrintForm->Show();


}
//---------------------------------------------------------------------------
void TReportGoodsReportUnion::GreateReportPrihodRozn(TSheetEditor *prForm)
{
AnsiString zapros="";
SumPrihod=0;

zapros=zapros+" select galldoc.iddoc, galldoc.posdoc, galldoc.tdoc, galldoc.numdoc, sum(rggoods_dv.rprice_rggoods_dv * rggoods_dv.kol_rggoods_dv)";
zapros=zapros+" , sklient.nameklient  ";
zapros=zapros+" from rggoods_dv  ";
zapros=zapros+" left outer join galldoc on rggoods_dv.iddoc_rggoods_dv=galldoc.iddoc ";
zapros=zapros+" left outer join sklient on galldoc.idkldoc=sklient.idklient   ";
zapros=zapros+" where rggoods_dv.idfirm_rggoods_dv=:PARAM_IDFIRM  and ";
zapros=zapros+"         rggoods_dv.idsklad_rggoods_dv=:PARAM_IDSKLAD  and ";
zapros=zapros+"         (rggoods_dv.posdoc_rggoods_dv between :PARAM_POSNACH and :PARAM_POSCON) and ";
zapros=zapros+"         rggoods_dv.tdv_rggoods_dv=0 ";
zapros=zapros+"  group by galldoc.iddoc, galldoc.posdoc, galldoc.tdoc, galldoc.numdoc";
zapros=zapros+", sklient.nameklient";

if (SortPoTypeDoc==true)
	{
	zapros=zapros+" order by galldoc.tdoc, galldoc.posdoc ";
	}
else
	{
	zapros=zapros+" order by galldoc.posdoc ";
	}


InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&DMQueryRead);
DMQueryRead->Init(InterfaceMainObject,0);
DMQueryRead->pFIBQ->Close();
DMQueryRead->pFIBQ->SQL->Clear();
DMQueryRead->pFIBQ->SQL->Add(zapros);
DMQueryRead->pFIBQ->ParamByName("PARAM_IDFIRM")->AsInteger=IdFirm;
DMQueryRead->pFIBQ->ParamByName("PARAM_IDSKLAD")->AsInteger=IdSklad;
DMQueryRead->pFIBQ->ParamByName("PARAM_POSNACH")->AsDateTime=PosNach;
DMQueryRead->pFIBQ->ParamByName("PARAM_POSCON")->AsDateTime=PosCon;
DMQueryRead->pFIBQ->ExecQuery();
while(!DMQueryRead->pFIBQ->Eof)
	{
	OutputStringPrihod(prForm);
	SumPrihod=SumPrihod+DMQueryRead->pFIBQ->FieldByName("SUM")->AsFloat;
	DMQueryRead->pFIBQ->Next();
	}
DMQueryRead->pFIBQ->Close();
DMQueryRead->kanRelease();
OutputItogiPrihoda(prForm);
}
//-----------------------------------------------------------------------------
void TReportGoodsReportUnion::GreateReportRashodRozn(TSheetEditor *prForm)
{
AnsiString zapros="";
SumRashod=0;

zapros=zapros+"  select REPORT_GOODSREPORT_RASHOD_ROZN.*";
zapros=zapros+", sklient.nameklient  ";
zapros=zapros+" from REPORT_GOODSREPORT_RASHOD_ROZN (:PARAM_POSNACH,:PARAM_POSCON,:PARAM_IDFIRM,:PARAM_IDSKLAD,:PARAM_PODATE)  ";
zapros=zapros+" left outer join galldoc on galldoc.iddoc=REPORT_GOODSREPORT_RASHOD_ROZN.out_iddoc ";
zapros=zapros+" left outer join sklient on sklient.idklient=galldoc.idkldoc  ";


if (SortPoTypeDoc==true)
	{
	zapros=zapros+" order by OUT_TDOC, OUT_POSDOC ";
	}
else
	{
	zapros=zapros+" order by OUT_POSDOC ";
	}


InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&DMQueryRead);
DMQueryRead->Init(InterfaceMainObject,0);
DMQueryRead->pFIBQ->Close();
DMQueryRead->pFIBQ->SQL->Clear();
DMQueryRead->pFIBQ->SQL->Add(zapros);
DMQueryRead->pFIBQ->ParamByName("PARAM_IDFIRM")->AsInteger=IdFirm;
DMQueryRead->pFIBQ->ParamByName("PARAM_IDSKLAD")->AsInteger=IdSklad;
DMQueryRead->pFIBQ->ParamByName("PARAM_POSNACH")->AsDateTime=PosNach;
DMQueryRead->pFIBQ->ParamByName("PARAM_POSCON")->AsDateTime=PosCon;
DMQueryRead->pFIBQ->ParamByName("PARAM_PODATE")->AsInteger=GroupCheckPoDate;

DMQueryRead->pFIBQ->ExecQuery();
while(!DMQueryRead->pFIBQ->Eof)
	{
	OutputStringRashod(prForm);
	SumRashod=SumRashod+DMQueryRead->pFIBQ->FieldByName("OUT_SUM")->AsFloat;
	DMQueryRead->pFIBQ->Next();
	}
DMQueryRead->pFIBQ->Close();
DMQueryRead->kanRelease();
}
//----------------------------------------------------------------------------
