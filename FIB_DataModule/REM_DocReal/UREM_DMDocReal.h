//---------------------------------------------------------------------------

#ifndef UREM_DMDocRealH
#define UREM_DMDocRealH
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
class TREM_DMDocReal : public TDataModule
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
	TFIBLargeIntField *DocID_REM_DREAL;
	TFIBLargeIntField *DocIDBASE_REM_DREAL;
	TFIBLargeIntField *DocIDDOC_REM_DREAL;
	TFIBWideStringField *DocGID_REM_DREAL;
	TFIBLargeIntField *DocIDTPRICE_REM_DREAL;
	TFIBWideStringField *DocPRIM_REM_DREAL;
	TFIBLargeIntField *DocIDCARD_REM_DREAL;
	TFIBWideStringField *DocNAME_SDISCOUNT_CARD;
	TFIBLargeIntField *DocTID_REM_DREALT;
	TFIBLargeIntField *DocTIDBASE_REM_DREALT;
	TFIBLargeIntField *DocTIDDOC_REM_DREALT;
	TFIBWideStringField *DocTGID_REM_DREALT;
	TFIBLargeIntField *DocTIDNOM_REM_DREALT;
	TFIBLargeIntField *DocTIDED_REM_DREALT;
	TFIBLargeIntField *DocTIDHW_REM_DREALT;
	TFIBBCDField *DocTKOL_REM_DREALT;
	TFIBBCDField *DocTKF_REM_DREALT;
	TFIBBCDField *DocTPRICE_REM_DREALT;
	TFIBBCDField *DocTSUM_REM_DREALT;
	TFIBIntegerField *DocTNDS_REM_DREALT;
	TFIBBCDField *DocTSUMNDS_REM_DREALT;
	TFIBBCDField *DocTPRSK_REM_DREALT;
	TFIBBCDField *DocTSUMSK_REM_DREALT;
	TFIBBCDField *DocTPRSK_CARD_REM_DREALT;
	TFIBBCDField *DocTPRSK_AUTO_REM_DREALT;
	TFIBBCDField *DocTPRSK_HAND_REM_DREALT;
	TFIBSmallIntField *DocTNO_SK_REM_DREALT;
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
	TFIBWideStringField *DocOsnTDOC_REM_GALLDOC;
	TFIBDateTimeField *DocOsnPOS_REM_GALLDOC;
	TFIBIntegerField *DocOsnNUM_REM_GALLDOC;
	TIntegerField *DocTRECNO;
	TFIBSmallIntField *DocTDVREG_REM_DREALT;
	TFIBIntegerField *DocTWARRANTY_REM_DREALT;
	TFIBSmallIntField *DocTFL_NECOND_REM_SHARDWARE;
	TFIBWideStringField *DocTPRICHINA_REM_SHARDWARE;
	TFIBWideStringField *DocAllPREFIKS_NUM_REM_GALLDOC;
	TFIBLargeIntField *DocTIDTNOM_REM_DREALT;
	TFIBLargeIntField *DocTIDMHRAN_DREALT;
	TFIBWideStringField *DocTNAME_STNOM;
	TFIBWideStringField *DocTNAME_SMHRAN;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocTAfterDelete(TDataSet *DataSet);
	void __fastcall DocTBeforeDelete(TDataSet *DataSet);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocAllPOS_REM_GALLDOCChange(TField *Sender);
	void __fastcall DocTPRICE_REM_DREALTChange(TField *Sender);
	void __fastcall DocTKOL_REM_DREALTChange(TField *Sender);
	void __fastcall DocTPRSK_REM_DREALTChange(TField *Sender);
	void __fastcall DocAllIDBASE_REM_GALLDOCChange(TField *Sender);
	void __fastcall DocOsnTDOC_REM_GALLDOCGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText);

private:	// User declarations
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
	double Summa(void);
		double SummaDoc;
		double SummaSkidok;
		double SummaNadbavok;
		double SummaDocFull;
		double SummaTable;

		double TekSummaDoc;

		double OldSummaStr;
		double NewSummaStr;

		double OldSummaSkidokStr;
		double NewSummaSkidokStr;

		double OldSummaNadbavokStr;
		double NewSummaNadbavokStr;

		double OldSummaFullStr;
		double NewSummaFullStr;



		double SebReal;
		double SebProd;
		double SebNom;
		double KolOtrSpisNom;
		double KolSpisNom;
		double KolBasEdinic;
		double KolBasEdinic2;
		double KFEd;

		double OldSumOplPlatCard;
		double OldTableSumOplPlatCard;
		double OldSumOplCreditCard;
		double OldTableSumOplCreditCard;
public:		// User declarations
        __fastcall TREM_DMDocReal(TComponent* Owner);

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
extern PACKAGE TREM_DMDocReal *REM_DMDocReal;
//---------------------------------------------------------------------------
#endif
