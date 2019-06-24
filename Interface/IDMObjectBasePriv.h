#ifndef UIDMObjectBasePrivH
#define UIDMObjectBasePrivH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMObjectBasePriv)) IDMObjectBasePriv : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBLargeIntField * TableID_OBJECT_BASE_PRIV = {read = get_TableID_OBJECT_BASE_PRIV , write = set_TableID_OBJECT_BASE_PRIV};
   virtual TFIBLargeIntField * get_TableID_OBJECT_BASE_PRIV(void)=0;
   virtual void set_TableID_OBJECT_BASE_PRIV(TFIBLargeIntField * TableID_OBJECT_BASE_PRIV)=0;

   __property TFIBLargeIntField * TableIDBASE_OBJECT_BASE_PRIV = {read = get_TableIDBASE_OBJECT_BASE_PRIV , write = set_TableIDBASE_OBJECT_BASE_PRIV};
   virtual TFIBLargeIntField * get_TableIDBASE_OBJECT_BASE_PRIV(void)=0;
   virtual void set_TableIDBASE_OBJECT_BASE_PRIV(TFIBLargeIntField * TableIDBASE_OBJECT_BASE_PRIV)=0;

   __property TFIBLargeIntField * TableIDGRPUSER_OBJECT_BASE_PRIV = {read = get_TableIDGRPUSER_OBJECT_BASE_PRIV , write = set_TableIDGRPUSER_OBJECT_BASE_PRIV};
   virtual TFIBLargeIntField * get_TableIDGRPUSER_OBJECT_BASE_PRIV(void)=0;
   virtual void set_TableIDGRPUSER_OBJECT_BASE_PRIV(TFIBLargeIntField * TableIDGRPUSER_OBJECT_BASE_PRIV)=0;

   __property TFIBSmallIntField * TableINS_OBJECT_BASE_PRIV = {read = get_TableINS_OBJECT_BASE_PRIV , write = set_TableINS_OBJECT_BASE_PRIV};
   virtual TFIBSmallIntField * get_TableINS_OBJECT_BASE_PRIV(void)=0;
   virtual void set_TableINS_OBJECT_BASE_PRIV(TFIBSmallIntField * TableINS_OBJECT_BASE_PRIV)=0;

   __property TFIBSmallIntField * TableEDIT_OBJECT_BASE_PRIV = {read = get_TableEDIT_OBJECT_BASE_PRIV , write = set_TableEDIT_OBJECT_BASE_PRIV};
   virtual TFIBSmallIntField * get_TableEDIT_OBJECT_BASE_PRIV(void)=0;
   virtual void set_TableEDIT_OBJECT_BASE_PRIV(TFIBSmallIntField * TableEDIT_OBJECT_BASE_PRIV)=0;

   __property TFIBSmallIntField * TableDEL_OBJECT_BASE_PRIV = {read = get_TableDEL_OBJECT_BASE_PRIV , write = set_TableDEL_OBJECT_BASE_PRIV};
   virtual TFIBSmallIntField * get_TableDEL_OBJECT_BASE_PRIV(void)=0;
   virtual void set_TableDEL_OBJECT_BASE_PRIV(TFIBSmallIntField * TableDEL_OBJECT_BASE_PRIV)=0;

   __property TFIBSmallIntField * TableEXEC_OBJECT_BASE_PRIV = {read = get_TableEXEC_OBJECT_BASE_PRIV , write = set_TableEXEC_OBJECT_BASE_PRIV};
   virtual TFIBSmallIntField * get_TableEXEC_OBJECT_BASE_PRIV(void)=0;
   virtual void set_TableEXEC_OBJECT_BASE_PRIV(TFIBSmallIntField * TableEXEC_OBJECT_BASE_PRIV)=0;

   __property TFIBIntegerField * TableNUMBER_OBJECT_BASE_PRIV = {read = get_TableNUMBER_OBJECT_BASE_PRIV , write = set_TableNUMBER_OBJECT_BASE_PRIV};
   virtual TFIBIntegerField * get_TableNUMBER_OBJECT_BASE_PRIV(void)=0;
   virtual void set_TableNUMBER_OBJECT_BASE_PRIV(TFIBIntegerField * TableNUMBER_OBJECT_BASE_PRIV)=0;

   __property TFIBLargeIntField * TableIDGRP_OBJECT_BASE_PRIV = {read = get_TableIDGRP_OBJECT_BASE_PRIV , write = set_TableIDGRP_OBJECT_BASE_PRIV};
   virtual TFIBLargeIntField * get_TableIDGRP_OBJECT_BASE_PRIV(void)=0;
   virtual void set_TableIDGRP_OBJECT_BASE_PRIV(TFIBLargeIntField * TableIDGRP_OBJECT_BASE_PRIV)=0;

   __property TFIBLargeIntField * ElementID_OBJECT_BASE_PRIV = {read = get_ElementID_OBJECT_BASE_PRIV , write = set_ElementID_OBJECT_BASE_PRIV};
   virtual TFIBLargeIntField * get_ElementID_OBJECT_BASE_PRIV(void)=0;
   virtual void set_ElementID_OBJECT_BASE_PRIV(TFIBLargeIntField * ElementID_OBJECT_BASE_PRIV)=0;

   __property TFIBLargeIntField * ElementIDBASE_OBJECT_BASE_PRIV = {read = get_ElementIDBASE_OBJECT_BASE_PRIV , write = set_ElementIDBASE_OBJECT_BASE_PRIV};
   virtual TFIBLargeIntField * get_ElementIDBASE_OBJECT_BASE_PRIV(void)=0;
   virtual void set_ElementIDBASE_OBJECT_BASE_PRIV(TFIBLargeIntField * ElementIDBASE_OBJECT_BASE_PRIV)=0;

   __property TFIBLargeIntField * ElementIDEXT_DOUT_OBJECT_BASE_PRIV = {read = get_ElementIDEXT_DOUT_OBJECT_BASE_PRIV , write = set_ElementIDEXT_DOUT_OBJECT_BASE_PRIV};
   virtual TFIBLargeIntField * get_ElementIDEXT_DOUT_OBJECT_BASE_PRIV(void)=0;
   virtual void set_ElementIDEXT_DOUT_OBJECT_BASE_PRIV(TFIBLargeIntField * ElementIDEXT_DOUT_OBJECT_BASE_PRIV)=0;

   __property TFIBLargeIntField * ElementIDEXT_BASE_OBJECT_BASE_PRIV = {read = get_ElementIDEXT_BASE_OBJECT_BASE_PRIV , write = set_ElementIDEXT_BASE_OBJECT_BASE_PRIV};
   virtual TFIBLargeIntField * get_ElementIDEXT_BASE_OBJECT_BASE_PRIV(void)=0;
   virtual void set_ElementIDEXT_BASE_OBJECT_BASE_PRIV(TFIBLargeIntField * ElementIDEXT_BASE_OBJECT_BASE_PRIV)=0;

   __property TFIBLargeIntField * ElementIDGRPUSER_OBJECT_BASE_PRIV = {read = get_ElementIDGRPUSER_OBJECT_BASE_PRIV , write = set_ElementIDGRPUSER_OBJECT_BASE_PRIV};
   virtual TFIBLargeIntField * get_ElementIDGRPUSER_OBJECT_BASE_PRIV(void)=0;
   virtual void set_ElementIDGRPUSER_OBJECT_BASE_PRIV(TFIBLargeIntField * ElementIDGRPUSER_OBJECT_BASE_PRIV)=0;

   __property TFIBSmallIntField * ElementINS_OBJECT_BASE_PRIV = {read = get_ElementINS_OBJECT_BASE_PRIV , write = set_ElementINS_OBJECT_BASE_PRIV};
   virtual TFIBSmallIntField * get_ElementINS_OBJECT_BASE_PRIV(void)=0;
   virtual void set_ElementINS_OBJECT_BASE_PRIV(TFIBSmallIntField * ElementINS_OBJECT_BASE_PRIV)=0;

   __property TFIBSmallIntField * ElementEDIT_OBJECT_BASE_PRIV = {read = get_ElementEDIT_OBJECT_BASE_PRIV , write = set_ElementEDIT_OBJECT_BASE_PRIV};
   virtual TFIBSmallIntField * get_ElementEDIT_OBJECT_BASE_PRIV(void)=0;
   virtual void set_ElementEDIT_OBJECT_BASE_PRIV(TFIBSmallIntField * ElementEDIT_OBJECT_BASE_PRIV)=0;

   __property TFIBSmallIntField * ElementDEL_OBJECT_BASE_PRIV = {read = get_ElementDEL_OBJECT_BASE_PRIV , write = set_ElementDEL_OBJECT_BASE_PRIV};
   virtual TFIBSmallIntField * get_ElementDEL_OBJECT_BASE_PRIV(void)=0;
   virtual void set_ElementDEL_OBJECT_BASE_PRIV(TFIBSmallIntField * ElementDEL_OBJECT_BASE_PRIV)=0;

   __property TFIBSmallIntField * ElementEXEC_OBJECT_BASE_PRIV = {read = get_ElementEXEC_OBJECT_BASE_PRIV , write = set_ElementEXEC_OBJECT_BASE_PRIV};
   virtual TFIBSmallIntField * get_ElementEXEC_OBJECT_BASE_PRIV(void)=0;
   virtual void set_ElementEXEC_OBJECT_BASE_PRIV(TFIBSmallIntField * ElementEXEC_OBJECT_BASE_PRIV)=0;

   __property TFIBIntegerField * ElementNUMBER_OBJECT_BASE_PRIV = {read = get_ElementNUMBER_OBJECT_BASE_PRIV , write = set_ElementNUMBER_OBJECT_BASE_PRIV};
   virtual TFIBIntegerField * get_ElementNUMBER_OBJECT_BASE_PRIV(void)=0;
   virtual void set_ElementNUMBER_OBJECT_BASE_PRIV(TFIBIntegerField * ElementNUMBER_OBJECT_BASE_PRIV)=0;

   __property TFIBLargeIntField * ElementIDGRP_OBJECT_BASE_PRIV = {read = get_ElementIDGRP_OBJECT_BASE_PRIV , write = set_ElementIDGRP_OBJECT_BASE_PRIV};
   virtual TFIBLargeIntField * get_ElementIDGRP_OBJECT_BASE_PRIV(void)=0;
   virtual void set_ElementIDGRP_OBJECT_BASE_PRIV(TFIBLargeIntField * ElementIDGRP_OBJECT_BASE_PRIV)=0;

   __property TFIBIntegerField * TableAPPLICATION_OBJECT_BASE_PRIV = {read = get_TableAPPLICATION_OBJECT_BASE_PRIV , write = set_TableAPPLICATION_OBJECT_BASE_PRIV};
   virtual TFIBIntegerField * get_TableAPPLICATION_OBJECT_BASE_PRIV(void)=0;
   virtual void set_TableAPPLICATION_OBJECT_BASE_PRIV(TFIBIntegerField * TableAPPLICATION_OBJECT_BASE_PRIV)=0;

   __property TFIBIntegerField * ElementAPPLICATION_OBJECT_BASE_PRIV = {read = get_ElementAPPLICATION_OBJECT_BASE_PRIV , write = set_ElementAPPLICATION_OBJECT_BASE_PRIV};
   virtual TFIBIntegerField * get_ElementAPPLICATION_OBJECT_BASE_PRIV(void)=0;
   virtual void set_ElementAPPLICATION_OBJECT_BASE_PRIV(TFIBIntegerField * ElementAPPLICATION_OBJECT_BASE_PRIV)=0;

   __property TpFIBQuery * Query = {read = get_Query , write = set_Query};
   virtual TpFIBQuery * get_Query(void)=0;
   virtual void set_Query(TpFIBQuery * Query)=0;

   __property TFIBWideStringField * ElementGUID_OBJECT_BASE_PRIV = {read = get_ElementGUID_OBJECT_BASE_PRIV , write = set_ElementGUID_OBJECT_BASE_PRIV};
   virtual TFIBWideStringField * get_ElementGUID_OBJECT_BASE_PRIV(void)=0;
   virtual void set_ElementGUID_OBJECT_BASE_PRIV(TFIBWideStringField * ElementGUID_OBJECT_BASE_PRIV)=0;

   __property TFIBWideStringField * TableGUID_OBJECT_BASE_PRIV = {read = get_TableGUID_OBJECT_BASE_PRIV , write = set_TableGUID_OBJECT_BASE_PRIV};
   virtual TFIBWideStringField * get_TableGUID_OBJECT_BASE_PRIV(void)=0;
   virtual void set_TableGUID_OBJECT_BASE_PRIV(TFIBWideStringField * TableGUID_OBJECT_BASE_PRIV)=0;

   __property TFIBWideStringField * TableNAME_PROGRAM_MODULE = {read = get_TableNAME_PROGRAM_MODULE , write = set_TableNAME_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_TableNAME_PROGRAM_MODULE(void)=0;
   virtual void set_TableNAME_PROGRAM_MODULE(TFIBWideStringField * TableNAME_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * TablePROGID_PROGRAM_MODULE = {read = get_TablePROGID_PROGRAM_MODULE , write = set_TablePROGID_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_TablePROGID_PROGRAM_MODULE(void)=0;
   virtual void set_TablePROGID_PROGRAM_MODULE(TFIBWideStringField * TablePROGID_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * TablePATCH_PROGRAM_MODULE = {read = get_TablePATCH_PROGRAM_MODULE , write = set_TablePATCH_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_TablePATCH_PROGRAM_MODULE(void)=0;
   virtual void set_TablePATCH_PROGRAM_MODULE(TFIBWideStringField * TablePATCH_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * ElementNAME_PROGRAM_MODULE = {read = get_ElementNAME_PROGRAM_MODULE , write = set_ElementNAME_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_ElementNAME_PROGRAM_MODULE(void)=0;
   virtual void set_ElementNAME_PROGRAM_MODULE(TFIBWideStringField * ElementNAME_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * ElementPROGID_PROGRAM_MODULE = {read = get_ElementPROGID_PROGRAM_MODULE , write = set_ElementPROGID_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_ElementPROGID_PROGRAM_MODULE(void)=0;
   virtual void set_ElementPROGID_PROGRAM_MODULE(TFIBWideStringField * ElementPROGID_PROGRAM_MODULE)=0;

   __property TFIBWideStringField * ElementPATCH_PROGRAM_MODULE = {read = get_ElementPATCH_PROGRAM_MODULE , write = set_ElementPATCH_PROGRAM_MODULE};
   virtual TFIBWideStringField * get_ElementPATCH_PROGRAM_MODULE(void)=0;
   virtual void set_ElementPATCH_PROGRAM_MODULE(TFIBWideStringField * ElementPATCH_PROGRAM_MODULE)=0;

   __property __int64 IdGrpUser = {read = get_IdGrpUser , write = set_IdGrpUser};
   virtual __int64 get_IdGrpUser(void)=0;
   virtual void set_IdGrpUser(__int64 IdGrpUser)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property int NumApplication = {read = get_NumApplication , write = set_NumApplication};
   virtual int get_NumApplication(void)=0;
   virtual void set_NumApplication(int NumApplication)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   virtual void OpenTable(int application, __int64 id_grp_user, __int64 id_grp, bool all)=0;
   virtual bool SaveIsmen()=0;
   virtual void CancelIsmen()=0;
   virtual bool Table_Delete(void)=0;
   virtual bool Table_AppendString(int application, __int64 id_grp_user, __int64 id_grp)=0;
   virtual bool NewElement(int application, __int64 id_grp_user, __int64 id_grp)=0;
   virtual bool OpenElement(__int64 id)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual bool InsertElement(int application, __int64 id_grp_user, __int64 id_grp)=0;
   virtual void Element_Edit(void)=0;
   virtual void Element_Post(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void ChancheGrp(__int64 id_new_grp)=0;
   virtual bool GetPrivDM(int application, __int64 id_grp_user, int object)=0;
   virtual bool GetPrivForm(__int64 id_grp_user, int object)=0;
};
#define IID_IDMObjectBasePriv __uuidof(IDMObjectBasePriv)
#endif
