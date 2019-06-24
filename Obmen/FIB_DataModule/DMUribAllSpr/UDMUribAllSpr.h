//---------------------------------------------------------------------------

#ifndef UDMUribAllSprH
#define UDMUribAllSprH
//---------------------------------------------------------------------------


//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include "FIBDatabase.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBQuery.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDataSet.hpp"
//---------------------------------------------------------------------------
class TDMUribAllSpr : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBDataSet *BaseForObmen;
	TFIBBCDField *BaseForObmenID_XSETUP_OBMEN;
	TFIBBCDField *BaseForObmenIDBASE_OBMEN_XSETUP_OBMEN;
	TFIBBCDField *BaseForObmenIDTISM_XSETUP_OBMEN;
	TFIBSmallIntField *BaseForObmenALLDOC_XSETUP_OBMEN;
	TFIBSmallIntField *BaseForObmenOUTNAC_XSETUP_OBMEN;
	TFIBSmallIntField *BaseForObmenOUTZPRICE_XSETUP_OBMEN;
	TFIBSmallIntField *BaseForObmenNOEDIT_XSETUP_OBMEN;
	TpFIBDataSet *TablesBase;
	TpFIBQuery *Query;
	TpFIBDataSet *TableTypePrice;
	TpFIBTransaction *Transaction;
	TFIBBCDField *TableTypePriceID_XTPRICE_FOR_OBMEN;
	TFIBBCDField *TableTypePriceIDBASE_OBMEN_XTPRICE_FOR_OBMEN;
	TFIBBCDField *TableTypePriceIDTPRICE_XTPRICE_FOR_OBMEN;
	TpFIBDataSet *FieldsTable;
		void __fastcall DataModuleCreate(TObject *Sender);
		void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
		__fastcall TDMUribAllSpr(TComponent* Owner);


	__int64 IdBaseForObmen;

	bool NoOutputEd;
	AnsiString FileNameOut;
	int NumRecord;

	bool Error;
	AnsiString TextError;



	void SaveFileXML(AnsiString str);
	bool CheckRecordForOutput(AnsiString name_table);
	bool CheckFieldForOutput(String name_field, String name_table) ;
	bool CreateXMLDocAllSpr(__int64 id_base);
    void OutputTableInXMLFile(String table_name);

};
//---------------------------------------------------------------------------
extern PACKAGE TDMUribAllSpr *DMUribAllSpr;
//---------------------------------------------------------------------------
#endif
