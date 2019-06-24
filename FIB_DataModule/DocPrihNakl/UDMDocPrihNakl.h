//---------------------------------------------------------------------------

#ifndef UDMDocPrihNaklH
#define UDMDocPrihNaklH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IDMSprPart.h"
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
class TDMDocPrihNakl : public TDataModule
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
	TFIBBCDField *DocAllSUMDOC;
	TFIBBCDField *DocTKOLPRNT;
	TFIBBCDField *DocTKFPRNT;
	TFIBBCDField *DocTPRICEPRNT;
	TFIBBCDField *DocTSUMPRNT;
	TFIBIntegerField *DocTTNOM;
	TIntegerField *DocTRECNO;
	TpFIBTransaction *IBTrDvReg;
	TpFIBDataSet *NumDoc;
	TFIBBCDField *DocTNAC_DPRNT;
	TFIBBCDField *DocTRPRICE_DPRNT;
	TFIBBCDField *DocTRSUM_DPRNT;
	TFIBBCDField *DocRSUM_DPRN;
	TpFIBQuery *pFIBQ;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBQuery *QueryDvReg;
	TFIBDateTimeField *DocPOSDOCPOST_DPRN;
	TFIBLargeIntField *DocAllIDDOC;
	TFIBWideStringField *DocAllTDOC;
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
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocAllNAMEFIRM;
	TFIBWideStringField *DocAllNAMESKLAD;
	TFIBWideStringField *DocAllNAMEKLIENT;
	TFIBLargeIntField *DocIDPRN;
	TFIBLargeIntField *DocIDDOCPRN;
	TFIBWideStringField *DocPRIMDOC;
	TFIBLargeIntField *DocIDTPRICE;
	TFIBWideStringField *DocGID_DPRN;
	TFIBLargeIntField *DocIDRTPRICE_DPRN;
	TFIBLargeIntField *DocIDBASE_DPRN;
	TFIBLargeIntField *DocTIDPRNT;
	TFIBLargeIntField *DocTIDDOCPRNT;
	TFIBLargeIntField *DocTIDNOMPRNT;
	TFIBLargeIntField *DocTIDEDPRNT;
	TFIBLargeIntField *DocTIDPARTPRNT;
	TFIBWideStringField *DocTGID_DPRNT;
	TFIBLargeIntField *DocTIDBASE_DPRNT;
	TFIBIntegerField *DocTNDS_DPRNT;
	TFIBBCDField *DocTSUMNDS_DPRNT;
	TFIBWideStringField *DocTNAMENOM;
	TFIBWideStringField *DocTNAMEED;
	TFIBWideStringField *DocTGTDPART;
	TFIBWideStringField *DocTSERTPART;
	TFIBDateTimeField *DocTSRGODNPART;
	TFIBWideStringField *DocNUMDOCPOST_DPRN;
	TFIBLargeIntField *DocAllIDBUSINOP_GALLDOC;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBIntegerField *DocTCODENOM;
	TFIBWideStringField *DocTARTNOM;
	TFIBWideStringField *DocTSHED;
	TFIBWideStringField *DocAllPREFIKS_NUM_GALLDOC;
	TFIBBCDField *DocTNAC_SUM_ED;
	TFIBBCDField *DocTNAC_SUM;
	TFIBSmallIntField *DocFL_TREB_OTCHET_DPRN;
	TFIBSmallIntField *DocFL_OTV_HRAN_DPRN;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DocT1CalcFields(TDataSet *DataSet);
	void __fastcall DocTAfterDelete(TDataSet *DataSet);
	void __fastcall DocTBeforeDelete(TDataSet *DataSet);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocAllPOSDOCChange(TField *Sender);
	void __fastcall DocTKOLPRNTChange(TField *Sender);
	void __fastcall DocTPRICEPRNTChange(TField *Sender);
	void __fastcall DocAllIDSKLDOCChange(TField *Sender);
	void __fastcall DocTRPRICE_DPRNTChange(TField *Sender);
	void __fastcall DocTSUMPRNTChange(TField *Sender);
	void __fastcall DocTRSUM_DPRNTChange(TField *Sender);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocAllIDBASE_GALLDOCChange(TField *Sender);
	void __fastcall DocAllIDFIRMDOCChange(TField *Sender);
private:	// User declarations


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		double SummaDoc;
		double TekSummaDoc;
		double OldSummaStr;
		double NewSummaStr;

		double OldRSummaStr;
		double NewRSummaStr;
		IDMSprPart * Part;
		//IDMSprPrice * DMSprPrice;

				bool flGetNumberDoc;  //при созданнии нового документа не будем
							  // каждый раз получать номер документа
public:		// User declarations
		__fastcall TDMDocPrihNakl(TComponent* Owner);

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
        void CreateNewPart(void);

		bool Prosmotr;    //только просмотр
		__int64 IdDoc;           //идентификатор текущей записи
		__int64 IdGrp;        // идетификатор группы
		__int64 IdElementaMaster;  //идентификатор внешенго справочника-владельца



		__int64 IdTypePrice;


        bool IsmPrice;
        bool IsmSum;

		__int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc);

		bool UpdatePrice(void);
		bool SkladRozn;
		bool EnableDvReg;
		int GetNumberNewDoc(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMDocPrihNakl *DMDocPrihNakl;
//---------------------------------------------------------------------------
#endif
