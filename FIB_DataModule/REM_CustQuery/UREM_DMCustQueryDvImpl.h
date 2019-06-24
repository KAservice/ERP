#ifndef UREM_DMCustQueryDvImplH
#define UREM_DMCustQueryDvImplH
#include "IREM_DMCustQueryDv.h"
#include "UREM_DMCustQueryDv.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMCustQueryDvImpl)) TREM_DMCustQueryDvImpl : public IREM_DMCustQueryDv
{
public:
   TREM_DMCustQueryDvImpl();
   ~TREM_DMCustQueryDvImpl();
   TREM_DMCustQueryDv * Object;
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

//IREM_DMCustQueryDv
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

   virtual TFIBLargeIntField * get_TableID_REM_CQUERYT_DV(void);
   virtual void set_TableID_REM_CQUERYT_DV(TFIBLargeIntField * TableID_REM_CQUERYT_DV);

   virtual TFIBWideStringField * get_TableGID_REM_CQUERYT_DV(void);
   virtual void set_TableGID_REM_CQUERYT_DV(TFIBWideStringField * TableGID_REM_CQUERYT_DV);

   virtual TFIBLargeIntField * get_TableIDBASE_REM_CQUERYT_DV(void);
   virtual void set_TableIDBASE_REM_CQUERYT_DV(TFIBLargeIntField * TableIDBASE_REM_CQUERYT_DV);

   virtual TFIBLargeIntField * get_TableIDCQT_REM_CQUERYT_DV(void);
   virtual void set_TableIDCQT_REM_CQUERYT_DV(TFIBLargeIntField * TableIDCQT_REM_CQUERYT_DV);

   virtual TFIBLargeIntField * get_TableIDUSER_REM_CQUERYT_DV(void);
   virtual void set_TableIDUSER_REM_CQUERYT_DV(TFIBLargeIntField * TableIDUSER_REM_CQUERYT_DV);

   virtual TFIBLargeIntField * get_TableIDSOST_REM_CQUERYT_DV(void);
   virtual void set_TableIDSOST_REM_CQUERYT_DV(TFIBLargeIntField * TableIDSOST_REM_CQUERYT_DV);

   virtual TFIBDateTimeField * get_TablePOS_REM_CQUERYT_DV(void);
   virtual void set_TablePOS_REM_CQUERYT_DV(TFIBDateTimeField * TablePOS_REM_CQUERYT_DV);

   virtual TFIBWideStringField * get_TableNAME_REM_SSOST_CQUERY(void);
   virtual void set_TableNAME_REM_SSOST_CQUERY(TFIBWideStringField * TableNAME_REM_SSOST_CQUERY);

   virtual TFIBWideStringField * get_TableNAME_USER(void);
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER);

   virtual TFIBLargeIntField * get_ElementID_REM_CQUERYT_DV(void);
   virtual void set_ElementID_REM_CQUERYT_DV(TFIBLargeIntField * ElementID_REM_CQUERYT_DV);

   virtual TFIBWideStringField * get_ElementGID_REM_CQUERYT_DV(void);
   virtual void set_ElementGID_REM_CQUERYT_DV(TFIBWideStringField * ElementGID_REM_CQUERYT_DV);

   virtual TFIBLargeIntField * get_ElementIDBASE_REM_CQUERYT_DV(void);
   virtual void set_ElementIDBASE_REM_CQUERYT_DV(TFIBLargeIntField * ElementIDBASE_REM_CQUERYT_DV);

   virtual TFIBLargeIntField * get_ElementIDCQT_REM_CQUERYT_DV(void);
   virtual void set_ElementIDCQT_REM_CQUERYT_DV(TFIBLargeIntField * ElementIDCQT_REM_CQUERYT_DV);

   virtual TFIBLargeIntField * get_ElementIDUSER_REM_CQUERYT_DV(void);
   virtual void set_ElementIDUSER_REM_CQUERYT_DV(TFIBLargeIntField * ElementIDUSER_REM_CQUERYT_DV);

   virtual TFIBLargeIntField * get_ElementIDSOST_REM_CQUERYT_DV(void);
   virtual void set_ElementIDSOST_REM_CQUERYT_DV(TFIBLargeIntField * ElementIDSOST_REM_CQUERYT_DV);

   virtual TFIBDateTimeField * get_ElementPOS_REM_CQUERYT_DV(void);
   virtual void set_ElementPOS_REM_CQUERYT_DV(TFIBDateTimeField * ElementPOS_REM_CQUERYT_DV);

   virtual TFIBWideStringField * get_ElementNAME_REM_SSOST_CQUERY(void);
   virtual void set_ElementNAME_REM_SSOST_CQUERY(TFIBWideStringField * ElementNAME_REM_SSOST_CQUERY);

   virtual TFIBWideStringField * get_ElementNAME_USER(void);
   virtual void set_ElementNAME_USER(TFIBWideStringField * ElementNAME_USER);

   virtual TFIBSmallIntField * get_TableRUN_REM_CQUERY_DV(void);
   virtual void set_TableRUN_REM_CQUERY_DV(TFIBSmallIntField * TableRUN_REM_CQUERY_DV);

   virtual TFIBSmallIntField * get_TableACT_REM_CQUERY_DV(void);
   virtual void set_TableACT_REM_CQUERY_DV(TFIBSmallIntField * TableACT_REM_CQUERY_DV);

   virtual TFIBSmallIntField * get_ElementRUN_REM_CQUERY_DV(void);
   virtual void set_ElementRUN_REM_CQUERY_DV(TFIBSmallIntField * ElementRUN_REM_CQUERY_DV);

   virtual TFIBSmallIntField * get_ElementACT_REM_CQUERY_DV(void);
   virtual void set_ElementACT_REM_CQUERY_DV(TFIBSmallIntField * ElementACT_REM_CQUERY_DV);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual __int64 get_IdCustQueryT(void);
   virtual void set_IdCustQueryT(__int64 IdCustQueryT);

   virtual void OpenTable(__int64 id_cqt);
   virtual int OpenElement(__int64 id);
   virtual bool NewElement(__int64 id_cqt);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual __int64 GetIDElement(UnicodeString gid);
   virtual UnicodeString GetGIDElement(__int64 id);
   virtual bool AddRecordDv(TDateTime pos,	__int64 id_cqt,	__int64 id_sost,__int64 id_user,int act,int run);
};
#define CLSID_TREM_DMCustQueryDvImpl __uuidof(TREM_DMCustQueryDvImpl)
#endif
