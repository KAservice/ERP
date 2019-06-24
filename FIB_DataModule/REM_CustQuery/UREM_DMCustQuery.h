//---------------------------------------------------------------------------

#ifndef UREM_DMCustQueryH
#define UREM_DMCustQueryH
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
class TREM_DMCustQuery : public TDataModule
{
__published:	// IDE-managed Components
	TDataSource *DataSourceDocT;
	TDataSource *DataSourceDoc;
	TpFIBDataSet *Doc;
	TpFIBDataSet *DocT;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *NumDoc;
	TFIBLargeIntField *DocID_REM_CQUERY;
	TFIBWideStringField *DocGID_REM_CQUERY;
	TFIBLargeIntField *DocIDBASE_REM_CQUERY;
	TFIBDateTimeField *DocPOS_REM_CQUERY;
	TFIBIntegerField *DocNUM_REM_CQUERY;
	TFIBLargeIntField *DocIDFIRM_REM_CQUERY;
	TFIBLargeIntField *DocIDSKLAD_REM_CQUERY;
	TFIBLargeIntField *DocIDUSER_REM_CQUERY;
	TFIBLargeIntField *DocIDKLIENT_REM_CQUERY;
	TFIBWideStringField *DocKLIENT_NAME_REM_CQUERY;
	TFIBWideStringField *DocKLIENT_ADR_REM_CQUERY;
	TFIBWideStringField *DocKLIENT_PHONE_REM_CQUERY;
	TFIBWideStringField *DocCOMMENTS_REM_CQUERY;
	TFIBSmallIntField *DocRUN_REM_CQUERY;
	TFIBBCDField *DocDO_SUM_REM_CQUERY;
	TFIBBCDField *DocTEC_SUM_REM_CQUERY;
	TFIBBCDField *DocSOGL_SUM_REM_CQUERY;
	TFIBLargeIntField *DocIDZ_REM_CQUERY;
	TFIBLargeIntField *DocIDMODEL_REM_CQUERY;
	TFIBWideStringField *DocNAME_MODEL_REM_CQUERY;
	TFIBWideStringField *DocNAMEFIRM;
	TFIBWideStringField *DocNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocNAME_REM_SMODEL;
	TFIBWideStringField *DocNAMESKLAD;
	TFIBWideStringField *DocNAMEKLIENT;
	TFIBWideStringField *DocNAME_REM_Z;
	TFIBIntegerField *DocNUM_REM_Z;
	TFIBDateTimeField *DocPOS_REM_Z;
	TFIBWideStringField *DocKLIENT_NAME_REM_Z;
	TFIBWideStringField *DocMODEL_REM_Z;
	TFIBWideStringField *DocNAME_USER;
	TFIBLargeIntField *DocTID_REM_CQUERYT;
	TFIBWideStringField *DocTGID_REM_CQUERYT;
	TFIBLargeIntField *DocTIDBASE_REM_CQUERYT;
	TFIBLargeIntField *DocTIDCQ_REM_CQUERYT;
	TFIBLargeIntField *DocTIDNOM_REM_CQUERYT;
	TFIBLargeIntField *DocTIDED_REM_CQUERYT;
	TFIBLargeIntField *DocTIDSOST_REM_CQUERYT;
	TFIBWideStringField *DocTNAMENOM_REM_CQUERYT;
	TFIBBCDField *DocTKOL_REM_CQUERYT;
	TFIBBCDField *DocTKF_REM_CQUERYT;
	TFIBBCDField *DocTPRICE_REM_CQUERYT;
	TFIBBCDField *DocTSUM_REM_CQUERYT;
	TFIBBCDField *DocTPRICE_DO_REM_CQUERYT;
	TFIBBCDField *DocTPRICE_TEC_REM_CQUERYT;
	TFIBBCDField *DocTPRICE_SOGL_REM_CQUERYT;
	TFIBIntegerField *DocTSROK_POST_REM_CQUERYT;
	TFIBDateTimeField *DocTPOS_POST_REM_CQUERYT;
	TFIBSmallIntField *DocTRUN_REM_CQUERYT;
	TFIBWideStringField *DocTCOMMENTS_REM_CQUERYT;
	TFIBWideStringField *DocTNAMENOM;
	TFIBWideStringField *DocTNAMEED;
	TFIBWideStringField *DocTNAME_REM_SSOST_CQUERY;
	TIntegerField *DocTRECNO;
	TFIBIntegerField *NumDocMAXNUMBER;
	TFIBSmallIntField *DocTACT_REM_CQUERYT;
	TFIBLargeIntField *DocTIDPRNOM_REM_CQUERYT;
	TFIBIntegerField *DocTCODENOM;
	TFIBWideStringField *DocTARTNOM;
	TFIBWideStringField *DocTSHED;
	TFIBWideStringField *DocTART_SPRNOM;
	TFIBIntegerField *DocTCODE_SPRNOM;
	TFIBWideStringField *DocTNAME_SPRNOM;
	TFIBLargeIntField *DocIDBRAND_REM_CQUERY;
	TFIBLargeIntField *DocIDPRODUCER_REM_CQUERY;
	TFIBSmallIntField *DocFL_KLIENT_UVEDOML_REM_CQUERY;
	TFIBWideStringField *DocNAME_SBRAND;
	TFIBWideStringField *DocNAME_SPRODUCER;
	TFIBIntegerField *DocNUM_ZAKAZA_REM_CQUERY;
	TFIBDateField *DocDATE_ZAKAZA_REM_CQUERY;
	TFIBLargeIntField *DocIDHW_REM_CQUERY;
	TFIBIntegerField *DocTYPE_REM_CQUERY;
	TFIBWideStringField *DocNAME_REM_SHARDWARE;
	TFIBWideStringField *DocSERNUM_REM_SHARDWARE;
	TFIBWideStringField *DocSERNUM2_REM_SHARDWARE;
	TFIBLargeIntField *DocIDPRMODEL_REM_CQUERY;
	TFIBDateTimeField *DocPOSTUPILO_REM_CQUERY;
	TFIBWideStringField *DocCODE_REM_SMODEL;
	TFIBWideStringField *DocNAME_REM_SPRMODEL;
	TFIBWideStringField *DocCODE_REM_SPRMODEL;
	TFIBDateField *DocPLAN_POSTAVKI_REM_CQUERY;
	TFIBDateTimeField *DocZAKAZANO_REM_CQUERY;
	TFIBDateTimeField *DocOTPRAVLENO_REM_CQUERY;
	TFIBWideStringField *DocTART_REM_CQUERYT;
	TFIBWideStringField *DocNAME_REM_CQUERY;
	TFIBWideStringField *DocNUM_STR_ZAK_POST_REM_CQUERY;
	TFIBSmallIntField *DocTFL_ADD_IN_SOBORUD_SNOM;
	TFIBDateTimeField *DocPOS_ZAK_POST_REM_CQUERY;
	TFIBWideStringField *DocNUM_STR_ZAK_SPROV_REM_CQUERY;
	TFIBDateTimeField *DocPOS_ZAK_SPROV_REM_CQUERY;
	TFIBWideStringField *DocNUM_DOC_OTPR_POST_REM_CQUERY;
	TFIBDateTimeField *DocPOS_DOC_OTPR_POST_REM_CQUERY;
	TFIBWideStringField *DocNUMDOCTK_REM_CQUERY;
	TFIBWideStringField *DocTK_REM_CQUERY;
	TFIBLargeIntField *DocIDPRODAVEC_REM_CQUERY;
	TFIBWideStringField *DocPRODAVEC_NAME;
	TFIBWideStringField *DocTSER_NUM_REM_CQUERYT;
	TFIBWideStringField *DocTUCH_SER_NUM_REM_CQUERYT;
	TFIBWideStringField *DocTREF_REM_CQUERYT;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocIDBASE_REM_CQUERYChange(TField *Sender);
	void __fastcall DocTIDSOST_REM_CQUERYTChange(TField *Sender);
	void __fastcall DocTACT_REM_CQUERYTChange(TField *Sender);
	void __fastcall DocTRUN_REM_CQUERYTChange(TField *Sender);
	void __fastcall DocTSROK_POST_REM_CQUERYTChange(TField *Sender);
private:	// User declarations
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;




public:		// User declarations
		__fastcall TREM_DMCustQuery(TComponent* Owner);

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //функция удаления реализации интерфейса
		bool flDeleteImpl;   //надо ли удалять реализацию при удалении текущего модуля

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //интерфейс класса реализации
		GUID ClsIdImpl;				 //GUID класса реализации

		//IMainInterface
		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);



		//Текущий интерфейс
		void NewDoc(void);
		void OpenDoc(__int64 id);
        bool SaveDoc(void);
		bool DeleteDoc(__int64 id);
        void CloseDoc(void); 

		bool Prosmotr;    //только просмотр
		__int64 IdCQ;           //идентификатор текущей записи

		void AddNewRecordDv(void);

		bool flChangeData;

};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMCustQuery *REM_DMCustQuery;
//---------------------------------------------------------------------------
#endif
