#ifndef UIDMSprProjectH
#define UIDMSprProjectH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>
class __declspec(uuid("{4E2DBB46-2B1B-4531-B535-FBEF8DA37BF9}")) IDMSprProject : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TDataSource * DataSourceElement = {read = get_DataSourceElement , write = set_DataSourceElement};
   virtual TDataSource * get_DataSourceElement(void)=0;
   virtual void set_DataSourceElement(TDataSource * DataSourceElement)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TFIBBCDField * TableID_SPROJECT = {read = get_TableID_SPROJECT , write = set_TableID_SPROJECT};
   virtual TFIBBCDField * get_TableID_SPROJECT(void)=0;
   virtual void set_TableID_SPROJECT(TFIBBCDField * TableID_SPROJECT)=0;

   __property TFIBBCDField * TableIDGRP_SPROJECT = {read = get_TableIDGRP_SPROJECT , write = set_TableIDGRP_SPROJECT};
   virtual TFIBBCDField * get_TableIDGRP_SPROJECT(void)=0;
   virtual void set_TableIDGRP_SPROJECT(TFIBBCDField * TableIDGRP_SPROJECT)=0;

   __property TFIBBCDField * ElementID_SPROJECT = {read = get_ElementID_SPROJECT , write = set_ElementID_SPROJECT};
   virtual TFIBBCDField * get_ElementID_SPROJECT(void)=0;
   virtual void set_ElementID_SPROJECT(TFIBBCDField * ElementID_SPROJECT)=0;

   __property TFIBBCDField * ElementIDGRP_SPROJECT = {read = get_ElementIDGRP_SPROJECT , write = set_ElementIDGRP_SPROJECT};
   virtual TFIBBCDField * get_ElementIDGRP_SPROJECT(void)=0;
   virtual void set_ElementIDGRP_SPROJECT(TFIBBCDField * ElementIDGRP_SPROJECT)=0;

   __property TFIBIntegerField * ElementCODE_SPROJECT = {read = get_ElementCODE_SPROJECT , write = set_ElementCODE_SPROJECT};
   virtual TFIBIntegerField * get_ElementCODE_SPROJECT(void)=0;
   virtual void set_ElementCODE_SPROJECT(TFIBIntegerField * ElementCODE_SPROJECT)=0;

   __property TpFIBDataSet * Code = {read = get_Code , write = set_Code};
   virtual TpFIBDataSet * get_Code(void)=0;
   virtual void set_Code(TpFIBDataSet * Code)=0;

   __property TFIBIntegerField * CodeMAXCODE = {read = get_CodeMAXCODE , write = set_CodeMAXCODE};
   virtual TFIBIntegerField * get_CodeMAXCODE(void)=0;
   virtual void set_CodeMAXCODE(TFIBIntegerField * CodeMAXCODE)=0;

   __property TFIBIntegerField * TableCODE_SPROJECT = {read = get_TableCODE_SPROJECT , write = set_TableCODE_SPROJECT};
   virtual TFIBIntegerField * get_TableCODE_SPROJECT(void)=0;
   virtual void set_TableCODE_SPROJECT(TFIBIntegerField * TableCODE_SPROJECT)=0;

   __property TFIBWideStringField * TableNAME_SPROJECT = {read = get_TableNAME_SPROJECT , write = set_TableNAME_SPROJECT};
   virtual TFIBWideStringField * get_TableNAME_SPROJECT(void)=0;
   virtual void set_TableNAME_SPROJECT(TFIBWideStringField * TableNAME_SPROJECT)=0;

   __property TFIBWideStringField * ElementNAME_SPROJECT = {read = get_ElementNAME_SPROJECT , write = set_ElementNAME_SPROJECT};
   virtual TFIBWideStringField * get_ElementNAME_SPROJECT(void)=0;
   virtual void set_ElementNAME_SPROJECT(TFIBWideStringField * ElementNAME_SPROJECT)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   virtual AnsiString GetTextQuery(__int64 id_grp, bool all)=0;
   virtual void OpenTable(__int64 id_grp, bool all)=0;
   virtual int OpenElement(__int64 id )=0;
   virtual bool NewElement(__int64 id_grp)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual void ChancheGrp(__int64 new_id_grp)=0;
   virtual __int64 FindPoCodu(int code)=0;
   virtual __int64 FindPoName(AnsiString name)=0;
   virtual __int64 GetIdGrpProject(__int64 id_project)=0;
   virtual int GetCodeProject(void)=0;
   virtual bool CheckCode(__int64 id_project, int code)=0;
};
#define IID_IDMSprProject __uuidof(IDMSprProject)
#endif
