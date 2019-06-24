//---------------------------------------------------------------------------

#ifndef UMainFormH
#define UMainFormH
//---------------------------------------------------------------------------
#include "UFormaViborBase.h"
#include "UDMSprScale.h"
#include "UDMSprVesNomForScale.h"
#include "UDMQueryRead.h"
#include "UScaleVP.h"
#include "UDMSprOborud.h"
//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TPopupMenu *PopupMenuSprScale;
	TMenuItem *ZagrScaleMainMenu;
	TMenuItem *HelpMainMenu;
	TMenuItem *OpenAboutMainMenu;
	TLabel *LabelNameScale;
	TLabel *LabelPort;
	TProgressBar *ProgressBar1;
	TStatusBar *StatusBar;
	TToolBar *ToolBar1;
	TToolButton *ToolButtonScale;
	TLabel *LabelSetNumber;
	TLabel *LabelBaudRate;
	TLabel *LabelKol;
	TToolButton *ToolButtonSetupScale;
	TToolButton *ToolButtonSetFormatLabel;
	TToolButton *ToolButtonSetParameterLabel;
	TToolButton *ToolButtonZagrusitScale;
	TToolButton *ToolButtonOpenAbout;
	TImageList *ImageList1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall OpenAboutMainMenuClick(TObject *Sender);

	///---------
		void __fastcall PopupMenuSprScaleClick(TObject *Sender);
	void __fastcall ZagrScaleMainMenuClick(TObject *Sender);
	void __fastcall ToolButtonSetupScaleClick(TObject *Sender);
	void __fastcall ToolButtonZagrusitScaleClick(TObject *Sender);
	void __fastcall ToolButtonSetFormatLabelClick(TObject *Sender);
	void __fastcall ToolButtonSetParameterLabelClick(TObject *Sender);
	void __fastcall ToolButtonOpenAboutClick(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);

	//---------------
private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);

	TDMSprOborud * DMSprOborud;

	TFormaViborBase * FormaViborBase;
	void __fastcall EndViborBase(TObject *Sender);


	TDMSprScale * DMSprScale;
	void GetSpisokScale(void);
	TDMSprVesNomForScale  * DMSprVesNomForScale;


	TDMQueryRead *DMQueryVesNom;

	__int64 IdScale;
	int Port;
	int BaudRate;
	int SetNumber;

	TScaleVP * ScaleVP;
	void ZagrusitScale(void);
	void AddTovar(void);
	void __fastcall ObrabExternalEvent(void);

	int KolZagrTov;

	        enum    {No,
				ZagrTovar_Operation,
				SetFormatLabel_Operation,
				SetParameterLabel_Operation} Operation;

	void ShowAbout(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
