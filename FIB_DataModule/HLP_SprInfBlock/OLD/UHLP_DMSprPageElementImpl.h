#ifndef UHLP_DMSprPageElementImplH
#define UHLP_DMSprPageElementImplH
#include "IHLP_DMSprPageElement.h"
#include "UHLP_DMSprPageElement.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_THLP_DMSprPageElementImpl)) THLP_DMSprPageElementImpl : public IHLP_DMSprPageElement
{
public:
   THLP_DMSprPageElementImpl();
   ~THLP_DMSprPageElementImpl();
   THLP_DMSprPageElement * Object;
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

//IHLP_DMSprPageElement
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

   virtual TFIBLargeIntField * get_TableID_HLP_PAGE_ELEMENT(void);
   virtual void set_TableID_HLP_PAGE_ELEMENT(TFIBLargeIntField * TableID_HLP_PAGE_ELEMENT);

   virtual TFIBLargeIntField * get_TableIDBASE_HLP_PAGE_ELEMENT(void);
   virtual void set_TableIDBASE_HLP_PAGE_ELEMENT(TFIBLargeIntField * TableIDBASE_HLP_PAGE_ELEMENT);

   virtual TFIBWideStringField * get_TableGID_HLP_PAGE_ELEMENT(void);
   virtual void set_TableGID_HLP_PAGE_ELEMENT(TFIBWideStringField * TableGID_HLP_PAGE_ELEMENT);

   virtual TFIBWideStringField * get_TableGUID_HLP_PAGE_ELEMENT(void);
   virtual void set_TableGUID_HLP_PAGE_ELEMENT(TFIBWideStringField * TableGUID_HLP_PAGE_ELEMENT);

   virtual TFIBLargeIntField * get_TableIDPAGE_HLP_PAGE_ELEMENT(void);
   virtual void set_TableIDPAGE_HLP_PAGE_ELEMENT(TFIBLargeIntField * TableIDPAGE_HLP_PAGE_ELEMENT);

   virtual TFIBSmallIntField * get_TableTYPE_HLP_PAGE_ELEMENT(void);
   virtual void set_TableTYPE_HLP_PAGE_ELEMENT(TFIBSmallIntField * TableTYPE_HLP_PAGE_ELEMENT);

   virtual TFIBWideStringField * get_TableTEXT_HLP_PAGE_ELEMENT(void);
   virtual void set_TableTEXT_HLP_PAGE_ELEMENT(TFIBWideStringField * TableTEXT_HLP_PAGE_ELEMENT);

   virtual TFIBWideStringField * get_TableGUIDPAGE_HLP_PAGE_ELEMENT(void);
   virtual void set_TableGUIDPAGE_HLP_PAGE_ELEMENT(TFIBWideStringField * TableGUIDPAGE_HLP_PAGE_ELEMENT);

   virtual TFIBWideStringField * get_TableGUIDIMAGE_HLP_PAGE_ELEMENT(void);
   virtual void set_TableGUIDIMAGE_HLP_PAGE_ELEMENT(TFIBWideStringField * TableGUIDIMAGE_HLP_PAGE_ELEMENT);

   virtual TFIBLargeIntField * get_ElementID_HLP_PAGE_ELEMENT(void);
   virtual void set_ElementID_HLP_PAGE_ELEMENT(TFIBLargeIntField * ElementID_HLP_PAGE_ELEMENT);

   virtual TFIBLargeIntField * get_ElementIDBASE_HLP_PAGE_ELEMENT(void);
   virtual void set_ElementIDBASE_HLP_PAGE_ELEMENT(TFIBLargeIntField * ElementIDBASE_HLP_PAGE_ELEMENT);

   virtual TFIBWideStringField * get_ElementGID_HLP_PAGE_ELEMENT(void);
   virtual void set_ElementGID_HLP_PAGE_ELEMENT(TFIBWideStringField * ElementGID_HLP_PAGE_ELEMENT);

   virtual TFIBWideStringField * get_ElementGUID_HLP_PAGE_ELEMENT(void);
   virtual void set_ElementGUID_HLP_PAGE_ELEMENT(TFIBWideStringField * ElementGUID_HLP_PAGE_ELEMENT);

   virtual TFIBLargeIntField * get_ElementIDPAGE_HLP_PAGE_ELEMENT(void);
   virtual void set_ElementIDPAGE_HLP_PAGE_ELEMENT(TFIBLargeIntField * ElementIDPAGE_HLP_PAGE_ELEMENT);

   virtual TFIBSmallIntField * get_ElementTYPE_HLP_PAGE_ELEMENT(void);
   virtual void set_ElementTYPE_HLP_PAGE_ELEMENT(TFIBSmallIntField * ElementTYPE_HLP_PAGE_ELEMENT);

   virtual TFIBWideStringField * get_ElementTEXT_HLP_PAGE_ELEMENT(void);
   virtual void set_ElementTEXT_HLP_PAGE_ELEMENT(TFIBWideStringField * ElementTEXT_HLP_PAGE_ELEMENT);

   virtual TFIBWideStringField * get_ElementGUIDPAGE_HLP_PAGE_ELEMENT(void);
   virtual void set_ElementGUIDPAGE_HLP_PAGE_ELEMENT(TFIBWideStringField * ElementGUIDPAGE_HLP_PAGE_ELEMENT);

   virtual TFIBWideStringField * get_ElementGUIDIMAGE_HLP_PAGE_ELEMENT(void);
   virtual void set_ElementGUIDIMAGE_HLP_PAGE_ELEMENT(TFIBWideStringField * ElementGUIDIMAGE_HLP_PAGE_ELEMENT);

   virtual TFIBLargeIntField * get_TableIDIMAGE_HLP_PAGE_ELEMENT(void);
   virtual void set_TableIDIMAGE_HLP_PAGE_ELEMENT(TFIBLargeIntField * TableIDIMAGE_HLP_PAGE_ELEMENT);

   virtual TFIBIntegerField * get_TableINDEX_HLP_PAGE_ELEMENT(void);
   virtual void set_TableINDEX_HLP_PAGE_ELEMENT(TFIBIntegerField * TableINDEX_HLP_PAGE_ELEMENT);

   virtual TFIBLargeIntField * get_ElementIDIMAGE_HLP_PAGE_ELEMENT(void);
   virtual void set_ElementIDIMAGE_HLP_PAGE_ELEMENT(TFIBLargeIntField * ElementIDIMAGE_HLP_PAGE_ELEMENT);

   virtual TFIBSmallIntField * get_ElementTYPE_TBL_HLP_PAGE_ELEMENT(void);
   virtual void set_ElementTYPE_TBL_HLP_PAGE_ELEMENT(TFIBSmallIntField * ElementTYPE_TBL_HLP_PAGE_ELEMENT);

   virtual TFIBIntegerField * get_ElementINDEX_HLP_PAGE_ELEMENT(void);
   virtual void set_ElementINDEX_HLP_PAGE_ELEMENT(TFIBIntegerField * ElementINDEX_HLP_PAGE_ELEMENT);

   virtual TFIBWideStringField * get_TableNAME_HLP_IMAGE(void);
   virtual void set_TableNAME_HLP_IMAGE(TFIBWideStringField * TableNAME_HLP_IMAGE);

   virtual TFIBBlobField * get_TableIMAGE_HLP_IMAGE(void);
   virtual void set_TableIMAGE_HLP_IMAGE(TFIBBlobField * TableIMAGE_HLP_IMAGE);

   virtual TFIBSmallIntField * get_TableTYPE_HLP_IMAGE(void);
   virtual void set_TableTYPE_HLP_IMAGE(TFIBSmallIntField * TableTYPE_HLP_IMAGE);

   virtual TFIBIntegerField * get_TableH_ALIGN_HLP_PAGE_ELEMENT(void);
   virtual void set_TableH_ALIGN_HLP_PAGE_ELEMENT(TFIBIntegerField * TableH_ALIGN_HLP_PAGE_ELEMENT);

   virtual TFIBIntegerField * get_ElementH_ALIGN_HLP_PAGE_ELEMENT(void);
   virtual void set_ElementH_ALIGN_HLP_PAGE_ELEMENT(TFIBIntegerField * ElementH_ALIGN_HLP_PAGE_ELEMENT);

   virtual __int64 get_IdPage(void);
   virtual void set_IdPage(__int64 IdPage);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual void OpenTable(__int64 id_page);
   virtual bool SaveIsmen(void);
   virtual bool CancelIsmen(void);
   virtual bool TableAppend(__int64 id_page);
   virtual bool TableDelete(void);
   virtual bool NewElement(__int64 id_page);
   virtual int OpenElement(__int64 id );
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
};
#define CLSID_THLP_DMSprPageElementImpl __uuidof(THLP_DMSprPageElementImpl)
#endif
