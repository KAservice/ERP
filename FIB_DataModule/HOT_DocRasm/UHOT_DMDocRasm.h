//---------------------------------------------------------------------------

#ifndef UHOT_DMDocRasmH
#define UHOT_DMDocRasmH
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
class THOT_DMDocRasm : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceDoc;
        TDataSource *DataSourceDocAll;
	TpFIBDataSet *DocAll;
	TpFIBDataSet *Doc;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBTransaction *IBTrDvReg;
	TpFIBDataSet *NumDoc;
	TFIBIntegerField *NumDocMAXNUMBER;
	TFIBDateTimeField *DocAllPOS_HOT_GALLDOC;
	TFIBSmallIntField *DocAllPR_HOT_GALLDOC;
	TFIBBCDField *DocAllSUM_HOT_GALLDOC;
	TFIBIntegerField *DocAllNUMBER_HOT_GALLDOC;
	TpFIBQuery *QueryDvReg;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBDataSet *DocT;
	TDataSource *DataSourceDocT;
	TFIBWideStringField *DocAllTDOC_HOT_GALLDOC;
	TFIBWideStringField *DocAllFNAME_USER;
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocAllNAMEFIRM;
	TFIBWideStringField *DocAllNAMEKLIENT;
	TFIBWideStringField *DocDESCR_HOT_DRASM;
	TFIBWideStringField *DocORG_HOT_DRASM;
	TFIBWideStringField *DocNAME_HOT_SCELPR;
	TFIBWideStringField *DocTBR_NAME_HOT_SNF;
	TFIBWideStringField *DocTBR_NAME_HOT_SCATNOM;
	TFIBWideStringField *DocTBR_NAME_HOT_STYPEPOS;
	TFIBWideStringField *DocTBR_NAMEGUEST;
	TFIBWideStringField *DocTBR_NAME_HOT_SSOSTNOM;
	TFIBDateTimeField *DocTBR_POSNACH_HOT_SOSTNF;
	TFIBDateTimeField *DocTBR_POSCON_HOT_SOSTNF;
	TFIBIntegerField *DocTBR_KOLM_HOT_SOSTNF;
	TFIBWideStringField *DocTRASM_NAME_HOT_SNF;
	TFIBWideStringField *DocTRASM_NAME_HOT_SCATNOM;
	TFIBWideStringField *DocTRASM_NAME_HOT_STYPEPOS;
	TFIBWideStringField *DocTRASM_NAMEGUEST;
	TFIBWideStringField *DocTRASM_NAME_HOT_SSOSTNOM;
	TFIBDateTimeField *DocTRASM_POSNACH_HOT_SOSTNF;
	TFIBDateTimeField *DocTRASM_POSCON_HOT_SOSTNF;
	TFIBIntegerField *DocTRASM_KOLM_HOT_SOSTNF;
	TFIBWideStringField *DocTBR2_NAME_HOT_SNF;
	TFIBWideStringField *DocTBR2_NAME_HOT_SCATNOM;
	TFIBWideStringField *DocTBR2_NAME_HOT_STYPEPOS;
	TFIBWideStringField *DocTBR2_NAMEGUEST;
	TFIBWideStringField *DocTBR2_NAME_HOT_SSOSTNOM;
	TFIBDateTimeField *DocTBR2_POSNACH_HOT_SOSTNF;
	TFIBDateTimeField *DocTBR2_POSCON_HOT_SOSTNF;
	TFIBIntegerField *DocTBR2_KOLM_HOT_SOSTNF;
	TStringField *DocTBR;
	TStringField *DocTRASM;
	TStringField *DocTBR2;
	TFIBLargeIntField *DocAllID_HOT_GALLDOC;
	TFIBLargeIntField *DocAllIDFIRM_HOT_GALLDOC;
	TFIBLargeIntField *DocAllIDKL_HOT_GALLDOC;
	TFIBLargeIntField *DocAllIDUSER_HOT_GALLDOC;
	TFIBLargeIntField *DocAllIDDOCOSN_HOT_GALLDOC;
	TFIBLargeIntField *DocAllIDBASE_HOT_GALLDOC;
	TFIBLargeIntField *DocID_HOT_DRASM;
	TFIBLargeIntField *DocIDDOCH_HOT_DRASM;
	TFIBLargeIntField *DocIDCELPR_HOT_DRASM;
	TFIBLargeIntField *DocIDBASE_HOT_DRASM;
	TFIBLargeIntField *DocIDTPRICE_HOT_DRASM;
	TFIBLargeIntField *DocTID_HOT_DRASMT;
	TFIBLargeIntField *DocTIDDOCH_HOT_DRASMT;
	TFIBLargeIntField *DocTIDSOSTBR_HOT_DRASMT;
	TFIBLargeIntField *DocTIDSOSTRASM_HOT_DRASMT;
	TFIBLargeIntField *DocTIDSOSTBR2_HOT_DRASMT;
	TFIBLargeIntField *DocTIDBASE_HOT_DRASMT;
	TFIBLargeIntField *DocTRASM_ID_HOT_SNF;
	TFIBLargeIntField *DocTRASM_ID_HOT_SCATNOM;
	TFIBLargeIntField *DocTRASM_ID_HOT_STYPEPOS;
	TFIBLargeIntField *DocTRASM_IDGUEST;
	TFIBLargeIntField *DocTRASM_ID_HOT_SSOSTNOM;
	TFIBLargeIntField *DocTBR2_ID_HOT_SNF;
	TFIBLargeIntField *DocTBR2_ID_HOT_SCATNOM;
	TFIBLargeIntField *DocTBR2_ID_HOT_STYPEPOS;
	TFIBLargeIntField *DocTBR2_IDGUEST;
	TFIBLargeIntField *DocTBR2_ID_HOT_SSOSTNOM;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall DocAllPOSDOCChange(TField *Sender);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocAllIDBASE_HOT_GALLDOCChange(TField *Sender);
	void __fastcall DocNewRecord(TDataSet *DataSet);
private:	// User declarations
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
	double Summa(void);
	__int64 IdDocH;           //идентификатор текущей записи
public:		// User declarations
        __fastcall THOT_DMDocRasm(TComponent* Owner);

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
        void CloseDoc(void);
		bool DeleteDoc(__int64 id);


		void AddString(void);
		void DeleteString(void);

		bool Prosmotr;    //только просмотр
        bool Vibor;       //для выбора




};
//---------------------------------------------------------------------------
extern PACKAGE THOT_DMDocRasm *HOT_DMDocRasm;
//---------------------------------------------------------------------------
#endif
