#ifndef UDMSprLossFactorValueImplH
#define UDMSprLossFactorValueImplH
#include "IDMSprLossFactorValue.h"
#include "UDMSprLossFactorValue.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprLossFactorValueImpl)) TDMSprLossFactorValueImpl : public IDMSprLossFactorValue
{
public:
   TDMSprLossFactorValueImpl();
   ~TDMSprLossFactorValueImpl();
   TDMSprLossFactorValue * Object;
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

//IDMSprLossFactorValue
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBQuery * get_Query(void);
   virtual void set_Query(TpFIBQuery * Query);

   virtual TpFIBDataSet * get_FactorList(void);
   virtual void set_FactorList(TpFIBDataSet * FactorList);

   virtual TDataSource * get_DataSourceFactorList(void);
   virtual void set_DataSourceFactorList(TDataSource * DataSourceFactorList);

   virtual TFIBLargeIntField * get_FactorListID_SFACTOR(void);
   virtual void set_FactorListID_SFACTOR(TFIBLargeIntField * FactorListID_SFACTOR);

   virtual TFIBWideStringField * get_FactorListNAME_SFACTOR(void);
   virtual void set_FactorListNAME_SFACTOR(TFIBWideStringField * FactorListNAME_SFACTOR);

   virtual TFIBLargeIntField * get_TableID_SLOSS_FACTOR_VAL(void);
   virtual void set_TableID_SLOSS_FACTOR_VAL(TFIBLargeIntField * TableID_SLOSS_FACTOR_VAL);

   virtual TFIBWideStringField * get_TableGID_SLOSS_FACTOR_VAL(void);
   virtual void set_TableGID_SLOSS_FACTOR_VAL(TFIBWideStringField * TableGID_SLOSS_FACTOR_VAL);

   virtual TFIBLargeIntField * get_TableIDBASE_SLOSS_FACTOR_VAL(void);
   virtual void set_TableIDBASE_SLOSS_FACTOR_VAL(TFIBLargeIntField * TableIDBASE_SLOSS_FACTOR_VAL);

   virtual TFIBLargeIntField * get_TableIDFACTOR_SLOSS_FACTOR_VAL(void);
   virtual void set_TableIDFACTOR_SLOSS_FACTOR_VAL(TFIBLargeIntField * TableIDFACTOR_SLOSS_FACTOR_VAL);

   virtual TFIBLargeIntField * get_TableIDLOSS_FACTOR_SLOSS_FACTOR_VAL(void);
   virtual void set_TableIDLOSS_FACTOR_SLOSS_FACTOR_VAL(TFIBLargeIntField * TableIDLOSS_FACTOR_SLOSS_FACTOR_VAL);

   virtual TFIBBCDField * get_TableVAL_SLOSS_FACTOR_VAL(void);
   virtual void set_TableVAL_SLOSS_FACTOR_VAL(TFIBBCDField * TableVAL_SLOSS_FACTOR_VAL);

   virtual TFIBLargeIntField * get_ElementID_SLOSS_FACTOR_VAL(void);
   virtual void set_ElementID_SLOSS_FACTOR_VAL(TFIBLargeIntField * ElementID_SLOSS_FACTOR_VAL);

   virtual TFIBWideStringField * get_ElementGID_SLOSS_FACTOR_VAL(void);
   virtual void set_ElementGID_SLOSS_FACTOR_VAL(TFIBWideStringField * ElementGID_SLOSS_FACTOR_VAL);

   virtual TFIBLargeIntField * get_ElementIDBASE_SLOSS_FACTOR_VAL(void);
   virtual void set_ElementIDBASE_SLOSS_FACTOR_VAL(TFIBLargeIntField * ElementIDBASE_SLOSS_FACTOR_VAL);

   virtual TFIBLargeIntField * get_ElementIDFACTOR_SLOSS_FACTOR_VAL(void);
   virtual void set_ElementIDFACTOR_SLOSS_FACTOR_VAL(TFIBLargeIntField * ElementIDFACTOR_SLOSS_FACTOR_VAL);

   virtual TFIBLargeIntField * get_ElementIDLOSS_FACTOR_SLOSS_FACTOR_VAL(void);
   virtual void set_ElementIDLOSS_FACTOR_SLOSS_FACTOR_VAL(TFIBLargeIntField * ElementIDLOSS_FACTOR_SLOSS_FACTOR_VAL);

   virtual TFIBBCDField * get_ElementVAL_SLOSS_FACTOR_VAL(void);
   virtual void set_ElementVAL_SLOSS_FACTOR_VAL(TFIBBCDField * ElementVAL_SLOSS_FACTOR_VAL);

   virtual __int64 get_IdFactor(void);
   virtual void set_IdFactor(__int64 IdFactor);

   virtual __int64 get_IdLossFactor(void);
   virtual void set_IdLossFactor(__int64 IdLossFactor);

   virtual bool OpenTable(__int64 id_loss_factor);
   virtual bool SaveIsmen(void);
   virtual void CancelIsmen(void);
   virtual bool OpenElement(__int64 id);
   virtual bool NewElement(void);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual __int64 FindElement(__int64 id_factor, __int64 id_loss_factor);
   virtual bool UpdateSpisokFactors(void);
};
#define CLSID_TDMSprLossFactorValueImpl __uuidof(TDMSprLossFactorValueImpl)
#endif
