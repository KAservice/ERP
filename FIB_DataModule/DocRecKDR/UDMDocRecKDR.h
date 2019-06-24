//---------------------------------------------------------------------------

#ifndef UDMDocRecKDRH
#define UDMDocRecKDRH
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

//---------------------------------------------------------------------------
class TDMDocRecKDR : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceDoc;
        TDataSource *DataSourceDocAll;
	TpFIBDataSet *DocAll;
	TpFIBDataSet *Doc;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBIntegerField *DocAllIDDOC;
	TFIBDateTimeField *DocAllPOSDOC;
	TFIBSmallIntField *DocAllPRDOC;
	TFIBStringField *DocAllTDOC;
	TFIBIntegerField *DocAllNUMDOC;
	TFIBIntegerField *DocAllIDFIRMDOC;
	TFIBIntegerField *DocAllIDSKLDOC;
	TFIBIntegerField *DocAllIDKLDOC;
	TFIBIntegerField *DocAllIDDOGDOC;
	TFIBBCDField *DocAllSUMDOC;
	TFIBIntegerField *DocAllIDUSERDOC;
	TFIBStringField *DocAllGID_DOC;
	TFIBStringField *DocAllPREFIKSDOC;
	TFIBIntegerField *DocAllIDDOCOSNDOC;
	TFIBStringField *DocAllFNAME_USER;
	TFIBStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBStringField *DocAllNAMEFIRM;
	TFIBIntegerField *DocID_DREC_KDR;
	TFIBStringField *DocGID_DREC_KDR;
	TFIBIntegerField *DocIDDOC_DREC_KDR;
	TFIBStringField *DocOPERATION_DREC_KDR;
	TFIBBCDField *DocDOHOD_DREC_KDR;
	TFIBBCDField *DocRASHOD_DREC_KDR;
	TpFIBDataSet *NumDoc;
	TFIBIntegerField *NumDocMAXNUMBER;
	TpFIBDataSet *Doc2;
	TpFIBTransaction *IBTrDvReg;
	TFIBIntegerField *Doc2IDDOC;
	TFIBSmallIntField *Doc2PRDOC;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
        void __fastcall DocAllPOSDOCChange(TField *Sender);
	void __fastcall DocAllNewRecord(TDataSet *DataSet);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocAllNAME_SINFBASE_OBMENGetText(TField *Sender,
          AnsiString &Text, bool DisplayText);
private:	// User declarations

public:		// User declarations
        __fastcall TDMDocRecKDR(TComponent* Owner);


        void NewDoc(void);
        void OpenDoc(int IdDoc);
        bool SaveDoc(void);
        bool DvRegDoc(void);
        bool CancelDvRegDoc(void);
        void CloseDoc(void);
        double Summa(void);
        bool DeleteDoc(int id);


        bool NewElement;  // новый элемент
        bool Prosmotr;    //только просмотр
        bool Vibor;       //для выбора
        int IdDoc;           //идентификатор текущей записи
        int IdGrp;        // идетификатор группы
        int IdElementaMaster;  //идентификатор внешенго справочника-владельца


        bool Error;
        String TextError;
};
//---------------------------------------------------------------------------
extern PACKAGE TDMDocRecKDR *DMDocRecKDR;
//---------------------------------------------------------------------------
#endif
