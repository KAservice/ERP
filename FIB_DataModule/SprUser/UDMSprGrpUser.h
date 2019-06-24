//---------------------------------------------------------------------------

#ifndef UDMSprGrpUserH
#define UDMSprGrpUserH
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
//---------------------------------------------------------------------------
class TDMSprGrpUser : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBIntegerField *TableINTERF_SGRPUSER;
	TIntegerField *TableRECNO;
	TFIBBCDField *TableID_SGRPUSER;
	TFIBBCDField *TableIDGRP_SGRPUSER;
	TFIBBCDField *ElementID_SGRPUSER;
	TFIBBCDField *ElementIDGRP_SGRPUSER;
	TFIBWideStringField *TableGID_SGRPUSER;
	TFIBWideStringField *TableNAME_SGRPUSER;
	TFIBWideStringField *TableROLE_SGRPUSER;
	TFIBWideStringField *ElementGID_SGRPUSER;
	TFIBWideStringField *ElementNAME_SGRPUSER;
	TFIBSmallIntField *ElementINTERF_SGRPUSER;
	TFIBWideStringField *ElementROLE_SGRPUSER;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprGrpUser(TComponent* Owner);


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

		bool Init(void);
		int Done(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv ;

        void OpenTable(void);
		int OpenElement(__int64 id);
		void NewElement(__int64 id_grp);
        bool SaveElement(void);
		void DeleteElement(__int64 id);

        __int64 GetIDElement(String gid);
        bool Error;
        AnsiString TextError;
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprGrpUser *DMSprGrpUser;
//---------------------------------------------------------------------------
#endif
