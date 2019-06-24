#ifndef UDMSprStorageLocationImplH
#define UDMSprStorageLocationImplH
#include "IDMSprStorageLocation.h"
#include "UDMSprStorageLocation.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprStorageLocationImpl)) TDMSprStorageLocationImpl : public IDMSprStorageLocation
{
public:
   TDMSprStorageLocationImpl();
   ~TDMSprStorageLocationImpl();
   TDMSprStorageLocation * Object;
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

//IDMSprStorageLocation
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

   virtual TFIBLargeIntField * get_TableID_SMHRAN(void);
   virtual void set_TableID_SMHRAN(TFIBLargeIntField * TableID_SMHRAN);

   virtual TFIBLargeIntField * get_TableIDBASE_SMHRAN(void);
   virtual void set_TableIDBASE_SMHRAN(TFIBLargeIntField * TableIDBASE_SMHRAN);

   virtual TFIBLargeIntField * get_TableIDGRP_SMHRAN(void);
   virtual void set_TableIDGRP_SMHRAN(TFIBLargeIntField * TableIDGRP_SMHRAN);

   virtual TFIBWideStringField * get_TableNAME_SMHRAN(void);
   virtual void set_TableNAME_SMHRAN(TFIBWideStringField * TableNAME_SMHRAN);

   virtual TFIBLargeIntField * get_TableIDSKLAD_SMHRAN(void);
   virtual void set_TableIDSKLAD_SMHRAN(TFIBLargeIntField * TableIDSKLAD_SMHRAN);

   virtual TFIBSmallIntField * get_TableFL_DOSTUPNO_SMHRAN(void);
   virtual void set_TableFL_DOSTUPNO_SMHRAN(TFIBSmallIntField * TableFL_DOSTUPNO_SMHRAN);

   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TFIBLargeIntField * get_ElementID_SMHRAN(void);
   virtual void set_ElementID_SMHRAN(TFIBLargeIntField * ElementID_SMHRAN);

   virtual TFIBLargeIntField * get_ElementIDBASE_SMHRAN(void);
   virtual void set_ElementIDBASE_SMHRAN(TFIBLargeIntField * ElementIDBASE_SMHRAN);

   virtual TFIBLargeIntField * get_ElementIDGRP_SMHRAN(void);
   virtual void set_ElementIDGRP_SMHRAN(TFIBLargeIntField * ElementIDGRP_SMHRAN);

   virtual TFIBWideStringField * get_ElementNAME_SMHRAN(void);
   virtual void set_ElementNAME_SMHRAN(TFIBWideStringField * ElementNAME_SMHRAN);

   virtual TFIBLargeIntField * get_ElementIDSKLAD_SMHRAN(void);
   virtual void set_ElementIDSKLAD_SMHRAN(TFIBLargeIntField * ElementIDSKLAD_SMHRAN);

   virtual TFIBSmallIntField * get_ElementFL_DOSTUPNO_SMHRAN(void);
   virtual void set_ElementFL_DOSTUPNO_SMHRAN(TFIBSmallIntField * ElementFL_DOSTUPNO_SMHRAN);

   virtual __int64 get_IdSklad(void);
   virtual void set_IdSklad(__int64 IdSklad);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual bool OpenTable(__int64 id_sklad, __int64 id_grp,bool all);
   virtual bool NewElement(__int64 id_sklad, __int64 id_grp);
   virtual bool OpenElement(__int64 id);
   virtual bool DeleteElement(__int64 id);
   virtual bool ChangeGrp(__int64 id_new_grp,__int64 id_mhran);
   virtual bool SaveElement(void);
};
#define CLSID_TDMSprStorageLocationImpl __uuidof(TDMSprStorageLocationImpl)
#endif
