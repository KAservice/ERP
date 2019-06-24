//---------------------------------------------------------------------------

#ifndef UMainFormH
#define UMainFormH
//---------------------------------------------------------------------------
#include "UFormaViborBase.h"
#include "UDMSprScale.h"
#include "UDMSprVesNomForScale.h"
#include "UDMSprOborud.h"
#include "UDMQueryRead.h"
//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
#include <ScktComp.hpp>
#include <Sockets.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TStatusBar *StatusBar;
	TMainMenu *MainMenu1;
	TMenuItem *HelpMainMenu;
	TMenuItem *MaimMenuAbout;
	TLabel *MessageLabel;
	TProgressBar *ProgressBar1;
	TMenuItem *ScaleMainMenu;
	TPopupMenu *PopupMenuSprScale;
	TLabel *LabelNameScale;
	TLabel *LabelIP;
	TLabel *LabelPort;
	TClientSocket *ClientSocket;
	TUdpSocket *UdpSocket;
	TLabel *LabelNameTypePrice;
	TImageList *ImageList1;
	TToolBar *ToolBar2;
	TToolButton *ToolButtonScale;
	TToolButton *ToolButtonZagrusitScale;
	TToolButton *ToolButtonSetupScale;
	TToolButton *ToolButtonOpenAbout;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall MaimMenuAboutClick(TObject *Sender);


	void __fastcall PopupMenuSprScaleClick(TObject *Sender);
	void __fastcall ClientSocketConnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall ClientSocketRead(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall ToolButtonDisconnectClick(TObject *Sender);
	void __fastcall ClientSocketError(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode);
	void __fastcall ToolButtonZagrusitScaleClick(TObject *Sender);
	void __fastcall ScaleMainMenuClick(TObject *Sender);
	void __fastcall ToolButtonOpenAboutClick(TObject *Sender);
	void __fastcall ToolButtonSetupScaleClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);

	AnsiString NameFileIni;

	TFormaViborBase * FormaViborBase;
	void __fastcall EndViborBase(TObject *Sender);

    TDMSprOborud * DMSprOborud;
	TDMSprScale * DMSprScale;
	void GetSpisokScale(void);
	TDMSprVesNomForScale  * DMSprVesNomForScale;
	TDMQueryRead *DMQueryVesNom;

	__int64 IdScale;
	AnsiString IP;
	int Port;
	__int64 IdOborud;

	void ZagrusitScale(void);
	void CreateFileMessage(void);
	void AddRecordTovar(int plu,
							int status_plu,
							int number_etiketki,
							int number_shtrih_coda,
							int prefiks_shtrih_coda,
							double price,
							double massa_tary,
							int code_tovar,
							TDateTime date_real,
							int srok_godn,
							AnsiString code_sertif,
							int number_osn_group,
							int number_font_name_tovar,
							AnsiString name_tovar);
							
	WORD CRC16(BYTE *buf, WORD len);
	void SendUDPPaket(void);
	void Connect(void);

	int KolRecord;

	void SendBlok(int number_blok);




	void ShowAbout(void);


	int NumberLabel;
	int NumberBarCode;
	int PrefiksBarCode;
	AnsiString CodeSertif;
	int NumberOsnGrp;
	int NumberFont;

	void GetParameterScale(int id_oborud);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
