//---------------------------------------------------------------------------

#ifndef UHOT_DMDocRealH
#define UHOT_DMDocRealH
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
class THOT_DMDocReal : public TDataModule
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
	TpFIBQuery *pFIBQ;
	TFIBDateTimeField *DocAllPOS_HOT_GALLDOC;
	TFIBSmallIntField *DocAllPR_HOT_GALLDOC;
	TFIBBCDField *DocAllSUM_HOT_GALLDOC;
	TFIBSmallIntField *DocTTUSL_HOT_DREALT;
	TFIBBCDField *DocTKOL_HOT_DREALT;
	TFIBBCDField *DocTKF_HOT_DREALT;
	TFIBBCDField *DocTPRICE_HOT_DREALT;
	TFIBBCDField *DocTSUM_HOT_DREALT;
	TFIBIntegerField *DocTTNOM;
	TIntegerField *DocTRECNO;
	TpFIBQuery *QueryDvReg;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBDataSet *TypePriceDataSet;
	TFIBDateTimeField *DocTPOSNACH_HOT_DREALT;
	TFIBDateTimeField *DocTPOSCON_HOT_DREALT;
	TpFIBDataSet *SpisokGuestOsnUslug;
	TpFIBDataSet *SpisokGuestDopUslug;
	TFIBFloatField *SpisokGuestOsnUslugSUMKOL;
	TFIBBCDField *SpisokGuestDopUslugSUM;
	TFIBBCDField *SpisokGuestDopUslugIDKLIENT;
	TFIBBCDField *SpisokGuestOsnUslugIDKLIENT;
	TpFIBDataSet *NumDoc;
	TFIBIntegerField *NumDocMAXNUMBER;
	TFIBWideStringField *SpisokGuestOsnUslugNAMEKLIENT;
	TFIBWideStringField *SpisokGuestDopUslugNAMEKLIENT;
	TFIBWideStringField *DocAllTDOC_HOT_GALLDOC;
	TFIBIntegerField *DocAllNUMBER_HOT_GALLDOC;
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocAllNAMEFIRM;
	TFIBWideStringField *DocAllNAMEKLIENT;
	TFIBWideStringField *DocAllFNAME_USER;
	TFIBWideStringField *DocAllNAMESKLAD;
	TFIBWideStringField *DocPRIM_HOT_DREAL;
	TFIBWideStringField *DocNAMEKKM_HOT_DREAL;
	TFIBWideStringField *DocZAVNUM_HOT_DREAL;
	TFIBWideStringField *DocREGNUM_HOT_DREAL;
	TFIBWideStringField *DocNUMCHECK_HOT_DREAL;
	TFIBWideStringField *DocNUMKL_HOT_DREAL;
	TFIBWideStringField *DocTNAMENOM;
	TFIBWideStringField *DocTNAMEED;
	TFIBWideStringField *DocTNAME_TPRICE;
	TFIBWideStringField *DocTNAME_HOT_SNF;
	TFIBWideStringField *DocTNAME_HOT_SCATNOM;
	TFIBWideStringField *DocTNAME_HOT_STYPEPOS;
	TFIBWideStringField *DocTNAMEKLIENT;
	TFIBLargeIntField *DocAllID_HOT_GALLDOC;
	TFIBLargeIntField *DocAllIDFIRM_HOT_GALLDOC;
	TFIBLargeIntField *DocAllIDKL_HOT_GALLDOC;
	TFIBLargeIntField *DocAllIDUSER_HOT_GALLDOC;
	TFIBLargeIntField *DocAllIDDOCOSN_HOT_GALLDOC;
	TFIBLargeIntField *DocAllIDSKLAD_HOT_GALLDOC;
	TFIBLargeIntField *DocAllIDBASE_HOT_GALLDOC;
	TFIBLargeIntField *DocID_HOT_DREAL;
	TFIBLargeIntField *DocIDDOCH_HOT_DREAL;
	TFIBLargeIntField *DocIDBASE_HOT_DREAL;
	TFIBLargeIntField *DocIDTPRICE_HOT_DREAL;
	TFIBLargeIntField *DocTID_HOT_DREALT;
	TFIBLargeIntField *DocTIDDOCH_HOT_DREALT;
	TFIBLargeIntField *DocTIDTPRICE_HOT_DREALT;
	TFIBLargeIntField *DocTIDNOM_HOT_DREALT;
	TFIBLargeIntField *DocTIDED_HOT_DREALT;
	TFIBLargeIntField *DocTIDNOMER_HOT_DREALT;
	TFIBLargeIntField *DocTIDCAT_HOT_DREALT;
	TFIBLargeIntField *DocTIDGUEST_HOT_DREALT;
	TFIBLargeIntField *DocTIDTPOS_HOT_DREALT;
	TFIBLargeIntField *DocTIDBASE_HOT_DREALT;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DocTCalcFields(TDataSet *DataSet);
        void __fastcall DocTBeforeDelete(TDataSet *DataSet);
        void __fastcall DocTAfterDelete(TDataSet *DataSet);
        void __fastcall DocNewRecord(TDataSet *DataSet);
        void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocAllPOS_HOT_GALLDOCChange(TField *Sender);
	void __fastcall DocTKOL_HOT_DREALTChange(TField *Sender);
	void __fastcall DocTPRICE_HOT_DREALTChange(TField *Sender);
	void __fastcall DocAllIDBASE_HOT_GALLDOCChange(TField *Sender);
	void __fastcall DocTTUSL_HOT_DREALTGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText);
	void __fastcall DocTTUSL_HOT_DREALTSetText(TField *Sender, const UnicodeString Text);


private:	// User declarations
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
	double Summa(void);
	__int64 IdDoc;           //идентификатор текущей записи
	        double SummaDoc;
		double OldSummaStr;
		double NewSummaStr;
		int KolBron;
public:		// User declarations
		__fastcall THOT_DMDocReal(TComponent* Owner);

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



		//Текущий интерфейс

		void NewDoc(void);
		void OpenDoc(__int64 IdDoc);
        bool SaveDoc(void);
        bool DvRegDoc(void);
        bool CancelDvRegDoc(void);
        void AddDocNewString(void);
        void DeleteStringDoc(void);
        void CloseDoc(void);
		bool DeleteDoc(__int64 id);



        bool Prosmotr;    //только просмотр
        bool NoEdit;
        bool Vibor;       //для выбора








		void AddStringReal(TDateTime pos_nach,TDateTime pos_con,
							__int64 id_nomer, AnsiString name_nomer,
							__int64 id_cat, AnsiString name_cat,
							__int64 id_type_pos, AnsiString name_type_pos,
							__int64 id_guest, AnsiString name_guest,
							bool add_bron);

	   void AddStringNewReal( TDateTime pos_nach,TDateTime pos_con,
							__int64 id_nomer,AnsiString name_nomer,
							__int64 id_cat, AnsiString name_cat,
							__int64 id_type_pos, AnsiString name_type_pos,
							__int64 id_guest, AnsiString name_guest,
							__int64 id_nom, AnsiString name_nom,
							__int64 id_ed, double kf,AnsiString name_ed,
							__int64 id_type_price,
							double kol,
							int type_usl
							);



	   void GetSpisokGuest(void);
	   double GetKolOsnUslugGuest(__int64 id_guest);
	   double GetSumDopUslugGuest(__int64 id_guest);

};
//---------------------------------------------------------------------------
extern PACKAGE THOT_DMDocReal *HOT_DMDocReal;
//---------------------------------------------------------------------------
#endif
