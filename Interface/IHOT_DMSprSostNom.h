#ifndef UIHOT_DMSprSostNomH
#define UIHOT_DMSprSostNomH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>
class __declspec(uuid("{7CC31D9B-2996-45A9-945C-83734EB15718}")) IHOT_DMSprSostNom : public IMainInterface
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

   __property TFIBSmallIntField * TableFLBRON_HOT_SSOSTNOM = {read = get_TableFLBRON_HOT_SSOSTNOM , write = set_TableFLBRON_HOT_SSOSTNOM};
   virtual TFIBSmallIntField * get_TableFLBRON_HOT_SSOSTNOM(void)=0;
   virtual void set_TableFLBRON_HOT_SSOSTNOM(TFIBSmallIntField * TableFLBRON_HOT_SSOSTNOM)=0;

   __property TFIBSmallIntField * TableFLRASM_HOT_SSOSTNOM = {read = get_TableFLRASM_HOT_SSOSTNOM , write = set_TableFLRASM_HOT_SSOSTNOM};
   virtual TFIBSmallIntField * get_TableFLRASM_HOT_SSOSTNOM(void)=0;
   virtual void set_TableFLRASM_HOT_SSOSTNOM(TFIBSmallIntField * TableFLRASM_HOT_SSOSTNOM)=0;

   __property TFIBSmallIntField * ElementFLBRON_HOT_SSOSTNOM = {read = get_ElementFLBRON_HOT_SSOSTNOM , write = set_ElementFLBRON_HOT_SSOSTNOM};
   virtual TFIBSmallIntField * get_ElementFLBRON_HOT_SSOSTNOM(void)=0;
   virtual void set_ElementFLBRON_HOT_SSOSTNOM(TFIBSmallIntField * ElementFLBRON_HOT_SSOSTNOM)=0;

   __property TFIBSmallIntField * ElementFLRASM_HOT_SSOSTNOM = {read = get_ElementFLRASM_HOT_SSOSTNOM , write = set_ElementFLRASM_HOT_SSOSTNOM};
   virtual TFIBSmallIntField * get_ElementFLRASM_HOT_SSOSTNOM(void)=0;
   virtual void set_ElementFLRASM_HOT_SSOSTNOM(TFIBSmallIntField * ElementFLRASM_HOT_SSOSTNOM)=0;

   __property TFIBBCDField * TableID_HOT_SSOSTNOM = {read = get_TableID_HOT_SSOSTNOM , write = set_TableID_HOT_SSOSTNOM};
   virtual TFIBBCDField * get_TableID_HOT_SSOSTNOM(void)=0;
   virtual void set_TableID_HOT_SSOSTNOM(TFIBBCDField * TableID_HOT_SSOSTNOM)=0;

   __property TFIBBCDField * ElementID_HOT_SSOSTNOM = {read = get_ElementID_HOT_SSOSTNOM , write = set_ElementID_HOT_SSOSTNOM};
   virtual TFIBBCDField * get_ElementID_HOT_SSOSTNOM(void)=0;
   virtual void set_ElementID_HOT_SSOSTNOM(TFIBBCDField * ElementID_HOT_SSOSTNOM)=0;

   __property TFIBIntegerField * ElementCOLOR_HOT_SSOSTNOM = {read = get_ElementCOLOR_HOT_SSOSTNOM , write = set_ElementCOLOR_HOT_SSOSTNOM};
   virtual TFIBIntegerField * get_ElementCOLOR_HOT_SSOSTNOM(void)=0;
   virtual void set_ElementCOLOR_HOT_SSOSTNOM(TFIBIntegerField * ElementCOLOR_HOT_SSOSTNOM)=0;

   __property TFIBWideStringField * TableNAME_HOT_SSOSTNOM = {read = get_TableNAME_HOT_SSOSTNOM , write = set_TableNAME_HOT_SSOSTNOM};
   virtual TFIBWideStringField * get_TableNAME_HOT_SSOSTNOM(void)=0;
   virtual void set_TableNAME_HOT_SSOSTNOM(TFIBWideStringField * TableNAME_HOT_SSOSTNOM)=0;

   __property TFIBWideStringField * ElementNAME_HOT_SSOSTNOM = {read = get_ElementNAME_HOT_SSOSTNOM , write = set_ElementNAME_HOT_SSOSTNOM};
   virtual TFIBWideStringField * get_ElementNAME_HOT_SSOSTNOM(void)=0;
   virtual void set_ElementNAME_HOT_SSOSTNOM(TFIBWideStringField * ElementNAME_HOT_SSOSTNOM)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 Id)=0;
   virtual bool NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void CloseElement(void)=0;
   virtual bool DeleteElement(__int64 Id)=0;
   virtual int GetIndexElementaPoID(__int64 id)=0;
};
#define IID_IHOT_DMSprSostNom __uuidof(IHOT_DMSprSostNom)
#endif
