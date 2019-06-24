//---------------------------------------------------------------------------

#ifndef UDMSprNacenkaH
#define UDMSprNacenkaH
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
class TDMSprNacenka : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *TPrice;
	TFIBBCDField *TableVALUE_SNACENKA;
	TFIBBCDField *ElementVALUE_SNACENKA;
	TFIBIntegerField *TableOKR_SNACENKA;
	TFIBIntegerField *ElementOKR_SNACENKA;
	TFIBBCDField *TableID_SNACENKA;
	TFIBBCDField *TableIDGRPNOM_SNACENKA;
	TFIBBCDField *TableIDTPRICE_SNACENKA;
	TFIBBCDField *ElementID_SNACENKA;
	TFIBBCDField *ElementIDGRPNOM_SNACENKA;
	TFIBBCDField *ElementIDTPRICE_SNACENKA;
	TFIBWideStringField *TableGID_SNACENKA;
	TFIBBCDField *TableIDBASE_SNACENKA;
	TFIBWideStringField *TableNAME_TPRICE;
	TFIBWideStringField *ElementGID_SNACENKA;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableAfterInsert(TDataSet *DataSet);
	void __fastcall TableNewRecord(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprNacenka(TComponent* Owner);


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

		void OpenTable(__int64 id_grp_nom);
        void SaveIsmen(void);

		int OpenElement(__int64 id);
        void NewElement(void);
        void SaveElement(void);
		void DeleteElement(__int64 id);
		int FindElement(__int64 id_type_price, __int64 id_grp_nom);

		void CancelIsmen(void);

		bool Error;
        String TextError;
		__int64 IdGrpNom;
        __int64 IdTypePrice;
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprNacenka *DMSprNacenka;
//---------------------------------------------------------------------------
#endif
