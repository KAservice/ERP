//---------------------------------------------------------------------------

#ifndef UHOT_DMDocRaschetH
#define UHOT_DMDocRaschetH
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
class THOT_DMDocRaschet : public TDataModule
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
	TpFIBQuery *QueryDvReg;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBDataSet *TypePriceDataSet;
	TFIBSmallIntField *DocTTUSL_HOT_DRASCHETT;
	TFIBBCDField *DocTKOL_HOT_DRASCHETT;
	TFIBBCDField *DocTKF_HOT_DRASCHETT;
	TFIBBCDField *DocTPRICE_HOT_DRASCHETT;
	TIntegerField *DocTRECNO;
	TFIBBCDField *DocTSUM_HOT_DRASCHETT;
	TFIBDateTimeField *DocTPOSNACH_HOT_DRASCHETT;
	TFIBDateTimeField *DocTPOSCON_HOT_DRASCHETT;
	TStringField *DocTVIBOR_TYPE_PRICE;
	TpFIBDataSet *SpisokGuestOsnUslug;
	TpFIBDataSet *SpisokGuestDopUslug;
	TFIBFloatField *SpisokGuestOsnUslugSUMKOL;
	TFIBBCDField *SpisokGuestDopUslugSUM;
	TFIBBCDField *SpisokGuestOsnUslugIDKLIENT;
	TFIBBCDField *SpisokGuestDopUslugIDKLIENT;
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
	TFIBWideStringField *DocPRIM_HOT_DRASCHET;
	TFIBWideStringField *DocNAMEBSCHET;
	TFIBWideStringField *DocTNAMENOM;
	TFIBWideStringField *DocTNAMEED;
	TFIBSmallIntField *DocTTNOM;
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
	TFIBLargeIntField *DocID_HOT_DRASCHET;
	TFIBLargeIntField *DocIDDOCH_HOT_DRASCHET;
	TFIBLargeIntField *DocIDBSCHET_HOT_DRASCHET;
	TFIBLargeIntField *DocIDBASE_HOT_DRASCHET;
	TFIBLargeIntField *DocIDTPRICE_HOT_DRASCHET;
	TFIBLargeIntField *DocTID_HOT_DRASCHETT;
	TFIBLargeIntField *DocTIDDOCH_HOT_DRASCHETT;
	TFIBLargeIntField *DocTIDTPRICE_HOT_DRASCHETT;
	TFIBLargeIntField *DocTIDNOM_HOT_DRASCHETT;
	TFIBLargeIntField *DocTIDED_HOT_DRASCHETT;
	TFIBLargeIntField *DocTIDNOMER_HOT_DRASCHETT;
	TFIBLargeIntField *DocTIDCAT_HOT_DRASCHETT;
	TFIBLargeIntField *DocTIDGUEST_HOT_DRASCHETT;
	TFIBLargeIntField *DocTIDTPOS_HOT_DRASCHETT;
	TFIBLargeIntField *DocTIDBASE_HOT_DRASCHETT;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DocTCalcFields(TDataSet *DataSet);
        void __fastcall DocTBeforeDelete(TDataSet *DataSet);
        void __fastcall DocTAfterDelete(TDataSet *DataSet);
        void __fastcall DocNewRecord(TDataSet *DataSet);
        void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocAllPOS_HOT_GALLDOCChange(TField *Sender);
	void __fastcall DocTKOL_HOT_DRASCHETTChange(TField *Sender);
	void __fastcall DocTPRICE_HOT_DRASCHETTChange(TField *Sender);
	void __fastcall DocAllIDBASE_HOT_GALLDOCChange(TField *Sender);
	void __fastcall DocTTUSL_HOT_DRASCHETTGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText);
	void __fastcall DocTTUSL_HOT_DRASCHETTSetText(TField *Sender, const UnicodeString Text);


private:	// User declarations
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

        double SummaDoc;
		double OldSummaStr;
		double NewSummaStr;
		 double Summa(void);
		 __int64 IdDoc;
public:		// User declarations
        __fastcall THOT_DMDocRaschet(TComponent* Owner);

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
		void AddString(void);
        void DeleteString(void);
        void CloseDoc(void);
		bool DeleteDoc(__int64 id);



		bool Prosmotr;    //только просмотр
        bool NoEdit;
		bool Vibor;       //для выбора






		void AddStringReal(TDateTime pos_nach,TDateTime pos_con,
							__int64 id_nomer, AnsiString name_nomer,
							__int64 id_cat, AnsiString name_cat,
							__int64 id_type_pos, AnsiString name_type_pos,
							__int64 id_guest, AnsiString name_guest);

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

	 int KolBron;

	   void GetSpisokGuest(void);
	   double GetKolOsnUslugGuest(__int64 id_guest);
	   double GetSumDopUslugGuest(__int64 id_guest);

};
//---------------------------------------------------------------------------
extern PACKAGE THOT_DMDocRaschet *HOT_DMDocRaschet;
//---------------------------------------------------------------------------
#endif
