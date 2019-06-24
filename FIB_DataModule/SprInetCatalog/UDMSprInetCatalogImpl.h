#ifndef UDMSprInetCatalogImplH
#define UDMSprInetCatalogImplH
#include "IDMSprInetCatalog.h"
#include "UDMSprInetCatalog.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprInetCatalogImpl)) TDMSprInetCatalogImpl : public IDMSprInetCatalog
{
public:
   TDMSprInetCatalogImpl();
   ~TDMSprInetCatalogImpl();
   TDMSprInetCatalog * Object;
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

//IDMSprInetCatalog
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

   virtual TFIBLargeIntField * get_TableID_SINETCATALOG(void);
   virtual void set_TableID_SINETCATALOG(TFIBLargeIntField * TableID_SINETCATALOG);

   virtual TFIBLargeIntField * get_TableIDBASE_SINETCATALOG(void);
   virtual void set_TableIDBASE_SINETCATALOG(TFIBLargeIntField * TableIDBASE_SINETCATALOG);

   virtual TFIBWideStringField * get_TableGID_SINETCATALOG(void);
   virtual void set_TableGID_SINETCATALOG(TFIBWideStringField * TableGID_SINETCATALOG);

   virtual TFIBWideStringField * get_TableNAME_SINETCATALOG(void);
   virtual void set_TableNAME_SINETCATALOG(TFIBWideStringField * TableNAME_SINETCATALOG);

   virtual TFIBLargeIntField * get_ElementID_SINETCATALOG(void);
   virtual void set_ElementID_SINETCATALOG(TFIBLargeIntField * ElementID_SINETCATALOG);

   virtual TFIBLargeIntField * get_ElementIDBASE_SINETCATALOG(void);
   virtual void set_ElementIDBASE_SINETCATALOG(TFIBLargeIntField * ElementIDBASE_SINETCATALOG);

   virtual TFIBWideStringField * get_ElementGID_SINETCATALOG(void);
   virtual void set_ElementGID_SINETCATALOG(TFIBWideStringField * ElementGID_SINETCATALOG);

   virtual TFIBWideStringField * get_ElementNAME_SINETCATALOG(void);
   virtual void set_ElementNAME_SINETCATALOG(TFIBWideStringField * ElementNAME_SINETCATALOG);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 id );
   virtual bool NewElement(void);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual __int64 GetIdPoName(UnicodeString name);
   virtual int GetIndexElementaPoID(__int64 id);
};
#define CLSID_TDMSprInetCatalogImpl __uuidof(TDMSprInetCatalogImpl)
#endif
