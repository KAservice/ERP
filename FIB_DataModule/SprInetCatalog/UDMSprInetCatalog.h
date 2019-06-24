//---------------------------------------------------------------------------

#ifndef UDMSprInetCatalogH
#define UDMSprInetCatalogH
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
class TDMSprInetCatalog : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBLargeIntField *TableID_SINETCATALOG;
	TFIBLargeIntField *TableIDBASE_SINETCATALOG;
	TFIBWideStringField *TableGID_SINETCATALOG;
	TFIBWideStringField *TableNAME_SINETCATALOG;
	TFIBLargeIntField *ElementID_SINETCATALOG;
	TFIBLargeIntField *ElementIDBASE_SINETCATALOG;
	TFIBWideStringField *ElementGID_SINETCATALOG;
	TFIBWideStringField *ElementNAME_SINETCATALOG;
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TDMSprInetCatalog(TComponent* Owner);

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
		int OpenElement(__int64 id );
		bool NewElement(void);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);

		//поиск
		__int64 GetIdPoName(UnicodeString name);
		__int64 IdElement;

       int GetIndexElementaPoID(__int64 id);


};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprInetCatalog *DMSprInetCatalog;
//---------------------------------------------------------------------------
#endif
