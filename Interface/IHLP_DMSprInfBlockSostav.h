#ifndef UIHLP_DMSprInfBlockSostavH
#define UIHLP_DMSprInfBlockSostavH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IHLP_DMSprInfBlockSostav)) IHLP_DMSprInfBlockSostav : public IMainInterface
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

   __property TFIBLargeIntField * TableID_HLP_IB_S = {read = get_TableID_HLP_IB_S , write = set_TableID_HLP_IB_S};
   virtual TFIBLargeIntField * get_TableID_HLP_IB_S(void)=0;
   virtual void set_TableID_HLP_IB_S(TFIBLargeIntField * TableID_HLP_IB_S)=0;

   __property TFIBLargeIntField * TableIDBASE_HLP_IB_S = {read = get_TableIDBASE_HLP_IB_S , write = set_TableIDBASE_HLP_IB_S};
   virtual TFIBLargeIntField * get_TableIDBASE_HLP_IB_S(void)=0;
   virtual void set_TableIDBASE_HLP_IB_S(TFIBLargeIntField * TableIDBASE_HLP_IB_S)=0;

   __property TFIBWideStringField * TableGUID_HLP_IB_S = {read = get_TableGUID_HLP_IB_S , write = set_TableGUID_HLP_IB_S};
   virtual TFIBWideStringField * get_TableGUID_HLP_IB_S(void)=0;
   virtual void set_TableGUID_HLP_IB_S(TFIBWideStringField * TableGUID_HLP_IB_S)=0;

   __property TFIBDateTimeField * TablePOS_ISM_HLP_IB_S = {read = get_TablePOS_ISM_HLP_IB_S , write = set_TablePOS_ISM_HLP_IB_S};
   virtual TFIBDateTimeField * get_TablePOS_ISM_HLP_IB_S(void)=0;
   virtual void set_TablePOS_ISM_HLP_IB_S(TFIBDateTimeField * TablePOS_ISM_HLP_IB_S)=0;

   __property TFIBLargeIntField * TableIDIB_HLP_IB_S = {read = get_TableIDIB_HLP_IB_S , write = set_TableIDIB_HLP_IB_S};
   virtual TFIBLargeIntField * get_TableIDIB_HLP_IB_S(void)=0;
   virtual void set_TableIDIB_HLP_IB_S(TFIBLargeIntField * TableIDIB_HLP_IB_S)=0;

   __property TFIBSmallIntField * TableTYPE_HLP_IB_S = {read = get_TableTYPE_HLP_IB_S , write = set_TableTYPE_HLP_IB_S};
   virtual TFIBSmallIntField * get_TableTYPE_HLP_IB_S(void)=0;
   virtual void set_TableTYPE_HLP_IB_S(TFIBSmallIntField * TableTYPE_HLP_IB_S)=0;

   __property TFIBWideStringField * TableTEXT_HLP_IB_S = {read = get_TableTEXT_HLP_IB_S , write = set_TableTEXT_HLP_IB_S};
   virtual TFIBWideStringField * get_TableTEXT_HLP_IB_S(void)=0;
   virtual void set_TableTEXT_HLP_IB_S(TFIBWideStringField * TableTEXT_HLP_IB_S)=0;

   __property TFIBLargeIntField * TableIDIMG_HLP_IB_S = {read = get_TableIDIMG_HLP_IB_S , write = set_TableIDIMG_HLP_IB_S};
   virtual TFIBLargeIntField * get_TableIDIMG_HLP_IB_S(void)=0;
   virtual void set_TableIDIMG_HLP_IB_S(TFIBLargeIntField * TableIDIMG_HLP_IB_S)=0;

   __property TFIBIntegerField * TableINDEX_HLP_IB_S = {read = get_TableINDEX_HLP_IB_S , write = set_TableINDEX_HLP_IB_S};
   virtual TFIBIntegerField * get_TableINDEX_HLP_IB_S(void)=0;
   virtual void set_TableINDEX_HLP_IB_S(TFIBIntegerField * TableINDEX_HLP_IB_S)=0;

   __property TFIBIntegerField * TableH_ALIGN_HLP_IB_S = {read = get_TableH_ALIGN_HLP_IB_S , write = set_TableH_ALIGN_HLP_IB_S};
   virtual TFIBIntegerField * get_TableH_ALIGN_HLP_IB_S(void)=0;
   virtual void set_TableH_ALIGN_HLP_IB_S(TFIBIntegerField * TableH_ALIGN_HLP_IB_S)=0;

   __property TFIBIntegerField * TableV_ALIGN_HLP_IB_S = {read = get_TableV_ALIGN_HLP_IB_S , write = set_TableV_ALIGN_HLP_IB_S};
   virtual TFIBIntegerField * get_TableV_ALIGN_HLP_IB_S(void)=0;
   virtual void set_TableV_ALIGN_HLP_IB_S(TFIBIntegerField * TableV_ALIGN_HLP_IB_S)=0;

   __property TFIBIntegerField * TableTYPE_TEXT_HLP_IB_S = {read = get_TableTYPE_TEXT_HLP_IB_S , write = set_TableTYPE_TEXT_HLP_IB_S};
   virtual TFIBIntegerField * get_TableTYPE_TEXT_HLP_IB_S(void)=0;
   virtual void set_TableTYPE_TEXT_HLP_IB_S(TFIBIntegerField * TableTYPE_TEXT_HLP_IB_S)=0;

   __property TFIBIntegerField * TableFONT_SIZE_HLP_IB_S = {read = get_TableFONT_SIZE_HLP_IB_S , write = set_TableFONT_SIZE_HLP_IB_S};
   virtual TFIBIntegerField * get_TableFONT_SIZE_HLP_IB_S(void)=0;
   virtual void set_TableFONT_SIZE_HLP_IB_S(TFIBIntegerField * TableFONT_SIZE_HLP_IB_S)=0;

   __property TFIBWideStringField * TableNAME_HLP_IMG = {read = get_TableNAME_HLP_IMG , write = set_TableNAME_HLP_IMG};
   virtual TFIBWideStringField * get_TableNAME_HLP_IMG(void)=0;
   virtual void set_TableNAME_HLP_IMG(TFIBWideStringField * TableNAME_HLP_IMG)=0;

   __property TFIBLargeIntField * ElementID_HLP_IB_S = {read = get_ElementID_HLP_IB_S , write = set_ElementID_HLP_IB_S};
   virtual TFIBLargeIntField * get_ElementID_HLP_IB_S(void)=0;
   virtual void set_ElementID_HLP_IB_S(TFIBLargeIntField * ElementID_HLP_IB_S)=0;

   __property TFIBLargeIntField * ElementIDBASE_HLP_IB_S = {read = get_ElementIDBASE_HLP_IB_S , write = set_ElementIDBASE_HLP_IB_S};
   virtual TFIBLargeIntField * get_ElementIDBASE_HLP_IB_S(void)=0;
   virtual void set_ElementIDBASE_HLP_IB_S(TFIBLargeIntField * ElementIDBASE_HLP_IB_S)=0;

   __property TFIBWideStringField * ElementGUID_HLP_IB_S = {read = get_ElementGUID_HLP_IB_S , write = set_ElementGUID_HLP_IB_S};
   virtual TFIBWideStringField * get_ElementGUID_HLP_IB_S(void)=0;
   virtual void set_ElementGUID_HLP_IB_S(TFIBWideStringField * ElementGUID_HLP_IB_S)=0;

   __property TFIBDateTimeField * ElementPOS_ISM_HLP_IB_S = {read = get_ElementPOS_ISM_HLP_IB_S , write = set_ElementPOS_ISM_HLP_IB_S};
   virtual TFIBDateTimeField * get_ElementPOS_ISM_HLP_IB_S(void)=0;
   virtual void set_ElementPOS_ISM_HLP_IB_S(TFIBDateTimeField * ElementPOS_ISM_HLP_IB_S)=0;

   __property TFIBLargeIntField * ElementIDIB_HLP_IB_S = {read = get_ElementIDIB_HLP_IB_S , write = set_ElementIDIB_HLP_IB_S};
   virtual TFIBLargeIntField * get_ElementIDIB_HLP_IB_S(void)=0;
   virtual void set_ElementIDIB_HLP_IB_S(TFIBLargeIntField * ElementIDIB_HLP_IB_S)=0;

   __property TFIBSmallIntField * ElementTYPE_HLP_IB_S = {read = get_ElementTYPE_HLP_IB_S , write = set_ElementTYPE_HLP_IB_S};
   virtual TFIBSmallIntField * get_ElementTYPE_HLP_IB_S(void)=0;
   virtual void set_ElementTYPE_HLP_IB_S(TFIBSmallIntField * ElementTYPE_HLP_IB_S)=0;

   __property TFIBWideStringField * ElementTEXT_HLP_IB_S = {read = get_ElementTEXT_HLP_IB_S , write = set_ElementTEXT_HLP_IB_S};
   virtual TFIBWideStringField * get_ElementTEXT_HLP_IB_S(void)=0;
   virtual void set_ElementTEXT_HLP_IB_S(TFIBWideStringField * ElementTEXT_HLP_IB_S)=0;

   __property TFIBLargeIntField * ElementIDIMG_HLP_IB_S = {read = get_ElementIDIMG_HLP_IB_S , write = set_ElementIDIMG_HLP_IB_S};
   virtual TFIBLargeIntField * get_ElementIDIMG_HLP_IB_S(void)=0;
   virtual void set_ElementIDIMG_HLP_IB_S(TFIBLargeIntField * ElementIDIMG_HLP_IB_S)=0;

   __property TFIBIntegerField * ElementINDEX_HLP_IB_S = {read = get_ElementINDEX_HLP_IB_S , write = set_ElementINDEX_HLP_IB_S};
   virtual TFIBIntegerField * get_ElementINDEX_HLP_IB_S(void)=0;
   virtual void set_ElementINDEX_HLP_IB_S(TFIBIntegerField * ElementINDEX_HLP_IB_S)=0;

   __property TFIBIntegerField * ElementH_ALIGN_HLP_IB_S = {read = get_ElementH_ALIGN_HLP_IB_S , write = set_ElementH_ALIGN_HLP_IB_S};
   virtual TFIBIntegerField * get_ElementH_ALIGN_HLP_IB_S(void)=0;
   virtual void set_ElementH_ALIGN_HLP_IB_S(TFIBIntegerField * ElementH_ALIGN_HLP_IB_S)=0;

   __property TFIBIntegerField * ElementV_ALIGN_HLP_IB_S = {read = get_ElementV_ALIGN_HLP_IB_S , write = set_ElementV_ALIGN_HLP_IB_S};
   virtual TFIBIntegerField * get_ElementV_ALIGN_HLP_IB_S(void)=0;
   virtual void set_ElementV_ALIGN_HLP_IB_S(TFIBIntegerField * ElementV_ALIGN_HLP_IB_S)=0;

   __property TFIBIntegerField * ElementTYPE_TEXT_HLP_IB_S = {read = get_ElementTYPE_TEXT_HLP_IB_S , write = set_ElementTYPE_TEXT_HLP_IB_S};
   virtual TFIBIntegerField * get_ElementTYPE_TEXT_HLP_IB_S(void)=0;
   virtual void set_ElementTYPE_TEXT_HLP_IB_S(TFIBIntegerField * ElementTYPE_TEXT_HLP_IB_S)=0;

   __property TFIBIntegerField * ElementFONT_SIZE_HLP_IB_S = {read = get_ElementFONT_SIZE_HLP_IB_S , write = set_ElementFONT_SIZE_HLP_IB_S};
   virtual TFIBIntegerField * get_ElementFONT_SIZE_HLP_IB_S(void)=0;
   virtual void set_ElementFONT_SIZE_HLP_IB_S(TFIBIntegerField * ElementFONT_SIZE_HLP_IB_S)=0;

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
#define IID_IHLP_DMSprInfBlockSostav __uuidof(IHLP_DMSprInfBlockSostav)
#endif
