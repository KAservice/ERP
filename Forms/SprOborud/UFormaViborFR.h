//---------------------------------------------------------------------------

#ifndef UFormaViborFRH
#define UFormaViborFRH
//---------------------------------------------------------------------------
#include "UDMViborFR.h"
#include "IDMFibConnection.h"

//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ToolWin.hpp> 
#include <Buttons.hpp>
#include <ActnList.hpp>
#include "cxClasses.hpp"
#include "cxControls.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxEdit.hpp"
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
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxLookAndFeels.hpp"


//---------------------------------------------------------------------------
class TFormaViborFR : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TLabel *ZagolovokLabel;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxButton *cxButton1;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_OBORUD;
	TcxGridDBColumn *cxGrid1DBTableView1COMNAME_OBORUD;
	TcxGridDBColumn *cxGrid1DBTableView1MODEL_OBORUD;
	TAction *ActionClose;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
		__fastcall TFormaViborFR(TComponent* Owner);

	IDMFibConnection * DM_Connection;
	IkanCom * InterfaceGlobalCom;
	bool Init(void);
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;



		TNotifyEvent FOnCloseForm;
        HANDLE IdRodForm;
        TDMViborFR * DM;
        bool Vibor;
        bool OutReady;

        __int64 IdArm;
        void UpdateForm(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaViborFR *FormaViborFR;
//---------------------------------------------------------------------------
#endif
