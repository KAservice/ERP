//---------------------------------------------------------------------------

#ifndef UDMDocZamenaH
#define UDMDocZamenaH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"

#include "IDMSprPart.h"
//#include "UDMSprPrice.h"

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
class TDMDocZamena : public TDataModule
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
	TFIBWideStringField *DocAllNAMEFIRM;
	TFIBWideStringField *DocAllNAMESKLAD;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBLargeIntField *DocID_DZAMENA;
	TFIBLargeIntField *DocIDBASE_DZAMENA;
	TFIBLargeIntField *DocIDDOC_DZAMENA;
	TFIBIntegerField *DocOPER_DZAMENA;
	TFIBWideStringField *DocDESCR_DZAMENA;
	TFIBLargeIntField *DocIDRTPRICE_DZAMENA;
	TFIBBCDField *DocS_RSUM_DZAMENA;
	TFIBBCDField *DocP_RSUM_DZAMENA;
	TFIBLargeIntField *DocTID_DZAMENAT;
	TFIBLargeIntField *DocTIDBASE_DZAMENAT;
	TFIBLargeIntField *DocTIDDOC_DZAMENAT;
	TFIBLargeIntField *DocTS_IDNOM_DZAMENAT;
	TFIBLargeIntField *DocTS_IDED_DZAMENAT;
	TFIBBCDField *DocTS_KF_DZAMENAT;
	TFIBBCDField *DocTS_KOL_DZAMENAT;
	TFIBBCDField *DocTS_RPRICE_DZAMENAT;
	TFIBBCDField *DocTS_RSUM_DZAMENAT;
	TFIBLargeIntField *DocTP_IDNOM_DZAMENAT;
	TFIBLargeIntField *DocTP_IDED_DZAMENAT;
	TFIBLargeIntField *DocTP_IDPART_DZAMENAT;
	TFIBBCDField *DocTP_KF_DZAMENAT;
	TFIBBCDField *DocTP_KOL_DZAMENAT;
	TFIBBCDField *DocTP_RPRICE_DZAMENAT;
	TFIBBCDField *DocTP_RSUM_DZAMENAT;
	TFIBWideStringField *DocTS_NAMENOM;
	TFIBWideStringField *DocTS_NAMEED;
	TFIBWideStringField *DocTP_NAMENOM;
	TFIBWideStringField *DocTP_NAMEED;
	TFIBWideStringField *DocAllPREFIKS_NUM_GALLDOC;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DocT1CalcFields(TDataSet *DataSet);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocAllPOSDOCChange(TField *Sender);
	void __fastcall DocAllIDSKLDOCChange(TField *Sender);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocAllIDBASE_GALLDOCChange(TField *Sender);
	void __fastcall DocTS_KOL_DZAMENATChange(TField *Sender);
	void __fastcall DocTS_RPRICE_DZAMENATChange(TField *Sender);
	void __fastcall DocTAfterDelete(TDataSet *DataSet);
	void __fastcall DocTBeforeDelete(TDataSet *DataSet);
	void __fastcall DocTP_KOL_DZAMENATChange(TField *Sender);
	void __fastcall DocTP_RPRICE_DZAMENATChange(TField *Sender);
	void __fastcall DocAllIDFIRMDOCChange(TField *Sender);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		IDMSprPart * Part;

		void CreateNewPart(void);



		double S_OldRSummaStr;
		double S_NewRSummaStr;

		double P_OldRSummaStr;
		double P_NewRSummaStr;

		bool flGetNumberDoc;  //при созданнии нового документа не будем
							  // каждый раз получать номер документа
public:		// User declarations
        __fastcall TDMDocZamena(TComponent* Owner);

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
extern PACKAGE TDMDocZamena *DMDocZamena;
//---------------------------------------------------------------------------
#endif
