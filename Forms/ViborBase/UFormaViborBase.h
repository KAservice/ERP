//---------------------------------------------------------------------------

#ifndef UFormaViborBaseH
#define UFormaViborBaseH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include "UFormaEditBase.h"
#include "inifiles.hpp"
#include <ActnList.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxListBox.hpp"
#include "cxTextEdit.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class TFormaViborBase : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *LabelFileName;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxListBox *ListBox1;
	TcxTextEdit *User;
	TcxTextEdit *Password;
	TcxButton *cxButtonAdd;
	TcxButton *cxButtonEdit;
	TcxButton *cxButtonDel;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonCancel;
	TAction *ActionAdd;
	TAction *ActionEdit;
	TAction *ActionDelete;
	TAction *ActionOK;
	TAction *ActionClose;
	TImageList *ImageList1;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall ListBox1Click(TObject *Sender);
	void __fastcall UserKeyPress(TObject *Sender, char &Key);
	void __fastcall PasswordKeyPress(TObject *Sender, char &Key);
	void __fastcall ActionAddExecute(TObject *Sender);
	void __fastcall ActionEditExecute(TObject *Sender);
	void __fastcall ActionDeleteExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaViborBase(TComponent* Owner);
        void UpdateSpisok(void);
        TStringList * List;
        void ZapuskProgramm(void);
        TNotifyEvent FOnCloseForm;
        void __fastcall EndEditParameterBase(TObject *Sender);

		AnsiString NameUser;
        AnsiString OldNameUser;
        AnsiString PasswordUser;
        AnsiString ConnectString;
        int NumberARM;
        bool OutReady;
        bool CloseForm;
        TFormaEditBase  * FormaEditBase;

        HANDLE IdRodForm;
        HANDLE IdDochForm;
        TIniFile * Ini;
        int AllKolBase;
		int TekBase;
		void SaveNameUser(void);
		void ClearNameUser(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaViborBase *FormaViborBase;
//---------------------------------------------------------------------------
#endif
