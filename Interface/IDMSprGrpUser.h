#ifndef UIDMSprGrpUserH
#define UIDMSprGrpUserH
#include "IMainInterface.h"
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{14E6230E-C841-4529-9251-7B35EA0B39DB}")) IDMSprGrpUser : public IMainInterface
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

   __property TFIBIntegerField * TableINTERF_SGRPUSER = {read = get_TableINTERF_SGRPUSER , write = set_TableINTERF_SGRPUSER};
   virtual TFIBIntegerField * get_TableINTERF_SGRPUSER(void)=0;
   virtual void set_TableINTERF_SGRPUSER(TFIBIntegerField * TableINTERF_SGRPUSER)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBBCDField * TableID_SGRPUSER = {read = get_TableID_SGRPUSER , write = set_TableID_SGRPUSER};
   virtual TFIBBCDField * get_TableID_SGRPUSER(void)=0;
   virtual void set_TableID_SGRPUSER(TFIBBCDField * TableID_SGRPUSER)=0;

   __property TFIBBCDField * TableIDGRP_SGRPUSER = {read = get_TableIDGRP_SGRPUSER , write = set_TableIDGRP_SGRPUSER};
   virtual TFIBBCDField * get_TableIDGRP_SGRPUSER(void)=0;
   virtual void set_TableIDGRP_SGRPUSER(TFIBBCDField * TableIDGRP_SGRPUSER)=0;

   __property TFIBBCDField * ElementID_SGRPUSER = {read = get_ElementID_SGRPUSER , write = set_ElementID_SGRPUSER};
   virtual TFIBBCDField * get_ElementID_SGRPUSER(void)=0;
   virtual void set_ElementID_SGRPUSER(TFIBBCDField * ElementID_SGRPUSER)=0;

   __property TFIBBCDField * ElementIDGRP_SGRPUSER = {read = get_ElementIDGRP_SGRPUSER , write = set_ElementIDGRP_SGRPUSER};
   virtual TFIBBCDField * get_ElementIDGRP_SGRPUSER(void)=0;
   virtual void set_ElementIDGRP_SGRPUSER(TFIBBCDField * ElementIDGRP_SGRPUSER)=0;

   __property TFIBWideStringField * TableGID_SGRPUSER = {read = get_TableGID_SGRPUSER , write = set_TableGID_SGRPUSER};
   virtual TFIBWideStringField * get_TableGID_SGRPUSER(void)=0;
   virtual void set_TableGID_SGRPUSER(TFIBWideStringField * TableGID_SGRPUSER)=0;

   __property TFIBWideStringField * TableNAME_SGRPUSER = {read = get_TableNAME_SGRPUSER , write = set_TableNAME_SGRPUSER};
   virtual TFIBWideStringField * get_TableNAME_SGRPUSER(void)=0;
   virtual void set_TableNAME_SGRPUSER(TFIBWideStringField * TableNAME_SGRPUSER)=0;

   __property TFIBWideStringField * TableROLE_SGRPUSER = {read = get_TableROLE_SGRPUSER , write = set_TableROLE_SGRPUSER};
   virtual TFIBWideStringField * get_TableROLE_SGRPUSER(void)=0;
   virtual void set_TableROLE_SGRPUSER(TFIBWideStringField * TableROLE_SGRPUSER)=0;

   __property TFIBWideStringField * ElementGID_SGRPUSER = {read = get_ElementGID_SGRPUSER , write = set_ElementGID_SGRPUSER};
   virtual TFIBWideStringField * get_ElementGID_SGRPUSER(void)=0;
   virtual void set_ElementGID_SGRPUSER(TFIBWideStringField * ElementGID_SGRPUSER)=0;

   __property TFIBWideStringField * ElementNAME_SGRPUSER = {read = get_ElementNAME_SGRPUSER , write = set_ElementNAME_SGRPUSER};
   virtual TFIBWideStringField * get_ElementNAME_SGRPUSER(void)=0;
   virtual void set_ElementNAME_SGRPUSER(TFIBWideStringField * ElementNAME_SGRPUSER)=0;

   __property TFIBSmallIntField * ElementINTERF_SGRPUSER = {read = get_ElementINTERF_SGRPUSER , write = set_ElementINTERF_SGRPUSER};
   virtual TFIBSmallIntField * get_ElementINTERF_SGRPUSER(void)=0;
   virtual void set_ElementINTERF_SGRPUSER(TFIBSmallIntField * ElementINTERF_SGRPUSER)=0;

   __property TFIBWideStringField * ElementROLE_SGRPUSER = {read = get_ElementROLE_SGRPUSER , write = set_ElementROLE_SGRPUSER};
   virtual TFIBWideStringField * get_ElementROLE_SGRPUSER(void)=0;
   virtual void set_ElementROLE_SGRPUSER(TFIBWideStringField * ElementROLE_SGRPUSER)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual void NewElement(__int64 id_grp)=0;
   virtual bool SaveElement(void)=0;
   virtual void DeleteElement(__int64 id)=0;
   virtual __int64 GetIDElement(String gid)=0;
};
#define IID_IDMSprGrpUser __uuidof(IDMSprGrpUser)
#endif
