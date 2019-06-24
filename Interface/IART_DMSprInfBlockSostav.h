#ifndef UIART_DMSprInfBlockSostavH
#define UIART_DMSprInfBlockSostavH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IART_DMSprInfBlockSostav)) IART_DMSprInfBlockSostav : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TDataSource * DataSourceElement = {read = get_DataSourceElement , write = set_DataSourceElement};
   virtual TDataSource * get_DataSourceElement(void)=0;
   virtual void set_DataSourceElement(TDataSource * DataSourceElement)=0;

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TFIBLargeIntField * TableID_ART_IB_S = {read = get_TableID_ART_IB_S , write = set_TableID_ART_IB_S};
   virtual TFIBLargeIntField * get_TableID_ART_IB_S(void)=0;
   virtual void set_TableID_ART_IB_S(TFIBLargeIntField * TableID_ART_IB_S)=0;

   __property TFIBLargeIntField * TableIDBASE_ART_IB_S = {read = get_TableIDBASE_ART_IB_S , write = set_TableIDBASE_ART_IB_S};
   virtual TFIBLargeIntField * get_TableIDBASE_ART_IB_S(void)=0;
   virtual void set_TableIDBASE_ART_IB_S(TFIBLargeIntField * TableIDBASE_ART_IB_S)=0;

   __property TFIBWideStringField * TableGUID_ART_IB_S = {read = get_TableGUID_ART_IB_S , write = set_TableGUID_ART_IB_S};
   virtual TFIBWideStringField * get_TableGUID_ART_IB_S(void)=0;
   virtual void set_TableGUID_ART_IB_S(TFIBWideStringField * TableGUID_ART_IB_S)=0;

   __property TFIBDateTimeField * TablePOS_ISM_ART_IB_S = {read = get_TablePOS_ISM_ART_IB_S , write = set_TablePOS_ISM_ART_IB_S};
   virtual TFIBDateTimeField * get_TablePOS_ISM_ART_IB_S(void)=0;
   virtual void set_TablePOS_ISM_ART_IB_S(TFIBDateTimeField * TablePOS_ISM_ART_IB_S)=0;

   __property TFIBLargeIntField * TableIDIB_ART_IB_S = {read = get_TableIDIB_ART_IB_S , write = set_TableIDIB_ART_IB_S};
   virtual TFIBLargeIntField * get_TableIDIB_ART_IB_S(void)=0;
   virtual void set_TableIDIB_ART_IB_S(TFIBLargeIntField * TableIDIB_ART_IB_S)=0;

   __property TFIBSmallIntField * TableTYPE_ART_IB_S = {read = get_TableTYPE_ART_IB_S , write = set_TableTYPE_ART_IB_S};
   virtual TFIBSmallIntField * get_TableTYPE_ART_IB_S(void)=0;
   virtual void set_TableTYPE_ART_IB_S(TFIBSmallIntField * TableTYPE_ART_IB_S)=0;

   __property TFIBWideStringField * TableTEXT_ART_IB_S = {read = get_TableTEXT_ART_IB_S , write = set_TableTEXT_ART_IB_S};
   virtual TFIBWideStringField * get_TableTEXT_ART_IB_S(void)=0;
   virtual void set_TableTEXT_ART_IB_S(TFIBWideStringField * TableTEXT_ART_IB_S)=0;

   __property TFIBLargeIntField * TableIDIMG_ART_IB_S = {read = get_TableIDIMG_ART_IB_S , write = set_TableIDIMG_ART_IB_S};
   virtual TFIBLargeIntField * get_TableIDIMG_ART_IB_S(void)=0;
   virtual void set_TableIDIMG_ART_IB_S(TFIBLargeIntField * TableIDIMG_ART_IB_S)=0;

   __property TFIBIntegerField * TableINDEX_ART_IB_S = {read = get_TableINDEX_ART_IB_S , write = set_TableINDEX_ART_IB_S};
   virtual TFIBIntegerField * get_TableINDEX_ART_IB_S(void)=0;
   virtual void set_TableINDEX_ART_IB_S(TFIBIntegerField * TableINDEX_ART_IB_S)=0;

   __property TFIBIntegerField * TableH_ALIGN_ART_IB_S = {read = get_TableH_ALIGN_ART_IB_S , write = set_TableH_ALIGN_ART_IB_S};
   virtual TFIBIntegerField * get_TableH_ALIGN_ART_IB_S(void)=0;
   virtual void set_TableH_ALIGN_ART_IB_S(TFIBIntegerField * TableH_ALIGN_ART_IB_S)=0;

   __property TFIBWideStringField * TableNAME_ART_IMG = {read = get_TableNAME_ART_IMG , write = set_TableNAME_ART_IMG};
   virtual TFIBWideStringField * get_TableNAME_ART_IMG(void)=0;
   virtual void set_TableNAME_ART_IMG(TFIBWideStringField * TableNAME_ART_IMG)=0;

   __property TFIBLargeIntField * ElementID_ART_IB_S = {read = get_ElementID_ART_IB_S , write = set_ElementID_ART_IB_S};
   virtual TFIBLargeIntField * get_ElementID_ART_IB_S(void)=0;
   virtual void set_ElementID_ART_IB_S(TFIBLargeIntField * ElementID_ART_IB_S)=0;

   __property TFIBLargeIntField * ElementIDBASE_ART_IB_S = {read = get_ElementIDBASE_ART_IB_S , write = set_ElementIDBASE_ART_IB_S};
   virtual TFIBLargeIntField * get_ElementIDBASE_ART_IB_S(void)=0;
   virtual void set_ElementIDBASE_ART_IB_S(TFIBLargeIntField * ElementIDBASE_ART_IB_S)=0;

   __property TFIBWideStringField * ElementGUID_ART_IB_S = {read = get_ElementGUID_ART_IB_S , write = set_ElementGUID_ART_IB_S};
   virtual TFIBWideStringField * get_ElementGUID_ART_IB_S(void)=0;
   virtual void set_ElementGUID_ART_IB_S(TFIBWideStringField * ElementGUID_ART_IB_S)=0;

   __property TFIBDateTimeField * ElementPOS_ISM_ART_IB_S = {read = get_ElementPOS_ISM_ART_IB_S , write = set_ElementPOS_ISM_ART_IB_S};
   virtual TFIBDateTimeField * get_ElementPOS_ISM_ART_IB_S(void)=0;
   virtual void set_ElementPOS_ISM_ART_IB_S(TFIBDateTimeField * ElementPOS_ISM_ART_IB_S)=0;

   __property TFIBLargeIntField * ElementIDIB_ART_IB_S = {read = get_ElementIDIB_ART_IB_S , write = set_ElementIDIB_ART_IB_S};
   virtual TFIBLargeIntField * get_ElementIDIB_ART_IB_S(void)=0;
   virtual void set_ElementIDIB_ART_IB_S(TFIBLargeIntField * ElementIDIB_ART_IB_S)=0;

   __property TFIBSmallIntField * ElementTYPE_ART_IB_S = {read = get_ElementTYPE_ART_IB_S , write = set_ElementTYPE_ART_IB_S};
   virtual TFIBSmallIntField * get_ElementTYPE_ART_IB_S(void)=0;
   virtual void set_ElementTYPE_ART_IB_S(TFIBSmallIntField * ElementTYPE_ART_IB_S)=0;

   __property TFIBWideStringField * ElementTEXT_ART_IB_S = {read = get_ElementTEXT_ART_IB_S , write = set_ElementTEXT_ART_IB_S};
   virtual TFIBWideStringField * get_ElementTEXT_ART_IB_S(void)=0;
   virtual void set_ElementTEXT_ART_IB_S(TFIBWideStringField * ElementTEXT_ART_IB_S)=0;

   __property TFIBLargeIntField * ElementIDIMG_ART_IB_S = {read = get_ElementIDIMG_ART_IB_S , write = set_ElementIDIMG_ART_IB_S};
   virtual TFIBLargeIntField * get_ElementIDIMG_ART_IB_S(void)=0;
   virtual void set_ElementIDIMG_ART_IB_S(TFIBLargeIntField * ElementIDIMG_ART_IB_S)=0;

   __property TFIBIntegerField * ElementINDEX_ART_IB_S = {read = get_ElementINDEX_ART_IB_S , write = set_ElementINDEX_ART_IB_S};
   virtual TFIBIntegerField * get_ElementINDEX_ART_IB_S(void)=0;
   virtual void set_ElementINDEX_ART_IB_S(TFIBIntegerField * ElementINDEX_ART_IB_S)=0;

   __property TFIBIntegerField * ElementH_ALIGN_ART_IB_S = {read = get_ElementH_ALIGN_ART_IB_S , write = set_ElementH_ALIGN_ART_IB_S};
   virtual TFIBIntegerField * get_ElementH_ALIGN_ART_IB_S(void)=0;
   virtual void set_ElementH_ALIGN_ART_IB_S(TFIBIntegerField * ElementH_ALIGN_ART_IB_S)=0;

   __property TFIBIntegerField * ElementV_ALIGN_ART_IB_S = {read = get_ElementV_ALIGN_ART_IB_S , write = set_ElementV_ALIGN_ART_IB_S};
   virtual TFIBIntegerField * get_ElementV_ALIGN_ART_IB_S(void)=0;
   virtual void set_ElementV_ALIGN_ART_IB_S(TFIBIntegerField * ElementV_ALIGN_ART_IB_S)=0;

   __property TFIBIntegerField * ElementTYPE_TEXT_ART_IB_S = {read = get_ElementTYPE_TEXT_ART_IB_S , write = set_ElementTYPE_TEXT_ART_IB_S};
   virtual TFIBIntegerField * get_ElementTYPE_TEXT_ART_IB_S(void)=0;
   virtual void set_ElementTYPE_TEXT_ART_IB_S(TFIBIntegerField * ElementTYPE_TEXT_ART_IB_S)=0;

   __property TFIBIntegerField * TableV_ALIGN_ART_IB_S = {read = get_TableV_ALIGN_ART_IB_S , write = set_TableV_ALIGN_ART_IB_S};
   virtual TFIBIntegerField * get_TableV_ALIGN_ART_IB_S(void)=0;
   virtual void set_TableV_ALIGN_ART_IB_S(TFIBIntegerField * TableV_ALIGN_ART_IB_S)=0;

   __property TFIBIntegerField * TableTYPE_TEXT_ART_IB_S = {read = get_TableTYPE_TEXT_ART_IB_S , write = set_TableTYPE_TEXT_ART_IB_S};
   virtual TFIBIntegerField * get_TableTYPE_TEXT_ART_IB_S(void)=0;
   virtual void set_TableTYPE_TEXT_ART_IB_S(TFIBIntegerField * TableTYPE_TEXT_ART_IB_S)=0;

   __property TFIBIntegerField * TableFONT_SIZE_ART_IB_S = {read = get_TableFONT_SIZE_ART_IB_S , write = set_TableFONT_SIZE_ART_IB_S};
   virtual TFIBIntegerField * get_TableFONT_SIZE_ART_IB_S(void)=0;
   virtual void set_TableFONT_SIZE_ART_IB_S(TFIBIntegerField * TableFONT_SIZE_ART_IB_S)=0;

   __property TFIBIntegerField * ElementFONT_SIZE_ART_IB_S = {read = get_ElementFONT_SIZE_ART_IB_S , write = set_ElementFONT_SIZE_ART_IB_S};
   virtual TFIBIntegerField * get_ElementFONT_SIZE_ART_IB_S(void)=0;
   virtual void set_ElementFONT_SIZE_ART_IB_S(TFIBIntegerField * ElementFONT_SIZE_ART_IB_S)=0;

   __property __int64 IdIB = {read = get_IdIB , write = set_IdIB};
   virtual __int64 get_IdIB(void)=0;
   virtual void set_IdIB(__int64 IdIB)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   virtual void OpenTable(__int64 id_ib)=0;
   virtual bool SaveIsmen(void)=0;
   virtual bool CancelIsmen(void)=0;
   virtual bool TableAppend(__int64 id_ib)=0;
   virtual bool TableDelete(void)=0;
   virtual bool NewElement(__int64 id_ib)=0;
   virtual int OpenElement(__int64 id )=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
};
#define IID_IART_DMSprInfBlockSostav __uuidof(IART_DMSprInfBlockSostav)
#endif
