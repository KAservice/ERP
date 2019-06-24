//---------------------------------------------------------------------------

#ifndef UFormaViborPeriodaH
#define UFormaViborPeriodaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include "UDM.h"
#include <ActnList.hpp>
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TFormaViborPerioda : public TForm
{
__published:	// IDE-managed Components
        TDateTimePicker *DateTimePicker1;
        TDateTimePicker *DateTimePicker2;
        TLabel *Label1;
        TLabel *Label2;
        TDateTimePicker *Time1;
        TDateTimePicker *Time2;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TButton *ButtonOK;
	TButton *ButtonClose;
	TAction *ActionOK;
	TAction *ActionClose;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Time1Change(TObject *Sender);
        void __fastcall Time2Change(TObject *Sender);
        void __fastcall DateTimePicker1KeyPress(TObject *Sender,
          char &Key);
        void __fastcall Time1KeyPress(TObject *Sender, char &Key);
        void __fastcall DateTimePicker2KeyPress(TObject *Sender,
          char &Key);
        void __fastcall Time2KeyPress(TObject *Sender, char &Key);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaViborPerioda(TComponent* Owner);
        TNotifyEvent FOnCloseForm;

        HANDLE IdRodForm;
        HANDLE IdDochForm;
        bool OutReady;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaViborPerioda *FormaViborPerioda;
//---------------------------------------------------------------------------
#endif
