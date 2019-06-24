#ifndef UDMSprGrpNomInetCatalogImplH
#define UDMSprGrpNomInetCatalogImplH
#include "IDMSprGrpNomInetCatalog.h"
#include "UDMSprGrpNomInetCatalog.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprGrpNomInetCatalogImpl)) TDMSprGrpNomInetCatalogImpl : public IDMSprGrpNomInetCatalog
{
public:
   TDMSprGrpNomInetCatalogImpl();
   ~TDMSprGrpNomInetCatalogImpl();
   TDMSprGrpNomInetCatalog * Object;
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

//IDMSprGrpNomInetCatalog
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

   virtual TFIBLargeIntField * get_ElementID_SNOMINETCAT_GRP(void);
   virtual void set_ElementID_SNOMINETCAT_GRP(TFIBLargeIntField * ElementID_SNOMINETCAT_GRP);

   virtual TFIBLargeIntField * get_ElementIDBASE_SNOMINETCAT_GRP(void);
   virtual void set_ElementIDBASE_SNOMINETCAT_GRP(TFIBLargeIntField * ElementIDBASE_SNOMINETCAT_GRP);

   virtual TFIBWideStringField * get_ElementGID_SNOMINETCAT_GRP(void);
   virtual void set_ElementGID_SNOMINETCAT_GRP(TFIBWideStringField * ElementGID_SNOMINETCAT_GRP);

   virtual TFIBLargeIntField * get_ElementIDGRP_SNOMINETCAT_GRP(void);
   virtual void set_ElementIDGRP_SNOMINETCAT_GRP(TFIBLargeIntField * ElementIDGRP_SNOMINETCAT_GRP);

   virtual TFIBLargeIntField * get_ElementIDINETCAT_SNOMINETCAT_GRP(void);
   virtual void set_ElementIDINETCAT_SNOMINETCAT_GRP(TFIBLargeIntField * ElementIDINETCAT_SNOMINETCAT_GRP);

   virtual TFIBWideStringField * get_ElementNAME_SNOMINETCAT_GRP(void);
   virtual void set_ElementNAME_SNOMINETCAT_GRP(TFIBWideStringField * ElementNAME_SNOMINETCAT_GRP);

   virtual TFIBLargeIntField * get_TableID_SNOMINETCAT_GRP(void);
   virtual void set_TableID_SNOMINETCAT_GRP(TFIBLargeIntField * TableID_SNOMINETCAT_GRP);

   virtual TFIBLargeIntField * get_TableIDBASE_SNOMINETCAT_GRP(void);
   virtual void set_TableIDBASE_SNOMINETCAT_GRP(TFIBLargeIntField * TableIDBASE_SNOMINETCAT_GRP);

   virtual TFIBWideStringField * get_TableGID_SNOMINETCAT_GRP(void);
   virtual void set_TableGID_SNOMINETCAT_GRP(TFIBWideStringField * TableGID_SNOMINETCAT_GRP);

   virtual TFIBLargeIntField * get_TableIDGRP_SNOMINETCAT_GRP(void);
   virtual void set_TableIDGRP_SNOMINETCAT_GRP(TFIBLargeIntField * TableIDGRP_SNOMINETCAT_GRP);

   virtual TFIBLargeIntField * get_TableIDINETCAT_SNOMINETCAT_GRP(void);
   virtual void set_TableIDINETCAT_SNOMINETCAT_GRP(TFIBLargeIntField * TableIDINETCAT_SNOMINETCAT_GRP);

   virtual TFIBWideStringField * get_TableNAME_SNOMINETCAT_GRP(void);
   virtual void set_TableNAME_SNOMINETCAT_GRP(TFIBWideStringField * TableNAME_SNOMINETCAT_GRP);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual __int64 get_IdInetCatalog(void);
   virtual void set_IdInetCatalog(__int64 IdInetCatalog);

   virtual void OpenTable(__int64 id_inet_catalog);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(__int64 id_inet_catalog, __int64 id_grp);
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 id);
};
#define CLSID_TDMSprGrpNomInetCatalogImpl __uuidof(TDMSprGrpNomInetCatalogImpl)
#endif
