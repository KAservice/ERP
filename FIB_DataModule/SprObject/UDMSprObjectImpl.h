#ifndef UDMSprObjectImplH
#define UDMSprObjectImplH
#include "IDMSprObject.h"
#include "UDMSprObject.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprObjectImpl)) TDMSprObjectImpl : public IDMSprObject
{
public:
   TDMSprObjectImpl();
   ~TDMSprObjectImpl();
   TDMSprObject * Object;
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

//IDMSprObject
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

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBLargeIntField * get_TableID_SOBJECT(void);
   virtual void set_TableID_SOBJECT(TFIBLargeIntField * TableID_SOBJECT);

   virtual TFIBWideStringField * get_TableNAME_SOBJECT(void);
   virtual void set_TableNAME_SOBJECT(TFIBWideStringField * TableNAME_SOBJECT);

   virtual TFIBLargeIntField * get_TableIDINFBASE_SOBJECT(void);
   virtual void set_TableIDINFBASE_SOBJECT(TFIBLargeIntField * TableIDINFBASE_SOBJECT);

   virtual TFIBLargeIntField * get_TableIDFIRM_SOBJECT(void);
   virtual void set_TableIDFIRM_SOBJECT(TFIBLargeIntField * TableIDFIRM_SOBJECT);

   virtual TFIBLargeIntField * get_TableIDSKLAD_SOBJECT(void);
   virtual void set_TableIDSKLAD_SOBJECT(TFIBLargeIntField * TableIDSKLAD_SOBJECT);

   virtual TFIBLargeIntField * get_TableIDKASSA_SOBJECT(void);
   virtual void set_TableIDKASSA_SOBJECT(TFIBLargeIntField * TableIDKASSA_SOBJECT);

   virtual TFIBLargeIntField * get_TableIDPODR_SOBJECT(void);
   virtual void set_TableIDPODR_SOBJECT(TFIBLargeIntField * TableIDPODR_SOBJECT);

   virtual TFIBWideStringField * get_TableNAME_SINFBASE_OBMEN(void);
   virtual void set_TableNAME_SINFBASE_OBMEN(TFIBWideStringField * TableNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_TableNAMEFIRM(void);
   virtual void set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM);

   virtual TFIBWideStringField * get_TableNAMESKLAD(void);
   virtual void set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD);

   virtual TFIBWideStringField * get_TableNAMEKKM(void);
   virtual void set_TableNAMEKKM(TFIBWideStringField * TableNAMEKKM);

   virtual TFIBWideStringField * get_TableNAMEPOD(void);
   virtual void set_TableNAMEPOD(TFIBWideStringField * TableNAMEPOD);

   virtual TFIBLargeIntField * get_ElementID_SOBJECT(void);
   virtual void set_ElementID_SOBJECT(TFIBLargeIntField * ElementID_SOBJECT);

   virtual TFIBLargeIntField * get_ElementIDBASE_SOBJECT(void);
   virtual void set_ElementIDBASE_SOBJECT(TFIBLargeIntField * ElementIDBASE_SOBJECT);

   virtual TFIBWideStringField * get_ElementNAME_SOBJECT(void);
   virtual void set_ElementNAME_SOBJECT(TFIBWideStringField * ElementNAME_SOBJECT);

   virtual TFIBLargeIntField * get_ElementIDINFBASE_SOBJECT(void);
   virtual void set_ElementIDINFBASE_SOBJECT(TFIBLargeIntField * ElementIDINFBASE_SOBJECT);

   virtual TFIBLargeIntField * get_ElementIDFIRM_SOBJECT(void);
   virtual void set_ElementIDFIRM_SOBJECT(TFIBLargeIntField * ElementIDFIRM_SOBJECT);

   virtual TFIBLargeIntField * get_ElementIDSKLAD_SOBJECT(void);
   virtual void set_ElementIDSKLAD_SOBJECT(TFIBLargeIntField * ElementIDSKLAD_SOBJECT);

   virtual TFIBLargeIntField * get_ElementIDKASSA_SOBJECT(void);
   virtual void set_ElementIDKASSA_SOBJECT(TFIBLargeIntField * ElementIDKASSA_SOBJECT);

   virtual TFIBLargeIntField * get_ElementIDPODR_SOBJECT(void);
   virtual void set_ElementIDPODR_SOBJECT(TFIBLargeIntField * ElementIDPODR_SOBJECT);

   virtual TFIBWideStringField * get_ElementNAME_SINFBASE_OBMEN(void);
   virtual void set_ElementNAME_SINFBASE_OBMEN(TFIBWideStringField * ElementNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_ElementNAMEFIRM(void);
   virtual void set_ElementNAMEFIRM(TFIBWideStringField * ElementNAMEFIRM);

   virtual TFIBWideStringField * get_ElementNAMESKLAD(void);
   virtual void set_ElementNAMESKLAD(TFIBWideStringField * ElementNAMESKLAD);

   virtual TFIBWideStringField * get_ElementNAMEKKM(void);
   virtual void set_ElementNAMEKKM(TFIBWideStringField * ElementNAMEKKM);

   virtual TFIBWideStringField * get_ElementNAMEPOD(void);
   virtual void set_ElementNAMEPOD(TFIBWideStringField * ElementNAMEPOD);

   virtual bool OpenTable(void);
   virtual bool  OpenElement(__int64 id);
   virtual bool NewElement(void);
   virtual bool SaveElement(void);
   virtual void CloseElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual __int64 GetIdElementPoName(UnicodeString   name);
   virtual int GetIndexInTablePoId(__int64 id_element);
   virtual __int64 GetIdElementPoGid(UnicodeString gid);
   virtual UnicodeString GetGidElementPoId(__int64 id);
};
#define CLSID_TDMSprObjectImpl __uuidof(TDMSprObjectImpl)
#endif
