//---------------------------------------------------------------------------

#ifndef UDMDocRevH
#define UDMDocRevH
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
class TDMDocRev : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceDoc;
        TDataSource *DataSourceDocT;
        TDataSource *DataSourceDocAll;
	TpFIBDataSet *DocAll;
	TpFIBDataSet *Doc;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *DocT;
	TFIBDateTimeField *DocAllPOSDOC;
	TFIBSmallIntField *DocAllPRDOC;
	TFIBIntegerField *DocAllNUMDOC;
	TFIBBCDField *DocAllSUMDOC;
	TpFIBTransaction *IBTrDvReg;
	TpFIBDataSet *NumDoc;
	TpFIBDataSet *IBQPoGrp;
	TpFIBDataSet *IBQ;
	TFIBIntegerField *DocTTNOM;
	TFIBBCDField *DocTKOL_DREVT;
	TFIBBCDField *DocTKF_DREVT;
	TFIBBCDField *DocTRPRICE_DREVT;
	TFIBBCDField *DocTRSUM_DREVT;
	TIntegerField *DocTRECNO;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBQuery *QueryDvReg;
	TpFIBDataSet *Ostatki;
	TFIBBCDField *OstatkiKFED;
	TFIBBCDField *OstatkiSUM;
	TFIBLargeIntField *OstatkiIDNOM;
	TFIBIntegerField *OstatkiCODENOM;
	TFIBWideStringField *OstatkiNAMENOM;
	TFIBLargeIntField *OstatkiIDED;
	TFIBWideStringField *OstatkiNAMEED;
	TFIBWideStringField *IBQPoGrpNAMEGN;
	TFIBLargeIntField *IBQPoGrpIDGN;
	TFIBWideStringField *IBQPoGrpNAMENOM;
	TFIBIntegerField *IBQPoGrpTNOM;
	TFIBIntegerField *IBQPoGrpCODENOM;
	TFIBLargeIntField *IBQPoGrpID_DREVT;
	TFIBLargeIntField *IBQPoGrpIDDOC_DREVT;
	TFIBLargeIntField *IBQPoGrpIDNOM_DREVT;
	TFIBLargeIntField *IBQPoGrpIDED_DREVT;
	TFIBBCDField *IBQPoGrpKOL_DREVT;
	TFIBBCDField *IBQPoGrpKF_DREVT;
	TFIBBCDField *IBQPoGrpRPRICE_DREVT;
	TFIBBCDField *IBQPoGrpRSUM_DREVT;
	TFIBWideStringField *IBQPoGrpNAMEED;
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
	TFIBWideStringField *DocAllNAME_USER;
	TFIBWideStringField *DocAllFNAME_USER;
	TFIBWideStringField *DocAllNAMEFIRM;
	TFIBWideStringField *DocAllNAMESKLAD;
	TFIBLargeIntField *DocID_DREV;
	TFIBWideStringField *DocGID_DREV;
	TFIBLargeIntField *DocIDDOC_DREV;
	TFIBLargeIntField *DocIDINV_DREV;
	TFIBWideStringField *DocDESCR_DREV;
	TFIBLargeIntField *DocIDRTPRICE_DREV;
	TFIBLargeIntField *DocIDBASE_DREV;
	TFIBWideStringField *DocNAME_SINV;
	TFIBWideStringField *DocTNAMEGN;
	TFIBLargeIntField *DocTIDGN;
	TFIBWideStringField *DocTNAMENOM;
	TFIBIntegerField *DocTCODENOM;
	TFIBLargeIntField *DocTID_DREVT;
	TFIBWideStringField *DocTGID_DREVT;
	TFIBLargeIntField *DocTIDDOC_DREVT;
	TFIBLargeIntField *DocTIDNOM_DREVT;
	TFIBLargeIntField *DocTIDED_DREVT;
	TFIBLargeIntField *DocTIDBASE_DREVT;
	TFIBLargeIntField *DocTIDEXT_DOUT_DREVT;
	TFIBLargeIntField *DocTIDEXT_BASE_DREVT;
	TFIBWideStringField *DocTNAMEED;
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocAllFNAMEFIRM;
	TFIBWideStringField *DocAllPADRFIRM;
	TFIBWideStringField *DocAllINNFIRM;
	TFIBLargeIntField *DocAllIDPROJECT_GALLDOC;
	TFIBLargeIntField *DocAllIDBUSINOP_GALLDOC;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBBCDField *DocTUCH_KOL_DREVT;
	TFIBBCDField *DocTUCH_RSUM_DREVT;
	TFIBBCDField *DocTUCH_SUM_DREVT;
	TFIBWideStringField *DocAllPREFIKS_NUM_GALLDOC;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocTAfterDelete(TDataSet *DataSet);
	void __fastcall DocTBeforeDelete(TDataSet *DataSet);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocTRPRICE_DREVTChange(TField *Sender);
	void __fastcall DocTKOL_DREVTChange(TField *Sender);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocAllIDBASE_GALLDOCChange(TField *Sender);
	void __fastcall DocAllPOSDOCChange(TField *Sender);
	void __fastcall DocAllIDSKLDOCChange(TField *Sender);
	void __fastcall DocAllIDFIRMDOCChange(TField *Sender);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

        double SummaDoc;
		double TekSummaDoc;
		double OldSummaStr;
		double NewSummaStr;
	AnsiString GetTextZaprosDocT(void);
	double Summa(void);

		bool flGetNumberDoc;  //при созданнии нового документа не будем
							  // каждый раз получать номер документа
public:		// User declarations
		__fastcall TDMDocRev(TComponent* Owner);

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
		bool DeleteDoc(__int64 id);



		__int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc);

        bool NewElement;  // новый элемент
        bool Prosmotr;    //только просмотр
		bool NoEdit;
		__int64 IdDoc;           //идентификатор текущей записи




        int IdGrpNom;


		bool ChangeTable;

		void AddOstatkiNaSklade(__int64 id_firm, __int64 id_sklad);

		bool EnableDvReg;
		int GetNumberNewDoc(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMDocRev *DMDocRev;
//---------------------------------------------------------------------------
#endif
