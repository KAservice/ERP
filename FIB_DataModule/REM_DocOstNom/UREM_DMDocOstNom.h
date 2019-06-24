//---------------------------------------------------------------------------

#ifndef UREM_DMDocOstNomH
#define UREM_DMDocOstNomH
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
class TREM_DMDocOstNom : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceDoc;
        TDataSource *DataSourceDocT;
        TDataSource *DataSourceDocAll;
	TpFIBDataSet *DocAll;
	TpFIBDataSet *Doc;
	TpFIBTransaction *IBTrDvReg;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *DocT;
	TpFIBDataSet *NumDoc;
	TFIBIntegerField *NumDocMAXNUMBER;
	TpFIBDataSet *DocOsn;
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
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBLargeIntField *DocID_REM_DOSN;
	TFIBLargeIntField *DocIDBASE_REM_DOSN;
	TFIBLargeIntField *DocIDDOC_REM_DOSN;
	TFIBWideStringField *DocGID_REM_DOSN;
	TFIBLargeIntField *DocIDTPRICE_REM_DOSN;
	TFIBLargeIntField *DocIDRTPRICE_REM_DOSN;
	TFIBBCDField *DocRSUM_REM_DOSN;
	TFIBWideStringField *DocPRIM_REM_DOSN;
	TDataSource *DataSourceDocOsn;
	TFIBLargeIntField *DocTID_REM_DOSNT;
	TFIBLargeIntField *DocTIDBASE_REM_DOSNT;
	TFIBLargeIntField *DocTIDDOC_REM_DOSNT;
	TFIBWideStringField *DocTGID_REM_DOSNT;
	TFIBLargeIntField *DocTIDNOM_REM_DOSNT;
	TFIBLargeIntField *DocTIDED_REM_DOSNT;
	TFIBLargeIntField *DocTIDHW_REM_DOSNT;
	TFIBBCDField *DocTKOL_REM_DOSNT;
	TFIBBCDField *DocTKF_REM_DOSNT;
	TFIBBCDField *DocTPRICE_REM_DOSNT;
	TFIBBCDField *DocTSUM_REM_DOSNT;
	TFIBBCDField *DocTRPRICE_REM_DOSNT;
	TFIBBCDField *DocTRSUM_REM_DOSNT;
	TFIBIntegerField *DocTNDS_REM_DOSNT;
	TFIBBCDField *DocTSUMNDS_REM_DOSNT;
	TFIBSmallIntField *DocTDVREG_REM_DOSNT;
	TFIBWideStringField *DocTNAMENOM;
	TFIBWideStringField *DocTNAMEED;
	TFIBIntegerField *DocTCODENOM;
	TFIBWideStringField *DocTARTNOM;
	TFIBWideStringField *DocTSHED;
	TFIBWideStringField *DocTNAME_REM_SHARDWARE;
	TFIBIntegerField *DocTCODE_REM_SHARDWARE;
	TFIBWideStringField *DocTSERNUM_REM_SHARDWARE;
	TFIBWideStringField *DocOsnTDOC_REM_GALLDOC;
	TFIBIntegerField *DocOsnNUM_REM_GALLDOC;
	TFIBDateTimeField *DocOsnPOS_REM_GALLDOC;
	TIntegerField *DocTRECNO;
	TFIBWideStringField *DocAllPREFIKS_NUM_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDOBJECT_REM_GALLDOC;
	TFIBWideStringField *DocAllNAME_SOBJECT;
	TpFIBDataSet *TypeNom;
	TFIBLargeIntField *TypeNomID_STNOM;
	TFIBWideStringField *TypeNomNAME_STNOM;
	TFIBLargeIntField *DocTIDTNOM_REM_DOSNT;
	TStringField *DocTNAME_TYPE_NOM_LOOCUP;
	TFIBLargeIntField *DocTIDMHRAN_REM_DOSNT;
	TFIBWideStringField *DocTNAME_SMHRAN;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocTAfterDelete(TDataSet *DataSet);
	void __fastcall DocTBeforeDelete(TDataSet *DataSet);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocAllPOS_REM_GALLDOCChange(TField *Sender);
	void __fastcall DocTKOL_REM_DOSNTChange(TField *Sender);
	void __fastcall DocTPRICE_REM_DOSNTChange(TField *Sender);
	void __fastcall DocTRPRICE_REM_DOSNTChange(TField *Sender);
	void __fastcall DocAllIDBASE_REM_GALLDOCChange(TField *Sender);
private:	// User declarations
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

        double Summa(void);


		double SummaDoc;
		double OldSummaStr;
		double NewSummaStr;

		double OldRSummaStr;
		double NewRSummaStr;
public:		// User declarations
		__fastcall TREM_DMDocOstNom(TComponent* Owner);

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
		void OpenDoc(__int64 id_doc);
        bool SaveDoc(void);
        void CloseDoc(void);
        bool DvRegDoc(void);
        bool CancelDvRegDoc(void);
        void AddDocNewString(void);
        void DeleteStringDoc(void);

		bool DeleteDoc(__int64 id);

        bool NewElement;  // новый элемент
        bool Prosmotr;    //только просмотр
		__int64 IdDoc;           //идентификатор текущей записи
		__int64 IdGrp;        // идетификатор группы
		__int64 IdElementaMaster;  //идентификатор внешенго справочника-владельца


};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMDocOstNom *REM_DMDocOstNom;
//---------------------------------------------------------------------------
#endif
