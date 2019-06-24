//---------------------------------------------------------------------------

#ifndef UViborBaseH
#define UViborBaseH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TViborBase : public TForm
{
__published:	// IDE-managed Components
        TButton *ButtonOK;
        TButton *ButtonAdd;
        TButton *ButtonDel;
        TButton *ButtonCancel;
        TEdit *Password;
        TLabel *Label1;
        TLabel *Label2;
        TButton *ButtonRename;
        TListBox *ListBox1;
        TEdit *User;
        TLabel *LabelFileName;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ButtonCancelClick(TObject *Sender);
        void __fastcall ButtonAddClick(TObject *Sender);
        void __fastcall ButtonOKClick(TObject *Sender);
        void __fastcall ButtonRenameClick(TObject *Sender);
        void __fastcall ListBox1Click(TObject *Sender);
        void __fastcall ButtonDelClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall PasswordKeyPress(TObject *Sender, char &Key);
        void __fastcall UserKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
        __fastcall TViborBase(TComponent* Owner);
        void UpdateSpisok(void);
        TStringList * List;
        String FindFileName(String NameBase);
        void ZapuskProgramm(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TViborBase *ViborBase;
//---------------------------------------------------------------------------
#endif
