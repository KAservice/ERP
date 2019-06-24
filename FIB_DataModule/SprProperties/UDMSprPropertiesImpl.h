#ifndef UDMSprPropertiesImplH
#define UDMSprPropertiesImplH
#include "IDMSprProperties.h"
#include "UDMSprProperties.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprPropertiesImpl)) TDMSprPropertiesImpl : public IDMSprProperties
{
public:
   TDMSprPropertiesImpl();
   ~TDMSprPropertiesImpl();
   TDMSprProperties * Object;
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

//IDMSprProperties
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

   virtual TFIBLargeIntField * get_TableID_SPROP(void);
   virtual void set_TableID_SPROP(TFIBLargeIntField * TableID_SPROP);

   virtual TFIBLargeIntField * get_TableIDBASE_SPROP(void);
   virtual void set_TableIDBASE_SPROP(TFIBLargeIntField * TableIDBASE_SPROP);

   virtual TFIBWideStringField * get_TableGID_SPROP(void);
   virtual void set_TableGID_SPROP(TFIBWideStringField * TableGID_SPROP);

   virtual TFIBLargeIntField * get_TableIDGRP_SPROP(void);
   virtual void set_TableIDGRP_SPROP(TFIBLargeIntField * TableIDGRP_SPROP);

   virtual TFIBWideStringField * get_TableNAME_SPROP(void);
   virtual void set_TableNAME_SPROP(TFIBWideStringField * TableNAME_SPROP);

   virtual TFIBSmallIntField * get_TableFL_TYPE_SPROP(void);
   virtual void set_TableFL_TYPE_SPROP(TFIBSmallIntField * TableFL_TYPE_SPROP);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBLargeIntField * get_ElementID_SPROP(void);
   virtual void set_ElementID_SPROP(TFIBLargeIntField * ElementID_SPROP);

   virtual TFIBLargeIntField * get_ElementIDBASE_SPROP(void);
   virtual void set_ElementIDBASE_SPROP(TFIBLargeIntField * ElementIDBASE_SPROP);

   virtual TFIBWideStringField * get_ElementGID_SPROP(void);
   virtual void set_ElementGID_SPROP(TFIBWideStringField * ElementGID_SPROP);

   virtual TFIBLargeIntField * get_ElementIDGRP_SPROP(void);
   virtual void set_ElementIDGRP_SPROP(TFIBLargeIntField * ElementIDGRP_SPROP);

   virtual TFIBWideStringField * get_ElementNAME_SPROP(void);
   virtual void set_ElementNAME_SPROP(TFIBWideStringField * ElementNAME_SPROP);

   virtual TFIBSmallIntField * get_ElementFL_TYPE_SPROP(void);
   virtual void set_ElementFL_TYPE_SPROP(TFIBSmallIntField * ElementFL_TYPE_SPROP);

   virtual TpFIBQuery * get_Query(void);
   virtual void set_Query(TpFIBQuery * Query);

   virtual TFIBWideStringField * get_ElementNAME_FOR_PRINT_SPROP(void);
   virtual void set_ElementNAME_FOR_PRINT_SPROP(TFIBWideStringField * ElementNAME_FOR_PRINT_SPROP);

   virtual TFIBWideStringField * get_TableNAME_FOR_PRINT_SPROP(void);
   virtual void set_TableNAME_FOR_PRINT_SPROP(TFIBWideStringField * TableNAME_FOR_PRINT_SPROP);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual void OpenTable(__int64 id_grp, bool all);
   virtual UnicodeString GetTextQuery(__int64 id_grp, bool all);
   virtual int OpenElement(__int64 id );
   virtual bool NewElement(__int64 id_grp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual void ChancheGrp(__int64 id_new_grp,__int64 id_prop);
   virtual __int64 FindPoName(UnicodeString name);
   virtual __int64 GetIdGrp(__int64 id_el);
};
#define CLSID_TDMSprPropertiesImpl __uuidof(TDMSprPropertiesImpl)
#endif
