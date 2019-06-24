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
	TLabel *Label6;
	TComboBox *NumberLabelComboBox;
	TMaskEdit *CodeSertMaskEdit;
	TButton *ButtonSave;
	TButton *ButtonClose;
	TLabel *Label11;
	TLabel *LabelNameScale;
	TLabel *Label12;
	TcxLabel *cxLabel1;
	TEdit *IPEdit;
	TEdit *PortEdit;
	TComboBox *NumberBarCodeComboBox;
	TEdit *PrefiksBarCodeEdit;
	TComboBox *NumberOsnGrpComboBox;
	TComboBox *NumberFontComboBox;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ButtonSaveClick(TObject *Sender);
	void __fastcall ButtonCloseClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormSetupScale(TComponent* Owner);


	__int64 IdScale;
	__int64 IdOborud;
	AnsiString NameScale;
	void  UpdateForm(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSetupScale *FormSetupScale;
//---------------------------------------------------------------------------
#endif
