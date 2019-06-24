#ifndef UIDMSprCustomerAccountH
#define UIDMSprCustomerAccountH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprCustomerAccount)) IDMSprCustomerAccount : public IMainInterface
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

   __property TpFIBQuery * Query = {read = get_Query , write = set_Query};
   virtual TpFIBQuery * get_Query(void)=0;
   virtual void set_Query(TpFIBQuery * Query)=0;

   __property TFIBLargeIntField * TableID_CUST_ACCOUNT = {read = get_TableID_CUST_ACCOUNT , write = set_TableID_CUST_ACCOUNT};
   virtual TFIBLargeIntField * get_TableID_CUST_ACCOUNT(void)=0;
   virtual void set_TableID_CUST_ACCOUNT(TFIBLargeIntField * TableID_CUST_ACCOUNT)=0;

   __property TFIBLargeIntField * TableIDBASE_CUST_ACCOUNT = {read = get_TableIDBASE_CUST_ACCOUNT , write = set_TableIDBASE_CUST_ACCOUNT};
   virtual TFIBLargeIntField * get_TableIDBASE_CUST_ACCOUNT(void)=0;
   virtual void set_TableIDBASE_CUST_ACCOUNT(TFIBLargeIntField * TableIDBASE_CUST_ACCOUNT)=0;

   __property TFIBWideStringField * TableGID_CUST_ACCOUNT = {read = get_TableGID_CUST_ACCOUNT , write = set_TableGID_CUST_ACCOUNT};
   virtual TFIBWideStringField * get_TableGID_CUST_ACCOUNT(void)=0;
   virtual void set_TableGID_CUST_ACCOUNT(TFIBWideStringField * TableGID_CUST_ACCOUNT)=0;

   __property TFIBLargeIntField * TableIDGRP_CUST_ACCOUNT = {read = get_TableIDGRP_CUST_ACCOUNT , write = set_TableIDGRP_CUST_ACCOUNT};
   virtual TFIBLargeIntField * get_TableIDGRP_CUST_ACCOUNT(void)=0;
   virtual void set_TableIDGRP_CUST_ACCOUNT(TFIBLargeIntField * TableIDGRP_CUST_ACCOUNT)=0;

   __property TFIBWideStringField * TableNAME_CUST_ACCOUNT = {read = get_TableNAME_CUST_ACCOUNT , write = set_TableNAME_CUST_ACCOUNT};
   virtual TFIBWideStringField * get_TableNAME_CUST_ACCOUNT(void)=0;
   virtual void set_TableNAME_CUST_ACCOUNT(TFIBWideStringField * TableNAME_CUST_ACCOUNT)=0;

   __property TFIBWideStringField * TableDESCR_CUST_ACCOUNT = {read = get_TableDESCR_CUST_ACCOUNT , write = set_TableDESCR_CUST_ACCOUNT};
   virtual TFIBWideStringField * get_TableDESCR_CUST_ACCOUNT(void)=0;
   virtual void set_TableDESCR_CUST_ACCOUNT(TFIBWideStringField * TableDESCR_CUST_ACCOUNT)=0;

   __property TFIBLargeIntField * TableIDUSER_CUST_ACCOUNT = {read = get_TableIDUSER_CUST_ACCOUNT , write = set_TableIDUSER_CUST_ACCOUNT};
   virtual TFIBLargeIntField * get_TableIDUSER_CUST_ACCOUNT(void)=0;
   virtual void set_TableIDUSER_CUST_ACCOUNT(TFIBLargeIntField * TableIDUSER_CUST_ACCOUNT)=0;

   __property TFIBWideStringField * TablePASSWORD_CUST_ACCOUNT = {read = get_TablePASSWORD_CUST_ACCOUNT , write = set_TablePASSWORD_CUST_ACCOUNT};
   virtual TFIBWideStringField * get_TablePASSWORD_CUST_ACCOUNT(void)=0;
   virtual void set_TablePASSWORD_CUST_ACCOUNT(TFIBWideStringField * TablePASSWORD_CUST_ACCOUNT)=0;

   __property TFIBWideStringField * TableLOGIN_CUST_ACCOUNT = {read = get_TableLOGIN_CUST_ACCOUNT , write = set_TableLOGIN_CUST_ACCOUNT};
   virtual TFIBWideStringField * get_TableLOGIN_CUST_ACCOUNT(void)=0;
   virtual void set_TableLOGIN_CUST_ACCOUNT(TFIBWideStringField * TableLOGIN_CUST_ACCOUNT)=0;

   __property TFIBLargeIntField * ElementID_CUST_ACCOUNT = {read = get_ElementID_CUST_ACCOUNT , write = set_ElementID_CUST_ACCOUNT};
   virtual TFIBLargeIntField * get_ElementID_CUST_ACCOUNT(void)=0;
   virtual void set_ElementID_CUST_ACCOUNT(TFIBLargeIntField * ElementID_CUST_ACCOUNT)=0;

   __property TFIBLargeIntField * ElementIDBASE_CUST_ACCOUNT = {read = get_ElementIDBASE_CUST_ACCOUNT , write = set_ElementIDBASE_CUST_ACCOUNT};
   virtual TFIBLargeIntField * get_ElementIDBASE_CUST_ACCOUNT(void)=0;
   virtual void set_ElementIDBASE_CUST_ACCOUNT(TFIBLargeIntField * ElementIDBASE_CUST_ACCOUNT)=0;

   __property TFIBWideStringField * ElementGID_CUST_ACCOUNT = {read = get_ElementGID_CUST_ACCOUNT , write = set_ElementGID_CUST_ACCOUNT};
   virtual TFIBWideStringField * get_ElementGID_CUST_ACCOUNT(void)=0;
   virtual void set_ElementGID_CUST_ACCOUNT(TFIBWideStringField * ElementGID_CUST_ACCOUNT)=0;

   __property TFIBLargeIntField * ElementIDGRP_CUST_ACCOUNT = {read = get_ElementIDGRP_CUST_ACCOUNT , write = set_ElementIDGRP_CUST_ACCOUNT};
   virtual TFIBLargeIntField * get_ElementIDGRP_CUST_ACCOUNT(void)=0;
   virtual void set_ElementIDGRP_CUST_ACCOUNT(TFIBLargeIntField * ElementIDGRP_CUST_ACCOUNT)=0;

   __property TFIBWideStringField * ElementNAME_CUST_ACCOUNT = {read = get_ElementNAME_CUST_ACCOUNT , write = set_ElementNAME_CUST_ACCOUNT};
   virtual TFIBWideStringField * get_ElementNAME_CUST_ACCOUNT(void)=0;
   virtual void set_ElementNAME_CUST_ACCOUNT(TFIBWideStringField * ElementNAME_CUST_ACCOUNT)=0;

   __property TFIBWideStringField * ElementDESCR_CUST_ACCOUNT = {read = get_ElementDESCR_CUST_ACCOUNT , write = set_ElementDESCR_CUST_ACCOUNT};
   virtual TFIBWideStringField * get_ElementDESCR_CUST_ACCOUNT(void)=0;
   virtual void set_ElementDESCR_CUST_ACCOUNT(TFIBWideStringField * ElementDESCR_CUST_ACCOUNT)=0;

   __property TFIBLargeIntField * ElementIDUSER_CUST_ACCOUNT = {read = get_ElementIDUSER_CUST_ACCOUNT , write = set_ElementIDUSER_CUST_ACCOUNT};
   virtual TFIBLargeIntField * get_ElementIDUSER_CUST_ACCOUNT(void)=0;
   virtual void set_ElementIDUSER_CUST_ACCOUNT(TFIBLargeIntField * ElementIDUSER_CUST_ACCOUNT)=0;

   __property TFIBWideStringField * ElementPASSWORD_CUST_ACCOUNT = {read = get_ElementPASSWORD_CUST_ACCOUNT , write = set_ElementPASSWORD_CUST_ACCOUNT};
   virtual TFIBWideStringField * get_ElementPASSWORD_CUST_ACCOUNT(void)=0;
   virtual void set_ElementPASSWORD_CUST_ACCOUNT(TFIBWideStringField * ElementPASSWORD_CUST_ACCOUNT)=0;

   __property TFIBWideStringField * ElementLOGIN_CUST_ACCOUNT = {read = get_ElementLOGIN_CUST_ACCOUNT , write = set_ElementLOGIN_CUST_ACCOUNT};
   virtual TFIBWideStringField * get_ElementLOGIN_CUST_ACCOUNT(void)=0;
   virtual void set_ElementLOGIN_CUST_ACCOUNT(TFIBWideStringField * ElementLOGIN_CUST_ACCOUNT)=0;

   __property TFIBWideStringField * TableNAME_USER = {read = get_TableNAME_USER , write = set_TableNAME_USER};
   virtual TFIBWideStringField * get_TableNAME_USER(void)=0;
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)=0;

   __property TFIBWideStringField * TableNAME_SGRPUSER = {read = get_TableNAME_SGRPUSER , write = set_TableNAME_SGRPUSER};
   virtual TFIBWideStringField * get_TableNAME_SGRPUSER(void)=0;
   virtual void set_TableNAME_SGRPUSER(TFIBWideStringField * TableNAME_SGRPUSER)=0;

   __property TFIBLargeIntField * TableIDGRP_USER = {read = get_TableIDGRP_USER , write = set_TableIDGRP_USER};
   virtual TFIBLargeIntField * get_TableIDGRP_USER(void)=0;
   virtual void set_TableIDGRP_USER(TFIBLargeIntField * TableIDGRP_USER)=0;

   __property TFIBWideStringField * ElementNAME_USER = {read = get_ElementNAME_USER , write = set_ElementNAME_USER};
   virtual TFIBWideStringField * get_ElementNAME_USER(void)=0;
   virtual void set_ElementNAME_USER(TFIBWideStringField * ElementNAME_USER)=0;

   __property TFIBLargeIntField * ElementIDGRP_USER = {read = get_ElementIDGRP_USER , write = set_ElementIDGRP_USER};
   virtual TFIBLargeIntField * get_ElementIDGRP_USER(void)=0;
   virtual void set_ElementIDGRP_USER(TFIBLargeIntField * ElementIDGRP_USER)=0;

   __property TFIBWideStringField * ElementNAME_SGRPUSER = {read = get_ElementNAME_SGRPUSER , write = set_ElementNAME_SGRPUSER};
   virtual TFIBWideStringField * get_ElementNAME_SGRPUSER(void)=0;
   virtual void set_ElementNAME_SGRPUSER(TFIBWideStringField * ElementNAME_SGRPUSER)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   virtual void OpenTable(__int64 id_grp, bool all)=0;
   virtual UnicodeString GetTextQuery(__int64 id_grp, bool all)=0;
   virtual int OpenElement(__int64 id )=0;
   virtual bool NewElement(__int64 id_grp)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual void ChancheGrp(__int64 id_new_grp,__int64 id_element)=0;
   virtual __int64 FindPoName(UnicodeString name)=0;
   virtual __int64 GetIdGrp(__int64 id_el)=0;
};
#define IID_IDMSprCustomerAccount __uuidof(IDMSprCustomerAccount)
#endif
