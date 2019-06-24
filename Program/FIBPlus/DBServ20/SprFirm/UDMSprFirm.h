//---------------------------------------------------------------------------

#ifndef UDMSprFirmH
#define UDMSprFirmH
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
class TDMSprFirm : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceElement;
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBStringField *TableINNFIRM;
	TFIBStringField *TableNAMEFIRM;
	TIntegerField *TableRECNO;
	TFIBStringField *ElementNAMEFIRM;
	TFIBStringField *ElementFNAMEFIRM;
	TFIBStringField *ElementPADRFIRM;
	TFIBStringField *ElementUADRFIRM;
	TFIBStringField *ElementINNFIRM;
	TFIBStringField *ElementKPPFIRM;
	TFIBStringField *ElementDIRFIRM;
	TFIBStringField *ElementBUHFIRM;
	TFIBStringField *ElementKASFIRM;
	TFIBStringField *ElementNUMDOCREGFIRM;
	TFIBStringField *ElementDATEDOCREGFIRM;
	TFIBSmallIntField *ElementTYPEFIRM;
	TFIBStringField *ElementOKPOSFIRM;
	TFIBStringField *ElementOKDPSFIRM;
	TFIBStringField *ElementTELFIRM;
	TpFIBQuery *pFIBQ;
	TFIBBCDField *TableIDFIRM;
	TFIBBCDField *ElementIDFIRM;
	TFIBStringField *ElementGID_SFIRM;
	TFIBStringField *ElementKRNAMEFIRM;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
		__fastcall TDMSprFirm(TComponent* Owner);

        bool Error;
		AnsiString TextError;

		void OpenTable(void);
		int OpenElement(__int64 Id);  //возвращает количество элементов
        void NewElement(void);
        bool SaveElement(void);
		void DeleteElement(__int64 Id);
		AnsiString GetGIDElement(__int64 id);
		__int64 GetIDElement(AnsiString gid);

		int GetIndexElementaPoID(__int64 id);

};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprFirm *DMSprFirm;
//---------------------------------------------------------------------------
#endif
