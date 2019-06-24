//---------------------------------------------------------------------------

#ifndef UDMDocIsmPriceH
#define UDMDocIsmPriceH
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
class TDMDocIsmPrice : public TDataModule
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
	TpFIBTransaction *IBTrDvReg;
	TIntegerField *DocTRECNO;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBQuery *QueryDvReg;
	TpFIBDataSet *NumDoc;
	TFloatField *DocTOLDSUM;
	TFloatField *DocTNEWSUM;
	TFloatField *DocTSUMISM;
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
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocAllNAMEFIRM;
	TFIBWideStringField *DocAllNAMESKLAD;
	TFIBWideStringField *DocAllNAMEKLIENT;
	TFIBWideStringField *DocAllFNAME_USER;
	TFIBLargeIntField *DocID_DISMPRICE;
	TFIBWideStringField *DocGID_DISMPRICE;
	TFIBLargeIntField *DocIDDOC_DISMPRICE;
	TFIBWideStringField *DocDESCR_DISMPRICE;
	TFIBLargeIntField *DocIDNEWTPRICE_DISMPRICE;
	TFIBLargeIntField *DocIDBASE_DISMPRICE;
	TFIBIntegerField *DocOPER_DISMPRICE;
	TFIBLargeIntField *DocIDINV_DISMPRICE;
	TFIBWideStringField *DocNAME_SINV;
	TFIBLargeIntField *DocTID_DISMPRICET;
	TFIBWideStringField *DocTGID_DISMPRICET;
	TFIBLargeIntField *DocTIDDOC_DISMPRICET;
	TFIBLargeIntField *DocTIDNOM_DISMPRICET;
	TFIBLargeIntField *DocTIDED_DISMPRICET;
	TFIBBCDField *DocTKOL_DISMPRICET;
	TFIBBCDField *DocTKF_DISMPRICET;
	TFIBBCDField *DocTOLDPRICE_DISMPRICET;
	TFIBBCDField *DocTNEWPRICE_DISMPRICET;
	TFIBLargeIntField *DocTIDBASE_DISMPRICET;
	TFIBWideStringField *DocTNAMENOM;
	TFIBWideStringField *DocTNAMEED;
	TFIBIntegerField *DocTTNOM;
	TFIBLargeIntField *DocAllIDBUSINOP_GALLDOC;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBWideStringField *DocAllPREFIKS_NUM_GALLDOC;
	TFIBBCDField *DocTSEB_PRICE_DISMPRICET;
	TFIBBCDField *DocTSEB_SUM_DISMPRICET;
	TFIBBCDField *DocTNAC_SUM_ED;
	TFIBBCDField *DocTNAC_SUM;
	TFIBBCDField *DocTNAC_NEW_DISMPRICET;
	TFIBBCDField *DocTNAC_OLD_DISMPRICET;
	TFIBWideStringField *DocTSHED;
	TFIBWideStringField *DocTARTNOM;
	TFIBIntegerField *DocTCODENOM;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DocTCalcFields(TDataSet *DataSet);
        void __fastcall DataModuleCreate(TObject *Sender);
        void __fastcall DocNewRecord(TDataSet *DataSet);
        void __fastcall DocTNewRecord(TDataSet *DataSet);
        void __fastcall DocAllPOSDOCChange(TField *Sender);
	void __fastcall DocAllIDBASE_GALLDOCChange(TField *Sender);
	void __fastcall DocAllIDSKLDOCChange(TField *Sender);
	void __fastcall DocAllIDFIRMDOCChange(TField *Sender);
	void __fastcall DocTSEB_SUM_DISMPRICETChange(TField *Sender);
	void __fastcall DocTSEB_PRICE_DISMPRICETChange(TField *Sender);
	void __fastcall DocTKOL_DISMPRICETChange(TField *Sender);
	void __fastcall DocTOLDPRICE_DISMPRICETChange(TField *Sender);
	void __fastcall DocTNEWPRICE_DISMPRICETChange(TField *Sender);
private:	// User declarations
bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

        double SummaDoc;
		double OldSummaStr;
		double NewSummaStr;

				bool flGetNumberDoc;  //при созданнии нового документа не будем
							  // каждый раз получать номер документа
public:		// User declarations
		__fastcall TDMDocIsmPrice(TComponent* Owner);

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
		void ValidateProsmotr(void);
        bool SaveDoc(void);
        bool DvRegDoc(void);
        bool CancelDvRegDoc(void);
        void AddDocNewString(void);
        void DeleteStringDoc(void);
        void CloseDoc(void);
		bool DeleteDoc(__int64 id);

        bool NewElement;  // новый элемент
		bool Prosmotr;    //только просмотр
		UnicodeString ProsmotrText;
		bool NoEdit;
		__int64 IdDoc;           //идентификатор текущей записи
		__int64 IdGrp;        // идетификатор группы
		__int64 IdElementaMaster;  //идентификатор внешенго справочника-владельца

		bool IsmPrice;


		__int64 IdSklad;
        bool AutoRaschet;
		bool EnableDvReg;
        int GetNumberNewDoc(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMDocIsmPrice *DMDocIsmPrice;
//---------------------------------------------------------------------------
#endif
