//---------------------------------------------------------------------------

#ifndef UREM_DMDocOtprPostH
#define UREM_DMDocOtprPostH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IDMSprPrice.h"

//--------------------------------------------------------------------------

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
class TREM_DMDocOtprPost : public TDataModule
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
	TFIBLargeIntField *DocAllIDPROJECT_REM_GALLDOC;
	TFIBLargeIntField *DocAllIDBUSINOP_REM_GALLDOC;
	TFIBWideStringField *DocAllFNAME_USER;
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocAllNAMEFIRM;
	TFIBWideStringField *DocAllNAMESKLAD;
	TFIBWideStringField *DocAllNAMEKLIENT;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBWideStringField *DocAllPREFIKS_NUM_REM_GALLDOC;
	TFIBLargeIntField *DocID_REM_DOTPRPOST;
	TFIBLargeIntField *DocIDBASE_REM_DOTPRPOST;
	TFIBLargeIntField *DocIDDOC_REM_DOTPRPOST;
	TFIBLargeIntField *DocIDTPRICE_REM_DOTPRPOST;
	TFIBLargeIntField *DocIDBRAND_REM_DOTPRPOST;
	TFIBLargeIntField *DocIDPRODUCER_REM_DOTPRPOST;
	TFIBWideStringField *DocTK_REM_DOTPRPOST;
	TFIBWideStringField *DocNUMDOCTK_REM_DOTPRPOST;
	TFIBDateField *DocPLANDOSTAVKI_REM_DOTPRPOST;
	TFIBWideStringField *DocNAME_SBRAND;
	TFIBWideStringField *DocNAME_SPRODUCER;
	TFIBLargeIntField *DocTID_REM_DOTPRPOSTT;
	TFIBLargeIntField *DocTIDBASE_REM_DOTPRPOSTT;
	TFIBLargeIntField *DocTIDDOC_REM_DOTPRPOSTT;
	TFIBLargeIntField *DocTIDNOM_REM_DOTPRPOSTT;
	TFIBLargeIntField *DocTIDED_REM_DOTPRPOSTT;
	TFIBBCDField *DocTKOL_REM_DOTPRPOSTT;
	TFIBBCDField *DocTKF_REM_DOTPRPOSTT;
	TFIBBCDField *DocTPRICE_REM_DOTPRPOSTT;
	TFIBBCDField *DocTSUM_REM_DOTPRPOSTT;
	TFIBLargeIntField *DocTIDCQT_REM_DOTPRPOSTT;
	TFIBLargeIntField *DocTIDPRNOM_REM_DOTPRPOSTT;
	TFIBWideStringField *DocTNAMENOM;
	TFIBSmallIntField *DocTFL_ADD_IN_SOBORUD_SNOM;
	TFIBWideStringField *DocTNAMEED;
	TFIBIntegerField *DocTCODENOM;
	TFIBWideStringField *DocTARTNOM;
	TFIBWideStringField *DocTSHED;
	TFIBLargeIntField *DocTID_REM_CQUERY;
	TFIBWideStringField *DocTNAME_REM_CQUERY;
	TFIBIntegerField *DocTNUM_REM_CQUERY;
	TFIBDateTimeField *DocTPOS_REM_CQUERY;
	TFIBWideStringField *DocTKLIENT_NAME_REM_CQUERY;
	TFIBWideStringField *DocTNAME_MODEL_REM_CQUERY;
	TFIBWideStringField *DocTNUM_STR_ZAK_POST_REM_CQUERY;
	TFIBLargeIntField *DocTID_REM_Z;
	TFIBWideStringField *DocTNAME_REM_Z;
	TFIBWideStringField *DocTPREFIKS_NUM_REM_Z;
	TFIBIntegerField *DocTNUM_REM_Z;
	TFIBDateTimeField *DocTPOS_REM_Z;
	TFIBWideStringField *DocTMODEL_REM_Z;
	TFIBWideStringField *DocTSERNUM_REM_Z;
	TFIBWideStringField *DocTSERNUM2_REM_Z;
	TFIBWideStringField *DocTSTR_CODE_VIGR_REM_Z_1;
	TFIBWideStringField *DocTNAME_REM_SPRMODEL;
	TFIBWideStringField *DocTART_SPRNOM;
	TFIBWideStringField *DocTNAME_SPRNOM;
	TFIBSmallIntField *DocTFL_DOSTUPNO_SPRNOM;
	TFIBWideStringField *DocTMODEL_STR_SPRNOM;
	TIntegerField *DocTRECNO;
	TFIBWideStringField *DocTART_REM_CQUERYT;
	TFIBWideStringField *DocTNAMENOM_REM_CQUERYT;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall DocTAfterDelete(TDataSet *DataSet);
	void __fastcall DocTBeforeDelete(TDataSet *DataSet);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocAllPOS_REM_GALLDOCChange(TField *Sender);
	void __fastcall DocAllIDBASE_REM_GALLDOCChange(TField *Sender);
	void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DocTNAME_REM_CQUERYGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText);
	void __fastcall DocTNAME_REM_ZGetText(TField *Sender, UnicodeString &Text, bool DisplayText);
	void __fastcall DocTKOL_REM_DOTPRPOSTTChange(TField *Sender);
	void __fastcall DocTPRICE_REM_DOTPRPOSTTChange(TField *Sender);



private:	// User declarations


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		bool flGetNumberDoc;  //при созданнии нового документа не будем
							  // каждый раз получать номер документа

		double SummaDoc;
		double TekSummaDoc;
		double OldSummaStr;
		double NewSummaStr;

		double OldRSummaStr;
		double NewRSummaStr;
public:		// User declarations
		__fastcall TREM_DMDocOtprPost(TComponent* Owner);

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




		bool NewDoc(void);
		bool OpenDoc(__int64 id);
		bool SaveDoc(void);
		bool DeleteDoc(__int64 id);

        bool DvRegDoc(void);
		bool CancelDvRegDoc(void);

		bool TableAppend(void);
		bool TableDelete(void);

		bool Prosmotr;    //только просмотр
		__int64 IdDoc;           //идентификатор текущей записи
		__int64 IdGrp;        // идетификатор группы
		__int64 IdElementaMaster;  //идентификатор внешенго справочника-владельца



		__int64 IdTypePrice;


		bool IsmPrice;
		bool IsmSum;

		__int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc);
		bool EnableDvReg;
		int GetNumberNewDoc(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMDocOtprPost *REM_DMDocOtprPost;
//---------------------------------------------------------------------------
#endif
