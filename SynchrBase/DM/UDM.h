//---------------------------------------------------------------------------

#ifndef UDMH
#define UDMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <DB.hpp>
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
#include "IB_Services.hpp"
//---------------------------------------------------------------------------
class TDM : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBDatabase *Database1;
	TpFIBTransaction *TrRead1;
	TpFIBDatabase *Database2;
	TpFIBTransaction *TrRead2;
	TpFIBTransaction *TrUpdate2;
	TpFIBDataSet *Tables;
	TpFIBDataSet *Fields;
	TDataSource *DataSourceTables;
	TDataSource *DataSourceFields;
	TFIBWideStringField *FieldsRDBFIELD_NAME;
	TFIBWideStringField *FieldsRDBFIELD_SOURCE;
	TpFIBQuery *Table1Base;
	TpFIBQuery *Element2Base;
	TpFIBQuery *Query;
	TpFIBQuery *QueryRecordCount;
	TpFIBSecurityService *pFIBSecurityService1;
	TpFIBDataSet *SprUser;
	TFIBWideStringField *SprUserNAME_USER;
	TFIBWideStringField *SprUserNAME2_USER;
	TFIBWideStringField *SprUserROLE_SGRPUSER;
	TFIBWideStringField *TablesFIELD_NAME;
	TFIBWideStringField *TablesTABLE_NAME;
	void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
