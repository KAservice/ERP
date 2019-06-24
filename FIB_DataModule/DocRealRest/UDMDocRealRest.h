//---------------------------------------------------------------------------

#ifndef UDMDocRealRestH
#define UDMDocRealRestH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include "UDMRegOtrSpisNom.h"
#include "UDMRegReal.h"
#include "UDMRegSebProd.h"
#include "UDMRegVipuskProd.h"
#include "UDMRegOstNom.h"
#include "UDMRegGoods.h"
#include <IBSQL.hpp>
#include "UDMRegVsRasch.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
//---------------------------------------------------------------------------
class TDMDocRealRest : public TDataModule
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
	TpFIBDataSet *Firma;
	TFIBStringField *FirmaNAMEFIRM;
	TFIBStringField *FirmaFNAMEFIRM;
	TFIBStringField *FirmaPADRFIRM;
	TFIBStringField *FirmaUADRFIRM;
	TFIBStringField *FirmaINNFIRM;
	TFIBStringField *FirmaKPPFIRM;
	TFIBStringField *FirmaDIRFIRM;
	TFIBStringField *FirmaBUHFIRM;
	TFIBStringField *FirmaKASFIRM;
	TFIBStringField *FirmaGID_SFIRM;
	TFIBStringField *FirmaNUMDOCREGFIRM;
	TFIBStringField *FirmaDATEDOCREGFIRM;
	TFIBSmallIntField *FirmaTYPEFIRM;
	TFIBStringField *FirmaOKPOSFIRM;
	TFIBStringField *FirmaOKDPSFIRM;
	TFIBStringField *FirmaTELFIRM;
	TpFIBDataSet *Klient;
	TFIBStringField *KlientNAMEKLIENT;
	TFIBStringField *KlientFNAME;
	TFIBStringField *KlientADRKLIENT;
	TFIBStringField *KlientTELKLIENT;
	TFIBStringField *KlientINNKLIENT;
	TFIBStringField *KlientKPPKLIENT;
	TFIBIntegerField *KlientTKLIENT;
	TFIBStringField *KlientGID_SKLIENT;
	TFIBStringField *KlientOKPOKLIENT;
	TpFIBDataSet *Sklad;
	TFIBStringField *SkladNAMESKLAD;
	TFIBStringField *SkladMOLSKLAD;
	TFIBStringField *SkladADRSKLAD;
	TFIBIntegerField *SkladTSKLAD;
	TFIBStringField *SkladGID_SSKLAD;
	TpFIBDataSet *SpisokTypePrice;
	TFIBDateTimeField *DocAllPOSDOC;
	TFIBSmallIntField *DocAllPRDOC;
	TFIBStringField *DocAllTDOC;
	TFIBIntegerField *DocAllNUMDOC;
	TFIBBCDField *DocAllSUMDOC;
	TFIBStringField *DocAllGID_DOC;
	TFIBStringField *DocAllNAMEFIRM;
	TFIBStringField *DocAllNAMEKLIENT;
	TFIBStringField *DocAllNAMESKLAD;
	TFIBStringField *DocAllNAME_USER;
	TFIBStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBStringField *DocPRIM_REALREST;
	TFIBStringField *DocGID_DREALREST;
	TFIBStringField *DocNAMEKLIENT;
	TFIBStringField *DocNAME_TPRICE;
	TFIBBCDField *DocTKOL_REALRESTT;
	TFIBBCDField *DocTKF_REALRESTT;
	TFIBBCDField *DocTPRICE_REALRESTT;
	TFIBBCDField *DocTSUM_REALRESTT;
	TFIBStringField *DocTGID_DREALRESTT;
	TFIBStringField *DocTKRNAMENOM;
	TFIBStringField *DocTNAMENOM;
	TFIBStringField *DocTNAMEED;
	TFIBIntegerField *DocTTNOM;
	TFIBBCDField *DocTZNACH_PRICE;
	TpFIBDataSet *NumDoc;
	TFIBIntegerField *NumDocMAXNUMBER;
	TpFIBDataSet *TablePart;
	TpFIBTransaction *IBTrDvReg;
	TpFIBDataSet *Doc2;
	TFIBBCDField *TablePartSUMOSTNOM;
	TFIBBCDField *TablePartKOLOSTNOM;
	TFIBDateTimeField *TablePartPOSDOC;
	TFIBSmallIntField *Doc2PRDOC;
	TIntegerField *DocTRECNO;
	TFIBStringField *SpisokTypePriceNAME_TPRICE;
	TFIBStringField *SpisokTypePriceGID_STPRICE;
	TFIBBCDField *FirmaIDFIRM;
	TFIBBCDField *KlientIDKLIENT;
	TFIBBCDField *KlientIDTPRICEKLIENT;
	TFIBBCDField *KlientIDGRPKLIENT;
	TFIBBCDField *KlientIDVIDKLIENT;
	TFIBBCDField *KlientIDCOUNTRYKLIENT;
	TFIBBCDField *SkladIDSKLAD;
	TFIBBCDField *SpisokTypePriceID_TPRICE;
	TFIBBCDField *TablePartIDOSTNOM;
	TFIBBCDField *TablePartIDFIRMOSTNOM;
	TFIBBCDField *TablePartIDSKLOSTNOM;
	TFIBBCDField *TablePartIDNOMOSTNOM;
	TFIBBCDField *TablePartIDPARTOSTNOM;
	TFIBBCDField *DocAllIDDOC;
	TFIBBCDField *DocAllIDFIRMDOC;
	TFIBBCDField *DocAllIDSKLDOC;
	TFIBBCDField *DocAllIDKLDOC;
	TFIBBCDField *DocAllIDDOGDOC;
	TFIBBCDField *DocAllIDUSERDOC;
	TFIBBCDField *DocAllIDDOCOSNDOC;
	TFIBBCDField *DocAllIDEXTDOC;
	TFIBIntegerField *DocAllTYPEEXTDOC;
	TFIBBCDField *DocID_REALREST;
	TFIBBCDField *DocIDDOC_REALREST;
	TFIBBCDField *DocIDPOK_REALREST;
	TFIBBCDField *DocIDTPRICE_REALREST;
	TFIBBCDField *DocTID_REALRESTT;
	TFIBBCDField *DocTIDDOC_REALRESTT;
	TFIBBCDField *DocTIDNOM_REALRESTT;
	TFIBBCDField *DocTIDED_REALRESTT;
	TFIBBCDField *Doc2IDDOC;
	TFIBBCDField *DocAllIDBASE_GALLDOC;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
        void __fastcall DocIDTPRICEChange(TField *Sender);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocAfterDelete(TDataSet *DataSet);
	void __fastcall DocTBeforeDelete(TDataSet *DataSet);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocAllPOSDOCChange(TField *Sender);
	void __fastcall DocAllNAME_SINFBASE_OBMENGetText(TField *Sender,
          AnsiString &Text, bool DisplayText);
	void __fastcall DocTKOL_REALRESTTChange(TField *Sender);
	void __fastcall DocTKF_REALRESTTChange(TField *Sender);
	void __fastcall DocTPRICE_REALRESTTChange(TField *Sender);
private:	// User declarations

public:		// User declarations
        __fastcall TDMDocRealRest(TComponent* Owner);


		TDMRegOstNom *DMRegOstNom;
		TDMRegGoods * DMRegGoods;
		TDMRegOtrSpisNom *DMRegOtrSpisNom;
		TDMRegReal *  DMRegReal ;
		TDMRegSebProd  * DMRegSebProd;
		TDMRegVipuskProd * DMRegVipuskProd;
        TDMRegVsRasch * DMRegVsRasch ;
        
        void NewDoc(void);
		void OpenDoc(__int64 IdDoc);
        bool SaveDoc(void);
        bool DvRegDoc(void);
        bool CancelDvRegDoc(void);
		bool DeleteDoc(__int64 id);
        void AddDocNewString(void);
        void DeleteStringDoc(void);
        void CloseDoc(void);
        double Summa(void);
        void SpisatPartSoSklada(double Kol, double Sum);
		void SpisatNomSoSklada(__int64 IdNom,double KolSpis);
        void SpisatProdSoSklada(void);
		void SpisatProd(__int64 idnom, float kol);

        bool NewElement;  // новый элемент
        bool Prosmotr;    //только просмотр
        bool Vibor;       //для выбора
		__int64 IdDoc;           //идентификатор текущей записи
		__int64 IdGrp;        // идетификатор группы
		__int64 IdElementaMaster;  //идентификатор внешенго справочника-владельца
		__int64 IdTypePrice;

        double SummaDoc;
        double SummaSkidok;
        double SummaNadbavok;
        double SummaDocFull;

        double TekSummaDoc;

        double OldSummaStr;
        double NewSummaStr;

        double OldSummaSkidokStr;
        double NewSummaSkidokStr;

        double OldSummaNadbavokStr;
        double NewSummaNadbavokStr;

        double OldSummaFullStr;
        double NewSummaFullStr;

        String TextError;
        bool Error;

        double SebReal;
        double SebProd;
        double SebNom;
        double KolOtrSpisNom;
        double KolSpisNom;
        double KolBasEdinic;
        double KolBasEdinic2;
        double KFEd;
        int Operation;    //1-реализация, 2-перемещение, 3-на выпуск продукции, 4-списание
        __int64 IdSklad;
        bool EnableDvReg;
		bool SkladRozn;

		bool NoOtrOstatok;
        
};
//---------------------------------------------------------------------------
extern PACKAGE TDMDocRealRest *DMDocRealRest;
//---------------------------------------------------------------------------
#endif
