//---------------------------------------------------------------------------

#ifndef UREM_DMDocPerH
#define UREM_DMDocPerH
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
class TREM_DMDocPer : public TDataModule
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
	TpFIBDataSet *SpisokTypePrice;
	TFIBIntegerField *SpisokTypePriceID_TPRICE;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBQuery *QueryDvReg;
	TpFIBDataSet *DocOsn;
	TDataSource *DataSourceDocOsn;
	TFIBWideStringField *SpisokTypePriceNAME_TPRICE;
	TFIBWideStringField *SpisokTypePriceGID_STPRICE;
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
	TFIBLargeIntField *DocID_REM_DPER;
	TFIBLargeIntField *DocIDBASE_REM_DPER;
	TFIBLargeIntField *DocIDDOC_REM_DPER;
	TFIBWideStringField *DocGID_REM_DPER;
	TFIBLargeIntField *DocIDRTPRICE_REM_DPER;
	TFIBLargeIntField *DocIDSKLPOL_REM_DPER;
	TFIBWideStringField *DocPRIM_REM_DPER;
	TFIBLargeIntField *DocTID_REM_DPERT;
	TFIBLargeIntField *DocTIDBASE_REM_DPERT;
	TFIBLargeIntField *DocTIDDOC_REM_DPERT;
	TFIBWideStringField *DocTGID_REM_DPERT;
	TFIBLargeIntField *DocTIDNOM_REM_DPERT;
	TFIBLargeIntField *DocTIDED_REM_DPERT;
	TFIBLargeIntField *DocTIDHW_REM_DPERT;
	TFIBBCDField *DocTKOL_REM_DPERT;
	TFIBBCDField *DocTKF_REM_DPERT;
	TFIBBCDField *DocTRPRICE_REM_DPERT;
	TFIBBCDField *DocTRSUM_REM_DPERT;
	TFIBBCDField *DocTNAC_REM_DPERT;
	TFIBSmallIntField *DocTDVREG_REM_DPERT;
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
	TFIBWideStringField *DocNAMESKLAD;
	TFIBSmallIntField *DocTDVREG_POL_REM_DPERT;
	TFIBWideStringField *DocAllPREFIKS_NUM_REM_GALLDOC;
	TFIBLargeIntField *DocTIDTNOM_REM_DPERT;
	TFIBLargeIntField *DocTIDMHRAN_OTPR_REM_DPERT;
	TFIBLargeIntField *DocTIDMHRAN_POL_REM_DPERT;
	TFIBWideStringField *DocTNAME_SMHRAN_POL;
	TFIBWideStringField *DocTNAME_STNOM;
	TFIBWideStringField *DocTNAME_SMHRAN_OTPR;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocTAfterDelete(TDataSet *DataSet);
	void __fastcall DocTBeforeDelete(TDataSet *DataSet);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocAllPOS_REM_GALLDOCChange(TField *Sender);
	void __fastcall DocAllIDBASE_REM_GALLDOCChange(TField *Sender);
	void __fastcall DocOsnTDOC_REM_GALLDOCGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText);
	void __fastcall DocTRPRICE_REM_DPERTChange(TField *Sender);
	void __fastcall DocTKOL_REM_DPERTChange(TField *Sender);

private:	// User declarations
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
	double Summa(void);
		double SummaDoc;
//		double SummaSkidok;
//		double SummaNadbavok;
//		double SummaDocFull;
//		double SummaTable;

//		double TekSummaDoc;

		double OldSummaStr;
		double NewSummaStr;

//		double OldSummaSkidokStr;
//		double NewSummaSkidokStr;

//		double OldSummaNadbavokStr;
//		double NewSummaNadbavokStr;

//		double OldSummaFullStr;
//		double NewSummaFullStr;



//		double SebReal;
//		double SebProd;
//		double SebNom;
//		double KolOtrSpisNom;
//		double KolSpisNom;
//		double KolBasEdinic;
//		double KolBasEdinic2;
//		double KFEd;

//		double OldSumOplPlatCard;
//		double OldTableSumOplPlatCard;
//		double OldSumOplCreditCard;
//		double OldTableSumOplCreditCard;
public:		// User declarations
        __fastcall TREM_DMDocPer(TComponent* Owner);

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
//		__int64 IdElementaMaster;  //идентификатор внешенго справочника-владельца
//		__int64 IdTypePrice;
//		int Operation;    //1-реализация, 2-перемещение, 3-на выпуск продукции, 4-списание
//		__int64 IdSklad;


        bool AutoRaschet;
		bool EnableDvReg;

		bool SkladRozn;
		bool NoOtrOstatok;


		int GetNumberNewDoc(void);




};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMDocPer *REM_DMDocPer;
//---------------------------------------------------------------------------
#endif
