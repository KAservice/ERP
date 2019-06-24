//---------------------------------------------------------------------------

#ifndef UDMDocSpisNomH
#define UDMDocSpisNomH
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
class TDMDocSpisNom : public TDataModule
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
	TFIBBCDField *DocTKOLSPNT;
	TFIBBCDField *DocTKFSPNT;
	TFIBBCDField *DocTPRICESPNT;
	TFIBBCDField *DocTSUMSPNT;
	TFIBIntegerField *DocTTNOM;
	TIntegerField *DocTRECNO;
	TpFIBTransaction *IBTrDvReg;
	TpFIBDataSet *NumDoc;
	TpFIBDataSet *Grp;
	TpFIBDataSet *El;
	TFIBBCDField *GrpSUMMA;
	TFIBBCDField *ElSUMMA;
	TFIBFloatField *ElSUMKOL;
	TpFIBDataSet *DocOsn;
	TFIBIntegerField *DocOsnNUMDOC;
	TFIBDateTimeField *DocOsnPOSDOC;
	TFIBBCDField *DocRSUM_DSPN;
	TFIBBCDField *DocTRPRICE_DSPNT;
	TFIBBCDField *DocTRSUM_DSPNT;
	TpFIBQuery *pFIBQ;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBQuery *QueryDvReg;
	TFIBBCDField *GrpIDGN;
	TFIBBCDField *DocAllIDDOC;
	TFIBBCDField *DocAllIDFIRMDOC;
	TFIBBCDField *DocAllIDSKLDOC;
	TFIBBCDField *DocAllIDKLDOC;
	TFIBBCDField *DocAllIDDOGDOC;
	TFIBBCDField *DocAllIDUSERDOC;
	TFIBBCDField *DocAllIDDOCOSNDOC;
	TFIBBCDField *DocIDSPN;
	TFIBBCDField *DocIDDOCSPN;
	TFIBBCDField *DocIDRTPRICE_DSPN;
	TFIBBCDField *DocTIDSPNT;
	TFIBBCDField *DocTIDDOCSPNT;
	TFIBBCDField *DocTIDNOMSPNT;
	TFIBBCDField *DocTIDEDSPNT;
	TFIBBCDField *DocAllIDEXTDOC;
	TFIBBCDField *DocIDBASE_DSPN;
	TFIBBCDField *DocTIDBASE_DSPNT;
	TFIBBCDField *DocAllIDBASE_GALLDOC;
	TFIBWideStringField *DocOsnTDOC;
	TFIBWideStringField *GrpNAMEGN;
	TFIBWideStringField *ElNAMENOM;
	TFIBWideStringField *ElNAMEED;
	TFIBWideStringField *DocAllTDOC;
	TFIBWideStringField *DocAllGID_DOC;
	TFIBIntegerField *DocAllTYPEEXTDOC;
	TFIBWideStringField *DocAllFNAME_USER;
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocAllNAMEFIRM;
	TFIBWideStringField *DocAllNAMESKLAD;
	TFIBWideStringField *DocTNAMENOM;
	TFIBWideStringField *DocTNAMEED;
	TFIBWideStringField *DocPRIMSPN;
	TFIBWideStringField *DocGID_DSPN;
	TFIBIntegerField *DocOPER_DSPN;
	TFIBBCDField *DocAllIDPROJECT_GALLDOC;
	TFIBBCDField *DocAllIDBUSINOP_GALLDOC;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBWideStringField *DocAllPREFIKS_NUM_GALLDOC;
	TFIBWideStringField *DocTARTNOM;
	TFIBIntegerField *DocTCODENOM;
	TFIBWideStringField *DocTSHED;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocTAfterDelete(TDataSet *DataSet);
	void __fastcall DocTBeforeDelete(TDataSet *DataSet);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocAllPOSDOCChange(TField *Sender);
	void __fastcall DocTKOLSPNTChange(TField *Sender);
	void __fastcall DocTRPRICE_DSPNTChange(TField *Sender);
	void __fastcall DocAllIDSKLDOCChange(TField *Sender);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocAllIDBASE_GALLDOCChange(TField *Sender);
	void __fastcall DocAllIDFIRMDOCChange(TField *Sender);
private:	// User declarations
bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

        double Summa(void);
		void SpisatPartSoSklada(double Kol, double Sum);
        double SummaDoc;
		double OldSummaStr;
		double NewSummaStr;



		double OldRSummaStr;
		double NewRSummaStr;
        double SebProd;
		double SebNom;
		double KolOtrSpisNom;
		double KolSpisNom;

		bool flGetNumberDoc;  //при созданнии нового документа не будем
							  // каждый раз получать номер документа
public:		// User declarations
        __fastcall TDMDocSpisNom(TComponent* Owner);

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




        int IdSklad;


		bool AddDataInv(void);
		bool SearchStringPoNom(__int64 id_nom);

		bool SkladRozn;
		bool NoOtrOstatok;

		bool EnableDvReg;
       int GetNumberNewDoc(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMDocSpisNom *DMDocSpisNom;
//---------------------------------------------------------------------------
#endif
