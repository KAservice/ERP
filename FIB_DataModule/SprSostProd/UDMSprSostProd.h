//---------------------------------------------------------------------------

#ifndef UDMSprSostProdH
#define UDMSprSostProdH
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
class TDMSprSostProd : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBBCDField *TableNKOL_SPROD;
	TFIBBCDField *TableBKOL_SPROD;
	TFIBBCDField *TableKFPRICE_SPROD;
	TFIBSmallIntField *TableSPIS_SPROD;
	TFIBBCDField *TableKF_SPROD;
	TFIBIntegerField *TableTNOM;
	TFIBBCDField *TableVALUE_SSEZKF;
	TFIBBCDField *TableVALUE_SSEZKF_SPROD;
	TIntegerField *TableRECNO;
	TFloatField *TableNABASED;
	TFloatField *TableNNABASED;
	TFloatField *TableSEZKF;
	TFloatField *TableSEZKF_SPROD;
	TFIBBCDField *TableID_SPROD;
	TFIBBCDField *TableIDNOMREST_SPROD;
	TFIBBCDField *TableIDKOMPL_SPROD;
	TFIBBCDField *TableIDED_SPROD;
	TFIBWideStringField *TableGID_SSPROD;
	TFIBWideStringField *TableNAMENOM;
	TFIBWideStringField *TableNAMEED;
	TFIBBCDField *TableIDPRODUCE_SSPROD;
	TFIBBCDField *TableIDLOSTFACTOR_SSPROD;
	TFIBWideStringField *TableNAME_SPRODUCE;
	TFIBWideStringField *TableNAME_SLOSS_FACTOR;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall TableNewRecord(TDataSet *DataSet);
	void __fastcall TableSPIS_SPRODGetText(TField *Sender, UnicodeString &Text, bool DisplayText);
	void __fastcall TableSPIS_SPRODSetText(TField *Sender, const UnicodeString Text);


private:	// User declarations
public:		// User declarations
		__fastcall TDMSprSostProd(TComponent* Owner);

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
		__int64 IdNomRest;
		void OpenTable(__int64 Nom);
        void NewElement(__int64 Nom);
        void DeleteElement();
        void SaveIsmen();
        void CancelIsmen();


        float KolEdProd;    //количество на которое задан состав
        float KFEdProd;     //коэффициент единицы
		TDateTime Pos;

        bool Error;
        AnsiString TextError;
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprSostProd *DMSprSostProd;
//---------------------------------------------------------------------------
#endif
