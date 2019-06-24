//---------------------------------------------------------------------------

#ifndef UFormaReportVosvratNalH
#define UFormaReportVosvratNalH
//---------------------------------------------------------------------------
#include "UDMReportVosvrat.h"
#include "UDM.h"
#include "UFormaSpiskaSprKKM.h"
#include "UFormaSpiskaSprFirm.h"
#include "USheetEditor.h"
//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtonEdit.hpp"
#include "cxCalendar.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxLabel.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
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
#include "cxPC.hpp"
#include "cxStyles.hpp"
#include <DB.hpp>
#include <ExtCtrls.hpp>
#include "cxGridBandedTableView.hpp"
#include "cxGridDBBandedTableView.hpp"
//---------------------------------------------------------------------------
class TFormaReportVosvratNal : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TcxLabel *cxLabel1;
	TcxDateEdit *PosNachcxDateEdit;
	TcxDateEdit *PosConcxDateEdit;
	TcxButtonEdit *NameKassacxButtonEdit;
	TcxLabel *cxLabel3;
	TcxLabel *cxLabel4;
	TPanel *Panel2;
	TcxButton *cxButtonClose;
	TcxButtonEdit *NameFirmcxButtonEdit;
	TcxLabel *cxLabel2;
	TcxGrid *cxGrid1;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridDBColumn *cxGrid1DBTableView1POSDOC;
	TcxGridDBColumn *cxGrid1DBTableView1NUMDOC;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEKKM;
	TcxGridDBColumn *cxGrid1DBTableView1SUMDOC;
	TcxGridDBColumn *cxGrid1DBTableView1OPERATION_DRKOROZN;
	TcxGridDBColumn *cxGrid1DBTableView1NKL_DRKOROZN;
	TcxGridDBColumn *cxGrid1DBTableView1NCHECK_DRKOROZN;
	TcxGridDBColumn *cxGrid1DBTableView1MODEL_DRKOROZN;
	TcxGridDBColumn *cxGrid1DBTableView1REGNUM_DRKOROZN;
	TcxGridDBColumn *cxGrid1DBTableView1SAVNUM_DRKOROZN;
	TcxGridLevel *cxGrid1Level1;
	TcxButton *cxButtonCreate;
	TcxButton *cxButtonPrintKM3;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButtonCreateClick(TObject *Sender);
	void __fastcall cxButtonCloseClick(TObject *Sender);
	void __fastcall NameKassacxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameFirmcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonPrintKM3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormaReportVosvratNal(TComponent* Owner);
        TDMReportVosvrat *DM;

        TNotifyEvent FOnCloseForm;

        bool Vibor;

		__int64 IdKassa;

		TFormaSpiskaSprKKM *FormaSpiskaSprKKM;
		void ViborKassa(void);
		void __fastcall EndViborKassa(TObject *Sender);

		__int64 IdFirm;
		TFormaSpiskaSprFirm *FormaSpiskaSprFirm;
		void ViborFirm(void);
		void __fastcall EndViborFirm(TObject *Sender);

		void PrintKM3(void);
		void OutputStringKM3(TSheetEditor *prForm);
		void OutputZagolovokKM3(TSheetEditor *prForm);
		void OutputPodavalKM3(TSheetEditor *prForm);
		int x,y,PorNumberStr;
		double SumReport;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaReportVosvratNal *FormaReportVosvratNal;
//---------------------------------------------------------------------------
#endif
