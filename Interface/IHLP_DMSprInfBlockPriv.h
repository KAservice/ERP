#ifndef UIHLP_DMSprInfBlockPrivH
#define UIHLP_DMSprInfBlockPrivH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IHLP_DMSprInfBlockPriv)) IHLP_DMSprInfBlockPriv : public IMainInterface
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

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TDataSource * DataSourceElement = {read = get_DataSourceElement , write = set_DataSourceElement};
   virtual TDataSource * get_DataSourceElement(void)=0;
   virtual void set_DataSourceElement(TDataSource * DataSourceElement)=0;

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TFIBLargeIntField * TableID_HLP_IB_PRIV = {read = get_TableID_HLP_IB_PRIV , write = set_TableID_HLP_IB_PRIV};
   virtual TFIBLargeIntField * get_TableID_HLP_IB_PRIV(void)=0;
   virtual void set_TableID_HLP_IB_PRIV(TFIBLargeIntField * TableID_HLP_IB_PRIV)=0;

   __property TFIBLargeIntField * TableIDBASE_HLP_IB_PRIV = {read = get_TableIDBASE_HLP_IB_PRIV , write = set_TableIDBASE_HLP_IB_PRIV};
   virtual TFIBLargeIntField * get_TableIDBASE_HLP_IB_PRIV(void)=0;
   virtual void set_TableIDBASE_HLP_IB_PRIV(TFIBLargeIntField * TableIDBASE_HLP_IB_PRIV)=0;

   __property TFIBLargeIntField * TableIDIB_HLP_IB_PRIV = {read = get_TableIDIB_HLP_IB_PRIV , write = set_TableIDIB_HLP_IB_PRIV};
   virtual TFIBLargeIntField * get_TableIDIB_HLP_IB_PRIV(void)=0;
   virtual void set_TableIDIB_HLP_IB_PRIV(TFIBLargeIntField * TableIDIB_HLP_IB_PRIV)=0;

   __property TFIBLargeIntField * TableIDGRPUSER_HLP_IB_PRIV = {read = get_TableIDGRPUSER_HLP_IB_PRIV , write = set_TableIDGRPUSER_HLP_IB_PRIV};
   virtual TFIBLargeIntField * get_TableIDGRPUSER_HLP_IB_PRIV(void)=0;
   virtual void set_TableIDGRPUSER_HLP_IB_PRIV(TFIBLargeIntField * TableIDGRPUSER_HLP_IB_PRIV)=0;

   __property TFIBSmallIntField * TableSEL_HLP_IB_PRIV = {read = get_TableSEL_HLP_IB_PRIV , write = set_TableSEL_HLP_IB_PRIV};
   virtual TFIBSmallIntField * get_TableSEL_HLP_IB_PRIV(void)=0;
   virtual void set_TableSEL_HLP_IB_PRIV(TFIBSmallIntField * TableSEL_HLP_IB_PRIV)=0;

   __property TFIBSmallIntField * TableINS_HLP_IB_PRIV = {read = get_TableINS_HLP_IB_PRIV , write = set_TableINS_HLP_IB_PRIV};
   virtual TFIBSmallIntField * get_TableINS_HLP_IB_PRIV(void)=0;
   virtual void set_TableINS_HLP_IB_PRIV(TFIBSmallIntField * TableINS_HLP_IB_PRIV)=0;

   __property TFIBSmallIntField * TableUPD_HLP_IB_PRIV = {read = get_TableUPD_HLP_IB_PRIV , write = set_TableUPD_HLP_IB_PRIV};
   virtual TFIBSmallIntField * get_TableUPD_HLP_IB_PRIV(void)=0;
   virtual void set_TableUPD_HLP_IB_PRIV(TFIBSmallIntField * TableUPD_HLP_IB_PRIV)=0;

   __property TFIBSmallIntField * TableDEL_HLP_IB_PRIV = {read = get_TableDEL_HLP_IB_PRIV , write = set_TableDEL_HLP_IB_PRIV};
   virtual TFIBSmallIntField * get_TableDEL_HLP_IB_PRIV(void)=0;
   virtual void set_TableDEL_HLP_IB_PRIV(TFIBSmallIntField * TableDEL_HLP_IB_PRIV)=0;

   __property TFIBWideStringField * TableNAME_SGRPUSER = {read = get_TableNAME_SGRPUSER , write = set_TableNAME_SGRPUSER};
   virtual TFIBWideStringField * get_TableNAME_SGRPUSER(void)=0;
   virtual void set_TableNAME_SGRPUSER(TFIBWideStringField * TableNAME_SGRPUSER)=0;

   __property TpFIBDataSet * GrpUser = {read = get_GrpUser , write = set_GrpUser};
   virtual TpFIBDataSet * get_GrpUser(void)=0;
   virtual void set_GrpUser(TpFIBDataSet * GrpUser)=0;

   __property TFIBLargeIntField * GrpUserID_SGRPUSER = {read = get_GrpUserID_SGRPUSER , write = set_GrpUserID_SGRPUSER};
   virtual TFIBLargeIntField * get_GrpUserID_SGRPUSER(void)=0;
   virtual void set_GrpUserID_SGRPUSER(TFIBLargeIntField * GrpUserID_SGRPUSER)=0;

   __property TFIBWideStringField * GrpUserNAME_SGRPUSER = {read = get_GrpUserNAME_SGRPUSER , write = set_GrpUserNAME_SGRPUSER};
   virtual TFIBWideStringField * get_GrpUserNAME_SGRPUSER(void)=0;
   virtual void set_GrpUserNAME_SGRPUSER(TFIBWideStringField * GrpUserNAME_SGRPUSER)=0;

   __property TStringField * TableNAME_GRP_USER_LOOKUP = {read = get_TableNAME_GRP_USER_LOOKUP , write = set_TableNAME_GRP_USER_LOOKUP};
   virtual TStringField * get_TableNAME_GRP_USER_LOOKUP(void)=0;
   virtual void set_TableNAME_GRP_USER_LOOKUP(TStringField * TableNAME_GRP_USER_LOOKUP)=0;

   __property TFIBLargeIntField * ElementID_HLP_IB_PRIV = {read = get_ElementID_HLP_IB_PRIV , write = set_ElementID_HLP_IB_PRIV};
   virtual TFIBLargeIntField * get_ElementID_HLP_IB_PRIV(void)=0;
   virtual void set_ElementID_HLP_IB_PRIV(TFIBLargeIntField * ElementID_HLP_IB_PRIV)=0;

   __property TFIBLargeIntField * ElementIDBASE_HLP_IB_PRIV = {read = get_ElementIDBASE_HLP_IB_PRIV , write = set_ElementIDBASE_HLP_IB_PRIV};
   virtual TFIBLargeIntField * get_ElementIDBASE_HLP_IB_PRIV(void)=0;
   virtual void set_ElementIDBASE_HLP_IB_PRIV(TFIBLargeIntField * ElementIDBASE_HLP_IB_PRIV)=0;

   __property TFIBLargeIntField * ElementIDIB_HLP_IB_PRIV = {read = get_ElementIDIB_HLP_IB_PRIV , write = set_ElementIDIB_HLP_IB_PRIV};
   virtual TFIBLargeIntField * get_ElementIDIB_HLP_IB_PRIV(void)=0;
   virtual void set_ElementIDIB_HLP_IB_PRIV(TFIBLargeIntField * ElementIDIB_HLP_IB_PRIV)=0;

   __property TFIBLargeIntField * ElementIDGRPUSER_HLP_IB_PRIV = {read = get_ElementIDGRPUSER_HLP_IB_PRIV , write = set_ElementIDGRPUSER_HLP_IB_PRIV};
   virtual TFIBLargeIntField * get_ElementIDGRPUSER_HLP_IB_PRIV(void)=0;
   virtual void set_ElementIDGRPUSER_HLP_IB_PRIV(TFIBLargeIntField * ElementIDGRPUSER_HLP_IB_PRIV)=0;

   __property TFIBSmallIntField * ElementSEL_HLP_IB_PRIV = {read = get_ElementSEL_HLP_IB_PRIV , write = set_ElementSEL_HLP_IB_PRIV};
   virtual TFIBSmallIntField * get_ElementSEL_HLP_IB_PRIV(void)=0;
   virtual void set_ElementSEL_HLP_IB_PRIV(TFIBSmallIntField * ElementSEL_HLP_IB_PRIV)=0;

   __property TFIBSmallIntField * ElementINS_HLP_IB_PRIV = {read = get_ElementINS_HLP_IB_PRIV , write = set_ElementINS_HLP_IB_PRIV};
   virtual TFIBSmallIntField * get_ElementINS_HLP_IB_PRIV(void)=0;
   virtual void set_ElementINS_HLP_IB_PRIV(TFIBSmallIntField * ElementINS_HLP_IB_PRIV)=0;

   __property TFIBSmallIntField * ElementUPD_HLP_IB_PRIV = {read = get_ElementUPD_HLP_IB_PRIV , write = set_ElementUPD_HLP_IB_PRIV};
   virtual TFIBSmallIntField * get_ElementUPD_HLP_IB_PRIV(void)=0;
   virtual void set_ElementUPD_HLP_IB_PRIV(TFIBSmallIntField * ElementUPD_HLP_IB_PRIV)=0;

   __property TFIBSmallIntField * ElementDEL_HLP_IB_PRIV = {read = get_ElementDEL_HLP_IB_PRIV , write = set_ElementDEL_HLP_IB_PRIV};
   virtual TFIBSmallIntField * get_ElementDEL_HLP_IB_PRIV(void)=0;
   virtual void set_ElementDEL_HLP_IB_PRIV(TFIBSmallIntField * ElementDEL_HLP_IB_PRIV)=0;

   __property __int64 IdIB = {read = get_IdIB , write = set_IdIB};
   virtual __int64 get_IdIB(void)=0;
   virtual void set_IdIB(__int64 IdIB)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   virtual void OpenTable(__int64 id_ib)=0;
   virtual bool SaveIsmen(void)=0;
   virtual bool CancelIsmen(void)=0;
   virtual bool TableAppend(__int64 id_ib)=0;
   virtual bool TableDelete(void)=0;
   virtual bool NewElement(__int64 id_ib)=0;
   virtual int OpenElement(__int64 id )=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
};
#define IID_IHLP_DMSprInfBlockPriv __uuidof(IHLP_DMSprInfBlockPriv)
#endif
