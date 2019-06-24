//---------------------------------------------------------------------------

#ifndef UFormaSagrPerH
#define UFormaSagrPerH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ADODB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
//-------------------------------------------------
#include "UDMSprTypePrice.h"
#include "UDMSprPrice.h"
#include <IBSQL.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <ActnList.hpp>
//---------------------------------------------------------------------------
class TFormaSagrPer : public TForm
{
__published:	// IDE-managed Components
        TOpenDialog *OpenDialog1;
        TToolBar *ToolBar1;
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *LabelFileName;
        TButton *ButtonOpenFile;
        TPanel *Panel3;
        TPanel *Panel4;
        TDataSource *DataSource1;
        TADOTable *ADOTable1;
        TPanel *Panel6;
        TPanel *Panel2;
        TButton *ButtonZagr;
        TButton *ButtonTest;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TDBGrid *DBGrid1;
        TRichEdit *RichEdit1;
        TDBGrid *DBGrid2;
        TDBGrid *DBGrid3;
        TLabel *Label2;
        TLabel *Label3;
        TADOTable *ADOTable2;
        TADOTable *ADOTable3;
        TDataSource *DataSource2;
        TDataSource *DataSource3;
        TProgressBar *ProgressBar1;
	TIBQuery *SprTPrice1;
        TButton *ButtonBistrZagr;
        TCheckBox *CreatePRNCheckBox;
        TCheckBox *UpdateGrpCheckBox;
        TADOTable *ADOTable4;
        TTabSheet *TabSheet3;
        TDataSource *DataSource4;
        TDBGrid *DBGrid4;
	TpFIBDataSet *Nom;
	TpFIBDataSet *Ed;
	TpFIBDataSet *Price;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBIntegerField *NomIDNOM;
	TFIBIntegerField *NomTNOM;
	TFIBIntegerField *NomCODENOM;
	TFIBStringField *NomNAMENOM;
	TFIBStringField *NomFNAMENOM;
	TFIBStringField *NomKRNAMENOM;
	TFIBIntegerField *NomIDBASEDNOM;
	TFIBIntegerField *NomIDOSNEDNOM;
	TFIBIntegerField *NomIDGRPNOM;
	TFIBStringField *NomARTNOM;
	TFIBStringField *NomGID_SNOM;
	TFIBStringField *NomDESCR_SNOM;
	TFIBIntegerField *NomIDFIRMNOM;
	TFIBIntegerField *NomSTNDSNOM;
	TFIBStringField *NomGTDNOM;
	TFIBIntegerField *NomIDCOUNTRYNOM;
	TFIBIntegerField *EdIDED;
	TFIBStringField *EdNAMEED;
	TFIBBCDField *EdKFED;
	TFIBIntegerField *EdTSHED;
	TFIBStringField *EdSHED;
	TFIBIntegerField *EdIDNOMED;
	TFIBIntegerField *EdIDOKEIED;
	TFIBSmallIntField *EdNEISPED;
	TFIBStringField *EdGID_SED;
	TFIBIntegerField *PriceID_PRICE;
	TFIBIntegerField *PriceIDNOM_PRICE;
	TFIBIntegerField *PriceIDTYPE_PRICE;
	TFIBBCDField *PriceZNACH_PRICE;
	TFIBStringField *PriceGID_SPRICE;
	TpFIBQuery *NomR;
	TpFIBQuery *EdR;
	TpFIBQuery *PriceR;
	TpFIBDataSet *SprTPrice;
	TpFIBQuery *IBSQL;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonOpenFileClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ButtonZagrClick(TObject *Sender);
        void __fastcall ButtonTestClick(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall ButtonBistrZagrClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaSagrPer(TComponent* Owner);

        TDMSprTypePrice *DMSprTypePrice;
        TDMSprPrice *DMSprPrice;

        void ProveritSprEd(void);
        void ProveritSprPrice(void);

        String FileName;
        String CatalogFile;
        void AddNewTovar(void);
        void EditTovar(void);
        void UpdateEd(void);
        void UpdatePrice(void);
        void CreateDocPrihNAkl(void);

        bool ErrorUpdateSpr;
        int KolError;
        bool NoUpdate;
        int GetIdTypePrice(String name);
        String Zapros;
        void AddNewTovar1(void);
        void EditTovar1(void);
        void UpdateEd1(void);
        void UpdatePrice1(void);
        void UpdateGrp(void);
        void Zagruska(void);
        int IdNom;
        int IdEd;
        int IdPrice;
        String FloatToStringComma(double value);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSagrPer *FormaSagrPer;
//---------------------------------------------------------------------------
#endif
