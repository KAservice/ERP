#ifndef UIDMSprOborudH
#define UIDMSprOborudH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprOborud)) IDMSprOborud : public IMainInterface
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

   __property TFIBSmallIntField * TableON_START_SOBORUD = {read = get_TableON_START_SOBORUD , write = set_TableON_START_SOBORUD};
   virtual TFIBSmallIntField * get_TableON_START_SOBORUD(void)=0;
   virtual void set_TableON_START_SOBORUD(TFIBSmallIntField * TableON_START_SOBORUD)=0;

   __property TFIBSmallIntField * ElementON_START_SOBORUD = {read = get_ElementON_START_SOBORUD , write = set_ElementON_START_SOBORUD};
   virtual TFIBSmallIntField * get_ElementON_START_SOBORUD(void)=0;
   virtual void set_ElementON_START_SOBORUD(TFIBSmallIntField * ElementON_START_SOBORUD)=0;

   __property TFIBWideStringField * TableNAME_OBORUD = {read = get_TableNAME_OBORUD , write = set_TableNAME_OBORUD};
   virtual TFIBWideStringField * get_TableNAME_OBORUD(void)=0;
   virtual void set_TableNAME_OBORUD(TFIBWideStringField * TableNAME_OBORUD)=0;

   __property TFIBWideStringField * TableCOMPNAME_OBORUD = {read = get_TableCOMPNAME_OBORUD , write = set_TableCOMPNAME_OBORUD};
   virtual TFIBWideStringField * get_TableCOMPNAME_OBORUD(void)=0;
   virtual void set_TableCOMPNAME_OBORUD(TFIBWideStringField * TableCOMPNAME_OBORUD)=0;

   __property TFIBWideStringField * TableCOMNAME_OBORUD = {read = get_TableCOMNAME_OBORUD , write = set_TableCOMNAME_OBORUD};
   virtual TFIBWideStringField * get_TableCOMNAME_OBORUD(void)=0;
   virtual void set_TableCOMNAME_OBORUD(TFIBWideStringField * TableCOMNAME_OBORUD)=0;

   __property TFIBWideStringField * TableBAUDRATE_OBORUD = {read = get_TableBAUDRATE_OBORUD , write = set_TableBAUDRATE_OBORUD};
   virtual TFIBWideStringField * get_TableBAUDRATE_OBORUD(void)=0;
   virtual void set_TableBAUDRATE_OBORUD(TFIBWideStringField * TableBAUDRATE_OBORUD)=0;

   __property TFIBWideStringField * TableMODEL_OBORUD = {read = get_TableMODEL_OBORUD , write = set_TableMODEL_OBORUD};
   virtual TFIBWideStringField * get_TableMODEL_OBORUD(void)=0;
   virtual void set_TableMODEL_OBORUD(TFIBWideStringField * TableMODEL_OBORUD)=0;

   __property TFIBWideStringField * TableGID_SOBORUD = {read = get_TableGID_SOBORUD , write = set_TableGID_SOBORUD};
   virtual TFIBWideStringField * get_TableGID_SOBORUD(void)=0;
   virtual void set_TableGID_SOBORUD(TFIBWideStringField * TableGID_SOBORUD)=0;

   __property TFIBWideStringField * TableSTRPAR_SOBORUD = {read = get_TableSTRPAR_SOBORUD , write = set_TableSTRPAR_SOBORUD};
   virtual TFIBWideStringField * get_TableSTRPAR_SOBORUD(void)=0;
   virtual void set_TableSTRPAR_SOBORUD(TFIBWideStringField * TableSTRPAR_SOBORUD)=0;

   __property TFIBWideStringField * TableMODUL_SOBORUD = {read = get_TableMODUL_SOBORUD , write = set_TableMODUL_SOBORUD};
   virtual TFIBWideStringField * get_TableMODUL_SOBORUD(void)=0;
   virtual void set_TableMODUL_SOBORUD(TFIBWideStringField * TableMODUL_SOBORUD)=0;

   __property TFIBWideStringField * ElementNAME_OBORUD = {read = get_ElementNAME_OBORUD , write = set_ElementNAME_OBORUD};
   virtual TFIBWideStringField * get_ElementNAME_OBORUD(void)=0;
   virtual void set_ElementNAME_OBORUD(TFIBWideStringField * ElementNAME_OBORUD)=0;

   __property TFIBWideStringField * ElementCOMPNAME_OBORUD = {read = get_ElementCOMPNAME_OBORUD , write = set_ElementCOMPNAME_OBORUD};
   virtual TFIBWideStringField * get_ElementCOMPNAME_OBORUD(void)=0;
   virtual void set_ElementCOMPNAME_OBORUD(TFIBWideStringField * ElementCOMPNAME_OBORUD)=0;

   __property TFIBWideStringField * ElementCOMNAME_OBORUD = {read = get_ElementCOMNAME_OBORUD , write = set_ElementCOMNAME_OBORUD};
   virtual TFIBWideStringField * get_ElementCOMNAME_OBORUD(void)=0;
   virtual void set_ElementCOMNAME_OBORUD(TFIBWideStringField * ElementCOMNAME_OBORUD)=0;

   __property TFIBWideStringField * ElementTYPE_OBORUD = {read = get_ElementTYPE_OBORUD , write = set_ElementTYPE_OBORUD};
   virtual TFIBWideStringField * get_ElementTYPE_OBORUD(void)=0;
   virtual void set_ElementTYPE_OBORUD(TFIBWideStringField * ElementTYPE_OBORUD)=0;

   __property TFIBWideStringField * ElementMODEL_OBORUD = {read = get_ElementMODEL_OBORUD , write = set_ElementMODEL_OBORUD};
   virtual TFIBWideStringField * get_ElementMODEL_OBORUD(void)=0;
   virtual void set_ElementMODEL_OBORUD(TFIBWideStringField * ElementMODEL_OBORUD)=0;

   __property TFIBWideStringField * ElementGID_SOBORUD = {read = get_ElementGID_SOBORUD , write = set_ElementGID_SOBORUD};
   virtual TFIBWideStringField * get_ElementGID_SOBORUD(void)=0;
   virtual void set_ElementGID_SOBORUD(TFIBWideStringField * ElementGID_SOBORUD)=0;

   __property TFIBWideStringField * ElementSTRPAR_SOBORUD = {read = get_ElementSTRPAR_SOBORUD , write = set_ElementSTRPAR_SOBORUD};
   virtual TFIBWideStringField * get_ElementSTRPAR_SOBORUD(void)=0;
   virtual void set_ElementSTRPAR_SOBORUD(TFIBWideStringField * ElementSTRPAR_SOBORUD)=0;

   __property TFIBWideStringField * ElementMODUL_SOBORUD = {read = get_ElementMODUL_SOBORUD , write = set_ElementMODUL_SOBORUD};
   virtual TFIBWideStringField * get_ElementMODUL_SOBORUD(void)=0;
   virtual void set_ElementMODUL_SOBORUD(TFIBWideStringField * ElementMODUL_SOBORUD)=0;

   __property TFIBWideStringField * TableTYPE_OBORUD = {read = get_TableTYPE_OBORUD , write = set_TableTYPE_OBORUD};
   virtual TFIBWideStringField * get_TableTYPE_OBORUD(void)=0;
   virtual void set_TableTYPE_OBORUD(TFIBWideStringField * TableTYPE_OBORUD)=0;

   __property TFIBWideStringField * ElementBAUDRATE_OBORUD = {read = get_ElementBAUDRATE_OBORUD , write = set_ElementBAUDRATE_OBORUD};
   virtual TFIBWideStringField * get_ElementBAUDRATE_OBORUD(void)=0;
   virtual void set_ElementBAUDRATE_OBORUD(TFIBWideStringField * ElementBAUDRATE_OBORUD)=0;

   __property TFIBLargeIntField * TableID_OBORUD = {read = get_TableID_OBORUD , write = set_TableID_OBORUD};
   virtual TFIBLargeIntField * get_TableID_OBORUD(void)=0;
   virtual void set_TableID_OBORUD(TFIBLargeIntField * TableID_OBORUD)=0;

   __property TFIBLargeIntField * TableIDARM_SOBORUD = {read = get_TableIDARM_SOBORUD , write = set_TableIDARM_SOBORUD};
   virtual TFIBLargeIntField * get_TableIDARM_SOBORUD(void)=0;
   virtual void set_TableIDARM_SOBORUD(TFIBLargeIntField * TableIDARM_SOBORUD)=0;

   __property TFIBLargeIntField * TableIDBASE_SOBORUD = {read = get_TableIDBASE_SOBORUD , write = set_TableIDBASE_SOBORUD};
   virtual TFIBLargeIntField * get_TableIDBASE_SOBORUD(void)=0;
   virtual void set_TableIDBASE_SOBORUD(TFIBLargeIntField * TableIDBASE_SOBORUD)=0;

   __property TFIBLargeIntField * ElementID_OBORUD = {read = get_ElementID_OBORUD , write = set_ElementID_OBORUD};
   virtual TFIBLargeIntField * get_ElementID_OBORUD(void)=0;
   virtual void set_ElementID_OBORUD(TFIBLargeIntField * ElementID_OBORUD)=0;

   __property TFIBLargeIntField * ElementIDARM_SOBORUD = {read = get_ElementIDARM_SOBORUD , write = set_ElementIDARM_SOBORUD};
   virtual TFIBLargeIntField * get_ElementIDARM_SOBORUD(void)=0;
   virtual void set_ElementIDARM_SOBORUD(TFIBLargeIntField * ElementIDARM_SOBORUD)=0;

   __property TFIBLargeIntField * ElementIDBASE_SOBORUD = {read = get_ElementIDBASE_SOBORUD , write = set_ElementIDBASE_SOBORUD};
   virtual TFIBLargeIntField * get_ElementIDBASE_SOBORUD(void)=0;
   virtual void set_ElementIDBASE_SOBORUD(TFIBLargeIntField * ElementIDBASE_SOBORUD)=0;

	  __property TFIBWideStringField * TablePROGID_SOBORUD = {read = get_TablePROGID_SOBORUD , write = set_TablePROGID_SOBORUD};
   virtual TFIBWideStringField * get_TablePROGID_SOBORUD(void)=0;
   virtual void set_TablePROGID_SOBORUD(TFIBWideStringField * TablePROGID_SOBORUD)=0;

	  __property TFIBWideStringField * ElementPROGID_SOBORUD = {read = get_ElementPROGID_SOBORUD , write = set_ElementPROGID_SOBORUD};
   virtual TFIBWideStringField * get_ElementPROGID_SOBORUD(void)=0;
   virtual void set_ElementPROGID_SOBORUD(TFIBWideStringField * ElementPROGID_SOBORUD)=0;

   __property __int64 IdKKM = {read = get_IdKKM , write = set_IdKKM};
   virtual __int64 get_IdKKM(void)=0;
   virtual void set_IdKKM(__int64 IdKKM)=0;


   virtual void OpenTable(__int64 id_kkm)=0;
   virtual void OpenTablePoTypeOborud(__int64 id_kkm, UnicodeString type_oborud)=0;
   virtual int OpenElement(__int64 Id)=0;
   virtual void NewElement(__int64 id_kkm)=0;
   virtual bool SaveElement(void)=0;
   virtual void DeleteElement(__int64 Id)=0;
   virtual UnicodeString GetParameter(UnicodeString parameter)=0;
   virtual UnicodeString GetParameterPoTable(UnicodeString parameter)=0;
};
#define IID_IDMSprOborud __uuidof(IDMSprOborud)
#endif
