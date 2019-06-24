//---------------------------------------------------------------------------

#ifndef UREM_DMDocVZipPerH
#define UREM_DMDocVZipPerH
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
class TREM_DMDocVZipPer : public TDataModule
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
	TFIBWideStringField *DocAllFNAME_USER;
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocAllNAMEFIRM;
	TFIBWideStringField *DocAllNAMESKLAD;
	TFIBWideStringField *DocAllNAMEKLIENT;
	TFIBLargeIntField *DocAllIDPROJECT_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDBUSINOP_REM_GALLDOC;
	TFIBWideStringField *DocAllPREFIKS_NUM_REM_GALLDOC;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBLargeIntField *DocAllIDOBJECT_REM_GALLDOC;
	TFIBWideStringField *DocAllNAME_SOBJECT;
	TFIBLargeIntField *DocID_REM_DVZPER;
	TFIBLargeIntField *DocIDBASE_REM_DVZPER;
	TFIBLargeIntField *DocIDDOC_REM_DVZPER;
	TFIBLargeIntField *DocIDSKLADPOL_REM_DVZPER;
	TFIBWideStringField *DocPRIM_REM_DVZPER;
	TFIBIntegerField *DocOPER_REM_DVZPER;
	TFIBWideStringField *DocNAMESKLAD;
	TFIBLargeIntField *DocTID_REM_DVZPERT;
	TFIBLargeIntField *DocTIDBASE_REM_DVZPERT;
	TFIBLargeIntField *DocTIDDOC_REM_DVZPERT;
	TFIBLargeIntField *DocTIDKLIENT_REM_DVZPERT;
	TFIBLargeIntField *DocTIDTNOM_REM_DVZPERT;
	TFIBLargeIntField *DocTIDNOM_REM_DVZPERT;
	TFIBLargeIntField *DocTIDZ_REM_DVZPERT;
	TFIBLargeIntField *DocTIDHW_REM_DVZPERT;
	TFIBBCDField *DocTKOL_REM_DVZPERT;
	TFIBLargeIntField *DocTIDTVZIP_REM_DVZPERT;
	TFIBWideStringField *DocTNAME_REM_Z;
	TFIBIntegerField *DocTNUM_REM_Z;
	TFIBDateTimeField *DocTPOS_REM_Z;
	TFIBWideStringField *DocTSERNUM_REM_Z;
	TFIBWideStringField *DocTSERNUM2_REM_Z;
	TFIBWideStringField *DocTKLIENT_NAME_REM_Z;
	TFIBWideStringField *DocTMODEL_REM_Z;
	TFIBWideStringField *DocTNAMEKLIENT;
	TFIBWideStringField *DocTNAME_STNOM;
	TFIBWideStringField *DocTNAMENOM;
	TFIBWideStringField *DocTNAME_REM_STVZIP;
	TFIBWideStringField *DocTNAME_REM_SHARDWARE;
	TFIBWideStringField *DocTSERNUM_REM_SHARDWARE;
	TFIBWideStringField *DocTSERNUM2_REM_SHARDWARE;
	TFIBWideStringField *DocTNAME_REM_SPRMODEL;
	TIntegerField *DocTRECNO;
	TFIBLargeIntField *DocTIDMHRAN_OTPR_REM_DVZPERT;
	TFIBLargeIntField *DocTIDMHRAN_POL_REM_DVZPERT;
	TFIBWideStringField *DocTNAME_SMHRAN_OTPR;
	TFIBWideStringField *DocTNAME_SMHRAN_POL;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocAllPOS_REM_GALLDOCChange(TField *Sender);
	void __fastcall DocAllIDBASE_REM_GALLDOCChange(TField *Sender);
private:	// User declarations

	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		double OldSummaStr;
		double NewSummaStr;

		double OldSummaMexStr;
		double NewSummaMexStr;

			bool flGetNumberDoc;  //при созданнии нового документа не будем
							  // каждый раз получать номер документа
public:		// User declarations
		__fastcall TREM_DMDocVZipPer(TComponent* Owner);

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //функция удаления реализации интерфейса
		bool flDeleteImpl;   //надо ли удалять реализацию при удалении текущего модуля

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //интерфейс класса реализации
		GUID ClsIdImpl;				 //GUID класса реализации

		//IMainInterface
		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);



		//Текущий интерфейс

		__int64 IdDoc;           //идентификатор текущей записи
		bool Prosmotr;    //только просмотр

		bool NewDoc(void);
		bool OpenDoc(__int64 id);
		bool SaveDoc(void);
		bool DeleteDoc(__int64 id);

        bool DvRegDoc(void);
		bool CancelDvRegDoc(void);

		void TableAppend(void);
		void TableDelete(void);

		int GetNumberNewDoc(void);



};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMDocVZipPer *REM_DMDocVZipPer;
//---------------------------------------------------------------------------
#endif
