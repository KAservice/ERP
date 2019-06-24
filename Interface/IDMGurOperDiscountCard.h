#ifndef UIDMGurOperDiscountCardH
#define UIDMGurOperDiscountCardH
#include "IMainInterface.h"
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>
class __declspec(uuid("{7E065634-B8D3-4C21-AACD-61C7A66A62B7}")) IDMGurOperDiscountCard : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TDataSource * DataSourceElement = {read = get_DataSourceElement , write = set_DataSourceElement};
   virtual TDataSource * get_DataSourceElement(void)=0;
   virtual void set_DataSourceElement(TDataSource * DataSourceElement)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBBCDField * TableSUM_GUROPER_DCARD = {read = get_TableSUM_GUROPER_DCARD , write = set_TableSUM_GUROPER_DCARD};
   virtual TFIBBCDField * get_TableSUM_GUROPER_DCARD(void)=0;
   virtual void set_TableSUM_GUROPER_DCARD(TFIBBCDField * TableSUM_GUROPER_DCARD)=0;

   __property TFIBDateTimeField * TablePOS_GUROPER_DCARD = {read = get_TablePOS_GUROPER_DCARD , write = set_TablePOS_GUROPER_DCARD};
   virtual TFIBDateTimeField * get_TablePOS_GUROPER_DCARD(void)=0;
   virtual void set_TablePOS_GUROPER_DCARD(TFIBDateTimeField * TablePOS_GUROPER_DCARD)=0;

   __property TFIBBCDField * ElementSUM_GUROPER_DCARD = {read = get_ElementSUM_GUROPER_DCARD , write = set_ElementSUM_GUROPER_DCARD};
   virtual TFIBBCDField * get_ElementSUM_GUROPER_DCARD(void)=0;
   virtual void set_ElementSUM_GUROPER_DCARD(TFIBBCDField * ElementSUM_GUROPER_DCARD)=0;

   __property TFIBDateTimeField * ElementPOS_GUROPER_DCARD = {read = get_ElementPOS_GUROPER_DCARD , write = set_ElementPOS_GUROPER_DCARD};
   virtual TFIBDateTimeField * get_ElementPOS_GUROPER_DCARD(void)=0;
   virtual void set_ElementPOS_GUROPER_DCARD(TFIBDateTimeField * ElementPOS_GUROPER_DCARD)=0;

   __property TpFIBQuery * Query = {read = get_Query , write = set_Query};
   virtual TpFIBQuery * get_Query(void)=0;
   virtual void set_Query(TpFIBQuery * Query)=0;

   __property TFIBBCDField * ElementID_GUROPER_DCARD = {read = get_ElementID_GUROPER_DCARD , write = set_ElementID_GUROPER_DCARD};
   virtual TFIBBCDField * get_ElementID_GUROPER_DCARD(void)=0;
   virtual void set_ElementID_GUROPER_DCARD(TFIBBCDField * ElementID_GUROPER_DCARD)=0;

   __property TFIBBCDField * ElementIDKLIENT_GUROPER_DCARD = {read = get_ElementIDKLIENT_GUROPER_DCARD , write = set_ElementIDKLIENT_GUROPER_DCARD};
   virtual TFIBBCDField * get_ElementIDKLIENT_GUROPER_DCARD(void)=0;
   virtual void set_ElementIDKLIENT_GUROPER_DCARD(TFIBBCDField * ElementIDKLIENT_GUROPER_DCARD)=0;

   __property TFIBBCDField * ElementIDSKLAD_GUROPER_DCARD = {read = get_ElementIDSKLAD_GUROPER_DCARD , write = set_ElementIDSKLAD_GUROPER_DCARD};
   virtual TFIBBCDField * get_ElementIDSKLAD_GUROPER_DCARD(void)=0;
   virtual void set_ElementIDSKLAD_GUROPER_DCARD(TFIBBCDField * ElementIDSKLAD_GUROPER_DCARD)=0;

   __property TFIBBCDField * ElementIDCARD_GUROPER_DCARD = {read = get_ElementIDCARD_GUROPER_DCARD , write = set_ElementIDCARD_GUROPER_DCARD};
   virtual TFIBBCDField * get_ElementIDCARD_GUROPER_DCARD(void)=0;
   virtual void set_ElementIDCARD_GUROPER_DCARD(TFIBBCDField * ElementIDCARD_GUROPER_DCARD)=0;

   __property TFIBBCDField * ElementIDDOC_GUROPER_DCARD = {read = get_ElementIDDOC_GUROPER_DCARD , write = set_ElementIDDOC_GUROPER_DCARD};
   virtual TFIBBCDField * get_ElementIDDOC_GUROPER_DCARD(void)=0;
   virtual void set_ElementIDDOC_GUROPER_DCARD(TFIBBCDField * ElementIDDOC_GUROPER_DCARD)=0;

   __property TFIBBCDField * TableID_GUROPER_DCARD = {read = get_TableID_GUROPER_DCARD , write = set_TableID_GUROPER_DCARD};
   virtual TFIBBCDField * get_TableID_GUROPER_DCARD(void)=0;
   virtual void set_TableID_GUROPER_DCARD(TFIBBCDField * TableID_GUROPER_DCARD)=0;

   __property TFIBBCDField * TableIDKLIENT_GUROPER_DCARD = {read = get_TableIDKLIENT_GUROPER_DCARD , write = set_TableIDKLIENT_GUROPER_DCARD};
   virtual TFIBBCDField * get_TableIDKLIENT_GUROPER_DCARD(void)=0;
   virtual void set_TableIDKLIENT_GUROPER_DCARD(TFIBBCDField * TableIDKLIENT_GUROPER_DCARD)=0;

   __property TFIBBCDField * TableIDSKLAD_GUROPER_DCARD = {read = get_TableIDSKLAD_GUROPER_DCARD , write = set_TableIDSKLAD_GUROPER_DCARD};
   virtual TFIBBCDField * get_TableIDSKLAD_GUROPER_DCARD(void)=0;
   virtual void set_TableIDSKLAD_GUROPER_DCARD(TFIBBCDField * TableIDSKLAD_GUROPER_DCARD)=0;

   __property TFIBBCDField * TableIDCARD_GUROPER_DCARD = {read = get_TableIDCARD_GUROPER_DCARD , write = set_TableIDCARD_GUROPER_DCARD};
   virtual TFIBBCDField * get_TableIDCARD_GUROPER_DCARD(void)=0;
   virtual void set_TableIDCARD_GUROPER_DCARD(TFIBBCDField * TableIDCARD_GUROPER_DCARD)=0;

   __property TFIBBCDField * TableIDDOC_GUROPER_DCARD = {read = get_TableIDDOC_GUROPER_DCARD , write = set_TableIDDOC_GUROPER_DCARD};
   virtual TFIBBCDField * get_TableIDDOC_GUROPER_DCARD(void)=0;
   virtual void set_TableIDDOC_GUROPER_DCARD(TFIBBCDField * TableIDDOC_GUROPER_DCARD)=0;

   __property TFIBWideStringField * TableNAMEKLIENT = {read = get_TableNAMEKLIENT , write = set_TableNAMEKLIENT};
   virtual TFIBWideStringField * get_TableNAMEKLIENT(void)=0;
   virtual void set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)=0;

   __property TFIBWideStringField * TableNAMESKLAD = {read = get_TableNAMESKLAD , write = set_TableNAMESKLAD};
   virtual TFIBWideStringField * get_TableNAMESKLAD(void)=0;
   virtual void set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)=0;

   __property TFIBWideStringField * TableNAME_SDISCOUNT_CARD = {read = get_TableNAME_SDISCOUNT_CARD , write = set_TableNAME_SDISCOUNT_CARD};
   virtual TFIBWideStringField * get_TableNAME_SDISCOUNT_CARD(void)=0;
   virtual void set_TableNAME_SDISCOUNT_CARD(TFIBWideStringField * TableNAME_SDISCOUNT_CARD)=0;

   __property TFIBWideStringField * ElementGID_GUROPER_DCARD = {read = get_ElementGID_GUROPER_DCARD , write = set_ElementGID_GUROPER_DCARD};
   virtual TFIBWideStringField * get_ElementGID_GUROPER_DCARD(void)=0;
   virtual void set_ElementGID_GUROPER_DCARD(TFIBWideStringField * ElementGID_GUROPER_DCARD)=0;

   __property TFIBWideStringField * ElementNAMEKLIENT = {read = get_ElementNAMEKLIENT , write = set_ElementNAMEKLIENT};
   virtual TFIBWideStringField * get_ElementNAMEKLIENT(void)=0;
   virtual void set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT)=0;

   __property TFIBWideStringField * ElementNAMESKLAD = {read = get_ElementNAMESKLAD , write = set_ElementNAMESKLAD};
   virtual TFIBWideStringField * get_ElementNAMESKLAD(void)=0;
   virtual void set_ElementNAMESKLAD(TFIBWideStringField * ElementNAMESKLAD)=0;

   __property TFIBWideStringField * ElementNAME_SDISCOUNT_CARD = {read = get_ElementNAME_SDISCOUNT_CARD , write = set_ElementNAME_SDISCOUNT_CARD};
   virtual TFIBWideStringField * get_ElementNAME_SDISCOUNT_CARD(void)=0;
   virtual void set_ElementNAME_SDISCOUNT_CARD(TFIBWideStringField * ElementNAME_SDISCOUNT_CARD)=0;

   __property bool elSave = {read = get_elSave , write = set_elSave};
   virtual bool get_elSave(void)=0;
   virtual void set_elSave(bool elSave)=0;

   __property TDateTime PosNach = {read = get_PosNach , write = set_PosNach};
   virtual TDateTime get_PosNach(void)=0;
   virtual void set_PosNach(TDateTime PosNach)=0;

   __property TDateTime PosCon = {read = get_PosCon , write = set_PosCon};
   virtual TDateTime get_PosCon(void)=0;
   virtual void set_PosCon(TDateTime PosCon)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual void NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void DeleteElement(__int64 id)=0;
   virtual double GetSumPokupok(__int64 id_klient, TDateTime pos_nach)=0;
   virtual __int64 PoiskPoCoduDoc(__int64 code_doc)=0;
};
#define IID_IDMGurOperDiscountCard __uuidof(IDMGurOperDiscountCard)
#endif
