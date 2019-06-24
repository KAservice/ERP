//---------------------------------------------------------------------------

#ifndef UDMSprPropertiesH
#define UDMSprPropertiesH
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
class TDMSprProperties : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBLargeIntField *TableID_SPROP;
	TFIBLargeIntField *TableIDBASE_SPROP;
	TFIBWideStringField *TableGID_SPROP;
	TFIBLargeIntField *TableIDGRP_SPROP;
	TFIBWideStringField *TableNAME_SPROP;
	TFIBSmallIntField *TableFL_TYPE_SPROP;
	TIntegerField *TableRECNO;
	TFIBLargeIntField *ElementID_SPROP;
	TFIBLargeIntField *ElementIDBASE_SPROP;
	TFIBWideStringField *ElementGID_SPROP;
	TFIBLargeIntField *ElementIDGRP_SPROP;
	TFIBWideStringField *ElementNAME_SPROP;
	TFIBSmallIntField *ElementFL_TYPE_SPROP;
	TpFIBQuery *Query;
	TFIBWideStringField *ElementNAME_FOR_PRINT_SPROP;
	TFIBWideStringField *TableNAME_FOR_PRINT_SPROP;
        void __fastcall DataModuleDestroy(TObject *Sender);



private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
        __fastcall TDMSprProperties(TComponent* Owner);

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


		void OpenTable(__int64 id_grp, bool all);
		UnicodeString GetTextQuery(__int64 id_grp, bool all);
		int OpenElement(__int64 id );
		bool NewElement(__int64 id_grp);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);
		void ChancheGrp(__int64 id_new_grp,__int64 id_prop);

		//поиск
		__int64 FindPoName(UnicodeString name);


		__int64 IdGrp;
        bool AllElement;
		__int64 IdElement;

		__int64 GetIdGrp(__int64 id_el);

};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprProperties *DMSprProperties;
//---------------------------------------------------------------------------
#endif
