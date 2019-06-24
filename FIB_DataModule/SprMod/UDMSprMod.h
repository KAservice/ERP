//---------------------------------------------------------------------------

#ifndef UDMSprModH
#define UDMSprModH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <Classes.hpp>
#include <DB.hpp>

//---------------------------------------------------------------------------
class TDMSprMod : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TIntegerField *TableRECNO;
	TFIBBCDField *TableID_MOD;
	TFIBBCDField *TableIDNOM_MOD;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall TableNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprMod(TComponent* Owner);



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

		__int64 IdNom;
		void OpenTable(__int64 Nom);
        void NewElement(__int64 Nom);
        void DeleteElement();
        void SaveIsmen();
		void CancelIsmen();

        bool Error;
		String TextError;
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprMod *DMSprMod;
//---------------------------------------------------------------------------
#endif
