//---------------------------------------------------------------------------

#ifndef UFormaExportSaleH
#define UFormaExportSaleH
//---------------------------------------------------------------------------

#include "UDMExportSale.h"
#include "UFormaSpiskaSprFirm.h"
#include "UFormaSpiskaSprSklad.h"
#include "UFormaSpiskaSprKKM.h"
//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "cxButtonEdit.hpp"
#include "cxCalendar.hpp"
#include "cxCheckBox.hpp"
#include "cxClasses.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxMaskEdit.hpp"
#include "cxRadioGroup.hpp"
#include "cxStyles.hpp"
#include "cxTextEdit.hpp"
#include <DB.hpp>
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>


#include <Dialogs.hpp>
#include "cxLocalization.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaExportSale : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TLabel *Label1;
	TcxButtonEdit *NameKassacxButtonEdit;
	TcxButtonEdit *NameSkladcxButtonEdit;
	TcxDateEdit *NachcxDateEdit;
	TcxDateEdit *ConcxDateEdit;
	TcxCheckBox *PoDatecxCheckBox;
	TcxRadioButton *SalecxRadioButton;
	TcxRadioButton *ReturnSalecxRadioButton;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1CODENOM;
	TcxGridDBColumn *cxGrid1DBTableView1ARTNOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid1DBTableView1CODE_SED;
	TcxGridDBColumn *cxGrid1DBTableView1SHED;
	TcxGridDBColumn *cxGrid1DBTableView1KFED;
	TcxGridDBColumn *cxGrid1DBTableView1KOL_SALE;
	TcxGridDBColumn *cxGrid1DBTableView1SUM_SALE;
	TcxButton *cxButtonClose;
	TcxButton *cxButtonCreate;
	TcxButtonEdit *NameFirmcxButtonEdit;
	TLabel *Label5;
	TcxButton *cxButtonExportText;
	TSaveDialog *SaveDialog1;
	TcxButton *cxButtonExportExcel;
	TcxButton *cxButtonExportHtml;
	TcxButton *cxButtonExportXML;
	TcxButtonEdit *PatchcxButtonEdit;
	TLabel *Label6;
	TcxGridDBColumn *cxGrid1DBTableView1OPERATION;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall NameKassacxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameFirmcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSkladcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonCreateClick(TObject *Sender);
	void __fastcall cxButtonCloseClick(TObject *Sender);
	void __fastcall cxButtonExportTextClick(TObject *Sender);
	void __fastcall cxButtonExportExcelClick(TObject *Sender);
	void __fastcall cxButtonExportHtmlClick(TObject *Sender);
	void __fastcall cxButtonExportXMLClick(TObject *Sender);
	void __fastcall PatchcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
private:	// User declarations

		//выбор фирмы
		TFormaSpiskaSprFirm * FormaSpiskaSprFirm;
		void ViborFirm(void);
		void __fastcall EndViborFirm(TObject *Sender);

		//выбор склада
		TFormaSpiskaSprSklad * FormaSpiskaSprSklad;
		void ViborSklad(void);
		void __fastcall EndViborSklad(TObject *Sender);

		//выбор кассы
		TFormaSpiskaSprKKM * FormaSpiskaSprKassa;
		void ViborKassa(void);
		void __fastcall EndViborKassa(TObject *Sender);

public:		// User declarations
	__fastcall TFormaExportSale(TComponent* Owner);
	void UpdateForm(void);

	TDMExportSale *DM;

   __int64 IdFirm;
   __int64 IdSklad;
   __int64 IdKassa;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaExportSale *FormaExportSale;
//---------------------------------------------------------------------------
#endif
