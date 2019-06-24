//---------------------------------------------------------------------------

#ifndef UDMSprEdH
#define UDMSprEdH
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
class TDMSprEd : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBStringField *TableNAMEED;
	TFIBBCDField *TableKFED;
	TFIBIntegerField *TableTSHED;
	TFIBStringField *TableSHED;
	TFIBSmallIntField *TableNEISPED;
	TIntegerField *TableRECNO;
	TFIBStringField *ElementNAMEED;
	TFIBBCDField *ElementKFED;
	TFIBIntegerField *ElementTSHED;
	TFIBStringField *ElementSHED;
	TFIBSmallIntField *ElementNEISPED;
	TpFIBDataSet *OKEI;
	TFIBStringField *OKEINAMEOKEI;
	TFIBIntegerField *OKEICODEOKEI;
	TpFIBQuery *pFIBQ;
	TFIBStringField *ElementNAMEOKEI;
	TFIBBCDField *ElementIDED;
	TFIBBCDField *ElementIDNOMED;
	TFIBBCDField *ElementIDOKEIED;
	TFIBBCDField *OKEIIDOKEI;
	TFIBStringField *TableGID_SED;
	TFIBStringField *ElementGID_SED;
	TFIBIntegerField *TableCODE_SED;
	TFIBIntegerField *ElementCODE_SED;
	TFIBBCDField *TableKF2_SED;
	TFIBBCDField *TableVES_SED;
	TFIBBCDField *ElementKF2_SED;
	TFIBBCDField *ElementVES_SED;
	TFIBLargeIntField *TableIDED;
	TFIBLargeIntField *TableIDNOMED;
	TFIBLargeIntField *TableIDOKEIED;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
		__fastcall TDMSprEd(TComponent* Owner);

		bool Error;
		AnsiString TextError;

		void OpenTable(__int64 IdNom);
		int OpenElement(__int64 Id);  //возвращает количество элементов
		bool NewElement(__int64 IdNom);
        bool SaveElement(void);
		bool DeleteElement(__int64 Id);
		void NewShtrihCod(void);
		__int64 FindEdPoSh(String ShtrihCod);
		__int64 FindEdPoCodu(int code);

		__int64 GetIDElement(String gid);
		AnsiString GetGIDElement(__int64 id);


		__int64 GetIdNomPoShtrihCodu(AnsiString shtrih_cod);

		bool CheckBarCode(__int64 id_ed, AnsiString sh);
        bool CheckCode(__int64 id_ed, int code);
		int GetCodeEd(void);


};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprEd *DMSprEd;
//---------------------------------------------------------------------------
#endif
