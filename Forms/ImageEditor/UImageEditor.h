//---------------------------------------------------------------------------

#ifndef UImageEditorH
#define UImageEditorH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include "dxBkgnd.hpp"
#include "dxPrnDev.hpp"
#include "dxPrnPg.hpp"
#include "dxPSCompsProvider.hpp"
#include "dxPSCore.hpp"
#include "dxPSEdgePatterns.hpp"
#include "dxPSEngn.hpp"
#include "dxPSFillPatterns.hpp"
#include "dxPSGlbl.hpp"
#include "dxPSGraphicLnk.hpp"
//#include "dxPSImgLnk.hpp"
#include "dxPSUtl.hpp"
#include "dxWrap.hpp"
#include "dxPSImgLnk.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
//#include "dxPSImgLnk.hpp"
//#include "dxPSImgLnk.hpp"
//#include "dxPSImgLnk.hpp"
//---------------------------------------------------------------------------
class TImageEditor : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TToolBar *tbsStandart;
        TToolButton *ToolButton1;
        TToolButton *tbsPreeView;
        TToolButton *tbsPrint;
        TPanel *Panel1;
        TToolButton *tbsPageSetup;
        TImageList *ImageList1;
	TdxComponentPrinter *dxComponentPrinter1;
	TdxImageReportLink *dxComponentPrinter1Link1;
	TcxButton *cxButtonClose;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall tbsPreeViewClick(TObject *Sender);
        void __fastcall tbsPrintClick(TObject *Sender);
        void __fastcall tbsPageSetupClick(TObject *Sender);
	void __fastcall cxButtonCloseClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TImageEditor(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TImageEditor *ImageEditor;
//---------------------------------------------------------------------------
#endif
