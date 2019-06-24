#ifndef UDMSprPropertiesGrpImplH
#define UDMSprPropertiesGrpImplH
#include "IDMSprPropertiesGrp.h"
#include "UDMSprPropertiesGrp.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprPropertiesGrpImpl)) TDMSprPropertiesGrpImpl : public IDMSprPropertiesGrp
{
public:
   TDMSprPropertiesGrpImpl();
   ~TDMSprPropertiesGrpImpl();
   TDMSprPropertiesGrp * Object;
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

//IDMSprPropertiesGrp
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

   virtual TFIBLargeIntField * get_TableID_SPROP_GRP(void);
   virtual void set_TableID_SPROP_GRP(TFIBLargeIntField * TableID_SPROP_GRP);

   virtual TFIBLargeIntField * get_TableIDBASE_SPROP_GRP(void);
   virtual void set_TableIDBASE_SPROP_GRP(TFIBLargeIntField * TableIDBASE_SPROP_GRP);

   virtual TFIBWideStringField * get_TableGID_SPROP_GRP(void);
   virtual void set_TableGID_SPROP_GRP(TFIBWideStringField * TableGID_SPROP_GRP);

   virtual TFIBLargeIntField * get_TableIDGRP_SPROP_GRP(void);
   virtual void set_TableIDGRP_SPROP_GRP(TFIBLargeIntField * TableIDGRP_SPROP_GRP);

   virtual TFIBWideStringField * get_TableNAME_SPROP_GRP(void);
   virtual void set_TableNAME_SPROP_GRP(TFIBWideStringField * TableNAME_SPROP_GRP);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBLargeIntField * get_ElementID_SPROP_GRP(void);
   virtual void set_ElementID_SPROP_GRP(TFIBLargeIntField * ElementID_SPROP_GRP);

   virtual TFIBLargeIntField * get_ElementIDBASE_SPROP_GRP(void);
   virtual void set_ElementIDBASE_SPROP_GRP(TFIBLargeIntField * ElementIDBASE_SPROP_GRP);

   virtual TFIBWideStringField * get_ElementGID_SPROP_GRP(void);
   virtual void set_ElementGID_SPROP_GRP(TFIBWideStringField * ElementGID_SPROP_GRP);

   virtual TFIBLargeIntField * get_ElementIDGRP_SPROP_GRP(void);
   virtual void set_ElementIDGRP_SPROP_GRP(TFIBLargeIntField * ElementIDGRP_SPROP_GRP);

   virtual TFIBWideStringField * get_ElementNAME_SPROP_GRP(void);
   virtual void set_ElementNAME_SPROP_GRP(TFIBWideStringField * ElementNAME_SPROP_GRP);

   virtual TFIBWideStringField * get_ElementNAME_FOR_PRINT_SPROP_GRP(void);
   virtual void set_ElementNAME_FOR_PRINT_SPROP_GRP(TFIBWideStringField * ElementNAME_FOR_PRINT_SPROP_GRP);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(__int64 id_grp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual __int64 FindPoName(UnicodeString name);
};
#define CLSID_TDMSprPropertiesGrpImpl __uuidof(TDMSprPropertiesGrpImpl)
#endif
