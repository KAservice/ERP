#ifndef UART_DMSprInfBlockSostavImplH
#define UART_DMSprInfBlockSostavImplH
#include "IART_DMSprInfBlockSostav.h"
#include "UART_DMSprInfBlockSostav.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TART_DMSprInfBlockSostavImpl)) TART_DMSprInfBlockSostavImpl : public IART_DMSprInfBlockSostav
{
public:
   TART_DMSprInfBlockSostavImpl();
   ~TART_DMSprInfBlockSostavImpl();
   TART_DMSprInfBlockSostav * Object;
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

//IART_DMSprInfBlockSostav
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

   virtual TFIBLargeIntField * get_TableID_ART_IB_S(void);
   virtual void set_TableID_ART_IB_S(TFIBLargeIntField * TableID_ART_IB_S);

   virtual TFIBLargeIntField * get_TableIDBASE_ART_IB_S(void);
   virtual void set_TableIDBASE_ART_IB_S(TFIBLargeIntField * TableIDBASE_ART_IB_S);

   virtual TFIBWideStringField * get_TableGUID_ART_IB_S(void);
   virtual void set_TableGUID_ART_IB_S(TFIBWideStringField * TableGUID_ART_IB_S);

   virtual TFIBDateTimeField * get_TablePOS_ISM_ART_IB_S(void);
   virtual void set_TablePOS_ISM_ART_IB_S(TFIBDateTimeField * TablePOS_ISM_ART_IB_S);

   virtual TFIBLargeIntField * get_TableIDIB_ART_IB_S(void);
   virtual void set_TableIDIB_ART_IB_S(TFIBLargeIntField * TableIDIB_ART_IB_S);

   virtual TFIBSmallIntField * get_TableTYPE_ART_IB_S(void);
   virtual void set_TableTYPE_ART_IB_S(TFIBSmallIntField * TableTYPE_ART_IB_S);

   virtual TFIBWideStringField * get_TableTEXT_ART_IB_S(void);
   virtual void set_TableTEXT_ART_IB_S(TFIBWideStringField * TableTEXT_ART_IB_S);

   virtual TFIBLargeIntField * get_TableIDIMG_ART_IB_S(void);
   virtual void set_TableIDIMG_ART_IB_S(TFIBLargeIntField * TableIDIMG_ART_IB_S);

   virtual TFIBIntegerField * get_TableINDEX_ART_IB_S(void);
   virtual void set_TableINDEX_ART_IB_S(TFIBIntegerField * TableINDEX_ART_IB_S);

   virtual TFIBIntegerField * get_TableH_ALIGN_ART_IB_S(void);
   virtual void set_TableH_ALIGN_ART_IB_S(TFIBIntegerField * TableH_ALIGN_ART_IB_S);

   virtual TFIBWideStringField * get_TableNAME_ART_IMG(void);
   virtual void set_TableNAME_ART_IMG(TFIBWideStringField * TableNAME_ART_IMG);

   virtual TFIBLargeIntField * get_ElementID_ART_IB_S(void);
   virtual void set_ElementID_ART_IB_S(TFIBLargeIntField * ElementID_ART_IB_S);

   virtual TFIBLargeIntField * get_ElementIDBASE_ART_IB_S(void);
   virtual void set_ElementIDBASE_ART_IB_S(TFIBLargeIntField * ElementIDBASE_ART_IB_S);

   virtual TFIBWideStringField * get_ElementGUID_ART_IB_S(void);
   virtual void set_ElementGUID_ART_IB_S(TFIBWideStringField * ElementGUID_ART_IB_S);

   virtual TFIBDateTimeField * get_ElementPOS_ISM_ART_IB_S(void);
   virtual void set_ElementPOS_ISM_ART_IB_S(TFIBDateTimeField * ElementPOS_ISM_ART_IB_S);

   virtual TFIBLargeIntField * get_ElementIDIB_ART_IB_S(void);
   virtual void set_ElementIDIB_ART_IB_S(TFIBLargeIntField * ElementIDIB_ART_IB_S);

   virtual TFIBSmallIntField * get_ElementTYPE_ART_IB_S(void);
   virtual void set_ElementTYPE_ART_IB_S(TFIBSmallIntField * ElementTYPE_ART_IB_S);

   virtual TFIBWideStringField * get_ElementTEXT_ART_IB_S(void);
   virtual void set_ElementTEXT_ART_IB_S(TFIBWideStringField * ElementTEXT_ART_IB_S);

   virtual TFIBLargeIntField * get_ElementIDIMG_ART_IB_S(void);
   virtual void set_ElementIDIMG_ART_IB_S(TFIBLargeIntField * ElementIDIMG_ART_IB_S);

   virtual TFIBIntegerField * get_ElementINDEX_ART_IB_S(void);
   virtual void set_ElementINDEX_ART_IB_S(TFIBIntegerField * ElementINDEX_ART_IB_S);

   virtual TFIBIntegerField * get_ElementH_ALIGN_ART_IB_S(void);
   virtual void set_ElementH_ALIGN_ART_IB_S(TFIBIntegerField * ElementH_ALIGN_ART_IB_S);

   virtual TFIBIntegerField * get_ElementV_ALIGN_ART_IB_S(void);
   virtual void set_ElementV_ALIGN_ART_IB_S(TFIBIntegerField * ElementV_ALIGN_ART_IB_S);

   virtual TFIBIntegerField * get_ElementTYPE_TEXT_ART_IB_S(void);
   virtual void set_ElementTYPE_TEXT_ART_IB_S(TFIBIntegerField * ElementTYPE_TEXT_ART_IB_S);

   virtual TFIBIntegerField * get_TableV_ALIGN_ART_IB_S(void);
   virtual void set_TableV_ALIGN_ART_IB_S(TFIBIntegerField * TableV_ALIGN_ART_IB_S);

   virtual TFIBIntegerField * get_TableTYPE_TEXT_ART_IB_S(void);
   virtual void set_TableTYPE_TEXT_ART_IB_S(TFIBIntegerField * TableTYPE_TEXT_ART_IB_S);

   virtual TFIBIntegerField * get_TableFONT_SIZE_ART_IB_S(void);
   virtual void set_TableFONT_SIZE_ART_IB_S(TFIBIntegerField * TableFONT_SIZE_ART_IB_S);

   virtual TFIBIntegerField * get_ElementFONT_SIZE_ART_IB_S(void);
   virtual void set_ElementFONT_SIZE_ART_IB_S(TFIBIntegerField * ElementFONT_SIZE_ART_IB_S);

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
#define CLSID_TART_DMSprInfBlockSostavImpl __uuidof(TART_DMSprInfBlockSostavImpl)
#endif
