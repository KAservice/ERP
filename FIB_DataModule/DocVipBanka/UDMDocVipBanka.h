//---------------------------------------------------------------------------

#ifndef UDMDocVipBankaH
#define UDMDocVipBankaH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"


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
class TDMDocVipBanka : public TDataModule
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
	TpFIBDataSet *NumDoc;
	TpFIBQuery *pFIBQ;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBQuery *QueryDvReg;
	TFIBBCDField *DocAllIDDOC;
	TFIBDateTimeField *DocAllPOSDOC;
	TFIBSmallIntField *DocAllPRDOC;
	TFIBIntegerField *DocAllNUMDOC;
	TFIBBCDField *DocAllIDFIRMDOC;
	TFIBBCDField *DocAllIDSKLDOC;
	TFIBBCDField *DocAllIDKLDOC;
	TFIBBCDField *DocAllIDDOGDOC;
	TFIBBCDField *DocAllSUMDOC;
	TFIBBCDField *DocAllIDUSERDOC;
	TFIBBCDField *DocAllIDDOCOSNDOC;
	TFIBBCDField *DocAllIDEXTDOC;
	TFIBBCDField *DocAllIDBASE_GALLDOC;
	TIntegerField *DocTRECNO;
	TFIBBCDField *DocID_DVIPBANK;
	TFIBBCDField *DocIDDOC_DVIPBANK;
	TFIBBCDField *DocIDBASE_DVIPBANK;
	TFIBBCDField *DocIDBSCHET_DVIPBANK;
	TFIBBCDField *DocTID_DVIPBANKT;
	TFIBBCDField *DocTIDBASE_DVIPBANKT;
	TFIBBCDField *DocTIDDOC_DVIPBANKT;
	TFIBBCDField *DocTIDKLIENT_DVIPBANKT;
	TFIBDateField *DocTDATEPP_DVIPBANKT;
	TFIBBCDField *DocTPRIHOD_DVIPBANKT;
	TFIBIntegerField *DocTPRIHODNDS_DVIPBANKT;
	TFIBBCDField *DocTPRIHODSUMNDS_DVIPBANKT;
	TFIBBCDField *DocTRASHOD_DVIPBANKT;
	TFIBIntegerField *DocTRASHODNDS_DVIPBANKT;
	TFIBBCDField *DocTRASHODSUMNDS_DVIPBANKT;
	TFIBIntegerField *DocTOPER_DVIPBANKT;
	TFIBWideStringField *DocAllTDOC;
	TFIBWideStringField *DocAllGID_DOC;
	TFIBIntegerField *DocAllTYPEEXTDOC;
	TFIBWideStringField *DocAllFNAME_USER;
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocAllNAMEFIRM;
	TFIBWideStringField *DocAllNAMESKLAD;
	TFIBWideStringField *DocPRIM_DVIPBANK;
	TFIBWideStringField *DocNAMEBSCHET;
	TFIBWideStringField *DocTNUMPP_DVIPBANKT;
	TFIBWideStringField *DocTTEXTPP_DVIPBANKT;
	TFIBWideStringField *DocTNAMEKLIENT;
	TFIBBCDField *DocAllIDPROJECT_GALLDOC;
	TFIBBCDField *DocAllIDBUSINOP_GALLDOC;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBWideStringField *DocAllPREFIKS_NUM_GALLDOC;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DocT1CalcFields(TDataSet *DataSet);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocAllPOSDOCChange(TField *Sender);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocAllIDBASE_GALLDOCChange(TField *Sender);
	void __fastcall DocIDBSCHET_DVIPBANKChange(TField *Sender);
	void __fastcall DocAllIDFIRMDOCChange(TField *Sender);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		bool flGetNumberDoc;  //при созданнии нового документа не будем
							  // каждый раз получать номер документа
public:		// User declarations
		__fastcall TDMDocVipBanka(TComponent* Owner);


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

		__int64 IdDoc;           //идентификатор текущей записи
		bool Prosmotr;    //только просмотр
		bool EnableDvReg; //разрешить движение регистров

		bool NewDoc(void);
		bool OpenDoc(__int64 IdDoc);
		bool SaveDoc(void);
		bool DeleteDoc(__int64 id);

        bool DvRegDoc(void);
		bool CancelDvRegDoc(void);

		void TableAppend(void);
		void TableDelete(void);

        int GetNumberNewDoc(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMDocVipBanka *DMDocVipBanka;
//---------------------------------------------------------------------------
#endif
