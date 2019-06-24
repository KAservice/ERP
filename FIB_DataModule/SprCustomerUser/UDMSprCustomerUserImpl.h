#ifndef UDMSprCustomerUserImplH
#define UDMSprCustomerUserImplH
#include "IDMSprCustomerUser.h"
#include "UDMSprCustomerUser.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprCustomerUserImpl)) TDMSprCustomerUserImpl : public IDMSprCustomerUser
{
public:
   TDMSprCustomerUserImpl();
   ~TDMSprCustomerUserImpl();
   TDMSprCustomerUser * Object;
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

//IDMSprCustomerUser
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBLargeIntField * get_TableID_CUST_USER(void);
   virtual void set_TableID_CUST_USER(TFIBLargeIntField * TableID_CUST_USER);

   virtual TFIBLargeIntField * get_TableIDBASE_CUST_USER(void);
   virtual void set_TableIDBASE_CUST_USER(TFIBLargeIntField * TableIDBASE_CUST_USER);

   virtual TFIBWideStringField * get_TableGID_CUST_USER(void);
   virtual void set_TableGID_CUST_USER(TFIBWideStringField * TableGID_CUST_USER);

   virtual TFIBLargeIntField * get_TableIDACCOUNT_CUST_USER(void);
   virtual void set_TableIDACCOUNT_CUST_USER(TFIBLargeIntField * TableIDACCOUNT_CUST_USER);

   virtual TFIBLargeIntField * get_TableIDGRP_CUST_USER(void);
   virtual void set_TableIDGRP_CUST_USER(TFIBLargeIntField * TableIDGRP_CUST_USER);

   virtual TFIBWideStringField * get_TableNAME_CUST_USER(void);
   virtual void set_TableNAME_CUST_USER(TFIBWideStringField * TableNAME_CUST_USER);

   virtual TFIBWideStringField * get_TableLOGIN_CUST_USER(void);
   virtual void set_TableLOGIN_CUST_USER(TFIBWideStringField * TableLOGIN_CUST_USER);

   virtual TFIBWideStringField * get_TablePASSWORD_CUST_USER(void);
   virtual void set_TablePASSWORD_CUST_USER(TFIBWideStringField * TablePASSWORD_CUST_USER);

   virtual TFIBLargeIntField * get_ElementID_CUST_USER(void);
   virtual void set_ElementID_CUST_USER(TFIBLargeIntField * ElementID_CUST_USER);

   virtual TFIBLargeIntField * get_ElementIDBASE_CUST_USER(void);
   virtual void set_ElementIDBASE_CUST_USER(TFIBLargeIntField * ElementIDBASE_CUST_USER);

   virtual TFIBWideStringField * get_ElementGID_CUST_USER(void);
   virtual void set_ElementGID_CUST_USER(TFIBWideStringField * ElementGID_CUST_USER);

   virtual TFIBLargeIntField * get_ElementIDACCOUNT_CUST_USER(void);
   virtual void set_ElementIDACCOUNT_CUST_USER(TFIBLargeIntField * ElementIDACCOUNT_CUST_USER);

   virtual TFIBLargeIntField * get_ElementIDGRP_CUST_USER(void);
   virtual void set_ElementIDGRP_CUST_USER(TFIBLargeIntField * ElementIDGRP_CUST_USER);

   virtual TFIBWideStringField * get_ElementNAME_CUST_USER(void);
   virtual void set_ElementNAME_CUST_USER(TFIBWideStringField * ElementNAME_CUST_USER);

   virtual TFIBWideStringField * get_ElementLOGIN_CUST_USER(void);
   virtual void set_ElementLOGIN_CUST_USER(TFIBWideStringField * ElementLOGIN_CUST_USER);

   virtual TFIBWideStringField * get_ElementPASSWORD_CUST_USER(void);
   virtual void set_ElementPASSWORD_CUST_USER(TFIBWideStringField * ElementPASSWORD_CUST_USER);

   virtual __int64 get_IdAccount(void);
   virtual void set_IdAccount(__int64 IdAccount);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual UnicodeString GetTextQuery(__int64 id_account,__int64 id_grp, bool all);
   virtual void OpenTable(__int64 id_account,__int64 id_grp,bool all);
   virtual int OpenElement(__int64 id);
   virtual bool NewElement(__int64 id_account,__int64 id_grp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual __int64 FindPoName(UnicodeString NameUser);
   virtual __int64 FindPoPassword(UnicodeString Password);
   virtual __int64 GetIdGrpUser(__int64 id_user);
   virtual void ChancheGrp(__int64 id_new_grp,__int64 id_element);
};
#define CLSID_TDMSprCustomerUserImpl __uuidof(TDMSprCustomerUserImpl)
#endif
