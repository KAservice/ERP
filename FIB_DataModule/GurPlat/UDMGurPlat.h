//---------------------------------------------------------------------------

#ifndef UDMGurPlatH
#define UDMGurPlatH
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
class TDMGurPlat : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBDataSet *Element;
	TpFIBDataSet *IBQ;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *pFIBQ;
	TpFIBDataSet *GurPlat;
	TFIBLargeIntField *TableID_GURNALPLAT;
	TFIBWideStringField *TableGID_GURNALPLAT;
	TFIBWideStringField *TableCODE_GURNALPLAT;
	TFIBWideStringField *TableNUMTEL_GURNALPLAT;
	TFIBIntegerField *TableNUMKV_GURNALPLAT;
	TFIBDateTimeField *TablePOS_GURNALPLAT;
	TFIBLargeIntField *TableIDUSER_GURNALPLAT;
	TFIBBCDField *TableSUM_GURNALPLAT;
	TFIBSmallIntField *TableOUT_GURNALPLAT;
	TFIBWideStringField *TableCODOPER_GURNALPLAT;
	TFIBBCDField *TableSUMKL_GURNALPLAT;
	TFIBBCDField *TablePROCENT_COMMISSION_GURNALPLAT;
	TFIBLargeIntField *TableIDKLIENT_GURNALPLAT;
	TFIBLargeIntField *TableIDBASE_GURNALPLAT;
	TFIBLargeIntField *TableIDOPERATOR_GURNALPLAT;
	TFIBLargeIntField *TableIDCODETEL_GURNALPLAT;
	TFIBWideStringField *TableNAME_USER;
	TFIBWideStringField *TableNAMEKLIENT;
	TFIBWideStringField *TableNAME_CODETEL;
	TFIBWideStringField *TableCODOPER_CODETEL;
	TFIBLargeIntField *GurPlatID_GURNALPLAT;
	TFIBLargeIntField *ElementID_GURNALPLAT;
	TFIBWideStringField *ElementGID_GURNALPLAT;
	TFIBWideStringField *ElementCODE_GURNALPLAT;
	TFIBWideStringField *ElementNUMTEL_GURNALPLAT;
	TFIBIntegerField *ElementNUMKV_GURNALPLAT;
	TFIBDateTimeField *ElementPOS_GURNALPLAT;
	TFIBLargeIntField *ElementIDUSER_GURNALPLAT;
	TFIBBCDField *ElementSUM_GURNALPLAT;
	TFIBSmallIntField *ElementOUT_GURNALPLAT;
	TFIBWideStringField *ElementCODOPER_GURNALPLAT;
	TFIBBCDField *ElementSUMKL_GURNALPLAT;
	TFIBBCDField *ElementPROCENT_COMMISSION_GURNALPLAT;
	TFIBLargeIntField *ElementIDKLIENT_GURNALPLAT;
	TFIBLargeIntField *ElementIDBASE_GURNALPLAT;
	TFIBLargeIntField *ElementIDOPERATOR_GURNALPLAT;
	TFIBLargeIntField *ElementIDCODETEL_GURNALPLAT;
	TFIBWideStringField *ElementNAME_USER;
	TFIBWideStringField *ElementNAMEKLIENT;
	TFIBWideStringField *ElementNAME_CODETEL;
	TFIBWideStringField *ElementCODOPER_CODETEL;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TDMGurPlat(TComponent* Owner);

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
		UnicodeString TextError;
		bool Init(void);
		int Done(void);


        void OpenTable();
        bool NoOnlyOut;
        AnsiString CodeTel;

        void UpdateTable(void);
		__int64 IdPlat;

        TDateTime PosNach;
        TDateTime PosCon;

        void  NewElement(void);
		int OpenElement(__int64 id);
        void  SaveElement();
		void DeleteElement(__int64 id);
        void DeleteAllElement(bool NoDeleteEndRecord);

		bool AddPlat(AnsiString cod,
					   AnsiString number,
                       double sum,
					   int number_kv,
                       AnsiString code_operator,
                       double procent_commission,
                       double sum_klient,
					   __int64 id_klient,
					   __int64 id_spr_code_tel);

        bool CheckPlat(AnsiString cod,
                       AnsiString number,
                       double sum,
					   int number_kv,
					   __int64 id_spr_code_tel);

        int GetNumberKv(AnsiString cod);

};
//---------------------------------------------------------------------------
extern PACKAGE TDMGurPlat *DMGurPlat;
//---------------------------------------------------------------------------
#endif
