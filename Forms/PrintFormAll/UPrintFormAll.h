//---------------------------------------------------------------------------

#ifndef UPrintFormAllH
#define UPrintFormAllH
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
#include <Dialogs.hpp>

//---------------------------------------------------------------------------
class TPrintFormAll : public TForm
{
__published:	// IDE-managed Components
        TF1Book *F1;
        TPanel *Panel1;
        TButton *Button1;
        TButton *ButtonSave;
        TSaveDialog *SaveDialog1;
        TButton *ButtonPageSetup;
        TButton *ButtonPrintSetup;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall ButtonSaveClick(TObject *Sender);
        void __fastcall ButtonPageSetupClick(TObject *Sender);
        void __fastcall ButtonPrintSetupClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TPrintFormAll(TComponent* Owner);
        String FileName;
};
//---------------------------------------------------------------------------
extern PACKAGE TPrintFormAll *PrintFormAll;
//---------------------------------------------------------------------------
#endif
