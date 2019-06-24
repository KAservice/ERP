//---------------------------------------------------------------------------

#ifndef UDMSprNomH
#define UDMSprNomH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"


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
	TpFIBDataSet *BasEd;
	TpFIBDataSet *OsnEd;
	TFIBBCDField *BasEdKFED;
	TFIBIntegerField *BasEdTSHED;
	TFIBSmallIntField *BasEdNEISPED;
	TFIBBCDField *OsnEdKFED;
	TFIBIntegerField *OsnEdTSHED;
	TFIBSmallIntField *OsnEdNEISPED;
	TpFIBDataSet *IBQSprGrpBV;
	TpFIBDataSet *SpTPrice;
	TpFIBDataSet *Code;
	TFIBIntegerField *CodeMAXCODE;
	TFIBIntegerField *ElementTNOM;
	TFIBIntegerField *ElementCODENOM;
	TFIBIntegerField *ElementSTNDSNOM;
	TFIBBCDField *ElementZNACH_PRICE;
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
	TFIBBCDField *ElementSKIDKA1_SNOM;
	TFIBBCDField *ElementSKIDKA2_SNOM;
	TFIBBCDField *ElementSKIDKA3_SNOM;
	TFIBSmallIntField *ElementTYPESRGODN_SNOM;
	TFIBSmallIntField *ElementSRGODN_SNOM;
	TpFIBDataSet *SprScaleAndGrpVesNom;
	TFIBBCDField *SprScaleAndGrpVesNomIDSCALE_SGRPVESNOM;
	TFIBBCDField *SprScaleAndGrpVesNomID_SGRPVESNOM;
	TpFIBDataSet *FisEd;
	TFIBBCDField *FIBBCDField1;
	TFIBIntegerField *FIBIntegerField1;
	TFIBSmallIntField *FIBSmallIntField1;
	TFIBBCDField *FIBBCDField2;
	TFIBBCDField *FIBBCDField3;
	TFIBBCDField *FIBBCDField4;
	TpFIBDataSet *SpisokEd;
	TDataSource *DataSourceSpisokEd;
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
	TFIBIntegerField *ElementWARRANTY_SNOM;
	TFIBSmallIntField *ElementFL_CREDIT_SNOM;
	TFIBSmallIntField *ElementFL_TRANSPORT_SNOM;
	TFIBLargeIntField *SpisokEdIDED;
	TFIBBCDField *ElementPOGR_SNOM;
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
	TFIBWideStringField *ElementNAMENOM;
	TFIBWideStringField *ElementFNAMENOM;
	TFIBWideStringField *ElementKRNAMENOM;
	TFIBWideStringField *ElementARTNOM;
	TFIBWideStringField *ElementDESCR_SNOM;
	TFIBWideStringField *ElementGTDNOM;
	TFIBLargeIntField *ElementIDBASE_SNOM;
	TFIBLargeIntField *ElementIDEXT_DOUT_SNOM;
	TFIBLargeIntField *ElementIDEXT_BASE_SNOM;
	TFIBWideStringField *ElementNAMEFIRM;
	TFIBWideStringField *ElementNAME_SCOUNTRY;
	TFIBWideStringField *ElementNAME_SVIDNOM;
	TFIBWideStringField *ElementSUPPLIER_NAME;
	TFIBWideStringField *ElementPRODUCER_NAME;
	TFIBWideStringField *ElementNAME_SBRAND;
	TFIBWideStringField *SpTPriceNAME_TPRICE;
	TFIBWideStringField *IBQSprGrpBVNAMEPOD;
	TFIBWideStringField *IBQSprGrpBVNAME_GBVNOM;
	TFIBWideStringField *SprScaleAndGrpVesNomNAME_SSCALE;
	TFIBWideStringField *SprScaleAndGrpVesNomNAME_SGRPVESNOM;
	TFIBWideStringField *BasEdNAMEED;
	TFIBWideStringField *BasEdSHED;
	TFIBWideStringField *OsnEdNAMEED;
	TFIBWideStringField *OsnEdSHED;
	TFIBWideStringField *FisEdNAMEED;
	TFIBWideStringField *FisEdSHED;
	TFIBWideStringField *SpisokEdNAMEED;
	TFIBWideStringField *ElementGID_SNOM;
	TFIBSmallIntField *ElementFL_ADD_IN_SOBORUD_SNOM;
	TFIBSmallIntField *ElementFL_DVREG_SNOM;
	TFIBLargeIntField *TableIDNOM;
	TFIBWideStringField *TableARTNOM;
	TFIBIntegerField *TableCODENOM;
	TFIBSmallIntField *TableTNOM;
	TFIBWideStringField *TableNAMENOM;
	TFIBWideStringField *TableNAMEED;
	TFIBBCDField *TableZNACH_PRICE;
	TFIBLargeIntField *TableIDGRPNOM;
	TFIBLargeIntField *TableID_SNOMINETCAT;
	TFIBBCDField *TableSUMKOL;
	TFIBWideStringField *TableSHED;
	TFIBBCDField *TableREM_OST;
	TFIBLargeIntField *TableIDFIRM;
	TFIBWideStringField *TableNAMEFIRM;
	TFIBLargeIntField *TableIDSKLAD;
	TFIBWideStringField *TableNAMESKLAD;
	TFIBLargeIntField *TableIDTNOM;
	TFIBWideStringField *TableNAME_STNOM;
	TFIBLargeIntField *TableIDED;
	TFIBBCDField *TableOUT_PRICE_SKLAD;
	TFIBBCDField *TableOUT_KFED;
	TFIBBCDField *TableOUT_KF2ED;
	TFIBLargeIntField *TableOUT_IDMHRAN;
	TFIBWideStringField *TableOUT_NAME_MHRAN;
	TFIBLargeIntField *TableOUT_IDMHRAN_REM;
	TFIBWideStringField *TableOUT_NAME_MHRAN_REM;
	TFIBLargeIntField *ElementIDVIDIMAGENABOR_SNOM;
	TFIBLargeIntField *ElementIDPROPNABOR_SNOM;
	TFIBLargeIntField *ElementIDDEPARTMENT_SNOM;
	TFIBWideStringField *ElementNAME_SDEPARTMENT;
	TFIBWideStringField *ElementNAME_SPROPNABOR;
	TFIBWideStringField *ElementNAME_SVIDIMAGE_NABOR;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableAfterScroll(TDataSet *DataSet);



private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		UnicodeString GetTextQuery(__int64 id_grp, bool all, bool check_ost,
						 __int64 id_firm, __int64 id_sklad, __int64 id_type_price,
						  bool only_ostatok, bool price_sklad,
						  bool only_change,__int64 id_inet_catalog);
public:		// User declarations
        __fastcall TDMSprNom(TComponent* Owner);

	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;
	IkanUnknown * InterfaceImpl; //интерфейс класса реализации
	GUID ClsIdImpl;				 //GUID класса реализации

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;

		bool Init(void);
		int Done(void);

        bool Error;
		String TextError;

        //Текущий интерфейс
		void OpenTable(__int64 Grp, bool All);

		int OpenElement(__int64 Id );
		bool NewElement(__int64 IdGrp);
        bool SaveElement(void);
		bool DeleteElement(__int64 Id);
		void ChancheGrp(__int64 NewGrp,__int64 id_nom);

		//поиск
		__int64 FindPoCodu(int Code);
		__int64 FindPoShtrihCodu(AnsiString shtrih_cod);
		__int64 FindPoName(AnsiString name);
		__int64 FindPoArtikulu(UnicodeString artikul);
		int GetIndexTypePrice(void);

		__int64 GetIdBasEd(__int64 id_nom);

		__int64 IdGrp;
        bool AllElement;
		__int64 IdElement;
		__int64 IdTypePrice;

		__int64 IdFirm;
		__int64 IdSklad;
		__int64 IdInetCatalog;
		int CheckOst;             //0 без остаткв, 1- основной, 2- ремонт
		bool OnlyChange;
		bool PriceSklad;
		bool OnlyOstatok;



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
