#ifndef UIDMSprPropertiesNaborSostavH
#define UIDMSprPropertiesNaborSostavH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprPropertiesNaborSostav)) IDMSprPropertiesNaborSostav : public IMainInterface
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

   __property TpFIBQuery * Query = {read = get_Query , write = set_Query};
   virtual TpFIBQuery * get_Query(void)=0;
   virtual void set_Query(TpFIBQuery * Query)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBLargeIntField * TableID_SPROPNABOR_SOST = {read = get_TableID_SPROPNABOR_SOST , write = set_TableID_SPROPNABOR_SOST};
   virtual TFIBLargeIntField * get_TableID_SPROPNABOR_SOST(void)=0;
   virtual void set_TableID_SPROPNABOR_SOST(TFIBLargeIntField * TableID_SPROPNABOR_SOST)=0;

   __property TFIBLargeIntField * TableIDBASE_SPROPNABOR_SOST = {read = get_TableIDBASE_SPROPNABOR_SOST , write = set_TableIDBASE_SPROPNABOR_SOST};
   virtual TFIBLargeIntField * get_TableIDBASE_SPROPNABOR_SOST(void)=0;
   virtual void set_TableIDBASE_SPROPNABOR_SOST(TFIBLargeIntField * TableIDBASE_SPROPNABOR_SOST)=0;

   __property TFIBWideStringField * TableGID_SPROPNABOR_SOST = {read = get_TableGID_SPROPNABOR_SOST , write = set_TableGID_SPROPNABOR_SOST};
   virtual TFIBWideStringField * get_TableGID_SPROPNABOR_SOST(void)=0;
   virtual void set_TableGID_SPROPNABOR_SOST(TFIBWideStringField * TableGID_SPROPNABOR_SOST)=0;

   __property TFIBLargeIntField * TableIDPROPNABOR_SPROPNABOR_SOST = {read = get_TableIDPROPNABOR_SPROPNABOR_SOST , write = set_TableIDPROPNABOR_SPROPNABOR_SOST};
   virtual TFIBLargeIntField * get_TableIDPROPNABOR_SPROPNABOR_SOST(void)=0;
   virtual void set_TableIDPROPNABOR_SPROPNABOR_SOST(TFIBLargeIntField * TableIDPROPNABOR_SPROPNABOR_SOST)=0;

   __property TFIBLargeIntField * TableIDPROP_SPROPNABOR_SOST = {read = get_TableIDPROP_SPROPNABOR_SOST , write = set_TableIDPROP_SPROPNABOR_SOST};
   virtual TFIBLargeIntField * get_TableIDPROP_SPROPNABOR_SOST(void)=0;
   virtual void set_TableIDPROP_SPROPNABOR_SOST(TFIBLargeIntField * TableIDPROP_SPROPNABOR_SOST)=0;

   __property TFIBIntegerField * TableINDEXSORT_SPROPNABOR_SOST = {read = get_TableINDEXSORT_SPROPNABOR_SOST , write = set_TableINDEXSORT_SPROPNABOR_SOST};
   virtual TFIBIntegerField * get_TableINDEXSORT_SPROPNABOR_SOST(void)=0;
   virtual void set_TableINDEXSORT_SPROPNABOR_SOST(TFIBIntegerField * TableINDEXSORT_SPROPNABOR_SOST)=0;

   __property TFIBLargeIntField * ElementID_SPROPNABOR_SOST = {read = get_ElementID_SPROPNABOR_SOST , write = set_ElementID_SPROPNABOR_SOST};
   virtual TFIBLargeIntField * get_ElementID_SPROPNABOR_SOST(void)=0;
   virtual void set_ElementID_SPROPNABOR_SOST(TFIBLargeIntField * ElementID_SPROPNABOR_SOST)=0;

   __property TFIBLargeIntField * ElementIDBASE_SPROPNABOR_SOST = {read = get_ElementIDBASE_SPROPNABOR_SOST , write = set_ElementIDBASE_SPROPNABOR_SOST};
   virtual TFIBLargeIntField * get_ElementIDBASE_SPROPNABOR_SOST(void)=0;
   virtual void set_ElementIDBASE_SPROPNABOR_SOST(TFIBLargeIntField * ElementIDBASE_SPROPNABOR_SOST)=0;

   __property TFIBWideStringField * ElementGID_SPROPNABOR_SOST = {read = get_ElementGID_SPROPNABOR_SOST , write = set_ElementGID_SPROPNABOR_SOST};
   virtual TFIBWideStringField * get_ElementGID_SPROPNABOR_SOST(void)=0;
   virtual void set_ElementGID_SPROPNABOR_SOST(TFIBWideStringField * ElementGID_SPROPNABOR_SOST)=0;

   __property TFIBLargeIntField * ElementIDPROPNABOR_SPROPNABOR_SOST = {read = get_ElementIDPROPNABOR_SPROPNABOR_SOST , write = set_ElementIDPROPNABOR_SPROPNABOR_SOST};
   virtual TFIBLargeIntField * get_ElementIDPROPNABOR_SPROPNABOR_SOST(void)=0;
   virtual void set_ElementIDPROPNABOR_SPROPNABOR_SOST(TFIBLargeIntField * ElementIDPROPNABOR_SPROPNABOR_SOST)=0;

   __property TFIBLargeIntField * ElementIDPROP_SPROPNABOR_SOST = {read = get_ElementIDPROP_SPROPNABOR_SOST , write = set_ElementIDPROP_SPROPNABOR_SOST};
   virtual TFIBLargeIntField * get_ElementIDPROP_SPROPNABOR_SOST(void)=0;
   virtual void set_ElementIDPROP_SPROPNABOR_SOST(TFIBLargeIntField * ElementIDPROP_SPROPNABOR_SOST)=0;

   __property TFIBIntegerField * ElementINDEXSORT_SPROPNABOR_SOST = {read = get_ElementINDEXSORT_SPROPNABOR_SOST , write = set_ElementINDEXSORT_SPROPNABOR_SOST};
   virtual TFIBIntegerField * get_ElementINDEXSORT_SPROPNABOR_SOST(void)=0;
   virtual void set_ElementINDEXSORT_SPROPNABOR_SOST(TFIBIntegerField * ElementINDEXSORT_SPROPNABOR_SOST)=0;

   __property TFIBWideStringField * TableNAME_SPROP = {read = get_TableNAME_SPROP , write = set_TableNAME_SPROP};
   virtual TFIBWideStringField * get_TableNAME_SPROP(void)=0;
   virtual void set_TableNAME_SPROP(TFIBWideStringField * TableNAME_SPROP)=0;

   __property TFIBWideStringField * ElementNAME_SPROP = {read = get_ElementNAME_SPROP , write = set_ElementNAME_SPROP};
   virtual TFIBWideStringField * get_ElementNAME_SPROP(void)=0;
   virtual void set_ElementNAME_SPROP(TFIBWideStringField * ElementNAME_SPROP)=0;

   __property TFIBWideStringField * TableNAME_FOR_PRINT_SPROP = {read = get_TableNAME_FOR_PRINT_SPROP , write = set_TableNAME_FOR_PRINT_SPROP};
   virtual TFIBWideStringField * get_TableNAME_FOR_PRINT_SPROP(void)=0;
   virtual void set_TableNAME_FOR_PRINT_SPROP(TFIBWideStringField * TableNAME_FOR_PRINT_SPROP)=0;

   __property TFIBWideStringField * TableNAME_SPROP_GRP = {read = get_TableNAME_SPROP_GRP , write = set_TableNAME_SPROP_GRP};
   virtual TFIBWideStringField * get_TableNAME_SPROP_GRP(void)=0;
   virtual void set_TableNAME_SPROP_GRP(TFIBWideStringField * TableNAME_SPROP_GRP)=0;

   __property TFIBWideStringField * TableNAME_FOR_PRINT_SPROP_GRP = {read = get_TableNAME_FOR_PRINT_SPROP_GRP , write = set_TableNAME_FOR_PRINT_SPROP_GRP};
   virtual TFIBWideStringField * get_TableNAME_FOR_PRINT_SPROP_GRP(void)=0;
   virtual void set_TableNAME_FOR_PRINT_SPROP_GRP(TFIBWideStringField * TableNAME_FOR_PRINT_SPROP_GRP)=0;

   __property TFIBSmallIntField * TableADD1_SPROPNABOR_SOST = {read = get_TableADD1_SPROPNABOR_SOST , write = set_TableADD1_SPROPNABOR_SOST};
   virtual TFIBSmallIntField * get_TableADD1_SPROPNABOR_SOST(void)=0;
   virtual void set_TableADD1_SPROPNABOR_SOST(TFIBSmallIntField * TableADD1_SPROPNABOR_SOST)=0;

   __property TFIBSmallIntField * TableADD2_SPROPNABOR_SOST = {read = get_TableADD2_SPROPNABOR_SOST , write = set_TableADD2_SPROPNABOR_SOST};
   virtual TFIBSmallIntField * get_TableADD2_SPROPNABOR_SOST(void)=0;
   virtual void set_TableADD2_SPROPNABOR_SOST(TFIBSmallIntField * TableADD2_SPROPNABOR_SOST)=0;

   __property TFIBSmallIntField * TableADD3_SPROPNABOR_SOST = {read = get_TableADD3_SPROPNABOR_SOST , write = set_TableADD3_SPROPNABOR_SOST};
   virtual TFIBSmallIntField * get_TableADD3_SPROPNABOR_SOST(void)=0;
   virtual void set_TableADD3_SPROPNABOR_SOST(TFIBSmallIntField * TableADD3_SPROPNABOR_SOST)=0;

   __property TFIBSmallIntField * TableADD4_SPROPNABOR_SOST = {read = get_TableADD4_SPROPNABOR_SOST , write = set_TableADD4_SPROPNABOR_SOST};
   virtual TFIBSmallIntField * get_TableADD4_SPROPNABOR_SOST(void)=0;
   virtual void set_TableADD4_SPROPNABOR_SOST(TFIBSmallIntField * TableADD4_SPROPNABOR_SOST)=0;

   __property TFIBSmallIntField * TableADD5_SPROPNABOR_SOST = {read = get_TableADD5_SPROPNABOR_SOST , write = set_TableADD5_SPROPNABOR_SOST};
   virtual TFIBSmallIntField * get_TableADD5_SPROPNABOR_SOST(void)=0;
   virtual void set_TableADD5_SPROPNABOR_SOST(TFIBSmallIntField * TableADD5_SPROPNABOR_SOST)=0;

   __property TFIBSmallIntField * ElementADD1_SPROPNABOR_SOST = {read = get_ElementADD1_SPROPNABOR_SOST , write = set_ElementADD1_SPROPNABOR_SOST};
   virtual TFIBSmallIntField * get_ElementADD1_SPROPNABOR_SOST(void)=0;
   virtual void set_ElementADD1_SPROPNABOR_SOST(TFIBSmallIntField * ElementADD1_SPROPNABOR_SOST)=0;

   __property TFIBSmallIntField * ElementADD2_SPROPNABOR_SOST = {read = get_ElementADD2_SPROPNABOR_SOST , write = set_ElementADD2_SPROPNABOR_SOST};
   virtual TFIBSmallIntField * get_ElementADD2_SPROPNABOR_SOST(void)=0;
   virtual void set_ElementADD2_SPROPNABOR_SOST(TFIBSmallIntField * ElementADD2_SPROPNABOR_SOST)=0;

   __property TFIBSmallIntField * ElementADD3_SPROPNABOR_SOST = {read = get_ElementADD3_SPROPNABOR_SOST , write = set_ElementADD3_SPROPNABOR_SOST};
   virtual TFIBSmallIntField * get_ElementADD3_SPROPNABOR_SOST(void)=0;
   virtual void set_ElementADD3_SPROPNABOR_SOST(TFIBSmallIntField * ElementADD3_SPROPNABOR_SOST)=0;

   __property TFIBSmallIntField * ElementADD4_SPROPNABOR_SOST = {read = get_ElementADD4_SPROPNABOR_SOST , write = set_ElementADD4_SPROPNABOR_SOST};
   virtual TFIBSmallIntField * get_ElementADD4_SPROPNABOR_SOST(void)=0;
   virtual void set_ElementADD4_SPROPNABOR_SOST(TFIBSmallIntField * ElementADD4_SPROPNABOR_SOST)=0;

   __property TFIBSmallIntField * ElementADD5_SPROPNABOR_SOST = {read = get_ElementADD5_SPROPNABOR_SOST , write = set_ElementADD5_SPROPNABOR_SOST};
   virtual TFIBSmallIntField * get_ElementADD5_SPROPNABOR_SOST(void)=0;
   virtual void set_ElementADD5_SPROPNABOR_SOST(TFIBSmallIntField * ElementADD5_SPROPNABOR_SOST)=0;

   virtual void OpenTable(__int64 id_nabor)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual bool NewElement(__int64 id_nabor)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
};
#define IID_IDMSprPropertiesNaborSostav __uuidof(IDMSprPropertiesNaborSostav)
#endif
