//---------------------------------------------------------------------------

#ifndef UHOT_FormaReportSostNF2H
#define UHOT_FormaReportSostNF2H
//---------------------------------------------------------------------------
#include "USheetEditor.h"
#include "UDM.h"
#include "UHOT_FormaSpiskaSprObject.h"
#include "UHOT_FormaSpiskaSprCatNom.h"
#include "UHOT_FormaSpiskaSprNF.h"
#include "UHOT_FormaSpiskaSprSostNom.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include <Buttons.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <ActnList.hpp>
#include "cxButtonEdit.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxButtons.hpp"
#include "cxCalendar.hpp"
#include "cxDropDownEdit.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxClasses.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include <ExtCtrls.hpp>
#include "cxGridBandedTableView.hpp"
//---------------------------------------------------------------------------
class THOT_FormaReportSostNF2 : public TForm
{
__published:	// IDE-managed Components
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TPanel *Panel1;
	TcxButton *cxButtonCreateReport;
	TcxButton *cxButtonClose;
	TcxButtonEdit *NameObjectcxButtonEdit;
	TLabel *Label4;
	TcxButtonEdit *NameCatcxButtonEdit;
	TcxDateEdit *PosNachcxDateEdit;
	TLabel *Label2;
	TLabel *Label1;
	TcxDateEdit *PosConcxDateEdit;
	TLabel *Label3;
	TLabel *Label7;
	TLabel *Label9;
	TcxButtonEdit *NameSostcxButtonEdit;
	TcxButtonEdit *NameNomercxButtonEdit;
	TLabel *Label6;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridTableView *cxGrid1TableView1;
	TpFIBTransaction *pFIBTr;
	TpFIBDataSet *SostNF;
	TcxGridBandedTableView *cxGrid1BandedTableView1;
	TFIBBCDField *SostNFID_HOT_SOSTNF;
	TFIBBCDField *SostNFID_HOT_SCATNOM;
	TFIBStringField *SostNFNAME_HOT_SCATNOM;
	TFIBBCDField *SostNFID_HOT_SNF;
	TFIBStringField *SostNFNAME_HOT_SNF;
	TFIBIntegerField *SostNFKOLM_HOT_SNF;
	TFIBBCDField *SostNFID_HOT_SSOSTNOM;
	TFIBDateTimeField *SostNFPOSNACH_HOT_SOSTNF;
	TFIBDateTimeField *SostNFPOSCON_HOT_SOSTNF;
	TFIBIntegerField *SostNFKOLM_HOT_SOSTNF;
	TFIBStringField *SostNFNAME_HOT_SSOSTNOM;
	TFIBBCDField *SostNFID_HOT_RGSOSTNF;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxButtonCreateReportClick(TObject *Sender);
	void __fastcall cxButtonCloseClick(TObject *Sender);
	void __fastcall NameObjectcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameCatcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameNomercxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSostcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxGrid1BandedTableView1CustomDrawCell(
          TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
          TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone);
private:	// User declarations
public:		// User declarations
        __fastcall THOT_FormaReportSostNF2(TComponent* Owner);

		__int64 IdObject;
		__int64 IdCat;
		__int64 IdNomer;
		__int64 IdSost;

		bool NewElement;  // новый элемент
		bool Prosmotr;    //только просмотр
		bool Vibor;       //для выбора
		__int64 IdDoc;           //идентификатор текущей записи

		__int64 IdElementaMaster;  //идентификатор внешенго справочника-владельца

		//выбор объекта
		THOT_FormaSpiskaSprObject * HOT_FormaSpiskaSprObject;
		void ViborObject(void);
		void __fastcall EndViborObject(TObject *Sender);

		//выбор категории номера
		THOT_FormaSpiskaSprCatNom * HOT_FormaSpiskaSprCatNom;
		void ViborCatNom(void);
		void __fastcall EndViborCatNom(TObject *Sender);

		//выбор номера
		THOT_FormaSpiskaSprNF *  HOT_FormaSpiskaSprNF;
		void ViborNF(void);
		void __fastcall EndViborNF(TObject *Sender);

		//выбор состояния номера
		THOT_FormaSpiskaSprSostNom * HOT_FormaSpiskaSprSostNom;
		void ViborSostNom(void);
		void __fastcall EndViborSostNom(TObject *Sender);

		AnsiString GetTextQuery(void);

        void OutputSost(int tec_column_left_margin, int num_first_row);
		int GetPosStart(void);
		int GetPosFinish(void);
                                                          
};
//---------------------------------------------------------------------------
extern PACKAGE THOT_FormaReportSostNF2 *HOT_FormaReportSostNF2;
//---------------------------------------------------------------------------
#endif
