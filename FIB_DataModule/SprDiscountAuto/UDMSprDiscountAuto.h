//---------------------------------------------------------------------------

#ifndef UDMSprDiscountAutoH
#define UDMSprDiscountAutoH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"

//----------------------------------------------------------------------------
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
class TDMSprDiscountAuto : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *pFIBQ;
	TpFIBDataSet *TableDiscountAuto;
	TFIBLargeIntField *ElementID_SDISCOUNT_AUTO;
	TFIBWideStringField *ElementGID_SDISCOUNT_AUTO;
	TFIBWideStringField *ElementNAME_SDISCOUNT_AUTO;
	TFIBSmallIntField *ElementACT_SDISCOUNT_AUTO;
	TFIBDateTimeField *ElementNACH_SDISCOUNT_AUTO;
	TFIBDateTimeField *ElementCON_SDISCOUNT_AUTO;
	TFIBBCDField *ElementPRSK_SDISCOUNT_AUTO;
	TFIBBCDField *ElementSUM_SDISCOUNT_AUTO;
	TFIBTimeField *ElementTIME_NACH_SDISCOUNT_AUTO;
	TFIBTimeField *ElementTIME_CON_SDISCOUNT_AUTO;
	TFIBSmallIntField *ElementDAY_SDISCOUNT_AUTO;
	TFIBLargeIntField *ElementIDVIDNOM_SDISCOUNT_AUTO;
	TFIBLargeIntField *ElementIDSKLAD_SDISCOUNT_AUTO;
	TFIBLargeIntField *ElementIDBASE_SDISCOUNT_AUTO;
	TFIBSmallIntField *ElementNUM_SKIDKI_SDISCOUNT_AUTO;
	TFIBLargeIntField *ElementIDGRPNOM_SDISCOUNT_AUTO;
	TFIBIntegerField *ElementTYPE_ACTION_SDISCOUNT_AUTO;
	TFIBWideStringField *ElementNAMESKLAD;
	TFIBWideStringField *ElementNAMEGN;
	TFIBWideStringField *ElementNAME_SVIDNOM;
	TFIBWideStringField *ElementMESSAGE_SDISCOUNT_AUTO;
	TFIBLargeIntField *TableDiscountAutoID_SDISCOUNT_AUTO;
	TFIBWideStringField *TableDiscountAutoGID_SDISCOUNT_AUTO;
	TFIBWideStringField *TableDiscountAutoNAME_SDISCOUNT_AUTO;
	TFIBSmallIntField *TableDiscountAutoACT_SDISCOUNT_AUTO;
	TFIBDateTimeField *TableDiscountAutoNACH_SDISCOUNT_AUTO;
	TFIBDateTimeField *TableDiscountAutoCON_SDISCOUNT_AUTO;
	TFIBBCDField *TableDiscountAutoPRSK_SDISCOUNT_AUTO;
	TFIBBCDField *TableDiscountAutoSUM_SDISCOUNT_AUTO;
	TFIBTimeField *TableDiscountAutoTIME_NACH_SDISCOUNT_AUTO;
	TFIBTimeField *TableDiscountAutoTIME_CON_SDISCOUNT_AUTO;
	TFIBSmallIntField *TableDiscountAutoDAY_SDISCOUNT_AUTO;
	TFIBLargeIntField *TableDiscountAutoIDVIDNOM_SDISCOUNT_AUTO;
	TFIBLargeIntField *TableDiscountAutoIDSKLAD_SDISCOUNT_AUTO;
	TFIBLargeIntField *TableDiscountAutoIDBASE_SDISCOUNT_AUTO;
	TFIBSmallIntField *TableDiscountAutoNUM_SKIDKI_SDISCOUNT_AUTO;
	TFIBLargeIntField *TableDiscountAutoIDGRPNOM_SDISCOUNT_AUTO;
	TFIBIntegerField *TableDiscountAutoTYPE_ACTION_SDISCOUNT_AUTO;
	TFIBWideStringField *TableDiscountAutoMESSAGE_SDISCOUNT_AUTO;
	TFIBLargeIntField *TableID_SDISCOUNT_AUTO;
	TFIBWideStringField *TableGID_SDISCOUNT_AUTO;
	TFIBWideStringField *TableNAME_SDISCOUNT_AUTO;
	TFIBSmallIntField *TableACT_SDISCOUNT_AUTO;
	TFIBDateTimeField *TableNACH_SDISCOUNT_AUTO;
	TFIBDateTimeField *TableCON_SDISCOUNT_AUTO;
	TFIBBCDField *TablePRSK_SDISCOUNT_AUTO;
	TFIBBCDField *TableSUM_SDISCOUNT_AUTO;
	TFIBTimeField *TableTIME_NACH_SDISCOUNT_AUTO;
	TFIBTimeField *TableTIME_CON_SDISCOUNT_AUTO;
	TFIBSmallIntField *TableDAY_SDISCOUNT_AUTO;
	TFIBLargeIntField *TableIDVIDNOM_SDISCOUNT_AUTO;
	TFIBLargeIntField *TableIDSKLAD_SDISCOUNT_AUTO;
	TFIBLargeIntField *TableIDBASE_SDISCOUNT_AUTO;
	TFIBSmallIntField *TableNUM_SKIDKI_SDISCOUNT_AUTO;
	TFIBLargeIntField *TableIDGRPNOM_SDISCOUNT_AUTO;
	TFIBIntegerField *TableTYPE_ACTION_SDISCOUNT_AUTO;
	TFIBWideStringField *TableMESSAGE_SDISCOUNT_AUTO;
	TFIBWideStringField *TableNAMESKLAD;
	TFIBWideStringField *TableNAMEGN;
	TFIBWideStringField *TableNAME_SVIDNOM;
	TIntegerField *TableRECNO;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
        __fastcall TDMSprDiscountAuto(TComponent* Owner);

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
		UnicodeString TextError;
		bool Init(void);
		int Done(void);





        void OpenTable(void);
		int OpenElement(__int64 Id);
        void NewElement(void);
        bool SaveElement(void);
        void CloseElement(void);
		void DeleteElement(__int64 Id);

        __int64 GetIDElement(UnicodeString gid);
		AnsiString GetGIDElement(__int64 id);


		int GetIndexElementaPoID(__int64 id);

		void OpenTableDiscountAuto(__int64 id_sklad);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprDiscountAuto *DMSprDiscountAuto;
//---------------------------------------------------------------------------
#endif
