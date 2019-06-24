#ifndef UHLP_DMSprImageImplH
#define UHLP_DMSprImageImplH
#include "IHLP_DMSprImage.h"
#include "UHLP_DMSprImage.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_THLP_DMSprImageImpl)) THLP_DMSprImageImpl : public IHLP_DMSprImage
{
public:
   THLP_DMSprImageImpl();
   ~THLP_DMSprImageImpl();
   THLP_DMSprImage * Object;
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

//IHLP_DMSprImage
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

   virtual TFIBLargeIntField * get_ElementID_HLP_IMAGE(void);
   virtual void set_ElementID_HLP_IMAGE(TFIBLargeIntField * ElementID_HLP_IMAGE);

   virtual TFIBLargeIntField * get_ElementIDBASE_HLP_IMAGE(void);
   virtual void set_ElementIDBASE_HLP_IMAGE(TFIBLargeIntField * ElementIDBASE_HLP_IMAGE);

   virtual TFIBWideStringField * get_ElementGID_HLP_IMAGE(void);
   virtual void set_ElementGID_HLP_IMAGE(TFIBWideStringField * ElementGID_HLP_IMAGE);

   virtual TFIBWideStringField * get_ElementGUID_HLP_IMAGE(void);
   virtual void set_ElementGUID_HLP_IMAGE(TFIBWideStringField * ElementGUID_HLP_IMAGE);

   virtual TFIBWideStringField * get_ElementGUIDELEMENT_HLP_IMAGE(void);
   virtual void set_ElementGUIDELEMENT_HLP_IMAGE(TFIBWideStringField * ElementGUIDELEMENT_HLP_IMAGE);

   virtual TFIBWideStringField * get_ElementTEXT_HLP_IMAGE(void);
   virtual void set_ElementTEXT_HLP_IMAGE(TFIBWideStringField * ElementTEXT_HLP_IMAGE);

   virtual TFIBSmallIntField * get_ElementTYPE_HLP_IMAGE(void);
   virtual void set_ElementTYPE_HLP_IMAGE(TFIBSmallIntField * ElementTYPE_HLP_IMAGE);

   virtual TFIBWideStringField * get_ElementNAME_HLP_IMAGE(void);
   virtual void set_ElementNAME_HLP_IMAGE(TFIBWideStringField * ElementNAME_HLP_IMAGE);

   virtual TFIBBlobField * get_ElementIMAGE_HLP_IMAGE(void);
   virtual void set_ElementIMAGE_HLP_IMAGE(TFIBBlobField * ElementIMAGE_HLP_IMAGE);

   virtual TFIBWideStringField * get_ElementGUIDGRP_HLP_IMAGE(void);
   virtual void set_ElementGUIDGRP_HLP_IMAGE(TFIBWideStringField * ElementGUIDGRP_HLP_IMAGE);

   virtual TFIBLargeIntField * get_ElementIDGRP_HLP_IMAGE(void);
   virtual void set_ElementIDGRP_HLP_IMAGE(TFIBLargeIntField * ElementIDGRP_HLP_IMAGE);

   virtual TFIBLargeIntField * get_TableID_HLP_IMAGE(void);
   virtual void set_TableID_HLP_IMAGE(TFIBLargeIntField * TableID_HLP_IMAGE);

   virtual TFIBLargeIntField * get_TableIDBASE_HLP_IMAGE(void);
   virtual void set_TableIDBASE_HLP_IMAGE(TFIBLargeIntField * TableIDBASE_HLP_IMAGE);

   virtual TFIBWideStringField * get_TableGID_HLP_IMAGE(void);
   virtual void set_TableGID_HLP_IMAGE(TFIBWideStringField * TableGID_HLP_IMAGE);

   virtual TFIBWideStringField * get_TableGUID_HLP_IMAGE(void);
   virtual void set_TableGUID_HLP_IMAGE(TFIBWideStringField * TableGUID_HLP_IMAGE);

   virtual TFIBWideStringField * get_TableGUIDELEMENT_HLP_IMAGE(void);
   virtual void set_TableGUIDELEMENT_HLP_IMAGE(TFIBWideStringField * TableGUIDELEMENT_HLP_IMAGE);

   virtual TFIBWideStringField * get_TableTEXT_HLP_IMAGE(void);
   virtual void set_TableTEXT_HLP_IMAGE(TFIBWideStringField * TableTEXT_HLP_IMAGE);

   virtual TFIBSmallIntField * get_TableTYPE_HLP_IMAGE(void);
   virtual void set_TableTYPE_HLP_IMAGE(TFIBSmallIntField * TableTYPE_HLP_IMAGE);

   virtual TFIBWideStringField * get_TableNAME_HLP_IMAGE(void);
   virtual void set_TableNAME_HLP_IMAGE(TFIBWideStringField * TableNAME_HLP_IMAGE);

   virtual TFIBBlobField * get_TableIMAGE_HLP_IMAGE(void);
   virtual void set_TableIMAGE_HLP_IMAGE(TFIBBlobField * TableIMAGE_HLP_IMAGE);

   virtual TFIBWideStringField * get_TableGUIDGRP_HLP_IMAGE(void);
   virtual void set_TableGUIDGRP_HLP_IMAGE(TFIBWideStringField * TableGUIDGRP_HLP_IMAGE);

   virtual TFIBLargeIntField * get_TableIDGRP_HLP_IMAGE(void);
   virtual void set_TableIDGRP_HLP_IMAGE(TFIBLargeIntField * TableIDGRP_HLP_IMAGE);

   virtual TFIBIntegerField * get_TableHEIGHT_HLP_IMAGE(void);
   virtual void set_TableHEIGHT_HLP_IMAGE(TFIBIntegerField * TableHEIGHT_HLP_IMAGE);

   virtual TFIBIntegerField * get_TableWIDTH_HLP_IMAGE(void);
   virtual void set_TableWIDTH_HLP_IMAGE(TFIBIntegerField * TableWIDTH_HLP_IMAGE);

   virtual TFIBIntegerField * get_ElementHEIGHT_HLP_IMAGE(void);
   virtual void set_ElementHEIGHT_HLP_IMAGE(TFIBIntegerField * ElementHEIGHT_HLP_IMAGE);

   virtual TFIBIntegerField * get_ElementWIDTH_HLP_IMAGE(void);
   virtual void set_ElementWIDTH_HLP_IMAGE(TFIBIntegerField * ElementWIDTH_HLP_IMAGE);

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
#define CLSID_THLP_DMSprImageImpl __uuidof(THLP_DMSprImageImpl)
#endif
