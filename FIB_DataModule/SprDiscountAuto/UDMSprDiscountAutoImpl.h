#ifndef UDMSprDiscountAutoImplH
#define UDMSprDiscountAutoImplH
#include "IDMSprDiscountAuto.h"
#include "UDMSprDiscountAuto.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprDiscountAutoImpl)) TDMSprDiscountAutoImpl : public IDMSprDiscountAuto
{
public:
   TDMSprDiscountAutoImpl();
   ~TDMSprDiscountAutoImpl();
   TDMSprDiscountAuto * Object;
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

//IDMSprDiscountAuto
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

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TpFIBDataSet * get_TableDiscountAuto(void);
   virtual void set_TableDiscountAuto(TpFIBDataSet * TableDiscountAuto);

   virtual TFIBLargeIntField * get_TableID_SDISCOUNT_AUTO(void);
   virtual void set_TableID_SDISCOUNT_AUTO(TFIBLargeIntField * TableID_SDISCOUNT_AUTO);

   virtual TFIBWideStringField * get_TableGID_SDISCOUNT_AUTO(void);
   virtual void set_TableGID_SDISCOUNT_AUTO(TFIBWideStringField * TableGID_SDISCOUNT_AUTO);

   virtual TFIBWideStringField * get_TableNAME_SDISCOUNT_AUTO(void);
   virtual void set_TableNAME_SDISCOUNT_AUTO(TFIBWideStringField * TableNAME_SDISCOUNT_AUTO);

   virtual TFIBSmallIntField * get_TableACT_SDISCOUNT_AUTO(void);
   virtual void set_TableACT_SDISCOUNT_AUTO(TFIBSmallIntField * TableACT_SDISCOUNT_AUTO);

   virtual TFIBDateTimeField * get_TableNACH_SDISCOUNT_AUTO(void);
   virtual void set_TableNACH_SDISCOUNT_AUTO(TFIBDateTimeField * TableNACH_SDISCOUNT_AUTO);

   virtual TFIBDateTimeField * get_TableCON_SDISCOUNT_AUTO(void);
   virtual void set_TableCON_SDISCOUNT_AUTO(TFIBDateTimeField * TableCON_SDISCOUNT_AUTO);

   virtual TFIBBCDField * get_TablePRSK_SDISCOUNT_AUTO(void);
   virtual void set_TablePRSK_SDISCOUNT_AUTO(TFIBBCDField * TablePRSK_SDISCOUNT_AUTO);

   virtual TFIBBCDField * get_TableSUM_SDISCOUNT_AUTO(void);
   virtual void set_TableSUM_SDISCOUNT_AUTO(TFIBBCDField * TableSUM_SDISCOUNT_AUTO);

   virtual TFIBTimeField * get_TableTIME_NACH_SDISCOUNT_AUTO(void);
   virtual void set_TableTIME_NACH_SDISCOUNT_AUTO(TFIBTimeField * TableTIME_NACH_SDISCOUNT_AUTO);

   virtual TFIBTimeField * get_TableTIME_CON_SDISCOUNT_AUTO(void);
   virtual void set_TableTIME_CON_SDISCOUNT_AUTO(TFIBTimeField * TableTIME_CON_SDISCOUNT_AUTO);

   virtual TFIBSmallIntField * get_TableDAY_SDISCOUNT_AUTO(void);
   virtual void set_TableDAY_SDISCOUNT_AUTO(TFIBSmallIntField * TableDAY_SDISCOUNT_AUTO);

   virtual TFIBLargeIntField * get_TableIDVIDNOM_SDISCOUNT_AUTO(void);
   virtual void set_TableIDVIDNOM_SDISCOUNT_AUTO(TFIBLargeIntField * TableIDVIDNOM_SDISCOUNT_AUTO);

   virtual TFIBLargeIntField * get_TableIDSKLAD_SDISCOUNT_AUTO(void);
   virtual void set_TableIDSKLAD_SDISCOUNT_AUTO(TFIBLargeIntField * TableIDSKLAD_SDISCOUNT_AUTO);

   virtual TFIBLargeIntField * get_TableIDBASE_SDISCOUNT_AUTO(void);
   virtual void set_TableIDBASE_SDISCOUNT_AUTO(TFIBLargeIntField * TableIDBASE_SDISCOUNT_AUTO);

   virtual TFIBSmallIntField * get_TableNUM_SKIDKI_SDISCOUNT_AUTO(void);
   virtual void set_TableNUM_SKIDKI_SDISCOUNT_AUTO(TFIBSmallIntField * TableNUM_SKIDKI_SDISCOUNT_AUTO);

   virtual TFIBLargeIntField * get_TableIDGRPNOM_SDISCOUNT_AUTO(void);
   virtual void set_TableIDGRPNOM_SDISCOUNT_AUTO(TFIBLargeIntField * TableIDGRPNOM_SDISCOUNT_AUTO);

   virtual TFIBIntegerField * get_TableTYPE_ACTION_SDISCOUNT_AUTO(void);
   virtual void set_TableTYPE_ACTION_SDISCOUNT_AUTO(TFIBIntegerField * TableTYPE_ACTION_SDISCOUNT_AUTO);

   virtual TFIBWideStringField * get_TableMESSAGE_SDISCOUNT_AUTO(void);
   virtual void set_TableMESSAGE_SDISCOUNT_AUTO(TFIBWideStringField * TableMESSAGE_SDISCOUNT_AUTO);

   virtual TFIBWideStringField * get_TableNAMESKLAD(void);
   virtual void set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD);

   virtual TFIBWideStringField * get_TableNAMEGN(void);
   virtual void set_TableNAMEGN(TFIBWideStringField * TableNAMEGN);

   virtual TFIBWideStringField * get_TableNAME_SVIDNOM(void);
   virtual void set_TableNAME_SVIDNOM(TFIBWideStringField * TableNAME_SVIDNOM);

   virtual TFIBLargeIntField * get_ElementID_SDISCOUNT_AUTO(void);
   virtual void set_ElementID_SDISCOUNT_AUTO(TFIBLargeIntField * ElementID_SDISCOUNT_AUTO);

   virtual TFIBWideStringField * get_ElementGID_SDISCOUNT_AUTO(void);
   virtual void set_ElementGID_SDISCOUNT_AUTO(TFIBWideStringField * ElementGID_SDISCOUNT_AUTO);

   virtual TFIBWideStringField * get_ElementNAME_SDISCOUNT_AUTO(void);
   virtual void set_ElementNAME_SDISCOUNT_AUTO(TFIBWideStringField * ElementNAME_SDISCOUNT_AUTO);

   virtual TFIBSmallIntField * get_ElementACT_SDISCOUNT_AUTO(void);
   virtual void set_ElementACT_SDISCOUNT_AUTO(TFIBSmallIntField * ElementACT_SDISCOUNT_AUTO);

   virtual TFIBDateTimeField * get_ElementNACH_SDISCOUNT_AUTO(void);
   virtual void set_ElementNACH_SDISCOUNT_AUTO(TFIBDateTimeField * ElementNACH_SDISCOUNT_AUTO);

   virtual TFIBDateTimeField * get_ElementCON_SDISCOUNT_AUTO(void);
   virtual void set_ElementCON_SDISCOUNT_AUTO(TFIBDateTimeField * ElementCON_SDISCOUNT_AUTO);

   virtual TFIBBCDField * get_ElementPRSK_SDISCOUNT_AUTO(void);
   virtual void set_ElementPRSK_SDISCOUNT_AUTO(TFIBBCDField * ElementPRSK_SDISCOUNT_AUTO);

   virtual TFIBBCDField * get_ElementSUM_SDISCOUNT_AUTO(void);
   virtual void set_ElementSUM_SDISCOUNT_AUTO(TFIBBCDField * ElementSUM_SDISCOUNT_AUTO);

   virtual TFIBTimeField * get_ElementTIME_NACH_SDISCOUNT_AUTO(void);
   virtual void set_ElementTIME_NACH_SDISCOUNT_AUTO(TFIBTimeField * ElementTIME_NACH_SDISCOUNT_AUTO);

   virtual TFIBTimeField * get_ElementTIME_CON_SDISCOUNT_AUTO(void);
   virtual void set_ElementTIME_CON_SDISCOUNT_AUTO(TFIBTimeField * ElementTIME_CON_SDISCOUNT_AUTO);

   virtual TFIBSmallIntField * get_ElementDAY_SDISCOUNT_AUTO(void);
   virtual void set_ElementDAY_SDISCOUNT_AUTO(TFIBSmallIntField * ElementDAY_SDISCOUNT_AUTO);

   virtual TFIBLargeIntField * get_ElementIDVIDNOM_SDISCOUNT_AUTO(void);
   virtual void set_ElementIDVIDNOM_SDISCOUNT_AUTO(TFIBLargeIntField * ElementIDVIDNOM_SDISCOUNT_AUTO);

   virtual TFIBLargeIntField * get_ElementIDSKLAD_SDISCOUNT_AUTO(void);
   virtual void set_ElementIDSKLAD_SDISCOUNT_AUTO(TFIBLargeIntField * ElementIDSKLAD_SDISCOUNT_AUTO);

   virtual TFIBLargeIntField * get_ElementIDBASE_SDISCOUNT_AUTO(void);
   virtual void set_ElementIDBASE_SDISCOUNT_AUTO(TFIBLargeIntField * ElementIDBASE_SDISCOUNT_AUTO);

   virtual TFIBSmallIntField * get_ElementNUM_SKIDKI_SDISCOUNT_AUTO(void);
   virtual void set_ElementNUM_SKIDKI_SDISCOUNT_AUTO(TFIBSmallIntField * ElementNUM_SKIDKI_SDISCOUNT_AUTO);

   virtual TFIBLargeIntField * get_ElementIDGRPNOM_SDISCOUNT_AUTO(void);
   virtual void set_ElementIDGRPNOM_SDISCOUNT_AUTO(TFIBLargeIntField * ElementIDGRPNOM_SDISCOUNT_AUTO);

   virtual TFIBIntegerField * get_ElementTYPE_ACTION_SDISCOUNT_AUTO(void);
   virtual void set_ElementTYPE_ACTION_SDISCOUNT_AUTO(TFIBIntegerField * ElementTYPE_ACTION_SDISCOUNT_AUTO);

   virtual TFIBWideStringField * get_ElementMESSAGE_SDISCOUNT_AUTO(void);
   virtual void set_ElementMESSAGE_SDISCOUNT_AUTO(TFIBWideStringField * ElementMESSAGE_SDISCOUNT_AUTO);

   virtual TFIBWideStringField * get_ElementNAMESKLAD(void);
   virtual void set_ElementNAMESKLAD(TFIBWideStringField * ElementNAMESKLAD);

   virtual TFIBWideStringField * get_ElementNAMEGN(void);
   virtual void set_ElementNAMEGN(TFIBWideStringField * ElementNAMEGN);

   virtual TFIBWideStringField * get_ElementNAME_SVIDNOM(void);
   virtual void set_ElementNAME_SVIDNOM(TFIBWideStringField * ElementNAME_SVIDNOM);

   virtual TFIBLargeIntField * get_TableDiscountAutoID_SDISCOUNT_AUTO(void);
   virtual void set_TableDiscountAutoID_SDISCOUNT_AUTO(TFIBLargeIntField * TableDiscountAutoID_SDISCOUNT_AUTO);

   virtual TFIBWideStringField * get_TableDiscountAutoGID_SDISCOUNT_AUTO(void);
   virtual void set_TableDiscountAutoGID_SDISCOUNT_AUTO(TFIBWideStringField * TableDiscountAutoGID_SDISCOUNT_AUTO);

   virtual TFIBWideStringField * get_TableDiscountAutoNAME_SDISCOUNT_AUTO(void);
   virtual void set_TableDiscountAutoNAME_SDISCOUNT_AUTO(TFIBWideStringField * TableDiscountAutoNAME_SDISCOUNT_AUTO);

   virtual TFIBSmallIntField * get_TableDiscountAutoACT_SDISCOUNT_AUTO(void);
   virtual void set_TableDiscountAutoACT_SDISCOUNT_AUTO(TFIBSmallIntField * TableDiscountAutoACT_SDISCOUNT_AUTO);

   virtual TFIBDateTimeField * get_TableDiscountAutoNACH_SDISCOUNT_AUTO(void);
   virtual void set_TableDiscountAutoNACH_SDISCOUNT_AUTO(TFIBDateTimeField * TableDiscountAutoNACH_SDISCOUNT_AUTO);

   virtual TFIBDateTimeField * get_TableDiscountAutoCON_SDISCOUNT_AUTO(void);
   virtual void set_TableDiscountAutoCON_SDISCOUNT_AUTO(TFIBDateTimeField * TableDiscountAutoCON_SDISCOUNT_AUTO);

   virtual TFIBBCDField * get_TableDiscountAutoPRSK_SDISCOUNT_AUTO(void);
   virtual void set_TableDiscountAutoPRSK_SDISCOUNT_AUTO(TFIBBCDField * TableDiscountAutoPRSK_SDISCOUNT_AUTO);

   virtual TFIBBCDField * get_TableDiscountAutoSUM_SDISCOUNT_AUTO(void);
   virtual void set_TableDiscountAutoSUM_SDISCOUNT_AUTO(TFIBBCDField * TableDiscountAutoSUM_SDISCOUNT_AUTO);

   virtual TFIBTimeField * get_TableDiscountAutoTIME_NACH_SDISCOUNT_AUTO(void);
   virtual void set_TableDiscountAutoTIME_NACH_SDISCOUNT_AUTO(TFIBTimeField * TableDiscountAutoTIME_NACH_SDISCOUNT_AUTO);

   virtual TFIBTimeField * get_TableDiscountAutoTIME_CON_SDISCOUNT_AUTO(void);
   virtual void set_TableDiscountAutoTIME_CON_SDISCOUNT_AUTO(TFIBTimeField * TableDiscountAutoTIME_CON_SDISCOUNT_AUTO);

   virtual TFIBSmallIntField * get_TableDiscountAutoDAY_SDISCOUNT_AUTO(void);
   virtual void set_TableDiscountAutoDAY_SDISCOUNT_AUTO(TFIBSmallIntField * TableDiscountAutoDAY_SDISCOUNT_AUTO);

   virtual TFIBLargeIntField * get_TableDiscountAutoIDVIDNOM_SDISCOUNT_AUTO(void);
   virtual void set_TableDiscountAutoIDVIDNOM_SDISCOUNT_AUTO(TFIBLargeIntField * TableDiscountAutoIDVIDNOM_SDISCOUNT_AUTO);

   virtual TFIBLargeIntField * get_TableDiscountAutoIDSKLAD_SDISCOUNT_AUTO(void);
   virtual void set_TableDiscountAutoIDSKLAD_SDISCOUNT_AUTO(TFIBLargeIntField * TableDiscountAutoIDSKLAD_SDISCOUNT_AUTO);

   virtual TFIBLargeIntField * get_TableDiscountAutoIDBASE_SDISCOUNT_AUTO(void);
   virtual void set_TableDiscountAutoIDBASE_SDISCOUNT_AUTO(TFIBLargeIntField * TableDiscountAutoIDBASE_SDISCOUNT_AUTO);

   virtual TFIBSmallIntField * get_TableDiscountAutoNUM_SKIDKI_SDISCOUNT_AUTO(void);
   virtual void set_TableDiscountAutoNUM_SKIDKI_SDISCOUNT_AUTO(TFIBSmallIntField * TableDiscountAutoNUM_SKIDKI_SDISCOUNT_AUTO);

   virtual TFIBLargeIntField * get_TableDiscountAutoIDGRPNOM_SDISCOUNT_AUTO(void);
   virtual void set_TableDiscountAutoIDGRPNOM_SDISCOUNT_AUTO(TFIBLargeIntField * TableDiscountAutoIDGRPNOM_SDISCOUNT_AUTO);

   virtual TFIBIntegerField * get_TableDiscountAutoTYPE_ACTION_SDISCOUNT_AUTO(void);
   virtual void set_TableDiscountAutoTYPE_ACTION_SDISCOUNT_AUTO(TFIBIntegerField * TableDiscountAutoTYPE_ACTION_SDISCOUNT_AUTO);

   virtual TFIBWideStringField * get_TableDiscountAutoMESSAGE_SDISCOUNT_AUTO(void);
   virtual void set_TableDiscountAutoMESSAGE_SDISCOUNT_AUTO(TFIBWideStringField * TableDiscountAutoMESSAGE_SDISCOUNT_AUTO);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 Id);
   virtual void NewElement(void);
   virtual bool SaveElement(void);
   virtual void CloseElement(void);
   virtual void DeleteElement(__int64 Id);
   virtual __int64 GetIDElement(UnicodeString gid);
   virtual AnsiString GetGIDElement(__int64 id);
   virtual int GetIndexElementaPoID(__int64 id);
   virtual void OpenTableDiscountAuto(__int64 id_sklad);
};
#define CLSID_TDMSprDiscountAutoImpl __uuidof(TDMSprDiscountAutoImpl)
#endif
