#ifndef UIDMExtModulePrivH
#define UIDMExtModulePrivH
#include "IMainInterface.h"
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{6B04967C-F41B-4870-BC28-386176BCCAA7}"))IDMExtModulePriv : public IMainInterface
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

   __property TFIBBCDField * TableIDMODULE_EXT_MODULE_PRIV = {read = get_TableIDMODULE_EXT_MODULE_PRIV , write = set_TableIDMODULE_EXT_MODULE_PRIV};
   virtual TFIBBCDField * get_TableIDMODULE_EXT_MODULE_PRIV(void)=0;
   virtual void set_TableIDMODULE_EXT_MODULE_PRIV(TFIBBCDField * TableIDMODULE_EXT_MODULE_PRIV)=0;

   __property TFIBSmallIntField * TableINS_EXT_MODULE_PRIV = {read = get_TableINS_EXT_MODULE_PRIV , write = set_TableINS_EXT_MODULE_PRIV};
   virtual TFIBSmallIntField * get_TableINS_EXT_MODULE_PRIV(void)=0;
   virtual void set_TableINS_EXT_MODULE_PRIV(TFIBSmallIntField * TableINS_EXT_MODULE_PRIV)=0;

   __property TFIBSmallIntField * TableEDIT_EXT_MODULE_PRIV = {read = get_TableEDIT_EXT_MODULE_PRIV , write = set_TableEDIT_EXT_MODULE_PRIV};
   virtual TFIBSmallIntField * get_TableEDIT_EXT_MODULE_PRIV(void)=0;
   virtual void set_TableEDIT_EXT_MODULE_PRIV(TFIBSmallIntField * TableEDIT_EXT_MODULE_PRIV)=0;

   __property TFIBSmallIntField * TableDEL_EXT_MODULE_PRIV = {read = get_TableDEL_EXT_MODULE_PRIV , write = set_TableDEL_EXT_MODULE_PRIV};
   virtual TFIBSmallIntField * get_TableDEL_EXT_MODULE_PRIV(void)=0;
   virtual void set_TableDEL_EXT_MODULE_PRIV(TFIBSmallIntField * TableDEL_EXT_MODULE_PRIV)=0;

   __property TFIBSmallIntField * TableEXEC_EXT_MODULE_PRIV = {read = get_TableEXEC_EXT_MODULE_PRIV , write = set_TableEXEC_EXT_MODULE_PRIV};
   virtual TFIBSmallIntField * get_TableEXEC_EXT_MODULE_PRIV(void)=0;
   virtual void set_TableEXEC_EXT_MODULE_PRIV(TFIBSmallIntField * TableEXEC_EXT_MODULE_PRIV)=0;

   __property TFIBBCDField * TableID_EXT_MODULE_PRIV = {read = get_TableID_EXT_MODULE_PRIV , write = set_TableID_EXT_MODULE_PRIV};
   virtual TFIBBCDField * get_TableID_EXT_MODULE_PRIV(void)=0;
   virtual void set_TableID_EXT_MODULE_PRIV(TFIBBCDField * TableID_EXT_MODULE_PRIV)=0;

   __property TFIBBCDField * TableIDGRPUSER_EXT_MODULE_PRIV = {read = get_TableIDGRPUSER_EXT_MODULE_PRIV , write = set_TableIDGRPUSER_EXT_MODULE_PRIV};
   virtual TFIBBCDField * get_TableIDGRPUSER_EXT_MODULE_PRIV(void)=0;
   virtual void set_TableIDGRPUSER_EXT_MODULE_PRIV(TFIBBCDField * TableIDGRPUSER_EXT_MODULE_PRIV)=0;

   __property TpFIBDataSet * SprGrpUser = {read = get_SprGrpUser , write = set_SprGrpUser};
   virtual TpFIBDataSet * get_SprGrpUser(void)=0;
   virtual void set_SprGrpUser(TpFIBDataSet * SprGrpUser)=0;

   __property TDataSource * DataSourceSprGrpUser = {read = get_DataSourceSprGrpUser , write = set_DataSourceSprGrpUser};
   virtual TDataSource * get_DataSourceSprGrpUser(void)=0;
   virtual void set_DataSourceSprGrpUser(TDataSource * DataSourceSprGrpUser)=0;

   __property TFIBBCDField * SprGrpUserID_SGRPUSER = {read = get_SprGrpUserID_SGRPUSER , write = set_SprGrpUserID_SGRPUSER};
   virtual TFIBBCDField * get_SprGrpUserID_SGRPUSER(void)=0;
   virtual void set_SprGrpUserID_SGRPUSER(TFIBBCDField * SprGrpUserID_SGRPUSER)=0;

   __property TpFIBQuery * Query = {read = get_Query , write = set_Query};
   virtual TpFIBQuery * get_Query(void)=0;
   virtual void set_Query(TpFIBQuery * Query)=0;

   __property TFIBWideStringField * SprGrpUserNAME_SGRPUSER = {read = get_SprGrpUserNAME_SGRPUSER , write = set_SprGrpUserNAME_SGRPUSER};
   virtual TFIBWideStringField * get_SprGrpUserNAME_SGRPUSER(void)=0;
   virtual void set_SprGrpUserNAME_SGRPUSER(TFIBWideStringField * SprGrpUserNAME_SGRPUSER)=0;

   __property TFIBWideStringField * SprGrpUserROLE_SGRPUSER = {read = get_SprGrpUserROLE_SGRPUSER , write = set_SprGrpUserROLE_SGRPUSER};
   virtual TFIBWideStringField * get_SprGrpUserROLE_SGRPUSER(void)=0;
   virtual void set_SprGrpUserROLE_SGRPUSER(TFIBWideStringField * SprGrpUserROLE_SGRPUSER)=0;

   __property __int64 IdModule = {read = get_IdModule , write = set_IdModule};
   virtual __int64 get_IdModule(void)=0;
   virtual void set_IdModule(__int64 IdModule)=0;

   __property __int64 IdGrpUser = {read = get_IdGrpUser , write = set_IdGrpUser};
   virtual __int64 get_IdGrpUser(void)=0;
   virtual void set_IdGrpUser(__int64 IdGrpUser)=0;

   virtual void OpenTable(__int64 id_module)=0;
   virtual void SaveIsmen(void)=0;
   virtual void CancelIsmen(void)=0;
   virtual void DeleteElement(__int64 id)=0;
   virtual bool CheckPriv(__int64 id_module, __int64 idgrp_user)=0;
};
#define IID_IDMExtModulePriv __uuidof(IDMExtModulePriv)
#endif
