#ifndef UREM_DMSprModelPropertiesValueImplH
#define UREM_DMSprModelPropertiesValueImplH
#include "IREM_DMSprModelPropertiesValue.h"
#include "UREM_DMSprModelPropertiesValue.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMSprModelPropertiesValueImpl)) TREM_DMSprModelPropertiesValueImpl : public IREM_DMSprModelPropertiesValue
{
public:
   TREM_DMSprModelPropertiesValueImpl();
   ~TREM_DMSprModelPropertiesValueImpl();
   TREM_DMSprModelPropertiesValue * Object;
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

//IREM_DMSprModelPropertiesValue
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TpFIBQuery * get_Query(void);
   virtual void set_Query(TpFIBQuery * Query);

   virtual TFIBLargeIntField * get_TableID_REM_SMODEL_PROPVAL(void);
   virtual void set_TableID_REM_SMODEL_PROPVAL(TFIBLargeIntField * TableID_REM_SMODEL_PROPVAL);

   virtual TFIBLargeIntField * get_TableIDBASE_REM_SMODEL_PROPVAL(void);
   virtual void set_TableIDBASE_REM_SMODEL_PROPVAL(TFIBLargeIntField * TableIDBASE_REM_SMODEL_PROPVAL);

   virtual TFIBWideStringField * get_TableGID_REM_SMODEL_PROPVAL(void);
   virtual void set_TableGID_REM_SMODEL_PROPVAL(TFIBWideStringField * TableGID_REM_SMODEL_PROPVAL);

   virtual TFIBLargeIntField * get_TableIDMODEL_REM_SMODEL_PROPVAL(void);
   virtual void set_TableIDMODEL_REM_SMODEL_PROPVAL(TFIBLargeIntField * TableIDMODEL_REM_SMODEL_PROPVAL);

   virtual TFIBLargeIntField * get_TableIDPROP_REM_SMODEL_PROPVAL(void);
   virtual void set_TableIDPROP_REM_SMODEL_PROPVAL(TFIBLargeIntField * TableIDPROP_REM_SMODEL_PROPVAL);

   virtual TFIBLargeIntField * get_TableIDPVL_REM_SMODEL_PROPVAL(void);
   virtual void set_TableIDPVL_REM_SMODEL_PROPVAL(TFIBLargeIntField * TableIDPVL_REM_SMODEL_PROPVAL);

   virtual TFIBWideStringField * get_TableVALTEXT_REM_SMODEL_PROPVAL(void);
   virtual void set_TableVALTEXT_REM_SMODEL_PROPVAL(TFIBWideStringField * TableVALTEXT_REM_SMODEL_PROPVAL);

   virtual TFIBDateTimeField * get_TableISM_REM_SMODEL_PROPVAL(void);
   virtual void set_TableISM_REM_SMODEL_PROPVAL(TFIBDateTimeField * TableISM_REM_SMODEL_PROPVAL);

   virtual TFIBWideStringField * get_TableNAME_SPROP(void);
   virtual void set_TableNAME_SPROP(TFIBWideStringField * TableNAME_SPROP);

   virtual TFIBWideStringField * get_TableNAME_FOR_PRINT_SPROP(void);
   virtual void set_TableNAME_FOR_PRINT_SPROP(TFIBWideStringField * TableNAME_FOR_PRINT_SPROP);

   virtual TFIBWideStringField * get_TableNAME_SPROPVALUELIST(void);
   virtual void set_TableNAME_SPROPVALUELIST(TFIBWideStringField * TableNAME_SPROPVALUELIST);

   virtual TFIBWideStringField * get_TableNAME_SPROP_GRP(void);
   virtual void set_TableNAME_SPROP_GRP(TFIBWideStringField * TableNAME_SPROP_GRP);

   virtual TFIBWideStringField * get_TableNAME_FOR_PRINT_SPROP_GRP(void);
   virtual void set_TableNAME_FOR_PRINT_SPROP_GRP(TFIBWideStringField * TableNAME_FOR_PRINT_SPROP_GRP);

   virtual TFIBLargeIntField * get_ElementID_REM_SMODEL_PROPVAL(void);
   virtual void set_ElementID_REM_SMODEL_PROPVAL(TFIBLargeIntField * ElementID_REM_SMODEL_PROPVAL);

   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SMODEL_PROPVAL(void);
   virtual void set_ElementIDBASE_REM_SMODEL_PROPVAL(TFIBLargeIntField * ElementIDBASE_REM_SMODEL_PROPVAL);

   virtual TFIBWideStringField * get_ElementGID_REM_SMODEL_PROPVAL(void);
   virtual void set_ElementGID_REM_SMODEL_PROPVAL(TFIBWideStringField * ElementGID_REM_SMODEL_PROPVAL);

   virtual TFIBLargeIntField * get_ElementIDMODEL_REM_SMODEL_PROPVAL(void);
   virtual void set_ElementIDMODEL_REM_SMODEL_PROPVAL(TFIBLargeIntField * ElementIDMODEL_REM_SMODEL_PROPVAL);

   virtual TFIBLargeIntField * get_ElementIDPROP_REM_SMODEL_PROPVAL(void);
   virtual void set_ElementIDPROP_REM_SMODEL_PROPVAL(TFIBLargeIntField * ElementIDPROP_REM_SMODEL_PROPVAL);

   virtual TFIBLargeIntField * get_ElementIDPVL_REM_SMODEL_PROPVAL(void);
   virtual void set_ElementIDPVL_REM_SMODEL_PROPVAL(TFIBLargeIntField * ElementIDPVL_REM_SMODEL_PROPVAL);

   virtual TFIBWideStringField * get_ElementVALTEXT_REM_SMODEL_PROPVAL(void);
   virtual void set_ElementVALTEXT_REM_SMODEL_PROPVAL(TFIBWideStringField * ElementVALTEXT_REM_SMODEL_PROPVAL);

   virtual TFIBDateTimeField * get_ElementISM_REM_SMODEL_PROPVAL(void);
   virtual void set_ElementISM_REM_SMODEL_PROPVAL(TFIBDateTimeField * ElementISM_REM_SMODEL_PROPVAL);

   virtual TFIBWideStringField * get_ElementNAME_SPROP(void);
   virtual void set_ElementNAME_SPROP(TFIBWideStringField * ElementNAME_SPROP);

   virtual TFIBWideStringField * get_ElementNAME_SPROPVALUELIST(void);
   virtual void set_ElementNAME_SPROPVALUELIST(TFIBWideStringField * ElementNAME_SPROPVALUELIST);

   virtual __int64 get_IdOwner(void);
   virtual void set_IdOwner(__int64 IdOwner);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual void OpenTable(__int64 id_owner);
   virtual bool NewElement(__int64 id_owner);
   virtual int OpenElement(__int64 id );
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
};
#define CLSID_TREM_DMSprModelPropertiesValueImpl __uuidof(TREM_DMSprModelPropertiesValueImpl)
#endif
