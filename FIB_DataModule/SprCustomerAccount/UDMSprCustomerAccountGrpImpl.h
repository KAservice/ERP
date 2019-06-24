#ifndef UDMSprCustomerAccountGrpImplH
#define UDMSprCustomerAccountGrpImplH
#include "IDMSprCustomerAccountGrp.h"
#include "UDMSprCustomerAccountGrp.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprCustomerAccountGrpImpl)) TDMSprCustomerAccountGrpImpl : public IDMSprCustomerAccountGrp
{
public:
   TDMSprCustomerAccountGrpImpl();
   ~TDMSprCustomerAccountGrpImpl();
   TDMSprCustomerAccountGrp * Object;
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

//IDMSprCustomerAccountGrp
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

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBLargeIntField * get_TableID_CUST_ACCOUNT_GRP(void);
   virtual void set_TableID_CUST_ACCOUNT_GRP(TFIBLargeIntField * TableID_CUST_ACCOUNT_GRP);

   virtual TFIBLargeIntField * get_TableIDBASE_CUST_ACCOUNT_GRP(void);
   virtual void set_TableIDBASE_CUST_ACCOUNT_GRP(TFIBLargeIntField * TableIDBASE_CUST_ACCOUNT_GRP);

   virtual TFIBWideStringField * get_TableGID_CUST_ACCOUNT_GRP(void);
   virtual void set_TableGID_CUST_ACCOUNT_GRP(TFIBWideStringField * TableGID_CUST_ACCOUNT_GRP);

   virtual TFIBLargeIntField * get_TableIDGRP_CUST_ACCOUNT_GRP(void);
   virtual void set_TableIDGRP_CUST_ACCOUNT_GRP(TFIBLargeIntField * TableIDGRP_CUST_ACCOUNT_GRP);

   virtual TFIBWideStringField * get_TableNAME_CUST_ACCOUNT_GRP(void);
   virtual void set_TableNAME_CUST_ACCOUNT_GRP(TFIBWideStringField * TableNAME_CUST_ACCOUNT_GRP);

   virtual TFIBLargeIntField * get_ElementID_CUST_ACCOUNT_GRP(void);
   virtual void set_ElementID_CUST_ACCOUNT_GRP(TFIBLargeIntField * ElementID_CUST_ACCOUNT_GRP);

   virtual TFIBLargeIntField * get_ElementIDBASE_CUST_ACCOUNT_GRP(void);
   virtual void set_ElementIDBASE_CUST_ACCOUNT_GRP(TFIBLargeIntField * ElementIDBASE_CUST_ACCOUNT_GRP);

   virtual TFIBWideStringField * get_ElementGID_CUST_ACCOUNT_GRP(void);
   virtual void set_ElementGID_CUST_ACCOUNT_GRP(TFIBWideStringField * ElementGID_CUST_ACCOUNT_GRP);

   virtual TFIBLargeIntField * get_ElementIDGRP_CUST_ACCOUNT_GRP(void);
   virtual void set_ElementIDGRP_CUST_ACCOUNT_GRP(TFIBLargeIntField * ElementIDGRP_CUST_ACCOUNT_GRP);

   virtual TFIBWideStringField * get_ElementNAME_CUST_ACCOUNT_GRP(void);
   virtual void set_ElementNAME_CUST_ACCOUNT_GRP(TFIBWideStringField * ElementNAME_CUST_ACCOUNT_GRP);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(__int64 id_grp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual __int64 FindPoName(UnicodeString name);
};
#define CLSID_TDMSprCustomerAccountGrpImpl __uuidof(TDMSprCustomerAccountGrpImpl)
#endif
