#ifndef UHLP_DMSprInfBlockGrpImplH
#define UHLP_DMSprInfBlockGrpImplH
#include "IHLP_DMSprInfBlockGrp.h"
#include "UHLP_DMSprInfBlockGrp.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_THLP_DMSprInfBlockGrpImpl)) THLP_DMSprInfBlockGrpImpl : public IHLP_DMSprInfBlockGrp
{
public:
   THLP_DMSprInfBlockGrpImpl();
   ~THLP_DMSprInfBlockGrpImpl();
   THLP_DMSprInfBlockGrp * Object;
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

//IHLP_DMSprInfBlockGrp
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

   virtual TFIBLargeIntField * get_TableID_HLP_IB_GRP(void);
   virtual void set_TableID_HLP_IB_GRP(TFIBLargeIntField * TableID_HLP_IB_GRP);

   virtual TFIBLargeIntField * get_TableIDBASE_HLP_IB_GRP(void);
   virtual void set_TableIDBASE_HLP_IB_GRP(TFIBLargeIntField * TableIDBASE_HLP_IB_GRP);

   virtual TFIBWideStringField * get_TableGUID_HLP_IB_GRP(void);
   virtual void set_TableGUID_HLP_IB_GRP(TFIBWideStringField * TableGUID_HLP_IB_GRP);

   virtual TFIBWideStringField * get_TableNAME_HLP_IB_GRP(void);
   virtual void set_TableNAME_HLP_IB_GRP(TFIBWideStringField * TableNAME_HLP_IB_GRP);

   virtual TFIBLargeIntField * get_TableIDGRP_HLP_IB_GRP(void);
   virtual void set_TableIDGRP_HLP_IB_GRP(TFIBLargeIntField * TableIDGRP_HLP_IB_GRP);

   virtual TFIBWideStringField * get_TableGUID_GRP_HLP_IB_GRP(void);
   virtual void set_TableGUID_GRP_HLP_IB_GRP(TFIBWideStringField * TableGUID_GRP_HLP_IB_GRP);

   virtual TFIBDateTimeField * get_TablePOS_ISM_HLP_IB_GRP(void);
   virtual void set_TablePOS_ISM_HLP_IB_GRP(TFIBDateTimeField * TablePOS_ISM_HLP_IB_GRP);

   virtual TFIBIntegerField * get_TableINDEX_HLP_IB_GRP(void);
   virtual void set_TableINDEX_HLP_IB_GRP(TFIBIntegerField * TableINDEX_HLP_IB_GRP);

   virtual TFIBLargeIntField * get_ElementID_HLP_IB_GRP(void);
   virtual void set_ElementID_HLP_IB_GRP(TFIBLargeIntField * ElementID_HLP_IB_GRP);

   virtual TFIBLargeIntField * get_ElementIDBASE_HLP_IB_GRP(void);
   virtual void set_ElementIDBASE_HLP_IB_GRP(TFIBLargeIntField * ElementIDBASE_HLP_IB_GRP);

   virtual TFIBWideStringField * get_ElementGUID_HLP_IB_GRP(void);
   virtual void set_ElementGUID_HLP_IB_GRP(TFIBWideStringField * ElementGUID_HLP_IB_GRP);

   virtual TFIBWideStringField * get_ElementNAME_HLP_IB_GRP(void);
   virtual void set_ElementNAME_HLP_IB_GRP(TFIBWideStringField * ElementNAME_HLP_IB_GRP);

   virtual TFIBLargeIntField * get_ElementIDGRP_HLP_IB_GRP(void);
   virtual void set_ElementIDGRP_HLP_IB_GRP(TFIBLargeIntField * ElementIDGRP_HLP_IB_GRP);

   virtual TFIBWideStringField * get_ElementGUID_GRP_HLP_IB_GRP(void);
   virtual void set_ElementGUID_GRP_HLP_IB_GRP(TFIBWideStringField * ElementGUID_GRP_HLP_IB_GRP);

   virtual TFIBDateTimeField * get_ElementPOS_ISM_HLP_IB_GRP(void);
   virtual void set_ElementPOS_ISM_HLP_IB_GRP(TFIBDateTimeField * ElementPOS_ISM_HLP_IB_GRP);

   virtual TFIBIntegerField * get_ElementINDEX_HLP_IB_GRP(void);
   virtual void set_ElementINDEX_HLP_IB_GRP(TFIBIntegerField * ElementINDEX_HLP_IB_GRP);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(__int64 id_grp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual __int64 FindPoName(UnicodeString name);
};
#define CLSID_THLP_DMSprInfBlockGrpImpl __uuidof(THLP_DMSprInfBlockGrpImpl)
#endif
