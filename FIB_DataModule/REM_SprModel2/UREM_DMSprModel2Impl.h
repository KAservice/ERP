#ifndef UREM_DMSprModel2ImplH
#define UREM_DMSprModel2ImplH
#include "IREM_DMSprModel2.h"
#include "UREM_DMSprModel2.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMSprModel2Impl)) TREM_DMSprModel2Impl : public IREM_DMSprModel2
{
public:
   TREM_DMSprModel2Impl();
   ~TREM_DMSprModel2Impl();
   TREM_DMSprModel2 * Object;
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

//IREM_DMSprModel2
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TDataSource * get_DataSourcePodr(void);
   virtual void set_DataSourcePodr(TDataSource * DataSourcePodr);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TFIBLargeIntField * get_TableID_REM_SMODEL2(void);
   virtual void set_TableID_REM_SMODEL2(TFIBLargeIntField * TableID_REM_SMODEL2);

   virtual TFIBWideStringField * get_TableGID_REM_SMODEL2(void);
   virtual void set_TableGID_REM_SMODEL2(TFIBWideStringField * TableGID_REM_SMODEL2);

   virtual TFIBLargeIntField * get_TableIDBASE_REM_SMODEL2(void);
   virtual void set_TableIDBASE_REM_SMODEL2(TFIBLargeIntField * TableIDBASE_REM_SMODEL2);

   virtual TFIBWideStringField * get_TableNAME_REM_SMODEL2(void);
   virtual void set_TableNAME_REM_SMODEL2(TFIBWideStringField * TableNAME_REM_SMODEL2);

   virtual TFIBLargeIntField * get_TableIDTYPEDEV_REM_SMODEL2(void);
   virtual void set_TableIDTYPEDEV_REM_SMODEL2(TFIBLargeIntField * TableIDTYPEDEV_REM_SMODEL2);

   virtual TFIBLargeIntField * get_TableIDMODEL_REM_SMODEL2(void);
   virtual void set_TableIDMODEL_REM_SMODEL2(TFIBLargeIntField * TableIDMODEL_REM_SMODEL2);

   virtual TFIBLargeIntField * get_TableIDGRP_REM_SMODEL2(void);
   virtual void set_TableIDGRP_REM_SMODEL2(TFIBLargeIntField * TableIDGRP_REM_SMODEL2);

   virtual TFIBWideStringField * get_TableSTRCODE_REM_SMODEL(void);
   virtual void set_TableSTRCODE_REM_SMODEL(TFIBWideStringField * TableSTRCODE_REM_SMODEL);

   virtual TFIBWideStringField * get_TableNAME_REM_SMODEL(void);
   virtual void set_TableNAME_REM_SMODEL(TFIBWideStringField * TableNAME_REM_SMODEL);

   virtual TFIBLargeIntField * get_ElementID_REM_SMODEL2(void);
   virtual void set_ElementID_REM_SMODEL2(TFIBLargeIntField * ElementID_REM_SMODEL2);

   virtual TFIBWideStringField * get_ElementGID_REM_SMODEL2(void);
   virtual void set_ElementGID_REM_SMODEL2(TFIBWideStringField * ElementGID_REM_SMODEL2);

   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SMODEL2(void);
   virtual void set_ElementIDBASE_REM_SMODEL2(TFIBLargeIntField * ElementIDBASE_REM_SMODEL2);

   virtual TFIBWideStringField * get_ElementNAME_REM_SMODEL2(void);
   virtual void set_ElementNAME_REM_SMODEL2(TFIBWideStringField * ElementNAME_REM_SMODEL2);

   virtual TFIBLargeIntField * get_ElementIDTYPEDEV_REM_SMODEL2(void);
   virtual void set_ElementIDTYPEDEV_REM_SMODEL2(TFIBLargeIntField * ElementIDTYPEDEV_REM_SMODEL2);

   virtual TFIBLargeIntField * get_ElementIDMODEL_REM_SMODEL2(void);
   virtual void set_ElementIDMODEL_REM_SMODEL2(TFIBLargeIntField * ElementIDMODEL_REM_SMODEL2);

   virtual TFIBLargeIntField * get_ElementIDGRP_REM_SMODEL2(void);
   virtual void set_ElementIDGRP_REM_SMODEL2(TFIBLargeIntField * ElementIDGRP_REM_SMODEL2);

   virtual TFIBWideStringField * get_ElementSTRCODE_REM_SMODEL(void);
   virtual void set_ElementSTRCODE_REM_SMODEL(TFIBWideStringField * ElementSTRCODE_REM_SMODEL);

   virtual TFIBWideStringField * get_ElementNAME_REM_SMODEL(void);
   virtual void set_ElementNAME_REM_SMODEL(TFIBWideStringField * ElementNAME_REM_SMODEL);

   virtual __int64 get_IdGroupElement(void);
   virtual void set_IdGroupElement(__int64 IdGroupElement);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual bool NewElement(__int64 id_group_element, __int64 id_grp);
   virtual bool InsertElement(__int64 id_group_element, __int64 id_grp, __int64 id_model);
   virtual bool OpenElement(__int64 id);
   virtual bool DeleteElement(__int64 id);
   virtual bool SaveElement(void);
   virtual bool ChancheGrp(__int64 id_new_grp,__int64 id_element);
   virtual bool OpenTable(__int64 id_group_element, __int64 id_grp, bool all);
   virtual bool TableSaveIsmen(void);
   virtual bool TableCancelIsmen(void);
   virtual bool TableNewElement(__int64 id_group_element, __int64 id_grp);
   virtual bool TableAppend(void);
   virtual bool TableDelete(void);
   virtual bool TableEdit(void);
   virtual bool TablePost(void);
};
#define CLSID_TREM_DMSprModel2Impl __uuidof(TREM_DMSprModel2Impl)
#endif
