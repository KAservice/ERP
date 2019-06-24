#ifndef UDMObjectBasePrivImplH
#define UDMObjectBasePrivImplH
#include "IDMObjectBasePriv.h"
#include "UDMObjectBasePriv.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMObjectBasePrivImpl)) TDMObjectBasePrivImpl : public IDMObjectBasePriv
{
public:
   TDMObjectBasePrivImpl();
   ~TDMObjectBasePrivImpl();
   TDMObjectBasePriv * Object;
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

//IDMObjectBasePriv
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

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBLargeIntField * get_TableID_OBJECT_BASE_PRIV(void);
   virtual void set_TableID_OBJECT_BASE_PRIV(TFIBLargeIntField * TableID_OBJECT_BASE_PRIV);

   virtual TFIBLargeIntField * get_TableIDBASE_OBJECT_BASE_PRIV(void);
   virtual void set_TableIDBASE_OBJECT_BASE_PRIV(TFIBLargeIntField * TableIDBASE_OBJECT_BASE_PRIV);

   virtual TFIBLargeIntField * get_TableIDGRPUSER_OBJECT_BASE_PRIV(void);
   virtual void set_TableIDGRPUSER_OBJECT_BASE_PRIV(TFIBLargeIntField * TableIDGRPUSER_OBJECT_BASE_PRIV);

   virtual TFIBSmallIntField * get_TableINS_OBJECT_BASE_PRIV(void);
   virtual void set_TableINS_OBJECT_BASE_PRIV(TFIBSmallIntField * TableINS_OBJECT_BASE_PRIV);

   virtual TFIBSmallIntField * get_TableEDIT_OBJECT_BASE_PRIV(void);
   virtual void set_TableEDIT_OBJECT_BASE_PRIV(TFIBSmallIntField * TableEDIT_OBJECT_BASE_PRIV);

   virtual TFIBSmallIntField * get_TableDEL_OBJECT_BASE_PRIV(void);
   virtual void set_TableDEL_OBJECT_BASE_PRIV(TFIBSmallIntField * TableDEL_OBJECT_BASE_PRIV);

   virtual TFIBSmallIntField * get_TableEXEC_OBJECT_BASE_PRIV(void);
   virtual void set_TableEXEC_OBJECT_BASE_PRIV(TFIBSmallIntField * TableEXEC_OBJECT_BASE_PRIV);

   virtual TFIBIntegerField * get_TableNUMBER_OBJECT_BASE_PRIV(void);
   virtual void set_TableNUMBER_OBJECT_BASE_PRIV(TFIBIntegerField * TableNUMBER_OBJECT_BASE_PRIV);

   virtual TFIBLargeIntField * get_TableIDGRP_OBJECT_BASE_PRIV(void);
   virtual void set_TableIDGRP_OBJECT_BASE_PRIV(TFIBLargeIntField * TableIDGRP_OBJECT_BASE_PRIV);

   virtual TFIBLargeIntField * get_ElementID_OBJECT_BASE_PRIV(void);
   virtual void set_ElementID_OBJECT_BASE_PRIV(TFIBLargeIntField * ElementID_OBJECT_BASE_PRIV);

   virtual TFIBLargeIntField * get_ElementIDBASE_OBJECT_BASE_PRIV(void);
   virtual void set_ElementIDBASE_OBJECT_BASE_PRIV(TFIBLargeIntField * ElementIDBASE_OBJECT_BASE_PRIV);

   virtual TFIBLargeIntField * get_ElementIDEXT_DOUT_OBJECT_BASE_PRIV(void);
   virtual void set_ElementIDEXT_DOUT_OBJECT_BASE_PRIV(TFIBLargeIntField * ElementIDEXT_DOUT_OBJECT_BASE_PRIV);

   virtual TFIBLargeIntField * get_ElementIDEXT_BASE_OBJECT_BASE_PRIV(void);
   virtual void set_ElementIDEXT_BASE_OBJECT_BASE_PRIV(TFIBLargeIntField * ElementIDEXT_BASE_OBJECT_BASE_PRIV);

   virtual TFIBLargeIntField * get_ElementIDGRPUSER_OBJECT_BASE_PRIV(void);
   virtual void set_ElementIDGRPUSER_OBJECT_BASE_PRIV(TFIBLargeIntField * ElementIDGRPUSER_OBJECT_BASE_PRIV);

   virtual TFIBSmallIntField * get_ElementINS_OBJECT_BASE_PRIV(void);
   virtual void set_ElementINS_OBJECT_BASE_PRIV(TFIBSmallIntField * ElementINS_OBJECT_BASE_PRIV);

   virtual TFIBSmallIntField * get_ElementEDIT_OBJECT_BASE_PRIV(void);
   virtual void set_ElementEDIT_OBJECT_BASE_PRIV(TFIBSmallIntField * ElementEDIT_OBJECT_BASE_PRIV);

   virtual TFIBSmallIntField * get_ElementDEL_OBJECT_BASE_PRIV(void);
   virtual void set_ElementDEL_OBJECT_BASE_PRIV(TFIBSmallIntField * ElementDEL_OBJECT_BASE_PRIV);

   virtual TFIBSmallIntField * get_ElementEXEC_OBJECT_BASE_PRIV(void);
   virtual void set_ElementEXEC_OBJECT_BASE_PRIV(TFIBSmallIntField * ElementEXEC_OBJECT_BASE_PRIV);

   virtual TFIBIntegerField * get_ElementNUMBER_OBJECT_BASE_PRIV(void);
   virtual void set_ElementNUMBER_OBJECT_BASE_PRIV(TFIBIntegerField * ElementNUMBER_OBJECT_BASE_PRIV);

   virtual TFIBLargeIntField * get_ElementIDGRP_OBJECT_BASE_PRIV(void);
   virtual void set_ElementIDGRP_OBJECT_BASE_PRIV(TFIBLargeIntField * ElementIDGRP_OBJECT_BASE_PRIV);

   virtual TFIBIntegerField * get_TableAPPLICATION_OBJECT_BASE_PRIV(void);
   virtual void set_TableAPPLICATION_OBJECT_BASE_PRIV(TFIBIntegerField * TableAPPLICATION_OBJECT_BASE_PRIV);

   virtual TFIBIntegerField * get_ElementAPPLICATION_OBJECT_BASE_PRIV(void);
   virtual void set_ElementAPPLICATION_OBJECT_BASE_PRIV(TFIBIntegerField * ElementAPPLICATION_OBJECT_BASE_PRIV);

   virtual TpFIBQuery * get_Query(void);
   virtual void set_Query(TpFIBQuery * Query);

   virtual TFIBWideStringField * get_ElementGUID_OBJECT_BASE_PRIV(void);
   virtual void set_ElementGUID_OBJECT_BASE_PRIV(TFIBWideStringField * ElementGUID_OBJECT_BASE_PRIV);

   virtual TFIBWideStringField * get_TableGUID_OBJECT_BASE_PRIV(void);
   virtual void set_TableGUID_OBJECT_BASE_PRIV(TFIBWideStringField * TableGUID_OBJECT_BASE_PRIV);

   virtual TFIBWideStringField * get_TableNAME_PROGRAM_MODULE(void);
   virtual void set_TableNAME_PROGRAM_MODULE(TFIBWideStringField * TableNAME_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_TablePROGID_PROGRAM_MODULE(void);
   virtual void set_TablePROGID_PROGRAM_MODULE(TFIBWideStringField * TablePROGID_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_TablePATCH_PROGRAM_MODULE(void);
   virtual void set_TablePATCH_PROGRAM_MODULE(TFIBWideStringField * TablePATCH_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_ElementNAME_PROGRAM_MODULE(void);
   virtual void set_ElementNAME_PROGRAM_MODULE(TFIBWideStringField * ElementNAME_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_ElementPROGID_PROGRAM_MODULE(void);
   virtual void set_ElementPROGID_PROGRAM_MODULE(TFIBWideStringField * ElementPROGID_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_ElementPATCH_PROGRAM_MODULE(void);
   virtual void set_ElementPATCH_PROGRAM_MODULE(TFIBWideStringField * ElementPATCH_PROGRAM_MODULE);

   virtual __int64 get_IdGrpUser(void);
   virtual void set_IdGrpUser(__int64 IdGrpUser);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual int get_NumApplication(void);
   virtual void set_NumApplication(int NumApplication);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual void OpenTable(int application, __int64 id_grp_user, __int64 id_grp, bool all);
   virtual bool SaveIsmen();
   virtual void CancelIsmen();
   virtual bool Table_Delete(void);
   virtual bool Table_AppendString(int application, __int64 id_grp_user, __int64 id_grp);
   virtual bool NewElement(int application, __int64 id_grp_user, __int64 id_grp);
   virtual bool OpenElement(__int64 id);
   virtual bool DeleteElement(__int64 id);
   virtual bool InsertElement(int application, __int64 id_grp_user, __int64 id_grp);
   virtual void Element_Edit(void);
   virtual void Element_Post(void);
   virtual bool SaveElement(void);
   virtual void ChancheGrp(__int64 id_new_grp);
   virtual bool GetPrivDM(int application, __int64 id_grp_user, int object);
   virtual bool GetPrivForm(__int64 id_grp_user, int object);
};
#define CLSID_TDMObjectBasePrivImpl __uuidof(TDMObjectBasePrivImpl)
#endif
