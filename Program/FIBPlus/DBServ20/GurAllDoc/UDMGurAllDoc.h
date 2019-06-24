//---------------------------------------------------------------------------

#ifndef UDMGurAllDocH
#define UDMGurAllDocH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
//---------------------------------------------------------------------------
class TDMGurAllDoc : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TFIBSmallIntField *TablePRDOC;
	TFIBStringField *TableTDOC;
	TFIBIntegerField *TableNUMDOC;
	TFIBBCDField *TableSUMDOC;
	TFIBStringField *TableNAMEFIRM;
	TFIBStringField *TableNAMESKLAD;
	TFIBStringField *TableNAMEKLIENT;
	TFIBStringField *TableNAME_USER;
	TpFIBDataSet *RegOstNomDv;
	TFIBDateTimeField *RegOstNomDvPOSDOC_OSTNOMDV;
	TFIBSmallIntField *RegOstNomDvTDV_OSTNOMDV;
	TFIBBCDField *RegOstNomDvSUM_OSTNOMDV;
	TFIBBCDField *RegOstNomDvKOL_OSTNOMDV;
	TFIBIntegerField *RegOstNomDvOPER_OSTNOMDV;
	TFIBBCDField *RegOstNomDvSUM2_OSTNOMDV;
	TFIBStringField *RegOstNomDvNAMEFIRM;
	TFIBStringField *RegOstNomDvNAMENOM;
	TFIBIntegerField *RegOstNomDvCODEPART;
	TFIBStringField *RegOstNomDvDOCPART;
	TFIBStringField *RegOstNomDvNAMESKLAD;
	TpFIBDataSet *IBQ;
	TFIBDateTimeField *TablePOSDOC;
	TpFIBQuery *pFIBQ;
	TFIBBCDField *TableIDDOC;
	TFIBBCDField *TableIDFIRMDOC;
	TFIBBCDField *TableIDSKLDOC;
	TFIBBCDField *TableIDKLDOC;
	TFIBBCDField *TableIDDOGDOC;
	TFIBBCDField *TableIDUSERDOC;
	TFIBBCDField *TableIDDOCOSNDOC;
	TFIBBCDField *TableIDEXTDOC;
	TFIBIntegerField *TableTYPEEXTDOC;
	TFIBBCDField *RegOstNomDvID_OSTNOMDV;
	TFIBBCDField *RegOstNomDvIDDOC_OSTNOMDV;
	TFIBBCDField *RegOstNomDvIDFIRM_OSTNOMDV;
	TFIBBCDField *RegOstNomDvIDSKL_OSTNOMDV;
	TFIBBCDField *RegOstNomDvIDNOM_OSTNOMDV;
	TFIBBCDField *RegOstNomDvIDPART_OSTNOMDV;
	TFIBBCDField *RegOstNomDvIDSTRDOC_OSTNOMDV;
	TFIBStringField *TableGID_DOC;
	TFIBBCDField *TableIDBASE_GALLDOC;
	TFIBBCDField *TableIDPROJECT_GALLDOC;
	TFIBStringField *TableNAME_SPROJECT;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall TableTDOCGetText(TField *Sender, AnsiString &Text,
          bool DisplayText);
	void __fastcall TableSUMDOCGetText(TField *Sender, AnsiString &Text,
          bool DisplayText);
private:	// User declarations
public:		// User declarations
        __fastcall TDMGurAllDoc(TComponent* Owner);

		bool Error;
		AnsiString TextError;
		TDateTime PosNach;
		TDateTime PosCon;
		__int64 IdDoc;
		__int64 IdKlient;
		__int64 IdSklad;
		__int64 IdFirm;
		String   StringTypeDoc;
		bool OtborVkl;
		bool NoCheck;

        void OpenTable();
		void UpdateTable(void);
		__int64 FindDocPoIdDog(__int64 iddogovor);
		bool CancelDvRegDoc(AnsiString type_doc, __int64 id_doc);
		bool DvRegDoc(AnsiString type_doc, __int64 id_doc);

        void AllCancelDvRegDoc(void);
		void AllDvRegDoc(void);


};
//---------------------------------------------------------------------------
extern PACKAGE TDMGurAllDoc *DMGurAllDoc;
//---------------------------------------------------------------------------
#endif
