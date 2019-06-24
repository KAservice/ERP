//---------------------------------------------------------------------------

#ifndef UDMDocSchetH
#define UDMDocSchetH
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
class TDMDocSchet : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceDocAll;
        TDataSource *DataSourceDoc;
        TDataSource *DataSourceDocT;
	TpFIBDataSet *DocAll;
	TpFIBDataSet *Doc;
	TpFIBDataSet *DocT;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBDateTimeField *DocAllPOSDOC;
	TFIBSmallIntField *DocAllPRDOC;
	TFIBIntegerField *DocAllNUMDOC;
	TFIBBCDField *DocAllSUMDOC;
	TFIBBCDField *DocTKOLSCHT;
	TFIBBCDField *DocTKFSCHT;
	TFIBBCDField *DocTPRICESCHT;
	TFIBBCDField *DocTSUMSCHT;
	TFIBIntegerField *DocTTNOM;
	TpFIBTransaction *IBTrDvReg;
	TpFIBDataSet *NumDoc;
	TIntegerField *DocTRECNO;
	TpFIBDataSet *IBQ;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBQuery *QueryDvReg;
	TFIBBCDField *DocAllIDDOC;
	TFIBBCDField *DocAllIDFIRMDOC;
	TFIBBCDField *DocAllIDSKLDOC;
	TFIBBCDField *DocAllIDKLDOC;
	TFIBBCDField *DocAllIDDOGDOC;
	TFIBBCDField *DocAllIDUSERDOC;
	TFIBBCDField *DocAllIDDOCOSNDOC;
	TFIBBCDField *DocIDSCH;
	TFIBBCDField *DocIDDOCSCH;
	TFIBBCDField *DocIDBSCHET_DSCH;
	TFIBBCDField *DocIDTPRICESCH;
	TFIBBCDField *DocTIDSCHT;
	TFIBBCDField *DocTIDDOCSCHT;
	TFIBBCDField *DocTIDNOMSCHT;
	TFIBBCDField *DocTIDEDSCHT;
	TFIBBCDField *DocAllIDEXTDOC;
	TpFIBQuery *pFIBQ;
	TFIBBCDField *DocIDBASE_DSCH;
	TFIBBCDField *DocTIDBASE_DSCHT;
	TFIBBCDField *DocAllIDBASE_GALLDOC;
	TFIBIntegerField *DocTNDS_DSCHT;
	TFIBBCDField *DocTSUMNDS_DSCHT;
	TFIBWideStringField *DocAllTDOC;
	TFIBWideStringField *DocAllGID_DOC;
	TFIBWideStringField *DocAllPREFIKSDOC;
	TFIBIntegerField *DocAllTYPEEXTDOC;
	TFIBWideStringField *DocAllFNAME_USER;
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocAllNAMEFIRM;
	TFIBWideStringField *DocAllNAMESKLAD;
	TFIBWideStringField *DocAllNAMEKLIENT;
	TFIBWideStringField *DocPRIMSCH;
	TFIBWideStringField *DocGID_DSCH;
	TFIBWideStringField *DocNAME_TPRICE;
	TFIBWideStringField *DocNAMEBSCHET;
	TFIBWideStringField *DocTGID_DSCHT;
	TFIBWideStringField *DocTNAMENOM;
	TFIBWideStringField *DocTNAMEED;
	TFIBBCDField *DocAllIDPROJECT_GALLDOC;
	TFIBBCDField *DocAllIDBUSINOP_GALLDOC;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBWideStringField *DocAllPREFIKS_NUM_GALLDOC;
	TFIBBCDField *DocTSUMSK_DSCHT;
	TFIBBCDField *DocTPRSK_DSCHT;
	TFIBSmallIntField *DocTNO_SK_DSCHT;
	TFIBBCDField *DocTPRSK_CARD_DSCHT;
	TFIBBCDField *DocTPRSK_AUTO_DSCHT;
	TFIBBCDField *DocTPRSK_HAND_DSCHT;
	TFIBWideStringField *DocTARTNOM;
	TFIBIntegerField *DocTCODENOM;
	TFIBWideStringField *DocTSHED;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocTAfterDelete(TDataSet *DataSet);
	void __fastcall DocTBeforeDelete(TDataSet *DataSet);
	void __fastcall DocAllPOSDOCChange(TField *Sender);
	void __fastcall DocTKOLSCHTChange(TField *Sender);
	void __fastcall DocTKFSCHTChange(TField *Sender);
	void __fastcall DocTPRICESCHTChange(TField *Sender);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocAllIDBASE_GALLDOCChange(TField *Sender);
	void __fastcall DocAllIDSKLDOCChange(TField *Sender);
	void __fastcall DocAllIDFIRMDOCChange(TField *Sender);
private:	// User declarations

	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
	double Summa(void);
	        double SummaDoc;
		double OldSummaStr;
		double NewSummaStr;

			bool flGetNumberDoc;  //при созданнии нового документа не будем
							  // каждый раз получать номер документа
public:		// User declarations
        __fastcall TDMDocSchet(TComponent* Owner);

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
        void CloseDoc(void);
        bool DvRegDoc(void);
        bool CancelDvRegDoc(void);
        void AddDocNewString(void);
        void DeleteStringDoc(void);
		bool DeleteDoc(__int64 id);


        bool NewElement;  // новый элемент
		bool Prosmotr;    //только просмотр
		__int64 IdDoc;           //идентификатор текущей записи






		bool EnableDvReg;
        int GetNumberNewDoc(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMDocSchet *DMDocSchet;
//---------------------------------------------------------------------------
#endif
