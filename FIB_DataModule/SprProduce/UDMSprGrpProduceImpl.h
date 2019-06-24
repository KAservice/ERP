#ifndef UDMSprGrpProduceImplH
#define UDMSprGrpProduceImplH
#include "IDMSprGrpProduce.h"
#include "UDMSprGrpProduce.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprGrpProduceImpl)) TDMSprGrpProduceImpl : public IDMSprGrpProduce
{
public:
   TDMSprGrpProduceImpl();
   ~TDMSprGrpProduceImpl();
   TDMSprGrpProduce * Object;
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

//IDMSprGrpProduce
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

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBLargeIntField * get_TableID_SPRODUCE_GRP(void);
   virtual void set_TableID_SPRODUCE_GRP(TFIBLargeIntField * TableID_SPRODUCE_GRP);

   virtual TFIBWideStringField * get_TableGID_SPRODUCE_GRP(void);
   virtual void set_TableGID_SPRODUCE_GRP(TFIBWideStringField * TableGID_SPRODUCE_GRP);

   virtual TFIBLargeIntField * get_TableIDBASE_SPRODUCE_GRP(void);
   virtual void set_TableIDBASE_SPRODUCE_GRP(TFIBLargeIntField * TableIDBASE_SPRODUCE_GRP);

   virtual TFIBWideStringField * get_TableNAME_SPRODUCE_GRP(void);
   virtual void set_TableNAME_SPRODUCE_GRP(TFIBWideStringField * TableNAME_SPRODUCE_GRP);

   virtual TFIBLargeIntField * get_TableIDGRP_SPRODUCE_GRP(void);
   virtual void set_TableIDGRP_SPRODUCE_GRP(TFIBLargeIntField * TableIDGRP_SPRODUCE_GRP);

   virtual TFIBLargeIntField * get_ElementID_SPRODUCE_GRP(void);
   virtual void set_ElementID_SPRODUCE_GRP(TFIBLargeIntField * ElementID_SPRODUCE_GRP);

   virtual TFIBWideStringField * get_ElementGID_SPRODUCE_GRP(void);
   virtual void set_ElementGID_SPRODUCE_GRP(TFIBWideStringField * ElementGID_SPRODUCE_GRP);

   virtual TFIBLargeIntField * get_ElementIDBASE_SPRODUCE_GRP(void);
   virtual void set_ElementIDBASE_SPRODUCE_GRP(TFIBLargeIntField * ElementIDBASE_SPRODUCE_GRP);

   virtual TFIBWideStringField * get_ElementNAME_SPRODUCE_GRP(void);
   virtual void set_ElementNAME_SPRODUCE_GRP(TFIBWideStringField * ElementNAME_SPRODUCE_GRP);

   virtual TFIBLargeIntField * get_ElementIDGRP_SPRODUCE_GRP(void);
   virtual void set_ElementIDGRP_SPRODUCE_GRP(TFIBLargeIntField * ElementIDGRP_SPRODUCE_GRP);

   virtual bool OpenTable(void);
   virtual bool OpenElement(__int64 id);
   virtual bool NewElement(__int64 id_grp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual __int64 GetIDElement(UnicodeString gid);
   virtual UnicodeString GetGIDElement(__int64 id);
   virtual __int64 FindPoName(UnicodeString name);
};
#define CLSID_TDMSprGrpProduceImpl __uuidof(TDMSprGrpProduceImpl)
#endif
