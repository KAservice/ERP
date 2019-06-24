//---------------------------------------------------------------------------

#ifndef UFormaSetupServerH
#define UFormaSetupServerH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TFormaSetupServer : public TForm
{
__published:	// IDE-managed Components
        TEdit *PortEdit;
        TEdit *NameUserEdit;
        TEdit *PasswordUserEdit;
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
	TLabel *Label5;
	TLabel *Label9;
	TEdit *IdBaseForObmenEdit;
	TEdit *NameBaseForObmenEdit;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonViborFileArhClick(TObject *Sender);
        void __fastcall ButtonSaveClick(TObject *Sender);
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaSetupServer(TComponent* Owner);
        TNotifyEvent FOnCloseForm;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSetupServer *FormaSetupServer;
//---------------------------------------------------------------------------
#endif
