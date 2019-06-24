//---------------------------------------------------------------------------

#ifndef UREM_DMDocAktH
#define UREM_DMDocAktH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"

//---------------------------------------------------------------------------
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
class TREM_DMDocAkt : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceDoc;
        TDataSource *DataSourceDocT;
        TDataSource *DataSourceDocAll;
	TpFIBDataSet *DocAll;
	TpFIBDataSet *Doc;
	TpFIBDataSet *DocT;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBTransaction *IBTrDvReg;
	TpFIBDataSet *NumDoc;
	TpFIBQuery *pFIBQ;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBQuery *QueryDvReg;
	TFIBIntegerField *NumDocMAXNUMBER;
	TFIBLargeIntField *DocAllID_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDBASE_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDFIRM_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDSKLAD_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDKLIENT_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDUSER_REM_GALLDOC;
	TFIBDateTimeField *DocAllPOS_REM_GALLDOC;
	TFIBIntegerField *DocAllNUM_REM_GALLDOC;
	TFIBSmallIntField *DocAllPR_REM_GALLDOC;
	TFIBWideStringField *DocAllTDOC_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDDOCOSN_REM_GALLDOC;
	TFIBIntegerField *DocAllTYPEEXTDOC_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDEXTDOC_REM_GALLDOC;
	TFIBBCDField *DocAllSUM_REM_GALLDOC;
	TFIBWideStringField *DocAllFNAME_USER;
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocAllNAMEFIRM;
	TFIBWideStringField *DocAllNAMESKLAD;
	TFIBWideStringField *DocAllNAMEKLIENT;
	TIntegerField *DocTRECNO;
	TFIBLargeIntField *DocID_REM_DAKT;
	TFIBLargeIntField *DocIDBASE_REM_DAKT;
	TFIBWideStringField *DocGID_REM_DAKT;
	TFIBLargeIntField *DocIDDOC_REM_DAKT;
	TFIBLargeIntField *DocIDZ_REM_DAKT;
	TFIBLargeIntField *DocIDHW_REM_DAKT;
	TFIBLargeIntField *DocIDKKT_REM_DAKT;
	TFIBWideStringField *DocPRIM_REM_DAKT;
	TFIBSmallIntField *DocKL_SOGLASEN_REM_DAKT;
	TFIBSmallIntField *DocPODPISAN_REM_DAKT;
	TFIBIntegerField *DocTYPE_REM_DAKT;
	TFIBWideStringField *DocNAME_REM_SHARDWARE;
	TFIBWideStringField *DocSERNUM_REM_SHARDWARE;
	TFIBWideStringField *DocSERNUM2_REM_SHARDWARE;
	TFIBWideStringField *DocNAME_REM_SKKT;
	TFIBWideStringField *DocSERNUM_REM_SKKT;
	TFIBWideStringField *DocSERNUM_REM_Z;
	TFIBWideStringField *DocSERNUM2_REM_Z;
	TFIBWideStringField *DocMODEL_REM_Z;
	TFIBWideStringField *DocNAME_REM_SMODEL;
	TFIBLargeIntField *DocTID_REM_DAKTT;
	TFIBLargeIntField *DocTIDBASE_REM_DAKTT;
	TFIBWideStringField *DocTGID_REM_DAKTT;
	TFIBLargeIntField *DocTIDDOC_REM_DAKTT;
	TFIBIntegerField *DocTINDEX_REM_DAKTT;
	TFIBWideStringField *DocTTEXT_REM_DAKTT;
	TFIBWideStringField *DocNAME_REM_Z;
	TFIBLargeIntField *DocAllIDPROJECT_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDBUSINOP_REM_GALLDOC;
	TFIBWideStringField *DocAllPREFIKS_NUM_REM_GALLDOC;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBLargeIntField *DocAllIDOBJECT_REM_GALLDOC;
	TFIBWideStringField *DocAllNAME_SOBJECT;
	TFIBWideStringField *DocNUM_U_PROISV_REM_DAKT;
	TFIBWideStringField *DocNEISPR_KLIENTA_REM_DAKT;
	TFIBWideStringField *DocNEISPR_SC_REM_DAKT;
	TFIBIntegerField *DocFL_FULL_KOMPL_REM_DAKT;
	TFIBWideStringField *DocNEKOMPL_STR_REM_DAKT;
	TFIBWideStringField *DocKOMPL_STR_REM_DAKT;
	TFIBIntegerField *DocFL_MEXPOVR_REM_DAKT;
	TFIBWideStringField *DocMEXPOVR_STR_REM_DAKT;
	TFIBWideStringField *DocNEISPR_BLOK_REM_DAKT;
	TFIBIntegerField *DocFL_PRICHINA_ACTA_REM_DAKT;
	TFIBWideStringField *DocPRICHINA_ACTA_DR_STR_REM_DAKT;
	TFIBIntegerField *DocFL_PRICHINA_SOST_REM_DAKT;
	TFIBIntegerField *DocFL_MESTONAX_REM_DAKT;
	TFIBWideStringField *DocISD_NAME_REM_DAKT;
	TFIBDateField *DocISD_DATE_PRODAGI_REM_DAKT;
	TFIBWideStringField *DocISD_MODEL_REM_DAKT;
	TFIBWideStringField *DocISD_SERNUM1_REM_DAKT;
	TFIBWideStringField *DocISD_SERNUM2_REM_DAKT;
	TFIBWideStringField *DocISD_SERNUM3_REM_DAKT;
	TFIBWideStringField *DocISD_NUMUP_REM_DAKT;
	TFIBWideStringField *DocISD_NUMTEXLIST_REM_DAKT;
	TFIBWideStringField *DocPRODAVEC_NAME_REM_DAKT;
	TFIBWideStringField *DocPRODAVEC_TEL_REM_DAKT;
	TFIBWideStringField *DocKLIENT_NAME_REM_DAKT;
	TFIBWideStringField *DocKLIENT_ADR_REM_DAKT;
	TFIBWideStringField *DocKLIENT_PHONE_REM_DAKT;
	TFIBWideStringField *DocPRICHINA_SOST_DR_REM_DAKT;
	TFIBWideStringField *DocPRODAVEC_ADR_REM_DAKT;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocAllPOS_REM_GALLDOCChange(TField *Sender);
	void __fastcall DocAllIDBASE_REM_GALLDOCChange(TField *Sender);
private:	// User declarations

	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TREM_DMDocAkt(TComponent* Owner);

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

		__int64 IdDoc;           //идентификатор текущей записи
		bool Prosmotr;    //только просмотр

		bool NewDoc(void);
		bool OpenDoc(__int64 id);
		bool SaveDoc(void);
		bool DeleteDoc(__int64 id);

        bool DvRegDoc(void);
		bool CancelDvRegDoc(void);

		void TableAppend(void);
		void TableDelete(void);




};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMDocAkt *REM_DMDocAkt;
//---------------------------------------------------------------------------
#endif
