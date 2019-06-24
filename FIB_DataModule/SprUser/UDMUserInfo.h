//---------------------------------------------------------------------------

#ifndef UDMUserInfoH
#define UDMUserInfoH
//---------------------------------------------------------------------------
#include "UDM.h"


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
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include "IB_Services.hpp"
//---------------------------------------------------------------------------
class TDMUserInfo : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceElement;
	TpFIBDataSet *Element;
	TpFIBTransaction *Transaction;
	TFIBSmallIntField *ElementTPOSREPORT_SUSER;
	TFIBSmallIntField *ElementTPOSGOURNAL_SUSER;
	TFIBSmallIntField *ElementKOLDAYREP_SUSER;
	TFIBSmallIntField *ElementKOLDAYGUR_SUSER;
	TFIBBCDField *ElementID_USER;
	TFIBBCDField *ElementIDPOD_USER;
	TFIBBCDField *ElementIDFIRM_USER;
	TFIBBCDField *ElementIDSKLAD_USER;
	TFIBBCDField *ElementIDTPRICE_USER;
	TFIBBCDField *ElementIDTPRICE1_USER;
	TFIBBCDField *ElementIDTPRICE2_USER;
	TFIBBCDField *ElementIDBSCHET_USER;
	TFIBBCDField *ElementIDGRP_USER;
	TFIBBCDField *ElementIDKASSA_USER;
	TFIBBCDField *ElementIDBASE_SUSER;
	TFIBSmallIntField *ElementREOPEN_GUR_SUSER;
	TFIBSmallIntField *ElementREOPEN_SPR_SUSER;
	TFIBSmallIntField *ElementSPRNOM_OST_SUSER;
	TFIBIntegerField *ElementEDIT_CHUG_DOC_SUSER;
	TFIBIntegerField *ElementDEL_CHUG_DOC_SUSER;
	TFIBSmallIntField *ElementSHOW_LOG_SUSER;
	TFIBSmallIntField *ElementDETALIED_LOG_SUSER;
	TFIBSmallIntField *ElementSAVENAME_SUSER;
	TFIBWideStringField *ElementNAME_USER;
	TFIBWideStringField *ElementFNAME_USER;
	TFIBIntegerField *ElementINTERF_USER;
	TFIBWideStringField *ElementNAMEPOD;
	TFIBWideStringField *ElementNAMEFIRM;
	TFIBWideStringField *ElementNAMESKLAD;
	TFIBWideStringField *ElementNAME_TPRICE;
	TFIBWideStringField *ElementNAME_SINFBASE_OBMEN;
	TFIBWideStringField *ElementNAMEBSCHET;
	TFIBWideStringField *ElementNAMEKKM;
	TFIBWideStringField *ElementNAME2_USER;
	TpFIBQuery *Query;
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
		__fastcall TDMUserInfo(TComponent* Owner, TDM * dm_connection);

        bool Error;
		UnicodeString TextError;

		TDM * DM_Connection;

		int TypeApplication;

		bool OpenElement(__int64 id);


		__int64 FindPoName(UnicodeString NameUser);
		__int64 FindPoPassword(UnicodeString Password);
		__int64 GetIdGrpUser(__int64 id_user);

		TDateTime GetPosNachReport(void);
		TDateTime GetPosNachGurnal(void);


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		bool GetPrivDM(int object);
		//application 1 обычное, 2 WEB
		bool GetPrivForm(int object);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMUserInfo *DMUserInfo;
//---------------------------------------------------------------------------
#endif
