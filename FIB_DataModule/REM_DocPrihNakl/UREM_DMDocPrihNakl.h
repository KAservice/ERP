//---------------------------------------------------------------------------

#ifndef UREM_DMDocPrihNaklH
#define UREM_DMDocPrihNaklH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IDMSprPrice.h"

//--------------------------------------------------------------------------

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
class TREM_DMDocPrihNakl : public TDataModule
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
	TFIBLargeIntField *DocAllIDPROJECT_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDBUSINOP_REM_GALLDOC;
	TFIBWideStringField *DocAllFNAME_USER;
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocAllNAMEFIRM;
	TFIBWideStringField *DocAllNAMESKLAD;
	TFIBWideStringField *DocAllNAMEKLIENT;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBLargeIntField *DocID_REM_DPRN;
	TFIBLargeIntField *DocIDBASE_REM_DPRN;
	TFIBLargeIntField *DocIDDOC_REM_DPRN;
	TFIBWideStringField *DocGID_REM_DPRN;
	TFIBLargeIntField *DocIDTPRICE_REM_DPRN;
	TFIBLargeIntField *DocIDRTPRICE_REM_DPRN;
	TFIBBCDField *DocRSUM_REM_DPRN;
	TFIBWideStringField *DocPRIM_REM_DPRN;
	TFIBWideStringField *DocNUMDOCPOST_REM_DPRN;
	TFIBDateTimeField *DocPOSDOCPOST_REM_DPRN;
	TFIBLargeIntField *DocTID_REM_DPRNT;
	TFIBLargeIntField *DocTIDBASE_REM_DPRNT;
	TFIBLargeIntField *DocTIDDOC_REM_DPRNT;
	TFIBWideStringField *DocTGID_REM_DPRNT;
	TFIBLargeIntField *DocTIDNOM_REM_DPRNT;
	TFIBLargeIntField *DocTIDED_REM_DPRNT;
	TFIBLargeIntField *DocTIDHW_REM_DPRNT;
	TFIBBCDField *DocTKOL_REM_DPRNT;
	TFIBBCDField *DocTKF_REM_DPRNT;
	TFIBBCDField *DocTPRICE_REM_DPRNT;
	TFIBBCDField *DocTSUM_REM_DPRNT;
	TFIBBCDField *DocTNAC_REM_DPRNT;
	TFIBBCDField *DocTRPRICE_REM_DPRNT;
	TFIBBCDField *DocTRSUM_REM_DPRNT;
	TFIBIntegerField *DocTNDS_REM_DPRNT;
	TFIBBCDField *DocTSUMNDS_REM_DPRNT;
	TFIBWideStringField *DocTNAMENOM;
	TFIBWideStringField *DocTNAMEED;
	TFIBIntegerField *DocTCODENOM;
	TFIBWideStringField *DocTARTNOM;
	TFIBWideStringField *DocTSHED;
	TFIBIntegerField *DocTCODE_REM_SHARDWARE;
	TFIBWideStringField *DocTSERNUM_REM_SHARDWARE;
	TIntegerField *DocTRECNO;
	TFIBWideStringField *DocTNAME_REM_SHARDWARE;
	TFIBSmallIntField *DocTDVREG_REM_DPRNT;
	TFIBWideStringField *DocAllPREFIKS_NUM_REM_GALLDOC;
	TFIBSmallIntField *DocFL_TREB_OTCHET_REM_DPRN;
	TFIBSmallIntField *DocFL_OTV_HRAN_REM_DPRN;
	TFIBLargeIntField *DocTIDCQT_REM_DPRNT;
	TFIBSmallIntField *DocTFL_ADD_IN_SOBORUD_SNOM;
	TFIBLargeIntField *DocTID_REM_CQUERY;
	TFIBWideStringField *DocTNAME_REM_CQUERY;
	TFIBIntegerField *DocTNUM_REM_CQUERY;
	TFIBDateTimeField *DocTPOS_REM_CQUERY;
	TFIBWideStringField *DocTKLIENT_NAME_REM_CQUERY;
	TFIBWideStringField *DocTNAME_MODEL_REM_CQUERY;
	TFIBWideStringField *DocTNUM_STR_ZAK_POST_REM_CQUERY;
	TFIBLargeIntField *DocTID_REM_Z;
	TFIBWideStringField *DocTNAME_REM_Z;
	TFIBWideStringField *DocTPREFIKS_NUM_REM_Z;
	TFIBIntegerField *DocTNUM_REM_Z;
	TFIBDateTimeField *DocTPOS_REM_Z;
	TFIBWideStringField *DocTMODEL_REM_Z;
	TFIBWideStringField *DocTSERNUM_REM_Z;
	TFIBWideStringField *DocTSERNUM2_REM_Z;
	TFIBWideStringField *DocTSTR_CODE_VIGR_REM_Z_1;
	TFIBLargeIntField *DocTIDTNOM_REM_DPRNT;
	TFIBLargeIntField *DocTIDMHRAN_REM_DPRNT;
	TFIBWideStringField *DocTNAME_SMHRAN;
	TFIBWideStringField *DocTNAME_STNOM;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall DocTAfterDelete(TDataSet *DataSet);
	void __fastcall DocTBeforeDelete(TDataSet *DataSet);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocAllPOS_REM_GALLDOCChange(TField *Sender);
	void __fastcall DocTKOL_REM_DPRNTChange(TField *Sender);
	void __fastcall DocTPRICE_REM_DPRNTChange(TField *Sender);
	void __fastcall DocAllIDSKLAD_REM_GALLDOCChange(TField *Sender);
	void __fastcall DocTRPRICE_REM_DPRNTChange(TField *Sender);
	void __fastcall DocAllIDBASE_REM_GALLDOCChange(TField *Sender);
	void __fastcall DocTNAME_REM_CQUERYGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText);
	void __fastcall DocTNAME_REM_ZGetText(TField *Sender, UnicodeString &Text, bool DisplayText);

private:	// User declarations


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		double SummaDoc;
		double TekSummaDoc;
		double OldSummaStr;
		double NewSummaStr;

		double OldRSummaStr;
		double NewRSummaStr;
public:		// User declarations
		__fastcall TREM_DMDocPrihNakl(TComponent* Owner);

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




		void NewDoc(void);
        void CopyDoc(__int64 id_doc);
		void OpenDoc(__int64 id);
        bool SaveDoc(void);
        bool DvRegDoc(void);
        bool CancelDvRegDoc(void);
        void AddDocNewString(void);
        void DeleteStringDoc(void);
		bool DeleteDoc(__int64 id);
        double Summa(void);

		bool Prosmotr;    //только просмотр
		__int64 IdDoc;           //идентификатор текущей записи
		__int64 IdGrp;        // идетификатор группы
		__int64 IdElementaMaster;  //идентификатор внешенго справочника-владельца



		__int64 IdTypePrice;


        bool IsmPrice;
        bool IsmSum;

		__int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc);
		bool SkladRozn;
		bool EnableDvReg;
};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMDocPrihNakl *REM_DMDocPrihNakl;
//---------------------------------------------------------------------------
#endif
