//---------------------------------------------------------------------------

#ifndef UDMDocSchetFactH
#define UDMDocSchetFactH
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
class TDMDocSchetFact : public TDataModule
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
	TFIBDateTimeField *DocAllPOSDOC;
	TFIBSmallIntField *DocAllPRDOC;
	TFIBIntegerField *DocAllNUMDOC;
	TFIBBCDField *DocAllSUMDOC;
	TFIBBCDField *DocTKOL_DSCHFACTT;
	TFIBBCDField *DocTKF_DSCHFACTT;
	TFIBBCDField *DocTPRICE_DSCHFACTT;
	TFIBBCDField *DocTSUM_DSCHFACTT;
	TFIBIntegerField *DocTSTNDS_DSCHFACTT;
	TFIBBCDField *DocTSUMNDS_DSCHFACTT;
	TFIBIntegerField *DocTTNOM;
	TIntegerField *DocTRECNO;
	TpFIBDataSet *NumDoc;
	TpFIBTransaction *IBTrDvReg;
	TpFIBDataSet *IBQ;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBQuery *QueryDvReg;
	TFIBBCDField *DocAllIDDOC;
	TFIBBCDField *DocAllIDFIRMDOC;
	TFIBBCDField *DocAllIDSKLDOC;
	TFIBBCDField *DocAllIDKLDOC;
	TFIBBCDField *DocAllIDDOGDOC;
	TFIBBCDField *DocAllIDUSERDOC;
	TFIBBCDField *DocAllIDDOCOSNDOC;
	TFIBBCDField *DocID_DSCHFACT;
	TFIBBCDField *DocIDDOC_DSCHFACT;
	TFIBBCDField *DocIDTPRICE_DSCHFACT;
	TFIBBCDField *DocTID_DSCHFACTT;
	TFIBBCDField *DocTIDDOC_DSCHFACTT;
	TFIBBCDField *DocTIDNOM_DSCHFACTT;
	TFIBBCDField *DocTIDED_DSCHFACTT;
	TFIBBCDField *DocAllIDEXTDOC;
	TFIBBCDField *DocIDGRPOL_DSCHFACT;
	TpFIBQuery *pFIBQ;
	TFIBBCDField *DocIDBASE_DSCHFACT;
	TFIBBCDField *DocTIDBASE_DSCHFACTT;
	TFIBBCDField *DocAllIDBASE_GALLDOC;
	TFIBWideStringField *DocAllTDOC;
	TFIBWideStringField *DocAllGID_DOC;
	TFIBWideStringField *DocAllPREFIKSDOC;
	TFIBIntegerField *DocAllTYPEEXTDOC;
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocAllNAMEFIRM;
	TFIBWideStringField *DocAllNAMESKLAD;
	TFIBWideStringField *DocAllNAMEKLIENT;
	TFIBWideStringField *DocAllFNAME_USER;
	TFIBWideStringField *DocGID_DSCHFACT;
	TFIBWideStringField *DocPRIM_DSCHFACT;
	TFIBWideStringField *DocNAMEKLIENT;
	TFIBWideStringField *DocTGID_DSCHFACTT;
	TFIBIntegerField *DocTNDS_DSCHFACTT;
	TFIBWideStringField *DocTNAMENOM;
	TFIBWideStringField *DocTNAMEED;
	TFIBBCDField *DocAllIDPROJECT_GALLDOC;
	TFIBBCDField *DocAllIDBUSINOP_GALLDOC;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBWideStringField *DocNUMPLAT_RASCH_DOC_DSCHFACT;
	TFIBDateTimeField *DocDATEPLAT_RASCH_DOC_DSCHFACT;
	TFIBWideStringField *DocAllPREFIKS_NUM_GALLDOC;
	TFIBWideStringField *DocTARTNOM;
	TFIBIntegerField *DocTCODENOM;
	TFIBWideStringField *DocTSHED;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
        void __fastcall DocAllPOSDOCChange(TField *Sender);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocTAfterDelete(TDataSet *DataSet);
	void __fastcall DocTBeforeDelete(TDataSet *DataSet);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocTKOL_DSCHFACTTChange(TField *Sender);
	void __fastcall DocTPRICE_DSCHFACTTChange(TField *Sender);
	void __fastcall DocAllIDBASE_GALLDOCChange(TField *Sender);
	void __fastcall DocAllIDSKLDOCChange(TField *Sender);
	void __fastcall DocAllIDFIRMDOCChange(TField *Sender);
private:	// User declarations
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

	double Summa(void);

        double SummaDoc;
		double OldSummaStr;
		double NewSummaStr;

		bool flGetNumberDoc;  //при созданнии нового документа не будем
							  // каждый раз получать номер документа
public:		// User declarations
        __fastcall TDMDocSchetFact(TComponent* Owner);

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
		void OpenDoc(__int64 IdDoc);
        bool SaveDoc(void);
        bool DvRegDoc(void);
        bool CancelDvRegDoc(void);
        void AddDocNewString(void);
        void DeleteStringDoc(void);
        void CloseDoc(void);
		bool DeleteDoc(__int64 id);





        bool NewElement;  // новый элемент
		bool Prosmotr;    //только просмотр
		__int64 IdDoc;           //идентификатор текущей записи




		bool EnableDvReg;
       int GetNumberNewDoc(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TDMDocSchetFact *DMDocSchetFact;
//---------------------------------------------------------------------------
#endif
