#ifndef UIDMSprGrafikPlatH
#define UIDMSprGrafikPlatH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{1CC69E80-7433-4C2C-AFB4-5FF68932E0A0}")) IDMSprGrafikPlat : public IMainInterface
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

   __property TFIBDateField * TableDO_SGRPLAT = {read = get_TableDO_SGRPLAT , write = set_TableDO_SGRPLAT};
   virtual TFIBDateField * get_TableDO_SGRPLAT(void)=0;
   virtual void set_TableDO_SGRPLAT(TFIBDateField * TableDO_SGRPLAT)=0;

   __property TFIBBCDField * TableSUM_SGRPLAT = {read = get_TableSUM_SGRPLAT , write = set_TableSUM_SGRPLAT};
   virtual TFIBBCDField * get_TableSUM_SGRPLAT(void)=0;
   virtual void set_TableSUM_SGRPLAT(TFIBBCDField * TableSUM_SGRPLAT)=0;

   __property TFIBBCDField * TableID_SGRPLAT = {read = get_TableID_SGRPLAT , write = set_TableID_SGRPLAT};
   virtual TFIBBCDField * get_TableID_SGRPLAT(void)=0;
   virtual void set_TableID_SGRPLAT(TFIBBCDField * TableID_SGRPLAT)=0;

   __property TFIBBCDField * TableIDDOG_SGRPLAT = {read = get_TableIDDOG_SGRPLAT , write = set_TableIDDOG_SGRPLAT};
   virtual TFIBBCDField * get_TableIDDOG_SGRPLAT(void)=0;
   virtual void set_TableIDDOG_SGRPLAT(TFIBBCDField * TableIDDOG_SGRPLAT)=0;

   __property TFIBWideStringField * TableGID_SGRPLAT = {read = get_TableGID_SGRPLAT , write = set_TableGID_SGRPLAT};
   virtual TFIBWideStringField * get_TableGID_SGRPLAT(void)=0;
   virtual void set_TableGID_SGRPLAT(TFIBWideStringField * TableGID_SGRPLAT)=0;

   __property __int64 IdDogovor = {read = get_IdDogovor , write = set_IdDogovor};
   virtual __int64 get_IdDogovor(void)=0;
   virtual void set_IdDogovor(__int64 IdDogovor)=0;

   virtual void OpenTable(__int64 idDogovor)=0;
   virtual void NewElement(__int64 idDogovor)=0;
   virtual void DeleteElement()=0;
   virtual void SaveIsmen()=0;
   virtual void CancelIsmen()=0;
};
#define IID_IDMSprGrafikPlat __uuidof(IDMSprGrafikPlat)
#endif
