#ifndef UIREM_DMSprProducerRabotaH
#define UIREM_DMSprProducerRabotaH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMSprProducerRabota)) IREM_DMSprProducerRabota : public IMainInterface
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

   __property TDataSource * DataSourceElement = {read = get_DataSourceElement , write = set_DataSourceElement};
   virtual TDataSource * get_DataSourceElement(void)=0;
   virtual void set_DataSourceElement(TDataSource * DataSourceElement)=0;

   __property TFIBLargeIntField * TableID_REM_SPRRABOTA = {read = get_TableID_REM_SPRRABOTA , write = set_TableID_REM_SPRRABOTA};
   virtual TFIBLargeIntField * get_TableID_REM_SPRRABOTA(void)=0;
   virtual void set_TableID_REM_SPRRABOTA(TFIBLargeIntField * TableID_REM_SPRRABOTA)=0;

   __property TFIBLargeIntField * TableIDBASE_REM_SPRRABOTA = {read = get_TableIDBASE_REM_SPRRABOTA , write = set_TableIDBASE_REM_SPRRABOTA};
   virtual TFIBLargeIntField * get_TableIDBASE_REM_SPRRABOTA(void)=0;
   virtual void set_TableIDBASE_REM_SPRRABOTA(TFIBLargeIntField * TableIDBASE_REM_SPRRABOTA)=0;

   __property TFIBWideStringField * TableGID_REM_SPRRABOTA = {read = get_TableGID_REM_SPRRABOTA , write = set_TableGID_REM_SPRRABOTA};
   virtual TFIBWideStringField * get_TableGID_REM_SPRRABOTA(void)=0;
   virtual void set_TableGID_REM_SPRRABOTA(TFIBWideStringField * TableGID_REM_SPRRABOTA)=0;

   __property TFIBLargeIntField * TableIDPR_REM_SPRRABOTA = {read = get_TableIDPR_REM_SPRRABOTA , write = set_TableIDPR_REM_SPRRABOTA};
   virtual TFIBLargeIntField * get_TableIDPR_REM_SPRRABOTA(void)=0;
   virtual void set_TableIDPR_REM_SPRRABOTA(TFIBLargeIntField * TableIDPR_REM_SPRRABOTA)=0;

   __property TFIBLargeIntField * TableIDGRP_REM_SPRRABOTA = {read = get_TableIDGRP_REM_SPRRABOTA , write = set_TableIDGRP_REM_SPRRABOTA};
   virtual TFIBLargeIntField * get_TableIDGRP_REM_SPRRABOTA(void)=0;
   virtual void set_TableIDGRP_REM_SPRRABOTA(TFIBLargeIntField * TableIDGRP_REM_SPRRABOTA)=0;

   __property TFIBWideStringField * TableNAME_REM_SPRRABOTA = {read = get_TableNAME_REM_SPRRABOTA , write = set_TableNAME_REM_SPRRABOTA};
   virtual TFIBWideStringField * get_TableNAME_REM_SPRRABOTA(void)=0;
   virtual void set_TableNAME_REM_SPRRABOTA(TFIBWideStringField * TableNAME_REM_SPRRABOTA)=0;

   __property TFIBWideStringField * TableNAME_ENG_REM_SPRRABOTA = {read = get_TableNAME_ENG_REM_SPRRABOTA , write = set_TableNAME_ENG_REM_SPRRABOTA};
   virtual TFIBWideStringField * get_TableNAME_ENG_REM_SPRRABOTA(void)=0;
   virtual void set_TableNAME_ENG_REM_SPRRABOTA(TFIBWideStringField * TableNAME_ENG_REM_SPRRABOTA)=0;

   __property TFIBWideStringField * TableCODE_REM_SPRRABOTA = {read = get_TableCODE_REM_SPRRABOTA , write = set_TableCODE_REM_SPRRABOTA};
   virtual TFIBWideStringField * get_TableCODE_REM_SPRRABOTA(void)=0;
   virtual void set_TableCODE_REM_SPRRABOTA(TFIBWideStringField * TableCODE_REM_SPRRABOTA)=0;

   __property TFIBIntegerField * TableLEVEL_REM_SPRRABOTA = {read = get_TableLEVEL_REM_SPRRABOTA , write = set_TableLEVEL_REM_SPRRABOTA};
   virtual TFIBIntegerField * get_TableLEVEL_REM_SPRRABOTA(void)=0;
   virtual void set_TableLEVEL_REM_SPRRABOTA(TFIBIntegerField * TableLEVEL_REM_SPRRABOTA)=0;

   __property TFIBIntegerField * TableTYPECLIENT_REM_SPRRABOTA = {read = get_TableTYPECLIENT_REM_SPRRABOTA , write = set_TableTYPECLIENT_REM_SPRRABOTA};
   virtual TFIBIntegerField * get_TableTYPECLIENT_REM_SPRRABOTA(void)=0;
   virtual void set_TableTYPECLIENT_REM_SPRRABOTA(TFIBIntegerField * TableTYPECLIENT_REM_SPRRABOTA)=0;

   __property TFIBIntegerField * TableTYPEPRODUCT_REM_SPRRABOTA = {read = get_TableTYPEPRODUCT_REM_SPRRABOTA , write = set_TableTYPEPRODUCT_REM_SPRRABOTA};
   virtual TFIBIntegerField * get_TableTYPEPRODUCT_REM_SPRRABOTA(void)=0;
   virtual void set_TableTYPEPRODUCT_REM_SPRRABOTA(TFIBIntegerField * TableTYPEPRODUCT_REM_SPRRABOTA)=0;

   __property TFIBWideStringField * TableLEVEL_STR_REM_SPRRABOTA = {read = get_TableLEVEL_STR_REM_SPRRABOTA , write = set_TableLEVEL_STR_REM_SPRRABOTA};
   virtual TFIBWideStringField * get_TableLEVEL_STR_REM_SPRRABOTA(void)=0;
   virtual void set_TableLEVEL_STR_REM_SPRRABOTA(TFIBWideStringField * TableLEVEL_STR_REM_SPRRABOTA)=0;

   __property TFIBLargeIntField * TableIDNOM_REM_SPRRABOTA = {read = get_TableIDNOM_REM_SPRRABOTA , write = set_TableIDNOM_REM_SPRRABOTA};
   virtual TFIBLargeIntField * get_TableIDNOM_REM_SPRRABOTA(void)=0;
   virtual void set_TableIDNOM_REM_SPRRABOTA(TFIBLargeIntField * TableIDNOM_REM_SPRRABOTA)=0;

   __property TFIBWideStringField * TableNAMENOM = {read = get_TableNAMENOM , write = set_TableNAMENOM};
   virtual TFIBWideStringField * get_TableNAMENOM(void)=0;
   virtual void set_TableNAMENOM(TFIBWideStringField * TableNAMENOM)=0;

   __property TFIBLargeIntField * ElementID_REM_SPRRABOTA = {read = get_ElementID_REM_SPRRABOTA , write = set_ElementID_REM_SPRRABOTA};
   virtual TFIBLargeIntField * get_ElementID_REM_SPRRABOTA(void)=0;
   virtual void set_ElementID_REM_SPRRABOTA(TFIBLargeIntField * ElementID_REM_SPRRABOTA)=0;

   __property TFIBLargeIntField * ElementIDBASE_REM_SPRRABOTA = {read = get_ElementIDBASE_REM_SPRRABOTA , write = set_ElementIDBASE_REM_SPRRABOTA};
   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SPRRABOTA(void)=0;
   virtual void set_ElementIDBASE_REM_SPRRABOTA(TFIBLargeIntField * ElementIDBASE_REM_SPRRABOTA)=0;

   __property TFIBWideStringField * ElementGID_REM_SPRRABOTA = {read = get_ElementGID_REM_SPRRABOTA , write = set_ElementGID_REM_SPRRABOTA};
   virtual TFIBWideStringField * get_ElementGID_REM_SPRRABOTA(void)=0;
   virtual void set_ElementGID_REM_SPRRABOTA(TFIBWideStringField * ElementGID_REM_SPRRABOTA)=0;

   __property TFIBLargeIntField * ElementIDPR_REM_SPRRABOTA = {read = get_ElementIDPR_REM_SPRRABOTA , write = set_ElementIDPR_REM_SPRRABOTA};
   virtual TFIBLargeIntField * get_ElementIDPR_REM_SPRRABOTA(void)=0;
   virtual void set_ElementIDPR_REM_SPRRABOTA(TFIBLargeIntField * ElementIDPR_REM_SPRRABOTA)=0;

   __property TFIBLargeIntField * ElementIDGRP_REM_SPRRABOTA = {read = get_ElementIDGRP_REM_SPRRABOTA , write = set_ElementIDGRP_REM_SPRRABOTA};
   virtual TFIBLargeIntField * get_ElementIDGRP_REM_SPRRABOTA(void)=0;
   virtual void set_ElementIDGRP_REM_SPRRABOTA(TFIBLargeIntField * ElementIDGRP_REM_SPRRABOTA)=0;

   __property TFIBWideStringField * ElementNAME_REM_SPRRABOTA = {read = get_ElementNAME_REM_SPRRABOTA , write = set_ElementNAME_REM_SPRRABOTA};
   virtual TFIBWideStringField * get_ElementNAME_REM_SPRRABOTA(void)=0;
   virtual void set_ElementNAME_REM_SPRRABOTA(TFIBWideStringField * ElementNAME_REM_SPRRABOTA)=0;

   __property TFIBWideStringField * ElementNAME_ENG_REM_SPRRABOTA = {read = get_ElementNAME_ENG_REM_SPRRABOTA , write = set_ElementNAME_ENG_REM_SPRRABOTA};
   virtual TFIBWideStringField * get_ElementNAME_ENG_REM_SPRRABOTA(void)=0;
   virtual void set_ElementNAME_ENG_REM_SPRRABOTA(TFIBWideStringField * ElementNAME_ENG_REM_SPRRABOTA)=0;

   __property TFIBWideStringField * ElementCODE_REM_SPRRABOTA = {read = get_ElementCODE_REM_SPRRABOTA , write = set_ElementCODE_REM_SPRRABOTA};
   virtual TFIBWideStringField * get_ElementCODE_REM_SPRRABOTA(void)=0;
   virtual void set_ElementCODE_REM_SPRRABOTA(TFIBWideStringField * ElementCODE_REM_SPRRABOTA)=0;

   __property TFIBIntegerField * ElementLEVEL_REM_SPRRABOTA = {read = get_ElementLEVEL_REM_SPRRABOTA , write = set_ElementLEVEL_REM_SPRRABOTA};
   virtual TFIBIntegerField * get_ElementLEVEL_REM_SPRRABOTA(void)=0;
   virtual void set_ElementLEVEL_REM_SPRRABOTA(TFIBIntegerField * ElementLEVEL_REM_SPRRABOTA)=0;

   __property TFIBIntegerField * ElementTYPECLIENT_REM_SPRRABOTA = {read = get_ElementTYPECLIENT_REM_SPRRABOTA , write = set_ElementTYPECLIENT_REM_SPRRABOTA};
   virtual TFIBIntegerField * get_ElementTYPECLIENT_REM_SPRRABOTA(void)=0;
   virtual void set_ElementTYPECLIENT_REM_SPRRABOTA(TFIBIntegerField * ElementTYPECLIENT_REM_SPRRABOTA)=0;

   __property TFIBIntegerField * ElementTYPEPRODUCT_REM_SPRRABOTA = {read = get_ElementTYPEPRODUCT_REM_SPRRABOTA , write = set_ElementTYPEPRODUCT_REM_SPRRABOTA};
   virtual TFIBIntegerField * get_ElementTYPEPRODUCT_REM_SPRRABOTA(void)=0;
   virtual void set_ElementTYPEPRODUCT_REM_SPRRABOTA(TFIBIntegerField * ElementTYPEPRODUCT_REM_SPRRABOTA)=0;

   __property TFIBWideStringField * ElementLEVEL_STR_REM_SPRRABOTA = {read = get_ElementLEVEL_STR_REM_SPRRABOTA , write = set_ElementLEVEL_STR_REM_SPRRABOTA};
   virtual TFIBWideStringField * get_ElementLEVEL_STR_REM_SPRRABOTA(void)=0;
   virtual void set_ElementLEVEL_STR_REM_SPRRABOTA(TFIBWideStringField * ElementLEVEL_STR_REM_SPRRABOTA)=0;

   __property TFIBLargeIntField * ElementIDNOM_REM_SPRRABOTA = {read = get_ElementIDNOM_REM_SPRRABOTA , write = set_ElementIDNOM_REM_SPRRABOTA};
   virtual TFIBLargeIntField * get_ElementIDNOM_REM_SPRRABOTA(void)=0;
   virtual void set_ElementIDNOM_REM_SPRRABOTA(TFIBLargeIntField * ElementIDNOM_REM_SPRRABOTA)=0;

   __property TFIBWideStringField * ElementNAMENOM = {read = get_ElementNAMENOM , write = set_ElementNAMENOM};
   virtual TFIBWideStringField * get_ElementNAMENOM(void)=0;
   virtual void set_ElementNAMENOM(TFIBWideStringField * ElementNAMENOM)=0;

   __property TpFIBQuery * Query = {read = get_Query , write = set_Query};
   virtual TpFIBQuery * get_Query(void)=0;
   virtual void set_Query(TpFIBQuery * Query)=0;

   __property __int64 IdGroupElement = {read = get_IdGroupElement , write = set_IdGroupElement};
   virtual __int64 get_IdGroupElement(void)=0;
   virtual void set_IdGroupElement(__int64 IdGroupElement)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   virtual void OpenTable(__int64 id_group_element, __int64 id_grp, bool all)=0;
   virtual bool NewElement(__int64 id_group_element, __int64 id_grp)=0;
   virtual bool OpenElement(__int64 id)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual bool SaveElement(void)=0;
   virtual void ChancheGrp(__int64 id_new_grp,__int64 id_element)=0;
   virtual __int64 FindPoCodu(__int64 id_group_element, UnicodeString code)=0;
   virtual __int64 FindPoName(__int64 id_group_element, UnicodeString name)=0;
   virtual __int64 FindPoNameEng(__int64 id_group_element, UnicodeString name)=0;
   virtual __int64 GetIdGrp(__int64 id_el)=0;
};
#define IID_IREM_DMSprProducerRabota __uuidof(IREM_DMSprProducerRabota)
#endif
