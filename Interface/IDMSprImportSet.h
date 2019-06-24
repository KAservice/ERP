#ifndef UIDMSprImportSetH
#define UIDMSprImportSetH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{1A118558-5CF6-4D96-9592-62AE34178350}")) IDMSprImportSet : public IMainInterface
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

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBBCDField * TableID_SIMPORTSET = {read = get_TableID_SIMPORTSET , write = set_TableID_SIMPORTSET};
   virtual TFIBBCDField * get_TableID_SIMPORTSET(void)=0;
   virtual void set_TableID_SIMPORTSET(TFIBBCDField * TableID_SIMPORTSET)=0;

   __property TFIBBCDField * TableIDBASE_SIMPORTSET = {read = get_TableIDBASE_SIMPORTSET , write = set_TableIDBASE_SIMPORTSET};
   virtual TFIBBCDField * get_TableIDBASE_SIMPORTSET(void)=0;
   virtual void set_TableIDBASE_SIMPORTSET(TFIBBCDField * TableIDBASE_SIMPORTSET)=0;

   __property TFIBSmallIntField * TableTYPE_SEARCH_SIMPORTSET = {read = get_TableTYPE_SEARCH_SIMPORTSET , write = set_TableTYPE_SEARCH_SIMPORTSET};
   virtual TFIBSmallIntField * get_TableTYPE_SEARCH_SIMPORTSET(void)=0;
   virtual void set_TableTYPE_SEARCH_SIMPORTSET(TFIBSmallIntField * TableTYPE_SEARCH_SIMPORTSET)=0;

   __property TFIBSmallIntField * TableTYPE_OBR_SIMPORTSET = {read = get_TableTYPE_OBR_SIMPORTSET , write = set_TableTYPE_OBR_SIMPORTSET};
   virtual TFIBSmallIntField * get_TableTYPE_OBR_SIMPORTSET(void)=0;
   virtual void set_TableTYPE_OBR_SIMPORTSET(TFIBSmallIntField * TableTYPE_OBR_SIMPORTSET)=0;

   __property TFIBBCDField * ElementID_SIMPORTSET = {read = get_ElementID_SIMPORTSET , write = set_ElementID_SIMPORTSET};
   virtual TFIBBCDField * get_ElementID_SIMPORTSET(void)=0;
   virtual void set_ElementID_SIMPORTSET(TFIBBCDField * ElementID_SIMPORTSET)=0;

   __property TFIBBCDField * ElementIDBASE_SIMPORTSET = {read = get_ElementIDBASE_SIMPORTSET , write = set_ElementIDBASE_SIMPORTSET};
   virtual TFIBBCDField * get_ElementIDBASE_SIMPORTSET(void)=0;
   virtual void set_ElementIDBASE_SIMPORTSET(TFIBBCDField * ElementIDBASE_SIMPORTSET)=0;

   __property TFIBSmallIntField * ElementTYPE_SEARCH_SIMPORTSET = {read = get_ElementTYPE_SEARCH_SIMPORTSET , write = set_ElementTYPE_SEARCH_SIMPORTSET};
   virtual TFIBSmallIntField * get_ElementTYPE_SEARCH_SIMPORTSET(void)=0;
   virtual void set_ElementTYPE_SEARCH_SIMPORTSET(TFIBSmallIntField * ElementTYPE_SEARCH_SIMPORTSET)=0;

   __property TFIBSmallIntField * ElementTYPE_OBR_SIMPORTSET = {read = get_ElementTYPE_OBR_SIMPORTSET , write = set_ElementTYPE_OBR_SIMPORTSET};
   virtual TFIBSmallIntField * get_ElementTYPE_OBR_SIMPORTSET(void)=0;
   virtual void set_ElementTYPE_OBR_SIMPORTSET(TFIBSmallIntField * ElementTYPE_OBR_SIMPORTSET)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBWideStringField * TableNAME_SIMPORTSET = {read = get_TableNAME_SIMPORTSET , write = set_TableNAME_SIMPORTSET};
   virtual TFIBWideStringField * get_TableNAME_SIMPORTSET(void)=0;
   virtual void set_TableNAME_SIMPORTSET(TFIBWideStringField * TableNAME_SIMPORTSET)=0;

   __property TFIBWideStringField * TableSTRPAR_SIMPORTSET = {read = get_TableSTRPAR_SIMPORTSET , write = set_TableSTRPAR_SIMPORTSET};
   virtual TFIBWideStringField * get_TableSTRPAR_SIMPORTSET(void)=0;
   virtual void set_TableSTRPAR_SIMPORTSET(TFIBWideStringField * TableSTRPAR_SIMPORTSET)=0;

   __property TFIBWideStringField * TableDIR_SIMPORTSET = {read = get_TableDIR_SIMPORTSET , write = set_TableDIR_SIMPORTSET};
   virtual TFIBWideStringField * get_TableDIR_SIMPORTSET(void)=0;
   virtual void set_TableDIR_SIMPORTSET(TFIBWideStringField * TableDIR_SIMPORTSET)=0;

   __property TFIBWideStringField * ElementNAME_SIMPORTSET = {read = get_ElementNAME_SIMPORTSET , write = set_ElementNAME_SIMPORTSET};
   virtual TFIBWideStringField * get_ElementNAME_SIMPORTSET(void)=0;
   virtual void set_ElementNAME_SIMPORTSET(TFIBWideStringField * ElementNAME_SIMPORTSET)=0;

   __property TFIBWideStringField * ElementSTRPAR_SIMPORTSET = {read = get_ElementSTRPAR_SIMPORTSET , write = set_ElementSTRPAR_SIMPORTSET};
   virtual TFIBWideStringField * get_ElementSTRPAR_SIMPORTSET(void)=0;
   virtual void set_ElementSTRPAR_SIMPORTSET(TFIBWideStringField * ElementSTRPAR_SIMPORTSET)=0;

   __property TFIBWideStringField * ElementDIR_SIMPORTSET = {read = get_ElementDIR_SIMPORTSET , write = set_ElementDIR_SIMPORTSET};
   virtual TFIBWideStringField * get_ElementDIR_SIMPORTSET(void)=0;
   virtual void set_ElementDIR_SIMPORTSET(TFIBWideStringField * ElementDIR_SIMPORTSET)=0;

   __property int TypeObr = {read = get_TypeObr , write = set_TypeObr};
   virtual int get_TypeObr(void)=0;
   virtual void set_TypeObr(int TypeObr)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual bool NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void CloseElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual __int64 GetIDElement(String gid)=0;
   virtual AnsiString GetGIDElement(__int64 id)=0;
   virtual int GetIndexElementaPoID(__int64 id)=0;
   virtual AnsiString GetParameter(AnsiString parameter)=0;
};
#define IID_IDMSprImportSet __uuidof(IDMSprImportSet)
#endif
