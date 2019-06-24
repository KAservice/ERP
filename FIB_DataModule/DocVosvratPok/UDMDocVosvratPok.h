//---------------------------------------------------------------------------

#ifndef UDMDocVosvratPokH
#define UDMDocVosvratPokH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IDMSprPart.h"
#include "IDMSprPrice.h"

//-----------------------------------------------------------------------------
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
class TDMDocVosvratPok : public TDataModule
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
	TIntegerField *DocTRECNO;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBQuery *QueryDvReg;
	TpFIBDataSet *NumDoc;
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
	TFIBWideStringField *DocAllNAME_SDOG;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBLargeIntField *DocID_DVPOK;
	TFIBWideStringField *DocGID_DVPOK;
	TFIBLargeIntField *DocIDDOC_DVPOK;
	TFIBLargeIntField *DocIDTPRICE_DVPOK;
	TFIBLargeIntField *DocIDRTPRICE_DVPOK;
	TFIBWideStringField *DocDESCR_DVPOK;
	TFIBIntegerField *DocOPER_DVPOK;
	TFIBBCDField *DocSUM_DVPOK;
	TFIBLargeIntField *DocIDBASE_DVPOK;
	TFIBLargeIntField *DocTID_DVPOKT;
	TFIBWideStringField *DocTGID_DVPOKT;
	TFIBLargeIntField *DocTIDDOC_DVPOKT;
	TFIBLargeIntField *DocTIDNOM_DVPOKT;
	TFIBLargeIntField *DocTIDED_DVPOKT;
	TFIBLargeIntField *DocTIDPART_DVPOKT;
	TFIBBCDField *DocTKOL_DVPOKT;
	TFIBBCDField *DocTKF_DVPOKT;
	TFIBBCDField *DocTPRICE_DVPOKT;
	TFIBBCDField *DocTSUM_DVPOKT;
	TFIBBCDField *DocTRPRICE_DVPOKT;
	TFIBBCDField *DocTRSUM_DVPOKT;
	TFIBLargeIntField *DocTIDBASE_DVPOKT;
	TFIBIntegerField *DocTNDS_DVPOKT;
	TFIBBCDField *DocTSUMNDS_DVPOKT;
	TFIBWideStringField *DocTNAMENOM;
	TFIBWideStringField *DocTNAMEED;
	TFIBWideStringField *DocKLIENT_NAME_DVPOK;
	TFIBWideStringField *DocKLIENT_ADR_DVPOK;
	TFIBWideStringField *DocKLIENT_PHONE_DVPOK;
	TFIBWideStringField *DocKLIENT_PASSPORT_DVPOK;
	TFIBWideStringField *DocPRICHINA_DVPOK;
	TFIBWideStringField *DocNUMDOCSALE_DVPOK;
	TFIBDateTimeField *DocPOSDOCSALE_DVPOK;
	TFIBWideStringField *DocNUMDOCKL_DVPOK;
	TFIBDateTimeField *DocPOSDOCKL_DVPOK;
	TpFIBDataSet *DocOsn;
	TFIBWideStringField *DocOsnTDOC;
	TFIBDateTimeField *DocOsnPOSDOC;
	TFIBIntegerField *DocOsnNUMDOC;
	TDataSource *DataSourceDocOsn;
	TFIBWideStringField *DocAllPREFIKS_NUM_GALLDOC;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DocTAfterDelete(TDataSet *DataSet);
	void __fastcall DocTBeforeDelete(TDataSet *DataSet);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocAllPOSDOCChange(TField *Sender);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocTPRICE_DVPOKTChange(TField *Sender);
	void __fastcall DocTKOL_DVPOKTChange(TField *Sender);
	void __fastcall DocTKF_DVPOKTChange(TField *Sender);
	void __fastcall DocTRPRICE_DVPOKTChange(TField *Sender);
	void __fastcall DocTRSUM_DVPOKTChange(TField *Sender);
	void __fastcall DocTAfterInsert(TDataSet *DataSet);
	void __fastcall DocTBeforeEdit(TDataSet *DataSet);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocAllIDBASE_GALLDOCChange(TField *Sender);
	void __fastcall DocOsnTDOCGetText(TField *Sender, UnicodeString &Text, bool DisplayText);
	void __fastcall DocAllIDSKLDOCChange(TField *Sender);
	void __fastcall DocAllIDFIRMDOCChange(TField *Sender);

private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		IDMSprPart * Part;
		IDMSprPrice * DMSprPrice;
		double Summa(void);
		void CreateNewPart(void);

        double SummaDoc;
		double TekSummaDoc;
		double OldSummaStr;
		double NewSummaStr;

		double OldRSummaStr;
		double NewRSummaStr;
		double OldSum;
		double OldRSum;

		bool flGetNumberDoc;  //при созданнии нового документа не будем
							  // каждый раз получать номер документа

public:		// User declarations
		__fastcall TDMDocVosvratPok(TComponent* Owner);

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
		void OpenDocOsn(void);
        bool SaveDoc(void);
        bool DvRegDoc(void);
        bool CancelDvRegDoc(void);
        void AddDocNewString(void);
        void DeleteStringDoc(void);
		bool DeleteDoc(__int64 id);



        bool NewElement;  // новый элемент
		bool Prosmotr;    //только просмотр
		__int64 IdDoc;           //идентификатор текущей записи




		__int64 IdTypePrice;
        bool IsmPrice;
        bool IsmSum;

		__int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc);


		void AddZakPrice(void);

		bool EnableDvReg;
		int GetNumberNewDoc(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMDocVosvratPok *DMDocVosvratPok;
//---------------------------------------------------------------------------
#endif
