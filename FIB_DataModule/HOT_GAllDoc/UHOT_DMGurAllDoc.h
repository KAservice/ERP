//---------------------------------------------------------------------------

#ifndef UHOT_DMGurAllDocH
#define UHOT_DMGurAllDocH
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
class THOT_DMGurAllDoc : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBQuery *pFIBQ;
	TFIBDateTimeField *TablePOS_HOT_GALLDOC;
	TFIBSmallIntField *TablePR_HOT_GALLDOC;
	TFIBBCDField *TableSUM_HOT_GALLDOC;
	TpFIBDataSet *IBQ;
	TFIBBCDField *TableID_HOT_GALLDOC;
	TFIBBCDField *TableIDFIRM_HOT_GALLDOC;
	TFIBBCDField *TableIDKL_HOT_GALLDOC;
	TFIBBCDField *TableIDUSER_HOT_GALLDOC;
	TFIBBCDField *TableIDDOCOSN_HOT_GALLDOC;
	TFIBBCDField *TableIDBASE_HOT_GALLDOC;
	TFIBWideStringField *TableTDOC_HOT_GALLDOC;
	TFIBWideStringField *TableNAMEFIRM;
	TFIBWideStringField *TableNAMEKLIENT;
	TFIBWideStringField *TableNAME_USER;
	TFIBIntegerField *TableNUMBER_HOT_GALLDOC;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall TableTDOC_HOT_GALLDOCGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall THOT_DMGurAllDoc(TComponent* Owner);

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


        void OpenTable();
        void UpdateTable(void);
		__int64 IdDocH;

		__int64 IdKlient;
		__int64 IdSklad;
		__int64 IdFirm;
        UnicodeString   StringTypeDoc;

        bool OtborVkl;
        bool OtborPoKlient ;
        bool OtborPoFirm;
        bool OtborPoSklad;
        bool OtborPoTypeDoc;

        bool NoCheck;

        TDateTime PosNach;
        TDateTime PosCon;
		int FindDocPoIdDog(__int64 iddogovor);



		bool CancelDvRegDoc(AnsiString type_doc, __int64 id_doc);
        bool DvRegDoc(AnsiString type_doc, __int64 id_doc);

        void AllCancelDvRegDoc(void);
		void AllDvRegDoc(void);


};
//---------------------------------------------------------------------------
extern PACKAGE THOT_DMGurAllDoc *HOT_DMGurAllDoc;
//---------------------------------------------------------------------------
#endif
