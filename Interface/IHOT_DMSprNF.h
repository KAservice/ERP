#ifndef UIHOT_DMSprNFH
#define UIHOT_DMSprNFH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>
class __declspec(uuid("{F3EE8380-DE2A-4042-8754-D0DD414C22A8}")) IHOT_DMSprNF : public IMainInterface
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

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBIntegerField * TableKOLM_HOT_SNF = {read = get_TableKOLM_HOT_SNF , write = set_TableKOLM_HOT_SNF};
   virtual TFIBIntegerField * get_TableKOLM_HOT_SNF(void)=0;
   virtual void set_TableKOLM_HOT_SNF(TFIBIntegerField * TableKOLM_HOT_SNF)=0;

   __property TFIBDateTimeField * TablePOSIN_HOT_SNF = {read = get_TablePOSIN_HOT_SNF , write = set_TablePOSIN_HOT_SNF};
   virtual TFIBDateTimeField * get_TablePOSIN_HOT_SNF(void)=0;
   virtual void set_TablePOSIN_HOT_SNF(TFIBDateTimeField * TablePOSIN_HOT_SNF)=0;

   __property TFIBDateTimeField * TablePOSOUT_HOT_SNF = {read = get_TablePOSOUT_HOT_SNF , write = set_TablePOSOUT_HOT_SNF};
   virtual TFIBDateTimeField * get_TablePOSOUT_HOT_SNF(void)=0;
   virtual void set_TablePOSOUT_HOT_SNF(TFIBDateTimeField * TablePOSOUT_HOT_SNF)=0;

   __property TFIBIntegerField * ElementKOLM_HOT_SNF = {read = get_ElementKOLM_HOT_SNF , write = set_ElementKOLM_HOT_SNF};
   virtual TFIBIntegerField * get_ElementKOLM_HOT_SNF(void)=0;
   virtual void set_ElementKOLM_HOT_SNF(TFIBIntegerField * ElementKOLM_HOT_SNF)=0;

   __property TFIBDateTimeField * ElementPOSIN_HOT_SNF = {read = get_ElementPOSIN_HOT_SNF , write = set_ElementPOSIN_HOT_SNF};
   virtual TFIBDateTimeField * get_ElementPOSIN_HOT_SNF(void)=0;
   virtual void set_ElementPOSIN_HOT_SNF(TFIBDateTimeField * ElementPOSIN_HOT_SNF)=0;

   __property TFIBDateTimeField * ElementPOSOUT_HOT_SNF = {read = get_ElementPOSOUT_HOT_SNF , write = set_ElementPOSOUT_HOT_SNF};
   virtual TFIBDateTimeField * get_ElementPOSOUT_HOT_SNF(void)=0;
   virtual void set_ElementPOSOUT_HOT_SNF(TFIBDateTimeField * ElementPOSOUT_HOT_SNF)=0;

   __property TFIBBCDField * ElementID_HOT_SNF = {read = get_ElementID_HOT_SNF , write = set_ElementID_HOT_SNF};
   virtual TFIBBCDField * get_ElementID_HOT_SNF(void)=0;
   virtual void set_ElementID_HOT_SNF(TFIBBCDField * ElementID_HOT_SNF)=0;

   __property TFIBBCDField * ElementIDOB_HOT_SNF = {read = get_ElementIDOB_HOT_SNF , write = set_ElementIDOB_HOT_SNF};
   virtual TFIBBCDField * get_ElementIDOB_HOT_SNF(void)=0;
   virtual void set_ElementIDOB_HOT_SNF(TFIBBCDField * ElementIDOB_HOT_SNF)=0;

   __property TFIBBCDField * ElementIDCAT_HOT_SNF = {read = get_ElementIDCAT_HOT_SNF , write = set_ElementIDCAT_HOT_SNF};
   virtual TFIBBCDField * get_ElementIDCAT_HOT_SNF(void)=0;
   virtual void set_ElementIDCAT_HOT_SNF(TFIBBCDField * ElementIDCAT_HOT_SNF)=0;

   __property TFIBBCDField * TableID_HOT_SNF = {read = get_TableID_HOT_SNF , write = set_TableID_HOT_SNF};
   virtual TFIBBCDField * get_TableID_HOT_SNF(void)=0;
   virtual void set_TableID_HOT_SNF(TFIBBCDField * TableID_HOT_SNF)=0;

   __property TFIBBCDField * TableIDOB_HOT_SNF = {read = get_TableIDOB_HOT_SNF , write = set_TableIDOB_HOT_SNF};
   virtual TFIBBCDField * get_TableIDOB_HOT_SNF(void)=0;
   virtual void set_TableIDOB_HOT_SNF(TFIBBCDField * TableIDOB_HOT_SNF)=0;

   __property TFIBBCDField * TableIDCAT_HOT_SNF = {read = get_TableIDCAT_HOT_SNF , write = set_TableIDCAT_HOT_SNF};
   virtual TFIBBCDField * get_TableIDCAT_HOT_SNF(void)=0;
   virtual void set_TableIDCAT_HOT_SNF(TFIBBCDField * TableIDCAT_HOT_SNF)=0;

   __property TFIBWideStringField * ElementNAME_HOT_SNF = {read = get_ElementNAME_HOT_SNF , write = set_ElementNAME_HOT_SNF};
   virtual TFIBWideStringField * get_ElementNAME_HOT_SNF(void)=0;
   virtual void set_ElementNAME_HOT_SNF(TFIBWideStringField * ElementNAME_HOT_SNF)=0;

   __property TFIBWideStringField * ElementNAME_HOT_SOBJECT = {read = get_ElementNAME_HOT_SOBJECT , write = set_ElementNAME_HOT_SOBJECT};
   virtual TFIBWideStringField * get_ElementNAME_HOT_SOBJECT(void)=0;
   virtual void set_ElementNAME_HOT_SOBJECT(TFIBWideStringField * ElementNAME_HOT_SOBJECT)=0;

   __property TFIBWideStringField * ElementNAME_HOT_SCATNOM = {read = get_ElementNAME_HOT_SCATNOM , write = set_ElementNAME_HOT_SCATNOM};
   virtual TFIBWideStringField * get_ElementNAME_HOT_SCATNOM(void)=0;
   virtual void set_ElementNAME_HOT_SCATNOM(TFIBWideStringField * ElementNAME_HOT_SCATNOM)=0;

   __property TFIBWideStringField * TableNAME_HOT_SNF = {read = get_TableNAME_HOT_SNF , write = set_TableNAME_HOT_SNF};
   virtual TFIBWideStringField * get_TableNAME_HOT_SNF(void)=0;
   virtual void set_TableNAME_HOT_SNF(TFIBWideStringField * TableNAME_HOT_SNF)=0;

   __property TFIBWideStringField * TableNAME_HOT_SOBJECT = {read = get_TableNAME_HOT_SOBJECT , write = set_TableNAME_HOT_SOBJECT};
   virtual TFIBWideStringField * get_TableNAME_HOT_SOBJECT(void)=0;
   virtual void set_TableNAME_HOT_SOBJECT(TFIBWideStringField * TableNAME_HOT_SOBJECT)=0;

   __property TFIBWideStringField * TableNAME_HOT_SCATNOM = {read = get_TableNAME_HOT_SCATNOM , write = set_TableNAME_HOT_SCATNOM};
   virtual TFIBWideStringField * get_TableNAME_HOT_SCATNOM(void)=0;
   virtual void set_TableNAME_HOT_SCATNOM(TFIBWideStringField * TableNAME_HOT_SCATNOM)=0;

   virtual void OpenTable(void)=0;
   virtual void UpdateTable(void)=0;
   virtual int OpenElement(__int64 Id)=0;
   virtual bool NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void CloseElement(void)=0;
   virtual bool DeleteElement(__int64 Id)=0;
   virtual int GetIndexElementaPoID(__int64 id)=0;
};
#define IID_IHOT_DMSprNF __uuidof(IHOT_DMSprNF)
#endif
