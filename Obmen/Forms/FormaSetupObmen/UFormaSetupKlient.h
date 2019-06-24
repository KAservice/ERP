//---------------------------------------------------------------------------

#ifndef UFormaSetupKlientH
#define UFormaSetupKlientH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TFormaSetupKlient : public TForm
{
__published:	// IDE-managed Components
        TEdit *IPAdressEdit;
        TEdit *PortEdit;
        TEdit *NameUserEdit;
        TEdit *PasswordUserEdit;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *ConnectStringEdit;
        TLabel *Label6;
        TEdit *PatchArhEdit;
        TLabel *Label7;
        TButton *ButtonViborFileArh;
        TOpenDialog *OpenDialog1;
        TButton *ButtonSave;
        TButton *ButtonClose;
        TEdit *PatchUnArhEdit;
        TLabel *Label8;
        TButton *Button1;
        TCheckBox *ViklPCCheckBox;
	TLabel *Label5;
	TLabel *Label9;
	TEdit *IdBaseForObmenEdit;
	TEdit *NameBaseForObmenEdit;
	TLabel *Label10;
	TCheckBox *AutoObmenCheckBox;
	TLabel *Label11;
	TEdit *IntervalEdit;
	TEdit *IntervalObmenaAfterErrorEdit;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonViborFileArhClick(TObject *Sender);
        void __fastcall ButtonSaveClick(TObject *Sender);
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaSetupKlient(TComponent* Owner);
        TNotifyEvent FOnCloseForm;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSetupKlient *FormaSetupKlient;
//---------------------------------------------------------------------------
#endif
