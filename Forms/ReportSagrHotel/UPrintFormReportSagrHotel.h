//---------------------------------------------------------------------------

#ifndef UPrintFormReportSagrHotelH
#define UPrintFormReportSagrHotelH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <AxCtrls.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <OleCtrls.hpp>
#include <ToolWin.hpp>
#include <VCF1.hpp>
//---------------------------------------------------------------------------
class TPrintFormReportSagrHotel : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButton2;
        TF1Book *F1;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButton2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TPrintFormReportSagrHotel(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPrintFormReportSagrHotel *PrintFormReportSagrHotel;
//---------------------------------------------------------------------------
#endif
