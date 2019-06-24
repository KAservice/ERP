#ifndef UDMSprCustomerKlientImplH
#define UDMSprCustomerKlientImplH
#include "IDMSprCustomerKlient.h"
#include "UDMSprCustomerKlient.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprCustomerKlientImpl)) TDMSprCustomerKlientImpl : public IDMSprCustomerKlient
{
public:
   TDMSprCustomerKlientImpl();
   ~TDMSprCustomerKlientImpl();
   TDMSprCustomerKlient * Object;
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

//IDMSprCustomerKlient
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TFIBLargeIntField * get_TableID_CUST_KLIENT(void);
   virtual void set_TableID_CUST_KLIENT(TFIBLargeIntField * TableID_CUST_KLIENT);

   virtual TFIBLargeIntField * get_TableIDBASE_CUST_KLIENT(void);
   virtual void set_TableIDBASE_CUST_KLIENT(TFIBLargeIntField * TableIDBASE_CUST_KLIENT);

   virtual TFIBWideStringField * get_TableGID_CUST_KLIENT(void);
   virtual void set_TableGID_CUST_KLIENT(TFIBWideStringField * TableGID_CUST_KLIENT);

   virtual TFIBLargeIntField * get_TableIDACCOUNT_CUST_KLIENT(void);
   virtual void set_TableIDACCOUNT_CUST_KLIENT(TFIBLargeIntField * TableIDACCOUNT_CUST_KLIENT);

   virtual TFIBLargeIntField * get_TableIDKLIENT_CUST_KLIENT(void);
   virtual void set_TableIDKLIENT_CUST_KLIENT(TFIBLargeIntField * TableIDKLIENT_CUST_KLIENT);

   virtual TFIBWideStringField * get_TableNAMEKLIENT(void);
   virtual void set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT);

   virtual TFIBLargeIntField * get_ElementID_CUST_KLIENT(void);
   virtual void set_ElementID_CUST_KLIENT(TFIBLargeIntField * ElementID_CUST_KLIENT);

   virtual TFIBLargeIntField * get_ElementIDBASE_CUST_KLIENT(void);
   virtual void set_ElementIDBASE_CUST_KLIENT(TFIBLargeIntField * ElementIDBASE_CUST_KLIENT);

   virtual TFIBWideStringField * get_ElementGID_CUST_KLIENT(void);
   virtual void set_ElementGID_CUST_KLIENT(TFIBWideStringField * ElementGID_CUST_KLIENT);

   virtual TFIBLargeIntField * get_ElementIDACCOUNT_CUST_KLIENT(void);
   virtual void set_ElementIDACCOUNT_CUST_KLIENT(TFIBLargeIntField * ElementIDACCOUNT_CUST_KLIENT);

   virtual TFIBLargeIntField * get_ElementIDKLIENT_CUST_KLIENT(void);
   virtual void set_ElementIDKLIENT_CUST_KLIENT(TFIBLargeIntField * ElementIDKLIENT_CUST_KLIENT);

   virtual TFIBWideStringField * get_ElementNAMEKLIENT(void);
   virtual void set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT);

   virtual __int64 get_IdAccount(void);
   virtual void set_IdAccount(__int64 IdAccount);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual void OpenTable(__int64 id_account);
   virtual bool SaveIsmen(void);
   virtual bool CancelIsmen(void);
   virtual bool TableAppend(__int64 id_account);
   virtual bool TableDelete(void);
   virtual bool NewElement(__int64 id_account);
   virtual int OpenElement(__int64 id );
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
};
#define CLSID_TDMSprCustomerKlientImpl __uuidof(TDMSprCustomerKlientImpl)
#endif
