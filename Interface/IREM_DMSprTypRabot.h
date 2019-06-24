#ifndef UIREM_DMSprTypRabotH
#define UIREM_DMSprTypRabotH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMSprTypRabot)) IREM_DMSprTypRabot : public IMainInterface
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

   __property TpFIBQuery * pFIBQuery = {read = get_pFIBQuery , write = set_pFIBQuery};
   virtual TpFIBQuery * get_pFIBQuery(void)=0;
   virtual void set_pFIBQuery(TpFIBQuery * pFIBQuery)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBLargeIntField * TableID_REM_STYPRABOT = {read = get_TableID_REM_STYPRABOT , write = set_TableID_REM_STYPRABOT};
   virtual TFIBLargeIntField * get_TableID_REM_STYPRABOT(void)=0;
   virtual void set_TableID_REM_STYPRABOT(TFIBLargeIntField * TableID_REM_STYPRABOT)=0;

   __property TFIBWideStringField * TableGID_REM_STYPRABOT = {read = get_TableGID_REM_STYPRABOT , write = set_TableGID_REM_STYPRABOT};
   virtual TFIBWideStringField * get_TableGID_REM_STYPRABOT(void)=0;
   virtual void set_TableGID_REM_STYPRABOT(TFIBWideStringField * TableGID_REM_STYPRABOT)=0;

   __property TFIBLargeIntField * TableIDBASE_REM_STYPRABOT = {read = get_TableIDBASE_REM_STYPRABOT , write = set_TableIDBASE_REM_STYPRABOT};
   virtual TFIBLargeIntField * get_TableIDBASE_REM_STYPRABOT(void)=0;
   virtual void set_TableIDBASE_REM_STYPRABOT(TFIBLargeIntField * TableIDBASE_REM_STYPRABOT)=0;

   __property TFIBLargeIntField * TableIDGRP_REM_STYPRABOT = {read = get_TableIDGRP_REM_STYPRABOT , write = set_TableIDGRP_REM_STYPRABOT};
   virtual TFIBLargeIntField * get_TableIDGRP_REM_STYPRABOT(void)=0;
   virtual void set_TableIDGRP_REM_STYPRABOT(TFIBLargeIntField * TableIDGRP_REM_STYPRABOT)=0;

   __property TFIBLargeIntField * TableIDNOM_REM_STYPRABOT = {read = get_TableIDNOM_REM_STYPRABOT , write = set_TableIDNOM_REM_STYPRABOT};
   virtual TFIBLargeIntField * get_TableIDNOM_REM_STYPRABOT(void)=0;
   virtual void set_TableIDNOM_REM_STYPRABOT(TFIBLargeIntField * TableIDNOM_REM_STYPRABOT)=0;

   __property TFIBWideStringField * TableNAME_REM_STYPRABOT = {read = get_TableNAME_REM_STYPRABOT , write = set_TableNAME_REM_STYPRABOT};
   virtual TFIBWideStringField * get_TableNAME_REM_STYPRABOT(void)=0;
   virtual void set_TableNAME_REM_STYPRABOT(TFIBWideStringField * TableNAME_REM_STYPRABOT)=0;

   __property TFIBWideStringField * TableDESCR_REM_STYPRABOT = {read = get_TableDESCR_REM_STYPRABOT , write = set_TableDESCR_REM_STYPRABOT};
   virtual TFIBWideStringField * get_TableDESCR_REM_STYPRABOT(void)=0;
   virtual void set_TableDESCR_REM_STYPRABOT(TFIBWideStringField * TableDESCR_REM_STYPRABOT)=0;

   __property TFIBWideStringField * TableNAMENOM = {read = get_TableNAMENOM , write = set_TableNAMENOM};
   virtual TFIBWideStringField * get_TableNAMENOM(void)=0;
   virtual void set_TableNAMENOM(TFIBWideStringField * TableNAMENOM)=0;

   __property TFIBWideStringField * TableARTNOM = {read = get_TableARTNOM , write = set_TableARTNOM};
   virtual TFIBWideStringField * get_TableARTNOM(void)=0;
   virtual void set_TableARTNOM(TFIBWideStringField * TableARTNOM)=0;

   __property TFIBIntegerField * TableCODENOM = {read = get_TableCODENOM , write = set_TableCODENOM};
   virtual TFIBIntegerField * get_TableCODENOM(void)=0;
   virtual void set_TableCODENOM(TFIBIntegerField * TableCODENOM)=0;

   __property TFIBLargeIntField * ElementID_REM_STYPRABOT = {read = get_ElementID_REM_STYPRABOT , write = set_ElementID_REM_STYPRABOT};
   virtual TFIBLargeIntField * get_ElementID_REM_STYPRABOT(void)=0;
   virtual void set_ElementID_REM_STYPRABOT(TFIBLargeIntField * ElementID_REM_STYPRABOT)=0;

   __property TFIBWideStringField * ElementGID_REM_STYPRABOT = {read = get_ElementGID_REM_STYPRABOT , write = set_ElementGID_REM_STYPRABOT};
   virtual TFIBWideStringField * get_ElementGID_REM_STYPRABOT(void)=0;
   virtual void set_ElementGID_REM_STYPRABOT(TFIBWideStringField * ElementGID_REM_STYPRABOT)=0;

   __property TFIBLargeIntField * ElementIDBASE_REM_STYPRABOT = {read = get_ElementIDBASE_REM_STYPRABOT , write = set_ElementIDBASE_REM_STYPRABOT};
   virtual TFIBLargeIntField * get_ElementIDBASE_REM_STYPRABOT(void)=0;
   virtual void set_ElementIDBASE_REM_STYPRABOT(TFIBLargeIntField * ElementIDBASE_REM_STYPRABOT)=0;

   __property TFIBLargeIntField * ElementIDGRP_REM_STYPRABOT = {read = get_ElementIDGRP_REM_STYPRABOT , write = set_ElementIDGRP_REM_STYPRABOT};
   virtual TFIBLargeIntField * get_ElementIDGRP_REM_STYPRABOT(void)=0;
   virtual void set_ElementIDGRP_REM_STYPRABOT(TFIBLargeIntField * ElementIDGRP_REM_STYPRABOT)=0;

   __property TFIBLargeIntField * ElementIDNOM_REM_STYPRABOT = {read = get_ElementIDNOM_REM_STYPRABOT , write = set_ElementIDNOM_REM_STYPRABOT};
   virtual TFIBLargeIntField * get_ElementIDNOM_REM_STYPRABOT(void)=0;
   virtual void set_ElementIDNOM_REM_STYPRABOT(TFIBLargeIntField * ElementIDNOM_REM_STYPRABOT)=0;

   __property TFIBWideStringField * ElementNAME_REM_STYPRABOT = {read = get_ElementNAME_REM_STYPRABOT , write = set_ElementNAME_REM_STYPRABOT};
   virtual TFIBWideStringField * get_ElementNAME_REM_STYPRABOT(void)=0;
   virtual void set_ElementNAME_REM_STYPRABOT(TFIBWideStringField * ElementNAME_REM_STYPRABOT)=0;

   __property TFIBWideStringField * ElementDESCR_REM_STYPRABOT = {read = get_ElementDESCR_REM_STYPRABOT , write = set_ElementDESCR_REM_STYPRABOT};
   virtual TFIBWideStringField * get_ElementDESCR_REM_STYPRABOT(void)=0;
   virtual void set_ElementDESCR_REM_STYPRABOT(TFIBWideStringField * ElementDESCR_REM_STYPRABOT)=0;

   __property TFIBWideStringField * ElementNAMENOM = {read = get_ElementNAMENOM , write = set_ElementNAMENOM};
   virtual TFIBWideStringField * get_ElementNAMENOM(void)=0;
   virtual void set_ElementNAMENOM(TFIBWideStringField * ElementNAMENOM)=0;

   __property TFIBWideStringField * ElementARTNOM = {read = get_ElementARTNOM , write = set_ElementARTNOM};
   virtual TFIBWideStringField * get_ElementARTNOM(void)=0;
   virtual void set_ElementARTNOM(TFIBWideStringField * ElementARTNOM)=0;

   __property TFIBIntegerField * ElementCODENOM = {read = get_ElementCODENOM , write = set_ElementCODENOM};
   virtual TFIBIntegerField * get_ElementCODENOM(void)=0;
   virtual void set_ElementCODENOM(TFIBIntegerField * ElementCODENOM)=0;

   __property TFIBWideStringField * TableNAME_ENG_REM_STYPRABOT = {read = get_TableNAME_ENG_REM_STYPRABOT , write = set_TableNAME_ENG_REM_STYPRABOT};
   virtual TFIBWideStringField * get_TableNAME_ENG_REM_STYPRABOT(void)=0;
   virtual void set_TableNAME_ENG_REM_STYPRABOT(TFIBWideStringField * TableNAME_ENG_REM_STYPRABOT)=0;

   __property TFIBWideStringField * ElementNAME_ENG_REM_STYPRABOT = {read = get_ElementNAME_ENG_REM_STYPRABOT , write = set_ElementNAME_ENG_REM_STYPRABOT};
   virtual TFIBWideStringField * get_ElementNAME_ENG_REM_STYPRABOT(void)=0;
   virtual void set_ElementNAME_ENG_REM_STYPRABOT(TFIBWideStringField * ElementNAME_ENG_REM_STYPRABOT)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   virtual UnicodeString GetTextQuery(__int64 id_grp, bool all)=0;
   virtual void OpenTable(__int64 id_grp, bool all)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual bool NewElement(__int64 id_grp)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual void ChancheGrp(__int64 id_new_grp, __int64 id_el)=0;
   virtual __int64 GetIdGrpTypRabot(__int64 id)=0;
   virtual __int64 FindPoNom(__int64 id_nom)=0;
};
#define IID_IREM_DMSprTypRabot __uuidof(IREM_DMSprTypRabot)
#endif
