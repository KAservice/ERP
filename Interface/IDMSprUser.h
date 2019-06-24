#ifndef UIDMSprUserH
#define UIDMSprUserH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include "IB_Services.hpp"
class __declspec(uuid(Global_IID_IDMSprUser)) IDMSprUser : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TDataSource * DataSourceElement = {read = get_DataSourceElement , write = set_DataSourceElement};
   virtual TDataSource * get_DataSourceElement(void)=0;
   virtual void set_DataSourceElement(TDataSource * DataSourceElement)=0;

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TpFIBTransaction * pFIBTr = {read = get_pFIBTr , write = set_pFIBTr};
   virtual TpFIBTransaction * get_pFIBTr(void)=0;
   virtual void set_pFIBTr(TpFIBTransaction * pFIBTr)=0;

   __property TpFIBTransaction * pFIBTrUpdate = {read = get_pFIBTrUpdate , write = set_pFIBTrUpdate};
   virtual TpFIBTransaction * get_pFIBTrUpdate(void)=0;
   virtual void set_pFIBTrUpdate(TpFIBTransaction * pFIBTrUpdate)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TIntegerField * TableUSERID = {read = get_TableUSERID , write = set_TableUSERID};
   virtual TIntegerField * get_TableUSERID(void)=0;
   virtual void set_TableUSERID(TIntegerField * TableUSERID)=0;

   __property TpFIBSecurityService * pFIBSecurityService1 = {read = get_pFIBSecurityService1 , write = set_pFIBSecurityService1};
   virtual TpFIBSecurityService * get_pFIBSecurityService1(void)=0;
   virtual void set_pFIBSecurityService1(TpFIBSecurityService * pFIBSecurityService1)=0;

   __property TFIBLargeIntField * TableID_USER = {read = get_TableID_USER , write = set_TableID_USER};
   virtual TFIBLargeIntField * get_TableID_USER(void)=0;
   virtual void set_TableID_USER(TFIBLargeIntField * TableID_USER)=0;

   __property TFIBLargeIntField * TableIDPOD_USER = {read = get_TableIDPOD_USER , write = set_TableIDPOD_USER};
   virtual TFIBLargeIntField * get_TableIDPOD_USER(void)=0;
   virtual void set_TableIDPOD_USER(TFIBLargeIntField * TableIDPOD_USER)=0;

   __property TFIBLargeIntField * TableIDFIRM_USER = {read = get_TableIDFIRM_USER , write = set_TableIDFIRM_USER};
   virtual TFIBLargeIntField * get_TableIDFIRM_USER(void)=0;
   virtual void set_TableIDFIRM_USER(TFIBLargeIntField * TableIDFIRM_USER)=0;

   __property TFIBLargeIntField * TableIDSKLAD_USER = {read = get_TableIDSKLAD_USER , write = set_TableIDSKLAD_USER};
   virtual TFIBLargeIntField * get_TableIDSKLAD_USER(void)=0;
   virtual void set_TableIDSKLAD_USER(TFIBLargeIntField * TableIDSKLAD_USER)=0;

   __property TFIBLargeIntField * TableIDTPRICE_USER = {read = get_TableIDTPRICE_USER , write = set_TableIDTPRICE_USER};
   virtual TFIBLargeIntField * get_TableIDTPRICE_USER(void)=0;
   virtual void set_TableIDTPRICE_USER(TFIBLargeIntField * TableIDTPRICE_USER)=0;

   __property TFIBWideStringField * TableNAME_USER = {read = get_TableNAME_USER , write = set_TableNAME_USER};
   virtual TFIBWideStringField * get_TableNAME_USER(void)=0;
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)=0;

   __property TFIBWideStringField * TableFNAME_USER = {read = get_TableFNAME_USER , write = set_TableFNAME_USER};
   virtual TFIBWideStringField * get_TableFNAME_USER(void)=0;
   virtual void set_TableFNAME_USER(TFIBWideStringField * TableFNAME_USER)=0;

   __property TFIBWideStringField * TablePASSWORD_USER = {read = get_TablePASSWORD_USER , write = set_TablePASSWORD_USER};
   virtual TFIBWideStringField * get_TablePASSWORD_USER(void)=0;
   virtual void set_TablePASSWORD_USER(TFIBWideStringField * TablePASSWORD_USER)=0;

   __property TFIBIntegerField * TableINTERF_USER = {read = get_TableINTERF_USER , write = set_TableINTERF_USER};
   virtual TFIBIntegerField * get_TableINTERF_USER(void)=0;
   virtual void set_TableINTERF_USER(TFIBIntegerField * TableINTERF_USER)=0;

   __property TFIBLargeIntField * TableIDTPRICE1_USER = {read = get_TableIDTPRICE1_USER , write = set_TableIDTPRICE1_USER};
   virtual TFIBLargeIntField * get_TableIDTPRICE1_USER(void)=0;
   virtual void set_TableIDTPRICE1_USER(TFIBLargeIntField * TableIDTPRICE1_USER)=0;

   __property TFIBLargeIntField * TableIDTPRICE2_USER = {read = get_TableIDTPRICE2_USER , write = set_TableIDTPRICE2_USER};
   virtual TFIBLargeIntField * get_TableIDTPRICE2_USER(void)=0;
   virtual void set_TableIDTPRICE2_USER(TFIBLargeIntField * TableIDTPRICE2_USER)=0;

   __property TFIBWideStringField * TableGID_SUSER = {read = get_TableGID_SUSER , write = set_TableGID_SUSER};
   virtual TFIBWideStringField * get_TableGID_SUSER(void)=0;
   virtual void set_TableGID_SUSER(TFIBWideStringField * TableGID_SUSER)=0;

   __property TFIBWideStringField * TablePREFIKS_USER = {read = get_TablePREFIKS_USER , write = set_TablePREFIKS_USER};
   virtual TFIBWideStringField * get_TablePREFIKS_USER(void)=0;
   virtual void set_TablePREFIKS_USER(TFIBWideStringField * TablePREFIKS_USER)=0;

   __property TFIBLargeIntField * TableIDBSCHET_USER = {read = get_TableIDBSCHET_USER , write = set_TableIDBSCHET_USER};
   virtual TFIBLargeIntField * get_TableIDBSCHET_USER(void)=0;
   virtual void set_TableIDBSCHET_USER(TFIBLargeIntField * TableIDBSCHET_USER)=0;

   __property TFIBLargeIntField * TableIDGRP_USER = {read = get_TableIDGRP_USER , write = set_TableIDGRP_USER};
   virtual TFIBLargeIntField * get_TableIDGRP_USER(void)=0;
   virtual void set_TableIDGRP_USER(TFIBLargeIntField * TableIDGRP_USER)=0;

   __property TFIBWideStringField * TableNAME2_USER = {read = get_TableNAME2_USER , write = set_TableNAME2_USER};
   virtual TFIBWideStringField * get_TableNAME2_USER(void)=0;
   virtual void set_TableNAME2_USER(TFIBWideStringField * TableNAME2_USER)=0;

   __property TFIBLargeIntField * TableIDKASSA_USER = {read = get_TableIDKASSA_USER , write = set_TableIDKASSA_USER};
   virtual TFIBLargeIntField * get_TableIDKASSA_USER(void)=0;
   virtual void set_TableIDKASSA_USER(TFIBLargeIntField * TableIDKASSA_USER)=0;

   __property TFIBSmallIntField * TableTPOSREPORT_SUSER = {read = get_TableTPOSREPORT_SUSER , write = set_TableTPOSREPORT_SUSER};
   virtual TFIBSmallIntField * get_TableTPOSREPORT_SUSER(void)=0;
   virtual void set_TableTPOSREPORT_SUSER(TFIBSmallIntField * TableTPOSREPORT_SUSER)=0;

   __property TFIBSmallIntField * TableTPOSGOURNAL_SUSER = {read = get_TableTPOSGOURNAL_SUSER , write = set_TableTPOSGOURNAL_SUSER};
   virtual TFIBSmallIntField * get_TableTPOSGOURNAL_SUSER(void)=0;
   virtual void set_TableTPOSGOURNAL_SUSER(TFIBSmallIntField * TableTPOSGOURNAL_SUSER)=0;

   __property TFIBSmallIntField * TableKOLDAYREP_SUSER = {read = get_TableKOLDAYREP_SUSER , write = set_TableKOLDAYREP_SUSER};
   virtual TFIBSmallIntField * get_TableKOLDAYREP_SUSER(void)=0;
   virtual void set_TableKOLDAYREP_SUSER(TFIBSmallIntField * TableKOLDAYREP_SUSER)=0;

   __property TFIBSmallIntField * TableKOLDAYGUR_SUSER = {read = get_TableKOLDAYGUR_SUSER , write = set_TableKOLDAYGUR_SUSER};
   virtual TFIBSmallIntField * get_TableKOLDAYGUR_SUSER(void)=0;
   virtual void set_TableKOLDAYGUR_SUSER(TFIBSmallIntField * TableKOLDAYGUR_SUSER)=0;

   __property TFIBLargeIntField * TableIDBASE_SUSER = {read = get_TableIDBASE_SUSER , write = set_TableIDBASE_SUSER};
   virtual TFIBLargeIntField * get_TableIDBASE_SUSER(void)=0;
   virtual void set_TableIDBASE_SUSER(TFIBLargeIntField * TableIDBASE_SUSER)=0;

   __property TFIBSmallIntField * TableUPDGUR_AFTER_CLOSE_DOC_SUSER = {read = get_TableUPDGUR_AFTER_CLOSE_DOC_SUSER , write = set_TableUPDGUR_AFTER_CLOSE_DOC_SUSER};
   virtual TFIBSmallIntField * get_TableUPDGUR_AFTER_CLOSE_DOC_SUSER(void)=0;
   virtual void set_TableUPDGUR_AFTER_CLOSE_DOC_SUSER(TFIBSmallIntField * TableUPDGUR_AFTER_CLOSE_DOC_SUSER)=0;

   __property TFIBSmallIntField * TableSPRNOM_OST_SUSER = {read = get_TableSPRNOM_OST_SUSER , write = set_TableSPRNOM_OST_SUSER};
   virtual TFIBSmallIntField * get_TableSPRNOM_OST_SUSER(void)=0;
   virtual void set_TableSPRNOM_OST_SUSER(TFIBSmallIntField * TableSPRNOM_OST_SUSER)=0;

   __property TFIBSmallIntField * TableREOPEN_GUR_SUSER = {read = get_TableREOPEN_GUR_SUSER , write = set_TableREOPEN_GUR_SUSER};
   virtual TFIBSmallIntField * get_TableREOPEN_GUR_SUSER(void)=0;
   virtual void set_TableREOPEN_GUR_SUSER(TFIBSmallIntField * TableREOPEN_GUR_SUSER)=0;

   __property TFIBSmallIntField * TableREOPEN_SPR_SUSER = {read = get_TableREOPEN_SPR_SUSER , write = set_TableREOPEN_SPR_SUSER};
   virtual TFIBSmallIntField * get_TableREOPEN_SPR_SUSER(void)=0;
   virtual void set_TableREOPEN_SPR_SUSER(TFIBSmallIntField * TableREOPEN_SPR_SUSER)=0;

   __property TFIBSmallIntField * TableEDIT_CHUG_DOC_SUSER = {read = get_TableEDIT_CHUG_DOC_SUSER , write = set_TableEDIT_CHUG_DOC_SUSER};
   virtual TFIBSmallIntField * get_TableEDIT_CHUG_DOC_SUSER(void)=0;
   virtual void set_TableEDIT_CHUG_DOC_SUSER(TFIBSmallIntField * TableEDIT_CHUG_DOC_SUSER)=0;

   __property TFIBSmallIntField * TableDEL_CHUG_DOC_SUSER = {read = get_TableDEL_CHUG_DOC_SUSER , write = set_TableDEL_CHUG_DOC_SUSER};
   virtual TFIBSmallIntField * get_TableDEL_CHUG_DOC_SUSER(void)=0;
   virtual void set_TableDEL_CHUG_DOC_SUSER(TFIBSmallIntField * TableDEL_CHUG_DOC_SUSER)=0;

   __property TFIBSmallIntField * TableSHOW_LOG_SUSER = {read = get_TableSHOW_LOG_SUSER , write = set_TableSHOW_LOG_SUSER};
   virtual TFIBSmallIntField * get_TableSHOW_LOG_SUSER(void)=0;
   virtual void set_TableSHOW_LOG_SUSER(TFIBSmallIntField * TableSHOW_LOG_SUSER)=0;

   __property TFIBSmallIntField * TableDETALIED_LOG_SUSER = {read = get_TableDETALIED_LOG_SUSER , write = set_TableDETALIED_LOG_SUSER};
   virtual TFIBSmallIntField * get_TableDETALIED_LOG_SUSER(void)=0;
   virtual void set_TableDETALIED_LOG_SUSER(TFIBSmallIntField * TableDETALIED_LOG_SUSER)=0;

   __property TFIBSmallIntField * TableSAVENAME_SUSER = {read = get_TableSAVENAME_SUSER , write = set_TableSAVENAME_SUSER};
   virtual TFIBSmallIntField * get_TableSAVENAME_SUSER(void)=0;
   virtual void set_TableSAVENAME_SUSER(TFIBSmallIntField * TableSAVENAME_SUSER)=0;

   __property TFIBLargeIntField * TableIDACTCATEGORY_SUSER = {read = get_TableIDACTCATEGORY_SUSER , write = set_TableIDACTCATEGORY_SUSER};
   virtual TFIBLargeIntField * get_TableIDACTCATEGORY_SUSER(void)=0;
   virtual void set_TableIDACTCATEGORY_SUSER(TFIBLargeIntField * TableIDACTCATEGORY_SUSER)=0;

   __property TFIBLargeIntField * ElementID_USER = {read = get_ElementID_USER , write = set_ElementID_USER};
   virtual TFIBLargeIntField * get_ElementID_USER(void)=0;
   virtual void set_ElementID_USER(TFIBLargeIntField * ElementID_USER)=0;

   __property TFIBLargeIntField * ElementIDPOD_USER = {read = get_ElementIDPOD_USER , write = set_ElementIDPOD_USER};
   virtual TFIBLargeIntField * get_ElementIDPOD_USER(void)=0;
   virtual void set_ElementIDPOD_USER(TFIBLargeIntField * ElementIDPOD_USER)=0;

   __property TFIBLargeIntField * ElementIDFIRM_USER = {read = get_ElementIDFIRM_USER , write = set_ElementIDFIRM_USER};
   virtual TFIBLargeIntField * get_ElementIDFIRM_USER(void)=0;
   virtual void set_ElementIDFIRM_USER(TFIBLargeIntField * ElementIDFIRM_USER)=0;

   __property TFIBLargeIntField * ElementIDSKLAD_USER = {read = get_ElementIDSKLAD_USER , write = set_ElementIDSKLAD_USER};
   virtual TFIBLargeIntField * get_ElementIDSKLAD_USER(void)=0;
   virtual void set_ElementIDSKLAD_USER(TFIBLargeIntField * ElementIDSKLAD_USER)=0;

   __property TFIBLargeIntField * ElementIDTPRICE_USER = {read = get_ElementIDTPRICE_USER , write = set_ElementIDTPRICE_USER};
   virtual TFIBLargeIntField * get_ElementIDTPRICE_USER(void)=0;
   virtual void set_ElementIDTPRICE_USER(TFIBLargeIntField * ElementIDTPRICE_USER)=0;

   __property TFIBWideStringField * ElementNAME_USER = {read = get_ElementNAME_USER , write = set_ElementNAME_USER};
   virtual TFIBWideStringField * get_ElementNAME_USER(void)=0;
   virtual void set_ElementNAME_USER(TFIBWideStringField * ElementNAME_USER)=0;

   __property TFIBWideStringField * ElementFNAME_USER = {read = get_ElementFNAME_USER , write = set_ElementFNAME_USER};
   virtual TFIBWideStringField * get_ElementFNAME_USER(void)=0;
   virtual void set_ElementFNAME_USER(TFIBWideStringField * ElementFNAME_USER)=0;

   __property TFIBWideStringField * ElementPASSWORD_USER = {read = get_ElementPASSWORD_USER , write = set_ElementPASSWORD_USER};
   virtual TFIBWideStringField * get_ElementPASSWORD_USER(void)=0;
   virtual void set_ElementPASSWORD_USER(TFIBWideStringField * ElementPASSWORD_USER)=0;

   __property TFIBIntegerField * ElementINTERF_USER = {read = get_ElementINTERF_USER , write = set_ElementINTERF_USER};
   virtual TFIBIntegerField * get_ElementINTERF_USER(void)=0;
   virtual void set_ElementINTERF_USER(TFIBIntegerField * ElementINTERF_USER)=0;

   __property TFIBLargeIntField * ElementIDTPRICE1_USER = {read = get_ElementIDTPRICE1_USER , write = set_ElementIDTPRICE1_USER};
   virtual TFIBLargeIntField * get_ElementIDTPRICE1_USER(void)=0;
   virtual void set_ElementIDTPRICE1_USER(TFIBLargeIntField * ElementIDTPRICE1_USER)=0;

   __property TFIBLargeIntField * ElementIDTPRICE2_USER = {read = get_ElementIDTPRICE2_USER , write = set_ElementIDTPRICE2_USER};
   virtual TFIBLargeIntField * get_ElementIDTPRICE2_USER(void)=0;
   virtual void set_ElementIDTPRICE2_USER(TFIBLargeIntField * ElementIDTPRICE2_USER)=0;

   __property TFIBWideStringField * ElementGID_SUSER = {read = get_ElementGID_SUSER , write = set_ElementGID_SUSER};
   virtual TFIBWideStringField * get_ElementGID_SUSER(void)=0;
   virtual void set_ElementGID_SUSER(TFIBWideStringField * ElementGID_SUSER)=0;

   __property TFIBWideStringField * ElementPREFIKS_USER = {read = get_ElementPREFIKS_USER , write = set_ElementPREFIKS_USER};
   virtual TFIBWideStringField * get_ElementPREFIKS_USER(void)=0;
   virtual void set_ElementPREFIKS_USER(TFIBWideStringField * ElementPREFIKS_USER)=0;

   __property TFIBLargeIntField * ElementIDBSCHET_USER = {read = get_ElementIDBSCHET_USER , write = set_ElementIDBSCHET_USER};
   virtual TFIBLargeIntField * get_ElementIDBSCHET_USER(void)=0;
   virtual void set_ElementIDBSCHET_USER(TFIBLargeIntField * ElementIDBSCHET_USER)=0;

   __property TFIBLargeIntField * ElementIDGRP_USER = {read = get_ElementIDGRP_USER , write = set_ElementIDGRP_USER};
   virtual TFIBLargeIntField * get_ElementIDGRP_USER(void)=0;
   virtual void set_ElementIDGRP_USER(TFIBLargeIntField * ElementIDGRP_USER)=0;

   __property TFIBWideStringField * ElementNAME2_USER = {read = get_ElementNAME2_USER , write = set_ElementNAME2_USER};
   virtual TFIBWideStringField * get_ElementNAME2_USER(void)=0;
   virtual void set_ElementNAME2_USER(TFIBWideStringField * ElementNAME2_USER)=0;

   __property TFIBLargeIntField * ElementIDKASSA_USER = {read = get_ElementIDKASSA_USER , write = set_ElementIDKASSA_USER};
   virtual TFIBLargeIntField * get_ElementIDKASSA_USER(void)=0;
   virtual void set_ElementIDKASSA_USER(TFIBLargeIntField * ElementIDKASSA_USER)=0;

   __property TFIBSmallIntField * ElementTPOSREPORT_SUSER = {read = get_ElementTPOSREPORT_SUSER , write = set_ElementTPOSREPORT_SUSER};
   virtual TFIBSmallIntField * get_ElementTPOSREPORT_SUSER(void)=0;
   virtual void set_ElementTPOSREPORT_SUSER(TFIBSmallIntField * ElementTPOSREPORT_SUSER)=0;

   __property TFIBSmallIntField * ElementTPOSGOURNAL_SUSER = {read = get_ElementTPOSGOURNAL_SUSER , write = set_ElementTPOSGOURNAL_SUSER};
   virtual TFIBSmallIntField * get_ElementTPOSGOURNAL_SUSER(void)=0;
   virtual void set_ElementTPOSGOURNAL_SUSER(TFIBSmallIntField * ElementTPOSGOURNAL_SUSER)=0;

   __property TFIBSmallIntField * ElementKOLDAYREP_SUSER = {read = get_ElementKOLDAYREP_SUSER , write = set_ElementKOLDAYREP_SUSER};
   virtual TFIBSmallIntField * get_ElementKOLDAYREP_SUSER(void)=0;
   virtual void set_ElementKOLDAYREP_SUSER(TFIBSmallIntField * ElementKOLDAYREP_SUSER)=0;

   __property TFIBSmallIntField * ElementKOLDAYGUR_SUSER = {read = get_ElementKOLDAYGUR_SUSER , write = set_ElementKOLDAYGUR_SUSER};
   virtual TFIBSmallIntField * get_ElementKOLDAYGUR_SUSER(void)=0;
   virtual void set_ElementKOLDAYGUR_SUSER(TFIBSmallIntField * ElementKOLDAYGUR_SUSER)=0;

   __property TFIBLargeIntField * ElementIDBASE_SUSER = {read = get_ElementIDBASE_SUSER , write = set_ElementIDBASE_SUSER};
   virtual TFIBLargeIntField * get_ElementIDBASE_SUSER(void)=0;
   virtual void set_ElementIDBASE_SUSER(TFIBLargeIntField * ElementIDBASE_SUSER)=0;

   __property TFIBSmallIntField * ElementUPDGUR_AFTER_CLOSE_DOC_SUSER = {read = get_ElementUPDGUR_AFTER_CLOSE_DOC_SUSER , write = set_ElementUPDGUR_AFTER_CLOSE_DOC_SUSER};
   virtual TFIBSmallIntField * get_ElementUPDGUR_AFTER_CLOSE_DOC_SUSER(void)=0;
   virtual void set_ElementUPDGUR_AFTER_CLOSE_DOC_SUSER(TFIBSmallIntField * ElementUPDGUR_AFTER_CLOSE_DOC_SUSER)=0;

   __property TFIBSmallIntField * ElementSPRNOM_OST_SUSER = {read = get_ElementSPRNOM_OST_SUSER , write = set_ElementSPRNOM_OST_SUSER};
   virtual TFIBSmallIntField * get_ElementSPRNOM_OST_SUSER(void)=0;
   virtual void set_ElementSPRNOM_OST_SUSER(TFIBSmallIntField * ElementSPRNOM_OST_SUSER)=0;

   __property TFIBSmallIntField * ElementREOPEN_GUR_SUSER = {read = get_ElementREOPEN_GUR_SUSER , write = set_ElementREOPEN_GUR_SUSER};
   virtual TFIBSmallIntField * get_ElementREOPEN_GUR_SUSER(void)=0;
   virtual void set_ElementREOPEN_GUR_SUSER(TFIBSmallIntField * ElementREOPEN_GUR_SUSER)=0;

   __property TFIBSmallIntField * ElementREOPEN_SPR_SUSER = {read = get_ElementREOPEN_SPR_SUSER , write = set_ElementREOPEN_SPR_SUSER};
   virtual TFIBSmallIntField * get_ElementREOPEN_SPR_SUSER(void)=0;
   virtual void set_ElementREOPEN_SPR_SUSER(TFIBSmallIntField * ElementREOPEN_SPR_SUSER)=0;

   __property TFIBIntegerField * ElementEDIT_CHUG_DOC_SUSER = {read = get_ElementEDIT_CHUG_DOC_SUSER , write = set_ElementEDIT_CHUG_DOC_SUSER};
   virtual TFIBIntegerField * get_ElementEDIT_CHUG_DOC_SUSER(void)=0;
   virtual void set_ElementEDIT_CHUG_DOC_SUSER(TFIBIntegerField * ElementEDIT_CHUG_DOC_SUSER)=0;

   __property TFIBIntegerField * ElementDEL_CHUG_DOC_SUSER = {read = get_ElementDEL_CHUG_DOC_SUSER , write = set_ElementDEL_CHUG_DOC_SUSER};
   virtual TFIBIntegerField * get_ElementDEL_CHUG_DOC_SUSER(void)=0;
   virtual void set_ElementDEL_CHUG_DOC_SUSER(TFIBIntegerField * ElementDEL_CHUG_DOC_SUSER)=0;

   __property TFIBSmallIntField * ElementSHOW_LOG_SUSER = {read = get_ElementSHOW_LOG_SUSER , write = set_ElementSHOW_LOG_SUSER};
   virtual TFIBSmallIntField * get_ElementSHOW_LOG_SUSER(void)=0;
   virtual void set_ElementSHOW_LOG_SUSER(TFIBSmallIntField * ElementSHOW_LOG_SUSER)=0;

   __property TFIBSmallIntField * ElementDETALIED_LOG_SUSER = {read = get_ElementDETALIED_LOG_SUSER , write = set_ElementDETALIED_LOG_SUSER};
   virtual TFIBSmallIntField * get_ElementDETALIED_LOG_SUSER(void)=0;
   virtual void set_ElementDETALIED_LOG_SUSER(TFIBSmallIntField * ElementDETALIED_LOG_SUSER)=0;

   __property TFIBSmallIntField * ElementSAVENAME_SUSER = {read = get_ElementSAVENAME_SUSER , write = set_ElementSAVENAME_SUSER};
   virtual TFIBSmallIntField * get_ElementSAVENAME_SUSER(void)=0;
   virtual void set_ElementSAVENAME_SUSER(TFIBSmallIntField * ElementSAVENAME_SUSER)=0;

   __property TFIBLargeIntField * ElementIDACTCATEGORY_SUSER = {read = get_ElementIDACTCATEGORY_SUSER , write = set_ElementIDACTCATEGORY_SUSER};
   virtual TFIBLargeIntField * get_ElementIDACTCATEGORY_SUSER(void)=0;
   virtual void set_ElementIDACTCATEGORY_SUSER(TFIBLargeIntField * ElementIDACTCATEGORY_SUSER)=0;

   __property TFIBLargeIntField * ElementIDPOD = {read = get_ElementIDPOD , write = set_ElementIDPOD};
   virtual TFIBLargeIntField * get_ElementIDPOD(void)=0;
   virtual void set_ElementIDPOD(TFIBLargeIntField * ElementIDPOD)=0;

   __property TFIBWideStringField * ElementNAMEPOD = {read = get_ElementNAMEPOD , write = set_ElementNAMEPOD};
   virtual TFIBWideStringField * get_ElementNAMEPOD(void)=0;
   virtual void set_ElementNAMEPOD(TFIBWideStringField * ElementNAMEPOD)=0;

   __property TFIBLargeIntField * ElementIDFIRM = {read = get_ElementIDFIRM , write = set_ElementIDFIRM};
   virtual TFIBLargeIntField * get_ElementIDFIRM(void)=0;
   virtual void set_ElementIDFIRM(TFIBLargeIntField * ElementIDFIRM)=0;

   __property TFIBWideStringField * ElementNAMEFIRM = {read = get_ElementNAMEFIRM , write = set_ElementNAMEFIRM};
   virtual TFIBWideStringField * get_ElementNAMEFIRM(void)=0;
   virtual void set_ElementNAMEFIRM(TFIBWideStringField * ElementNAMEFIRM)=0;

   __property TFIBLargeIntField * ElementIDSKLAD = {read = get_ElementIDSKLAD , write = set_ElementIDSKLAD};
   virtual TFIBLargeIntField * get_ElementIDSKLAD(void)=0;
   virtual void set_ElementIDSKLAD(TFIBLargeIntField * ElementIDSKLAD)=0;

   __property TFIBWideStringField * ElementNAMESKLAD = {read = get_ElementNAMESKLAD , write = set_ElementNAMESKLAD};
   virtual TFIBWideStringField * get_ElementNAMESKLAD(void)=0;
   virtual void set_ElementNAMESKLAD(TFIBWideStringField * ElementNAMESKLAD)=0;

   __property TFIBLargeIntField * ElementID_TPRICE = {read = get_ElementID_TPRICE , write = set_ElementID_TPRICE};
   virtual TFIBLargeIntField * get_ElementID_TPRICE(void)=0;
   virtual void set_ElementID_TPRICE(TFIBLargeIntField * ElementID_TPRICE)=0;

   __property TFIBWideStringField * ElementNAME_TPRICE = {read = get_ElementNAME_TPRICE , write = set_ElementNAME_TPRICE};
   virtual TFIBWideStringField * get_ElementNAME_TPRICE(void)=0;
   virtual void set_ElementNAME_TPRICE(TFIBWideStringField * ElementNAME_TPRICE)=0;

   __property TFIBWideStringField * ElementNAME_SINFBASE_OBMEN = {read = get_ElementNAME_SINFBASE_OBMEN , write = set_ElementNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_ElementNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_ElementNAME_SINFBASE_OBMEN(TFIBWideStringField * ElementNAME_SINFBASE_OBMEN)=0;

   __property TFIBWideStringField * ElementNAMEBSCHET = {read = get_ElementNAMEBSCHET , write = set_ElementNAMEBSCHET};
   virtual TFIBWideStringField * get_ElementNAMEBSCHET(void)=0;
   virtual void set_ElementNAMEBSCHET(TFIBWideStringField * ElementNAMEBSCHET)=0;

   __property TFIBWideStringField * ElementNAMEKKM = {read = get_ElementNAMEKKM , write = set_ElementNAMEKKM};
   virtual TFIBWideStringField * get_ElementNAMEKKM(void)=0;
   virtual void set_ElementNAMEKKM(TFIBWideStringField * ElementNAMEKKM)=0;

   __property TFIBWideStringField * ElementNAME_REM_SACTCATEGORY = {read = get_ElementNAME_REM_SACTCATEGORY , write = set_ElementNAME_REM_SACTCATEGORY};
   virtual TFIBWideStringField * get_ElementNAME_REM_SACTCATEGORY(void)=0;
   virtual void set_ElementNAME_REM_SACTCATEGORY(TFIBWideStringField * ElementNAME_REM_SACTCATEGORY)=0;

   __property bool UserOK = {read = get_UserOK , write = set_UserOK};
   virtual bool get_UserOK(void)=0;
   virtual void set_UserOK(bool UserOK)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   virtual AnsiString GetTextQuery(__int64 id_grp, bool all)=0;
   virtual void OpenTable(__int64 id_grp,bool all)=0;
   virtual int OpenElement(__int64 Id)=0;
   virtual void NewElement(__int64 id_grp)=0;
   virtual bool SaveElement(void)=0;
   virtual void DeleteElement(__int64 Id)=0;
   virtual __int64 FindPoName(String NameUser)=0;
   virtual __int64 FindPoPassword(String Password)=0;
   virtual __int64 GetIdGrpUser(__int64 id_user)=0;
   virtual void ChancheGrp(__int64 new_grp)=0;
   virtual TDateTime GetPosNachReport(void)=0;
   virtual TDateTime GetPosNachGurnal(void)=0;
};
#define IID_IDMSprUser __uuidof(IDMSprUser)
#endif
