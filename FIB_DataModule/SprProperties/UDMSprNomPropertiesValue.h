//---------------------------------------------------------------------------

#ifndef UDMSprNomPropertiesValueH
#define UDMSprNomPropertiesValueH
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
class TDMSprNomPropertiesValue : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBLargeIntField *TableID_SNOMPROPVALUE;
	TFIBLargeIntField *TableIDBASE_SNOMPROPVALUE;
	TFIBWideStringField *TableGID_SNOMPROPVALUE;
	TFIBLargeIntField *TableIDNOM_SNOMPROPVALUE;
	TFIBLargeIntField *TableIDPROP_SNOMPROPVALUE;
	TFIBLargeIntField *TableIDPROPVALLIST_SNOMPROPVALUE;
	TFIBWideStringField *TableVALTEXT_SNOMPROPVALUE;
	TFIBWideStringField *TableNAME_SPROP;
	TFIBWideStringField *TableNAME_SPROPVALUELIST;
	TDataSource *DataSourceElement;
	TpFIBDataSet *Element;
	TFIBLargeIntField *ElementID_SNOMPROPVALUE;
	TFIBLargeIntField *ElementIDBASE_SNOMPROPVALUE;
	TFIBWideStringField *ElementGID_SNOMPROPVALUE;
	TFIBLargeIntField *ElementIDNOM_SNOMPROPVALUE;
	TFIBLargeIntField *ElementIDPROP_SNOMPROPVALUE;
	TFIBLargeIntField *ElementIDPROPVALLIST_SNOMPROPVALUE;
	TFIBWideStringField *ElementVALTEXT_SNOMPROPVALUE;
	TFIBWideStringField *ElementNAME_SPROP;
	TFIBWideStringField *ElementNAME_SPROPVALUELIST;
	TFIBIntegerField *TableINDEX_SNOMPROPVALUE;
	TFIBIntegerField *ElementINDEX_SNOMPROPVALUE;
	TFIBWideStringField *TableNAME_FOR_PRINT_SPROP;
	TFIBWideStringField *TableNAME_SPROP_GRP;
	TFIBWideStringField *TableNAME_FOR_PRINT_SPROP_GRP;
	TFIBSmallIntField *TableADD1_SNOMPROPVALUE;
	TFIBSmallIntField *TableADD2_SNOMPROPVALUE;
	TFIBSmallIntField *TableADD3_SNOMPROPVALUE;
	TFIBSmallIntField *TableADD4_SNOMPROPVALUE;
	TFIBSmallIntField *TableADD5_SNOMPROPVALUE;
	TFIBSmallIntField *ElementADD1_SNOMPROPVALUE;
	TFIBSmallIntField *ElementADD2_SNOMPROPVALUE;
	TFIBSmallIntField *ElementADD3_SNOMPROPVALUE;
	TFIBSmallIntField *ElementADD4_SNOMPROPVALUE;
	TFIBSmallIntField *ElementADD5_SNOMPROPVALUE;
	TpFIBQuery *Query;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableNewRecord(TDataSet *DataSet);


private:	// User declarations


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TDMSprNomPropertiesValue(TComponent* Owner);

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


		__int64 IdNom;
		__int64 IdElement;

		void OpenTable(__int64 id_nom);
		bool NewElement(__int64 id_nom);

		int OpenElement(__int64 id );
		bool SaveElement(void);
		bool DeleteElement(__int64 id);

		__int64 GetIdPoIdNomIdProp(__int64 id_nom, __int64 id_prop);

};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprNomPropertiesValue *DMSprNomPropertiesValue;
//---------------------------------------------------------------------------
#endif
