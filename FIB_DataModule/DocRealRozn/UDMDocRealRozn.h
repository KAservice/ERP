//---------------------------------------------------------------------------

#ifndef UDMDocRealRoznH
#define UDMDocRealRoznH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"

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
class TDMDocRealRozn : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceDoc;
        TDataSource *DataSourceDocT;
        TDataSource *DataSourceDocAll;
        TDataSource *DataSourcePay;
	TpFIBDataSet *DocAll;
	TpFIBDataSet *Doc;
	TpFIBDataSet *DocT;
	TpFIBDataSet *Pay;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBBCDField *DocFIRSTSUM_DREALROZN;
	TFIBDateTimeField *DocAllPOSDOC;
	TFIBSmallIntField *DocAllPRDOC;
	TFIBIntegerField *DocAllNUMDOC;
	TFIBBCDField *DocAllSUMDOC;
	TFIBBCDField *DocTKOL_DREALROZNT;
	TFIBBCDField *DocTKF_DREALROZNT;
	TFIBBCDField *DocTPRICE_DREALROZNT;
	TFIBBCDField *DocTSUM_DREALROZNT;
	TIntegerField *DocTRECNO;
	TFIBDateField *PayDO_DREALROZN_PAY;
	TFIBBCDField *PaySUM_DREALROZN_PAY;
	TpFIBDataSet *NumDoc;
	TpFIBTransaction *IBTrDvReg;
	TIntegerField *PayRECNO;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBQuery *QueryDvReg;
	TFIBBCDField *DocTPRICEFULL_DREALROZNT;
	TFIBBCDField *DocTPRSK_DREALROZNT;
	TFIBBCDField *DocTSUMSK_DREALROZNT;
	TFIBBCDField *DocTPRNAD_DREALROZNT;
	TFIBBCDField *DocTSUMNAD_DREALROZNT;
	TFIBIntegerField *DocTNDS_DREALROZNT;
	TFIBBCDField *DocTSUMNDS_DREALROZNT;
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
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocAllNAMEFIRM;
	TFIBWideStringField *DocAllNAMESKLAD;
	TFIBWideStringField *DocAllNAMEKLIENT;
	TFIBWideStringField *DocAllFNAME_USER;
	TFIBWideStringField *DocAllNAME_SDOG;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBLargeIntField *DocID_DREALROZN;
	TFIBLargeIntField *DocIDDOC_DREALROZN;
	TFIBWideStringField *DocGID_DREALROZN;
	TFIBLargeIntField *DocIDTPRICE_DREALROZN;
	TFIBWideStringField *DocPRIM_DREALROZN;
	TFIBLargeIntField *DocIDKKM_DREALROZN;
	TFIBLargeIntField *DocIDDCARD_DREALROZN;
	TFIBLargeIntField *DocIDBASE_DREALROZN;
	TFIBWideStringField *DocNAME_TPRICE;
	TFIBWideStringField *DocNAMEKKM;
	TFIBLargeIntField *DocTID_DREALROZNT;
	TFIBLargeIntField *DocTIDDOC_DREALROZNT;
	TFIBWideStringField *DocTGID_DREALROZNT;
	TFIBLargeIntField *DocTIDNOM_DREALROZNT;
	TFIBLargeIntField *DocTIDED_DREALROZNT;
	TFIBLargeIntField *DocTIDBASE_DREALROZNT;
	TFIBWideStringField *DocTNAMENOM;
	TFIBWideStringField *DocTNAMEED;
	TFIBSmallIntField *DocTTNOM;
	TFIBLargeIntField *PayID_DREALROZN_PAY;
	TFIBLargeIntField *PayIDDOC_DREALROZN_PAY;
	TFIBWideStringField *PayGID_DREALROZN_PAY;
	TFIBLargeIntField *PayIDBASE_DREALROZN_PAY;
	TFIBWideStringField *DocAllTDOC;
	TFIBLargeIntField *DocAllIDBUSINOP_GALLDOC;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBWideStringField *DocAllPREFIKS_NUM_GALLDOC;
	TFIBBCDField *DocTPRSK_CARD_DREALROZNT;
	TFIBBCDField *DocTPRSK_AUTO_DREALROZNT;
	TFIBBCDField *DocTPRSK_HAND_DREALROZNT;
	TFIBSmallIntField *DocTNO_SK_DREALROZNT;
	TFIBWideStringField *DocTARTNOM;
	TFIBIntegerField *DocTCODENOM;
	TFIBWideStringField *DocTSHED;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocTAfterDelete(TDataSet *DataSet);
	void __fastcall DocTBeforeDelete(TDataSet *DataSet);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall PayCalcFields(TDataSet *DataSet);
	void __fastcall PayNewRecord(TDataSet *DataSet);
	void __fastcall DocAllPOSDOCChange(TField *Sender);
	void __fastcall DocTKOL_DREALROZNTChange(TField *Sender);
	void __fastcall DocTPRICE_DREALROZNTChange(TField *Sender);
	void __fastcall DocTPRSK_DREALROZNTChange(TField *Sender);
	void __fastcall DocTPRNAD_DREALROZNTChange(TField *Sender);
	void __fastcall DocAllIDBASE_GALLDOCChange(TField *Sender);
	void __fastcall DocAllIDSKLDOCChange(TField *Sender);
	void __fastcall DocAllIDFIRMDOCChange(TField *Sender);
private:	// User declarations
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

	double Summa(void);

        double SummaDoc;
		double OldSummaStr;
		double NewSummaStr;

		double SebReal;
		double SebProd;
		double SebNom;
		double KolOtrSpisNom;
		double KolSpisNom;
		double KolBasEdinic;
		double KolBasEdinic2;
		double KFEd;

			bool flGetNumberDoc;  //при созданнии нового документа не будем
							  // каждый раз получать номер документа
public:		// User declarations
        __fastcall TDMDocRealRozn(TComponent* Owner);

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
		bool NoEdit;
		__int64 IdDoc;           //идентификатор текущей записи

		__int64 IdSklad;

        bool AutoRaschet;
        bool EnableDvReg;

        bool SkladRozn;
        bool NoOtrOstatok;

       int GetNumberNewDoc(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMDocRealRozn *DMDocRealRozn;
//---------------------------------------------------------------------------
#endif
