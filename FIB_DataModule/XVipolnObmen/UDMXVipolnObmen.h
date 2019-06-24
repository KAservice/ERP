//---------------------------------------------------------------------------

#ifndef UDMXVipolnObmenH
#define UDMXVipolnObmenH
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
class TDMXVipolnObmen : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *Query;
	TFIBLargeIntField *TableID_XVIPOLN_OBMEN;
	TFIBLargeIntField *TableIDBASE_XVIPOLN_OBMEN;
	TFIBLargeIntField *TableIDINFBASE_XVIPOLN_OBMEN;
	TFIBDateTimeField *TablePOS_ZAGR_XVIPOLN_OBMEN;
	TFIBDateTimeField *TablePOS_VIGR_XVIPOLN_OBMEN;
	TFIBWideStringField *TableNAME_SINFBASE_OBMEN;
	TFIBSmallIntField *TableNOACT_SINFBASE_OBMEN;
	TFIBLargeIntField *ElementID_XVIPOLN_OBMEN;
	TFIBLargeIntField *ElementIDBASE_XVIPOLN_OBMEN;
	TFIBLargeIntField *ElementIDINFBASE_XVIPOLN_OBMEN;
	TFIBDateTimeField *ElementPOS_ZAGR_XVIPOLN_OBMEN;
	TFIBDateTimeField *ElementPOS_VIGR_XVIPOLN_OBMEN;
	TFIBWideStringField *ElementNAME_SINFBASE_OBMEN;
	TFIBSmallIntField *ElementNOACT_SINFBASE_OBMEN;
        void __fastcall DataModuleDestroy(TObject *Sender);



private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
        __fastcall TDMXVipolnObmen(TComponent* Owner);

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
		UnicodeString GetTextQuery(__int64 id_grp, bool all);
		int OpenElement(__int64 id );
		bool NewElement(void);
		bool SaveElement(void);
		bool DeleteElement(__int64 id);
		void ChancheGrp(__int64 id_new_grp,__int64 id_element);

		//поиск
		__int64 FindPoName(UnicodeString name);
        __int64 FindPoIdBase(__int64 id_base);

		__int64 IdGrp;
        bool AllElement;
		__int64 IdElement;

		__int64 GetIdGrp(__int64 id_el);

};
//---------------------------------------------------------------------------
extern PACKAGE TDMXVipolnObmen *DMXVipolnObmen;
//---------------------------------------------------------------------------
#endif
