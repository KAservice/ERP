#ifndef UDMSprNomInetCatalogImplH
#define UDMSprNomInetCatalogImplH
#include "IDMSprNomInetCatalog.h"
#include "UDMSprNomInetCatalog.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprNomInetCatalogImpl)) TDMSprNomInetCatalogImpl : public IDMSprNomInetCatalog
{
public:
   TDMSprNomInetCatalogImpl();
   ~TDMSprNomInetCatalogImpl();
   TDMSprNomInetCatalog * Object;
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

//IDMSprNomInetCatalog
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TFIBLargeIntField * get_TableID_SNOMINETCAT(void);
   virtual void set_TableID_SNOMINETCAT(TFIBLargeIntField * TableID_SNOMINETCAT);

   virtual TFIBLargeIntField * get_TableIDBASE_SNOMINETCAT(void);
   virtual void set_TableIDBASE_SNOMINETCAT(TFIBLargeIntField * TableIDBASE_SNOMINETCAT);

   virtual TFIBWideStringField * get_TableGID_SNOMINETCAT(void);
   virtual void set_TableGID_SNOMINETCAT(TFIBWideStringField * TableGID_SNOMINETCAT);

   virtual TFIBLargeIntField * get_TableIDINETCAT_SNOMINETCAT(void);
   virtual void set_TableIDINETCAT_SNOMINETCAT(TFIBLargeIntField * TableIDINETCAT_SNOMINETCAT);

   virtual TFIBLargeIntField * get_TableIDGRP_SNOMINETCAT(void);
   virtual void set_TableIDGRP_SNOMINETCAT(TFIBLargeIntField * TableIDGRP_SNOMINETCAT);

   virtual TFIBLargeIntField * get_TableIDNOM_SNOMINETCAT(void);
   virtual void set_TableIDNOM_SNOMINETCAT(TFIBLargeIntField * TableIDNOM_SNOMINETCAT);

   virtual TFIBWideStringField * get_TableNAMENOM(void);
   virtual void set_TableNAMENOM(TFIBWideStringField * TableNAMENOM);

   virtual TFIBBCDField * get_TableZNACH_PRICE(void);
   virtual void set_TableZNACH_PRICE(TFIBBCDField * TableZNACH_PRICE);

   virtual TFIBWideStringField * get_TableNAMEED(void);
   virtual void set_TableNAMEED(TFIBWideStringField * TableNAMEED);

   virtual TFIBLargeIntField * get_ElementID_SNOMINETCAT(void);
   virtual void set_ElementID_SNOMINETCAT(TFIBLargeIntField * ElementID_SNOMINETCAT);

   virtual TFIBLargeIntField * get_ElementIDBASE_SNOMINETCAT(void);
   virtual void set_ElementIDBASE_SNOMINETCAT(TFIBLargeIntField * ElementIDBASE_SNOMINETCAT);

   virtual TFIBWideStringField * get_ElementGID_SNOMINETCAT(void);
   virtual void set_ElementGID_SNOMINETCAT(TFIBWideStringField * ElementGID_SNOMINETCAT);

   virtual TFIBLargeIntField * get_ElementIDINETCAT_SNOMINETCAT(void);
   virtual void set_ElementIDINETCAT_SNOMINETCAT(TFIBLargeIntField * ElementIDINETCAT_SNOMINETCAT);

   virtual TFIBLargeIntField * get_ElementIDGRP_SNOMINETCAT(void);
   virtual void set_ElementIDGRP_SNOMINETCAT(TFIBLargeIntField * ElementIDGRP_SNOMINETCAT);

   virtual TFIBLargeIntField * get_ElementIDNOM_SNOMINETCAT(void);
   virtual void set_ElementIDNOM_SNOMINETCAT(TFIBLargeIntField * ElementIDNOM_SNOMINETCAT);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBIntegerField * get_TableCODENOM(void);
   virtual void set_TableCODENOM(TFIBIntegerField * TableCODENOM);

   virtual TFIBWideStringField * get_TableARTNOM(void);
   virtual void set_TableARTNOM(TFIBWideStringField * TableARTNOM);

   virtual TFIBWideStringField * get_TableSHED(void);
   virtual void set_TableSHED(TFIBWideStringField * TableSHED);

   virtual __int64 get_IdInetCatalog(void);
   virtual void set_IdInetCatalog(__int64 IdInetCatalog);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual __int64 get_IdTypePrice(void);
   virtual void set_IdTypePrice(__int64 IdTypePrice);

   virtual void OpenTable(__int64 id_inet_catalog, __int64 id_grp,bool all);
   virtual void NewElement(__int64 id_inet_catalog, __int64 id_grp);
   virtual bool OpenElement(__int64 id);
   virtual void InsertElement(__int64 id_inet_catalog, __int64 id_grp, __int64 id_nom);
   virtual void DeleteElement();
   virtual void SaveIsmen();
   virtual void CancelIsmen();
   virtual void ChancheGrp(__int64 id_new_grp);
   virtual bool FindPoInetCatalogAndNom(__int64 id_inet_catalog, __int64 id_nom);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
};
#define CLSID_TDMSprNomInetCatalogImpl __uuidof(TDMSprNomInetCatalogImpl)
#endif
