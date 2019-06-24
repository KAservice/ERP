//---------------------------------------------------------------------------


#pragma hdrstop

#include "UReportDvRegDoc.h"
#include "IDMQueryRead.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)


//-------------------------------------------------------------------
TReportDvRegDoc::TReportDvRegDoc()
{


}
//-----------------------------------------------------------------------------
TReportDvRegDoc::~TReportDvRegDoc()
{


}
//-----------------------------------------------------------------------
bool TReportDvRegDoc::Init(void)
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
void TReportDvRegDoc::CreateReport(void)
{
InterfaceGlobalCom->kanCreateObject(ProgId_SheetEditor, IID_ISheetEditor,
																	(void**)&SE);


SE->RowsAutoHeight=false;

if (!SE) return;

x = 1;
y = 1;
SE->BeginUpdate();

SE->SetColumnWidth(0,10);
SE->SetColumnWidth(1,50);
SE->SetColumnWidth(2,120);


IDMQueryRead  * q;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&q);
q->Init(InterfaceMainObject,0);
q->pFIBQ->SQL->Clear();
q->pFIBQ->SQL->Add(" select TDOC, POSDOC, NUMDOC from GALLDOC where IDDOC="+IntToStr(IdDoc));
q->pFIBQ->ExecQuery();

SE->TecCell_GetObject(x, y);
SE->TecCell_SetText( "Движения регистров документа "+glGetNameDoc(q->pFIBQ->FieldByName("TDOC")->AsString)
								+"  №"+q->pFIBQ->FieldByName("NUMDOC")->AsString
								+" от "+q->pFIBQ->FieldByName("POSDOC")->AsString);
SE->TecCell_SetHorzTextAlign(ISheetEditor::haLEFT);
SE->TecCell_SetFontSize(16);
SE->TecCell_SetFontStyle(TFontStyles() << fsBold);
SE->SetRowsHeight(y, 25);
SE->TecCell_DeleteObject();
y++;

SE->TecCell_GetObject(x, y);
SE->TecCell_SetText(  "ID документа "+IntToStr(IdDoc));
SE->TecCell_SetHorzTextAlign(ISheetEditor::haLEFT);
SE->SetRowsHeight(y, 25);
SE->TecCell_DeleteObject();

q->kanRelease();
y++;y++;

OutputReport_RegAdvCust();
OutputReport_RegBank();
OutputReport_RegGoods();
OutputReport_RegKassa();
OutputReport_RegOstNom();
OutputReport_RegOtrSpis();
OutputReport_RegPaySale();
OutputReport_RegSebProd();
OutputReport_RegVipProd();
OutputReport_RegVSRasch();
OutputReport_RegReal();



SE->EndUpdate();


}
//-----------------------------------------------------------------------------
void TReportDvRegDoc::OutputReport_RegAdvCust(void)
{

IDMQueryRead  * q;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&q);
q->Init(InterfaceMainObject,0);
q->pFIBQ->SQL->Clear();
q->pFIBQ->SQL->Add(" select RGADVCUST_DV.*, NAMEFIRM, NAMEKLIENT from RGADVCUST_DV");
q->pFIBQ->SQL->Add(" left outer join SFIRM on IDFIRM_RGADVCUST_DV=IDFIRM");
q->pFIBQ->SQL->Add(" left outer join SKLIENT on IDKLIENT_RGADVCUST_DV=IDKLIENT");
q->pFIBQ->SQL->Add(" where IDDOC_RGADVCUST_DV="+IntToStr(IdDoc));
q->pFIBQ->ExecQuery();
if (q->pFIBQ->RecordCount==0)
	{
	q->kanRelease();
	return;
	}
SE->TecCell_GetObject(2, y);
SE->TecCell_SetText( "Авансы покупателей ");
SE->TecCell_SetHorzTextAlign(ISheetEditor::haLEFT);
SE->TecCell_SetFontSize(16);
SE->TecCell_SetFontStyle(TFontStyles() << fsBold);
SE->SetRowsHeight(y, 25);
SE->TecCell_DeleteObject();
y++;y++;

//шапка
	x=1;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText( "Тип дв.");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText( "Поз. док");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	TRect rect;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("Фирма");
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("Контрагент");
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);;
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Сумма");
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	y++;


//конец шапки

while(!q->pFIBQ->Eof)
	{
	x=1;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetFontSize(16);
	if (q->pFIBQ->FieldByName("TDV_RGADVCUST_DV")->AsInteger==0)
		{
		SE->TecCell_SetText("+");
		SE->TecCell_SetFontColor(4);
		}
	else
		{
		SE->TecCell_SetText("-");
		SE->TecCell_SetFontColor(2);
		}
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("POS_RGADVCUST_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("ID="+q->pFIBQ->FieldByName("IDFIRM_RGADVCUST_DV")->AsString
				+" "+q->pFIBQ->FieldByName("NAMEFIRM")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("ID="+q->pFIBQ->FieldByName("IDKLIENT_RGADVCUST_DV")->AsString
				+" "+q->pFIBQ->FieldByName("NAMEKLIENT")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
	SE->TecCell_SetText( q->pFIBQ->FieldByName("SUM_RGADVCUST_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	q->pFIBQ->Next();
	y++;
	}
	y++;
q->kanRelease();
}
//----------------------------------------------------------------------------
void TReportDvRegDoc::OutputReport_RegBank(void)
{
IDMQueryRead  * q;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&q);
q->Init(InterfaceMainObject,0);
q->pFIBQ->SQL->Clear();
q->pFIBQ->SQL->Add(" select RGBANK_DV.*, NAMEFIRM, NAMEBSCHET from RGBANK_DV");
q->pFIBQ->SQL->Add(" left outer join SFIRM on IDFIRM_RGBANK_DV=IDFIRM");
q->pFIBQ->SQL->Add(" left outer join SBSCHET on IDBSCHET_RGBANK_DV=IDBSCHET");
q->pFIBQ->SQL->Add(" where IDDOC_RGBANK_DV="+IntToStr(IdDoc));
q->pFIBQ->ExecQuery();
if (q->pFIBQ->RecordCount==0)
	{
	q->kanRelease();
	return;
	}
SE->TecCell_GetObject(2, y);
SE->TecCell_SetText("Банк");
SE->TecCell_SetHorzTextAlign(ISheetEditor::haLEFT);
SE->TecCell_SetFontSize(16);
SE->TecCell_SetFontStyle(TFontStyles() << fsBold);
SE->SetRowsHeight(y,25);
SE->TecCell_DeleteObject();
y++;y++;

//шапка
	x=1;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Тип дв.");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("Поз. док.");
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	TRect rect;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("Фирма");
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("Банк. счет");
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Сумма");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Опер.");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->SetRowsHeight(y, 20);
	y++;
//конец шапки

while(!q->pFIBQ->Eof)
	{
	x=1;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetFontSize(16);
	if (q->pFIBQ->FieldByName("TDV_RGBANK_DV")->AsInteger==0)
		{
		SE->TecCell_SetText("+");
		SE->TecCell_SetFontColor(4);
		}
	else
		{
		SE->TecCell_SetText("-");
		SE->TecCell_SetFontColor(2);
		}
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("POSDOC_RGBANK_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("ID="+q->pFIBQ->FieldByName("IDFIRM_RGBANK_DV")->AsString
				+" "+q->pFIBQ->FieldByName("NAMEFIRM")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText( "ID="+q->pFIBQ->FieldByName("IDBSCHET_RGBANK_DV")->AsString
				+" "+q->pFIBQ->FieldByName("NAMEBSCHET")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("SUM_RGBANK_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("OPER_RGBANK_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	q->pFIBQ->Next();
	SE->SetRowsHeight(y, 20);
	y++;
	}
	y++;
q->kanRelease();

}
//---------------------------------------------------------------------------
void TReportDvRegDoc::OutputReport_RegGoods(void)
{
IDMQueryRead  * q;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&q);
q->Init(InterfaceMainObject,0);
q->pFIBQ->SQL->Clear();
q->pFIBQ->SQL->Add(" select RGGOODS_DV.*, NAMEFIRM, NAMESKLAD, NAMENOM from RGGOODS_DV");
q->pFIBQ->SQL->Add(" left outer join SFIRM on IDFIRM_RGGOODS_DV=IDFIRM");
q->pFIBQ->SQL->Add(" left outer join SSKLAD on IDSKLAD_RGGOODS_DV=IDSKLAD");
q->pFIBQ->SQL->Add(" left outer join SNOM on IDNOM_RGGOODS_DV=IDNOM");
q->pFIBQ->SQL->Add(" where IDDOC_RGGOODS_DV="+IntToStr(IdDoc));
q->pFIBQ->ExecQuery();
if (q->pFIBQ->RecordCount==0)
	{
	q->kanRelease();
	return;
	}
SE->TecCell_GetObject(2, y);
SE->TecCell_SetText("Остатки товаров ");
SE->TecCell_SetHorzTextAlign(ISheetEditor::haLEFT);
SE->TecCell_SetFontSize(16);
SE->TecCell_SetFontStyle(TFontStyles() << fsBold);
SE->SetRowsHeight(y,25);
SE->TecCell_DeleteObject();
y++;y++;

//шапка
	x=1;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Тип дв.");
SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Поз. док.");
SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
SE->TecCell_DeleteObject();
	x++;
	TRect rect;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Фирма");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("Склад");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("Товар");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Розн. цена");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Кол.");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Опер.");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Тип");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->SetRowsHeight(y,20);
	y++;
//конец шапки

while(!q->pFIBQ->Eof)
	{
	x=1;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetFontSize(16);
	if (q->pFIBQ->FieldByName("TDV_RGGOODS_DV")->AsInteger==0)
		{
		SE->TecCell_SetText("+");
		SE->TecCell_SetFontColor(4);
		}
	else
		{
		SE->TecCell_SetText("-");
		SE->TecCell_SetFontColor(2);
		}
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("POSDOC_RGGOODS_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("ID="+q->pFIBQ->FieldByName("IDFIRM_RGGOODS_DV")->AsString
				+" "+q->pFIBQ->FieldByName("NAMEFIRM")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("ID="+q->pFIBQ->FieldByName("IDSKLAD_RGGOODS_DV")->AsString
				+" "+q->pFIBQ->FieldByName("NAMESKLAD")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("ID="+q->pFIBQ->FieldByName("IDNOM_RGGOODS_DV")->AsString
				+" "+q->pFIBQ->FieldByName("NAMENOM")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("RPRICE_RGGOODS_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("KOL_RGGOODS_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
	SE->TecCell_SetText( q->pFIBQ->FieldByName("OPER_RGGOODS_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("TYPE_RGGOODS_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	q->pFIBQ->Next();
	SE->SetRowsHeight(y,20);
	y++;
	}
	y++;
q->kanRelease();
}
//----------------------------------------------------------------------------
void TReportDvRegDoc::OutputReport_RegKassa(void)
{

IDMQueryRead  * q;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&q);
q->Init(InterfaceMainObject,0);
q->pFIBQ->SQL->Clear();
q->pFIBQ->SQL->Add(" select RGKASSA_DV.*, NAMEFIRM, NAMEKKM from RGKASSA_DV");
q->pFIBQ->SQL->Add(" left outer join SFIRM on IDFIRM_RGKASSA_DV=IDFIRM");
q->pFIBQ->SQL->Add(" left outer join SKKM on IDKKM_RGKASSA_DV=IDKKM");
q->pFIBQ->SQL->Add(" where IDDOC_RGKASSA_DV="+IntToStr(IdDoc));
q->pFIBQ->ExecQuery();
if (q->pFIBQ->RecordCount==0)
	{
	q->kanRelease();
	return;
	}
SE->TecCell_GetObject(2, y);
SE->TecCell_SetText("Касса ");
SE->TecCell_SetHorzTextAlign(ISheetEditor::haLEFT);
SE->TecCell_SetFontSize(16);
SE->TecCell_SetFontStyle(TFontStyles() << fsBold);
SE->SetRowsHeight(y,25);
SE->TecCell_DeleteObject();
y++;y++;

//шапка
	x=1;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Тип дв.");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Поз. док.");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	TRect rect;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("Фирма");
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("Касса");
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Сумма");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Опер");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->SetRowsHeight(y,20);
	y++;
//конец шапки

while(!q->pFIBQ->Eof)
	{
	x=1;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetFontSize(16);
	if (q->pFIBQ->FieldByName("TDV_RGKASSA_DV")->AsInteger==0)
		{
		SE->TecCell_SetText("+");
		SE->TecCell_SetFontColor(4);
		}
	else
		{
		SE->TecCell_SetText("-");
		SE->TecCell_SetFontColor(2);
		}
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("POSDOC_RGKASSA_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("ID="+q->pFIBQ->FieldByName("IDFIRM_RGKASSA_DV")->AsString
				+" "+q->pFIBQ->FieldByName("NAMEFIRM")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText( "ID="+q->pFIBQ->FieldByName("IDKKM_RGKASSA_DV")->AsString
				+" "+q->pFIBQ->FieldByName("NAMEKKM")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("SUM_RGKASSA_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("OPER_RGKASSA_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	q->pFIBQ->Next();
	SE->SetRowsHeight(y,25);
	y++;
	}
	y++;
q->kanRelease();

}
//-----------------------------------------------------------------------------
void TReportDvRegDoc::OutputReport_RegOstNom(void)
{
IDMQueryRead  * q;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&q);
q->Init(InterfaceMainObject,0);
q->pFIBQ->SQL->Clear();
q->pFIBQ->SQL->Add(" select RGOSTNOM_DV.*, NAMEFIRM, NAMESKLAD, NAMENOM, CODEPART, DOCPART from RGOSTNOM_DV");
q->pFIBQ->SQL->Add(" left outer join SFIRM on IDFIRM_OSTNOMDV=IDFIRM");
q->pFIBQ->SQL->Add(" left outer join SSKLAD on IDSKL_OSTNOMDV=IDSKLAD");
q->pFIBQ->SQL->Add(" left outer join SNOM on IDNOM_OSTNOMDV=IDNOM");
q->pFIBQ->SQL->Add(" left outer join SPART on IDPART_OSTNOMDV=IDPART");
q->pFIBQ->SQL->Add(" where IDDOC_OSTNOMDV="+IntToStr(IdDoc));
q->pFIBQ->ExecQuery();
if (q->pFIBQ->RecordCount==0)
	{
	q->kanRelease();
	return;
	}
SE->TecCell_GetObject(2, y);
SE->TecCell_SetText("Остатки партий товаров ");
SE->TecCell_SetHorzTextAlign(ISheetEditor::haLEFT);
SE->TecCell_SetFontSize(16);
SE->TecCell_SetFontStyle(TFontStyles() << fsBold);
SE->SetRowsHeight(y,25);
SE->TecCell_DeleteObject();
y++;y++;

//шапка
	x=1;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Тип дв.");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Поз. док.");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	TRect rect;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("Фирма");
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("Склад");
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("Товар");
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("Партия");
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("Сумма");
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Кол.");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("ID строки док.");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Опер");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Сумма 2");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->SetRowsHeight(y,25);
	y++;
//конец шапки

while(!q->pFIBQ->Eof)
	{
	x=1;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetFontSize(16);
	if (q->pFIBQ->FieldByName("TDV_OSTNOMDV")->AsInteger==0)
		{
		SE->TecCell_SetText("+");
		SE->TecCell_SetFontColor(4);
		}
	else
		{
		SE->TecCell_SetText("-");
		SE->TecCell_SetFontColor(2);
		}
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("POSDOC_OSTNOMDV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("ID="+q->pFIBQ->FieldByName("IDFIRM_OSTNOMDV")->AsString
				+" "+q->pFIBQ->FieldByName("NAMEFIRM")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("ID="+q->pFIBQ->FieldByName("IDSKL_OSTNOMDV")->AsString
				+" "+q->pFIBQ->FieldByName("NAMESKLAD")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText( "ID="+q->pFIBQ->FieldByName("IDNOM_OSTNOMDV")->AsString
				+" "+q->pFIBQ->FieldByName("NAMENOM")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText( "ID="+q->pFIBQ->FieldByName("IDPART_OSTNOMDV")->AsString
				+" "+q->pFIBQ->FieldByName("CODEPART")->AsString
				+" "+q->pFIBQ->FieldByName("DOCPART")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("SUM_OSTNOMDV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("KOL_OSTNOMDV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("IDSTRDOC_OSTNOMDV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("OPER_OSTNOMDV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("SUM2_OSTNOMDV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	q->pFIBQ->Next();
	SE->SetRowsHeight(y,20);
	y++;
	}

q->kanRelease();
	y++;
}
//-----------------------------------------------------------------------------
void TReportDvRegDoc::OutputReport_RegOtrSpis(void)
{

//IDMQueryRead  * q;
//InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
//													(void**)&q);
//q->Init(InterfaceMainObject,0);
//q->pFIBQ->SQL->Clear();
//q->pFIBQ->SQL->Add(" select RGOTRSPIS_DV.*, NAMEFIRM, NAMESKLAD, NAMENOM from RGOTRSPIS_DV");
//q->pFIBQ->SQL->Add(" left outer join SFIRM on IDFIRM_RGOTRSPIS_DV=IDFIRM");
//q->pFIBQ->SQL->Add(" left outer join SSKLAD on IDSKL_RGOTRSPIS_DV=IDSKLAD");
//q->pFIBQ->SQL->Add(" left outer join SNOM on IDNOM_RGOTRSPIS_DV=IDNOM");
//q->pFIBQ->SQL->Add(" where IDDOC_RGOTRSPIS_DV="+IntToStr(IdDoc));
//q->pFIBQ->ExecQuery();
//if (q->pFIBQ->RecordCount==0)
//	{
//	q->kanRelease();
//	return;
//	}
//cell = SE->SS->ActiveSheet->GetCellObject(2, y);
//cell->Text = "Отрицательное списание ";
//cell->Style->HorzTextAlign = haLEFT;
//cell->Style->Font->Size = 16;
//cell->Style->Font->Style = TFontStyles() << fsBold;
//SE->SS->ActiveSheet->Rows->Size[y]=25;
//delete cell;
//y++;y++;
//
////шапка
//	x=1;
//	cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//	cell->Style->HorzTextAlign = haCENTER;
//	cell->Text = "Тип дв.";
//	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//	cell->Style->Borders->Edges [eRight]->Style=lsThin;
//	cell->Style->Borders->Edges [eTop]->Style=lsThin;
//	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//	delete cell;
//	x++;
//	cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//	cell->Text = "Поз. док.";
//	cell->Style->HorzTextAlign = haCENTER;
//	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//	cell->Style->Borders->Edges [eRight]->Style=lsThin;
//	cell->Style->Borders->Edges [eTop]->Style=lsThin;
//	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//	delete cell;
//	x++;
//	TRect rect;
//	rect.Left = x;
//	rect.Top = y;
//	rect.Right = x+1;
//	rect.Bottom = y;
//	SE->SS->ActiveSheet->SetMergedState(rect, true);
//	cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//	cell->Text = "Фирма";
//	cell->Style->HorzTextAlign = haCENTER;
//	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//	cell->Style->Borders->Edges [eTop]->Style=lsThin;
//	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//	delete cell;
//	x++;
//	cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//	cell->Style->Borders->Edges [eRight]->Style=lsThin;
//	cell->Style->Borders->Edges [eTop]->Style=lsThin;
//	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//	delete cell;
//	x++;
//	rect.Left = x;
//	rect.Top = y;
//	rect.Right = x+1;
//	rect.Bottom = y;
//	SE->SS->ActiveSheet->SetMergedState(rect, true);
//	cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//	cell->Text = "Склад";
//	cell->Style->HorzTextAlign = haCENTER;
//	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//	cell->Style->Borders->Edges [eTop]->Style=lsThin;
//	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//	delete cell;
//	x++;
//	cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//	cell->Style->Borders->Edges [eRight]->Style=lsThin;
//	cell->Style->Borders->Edges [eTop]->Style=lsThin;
//	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//	delete cell;
//	x++;
//	rect.Left = x;
//	rect.Top = y;
//	rect.Right = x+1;
//	rect.Bottom = y;
//	SE->SS->ActiveSheet->SetMergedState(rect, true);
//	cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//	cell->Text = "Товар";
//	cell->Style->HorzTextAlign = haCENTER;
//	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//	cell->Style->Borders->Edges [eTop]->Style=lsThin;
//	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//	delete cell;
//	x++;
//	cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//	cell->Style->Borders->Edges [eRight]->Style=lsThin;
//	cell->Style->Borders->Edges [eTop]->Style=lsThin;
//	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//	delete cell;
//	x++;
//	cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//	cell->Style->HorzTextAlign = haCENTER;
//	cell->Text ="ID строки док.";
//	cell->Style->Borders->Edges [eRight]->Style=lsThin;
//	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//	cell->Style->Borders->Edges [eTop]->Style=lsThin;
//	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//	delete cell;
//	x++;
//	cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//	cell->Style->HorzTextAlign = haCENTER;
//	cell->Text = "Кол.";
//	cell->Style->Borders->Edges [eRight]->Style=lsThin;
//	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//	cell->Style->Borders->Edges [eTop]->Style=lsThin;
//	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//	delete cell;
//	x++;
//	SE->SS->ActiveSheet->Rows->Size[y]=20;
//	y++;
////конец шапки
//
//while(!q->pFIBQ->Eof)
//	{
//	x=1;
//	cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//	cell->Style->HorzTextAlign = haCENTER;
//	cell->Style->Font->Size = 16;
//	if (q->pFIBQ->FieldByName("TDV_RGOTRSPIS_DV")->AsInteger==0)
//		{
//		cell->Text = "+";
//		cell->Style->Font->FontColor=4;
//		}
//	else
//		{
//		cell->Text = "-";
//		cell->Style->Font->FontColor=2;
//		}
//	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//	cell->Style->Borders->Edges [eRight]->Style=lsThin;
//	cell->Style->Borders->Edges [eTop]->Style=lsThin;
//	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//	delete cell;
//	x++;
//	cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//	cell->Text = q->pFIBQ->FieldByName("POSDOC_RGOTRSPIS_DV")->AsString;
//	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//	cell->Style->Borders->Edges [eRight]->Style=lsThin;
//	cell->Style->Borders->Edges [eTop]->Style=lsThin;
//	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//	delete cell;
//	x++;
//	rect.Left = x;
//	rect.Top = y;
//	rect.Right = x+1;
//	rect.Bottom = y;
//	SE->SS->ActiveSheet->SetMergedState(rect, true);
//	cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//	cell->Text = "ID="+q->pFIBQ->FieldByName("IDFIRM_RGOTRSPIS_DV")->AsString
//				+" "+q->pFIBQ->FieldByName("NAMEFIRM")->AsString;
//	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//	cell->Style->Borders->Edges [eTop]->Style=lsThin;
//	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//	delete cell;
//	x++;
//	cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//	cell->Style->Borders->Edges [eRight]->Style=lsThin;
//	cell->Style->Borders->Edges [eTop]->Style=lsThin;
//	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//	delete cell;
//	x++;
//	rect.Left = x;
//	rect.Top = y;
//	rect.Right = x+1;
//	rect.Bottom = y;
//	SE->SS->ActiveSheet->SetMergedState(rect, true);
//	cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//	cell->Text = "ID="+q->pFIBQ->FieldByName("IDSKL_RGOTRSPIS_DV")->AsString
//				+" "+q->pFIBQ->FieldByName("NAMESKLAD")->AsString;
//	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//	cell->Style->Borders->Edges [eTop]->Style=lsThin;
//	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//	delete cell;
//	x++;
//	cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//	cell->Style->Borders->Edges [eRight]->Style=lsThin;
//	cell->Style->Borders->Edges [eTop]->Style=lsThin;
//	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//	delete cell;
//	x++;
//	rect.Left = x;
//	rect.Top = y;
//	rect.Right = x+1;
//	rect.Bottom = y;
//	SE->SS->ActiveSheet->SetMergedState(rect, true);
//	cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//	cell->Text = "ID="+q->pFIBQ->FieldByName("IDNOM_RGOTRSPIS_DV")->AsString
//				+" "+q->pFIBQ->FieldByName("NAMENOM")->AsString;
//	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//	cell->Style->Borders->Edges [eTop]->Style=lsThin;
//	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//	delete cell;
//	x++;
//	cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//	cell->Style->Borders->Edges [eRight]->Style=lsThin;
//	cell->Style->Borders->Edges [eTop]->Style=lsThin;
//	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//	delete cell;
//	x++;
//	cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//	cell->Style->HorzTextAlign = haRIGHT;
//	cell->Text = q->pFIBQ->FieldByName("IDSTRDOC_RGOTRSPIS_DV")->AsString;
//	cell->Style->Borders->Edges [eRight]->Style=lsThin;
//	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//	cell->Style->Borders->Edges [eTop]->Style=lsThin;
//	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//	delete cell;
//	x++;
//	cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//	cell->Style->HorzTextAlign = haRIGHT;
//	cell->Text = q->pFIBQ->FieldByName("KOL_RGOTRSPIS_DV")->AsString;
//	cell->Style->Borders->Edges [eRight]->Style=lsThin;
//	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//	cell->Style->Borders->Edges [eTop]->Style=lsThin;
//	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//	delete cell;
//	x++;
//	q->pFIBQ->Next();
//	SE->SS->ActiveSheet->Rows->Size[y]=20;
//	y++;
//	}
//	y++;
//q->kanRelease();
//


}
//------------------------------------------------------------------------------
void TReportDvRegDoc::OutputReport_RegPaySale(void)
{
IDMQueryRead  * q;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&q);
q->Init(InterfaceMainObject,0);
q->pFIBQ->SQL->Clear();
q->pFIBQ->SQL->Add(" select RGPAYSALE_DV.*, NAMEFIRM, NAMEKLIENT, NAME_SDOG, NUMDOC, POSDOC, TDOC from RGPAYSALE_DV");
q->pFIBQ->SQL->Add(" left outer join SFIRM on IDFIRM_RGPAYSALE_DV=IDFIRM");
q->pFIBQ->SQL->Add(" left outer join SKLIENT on IDKLIENT_RGPAYSALE_DV=IDKLIENT");
q->pFIBQ->SQL->Add(" left outer join SDOG on IDDOG_RGPAYSALE_DV=ID_SDOG");
q->pFIBQ->SQL->Add(" left outer join GALLDOC on IDDOCSALE_RGPAYSALE_DV=IDDOC");
q->pFIBQ->SQL->Add(" where IDDOC_RGPAYSALE_DV="+IntToStr(IdDoc));
q->pFIBQ->ExecQuery();
if (q->pFIBQ->RecordCount==0)
	{
	q->kanRelease();
	return;
	}
SE->TecCell_GetObject(2, y);
SE->TecCell_SetText("Оплата реализации ");
SE->TecCell_SetHorzTextAlign(ISheetEditor::haLEFT);
SE->TecCell_SetFontSize(16);
SE->TecCell_SetFontStyle(TFontStyles() << fsBold);
SE->SetRowsHeight(y,25);
SE->TecCell_DeleteObject();
y++;y++;

//шапка
	x=1;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Тип дв.");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Поз. док.");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	TRect rect;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Фирма");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Контрагент");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Договор");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("Док. продажи");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Дата");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Сумма");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	SE->SetRowsHeight(y,25);
	y++;
//конец шапки

while(!q->pFIBQ->Eof)
	{
	x=1;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haLEFT);
	SE->TecCell_SetFontSize(16);
	SE->TecCell_SetFontStyle(TFontStyles() << fsBold);
	if (q->pFIBQ->FieldByName("TDV_RGPAYSALE_DV")->AsInteger==0)
		{
		SE->TecCell_SetText("+");
		SE->TecCell_SetFontColor(4);
		}
	else
		{
		SE->TecCell_SetText("-");
		SE->TecCell_SetFontColor(2);
		}
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("POS_RGPAYSALE_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("ID="+q->pFIBQ->FieldByName("IDFIRM_RGPAYSALE_DV")->AsString
				+" "+q->pFIBQ->FieldByName("NAMEFIRM")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("ID="+q->pFIBQ->FieldByName("IDKLIENT_RGPAYSALE_DV")->AsString
				+" "+q->pFIBQ->FieldByName("NAMEKLIENT")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("ID="+q->pFIBQ->FieldByName("IDDOG_RGPAYSALE_DV")->AsString
				+" "+q->pFIBQ->FieldByName("NAME_SDOG")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("ID="+q->pFIBQ->FieldByName("IDDOCSALE_RGPAYSALE_DV")->AsString
				+" "+glGetNameDoc(q->pFIBQ->FieldByName("TDOC")->AsString)
				+" №"+q->pFIBQ->FieldByName("NUMDOC")->AsString
				+" от "+q->pFIBQ->FieldByName("POSDOC")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("DATE_RGPAYSALE_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("SUM_RGPAYSALE_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	q->pFIBQ->Next();
	SE->SetRowsHeight(y,20);
	y++;
	}

q->kanRelease();
	y++;
}
//-----------------------------------------------------------------------------
void TReportDvRegDoc::OutputReport_RegSebProd(void)
{

IDMQueryRead  * q;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&q);
q->Init(InterfaceMainObject,0);
q->pFIBQ->SQL->Clear();
q->pFIBQ->SQL->Add(" select RGSEBPROD_DV.*, NAMEFIRM, NAMESKLAD, NAMENOM from RGSEBPROD_DV");
q->pFIBQ->SQL->Add(" left outer join SFIRM on IDFIRM_RGSEBPROD_DV=IDFIRM");
q->pFIBQ->SQL->Add(" left outer join SSKLAD on IDSKLAD_RGSEBPROD_DV=IDSKLAD");
q->pFIBQ->SQL->Add(" left outer join SNOM on IDNOM_RGSEBPROD_DV=IDNOM");
q->pFIBQ->SQL->Add(" where IDDOC_RGSEBPROD_DV="+IntToStr(IdDoc));
q->pFIBQ->ExecQuery();
if (q->pFIBQ->RecordCount==0)
	{
	q->kanRelease();
	return;
	}
SE->TecCell_GetObject(2, y);
SE->TecCell_SetText("Себестоимость продукции ");
SE->TecCell_SetHorzTextAlign(ISheetEditor::haLEFT);
SE->TecCell_SetFontSize(16);
SE->TecCell_SetFontStyle(TFontStyles() << fsBold);
SE->SetRowsHeight(y,25);
SE->TecCell_DeleteObject();
y++;y++;

//шапка
	x=1;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Тип дв.");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Поз. док.");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	TRect rect;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("Продукция");
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("Фирма");
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("Склад");
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("Ингредиент");
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Кол.");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Сумма");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Кол -");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->SetRowsHeight(y,25);
	y++;
//конец шапки

while(!q->pFIBQ->Eof)
	{
	x=1;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetFontSize(16);
	if (q->pFIBQ->FieldByName("TDV_RGSEBPROD_DV")->AsInteger==0)
		{
		SE->TecCell_SetText("+");
		SE->TecCell_SetFontColor(4);
		}
	else
		{
		SE->TecCell_SetText("-");
		SE->TecCell_SetFontColor(2);
		}
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("POSDOC_RGSEBPROD_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	IDMQueryRead  * q1;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&q1);
	q1->Init(InterfaceMainObject,0);
	q1->pFIBQ->SQL->Clear();
	q1->pFIBQ->SQL->Add(" select IDNOM, NAMENOM from RGVIPPROD_DV");
	q1->pFIBQ->SQL->Add(" left outer join SNOM on IDNOM_RGVIPPROD_DV=IDNOM");
	q1->pFIBQ->SQL->Add(" where ID_RGVIPPROD_DV="+q->pFIBQ->FieldByName("IDVIPPROD_RGSEBPROD_DV")->AsString);
	q1->pFIBQ->ExecQuery();
	SE->TecCell_SetText("ID="+q1->pFIBQ->FieldByName("IDNOM")->AsString
				+" "+q1->pFIBQ->FieldByName("NAMENOM")->AsString);
	q1->kanRelease();
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("ID="+q->pFIBQ->FieldByName("IDFIRM_RGSEBPROD_DV")->AsString
				+" "+q->pFIBQ->FieldByName("NAMEFIRM")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("ID="+q->pFIBQ->FieldByName("IDSKLAD_RGSEBPROD_DV")->AsString
				+" "+q->pFIBQ->FieldByName("NAMESKLAD")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("ID="+q->pFIBQ->FieldByName("IDNOM_RGSEBPROD_DV")->AsString
				+" "+q->pFIBQ->FieldByName("NAMENOM")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("KOL_RGSEBPROD_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("SUM_RGSEBPROD_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("KOLOTR_RGSEBPROD_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;

	q->pFIBQ->Next();
	SE->SetRowsHeight(y,20);
	y++;
	}

q->kanRelease();
	y++;
}
//-----------------------------------------------------------------------------
void TReportDvRegDoc::OutputReport_RegVipProd(void)
{
IDMQueryRead  * q;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&q);
q->Init(InterfaceMainObject,0);
q->pFIBQ->SQL->Clear();
q->pFIBQ->SQL->Add(" select RGVIPPROD_DV.*, NAMEFIRM, NAMESKLAD, NAMENOM from RGVIPPROD_DV");
q->pFIBQ->SQL->Add(" left outer join SFIRM on IDFIRM_RGVIPPROD_DV=IDFIRM");
q->pFIBQ->SQL->Add(" left outer join SSKLAD on IDSKLAD_RGVIPPROD_DV=IDSKLAD");
q->pFIBQ->SQL->Add(" left outer join SNOM on IDNOM_RGVIPPROD_DV=IDNOM");
q->pFIBQ->SQL->Add(" where IDDOC_RGVIPPROD_DV="+IntToStr(IdDoc));
q->pFIBQ->ExecQuery();
if (q->pFIBQ->RecordCount==0)
	{
	q->kanRelease();
	return;
	}
SE->TecCell_GetObject(2, y);
SE->TecCell_SetText("Выпуск продукции ");
SE->TecCell_SetHorzTextAlign(ISheetEditor::haLEFT);
SE->TecCell_SetFontSize(16);
SE->TecCell_SetFontStyle(TFontStyles() << fsBold);
SE->SetRowsHeight(y,25);
SE->TecCell_DeleteObject();
y++;y++;

//шапка
	x=1;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Тип дв.");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Поз. док.");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	TRect rect;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("Фирма");
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("Склад");
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("Продукция");
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("Кол.");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Себестоимость");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	SE->SetRowsHeight(y,20);
	y++;
//конец шапки

while(!q->pFIBQ->Eof)
	{
	x=1;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetFontSize(16);
	if (q->pFIBQ->FieldByName("TDV_RGVIPPROD_DV")->AsInteger==0)
		{
		SE->TecCell_SetText("+");
		SE->TecCell_SetFontColor(4);
		}
	else
		{
		SE->TecCell_SetText("-");
		SE->TecCell_SetFontColor(2);
		}
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("POSDOC_RGVIPPROD_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("ID="+q->pFIBQ->FieldByName("IDFIRM_RGVIPPROD_DV")->AsString
				+" "+q->pFIBQ->FieldByName("NAMEFIRM")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("ID="+q->pFIBQ->FieldByName("IDSKLAD_RGVIPPROD_DV")->AsString
				+" "+q->pFIBQ->FieldByName("NAMESKLAD")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("ID="+q->pFIBQ->FieldByName("IDNOM_RGVIPPROD_DV")->AsString
				+" "+q->pFIBQ->FieldByName("NAMENOM")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("KOL_RGVIPPROD_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("SEB_RGVIPPROD_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	q->pFIBQ->Next();
	SE->SetRowsHeight(y,20);
	y++;
	}

q->kanRelease();
	y++;
}
//----------------------------------------------------------------------------
void TReportDvRegDoc::OutputReport_RegVSRasch(void)
{

IDMQueryRead  * q;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&q);
q->Init(InterfaceMainObject,0);
q->pFIBQ->SQL->Clear();
q->pFIBQ->SQL->Add(" select RGVSRASCH_DV.*, NAMEFIRM, NAMEKLIENT, NAME_SDOG from RGVSRASCH_DV");
q->pFIBQ->SQL->Add(" left outer join SFIRM on IDFIRM_VSRASCH_DV=IDFIRM");
q->pFIBQ->SQL->Add(" left outer join SKLIENT on IDKLIENT_VSRASCH_DV=IDKLIENT");
q->pFIBQ->SQL->Add(" left outer join SDOG on IDDOG_VSRASCH_DV=ID_SDOG");
q->pFIBQ->SQL->Add(" where IDDOC_VSRASCH_DV="+IntToStr(IdDoc));
q->pFIBQ->ExecQuery();
if (q->pFIBQ->RecordCount==0)
	{
	q->kanRelease();
	return;
	}
SE->TecCell_GetObject(2, y);
SE->TecCell_SetText("Взаиморасчеты ");
SE->TecCell_SetHorzTextAlign(ISheetEditor::haLEFT);
SE->TecCell_SetFontSize(16);
SE->TecCell_SetFontStyle(TFontStyles() << fsBold);
SE->SetRowsHeight(y,25);
SE->TecCell_DeleteObject();
y++;y++;

//шапка
	x=1;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Тип дв.");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Поз. док.");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	TRect rect;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Фирма");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Контрагент");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("Договор");
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("Сумма");
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	SE->SetRowsHeight(y,20);
	y++;
//конец шапки

while(!q->pFIBQ->Eof)
	{
	x=1;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetFontSize(16);
	if (q->pFIBQ->FieldByName("TDV_VSRASCH_DV")->AsInteger==0)
		{
		SE->TecCell_SetText("+");
		SE->TecCell_SetFontColor(4);
		}
	else
		{
		SE->TecCell_SetText("-");
		SE->TecCell_SetFontColor(2);
		}
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("POSDOC_VSRASCH_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("ID="+q->pFIBQ->FieldByName("IDFIRM_VSRASCH_DV")->AsString
				+" "+q->pFIBQ->FieldByName("NAMEFIRM")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("ID="+q->pFIBQ->FieldByName("IDKLIENT_VSRASCH_DV")->AsString
				+" "+q->pFIBQ->FieldByName("NAMEKLIENT")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("ID="+q->pFIBQ->FieldByName("IDDOG_VSRASCH_DV")->AsString
				+" "+q->pFIBQ->FieldByName("NAME_SDOG")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("SUM_VSRASCH_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	q->pFIBQ->Next();
	SE->SetRowsHeight(y,20);
	y++;
	}

q->kanRelease();
	y++;

}
//----------------------------------------------------------------------------
void TReportDvRegDoc::OutputReport_RegReal(void)
{

IDMQueryRead  * q;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&q);
q->Init(InterfaceMainObject,0);
q->pFIBQ->SQL->Clear();
q->pFIBQ->SQL->Add(" select RGREAL_DV.*, NAMEFIRM, NAMESKLAD, NAMENOM, CODEPART, DOCPART from RGREAL_DV");
q->pFIBQ->SQL->Add(" left outer join SFIRM on IDFIRM_RGREAL_DV=IDFIRM");
q->pFIBQ->SQL->Add(" left outer join SSKLAD on IDSKLAD_RGREAL_DV=IDSKLAD");
q->pFIBQ->SQL->Add(" left outer join SNOM on IDNOM_RGREAL_DV=IDNOM");
q->pFIBQ->SQL->Add(" left outer join SPART on IDPART_RGREAL_DV=IDPART");
q->pFIBQ->SQL->Add(" where IDDOC_RGREAL_DV="+IntToStr(IdDoc));
q->pFIBQ->ExecQuery();
if (q->pFIBQ->RecordCount==0)
	{
	q->kanRelease();
	return;
	}

SE->TecCell_GetObject(2, y);
SE->TecCell_SetText("Реализация ");
SE->TecCell_SetHorzTextAlign(ISheetEditor::haLEFT);
SE->TecCell_SetFontSize(16);
SE->TecCell_SetFontStyle(TFontStyles() << fsBold);
SE->TecCell_DeleteObject();
SE->SetRowsHeight(y,25);
y++;y++;

//шапка
	x=1;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Тип дв.");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText( "Поз. док.");
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	TRect rect;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText( "Фирма");
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText( "Склад");
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText( "Номенклатура");
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText( "Партия");
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText( "Опер");
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Кол.");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Сумма");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Себест");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Результат");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Кол -");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText("Id пок");
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->SetRowsHeight(y,25);
	y++;
//конец шапки

while(!q->pFIBQ->Eof)
	{
	x=1;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetFontSize(16);
	if (q->pFIBQ->FieldByName("TDV_RGREAL_DV")->AsInteger==0)
		{
		SE->TecCell_SetText("+");
		SE->TecCell_SetFontColor(4);
		}
	else
		{
		SE->TecCell_SetText("-");
		SE->TecCell_SetFontColor(2);
		}
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("POSDOC_RGREAL_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText( "ID="+q->pFIBQ->FieldByName("IDFIRM_RGREAL_DV")->AsString
				+" "+q->pFIBQ->FieldByName("NAMEFIRM")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("ID="+q->pFIBQ->FieldByName("IDSKLAD_RGREAL_DV")->AsString
				+" "+q->pFIBQ->FieldByName("NAMESKLAD")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("ID="+q->pFIBQ->FieldByName("IDNOM_RGREAL_DV")->AsString
				+" "+q->pFIBQ->FieldByName("NAMENOM")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+1;
	rect.Bottom = y;
	SE->SetMergeState(rect, true);
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetText("ID="+q->pFIBQ->FieldByName("IDPART_RGREAL_DV")->AsString
				+" "+q->pFIBQ->FieldByName("CODEPART")->AsString
				+" "+q->pFIBQ->FieldByName("DOCPART")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("OPER_RGREAL_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("KOL_RGREAL_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("SUMREAL_RGREAL_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("SEBREAL_RGREAL_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("RESREAL_RGREAL_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("KOLOTR_RGREAL_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	SE->TecCell_GetObject(x, y);
	SE->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
	SE->TecCell_SetText(q->pFIBQ->FieldByName("IDPOK_RGREAL_DV")->AsString);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
	SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
	SE->TecCell_DeleteObject();
	x++;
	q->pFIBQ->Next();
	SE->SetRowsHeight(y,25);
	y++;
	}

q->kanRelease();
	y++;


}
//-----------------------------------------------------------------------------
