//---------------------------------------------------------------------------

#ifndef UFormaSetupScaleH
#define UFormaSetupScaleH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Mask.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLabel.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormSetupScale : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TCheckBox *CheckBoxPrintDate;
	TCheckBox *CheckBoxPrintPrice;
	TCheckBox *CheckBoxPrintZnakSert;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TComboBox *VidLabelComboBox;
	TMaskEdit *HeightLabelMaskEdit;
	TMaskEdit *NumberOtdelVesMaskEdit;
	TMaskEdit *NumberOtdelShtMaskEdit;
	TComboBox *TypeSHComboBox;
	TMaskEdit *CodeSertMaskEdit;
	TEdit *ReklamaStr1Edit;
	TEdit *ReklamaStr2Edit;
	TEdit *NeZaprogStr1Edit;
	TEdit *NeZaprogStr2Edit;
	TButton *ButtonSave;
	TButton *ButtonClose;
	TLabel *Label11;
	TLabel *LabelNameScale;
	TMaskEdit *KolDopStringMaskEdit;
	TLabel *Label12;
	TcxComboBox *TypeSrokGodncxComboBox;
	TcxLabel *cxLabel1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ButtonSaveClick(TObject *Sender);
	void __fastcall ButtonCloseClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormSetupScale(TComponent* Owner);


	__int64 IdScale;
	AnsiString NameScale;
	void  UpdateForm(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSetupScale *FormSetupScale;
//---------------------------------------------------------------------------
#endif
