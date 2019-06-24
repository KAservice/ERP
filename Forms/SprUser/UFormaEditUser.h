//---------------------------------------------------------------------------

#ifndef UFormaEditUserH
#define UFormaEditUserH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"


//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "IB_Services.hpp"
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGroupBox.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include <ActnList.hpp>
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaEditUser : public TForm
{
__published:	// IDE-managed Components
	TpFIBSecurityService *pFIBSecurityService1;
	TLabel *NameUserLabel;
	TLabel *NameServerLabel;
	TLabel *Name2UserLabel;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *RoleUserLabel;
	TcxGroupBox *cxGroupBox1;
	TcxButton *cxButtonClose;
	TcxButton *cxButtonAddRole;
	TcxButton *cxButtonDelRole;
	TcxGroupBox *cxGroupBox2;
	TcxButton *cxButtonNew;
	TcxButton *cxButtonEdit;
	TcxButton *cxButtonDel;
	TcxTextEdit *PasswordEdit;
	TcxTextEdit *Password2Edit;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TAction *ActionClose;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButtonAddRoleClick(TObject *Sender);
	void __fastcall cxButtonDelRoleClick(TObject *Sender);
	void __fastcall cxButtonNewClick(TObject *Sender);
	void __fastcall cxButtonEditClick(TObject *Sender);
	void __fastcall cxButtonDelClick(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormaEditUser(TComponent* Owner);

	IDMFibConnection * DM_Connection;
	IkanCom * InterfaceGlobalCom;
	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	bool Init(void);
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

	UnicodeString Name2User;
    void UpdateForm(void);
    UnicodeString RoleUser;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaEditUser *FormaEditUser;
//---------------------------------------------------------------------------
#endif
