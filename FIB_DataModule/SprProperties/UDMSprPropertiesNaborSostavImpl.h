#ifndef UDMSprPropertiesNaborSostavImplH
#define UDMSprPropertiesNaborSostavImplH
#include "IDMSprPropertiesNaborSostav.h"
#include "UDMSprPropertiesNaborSostav.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprPropertiesNaborSostavImpl)) TDMSprPropertiesNaborSostavImpl : public IDMSprPropertiesNaborSostav
{
public:
   TDMSprPropertiesNaborSostavImpl();
   ~TDMSprPropertiesNaborSostavImpl();
   TDMSprPropertiesNaborSostav * Object;
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

//IDMSprPropertiesNaborSostav
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

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBLargeIntField * get_TableID_SPROPNABOR_SOST(void);
   virtual void set_TableID_SPROPNABOR_SOST(TFIBLargeIntField * TableID_SPROPNABOR_SOST);

   virtual TFIBLargeIntField * get_TableIDBASE_SPROPNABOR_SOST(void);
   virtual void set_TableIDBASE_SPROPNABOR_SOST(TFIBLargeIntField * TableIDBASE_SPROPNABOR_SOST);

   virtual TFIBWideStringField * get_TableGID_SPROPNABOR_SOST(void);
   virtual void set_TableGID_SPROPNABOR_SOST(TFIBWideStringField * TableGID_SPROPNABOR_SOST);

   virtual TFIBLargeIntField * get_TableIDPROPNABOR_SPROPNABOR_SOST(void);
   virtual void set_TableIDPROPNABOR_SPROPNABOR_SOST(TFIBLargeIntField * TableIDPROPNABOR_SPROPNABOR_SOST);

   virtual TFIBLargeIntField * get_TableIDPROP_SPROPNABOR_SOST(void);
   virtual void set_TableIDPROP_SPROPNABOR_SOST(TFIBLargeIntField * TableIDPROP_SPROPNABOR_SOST);

   virtual TFIBIntegerField * get_TableINDEXSORT_SPROPNABOR_SOST(void);
   virtual void set_TableINDEXSORT_SPROPNABOR_SOST(TFIBIntegerField * TableINDEXSORT_SPROPNABOR_SOST);

   virtual TFIBLargeIntField * get_ElementID_SPROPNABOR_SOST(void);
   virtual void set_ElementID_SPROPNABOR_SOST(TFIBLargeIntField * ElementID_SPROPNABOR_SOST);

   virtual TFIBLargeIntField * get_ElementIDBASE_SPROPNABOR_SOST(void);
   virtual void set_ElementIDBASE_SPROPNABOR_SOST(TFIBLargeIntField * ElementIDBASE_SPROPNABOR_SOST);

   virtual TFIBWideStringField * get_ElementGID_SPROPNABOR_SOST(void);
   virtual void set_ElementGID_SPROPNABOR_SOST(TFIBWideStringField * ElementGID_SPROPNABOR_SOST);

   virtual TFIBLargeIntField * get_ElementIDPROPNABOR_SPROPNABOR_SOST(void);
   virtual void set_ElementIDPROPNABOR_SPROPNABOR_SOST(TFIBLargeIntField * ElementIDPROPNABOR_SPROPNABOR_SOST);

   virtual TFIBLargeIntField * get_ElementIDPROP_SPROPNABOR_SOST(void);
   virtual void set_ElementIDPROP_SPROPNABOR_SOST(TFIBLargeIntField * ElementIDPROP_SPROPNABOR_SOST);

   virtual TFIBIntegerField * get_ElementINDEXSORT_SPROPNABOR_SOST(void);
   virtual void set_ElementINDEXSORT_SPROPNABOR_SOST(TFIBIntegerField * ElementINDEXSORT_SPROPNABOR_SOST);

   virtual TFIBWideStringField * get_TableNAME_SPROP(void);
   virtual void set_TableNAME_SPROP(TFIBWideStringField * TableNAME_SPROP);

   virtual TFIBWideStringField * get_ElementNAME_SPROP(void);
   virtual void set_ElementNAME_SPROP(TFIBWideStringField * ElementNAME_SPROP);

   virtual TFIBWideStringField * get_TableNAME_FOR_PRINT_SPROP(void);
   virtual void set_TableNAME_FOR_PRINT_SPROP(TFIBWideStringField * TableNAME_FOR_PRINT_SPROP);

   virtual TFIBWideStringField * get_TableNAME_SPROP_GRP(void);
   virtual void set_TableNAME_SPROP_GRP(TFIBWideStringField * TableNAME_SPROP_GRP);

   virtual TFIBWideStringField * get_TableNAME_FOR_PRINT_SPROP_GRP(void);
   virtual void set_TableNAME_FOR_PRINT_SPROP_GRP(TFIBWideStringField * TableNAME_FOR_PRINT_SPROP_GRP);

   virtual TFIBSmallIntField * get_TableADD1_SPROPNABOR_SOST(void);
   virtual void set_TableADD1_SPROPNABOR_SOST(TFIBSmallIntField * TableADD1_SPROPNABOR_SOST);

   virtual TFIBSmallIntField * get_TableADD2_SPROPNABOR_SOST(void);
   virtual void set_TableADD2_SPROPNABOR_SOST(TFIBSmallIntField * TableADD2_SPROPNABOR_SOST);

   virtual TFIBSmallIntField * get_TableADD3_SPROPNABOR_SOST(void);
   virtual void set_TableADD3_SPROPNABOR_SOST(TFIBSmallIntField * TableADD3_SPROPNABOR_SOST);

   virtual TFIBSmallIntField * get_TableADD4_SPROPNABOR_SOST(void);
   virtual void set_TableADD4_SPROPNABOR_SOST(TFIBSmallIntField * TableADD4_SPROPNABOR_SOST);

   virtual TFIBSmallIntField * get_TableADD5_SPROPNABOR_SOST(void);
   virtual void set_TableADD5_SPROPNABOR_SOST(TFIBSmallIntField * TableADD5_SPROPNABOR_SOST);

   virtual TFIBSmallIntField * get_ElementADD1_SPROPNABOR_SOST(void);
   virtual void set_ElementADD1_SPROPNABOR_SOST(TFIBSmallIntField * ElementADD1_SPROPNABOR_SOST);

   virtual TFIBSmallIntField * get_ElementADD2_SPROPNABOR_SOST(void);
   virtual void set_ElementADD2_SPROPNABOR_SOST(TFIBSmallIntField * ElementADD2_SPROPNABOR_SOST);

   virtual TFIBSmallIntField * get_ElementADD3_SPROPNABOR_SOST(void);
   virtual void set_ElementADD3_SPROPNABOR_SOST(TFIBSmallIntField * ElementADD3_SPROPNABOR_SOST);

   virtual TFIBSmallIntField * get_ElementADD4_SPROPNABOR_SOST(void);
   virtual void set_ElementADD4_SPROPNABOR_SOST(TFIBSmallIntField * ElementADD4_SPROPNABOR_SOST);

   virtual TFIBSmallIntField * get_ElementADD5_SPROPNABOR_SOST(void);
   virtual void set_ElementADD5_SPROPNABOR_SOST(TFIBSmallIntField * ElementADD5_SPROPNABOR_SOST);

   virtual void OpenTable(__int64 id_nabor);
   virtual int OpenElement(__int64 id);
   virtual bool NewElement(__int64 id_nabor);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
};
#define CLSID_TDMSprPropertiesNaborSostavImpl __uuidof(TDMSprPropertiesNaborSostavImpl)
#endif
