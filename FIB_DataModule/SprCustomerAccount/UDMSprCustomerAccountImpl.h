#ifndef UDMSprCustomerAccountImplH
#define UDMSprCustomerAccountImplH
#include "IDMSprCustomerAccount.h"
#include "UDMSprCustomerAccount.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprCustomerAccountImpl)) TDMSprCustomerAccountImpl : public IDMSprCustomerAccount
{
public:
   TDMSprCustomerAccountImpl();
   ~TDMSprCustomerAccountImpl();
   TDMSprCustomerAccount * Object;
   int NumRefs;
   bool flDeleteObject;
   void DeleteImpl(void);

   //IUnknown
   virtual int kanQueryInterface(REFIID id_interface,void ** ppv);
   virtual int kanAddRef(void);
   virtual int kanRelease(void);

   //IMainInterface
   virtual int  get_CodeError(void);
   virtual void set_CodeError(int CodeError);
   virtual UnicodeString  get_TextError(void);
   virtual void set_TextError(UnicodeString  TextError);
   virtual int Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object);
   virtual int Done(void);

//IDMSprCustomerAccount
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBQuery * get_Query(void);
   virtual void set_Query(TpFIBQuery * Query);

   virtual TFIBLargeIntField * get_TableID_CUST_ACCOUNT(void);
   virtual void set_TableID_CUST_ACCOUNT(TFIBLargeIntField * TableID_CUST_ACCOUNT);

   virtual TFIBLargeIntField * get_TableIDBASE_CUST_ACCOUNT(void);
   virtual void set_TableIDBASE_CUST_ACCOUNT(TFIBLargeIntField * TableIDBASE_CUST_ACCOUNT);

   virtual TFIBWideStringField * get_TableGID_CUST_ACCOUNT(void);
   virtual void set_TableGID_CUST_ACCOUNT(TFIBWideStringField * TableGID_CUST_ACCOUNT);

   virtual TFIBLargeIntField * get_TableIDGRP_CUST_ACCOUNT(void);
   virtual void set_TableIDGRP_CUST_ACCOUNT(TFIBLargeIntField * TableIDGRP_CUST_ACCOUNT);

   virtual TFIBWideStringField * get_TableNAME_CUST_ACCOUNT(void);
   virtual void set_TableNAME_CUST_ACCOUNT(TFIBWideStringField * TableNAME_CUST_ACCOUNT);

   virtual TFIBWideStringField * get_TableDESCR_CUST_ACCOUNT(void);
   virtual void set_TableDESCR_CUST_ACCOUNT(TFIBWideStringField * TableDESCR_CUST_ACCOUNT);

   virtual TFIBLargeIntField * get_TableIDUSER_CUST_ACCOUNT(void);
   virtual void set_TableIDUSER_CUST_ACCOUNT(TFIBLargeIntField * TableIDUSER_CUST_ACCOUNT);

   virtual TFIBWideStringField * get_TablePASSWORD_CUST_ACCOUNT(void);
   virtual void set_TablePASSWORD_CUST_ACCOUNT(TFIBWideStringField * TablePASSWORD_CUST_ACCOUNT);

   virtual TFIBWideStringField * get_TableLOGIN_CUST_ACCOUNT(void);
   virtual void set_TableLOGIN_CUST_ACCOUNT(TFIBWideStringField * TableLOGIN_CUST_ACCOUNT);

   virtual TFIBLargeIntField * get_ElementID_CUST_ACCOUNT(void);
   virtual void set_ElementID_CUST_ACCOUNT(TFIBLargeIntField * ElementID_CUST_ACCOUNT);

   virtual TFIBLargeIntField * get_ElementIDBASE_CUST_ACCOUNT(void);
   virtual void set_ElementIDBASE_CUST_ACCOUNT(TFIBLargeIntField * ElementIDBASE_CUST_ACCOUNT);

   virtual TFIBWideStringField * get_ElementGID_CUST_ACCOUNT(void);
   virtual void set_ElementGID_CUST_ACCOUNT(TFIBWideStringField * ElementGID_CUST_ACCOUNT);

   virtual TFIBLargeIntField * get_ElementIDGRP_CUST_ACCOUNT(void);
   virtual void set_ElementIDGRP_CUST_ACCOUNT(TFIBLargeIntField * ElementIDGRP_CUST_ACCOUNT);

   virtual TFIBWideStringField * get_ElementNAME_CUST_ACCOUNT(void);
   virtual void set_ElementNAME_CUST_ACCOUNT(TFIBWideStringField * ElementNAME_CUST_ACCOUNT);

   virtual TFIBWideStringField * get_ElementDESCR_CUST_ACCOUNT(void);
   virtual void set_ElementDESCR_CUST_ACCOUNT(TFIBWideStringField * ElementDESCR_CUST_ACCOUNT);

   virtual TFIBLargeIntField * get_ElementIDUSER_CUST_ACCOUNT(void);
   virtual void set_ElementIDUSER_CUST_ACCOUNT(TFIBLargeIntField * ElementIDUSER_CUST_ACCOUNT);

   virtual TFIBWideStringField * get_ElementPASSWORD_CUST_ACCOUNT(void);
   virtual void set_ElementPASSWORD_CUST_ACCOUNT(TFIBWideStringField * ElementPASSWORD_CUST_ACCOUNT);

   virtual TFIBWideStringField * get_ElementLOGIN_CUST_ACCOUNT(void);
   virtual void set_ElementLOGIN_CUST_ACCOUNT(TFIBWideStringField * ElementLOGIN_CUST_ACCOUNT);

   virtual TFIBWideStringField * get_TableNAME_USER(void);
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER);

   virtual TFIBWideStringField * get_TableNAME_SGRPUSER(void);
   virtual void set_TableNAME_SGRPUSER(TFIBWideStringField * TableNAME_SGRPUSER);

   virtual TFIBLargeIntField * get_TableIDGRP_USER(void);
   virtual void set_TableIDGRP_USER(TFIBLargeIntField * TableIDGRP_USER);

   virtual TFIBWideStringField * get_ElementNAME_USER(void);
   virtual void set_ElementNAME_USER(TFIBWideStringField * ElementNAME_USER);

   virtual TFIBLargeIntField * get_ElementIDGRP_USER(void);
   virtual void set_ElementIDGRP_USER(TFIBLargeIntField * ElementIDGRP_USER);

   virtual TFIBWideStringField * get_ElementNAME_SGRPUSER(void);
   virtual void set_ElementNAME_SGRPUSER(TFIBWideStringField * ElementNAME_SGRPUSER);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual void OpenTable(__int64 id_grp, bool all);
   virtual UnicodeString GetTextQuery(__int64 id_grp, bool all);
   virtual int OpenElement(__int64 id );
   virtual bool NewElement(__int64 id_grp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual void ChancheGrp(__int64 id_new_grp,__int64 id_element);
   virtual __int64 FindPoName(UnicodeString name);
   virtual __int64 GetIdGrp(__int64 id_el);
};
#define CLSID_TDMSprCustomerAccountImpl __uuidof(TDMSprCustomerAccountImpl)
#endif
