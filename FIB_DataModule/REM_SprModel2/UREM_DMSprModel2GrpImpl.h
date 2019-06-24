#ifndef UREM_DMSprModel2GrpImplH
#define UREM_DMSprModel2GrpImplH
#include "IREM_DMSprModel2Grp.h"
#include "UREM_DMSprModel2Grp.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMSprModel2GrpImpl)) TREM_DMSprModel2GrpImpl : public IREM_DMSprModel2Grp
{
public:
   TREM_DMSprModel2GrpImpl();
   ~TREM_DMSprModel2GrpImpl();
   TREM_DMSprModel2Grp * Object;
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

//IREM_DMSprModel2Grp
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

   virtual TFIBLargeIntField * get_TableID_REM_SMODEL2_GRP(void);
   virtual void set_TableID_REM_SMODEL2_GRP(TFIBLargeIntField * TableID_REM_SMODEL2_GRP);

   virtual TFIBWideStringField * get_TableGID_REM_SMODEL2_GRP(void);
   virtual void set_TableGID_REM_SMODEL2_GRP(TFIBWideStringField * TableGID_REM_SMODEL2_GRP);

   virtual TFIBLargeIntField * get_TableIDBASE_REM_SMODEL2_GRP(void);
   virtual void set_TableIDBASE_REM_SMODEL2_GRP(TFIBLargeIntField * TableIDBASE_REM_SMODEL2_GRP);

   virtual TFIBLargeIntField * get_TableIDGRP_REM_SMODEL2_GRP(void);
   virtual void set_TableIDGRP_REM_SMODEL2_GRP(TFIBLargeIntField * TableIDGRP_REM_SMODEL2_GRP);

   virtual TFIBWideStringField * get_TableNAME_REM_SMODEL2_GRP(void);
   virtual void set_TableNAME_REM_SMODEL2_GRP(TFIBWideStringField * TableNAME_REM_SMODEL2_GRP);

   virtual TFIBLargeIntField * get_TableIDTYPEDEV_REM_SMODEL2_GRP(void);
   virtual void set_TableIDTYPEDEV_REM_SMODEL2_GRP(TFIBLargeIntField * TableIDTYPEDEV_REM_SMODEL2_GRP);

   virtual TFIBLargeIntField * get_ElementID_REM_SMODEL2_GRP(void);
   virtual void set_ElementID_REM_SMODEL2_GRP(TFIBLargeIntField * ElementID_REM_SMODEL2_GRP);

   virtual TFIBWideStringField * get_ElementGID_REM_SMODEL2_GRP(void);
   virtual void set_ElementGID_REM_SMODEL2_GRP(TFIBWideStringField * ElementGID_REM_SMODEL2_GRP);

   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SMODEL2_GRP(void);
   virtual void set_ElementIDBASE_REM_SMODEL2_GRP(TFIBLargeIntField * ElementIDBASE_REM_SMODEL2_GRP);

   virtual TFIBLargeIntField * get_ElementIDGRP_REM_SMODEL2_GRP(void);
   virtual void set_ElementIDGRP_REM_SMODEL2_GRP(TFIBLargeIntField * ElementIDGRP_REM_SMODEL2_GRP);

   virtual TFIBWideStringField * get_ElementNAME_REM_SMODEL2_GRP(void);
   virtual void set_ElementNAME_REM_SMODEL2_GRP(TFIBWideStringField * ElementNAME_REM_SMODEL2_GRP);

   virtual TFIBLargeIntField * get_ElementIDTYPEDEV_REM_SMODEL2_GRP(void);
   virtual void set_ElementIDTYPEDEV_REM_SMODEL2_GRP(TFIBLargeIntField * ElementIDTYPEDEV_REM_SMODEL2_GRP);

   virtual __int64 get_IdGroupElement(void);
   virtual void set_IdGroupElement(__int64 IdGroupElement);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual bool OpenTable(__int64 id_group_element);
   virtual bool OpenElement(__int64 id);
   virtual bool NewElement(__int64 id_group_element, __int64 id_grp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
};
#define CLSID_TREM_DMSprModel2GrpImpl __uuidof(TREM_DMSprModel2GrpImpl)
#endif
