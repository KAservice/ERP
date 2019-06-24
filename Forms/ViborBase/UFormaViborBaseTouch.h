//---------------------------------------------------------------------------

#ifndef UFormaViborBaseTouchH
#define UFormaViborBaseTouchH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include "UFormaEditBase.h"
#include "inifiles.hpp"
#include <ActnList.hpp>
#include <Buttons.hpp>
#include "UKalkulator.h"
//---------------------------------------------------------------------------
class TFormaViborBaseTouch : public TForm
{
__published:	// IDE-managed Components
        TButton *ButtonOK;
        TButton *ButtonAdd;
        TButton *ButtonDel;
        TButton *ButtonCancel;
        TButton *ButtonRename;
        TListBox *ListBox1;
        TLabel *LabelFileName;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TBitBtn *BitBtnInputCode;
	TBitBtn *BitBtnInputPassword;
	TEdit *CodeEdit;
	TEdit *PasswordEdit;
	TLabel *Label1;
	TLabel *Label2;
	TButton *ButtonUp;
	TButton *ButtonDown;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ButtonCancelClick(TObject *Sender);
        void __fastcall ButtonAddClick(TObject *Sender);
        void __fastcall ButtonOKClick(TObject *Sender);
        void __fastcall ButtonRenameClick(TObject *Sender);
        void __fastcall ListBox1Click(TObject *Sender);
        void __fastcall ButtonDelClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall BitBtnInputCodeClick(TObject *Sender);
	void __fastcall BitBtnInputPasswordClick(TObject *Sender);
	void __fastcall ButtonUpClick(TObject *Sender);
	void __fastcall ButtonDownClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaViborBaseTouch(TComponent* Owner);
        void UpdateSpisok(void);
        TStringList * List;
        void ZapuskProgramm(void);
        TNotifyEvent FOnCloseForm;
		void __fastcall EndEditParameterBase(TObject *Sender);

        AnsiString NameUser;
        AnsiString PasswordUser;
		AnsiString ConnectString;
		int CodeUser;
        int NumberARM;
        bool OutReady;
        bool CloseForm;
		TFormaEditBase  * FormaEditBase;

        HANDLE IdRodForm;
        HANDLE IdDochForm;
        TIniFile * Ini;
        int AllKolBase;
		int TekBase;

        TKalkulator * Kalkulator;
		void __fastcall EndInputCodeUser(TObject *Sender);
		void __fastcall EndInputPasswordUser(TObject *Sender);


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaViborBaseTouch *FormaViborBaseTouch;
//---------------------------------------------------------------------------
#endif
