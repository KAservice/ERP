//---------------------------------------------------------------------------

#ifndef UDMH
#define UDMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "FIBDatabase.hpp"
#include "pFIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDataSet.hpp"
#include <DB.hpp>
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
//---------------------------------------------------------------------------
class TDM : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBDatabase *Database;
	TpFIBTransaction *Transaction;
	TpFIBDataSet *TableTypePrice;
	TFIBBCDField *TableTypePriceID_STYPEPRICE_OBMEN;
	TFIBBCDField *TableTypePriceIDBASE_STYPEPRICE_OBMEN;
	TFIBBCDField *TableTypePriceIDTPRICE_STYPEPRICE_OBMEN;
	TpFIBQuery *Query;
	TpFIBDataSet *TablesBase;
	TpFIBDataSet *BaseForObmen;
	TpFIBDataSet *TableGenerators;
	TpFIBQuery *QueryUpdate;
	TpFIBTransaction *TrUpdate;
	TFIBBCDField *BaseForObmenID_XSETUP_OBMEN;
	TFIBBCDField *BaseForObmenIDBASE_OBMEN_XSETUP_OBMEN;
	TFIBBCDField *BaseForObmenIDTISM_XSETUP_OBMEN;
	TFIBBCDField *BaseForObmenIDBASE_XSETUP_OBMEN;
	TFIBBCDField *BaseForObmenIDFIRST_DO_XSETUP_OBMEN;
	void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDM(TComponent* Owner);

	UnicodeString UserName;
	UnicodeString PasswordUser;
	UnicodeString ConnectString;

	__int64 IdBaseForObmen;

	bool NoOutputEd;
	UnicodeString FileNameOut;
	//AnsiString CatalogObmena;
	int NumRecord;

	bool Error;
	UnicodeString TextError;

	bool ConnectInfBase(void);
	void DisconnectInfBase(void);
	
	void glSetOperation(__int64 id_base_for_obmen, int oper);
	int glGetOperation(__int64 id_base_for_obmen);


	UnicodeString GetVersionProgramFile(void);
	void glSaveProtocol(UnicodeString str);

};

//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
