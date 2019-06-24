//---------------------------------------------------------------------------

#ifndef UInputCodeH
#define UInputCodeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFormInCode : public TForm
{
__published:	// IDE-managed Components
        TEdit *Edit1;
        TEdit *Edit2;
        TLabel *Label1;
        TLabel *NameSprLabel;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *NameTovarLabel;
        TLabel *OstatokLabel;
private:	// User declarations
public:		// User declarations
        __fastcall TFormInCode(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormInCode *FormInCode;
//---------------------------------------------------------------------------
#endif
