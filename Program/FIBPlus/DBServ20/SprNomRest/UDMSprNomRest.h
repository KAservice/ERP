//---------------------------------------------------------------------------

#ifndef UDMSprNomRestH
#define UDMSprNomRestH
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
//---------------------------------------------------------------------------
class TDMSprNomRest : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceElement;
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBStringField *TableNAME_NOMREST;
	TFIBDateTimeField *TablePOS_NOMREST;
	TIntegerField *TableRECNO;
	TpFIBDataSet *IBQ;
	TFIBBCDField *IBQNKOL_SPROD;
	TFIBBCDField *IBQBKOL_SPROD;
	TFIBBCDField *IBQKFPRICE_SPROD;
	TFIBSmallIntField *IBQSPIS_SPROD;
	TFIBStringField *IBQNAMENOM;
	TFIBBCDField *IBQVALUE_SSEZKF;
	TFIBBCDField *IBQVALUE_SSEZKF_SPROD;
	TFIBStringField *ElementSOST_NOMREST;
	TFIBStringField *ElementTEHN_NOMREST;
	TFIBStringField *ElementVIH_NOMREST;
	TFIBStringField *ElementSROK_NOMREST;
	TFIBStringField *ElementNOMER_NOMREST;
	TFIBStringField *ElementNAME_NOMREST;
	TFIBDateTimeField *ElementPOS_NOMREST;
	TFIBBCDField *ElementKOLEDPROD_NOMREST;
	TFloatField *IBQSEZKF_SPROD;
	TFloatField *IBQSEZKF;
	TFIBBCDField *ElementKFED;
	TFIBStringField *ElementNAME_MPRIG;
	TFIBStringField *ElementNAMENOM;
	TFIBStringField *ElementNAMEED;
	TFIBBCDField *TableID_NOMREST;
	TFIBBCDField *TableIDNOM_NOMREST;
	TFIBBCDField *ElementID_NOMREST;
	TFIBBCDField *ElementIDNOM_NOMREST;
	TFIBBCDField *ElementIDMPRIG_NOMREST;
	TFIBBCDField *ElementIDEDPROD_NOMREST;
	TFIBBCDField *ElementIDSKLAD_MPRIG;
	TFIBBCDField *IBQID_SPROD;
	TFIBBCDField *IBQIDKOMPL_SPROD;
	TFIBStringField *ElementGID_SNOMREST;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
	void __fastcall TableNAME_NOMRESTGetText(TField *Sender, AnsiString &Text,
          bool DisplayText);
	void __fastcall IBQCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprNomRest(TComponent* Owner);
        
        void OpenTable(void);

        int OpenElement(void);
        void NewElement(void);
        bool SaveElement(void);
        void DeleteElement(void);

		__int64 Id;
		__int64 IdNom;
        bool Error;
        String TextError;

        __int64 GetTekSostav(__int64 idNom, TDateTime pos);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprNomRest *DMSprNomRest;
//---------------------------------------------------------------------------
#endif
