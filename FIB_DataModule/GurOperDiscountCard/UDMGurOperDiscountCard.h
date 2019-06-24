//---------------------------------------------------------------------------

#ifndef UDMGurOperDiscountCardH
#define UDMGurOperDiscountCardH
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
class TDMGurOperDiscountCard : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TIntegerField *TableRECNO;
	TFIBBCDField *TableSUM_GUROPER_DCARD;
	TFIBDateTimeField *TablePOS_GUROPER_DCARD;
	TFIBBCDField *ElementSUM_GUROPER_DCARD;
	TFIBDateTimeField *ElementPOS_GUROPER_DCARD;
	TpFIBQuery *Query;
	TFIBBCDField *ElementID_GUROPER_DCARD;
	TFIBBCDField *ElementIDKLIENT_GUROPER_DCARD;
	TFIBBCDField *ElementIDSKLAD_GUROPER_DCARD;
	TFIBBCDField *ElementIDCARD_GUROPER_DCARD;
	TFIBBCDField *ElementIDDOC_GUROPER_DCARD;
	TFIBBCDField *TableID_GUROPER_DCARD;
	TFIBBCDField *TableIDKLIENT_GUROPER_DCARD;
	TFIBBCDField *TableIDSKLAD_GUROPER_DCARD;
	TFIBBCDField *TableIDCARD_GUROPER_DCARD;
	TFIBBCDField *TableIDDOC_GUROPER_DCARD;
	TFIBWideStringField *TableNAMEKLIENT;
	TFIBWideStringField *TableNAMESKLAD;
	TFIBWideStringField *TableNAME_SDISCOUNT_CARD;
	TFIBWideStringField *ElementGID_GUROPER_DCARD;
	TFIBWideStringField *ElementNAMEKLIENT;
	TFIBWideStringField *ElementNAMESKLAD;
	TFIBWideStringField *ElementNAME_SDISCOUNT_CARD;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall DataModuleCreate(TObject *Sender);
private:	// User declarations

	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
		__fastcall TDMGurOperDiscountCard(TComponent* Owner);

	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;
		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;
		UnicodeString TextError;
		bool Init(void);
		int Done(void);

		void OpenTable(void);
		int OpenElement(__int64 id);  //возвращает количество элементов
		void NewElement(void);
        bool SaveElement(void);
        void DeleteElement(__int64 id);


		bool elSave;

		double GetSumPokupok(__int64 id_klient, TDateTime pos_nach);
		__int64 PoiskPoCoduDoc(__int64 code_doc);


		TDateTime PosNach;
		TDateTime PosCon;
};
//---------------------------------------------------------------------------
extern PACKAGE TDMGurOperDiscountCard *DMGurOperDiscountCard;
//---------------------------------------------------------------------------
#endif
