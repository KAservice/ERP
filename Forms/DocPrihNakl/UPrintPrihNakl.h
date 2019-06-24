//---------------------------------------------------------------------------

#ifndef UPrintPrihNaklH
#define UPrintPrihNaklH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <AxCtrls.hpp>
#include <ComCtrls.hpp>
#include <OleCtrls.hpp>
#include <ToolWin.hpp>
#include <VCF1.hpp>
//---------------------------------------------------------------------------
class TPrintFormDocPrihNakl : public TForm
{
__published:	// IDE-managed Components
        TToolBar *ToolBar1;
        TF1Book *P;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TPrintFormDocPrihNakl(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPrintFormDocPrihNakl *PrintFormDocPrihNakl;
//---------------------------------------------------------------------------
#endif
