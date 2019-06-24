#ifndef UIREM_DMSprTrebRabotH
#define UIREM_DMSprTrebRabotH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMSprTrebRabot)) IREM_DMSprTrebRabot : public IMainInterface
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

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBLargeIntField * TableID_REM_STREBRABOT = {read = get_TableID_REM_STREBRABOT , write = set_TableID_REM_STREBRABOT};
   virtual TFIBLargeIntField * get_TableID_REM_STREBRABOT(void)=0;
   virtual void set_TableID_REM_STREBRABOT(TFIBLargeIntField * TableID_REM_STREBRABOT)=0;

   __property TFIBWideStringField * TableGID_REM_STREBRABOT = {read = get_TableGID_REM_STREBRABOT , write = set_TableGID_REM_STREBRABOT};
   virtual TFIBWideStringField * get_TableGID_REM_STREBRABOT(void)=0;
   virtual void set_TableGID_REM_STREBRABOT(TFIBWideStringField * TableGID_REM_STREBRABOT)=0;

   __property TFIBLargeIntField * TableIDBASE_REM_STREBRABOT = {read = get_TableIDBASE_REM_STREBRABOT , write = set_TableIDBASE_REM_STREBRABOT};
   virtual TFIBLargeIntField * get_TableIDBASE_REM_STREBRABOT(void)=0;
   virtual void set_TableIDBASE_REM_STREBRABOT(TFIBLargeIntField * TableIDBASE_REM_STREBRABOT)=0;

   __property TFIBLargeIntField * TableIDDMN_REM_STREBRABOT = {read = get_TableIDDMN_REM_STREBRABOT , write = set_TableIDDMN_REM_STREBRABOT};
   virtual TFIBLargeIntField * get_TableIDDMN_REM_STREBRABOT(void)=0;
   virtual void set_TableIDDMN_REM_STREBRABOT(TFIBLargeIntField * TableIDDMN_REM_STREBRABOT)=0;

   __property TFIBLargeIntField * TableIDTYPRABOT_REM_STREBRABOT = {read = get_TableIDTYPRABOT_REM_STREBRABOT , write = set_TableIDTYPRABOT_REM_STREBRABOT};
   virtual TFIBLargeIntField * get_TableIDTYPRABOT_REM_STREBRABOT(void)=0;
   virtual void set_TableIDTYPRABOT_REM_STREBRABOT(TFIBLargeIntField * TableIDTYPRABOT_REM_STREBRABOT)=0;

   __property TFIBWideStringField * TableNAME_REM_STREBRABOT = {read = get_TableNAME_REM_STREBRABOT , write = set_TableNAME_REM_STREBRABOT};
   virtual TFIBWideStringField * get_TableNAME_REM_STREBRABOT(void)=0;
   virtual void set_TableNAME_REM_STREBRABOT(TFIBWideStringField * TableNAME_REM_STREBRABOT)=0;

   __property TFIBWideStringField * TableNAME_REM_STYPRABOT = {read = get_TableNAME_REM_STYPRABOT , write = set_TableNAME_REM_STYPRABOT};
   virtual TFIBWideStringField * get_TableNAME_REM_STYPRABOT(void)=0;
   virtual void set_TableNAME_REM_STYPRABOT(TFIBWideStringField * TableNAME_REM_STYPRABOT)=0;

   __property TFIBLargeIntField * ElementID_REM_STREBRABOT = {read = get_ElementID_REM_STREBRABOT , write = set_ElementID_REM_STREBRABOT};
   virtual TFIBLargeIntField * get_ElementID_REM_STREBRABOT(void)=0;
   virtual void set_ElementID_REM_STREBRABOT(TFIBLargeIntField * ElementID_REM_STREBRABOT)=0;

   __property TFIBWideStringField * ElementGID_REM_STREBRABOT = {read = get_ElementGID_REM_STREBRABOT , write = set_ElementGID_REM_STREBRABOT};
   virtual TFIBWideStringField * get_ElementGID_REM_STREBRABOT(void)=0;
   virtual void set_ElementGID_REM_STREBRABOT(TFIBWideStringField * ElementGID_REM_STREBRABOT)=0;

   __property TFIBLargeIntField * ElementIDBASE_REM_STREBRABOT = {read = get_ElementIDBASE_REM_STREBRABOT , write = set_ElementIDBASE_REM_STREBRABOT};
   virtual TFIBLargeIntField * get_ElementIDBASE_REM_STREBRABOT(void)=0;
   virtual void set_ElementIDBASE_REM_STREBRABOT(TFIBLargeIntField * ElementIDBASE_REM_STREBRABOT)=0;

   __property TFIBLargeIntField * ElementIDDMN_REM_STREBRABOT = {read = get_ElementIDDMN_REM_STREBRABOT , write = set_ElementIDDMN_REM_STREBRABOT};
   virtual TFIBLargeIntField * get_ElementIDDMN_REM_STREBRABOT(void)=0;
   virtual void set_ElementIDDMN_REM_STREBRABOT(TFIBLargeIntField * ElementIDDMN_REM_STREBRABOT)=0;

   __property TFIBLargeIntField * ElementIDTYPRABOT_REM_STREBRABOT = {read = get_ElementIDTYPRABOT_REM_STREBRABOT , write = set_ElementIDTYPRABOT_REM_STREBRABOT};
   virtual TFIBLargeIntField * get_ElementIDTYPRABOT_REM_STREBRABOT(void)=0;
   virtual void set_ElementIDTYPRABOT_REM_STREBRABOT(TFIBLargeIntField * ElementIDTYPRABOT_REM_STREBRABOT)=0;

   __property TFIBWideStringField * ElementNAME_REM_STREBRABOT = {read = get_ElementNAME_REM_STREBRABOT , write = set_ElementNAME_REM_STREBRABOT};
   virtual TFIBWideStringField * get_ElementNAME_REM_STREBRABOT(void)=0;
   virtual void set_ElementNAME_REM_STREBRABOT(TFIBWideStringField * ElementNAME_REM_STREBRABOT)=0;

   __property TFIBWideStringField * ElementNAME_REM_STYPRABOT = {read = get_ElementNAME_REM_STYPRABOT , write = set_ElementNAME_REM_STYPRABOT};
   virtual TFIBWideStringField * get_ElementNAME_REM_STYPRABOT(void)=0;
   virtual void set_ElementNAME_REM_STYPRABOT(TFIBWideStringField * ElementNAME_REM_STYPRABOT)=0;

   virtual void OpenTable(__int64 id_defect_model_neispr)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual bool NewElement(__int64 id_defect_model_neispr)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
};
#define IID_IREM_DMSprTrebRabot __uuidof(IREM_DMSprTrebRabot)
#endif
