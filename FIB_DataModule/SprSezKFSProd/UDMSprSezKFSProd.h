//---------------------------------------------------------------------------

#ifndef UDMSprSezKFSProdH
#define UDMSprSezKFSProdH
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
class TDMSprSezKFSProd : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBIntegerField *TableMONTH_SSEZKF_SPROD;
	TFIBBCDField *TableVALUE_SSEZKF_SPROD;
	TIntegerField *TableRECNO;
	TFIBBCDField *TableID_SSEZKF_SPROD;
	TFIBBCDField *TableIDSSPROD_SSEZKF_SPROD;
	TFIBWideStringField *TableGID_SSEZKF_SPROD;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprSezKFSProd(TComponent* Owner);


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
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		__int64 IdSProd;
		void OpenTable(__int64 idSProd);
        void NewElement(__int64 idSProd);
        void DeleteElement();
        void SaveIsmen();
		void CancelIsmen();

        bool Error;
		AnsiString TextError;
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprSezKFSProd *DMSprSezKFSProd;
//---------------------------------------------------------------------------
#endif
