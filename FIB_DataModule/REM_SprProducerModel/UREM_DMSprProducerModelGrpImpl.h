#ifndef UREM_DMSprProducerModelGrpImplH
#define UREM_DMSprProducerModelGrpImplH
#include "IREM_DMSprProducerModelGrp.h"
#include "UREM_DMSprProducerModelGrp.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMSprProducerModelGrpImpl)) TREM_DMSprProducerModelGrpImpl : public IREM_DMSprProducerModelGrp
{
public:
   TREM_DMSprProducerModelGrpImpl();
   ~TREM_DMSprProducerModelGrpImpl();
   TREM_DMSprProducerModelGrp * Object;
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

//IREM_DMSprProducerModelGrp
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

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBLargeIntField * get_TableID_REM_SPRMODEL_GRP(void);
   virtual void set_TableID_REM_SPRMODEL_GRP(TFIBLargeIntField * TableID_REM_SPRMODEL_GRP);

   virtual TFIBLargeIntField * get_TableIDBASE_REM_SPRMODEL_GRP(void);
   virtual void set_TableIDBASE_REM_SPRMODEL_GRP(TFIBLargeIntField * TableIDBASE_REM_SPRMODEL_GRP);

   virtual TFIBWideStringField * get_TableGID_REM_SPRMODEL_GRP(void);
   virtual void set_TableGID_REM_SPRMODEL_GRP(TFIBWideStringField * TableGID_REM_SPRMODEL_GRP);

   virtual TFIBLargeIntField * get_TableIDPR_REM_SPRMODEL_GRP(void);
   virtual void set_TableIDPR_REM_SPRMODEL_GRP(TFIBLargeIntField * TableIDPR_REM_SPRMODEL_GRP);

   virtual TFIBLargeIntField * get_TableIDGRP_REM_SPRMODEL_GRP(void);
   virtual void set_TableIDGRP_REM_SPRMODEL_GRP(TFIBLargeIntField * TableIDGRP_REM_SPRMODEL_GRP);

   virtual TFIBWideStringField * get_TableNAME_REM_SPRMODEL_GRP(void);
   virtual void set_TableNAME_REM_SPRMODEL_GRP(TFIBWideStringField * TableNAME_REM_SPRMODEL_GRP);

   virtual TFIBLargeIntField * get_ElementID_REM_SPRMODEL_GRP(void);
   virtual void set_ElementID_REM_SPRMODEL_GRP(TFIBLargeIntField * ElementID_REM_SPRMODEL_GRP);

   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SPRMODEL_GRP(void);
   virtual void set_ElementIDBASE_REM_SPRMODEL_GRP(TFIBLargeIntField * ElementIDBASE_REM_SPRMODEL_GRP);

   virtual TFIBWideStringField * get_ElementGID_REM_SPRMODEL_GRP(void);
   virtual void set_ElementGID_REM_SPRMODEL_GRP(TFIBWideStringField * ElementGID_REM_SPRMODEL_GRP);

   virtual TFIBLargeIntField * get_ElementIDPR_REM_SPRMODEL_GRP(void);
   virtual void set_ElementIDPR_REM_SPRMODEL_GRP(TFIBLargeIntField * ElementIDPR_REM_SPRMODEL_GRP);

   virtual TFIBLargeIntField * get_ElementIDGRP_REM_SPRMODEL_GRP(void);
   virtual void set_ElementIDGRP_REM_SPRMODEL_GRP(TFIBLargeIntField * ElementIDGRP_REM_SPRMODEL_GRP);

   virtual TFIBWideStringField * get_ElementNAME_REM_SPRMODEL_GRP(void);
   virtual void set_ElementNAME_REM_SPRMODEL_GRP(TFIBWideStringField * ElementNAME_REM_SPRMODEL_GRP);

   virtual __int64 get_IdGroupElement(void);
   virtual void set_IdGroupElement(__int64 IdGroupElement);

   virtual void OpenTable(__int64 id_group_element);
   virtual int OpenElement(__int64 id);
   virtual bool NewElement(__int64 id_group_element, __int64 id_grp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
};
#define CLSID_TREM_DMSprProducerModelGrpImpl __uuidof(TREM_DMSprProducerModelGrpImpl)
#endif
