//---------------------------------------------------------------------------

#ifndef UDMSprGrpBusinessOperH
#define UDMSprGrpBusinessOperH
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
class TDMSprGrpBusinessOper : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *pFIBQ;
	TFIBLargeIntField *TableID_SBUSINESS_OPER_GRP;
	TFIBWideStringField *TableGID_SBUSINESS_OPER_GRP;
	TFIBLargeIntField *TableIDBASE_SBUSINESS_OPER_GRP;
	TFIBLargeIntField *TableIDGRP_SBUSINESS_OPER_GRP;
	TFIBWideStringField *TableNAME_SBUSINESS_OPER_GRP;
	TFIBLargeIntField *ElementID_SBUSINESS_OPER_GRP;
	TFIBWideStringField *ElementGID_SBUSINESS_OPER_GRP;
	TFIBLargeIntField *ElementIDBASE_SBUSINESS_OPER_GRP;
	TFIBLargeIntField *ElementIDGRP_SBUSINESS_OPER_GRP;
	TFIBWideStringField *ElementNAME_SBUSINESS_OPER_GRP;
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprGrpBusinessOper(TComponent* Owner);


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

        void OpenTable(void);
		int OpenElement(__int64 id);
		void NewElement(__int64 id_grp);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);

        bool Error;
		UnicodeString TextError;

		__int64 GetIdPoName(UnicodeString name);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprGrpBusinessOper *DMSprGrpBusinessOper;
//---------------------------------------------------------------------------
#endif
