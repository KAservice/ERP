//---------------------------------------------------------------------------

#ifndef UDMSprGrpProduceH
#define UDMSprGrpProduceH
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
class TDMSprGrpProduce : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *pFIBQ;
	TIntegerField *TableRECNO;
	TFIBLargeIntField *TableID_SPRODUCE_GRP;
	TFIBWideStringField *TableGID_SPRODUCE_GRP;
	TFIBLargeIntField *TableIDBASE_SPRODUCE_GRP;
	TFIBWideStringField *TableNAME_SPRODUCE_GRP;
	TFIBLargeIntField *TableIDGRP_SPRODUCE_GRP;
	TFIBLargeIntField *ElementID_SPRODUCE_GRP;
	TFIBWideStringField *ElementGID_SPRODUCE_GRP;
	TFIBLargeIntField *ElementIDBASE_SPRODUCE_GRP;
	TFIBWideStringField *ElementNAME_SPRODUCE_GRP;
	TFIBLargeIntField *ElementIDGRP_SPRODUCE_GRP;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
        __fastcall TDMSprGrpProduce(TComponent* Owner);

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
extern PACKAGE TDMSprGrpProduce *DMSprGrpProduce;
//---------------------------------------------------------------------------
#endif
