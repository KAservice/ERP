#ifndef UDMSprNomPropertiesValueImplH
#define UDMSprNomPropertiesValueImplH
#include "IDMSprNomPropertiesValue.h"
#include "UDMSprNomPropertiesValue.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprNomPropertiesValueImpl)) TDMSprNomPropertiesValueImpl : public IDMSprNomPropertiesValue
{
public:
   TDMSprNomPropertiesValueImpl();
   ~TDMSprNomPropertiesValueImpl();
   TDMSprNomPropertiesValue * Object;
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

//IDMSprNomPropertiesValue
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TFIBLargeIntField * get_TableID_SNOMPROPVALUE(void);
   virtual void set_TableID_SNOMPROPVALUE(TFIBLargeIntField * TableID_SNOMPROPVALUE);

   virtual TFIBLargeIntField * get_TableIDBASE_SNOMPROPVALUE(void);
   virtual void set_TableIDBASE_SNOMPROPVALUE(TFIBLargeIntField * TableIDBASE_SNOMPROPVALUE);

   virtual TFIBWideStringField * get_TableGID_SNOMPROPVALUE(void);
   virtual void set_TableGID_SNOMPROPVALUE(TFIBWideStringField * TableGID_SNOMPROPVALUE);

   virtual TFIBLargeIntField * get_TableIDNOM_SNOMPROPVALUE(void);
   virtual void set_TableIDNOM_SNOMPROPVALUE(TFIBLargeIntField * TableIDNOM_SNOMPROPVALUE);

   virtual TFIBLargeIntField * get_TableIDPROP_SNOMPROPVALUE(void);
   virtual void set_TableIDPROP_SNOMPROPVALUE(TFIBLargeIntField * TableIDPROP_SNOMPROPVALUE);

   virtual TFIBLargeIntField * get_TableIDPROPVALLIST_SNOMPROPVALUE(void);
   virtual void set_TableIDPROPVALLIST_SNOMPROPVALUE(TFIBLargeIntField * TableIDPROPVALLIST_SNOMPROPVALUE);

   virtual TFIBWideStringField * get_TableVALTEXT_SNOMPROPVALUE(void);
   virtual void set_TableVALTEXT_SNOMPROPVALUE(TFIBWideStringField * TableVALTEXT_SNOMPROPVALUE);

   virtual TFIBWideStringField * get_TableNAME_SPROP(void);
   virtual void set_TableNAME_SPROP(TFIBWideStringField * TableNAME_SPROP);

   virtual TFIBWideStringField * get_TableNAME_SPROPVALUELIST(void);
   virtual void set_TableNAME_SPROPVALUELIST(TFIBWideStringField * TableNAME_SPROPVALUELIST);

   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TFIBLargeIntField * get_ElementID_SNOMPROPVALUE(void);
   virtual void set_ElementID_SNOMPROPVALUE(TFIBLargeIntField * ElementID_SNOMPROPVALUE);

   virtual TFIBLargeIntField * get_ElementIDBASE_SNOMPROPVALUE(void);
   virtual void set_ElementIDBASE_SNOMPROPVALUE(TFIBLargeIntField * ElementIDBASE_SNOMPROPVALUE);

   virtual TFIBWideStringField * get_ElementGID_SNOMPROPVALUE(void);
   virtual void set_ElementGID_SNOMPROPVALUE(TFIBWideStringField * ElementGID_SNOMPROPVALUE);

   virtual TFIBLargeIntField * get_ElementIDNOM_SNOMPROPVALUE(void);
   virtual void set_ElementIDNOM_SNOMPROPVALUE(TFIBLargeIntField * ElementIDNOM_SNOMPROPVALUE);

   virtual TFIBLargeIntField * get_ElementIDPROP_SNOMPROPVALUE(void);
   virtual void set_ElementIDPROP_SNOMPROPVALUE(TFIBLargeIntField * ElementIDPROP_SNOMPROPVALUE);

   virtual TFIBLargeIntField * get_ElementIDPROPVALLIST_SNOMPROPVALUE(void);
   virtual void set_ElementIDPROPVALLIST_SNOMPROPVALUE(TFIBLargeIntField * ElementIDPROPVALLIST_SNOMPROPVALUE);

   virtual TFIBWideStringField * get_ElementVALTEXT_SNOMPROPVALUE(void);
   virtual void set_ElementVALTEXT_SNOMPROPVALUE(TFIBWideStringField * ElementVALTEXT_SNOMPROPVALUE);

   virtual TFIBWideStringField * get_ElementNAME_SPROP(void);
   virtual void set_ElementNAME_SPROP(TFIBWideStringField * ElementNAME_SPROP);

   virtual TFIBWideStringField * get_ElementNAME_SPROPVALUELIST(void);
   virtual void set_ElementNAME_SPROPVALUELIST(TFIBWideStringField * ElementNAME_SPROPVALUELIST);

   virtual TFIBIntegerField * get_TableINDEX_SNOMPROPVALUE(void);
   virtual void set_TableINDEX_SNOMPROPVALUE(TFIBIntegerField * TableINDEX_SNOMPROPVALUE);

   virtual TFIBIntegerField * get_ElementINDEX_SNOMPROPVALUE(void);
   virtual void set_ElementINDEX_SNOMPROPVALUE(TFIBIntegerField * ElementINDEX_SNOMPROPVALUE);

   virtual TFIBWideStringField * get_TableNAME_FOR_PRINT_SPROP(void);
   virtual void set_TableNAME_FOR_PRINT_SPROP(TFIBWideStringField * TableNAME_FOR_PRINT_SPROP);

   virtual TFIBWideStringField * get_TableNAME_SPROP_GRP(void);
   virtual void set_TableNAME_SPROP_GRP(TFIBWideStringField * TableNAME_SPROP_GRP);

   virtual TFIBWideStringField * get_TableNAME_FOR_PRINT_SPROP_GRP(void);
   virtual void set_TableNAME_FOR_PRINT_SPROP_GRP(TFIBWideStringField * TableNAME_FOR_PRINT_SPROP_GRP);

   virtual TFIBSmallIntField * get_TableADD1_SNOMPROPVALUE(void);
   virtual void set_TableADD1_SNOMPROPVALUE(TFIBSmallIntField * TableADD1_SNOMPROPVALUE);

   virtual TFIBSmallIntField * get_TableADD2_SNOMPROPVALUE(void);
   virtual void set_TableADD2_SNOMPROPVALUE(TFIBSmallIntField * TableADD2_SNOMPROPVALUE);

   virtual TFIBSmallIntField * get_TableADD3_SNOMPROPVALUE(void);
   virtual void set_TableADD3_SNOMPROPVALUE(TFIBSmallIntField * TableADD3_SNOMPROPVALUE);

   virtual TFIBSmallIntField * get_TableADD4_SNOMPROPVALUE(void);
   virtual void set_TableADD4_SNOMPROPVALUE(TFIBSmallIntField * TableADD4_SNOMPROPVALUE);

   virtual TFIBSmallIntField * get_TableADD5_SNOMPROPVALUE(void);
   virtual void set_TableADD5_SNOMPROPVALUE(TFIBSmallIntField * TableADD5_SNOMPROPVALUE);

   virtual TFIBSmallIntField * get_ElementADD1_SNOMPROPVALUE(void);
   virtual void set_ElementADD1_SNOMPROPVALUE(TFIBSmallIntField * ElementADD1_SNOMPROPVALUE);

   virtual TFIBSmallIntField * get_ElementADD2_SNOMPROPVALUE(void);
   virtual void set_ElementADD2_SNOMPROPVALUE(TFIBSmallIntField * ElementADD2_SNOMPROPVALUE);

   virtual TFIBSmallIntField * get_ElementADD3_SNOMPROPVALUE(void);
   virtual void set_ElementADD3_SNOMPROPVALUE(TFIBSmallIntField * ElementADD3_SNOMPROPVALUE);

   virtual TFIBSmallIntField * get_ElementADD4_SNOMPROPVALUE(void);
   virtual void set_ElementADD4_SNOMPROPVALUE(TFIBSmallIntField * ElementADD4_SNOMPROPVALUE);

   virtual TFIBSmallIntField * get_ElementADD5_SNOMPROPVALUE(void);
   virtual void set_ElementADD5_SNOMPROPVALUE(TFIBSmallIntField * ElementADD5_SNOMPROPVALUE);

   virtual TpFIBQuery * get_Query(void);
   virtual void set_Query(TpFIBQuery * Query);

   virtual __int64 get_IdNom(void);
   virtual void set_IdNom(__int64 IdNom);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual void OpenTable(__int64 id_nom);
   virtual bool NewElement(__int64 id_nom);
   virtual int OpenElement(__int64 id );
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual __int64 GetIdPoIdNomIdProp(__int64 id_nom, __int64 id_prop);
};
#define CLSID_TDMSprNomPropertiesValueImpl __uuidof(TDMSprNomPropertiesValueImpl)
#endif
