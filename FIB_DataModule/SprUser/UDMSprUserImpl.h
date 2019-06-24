#ifndef UDMSprUserImplH
#define UDMSprUserImplH
#include "IDMSprUser.h"
#include "UDMSprUser.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprUserImpl)) TDMSprUserImpl : public IDMSprUser
{
public:
   TDMSprUserImpl();
   ~TDMSprUserImpl();
   TDMSprUser * Object;
   int NumRefs;
   bool flDeleteObject;
   void DeleteImpl(void);

   //IUnknown
   virtual int kanQueryInterface(REFIID id_interface,void ** ppv);
   virtual int kanAddRef(void);
   virtual int kanRelease(void);

   //IMainInterface
   virtual int  get_CodeError(void);
   virtual void set_CodeError(int CodeError);
   virtual UnicodeString  get_TextError(void);
   virtual void set_TextError(UnicodeString  TextError);
   virtual int Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object);
   virtual int Done(void);

//IDMSprUser
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TpFIBTransaction * get_pFIBTr(void);
   virtual void set_pFIBTr(TpFIBTransaction * pFIBTr);

   virtual TpFIBTransaction * get_pFIBTrUpdate(void);
   virtual void set_pFIBTrUpdate(TpFIBTransaction * pFIBTrUpdate);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TIntegerField * get_TableUSERID(void);
   virtual void set_TableUSERID(TIntegerField * TableUSERID);

   virtual TpFIBSecurityService * get_pFIBSecurityService1(void);
   virtual void set_pFIBSecurityService1(TpFIBSecurityService * pFIBSecurityService1);

   virtual TFIBLargeIntField * get_TableID_USER(void);
   virtual void set_TableID_USER(TFIBLargeIntField * TableID_USER);

   virtual TFIBLargeIntField * get_TableIDPOD_USER(void);
   virtual void set_TableIDPOD_USER(TFIBLargeIntField * TableIDPOD_USER);

   virtual TFIBLargeIntField * get_TableIDFIRM_USER(void);
   virtual void set_TableIDFIRM_USER(TFIBLargeIntField * TableIDFIRM_USER);

   virtual TFIBLargeIntField * get_TableIDSKLAD_USER(void);
   virtual void set_TableIDSKLAD_USER(TFIBLargeIntField * TableIDSKLAD_USER);

   virtual TFIBLargeIntField * get_TableIDTPRICE_USER(void);
   virtual void set_TableIDTPRICE_USER(TFIBLargeIntField * TableIDTPRICE_USER);

   virtual TFIBWideStringField * get_TableNAME_USER(void);
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER);

   virtual TFIBWideStringField * get_TableFNAME_USER(void);
   virtual void set_TableFNAME_USER(TFIBWideStringField * TableFNAME_USER);

   virtual TFIBWideStringField * get_TablePASSWORD_USER(void);
   virtual void set_TablePASSWORD_USER(TFIBWideStringField * TablePASSWORD_USER);

   virtual TFIBIntegerField * get_TableINTERF_USER(void);
   virtual void set_TableINTERF_USER(TFIBIntegerField * TableINTERF_USER);

   virtual TFIBLargeIntField * get_TableIDTPRICE1_USER(void);
   virtual void set_TableIDTPRICE1_USER(TFIBLargeIntField * TableIDTPRICE1_USER);

   virtual TFIBLargeIntField * get_TableIDTPRICE2_USER(void);
   virtual void set_TableIDTPRICE2_USER(TFIBLargeIntField * TableIDTPRICE2_USER);

   virtual TFIBWideStringField * get_TableGID_SUSER(void);
   virtual void set_TableGID_SUSER(TFIBWideStringField * TableGID_SUSER);

   virtual TFIBWideStringField * get_TablePREFIKS_USER(void);
   virtual void set_TablePREFIKS_USER(TFIBWideStringField * TablePREFIKS_USER);

   virtual TFIBLargeIntField * get_TableIDBSCHET_USER(void);
   virtual void set_TableIDBSCHET_USER(TFIBLargeIntField * TableIDBSCHET_USER);

   virtual TFIBLargeIntField * get_TableIDGRP_USER(void);
   virtual void set_TableIDGRP_USER(TFIBLargeIntField * TableIDGRP_USER);

   virtual TFIBWideStringField * get_TableNAME2_USER(void);
   virtual void set_TableNAME2_USER(TFIBWideStringField * TableNAME2_USER);

   virtual TFIBLargeIntField * get_TableIDKASSA_USER(void);
   virtual void set_TableIDKASSA_USER(TFIBLargeIntField * TableIDKASSA_USER);

   virtual TFIBSmallIntField * get_TableTPOSREPORT_SUSER(void);
   virtual void set_TableTPOSREPORT_SUSER(TFIBSmallIntField * TableTPOSREPORT_SUSER);

   virtual TFIBSmallIntField * get_TableTPOSGOURNAL_SUSER(void);
   virtual void set_TableTPOSGOURNAL_SUSER(TFIBSmallIntField * TableTPOSGOURNAL_SUSER);

   virtual TFIBSmallIntField * get_TableKOLDAYREP_SUSER(void);
   virtual void set_TableKOLDAYREP_SUSER(TFIBSmallIntField * TableKOLDAYREP_SUSER);

   virtual TFIBSmallIntField * get_TableKOLDAYGUR_SUSER(void);
   virtual void set_TableKOLDAYGUR_SUSER(TFIBSmallIntField * TableKOLDAYGUR_SUSER);

   virtual TFIBLargeIntField * get_TableIDBASE_SUSER(void);
   virtual void set_TableIDBASE_SUSER(TFIBLargeIntField * TableIDBASE_SUSER);

   virtual TFIBSmallIntField * get_TableUPDGUR_AFTER_CLOSE_DOC_SUSER(void);
   virtual void set_TableUPDGUR_AFTER_CLOSE_DOC_SUSER(TFIBSmallIntField * TableUPDGUR_AFTER_CLOSE_DOC_SUSER);

   virtual TFIBSmallIntField * get_TableSPRNOM_OST_SUSER(void);
   virtual void set_TableSPRNOM_OST_SUSER(TFIBSmallIntField * TableSPRNOM_OST_SUSER);

   virtual TFIBSmallIntField * get_TableREOPEN_GUR_SUSER(void);
   virtual void set_TableREOPEN_GUR_SUSER(TFIBSmallIntField * TableREOPEN_GUR_SUSER);

   virtual TFIBSmallIntField * get_TableREOPEN_SPR_SUSER(void);
   virtual void set_TableREOPEN_SPR_SUSER(TFIBSmallIntField * TableREOPEN_SPR_SUSER);

   virtual TFIBSmallIntField * get_TableEDIT_CHUG_DOC_SUSER(void);
   virtual void set_TableEDIT_CHUG_DOC_SUSER(TFIBSmallIntField * TableEDIT_CHUG_DOC_SUSER);

   virtual TFIBSmallIntField * get_TableDEL_CHUG_DOC_SUSER(void);
   virtual void set_TableDEL_CHUG_DOC_SUSER(TFIBSmallIntField * TableDEL_CHUG_DOC_SUSER);

   virtual TFIBSmallIntField * get_TableSHOW_LOG_SUSER(void);
   virtual void set_TableSHOW_LOG_SUSER(TFIBSmallIntField * TableSHOW_LOG_SUSER);

   virtual TFIBSmallIntField * get_TableDETALIED_LOG_SUSER(void);
   virtual void set_TableDETALIED_LOG_SUSER(TFIBSmallIntField * TableDETALIED_LOG_SUSER);

   virtual TFIBSmallIntField * get_TableSAVENAME_SUSER(void);
   virtual void set_TableSAVENAME_SUSER(TFIBSmallIntField * TableSAVENAME_SUSER);

   virtual TFIBLargeIntField * get_TableIDACTCATEGORY_SUSER(void);
   virtual void set_TableIDACTCATEGORY_SUSER(TFIBLargeIntField * TableIDACTCATEGORY_SUSER);

   virtual TFIBLargeIntField * get_ElementID_USER(void);
   virtual void set_ElementID_USER(TFIBLargeIntField * ElementID_USER);

   virtual TFIBLargeIntField * get_ElementIDPOD_USER(void);
   virtual void set_ElementIDPOD_USER(TFIBLargeIntField * ElementIDPOD_USER);

   virtual TFIBLargeIntField * get_ElementIDFIRM_USER(void);
   virtual void set_ElementIDFIRM_USER(TFIBLargeIntField * ElementIDFIRM_USER);

   virtual TFIBLargeIntField * get_ElementIDSKLAD_USER(void);
   virtual void set_ElementIDSKLAD_USER(TFIBLargeIntField * ElementIDSKLAD_USER);

   virtual TFIBLargeIntField * get_ElementIDTPRICE_USER(void);
   virtual void set_ElementIDTPRICE_USER(TFIBLargeIntField * ElementIDTPRICE_USER);

   virtual TFIBWideStringField * get_ElementNAME_USER(void);
   virtual void set_ElementNAME_USER(TFIBWideStringField * ElementNAME_USER);

   virtual TFIBWideStringField * get_ElementFNAME_USER(void);
   virtual void set_ElementFNAME_USER(TFIBWideStringField * ElementFNAME_USER);

   virtual TFIBWideStringField * get_ElementPASSWORD_USER(void);
   virtual void set_ElementPASSWORD_USER(TFIBWideStringField * ElementPASSWORD_USER);

   virtual TFIBIntegerField * get_ElementINTERF_USER(void);
   virtual void set_ElementINTERF_USER(TFIBIntegerField * ElementINTERF_USER);

   virtual TFIBLargeIntField * get_ElementIDTPRICE1_USER(void);
   virtual void set_ElementIDTPRICE1_USER(TFIBLargeIntField * ElementIDTPRICE1_USER);

   virtual TFIBLargeIntField * get_ElementIDTPRICE2_USER(void);
   virtual void set_ElementIDTPRICE2_USER(TFIBLargeIntField * ElementIDTPRICE2_USER);

   virtual TFIBWideStringField * get_ElementGID_SUSER(void);
   virtual void set_ElementGID_SUSER(TFIBWideStringField * ElementGID_SUSER);

   virtual TFIBWideStringField * get_ElementPREFIKS_USER(void);
   virtual void set_ElementPREFIKS_USER(TFIBWideStringField * ElementPREFIKS_USER);

   virtual TFIBLargeIntField * get_ElementIDBSCHET_USER(void);
   virtual void set_ElementIDBSCHET_USER(TFIBLargeIntField * ElementIDBSCHET_USER);

   virtual TFIBLargeIntField * get_ElementIDGRP_USER(void);
   virtual void set_ElementIDGRP_USER(TFIBLargeIntField * ElementIDGRP_USER);

   virtual TFIBWideStringField * get_ElementNAME2_USER(void);
   virtual void set_ElementNAME2_USER(TFIBWideStringField * ElementNAME2_USER);

   virtual TFIBLargeIntField * get_ElementIDKASSA_USER(void);
   virtual void set_ElementIDKASSA_USER(TFIBLargeIntField * ElementIDKASSA_USER);

   virtual TFIBSmallIntField * get_ElementTPOSREPORT_SUSER(void);
   virtual void set_ElementTPOSREPORT_SUSER(TFIBSmallIntField * ElementTPOSREPORT_SUSER);

   virtual TFIBSmallIntField * get_ElementTPOSGOURNAL_SUSER(void);
   virtual void set_ElementTPOSGOURNAL_SUSER(TFIBSmallIntField * ElementTPOSGOURNAL_SUSER);

   virtual TFIBSmallIntField * get_ElementKOLDAYREP_SUSER(void);
   virtual void set_ElementKOLDAYREP_SUSER(TFIBSmallIntField * ElementKOLDAYREP_SUSER);

   virtual TFIBSmallIntField * get_ElementKOLDAYGUR_SUSER(void);
   virtual void set_ElementKOLDAYGUR_SUSER(TFIBSmallIntField * ElementKOLDAYGUR_SUSER);

   virtual TFIBLargeIntField * get_ElementIDBASE_SUSER(void);
   virtual void set_ElementIDBASE_SUSER(TFIBLargeIntField * ElementIDBASE_SUSER);

   virtual TFIBSmallIntField * get_ElementUPDGUR_AFTER_CLOSE_DOC_SUSER(void);
   virtual void set_ElementUPDGUR_AFTER_CLOSE_DOC_SUSER(TFIBSmallIntField * ElementUPDGUR_AFTER_CLOSE_DOC_SUSER);

   virtual TFIBSmallIntField * get_ElementSPRNOM_OST_SUSER(void);
   virtual void set_ElementSPRNOM_OST_SUSER(TFIBSmallIntField * ElementSPRNOM_OST_SUSER);

   virtual TFIBSmallIntField * get_ElementREOPEN_GUR_SUSER(void);
   virtual void set_ElementREOPEN_GUR_SUSER(TFIBSmallIntField * ElementREOPEN_GUR_SUSER);

   virtual TFIBSmallIntField * get_ElementREOPEN_SPR_SUSER(void);
   virtual void set_ElementREOPEN_SPR_SUSER(TFIBSmallIntField * ElementREOPEN_SPR_SUSER);

   virtual TFIBIntegerField * get_ElementEDIT_CHUG_DOC_SUSER(void);
   virtual void set_ElementEDIT_CHUG_DOC_SUSER(TFIBIntegerField * ElementEDIT_CHUG_DOC_SUSER);

   virtual TFIBIntegerField * get_ElementDEL_CHUG_DOC_SUSER(void);
   virtual void set_ElementDEL_CHUG_DOC_SUSER(TFIBIntegerField * ElementDEL_CHUG_DOC_SUSER);

   virtual TFIBSmallIntField * get_ElementSHOW_LOG_SUSER(void);
   virtual void set_ElementSHOW_LOG_SUSER(TFIBSmallIntField * ElementSHOW_LOG_SUSER);

   virtual TFIBSmallIntField * get_ElementDETALIED_LOG_SUSER(void);
   virtual void set_ElementDETALIED_LOG_SUSER(TFIBSmallIntField * ElementDETALIED_LOG_SUSER);

   virtual TFIBSmallIntField * get_ElementSAVENAME_SUSER(void);
   virtual void set_ElementSAVENAME_SUSER(TFIBSmallIntField * ElementSAVENAME_SUSER);

   virtual TFIBLargeIntField * get_ElementIDACTCATEGORY_SUSER(void);
   virtual void set_ElementIDACTCATEGORY_SUSER(TFIBLargeIntField * ElementIDACTCATEGORY_SUSER);

   virtual TFIBLargeIntField * get_ElementIDPOD(void);
   virtual void set_ElementIDPOD(TFIBLargeIntField * ElementIDPOD);

   virtual TFIBWideStringField * get_ElementNAMEPOD(void);
   virtual void set_ElementNAMEPOD(TFIBWideStringField * ElementNAMEPOD);

   virtual TFIBLargeIntField * get_ElementIDFIRM(void);
   virtual void set_ElementIDFIRM(TFIBLargeIntField * ElementIDFIRM);

   virtual TFIBWideStringField * get_ElementNAMEFIRM(void);
   virtual void set_ElementNAMEFIRM(TFIBWideStringField * ElementNAMEFIRM);

   virtual TFIBLargeIntField * get_ElementIDSKLAD(void);
   virtual void set_ElementIDSKLAD(TFIBLargeIntField * ElementIDSKLAD);

   virtual TFIBWideStringField * get_ElementNAMESKLAD(void);
   virtual void set_ElementNAMESKLAD(TFIBWideStringField * ElementNAMESKLAD);

   virtual TFIBLargeIntField * get_ElementID_TPRICE(void);
   virtual void set_ElementID_TPRICE(TFIBLargeIntField * ElementID_TPRICE);

   virtual TFIBWideStringField * get_ElementNAME_TPRICE(void);
   virtual void set_ElementNAME_TPRICE(TFIBWideStringField * ElementNAME_TPRICE);

   virtual TFIBWideStringField * get_ElementNAME_SINFBASE_OBMEN(void);
   virtual void set_ElementNAME_SINFBASE_OBMEN(TFIBWideStringField * ElementNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_ElementNAMEBSCHET(void);
   virtual void set_ElementNAMEBSCHET(TFIBWideStringField * ElementNAMEBSCHET);

   virtual TFIBWideStringField * get_ElementNAMEKKM(void);
   virtual void set_ElementNAMEKKM(TFIBWideStringField * ElementNAMEKKM);

   virtual TFIBWideStringField * get_ElementNAME_REM_SACTCATEGORY(void);
   virtual void set_ElementNAME_REM_SACTCATEGORY(TFIBWideStringField * ElementNAME_REM_SACTCATEGORY);

   virtual bool get_UserOK(void);
   virtual void set_UserOK(bool UserOK);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual AnsiString GetTextQuery(__int64 id_grp, bool all);
   virtual void OpenTable(__int64 id_grp,bool all);
   virtual int OpenElement(__int64 Id);
   virtual void NewElement(__int64 id_grp);
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 Id);
   virtual __int64 FindPoName(String NameUser);
   virtual __int64 FindPoPassword(String Password);
   virtual __int64 GetIdGrpUser(__int64 id_user);
   virtual void ChancheGrp(__int64 new_grp);
   virtual TDateTime GetPosNachReport(void);
   virtual TDateTime GetPosNachGurnal(void);
};
#define CLSID_TDMSprUserImpl __uuidof(TDMSprUserImpl)
#endif
