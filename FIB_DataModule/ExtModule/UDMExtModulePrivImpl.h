#ifndef UDMExtModulePrivImplH
#define UDMExtModulePrivImplH
#include "IDMExtModulePriv.h"
#include "UDMExtModulePriv.h"
//---------------------------------------------------------------
class __declspec(uuid("{8697514F-F359-42D8-9401-FD8D67CF93EE}")) TDMExtModulePrivImpl : public IDMExtModulePriv
{
public:
   TDMExtModulePrivImpl();
   ~TDMExtModulePrivImpl();
   TDMExtModulePriv * Object;
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

//IDMExtModulePriv
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TFIBBCDField * get_TableIDMODULE_EXT_MODULE_PRIV(void);
   virtual void set_TableIDMODULE_EXT_MODULE_PRIV(TFIBBCDField * TableIDMODULE_EXT_MODULE_PRIV);

   virtual TFIBSmallIntField * get_TableINS_EXT_MODULE_PRIV(void);
   virtual void set_TableINS_EXT_MODULE_PRIV(TFIBSmallIntField * TableINS_EXT_MODULE_PRIV);

   virtual TFIBSmallIntField * get_TableEDIT_EXT_MODULE_PRIV(void);
   virtual void set_TableEDIT_EXT_MODULE_PRIV(TFIBSmallIntField * TableEDIT_EXT_MODULE_PRIV);

   virtual TFIBSmallIntField * get_TableDEL_EXT_MODULE_PRIV(void);
   virtual void set_TableDEL_EXT_MODULE_PRIV(TFIBSmallIntField * TableDEL_EXT_MODULE_PRIV);

   virtual TFIBSmallIntField * get_TableEXEC_EXT_MODULE_PRIV(void);
   virtual void set_TableEXEC_EXT_MODULE_PRIV(TFIBSmallIntField * TableEXEC_EXT_MODULE_PRIV);

   virtual TFIBBCDField * get_TableID_EXT_MODULE_PRIV(void);
   virtual void set_TableID_EXT_MODULE_PRIV(TFIBBCDField * TableID_EXT_MODULE_PRIV);

   virtual TFIBBCDField * get_TableIDGRPUSER_EXT_MODULE_PRIV(void);
   virtual void set_TableIDGRPUSER_EXT_MODULE_PRIV(TFIBBCDField * TableIDGRPUSER_EXT_MODULE_PRIV);

   virtual TpFIBDataSet * get_SprGrpUser(void);
   virtual void set_SprGrpUser(TpFIBDataSet * SprGrpUser);

   virtual TDataSource * get_DataSourceSprGrpUser(void);
   virtual void set_DataSourceSprGrpUser(TDataSource * DataSourceSprGrpUser);

   virtual TFIBBCDField * get_SprGrpUserID_SGRPUSER(void);
   virtual void set_SprGrpUserID_SGRPUSER(TFIBBCDField * SprGrpUserID_SGRPUSER);

   virtual TpFIBQuery * get_Query(void);
   virtual void set_Query(TpFIBQuery * Query);

   virtual TFIBWideStringField * get_SprGrpUserNAME_SGRPUSER(void);
   virtual void set_SprGrpUserNAME_SGRPUSER(TFIBWideStringField * SprGrpUserNAME_SGRPUSER);

   virtual TFIBWideStringField * get_SprGrpUserROLE_SGRPUSER(void);
   virtual void set_SprGrpUserROLE_SGRPUSER(TFIBWideStringField * SprGrpUserROLE_SGRPUSER);

   virtual __int64 get_IdModule(void);
   virtual void set_IdModule(__int64 IdModule);

   virtual __int64 get_IdGrpUser(void);
   virtual void set_IdGrpUser(__int64 IdGrpUser);

   virtual void OpenTable(__int64 id_module);
   virtual void SaveIsmen(void);
   virtual void CancelIsmen(void);
   virtual void DeleteElement(__int64 id);
   virtual bool CheckPriv(__int64 id_module, __int64 idgrp_user);
};
#define CLSID_TDMExtModulePrivImpl __uuidof(TDMExtModulePrivImpl)
#endif
