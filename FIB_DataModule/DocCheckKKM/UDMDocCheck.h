//---------------------------------------------------------------------------

#ifndef UDMDocCheckH
#define UDMDocCheckH
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
class TDMDocCheck : public TDataModule
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
	TFIBDateTimeField *DocAllPOSDOC;
	TFIBSmallIntField *DocAllPRDOC;
	TFIBIntegerField *DocAllNUMDOC;
	TpFIBTransaction *IBTrDvReg;
	TpFIBDataSet *NumDoc;
	TpFIBDataSet *SpisokTypePrice;
	TFIBIntegerField *SpisokTypePriceID_TPRICE;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBQuery *QueryDvReg;
	TpFIBDataSet *DocOsn;
	TDataSource *DataSourceDocOsn;
	TpFIBDataSet *DocOpl;
	TDataSource *DataSourceDocOpl;
	TFIBLargeIntField *DocAllIDDOC;
	TFIBWideStringField *DocAllTDOC;
	TFIBLargeIntField *DocAllIDFIRMDOC;
	TFIBLargeIntField *DocAllIDSKLDOC;
	TFIBLargeIntField *DocAllIDKLDOC;
	TFIBLargeIntField *DocAllIDDOGDOC;
	TFIBBCDField *DocAllSUMDOC;
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
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocAllNAMEFIRM;
	TFIBWideStringField *DocAllNAMESKLAD;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocOsnTDOC;
	TFIBDateTimeField *DocOsnPOSDOC;
	TFIBIntegerField *DocOsnNUMDOC;
	TIntegerField *DocOplRECNO;
	TFIBLargeIntField *DocIDCHK;
	TFIBLargeIntField *DocIDDOCCHK;
	TFIBLargeIntField *DocIDKKMCHK;
	TFIBLargeIntField *DocIDTPRICE;
	TFIBIntegerField *DocNCHECKCHK;
	TFIBIntegerField *DocNKLCHK;
	TFIBIntegerField *DocOPERCHK;
	TFIBBCDField *DocOPLNALCHK;
	TFIBBCDField *DocOPLPCCHK;
	TFIBBCDField *DocNALCHK;
	TFIBWideStringField *DocPRIMCHK;
	TFIBWideStringField *DocGID_DCHK;
	TFIBSmallIntField *DocDVREGCHK;
	TFIBWideStringField *DocSAVNUMCHK;
	TFIBWideStringField *DocMODELCHK;
	TFIBWideStringField *DocREGNUMCHK;
	TFIBLargeIntField *DocIDDCARDCHK;
	TFIBLargeIntField *DocIDBASE_DCHK;
	TFIBBCDField *DocSDACHA_DCHK;
	TFIBLargeIntField *DocIDBSCHET_DCHK;
	TFIBBCDField *DocOPLPLATCARD_DCHK;
	TFIBBCDField *DocOPLCREDITCARD_DCHK;
	TFIBBCDField *DocOPLPLATCARD_ALL_DCHK;
	TFIBBCDField *DocOPLCREDITCARD_ALL_DCHK;
	TFIBWideStringField *DocNAMEKKM;
	TFIBWideStringField *DocNAME_SDISCOUNT_CARD;
	TFIBWideStringField *DocNAMEBSCHET;
	TFIBLargeIntField *DocTIDCHKT;
	TFIBLargeIntField *DocTIDDOCCHKT;
	TFIBLargeIntField *DocTIDNOMCHKT;
	TFIBLargeIntField *DocTIDEDCHKT;
	TFIBBCDField *DocTKOLCHKT;
	TFIBBCDField *DocTKFCHKT;
	TFIBBCDField *DocTPRICECHKT;
	TFIBBCDField *DocTSUMCHKT;
	TFIBBCDField *DocTSKCHKT;
	TFIBBCDField *DocTNADCHKT;
	TFIBBCDField *DocTPRSKCHKT;
	TFIBBCDField *DocTPRNADCHKT;
	TFIBWideStringField *DocTGID_DCHKT;
	TFIBLargeIntField *DocTIDBASE_DCHKT;
	TFIBBCDField *DocTPRSK_CARD_DCHKT;
	TFIBBCDField *DocTPRSK_AUTO_DCHKT;
	TFIBIntegerField *DocTNDS_DCHKT;
	TFIBBCDField *DocTSUMNDS_DCHKT;
	TFIBWideStringField *DocTKRNAMENOM;
	TFIBWideStringField *DocTNAMENOM;
	TFIBWideStringField *DocTNAMEED;
	TFIBSmallIntField *DocTTNOM;
	TIntegerField *DocTRECNO;
	TFIBLargeIntField *DocOplID_DCHK_OPL;
	TFIBLargeIntField *DocOplIDBASE_DCHK_OPL;
	TFIBLargeIntField *DocOplIDCARD_DCHK_OPL;
	TFIBBCDField *DocOplSUMPLAT_DCHK_OPL;
	TFIBBCDField *DocOplSUMCREDIT_DCHK_OPL;
	TFIBLargeIntField *DocOplIDDOC_DCHK_OPL;
	TFIBWideStringField *DocOplNAME_SDISCOUNT_CARD;
	TFloatField *DocALLOPL;
	TFIBWideStringField *SpisokTypePriceNAME_TPRICE;
	TFIBWideStringField *SpisokTypePriceGID_STPRICE;
	TFIBIntegerField *DocTCODENOM;
	TFIBWideStringField *DocTARTNOM;
	TFIBWideStringField *DocTSHED;
	TFIBLargeIntField *DocAllIDBUSINOP_GALLDOC;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBBCDField *DocOPL_OTHER_DCHK;
	TFIBBCDField *DocTPRSK_HAND_DCHKT;
	TFIBSmallIntField *DocTNO_SK_DCHKT;
	TFIBLargeIntField *DocTIDGRPNOM;
	TFIBLargeIntField *DocTIDVID_SNOM;
	TFIBWideStringField *DocTNAMEGN;
	TFIBWideStringField *DocTNAME_SVIDNOM;
	TFIBWideStringField *DocAllPREFIKS_NUM_GALLDOC;



	TFIBLargeIntField *DocTIDTNOM_DCHKT;
	TFIBLargeIntField *DocTIDDEPARTMENT_DCHKT;
	TFIBIntegerField *DocTNUMOTDKKT_SDEPARTMENT;
	TFIBWideStringField *DocTNAME_SDEPARTMENT;
	TFIBWideStringField *DocTNAME_STNOM;
	TFIBWideStringField *DocFISCALSIGN_DCHK;
	TFIBWideStringField *DocPHONE_DCHK;
	TFIBWideStringField *DocEMAIL_DCHK;




        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocTAfterDelete(TDataSet *DataSet);
	void __fastcall DocTBeforeDelete(TDataSet *DataSet);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocAllPOSDOCChange(TField *Sender);
	void __fastcall DocOPLPCCHKChange(TField *Sender);
	void __fastcall DocNALCHKChange(TField *Sender);
	void __fastcall DocTKOLCHKTChange(TField *Sender);
	void __fastcall DocTPRICECHKTChange(TField *Sender);
	void __fastcall DocTSKCHKTGetText(TField *Sender, AnsiString &Text,
          bool DisplayText);
	void __fastcall DocTNADCHKTGetText(TField *Sender, AnsiString &Text,
          bool DisplayText);
	void __fastcall DocTPRSKCHKTChange(TField *Sender);
	void __fastcall DocTPRNADCHKTChange(TField *Sender);
	void __fastcall DocAllIDBASE_GALLDOCChange(TField *Sender);
	void __fastcall DocOsnTDOCGetText(TField *Sender, AnsiString &Text,
          bool DisplayText);
	void __fastcall DocTSUMCHKTChange(TField *Sender);
	void __fastcall DocOplNewRecord(TDataSet *DataSet);
	void __fastcall DocAllSUMDOCChange(TField *Sender);
	void __fastcall DocOPLCREDITCARD_ALL_DCHKChange(TField *Sender);
	void __fastcall DocOPLPLATCARD_ALL_DCHKChange(TField *Sender);
	void __fastcall DocOPLPLATCARD_DCHKChange(TField *Sender);
	void __fastcall DocOplSUMPLAT_DCHK_OPLChange(TField *Sender);
	void __fastcall DocBeforeEdit(TDataSet *DataSet);
	void __fastcall DocOplCalcFields(TDataSet *DataSet);
	void __fastcall DocOplBeforeEdit(TDataSet *DataSet);
	void __fastcall DocOplBeforeDelete(TDataSet *DataSet);
	void __fastcall DocOplAfterDelete(TDataSet *DataSet);
	void __fastcall DocOPLCREDITCARD_DCHKChange(TField *Sender);
	void __fastcall DocOplSUMCREDIT_DCHK_OPLChange(TField *Sender);
	void __fastcall DocCalcFields(TDataSet *DataSet);
	void __fastcall DocAllNAME_SINFBASE_OBMENGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText);
	void __fastcall DocOPERCHKGetText(TField *Sender, UnicodeString &Text, bool DisplayText);
	void __fastcall DocAllIDSKLDOCChange(TField *Sender);
	void __fastcall DocAllIDFIRMDOCChange(TField *Sender);
	void __fastcall DocIDKKMCHKChange(TField *Sender);

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

		bool flGetNumberDoc;  //при созданнии нового документа не будем
							  // каждый раз получать номер документа
public:		// User declarations
        __fastcall TDMDocCheck(TComponent* Owner);

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

		void AdddRecordInGurOperDiscountCard(void);

		int GetNumberNewDoc(void);




};
//---------------------------------------------------------------------------
extern PACKAGE TDMDocCheck *DMDocCheck;
//---------------------------------------------------------------------------
#endif
