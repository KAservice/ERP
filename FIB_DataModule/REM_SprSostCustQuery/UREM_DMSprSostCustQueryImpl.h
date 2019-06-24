#ifndef UREM_DMSprSostCustQueryImplH
#define UREM_DMSprSostCustQueryImplH
#include "IREM_DMSprSostCustQuery.h"
#include "UREM_DMSprSostCustQuery.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMSprSostCustQueryImpl)) TREM_DMSprSostCustQueryImpl : public IREM_DMSprSostCustQuery
{
public:
   TREM_DMSprSostCustQueryImpl();
   ~TREM_DMSprSostCustQueryImpl();
   TREM_DMSprSostCustQuery * Object;
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

//IREM_DMSprSostCustQuery
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

   virtual TFIBLargeIntField * get_TableID_REM_SSOST_CQUERY(void);
   virtual void set_TableID_REM_SSOST_CQUERY(TFIBLargeIntField * TableID_REM_SSOST_CQUERY);

   virtual TFIBWideStringField * get_TableGID_REM_SSOST_CQUERY(void);
   virtual void set_TableGID_REM_SSOST_CQUERY(TFIBWideStringField * TableGID_REM_SSOST_CQUERY);

   virtual TFIBLargeIntField * get_TableIDBASE_REM_SSOST_CQUERY(void);
   virtual void set_TableIDBASE_REM_SSOST_CQUERY(TFIBLargeIntField * TableIDBASE_REM_SSOST_CQUERY);

   virtual TFIBWideStringField * get_TableNAME_REM_SSOST_CQUERY(void);
   virtual void set_TableNAME_REM_SSOST_CQUERY(TFIBWideStringField * TableNAME_REM_SSOST_CQUERY);

   virtual TFIBLargeIntField * get_ElementID_REM_SSOST_CQUERY(void);
   virtual void set_ElementID_REM_SSOST_CQUERY(TFIBLargeIntField * ElementID_REM_SSOST_CQUERY);

   virtual TFIBWideStringField * get_ElementGID_REM_SSOST_CQUERY(void);
   virtual void set_ElementGID_REM_SSOST_CQUERY(TFIBWideStringField * ElementGID_REM_SSOST_CQUERY);

   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SSOST_CQUERY(void);
   virtual void set_ElementIDBASE_REM_SSOST_CQUERY(TFIBLargeIntField * ElementIDBASE_REM_SSOST_CQUERY);

   virtual TFIBWideStringField * get_ElementNAME_REM_SSOST_CQUERY(void);
   virtual void set_ElementNAME_REM_SSOST_CQUERY(TFIBWideStringField * ElementNAME_REM_SSOST_CQUERY);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(void);
   virtual bool SaveElement(void);
   virtual void CloseElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual __int64 GetIDElement(UnicodeString gid);
   virtual UnicodeString GetGIDElement(__int64 id);
   virtual int GetIndexElementaPoID(__int64 id);
};
#define CLSID_TREM_DMSprSostCustQueryImpl __uuidof(TREM_DMSprSostCustQueryImpl)
#endif
