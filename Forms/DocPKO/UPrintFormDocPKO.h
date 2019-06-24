//---------------------------------------------------------------------------

#ifndef UPrintFormDocPKOH
#define UPrintFormDocPKOH
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
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TPrintFormDocPKO : public TForm
{
__published:	// IDE-managed Components
        TF1Book *F1;
        TPanel *Panel1;
        TButton *Button1;
        TButton *ButtonSave;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall ButtonSaveClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TPrintFormDocPKO(TComponent* Owner);
        String FileName;
};
//---------------------------------------------------------------------------
extern PACKAGE TPrintFormDocPKO *PrintFormDocPKO;
//---------------------------------------------------------------------------
#endif
