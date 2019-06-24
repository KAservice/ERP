//---------------------------------------------------------------------------

#ifndef UDMDocSborkaKomplH
#define UDMDocSborkaKomplH
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
class TDMDocSborkaKompl : public TDataModule
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
	TFIBBCDField *DocID_DSBKOMPL;
	TFIBBCDField *DocIDBASE_DSBKOMPL;
	TFIBBCDField *DocIDDOC_DSBKOMPL;
	TFIBBCDField *DocIDNOM_DSBKOMPL;
	TFIBBCDField *DocIDED_DSBKOMPL;
	TFIBBCDField *DocKF_DSBKOMPL;
	TFIBBCDField *DocKOL_DSBKOMPL;
	TFIBBCDField *DocRPRICE_DSBKOMPL;
	TFIBBCDField *DocTID_DSBKOMPLT;
	TFIBBCDField *DocTIDBASE_DSBKOMPLT;
	TFIBBCDField *DocTIDDOC_DSBKOMPLT;
	TFIBBCDField *DocTIDNOM_DSBKOMPLT;
	TFIBBCDField *DocTIDED_DSBKOMPLT;
	TFIBBCDField *DocTKF_DSBKOMPLT;
	TFIBBCDField *DocTKOL_DSBKOMPLT;
	TFIBBCDField *DocTRPRICE_DSBKOMPLT;
	TFIBBCDField *DocTRSUM_DSBKOMPLT;
	TFIBBCDField *DocIDRTPRICE_DSBKOMPL;
	TFIBBCDField *DocIDPART_DSBKOMPL;
	TIntegerField *DocTRECNO;
	TFIBWideStringField *DocAllGID_DOC;
	TFIBIntegerField *DocAllTYPEEXTDOC;
	TFIBWideStringField *DocAllFNAME_USER;
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocAllNAMEFIRM;
	TFIBWideStringField *DocAllNAMESKLAD;
	TFIBWideStringField *DocDESCR_DSBKOMPL;
	TFIBWideStringField *DocNAMENOM;
	TFIBWideStringField *DocNAMEED;
	TFIBWideStringField *DocTNAMENOM;
	TFIBWideStringField *DocTNAMEED;
	TFIBWideStringField *DocAllTDOC;
	TFIBBCDField *DocAllIDPROJECT_GALLDOC;
	TFIBBCDField *DocAllIDBUSINOP_GALLDOC;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBWideStringField *DocAllPREFIKS_NUM_GALLDOC;
	TFIBWideStringField *DocTARTNOM;
	TFIBIntegerField *DocTCODENOM;
	TFIBWideStringField *DocTSHED;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DocT1CalcFields(TDataSet *DataSet);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DocTAfterDelete(TDataSet *DataSet);
	void __fastcall DocTBeforeDelete(TDataSet *DataSet);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocAllPOSDOCChange(TField *Sender);
	void __fastcall DocAllIDSKLDOCChange(TField *Sender);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocAllIDBASE_GALLDOCChange(TField *Sender);
	void __fastcall DocTKOL_DSBKOMPLTChange(TField *Sender);
	void __fastcall DocTRPRICE_DSBKOMPLTChange(TField *Sender);
	void __fastcall DocAllIDFIRMDOCChange(TField *Sender);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		IDMSprPart * Part;
		void CreateNewPart(void);

				double OldRSummaStr;
		double NewRSummaStr;

		bool flGetNumberDoc;  //при созданнии нового документа не будем
							  // каждый раз получать номер документа
public:		// User declarations
        __fastcall TDMDocSborkaKompl(TComponent* Owner);

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
extern PACKAGE TDMDocSborkaKompl *DMDocSborkaKompl;
//---------------------------------------------------------------------------
#endif
