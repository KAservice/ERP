//---------------------------------------------------------------------------

#ifndef UDMDocSpOtrOstH
#define UDMDocSpOtrOstH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"



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
class TDMDocSpOtrOst : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceDoc;
        TDataSource *DataSourceDocT;
        TDataSource *DataSourceDocAll;
	TpFIBDataSet *DocAll;
	TpFIBDataSet *Doc;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *DocT;
	TpFIBTransaction *IBTrDvReg;
	TpFIBDataSet *NumDoc;
	TpFIBDataSet *IBQPoGrp;
	TpFIBDataSet *IBQ;
	TIntegerField *DocTRECNO;
	TFIBIntegerField *IBQPoGrpTNOM;
	TFIBIntegerField *IBQPoGrpCODENOM;
	TFIBBCDField *IBQPoGrpKOL_DSPOTROSTT;
	TFIBBCDField *IBQPoGrpKF_DSPOTROSTT;
	TFIBBCDField *IBQPoGrpPRICE_DSPOTROSTT;
	TFIBBCDField *IBQPoGrpSUM_DSPOTROSTT;
	TFIBBCDField *IBQPoGrpRPRICE_DSPOTROSTT;
	TFIBBCDField *IBQPoGrpRSUM_DSPOTROSTT;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBQuery *QueryDvReg;
	TFIBBCDField *IBQPoGrpIDGN;
	TFIBBCDField *IBQPoGrpID_DSPOTROSTT;
	TFIBBCDField *IBQPoGrpIDDOC_DSPOTROSTT;
	TFIBBCDField *IBQPoGrpIDNOM_DSPOTROSTT;
	TFIBBCDField *IBQPoGrpIDED_DSPOTROSTT;
	TFIBBCDField *IBQPoGrpIDPART_DSPOTROSTT;
	TFIBWideStringField *IBQPoGrpNAMEGN;
	TFIBWideStringField *IBQPoGrpNAMENOM;
	TFIBWideStringField *IBQPoGrpNAMEED;
	TFIBWideStringField *DocTNAMEGN;
	TFIBWideStringField *DocTNAMENOM;
	TFIBWideStringField *DocTNAMEED;
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
	TFIBWideStringField *DocAllNAME_USER;
	TFIBWideStringField *DocAllNAMEFIRM;
	TFIBWideStringField *DocAllNAMESKLAD;
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBLargeIntField *DocID_DSPOTROST;
	TFIBLargeIntField *DocIDDOC_DSPOTROST;
	TFIBWideStringField *DocGID_DSPOTROST;
	TFIBWideStringField *DocDESCR_DSPOTROST;
	TFIBLargeIntField *DocIDRTPRICE_DSPOTROST;
	TFIBBCDField *DocRSUM_DSPOTROST;
	TFIBLargeIntField *DocIDBASE_DSPOTROST;
	TFIBLargeIntField *DocTIDGN;
	TFIBIntegerField *DocTTNOM;
	TFIBIntegerField *DocTCODENOM;
	TFIBLargeIntField *DocTID_DSPOTROSTT;
	TFIBLargeIntField *DocTIDDOC_DSPOTROSTT;
	TFIBWideStringField *DocTGID_DSPOTROSTT;
	TFIBLargeIntField *DocTIDNOM_DSPOTROSTT;
	TFIBLargeIntField *DocTIDED_DSPOTROSTT;
	TFIBLargeIntField *DocTIDPART_DSPOTROSTT;
	TFIBBCDField *DocTKOL_DSPOTROSTT;
	TFIBBCDField *DocTKF_DSPOTROSTT;
	TFIBBCDField *DocTPRICE_DSPOTROSTT;
	TFIBBCDField *DocTSUM_DSPOTROSTT;
	TFIBBCDField *DocTRPRICE_DSPOTROSTT;
	TFIBBCDField *DocTRSUM_DSPOTROSTT;
	TFIBLargeIntField *DocTIDBASE_DSPOTROSTT;
	TFIBWideStringField *DocAllFNAME_USER;
	TFIBWideStringField *DocAllPREFIKS_NUM_GALLDOC;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocTAfterDelete(TDataSet *DataSet);
	void __fastcall DocTBeforeDelete(TDataSet *DataSet);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocAllPOSDOCChange(TField *Sender);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocAllIDBASE_GALLDOCChange(TField *Sender);
	void __fastcall DocAllIDSKLDOCChange(TField *Sender);
	void __fastcall DocAllIDFIRMDOCChange(TField *Sender);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		double Summa(void);
		        double SummaDoc;
		double TekSummaDoc;
		double OldSummaStr;
		double NewSummaStr;
AnsiString GetTextZaprosDocT(void);

		bool flGetNumberDoc;  //при созданнии нового документа не будем
							  // каждый раз получать номер документа

public:		// User declarations
        __fastcall TDMDocSpOtrOst(TComponent* Owner);

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

        void NewDoc(void);
		void OpenDoc(__int64 id_doc);
        bool SaveDoc(void);
        bool DvRegDoc(void);
        bool CancelDvRegDoc(void);
        void AddDocNewString(void);
        void DeleteStringDoc(void);
		bool DeleteDoc(__int64 id);



		__int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc);

        bool NewElement;  // новый элемент
        bool Prosmotr;    //только просмотр
		bool NoEdit;
		__int64 IdDoc;           //идентификатор текущей записи





        __int64 IdGrpNom;


		bool ChangeTable;

		bool EnableDvReg;

		int GetNumberNewDoc(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMDocSpOtrOst *DMDocSpOtrOst;
//---------------------------------------------------------------------------
#endif
