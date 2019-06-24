//---------------------------------------------------------------------------

#ifndef UDMDocRealH
#define UDMDocRealH
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
	TFIBStringField *DocAllTDOC;
	TFIBIntegerField *DocAllNUMDOC;
	TFIBBCDField *DocAllSUMDOC;
	TFIBStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBStringField *DocAllNAMEFIRM;
	TFIBStringField *DocAllNAMESKLAD;
	TFIBStringField *DocAllNAMEKLIENT;
	TFIBStringField *DocAllFNAME_USER;
	TFIBStringField *DocPRIMREA;
	TFIBStringField *DocNAME_TPRICE;
	TFIBStringField *DocNAMEKLIENT;
	TFIBStringField *DocNAMEBSCHET;
	TFIBBCDField *DocTKOLREAT;
	TFIBBCDField *DocTKFREAT;
	TFIBBCDField *DocTPRICEREAT;
	TFIBBCDField *DocTSUMREAT;
	TFIBStringField *DocTNAMENOM;
	TFIBStringField *DocTNAMEED;
	TFIBIntegerField *DocTTNOM;
	TpFIBTransaction *IBTrDvReg;
	TpFIBQuery *pFIBQ;
	TIntegerField *DocTRECNO;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBQuery *QueryDvReg;
	TpFIBDataSet *NumDoc;
	TFIBBCDField *DocAllIDDOC;
	TFIBBCDField *DocAllIDFIRMDOC;
	TFIBBCDField *DocAllIDSKLDOC;
	TFIBBCDField *DocAllIDKLDOC;
	TFIBBCDField *DocAllIDDOGDOC;
	TFIBBCDField *DocAllIDUSERDOC;
	TFIBBCDField *DocAllIDDOCOSNDOC;
	TFIBIntegerField *DocAllTYPEEXTDOC;
	TFIBBCDField *DocIDREA;
	TFIBBCDField *DocIDDOCREA;
	TFIBBCDField *DocIDTPRICEREA;
	TFIBBCDField *DocIDGRPOLREA;
	TFIBBCDField *DocIDBSCHETREA;
	TFIBBCDField *DocTIDREAT;
	TFIBBCDField *DocTIDDOCREAT;
	TFIBBCDField *DocTIDNOMREAT;
	TFIBBCDField *DocTIDEDREAT;
	TFIBBCDField *DocAllIDEXTDOC;
	TFIBStringField *DocAllGID_DOC;
	TFIBStringField *DocGID_DREA;
	TFIBStringField *DocTGID_DREAT;
	TFIBBCDField *DocIDBASE_DREA;
	TFIBBCDField *DocTIDBASE_DREAT;
	TFIBBCDField *DocAllIDBASE_GALLDOC;
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
        void __fastcall DocAllNAME_SINFBASE_OBMENGetText(TField *Sender,
          AnsiString &Text, bool DisplayText);
	void __fastcall DocAllIDBASE_GALLDOCChange(TField *Sender);
private:	// User declarations

public:		// User declarations
        __fastcall TDMDocReal(TComponent* Owner);


		void NewDoc(void);
		void OpenDoc(__int64 IdDoc);
        bool SaveDoc(void);
        bool DvRegDoc(void);
        bool CancelDvRegDoc(void);
        void AddDocNewString(void);
        void DeleteStringDoc(void);
        void CloseDoc(void);
		bool DeleteDoc(__int64 id);
        double Summa(void);
        __int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc);


        bool NewElement;  // новый элемент
        bool Prosmotr;    //только просмотр
        bool NoEdit;
        bool Vibor;       //для выбора
		__int64 IdDoc;           //идентификатор текущей записи
		__int64 IdGrp;        // идетификатор группы
        __int64 IdElementaMaster;  //идентификатор внешенго справочника-владельца

        double SummaDoc;
        double OldSummaStr;
        double NewSummaStr;

        bool Error;
        AnsiString TextError;


        int Operation;    //1-реализация, 2-перемещение, 3-на выпуск продукции, 4-списание
        int IdSklad;
        double SebReal;
        double SebProd;
        double SebNom;
        double KolOtrSpisNom;
        double KolSpisNom;
        double KolBasEdinic;
        double KolBasEdinic2;
        double KFEd;
        bool AutoRaschet;
        bool EnableDvReg;

		__int64 GetIDDocSchetFact(void);

        bool SkladRozn;
        bool NoOtrOstatok;

};
//---------------------------------------------------------------------------
extern PACKAGE TDMDocReal *DMDocReal;
//---------------------------------------------------------------------------
#endif
