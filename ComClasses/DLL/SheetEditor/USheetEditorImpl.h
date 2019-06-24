//---------------------------------------------------------------------------

#ifndef USheetEditorImplH
#define USheetEditorImplH
#include "USheetEditor.h"
#include "ISheetEditor.h"
//---------------------------------------------------------------------------

class __declspec(uuid(Global_CLSID_TSheetEditorImpl)) TSheetEditorImpl : public ISheetEditor
{
public:
   TSheetEditorImpl();
   ~TSheetEditorImpl();


	TSheetEditor * SE;
	int NumRefs;

	TcxSSCellObject * TecCell;



	//IUnknown
	virtual int kanQueryInterface(REFIID id_interface, void ** ppv);
	virtual int kanAddRef(void);
	virtual int kanRelease(void);


	 //ISheetEditor

virtual void BeginUpdate();
virtual void EndUpdate();

virtual void TecCell_GetObject(int x, int y);
virtual void TecCell_DeleteObject(void);
virtual void TecCell_SetText(UnicodeString value);
virtual UnicodeString TecCell_GetText(void);
virtual void TecCell_SetFontStyle(TFontStyles style);
virtual void TecCell_SetHorzTextAlign(TkanHorzTextAlign value);
virtual void TecCell_SetVertTextAlign(TkanVertTextAlign value);
virtual void TecCell_SetBordersEdgesStyle(TkanSSEdgeBorder borders, TkanSSEdgeLineStyle style_line);
virtual void TecCell_SetFontSize(int size);
virtual void TecCell_SetWordBreake(bool value);
virtual void TecCell_SetBackgroundColor(int value);
virtual void TecCell_SetFontColor(int value);

virtual void SetMergeState(TRect rect, bool IsMerge);
virtual void SetRowsHeightAuto(int y, int x1, int x2, int x_max, UnicodeString s);

virtual void SetColumnWidth(int column, int width);
virtual int  GetColumnWidth(int column);
virtual void SetRowsHeight(int row, int height);
virtual int  GetRowsHeight(int row);


virtual void ClearHistory(void);

//ÑÂÎÉÑÒÂÀ

	virtual int  get_DefaultFontSize(void);
	virtual void set_DefaultFontSize(int  value);

	virtual UnicodeString  get_DefaultFontName(void);
	virtual void set_DefaultFontName(UnicodeString  value);

	virtual bool  get_RowsAutoHeight(void);
	virtual void set_RowsAutoHeight(bool  value);

	virtual int  get_DefaultColWidth(void);
	virtual void set_DefaultColWidth(int  value);

	virtual int  get_DefaultRowHeight(void);
	virtual void set_DefaultRowHeight(int  value);

	virtual bool  get_ShowGrid(void);
	virtual void set_ShowGrid(bool  value);
};

#define CLSID_TSheetEditorImpl __uuidof(TSheetEditorImpl)
#endif
