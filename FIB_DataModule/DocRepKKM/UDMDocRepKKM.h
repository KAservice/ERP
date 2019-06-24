//---------------------------------------------------------------------------

#ifndef UDMDocRepKKMH
#define UDMDocRepKKMH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
//---------------------------------------------------------------------------
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>



//---------------------------------------------------------------------------
class TDMDocRepKKM : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceDoc;
        TDataSource *DataSourceDocT;
        TDataSource *DataSourceDocAll;
	TpFIBDataSet *DocAll;
	TpFIBDataSet *Doc;
	TpFIBDataSet *DocT;
	TpFIBTransaction *IBTrDvReg;
	TpFIBDataSet *NumDoc;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBDateTimeField *DocAllPOSDOC;
	TFIBSmallIntField *DocAllPRDOC;
	TFIBIntegerField *DocAllNUMDOC;
	TFIBBCDField *DocAllSUMDOC;
	TFIBBCDField *DocOPLNAL_DREPKKM;
	TFIBBCDField *DocOPLPC_DREPKKM;
	TFIBIntegerField *DocNKL_DREPKKM;
	TFIBBCDField *DocSK_DREPKKM;
	TFIBBCDField *DocNAD_DREPKKM;
	TFIBSmallIntField *DocDVREG_DREPKKM;
	TFIBBCDField *DocTPRICE_DREPKKMT;
	TFIBBCDField *DocTKOL_DREPKKMT;
	TFIBBCDField *DocTKF_DREPKKMT;
	TFIBBCDField *DocTSUM_DREPKKMT;
	TFIBBCDField *DocTSK_DREPKKMT;
	TFIBBCDField *DocTNAD_DREPKKMT;
	TFIBBCDField *DocTPRICEFULL_DREPKKMT;
	TFIBIntegerField *DocTTNOM;
	TIntegerField *DocTRECNO;
	TpFIBDataSet *IBQ;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBQuery *QueryDvReg;
	TpFIBDataSet *TableDoc;
	TpFIBDataSet *PayDoc;
	TFIBBCDField *TableDocSUMMA;
	TFIBFloatField *TableDocSUMKOL;
	TFIBBCDField *TableDocSUMSK;
	TFIBBCDField *TableDocSUMNAD;
	TFIBBCDField *PayDocOPLATANAL;
	TFIBBCDField *PayDocOPLATAPC;
	TFIBLargeIntField *TableDocIDNOM;
	TFIBWideStringField *TableDocNAMENOM;
	TFIBLargeIntField *TableDocIDED;
	TFIBWideStringField *TableDocNAMEED;
	TFIBLargeIntField *DocAllIDDOC;
	TFIBLargeIntField *DocAllIDFIRMDOC;
	TFIBLargeIntField *DocAllIDSKLDOC;
	TFIBLargeIntField *DocAllIDKLDOC;
	TFIBLargeIntField *DocAllIDDOGDOC;
	TFIBLargeIntField *DocAllIDUSERDOC;
	TFIBWideStringField *DocAllGID_DOC;
	TFIBWideStringField *DocAllPREFIKSDOC;
	TFIBLargeIntField *DocAllIDDOCOSNDOC;
	TFIBLargeIntField *DocAllIDEXTDOC;
	TFIBIntegerField *DocAllTYPEEXTDOC;
	TFIBLargeIntField *DocAllIDBASE_GALLDOC;
	TFIBLargeIntField *DocAllIDPROJECT_GALLDOC;
	TFIBWideStringField *DocAllFNAME_USER;
	TFIBWideStringField *DocAllNAME_SDOG;
	TFIBWideStringField *DocAllNAMEKLIENT;
	TFIBWideStringField *DocAllNAMEFIRM;
	TFIBWideStringField *DocAllNAMESKLAD;
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBLargeIntField *DocID_DREPKKM;
	TFIBWideStringField *DocGID_DREPKKM;
	TFIBLargeIntField *DocIDDOC_DREPKKM;
	TFIBLargeIntField *DocIDKKM_DREPKKM;
	TFIBWideStringField *DocPRIM_DREPKKM;
	TFIBLargeIntField *DocIDTPRICE_DREPKKM;
	TFIBLargeIntField *DocIDBASE_DREPKKM;
	TFIBLargeIntField *DocIDBSCHET_DREPKKM;
	TFIBWideStringField *DocNAMEKKM;
	TFIBWideStringField *DocNAME_TPRICE;
	TFIBWideStringField *DocNAMEBSCHET;
	TFIBLargeIntField *DocTID_DREPKKMT;
	TFIBWideStringField *DocTGID_DREPKKMT;
	TFIBLargeIntField *DocTIDDOC_DREPKKMT;
	TFIBLargeIntField *DocTIDNOM_DREPKKMT;
	TFIBLargeIntField *DocTIDED_DREPKKMT;
	TFIBLargeIntField *DocTIDBASE_DREPKKMT;
	TFIBIntegerField *DocTNDS_DREPKKMT;
	TFIBBCDField *DocTSUMNDS_DREPKKMT;
	TFIBWideStringField *DocTKRNAMENOM;
	TFIBWideStringField *DocTNAMENOM;
	TFIBWideStringField *DocTNAMEED;
	TFIBWideStringField *DocAllTDOC;
	TFIBLargeIntField *DocAllIDBUSINOP_GALLDOC;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBWideStringField *DocAllPREFIKS_NUM_GALLDOC;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocTAfterDelete(TDataSet *DataSet);
	void __fastcall DocTBeforeDelete(TDataSet *DataSet);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocAllPOSDOCChange(TField *Sender);
	void __fastcall DocTKOL_DREPKKMTChange(TField *Sender);
	void __fastcall DocTKF_DREPKKMTChange(TField *Sender);
	void __fastcall DocTPRICE_DREPKKMTChange(TField *Sender);
	void __fastcall DocAllIDBASE_GALLDOCChange(TField *Sender);
	void __fastcall DocIDKKM_DREPKKMChange(TField *Sender);
private:	// User declarations
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

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

		float OplataNal;
		float OplataPC;

			bool flGetNumberDoc;  //при созданнии нового документа не будем
							  // каждый раз получать номер документа

public:		// User declarations
		__fastcall TDMDocRepKKM(TComponent* Owner);


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

        //регистр себестоимости реализации
        //регистр отриц себестоимости реализации
        void NewDoc(void);
		void OpenDoc(__int64 IdDoc);
        bool SaveDoc(void);
		bool DvRegDoc(void);
		bool CancelDvRegDoc(void);
		bool DeleteDoc(__int64 id);
		void AddDocNewString(void);
		void DeleteStringDoc(void);
		void CloseDoc(void);
		double Summa(void);

		bool NewElement;  // новый элемент
		bool Prosmotr;    //только просмотр
		bool Vibor;       //для выбора
		__int64 IdDoc;           //идентификатор текущей записи
		__int64 IdTypePrice;
		__int64 IdSklad;
		bool NoEdit;


        bool AutoRaschet;
        bool EnableDvReg;

		bool CreateReportKKM(   __int64 id_sklad,
								__int64 id_kkm,
								__int64 id_firm,
                                int number_kl ,
                                TDateTime NachInterval,
                                TDateTime ConInterval
                                );




		void GetSumOplata(      __int64 id_sklad,
								__int64 id_kkm,
                                __int64 id_firm,
                                int number_kl ,
                                TDateTime NachInterval,
                                TDateTime ConInterval
                                );

		bool SkladRozn;
		bool NoOtrOstatok;


		int GetNumberNewDoc(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMDocRepKKM *DMDocRepKKM;
//---------------------------------------------------------------------------
#endif
