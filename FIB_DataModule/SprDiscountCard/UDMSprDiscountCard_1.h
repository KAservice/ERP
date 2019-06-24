//---------------------------------------------------------------------------

#ifndef UDMSprDiscountCard_1H
#define UDMSprDiscountCard_1H
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
class TDMSprDiscountCard_1 : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBIntegerField *TableCODE_SDISCOUNT_CARD;
	TFIBIntegerField *TableTYPE_SDISCOUNT_CARD;
	TFIBDateTimeField *TableNACH_SDISCOUNT_CARD;
	TFIBDateTimeField *TableCON_SDISCOUNT_CARD;
	TFIBBCDField *TablePRSK_SDISCOUNT_CARD;
	TIntegerField *TableRECNO;
	TFIBIntegerField *ElementCODE_SDISCOUNT_CARD;
	TFIBIntegerField *ElementTYPE_SDISCOUNT_CARD;
	TFIBDateTimeField *ElementNACH_SDISCOUNT_CARD;
	TFIBDateTimeField *ElementCON_SDISCOUNT_CARD;
	TFIBBCDField *ElementPRSK_SDISCOUNT_CARD;
	TFIBIntegerField *TableACT_SDISCOUNT_CARD;
	TFIBIntegerField *ElementACT_SDISCOUNT_CARD;
	TpFIBQuery *Query;
	TFIBSmallIntField *TableFL_DISC_SDISCOUNT_CARD;
	TFIBSmallIntField *TableFL_PLAT_SDISCOUNT_CARD;
	TFIBSmallIntField *ElementFL_DISC_SDISCOUNT_CARD;
	TFIBSmallIntField *ElementFL_PLAT_SDISCOUNT_CARD;
	TFIBSmallIntField *ElementFL_CREDIT_SDISCOUNT_CARD;
	TFIBLargeIntField *TableIDBASE_SDISCOUNT_CARD;
	TFIBSmallIntField *TableFL_CREDIT_SDISCOUNT_CARD;
	TFIBLargeIntField *TableIDDOG_SDISCOUNT_CARD;
	TFIBLargeIntField *TableID_SDISCOUNT_CARD;
	TFIBLargeIntField *TableIDKLIENT_SDISCOUNT_CARD;
	TFIBLargeIntField *TableIDVID_SDISCOUNT_CARD;
	TFIBLargeIntField *ElementID_SDISCOUNT_CARD;
	TFIBLargeIntField *ElementIDKLIENT_SDISCOUNT_CARD;
	TFIBLargeIntField *ElementIDVID_SDISCOUNT_CARD;
	TFIBLargeIntField *ElementIDBASE_SDISCOUNT_CARD;
	TFIBLargeIntField *ElementIDDOG_SDISCOUNT_CARD;
	TFIBWideStringField *TableNAME_SDISCOUNT_CARD;
	TFIBWideStringField *TableNAME_SVID_DCARD;
	TFIBWideStringField *TableNAMEKLIENT;
	TFIBWideStringField *ElementGID_SDISCOUNT_CARD;
	TFIBWideStringField *ElementNAME_SDISCOUNT_CARD;
	TFIBWideStringField *ElementSHCODE_SDISCOUNT_CARD;
	TFIBWideStringField *ElementNAMEKLIENT;
	TFIBWideStringField *ElementNAME_SVID_DCARD;
	TFIBWideStringField *ElementNAME_SDOG;
	TFIBWideStringField *TableSHCODE_SDISCOUNT_CARD;
	TFIBWideStringField *TableGID_SDISCOUNT_CARD;
	TFIBSmallIntField *TableSINGLE_SDISCOUNT_CARD;
	TFIBSmallIntField *ElementSINGLE_SDISCOUNT_CARD;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprDiscountCard_1(TComponent* Owner);


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

		void OpenTable(__int64 id_grp, bool all);
		int OpenElement(__int64 id);  //возвращает количество элементов
		bool NewElement(__int64 id_klient);
		bool SaveElement(void);
		void DeleteElement(__int64 id);

		__int64 IdKlient;
        bool Error;
        String TextError;

		bool elSave;
		bool AllElement;
		__int64 IdGrp;

        __int64 GetIdGrpKlient(__int64 id_discount_card);
		__int64 PoiskPoCodu(AnsiString code);
		__int64 PoiskPoShCodu(AnsiString sh_code);

		int GetCodeCard(void);

		bool CheckBarCode(__int64 id_card, AnsiString sh);
		bool CheckCode(__int64 id_card, int code);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprDiscountCard_1 *DMSprDiscountCard_1;
//---------------------------------------------------------------------------
#endif
