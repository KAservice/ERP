//---------------------------------------------------------------------------

#ifndef UFormaReportOdinCodH
#define UFormaReportOdinCodH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include "UFormaSpiskaSprNom.h"
#include "UDM.h"
//#include "UPrintFormAll.h"
#include "USheetEditor.h"
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <ActnList.hpp>
//---------------------------------------------------------------------------
class TFormaReportOdinCod : public TForm
{
__published:	// IDE-managed Components
        TButton *ButtonCreateReport;
        TButton *ButtonClose;
        TLabel *Label3;
	TpFIBTransaction *IBTr;
	TpFIBDataSet *Nom;
	TpFIBDataSet *SpisokNom;
	TFIBIntegerField *SpisokNomCODENOM;
	TFIBStringField *SpisokNomNAMENOM;
	TFIBIntegerField *NomTNOM;
	TFIBIntegerField *NomCODENOM;
	TFIBStringField *NomNAMENOM;
	TFIBStringField *NomFNAMENOM;
	TFIBStringField *NomKRNAMENOM;
	TFIBStringField *NomARTNOM;
	TFIBStringField *NomGID_SNOM;
	TFIBStringField *NomDESCR_SNOM;
	TFIBIntegerField *NomSTNDSNOM;
	TFIBStringField *NomGTDNOM;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TFIBBCDField *SpisokNomIDNOM;
	TFIBBCDField *NomIDNOM;
	TFIBBCDField *NomIDBASEDNOM;
	TFIBBCDField *NomIDOSNEDNOM;
	TFIBBCDField *NomIDGRPNOM;
	TFIBBCDField *NomIDFIRMNOM;
	TFIBBCDField *NomIDCOUNTRYNOM;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall ButtonCreateReportClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaReportOdinCod(TComponent* Owner);

        int numRow;
        int numCol;
        int porNumStr;

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaReportOdinCod *FormaReportOdinCod;
//---------------------------------------------------------------------------
#endif
