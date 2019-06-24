#ifndef UIDMViborOborudH
#define UIDMViborOborudH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>

class __declspec(uuid("{31A3AA1E-4CB8-43D8-AEA8-83578C055C6E}")) IDMViborOborud : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TFIBBCDField * TableID_OBORUD = {read = get_TableID_OBORUD , write = set_TableID_OBORUD};
   virtual TFIBBCDField * get_TableID_OBORUD(void)=0;
   virtual void set_TableID_OBORUD(TFIBBCDField * TableID_OBORUD)=0;

   __property TFIBBCDField * TableIDARM_SOBORUD = {read = get_TableIDARM_SOBORUD , write = set_TableIDARM_SOBORUD};
   virtual TFIBBCDField * get_TableIDARM_SOBORUD(void)=0;
   virtual void set_TableIDARM_SOBORUD(TFIBBCDField * TableIDARM_SOBORUD)=0;

   __property TFIBSmallIntField * TableON_START_SOBORUD = {read = get_TableON_START_SOBORUD , write = set_TableON_START_SOBORUD};
   virtual TFIBSmallIntField * get_TableON_START_SOBORUD(void)=0;
   virtual void set_TableON_START_SOBORUD(TFIBSmallIntField * TableON_START_SOBORUD)=0;

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

   __property TFIBWideStringField * TableTYPE_OBORUD = {read = get_TableTYPE_OBORUD , write = set_TableTYPE_OBORUD};
   virtual TFIBWideStringField * get_TableTYPE_OBORUD(void)=0;
   virtual void set_TableTYPE_OBORUD(TFIBWideStringField * TableTYPE_OBORUD)=0;

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

   __property TFIBBCDField * TableIDBASE_SOBORUD = {read = get_TableIDBASE_SOBORUD , write = set_TableIDBASE_SOBORUD};
   virtual TFIBBCDField * get_TableIDBASE_SOBORUD(void)=0;
   virtual void set_TableIDBASE_SOBORUD(TFIBBCDField * TableIDBASE_SOBORUD)=0;

   __property __int64 IdArm = {read = get_IdArm , write = set_IdArm};
   virtual __int64 get_IdArm(void)=0;
   virtual void set_IdArm(__int64 IdArm)=0;

   virtual void OpenTable(__int64 id_arm, AnsiString type_oborud)=0;
};
#define IID_IDMViborOborud __uuidof(IDMViborOborud)
#endif
