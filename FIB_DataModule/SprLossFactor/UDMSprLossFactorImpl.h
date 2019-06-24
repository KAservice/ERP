#ifndef UDMSprLossFactorImplH
#define UDMSprLossFactorImplH
#include "IDMSprLossFactor.h"
#include "UDMSprLossFactor.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprLossFactorImpl)) TDMSprLossFactorImpl : public IDMSprLossFactor
{
public:
   TDMSprLossFactorImpl();
   ~TDMSprLossFactorImpl();
   TDMSprLossFactor * Object;
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

//IDMSprLossFactor
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

   virtual TFIBLargeIntField * get_TableID_SLOSS_FACTOR(void);
   virtual void set_TableID_SLOSS_FACTOR(TFIBLargeIntField * TableID_SLOSS_FACTOR);

   virtual TFIBWideStringField * get_TableGID_SLOSS_FACTOR(void);
   virtual void set_TableGID_SLOSS_FACTOR(TFIBWideStringField * TableGID_SLOSS_FACTOR);

   virtual TFIBLargeIntField * get_TableIDBASE_SLOSS_FACTOR(void);
   virtual void set_TableIDBASE_SLOSS_FACTOR(TFIBLargeIntField * TableIDBASE_SLOSS_FACTOR);

   virtual TFIBWideStringField * get_TableNAME_SLOSS_FACTOR(void);
   virtual void set_TableNAME_SLOSS_FACTOR(TFIBWideStringField * TableNAME_SLOSS_FACTOR);

   virtual TFIBWideStringField * get_TableCOMMENT_SLOSS_FACTOR(void);
   virtual void set_TableCOMMENT_SLOSS_FACTOR(TFIBWideStringField * TableCOMMENT_SLOSS_FACTOR);

   virtual TFIBBCDField * get_TableENCEN_SLOSS_FACTOR(void);
   virtual void set_TableENCEN_SLOSS_FACTOR(TFIBBCDField * TableENCEN_SLOSS_FACTOR);

   virtual TFIBBCDField * get_TableBELKI_SLOSS_FACTOR(void);
   virtual void set_TableBELKI_SLOSS_FACTOR(TFIBBCDField * TableBELKI_SLOSS_FACTOR);

   virtual TFIBBCDField * get_TableGIRI_SLOSS_FACTOR(void);
   virtual void set_TableGIRI_SLOSS_FACTOR(TFIBBCDField * TableGIRI_SLOSS_FACTOR);

   virtual TFIBBCDField * get_TableUGL_SLOSS_FACTOR(void);
   virtual void set_TableUGL_SLOSS_FACTOR(TFIBBCDField * TableUGL_SLOSS_FACTOR);

   virtual TFIBWideStringField * get_TableCODE_SLOSS_FACTOR(void);
   virtual void set_TableCODE_SLOSS_FACTOR(TFIBWideStringField * TableCODE_SLOSS_FACTOR);

   virtual TFIBLargeIntField * get_TableIDGRP_SLOSS_FACTOR(void);
   virtual void set_TableIDGRP_SLOSS_FACTOR(TFIBLargeIntField * TableIDGRP_SLOSS_FACTOR);

   virtual TFIBLargeIntField * get_ElementID_SLOSS_FACTOR(void);
   virtual void set_ElementID_SLOSS_FACTOR(TFIBLargeIntField * ElementID_SLOSS_FACTOR);

   virtual TFIBWideStringField * get_ElementGID_SLOSS_FACTOR(void);
   virtual void set_ElementGID_SLOSS_FACTOR(TFIBWideStringField * ElementGID_SLOSS_FACTOR);

   virtual TFIBLargeIntField * get_ElementIDBASE_SLOSS_FACTOR(void);
   virtual void set_ElementIDBASE_SLOSS_FACTOR(TFIBLargeIntField * ElementIDBASE_SLOSS_FACTOR);

   virtual TFIBWideStringField * get_ElementNAME_SLOSS_FACTOR(void);
   virtual void set_ElementNAME_SLOSS_FACTOR(TFIBWideStringField * ElementNAME_SLOSS_FACTOR);

   virtual TFIBWideStringField * get_ElementCOMMENT_SLOSS_FACTOR(void);
   virtual void set_ElementCOMMENT_SLOSS_FACTOR(TFIBWideStringField * ElementCOMMENT_SLOSS_FACTOR);

   virtual TFIBBCDField * get_ElementENCEN_SLOSS_FACTOR(void);
   virtual void set_ElementENCEN_SLOSS_FACTOR(TFIBBCDField * ElementENCEN_SLOSS_FACTOR);

   virtual TFIBBCDField * get_ElementBELKI_SLOSS_FACTOR(void);
   virtual void set_ElementBELKI_SLOSS_FACTOR(TFIBBCDField * ElementBELKI_SLOSS_FACTOR);

   virtual TFIBBCDField * get_ElementGIRI_SLOSS_FACTOR(void);
   virtual void set_ElementGIRI_SLOSS_FACTOR(TFIBBCDField * ElementGIRI_SLOSS_FACTOR);

   virtual TFIBBCDField * get_ElementUGL_SLOSS_FACTOR(void);
   virtual void set_ElementUGL_SLOSS_FACTOR(TFIBBCDField * ElementUGL_SLOSS_FACTOR);

   virtual TFIBWideStringField * get_ElementCODE_SLOSS_FACTOR(void);
   virtual void set_ElementCODE_SLOSS_FACTOR(TFIBWideStringField * ElementCODE_SLOSS_FACTOR);

   virtual TFIBLargeIntField * get_ElementIDGRP_SLOSS_FACTOR(void);
   virtual void set_ElementIDGRP_SLOSS_FACTOR(TFIBLargeIntField * ElementIDGRP_SLOSS_FACTOR);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual bool OpenTable(__int64 id_grp, bool all);
   virtual UnicodeString GetTextQuery(__int64 id_grp, bool all);
   virtual bool OpenElement(__int64 id );
   virtual bool NewElement(__int64 id_grp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual bool ChancheGrp(__int64 id_new_grp,__int64 id_el);
   virtual __int64 FindPoName(UnicodeString name);
   virtual __int64 GetIDElement(UnicodeString gid);
   virtual UnicodeString GetGIDElement(__int64 id);
   virtual __int64 GetIdGrp(__int64 id_el);
};
#define CLSID_TDMSprLossFactorImpl __uuidof(TDMSprLossFactorImpl)
#endif
