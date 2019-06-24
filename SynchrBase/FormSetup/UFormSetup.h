//---------------------------------------------------------------------------

#ifndef UFormSetupH
#define UFormSetupH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxEdit.hpp"
#include "cxGroupBox.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxTextEdit.hpp"
#include "cxClasses.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include <DB.hpp>
#include "cxButtons.hpp"
#include <Menus.hpp>
#include "cxDBLookupComboBox.hpp"
#include "cxCheckBox.hpp"
#include "cxPC.hpp"
#include <ExtCtrls.hpp>
#include <DBClient.hpp>
#include <SimpleDS.hpp>
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormSetup : public TForm
{
__published:	// IDE-managed Components
	TcxPageControl *cxPageControl1;
	TcxTabSheet *cxTabSheet1;
	TcxTabSheet *cxTabSheet2;
	TcxGrid *cxGridFields;
	TcxGridDBTableView *cxGridFieldsDBTableView1;
	TcxGridDBColumn *cxGridFieldsDBTableView1NameFields;
	TcxGridTableView *cxGridFieldsTableView1;
	TcxGridColumn *cxGridFieldsTableView1Out;
	TcxGridColumn *cxGridFieldsTableView1NameField;
	TcxGridLevel *cxGridFieldsLevel1;
	TcxGrid *cxGridTables;
	TcxGridDBTableView *cxGridTablesDBTableView1;
	TcxGridTableView *cxGridTablesTableView1;
	TcxGridColumn *cxGridTablesTableView1Number;
	TcxGridColumn *cxGridTablesTableView1NameTable;
	TcxGridColumn *cxGridTablesTableView1NameFieldId;
	TcxGridLevel *cxGridTablesLevel1;
	TcxGroupBox *cxGroupBox2;
	TcxLabel *cxLabel4;
	TcxLabel *cxLabel6;
	TcxLabel *cxLabel7;
	TcxGroupBox *cxGroupBox1;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel3;
	TcxLabel *cxLabel5;
	TcxTextEdit *ConnectStringcxTextEdit;
	TcxTextEdit *NameUsercxTextEdit;
	TcxTextEdit *PasswordUsercxTextEdit;
	TcxButton *cxButton5;
	TcxButton *cxButtonConnect;
	TcxButton *cxButtonDisconnect;
	TPanel *Panel1;
	TcxButton *cxButton1;
	TcxButton *cxButtonUpdateFields;
	TPanel *Panel2;
	TcxButton *cxButton3;
	TPanel *Panel3;
	TcxTextEdit *ConnectString2cxTextEdit;
	TcxTextEdit *NameUser2cxTextEdit;
	TcxTextEdit *PasswordUser2cxTextEdit;
	TcxButton *cxButton4;
	TcxCheckBox *UpdateUsercxCheckBox;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButtonConnectClick(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxButtonUpdateFieldsClick(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall cxButton4Click(TObject *Sender);
	void __fastcall cxButtonDisconnectClick(TObject *Sender);
	void __fastcall cxButton5Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormSetup(TComponent* Owner);


	void UpdateForm(void);
	void UpdateFields(void);
	void SaveInfoTable(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSetup *FormSetup;
//---------------------------------------------------------------------------
#endif
