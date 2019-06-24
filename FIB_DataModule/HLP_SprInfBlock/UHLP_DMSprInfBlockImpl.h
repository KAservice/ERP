#ifndef UHLP_DMSprInfBlockImplH
#define UHLP_DMSprInfBlockImplH
#include "IHLP_DMSprInfBlock.h"
#include "UHLP_DMSprInfBlock.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_THLP_DMSprInfBlockImpl)) THLP_DMSprInfBlockImpl : public IHLP_DMSprInfBlock
{
public:
   THLP_DMSprInfBlockImpl();
   ~THLP_DMSprInfBlockImpl();
   THLP_DMSprInfBlock * Object;
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

//IHLP_DMSprInfBlock
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

   virtual TFIBLargeIntField * get_TableID_HLP_IB(void);
   virtual void set_TableID_HLP_IB(TFIBLargeIntField * TableID_HLP_IB);

   virtual TFIBLargeIntField * get_TableIDBASE_HLP_IB(void);
   virtual void set_TableIDBASE_HLP_IB(TFIBLargeIntField * TableIDBASE_HLP_IB);

   virtual TFIBDateTimeField * get_TablePOS_ISM_HLP_IB(void);
   virtual void set_TablePOS_ISM_HLP_IB(TFIBDateTimeField * TablePOS_ISM_HLP_IB);

   virtual TFIBWideStringField * get_TableGUID_HLP_IB(void);
   virtual void set_TableGUID_HLP_IB(TFIBWideStringField * TableGUID_HLP_IB);

   virtual TFIBLargeIntField * get_TableIDGRP_HLP_IB(void);
   virtual void set_TableIDGRP_HLP_IB(TFIBLargeIntField * TableIDGRP_HLP_IB);

   virtual TFIBWideStringField * get_TableGUIDGRP_HLP_IB(void);
   virtual void set_TableGUIDGRP_HLP_IB(TFIBWideStringField * TableGUIDGRP_HLP_IB);

   virtual TFIBWideStringField * get_TableNAME_HLP_IB(void);
   virtual void set_TableNAME_HLP_IB(TFIBWideStringField * TableNAME_HLP_IB);

   virtual TFIBWideStringField * get_TableKEYWORDS_HLP_IB(void);
   virtual void set_TableKEYWORDS_HLP_IB(TFIBWideStringField * TableKEYWORDS_HLP_IB);

   virtual TFIBWideStringField * get_TableTITLE_HLP_IB(void);
   virtual void set_TableTITLE_HLP_IB(TFIBWideStringField * TableTITLE_HLP_IB);

   virtual TFIBWideStringField * get_TableDESCR_HLP_IB(void);
   virtual void set_TableDESCR_HLP_IB(TFIBWideStringField * TableDESCR_HLP_IB);

   virtual TFIBIntegerField * get_TableINDEX_HLP_IB(void);
   virtual void set_TableINDEX_HLP_IB(TFIBIntegerField * TableINDEX_HLP_IB);

   virtual TFIBWideStringField * get_TableWEB_KEYWORDS_HLP_IB(void);
   virtual void set_TableWEB_KEYWORDS_HLP_IB(TFIBWideStringField * TableWEB_KEYWORDS_HLP_IB);

   virtual TFIBWideStringField * get_TableWEB_TITLE_HLP_IB(void);
   virtual void set_TableWEB_TITLE_HLP_IB(TFIBWideStringField * TableWEB_TITLE_HLP_IB);

   virtual TFIBWideStringField * get_TableWEB_DESCR_HLP_IB(void);
   virtual void set_TableWEB_DESCR_HLP_IB(TFIBWideStringField * TableWEB_DESCR_HLP_IB);

   virtual TFIBLargeIntField * get_ElementID_HLP_IB(void);
   virtual void set_ElementID_HLP_IB(TFIBLargeIntField * ElementID_HLP_IB);

   virtual TFIBLargeIntField * get_ElementIDBASE_HLP_IB(void);
   virtual void set_ElementIDBASE_HLP_IB(TFIBLargeIntField * ElementIDBASE_HLP_IB);

   virtual TFIBDateTimeField * get_ElementPOS_ISM_HLP_IB(void);
   virtual void set_ElementPOS_ISM_HLP_IB(TFIBDateTimeField * ElementPOS_ISM_HLP_IB);

   virtual TFIBWideStringField * get_ElementGUID_HLP_IB(void);
   virtual void set_ElementGUID_HLP_IB(TFIBWideStringField * ElementGUID_HLP_IB);

   virtual TFIBLargeIntField * get_ElementIDGRP_HLP_IB(void);
   virtual void set_ElementIDGRP_HLP_IB(TFIBLargeIntField * ElementIDGRP_HLP_IB);

   virtual TFIBWideStringField * get_ElementGUIDGRP_HLP_IB(void);
   virtual void set_ElementGUIDGRP_HLP_IB(TFIBWideStringField * ElementGUIDGRP_HLP_IB);

   virtual TFIBWideStringField * get_ElementNAME_HLP_IB(void);
   virtual void set_ElementNAME_HLP_IB(TFIBWideStringField * ElementNAME_HLP_IB);

   virtual TFIBWideStringField * get_ElementKEYWORDS_HLP_IB(void);
   virtual void set_ElementKEYWORDS_HLP_IB(TFIBWideStringField * ElementKEYWORDS_HLP_IB);

   virtual TFIBWideStringField * get_ElementTITLE_HLP_IB(void);
   virtual void set_ElementTITLE_HLP_IB(TFIBWideStringField * ElementTITLE_HLP_IB);

   virtual TFIBWideStringField * get_ElementDESCR_HLP_IB(void);
   virtual void set_ElementDESCR_HLP_IB(TFIBWideStringField * ElementDESCR_HLP_IB);

   virtual TFIBIntegerField * get_ElementINDEX_HLP_IB(void);
   virtual void set_ElementINDEX_HLP_IB(TFIBIntegerField * ElementINDEX_HLP_IB);

   virtual TFIBWideStringField * get_ElementWEB_KEYWORDS_HLP_IB(void);
   virtual void set_ElementWEB_KEYWORDS_HLP_IB(TFIBWideStringField * ElementWEB_KEYWORDS_HLP_IB);

   virtual TFIBWideStringField * get_ElementWEB_TITLE_HLP_IB(void);
   virtual void set_ElementWEB_TITLE_HLP_IB(TFIBWideStringField * ElementWEB_TITLE_HLP_IB);

   virtual TFIBWideStringField * get_ElementWEB_DESCR_HLP_IB(void);
   virtual void set_ElementWEB_DESCR_HLP_IB(TFIBWideStringField * ElementWEB_DESCR_HLP_IB);

   virtual TFIBWideStringField * get_TableGUID_PROG_MODULE_HLP_IB(void);
   virtual void set_TableGUID_PROG_MODULE_HLP_IB(TFIBWideStringField * TableGUID_PROG_MODULE_HLP_IB);

   virtual TFIBWideStringField * get_TableNAME_PROGRAM_MODULE(void);
   virtual void set_TableNAME_PROGRAM_MODULE(TFIBWideStringField * TableNAME_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_TableMODULE_PROGRAM_MODULE(void);
   virtual void set_TableMODULE_PROGRAM_MODULE(TFIBWideStringField * TableMODULE_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_TableDESCR_PROGRAM_MODULE(void);
   virtual void set_TableDESCR_PROGRAM_MODULE(TFIBWideStringField * TableDESCR_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_TablePATCH_PROGRAM_MODULE(void);
   virtual void set_TablePATCH_PROGRAM_MODULE(TFIBWideStringField * TablePATCH_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_ElementGUID_PROG_MODULE_HLP_IB(void);
   virtual void set_ElementGUID_PROG_MODULE_HLP_IB(TFIBWideStringField * ElementGUID_PROG_MODULE_HLP_IB);

   virtual TFIBWideStringField * get_ElementNAME_PROGRAM_MODULE(void);
   virtual void set_ElementNAME_PROGRAM_MODULE(TFIBWideStringField * ElementNAME_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_ElementMODULE_PROGRAM_MODULE(void);
   virtual void set_ElementMODULE_PROGRAM_MODULE(TFIBWideStringField * ElementMODULE_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_ElementDESCR_PROGRAM_MODULE(void);
   virtual void set_ElementDESCR_PROGRAM_MODULE(TFIBWideStringField * ElementDESCR_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_ElementPATCH_PROGRAM_MODULE(void);
   virtual void set_ElementPATCH_PROGRAM_MODULE(TFIBWideStringField * ElementPATCH_PROGRAM_MODULE);

   virtual TFIBSmallIntField * get_TableFL_ADD_SITEMAP_HLP_IB(void);
   virtual void set_TableFL_ADD_SITEMAP_HLP_IB(TFIBSmallIntField * TableFL_ADD_SITEMAP_HLP_IB);

   virtual TFIBSmallIntField * get_ElementFL_ADD_SITEMAP_HLP_IB(void);
   virtual void set_ElementFL_ADD_SITEMAP_HLP_IB(TFIBSmallIntField * ElementFL_ADD_SITEMAP_HLP_IB);

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
   virtual __int64 GetIdPoGuidProgModule(UnicodeString guid_str);
};
#define CLSID_THLP_DMSprInfBlockImpl __uuidof(THLP_DMSprInfBlockImpl)
#endif
