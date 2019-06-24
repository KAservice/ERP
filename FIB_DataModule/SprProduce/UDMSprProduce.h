//---------------------------------------------------------------------------

#ifndef UDMSprProduceH
#define UDMSprProduceH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"


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
#include <DBClient.hpp>
//---------------------------------------------------------------------------
class TDMSprProduce : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *Query;
	TFIBLargeIntField *ElementID_SPRODUCE;
	TFIBWideStringField *ElementGID_SPRODUCE;
	TFIBLargeIntField *ElementIDBASE_SPRODUCE;
	TFIBLargeIntField *ElementIDGRP_SPRODUCE;
	TFIBWideStringField *ElementNAME_SPRODUCE;
	TFIBWideStringField *ElementCODE_SPRODUCE;
	TFIBBCDField *ElementBELKI_SPRODUCE;
	TFIBBCDField *ElementGIRI_SPRODUCE;
	TFIBBCDField *ElementUGL_SPRODUCE;
	TFIBWideStringField *ElementCOMMENT_SPRODUCE;
	TFIBLargeIntField *TableID_SPRODUCE;
	TFIBWideStringField *TableGID_SPRODUCE;
	TFIBLargeIntField *TableIDBASE_SPRODUCE;
	TFIBLargeIntField *TableIDGRP_SPRODUCE;
	TFIBWideStringField *TableNAME_SPRODUCE;
	TFIBWideStringField *TableCODE_SPRODUCE;
	TFIBBCDField *TableBELKI_SPRODUCE;
	TFIBBCDField *TableGIRI_SPRODUCE;
	TFIBBCDField *TableUGL_SPRODUCE;
	TFIBWideStringField *TableCOMMENT_SPRODUCE;
        void __fastcall DataModuleDestroy(TObject *Sender);



private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


public:		// User declarations
        __fastcall TDMSprProduce(TComponent* Owner);

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


		bool OpenTable(__int64 id_grp, bool all);
		UnicodeString GetTextQuery(__int64 id_grp, bool all);
		bool OpenElement(__int64 id );
		bool NewElement(__int64 id_grp);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);
		bool ChancheGrp(__int64 id_new_grp,__int64 id_el);

		//поиск
		__int64 FindPoName(UnicodeString name);

		__int64 IdGrp;
        bool AllElement;
		__int64 IdElement;

		__int64 GetIDElement(UnicodeString gid);
		UnicodeString GetGIDElement(__int64 id);

		__int64 GetIdGrp(__int64 id_el);

};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprProduce *DMSprProduce;
//---------------------------------------------------------------------------
#endif
