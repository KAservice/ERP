//---------------------------------------------------------------------------

#ifndef UREM_DMDocRegOtchetPostH
#define UREM_DMDocRegOtchetPostH
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
class TREM_DMDocRegOtchetPost : public TDataModule
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
	TFIBLargeIntField *DocAllID_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDBASE_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDFIRM_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDSKLAD_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDKLIENT_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDUSER_REM_GALLDOC;
	TFIBDateTimeField *DocAllPOS_REM_GALLDOC;
	TFIBIntegerField *DocAllNUM_REM_GALLDOC;
	TFIBSmallIntField *DocAllPR_REM_GALLDOC;
	TFIBWideStringField *DocAllTDOC_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDDOCOSN_REM_GALLDOC;
	TFIBIntegerField *DocAllTYPEEXTDOC_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDEXTDOC_REM_GALLDOC;
	TFIBBCDField *DocAllSUM_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDPROJECT_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDBUSINOP_REM_GALLDOC;
	TFIBWideStringField *DocAllPREFIKS_NUM_REM_GALLDOC;
	TFIBWideStringField *DocAllFNAME_USER;
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBLargeIntField *DocID_REM_DRG_OTCHPOST;
	TFIBLargeIntField *DocIDBASE_REM_DRG_OTCHPOST;
	TFIBLargeIntField *DocIDDOC_REM_DRG_OTCHPOST;
	TFIBWideStringField *DocDESCR_REM_DRG_OTCHPOST;
	TFIBLargeIntField *DocTID_REM_DRG_OTCHPOSTT;
	TFIBLargeIntField *DocTIDBASE_REM_DRG_OTCHPOSTT;
	TFIBLargeIntField *DocTIDDOC_REM_DRG_OTCHPOSTT;
	TFIBSmallIntField *DocTTDV_REM_DRG_OTCHPOSTT;
	TFIBLargeIntField *DocTIDFIRM_REM_DRG_OTCHPOSTT;
	TFIBLargeIntField *DocTIDSKLAD_REM_DRG_OTCHPOSTT;
	TFIBLargeIntField *DocTIDPOST_REM_DRG_OTCHPOSTT;
	TFIBLargeIntField *DocTIDDOCPOST_REM_DRG_OTCHPOSTT;
	TFIBLargeIntField *DocTIDNOM_REM_DRG_OTCHPOSTT;
	TFIBBCDField *DocTKOL_REM_DRG_OTCHPOSTT;
	TFIBBCDField *DocTSUM_REM_DRG_OTCHPOSTT;
	TFIBWideStringField *DocTNAMEFIRM;
	TFIBWideStringField *DocTNAMESKLAD;
	TFIBWideStringField *DocTNAMENOM;
	TFIBIntegerField *DocTCODENOM;
	TFIBWideStringField *DocTARTNOM;
	TFIBWideStringField *DocTPREFIKS_NUM_REM_GALLDOC;
	TFIBIntegerField *DocTNUM_REM_GALLDOC;
	TFIBDateTimeField *DocTPOS_REM_GALLDOC;
	TFIBWideStringField *DocTNAMEKLIENT;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocAllPOS_REM_GALLDOCChange(TField *Sender);
	void __fastcall DocAllIDBASE_REM_GALLDOCChange(TField *Sender);
private:	// User declarations

	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
			bool flGetNumberDoc;  //при созданнии нового документа не будем
							  // каждый раз получать номер документа
public:		// User declarations
        __fastcall TREM_DMDocRegOtchetPost(TComponent* Owner);

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
extern PACKAGE TREM_DMDocRegOtchetPost *REM_DMDocRegOtchetPost;
//---------------------------------------------------------------------------
#endif
