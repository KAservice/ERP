#ifndef UDMSprStorageLocationGrpImplH
#define UDMSprStorageLocationGrpImplH
#include "IDMSprStorageLocationGrp.h"
#include "UDMSprStorageLocationGrp.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprStorageLocationGrpImpl)) TDMSprStorageLocationGrpImpl : public IDMSprStorageLocationGrp
{
public:
   TDMSprStorageLocationGrpImpl();
   ~TDMSprStorageLocationGrpImpl();
   TDMSprStorageLocationGrp * Object;
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

//IDMSprStorageLocationGrp
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBLargeIntField * get_TableID_SMHRAN_GRP(void);
   virtual void set_TableID_SMHRAN_GRP(TFIBLargeIntField * TableID_SMHRAN_GRP);

   virtual TFIBLargeIntField * get_TableIDBASE_SMHRAN_GRP(void);
   virtual void set_TableIDBASE_SMHRAN_GRP(TFIBLargeIntField * TableIDBASE_SMHRAN_GRP);

   virtual TFIBLargeIntField * get_TableIDGRP_SMHRAN_GRP(void);
   virtual void set_TableIDGRP_SMHRAN_GRP(TFIBLargeIntField * TableIDGRP_SMHRAN_GRP);

   virtual TFIBWideStringField * get_TableNAME_SMHRAN_GRP(void);
   virtual void set_TableNAME_SMHRAN_GRP(TFIBWideStringField * TableNAME_SMHRAN_GRP);

   virtual TFIBLargeIntField * get_TableIDSKLAD_SMHRAN_GRP(void);
   virtual void set_TableIDSKLAD_SMHRAN_GRP(TFIBLargeIntField * TableIDSKLAD_SMHRAN_GRP);

   virtual TFIBLargeIntField * get_ElementID_SMHRAN_GRP(void);
   virtual void set_ElementID_SMHRAN_GRP(TFIBLargeIntField * ElementID_SMHRAN_GRP);

   virtual TFIBLargeIntField * get_ElementIDBASE_SMHRAN_GRP(void);
   virtual void set_ElementIDBASE_SMHRAN_GRP(TFIBLargeIntField * ElementIDBASE_SMHRAN_GRP);

   virtual TFIBLargeIntField * get_ElementIDGRP_SMHRAN_GRP(void);
   virtual void set_ElementIDGRP_SMHRAN_GRP(TFIBLargeIntField * ElementIDGRP_SMHRAN_GRP);

   virtual TFIBWideStringField * get_ElementNAME_SMHRAN_GRP(void);
   virtual void set_ElementNAME_SMHRAN_GRP(TFIBWideStringField * ElementNAME_SMHRAN_GRP);

   virtual TFIBLargeIntField * get_ElementIDSKLAD_SMHRAN_GRP(void);
   virtual void set_ElementIDSKLAD_SMHRAN_GRP(TFIBLargeIntField * ElementIDSKLAD_SMHRAN_GRP);

   virtual __int64 get_IdSklad(void);
   virtual void set_IdSklad(__int64 IdSklad);

   virtual void OpenTable(__int64 id_sklad);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(__int64 id_sklad, __int64 id_grp);
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 id);
};
#define CLSID_TDMSprStorageLocationGrpImpl __uuidof(TDMSprStorageLocationGrpImpl)
#endif
