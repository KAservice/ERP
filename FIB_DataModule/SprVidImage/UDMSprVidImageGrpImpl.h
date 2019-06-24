#ifndef UDMSprVidImageGrpImplH
#define UDMSprVidImageGrpImplH
#include "IDMSprVidImageGrp.h"
#include "UDMSprVidImageGrp.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprVidImageGrpImpl)) TDMSprVidImageGrpImpl : public IDMSprVidImageGrp
{
public:
   TDMSprVidImageGrpImpl();
   ~TDMSprVidImageGrpImpl();
   TDMSprVidImageGrp * Object;
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

//IDMSprVidImageGrp
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

   virtual TFIBLargeIntField * get_TableID_SVIDIMAGE_GRP(void);
   virtual void set_TableID_SVIDIMAGE_GRP(TFIBLargeIntField * TableID_SVIDIMAGE_GRP);

   virtual TFIBLargeIntField * get_TableIDBASE_SVIDIMAGE_GRP(void);
   virtual void set_TableIDBASE_SVIDIMAGE_GRP(TFIBLargeIntField * TableIDBASE_SVIDIMAGE_GRP);

   virtual TFIBWideStringField * get_TableGID_SVIDIMAGE_GRP(void);
   virtual void set_TableGID_SVIDIMAGE_GRP(TFIBWideStringField * TableGID_SVIDIMAGE_GRP);

   virtual TFIBLargeIntField * get_TableIDGRP_SVIDIMAGE_GRP(void);
   virtual void set_TableIDGRP_SVIDIMAGE_GRP(TFIBLargeIntField * TableIDGRP_SVIDIMAGE_GRP);

   virtual TFIBWideStringField * get_TableNAME_SVIDIMAGE_GRP(void);
   virtual void set_TableNAME_SVIDIMAGE_GRP(TFIBWideStringField * TableNAME_SVIDIMAGE_GRP);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBLargeIntField * get_ElementID_SVIDIMAGE_GRP(void);
   virtual void set_ElementID_SVIDIMAGE_GRP(TFIBLargeIntField * ElementID_SVIDIMAGE_GRP);

   virtual TFIBLargeIntField * get_ElementIDBASE_SVIDIMAGE_GRP(void);
   virtual void set_ElementIDBASE_SVIDIMAGE_GRP(TFIBLargeIntField * ElementIDBASE_SVIDIMAGE_GRP);

   virtual TFIBWideStringField * get_ElementGID_SVIDIMAGE_GRP(void);
   virtual void set_ElementGID_SVIDIMAGE_GRP(TFIBWideStringField * ElementGID_SVIDIMAGE_GRP);

   virtual TFIBLargeIntField * get_ElementIDGRP_SVIDIMAGE_GRP(void);
   virtual void set_ElementIDGRP_SVIDIMAGE_GRP(TFIBLargeIntField * ElementIDGRP_SVIDIMAGE_GRP);

   virtual TFIBWideStringField * get_ElementNAME_SVIDIMAGE_GRP(void);
   virtual void set_ElementNAME_SVIDIMAGE_GRP(TFIBWideStringField * ElementNAME_SVIDIMAGE_GRP);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(__int64 id_grp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual __int64 FindPoName(UnicodeString name);
};
#define CLSID_TDMSprVidImageGrpImpl __uuidof(TDMSprVidImageGrpImpl)
#endif
