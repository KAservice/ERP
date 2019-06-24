#ifndef UIDMSprNomPropertiesValueH
#define UIDMSprNomPropertiesValueH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprNomPropertiesValue)) IDMSprNomPropertiesValue : public IMainInterface
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

   __property TFIBLargeIntField * TableID_SNOMPROPVALUE = {read = get_TableID_SNOMPROPVALUE , write = set_TableID_SNOMPROPVALUE};
   virtual TFIBLargeIntField * get_TableID_SNOMPROPVALUE(void)=0;
   virtual void set_TableID_SNOMPROPVALUE(TFIBLargeIntField * TableID_SNOMPROPVALUE)=0;

   __property TFIBLargeIntField * TableIDBASE_SNOMPROPVALUE = {read = get_TableIDBASE_SNOMPROPVALUE , write = set_TableIDBASE_SNOMPROPVALUE};
   virtual TFIBLargeIntField * get_TableIDBASE_SNOMPROPVALUE(void)=0;
   virtual void set_TableIDBASE_SNOMPROPVALUE(TFIBLargeIntField * TableIDBASE_SNOMPROPVALUE)=0;

   __property TFIBWideStringField * TableGID_SNOMPROPVALUE = {read = get_TableGID_SNOMPROPVALUE , write = set_TableGID_SNOMPROPVALUE};
   virtual TFIBWideStringField * get_TableGID_SNOMPROPVALUE(void)=0;
   virtual void set_TableGID_SNOMPROPVALUE(TFIBWideStringField * TableGID_SNOMPROPVALUE)=0;

   __property TFIBLargeIntField * TableIDNOM_SNOMPROPVALUE = {read = get_TableIDNOM_SNOMPROPVALUE , write = set_TableIDNOM_SNOMPROPVALUE};
   virtual TFIBLargeIntField * get_TableIDNOM_SNOMPROPVALUE(void)=0;
   virtual void set_TableIDNOM_SNOMPROPVALUE(TFIBLargeIntField * TableIDNOM_SNOMPROPVALUE)=0;

   __property TFIBLargeIntField * TableIDPROP_SNOMPROPVALUE = {read = get_TableIDPROP_SNOMPROPVALUE , write = set_TableIDPROP_SNOMPROPVALUE};
   virtual TFIBLargeIntField * get_TableIDPROP_SNOMPROPVALUE(void)=0;
   virtual void set_TableIDPROP_SNOMPROPVALUE(TFIBLargeIntField * TableIDPROP_SNOMPROPVALUE)=0;

   __property TFIBLargeIntField * TableIDPROPVALLIST_SNOMPROPVALUE = {read = get_TableIDPROPVALLIST_SNOMPROPVALUE , write = set_TableIDPROPVALLIST_SNOMPROPVALUE};
   virtual TFIBLargeIntField * get_TableIDPROPVALLIST_SNOMPROPVALUE(void)=0;
   virtual void set_TableIDPROPVALLIST_SNOMPROPVALUE(TFIBLargeIntField * TableIDPROPVALLIST_SNOMPROPVALUE)=0;

   __property TFIBWideStringField * TableVALTEXT_SNOMPROPVALUE = {read = get_TableVALTEXT_SNOMPROPVALUE , write = set_TableVALTEXT_SNOMPROPVALUE};
   virtual TFIBWideStringField * get_TableVALTEXT_SNOMPROPVALUE(void)=0;
   virtual void set_TableVALTEXT_SNOMPROPVALUE(TFIBWideStringField * TableVALTEXT_SNOMPROPVALUE)=0;

   __property TFIBWideStringField * TableNAME_SPROP = {read = get_TableNAME_SPROP , write = set_TableNAME_SPROP};
   virtual TFIBWideStringField * get_TableNAME_SPROP(void)=0;
   virtual void set_TableNAME_SPROP(TFIBWideStringField * TableNAME_SPROP)=0;

   __property TFIBWideStringField * TableNAME_SPROPVALUELIST = {read = get_TableNAME_SPROPVALUELIST , write = set_TableNAME_SPROPVALUELIST};
   virtual TFIBWideStringField * get_TableNAME_SPROPVALUELIST(void)=0;
   virtual void set_TableNAME_SPROPVALUELIST(TFIBWideStringField * TableNAME_SPROPVALUELIST)=0;

   __property TDataSource * DataSourceElement = {read = get_DataSourceElement , write = set_DataSourceElement};
   virtual TDataSource * get_DataSourceElement(void)=0;
   virtual void set_DataSourceElement(TDataSource * DataSourceElement)=0;

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TFIBLargeIntField * ElementID_SNOMPROPVALUE = {read = get_ElementID_SNOMPROPVALUE , write = set_ElementID_SNOMPROPVALUE};
   virtual TFIBLargeIntField * get_ElementID_SNOMPROPVALUE(void)=0;
   virtual void set_ElementID_SNOMPROPVALUE(TFIBLargeIntField * ElementID_SNOMPROPVALUE)=0;

   __property TFIBLargeIntField * ElementIDBASE_SNOMPROPVALUE = {read = get_ElementIDBASE_SNOMPROPVALUE , write = set_ElementIDBASE_SNOMPROPVALUE};
   virtual TFIBLargeIntField * get_ElementIDBASE_SNOMPROPVALUE(void)=0;
   virtual void set_ElementIDBASE_SNOMPROPVALUE(TFIBLargeIntField * ElementIDBASE_SNOMPROPVALUE)=0;

   __property TFIBWideStringField * ElementGID_SNOMPROPVALUE = {read = get_ElementGID_SNOMPROPVALUE , write = set_ElementGID_SNOMPROPVALUE};
   virtual TFIBWideStringField * get_ElementGID_SNOMPROPVALUE(void)=0;
   virtual void set_ElementGID_SNOMPROPVALUE(TFIBWideStringField * ElementGID_SNOMPROPVALUE)=0;

   __property TFIBLargeIntField * ElementIDNOM_SNOMPROPVALUE = {read = get_ElementIDNOM_SNOMPROPVALUE , write = set_ElementIDNOM_SNOMPROPVALUE};
   virtual TFIBLargeIntField * get_ElementIDNOM_SNOMPROPVALUE(void)=0;
   virtual void set_ElementIDNOM_SNOMPROPVALUE(TFIBLargeIntField * ElementIDNOM_SNOMPROPVALUE)=0;

   __property TFIBLargeIntField * ElementIDPROP_SNOMPROPVALUE = {read = get_ElementIDPROP_SNOMPROPVALUE , write = set_ElementIDPROP_SNOMPROPVALUE};
   virtual TFIBLargeIntField * get_ElementIDPROP_SNOMPROPVALUE(void)=0;
   virtual void set_ElementIDPROP_SNOMPROPVALUE(TFIBLargeIntField * ElementIDPROP_SNOMPROPVALUE)=0;

   __property TFIBLargeIntField * ElementIDPROPVALLIST_SNOMPROPVALUE = {read = get_ElementIDPROPVALLIST_SNOMPROPVALUE , write = set_ElementIDPROPVALLIST_SNOMPROPVALUE};
   virtual TFIBLargeIntField * get_ElementIDPROPVALLIST_SNOMPROPVALUE(void)=0;
   virtual void set_ElementIDPROPVALLIST_SNOMPROPVALUE(TFIBLargeIntField * ElementIDPROPVALLIST_SNOMPROPVALUE)=0;

   __property TFIBWideStringField * ElementVALTEXT_SNOMPROPVALUE = {read = get_ElementVALTEXT_SNOMPROPVALUE , write = set_ElementVALTEXT_SNOMPROPVALUE};
   virtual TFIBWideStringField * get_ElementVALTEXT_SNOMPROPVALUE(void)=0;
   virtual void set_ElementVALTEXT_SNOMPROPVALUE(TFIBWideStringField * ElementVALTEXT_SNOMPROPVALUE)=0;

   __property TFIBWideStringField * ElementNAME_SPROP = {read = get_ElementNAME_SPROP , write = set_ElementNAME_SPROP};
   virtual TFIBWideStringField * get_ElementNAME_SPROP(void)=0;
   virtual void set_ElementNAME_SPROP(TFIBWideStringField * ElementNAME_SPROP)=0;

   __property TFIBWideStringField * ElementNAME_SPROPVALUELIST = {read = get_ElementNAME_SPROPVALUELIST , write = set_ElementNAME_SPROPVALUELIST};
   virtual TFIBWideStringField * get_ElementNAME_SPROPVALUELIST(void)=0;
   virtual void set_ElementNAME_SPROPVALUELIST(TFIBWideStringField * ElementNAME_SPROPVALUELIST)=0;

   __property TFIBIntegerField * TableINDEX_SNOMPROPVALUE = {read = get_TableINDEX_SNOMPROPVALUE , write = set_TableINDEX_SNOMPROPVALUE};
   virtual TFIBIntegerField * get_TableINDEX_SNOMPROPVALUE(void)=0;
   virtual void set_TableINDEX_SNOMPROPVALUE(TFIBIntegerField * TableINDEX_SNOMPROPVALUE)=0;

   __property TFIBIntegerField * ElementINDEX_SNOMPROPVALUE = {read = get_ElementINDEX_SNOMPROPVALUE , write = set_ElementINDEX_SNOMPROPVALUE};
   virtual TFIBIntegerField * get_ElementINDEX_SNOMPROPVALUE(void)=0;
   virtual void set_ElementINDEX_SNOMPROPVALUE(TFIBIntegerField * ElementINDEX_SNOMPROPVALUE)=0;

   __property TFIBWideStringField * TableNAME_FOR_PRINT_SPROP = {read = get_TableNAME_FOR_PRINT_SPROP , write = set_TableNAME_FOR_PRINT_SPROP};
   virtual TFIBWideStringField * get_TableNAME_FOR_PRINT_SPROP(void)=0;
   virtual void set_TableNAME_FOR_PRINT_SPROP(TFIBWideStringField * TableNAME_FOR_PRINT_SPROP)=0;

   __property TFIBWideStringField * TableNAME_SPROP_GRP = {read = get_TableNAME_SPROP_GRP , write = set_TableNAME_SPROP_GRP};
   virtual TFIBWideStringField * get_TableNAME_SPROP_GRP(void)=0;
   virtual void set_TableNAME_SPROP_GRP(TFIBWideStringField * TableNAME_SPROP_GRP)=0;

   __property TFIBWideStringField * TableNAME_FOR_PRINT_SPROP_GRP = {read = get_TableNAME_FOR_PRINT_SPROP_GRP , write = set_TableNAME_FOR_PRINT_SPROP_GRP};
   virtual TFIBWideStringField * get_TableNAME_FOR_PRINT_SPROP_GRP(void)=0;
   virtual void set_TableNAME_FOR_PRINT_SPROP_GRP(TFIBWideStringField * TableNAME_FOR_PRINT_SPROP_GRP)=0;

   __property TFIBSmallIntField * TableADD1_SNOMPROPVALUE = {read = get_TableADD1_SNOMPROPVALUE , write = set_TableADD1_SNOMPROPVALUE};
   virtual TFIBSmallIntField * get_TableADD1_SNOMPROPVALUE(void)=0;
   virtual void set_TableADD1_SNOMPROPVALUE(TFIBSmallIntField * TableADD1_SNOMPROPVALUE)=0;

   __property TFIBSmallIntField * TableADD2_SNOMPROPVALUE = {read = get_TableADD2_SNOMPROPVALUE , write = set_TableADD2_SNOMPROPVALUE};
   virtual TFIBSmallIntField * get_TableADD2_SNOMPROPVALUE(void)=0;
   virtual void set_TableADD2_SNOMPROPVALUE(TFIBSmallIntField * TableADD2_SNOMPROPVALUE)=0;

   __property TFIBSmallIntField * TableADD3_SNOMPROPVALUE = {read = get_TableADD3_SNOMPROPVALUE , write = set_TableADD3_SNOMPROPVALUE};
   virtual TFIBSmallIntField * get_TableADD3_SNOMPROPVALUE(void)=0;
   virtual void set_TableADD3_SNOMPROPVALUE(TFIBSmallIntField * TableADD3_SNOMPROPVALUE)=0;

   __property TFIBSmallIntField * TableADD4_SNOMPROPVALUE = {read = get_TableADD4_SNOMPROPVALUE , write = set_TableADD4_SNOMPROPVALUE};
   virtual TFIBSmallIntField * get_TableADD4_SNOMPROPVALUE(void)=0;
   virtual void set_TableADD4_SNOMPROPVALUE(TFIBSmallIntField * TableADD4_SNOMPROPVALUE)=0;

   __property TFIBSmallIntField * TableADD5_SNOMPROPVALUE = {read = get_TableADD5_SNOMPROPVALUE , write = set_TableADD5_SNOMPROPVALUE};
   virtual TFIBSmallIntField * get_TableADD5_SNOMPROPVALUE(void)=0;
   virtual void set_TableADD5_SNOMPROPVALUE(TFIBSmallIntField * TableADD5_SNOMPROPVALUE)=0;

   __property TFIBSmallIntField * ElementADD1_SNOMPROPVALUE = {read = get_ElementADD1_SNOMPROPVALUE , write = set_ElementADD1_SNOMPROPVALUE};
   virtual TFIBSmallIntField * get_ElementADD1_SNOMPROPVALUE(void)=0;
   virtual void set_ElementADD1_SNOMPROPVALUE(TFIBSmallIntField * ElementADD1_SNOMPROPVALUE)=0;

   __property TFIBSmallIntField * ElementADD2_SNOMPROPVALUE = {read = get_ElementADD2_SNOMPROPVALUE , write = set_ElementADD2_SNOMPROPVALUE};
   virtual TFIBSmallIntField * get_ElementADD2_SNOMPROPVALUE(void)=0;
   virtual void set_ElementADD2_SNOMPROPVALUE(TFIBSmallIntField * ElementADD2_SNOMPROPVALUE)=0;

   __property TFIBSmallIntField * ElementADD3_SNOMPROPVALUE = {read = get_ElementADD3_SNOMPROPVALUE , write = set_ElementADD3_SNOMPROPVALUE};
   virtual TFIBSmallIntField * get_ElementADD3_SNOMPROPVALUE(void)=0;
   virtual void set_ElementADD3_SNOMPROPVALUE(TFIBSmallIntField * ElementADD3_SNOMPROPVALUE)=0;

   __property TFIBSmallIntField * ElementADD4_SNOMPROPVALUE = {read = get_ElementADD4_SNOMPROPVALUE , write = set_ElementADD4_SNOMPROPVALUE};
   virtual TFIBSmallIntField * get_ElementADD4_SNOMPROPVALUE(void)=0;
   virtual void set_ElementADD4_SNOMPROPVALUE(TFIBSmallIntField * ElementADD4_SNOMPROPVALUE)=0;

   __property TFIBSmallIntField * ElementADD5_SNOMPROPVALUE = {read = get_ElementADD5_SNOMPROPVALUE , write = set_ElementADD5_SNOMPROPVALUE};
   virtual TFIBSmallIntField * get_ElementADD5_SNOMPROPVALUE(void)=0;
   virtual void set_ElementADD5_SNOMPROPVALUE(TFIBSmallIntField * ElementADD5_SNOMPROPVALUE)=0;

   __property TpFIBQuery * Query = {read = get_Query , write = set_Query};
   virtual TpFIBQuery * get_Query(void)=0;
   virtual void set_Query(TpFIBQuery * Query)=0;

   __property __int64 IdNom = {read = get_IdNom , write = set_IdNom};
   virtual __int64 get_IdNom(void)=0;
   virtual void set_IdNom(__int64 IdNom)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   virtual void OpenTable(__int64 id_nom)=0;
   virtual bool NewElement(__int64 id_nom)=0;
   virtual int OpenElement(__int64 id )=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual __int64 GetIdPoIdNomIdProp(__int64 id_nom, __int64 id_prop)=0;
};
#define IID_IDMSprNomPropertiesValue __uuidof(IDMSprNomPropertiesValue)
#endif
