#ifndef UIDMSprImportEdH
#define UIDMSprImportEdH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{0DE8AD0F-6B88-485C-9E4E-B29EDAE9B6C7}")) IDMSprImportEd : public IMainInterface
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

   __property TFIBBCDField * TableID_SIMPORTED = {read = get_TableID_SIMPORTED , write = set_TableID_SIMPORTED};
   virtual TFIBBCDField * get_TableID_SIMPORTED(void)=0;
   virtual void set_TableID_SIMPORTED(TFIBBCDField * TableID_SIMPORTED)=0;

   __property TFIBBCDField * TableIDBASE_SIMPORTED = {read = get_TableIDBASE_SIMPORTED , write = set_TableIDBASE_SIMPORTED};
   virtual TFIBBCDField * get_TableIDBASE_SIMPORTED(void)=0;
   virtual void set_TableIDBASE_SIMPORTED(TFIBBCDField * TableIDBASE_SIMPORTED)=0;

   __property TFIBBCDField * TableIDNOM_SIMPORTED = {read = get_TableIDNOM_SIMPORTED , write = set_TableIDNOM_SIMPORTED};
   virtual TFIBBCDField * get_TableIDNOM_SIMPORTED(void)=0;
   virtual void set_TableIDNOM_SIMPORTED(TFIBBCDField * TableIDNOM_SIMPORTED)=0;

   __property TFIBBCDField * TableIDKLIENT_SIMPORTED = {read = get_TableIDKLIENT_SIMPORTED , write = set_TableIDKLIENT_SIMPORTED};
   virtual TFIBBCDField * get_TableIDKLIENT_SIMPORTED(void)=0;
   virtual void set_TableIDKLIENT_SIMPORTED(TFIBBCDField * TableIDKLIENT_SIMPORTED)=0;

   __property TFIBBCDField * TableIDED_SIMPORTED = {read = get_TableIDED_SIMPORTED , write = set_TableIDED_SIMPORTED};
   virtual TFIBBCDField * get_TableIDED_SIMPORTED(void)=0;
   virtual void set_TableIDED_SIMPORTED(TFIBBCDField * TableIDED_SIMPORTED)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBBCDField * ElementID_SIMPORTED = {read = get_ElementID_SIMPORTED , write = set_ElementID_SIMPORTED};
   virtual TFIBBCDField * get_ElementID_SIMPORTED(void)=0;
   virtual void set_ElementID_SIMPORTED(TFIBBCDField * ElementID_SIMPORTED)=0;

   __property TFIBBCDField * ElementIDBASE_SIMPORTED = {read = get_ElementIDBASE_SIMPORTED , write = set_ElementIDBASE_SIMPORTED};
   virtual TFIBBCDField * get_ElementIDBASE_SIMPORTED(void)=0;
   virtual void set_ElementIDBASE_SIMPORTED(TFIBBCDField * ElementIDBASE_SIMPORTED)=0;

   __property TFIBBCDField * ElementIDNOM_SIMPORTED = {read = get_ElementIDNOM_SIMPORTED , write = set_ElementIDNOM_SIMPORTED};
   virtual TFIBBCDField * get_ElementIDNOM_SIMPORTED(void)=0;
   virtual void set_ElementIDNOM_SIMPORTED(TFIBBCDField * ElementIDNOM_SIMPORTED)=0;

   __property TFIBBCDField * ElementIDKLIENT_SIMPORTED = {read = get_ElementIDKLIENT_SIMPORTED , write = set_ElementIDKLIENT_SIMPORTED};
   virtual TFIBBCDField * get_ElementIDKLIENT_SIMPORTED(void)=0;
   virtual void set_ElementIDKLIENT_SIMPORTED(TFIBBCDField * ElementIDKLIENT_SIMPORTED)=0;

   __property TFIBBCDField * ElementIDED_SIMPORTED = {read = get_ElementIDED_SIMPORTED , write = set_ElementIDED_SIMPORTED};
   virtual TFIBBCDField * get_ElementIDED_SIMPORTED(void)=0;
   virtual void set_ElementIDED_SIMPORTED(TFIBBCDField * ElementIDED_SIMPORTED)=0;

   __property TFIBWideStringField * TableBARCODE_SIMPORTED = {read = get_TableBARCODE_SIMPORTED , write = set_TableBARCODE_SIMPORTED};
   virtual TFIBWideStringField * get_TableBARCODE_SIMPORTED(void)=0;
   virtual void set_TableBARCODE_SIMPORTED(TFIBWideStringField * TableBARCODE_SIMPORTED)=0;

   __property TFIBWideStringField * TableCODE_SIMPORTED = {read = get_TableCODE_SIMPORTED , write = set_TableCODE_SIMPORTED};
   virtual TFIBWideStringField * get_TableCODE_SIMPORTED(void)=0;
   virtual void set_TableCODE_SIMPORTED(TFIBWideStringField * TableCODE_SIMPORTED)=0;

   __property TFIBWideStringField * TableNAME_SIMPORTED = {read = get_TableNAME_SIMPORTED , write = set_TableNAME_SIMPORTED};
   virtual TFIBWideStringField * get_TableNAME_SIMPORTED(void)=0;
   virtual void set_TableNAME_SIMPORTED(TFIBWideStringField * TableNAME_SIMPORTED)=0;

   __property TFIBWideStringField * ElementBARCODE_SIMPORTED = {read = get_ElementBARCODE_SIMPORTED , write = set_ElementBARCODE_SIMPORTED};
   virtual TFIBWideStringField * get_ElementBARCODE_SIMPORTED(void)=0;
   virtual void set_ElementBARCODE_SIMPORTED(TFIBWideStringField * ElementBARCODE_SIMPORTED)=0;

   __property TFIBWideStringField * ElementCODE_SIMPORTED = {read = get_ElementCODE_SIMPORTED , write = set_ElementCODE_SIMPORTED};
   virtual TFIBWideStringField * get_ElementCODE_SIMPORTED(void)=0;
   virtual void set_ElementCODE_SIMPORTED(TFIBWideStringField * ElementCODE_SIMPORTED)=0;

   __property TFIBWideStringField * ElementNAME_SIMPORTED = {read = get_ElementNAME_SIMPORTED , write = set_ElementNAME_SIMPORTED};
   virtual TFIBWideStringField * get_ElementNAME_SIMPORTED(void)=0;
   virtual void set_ElementNAME_SIMPORTED(TFIBWideStringField * ElementNAME_SIMPORTED)=0;

   __property TFIBWideStringField * ElementNAMEKLIENT = {read = get_ElementNAMEKLIENT , write = set_ElementNAMEKLIENT};
   virtual TFIBWideStringField * get_ElementNAMEKLIENT(void)=0;
   virtual void set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT)=0;

   virtual void OpenTable(__int64 id_ed)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual bool NewElement(__int64 id_nom,__int64 id_ed)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 dd)=0;
};
#define IID_IDMSprImportEd __uuidof(IDMSprImportEd)
#endif
