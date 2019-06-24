//---------------------------------------------------------------------------

#ifndef UFormaEditBaseH
#define UFormaEditBaseH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include <ActnList.hpp>
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class TFormaEditBase : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonCancel;
	TcxTextEdit *NumberARM;
	TcxTextEdit *ConnectString;
	TcxTextEdit *NameBase;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TAction *ActionClose;
	TAction *ActionOK;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
	void __fastcall NameBaseKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall ConnectStringKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall NumberARMKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaEditBase(TComponent* Owner);
        String OldName;
        TNotifyEvent FOnCloseForm;
        bool OutReady;

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaEditBase *FormaEditBase;
//---------------------------------------------------------------------------
#endif
