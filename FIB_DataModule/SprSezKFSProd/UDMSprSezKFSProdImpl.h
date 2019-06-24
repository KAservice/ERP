#ifndef UDMSprSezKFSProdImplH
#define UDMSprSezKFSProdImplH
#include "IDMSprSezKFSProd.h"
#include "UDMSprSezKFSProd.h"
//---------------------------------------------------------------
class __declspec(uuid("{28C9CF7F-4606-4BDE-9FAE-756A8398134C}"))TDMSprSezKFSProdImpl : public IDMSprSezKFSProd
{
public:
   TDMSprSezKFSProdImpl();
   ~TDMSprSezKFSProdImpl();
   TDMSprSezKFSProd * Object;
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

//IDMSprSezKFSProd
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TFIBIntegerField * get_TableMONTH_SSEZKF_SPROD(void);
   virtual void set_TableMONTH_SSEZKF_SPROD(TFIBIntegerField * TableMONTH_SSEZKF_SPROD);

   virtual TFIBBCDField * get_TableVALUE_SSEZKF_SPROD(void);
   virtual void set_TableVALUE_SSEZKF_SPROD(TFIBBCDField * TableVALUE_SSEZKF_SPROD);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBBCDField * get_TableID_SSEZKF_SPROD(void);
   virtual void set_TableID_SSEZKF_SPROD(TFIBBCDField * TableID_SSEZKF_SPROD);

   virtual TFIBBCDField * get_TableIDSSPROD_SSEZKF_SPROD(void);
   virtual void set_TableIDSSPROD_SSEZKF_SPROD(TFIBBCDField * TableIDSSPROD_SSEZKF_SPROD);

   virtual TFIBWideStringField * get_TableGID_SSEZKF_SPROD(void);
   virtual void set_TableGID_SSEZKF_SPROD(TFIBWideStringField * TableGID_SSEZKF_SPROD);

   virtual __int64 get_IdSProd(void);
   virtual void set_IdSProd(__int64 IdSProd);

   virtual void OpenTable(__int64 idSProd);
   virtual void NewElement(__int64 idSProd);
   virtual void DeleteElement();
   virtual void SaveIsmen();
   virtual void CancelIsmen();
};
#define CLSID_TDMSprSezKFSProdImpl __uuidof(TDMSprSezKFSProdImpl)
#endif
