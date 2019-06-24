//---------------------------------------------------------------------------

#ifndef UFormaInputTextH
#define UFormaInputTextH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaInputText : public TForm
{
__published:	// IDE-managed Components
        TLabel *NameLabel;
	TcxTextEdit *InputTextEdit;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall InputTextEditKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaInputText(TComponent* Owner);


        HANDLE IdRodForm;
        HANDLE IdDochForm;
        TNotifyEvent FOnCloseForm;
        
        bool Vibor;
        bool OutReady;
        UnicodeString InputText;



};
//---------------------------------------------------------------------------
extern PACKAGE TFormaInputText *FormaInputText;
//---------------------------------------------------------------------------
#endif
