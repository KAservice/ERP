//---------------------------------------------------------------------------

#ifndef UDMSprUserH
#define UDMSprUserH
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
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include "IB_Services.hpp"
//---------------------------------------------------------------------------
class TDMSprUser : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Element;
	TpFIBTransaction *pFIBTr;
	TpFIBTransaction *pFIBTrUpdate;
	TFIBStringField *ElementNAME_USER;
	TFIBStringField *ElementFNAME_USER;
	TFIBStringField *ElementPASSWORD_USER;
	TFIBSmallIntField *ElementINTERF_USER;
	TFIBStringField *ElementNAMEPOD;
	TFIBStringField *ElementNAMEFIRM;
	TFIBStringField *ElementNAMESKLAD;
	TFIBStringField *ElementNAME_TPRICE;
	TFIBStringField *ElementNAME_SINFBASE_OBMEN;
	TFIBStringField *ElementNAMEBSCHET;
	TpFIBDataSet *Table;
	TFIBStringField *TableNAME_USER;
	TFIBStringField *TableFNAME_USER;
	TFIBStringField *TablePASSWORD_USER;
	TFIBSmallIntField *TableINTERF_USER;
	TFIBStringField *TablePREFIKS_USER;
	TpFIBQuery *pFIBQ;
	TFIBStringField *ElementNAME2_USER;
	TFIBStringField *TableNAME2_USER;
	TIntegerField *TableUSERID;
	TpFIBSecurityService *pFIBSecurityService1;
	TFIBStringField *ElementNAMEKKM;
	TFIBSmallIntField *ElementTPOSREPORT_SUSER;
	TFIBSmallIntField *ElementTPOSGOURNAL_SUSER;
	TFIBSmallIntField *ElementKOLDAYREP_SUSER;
	TFIBSmallIntField *ElementKOLDAYGUR_SUSER;
	TFIBBCDField *TableID_USER;
	TFIBBCDField *TableIDPOD_USER;
	TFIBBCDField *TableIDFIRM_USER;
	TFIBBCDField *TableIDSKLAD_USER;
	TFIBBCDField *TableIDTPRICE_USER;
	TFIBBCDField *TableIDTPRICE1_USER;
	TFIBBCDField *TableIDTPRICE2_USER;
	TFIBStringField *TableGID_SUSER;
	TFIBBCDField *TableIDBSCHET_USER;
	TFIBBCDField *TableIDGRP_USER;
	TFIBBCDField *TableIDKASSA_USER;
	TFIBSmallIntField *TableTPOSREPORT_SUSER;
	TFIBSmallIntField *TableTPOSGOURNAL_SUSER;
	TFIBBCDField *ElementID_USER;
	TFIBBCDField *ElementIDPOD_USER;
	TFIBBCDField *ElementIDFIRM_USER;
	TFIBBCDField *ElementIDSKLAD_USER;
	TFIBBCDField *ElementIDTPRICE_USER;
	TFIBBCDField *ElementIDTPRICE1_USER;
	TFIBBCDField *ElementIDTPRICE2_USER;
	TFIBStringField *ElementGID_SUSER;
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
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall ElementEDIT_CHUG_DOC_SUSERValidate(TField *Sender);
	void __fastcall ElementDEL_CHUG_DOC_SUSERValidate(TField *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprUser(TComponent* Owner);
		AnsiString GetTextQuery(__int64 id_grp, bool all);
		void OpenTable(__int64 id_grp,bool all);
		int OpenElement(__int64 Id);
		void NewElement(__int64 id_grp);
        bool SaveElement(void);
		void DeleteElement(__int64 Id);

		__int64 FindPoName(String NameUser);
        __int64 FindPoPassword(String Password);

        bool Error;
        String TextError;
		bool UserOK;
		__int64 IdGrp;
		bool AllElement;
		__int64 GetIdGrpUser(__int64 id_user);
		void ChancheGrp(__int64 new_grp);

		TDateTime GetPosNachReport(void);
		TDateTime GetPosNachGurnal(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprUser *DMSprUser;
//---------------------------------------------------------------------------
#endif
