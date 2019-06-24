//---------------------------------------------------------------------------

#ifndef UDMSprPropertiesGrpH
#define UDMSprPropertiesGrpH
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
class TDMSprPropertiesGrp : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *pFIBQ;
	TFIBLargeIntField *TableID_SPROP_GRP;
	TFIBLargeIntField *TableIDBASE_SPROP_GRP;
	TFIBWideStringField *TableGID_SPROP_GRP;
	TFIBLargeIntField *TableIDGRP_SPROP_GRP;
	TFIBWideStringField *TableNAME_SPROP_GRP;
	TIntegerField *TableRECNO;
	TFIBLargeIntField *ElementID_SPROP_GRP;
	TFIBLargeIntField *ElementIDBASE_SPROP_GRP;
	TFIBWideStringField *ElementGID_SPROP_GRP;
	TFIBLargeIntField *ElementIDGRP_SPROP_GRP;
	TFIBWideStringField *ElementNAME_SPROP_GRP;
	TFIBWideStringField *ElementNAME_FOR_PRINT_SPROP_GRP;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
        __fastcall TDMSprPropertiesGrp(TComponent* Owner);

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

		bool Error;
		UnicodeString TextError;

		bool Init(void);
		int Done(void);


        void OpenTable(void);
		int OpenElement(__int64 id);
		void NewElement(__int64 id_grp);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);


		__int64 FindPoName(UnicodeString name);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprPropertiesGrp *DMSprPropertiesGrp;
//---------------------------------------------------------------------------
#endif
