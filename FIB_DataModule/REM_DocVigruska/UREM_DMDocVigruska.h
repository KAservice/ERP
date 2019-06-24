//---------------------------------------------------------------------------

#ifndef UREM_DMDocVigruskaH
#define UREM_DMDocVigruskaH
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
class TREM_DMDocVigruska : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceDocT;
        TDataSource *DataSourceDocAll;
	TpFIBDataSet *DocAll;
	TpFIBDataSet *DocT;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBTransaction *IBTrDvReg;
	TpFIBDataSet *NumDoc;
	TpFIBQuery *pFIBQ;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBQuery *QueryDvReg;
	TFIBLargeIntField *DocAllID_REM_GUR_VIGR;
	TFIBLargeIntField *DocAllIDBASE_REM_GUR_VIGR;
	TFIBLargeIntField *DocAllIDUSER_REM_GUR_VIGR;
	TFIBDateTimeField *DocAllPOS_REM_GUR_VIGR;
	TFIBIntegerField *DocAllNUM_REM_GUR_VIGR;
	TFIBWideStringField *DocAllGUID_TRANSACTION_REM_GUR_VIGR;
	TFIBWideStringField *DocAllCODE_STR_VIGR_REM_GUR_VIGR;
	TFIBWideStringField *DocAllGUID_VIGR_REM_GUR_VIGR;
	TFIBLargeIntField *DocAllIDKLIENT_REM_GUR_VIGR;
	TFIBLargeIntField *DocAllIDPRODUCER_REM_GUR_VIGR;
	TFIBWideStringField *DocAllNAME_SPRODUCER;
	TFIBWideStringField *DocAllNAMEKLIENT;
	TFIBWideStringField *DocAllNAME_USER;
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBLargeIntField *DocTID_REM_GUR_VIGRT;
	TFIBLargeIntField *DocTIDBASE_REM_GUR_VIGRT;
	TFIBLargeIntField *DocTIDDOC_REM_GUR_VIGRT;
	TFIBLargeIntField *DocTIDDOCVIGR_REM_GUR_VIGRT;
	TFIBWideStringField *DocTNAMEFIRM;
	TFIBWideStringField *DocTNAMESKLAD;
	TFIBWideStringField *DocTNAMEKLIENT;
	TFIBWideStringField *DocTNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocTPREFIKS_NUM_REM_GALLDOC;
	TFIBSmallIntField *DocTPR_REM_GALLDOC;
	TFIBIntegerField *DocTNUM_REM_GALLDOC;
	TFIBDateTimeField *DocTPOS_REM_GALLDOC;
	TFIBWideStringField *DocTTDOC_REM_GALLDOC;
	TIntegerField *DocTRECNO;
	TFIBWideStringField *DocTOUT_INFO;
	TFIBLargeIntField *DocTOUT_IDZ;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocAllPOS_REM_GUR_VIGRChange(TField *Sender);
	void __fastcall DocAllIDBASE_REM_GUR_VIGRChange(TField *Sender);
	void __fastcall DocTTDOC_REM_GALLDOCGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText);
private:	// User declarations

	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
			bool flGetNumberDoc;  //при созданнии нового документа не будем
							  // каждый раз получать номер документа
public:		// User declarations
        __fastcall TREM_DMDocVigruska(TComponent* Owner);

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
extern PACKAGE TREM_DMDocVigruska *REM_DMDocVigruska;
//---------------------------------------------------------------------------
#endif
