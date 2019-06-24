//---------------------------------------------------------------------------

#ifndef UDMDocOstNomH
#define UDMDocOstNomH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IDMSprPart.h"

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
class TDMDocOstNom : public TDataModule
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
	TFIBBCDField *DocTKOLOSNT;
	TFIBBCDField *DocTKFOSNT;
	TFIBBCDField *DocTPRICEOSNT;
	TFIBBCDField *DocTSUMOSNT;
	TFIBIntegerField *DocTTNOM;
	TIntegerField *DocTRECNO;
	TpFIBDataSet *NumDoc;
	TpFIBDataSet *Grp;
	TpFIBDataSet *El;
	TpFIBDataSet *IBQ;
	TpFIBQuery *pFIBQ;
	TpFIBDataSet *DocOsn;
	TFIBIntegerField *DocOsnNUMDOC;
	TFIBDateTimeField *DocOsnPOSDOC;
	TFIBBCDField *DocRSUM_DOSN;
	TFIBBCDField *DocTRPRICE_DOSNT;
	TFIBBCDField *DocTRSUM_DOSNT;
	TFIBBCDField *DocTNAC_DOSNT;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBQuery *QueryDvReg;
	TFIBIntegerField *DocTNDS_DOSNT;
	TFIBBCDField *DocTSUMNDS_DOSNT;
	TFIBDateTimeField *DocTSRGODNPART;
	TFIBWideStringField *DocOsnTDOC;
	TFIBWideStringField *GrpNAMEGN;
	TFIBLargeIntField *GrpIDGN;
	TFIBBCDField *GrpSUMMA;
	TFIBWideStringField *ElNAMENOM;
	TFIBWideStringField *ElNAMEED;
	TFIBBCDField *ElSUMMA;
	TFIBFloatField *ElSUMKOL;
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
	TFIBWideStringField *DocAllFNAME_USER;
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocAllNAMEFIRM;
	TFIBWideStringField *DocAllNAMESKLAD;
	TFIBLargeIntField *DocIDOSN;
	TFIBLargeIntField *DocIDDOCOSN;
	TFIBWideStringField *DocPRIMOSN;
	TFIBLargeIntField *DocIDTPRICEOSN;
	TFIBWideStringField *DocGID_DOSN;
	TFIBLargeIntField *DocIDRTPRICE_DOSN;
	TFIBLargeIntField *DocIDBASE_DOSN;
	TFIBIntegerField *DocOPER_DOSN;
	TFIBWideStringField *DocNAME_TPRICE;
	TFIBLargeIntField *DocTIDOSNT;
	TFIBLargeIntField *DocTIDDOCOSNT;
	TFIBLargeIntField *DocTIDNOMOSNT;
	TFIBLargeIntField *DocTIDEDOSNT;
	TFIBLargeIntField *DocTIDPARTOSNT;
	TFIBWideStringField *DocTGID_DOSNT;
	TFIBLargeIntField *DocTIDBASE_DOSNT;
	TFIBWideStringField *DocTNAMENOM;
	TFIBWideStringField *DocTNAMEED;
	TFIBWideStringField *DocTGTDPART;
	TFIBWideStringField *DocTSERTPART;
	TFIBLargeIntField *DocAllIDBUSINOP_GALLDOC;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBWideStringField *DocAllPREFIKS_NUM_GALLDOC;
	TFIBWideStringField *DocTARTNOM;
	TFIBIntegerField *DocTCODENOM;
	TFIBWideStringField *DocTSHED;
	TpFIBDataSet *TypeNom;
	TFIBLargeIntField *TypeNomID_STNOM;
	TFIBWideStringField *TypeNomNAME_STNOM;
	TFIBLargeIntField *DocTIDTNOM_DOSNT;
	TStringField *DocTNAME_TYPE_NOM;
	TFIBLargeIntField *DocAllIDOBJECT_GALLDOC;
	TFIBWideStringField *DocAllNAME_SOBJECT;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocTAfterDelete(TDataSet *DataSet);
	void __fastcall DocTBeforeDelete(TDataSet *DataSet);
	void __fastcall DocAllPOSDOCChange(TField *Sender);
	void __fastcall DocTKOLOSNTChange(TField *Sender);
	void __fastcall DocTPRICEOSNTChange(TField *Sender);
	void __fastcall DocAllIDSKLDOCChange(TField *Sender);
	void __fastcall DocTRPRICE_DOSNTChange(TField *Sender);
	void __fastcall DocTSUMOSNTChange(TField *Sender);
	void __fastcall DocTRSUM_DOSNTChange(TField *Sender);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocAllIDBASE_GALLDOCChange(TField *Sender);
	void __fastcall DocAllIDFIRMDOCChange(TField *Sender);
private:	// User declarations
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
IDMSprPart * Part;
        double Summa(void);
		void CreateNewPart(void);

		        double SummaDoc;
		double OldSummaStr;
		double NewSummaStr;

		double OldRSummaStr;
		double NewRSummaStr;

				bool flGetNumberDoc;  //при созданнии нового документа не будем
							  // каждый раз получать номер документа
public:		// User declarations
		__fastcall TDMDocOstNom(TComponent* Owner);

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
		__int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc);
        
        bool NewElement;  // новый элемент
        bool Prosmotr;    //только просмотр
		__int64 IdDoc;           //идентификатор текущей записи
		__int64 IdGrp;        // идетификатор группы
		__int64 IdElementaMaster;  //идентификатор внешенго справочника-владельца





		bool AddDataInv(void);
		bool SearchStringPoNom(__int64 id_nom);

		bool SkladRozn;

		bool EnableDvReg;
		int GetNumberNewDoc(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMDocOstNom *DMDocOstNom;
//---------------------------------------------------------------------------
#endif
