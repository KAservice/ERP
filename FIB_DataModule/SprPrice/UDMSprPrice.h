//---------------------------------------------------------------------------

#ifndef UDMSprPriceH
#define UDMSprPriceH
//---------------------------------------------------------------------------


#include "IDMFibConnection.h"
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
class TDMSprPrice : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBBCDField *TableZNACH_PRICE;
	TFIBBCDField *ElementZNACH_PRICE;
	TpFIBDataSet *TPrice;
	TFIBSmallIntField *TableFL_CHANGE_PRICE;
	TFIBSmallIntField *ElementFL_CHANGE_PRICE;
	TpFIBQuery *pFIBQ;
	TFIBBCDField *ElementID_PRICE;
	TFIBBCDField *ElementIDNOM_PRICE;
	TFIBBCDField *ElementIDTYPE_PRICE;
	TFIBBCDField *ElementIDED_SPRICE;
	TpFIBDataSet *SpisokEd;
	TFIBBCDField *SpisokEdKFED;
	TDataSource *DataSourceSpisokEd;
	TFIBLargeIntField *TPriceID_TPRICE;
	TFIBLargeIntField *TableID_PRICE;
	TFIBLargeIntField *TableIDNOM_PRICE;
	TFIBLargeIntField *TableIDTYPE_PRICE;
	TFIBLargeIntField *TableIDED_SPRICE;
	TFIBLargeIntField *SpisokEdIDED;
	TFIBWideStringField *TableGID_SPRICE;
	TFIBLargeIntField *TableIDBASE_SPRICE;
	TFIBWideStringField *TableNAME_TPRICE;
	TFIBWideStringField *ElementGID_SPRICE;
	TFIBWideStringField *TPriceNAME_TPRICE;
	TFIBWideStringField *SpisokEdNAMEED;
	TStringField *TableNAMETPRICE;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableAfterInsert(TDataSet *DataSet);
	void __fastcall TableNewRecord(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
		__fastcall TDMSprPrice(TComponent* Owner);

	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;
		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;

		bool Init(void);
		int Done(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		void OpenTable(__int64 IdNom);
        bool SaveIsmen(void);
        void CancelIsmen(void);
		int OpenElement(__int64 Id);
        void NewElement(void);
        bool SaveElement(void);
        void DeleteElement(__int64 Id);
		__int64 FindElement(__int64 idTypePrice, __int64 idNom);
		__int64 FindElementPoEd(__int64 idTypePrice, __int64 idNom, __int64 id_ed);

		bool Error;
		String TextError;
		__int64 IdNom;
		__int64 IdTypePrice;

		double GetValuePrice(__int64 id_type_price,
							__int64 id_nom,
							__int64 id_ed,
							double kf_ed,
							__int64 id_bas_ed);
	   void UpdateSpisokEd(__int64 id_nom);
	   __int64 IdBasEd;
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprPrice *DMSprPrice;
//---------------------------------------------------------------------------
#endif
