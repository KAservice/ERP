#ifndef UDMSprProduceImplH
#define UDMSprProduceImplH
#include "IDMSprProduce.h"
#include "UDMSprProduce.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprProduceImpl)) TDMSprProduceImpl : public IDMSprProduce
{
public:
   TDMSprProduceImpl();
   ~TDMSprProduceImpl();
   TDMSprProduce * Object;
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

//IDMSprProduce
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

   virtual TFIBLargeIntField * get_ElementID_SPRODUCE(void);
   virtual void set_ElementID_SPRODUCE(TFIBLargeIntField * ElementID_SPRODUCE);

   virtual TFIBWideStringField * get_ElementGID_SPRODUCE(void);
   virtual void set_ElementGID_SPRODUCE(TFIBWideStringField * ElementGID_SPRODUCE);

   virtual TFIBLargeIntField * get_ElementIDBASE_SPRODUCE(void);
   virtual void set_ElementIDBASE_SPRODUCE(TFIBLargeIntField * ElementIDBASE_SPRODUCE);

   virtual TFIBLargeIntField * get_ElementIDGRP_SPRODUCE(void);
   virtual void set_ElementIDGRP_SPRODUCE(TFIBLargeIntField * ElementIDGRP_SPRODUCE);

   virtual TFIBWideStringField * get_ElementNAME_SPRODUCE(void);
   virtual void set_ElementNAME_SPRODUCE(TFIBWideStringField * ElementNAME_SPRODUCE);

   virtual TFIBWideStringField * get_ElementCODE_SPRODUCE(void);
   virtual void set_ElementCODE_SPRODUCE(TFIBWideStringField * ElementCODE_SPRODUCE);

   virtual TFIBBCDField * get_ElementBELKI_SPRODUCE(void);
   virtual void set_ElementBELKI_SPRODUCE(TFIBBCDField * ElementBELKI_SPRODUCE);

   virtual TFIBBCDField * get_ElementGIRI_SPRODUCE(void);
   virtual void set_ElementGIRI_SPRODUCE(TFIBBCDField * ElementGIRI_SPRODUCE);

   virtual TFIBBCDField * get_ElementUGL_SPRODUCE(void);
   virtual void set_ElementUGL_SPRODUCE(TFIBBCDField * ElementUGL_SPRODUCE);

   virtual TFIBWideStringField * get_ElementCOMMENT_SPRODUCE(void);
   virtual void set_ElementCOMMENT_SPRODUCE(TFIBWideStringField * ElementCOMMENT_SPRODUCE);

   virtual TFIBLargeIntField * get_TableID_SPRODUCE(void);
   virtual void set_TableID_SPRODUCE(TFIBLargeIntField * TableID_SPRODUCE);

   virtual TFIBWideStringField * get_TableGID_SPRODUCE(void);
   virtual void set_TableGID_SPRODUCE(TFIBWideStringField * TableGID_SPRODUCE);

   virtual TFIBLargeIntField * get_TableIDBASE_SPRODUCE(void);
   virtual void set_TableIDBASE_SPRODUCE(TFIBLargeIntField * TableIDBASE_SPRODUCE);

   virtual TFIBLargeIntField * get_TableIDGRP_SPRODUCE(void);
   virtual void set_TableIDGRP_SPRODUCE(TFIBLargeIntField * TableIDGRP_SPRODUCE);

   virtual TFIBWideStringField * get_TableNAME_SPRODUCE(void);
   virtual void set_TableNAME_SPRODUCE(TFIBWideStringField * TableNAME_SPRODUCE);

   virtual TFIBWideStringField * get_TableCODE_SPRODUCE(void);
   virtual void set_TableCODE_SPRODUCE(TFIBWideStringField * TableCODE_SPRODUCE);

   virtual TFIBBCDField * get_TableBELKI_SPRODUCE(void);
   virtual void set_TableBELKI_SPRODUCE(TFIBBCDField * TableBELKI_SPRODUCE);

   virtual TFIBBCDField * get_TableGIRI_SPRODUCE(void);
   virtual void set_TableGIRI_SPRODUCE(TFIBBCDField * TableGIRI_SPRODUCE);

   virtual TFIBBCDField * get_TableUGL_SPRODUCE(void);
   virtual void set_TableUGL_SPRODUCE(TFIBBCDField * TableUGL_SPRODUCE);

   virtual TFIBWideStringField * get_TableCOMMENT_SPRODUCE(void);
   virtual void set_TableCOMMENT_SPRODUCE(TFIBWideStringField * TableCOMMENT_SPRODUCE);

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
#define CLSID_TDMSprProduceImpl __uuidof(TDMSprProduceImpl)
#endif
