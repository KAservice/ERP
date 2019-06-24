#ifndef UDMSprPropertiesNaborGrpImplH
#define UDMSprPropertiesNaborGrpImplH
#include "IDMSprPropertiesNaborGrp.h"
#include "UDMSprPropertiesNaborGrp.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprPropertiesNaborGrpImpl)) TDMSprPropertiesNaborGrpImpl : public IDMSprPropertiesNaborGrp
{
public:
   TDMSprPropertiesNaborGrpImpl();
   ~TDMSprPropertiesNaborGrpImpl();
   TDMSprPropertiesNaborGrp * Object;
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

//IDMSprPropertiesNaborGrp
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

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBLargeIntField * get_TableID_SPROPNABOR_GRP(void);
   virtual void set_TableID_SPROPNABOR_GRP(TFIBLargeIntField * TableID_SPROPNABOR_GRP);

   virtual TFIBLargeIntField * get_TableIDBASE_SPROPNABOR_GRP(void);
   virtual void set_TableIDBASE_SPROPNABOR_GRP(TFIBLargeIntField * TableIDBASE_SPROPNABOR_GRP);

   virtual TFIBWideStringField * get_TableGID_SPROPNABOR_GRP(void);
   virtual void set_TableGID_SPROPNABOR_GRP(TFIBWideStringField * TableGID_SPROPNABOR_GRP);

   virtual TFIBLargeIntField * get_TableIDGRP_SPROPNABOR_GRP(void);
   virtual void set_TableIDGRP_SPROPNABOR_GRP(TFIBLargeIntField * TableIDGRP_SPROPNABOR_GRP);

   virtual TFIBWideStringField * get_TableNAME_SPROPNABOR_GRP(void);
   virtual void set_TableNAME_SPROPNABOR_GRP(TFIBWideStringField * TableNAME_SPROPNABOR_GRP);

   virtual TFIBLargeIntField * get_ElementID_SPROPNABOR_GRP(void);
   virtual void set_ElementID_SPROPNABOR_GRP(TFIBLargeIntField * ElementID_SPROPNABOR_GRP);

   virtual TFIBLargeIntField * get_ElementIDBASE_SPROPNABOR_GRP(void);
   virtual void set_ElementIDBASE_SPROPNABOR_GRP(TFIBLargeIntField * ElementIDBASE_SPROPNABOR_GRP);

   virtual TFIBWideStringField * get_ElementGID_SPROPNABOR_GRP(void);
   virtual void set_ElementGID_SPROPNABOR_GRP(TFIBWideStringField * ElementGID_SPROPNABOR_GRP);

   virtual TFIBLargeIntField * get_ElementIDGRP_SPROPNABOR_GRP(void);
   virtual void set_ElementIDGRP_SPROPNABOR_GRP(TFIBLargeIntField * ElementIDGRP_SPROPNABOR_GRP);

   virtual TFIBWideStringField * get_ElementNAME_SPROPNABOR_GRP(void);
   virtual void set_ElementNAME_SPROPNABOR_GRP(TFIBWideStringField * ElementNAME_SPROPNABOR_GRP);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(__int64 id_grp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual __int64 FindPoName(UnicodeString name);
};
#define CLSID_TDMSprPropertiesNaborGrpImpl __uuidof(TDMSprPropertiesNaborGrpImpl)
#endif
