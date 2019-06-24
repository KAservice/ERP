//---------------------------------------------------------------------------

#ifndef UREM_DMDocZStartH
#define UREM_DMDocZStartH
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
class TREM_DMDocZStart : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceDoc;
        TDataSource *DataSourceDocAll;
	TpFIBDataSet *DocAll;
	TpFIBDataSet *Doc;
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
	TFIBLargeIntField *DocID_REM_DZSTART;
	TFIBLargeIntField *DocIDBASE_REM_DZSTART;
	TFIBWideStringField *DocGID_REM_DZSTART;
	TFIBLargeIntField *DocIDDOC_REM_DZSTART;
	TFIBLargeIntField *DocIDZ_REM_DZSTART;
	TFIBWideStringField *DocPRIM_REM_DZSTART;
	TFIBWideStringField *DocNAME_REM_Z;
	TFIBIntegerField *DocNUM_REM_Z;
	TFIBDateTimeField *DocPOS_REM_Z;
	TFIBWideStringField *DocSERNUM_REM_Z;
	TFIBWideStringField *DocSERNUM2_REM_Z;
	TFIBWideStringField *DocKLIENT_NAME_REM_Z;
	TFIBWideStringField *DocMODEL_REM_Z;
	TFIBWideStringField *DocNAME_REM_SMODEL;
	TFIBLargeIntField *DocAllIDPROJECT_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDBUSINOP_REM_GALLDOC;
	TFIBWideStringField *DocAllPREFIKS_NUM_REM_GALLDOC;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBLargeIntField *DocIDPR_REM_DZSTART;
	TFIBLargeIntField *DocIDCFCPR_REM_DZSTART;
	TFIBLargeIntField *DocIDNEISPR_REM_DZSTART;
	TFIBLargeIntField *DocIDPRMODEL_REM_DZSTART;
	TFIBWideStringField *DocPODO_REM_DZSTART;
	TFIBWideStringField *DocPRODAVEC_REM_DZSTART;
	TFIBWideStringField *DocSERNUM3_REM_DZSTART;
	TFIBWideStringField *DocSERNUM4_REM_DZSTART;
	TFIBWideStringField *DocNUMBAT_REM_DZSTART;
	TFIBWideStringField *DocSOST_REM_DZSTART;
	TFIBDateField *DocDATEVIPUSK_REM_DZSTART;
	TFIBDateField *DocDATE_PRODAGI_REM_DZSTART;
	TFIBIntegerField *DocKEM_SDANO_REM_DZSTART;
	TFIBIntegerField *DocTYPE_REMONT_REM_DZSTART;
	TFIBWideStringField *DocNAME_SPRODUCER;
	TFIBWideStringField *DocNAME_REM_SPRNEISPR;
	TFIBWideStringField *DocCODE_REM_SPRNEISPR;
	TFIBWideStringField *DocNAME_REM_SNEISPR;
	TFIBWideStringField *DocNAME_REM_SPRMODEL;
	TFIBWideStringField *DocCODE_REM_SPRMODEL;
	TFIBWideStringField *DocNUM_GARDOC_REM_Z;
	TFIBLargeIntField *DocIDSELLER_REM_DZSTART;
	TFIBWideStringField *DocNAME_REM_SPRNEISPR_GRP;
	TFIBWideStringField *DocNAME_ENG_REM_SPRNEISPR_GRP;
	TFIBWideStringField *DocNAME_ENG_REM_SNEISPR;
	TFIBWideStringField *DocNAME_REM_SGRPNEISPR;
	TFIBWideStringField *DocNAME_ENG_REM_SGRPNEISPR;
	TFIBWideStringField *DocNAME_SSELLER;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocAllPOS_REM_GALLDOCChange(TField *Sender);
	void __fastcall DocAllIDBASE_REM_GALLDOCChange(TField *Sender);
private:	// User declarations

	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		double OldSummaStr;
		double NewSummaStr;

		double OldSummaMexStr;
		double NewSummaMexStr;
public:		// User declarations
		__fastcall TREM_DMDocZStart(TComponent* Owner);

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






};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMDocZStart *REM_DMDocZStart;
//---------------------------------------------------------------------------
#endif
