#ifndef UHLP_DMSprNaborInfBlockImplH
#define UHLP_DMSprNaborInfBlockImplH
#include "IHLP_DMSprNaborInfBlock.h"
#include "UHLP_DMSprNaborInfBlock.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_THLP_DMSprNaborInfBlockImpl)) THLP_DMSprNaborInfBlockImpl : public IHLP_DMSprNaborInfBlock
{
public:
   THLP_DMSprNaborInfBlockImpl();
   ~THLP_DMSprNaborInfBlockImpl();
   THLP_DMSprNaborInfBlock * Object;
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

//IHLP_DMSprNaborInfBlock
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

   virtual TFIBLargeIntField * get_TableID_HLP_N_IB(void);
   virtual void set_TableID_HLP_N_IB(TFIBLargeIntField * TableID_HLP_N_IB);

   virtual TFIBLargeIntField * get_TableIDBASE_HLP_N_IB(void);
   virtual void set_TableIDBASE_HLP_N_IB(TFIBLargeIntField * TableIDBASE_HLP_N_IB);

   virtual TFIBWideStringField * get_TableGUID_HLP_N_IB(void);
   virtual void set_TableGUID_HLP_N_IB(TFIBWideStringField * TableGUID_HLP_N_IB);

   virtual TFIBDateTimeField * get_TablePOS_ISM_HLP_N_IB(void);
   virtual void set_TablePOS_ISM_HLP_N_IB(TFIBDateTimeField * TablePOS_ISM_HLP_N_IB);

   virtual TFIBLargeIntField * get_TableIDGRP_HLP_N_IB(void);
   virtual void set_TableIDGRP_HLP_N_IB(TFIBLargeIntField * TableIDGRP_HLP_N_IB);

   virtual TFIBWideStringField * get_TableNAME_HLP_N_IB(void);
   virtual void set_TableNAME_HLP_N_IB(TFIBWideStringField * TableNAME_HLP_N_IB);

   virtual TFIBIntegerField * get_TableINDEX_HLP_N_IB(void);
   virtual void set_TableINDEX_HLP_N_IB(TFIBIntegerField * TableINDEX_HLP_N_IB);

   virtual TFIBLargeIntField * get_ElementID_HLP_N_IB(void);
   virtual void set_ElementID_HLP_N_IB(TFIBLargeIntField * ElementID_HLP_N_IB);

   virtual TFIBLargeIntField * get_ElementIDBASE_HLP_N_IB(void);
   virtual void set_ElementIDBASE_HLP_N_IB(TFIBLargeIntField * ElementIDBASE_HLP_N_IB);

   virtual TFIBWideStringField * get_ElementGUID_HLP_N_IB(void);
   virtual void set_ElementGUID_HLP_N_IB(TFIBWideStringField * ElementGUID_HLP_N_IB);

   virtual TFIBDateTimeField * get_ElementPOS_ISM_HLP_N_IB(void);
   virtual void set_ElementPOS_ISM_HLP_N_IB(TFIBDateTimeField * ElementPOS_ISM_HLP_N_IB);

   virtual TFIBLargeIntField * get_ElementIDGRP_HLP_N_IB(void);
   virtual void set_ElementIDGRP_HLP_N_IB(TFIBLargeIntField * ElementIDGRP_HLP_N_IB);

   virtual TFIBWideStringField * get_ElementNAME_HLP_N_IB(void);
   virtual void set_ElementNAME_HLP_N_IB(TFIBWideStringField * ElementNAME_HLP_N_IB);

   virtual TFIBIntegerField * get_ElementINDEX_HLP_N_IB(void);
   virtual void set_ElementINDEX_HLP_N_IB(TFIBIntegerField * ElementINDEX_HLP_N_IB);

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
#define CLSID_THLP_DMSprNaborInfBlockImpl __uuidof(THLP_DMSprNaborInfBlockImpl)
#endif
