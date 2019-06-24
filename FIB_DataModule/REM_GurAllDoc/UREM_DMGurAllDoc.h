//---------------------------------------------------------------------------

#ifndef UREM_DMGurAllDocH
#define UREM_DMGurAllDocH
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
class TREM_DMGurAllDoc : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBDataSet *IBQ;
	TpFIBQuery *pFIBQ;
	TFIBLargeIntField *TableID_REM_GALLDOC;
	TFIBLargeIntField *TableIDBASE_REM_GALLDOC;
	TFIBLargeIntField *TableIDFIRM_REM_GALLDOC;
	TFIBLargeIntField *TableIDSKLAD_REM_GALLDOC;
	TFIBLargeIntField *TableIDKLIENT_REM_GALLDOC;
	TFIBLargeIntField *TableIDUSER_REM_GALLDOC;
	TFIBDateTimeField *TablePOS_REM_GALLDOC;
	TFIBIntegerField *TableNUM_REM_GALLDOC;
	TFIBSmallIntField *TablePR_REM_GALLDOC;
	TFIBWideStringField *TableTDOC_REM_GALLDOC;
	TFIBLargeIntField *TableIDDOCOSN_REM_GALLDOC;
	TFIBIntegerField *TableTYPEEXTDOC_REM_GALLDOC;
	TFIBLargeIntField *TableIDEXTDOC_REM_GALLDOC;
	TFIBBCDField *TableSUM_REM_GALLDOC;
	TFIBWideStringField *TableNAMEFIRM;
	TFIBWideStringField *TableNAMESKLAD;
	TFIBWideStringField *TableNAMEKLIENT;
	TFIBWideStringField *TableNAME_USER;
	TFIBWideStringField *TablePREFIKS_NUM_REM_GALLDOC;
	TFIBWideStringField *TableNAME_SINFBASE_OBMEN;
	TFIBLargeIntField *TableIDPROJECT_REM_GALLDOC;
	TFIBLargeIntField *TableIDBUSINOP_REM_GALLDOC;
	TFIBLargeIntField *TableID_REM_GUR_PROV;
	TFIBIntegerField *TableRES_REM_GUR_PROV;
	TFIBLargeIntField *TableIDDOC_REM_GUR_VIGRT;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableTDOC_REM_GALLDOCGetText(TField *Sender, AnsiString &Text,
          bool DisplayText);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


public:		// User declarations
		__fastcall TREM_DMGurAllDoc(TComponent* Owner);

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

		TDateTime PosNach;
		TDateTime PosCon;
		__int64 IdDoc;
		__int64 IdKlient;
		__int64 IdSklad;
		__int64 IdFirm;
		UnicodeString   StringTypeDoc;
		bool OtborVkl;

        void OpenTable();
		void UpdateTable(void);
		bool CancelDvRegDoc(UnicodeString type_doc, __int64 id_doc);
		bool DvRegDoc(UnicodeString type_doc, __int64 id_doc);

        void AllCancelDvRegDoc(void);
		void AllDvRegDoc(void);

		//открыть журнал только с выбранным оборудованием
		bool OpenTableOnlyHardware(__int64 id_hw);

		//открыть журнал только с выбранной заявкой
		bool OpenTableOnlyZayavka(__int64 id_z);



};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMGurAllDoc *REM_DMGurAllDoc;
//---------------------------------------------------------------------------
#endif
