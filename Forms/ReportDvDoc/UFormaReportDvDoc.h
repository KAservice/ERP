//---------------------------------------------------------------------------

#ifndef UFormaReportDvDocH
#define UFormaReportDvDocH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UDM.h"
#include "USheetEditor.h"
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
//---------------------------------------------------------------------------
class TFormaReportDvDoc : public TForm
{
__published:	// IDE-managed Components
	TpFIBDataSet *IBQ;
	TpFIBDataSet *DvRegOstNom;
	TpFIBTransaction *IBTr;
	TFIBDateTimeField *DvRegOstNomPOSDOC_OSTNOMDV;
	TFIBSmallIntField *DvRegOstNomTDV_OSTNOMDV;
	TFIBBCDField *DvRegOstNomSUM_OSTNOMDV;
	TFIBBCDField *DvRegOstNomKOL_OSTNOMDV;
	TFIBIntegerField *DvRegOstNomOPER_OSTNOMDV;
	TFIBBCDField *DvRegOstNomSUM2_OSTNOMDV;
	TFIBStringField *DvRegOstNomNAMEFIRM;
	TFIBStringField *DvRegOstNomNAMENOM;
	TFIBIntegerField *DvRegOstNomCODEPART;
	TFIBStringField *DvRegOstNomDOCPART;
	TFIBStringField *DvRegOstNomNAMESKLAD;
	TFIBBCDField *DvRegOstNomID_OSTNOMDV;
	TFIBBCDField *DvRegOstNomIDDOC_OSTNOMDV;
	TFIBBCDField *DvRegOstNomIDFIRM_OSTNOMDV;
	TFIBBCDField *DvRegOstNomIDSKL_OSTNOMDV;
	TFIBBCDField *DvRegOstNomIDNOM_OSTNOMDV;
	TFIBBCDField *DvRegOstNomIDPART_OSTNOMDV;
	TFIBBCDField *DvRegOstNomIDSTRDOC_OSTNOMDV;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaReportDvDoc(TComponent* Owner);

		__int64 IdDoc;
        int x,y;
        int porNumStr;

        void CreateReportDvDoc(__int64 id_doc);
        void OutputZagolovokReport(TSheetEditor *prForm);
        void OutputPodvalReport(TSheetEditor *prForm);

        void OutputZagolovokRegOstNom(TSheetEditor *prForm);
        void OutputStringRegOstNom(TSheetEditor *prForm);
        void OutputPodvalRegOstNom(TSheetEditor *prForm);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaReportDvDoc *FormaReportDvDoc;
//---------------------------------------------------------------------------
#endif
