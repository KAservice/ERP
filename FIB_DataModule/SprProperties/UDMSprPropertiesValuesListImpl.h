#ifndef UDMSprPropertiesValuesListImplH
#define UDMSprPropertiesValuesListImplH
#include "IDMSprPropertiesValuesList.h"
#include "UDMSprPropertiesValuesList.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprPropertiesValuesListImpl)) TDMSprPropertiesValuesListImpl : public IDMSprPropertiesValuesList
{
public:
   TDMSprPropertiesValuesListImpl();
   ~TDMSprPropertiesValuesListImpl();
   TDMSprPropertiesValuesList * Object;
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

//IDMSprPropertiesValuesList
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

   virtual TpFIBQuery * get_Query(void);
   virtual void set_Query(TpFIBQuery * Query);

   virtual TFIBLargeIntField * get_TableID_SPROPVALUELIST(void);
   virtual void set_TableID_SPROPVALUELIST(TFIBLargeIntField * TableID_SPROPVALUELIST);

   virtual TFIBLargeIntField * get_TableIDBASE_SPROPVALUELIST(void);
   virtual void set_TableIDBASE_SPROPVALUELIST(TFIBLargeIntField * TableIDBASE_SPROPVALUELIST);

   virtual TFIBWideStringField * get_TableGID_SPROPVALUELIST(void);
   virtual void set_TableGID_SPROPVALUELIST(TFIBWideStringField * TableGID_SPROPVALUELIST);

   virtual TFIBLargeIntField * get_TableIDPROP_SPROPVALUELIST(void);
   virtual void set_TableIDPROP_SPROPVALUELIST(TFIBLargeIntField * TableIDPROP_SPROPVALUELIST);

   virtual TFIBWideStringField * get_TableNAME_SPROPVALUELIST(void);
   virtual void set_TableNAME_SPROPVALUELIST(TFIBWideStringField * TableNAME_SPROPVALUELIST);

   virtual TFIBLargeIntField * get_ElementID_SPROPVALUELIST(void);
   virtual void set_ElementID_SPROPVALUELIST(TFIBLargeIntField * ElementID_SPROPVALUELIST);

   virtual TFIBLargeIntField * get_ElementIDBASE_SPROPVALUELIST(void);
   virtual void set_ElementIDBASE_SPROPVALUELIST(TFIBLargeIntField * ElementIDBASE_SPROPVALUELIST);

   virtual TFIBWideStringField * get_ElementGID_SPROPVALUELIST(void);
   virtual void set_ElementGID_SPROPVALUELIST(TFIBWideStringField * ElementGID_SPROPVALUELIST);

   virtual TFIBLargeIntField * get_ElementIDPROP_SPROPVALUELIST(void);
   virtual void set_ElementIDPROP_SPROPVALUELIST(TFIBLargeIntField * ElementIDPROP_SPROPVALUELIST);

   virtual TFIBWideStringField * get_ElementNAME_SPROPVALUELIST(void);
   virtual void set_ElementNAME_SPROPVALUELIST(TFIBWideStringField * ElementNAME_SPROPVALUELIST);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual void OpenTable(__int64 id_prop);
   virtual int OpenElement(__int64 id);
   virtual bool NewElement(__int64 id_prop);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
};
#define CLSID_TDMSprPropertiesValuesListImpl __uuidof(TDMSprPropertiesValuesListImpl)
#endif
