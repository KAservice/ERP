#ifndef UDMSprCustomerUserGrpImplH
#define UDMSprCustomerUserGrpImplH
#include "IDMSprCustomerUserGrp.h"
#include "UDMSprCustomerUserGrp.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprCustomerUserGrpImpl)) TDMSprCustomerUserGrpImpl : public IDMSprCustomerUserGrp
{
public:
   TDMSprCustomerUserGrpImpl();
   ~TDMSprCustomerUserGrpImpl();
   TDMSprCustomerUserGrp * Object;
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

//IDMSprCustomerUserGrp
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

   virtual TFIBLargeIntField * get_TableID_CUST_USER_GRP(void);
   virtual void set_TableID_CUST_USER_GRP(TFIBLargeIntField * TableID_CUST_USER_GRP);

   virtual TFIBLargeIntField * get_TableIDBASE_CUST_USER_GRP(void);
   virtual void set_TableIDBASE_CUST_USER_GRP(TFIBLargeIntField * TableIDBASE_CUST_USER_GRP);

   virtual TFIBWideStringField * get_TableGID_CUST_USER_GRP(void);
   virtual void set_TableGID_CUST_USER_GRP(TFIBWideStringField * TableGID_CUST_USER_GRP);

   virtual TFIBLargeIntField * get_TableIDGRP_CUST_USER_GRP(void);
   virtual void set_TableIDGRP_CUST_USER_GRP(TFIBLargeIntField * TableIDGRP_CUST_USER_GRP);

   virtual TFIBLargeIntField * get_TableIDACCOUNT_CUST_USER_GRP(void);
   virtual void set_TableIDACCOUNT_CUST_USER_GRP(TFIBLargeIntField * TableIDACCOUNT_CUST_USER_GRP);

   virtual TFIBWideStringField * get_TableNAME_CUST_USER_GRP(void);
   virtual void set_TableNAME_CUST_USER_GRP(TFIBWideStringField * TableNAME_CUST_USER_GRP);

   virtual TFIBLargeIntField * get_ElementID_CUST_USER_GRP(void);
   virtual void set_ElementID_CUST_USER_GRP(TFIBLargeIntField * ElementID_CUST_USER_GRP);

   virtual TFIBLargeIntField * get_ElementIDBASE_CUST_USER_GRP(void);
   virtual void set_ElementIDBASE_CUST_USER_GRP(TFIBLargeIntField * ElementIDBASE_CUST_USER_GRP);

   virtual TFIBWideStringField * get_ElementGID_CUST_USER_GRP(void);
   virtual void set_ElementGID_CUST_USER_GRP(TFIBWideStringField * ElementGID_CUST_USER_GRP);

   virtual TFIBLargeIntField * get_ElementIDGRP_CUST_USER_GRP(void);
   virtual void set_ElementIDGRP_CUST_USER_GRP(TFIBLargeIntField * ElementIDGRP_CUST_USER_GRP);

   virtual TFIBLargeIntField * get_ElementIDACCOUNT_CUST_USER_GRP(void);
   virtual void set_ElementIDACCOUNT_CUST_USER_GRP(TFIBLargeIntField * ElementIDACCOUNT_CUST_USER_GRP);

   virtual TFIBWideStringField * get_ElementNAME_CUST_USER_GRP(void);
   virtual void set_ElementNAME_CUST_USER_GRP(TFIBWideStringField * ElementNAME_CUST_USER_GRP);

   virtual __int64 get_IdAccount(void);
   virtual void set_IdAccount(__int64 IdAccount);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual void OpenTable(__int64 id_account);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(__int64 id_account, __int64 id_grp);
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 id);
};
#define CLSID_TDMSprCustomerUserGrpImpl __uuidof(TDMSprCustomerUserGrpImpl)
#endif
