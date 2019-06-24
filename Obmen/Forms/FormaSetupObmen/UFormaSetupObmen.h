//---------------------------------------------------------------------------

#ifndef UFormaSetupObmenH
#define UFormaSetupObmenH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <Mask.hpp>
#include "cxButtonEdit.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGroupBox.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxMaskEdit.hpp"
#include "cxRadioGroup.hpp"
#include "cxTextEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
#include "cxPC.hpp"
#include <ExtCtrls.hpp>
#include "cxLabel.hpp"
#include "UkanGlobalConstant.h"
//---------------------------------------------------------------------------
class TFormaSetupObmen : public TForm
{
__published:	// IDE-managed Components
        TOpenDialog *OpenDialog1;
	TcxPageControl *cxPageControl1;
	TcxTabSheet *cxTabSheet1;
	TcxTabSheet *cxTabSheet2;
	TPanel *Panel1;
	TcxGroupBox *cxGroupBox2;
	TLabel *Label9;
	TLabel *Label5;
	TEdit *NameBaseForObmenEdit;
	TEdit *IdBaseForObmenEdit;
	TPanel *Panel2;
	TButton *ButtonSave;
	TButton *ButtonClose;
	TcxTextEdit *EMailcxTextEdit;
	TcxLabel *cxLabel1;
	TcxTabSheet *cxTabSheet3;
	TcxTabSheet *cxTabSheet4;
	TcxGroupBox *cxGroupBox6;
	TLabel *Label15;
	TcxButtonEdit *CatalogObmenacxButtonEdit;
	TcxGroupBox *cxGroupBox4;
	TLabel *Label10;
	TLabel *Label11;
	TCheckBox *AutoObmenCheckBox;
	TEdit *IntervalEdit;
	TEdit *IntervalObmenaAfterErrorEdit;
	TcxRadioGroup *cxRadioGroup1;
	TcxRadioButton *CatalogObmenacxRadioButton;
	TcxRadioButton *MAPIcxRadioButton;
	TcxGroupBox *cxGroupBox1;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label6;
	TEdit *NameUserEdit;
	TEdit *PasswordUserEdit;
	TcxButtonEdit *ConnectStringcxButtonEdit;
	TLabel *Label1;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonSaveClick(TObject *Sender);
        void __fastcall ButtonCloseClick(TObject *Sender);
	void __fastcall ConnectStringcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall CatalogObmenacxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaSetupObmen(TComponent* Owner);
		TNotifyEvent FOnCloseForm;

		__int64 IdTecBase;
		__int64 IdBaseForObmen;

		void UpdateForm(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSetupObmen *FormaSetupObmen;
//---------------------------------------------------------------------------
#endif
