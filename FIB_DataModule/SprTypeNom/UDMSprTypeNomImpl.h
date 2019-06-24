#ifndef UDMSprTypeNomImplH
#define UDMSprTypeNomImplH
#include "IDMSprTypeNom.h"
#include "UDMSprTypeNom.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprTypeNomImpl)) TDMSprTypeNomImpl : public IDMSprTypeNom
{
public:
   TDMSprTypeNomImpl();
   ~TDMSprTypeNomImpl();
   TDMSprTypeNom * Object;
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

//IDMSprTypeNom
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

   virtual TFIBLargeIntField * get_TableID_STNOM(void);
   virtual void set_TableID_STNOM(TFIBLargeIntField * TableID_STNOM);

   virtual TFIBLargeIntField * get_TableIDBASE_STNOM(void);
   virtual void set_TableIDBASE_STNOM(TFIBLargeIntField * TableIDBASE_STNOM);

   virtual TFIBWideStringField * get_TableNAME_STNOM(void);
   virtual void set_TableNAME_STNOM(TFIBWideStringField * TableNAME_STNOM);

   virtual TFIBLargeIntField * get_ElementID_STNOM(void);
   virtual void set_ElementID_STNOM(TFIBLargeIntField * ElementID_STNOM);

   virtual TFIBLargeIntField * get_ElementIDBASE_STNOM(void);
   virtual void set_ElementIDBASE_STNOM(TFIBLargeIntField * ElementIDBASE_STNOM);

   virtual TFIBWideStringField * get_ElementNAME_STNOM(void);
   virtual void set_ElementNAME_STNOM(TFIBWideStringField * ElementNAME_STNOM);

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
#define CLSID_TDMSprTypeNomImpl __uuidof(TDMSprTypeNomImpl)
#endif
