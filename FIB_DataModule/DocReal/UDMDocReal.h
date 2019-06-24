//---------------------------------------------------------------------------

#ifndef UDMDocRealH
#define UDMDocRealH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"


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
class TDMDocReal : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceDoc;
        TDataSource *DataSourceDocT;
        TDataSource *DataSourceDocAll;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *DocAll;
	TpFIBDataSet *Doc;
	TpFIBDataSet *DocT;
	TFIBDateTimeField *DocAllPOSDOC;
	TFIBSmallIntField *DocAllPRDOC;
	TFIBIntegerField *DocAllNUMDOC;
	TFIBBCDField *DocAllSUMDOC;
	TFIBBCDField *DocTKOLREAT;
	TFIBBCDField *DocTKFREAT;
	TFIBBCDField *DocTPRICEREAT;
	TFIBBCDField *DocTSUMREAT;
	TpFIBTransaction *IBTrDvReg;
	TpFIBQuery *pFIBQ;
	TIntegerField *DocTRECNO;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBQuery *QueryDvReg;
	TpFIBDataSet *NumDoc;
	TFIBLargeIntField *DocAllIDDOC;
	TFIBLargeIntField *DocAllIDFIRMDOC;
	TFIBLargeIntField *DocAllIDSKLDOC;
	TFIBLargeIntField *DocAllIDKLDOC;
	TFIBLargeIntField *DocAllIDDOGDOC;
	TFIBLargeIntField *DocAllIDUSERDOC;
	TFIBWideStringField *DocAllGID_DOC;
	TFIBWideStringField *DocAllPREFIKSDOC;
	TFIBLargeIntField *DocAllIDDOCOSNDOC;
	TFIBLargeIntField *DocAllIDEXTDOC;
	TFIBIntegerField *DocAllTYPEEXTDOC;
	TFIBLargeIntField *DocAllIDBASE_GALLDOC;
	TFIBLargeIntField *DocAllIDPROJECT_GALLDOC;
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocAllNAMEFIRM;
	TFIBWideStringField *DocAllNAMESKLAD;
	TFIBWideStringField *DocAllNAMEKLIENT;
	TFIBWideStringField *DocAllFNAME_USER;
	TFIBLargeIntField *DocIDREA;
	TFIBLargeIntField *DocIDDOCREA;
	TFIBWideStringField *DocPRIMREA;
	TFIBWideStringField *DocGID_DREA;
	TFIBLargeIntField *DocIDTPRICEREA;
	TFIBLargeIntField *DocIDGRPOLREA;
	TFIBLargeIntField *DocIDBSCHETREA;
	TFIBLargeIntField *DocIDBASE_DREA;
	TFIBWideStringField *DocNAME_TPRICE;
	TFIBWideStringField *DocNAMEKLIENT;
	TFIBWideStringField *DocNAMEBSCHET;
	TFIBLargeIntField *DocTIDREAT;
	TFIBLargeIntField *DocTIDDOCREAT;
	TFIBLargeIntField *DocTIDNOMREAT;
	TFIBLargeIntField *DocTIDEDREAT;
	TFIBWideStringField *DocTGID_DREAT;
	TFIBLargeIntField *DocTIDBASE_DREAT;
	TFIBIntegerField *DocTNDS_DREAT;
	TFIBBCDField *DocTSUMNDS_DREAT;
	TFIBWideStringField *DocTNAMENOM;
	TFIBWideStringField *DocTNAMEED;
	TFIBSmallIntField *DocTTNOM;
	TFIBWideStringField *DocAllTDOC;
	TFIBLargeIntField *DocAllIDBUSINOP_GALLDOC;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBLargeIntField *DocIDRSCHETKLIENT_DREA;
	TFIBLargeIntField *DocIDRSCHETGRPOL_DREA;
	TFIBWideStringField *DocNAME_RSCHET_KLIENT;
	TFIBWideStringField *DocNAME_RSCHET_GRPOL;
	TFIBWideStringField *DocAllPREFIKS_NUM_GALLDOC;
	TFIBBCDField *DocTSUMSK_DREAT;
	TFIBBCDField *DocTPRSK_CARD_DREAT;
	TFIBBCDField *DocTPRSK_AUTO_DREAT;
	TFIBBCDField *DocTPRSK_HAND_DREAT;
	TFIBBCDField *DocTPRSK_DREAT;
	TFIBBCDField *DocTNO_SK_DREAT;
	TFIBWideStringField *DocTARTNOM;
	TFIBIntegerField *DocTCODENOM;
	TFIBWideStringField *DocTSHED;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DocTCalcFields(TDataSet *DataSet);
        void __fastcall DataModuleCreate(TObject *Sender);
        void __fastcall DocTBeforeDelete(TDataSet *DataSet);
        void __fastcall DocTAfterDelete(TDataSet *DataSet);
        void __fastcall DocTKOLREATChange(TField *Sender);
        void __fastcall DocTPRICEREATChange(TField *Sender);
        void __fastcall DocNewRecord(TDataSet *DataSet);
        void __fastcall DocTNewRecord(TDataSet *DataSet);
        void __fastcall DocAllPOSDOCChange(TField *Sender);
	void __fastcall DocAllIDBASE_GALLDOCChange(TField *Sender);
	void __fastcall DocAllIDSKLDOCChange(TField *Sender);
	void __fastcall DocAllIDFIRMDOCChange(TField *Sender);
private:	// User declarations

	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
	double Summa(void);
	        double SebReal;
		double SebProd;
		double SebNom;
		double KolOtrSpisNom;
		double KolSpisNom;
		double KolBasEdinic;
		double KolBasEdinic2;
		double KFEd;

			bool flGetNumberDoc;  //при созданнии нового документа не будем
							  // каждый раз получать номер документа
public:		// User declarations
        __fastcall TDMDocReal(TComponent* Owner);


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

        __int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc);


        bool NewElement;  // новый элемент
        bool Prosmotr;    //только просмотр
		bool NoEdit;
		__int64 IdDoc;           //идентификатор текущей записи


        double SummaDoc;
        double OldSummaStr;
        double NewSummaStr;

        int IdSklad;

        bool AutoRaschet;
        bool EnableDvReg;

		__int64 GetIDDocSchetFact(void);

        bool SkladRozn;
		bool NoOtrOstatok;
        int GetNumberNewDoc(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMDocReal *DMDocReal;
//---------------------------------------------------------------------------
#endif
