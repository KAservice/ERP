//---------------------------------------------------------------------------

#ifndef UDMSprVesNomForScaleH
#define UDMSprVesNomForScaleH
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
//---------------------------------------------------------------------------
class TDMSprVesNomForScale : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBDataSet *Element;
	TFIBIntegerField *ElementCODE_SVESNOM;
	TpFIBTransaction *IBTr;
	TpFIBDataSet *Table;
	TFIBIntegerField *TableCODE_SVESNOM;
	TFIBBCDField *TableZNACH_PRICE;
	TIntegerField *TableRECNO;
	TFIBIntegerField *TableCODE_SED;
	TFIBBCDField *TableID_SVESNOM;
	TFIBBCDField *TableIDSCALE_SVESNOM;
	TFIBBCDField *TableIDNOM_SVESNOM;
	TFIBBCDField *TableIDBASE_SVESNOM;
	TFIBBCDField *ElementID_SVESNOM;
	TFIBBCDField *ElementIDSCALE_SVESNOM;
	TFIBBCDField *ElementIDNOM_SVESNOM;
	TFIBBCDField *ElementIDBASE_SVESNOM;
	TFIBWideStringField *TableGID_SVESNOM;
	TFIBWideStringField *TableNAMENOM;
	TFIBWideStringField *TableNAMEED;
	TFIBWideStringField *ElementGID_SVESNOM;
	void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDMSprVesNomForScale(TComponent* Owner);


	__int64 IdScale;
	__int64 IdTypePrice;
    void OpenTable(__int64 id_scale);

	
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprVesNomForScale *DMSprVesNomForScale;
//---------------------------------------------------------------------------
#endif
