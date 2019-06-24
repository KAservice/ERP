//---------------------------------------------------------------------------

#ifndef UREM_DMDocSborkaKomplH
#define UREM_DMDocSborkaKomplH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"

//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
//---------------------------------------------------------------------------
class TREM_DMDocSborkaKompl : public TDataModule
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
	TFIBIntegerField *NumDocMAXNUMBER;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBQuery *QueryDvReg;
	TpFIBDataSet *DocOsn;
	TDataSource *DataSourceDocOsn;
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
	TFIBWideStringField *DocOsnTDOC_REM_GALLDOC;
	TFIBDateTimeField *DocOsnPOS_REM_GALLDOC;
	TFIBIntegerField *DocOsnNUM_REM_GALLDOC;
	TFIBLargeIntField *DocTID_REM_DSBKOMPLT;
	TFIBLargeIntField *DocTIDBASE_REM_DSBKOMPLT;
	TFIBLargeIntField *DocTIDDOC_REM_DSBKOMPLT;
	TFIBWideStringField *DocTGID_REM_DSBKOMPLT;
	TFIBLargeIntField *DocTIDNOM_REM_DSBKOMPLT;
	TFIBLargeIntField *DocTIDED_REM_DSBKOMPLT;
	TFIBLargeIntField *DocTIDHW_REM_DSBKOMPLT;
	TFIBBCDField *DocTKOL_REM_DSBKOMPLT;
	TFIBBCDField *DocTKF_REM_DSBKOMPLT;
	TFIBBCDField *DocTRPRICE_REM_DSBKOMPLT;
	TFIBBCDField *DocTRSUM_REM_DSBKOMPLT;
	TFIBSmallIntField *DocTDVREG_REM_DSBKOMPLT;
	TFIBWideStringField *DocTKRNAMENOM;
	TFIBWideStringField *DocTNAMENOM;
	TFIBSmallIntField *DocTTNOM;
	TFIBIntegerField *DocTCODENOM;
	TFIBWideStringField *DocTARTNOM;
	TFIBWideStringField *DocTNAMEED;
	TFIBWideStringField *DocTSHED;
	TFIBLargeIntField *DocTIDGRPNOM;
	TFIBLargeIntField *DocTIDVID_SNOM;
	TFIBWideStringField *DocTNAMEGN;
	TFIBWideStringField *DocTNAME_SVIDNOM;
	TFIBWideStringField *DocTNAME_REM_SHARDWARE;
	TFIBIntegerField *DocTCODE_REM_SHARDWARE;
	TFIBWideStringField *DocTSERNUM_REM_SHARDWARE;
	TIntegerField *DocTRECNO;
	TFIBLargeIntField *DocID_REM_DSBKOMPL;
	TFIBLargeIntField *DocIDBASE_REM_DSBKOMPL;
	TFIBLargeIntField *DocIDDOC_REM_DSBKOMPL;
	TFIBWideStringField *DocGID_REM_DSBKOMPL;
	TFIBLargeIntField *DocIDNOM_REM_DSBKOMPL;
	TFIBLargeIntField *DocIDED_REM_DSBKOMPL;
	TFIBLargeIntField *DocIDHW_REM_DSBKOMPL;
	TFIBBCDField *DocKOL_REM_DSBKOMPL;
	TFIBBCDField *DocKF_REM_DSBKOMPL;
	TFIBBCDField *DocRPRICE_REM_DSBKOMPL;
	TFIBLargeIntField *DocIDRTPRICE_REM_DSBKOMPL;
	TFIBWideStringField *DocPRIM_REM_DSBKOMPL;
	TFIBWideStringField *DocNAMENOM;
	TFIBIntegerField *DocCODENOM;
	TFIBWideStringField *DocARTNOM;
	TFIBWideStringField *DocNAME_REM_SHARDWARE;
	TFIBIntegerField *DocCODE_REM_SHARDWARE;
	TFIBWideStringField *DocSERNUM_REM_SHARDWARE;
	TFIBWideStringField *DocNAMEED;
	TFIBWideStringField *DocAllPREFIKS_NUM_REM_GALLDOC;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocAllPOS_REM_GALLDOCChange(TField *Sender);
	void __fastcall DocAllIDBASE_REM_GALLDOCChange(TField *Sender);
	void __fastcall DocOsnTDOC_REM_GALLDOCGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText);
	void __fastcall DocTKOL_REM_DSBKOMPLTChange(TField *Sender);
	void __fastcall DocTRPRICE_REM_DSBKOMPLTChange(TField *Sender);
	void __fastcall DocTAfterDelete(TDataSet *DataSet);
	void __fastcall DocTBeforeDelete(TDataSet *DataSet);

private:	// User declarations
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

	double OldRoznSummaStr;
	double NewRoznSummaStr;




public:		// User declarations
        __fastcall TREM_DMDocSborkaKompl(TComponent* Owner);

	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;
	IkanUnknown * InterfaceImpl; //интерфейс класса реализации
	GUID ClsIdImpl;				 //GUID класса реализации
		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;
		UnicodeString TextError;
		bool Init(void);
		int Done(void);



        void NewDoc(void);
		bool OpenDoc(__int64 IdDoc);
		void OpenDocOsn(void);
		bool SaveDoc(void);
		bool BeforeSaveDoc(void);
		bool AfterSaveDoc(void);


		bool DvRegDoc(void);
		bool CancelDvRegDoc(void);


		bool DeleteDoc(__int64 id);
        void AddDocNewString(void);
        void DeleteStringDoc(void);
        void CloseDoc(void);


		bool NewElement;  // новый элемент

		bool Prosmotr;    //только просмотр
		UnicodeString ProsmotrText;
		void ValidateProsmotr(void);

		__int64 IdDoc;           //идентификатор текущей записи
		__int64 IdGrp;        // идетификатор группы
		__int64 IdElementaMaster;  //идентификатор внешенго справочника-владельца
		__int64 IdTypePrice;
		int Operation;    //1-реализация, 2-перемещение, 3-на выпуск продукции, 4-списание
		__int64 IdSklad;


        bool AutoRaschet;
		bool EnableDvReg;

		bool SkladRozn;
		bool NoOtrOstatok;


		int GetNumberNewDoc(void);




};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMDocSborkaKompl *REM_DMDocSborkaKompl;
//---------------------------------------------------------------------------
#endif
