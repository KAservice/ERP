//---------------------------------------------------------------------------

#ifndef UZapuskH
#define UZapuskH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFZapusk : public TForm
{
__published:	// IDE-managed Components
        TButton *ButtonOK;
        TButton *ButtonAdd;
        TButton *ButtonDel;
        TButton *ButtonCancel;
        TLabel *Label1;
        TButton *ButtonRename;
        TListBox *ListBox1;
        TLabel *LabelFileName;
        TEdit *SetNumber;
        TUpDown *UpDown1;
        TLabel *Label3;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ButtonCancelClick(TObject *Sender);
        void __fastcall ButtonAddClick(TObject *Sender);
        void __fastcall ButtonOKClick(TObject *Sender);
        void __fastcall ButtonRenameClick(TObject *Sender);
        void __fastcall ListBox1Click(TObject *Sender);
        void __fastcall ButtonDelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFZapusk(TComponent* Owner);
        void UpdateSpisok(void);
        TStringList * List;
        String FindFileName(String NameBase);
};
//---------------------------------------------------------------------------
extern PACKAGE TFZapusk *FZapusk;
//---------------------------------------------------------------------------
#endif
