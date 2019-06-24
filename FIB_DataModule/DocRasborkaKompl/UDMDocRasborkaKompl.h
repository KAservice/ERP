//---------------------------------------------------------------------------

#ifndef UDMDocRasborkaKomplH
#define UDMDocRasborkaKomplH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"

#include "IDMSprPart.h"

//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
//---------------------------------------------------------------------------
class TDMDocRasborkaKompl : public TDataModule
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
	TFIBBCDField *DocKF_DRASBKOMPL;
	TFIBBCDField *DocKOL_DRASBKOMPL;
	TFIBBCDField *DocRPRICE_DRASBKOMPL;
	TFIBBCDField *DocTKF_DRASBKOMPLT;
	TFIBBCDField *DocTKOL_DRASBKOMPLT;
	TFIBBCDField *DocTRPRICE_DRASBKOMPLT;
	TFIBBCDField *DocTRSUM_DRASBKOMPLT;
	TIntegerField *DocTRECNO;
	TFIBBCDField *DocTKFSEB_DRASBKOMPLT;
	TFIBLargeIntField *DocAllIDDOC;
	TFIBWideStringField *DocAllTDOC;
	TFIBLargeIntField *DocAllIDFIRMDOC;
	TFIBLargeIntField *DocAllIDSKLDOC;
	TFIBLargeIntField *DocAllIDKLDOC;
	TFIBLargeIntField *DocAllIDDOGDOC;
	TFIBLargeIntField *DocAllIDUSERDOC;
	TFIBWideStringField *DocAllPREFIKSDOC;
	TFIBLargeIntField *DocAllIDDOCOSNDOC;
	TFIBLargeIntField *DocAllIDEXTDOC;
	TFIBIntegerField *DocAllTYPEEXTDOC;
	TFIBLargeIntField *DocAllIDBASE_GALLDOC;
	TFIBLargeIntField *DocAllIDPROJECT_GALLDOC;
	TFIBWideStringField *DocAllFNAME_USER;
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocAllNAMEFIRM;
	TFIBWideStringField *DocAllNAMESKLAD;
	TFIBLargeIntField *DocID_DRASBKOMPL;
	TFIBLargeIntField *DocIDBASE_DRASBKOMPL;
	TFIBLargeIntField *DocIDDOC_DRASBKOMPL;
	TFIBLargeIntField *DocIDNOM_DRASBKOMPL;
	TFIBLargeIntField *DocIDED_DRASBKOMPL;
	TFIBWideStringField *DocDESCR_DRASBKOMPL;
	TFIBLargeIntField *DocIDRTPRICE_DRASBKOMPL;
	TFIBWideStringField *DocNAMENOM;
	TFIBWideStringField *DocNAMEED;
	TFIBLargeIntField *DocTID_DRASBKOMPLT;
	TFIBLargeIntField *DocTIDBASE_DRASBKOMPLT;
	TFIBLargeIntField *DocTIDDOC_DRASBKOMPLT;
	TFIBLargeIntField *DocTIDNOM_DRASBKOMPLT;
	TFIBLargeIntField *DocTIDED_DRASBKOMPLT;
	TFIBLargeIntField *DocTIDPART_DRASBKOMPLT;
	TFIBWideStringField *DocTNAMENOM;
	TFIBWideStringField *DocTNAMEED;
	TFIBWideStringField *DocAllGID_DOC;
	TFIBLargeIntField *DocAllIDBUSINOP_GALLDOC;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBWideStringField *DocAllPREFIKS_NUM_GALLDOC;
	TFIBWideStringField *DocTARTNOM;
	TFIBIntegerField *DocTCODENOM;
	TFIBWideStringField *DocTSHED;
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
	void __fastcall DocTKOL_DRASBKOMPLTChange(TField *Sender);
	void __fastcall DocTRPRICE_DRASBKOMPLTChange(TField *Sender);
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
		__fastcall TDMDocRasborkaKompl(TComponent* Owner);

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
extern PACKAGE TDMDocRasborkaKompl *DMDocRasborkaKompl;
//---------------------------------------------------------------------------
#endif
