#ifndef UIHOT_DMTableSostNFH
#define UIHOT_DMTableSostNFH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>
class __declspec(uuid("{6E074D8B-B40D-410D-A30B-584F7BAC17F4}")) IHOT_DMTableSostNF : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TDataSource * DataSourceElement = {read = get_DataSourceElement , write = set_DataSourceElement};
   virtual TDataSource * get_DataSourceElement(void)=0;
   virtual void set_DataSourceElement(TDataSource * DataSourceElement)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TFIBIntegerField * TableKOLM_HOT_SOSTNF = {read = get_TableKOLM_HOT_SOSTNF , write = set_TableKOLM_HOT_SOSTNF};
   virtual TFIBIntegerField * get_TableKOLM_HOT_SOSTNF(void)=0;
   virtual void set_TableKOLM_HOT_SOSTNF(TFIBIntegerField * TableKOLM_HOT_SOSTNF)=0;

   __property TFIBDateTimeField * TablePOSNACH_HOT_SOSTNF = {read = get_TablePOSNACH_HOT_SOSTNF , write = set_TablePOSNACH_HOT_SOSTNF};
   virtual TFIBDateTimeField * get_TablePOSNACH_HOT_SOSTNF(void)=0;
   virtual void set_TablePOSNACH_HOT_SOSTNF(TFIBDateTimeField * TablePOSNACH_HOT_SOSTNF)=0;

   __property TFIBDateTimeField * TablePOSCON_HOT_SOSTNF = {read = get_TablePOSCON_HOT_SOSTNF , write = set_TablePOSCON_HOT_SOSTNF};
   virtual TFIBDateTimeField * get_TablePOSCON_HOT_SOSTNF(void)=0;
   virtual void set_TablePOSCON_HOT_SOSTNF(TFIBDateTimeField * TablePOSCON_HOT_SOSTNF)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBIntegerField * ElementKOLM_HOT_SOSTNF = {read = get_ElementKOLM_HOT_SOSTNF , write = set_ElementKOLM_HOT_SOSTNF};
   virtual TFIBIntegerField * get_ElementKOLM_HOT_SOSTNF(void)=0;
   virtual void set_ElementKOLM_HOT_SOSTNF(TFIBIntegerField * ElementKOLM_HOT_SOSTNF)=0;

   __property TFIBDateTimeField * ElementPOSNACH_HOT_SOSTNF = {read = get_ElementPOSNACH_HOT_SOSTNF , write = set_ElementPOSNACH_HOT_SOSTNF};
   virtual TFIBDateTimeField * get_ElementPOSNACH_HOT_SOSTNF(void)=0;
   virtual void set_ElementPOSNACH_HOT_SOSTNF(TFIBDateTimeField * ElementPOSNACH_HOT_SOSTNF)=0;

   __property TFIBDateTimeField * ElementPOSCON_HOT_SOSTNF = {read = get_ElementPOSCON_HOT_SOSTNF , write = set_ElementPOSCON_HOT_SOSTNF};
   virtual TFIBDateTimeField * get_ElementPOSCON_HOT_SOSTNF(void)=0;
   virtual void set_ElementPOSCON_HOT_SOSTNF(TFIBDateTimeField * ElementPOSCON_HOT_SOSTNF)=0;

   __property TFIBBCDField * TableID_HOT_SOSTNF = {read = get_TableID_HOT_SOSTNF , write = set_TableID_HOT_SOSTNF};
   virtual TFIBBCDField * get_TableID_HOT_SOSTNF(void)=0;
   virtual void set_TableID_HOT_SOSTNF(TFIBBCDField * TableID_HOT_SOSTNF)=0;

   __property TFIBBCDField * TableIDNOMER_HOT_SOSTNF = {read = get_TableIDNOMER_HOT_SOSTNF , write = set_TableIDNOMER_HOT_SOSTNF};
   virtual TFIBBCDField * get_TableIDNOMER_HOT_SOSTNF(void)=0;
   virtual void set_TableIDNOMER_HOT_SOSTNF(TFIBBCDField * TableIDNOMER_HOT_SOSTNF)=0;

   __property TFIBBCDField * TableIDPLAT_HOT_SOSTNF = {read = get_TableIDPLAT_HOT_SOSTNF , write = set_TableIDPLAT_HOT_SOSTNF};
   virtual TFIBBCDField * get_TableIDPLAT_HOT_SOSTNF(void)=0;
   virtual void set_TableIDPLAT_HOT_SOSTNF(TFIBBCDField * TableIDPLAT_HOT_SOSTNF)=0;

   __property TFIBBCDField * TableIDGUEST_HOT_SOSTNF = {read = get_TableIDGUEST_HOT_SOSTNF , write = set_TableIDGUEST_HOT_SOSTNF};
   virtual TFIBBCDField * get_TableIDGUEST_HOT_SOSTNF(void)=0;
   virtual void set_TableIDGUEST_HOT_SOSTNF(TFIBBCDField * TableIDGUEST_HOT_SOSTNF)=0;

   __property TFIBBCDField * TableIDSOST_HOT_SOSTNF = {read = get_TableIDSOST_HOT_SOSTNF , write = set_TableIDSOST_HOT_SOSTNF};
   virtual TFIBBCDField * get_TableIDSOST_HOT_SOSTNF(void)=0;
   virtual void set_TableIDSOST_HOT_SOSTNF(TFIBBCDField * TableIDSOST_HOT_SOSTNF)=0;

   __property TFIBBCDField * TableIDTPOS_HOT_SOSTNF = {read = get_TableIDTPOS_HOT_SOSTNF , write = set_TableIDTPOS_HOT_SOSTNF};
   virtual TFIBBCDField * get_TableIDTPOS_HOT_SOSTNF(void)=0;
   virtual void set_TableIDTPOS_HOT_SOSTNF(TFIBBCDField * TableIDTPOS_HOT_SOSTNF)=0;

   __property TFIBBCDField * TableIDCAT_HOT_SOSTNF = {read = get_TableIDCAT_HOT_SOSTNF , write = set_TableIDCAT_HOT_SOSTNF};
   virtual TFIBBCDField * get_TableIDCAT_HOT_SOSTNF(void)=0;
   virtual void set_TableIDCAT_HOT_SOSTNF(TFIBBCDField * TableIDCAT_HOT_SOSTNF)=0;

   __property TFIBBCDField * TableIDDOCH_HOT_SOSTNF = {read = get_TableIDDOCH_HOT_SOSTNF , write = set_TableIDDOCH_HOT_SOSTNF};
   virtual TFIBBCDField * get_TableIDDOCH_HOT_SOSTNF(void)=0;
   virtual void set_TableIDDOCH_HOT_SOSTNF(TFIBBCDField * TableIDDOCH_HOT_SOSTNF)=0;

   __property TFIBBCDField * ElementID_HOT_SOSTNF = {read = get_ElementID_HOT_SOSTNF , write = set_ElementID_HOT_SOSTNF};
   virtual TFIBBCDField * get_ElementID_HOT_SOSTNF(void)=0;
   virtual void set_ElementID_HOT_SOSTNF(TFIBBCDField * ElementID_HOT_SOSTNF)=0;

   __property TFIBBCDField * ElementIDNOMER_HOT_SOSTNF = {read = get_ElementIDNOMER_HOT_SOSTNF , write = set_ElementIDNOMER_HOT_SOSTNF};
   virtual TFIBBCDField * get_ElementIDNOMER_HOT_SOSTNF(void)=0;
   virtual void set_ElementIDNOMER_HOT_SOSTNF(TFIBBCDField * ElementIDNOMER_HOT_SOSTNF)=0;

   __property TFIBBCDField * ElementIDPLAT_HOT_SOSTNF = {read = get_ElementIDPLAT_HOT_SOSTNF , write = set_ElementIDPLAT_HOT_SOSTNF};
   virtual TFIBBCDField * get_ElementIDPLAT_HOT_SOSTNF(void)=0;
   virtual void set_ElementIDPLAT_HOT_SOSTNF(TFIBBCDField * ElementIDPLAT_HOT_SOSTNF)=0;

   __property TFIBBCDField * ElementIDGUEST_HOT_SOSTNF = {read = get_ElementIDGUEST_HOT_SOSTNF , write = set_ElementIDGUEST_HOT_SOSTNF};
   virtual TFIBBCDField * get_ElementIDGUEST_HOT_SOSTNF(void)=0;
   virtual void set_ElementIDGUEST_HOT_SOSTNF(TFIBBCDField * ElementIDGUEST_HOT_SOSTNF)=0;

   __property TFIBBCDField * ElementIDSOST_HOT_SOSTNF = {read = get_ElementIDSOST_HOT_SOSTNF , write = set_ElementIDSOST_HOT_SOSTNF};
   virtual TFIBBCDField * get_ElementIDSOST_HOT_SOSTNF(void)=0;
   virtual void set_ElementIDSOST_HOT_SOSTNF(TFIBBCDField * ElementIDSOST_HOT_SOSTNF)=0;

   __property TFIBBCDField * ElementIDTPOS_HOT_SOSTNF = {read = get_ElementIDTPOS_HOT_SOSTNF , write = set_ElementIDTPOS_HOT_SOSTNF};
   virtual TFIBBCDField * get_ElementIDTPOS_HOT_SOSTNF(void)=0;
   virtual void set_ElementIDTPOS_HOT_SOSTNF(TFIBBCDField * ElementIDTPOS_HOT_SOSTNF)=0;

   __property TFIBBCDField * ElementIDCAT_HOT_SOSTNF = {read = get_ElementIDCAT_HOT_SOSTNF , write = set_ElementIDCAT_HOT_SOSTNF};
   virtual TFIBBCDField * get_ElementIDCAT_HOT_SOSTNF(void)=0;
   virtual void set_ElementIDCAT_HOT_SOSTNF(TFIBBCDField * ElementIDCAT_HOT_SOSTNF)=0;

   __property TFIBBCDField * ElementIDDOCH_HOT_SOSTNF = {read = get_ElementIDDOCH_HOT_SOSTNF , write = set_ElementIDDOCH_HOT_SOSTNF};
   virtual TFIBBCDField * get_ElementIDDOCH_HOT_SOSTNF(void)=0;
   virtual void set_ElementIDDOCH_HOT_SOSTNF(TFIBBCDField * ElementIDDOCH_HOT_SOSTNF)=0;

   __property TFIBBCDField * ElementIDCEL_HOT_SOSTNF = {read = get_ElementIDCEL_HOT_SOSTNF , write = set_ElementIDCEL_HOT_SOSTNF};
   virtual TFIBBCDField * get_ElementIDCEL_HOT_SOSTNF(void)=0;
   virtual void set_ElementIDCEL_HOT_SOSTNF(TFIBBCDField * ElementIDCEL_HOT_SOSTNF)=0;

   __property TFIBWideStringField * TableNAMEPLAT = {read = get_TableNAMEPLAT , write = set_TableNAMEPLAT};
   virtual TFIBWideStringField * get_TableNAMEPLAT(void)=0;
   virtual void set_TableNAMEPLAT(TFIBWideStringField * TableNAMEPLAT)=0;

   __property TFIBWideStringField * TableNAMEGUEST = {read = get_TableNAMEGUEST , write = set_TableNAMEGUEST};
   virtual TFIBWideStringField * get_TableNAMEGUEST(void)=0;
   virtual void set_TableNAMEGUEST(TFIBWideStringField * TableNAMEGUEST)=0;

   __property TFIBWideStringField * TableNAME_HOT_SNF = {read = get_TableNAME_HOT_SNF , write = set_TableNAME_HOT_SNF};
   virtual TFIBWideStringField * get_TableNAME_HOT_SNF(void)=0;
   virtual void set_TableNAME_HOT_SNF(TFIBWideStringField * TableNAME_HOT_SNF)=0;

   __property TFIBWideStringField * TableNAME_HOT_SSOSTNOM = {read = get_TableNAME_HOT_SSOSTNOM , write = set_TableNAME_HOT_SSOSTNOM};
   virtual TFIBWideStringField * get_TableNAME_HOT_SSOSTNOM(void)=0;
   virtual void set_TableNAME_HOT_SSOSTNOM(TFIBWideStringField * TableNAME_HOT_SSOSTNOM)=0;

   __property TFIBWideStringField * TableNAME_HOT_STYPEPOS = {read = get_TableNAME_HOT_STYPEPOS , write = set_TableNAME_HOT_STYPEPOS};
   virtual TFIBWideStringField * get_TableNAME_HOT_STYPEPOS(void)=0;
   virtual void set_TableNAME_HOT_STYPEPOS(TFIBWideStringField * TableNAME_HOT_STYPEPOS)=0;

   __property TFIBWideStringField * ElementNAMEPLAT = {read = get_ElementNAMEPLAT , write = set_ElementNAMEPLAT};
   virtual TFIBWideStringField * get_ElementNAMEPLAT(void)=0;
   virtual void set_ElementNAMEPLAT(TFIBWideStringField * ElementNAMEPLAT)=0;

   __property TFIBWideStringField * ElementNAMEGUEST = {read = get_ElementNAMEGUEST , write = set_ElementNAMEGUEST};
   virtual TFIBWideStringField * get_ElementNAMEGUEST(void)=0;
   virtual void set_ElementNAMEGUEST(TFIBWideStringField * ElementNAMEGUEST)=0;

   __property TFIBWideStringField * ElementNAME_HOT_SNF = {read = get_ElementNAME_HOT_SNF , write = set_ElementNAME_HOT_SNF};
   virtual TFIBWideStringField * get_ElementNAME_HOT_SNF(void)=0;
   virtual void set_ElementNAME_HOT_SNF(TFIBWideStringField * ElementNAME_HOT_SNF)=0;

   __property TFIBWideStringField * ElementNAME_HOT_SSOSTNOM = {read = get_ElementNAME_HOT_SSOSTNOM , write = set_ElementNAME_HOT_SSOSTNOM};
   virtual TFIBWideStringField * get_ElementNAME_HOT_SSOSTNOM(void)=0;
   virtual void set_ElementNAME_HOT_SSOSTNOM(TFIBWideStringField * ElementNAME_HOT_SSOSTNOM)=0;

   __property TFIBWideStringField * ElementNAME_HOT_STYPEPOS = {read = get_ElementNAME_HOT_STYPEPOS , write = set_ElementNAME_HOT_STYPEPOS};
   virtual TFIBWideStringField * get_ElementNAME_HOT_STYPEPOS(void)=0;
   virtual void set_ElementNAME_HOT_STYPEPOS(TFIBWideStringField * ElementNAME_HOT_STYPEPOS)=0;

   __property TFIBWideStringField * ElementNAME_HOT_SCATNOM = {read = get_ElementNAME_HOT_SCATNOM , write = set_ElementNAME_HOT_SCATNOM};
   virtual TFIBWideStringField * get_ElementNAME_HOT_SCATNOM(void)=0;
   virtual void set_ElementNAME_HOT_SCATNOM(TFIBWideStringField * ElementNAME_HOT_SCATNOM)=0;

   __property TFIBWideStringField * ElementNAME_HOT_SCELPR = {read = get_ElementNAME_HOT_SCELPR , write = set_ElementNAME_HOT_SCELPR};
   virtual TFIBWideStringField * get_ElementNAME_HOT_SCELPR(void)=0;
   virtual void set_ElementNAME_HOT_SCELPR(TFIBWideStringField * ElementNAME_HOT_SCELPR)=0;

   __property __int64 IdPlat = {read = get_IdPlat , write = set_IdPlat};
   virtual __int64 get_IdPlat(void)=0;
   virtual void set_IdPlat(__int64 IdPlat)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 Id)=0;
   virtual bool NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 Id)=0;
};
#define IID_IHOT_DMTableSostNF __uuidof(IHOT_DMTableSostNF)
#endif
