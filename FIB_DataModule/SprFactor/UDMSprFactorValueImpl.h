#ifndef UDMSprFactorValueImplH
#define UDMSprFactorValueImplH
#include "IDMSprFactorValue.h"
#include "UDMSprFactorValue.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprFactorValueImpl)) TDMSprFactorValueImpl : public IDMSprFactorValue
{
public:
   TDMSprFactorValueImpl();
   ~TDMSprFactorValueImpl();
   TDMSprFactorValue * Object;
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

//IDMSprFactorValue
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

   virtual TFIBLargeIntField * get_TableID_SFACTOR_VAL(void);
   virtual void set_TableID_SFACTOR_VAL(TFIBLargeIntField * TableID_SFACTOR_VAL);

   virtual TFIBWideStringField * get_TableGID_SFACTOR_VAL(void);
   virtual void set_TableGID_SFACTOR_VAL(TFIBWideStringField * TableGID_SFACTOR_VAL);

   virtual TFIBLargeIntField * get_TableIDBASE_SFACTOR_VAL(void);
   virtual void set_TableIDBASE_SFACTOR_VAL(TFIBLargeIntField * TableIDBASE_SFACTOR_VAL);

   virtual TFIBLargeIntField * get_TableIDPRODUCE_SFACTOR_VAL(void);
   virtual void set_TableIDPRODUCE_SFACTOR_VAL(TFIBLargeIntField * TableIDPRODUCE_SFACTOR_VAL);

   virtual TFIBLargeIntField * get_TableIDFACTOR_SFACTOR_VAL(void);
   virtual void set_TableIDFACTOR_SFACTOR_VAL(TFIBLargeIntField * TableIDFACTOR_SFACTOR_VAL);

   virtual TFIBBCDField * get_TableVALUE_SFACTOR_VAL(void);
   virtual void set_TableVALUE_SFACTOR_VAL(TFIBBCDField * TableVALUE_SFACTOR_VAL);

   virtual TFIBLargeIntField * get_ElementID_SFACTOR_VAL(void);
   virtual void set_ElementID_SFACTOR_VAL(TFIBLargeIntField * ElementID_SFACTOR_VAL);

   virtual TFIBWideStringField * get_ElementGID_SFACTOR_VAL(void);
   virtual void set_ElementGID_SFACTOR_VAL(TFIBWideStringField * ElementGID_SFACTOR_VAL);

   virtual TFIBLargeIntField * get_ElementIDBASE_SFACTOR_VAL(void);
   virtual void set_ElementIDBASE_SFACTOR_VAL(TFIBLargeIntField * ElementIDBASE_SFACTOR_VAL);

   virtual TFIBLargeIntField * get_ElementIDPRODUCE_SFACTOR_VAL(void);
   virtual void set_ElementIDPRODUCE_SFACTOR_VAL(TFIBLargeIntField * ElementIDPRODUCE_SFACTOR_VAL);

   virtual TFIBLargeIntField * get_ElementIDFACTOR_SFACTOR_VAL(void);
   virtual void set_ElementIDFACTOR_SFACTOR_VAL(TFIBLargeIntField * ElementIDFACTOR_SFACTOR_VAL);

   virtual TFIBBCDField * get_ElementVALUE_SFACTOR_VAL(void);
   virtual void set_ElementVALUE_SFACTOR_VAL(TFIBBCDField * ElementVALUE_SFACTOR_VAL);

   virtual __int64 get_IdFactor(void);
   virtual void set_IdFactor(__int64 IdFactor);

   virtual __int64 get_IdProduce(void);
   virtual void set_IdProduce(__int64 IdProduce);

   virtual bool OpenTable(__int64 id_produce);
   virtual bool SaveIsmen(void);
   virtual void CancelIsmen(void);
   virtual bool OpenElement(__int64 Id);
   virtual bool NewElement(void);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 Id);
   virtual __int64 FindElement(__int64 id_factor, __int64 id_produce);
   virtual bool UpdateSpisokFactors(void);
};
#define CLSID_TDMSprFactorValueImpl __uuidof(TDMSprFactorValueImpl)
#endif
