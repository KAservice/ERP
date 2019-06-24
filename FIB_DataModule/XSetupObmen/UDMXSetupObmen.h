//---------------------------------------------------------------------------

#ifndef UDMXSetupObmenH
#define UDMXSetupObmenH
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
class TDMXSetupObmen : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBBCDField *TableID_XSETUP_OBMEN;
	TFIBBCDField *TableIDBASE_OBMEN_XSETUP_OBMEN;
	TFIBBCDField *TableIDTISM_XSETUP_OBMEN;
	TFIBSmallIntField *TableALLDOC_XSETUP_OBMEN;
	TFIBSmallIntField *TableOUTNAC_XSETUP_OBMEN;
	TFIBSmallIntField *TableOUTZPRICE_XSETUP_OBMEN;
	TFIBSmallIntField *TableNOEDIT_XSETUP_OBMEN;
	TFIBBCDField *TableIDBASE_XSETUP_OBMEN;
	TpFIBDataSet *Element;
	TFIBBCDField *ElementID_XSETUP_OBMEN;
	TFIBBCDField *ElementIDBASE_OBMEN_XSETUP_OBMEN;
	TFIBBCDField *ElementIDTISM_XSETUP_OBMEN;
	TFIBSmallIntField *ElementALLDOC_XSETUP_OBMEN;
	TFIBSmallIntField *ElementOUTNAC_XSETUP_OBMEN;
	TFIBSmallIntField *ElementOUTZPRICE_XSETUP_OBMEN;
	TFIBSmallIntField *ElementNOEDIT_XSETUP_OBMEN;
	TFIBBCDField *ElementIDBASE_XSETUP_OBMEN;
	TDataSource *DataSourceElement;
	TpFIBDataSet *BaseForObmen;
	TpFIBDataSet *TypePriceForObmen;
	TDataSource *DataSourceBaseForObmen;
	TDataSource *DataSourceTypePriceForObmen;
	TFIBBCDField *BaseForObmenID_XBASE_FOR_OBMEN;
	TFIBBCDField *BaseForObmenIDBASE_OBMEN_XBASE_FOR_OBMEN;
	TFIBBCDField *BaseForObmenIDBASE_OBJECT_XBASE_FOR_OBMEN;
	TFIBBCDField *BaseForObmenIDBASE_XBASE_FOR_OBMEN;
	TFIBBCDField *TypePriceForObmenID_XTPRICE_FOR_OBMEN;
	TFIBBCDField *TypePriceForObmenIDBASE_OBMEN_XTPRICE_FOR_OBMEN;
	TFIBBCDField *TypePriceForObmenIDTPRICE_XTPRICE_FOR_OBMEN;
	TFIBBCDField *TypePriceForObmenIDBASE_XTPRICE_FOR_OBMEN;
	TIntegerField *TableRECNO;
	TFIBBCDField *ElementIDFIRST_DO_XSETUP_OBMEN;
	TFIBIntegerField *ElementOPER_XSETUP_OBMEN;
	TFIBWideStringField *TableNAME_SINFBASE_OBMEN;
	TFIBWideStringField *ElementNAME_SINFBASE_OBMEN;
	TFIBWideStringField *BaseForObmenNAME_SINFBASE_OBMEN;
	TFIBWideStringField *TypePriceForObmenNAME_TPRICE;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall BaseForObmenNewRecord(TDataSet *DataSet);
	void __fastcall TypePriceForObmenNewRecord(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMXSetupObmen(TComponent* Owner);

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
	UnicodeString TextError;
	bool Init(void);
	int Done(void);
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		__int64 IdBase;
        bool AllElement;
		void OpenTable(void);
		bool OpenElement(__int64 id_base);
		void NewElement(void);
		bool SaveElement(void);
		bool DeleteElement(__int64 id_base);
		bool AddBase(__int64 id_base, AnsiString name_base);
		bool AddTypePrice(__int64 id_type_price, AnsiString name_type_price);
		bool DeleteBase(void);
		bool DeleteTypePrice(void);





};
//---------------------------------------------------------------------------
extern PACKAGE TDMXSetupObmen *DMXSetupObmen;
//---------------------------------------------------------------------------
#endif
