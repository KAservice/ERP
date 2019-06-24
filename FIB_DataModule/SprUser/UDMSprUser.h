//---------------------------------------------------------------------------

#ifndef UDMSprUserH
#define UDMSprUserH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "IB_Services.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>



//---------------------------------------------------------------------------
class TDMSprUser : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Element;
	TpFIBTransaction *pFIBTr;
	TpFIBTransaction *pFIBTrUpdate;
	TpFIBDataSet *Table;
	TpFIBQuery *pFIBQ;
	TIntegerField *TableUSERID;
	TpFIBSecurityService *pFIBSecurityService1;
	TFIBLargeIntField *TableID_USER;
	TFIBLargeIntField *TableIDPOD_USER;
	TFIBLargeIntField *TableIDFIRM_USER;
	TFIBLargeIntField *TableIDSKLAD_USER;
	TFIBLargeIntField *TableIDTPRICE_USER;
	TFIBWideStringField *TableNAME_USER;
	TFIBWideStringField *TableFNAME_USER;
	TFIBWideStringField *TablePASSWORD_USER;
	TFIBIntegerField *TableINTERF_USER;
	TFIBLargeIntField *TableIDTPRICE1_USER;
	TFIBLargeIntField *TableIDTPRICE2_USER;
	TFIBWideStringField *TableGID_SUSER;
	TFIBWideStringField *TablePREFIKS_USER;
	TFIBLargeIntField *TableIDBSCHET_USER;
	TFIBLargeIntField *TableIDGRP_USER;
	TFIBWideStringField *TableNAME2_USER;
	TFIBLargeIntField *TableIDKASSA_USER;
	TFIBSmallIntField *TableTPOSREPORT_SUSER;
	TFIBSmallIntField *TableTPOSGOURNAL_SUSER;
	TFIBSmallIntField *TableKOLDAYREP_SUSER;
	TFIBSmallIntField *TableKOLDAYGUR_SUSER;
	TFIBLargeIntField *TableIDBASE_SUSER;
	TFIBSmallIntField *TableUPDGUR_AFTER_CLOSE_DOC_SUSER;
	TFIBSmallIntField *TableSPRNOM_OST_SUSER;
	TFIBSmallIntField *TableREOPEN_GUR_SUSER;
	TFIBSmallIntField *TableREOPEN_SPR_SUSER;
	TFIBSmallIntField *TableEDIT_CHUG_DOC_SUSER;
	TFIBSmallIntField *TableDEL_CHUG_DOC_SUSER;
	TFIBSmallIntField *TableSHOW_LOG_SUSER;
	TFIBSmallIntField *TableDETALIED_LOG_SUSER;
	TFIBSmallIntField *TableSAVENAME_SUSER;
	TFIBLargeIntField *TableIDACTCATEGORY_SUSER;
	TFIBLargeIntField *ElementID_USER;
	TFIBLargeIntField *ElementIDPOD_USER;
	TFIBLargeIntField *ElementIDFIRM_USER;
	TFIBLargeIntField *ElementIDSKLAD_USER;
	TFIBLargeIntField *ElementIDTPRICE_USER;
	TFIBWideStringField *ElementNAME_USER;
	TFIBWideStringField *ElementFNAME_USER;
	TFIBWideStringField *ElementPASSWORD_USER;
	TFIBIntegerField *ElementINTERF_USER;
	TFIBLargeIntField *ElementIDTPRICE1_USER;
	TFIBLargeIntField *ElementIDTPRICE2_USER;
	TFIBWideStringField *ElementGID_SUSER;
	TFIBWideStringField *ElementPREFIKS_USER;
	TFIBLargeIntField *ElementIDBSCHET_USER;
	TFIBLargeIntField *ElementIDGRP_USER;
	TFIBWideStringField *ElementNAME2_USER;
	TFIBLargeIntField *ElementIDKASSA_USER;
	TFIBSmallIntField *ElementTPOSREPORT_SUSER;
	TFIBSmallIntField *ElementTPOSGOURNAL_SUSER;
	TFIBSmallIntField *ElementKOLDAYREP_SUSER;
	TFIBSmallIntField *ElementKOLDAYGUR_SUSER;
	TFIBLargeIntField *ElementIDBASE_SUSER;
	TFIBSmallIntField *ElementUPDGUR_AFTER_CLOSE_DOC_SUSER;
	TFIBSmallIntField *ElementSPRNOM_OST_SUSER;
	TFIBSmallIntField *ElementREOPEN_GUR_SUSER;
	TFIBSmallIntField *ElementREOPEN_SPR_SUSER;
	TFIBIntegerField *ElementEDIT_CHUG_DOC_SUSER;
	TFIBIntegerField *ElementDEL_CHUG_DOC_SUSER;
	TFIBSmallIntField *ElementSHOW_LOG_SUSER;
	TFIBSmallIntField *ElementDETALIED_LOG_SUSER;
	TFIBSmallIntField *ElementSAVENAME_SUSER;
	TFIBLargeIntField *ElementIDACTCATEGORY_SUSER;
	TFIBLargeIntField *ElementIDPOD;
	TFIBWideStringField *ElementNAMEPOD;
	TFIBLargeIntField *ElementIDFIRM;
	TFIBWideStringField *ElementNAMEFIRM;
	TFIBLargeIntField *ElementIDSKLAD;
	TFIBWideStringField *ElementNAMESKLAD;
	TFIBLargeIntField *ElementID_TPRICE;
	TFIBWideStringField *ElementNAME_TPRICE;
	TFIBWideStringField *ElementNAME_SINFBASE_OBMEN;
	TFIBWideStringField *ElementNAMEBSCHET;
	TFIBWideStringField *ElementNAMEKKM;
	TFIBWideStringField *ElementNAME_REM_SACTCATEGORY;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall ElementEDIT_CHUG_DOC_SUSERValidate(TField *Sender);
	void __fastcall ElementDEL_CHUG_DOC_SUSERValidate(TField *Sender);
private:	// User declarations
public:		// User declarations
		__fastcall TDMSprUser(TComponent* Owner);

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

		bool Init(void);
		int Done(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv ;

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
