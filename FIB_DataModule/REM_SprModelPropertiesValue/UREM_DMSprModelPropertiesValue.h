//---------------------------------------------------------------------------

#ifndef UREM_DMSprModelPropertiesValueH
#define UREM_DMSprModelPropertiesValueH
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
class TREM_DMSprModelPropertiesValue : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TDataSource *DataSourceElement;
	TpFIBDataSet *Element;
	TpFIBQuery *Query;
	TFIBLargeIntField *TableID_REM_SMODEL_PROPVAL;
	TFIBLargeIntField *TableIDBASE_REM_SMODEL_PROPVAL;
	TFIBWideStringField *TableGID_REM_SMODEL_PROPVAL;
	TFIBLargeIntField *TableIDMODEL_REM_SMODEL_PROPVAL;
	TFIBLargeIntField *TableIDPROP_REM_SMODEL_PROPVAL;
	TFIBLargeIntField *TableIDPVL_REM_SMODEL_PROPVAL;
	TFIBWideStringField *TableVALTEXT_REM_SMODEL_PROPVAL;
	TFIBDateTimeField *TableISM_REM_SMODEL_PROPVAL;
	TFIBWideStringField *TableNAME_SPROP;
	TFIBWideStringField *TableNAME_FOR_PRINT_SPROP;
	TFIBWideStringField *TableNAME_SPROPVALUELIST;
	TFIBWideStringField *TableNAME_SPROP_GRP;
	TFIBWideStringField *TableNAME_FOR_PRINT_SPROP_GRP;
	TFIBLargeIntField *ElementID_REM_SMODEL_PROPVAL;
	TFIBLargeIntField *ElementIDBASE_REM_SMODEL_PROPVAL;
	TFIBWideStringField *ElementGID_REM_SMODEL_PROPVAL;
	TFIBLargeIntField *ElementIDMODEL_REM_SMODEL_PROPVAL;
	TFIBLargeIntField *ElementIDPROP_REM_SMODEL_PROPVAL;
	TFIBLargeIntField *ElementIDPVL_REM_SMODEL_PROPVAL;
	TFIBWideStringField *ElementVALTEXT_REM_SMODEL_PROPVAL;
	TFIBDateTimeField *ElementISM_REM_SMODEL_PROPVAL;
	TFIBWideStringField *ElementNAME_SPROP;
	TFIBWideStringField *ElementNAME_SPROPVALUELIST;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableNewRecord(TDataSet *DataSet);


private:	// User declarations


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TREM_DMSprModelPropertiesValue(TComponent* Owner);

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
extern PACKAGE TREM_DMSprModelPropertiesValue *REM_DMSprModelPropertiesValue;
//---------------------------------------------------------------------------
#endif
