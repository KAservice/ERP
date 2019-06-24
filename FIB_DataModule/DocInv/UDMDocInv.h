//---------------------------------------------------------------------------

#ifndef UDMDocInvH
#define UDMDocInvH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
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
class TDMDocInv : public TDataModule
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
	TFIBIntegerField *IBQPoGrpTNOM;
	TFIBIntegerField *IBQPoGrpCODENOM;
	TFIBBCDField *IBQPoGrpKF_INVT;
	TFIBBCDField *IBQPoGrpKOLUCH_INVT;
	TFIBBCDField *IBQPoGrpKOLFAKT_INVT;
	TFIBBCDField *IBQPoGrpPRICE_INVT;
	TFIBBCDField *IBQPoGrpSUMF_INVT;
	TpFIBDataSet *IBQ;
	TpFIBDataSet *GoodsDataSet;
	TFIBFloatField *GoodsDataSetSUMKOL;
	TFIBBCDField *GoodsDataSetRSUM;
	TFIBIntegerField *GoodsDataSetCODENOM;
	TpFIBDataSet *OstatkiDataSet;
	TFIBIntegerField *OstatkiDataSetCODENOM;
	TFIBBCDField *OstatkiDataSetKFED;
	TFIBBCDField *OstatkiDataSetSUMKOL;
	TpFIBQuery *pFIBQ;
	TFIBIntegerField *DocTCODENOM;
	TFIBBCDField *DocTKF_INVT;
	TFIBBCDField *DocTKOLUCH_INVT;
	TFIBBCDField *DocTKOLFAKT_INVT;
	TFIBBCDField *DocTPRICE_INVT;
	TFIBBCDField *DocTSUMF_INVT;
	TIntegerField *DocTRECNO;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBQuery *QueryDvReg;
	TFIBBCDField *GoodsDataSetIDNOM_DREVT;
	TFIBBCDField *GoodsDataSetIDED_DREVT;
	TFIBBCDField *OstatkiDataSetIDNOM;
	TFIBBCDField *OstatkiDataSetIDED;
	TFIBBCDField *IBQPoGrpIDGN;
	TFIBBCDField *IBQPoGrpID_INVT;
	TFIBBCDField *IBQPoGrpIDDOC_INVT;
	TFIBBCDField *IBQPoGrpIDNOM_INVT;
	TFIBBCDField *IBQPoGrpIDED_INVT;
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
	TFIBWideStringField *DocAllFNAME_USER;
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocAllNAMEFIRM;
	TFIBWideStringField *DocAllNAMESKLAD;
	TFIBLargeIntField *DocID_INV;
	TFIBLargeIntField *DocIDDOC_INV;
	TFIBWideStringField *DocPRIM_INV;
	TFIBWideStringField *DocGID_INV;
	TFIBLargeIntField *DocIDTPRICE_INV;
	TFIBLargeIntField *DocIDINV_INV;
	TFIBIntegerField *DocTYPE_INV;
	TFIBLargeIntField *DocIDBASE_DINV;
	TFIBWideStringField *DocNAME_SINV;
	TFIBWideStringField *DocTNAMEGN;
	TFIBLargeIntField *DocTIDGN;
	TFIBWideStringField *DocTNAMENOM;
	TFIBIntegerField *DocTTNOM;
	TFIBLargeIntField *DocTID_INVT;
	TFIBLargeIntField *DocTIDDOC_INVT;
	TFIBLargeIntField *DocTIDNOM_INVT;
	TFIBLargeIntField *DocTIDED_INVT;
	TFIBWideStringField *DocTGID_INVT;
	TFIBLargeIntField *DocTIDBASE_DINVT;
	TFIBWideStringField *DocTNAMEED;
	TFIBWideStringField *DocAllFNAMEFIRM;
	TFIBWideStringField *DocAllINNFIRM;
	TFIBWideStringField *DocAllPADRFIRM;
	TFIBWideStringField *IBQPoGrpNAMEGN;
	TFIBWideStringField *IBQPoGrpNAMENOM;
	TFIBWideStringField *IBQPoGrpNAMEED;
	TFIBWideStringField *GoodsDataSetNAMENOM;
	TFIBWideStringField *GoodsDataSetNAMEED;
	TFIBWideStringField *OstatkiDataSetNAMENOM;
	TFIBWideStringField *OstatkiDataSetNAMEED;
	TFIBLargeIntField *DocAllIDBUSINOP_GALLDOC;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBWideStringField *DocAllPREFIKS_NUM_GALLDOC;
	TFIBWideStringField *DocTARTNOM;
	TFIBWideStringField *DocTSHED;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocTAfterDelete(TDataSet *DataSet);
	void __fastcall DocTBeforeDelete(TDataSet *DataSet);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocTKOLFAKT_INVTChange(TField *Sender);
	void __fastcall DocTPRICE_INVTChange(TField *Sender);
	void __fastcall DocAllPOSDOCChange(TField *Sender);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocAllIDBASE_GALLDOCChange(TField *Sender);
	void __fastcall DocAllIDSKLDOCChange(TField *Sender);
	void __fastcall DocAllIDFIRMDOCChange(TField *Sender);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
AnsiString GetTextZaprosDocT(void);
		double Summa(void);

		        double SummaDoc;
		double TekSummaDoc;
		double OldSummaStr;
		double NewSummaStr;

				bool flGetNumberDoc;  //при созданнии нового документа не будем
							  // каждый раз получать номер документа
public:		// User declarations
		__fastcall TDMDocInv(TComponent* Owner);

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
		__int64 IdGrp;        // идетификатор группы
		__int64 IdElementaMaster;  //идентификатор внешенго справочника-владельца



		__int64 IdGrpNom;


		bool ChangeTable;

		void AddDataRev(void);
		bool ErrorRaschet;
		bool SearchStringPoNom(__int64 id_nom);

		bool EnableDvReg;
		int GetNumberNewDoc(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMDocInv *DMDocInv;
//---------------------------------------------------------------------------
#endif
