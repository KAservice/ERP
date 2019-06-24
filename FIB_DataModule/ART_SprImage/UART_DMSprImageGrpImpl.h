#ifndef UART_DMSprImageGrpImplH
#define UART_DMSprImageGrpImplH
#include "IART_DMSprImageGrp.h"
#include "UART_DMSprImageGrp.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TART_DMSprImageGrpImpl)) TART_DMSprImageGrpImpl : public IART_DMSprImageGrp
{
public:
   TART_DMSprImageGrpImpl();
   ~TART_DMSprImageGrpImpl();
   TART_DMSprImageGrp * Object;
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

//IART_DMSprImageGrp
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

   virtual TFIBLargeIntField * get_TableID_ART_IMG_GRP(void);
   virtual void set_TableID_ART_IMG_GRP(TFIBLargeIntField * TableID_ART_IMG_GRP);

   virtual TFIBLargeIntField * get_TableIDBASE_ART_IMG_GRP(void);
   virtual void set_TableIDBASE_ART_IMG_GRP(TFIBLargeIntField * TableIDBASE_ART_IMG_GRP);

   virtual TFIBWideStringField * get_TableGUID_ART_IMG_GRP(void);
   virtual void set_TableGUID_ART_IMG_GRP(TFIBWideStringField * TableGUID_ART_IMG_GRP);

   virtual TFIBDateTimeField * get_TablePOS_ISM_ART_IMG_GRP(void);
   virtual void set_TablePOS_ISM_ART_IMG_GRP(TFIBDateTimeField * TablePOS_ISM_ART_IMG_GRP);

   virtual TFIBLargeIntField * get_TableIDGRP_ART_IMG_GRP(void);
   virtual void set_TableIDGRP_ART_IMG_GRP(TFIBLargeIntField * TableIDGRP_ART_IMG_GRP);

   virtual TFIBWideStringField * get_TableGUIDGRP_ART_IMG_GRP(void);
   virtual void set_TableGUIDGRP_ART_IMG_GRP(TFIBWideStringField * TableGUIDGRP_ART_IMG_GRP);

   virtual TFIBWideStringField * get_TableNAME_ART_IMG_GRP(void);
   virtual void set_TableNAME_ART_IMG_GRP(TFIBWideStringField * TableNAME_ART_IMG_GRP);

   virtual TFIBLargeIntField * get_ElementID_ART_IMG_GRP(void);
   virtual void set_ElementID_ART_IMG_GRP(TFIBLargeIntField * ElementID_ART_IMG_GRP);

   virtual TFIBLargeIntField * get_ElementIDBASE_ART_IMG_GRP(void);
   virtual void set_ElementIDBASE_ART_IMG_GRP(TFIBLargeIntField * ElementIDBASE_ART_IMG_GRP);

   virtual TFIBWideStringField * get_ElementGUID_ART_IMG_GRP(void);
   virtual void set_ElementGUID_ART_IMG_GRP(TFIBWideStringField * ElementGUID_ART_IMG_GRP);

   virtual TFIBDateTimeField * get_ElementPOS_ISM_ART_IMG_GRP(void);
   virtual void set_ElementPOS_ISM_ART_IMG_GRP(TFIBDateTimeField * ElementPOS_ISM_ART_IMG_GRP);

   virtual TFIBLargeIntField * get_ElementIDGRP_ART_IMG_GRP(void);
   virtual void set_ElementIDGRP_ART_IMG_GRP(TFIBLargeIntField * ElementIDGRP_ART_IMG_GRP);

   virtual TFIBWideStringField * get_ElementGUIDGRP_ART_IMG_GRP(void);
   virtual void set_ElementGUIDGRP_ART_IMG_GRP(TFIBWideStringField * ElementGUIDGRP_ART_IMG_GRP);

   virtual TFIBWideStringField * get_ElementNAME_ART_IMG_GRP(void);
   virtual void set_ElementNAME_ART_IMG_GRP(TFIBWideStringField * ElementNAME_ART_IMG_GRP);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(__int64 id_grp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual __int64 FindPoName(UnicodeString name);
};
#define CLSID_TART_DMSprImageGrpImpl __uuidof(TART_DMSprImageGrpImpl)
#endif
