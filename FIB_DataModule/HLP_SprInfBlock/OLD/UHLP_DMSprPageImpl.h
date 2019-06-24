#ifndef UHLP_DMSprPageImplH
#define UHLP_DMSprPageImplH
#include "IHLP_DMSprPage.h"
#include "UHLP_DMSprPage.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_THLP_DMSprPageImpl)) THLP_DMSprPageImpl : public IHLP_DMSprPage
{
public:
   THLP_DMSprPageImpl();
   ~THLP_DMSprPageImpl();
   THLP_DMSprPage * Object;
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

//IHLP_DMSprPage
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

   virtual TpFIBQuery * get_Query(void);
   virtual void set_Query(TpFIBQuery * Query);

   virtual TFIBLargeIntField * get_TableID_HLP_PAGE(void);
   virtual void set_TableID_HLP_PAGE(TFIBLargeIntField * TableID_HLP_PAGE);

   virtual TFIBLargeIntField * get_TableIDBASE_HLP_PAGE(void);
   virtual void set_TableIDBASE_HLP_PAGE(TFIBLargeIntField * TableIDBASE_HLP_PAGE);

   virtual TFIBWideStringField * get_TableGID_HLP_PAGE(void);
   virtual void set_TableGID_HLP_PAGE(TFIBWideStringField * TableGID_HLP_PAGE);

   virtual TFIBLargeIntField * get_TableIDGRP_HLP_PAGE(void);
   virtual void set_TableIDGRP_HLP_PAGE(TFIBLargeIntField * TableIDGRP_HLP_PAGE);

   virtual TFIBWideStringField * get_TableNAME_HLP_PAGE(void);
   virtual void set_TableNAME_HLP_PAGE(TFIBWideStringField * TableNAME_HLP_PAGE);

   virtual TFIBWideStringField * get_TableKEYWORDS_HLP_PAGE(void);
   virtual void set_TableKEYWORDS_HLP_PAGE(TFIBWideStringField * TableKEYWORDS_HLP_PAGE);

   virtual TFIBWideStringField * get_TableTITLE_HLP_PAGE(void);
   virtual void set_TableTITLE_HLP_PAGE(TFIBWideStringField * TableTITLE_HLP_PAGE);

   virtual TFIBWideStringField * get_TableDESCR_HLP_PAGE(void);
   virtual void set_TableDESCR_HLP_PAGE(TFIBWideStringField * TableDESCR_HLP_PAGE);

   virtual TFIBIntegerField * get_TableINDEX_HLP_PAGE(void);
   virtual void set_TableINDEX_HLP_PAGE(TFIBIntegerField * TableINDEX_HLP_PAGE);

   virtual TFIBWideStringField * get_TableWEBKEYWORDS_HLP_PAGE(void);
   virtual void set_TableWEBKEYWORDS_HLP_PAGE(TFIBWideStringField * TableWEBKEYWORDS_HLP_PAGE);

   virtual TFIBWideStringField * get_TableWEBTITLE_HLP_PAGE(void);
   virtual void set_TableWEBTITLE_HLP_PAGE(TFIBWideStringField * TableWEBTITLE_HLP_PAGE);

   virtual TFIBWideStringField * get_TableWEBDESCR_HLP_PAGE(void);
   virtual void set_TableWEBDESCR_HLP_PAGE(TFIBWideStringField * TableWEBDESCR_HLP_PAGE);

   virtual TFIBWideStringField * get_TableGUIDGRP_HLP_PAGE(void);
   virtual void set_TableGUIDGRP_HLP_PAGE(TFIBWideStringField * TableGUIDGRP_HLP_PAGE);

   virtual TFIBWideStringField * get_TableSTRCODE_HLP_PAGE(void);
   virtual void set_TableSTRCODE_HLP_PAGE(TFIBWideStringField * TableSTRCODE_HLP_PAGE);

   virtual TFIBWideStringField * get_TableGUID_HLP_PAGE(void);
   virtual void set_TableGUID_HLP_PAGE(TFIBWideStringField * TableGUID_HLP_PAGE);

   virtual TFIBLargeIntField * get_ElementID_HLP_PAGE(void);
   virtual void set_ElementID_HLP_PAGE(TFIBLargeIntField * ElementID_HLP_PAGE);

   virtual TFIBLargeIntField * get_ElementIDBASE_HLP_PAGE(void);
   virtual void set_ElementIDBASE_HLP_PAGE(TFIBLargeIntField * ElementIDBASE_HLP_PAGE);

   virtual TFIBWideStringField * get_ElementGID_HLP_PAGE(void);
   virtual void set_ElementGID_HLP_PAGE(TFIBWideStringField * ElementGID_HLP_PAGE);

   virtual TFIBLargeIntField * get_ElementIDGRP_HLP_PAGE(void);
   virtual void set_ElementIDGRP_HLP_PAGE(TFIBLargeIntField * ElementIDGRP_HLP_PAGE);

   virtual TFIBWideStringField * get_ElementNAME_HLP_PAGE(void);
   virtual void set_ElementNAME_HLP_PAGE(TFIBWideStringField * ElementNAME_HLP_PAGE);

   virtual TFIBWideStringField * get_ElementKEYWORDS_HLP_PAGE(void);
   virtual void set_ElementKEYWORDS_HLP_PAGE(TFIBWideStringField * ElementKEYWORDS_HLP_PAGE);

   virtual TFIBWideStringField * get_ElementTITLE_HLP_PAGE(void);
   virtual void set_ElementTITLE_HLP_PAGE(TFIBWideStringField * ElementTITLE_HLP_PAGE);

   virtual TFIBWideStringField * get_ElementDESCR_HLP_PAGE(void);
   virtual void set_ElementDESCR_HLP_PAGE(TFIBWideStringField * ElementDESCR_HLP_PAGE);

   virtual TFIBIntegerField * get_ElementINDEX_HLP_PAGE(void);
   virtual void set_ElementINDEX_HLP_PAGE(TFIBIntegerField * ElementINDEX_HLP_PAGE);

   virtual TFIBWideStringField * get_ElementWEBKEYWORDS_HLP_PAGE(void);
   virtual void set_ElementWEBKEYWORDS_HLP_PAGE(TFIBWideStringField * ElementWEBKEYWORDS_HLP_PAGE);

   virtual TFIBWideStringField * get_ElementWEBTITLE_HLP_PAGE(void);
   virtual void set_ElementWEBTITLE_HLP_PAGE(TFIBWideStringField * ElementWEBTITLE_HLP_PAGE);

   virtual TFIBWideStringField * get_ElementWEBDESCR_HLP_PAGE(void);
   virtual void set_ElementWEBDESCR_HLP_PAGE(TFIBWideStringField * ElementWEBDESCR_HLP_PAGE);

   virtual TFIBWideStringField * get_ElementGUIDGRP_HLP_PAGE(void);
   virtual void set_ElementGUIDGRP_HLP_PAGE(TFIBWideStringField * ElementGUIDGRP_HLP_PAGE);

   virtual TFIBWideStringField * get_ElementSTRCODE_HLP_PAGE(void);
   virtual void set_ElementSTRCODE_HLP_PAGE(TFIBWideStringField * ElementSTRCODE_HLP_PAGE);

   virtual TFIBWideStringField * get_ElementGUID_HLP_PAGE(void);
   virtual void set_ElementGUID_HLP_PAGE(TFIBWideStringField * ElementGUID_HLP_PAGE);

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
   virtual void ChancheGrp(__int64 id_new_grp,__int64 id_element);
   virtual __int64 FindPoName(UnicodeString name);
   virtual __int64 GetIdGrp(__int64 id_el);
};
#define CLSID_THLP_DMSprPageImpl __uuidof(THLP_DMSprPageImpl)
#endif
