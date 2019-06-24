//---------------------------------------------------------------------------

#ifndef UDMSprPriceScheduleH
#define UDMSprPriceScheduleH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"

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
class TDMSprPriceSchedule : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *TPrice;
	TpFIBQuery *Query;
	TpFIBDataSet *SpisokEd;
	TFIBBCDField *SpisokEdIDED;
	TFIBBCDField *SpisokEdKFED;
	TDataSource *DataSourceSpisokEd;
	TDataSource *DataSourceTypePrice;
	TFIBBCDField *TableID_SPRICE_SCHEDULE;
	TFIBBCDField *TableIDBASE_SPRICE_SCHEDULE;
	TFIBBCDField *TableIDNOM_SPRICE_SCHEDULE;
	TFIBBCDField *TableIDTYPE_SPRICE_SCHEDULE;
	TFIBBCDField *TableIDED_SPRICE_SCHEDULE;
	TFIBBCDField *TableVALUE_SPRICE_SCHEDULE;
	TFIBDateTimeField *TablePOS_SPRICE_SCHEDULE;
	TFIBBCDField *ElementID_SPRICE_SCHEDULE;
	TFIBBCDField *ElementIDBASE_SPRICE_SCHEDULE;
	TFIBBCDField *ElementIDNOM_SPRICE_SCHEDULE;
	TFIBBCDField *ElementIDTYPE_SPRICE_SCHEDULE;
	TFIBBCDField *ElementIDED_SPRICE_SCHEDULE;
	TFIBBCDField *ElementVALUE_SPRICE_SCHEDULE;
	TFIBDateTimeField *ElementPOS_SPRICE_SCHEDULE;
	TFIBWideStringField *TableNAME_TPRICE;
	TFIBWideStringField *SpisokEdNAMEED;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableAfterInsert(TDataSet *DataSet);
	void __fastcall TableNewRecord(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprPriceSchedule(TComponent* Owner);

	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IkanUnknown * InterfaceImpl; //интерфейс класса реализации
	GUID ClsIdImpl;				 //GUID класса реализации
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;

		bool Init(void);
		int Done(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		void OpenTable(__int64 id_nom);
        bool SaveIsmen(void);
        void CancelIsmen(void);
		int OpenElement(__int64 id);
        void NewElement(void);
        bool SaveElement(void);
		void DeleteElement(__int64 id);

		bool Error;
		String TextError;
		__int64 IdNom;
		__int64 IdTypePrice;


	   void UpdateSpisokEd(__int64 id_nom);
	   __int64 IdBasEd;

	   double GetValuePrice(__int64 id_nom,
							__int64 id_type_price,
							__int64 id_ed,
							TDateTime pos);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprPriceSchedule *DMSprPriceSchedule;
//---------------------------------------------------------------------------
#endif
