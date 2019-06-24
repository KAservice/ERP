//---------------------------------------------------------------------------

#ifndef UDMSprBusinessOperH
#define UDMSprBusinessOperH
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
class TDMSprBusinessOper : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBLargeIntField *TableID_SBUSINESS_OPER;
	TFIBWideStringField *TableGID_SBUSINESS_OPER;
	TFIBLargeIntField *TableIDBASE_SBUSINESS_OPER;
	TFIBWideStringField *TableNAME_SBUSINESS_OPER;
	TFIBLargeIntField *TableIDGRP_SBUSINESS_OPER;
	TFIBLargeIntField *ElementID_SBUSINESS_OPER;
	TFIBWideStringField *ElementGID_SBUSINESS_OPER;
	TFIBLargeIntField *ElementIDBASE_SBUSINESS_OPER;
	TFIBWideStringField *ElementNAME_SBUSINESS_OPER;
	TFIBLargeIntField *ElementIDGRP_SBUSINESS_OPER;
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations

UnicodeString GetTextQuery(__int64 id_grp, bool all) ;
public:		// User declarations
		__fastcall TDMSprBusinessOper(TComponent* Owner);

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

		bool Init(void);
		int Done(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;



		void OpenTable(__int64 id_grp, bool all);
		int OpenElement(__int64 id );
		bool NewElement(__int64 id_grp);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);
		void ChancheGrp(__int64 new_id_grp);

		//поиск
		__int64 GetIdPoName(UnicodeString name);

		__int64 IdGrp;
		bool AllElement;
		__int64 IdElement;

        bool Error;
		UnicodeString TextError;

		__int64 GetIdGrpBusinessOper(__int64 id_bo);

};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprBusinessOper *DMSprBusinessOper;
//---------------------------------------------------------------------------
#endif
