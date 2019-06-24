#ifndef UDMObjectBaseGrpImplH
#define UDMObjectBaseGrpImplH
#include "IDMObjectBaseGrp.h"
#include "UDMObjectBaseGrp.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMObjectBaseGrpImpl)) TDMObjectBaseGrpImpl : public IDMObjectBaseGrp
{
public:
   TDMObjectBaseGrpImpl();
   ~TDMObjectBaseGrpImpl();
   TDMObjectBaseGrp * Object;
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

//IDMObjectBaseGrp
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

   virtual TFIBLargeIntField * get_TableID_OBJECT_BASE_GRP(void);
   virtual void set_TableID_OBJECT_BASE_GRP(TFIBLargeIntField * TableID_OBJECT_BASE_GRP);

   virtual TFIBLargeIntField * get_TableIDBASE_OBJECT_BASE_GRP(void);
   virtual void set_TableIDBASE_OBJECT_BASE_GRP(TFIBLargeIntField * TableIDBASE_OBJECT_BASE_GRP);

   virtual TFIBWideStringField * get_TableNAME_OBJECT_BASE_GRP(void);
   virtual void set_TableNAME_OBJECT_BASE_GRP(TFIBWideStringField * TableNAME_OBJECT_BASE_GRP);

   virtual TFIBLargeIntField * get_TableIDGRP_OBJECT_BASE_GRP(void);
   virtual void set_TableIDGRP_OBJECT_BASE_GRP(TFIBLargeIntField * TableIDGRP_OBJECT_BASE_GRP);

   virtual TFIBLargeIntField * get_ElementID_OBJECT_BASE_GRP(void);
   virtual void set_ElementID_OBJECT_BASE_GRP(TFIBLargeIntField * ElementID_OBJECT_BASE_GRP);

   virtual TFIBLargeIntField * get_ElementIDBASE_OBJECT_BASE_GRP(void);
   virtual void set_ElementIDBASE_OBJECT_BASE_GRP(TFIBLargeIntField * ElementIDBASE_OBJECT_BASE_GRP);

   virtual TFIBWideStringField * get_ElementNAME_OBJECT_BASE_GRP(void);
   virtual void set_ElementNAME_OBJECT_BASE_GRP(TFIBWideStringField * ElementNAME_OBJECT_BASE_GRP);

   virtual TFIBLargeIntField * get_ElementIDGRP_OBJECT_BASE_GRP(void);
   virtual void set_ElementIDGRP_OBJECT_BASE_GRP(TFIBLargeIntField * ElementIDGRP_OBJECT_BASE_GRP);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual void OpenTable(void);
   virtual void Table_First(void);
   virtual void Table_Next(void);
   virtual int OpenElement(__int64 id);
   virtual void NewElement( __int64 id_grp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual void Element_Edit(void);
   virtual void Element_Post(void);
};
#define CLSID_TDMObjectBaseGrpImpl __uuidof(TDMObjectBaseGrpImpl)
#endif
