//---------------------------------------------------------------------------


#pragma hdrstop

#include "USheetEditorImpl.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------------------
TSheetEditorImpl::TSheetEditorImpl()
{

SE=new TSheetEditor(Application);
NumRefs=0;
++NumObject;
}
//----------------------------------------------------------------------------
TSheetEditorImpl::~TSheetEditorImpl()
{

delete SE;
--NumObject;
}
//----------------------------------------------------------------------------
int TSheetEditorImpl::kanQueryInterface(REFIID id_interface, void ** ppv)
{
int result=0;

if (id_interface==IID_IkanUnknown)
	{
	*ppv=static_cast<IkanUnknown*> (this);
	result=-1;
	}
else if (id_interface==IID_ISheetEditor)
	{
	*ppv=static_cast<ISheetEditor*> (this);
	result=-1;
	}
else
	{
	*ppv=NULL;
	result=1;
	return result;
	}

kanAddRef();

return result;
}
//---------------------------------------------------------------------------
int TSheetEditorImpl::kanAddRef(void)
{

return (++NumRefs);
}
//----------------------------------------------------------------------------
int TSheetEditorImpl::kanRelease(void)
{

if (--NumRefs==0)
	{
	delete this;
	}
return NumRefs;
}
//-----------------------------------------------------------------------------

//ISheetEditor
void TSheetEditorImpl::BeginUpdate()
{
SE->SS->BeginUpdate();

}
//----------------------------------------------------------------------------
void TSheetEditorImpl::EndUpdate()
{
SE->SS->EndUpdate();

}
//----------------------------------------------------------------------------

void TSheetEditorImpl::TecCell_GetObject(int x, int y)
{
TecCell=SE->SS->ActiveSheet->GetCellObject(x, y);
}
//-----------------------------------------------------------------------------
void TSheetEditorImpl::TecCell_DeleteObject(void)
{
delete TecCell;
}
//-----------------------------------------------------------------------------
void TSheetEditorImpl::TecCell_SetText(UnicodeString value)
{
TecCell->Text=value;
}
//-----------------------------------------------------------------------------
UnicodeString TSheetEditorImpl::TecCell_GetText(void)
{
return TecCell->Text;
}
//-----------------------------------------------------------------------------
void TSheetEditorImpl::TecCell_SetFontStyle(TFontStyles style)
{
TecCell->Style->Font->Style =  style;
}
//-----------------------------------------------------------------------------
void TSheetEditorImpl::TecCell_SetHorzTextAlign(TkanHorzTextAlign value)
{
switch (value)
        {
		case haGENERAL 	:{TecCell->Style->HorzTextAlign = 	TcxHorzTextAlign::haGENERAL;} break;
		case haLEFT 	:{TecCell->Style->HorzTextAlign = 	TcxHorzTextAlign::haLEFT;} break;
		case haCENTER 	:{TecCell->Style->HorzTextAlign = 	TcxHorzTextAlign::haCENTER;} break;
		case haRIGHT 	:{TecCell->Style->HorzTextAlign = 	TcxHorzTextAlign::haRIGHT;} break;
		case haJUSTIFY 	:{TecCell->Style->HorzTextAlign = 	TcxHorzTextAlign::haJUSTIFY;} break;
		default :		{TecCell->Style->HorzTextAlign 	= 	TcxHorzTextAlign::haGENERAL;} break;
		}
}
//-----------------------------------------------------------------------------
void TSheetEditorImpl::TecCell_SetVertTextAlign(TkanVertTextAlign value)
{
switch (value)
        {
		case vaTOP 	:{TecCell->Style->VertTextAlign = 	TcxVertTextAlign::vaTOP;} break;
		case vaCENTER 	:{TecCell->Style->VertTextAlign = 	TcxVertTextAlign::vaCENTER;} break;
		case vaBOTTOM 	:{TecCell->Style->VertTextAlign = 	TcxVertTextAlign::vaBOTTOM;} break;
		case vaJUSTIFY	:{TecCell->Style->VertTextAlign = 	TcxVertTextAlign::vaJUSTIFY;} break;
		default :		{TecCell->Style->VertTextAlign 	= 	TcxVertTextAlign::vaCENTER;} break;
		}
}
//-----------------------------------------------------------------------------
void TSheetEditorImpl::TecCell_SetBordersEdgesStyle(TkanSSEdgeBorder borders, TkanSSEdgeLineStyle style_line)
{
TcxSSEdgeBorder edge_border;
TcxSSEdgeLineStyle cx_line_style;

switch (borders)
		{
		case eLeft 	:{edge_border = TcxSSEdgeBorder::eLeft;} break;
		case eTop 	:{edge_border = TcxSSEdgeBorder::eTop;} break;
		case eRight 	:{edge_border = TcxSSEdgeBorder::eRight;} break;
		case eBottom 	:{edge_border = TcxSSEdgeBorder::eBottom;} break;
		default :		{edge_border = TcxSSEdgeBorder::eLeft;} break;
		}


switch (style_line)
		{
		case lsDefault 			:{cx_line_style = TcxSSEdgeLineStyle::lsDefault;} break;
		case lsThin 			:{cx_line_style = TcxSSEdgeLineStyle::lsThin;} break;
		case lsMedium 			:{cx_line_style = TcxSSEdgeLineStyle::lsMedium;} break;
		case lsDashed			:{cx_line_style = TcxSSEdgeLineStyle::lsDashed;} break;
		case lsDotted 			:{cx_line_style = TcxSSEdgeLineStyle::lsDotted;} break;
		case lsThick 			:{cx_line_style = TcxSSEdgeLineStyle::lsThick;} break;
		case lsDouble 			:{cx_line_style = TcxSSEdgeLineStyle::lsDouble;} break;
		case lsHair				:{cx_line_style = TcxSSEdgeLineStyle::lsHair;} break;
		case lsMediumDashed 	:{cx_line_style = TcxSSEdgeLineStyle::lsMediumDashed;} break;
		case lsDashDot 			:{cx_line_style = TcxSSEdgeLineStyle::lsDashDot;} break;
		case lsMediumDashDot	:{cx_line_style = TcxSSEdgeLineStyle::lsMediumDashDot;} break;
		case lsDashDotDot 		:{cx_line_style = TcxSSEdgeLineStyle::lsDashDotDot;} break;
		case lsMediumDashDotDot	:{cx_line_style = TcxSSEdgeLineStyle::lsMediumDashDotDot;} break;
		case lsSlantedDashDot 	:{cx_line_style = TcxSSEdgeLineStyle::lsSlantedDashDot;} break;
		case lsNone				:{cx_line_style = TcxSSEdgeLineStyle::lsNone;} break;
		default 				:{cx_line_style = TcxSSEdgeLineStyle::lsDefault;} break;
		}

TecCell->Style->Borders->Edges [edge_border]->Style=cx_line_style;
}
//-----------------------------------------------------------------------------
void TSheetEditorImpl::TecCell_SetFontSize(int size)
{
TecCell->Style->Font->Size = size;
}
//-----------------------------------------------------------------------------
void TSheetEditorImpl::TecCell_SetWordBreake(bool value)
{
TecCell->Style->WordBreak = value;

}
//----------------------------------------------------------------------------
void TSheetEditorImpl::TecCell_SetBackgroundColor(int value)
{
TecCell->Style->Brush->BackgroundColor=value;
}
//---------------------------------------------------------------------------
void TSheetEditorImpl::TecCell_SetFontColor(int value)
{

TecCell->Style->Font->FontColor=value;
}
//-----------------------------------------------------------------------------






//-----------------------------------------------------------------------------
void TSheetEditorImpl::SetMergeState(TRect rect, bool IsMerge)
{
SE->SS->ActiveSheet->SetMergedState(rect, IsMerge);
}
//-----------------------------------------------------------------------------
void TSheetEditorImpl::SetRowsHeightAuto(int y, int x1, int x2, int x_max, UnicodeString s)
{
SE->SetRowsHeightAuto(y,x1,x2,x_max,s);
}
//-----------------------------------------------------------------------------

void TSheetEditorImpl::SetColumnWidth(int column, int width)
{
SE->SS->ActiveSheet->Cols->Size[column] = width;
}
//-----------------------------------------------------------------------------
int  TSheetEditorImpl::GetColumnWidth(int column)
{
return SE->SS->ActiveSheet->Cols->Size[column];
}
//-----------------------------------------------------------------------------
void TSheetEditorImpl::SetRowsHeight(int row, int height)
{
SE->SS->ActiveSheet->Rows->Size[row]=height;
}
//-----------------------------------------------------------------------------
int  TSheetEditorImpl::GetRowsHeight(int row)
{
return SE->SS->ActiveSheet->Rows->Size[row];
}
//-----------------------------------------------------------------------------
void TSheetEditorImpl::ClearHistory(void)
{
SE->SS->History->Clear();
}
//-----------------------------------------------------------------------------





//-----------------------------------------------------------------------------
//ÑÂÎÉÑÒÂÀ

int  TSheetEditorImpl::get_DefaultFontSize(void)
{
return SE->SS->DefaultStyle->Font->Size;
}
//-----------------------------------------------------------------------------
void TSheetEditorImpl::set_DefaultFontSize(int  value)
{
SE->SS->DefaultStyle->Font->Size=value;

}
//-----------------------------------------------------------------------------

UnicodeString  TSheetEditorImpl::get_DefaultFontName(void)
{
return SE->SS->DefaultStyle->Font->Name;
}
//-----------------------------------------------------------------------------
void TSheetEditorImpl::set_DefaultFontName(UnicodeString  value)
{
SE->SS->DefaultStyle->Font->Name=value;

}
//-----------------------------------------------------------------------------

bool  TSheetEditorImpl::get_RowsAutoHeight(void)
{
return SE->SS->RowsAutoHeight;
}
//-----------------------------------------------------------------------------
void TSheetEditorImpl::set_RowsAutoHeight(bool  value)
{
SE->SS->RowsAutoHeight=value;
}
//-----------------------------------------------------------------------------

int  TSheetEditorImpl::get_DefaultColWidth(void)
{
return SE->SS->DefaultColWidth;

}
//-----------------------------------------------------------------------------
void TSheetEditorImpl::set_DefaultColWidth(int  value)
{
SE->SS->DefaultColWidth=value;
}
//-----------------------------------------------------------------------------

int  TSheetEditorImpl::get_DefaultRowHeight(void)
{
return SE->SS->DefaultRowHeight;
}
//-----------------------------------------------------------------------------
void TSheetEditorImpl::set_DefaultRowHeight(int  value)
{
SE->SS->DefaultRowHeight=value;
}
//-----------------------------------------------------------------------------

bool  TSheetEditorImpl::get_ShowGrid(void)
{
return SE->SS->ShowGrid;
}
//-----------------------------------------------------------------------------
void TSheetEditorImpl::set_ShowGrid(bool  value)
{
SE->SS->ShowGrid=value;
}
//-----------------------------------------------------------------------------
