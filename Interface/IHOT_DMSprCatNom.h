#ifndef UIHOT_DMSprCatNomH
#define UIHOT_DMSprCatNomH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>
class __declspec(uuid("{774B73A6-4197-470A-8827-D5E0199A33E6}")) IHOT_DMSprCatNom : public IMainInterface
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

   __property TFIBBCDField * ElementID_HOT_SCATNOM = {read = get_ElementID_HOT_SCATNOM , write = set_ElementID_HOT_SCATNOM};
   virtual TFIBBCDField * get_ElementID_HOT_SCATNOM(void)=0;
   virtual void set_ElementID_HOT_SCATNOM(TFIBBCDField * ElementID_HOT_SCATNOM)=0;

   __property TFIBBCDField * TableID_HOT_SCATNOM = {read = get_TableID_HOT_SCATNOM , write = set_TableID_HOT_SCATNOM};
   virtual TFIBBCDField * get_TableID_HOT_SCATNOM(void)=0;
   virtual void set_TableID_HOT_SCATNOM(TFIBBCDField * TableID_HOT_SCATNOM)=0;

   __property TFIBWideStringField * ElementNAME_HOT_SCATNOM = {read = get_ElementNAME_HOT_SCATNOM , write = set_ElementNAME_HOT_SCATNOM};
   virtual TFIBWideStringField * get_ElementNAME_HOT_SCATNOM(void)=0;
   virtual void set_ElementNAME_HOT_SCATNOM(TFIBWideStringField * ElementNAME_HOT_SCATNOM)=0;

   __property TFIBWideStringField * ElementDESCR_HOT_SCATNOM = {read = get_ElementDESCR_HOT_SCATNOM , write = set_ElementDESCR_HOT_SCATNOM};
   virtual TFIBWideStringField * get_ElementDESCR_HOT_SCATNOM(void)=0;
   virtual void set_ElementDESCR_HOT_SCATNOM(TFIBWideStringField * ElementDESCR_HOT_SCATNOM)=0;

   __property TFIBWideStringField * TableNAME_HOT_SCATNOM = {read = get_TableNAME_HOT_SCATNOM , write = set_TableNAME_HOT_SCATNOM};
   virtual TFIBWideStringField * get_TableNAME_HOT_SCATNOM(void)=0;
   virtual void set_TableNAME_HOT_SCATNOM(TFIBWideStringField * TableNAME_HOT_SCATNOM)=0;

   __property TFIBWideStringField * TableDESCR_HOT_SCATNOM = {read = get_TableDESCR_HOT_SCATNOM , write = set_TableDESCR_HOT_SCATNOM};
   virtual TFIBWideStringField * get_TableDESCR_HOT_SCATNOM(void)=0;
   virtual void set_TableDESCR_HOT_SCATNOM(TFIBWideStringField * TableDESCR_HOT_SCATNOM)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 Id)=0;
   virtual bool NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void CloseElement(void)=0;
   virtual bool DeleteElement(__int64 Id)=0;
   virtual __int64 GetIDElement(String gid)=0;
   virtual AnsiString GetGIDElement(__int64 id)=0;
   virtual int GetIndexElementaPoID(__int64 id)=0;
};
#define IID_IHOT_DMSprCatNom __uuidof(IHOT_DMSprCatNom)
#endif
