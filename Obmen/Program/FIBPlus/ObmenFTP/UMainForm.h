//---------------------------------------------------------------------------

#ifndef UMainFormH
#define UMainFormH
//---------------------------------------------------------------------------

#include "UFormaSetupObmen.h"

//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//#include <ScktComp.hpp>
#include <Dialogs.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include "IdExplicitTLSClientServerBase.hpp"
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdFTP.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *CreateDataOutMainMenu;
	TMenuItem *CreateFileMainMenu;
	TMenuItem *ZagrIsmenMainMenu;
	TMenuItem *OpenFormSetupMainMenu;
	TProgressBar *ProgressBar1;
	TStatusBar *StatusBar1;
	TMemo *Memo1;
	TPanel *Panel1;
	TLabel *StringConnectLabel;
	TLabel *NameBaseForObmenLabel;
	TOpenDialog *OpenDialog1;
	TMenuItem *TestConnectBaseMainMenu;
	TTrayIcon *TrayIcon1;
	TPopupMenu *PopupMenuTrayIcon;
	TImageList *ImageListTrayIcon;
	TMenuItem *ShowPopupMenuTrayIcon;
	TMenuItem *HideMainMenu;
	TTimer *Timer1;
	TTimer *TimerHide;
	TToolBar *ToolBar1;
	TToolButton *ToolButtonZagrusitFile;
	TToolButton *ToolButtonSetup;
	TImageList *ImageList1;
	TMenuItem *N1;
	TToolButton *ToolButtonCreateFile;
	TToolButton *ToolButton1;
	TMenuItem *ZagrusitMainMenu;
	TMenuItem *VigrusitMainMenu;
	TIdFTP *IdFTP1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall OpenFormSetupMainMenuClick(TObject *Sender);
	void __fastcall CreateDataOutMainMenuClick(TObject *Sender);
	void __fastcall CreateFileMainMenuClick(TObject *Sender);
	void __fastcall ZagrIsmenMainMenuClick(TObject *Sender);
	void __fastcall TestConnectBaseMainMenuClick(TObject *Sender);
	void __fastcall ShowPopupMenuTrayIconClick(TObject *Sender);
	void __fastcall HideMainMenuClick(TObject *Sender);
	void __fastcall TimerHideTimer(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall ToolButtonSetupClick(TObject *Sender);
	void __fastcall ToolButtonZagrusitFileClick(TObject *Sender);
	void __fastcall ToolButtonCreateFileClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);

	void GetParameterObmen(void);

	//настройка параметров
	TFormaSetupObmen * FormaSetupObmen;
	void OpenFormSetupObmen(void);
	void __fastcall CloseFormSetupObmen(TObject *Sender);
	
	//параметры обмена

	UnicodeString UserName;
	UnicodeString PasswordUser;
	UnicodeString ConnectString;

	UnicodeString PatchArhivator;
	UnicodeString PatchUnArh;

	UnicodeString NameBaseForObmen;
	__int64 IdBaseForObmen;
	__int64 IdTecBase;
	

	UnicodeString CatalogProtocol;
	UnicodeString LocCatalog;

	int TypeObmen;   //1- через каталог обмена, 2- через FTP

	UnicodeString CatalogObmena;

	UnicodeString FTPHost;
	UnicodeString FTPPatch;
	UnicodeString FTPUser;
	UnicodeString FTPPassword;

   int Interval;
   int IntervalAfterError;
   bool AutoObmen;


	
    //-----------------------------------------------
	void UpdateForm(void);


	void CreateDataOut(void);
	void CreateXMLFile(bool povtor);
	bool ArhiveXMLFile(void);
	bool UnarhiveFile(void);
	void UpdateBase(void);
	


	UnicodeString InNameFileArh;
	UnicodeString InNameFileXml;
	UnicodeString OutNameFileArh;
	UnicodeString OutNameFileXml;

	int Int_Operation;
	UnicodeString Operation;

	void SetOperationObmen(int operation);
	void GetIdTecBase(void);
	int GetOperationObmen(__int64 id_base_for_obmen);


        void __fastcall EventNextRecord(TObject *Sender);
        void __fastcall EventFirstRecord(TObject *Sender);
		int *lpKolRecord;
		int KolObrabRecord;
		int TecKolRecordForProtocol;
		int TecKolRecordForMessage;
		bool UpdateProgressBar;





   void StartTimerIntervalObmena(void);
   void StartTimerIntervalObmenaAfterError(void);


   void ZagrusitIsmen(void);
   void VigrusitIsmen(void);


   bool CopyFileInLocCatalog(void);
   bool CopyFileInCatalogObmena(void);

   bool DeleteVhodFileInCatalogObmena(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
