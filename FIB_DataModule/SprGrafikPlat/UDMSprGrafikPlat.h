//---------------------------------------------------------------------------

#ifndef UDMSprGrafikPlatH
#define UDMSprGrafikPlatH
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
class TDMSprGrafikPlat : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBDateField *TableDO_SGRPLAT;
	TFIBBCDField *TableSUM_SGRPLAT;
	TFIBBCDField *TableID_SGRPLAT;
	TFIBBCDField *TableIDDOG_SGRPLAT;
	TFIBWideStringField *TableGID_SGRPLAT;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
		__fastcall TDMSprGrafikPlat(TComponent* Owner);

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


		__int64 IdDogovor;
		void OpenTable(__int64 idDogovor);
        void NewElement(__int64 idDogovor);
        void DeleteElement();
        void SaveIsmen();
		void CancelIsmen();

		bool Error;
		AnsiString TextError;
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprGrafikPlat *DMSprGrafikPlat;
//---------------------------------------------------------------------------
#endif
