//---------------------------------------------------------------------------

#ifndef UDMDocVosvratPostH
#define UDMDocVosvratPostH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"


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
class TDMDocVosvratPost : public TDataModule
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
	TIntegerField *DocTRECNO;
	TpFIBDataSet *NumDoc;
	TpFIBTransaction *IBTrDvReg;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBQuery *QueryDvReg;
	TFIBLargeIntField *DocAllIDDOC;
	TFIBDateTimeField *DocAllPOSDOC;
	TFIBSmallIntField *DocAllPRDOC;
	TFIBWideStringField *DocAllTDOC;
	TFIBIntegerField *DocAllNUMDOC;
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
	TFIBLargeIntField *DocAllIDBUSINOP_GALLDOC;
	TFIBWideStringField *DocAllFNAME_USER;
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocAllNAMEFIRM;
	TFIBWideStringField *DocAllNAMESKLAD;
	TFIBWideStringField *DocAllNAMEKLIENT;
	TFIBWideStringField *DocAllTDOC_OSN;
	TFIBIntegerField *DocAllNUMDOC_OSN;
	TFIBDateTimeField *DocAllPOSDOC_OSN;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBLargeIntField *DocIDVPO;
	TFIBLargeIntField *DocIDDOCVPO;
	TFIBWideStringField *DocPRIMVPO;
	TFIBWideStringField *DocGID_DVPO;
	TFIBLargeIntField *DocIDTPRICE_DVPO;
	TFIBLargeIntField *DocIDBASE_DVPO;
	TFIBLargeIntField *DocIDRTPRICE_DVPO;
	TFIBIntegerField *DocOPER_DVPO;
	TFIBWideStringField *DocNUMDOCPOST_DVPO;
	TFIBDateTimeField *DocPOSDOCPOST_DVPO;
	TFIBWideStringField *DocNAME_TPRICE;
	TFIBLargeIntField *DocTIDVPOT;
	TFIBLargeIntField *DocTIDDOCVPOT;
	TFIBLargeIntField *DocTIDNOMVPOT;
	TFIBLargeIntField *DocTIDEDVPOT;
	TFIBBCDField *DocTKOLVPOT;
	TFIBBCDField *DocTKFVPOT;
	TFIBBCDField *DocTPRICEVPOT;
	TFIBBCDField *DocTSUMVPOT;
	TFIBWideStringField *DocTGID_DVPOT;
	TFIBLargeIntField *DocTIDBASE_DVPOT;
	TFIBBCDField *DocTRPRICE_DVPOT;
	TFIBBCDField *DocTRSUM_DVPOT;
	TFIBIntegerField *DocTNDS_DVPOT;
	TFIBBCDField *DocTSUMNDS_DVPOT;
	TFIBWideStringField *DocTNAMENOM;
	TFIBWideStringField *DocTNAMEED;
	TFIBSmallIntField *DocTTNOM;
	TFIBLargeIntField *DocIDGRPOL_DVPO;
	TFIBLargeIntField *DocIDBSCHET_DVPO;
	TFIBLargeIntField *DocIDRSCHETKLIENT_DVPO;
	TFIBLargeIntField *DocIDRSCHETGRPOL_DVPO;
	TFIBWideStringField *DocNAMEKLIENT;
	TFIBWideStringField *DocNAMEBSCHET;
	TFIBWideStringField *DocNAME_RSCHET_KLIENT;
	TFIBWideStringField *DocNAME_RSCHET_GRPOL;
	TFIBWideStringField *DocTARTNOM;
	TFIBIntegerField *DocTCODENOM;
	TFIBWideStringField *DocTSHED;
	TFIBWideStringField *DocAllPREFIKS_NUM_GALLDOC;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocTAfterDelete(TDataSet *DataSet);
	void __fastcall DocTBeforeDelete(TDataSet *DataSet);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocAllPOSDOCChange(TField *Sender);
	void __fastcall DocTKOLVPOTChange(TField *Sender);
	void __fastcall DocTPRICEVPOTChange(TField *Sender);
	void __fastcall DocAllIDSKLDOCChange(TField *Sender);
	void __fastcall DocAllIDBASE_GALLDOCChange(TField *Sender);
	void __fastcall DocTRPRICE_DVPOTChange(TField *Sender);
	void __fastcall DocAllTDOC_OSNGetText(TField *Sender, UnicodeString &Text, bool DisplayText);
	void __fastcall DocAllIDFIRMDOCChange(TField *Sender);

private:	// User declarations
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

        double Summa(void);
		void SpisatPartSoSklada(double Kol, double Sum);
	        double SummaDoc;
		double OldSummaStr;
		double NewSummaStr;

			bool flGetNumberDoc;  //при созданнии нового документа не будем
							  // каждый раз получать номер документа
public:		// User declarations
		__fastcall TDMDocVosvratPost(TComponent* Owner);

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
		void OpenDoc(__int64 IdDoc);
        bool SaveDoc(void);
        bool DvRegDoc(void);
        bool CancelDvRegDoc(void);
        void AddDocNewString(void);
        void DeleteStringDoc(void);
        void CloseDoc(void);

        bool DeleteDoc(__int64 id);

        bool NewElement;  // новый элемент
		bool Prosmotr;    //только просмотр
		__int64 IdDoc;           //идентификатор текущей записи





		bool SkladRozn;
		bool NoOtrOstatok;

		bool EnableDvReg;

		int GetNumberNewDoc(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMDocVosvratPost *DMDocVosvratPost;
//---------------------------------------------------------------------------
#endif
