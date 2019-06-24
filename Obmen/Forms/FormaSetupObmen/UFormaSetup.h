//---------------------------------------------------------------------------

#ifndef UFormaSetupH
#define UFormaSetupH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TFormaSetup : public TForm
{
__published:	// IDE-managed Components
        TEdit *IPAdressEdit;
        TEdit *PortEdit;
        TEdit *NameUserEdit;
        TEdit *PasswordUserEdit;
        TEdit *PrefiksEdit;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
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
        TEdit *CatalogObmenaEdit;
        TButton *ButtonViborCatalogObmena;
        TLabel *Label9;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonViborFileArhClick(TObject *Sender);
        void __fastcall ButtonSaveClick(TObject *Sender);
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall ButtonViborCatalogObmenaClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaSetup(TComponent* Owner);
        TNotifyEvent FOnCloseForm;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSetup *FormaSetup;
//---------------------------------------------------------------------------
#endif
