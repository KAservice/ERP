//---------------------------------------------------------------------------

#ifndef UDMSprNomH
#define UDMSprNomH
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
#include <DBClient.hpp>
//---------------------------------------------------------------------------
class TDMSprNom : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBIntegerField *TableCODENOM;
	TFIBIntegerField *TableTNOM;
	TFIBStringField *TableNAMENOM;
	TFIBStringField *TableNAMEED;
	TFIBBCDField *TableZNACH_PRICE;
	TFIBBCDField *TableSUMKOL;
	TpFIBDataSet *BasEd;
	TpFIBDataSet *OsnEd;
	TFIBStringField *BasEdNAMEED;
	TFIBBCDField *BasEdKFED;
	TFIBIntegerField *BasEdTSHED;
	TFIBStringField *BasEdSHED;
	TFIBSmallIntField *BasEdNEISPED;
	TFIBStringField *OsnEdNAMEED;
	TFIBBCDField *OsnEdKFED;
	TFIBIntegerField *OsnEdTSHED;
	TFIBStringField *OsnEdSHED;
	TFIBSmallIntField *OsnEdNEISPED;
	TpFIBDataSet *IBQSprGrpBV;
	TFIBStringField *IBQSprGrpBVNAMEPOD;
	TFIBStringField *IBQSprGrpBVNAME_GBVNOM;
	TpFIBDataSet *SpTPrice;
	TFIBStringField *SpTPriceNAME_TPRICE;
	TpFIBDataSet *Code;
	TFIBIntegerField *CodeMAXCODE;
	TFIBIntegerField *ElementTNOM;
	TFIBIntegerField *ElementCODENOM;
	TFIBStringField *ElementFNAMENOM;
	TFIBStringField *ElementKRNAMENOM;
	TFIBStringField *ElementARTNOM;
	TFIBStringField *ElementDESCR_SNOM;
	TFIBIntegerField *ElementSTNDSNOM;
	TFIBStringField *ElementGTDNOM;
	TFIBBCDField *ElementZNACH_PRICE;
	TFIBStringField *ElementNAMEFIRM;
	TFIBStringField *ElementNAME_SCOUNTRY;
	TpFIBQuery *pFIBQuery;
	TpFIBTransaction *pFIBTrUpdate;
	TpFIBTransaction *pFIBTr;
	TFIBSmallIntField *ElementFL_CHANGE_NOM;
	TFIBBCDField *ElementMINOSTNOM;
	TFIBBCDField *BasEdIDED;
	TFIBBCDField *BasEdIDNOMED;
	TFIBBCDField *BasEdIDOKEIED;
	TFIBBCDField *OsnEdIDED;
	TFIBBCDField *OsnEdIDNOMED;
	TFIBBCDField *OsnEdIDOKEIED;
	TFIBBCDField *SpTPriceID_TPRICE;
	TFIBBCDField *IBQSprGrpBVIDPOD_GBVNOM;
	TFIBBCDField *IBQSprGrpBVID_GBVNOM;
	TFIBStringField *ElementGID_SNOM;
	TFIBBCDField *ElementSKIDKA1_SNOM;
	TFIBBCDField *ElementSKIDKA2_SNOM;
	TFIBBCDField *ElementSKIDKA3_SNOM;
	TFIBStringField *ElementNAME_SVIDNOM;
	TFIBSmallIntField *ElementTYPESRGODN_SNOM;
	TFIBSmallIntField *ElementSRGODN_SNOM;
	TpFIBDataSet *SprScaleAndGrpVesNom;
	TFIBStringField *SprScaleAndGrpVesNomNAME_SSCALE;
	TFIBBCDField *SprScaleAndGrpVesNomIDSCALE_SGRPVESNOM;
	TFIBBCDField *SprScaleAndGrpVesNomID_SGRPVESNOM;
	TFIBStringField *SprScaleAndGrpVesNomNAME_SGRPVESNOM;
	TpFIBDataSet *FisEd;
	TFIBStringField *FIBStringField1;
	TFIBBCDField *FIBBCDField1;
	TFIBIntegerField *FIBIntegerField1;
	TFIBStringField *FIBStringField2;
	TFIBSmallIntField *FIBSmallIntField1;
	TFIBBCDField *FIBBCDField2;
	TFIBBCDField *FIBBCDField3;
	TFIBBCDField *FIBBCDField4;
	TpFIBDataSet *SpisokEd;
	TDataSource *DataSourceSpisokEd;
	TFIBStringField *SpisokEdNAMEED;
	TFIBBCDField *SpisokEdKFED;
	TDataSource *DataSourceBasEd;
	TDataSource *DataSourceOsnEd;
	TDataSource *DataSourceFisEd;
	TFIBIntegerField *BasEdCODE_SED;
	TFIBBCDField *BasEdKF2_SED;
	TFIBBCDField *BasEdVES_SED;
	TFIBIntegerField *OsnEdCODE_SED;
	TFIBBCDField *OsnEdKF2_SED;
	TFIBBCDField *OsnEdVES_SED;
	TFIBIntegerField *FisEdCODE_SED;
	TFIBBCDField *FisEdKF2_SED;
	TFIBBCDField *FisEdVES_SED;
	TFIBDateTimeField *ElementGODEN_DO_SNOM;
	TFIBStringField *ElementSUPPLIER_NAME;
	TFIBStringField *ElementPRODUCER_NAME;
	TFIBStringField *ElementNAMENOM;
	TFIBIntegerField *ElementWARRANTY_SNOM;
	TFIBSmallIntField *ElementFL_CREDIT_SNOM;
	TFIBSmallIntField *ElementFL_TRANSPORT_SNOM;
	TFIBStringField *ElementNAME_SBRAND;
	TFIBStringField *TableARTNOM;
	TFIBLargeIntField *SpisokEdIDED;
	TFIBBCDField *TableIDNOM;
	TFIBBCDField *TableIDGRPNOM;
	TFIBBCDField *ElementPOGR_SNOM;
	TClientDataSet *ClientDataSet1;
	TFIBLargeIntField *ElementIDNOM;
	TFIBLargeIntField *ElementIDBASEDNOM;
	TFIBLargeIntField *ElementIDOSNEDNOM;
	TFIBLargeIntField *ElementIDFISED_SNOM;
	TFIBLargeIntField *ElementIDGRPNOM;
	TFIBLargeIntField *ElementIDFIRMNOM;
	TFIBLargeIntField *ElementIDCOUNTRYNOM;
	TFIBLargeIntField *ElementIDVID_SNOM;
	TFIBLargeIntField *ElementIDSUPPLIER_SNOM;
	TFIBLargeIntField *ElementIDPRODUCER_SNOM;
	TFIBLargeIntField *ElementIDBRAND_SNOM;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableAfterScroll(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprNom(TComponent* Owner);

		void OpenTable(__int64 Grp, bool All);
		AnsiString GetTextQuery(__int64 id_grp, bool all, bool check_ost,
						 __int64 id_firm, __int64 id_sklad, __int64 id_type_price,
						  bool only_ostatok, bool price_sklad,
						  bool only_change);
		int OpenElement(__int64 Id );
		bool NewElement(__int64 IdGrp);
        bool SaveElement(void);
		bool DeleteElement(__int64 Id);
		void ChancheGrp(__int64 NewGrp);

		//поиск
		__int64 FindPoCodu(int Code);
		__int64 FindPoShtrihCodu(AnsiString shtrih_cod);
		__int64 FindPoName(AnsiString name);
		int GetIndexTypePrice(void);

		__int64 GetIdBasEd(__int64 id_nom);

		__int64 IdGrp;
        bool AllElement;
		__int64 IdElement;
		__int64 IdTypePrice;

		__int64 IdFirm;
		__int64 IdSklad;
		bool CheckOst;
		bool OnlyChange;
		bool PriceSklad;
		bool OnlyOstatok;

        bool Error;
        String TextError;

		__int64 GetIDElement(String gid);
		AnsiString GetGIDElement(__int64 id);
		int PorNumberString;

		__int64 GetIdGrpNom(__int64 id_nom);

		bool ClearFlagChange(void);

		bool DeleteNom(__int64 id_nom);

		int GetCodeNom(void);
		bool CheckCode(__int64 id_nom, int code);


		void OpenSpisokEd(__int64 id_nom);
		void OpenEd(void);

		void OpenBasEd(void);
		void OpenOsnEd(void);
		void OpenFisEd(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprNom *DMSprNom;
//---------------------------------------------------------------------------
#endif
