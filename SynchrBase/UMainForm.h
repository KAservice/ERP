//---------------------------------------------------------------------------

#ifndef UMainFormH
#define UMainFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonOpenFormSetup;
	TButton *ButtonUpdate;
	TTimer *Timer1;
	TLabel *LabelNameTable;
	TLabel *LabelStartUpdate;
	TTimer *Timer2;
	TTrayIcon *TrayIcon1;
	TImageList *ImageListTrayIcon;
	TPopupMenu *PopupMenuTrayIcon;
	TMenuItem *ShowPopupMenuTrayIcon;
	TTimer *TimerHide;
	void __fastcall ButtonOpenFormSetupClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ButtonUpdateClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall ShowPopupMenuTrayIconClick(TObject *Sender);
	void __fastcall TimerHideTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);

	void UpdateBase(void);

	void UpdateTable(UnicodeString name_table, UnicodeString name_field_id, TStringList * list);
	UnicodeString GetZaprosViborTable(UnicodeString name_table, UnicodeString name_field_id, TStringList * list);
	UnicodeString GetZaprosElement(UnicodeString name_table, UnicodeString name_field_id, TStringList * list);
	UnicodeString GetZaprosInsert(UnicodeString name_table, UnicodeString name_field_id, TStringList * list);
	UnicodeString GetZaprosUpdate(UnicodeString name_table,UnicodeString name_field_id, TStringList * list);



	TStringList * StrListTables;
	int IndexStrListTables;

	void SaveProtocol(UnicodeString str);
	UnicodeString CatalogProtocol;

	void UpdateUser(void);
	bool UpdUser;
	AnsiString NameUser;
	AnsiString PasswordUser;
	AnsiString ConnectString;

	UnicodeString CommaToStringPixel(UnicodeString value);
	UnicodeString GetTextTypeField(int type);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
