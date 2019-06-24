//---------------------------------------------------------------------------

#ifndef UDMDocVipuskProdH
#define UDMDocVipuskProdH
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
class TDMDocVipuskProd : public TDataModule
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
	TIntegerField *DocTRECNO;
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
	TFIBLargeIntField *DocID_DVIPPROD;
	TFIBLargeIntField *DocIDDOC_DVIPPROD;
	TFIBLargeIntField *DocIDBASE_DVIPPROD;
	TFIBWideStringField *DocPRIM_DVIPPROD;
	TFIBLargeIntField *DocIDRTPRICE_DVIPPROD;
	TFIBLargeIntField *DocTID_DVIPPRODT;
	TFIBLargeIntField *DocTIDDOC_DVIPPRODT;
	TFIBLargeIntField *DocTIDBASE_DVIPPRODT;
	TFIBLargeIntField *DocTIDNOM_DVIPPRODT;
	TFIBLargeIntField *DocTIDED_DVIPPRODT;
	TFIBLargeIntField *DocTIDPART_DVIPPRODT;
	TFIBBCDField *DocTKOL_DVIPPRODT;
	TFIBBCDField *DocTKF_DVIPPRODT;
	TFIBBCDField *DocTRPRICE_DVIPPRODT;
	TFIBBCDField *DocTRSUM_DVIPPRODT;
	TFIBWideStringField *DocTNAMENOM;
	TFIBWideStringField *DocTNAMEED;
	TFIBIntegerField *DocTTNOM;
	TFIBWideStringField *DocAllNAMEFIRM;
	TFIBWideStringField *DocAllNAMESKLAD;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBWideStringField *DocAllPREFIKS_NUM_GALLDOC;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DocTAfterDelete(TDataSet *DataSet);
	void __fastcall DocTBeforeDelete(TDataSet *DataSet);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocAllPOSDOCChange(TField *Sender);
	void __fastcall DocAllIDSKLDOCChange(TField *Sender);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocAllIDBASE_GALLDOCChange(TField *Sender);
	void __fastcall DocTKOL_DVIPPRODTChange(TField *Sender);
	void __fastcall DocTRPRICE_DVIPPRODTChange(TField *Sender);
	void __fastcall DocAllIDFIRMDOCChange(TField *Sender);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		IDMSprPart * Part;
//		TDMSprPrice * DMSprPrice;
		void CreateNewPart(void);

		double OldRSummaStr;
		double NewRSummaStr;

		bool flGetNumberDoc;  //при созданнии нового документа не будем
							  // каждый раз получать номер документа
public:		// User declarations
		__fastcall TDMDocVipuskProd(TComponent* Owner);

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
		bool SkladRozn;   //розничный склад
		bool EnableDvReg; //разрешить движение регистров

		bool NewDoc(void);
		bool OpenDoc(__int64 IdDoc);
		bool SaveDoc(void);
		bool DeleteDoc(__int64 id);

		bool DvRegDoc(void);
		bool CancelDvRegDoc(void);

		void TableAppend(void);
		void TableDelete(void);




		__int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc);


       int GetNumberNewDoc(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMDocVipuskProd *DMDocVipuskProd;
//---------------------------------------------------------------------------
#endif
