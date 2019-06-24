#ifndef UIDMXSetupObmenH
#define UIDMXSetupObmenH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{4BB2F291-2DD2-43E6-996D-0EDF8DA8EBDF}")) IDMXSetupObmen : public IMainInterface
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

   __property TFIBBCDField * TableID_XSETUP_OBMEN = {read = get_TableID_XSETUP_OBMEN , write = set_TableID_XSETUP_OBMEN};
   virtual TFIBBCDField * get_TableID_XSETUP_OBMEN(void)=0;
   virtual void set_TableID_XSETUP_OBMEN(TFIBBCDField * TableID_XSETUP_OBMEN)=0;

   __property TFIBBCDField * TableIDBASE_OBMEN_XSETUP_OBMEN = {read = get_TableIDBASE_OBMEN_XSETUP_OBMEN , write = set_TableIDBASE_OBMEN_XSETUP_OBMEN};
   virtual TFIBBCDField * get_TableIDBASE_OBMEN_XSETUP_OBMEN(void)=0;
   virtual void set_TableIDBASE_OBMEN_XSETUP_OBMEN(TFIBBCDField * TableIDBASE_OBMEN_XSETUP_OBMEN)=0;

   __property TFIBBCDField * TableIDTISM_XSETUP_OBMEN = {read = get_TableIDTISM_XSETUP_OBMEN , write = set_TableIDTISM_XSETUP_OBMEN};
   virtual TFIBBCDField * get_TableIDTISM_XSETUP_OBMEN(void)=0;
   virtual void set_TableIDTISM_XSETUP_OBMEN(TFIBBCDField * TableIDTISM_XSETUP_OBMEN)=0;

   __property TFIBSmallIntField * TableALLDOC_XSETUP_OBMEN = {read = get_TableALLDOC_XSETUP_OBMEN , write = set_TableALLDOC_XSETUP_OBMEN};
   virtual TFIBSmallIntField * get_TableALLDOC_XSETUP_OBMEN(void)=0;
   virtual void set_TableALLDOC_XSETUP_OBMEN(TFIBSmallIntField * TableALLDOC_XSETUP_OBMEN)=0;

   __property TFIBSmallIntField * TableOUTNAC_XSETUP_OBMEN = {read = get_TableOUTNAC_XSETUP_OBMEN , write = set_TableOUTNAC_XSETUP_OBMEN};
   virtual TFIBSmallIntField * get_TableOUTNAC_XSETUP_OBMEN(void)=0;
   virtual void set_TableOUTNAC_XSETUP_OBMEN(TFIBSmallIntField * TableOUTNAC_XSETUP_OBMEN)=0;

   __property TFIBSmallIntField * TableOUTZPRICE_XSETUP_OBMEN = {read = get_TableOUTZPRICE_XSETUP_OBMEN , write = set_TableOUTZPRICE_XSETUP_OBMEN};
   virtual TFIBSmallIntField * get_TableOUTZPRICE_XSETUP_OBMEN(void)=0;
   virtual void set_TableOUTZPRICE_XSETUP_OBMEN(TFIBSmallIntField * TableOUTZPRICE_XSETUP_OBMEN)=0;

   __property TFIBSmallIntField * TableNOEDIT_XSETUP_OBMEN = {read = get_TableNOEDIT_XSETUP_OBMEN , write = set_TableNOEDIT_XSETUP_OBMEN};
   virtual TFIBSmallIntField * get_TableNOEDIT_XSETUP_OBMEN(void)=0;
   virtual void set_TableNOEDIT_XSETUP_OBMEN(TFIBSmallIntField * TableNOEDIT_XSETUP_OBMEN)=0;

   __property TFIBBCDField * TableIDBASE_XSETUP_OBMEN = {read = get_TableIDBASE_XSETUP_OBMEN , write = set_TableIDBASE_XSETUP_OBMEN};
   virtual TFIBBCDField * get_TableIDBASE_XSETUP_OBMEN(void)=0;
   virtual void set_TableIDBASE_XSETUP_OBMEN(TFIBBCDField * TableIDBASE_XSETUP_OBMEN)=0;

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TFIBBCDField * ElementID_XSETUP_OBMEN = {read = get_ElementID_XSETUP_OBMEN , write = set_ElementID_XSETUP_OBMEN};
   virtual TFIBBCDField * get_ElementID_XSETUP_OBMEN(void)=0;
   virtual void set_ElementID_XSETUP_OBMEN(TFIBBCDField * ElementID_XSETUP_OBMEN)=0;

   __property TFIBBCDField * ElementIDBASE_OBMEN_XSETUP_OBMEN = {read = get_ElementIDBASE_OBMEN_XSETUP_OBMEN , write = set_ElementIDBASE_OBMEN_XSETUP_OBMEN};
   virtual TFIBBCDField * get_ElementIDBASE_OBMEN_XSETUP_OBMEN(void)=0;
   virtual void set_ElementIDBASE_OBMEN_XSETUP_OBMEN(TFIBBCDField * ElementIDBASE_OBMEN_XSETUP_OBMEN)=0;

   __property TFIBBCDField * ElementIDTISM_XSETUP_OBMEN = {read = get_ElementIDTISM_XSETUP_OBMEN , write = set_ElementIDTISM_XSETUP_OBMEN};
   virtual TFIBBCDField * get_ElementIDTISM_XSETUP_OBMEN(void)=0;
   virtual void set_ElementIDTISM_XSETUP_OBMEN(TFIBBCDField * ElementIDTISM_XSETUP_OBMEN)=0;

   __property TFIBSmallIntField * ElementALLDOC_XSETUP_OBMEN = {read = get_ElementALLDOC_XSETUP_OBMEN , write = set_ElementALLDOC_XSETUP_OBMEN};
   virtual TFIBSmallIntField * get_ElementALLDOC_XSETUP_OBMEN(void)=0;
   virtual void set_ElementALLDOC_XSETUP_OBMEN(TFIBSmallIntField * ElementALLDOC_XSETUP_OBMEN)=0;

   __property TFIBSmallIntField * ElementOUTNAC_XSETUP_OBMEN = {read = get_ElementOUTNAC_XSETUP_OBMEN , write = set_ElementOUTNAC_XSETUP_OBMEN};
   virtual TFIBSmallIntField * get_ElementOUTNAC_XSETUP_OBMEN(void)=0;
   virtual void set_ElementOUTNAC_XSETUP_OBMEN(TFIBSmallIntField * ElementOUTNAC_XSETUP_OBMEN)=0;

   __property TFIBSmallIntField * ElementOUTZPRICE_XSETUP_OBMEN = {read = get_ElementOUTZPRICE_XSETUP_OBMEN , write = set_ElementOUTZPRICE_XSETUP_OBMEN};
   virtual TFIBSmallIntField * get_ElementOUTZPRICE_XSETUP_OBMEN(void)=0;
   virtual void set_ElementOUTZPRICE_XSETUP_OBMEN(TFIBSmallIntField * ElementOUTZPRICE_XSETUP_OBMEN)=0;

   __property TFIBSmallIntField * ElementNOEDIT_XSETUP_OBMEN = {read = get_ElementNOEDIT_XSETUP_OBMEN , write = set_ElementNOEDIT_XSETUP_OBMEN};
   virtual TFIBSmallIntField * get_ElementNOEDIT_XSETUP_OBMEN(void)=0;
   virtual void set_ElementNOEDIT_XSETUP_OBMEN(TFIBSmallIntField * ElementNOEDIT_XSETUP_OBMEN)=0;

   __property TFIBBCDField * ElementIDBASE_XSETUP_OBMEN = {read = get_ElementIDBASE_XSETUP_OBMEN , write = set_ElementIDBASE_XSETUP_OBMEN};
   virtual TFIBBCDField * get_ElementIDBASE_XSETUP_OBMEN(void)=0;
   virtual void set_ElementIDBASE_XSETUP_OBMEN(TFIBBCDField * ElementIDBASE_XSETUP_OBMEN)=0;

   __property TDataSource * DataSourceElement = {read = get_DataSourceElement , write = set_DataSourceElement};
   virtual TDataSource * get_DataSourceElement(void)=0;
   virtual void set_DataSourceElement(TDataSource * DataSourceElement)=0;

   __property TpFIBDataSet * BaseForObmen = {read = get_BaseForObmen , write = set_BaseForObmen};
   virtual TpFIBDataSet * get_BaseForObmen(void)=0;
   virtual void set_BaseForObmen(TpFIBDataSet * BaseForObmen)=0;

   __property TpFIBDataSet * TypePriceForObmen = {read = get_TypePriceForObmen , write = set_TypePriceForObmen};
   virtual TpFIBDataSet * get_TypePriceForObmen(void)=0;
   virtual void set_TypePriceForObmen(TpFIBDataSet * TypePriceForObmen)=0;

   __property TDataSource * DataSourceBaseForObmen = {read = get_DataSourceBaseForObmen , write = set_DataSourceBaseForObmen};
   virtual TDataSource * get_DataSourceBaseForObmen(void)=0;
   virtual void set_DataSourceBaseForObmen(TDataSource * DataSourceBaseForObmen)=0;

   __property TDataSource * DataSourceTypePriceForObmen = {read = get_DataSourceTypePriceForObmen , write = set_DataSourceTypePriceForObmen};
   virtual TDataSource * get_DataSourceTypePriceForObmen(void)=0;
   virtual void set_DataSourceTypePriceForObmen(TDataSource * DataSourceTypePriceForObmen)=0;

   __property TFIBBCDField * BaseForObmenID_XBASE_FOR_OBMEN = {read = get_BaseForObmenID_XBASE_FOR_OBMEN , write = set_BaseForObmenID_XBASE_FOR_OBMEN};
   virtual TFIBBCDField * get_BaseForObmenID_XBASE_FOR_OBMEN(void)=0;
   virtual void set_BaseForObmenID_XBASE_FOR_OBMEN(TFIBBCDField * BaseForObmenID_XBASE_FOR_OBMEN)=0;

   __property TFIBBCDField * BaseForObmenIDBASE_OBMEN_XBASE_FOR_OBMEN = {read = get_BaseForObmenIDBASE_OBMEN_XBASE_FOR_OBMEN , write = set_BaseForObmenIDBASE_OBMEN_XBASE_FOR_OBMEN};
   virtual TFIBBCDField * get_BaseForObmenIDBASE_OBMEN_XBASE_FOR_OBMEN(void)=0;
   virtual void set_BaseForObmenIDBASE_OBMEN_XBASE_FOR_OBMEN(TFIBBCDField * BaseForObmenIDBASE_OBMEN_XBASE_FOR_OBMEN)=0;

   __property TFIBBCDField * BaseForObmenIDBASE_OBJECT_XBASE_FOR_OBMEN = {read = get_BaseForObmenIDBASE_OBJECT_XBASE_FOR_OBMEN , write = set_BaseForObmenIDBASE_OBJECT_XBASE_FOR_OBMEN};
   virtual TFIBBCDField * get_BaseForObmenIDBASE_OBJECT_XBASE_FOR_OBMEN(void)=0;
   virtual void set_BaseForObmenIDBASE_OBJECT_XBASE_FOR_OBMEN(TFIBBCDField * BaseForObmenIDBASE_OBJECT_XBASE_FOR_OBMEN)=0;

   __property TFIBBCDField * BaseForObmenIDBASE_XBASE_FOR_OBMEN = {read = get_BaseForObmenIDBASE_XBASE_FOR_OBMEN , write = set_BaseForObmenIDBASE_XBASE_FOR_OBMEN};
   virtual TFIBBCDField * get_BaseForObmenIDBASE_XBASE_FOR_OBMEN(void)=0;
   virtual void set_BaseForObmenIDBASE_XBASE_FOR_OBMEN(TFIBBCDField * BaseForObmenIDBASE_XBASE_FOR_OBMEN)=0;

   __property TFIBBCDField * TypePriceForObmenID_XTPRICE_FOR_OBMEN = {read = get_TypePriceForObmenID_XTPRICE_FOR_OBMEN , write = set_TypePriceForObmenID_XTPRICE_FOR_OBMEN};
   virtual TFIBBCDField * get_TypePriceForObmenID_XTPRICE_FOR_OBMEN(void)=0;
   virtual void set_TypePriceForObmenID_XTPRICE_FOR_OBMEN(TFIBBCDField * TypePriceForObmenID_XTPRICE_FOR_OBMEN)=0;

   __property TFIBBCDField * TypePriceForObmenIDBASE_OBMEN_XTPRICE_FOR_OBMEN = {read = get_TypePriceForObmenIDBASE_OBMEN_XTPRICE_FOR_OBMEN , write = set_TypePriceForObmenIDBASE_OBMEN_XTPRICE_FOR_OBMEN};
   virtual TFIBBCDField * get_TypePriceForObmenIDBASE_OBMEN_XTPRICE_FOR_OBMEN(void)=0;
   virtual void set_TypePriceForObmenIDBASE_OBMEN_XTPRICE_FOR_OBMEN(TFIBBCDField * TypePriceForObmenIDBASE_OBMEN_XTPRICE_FOR_OBMEN)=0;

   __property TFIBBCDField * TypePriceForObmenIDTPRICE_XTPRICE_FOR_OBMEN = {read = get_TypePriceForObmenIDTPRICE_XTPRICE_FOR_OBMEN , write = set_TypePriceForObmenIDTPRICE_XTPRICE_FOR_OBMEN};
   virtual TFIBBCDField * get_TypePriceForObmenIDTPRICE_XTPRICE_FOR_OBMEN(void)=0;
   virtual void set_TypePriceForObmenIDTPRICE_XTPRICE_FOR_OBMEN(TFIBBCDField * TypePriceForObmenIDTPRICE_XTPRICE_FOR_OBMEN)=0;

   __property TFIBBCDField * TypePriceForObmenIDBASE_XTPRICE_FOR_OBMEN = {read = get_TypePriceForObmenIDBASE_XTPRICE_FOR_OBMEN , write = set_TypePriceForObmenIDBASE_XTPRICE_FOR_OBMEN};
   virtual TFIBBCDField * get_TypePriceForObmenIDBASE_XTPRICE_FOR_OBMEN(void)=0;
   virtual void set_TypePriceForObmenIDBASE_XTPRICE_FOR_OBMEN(TFIBBCDField * TypePriceForObmenIDBASE_XTPRICE_FOR_OBMEN)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBBCDField * ElementIDFIRST_DO_XSETUP_OBMEN = {read = get_ElementIDFIRST_DO_XSETUP_OBMEN , write = set_ElementIDFIRST_DO_XSETUP_OBMEN};
   virtual TFIBBCDField * get_ElementIDFIRST_DO_XSETUP_OBMEN(void)=0;
   virtual void set_ElementIDFIRST_DO_XSETUP_OBMEN(TFIBBCDField * ElementIDFIRST_DO_XSETUP_OBMEN)=0;

   __property TFIBIntegerField * ElementOPER_XSETUP_OBMEN = {read = get_ElementOPER_XSETUP_OBMEN , write = set_ElementOPER_XSETUP_OBMEN};
   virtual TFIBIntegerField * get_ElementOPER_XSETUP_OBMEN(void)=0;
   virtual void set_ElementOPER_XSETUP_OBMEN(TFIBIntegerField * ElementOPER_XSETUP_OBMEN)=0;

   __property TFIBWideStringField * TableNAME_SINFBASE_OBMEN = {read = get_TableNAME_SINFBASE_OBMEN , write = set_TableNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_TableNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_TableNAME_SINFBASE_OBMEN(TFIBWideStringField * TableNAME_SINFBASE_OBMEN)=0;

   __property TFIBWideStringField * ElementNAME_SINFBASE_OBMEN = {read = get_ElementNAME_SINFBASE_OBMEN , write = set_ElementNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_ElementNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_ElementNAME_SINFBASE_OBMEN(TFIBWideStringField * ElementNAME_SINFBASE_OBMEN)=0;

   __property TFIBWideStringField * BaseForObmenNAME_SINFBASE_OBMEN = {read = get_BaseForObmenNAME_SINFBASE_OBMEN , write = set_BaseForObmenNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_BaseForObmenNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_BaseForObmenNAME_SINFBASE_OBMEN(TFIBWideStringField * BaseForObmenNAME_SINFBASE_OBMEN)=0;

   __property TFIBWideStringField * TypePriceForObmenNAME_TPRICE = {read = get_TypePriceForObmenNAME_TPRICE , write = set_TypePriceForObmenNAME_TPRICE};
   virtual TFIBWideStringField * get_TypePriceForObmenNAME_TPRICE(void)=0;
   virtual void set_TypePriceForObmenNAME_TPRICE(TFIBWideStringField * TypePriceForObmenNAME_TPRICE)=0;

   __property __int64 IdBase = {read = get_IdBase , write = set_IdBase};
   virtual __int64 get_IdBase(void)=0;
   virtual void set_IdBase(__int64 IdBase)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   virtual void OpenTable(void)=0;
   virtual bool OpenElement(__int64 id_base)=0;
   virtual void NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id_base)=0;
   virtual bool AddBase(__int64 id_base, AnsiString name_base)=0;
   virtual bool AddTypePrice(__int64 id_type_price, AnsiString name_type_price)=0;
   virtual bool DeleteBase(void)=0;
   virtual bool DeleteTypePrice(void)=0;
};
#define IID_IDMXSetupObmen __uuidof(IDMXSetupObmen)
#endif
