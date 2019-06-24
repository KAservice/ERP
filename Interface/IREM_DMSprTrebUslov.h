#ifndef UIREM_DMSprTrebUslovH
#define UIREM_DMSprTrebUslovH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMSprTrebUslov)) IREM_DMSprTrebUslov : public IMainInterface
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

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBLargeIntField * TableID_REM_STREBUSLOV = {read = get_TableID_REM_STREBUSLOV , write = set_TableID_REM_STREBUSLOV};
   virtual TFIBLargeIntField * get_TableID_REM_STREBUSLOV(void)=0;
   virtual void set_TableID_REM_STREBUSLOV(TFIBLargeIntField * TableID_REM_STREBUSLOV)=0;

   __property TFIBWideStringField * TableGID_REM_STREBUSLOV = {read = get_TableGID_REM_STREBUSLOV , write = set_TableGID_REM_STREBUSLOV};
   virtual TFIBWideStringField * get_TableGID_REM_STREBUSLOV(void)=0;
   virtual void set_TableGID_REM_STREBUSLOV(TFIBWideStringField * TableGID_REM_STREBUSLOV)=0;

   __property TFIBLargeIntField * TableIDBASE_REM_STREBUSLOV = {read = get_TableIDBASE_REM_STREBUSLOV , write = set_TableIDBASE_REM_STREBUSLOV};
   virtual TFIBLargeIntField * get_TableIDBASE_REM_STREBUSLOV(void)=0;
   virtual void set_TableIDBASE_REM_STREBUSLOV(TFIBLargeIntField * TableIDBASE_REM_STREBUSLOV)=0;

   __property TFIBLargeIntField * TableIDDMN_REM_STREBUSLOV = {read = get_TableIDDMN_REM_STREBUSLOV , write = set_TableIDDMN_REM_STREBUSLOV};
   virtual TFIBLargeIntField * get_TableIDDMN_REM_STREBUSLOV(void)=0;
   virtual void set_TableIDDMN_REM_STREBUSLOV(TFIBLargeIntField * TableIDDMN_REM_STREBUSLOV)=0;

   __property TFIBLargeIntField * TableIDTYPUSLA_REM_STREBUSLOV = {read = get_TableIDTYPUSLA_REM_STREBUSLOV , write = set_TableIDTYPUSLA_REM_STREBUSLOV};
   virtual TFIBLargeIntField * get_TableIDTYPUSLA_REM_STREBUSLOV(void)=0;
   virtual void set_TableIDTYPUSLA_REM_STREBUSLOV(TFIBLargeIntField * TableIDTYPUSLA_REM_STREBUSLOV)=0;

   __property TFIBWideStringField * TableNAME_REM_STREBUSLOV = {read = get_TableNAME_REM_STREBUSLOV , write = set_TableNAME_REM_STREBUSLOV};
   virtual TFIBWideStringField * get_TableNAME_REM_STREBUSLOV(void)=0;
   virtual void set_TableNAME_REM_STREBUSLOV(TFIBWideStringField * TableNAME_REM_STREBUSLOV)=0;

   __property TFIBWideStringField * TableNAME_REM_STYPUSLOV = {read = get_TableNAME_REM_STYPUSLOV , write = set_TableNAME_REM_STYPUSLOV};
   virtual TFIBWideStringField * get_TableNAME_REM_STYPUSLOV(void)=0;
   virtual void set_TableNAME_REM_STYPUSLOV(TFIBWideStringField * TableNAME_REM_STYPUSLOV)=0;

   __property TFIBLargeIntField * ElementID_REM_STREBUSLOV = {read = get_ElementID_REM_STREBUSLOV , write = set_ElementID_REM_STREBUSLOV};
   virtual TFIBLargeIntField * get_ElementID_REM_STREBUSLOV(void)=0;
   virtual void set_ElementID_REM_STREBUSLOV(TFIBLargeIntField * ElementID_REM_STREBUSLOV)=0;

   __property TFIBWideStringField * ElementGID_REM_STREBUSLOV = {read = get_ElementGID_REM_STREBUSLOV , write = set_ElementGID_REM_STREBUSLOV};
   virtual TFIBWideStringField * get_ElementGID_REM_STREBUSLOV(void)=0;
   virtual void set_ElementGID_REM_STREBUSLOV(TFIBWideStringField * ElementGID_REM_STREBUSLOV)=0;

   __property TFIBLargeIntField * ElementIDBASE_REM_STREBUSLOV = {read = get_ElementIDBASE_REM_STREBUSLOV , write = set_ElementIDBASE_REM_STREBUSLOV};
   virtual TFIBLargeIntField * get_ElementIDBASE_REM_STREBUSLOV(void)=0;
   virtual void set_ElementIDBASE_REM_STREBUSLOV(TFIBLargeIntField * ElementIDBASE_REM_STREBUSLOV)=0;

   __property TFIBLargeIntField * ElementIDDMN_REM_STREBUSLOV = {read = get_ElementIDDMN_REM_STREBUSLOV , write = set_ElementIDDMN_REM_STREBUSLOV};
   virtual TFIBLargeIntField * get_ElementIDDMN_REM_STREBUSLOV(void)=0;
   virtual void set_ElementIDDMN_REM_STREBUSLOV(TFIBLargeIntField * ElementIDDMN_REM_STREBUSLOV)=0;

   __property TFIBLargeIntField * ElementIDTYPUSLA_REM_STREBUSLOV = {read = get_ElementIDTYPUSLA_REM_STREBUSLOV , write = set_ElementIDTYPUSLA_REM_STREBUSLOV};
   virtual TFIBLargeIntField * get_ElementIDTYPUSLA_REM_STREBUSLOV(void)=0;
   virtual void set_ElementIDTYPUSLA_REM_STREBUSLOV(TFIBLargeIntField * ElementIDTYPUSLA_REM_STREBUSLOV)=0;

   __property TFIBWideStringField * ElementNAME_REM_STREBUSLOV = {read = get_ElementNAME_REM_STREBUSLOV , write = set_ElementNAME_REM_STREBUSLOV};
   virtual TFIBWideStringField * get_ElementNAME_REM_STREBUSLOV(void)=0;
   virtual void set_ElementNAME_REM_STREBUSLOV(TFIBWideStringField * ElementNAME_REM_STREBUSLOV)=0;

   __property TFIBWideStringField * ElementNAME_REM_STYPUSLOV = {read = get_ElementNAME_REM_STYPUSLOV , write = set_ElementNAME_REM_STYPUSLOV};
   virtual TFIBWideStringField * get_ElementNAME_REM_STYPUSLOV(void)=0;
   virtual void set_ElementNAME_REM_STYPUSLOV(TFIBWideStringField * ElementNAME_REM_STYPUSLOV)=0;

   virtual void OpenTable(__int64 id_defect_model_neispr)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual bool NewElement(__int64 id_defect_model_neispr)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
};
#define IID_IREM_DMSprTrebUslov __uuidof(IREM_DMSprTrebUslov)
#endif
