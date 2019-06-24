#ifndef UART_DMSprImageImplH
#define UART_DMSprImageImplH
#include "IART_DMSprImage.h"
#include "UART_DMSprImage.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TART_DMSprImageImpl)) TART_DMSprImageImpl : public IART_DMSprImage
{
public:
   TART_DMSprImageImpl();
   ~TART_DMSprImageImpl();
   TART_DMSprImage * Object;
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

//IART_DMSprImage
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

   virtual TFIBLargeIntField * get_ElementID_ART_IMG(void);
   virtual void set_ElementID_ART_IMG(TFIBLargeIntField * ElementID_ART_IMG);

   virtual TFIBLargeIntField * get_ElementIDBASE_ART_IMG(void);
   virtual void set_ElementIDBASE_ART_IMG(TFIBLargeIntField * ElementIDBASE_ART_IMG);

   virtual TFIBWideStringField * get_ElementGUID_ART_IMG(void);
   virtual void set_ElementGUID_ART_IMG(TFIBWideStringField * ElementGUID_ART_IMG);

   virtual TFIBDateTimeField * get_ElementPOS_ISM_ART_IMG(void);
   virtual void set_ElementPOS_ISM_ART_IMG(TFIBDateTimeField * ElementPOS_ISM_ART_IMG);

   virtual TFIBLargeIntField * get_ElementIDGRP_ART_IMG(void);
   virtual void set_ElementIDGRP_ART_IMG(TFIBLargeIntField * ElementIDGRP_ART_IMG);

   virtual TFIBWideStringField * get_ElementGUIDGRP_ART_IMG(void);
   virtual void set_ElementGUIDGRP_ART_IMG(TFIBWideStringField * ElementGUIDGRP_ART_IMG);

   virtual TFIBWideStringField * get_ElementNAME_ART_IMG(void);
   virtual void set_ElementNAME_ART_IMG(TFIBWideStringField * ElementNAME_ART_IMG);

   virtual TFIBWideStringField * get_ElementTEXT_ART_IMG(void);
   virtual void set_ElementTEXT_ART_IMG(TFIBWideStringField * ElementTEXT_ART_IMG);

   virtual TFIBIntegerField * get_ElementHEIGHT_ART_IMG(void);
   virtual void set_ElementHEIGHT_ART_IMG(TFIBIntegerField * ElementHEIGHT_ART_IMG);

   virtual TFIBIntegerField * get_ElementWIDTH_ART_IMG(void);
   virtual void set_ElementWIDTH_ART_IMG(TFIBIntegerField * ElementWIDTH_ART_IMG);

   virtual TFIBBlobField * get_ElementIMAGE_ART_IMG(void);
   virtual void set_ElementIMAGE_ART_IMG(TFIBBlobField * ElementIMAGE_ART_IMG);

   virtual TFIBLargeIntField * get_TableID_ART_IMG(void);
   virtual void set_TableID_ART_IMG(TFIBLargeIntField * TableID_ART_IMG);

   virtual TFIBLargeIntField * get_TableIDBASE_ART_IMG(void);
   virtual void set_TableIDBASE_ART_IMG(TFIBLargeIntField * TableIDBASE_ART_IMG);

   virtual TFIBWideStringField * get_TableGUID_ART_IMG(void);
   virtual void set_TableGUID_ART_IMG(TFIBWideStringField * TableGUID_ART_IMG);

   virtual TFIBDateTimeField * get_TablePOS_ISM_ART_IMG(void);
   virtual void set_TablePOS_ISM_ART_IMG(TFIBDateTimeField * TablePOS_ISM_ART_IMG);

   virtual TFIBLargeIntField * get_TableIDGRP_ART_IMG(void);
   virtual void set_TableIDGRP_ART_IMG(TFIBLargeIntField * TableIDGRP_ART_IMG);

   virtual TFIBWideStringField * get_TableGUIDGRP_ART_IMG(void);
   virtual void set_TableGUIDGRP_ART_IMG(TFIBWideStringField * TableGUIDGRP_ART_IMG);

   virtual TFIBWideStringField * get_TableNAME_ART_IMG(void);
   virtual void set_TableNAME_ART_IMG(TFIBWideStringField * TableNAME_ART_IMG);

   virtual TFIBWideStringField * get_TableTEXT_ART_IMG(void);
   virtual void set_TableTEXT_ART_IMG(TFIBWideStringField * TableTEXT_ART_IMG);

   virtual TFIBIntegerField * get_TableHEIGHT_ART_IMG(void);
   virtual void set_TableHEIGHT_ART_IMG(TFIBIntegerField * TableHEIGHT_ART_IMG);

   virtual TFIBIntegerField * get_TableWIDTH_ART_IMG(void);
   virtual void set_TableWIDTH_ART_IMG(TFIBIntegerField * TableWIDTH_ART_IMG);

   virtual TFIBBlobField * get_TableIMAGE_ART_IMG(void);
   virtual void set_TableIMAGE_ART_IMG(TFIBBlobField * TableIMAGE_ART_IMG);

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
#define CLSID_TART_DMSprImageImpl __uuidof(TART_DMSprImageImpl)
#endif
