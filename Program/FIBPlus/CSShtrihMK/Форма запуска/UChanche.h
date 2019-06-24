//---------------------------------------------------------------------------

#ifndef UChancheH
#define UChancheH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TFChanche : public TForm
{
__published:	// IDE-managed Components
        TEdit *NameBase;
        TEdit *FileName;
        TButton *ButtonOK;
        TButton *ButtonCancel;
        TLabel *Label1;
        TLabel *Label2;
        void __fastcall ButtonCancelClick(TObject *Sender);
        void __fastcall ButtonOKClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFChanche(TComponent* Owner);
        String OldName;
};
//---------------------------------------------------------------------------
extern PACKAGE TFChanche *FChanche;
//---------------------------------------------------------------------------
#endif
