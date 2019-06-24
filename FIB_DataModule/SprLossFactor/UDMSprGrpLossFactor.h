//---------------------------------------------------------------------------

#ifndef UDMSprGrpLossFactorH
#define UDMSprGrpLossFactorH
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
class TDMSprGrpLossFactor : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *Query;
	TIntegerField *TableRECNO;
	TFIBLargeIntField *TableID_SLOSS_FACTOR_GRP;
	TFIBWideStringField *TableGID_SLOSS_FACTOR_GRP;
	TFIBLargeIntField *TableIDBASE_SLOSS_FACTOR_GRP;
	TFIBLargeIntField *TableIDGRP_SLOSS_FACTOR_GRP;
	TFIBWideStringField *TableNAME_SLOSS_FACTOR_GRP;
	TFIBLargeIntField *ElementID_SLOSS_FACTOR_GRP;
	TFIBWideStringField *ElementGID_SLOSS_FACTOR_GRP;
	TFIBLargeIntField *ElementIDBASE_SLOSS_FACTOR_GRP;
	TFIBLargeIntField *ElementIDGRP_SLOSS_FACTOR_GRP;
	TFIBWideStringField *ElementNAME_SLOSS_FACTOR_GRP;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
        __fastcall TDMSprGrpLossFactor(TComponent* Owner);

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //функция удаления реализации интерфейса
		bool flDeleteImpl;   //надо ли удалять реализацию при удалении текущего модуля

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //интерфейс класса реализации
		GUID ClsIdImpl;				 //GUID класса реализации

		//IMainInterface
		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);



		bool OpenTable(void);
		bool OpenElement(__int64 id);
		bool NewElement(__int64 id_grp);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);

		__int64 GetIDElement(UnicodeString gid);
		UnicodeString GetGIDElement(__int64 id);
		__int64 FindPoName(UnicodeString name);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprGrpLossFactor *DMSprGrpLossFactor;
//---------------------------------------------------------------------------
#endif
