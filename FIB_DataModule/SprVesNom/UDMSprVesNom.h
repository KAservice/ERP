//---------------------------------------------------------------------------

#ifndef UDMSprVesNomH
#define UDMSprVesNomH
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
//---------------------------------------------------------------------------
class TDMSprVesNom : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *Element;
	TFIBIntegerField *TableCODE_SVESNOM;
	TFIBBCDField *TableZNACH_PRICE;
	TIntegerField *TableRECNO;
	TFIBIntegerField *ElementCODE_SVESNOM;
	TpFIBDataSet *MaxCode;
	TpFIBDataSet *SpTPrice;
	TFIBIntegerField *MaxCodeMAXCODE;
	TFIBBCDField *SpTPriceID_TPRICE;
	TFIBBCDField *ElementID_SVESNOM;
	TFIBBCDField *ElementIDSCALE_SVESNOM;
	TFIBBCDField *ElementIDNOM_SVESNOM;
	TFIBBCDField *TableID_SVESNOM;
	TFIBBCDField *TableIDNOM_SVESNOM;
	TFIBBCDField *TableIDSCALE_SVESNOM;
	TFIBBCDField *TableIDGRP_SVESNOM;
	TFIBBCDField *ElementIDGRP_SVESNOM;
	TFIBWideStringField *TableGID_SVESNOM;
	TFIBBCDField *TableIDBASE_SVESNOM;
	TFIBWideStringField *TableNAMENOM;
	TFIBWideStringField *TableNAMEED;
	TFIBWideStringField *ElementGID_SVESNOM;
	TFIBWideStringField *SpTPriceNAME_TPRICE;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall TableNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
		__fastcall TDMSprVesNom(TComponent* Owner);

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
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv ;

		bool Error;
		AnsiString TextError;

		__int64 IdScale;
		__int64 IdGrp;
		bool AllElement;
		__int64 IdTypePrice;

		int NumberAddElement;
	   //	__int64 IdTypePrice;

		void OpenTable(__int64 id_scale, __int64 id_grp, __int64 id_type_price, bool all);
		bool SaveIsmen();
		void CancelIsmen();

		void NewElement(__int64 id_scale, __int64 id_grp);
		bool OpenElement(__int64 id);
		void DeleteElement();
		bool InsertElement(__int64 id_scale, __int64 id_grp, __int64 id_nom);

		void ChancheGrp(__int64 id_new_grp);



		__int64 FindElementPoScaleAndNom(__int64 id_scale, __int64 id_nom);

};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprVesNom *DMSprVesNom;
//---------------------------------------------------------------------------
#endif
