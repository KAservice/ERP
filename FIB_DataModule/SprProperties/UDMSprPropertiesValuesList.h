//---------------------------------------------------------------------------

#ifndef UDMSprPropertiesValuesListH
#define UDMSprPropertiesValuesListH
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
class TDMSprPropertiesValuesList : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *Query;
	TFIBLargeIntField *TableID_SPROPVALUELIST;
	TFIBLargeIntField *TableIDBASE_SPROPVALUELIST;
	TFIBWideStringField *TableGID_SPROPVALUELIST;
	TFIBLargeIntField *TableIDPROP_SPROPVALUELIST;
	TFIBWideStringField *TableNAME_SPROPVALUELIST;
	TFIBLargeIntField *ElementID_SPROPVALUELIST;
	TFIBLargeIntField *ElementIDBASE_SPROPVALUELIST;
	TFIBWideStringField *ElementGID_SPROPVALUELIST;
	TFIBLargeIntField *ElementIDPROP_SPROPVALUELIST;
	TFIBWideStringField *ElementNAME_SPROPVALUELIST;
	TIntegerField *TableRECNO;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations


bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


public:		// User declarations
		__fastcall TDMSprPropertiesValuesList(TComponent* Owner);

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




		void OpenTable(__int64 id_prop);
		int OpenElement(__int64 id);  //возвращает количество элементов
		bool NewElement(__int64 id_prop);
		bool SaveElement(void);
		bool DeleteElement(__int64 id);


};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprPropertiesValuesList *DMSprPropertiesValuesList;
//---------------------------------------------------------------------------
#endif
