//---------------------------------------------------------------------------

#ifndef UREM_DMSprProducerModelPropertiesValueH
#define UREM_DMSprProducerModelPropertiesValueH
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
class TREM_DMSprProducerModelPropertiesValue : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TDataSource *DataSourceElement;
	TpFIBDataSet *Element;
	TpFIBQuery *Query;
	TFIBLargeIntField *TableID_REM_SPRMOD_PRVAL;
	TFIBLargeIntField *TableIDBASE_REM_SPRMOD_PRVAL;
	TFIBWideStringField *TableGID_REM_SPRMOD_PRVAL;
	TFIBLargeIntField *TableIDPRMODEL_REM_SPRMOD_PRVAL;
	TFIBLargeIntField *TableIDPROP_REM_SPRMOD_PRVAL;
	TFIBLargeIntField *TableIDPVL_REM_SPRMOD_PRVAL;
	TFIBWideStringField *TableVALTEXT_REM_SPRMOD_PRVAL;
	TFIBDateTimeField *TableISM_REM_SPRMOD_PRVAL;
	TFIBWideStringField *TableNAME_SPROP;
	TFIBWideStringField *TableNAME_FOR_PRINT_SPROP;
	TFIBWideStringField *TableNAME_SPROPVALUELIST;
	TFIBWideStringField *TableNAME_SPROP_GRP;
	TFIBWideStringField *TableNAME_FOR_PRINT_SPROP_GRP;
	TFIBLargeIntField *ElementID_REM_SPRMOD_PRVAL;
	TFIBLargeIntField *ElementIDBASE_REM_SPRMOD_PRVAL;
	TFIBWideStringField *ElementGID_REM_SPRMOD_PRVAL;
	TFIBLargeIntField *ElementIDPRMODEL_REM_SPRMOD_PRVAL;
	TFIBLargeIntField *ElementIDPROP_REM_SPRMOD_PRVAL;
	TFIBLargeIntField *ElementIDPVL_REM_SPRMOD_PRVAL;
	TFIBWideStringField *ElementVALTEXT_REM_SPRMOD_PRVAL;
	TFIBDateTimeField *ElementISM_REM_SPRMOD_PRVAL;
	TFIBWideStringField *ElementNAME_SPROP;
	TFIBWideStringField *ElementNAME_SPROPVALUELIST;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableNewRecord(TDataSet *DataSet);


private:	// User declarations


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TREM_DMSprProducerModelPropertiesValue(TComponent* Owner);

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
        bool Error;
		UnicodeString TextError;


		bool Init(void);
		int Done(void);


		__int64 IdOwner;
		__int64 IdElement;

		void OpenTable(__int64 id_owner);
		bool NewElement(__int64 id_owner);

		int OpenElement(__int64 id );
		bool SaveElement(void);
		bool DeleteElement(__int64 id);



};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMSprProducerModelPropertiesValue *REM_DMSprProducerModelPropertiesValue;
//---------------------------------------------------------------------------
#endif
