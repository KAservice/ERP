#ifndef UART_DMSprInfBlockGrpImplH
#define UART_DMSprInfBlockGrpImplH
#include "IART_DMSprInfBlockGrp.h"
#include "UART_DMSprInfBlockGrp.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TART_DMSprInfBlockGrpImpl)) TART_DMSprInfBlockGrpImpl : public IART_DMSprInfBlockGrp
{
public:
   TART_DMSprInfBlockGrpImpl();
   ~TART_DMSprInfBlockGrpImpl();
   TART_DMSprInfBlockGrp * Object;
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

//IART_DMSprInfBlockGrp
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

   virtual TFIBLargeIntField * get_TableID_ART_IB_GRP(void);
   virtual void set_TableID_ART_IB_GRP(TFIBLargeIntField * TableID_ART_IB_GRP);

   virtual TFIBLargeIntField * get_TableIDBASE_ART_IB_GRP(void);
   virtual void set_TableIDBASE_ART_IB_GRP(TFIBLargeIntField * TableIDBASE_ART_IB_GRP);

   virtual TFIBWideStringField * get_TableGUID_ART_IB_GRP(void);
   virtual void set_TableGUID_ART_IB_GRP(TFIBWideStringField * TableGUID_ART_IB_GRP);

   virtual TFIBWideStringField * get_TableNAME_ART_IB_GRP(void);
   virtual void set_TableNAME_ART_IB_GRP(TFIBWideStringField * TableNAME_ART_IB_GRP);

   virtual TFIBLargeIntField * get_TableIDGRP_ART_IB_GRP(void);
   virtual void set_TableIDGRP_ART_IB_GRP(TFIBLargeIntField * TableIDGRP_ART_IB_GRP);

   virtual TFIBWideStringField * get_TableGUID_GRP_ART_IB_GRP(void);
   virtual void set_TableGUID_GRP_ART_IB_GRP(TFIBWideStringField * TableGUID_GRP_ART_IB_GRP);

   virtual TFIBDateTimeField * get_TablePOS_ISM_ART_IB_GRP(void);
   virtual void set_TablePOS_ISM_ART_IB_GRP(TFIBDateTimeField * TablePOS_ISM_ART_IB_GRP);

   virtual TFIBLargeIntField * get_ElementID_ART_IB_GRP(void);
   virtual void set_ElementID_ART_IB_GRP(TFIBLargeIntField * ElementID_ART_IB_GRP);

   virtual TFIBLargeIntField * get_ElementIDBASE_ART_IB_GRP(void);
   virtual void set_ElementIDBASE_ART_IB_GRP(TFIBLargeIntField * ElementIDBASE_ART_IB_GRP);

   virtual TFIBWideStringField * get_ElementGUID_ART_IB_GRP(void);
   virtual void set_ElementGUID_ART_IB_GRP(TFIBWideStringField * ElementGUID_ART_IB_GRP);

   virtual TFIBWideStringField * get_ElementNAME_ART_IB_GRP(void);
   virtual void set_ElementNAME_ART_IB_GRP(TFIBWideStringField * ElementNAME_ART_IB_GRP);

   virtual TFIBLargeIntField * get_ElementIDGRP_ART_IB_GRP(void);
   virtual void set_ElementIDGRP_ART_IB_GRP(TFIBLargeIntField * ElementIDGRP_ART_IB_GRP);

   virtual TFIBWideStringField * get_ElementGUID_GRP_ART_IB_GRP(void);
   virtual void set_ElementGUID_GRP_ART_IB_GRP(TFIBWideStringField * ElementGUID_GRP_ART_IB_GRP);

   virtual TFIBDateTimeField * get_ElementPOS_ISM_ART_IB_GRP(void);
   virtual void set_ElementPOS_ISM_ART_IB_GRP(TFIBDateTimeField * ElementPOS_ISM_ART_IB_GRP);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(__int64 id_grp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual __int64 FindPoName(UnicodeString name);
};
#define CLSID_TART_DMSprInfBlockGrpImpl __uuidof(TART_DMSprInfBlockGrpImpl)
#endif
