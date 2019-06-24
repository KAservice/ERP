#ifndef UHLP_DMSprInfBlockSostavImplH
#define UHLP_DMSprInfBlockSostavImplH
#include "IHLP_DMSprInfBlockSostav.h"
#include "UHLP_DMSprInfBlockSostav.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_THLP_DMSprInfBlockSostavImpl)) THLP_DMSprInfBlockSostavImpl : public IHLP_DMSprInfBlockSostav
{
public:
   THLP_DMSprInfBlockSostavImpl();
   ~THLP_DMSprInfBlockSostavImpl();
   THLP_DMSprInfBlockSostav * Object;
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

//IHLP_DMSprInfBlockSostav
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

   virtual TFIBLargeIntField * get_TableID_HLP_IB_S(void);
   virtual void set_TableID_HLP_IB_S(TFIBLargeIntField * TableID_HLP_IB_S);

   virtual TFIBLargeIntField * get_TableIDBASE_HLP_IB_S(void);
   virtual void set_TableIDBASE_HLP_IB_S(TFIBLargeIntField * TableIDBASE_HLP_IB_S);

   virtual TFIBWideStringField * get_TableGUID_HLP_IB_S(void);
   virtual void set_TableGUID_HLP_IB_S(TFIBWideStringField * TableGUID_HLP_IB_S);

   virtual TFIBDateTimeField * get_TablePOS_ISM_HLP_IB_S(void);
   virtual void set_TablePOS_ISM_HLP_IB_S(TFIBDateTimeField * TablePOS_ISM_HLP_IB_S);

   virtual TFIBLargeIntField * get_TableIDIB_HLP_IB_S(void);
   virtual void set_TableIDIB_HLP_IB_S(TFIBLargeIntField * TableIDIB_HLP_IB_S);

   virtual TFIBSmallIntField * get_TableTYPE_HLP_IB_S(void);
   virtual void set_TableTYPE_HLP_IB_S(TFIBSmallIntField * TableTYPE_HLP_IB_S);

   virtual TFIBWideStringField * get_TableTEXT_HLP_IB_S(void);
   virtual void set_TableTEXT_HLP_IB_S(TFIBWideStringField * TableTEXT_HLP_IB_S);

   virtual TFIBLargeIntField * get_TableIDIMG_HLP_IB_S(void);
   virtual void set_TableIDIMG_HLP_IB_S(TFIBLargeIntField * TableIDIMG_HLP_IB_S);

   virtual TFIBIntegerField * get_TableINDEX_HLP_IB_S(void);
   virtual void set_TableINDEX_HLP_IB_S(TFIBIntegerField * TableINDEX_HLP_IB_S);

   virtual TFIBIntegerField * get_TableH_ALIGN_HLP_IB_S(void);
   virtual void set_TableH_ALIGN_HLP_IB_S(TFIBIntegerField * TableH_ALIGN_HLP_IB_S);

   virtual TFIBIntegerField * get_TableV_ALIGN_HLP_IB_S(void);
   virtual void set_TableV_ALIGN_HLP_IB_S(TFIBIntegerField * TableV_ALIGN_HLP_IB_S);

   virtual TFIBIntegerField * get_TableTYPE_TEXT_HLP_IB_S(void);
   virtual void set_TableTYPE_TEXT_HLP_IB_S(TFIBIntegerField * TableTYPE_TEXT_HLP_IB_S);

   virtual TFIBIntegerField * get_TableFONT_SIZE_HLP_IB_S(void);
   virtual void set_TableFONT_SIZE_HLP_IB_S(TFIBIntegerField * TableFONT_SIZE_HLP_IB_S);

   virtual TFIBWideStringField * get_TableNAME_HLP_IMG(void);
   virtual void set_TableNAME_HLP_IMG(TFIBWideStringField * TableNAME_HLP_IMG);

   virtual TFIBLargeIntField * get_ElementID_HLP_IB_S(void);
   virtual void set_ElementID_HLP_IB_S(TFIBLargeIntField * ElementID_HLP_IB_S);

   virtual TFIBLargeIntField * get_ElementIDBASE_HLP_IB_S(void);
   virtual void set_ElementIDBASE_HLP_IB_S(TFIBLargeIntField * ElementIDBASE_HLP_IB_S);

   virtual TFIBWideStringField * get_ElementGUID_HLP_IB_S(void);
   virtual void set_ElementGUID_HLP_IB_S(TFIBWideStringField * ElementGUID_HLP_IB_S);

   virtual TFIBDateTimeField * get_ElementPOS_ISM_HLP_IB_S(void);
   virtual void set_ElementPOS_ISM_HLP_IB_S(TFIBDateTimeField * ElementPOS_ISM_HLP_IB_S);

   virtual TFIBLargeIntField * get_ElementIDIB_HLP_IB_S(void);
   virtual void set_ElementIDIB_HLP_IB_S(TFIBLargeIntField * ElementIDIB_HLP_IB_S);

   virtual TFIBSmallIntField * get_ElementTYPE_HLP_IB_S(void);
   virtual void set_ElementTYPE_HLP_IB_S(TFIBSmallIntField * ElementTYPE_HLP_IB_S);

   virtual TFIBWideStringField * get_ElementTEXT_HLP_IB_S(void);
   virtual void set_ElementTEXT_HLP_IB_S(TFIBWideStringField * ElementTEXT_HLP_IB_S);

   virtual TFIBLargeIntField * get_ElementIDIMG_HLP_IB_S(void);
   virtual void set_ElementIDIMG_HLP_IB_S(TFIBLargeIntField * ElementIDIMG_HLP_IB_S);

   virtual TFIBIntegerField * get_ElementINDEX_HLP_IB_S(void);
   virtual void set_ElementINDEX_HLP_IB_S(TFIBIntegerField * ElementINDEX_HLP_IB_S);

   virtual TFIBIntegerField * get_ElementH_ALIGN_HLP_IB_S(void);
   virtual void set_ElementH_ALIGN_HLP_IB_S(TFIBIntegerField * ElementH_ALIGN_HLP_IB_S);

   virtual TFIBIntegerField * get_ElementV_ALIGN_HLP_IB_S(void);
   virtual void set_ElementV_ALIGN_HLP_IB_S(TFIBIntegerField * ElementV_ALIGN_HLP_IB_S);

   virtual TFIBIntegerField * get_ElementTYPE_TEXT_HLP_IB_S(void);
   virtual void set_ElementTYPE_TEXT_HLP_IB_S(TFIBIntegerField * ElementTYPE_TEXT_HLP_IB_S);

   virtual TFIBIntegerField * get_ElementFONT_SIZE_HLP_IB_S(void);
   virtual void set_ElementFONT_SIZE_HLP_IB_S(TFIBIntegerField * ElementFONT_SIZE_HLP_IB_S);

   virtual __int64 get_IdIB(void);
   virtual void set_IdIB(__int64 IdIB);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual void OpenTable(__int64 id_ib);
   virtual bool SaveIsmen(void);
   virtual bool CancelIsmen(void);
   virtual bool TableAppend(__int64 id_ib);
   virtual bool TableDelete(void);
   virtual bool NewElement(__int64 id_ib);
   virtual int OpenElement(__int64 id );
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
};
#define CLSID_THLP_DMSprInfBlockSostavImpl __uuidof(THLP_DMSprInfBlockSostavImpl)
#endif
