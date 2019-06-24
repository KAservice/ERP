#ifndef UIDMSprDiscountCard_1H
#define UIDMSprDiscountCard_1H
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprDiscountCard_1)) IDMSprDiscountCard_1 : public IMainInterface
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

   __property TFIBIntegerField * TableCODE_SDISCOUNT_CARD = {read = get_TableCODE_SDISCOUNT_CARD , write = set_TableCODE_SDISCOUNT_CARD};
   virtual TFIBIntegerField * get_TableCODE_SDISCOUNT_CARD(void)=0;
   virtual void set_TableCODE_SDISCOUNT_CARD(TFIBIntegerField * TableCODE_SDISCOUNT_CARD)=0;

   __property TFIBIntegerField * TableTYPE_SDISCOUNT_CARD = {read = get_TableTYPE_SDISCOUNT_CARD , write = set_TableTYPE_SDISCOUNT_CARD};
   virtual TFIBIntegerField * get_TableTYPE_SDISCOUNT_CARD(void)=0;
   virtual void set_TableTYPE_SDISCOUNT_CARD(TFIBIntegerField * TableTYPE_SDISCOUNT_CARD)=0;

   __property TFIBDateTimeField * TableNACH_SDISCOUNT_CARD = {read = get_TableNACH_SDISCOUNT_CARD , write = set_TableNACH_SDISCOUNT_CARD};
   virtual TFIBDateTimeField * get_TableNACH_SDISCOUNT_CARD(void)=0;
   virtual void set_TableNACH_SDISCOUNT_CARD(TFIBDateTimeField * TableNACH_SDISCOUNT_CARD)=0;

   __property TFIBDateTimeField * TableCON_SDISCOUNT_CARD = {read = get_TableCON_SDISCOUNT_CARD , write = set_TableCON_SDISCOUNT_CARD};
   virtual TFIBDateTimeField * get_TableCON_SDISCOUNT_CARD(void)=0;
   virtual void set_TableCON_SDISCOUNT_CARD(TFIBDateTimeField * TableCON_SDISCOUNT_CARD)=0;

   __property TFIBBCDField * TablePRSK_SDISCOUNT_CARD = {read = get_TablePRSK_SDISCOUNT_CARD , write = set_TablePRSK_SDISCOUNT_CARD};
   virtual TFIBBCDField * get_TablePRSK_SDISCOUNT_CARD(void)=0;
   virtual void set_TablePRSK_SDISCOUNT_CARD(TFIBBCDField * TablePRSK_SDISCOUNT_CARD)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBIntegerField * ElementCODE_SDISCOUNT_CARD = {read = get_ElementCODE_SDISCOUNT_CARD , write = set_ElementCODE_SDISCOUNT_CARD};
   virtual TFIBIntegerField * get_ElementCODE_SDISCOUNT_CARD(void)=0;
   virtual void set_ElementCODE_SDISCOUNT_CARD(TFIBIntegerField * ElementCODE_SDISCOUNT_CARD)=0;

   __property TFIBIntegerField * ElementTYPE_SDISCOUNT_CARD = {read = get_ElementTYPE_SDISCOUNT_CARD , write = set_ElementTYPE_SDISCOUNT_CARD};
   virtual TFIBIntegerField * get_ElementTYPE_SDISCOUNT_CARD(void)=0;
   virtual void set_ElementTYPE_SDISCOUNT_CARD(TFIBIntegerField * ElementTYPE_SDISCOUNT_CARD)=0;

   __property TFIBDateTimeField * ElementNACH_SDISCOUNT_CARD = {read = get_ElementNACH_SDISCOUNT_CARD , write = set_ElementNACH_SDISCOUNT_CARD};
   virtual TFIBDateTimeField * get_ElementNACH_SDISCOUNT_CARD(void)=0;
   virtual void set_ElementNACH_SDISCOUNT_CARD(TFIBDateTimeField * ElementNACH_SDISCOUNT_CARD)=0;

   __property TFIBDateTimeField * ElementCON_SDISCOUNT_CARD = {read = get_ElementCON_SDISCOUNT_CARD , write = set_ElementCON_SDISCOUNT_CARD};
   virtual TFIBDateTimeField * get_ElementCON_SDISCOUNT_CARD(void)=0;
   virtual void set_ElementCON_SDISCOUNT_CARD(TFIBDateTimeField * ElementCON_SDISCOUNT_CARD)=0;

   __property TFIBBCDField * ElementPRSK_SDISCOUNT_CARD = {read = get_ElementPRSK_SDISCOUNT_CARD , write = set_ElementPRSK_SDISCOUNT_CARD};
   virtual TFIBBCDField * get_ElementPRSK_SDISCOUNT_CARD(void)=0;
   virtual void set_ElementPRSK_SDISCOUNT_CARD(TFIBBCDField * ElementPRSK_SDISCOUNT_CARD)=0;

   __property TFIBIntegerField * TableACT_SDISCOUNT_CARD = {read = get_TableACT_SDISCOUNT_CARD , write = set_TableACT_SDISCOUNT_CARD};
   virtual TFIBIntegerField * get_TableACT_SDISCOUNT_CARD(void)=0;
   virtual void set_TableACT_SDISCOUNT_CARD(TFIBIntegerField * TableACT_SDISCOUNT_CARD)=0;

   __property TFIBIntegerField * ElementACT_SDISCOUNT_CARD = {read = get_ElementACT_SDISCOUNT_CARD , write = set_ElementACT_SDISCOUNT_CARD};
   virtual TFIBIntegerField * get_ElementACT_SDISCOUNT_CARD(void)=0;
   virtual void set_ElementACT_SDISCOUNT_CARD(TFIBIntegerField * ElementACT_SDISCOUNT_CARD)=0;

   __property TpFIBQuery * Query = {read = get_Query , write = set_Query};
   virtual TpFIBQuery * get_Query(void)=0;
   virtual void set_Query(TpFIBQuery * Query)=0;

   __property TFIBSmallIntField * TableFL_DISC_SDISCOUNT_CARD = {read = get_TableFL_DISC_SDISCOUNT_CARD , write = set_TableFL_DISC_SDISCOUNT_CARD};
   virtual TFIBSmallIntField * get_TableFL_DISC_SDISCOUNT_CARD(void)=0;
   virtual void set_TableFL_DISC_SDISCOUNT_CARD(TFIBSmallIntField * TableFL_DISC_SDISCOUNT_CARD)=0;

   __property TFIBSmallIntField * TableFL_PLAT_SDISCOUNT_CARD = {read = get_TableFL_PLAT_SDISCOUNT_CARD , write = set_TableFL_PLAT_SDISCOUNT_CARD};
   virtual TFIBSmallIntField * get_TableFL_PLAT_SDISCOUNT_CARD(void)=0;
   virtual void set_TableFL_PLAT_SDISCOUNT_CARD(TFIBSmallIntField * TableFL_PLAT_SDISCOUNT_CARD)=0;

   __property TFIBSmallIntField * ElementFL_DISC_SDISCOUNT_CARD = {read = get_ElementFL_DISC_SDISCOUNT_CARD , write = set_ElementFL_DISC_SDISCOUNT_CARD};
   virtual TFIBSmallIntField * get_ElementFL_DISC_SDISCOUNT_CARD(void)=0;
   virtual void set_ElementFL_DISC_SDISCOUNT_CARD(TFIBSmallIntField * ElementFL_DISC_SDISCOUNT_CARD)=0;

   __property TFIBSmallIntField * ElementFL_PLAT_SDISCOUNT_CARD = {read = get_ElementFL_PLAT_SDISCOUNT_CARD , write = set_ElementFL_PLAT_SDISCOUNT_CARD};
   virtual TFIBSmallIntField * get_ElementFL_PLAT_SDISCOUNT_CARD(void)=0;
   virtual void set_ElementFL_PLAT_SDISCOUNT_CARD(TFIBSmallIntField * ElementFL_PLAT_SDISCOUNT_CARD)=0;

   __property TFIBSmallIntField * ElementFL_CREDIT_SDISCOUNT_CARD = {read = get_ElementFL_CREDIT_SDISCOUNT_CARD , write = set_ElementFL_CREDIT_SDISCOUNT_CARD};
   virtual TFIBSmallIntField * get_ElementFL_CREDIT_SDISCOUNT_CARD(void)=0;
   virtual void set_ElementFL_CREDIT_SDISCOUNT_CARD(TFIBSmallIntField * ElementFL_CREDIT_SDISCOUNT_CARD)=0;

   __property TFIBLargeIntField * TableIDBASE_SDISCOUNT_CARD = {read = get_TableIDBASE_SDISCOUNT_CARD , write = set_TableIDBASE_SDISCOUNT_CARD};
   virtual TFIBLargeIntField * get_TableIDBASE_SDISCOUNT_CARD(void)=0;
   virtual void set_TableIDBASE_SDISCOUNT_CARD(TFIBLargeIntField * TableIDBASE_SDISCOUNT_CARD)=0;

   __property TFIBSmallIntField * TableFL_CREDIT_SDISCOUNT_CARD = {read = get_TableFL_CREDIT_SDISCOUNT_CARD , write = set_TableFL_CREDIT_SDISCOUNT_CARD};
   virtual TFIBSmallIntField * get_TableFL_CREDIT_SDISCOUNT_CARD(void)=0;
   virtual void set_TableFL_CREDIT_SDISCOUNT_CARD(TFIBSmallIntField * TableFL_CREDIT_SDISCOUNT_CARD)=0;

   __property TFIBLargeIntField * TableIDDOG_SDISCOUNT_CARD = {read = get_TableIDDOG_SDISCOUNT_CARD , write = set_TableIDDOG_SDISCOUNT_CARD};
   virtual TFIBLargeIntField * get_TableIDDOG_SDISCOUNT_CARD(void)=0;
   virtual void set_TableIDDOG_SDISCOUNT_CARD(TFIBLargeIntField * TableIDDOG_SDISCOUNT_CARD)=0;

   __property TFIBLargeIntField * TableID_SDISCOUNT_CARD = {read = get_TableID_SDISCOUNT_CARD , write = set_TableID_SDISCOUNT_CARD};
   virtual TFIBLargeIntField * get_TableID_SDISCOUNT_CARD(void)=0;
   virtual void set_TableID_SDISCOUNT_CARD(TFIBLargeIntField * TableID_SDISCOUNT_CARD)=0;

   __property TFIBLargeIntField * TableIDKLIENT_SDISCOUNT_CARD = {read = get_TableIDKLIENT_SDISCOUNT_CARD , write = set_TableIDKLIENT_SDISCOUNT_CARD};
   virtual TFIBLargeIntField * get_TableIDKLIENT_SDISCOUNT_CARD(void)=0;
   virtual void set_TableIDKLIENT_SDISCOUNT_CARD(TFIBLargeIntField * TableIDKLIENT_SDISCOUNT_CARD)=0;

   __property TFIBLargeIntField * TableIDVID_SDISCOUNT_CARD = {read = get_TableIDVID_SDISCOUNT_CARD , write = set_TableIDVID_SDISCOUNT_CARD};
   virtual TFIBLargeIntField * get_TableIDVID_SDISCOUNT_CARD(void)=0;
   virtual void set_TableIDVID_SDISCOUNT_CARD(TFIBLargeIntField * TableIDVID_SDISCOUNT_CARD)=0;

   __property TFIBLargeIntField * ElementID_SDISCOUNT_CARD = {read = get_ElementID_SDISCOUNT_CARD , write = set_ElementID_SDISCOUNT_CARD};
   virtual TFIBLargeIntField * get_ElementID_SDISCOUNT_CARD(void)=0;
   virtual void set_ElementID_SDISCOUNT_CARD(TFIBLargeIntField * ElementID_SDISCOUNT_CARD)=0;

   __property TFIBLargeIntField * ElementIDKLIENT_SDISCOUNT_CARD = {read = get_ElementIDKLIENT_SDISCOUNT_CARD , write = set_ElementIDKLIENT_SDISCOUNT_CARD};
   virtual TFIBLargeIntField * get_ElementIDKLIENT_SDISCOUNT_CARD(void)=0;
   virtual void set_ElementIDKLIENT_SDISCOUNT_CARD(TFIBLargeIntField * ElementIDKLIENT_SDISCOUNT_CARD)=0;

   __property TFIBLargeIntField * ElementIDVID_SDISCOUNT_CARD = {read = get_ElementIDVID_SDISCOUNT_CARD , write = set_ElementIDVID_SDISCOUNT_CARD};
   virtual TFIBLargeIntField * get_ElementIDVID_SDISCOUNT_CARD(void)=0;
   virtual void set_ElementIDVID_SDISCOUNT_CARD(TFIBLargeIntField * ElementIDVID_SDISCOUNT_CARD)=0;

   __property TFIBLargeIntField * ElementIDBASE_SDISCOUNT_CARD = {read = get_ElementIDBASE_SDISCOUNT_CARD , write = set_ElementIDBASE_SDISCOUNT_CARD};
   virtual TFIBLargeIntField * get_ElementIDBASE_SDISCOUNT_CARD(void)=0;
   virtual void set_ElementIDBASE_SDISCOUNT_CARD(TFIBLargeIntField * ElementIDBASE_SDISCOUNT_CARD)=0;

   __property TFIBLargeIntField * ElementIDDOG_SDISCOUNT_CARD = {read = get_ElementIDDOG_SDISCOUNT_CARD , write = set_ElementIDDOG_SDISCOUNT_CARD};
   virtual TFIBLargeIntField * get_ElementIDDOG_SDISCOUNT_CARD(void)=0;
   virtual void set_ElementIDDOG_SDISCOUNT_CARD(TFIBLargeIntField * ElementIDDOG_SDISCOUNT_CARD)=0;

   __property TFIBWideStringField * TableNAME_SDISCOUNT_CARD = {read = get_TableNAME_SDISCOUNT_CARD , write = set_TableNAME_SDISCOUNT_CARD};
   virtual TFIBWideStringField * get_TableNAME_SDISCOUNT_CARD(void)=0;
   virtual void set_TableNAME_SDISCOUNT_CARD(TFIBWideStringField * TableNAME_SDISCOUNT_CARD)=0;

   __property TFIBWideStringField * TableNAME_SVID_DCARD = {read = get_TableNAME_SVID_DCARD , write = set_TableNAME_SVID_DCARD};
   virtual TFIBWideStringField * get_TableNAME_SVID_DCARD(void)=0;
   virtual void set_TableNAME_SVID_DCARD(TFIBWideStringField * TableNAME_SVID_DCARD)=0;

   __property TFIBWideStringField * TableNAMEKLIENT = {read = get_TableNAMEKLIENT , write = set_TableNAMEKLIENT};
   virtual TFIBWideStringField * get_TableNAMEKLIENT(void)=0;
   virtual void set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)=0;

   __property TFIBWideStringField * ElementGID_SDISCOUNT_CARD = {read = get_ElementGID_SDISCOUNT_CARD , write = set_ElementGID_SDISCOUNT_CARD};
   virtual TFIBWideStringField * get_ElementGID_SDISCOUNT_CARD(void)=0;
   virtual void set_ElementGID_SDISCOUNT_CARD(TFIBWideStringField * ElementGID_SDISCOUNT_CARD)=0;

   __property TFIBWideStringField * ElementNAME_SDISCOUNT_CARD = {read = get_ElementNAME_SDISCOUNT_CARD , write = set_ElementNAME_SDISCOUNT_CARD};
   virtual TFIBWideStringField * get_ElementNAME_SDISCOUNT_CARD(void)=0;
   virtual void set_ElementNAME_SDISCOUNT_CARD(TFIBWideStringField * ElementNAME_SDISCOUNT_CARD)=0;

   __property TFIBWideStringField * ElementSHCODE_SDISCOUNT_CARD = {read = get_ElementSHCODE_SDISCOUNT_CARD , write = set_ElementSHCODE_SDISCOUNT_CARD};
   virtual TFIBWideStringField * get_ElementSHCODE_SDISCOUNT_CARD(void)=0;
   virtual void set_ElementSHCODE_SDISCOUNT_CARD(TFIBWideStringField * ElementSHCODE_SDISCOUNT_CARD)=0;

   __property TFIBWideStringField * ElementNAMEKLIENT = {read = get_ElementNAMEKLIENT , write = set_ElementNAMEKLIENT};
   virtual TFIBWideStringField * get_ElementNAMEKLIENT(void)=0;
   virtual void set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT)=0;

   __property TFIBWideStringField * ElementNAME_SVID_DCARD = {read = get_ElementNAME_SVID_DCARD , write = set_ElementNAME_SVID_DCARD};
   virtual TFIBWideStringField * get_ElementNAME_SVID_DCARD(void)=0;
   virtual void set_ElementNAME_SVID_DCARD(TFIBWideStringField * ElementNAME_SVID_DCARD)=0;

   __property TFIBWideStringField * ElementNAME_SDOG = {read = get_ElementNAME_SDOG , write = set_ElementNAME_SDOG};
   virtual TFIBWideStringField * get_ElementNAME_SDOG(void)=0;
   virtual void set_ElementNAME_SDOG(TFIBWideStringField * ElementNAME_SDOG)=0;

   __property TFIBWideStringField * TableSHCODE_SDISCOUNT_CARD = {read = get_TableSHCODE_SDISCOUNT_CARD , write = set_TableSHCODE_SDISCOUNT_CARD};
   virtual TFIBWideStringField * get_TableSHCODE_SDISCOUNT_CARD(void)=0;
   virtual void set_TableSHCODE_SDISCOUNT_CARD(TFIBWideStringField * TableSHCODE_SDISCOUNT_CARD)=0;

   __property TFIBWideStringField * TableGID_SDISCOUNT_CARD = {read = get_TableGID_SDISCOUNT_CARD , write = set_TableGID_SDISCOUNT_CARD};
   virtual TFIBWideStringField * get_TableGID_SDISCOUNT_CARD(void)=0;
   virtual void set_TableGID_SDISCOUNT_CARD(TFIBWideStringField * TableGID_SDISCOUNT_CARD)=0;

   __property TFIBSmallIntField * TableSINGLE_SDISCOUNT_CARD = {read = get_TableSINGLE_SDISCOUNT_CARD , write = set_TableSINGLE_SDISCOUNT_CARD};
   virtual TFIBSmallIntField * get_TableSINGLE_SDISCOUNT_CARD(void)=0;
   virtual void set_TableSINGLE_SDISCOUNT_CARD(TFIBSmallIntField * TableSINGLE_SDISCOUNT_CARD)=0;

   __property TFIBSmallIntField * ElementSINGLE_SDISCOUNT_CARD = {read = get_ElementSINGLE_SDISCOUNT_CARD , write = set_ElementSINGLE_SDISCOUNT_CARD};
   virtual TFIBSmallIntField * get_ElementSINGLE_SDISCOUNT_CARD(void)=0;
   virtual void set_ElementSINGLE_SDISCOUNT_CARD(TFIBSmallIntField * ElementSINGLE_SDISCOUNT_CARD)=0;

   __property __int64 IdKlient = {read = get_IdKlient , write = set_IdKlient};
   virtual __int64 get_IdKlient(void)=0;
   virtual void set_IdKlient(__int64 IdKlient)=0;

   __property bool elSave = {read = get_elSave , write = set_elSave};
   virtual bool get_elSave(void)=0;
   virtual void set_elSave(bool elSave)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   virtual void OpenTable(__int64 id_grp, bool all)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual bool NewElement(__int64 id_klient)=0;
   virtual bool SaveElement(void)=0;
   virtual void DeleteElement(__int64 id)=0;
   virtual __int64 GetIdGrpKlient(__int64 id_discount_card)=0;
   virtual __int64 PoiskPoCodu(AnsiString code)=0;
   virtual __int64 PoiskPoShCodu(AnsiString sh_code)=0;
   virtual int GetCodeCard(void)=0;
   virtual bool CheckBarCode(__int64 id_card, AnsiString sh)=0;
   virtual bool CheckCode(__int64 id_card, int code)=0;
};
#define IID_IDMSprDiscountCard_1 __uuidof(IDMSprDiscountCard_1)
#endif
