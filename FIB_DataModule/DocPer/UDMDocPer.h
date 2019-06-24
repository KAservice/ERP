//---------------------------------------------------------------------------

#ifndef UDMDocPerH
#define UDMDocPerH
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
class TDMDocPer : public TDataModule
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
	TFIBBCDField *DocTKOLPERT;
	TFIBBCDField *DocTKFPERT;
	TFIBBCDField *DocTPRICEPERT;
	TFIBBCDField *DocTSUMPERT;
	TIntegerField *DocTRECNO;
	TpFIBTransaction *IBTrDvReg;
	TpFIBDataSet *NumDoc;
	TpFIBDataSet *Firma;
	TpFIBDataSet *Sklad;
	TpFIBDataSet *SkladPol;
	TpFIBQuery *pFIBQ;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBQuery *QueryDvReg;
	TFIBBCDField *DocTNAC_DPERT;
	TFIBIntegerField *DocTNDS_DPERT;
	TFIBBCDField *DocTSUMNDS_DPERT;
	TFIBLargeIntField *SkladPolIDSKLAD;
	TFIBWideStringField *SkladPolNAMESKLAD;
	TFIBWideStringField *SkladPolMOLSKLAD;
	TFIBWideStringField *SkladPolADRSKLAD;
	TFIBIntegerField *SkladPolTSKLAD;
	TFIBWideStringField *SkladPolGID_SSKLAD;
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
	TFIBLargeIntField *DocIDPER;
	TFIBLargeIntField *DocIDDOCPER;
	TFIBLargeIntField *DocIDSKLPOLPER;
	TFIBWideStringField *DocPRIMPER;
	TFIBWideStringField *DocGID_DPER;
	TFIBLargeIntField *DocIDRTPRICE_DPER;
	TFIBLargeIntField *DocIDBASE_DPER;
	TFIBWideStringField *DocNAMESKLAD;
	TFIBLargeIntField *DocTIDPERT;
	TFIBLargeIntField *DocTIDDOCPERT;
	TFIBLargeIntField *DocTIDNOMPERT;
	TFIBLargeIntField *DocTIDEDPERT;
	TFIBWideStringField *DocTGID_DPERT;
	TFIBLargeIntField *DocTIDBASE_DPERT;
	TFIBWideStringField *DocTNAMENOM;
	TFIBWideStringField *DocTNAMEED;
	TFIBSmallIntField *DocTTNOM;
	TFIBLargeIntField *DocAllIDBUSINOP_GALLDOC;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBIntegerField *DocTCODENOM;
	TFIBWideStringField *DocTARTNOM;
	TFIBWideStringField *DocTSHED;
	TFIBWideStringField *DocAllPREFIKS_NUM_GALLDOC;
	TFIBBCDField *DocTSEB_PRICE_DPERT;
	TFIBBCDField *DocTSEB_SUM_DPERT;
	TFIBBCDField *DocTNAC_SUM_ED;
	TFIBBCDField *DocTNAC_SUM;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocTAfterDelete(TDataSet *DataSet);
	void __fastcall DocTBeforeDelete(TDataSet *DataSet);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocAllPOSDOCChange(TField *Sender);
	void __fastcall DocAllIDSKLDOCChange(TField *Sender);
	void __fastcall DocIDSKLPOLPERChange(TField *Sender);
	void __fastcall DocTPRICEPERTChange(TField *Sender);
	void __fastcall DocTKOLPERTChange(TField *Sender);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocAllIDBASE_GALLDOCChange(TField *Sender);
	void __fastcall DocAllIDFIRMDOCChange(TField *Sender);
	void __fastcall DocTSEB_PRICE_DPERTChange(TField *Sender);
	void __fastcall DocTSEB_SUM_DPERTChange(TField *Sender);
	void __fastcall DocTSUMPERTChange(TField *Sender);
private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


		double Summa(void);
		double SummaDoc;

		double TekSummaDoc;
		double OldSummaStr;
		double NewSummaStr;

		bool flGetNumberDoc;  //при созданнии нового документа не будем
							  // каждый раз получать номер документа
public:		// User declarations
        __fastcall TDMDocPer(TComponent* Owner);

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
        void CloseDoc(void);


		__int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc);

        bool NewElement;  // новый элемент
		bool Prosmotr;    //только просмотр
		__int64 IdDoc;           //идентификатор текущей записи
		__int64 IdGrp;        // идетификатор группы
        __int64 IdElementaMaster;  //идентификатор внешенго справочника-владельца





        bool EnableDvReg;
		bool SkladPolRozn;
		bool SkladOtprRozn;
		bool NoOtrOstatok;
		int GetNumberNewDoc(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMDocPer *DMDocPer;
//---------------------------------------------------------------------------
#endif
