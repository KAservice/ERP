//---------------------------------------------------------------------------

#ifndef UDMRegZakH
#define UDMRegZakH
//---------------------------------------------------------------------------

#include "UDM.h"
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
//---------------------------------------------------------------------------
class TDMRegZak : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceDoc;
        TDataSource *DataSourceDocT;
        TDataSource *DataSourceOb;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *Doc;
	TFIBBCDField *DocSUM_ZAK;
	TFIBSmallIntField *DocSOST_ZAK;
	TpFIBDataSet *DocT;
	TFIBBCDField *DocTKOLPR_ZAKT;
	TFIBBCDField *DocTKOLOT_ZAKT;
	TFIBBCDField *DocTKOLZ_ZAKT;
	TFIBBCDField *DocTKF_ZAKT;
	TFIBBCDField *DocTPRICE_ZAKT;
	TFIBBCDField *DocTSUM_ZAKT;
	TFIBBCDField *DocTOTKAZ_ZAKT;
	TFIBIntegerField *DocTTNOM;
	TFIBBCDField *DocTZNACH_PRICE;
	TpFIBDataSet *Ob;
	TFIBSmallIntField *ObGRP_STROB;
	TpFIBDataSet *Table;
	TFIBBCDField *TableSUM_ZAK;
	TFIBSmallIntField *TableSOST_ZAK;
	TpFIBDataSet *IBQPrint;
	TpFIBDataSet *IBQMPrig;
	TpFIBDataSet *IBQNom;
	TFIBBCDField *IBQPrintKF_ZAKT;
	TFIBBCDField *IBQPrintKOLZ_ZAKT;
	TFIBBCDField *IBQPrintKOLPR_ZAKT;
	TFIBBCDField *IBQPrintOTKAZ_ZAKT;
	TIntegerField *DocTRECNO;
	TFIBBCDField *IBQPrintID_ZAKT;
	TFIBBCDField *IBQPrintIDMPRIG_ZAKT;
	TFIBBCDField *TableID_ZAK;
	TFIBBCDField *TableIDOB_ZAK;
	TFIBBCDField *TableIDKLIENT_ZAK;
	TFIBBCDField *TableIDUSER_ZAK;
	TFIBBCDField *DocID_ZAK;
	TFIBBCDField *DocIDOB_ZAK;
	TFIBBCDField *DocIDKLIENT_ZAK;
	TFIBBCDField *DocIDUSER_ZAK;
	TFIBBCDField *DocIDKLIENT;
	TFIBBCDField *DocIDTYPEPRICE_ZAK;
	TFIBBCDField *DocIDDISCOUNTCARD_ZAK;
	TFIBBCDField *DocTPRSK_ZAKT;
	TFIBBCDField *DocTPRNAD_ZAKT;
	TFIBBCDField *DocTSUMSK_ZAKT;
	TFIBBCDField *DocTSUMNAD_ZAKT;
	TFIBBCDField *ObID_STROB;
	TFIBBCDField *ObIDGRP_STROB;
	TFIBBCDField *DocTID_ZAKT;
	TFIBBCDField *DocTIDZ_ZAKT;
	TFIBBCDField *DocTIDNOM_ZAKT;
	TFIBBCDField *DocTIDED_ZAKT;
	TFIBBCDField *DocTIDMPRIG_ZAKT;
	TFIBBCDField *DocTIDBASE_RGZAKT;
	TFIBBCDField *DocTPRSK_CARD_RGZAKT;
	TFIBBCDField *DocTPRSK_AUTO_RGZAKT;
	TFIBWideStringField *IBQPrintKRNAMENOM;
	TFIBWideStringField *IBQPrintNAMEED;
	TFIBWideStringField *IBQMPrigNAME_MPRIG;
	TFIBWideStringField *IBQMPrigCOMPNAME_OBORUD;
	TFIBWideStringField *IBQMPrigCOMNAME_OBORUD;
	TFIBWideStringField *IBQMPrigBAUDRATE_OBORUD;
	TFIBWideStringField *IBQNomNAME_MPRIG;
	TFIBWideStringField *ObNAME_STROB;
	TFIBIntegerField *ObCODE_STROB;
	TFIBWideStringField *ObGID_SSTROB;
	TFIBWideStringField *DocTNAMENOM;
	TFIBWideStringField *DocTKRNAMENOM;
	TFIBWideStringField *DocTNAMEED;
	TFIBWideStringField *DocTNAME_MPRIG;
	TFIBWideStringField *DocNAME_STROB;
	TFIBWideStringField *DocNAMEKLIENT;
	TFIBWideStringField *DocNAME_USER;
	TFIBWideStringField *DocNAME_TPRICE;
	TFIBWideStringField *DocNAME_SDISCOUNT_CARD;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall DocCalcFields(TDataSet *DataSet);
	void __fastcall DocTAfterDelete(TDataSet *DataSet);
	void __fastcall DocTBeforeDelete(TDataSet *DataSet);
	void __fastcall DocTKOLOT_ZAKTChange(TField *Sender);
	void __fastcall DocTKF_ZAKTChange(TField *Sender);
	void __fastcall DocTPRICE_ZAKTChange(TField *Sender);
	void __fastcall DocTPRSK_ZAKTChange(TField *Sender);
	void __fastcall DocTPRNAD_ZAKTChange(TField *Sender);
private:	// User declarations

	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
        double SummaDoc;
		double OldSummaStr;
		double NewSummaStr;
        double Summa(void);

public:		// User declarations
		__fastcall TDMRegZak(TComponent* Owner);

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //функция удаления реализации интерфейса
		bool flDeleteImpl;   //надо ли удалять реализацию при удалении текущего модуля

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //интерфейс класса реализации
		GUID ClsIdImpl;				 //GUID класса реализации



		//IMainInterface

		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);

		void NewDoc(__int64 ob);
        void OpenDoc(__int64 id);
        bool SaveDoc(void);
        void CloseDoc(void);
        void AddDocNewString(void);
        void DeleteStringDoc(void);
		bool DeleteDoc(__int64 id);


		bool Prosmotr;    //только просмотр
		__int64 IdDoc;           //идентификатор текущей записи
		__int64 IdOb;
		__int64 IdTypePrice;



		void OpenMPrig(void);



};
//---------------------------------------------------------------------------
extern PACKAGE TDMRegZak *DMRegZak;
//---------------------------------------------------------------------------
#endif
