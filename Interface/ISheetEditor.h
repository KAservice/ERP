//---------------------------------------------------------------------------

#ifndef UISheetEditorH
#define UISheetEditorH
//---------------------------------------------------------------------------
#include "GlobalInterface.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------------------
class __declspec(uuid(Global_IID_ISheetEditor))ISheetEditor: public IkanUnknown
{
public:



enum TkanHorzTextAlign { haGENERAL, haLEFT, haCENTER, haRIGHT, haFILL, haJUSTIFY };
enum TkanVertTextAlign { vaTOP, vaCENTER, vaBOTTOM, vaJUSTIFY };
enum TkanSSEdgeBorder { eLeft, eTop, eRight, eBottom };
enum TkanSSEdgeLineStyle { lsDefault, lsThin, lsMedium, lsDashed, lsDotted,
				lsThick, lsDouble, lsHair, lsMediumDashed, lsDashDot, lsMediumDashDot,
				lsDashDotDot, lsMediumDashDotDot, lsSlantedDashDot, lsNone };


virtual void BeginUpdate()=0;
virtual void EndUpdate()=0;

virtual void TecCell_GetObject(int x, int y)=0;
virtual void TecCell_DeleteObject(void)=0;
virtual void TecCell_SetText(UnicodeString value)=0;
virtual UnicodeString TecCell_GetText(void)=0;
virtual void TecCell_SetFontStyle(TFontStyles style)=0;
virtual void TecCell_SetHorzTextAlign(TkanHorzTextAlign value)=0;
virtual void TecCell_SetVertTextAlign(TkanVertTextAlign value)=0;
virtual void TecCell_SetBordersEdgesStyle(TkanSSEdgeBorder borders, TkanSSEdgeLineStyle style_line)=0;
virtual void TecCell_SetFontSize(int size)=0;
virtual void TecCell_SetWordBreake(bool value)=0;
virtual void TecCell_SetBackgroundColor(int value)=0;
virtual void TecCell_SetFontColor(int value)=0;

virtual void SetMergeState(TRect rect, bool IsMerge)=0;
virtual void SetRowsHeightAuto(int y, int x1, int x2, int x_max, UnicodeString s)=0;

virtual void SetColumnWidth(int column, int width)=0;
virtual int  GetColumnWidth(int column)=0;
virtual void SetRowsHeight(int row, int height)=0;
virtual int  GetRowsHeight(int row)=0;

virtual void ClearHistory(void)=0;


//ÑÂÎÉÑÒÂÀ

	virtual int  get_DefaultFontSize(void)=0;
	virtual void set_DefaultFontSize(int  value)=0;

	virtual UnicodeString  get_DefaultFontName(void)=0;
	virtual void set_DefaultFontName(UnicodeString  value)=0;

	virtual bool  get_RowsAutoHeight(void)=0;
	virtual void set_RowsAutoHeight(bool  value)=0;

	virtual int  get_DefaultColWidth(void)=0;
	virtual void set_DefaultColWidth(int  value)=0;

	virtual int  get_DefaultRowHeight(void)=0;
	virtual void set_DefaultRowHeight(int  value)=0;

	virtual bool  get_ShowGrid(void)=0;
	virtual void set_ShowGrid(bool  value)=0;


	__property int  DefaultFontSize = {read = get_DefaultFontSize,
												 write = set_DefaultFontSize};
	__property UnicodeString  DefaultFontName = {read = get_DefaultFontName,
												 write = set_DefaultFontName};
	__property bool  RowsAutoHeight = {read = get_RowsAutoHeight,
												 write = set_RowsAutoHeight};
	__property int  DefaultColWidth = {read = get_DefaultColWidth,
												 write = set_DefaultColWidth};
	__property int  DefaultRowHeight = {read = get_DefaultRowHeight,
												 write = set_DefaultRowHeight};
	__property bool  ShowGrid = {read = get_ShowGrid,
												 write = set_ShowGrid};

};



#define IID_ISheetEditor __uuidof(ISheetEditor)

#endif
