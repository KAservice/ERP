#ifndef UIDMSprCustomerUserH
#define UIDMSprCustomerUserH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprCustomerUser)) IDMSprCustomerUser : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TDataSource * DataSourceElement = {read = get_DataSourceElement , write = set_DataSourceElement};
   virtual TDataSource * get_DataSourceElement(void)=0;
   virtual void set_DataSourceElement(TDataSource * DataSourceElement)=0;

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBLargeIntField * TableID_CUST_USER = {read = get_TableID_CUST_USER , write = set_TableID_CUST_USER};
   virtual TFIBLargeIntField * get_TableID_CUST_USER(void)=0;
   virtual void set_TableID_CUST_USER(TFIBLargeIntField * TableID_CUST_USER)=0;

   __property TFIBLargeIntField * TableIDBASE_CUST_USER = {read = get_TableIDBASE_CUST_USER , write = set_TableIDBASE_CUST_USER};
   virtual TFIBLargeIntField * get_TableIDBASE_CUST_USER(void)=0;
   virtual void set_TableIDBASE_CUST_USER(TFIBLargeIntField * TableIDBASE_CUST_USER)=0;

   __property TFIBWideStringField * TableGID_CUST_USER = {read = get_TableGID_CUST_USER , write = set_TableGID_CUST_USER};
   virtual TFIBWideStringField * get_TableGID_CUST_USER(void)=0;
   virtual void set_TableGID_CUST_USER(TFIBWideStringField * TableGID_CUST_USER)=0;

   __property TFIBLargeIntField * TableIDACCOUNT_CUST_USER = {read = get_TableIDACCOUNT_CUST_USER , write = set_TableIDACCOUNT_CUST_USER};
   virtual TFIBLargeIntField * get_TableIDACCOUNT_CUST_USER(void)=0;
   virtual void set_TableIDACCOUNT_CUST_USER(TFIBLargeIntField * TableIDACCOUNT_CUST_USER)=0;

   __property TFIBLargeIntField * TableIDGRP_CUST_USER = {read = get_TableIDGRP_CUST_USER , write = set_TableIDGRP_CUST_USER};
   virtual TFIBLargeIntField * get_TableIDGRP_CUST_USER(void)=0;
   virtual void set_TableIDGRP_CUST_USER(TFIBLargeIntField * TableIDGRP_CUST_USER)=0;

   __property TFIBWideStringField * TableNAME_CUST_USER = {read = get_TableNAME_CUST_USER , write = set_TableNAME_CUST_USER};
   virtual TFIBWideStringField * get_TableNAME_CUST_USER(void)=0;
   virtual void set_TableNAME_CUST_USER(TFIBWideStringField * TableNAME_CUST_USER)=0;

   __property TFIBWideStringField * TableLOGIN_CUST_USER = {read = get_TableLOGIN_CUST_USER , write = set_TableLOGIN_CUST_USER};
   virtual TFIBWideStringField * get_TableLOGIN_CUST_USER(void)=0;
   virtual void set_TableLOGIN_CUST_USER(TFIBWideStringField * TableLOGIN_CUST_USER)=0;

   __property TFIBWideStringField * TablePASSWORD_CUST_USER = {read = get_TablePASSWORD_CUST_USER , write = set_TablePASSWORD_CUST_USER};
   virtual TFIBWideStringField * get_TablePASSWORD_CUST_USER(void)=0;
   virtual void set_TablePASSWORD_CUST_USER(TFIBWideStringField * TablePASSWORD_CUST_USER)=0;

   __property TFIBLargeIntField * ElementID_CUST_USER = {read = get_ElementID_CUST_USER , write = set_ElementID_CUST_USER};
   virtual TFIBLargeIntField * get_ElementID_CUST_USER(void)=0;
   virtual void set_ElementID_CUST_USER(TFIBLargeIntField * ElementID_CUST_USER)=0;

   __property TFIBLargeIntField * ElementIDBASE_CUST_USER = {read = get_ElementIDBASE_CUST_USER , write = set_ElementIDBASE_CUST_USER};
   virtual TFIBLargeIntField * get_ElementIDBASE_CUST_USER(void)=0;
   virtual void set_ElementIDBASE_CUST_USER(TFIBLargeIntField * ElementIDBASE_CUST_USER)=0;

   __property TFIBWideStringField * ElementGID_CUST_USER = {read = get_ElementGID_CUST_USER , write = set_ElementGID_CUST_USER};
   virtual TFIBWideStringField * get_ElementGID_CUST_USER(void)=0;
   virtual void set_ElementGID_CUST_USER(TFIBWideStringField * ElementGID_CUST_USER)=0;

   __property TFIBLargeIntField * ElementIDACCOUNT_CUST_USER = {read = get_ElementIDACCOUNT_CUST_USER , write = set_ElementIDACCOUNT_CUST_USER};
   virtual TFIBLargeIntField * get_ElementIDACCOUNT_CUST_USER(void)=0;
   virtual void set_ElementIDACCOUNT_CUST_USER(TFIBLargeIntField * ElementIDACCOUNT_CUST_USER)=0;

   __property TFIBLargeIntField * ElementIDGRP_CUST_USER = {read = get_ElementIDGRP_CUST_USER , write = set_ElementIDGRP_CUST_USER};
   virtual TFIBLargeIntField * get_ElementIDGRP_CUST_USER(void)=0;
   virtual void set_ElementIDGRP_CUST_USER(TFIBLargeIntField * ElementIDGRP_CUST_USER)=0;

   __property TFIBWideStringField * ElementNAME_CUST_USER = {read = get_ElementNAME_CUST_USER , write = set_ElementNAME_CUST_USER};
   virtual TFIBWideStringField * get_ElementNAME_CUST_USER(void)=0;
   virtual void set_ElementNAME_CUST_USER(TFIBWideStringField * ElementNAME_CUST_USER)=0;

   __property TFIBWideStringField * ElementLOGIN_CUST_USER = {read = get_ElementLOGIN_CUST_USER , write = set_ElementLOGIN_CUST_USER};
   virtual TFIBWideStringField * get_ElementLOGIN_CUST_USER(void)=0;
   virtual void set_ElementLOGIN_CUST_USER(TFIBWideStringField * ElementLOGIN_CUST_USER)=0;

   __property TFIBWideStringField * ElementPASSWORD_CUST_USER = {read = get_ElementPASSWORD_CUST_USER , write = set_ElementPASSWORD_CUST_USER};
   virtual TFIBWideStringField * get_ElementPASSWORD_CUST_USER(void)=0;
   virtual void set_ElementPASSWORD_CUST_USER(TFIBWideStringField * ElementPASSWORD_CUST_USER)=0;

   __property __int64 IdAccount = {read = get_IdAccount , write = set_IdAccount};
   virtual __int64 get_IdAccount(void)=0;
   virtual void set_IdAccount(__int64 IdAccount)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   virtual UnicodeString GetTextQuery(__int64 id_account,__int64 id_grp, bool all)=0;
   virtual void OpenTable(__int64 id_account,__int64 id_grp,bool all)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual bool NewElement(__int64 id_account,__int64 id_grp)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual __int64 FindPoName(UnicodeString NameUser)=0;
   virtual __int64 FindPoPassword(UnicodeString Password)=0;
   virtual __int64 GetIdGrpUser(__int64 id_user)=0;
   virtual void ChancheGrp(__int64 id_new_grp,__int64 id_element)=0;
};
#define IID_IDMSprCustomerUser __uuidof(IDMSprCustomerUser)
#endif
