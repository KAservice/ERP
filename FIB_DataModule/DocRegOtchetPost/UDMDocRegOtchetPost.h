//---------------------------------------------------------------------------

#ifndef UDMDocRegOtchetPostH
#define UDMDocRegOtchetPostH
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
class TDMDocRegOtchetPost : public TDataModule
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
	TFIBDateTimeField *DocAllPOSDOC;
	TFIBSmallIntField *DocAllPRDOC;
	TFIBIntegerField *DocAllNUMDOC;
	TFIBBCDField *DocAllSUMDOC;
	TIntegerField *DocTRECNO;
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
	TFIBWideStringField *DocAllFNAME_USER;
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocAllTDOC;
	TFIBLargeIntField *DocAllIDBUSINOP_GALLDOC;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBWideStringField *DocAllPREFIKS_NUM_GALLDOC;
	TFIBLargeIntField *DocID_DRG_OTCHPOST;
	TFIBLargeIntField *DocIDBASE_DRG_OTCHPOST;
	TFIBLargeIntField *DocIDDOC_DRG_OTCHPOST;
	TFIBWideStringField *DocDESCR_DRG_OTCHPOST;
	TFIBLargeIntField *DocTID_DRG_OTCHPOSTT;
	TFIBLargeIntField *DocTIDBASE_DRG_OTCHPOSTT;
	TFIBLargeIntField *DocTIDDOC_DRG_OTCHPOSTT;
	TFIBSmallIntField *DocTTDV_DRG_OTCHPOSTT;
	TFIBLargeIntField *DocTIDFIRM_DRG_OTCHPOSTT;
	TFIBLargeIntField *DocTIDSKLAD_DRG_OTCHPOSTT;
	TFIBLargeIntField *DocTIDPOST_DRG_OTCHPOSTT;
	TFIBLargeIntField *DocTIDDOCPOST_DRG_OTCHPOSTT;
	TFIBLargeIntField *DocTIDNOM_DRG_OTCHPOSTT;
	TFIBBCDField *DocTKOL_DRG_OTCHPOSTT;
	TFIBBCDField *DocTSUM_DRG_OTCHPOSTT;
	TFIBWideStringField *DocTNAMEFIRM;
	TFIBWideStringField *DocTNAMESKLAD;
	TFIBWideStringField *DocTNAMEKLIENT;
	TFIBWideStringField *DocTPREFIKS_NUM_GALLDOC;
	TFIBIntegerField *DocTNUMDOC;
	TFIBDateTimeField *DocTPOSDOC;
	TFIBWideStringField *DocTNAMENOM;
	TFIBIntegerField *DocTCODENOM;
	TFIBWideStringField *DocTARTNOM;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocAllPOSDOCChange(TField *Sender);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocAllIDBASE_GALLDOCChange(TField *Sender);
private:	// User declarations

	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
			bool flGetNumberDoc;  //при созданнии нового документа не будем
							  // каждый раз получать номер документа
public:		// User declarations
        __fastcall TDMDocRegOtchetPost(TComponent* Owner);

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
extern PACKAGE TDMDocRegOtchetPost *DMDocRegOtchetPost;
//---------------------------------------------------------------------------
#endif
