//---------------------------------------------------------------------------

#ifndef UDataModuleMainH
#define UDataModuleMainH
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
//---------------------------------------------------------------------------
class TDataModuleMain : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBDatabase *Database;
	TpFIBTransaction *TrRead;
	TpFIBDataSet *UserDataSet;
	TFIBBCDField *UserDataSetID_USER;
	TFIBBCDField *UserDataSetIDPOD_USER;
	TFIBBCDField *UserDataSetIDFIRM_USER;
	TFIBBCDField *UserDataSetIDSKLAD_USER;
	TFIBBCDField *UserDataSetIDTPRICE_USER;
	TFIBWideStringField *UserDataSetNAME_USER;
	TFIBWideStringField *UserDataSetFNAME_USER;
	TFIBWideStringField *UserDataSetPASSWORD_USER;
	TFIBIntegerField *UserDataSetINTERF_USER;
	TFIBBCDField *UserDataSetIDTPRICE1_USER;
	TFIBBCDField *UserDataSetIDTPRICE2_USER;
	TFIBWideStringField *UserDataSetGID_SUSER;
	TFIBWideStringField *UserDataSetPREFIKS_USER;
	TFIBBCDField *UserDataSetIDBSCHET_USER;
	TFIBBCDField *UserDataSetIDGRP_USER;
	TFIBWideStringField *UserDataSetNAME2_USER;
	TFIBBCDField *UserDataSetIDKASSA_USER;
	TFIBSmallIntField *UserDataSetTPOSREPORT_SUSER;
	TFIBSmallIntField *UserDataSetTPOSGOURNAL_SUSER;
	TFIBSmallIntField *UserDataSetKOLDAYREP_SUSER;
	TFIBSmallIntField *UserDataSetKOLDAYGUR_SUSER;
	TFIBBCDField *UserDataSetIDBASE_SUSER;
	TFIBSmallIntField *UserDataSetUPDGUR_AFTER_CLOSE_DOC_SUSER;
	TFIBSmallIntField *UserDataSetSPRNOM_OST_SUSER;
	TFIBSmallIntField *UserDataSetREOPEN_GUR_SUSER;
	TFIBSmallIntField *UserDataSetREOPEN_SPR_SUSER;
	TFIBIntegerField *UserDataSetEDIT_CHUG_DOC_SUSER;
	TFIBIntegerField *UserDataSetDEL_CHUG_DOC_SUSER;
	TFIBSmallIntField *UserDataSetSHOW_LOG_SUSER;
	TFIBSmallIntField *UserDataSetDETALIED_LOG_SUSER;
	TFIBSmallIntField *UserDataSetSAVENAME_SUSER;
	void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDataModuleMain(TComponent* Owner);


	   AnsiString ConnectString;
	   AnsiString NameUser;
	   AnsiString PasswordUser;

	   bool GlobConnect(void);
	   AnsiString TextError;
	   bool Error;
};
//---------------------------------------------------------------------------
extern PACKAGE TDataModuleMain *DataModuleMain;
//---------------------------------------------------------------------------
#endif
