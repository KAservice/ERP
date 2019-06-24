#ifndef UIDMSprProducerNomH
#define UIDMSprProducerNomH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprProducerNom)) IDMSprProducerNom : public IMainInterface
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

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TpFIBDataSet * SpTPrice = {read = get_SpTPrice , write = set_SpTPrice};
   virtual TpFIBDataSet * get_SpTPrice(void)=0;
   virtual void set_SpTPrice(TpFIBDataSet * SpTPrice)=0;

   __property TDataSource * DataSourceElement = {read = get_DataSourceElement , write = set_DataSourceElement};
   virtual TDataSource * get_DataSourceElement(void)=0;
   virtual void set_DataSourceElement(TDataSource * DataSourceElement)=0;

   __property TFIBLargeIntField * ElementID_SPRNOM = {read = get_ElementID_SPRNOM , write = set_ElementID_SPRNOM};
   virtual TFIBLargeIntField * get_ElementID_SPRNOM(void)=0;
   virtual void set_ElementID_SPRNOM(TFIBLargeIntField * ElementID_SPRNOM)=0;

   __property TFIBLargeIntField * ElementIDBASE_SPRNOM = {read = get_ElementIDBASE_SPRNOM , write = set_ElementIDBASE_SPRNOM};
   virtual TFIBLargeIntField * get_ElementIDBASE_SPRNOM(void)=0;
   virtual void set_ElementIDBASE_SPRNOM(TFIBLargeIntField * ElementIDBASE_SPRNOM)=0;

   __property TFIBWideStringField * ElementGID_SPRNOM = {read = get_ElementGID_SPRNOM , write = set_ElementGID_SPRNOM};
   virtual TFIBWideStringField * get_ElementGID_SPRNOM(void)=0;
   virtual void set_ElementGID_SPRNOM(TFIBWideStringField * ElementGID_SPRNOM)=0;

   __property TFIBLargeIntField * ElementIDPROD_SPRNOM = {read = get_ElementIDPROD_SPRNOM , write = set_ElementIDPROD_SPRNOM};
   virtual TFIBLargeIntField * get_ElementIDPROD_SPRNOM(void)=0;
   virtual void set_ElementIDPROD_SPRNOM(TFIBLargeIntField * ElementIDPROD_SPRNOM)=0;

   __property TFIBLargeIntField * ElementIDGRP_SPRNOM = {read = get_ElementIDGRP_SPRNOM , write = set_ElementIDGRP_SPRNOM};
   virtual TFIBLargeIntField * get_ElementIDGRP_SPRNOM(void)=0;
   virtual void set_ElementIDGRP_SPRNOM(TFIBLargeIntField * ElementIDGRP_SPRNOM)=0;

   __property TFIBIntegerField * ElementCODE_SPRNOM = {read = get_ElementCODE_SPRNOM , write = set_ElementCODE_SPRNOM};
   virtual TFIBIntegerField * get_ElementCODE_SPRNOM(void)=0;
   virtual void set_ElementCODE_SPRNOM(TFIBIntegerField * ElementCODE_SPRNOM)=0;

   __property TFIBWideStringField * ElementART_SPRNOM = {read = get_ElementART_SPRNOM , write = set_ElementART_SPRNOM};
   virtual TFIBWideStringField * get_ElementART_SPRNOM(void)=0;
   virtual void set_ElementART_SPRNOM(TFIBWideStringField * ElementART_SPRNOM)=0;

   __property TFIBWideStringField * ElementNAME_SPRNOM = {read = get_ElementNAME_SPRNOM , write = set_ElementNAME_SPRNOM};
   virtual TFIBWideStringField * get_ElementNAME_SPRNOM(void)=0;
   virtual void set_ElementNAME_SPRNOM(TFIBWideStringField * ElementNAME_SPRNOM)=0;

   __property TFIBWideStringField * ElementKRNAME_SPRNOM = {read = get_ElementKRNAME_SPRNOM , write = set_ElementKRNAME_SPRNOM};
   virtual TFIBWideStringField * get_ElementKRNAME_SPRNOM(void)=0;
   virtual void set_ElementKRNAME_SPRNOM(TFIBWideStringField * ElementKRNAME_SPRNOM)=0;

   __property TFIBWideStringField * ElementFNAME_SPRNOM = {read = get_ElementFNAME_SPRNOM , write = set_ElementFNAME_SPRNOM};
   virtual TFIBWideStringField * get_ElementFNAME_SPRNOM(void)=0;
   virtual void set_ElementFNAME_SPRNOM(TFIBWideStringField * ElementFNAME_SPRNOM)=0;

   __property TFIBIntegerField * ElementTYPE_SPRNOM = {read = get_ElementTYPE_SPRNOM , write = set_ElementTYPE_SPRNOM};
   virtual TFIBIntegerField * get_ElementTYPE_SPRNOM(void)=0;
   virtual void set_ElementTYPE_SPRNOM(TFIBIntegerField * ElementTYPE_SPRNOM)=0;

   __property TFIBLargeIntField * ElementIDBASED_SPRNOM = {read = get_ElementIDBASED_SPRNOM , write = set_ElementIDBASED_SPRNOM};
   virtual TFIBLargeIntField * get_ElementIDBASED_SPRNOM(void)=0;
   virtual void set_ElementIDBASED_SPRNOM(TFIBLargeIntField * ElementIDBASED_SPRNOM)=0;

   __property TFIBLargeIntField * TableID_SPRNOM = {read = get_TableID_SPRNOM , write = set_TableID_SPRNOM};
   virtual TFIBLargeIntField * get_TableID_SPRNOM(void)=0;
   virtual void set_TableID_SPRNOM(TFIBLargeIntField * TableID_SPRNOM)=0;

   __property TFIBLargeIntField * TableIDGRP_SPRNOM = {read = get_TableIDGRP_SPRNOM , write = set_TableIDGRP_SPRNOM};
   virtual TFIBLargeIntField * get_TableIDGRP_SPRNOM(void)=0;
   virtual void set_TableIDGRP_SPRNOM(TFIBLargeIntField * TableIDGRP_SPRNOM)=0;

   __property TFIBLargeIntField * TableIDPROD_SPRNOM = {read = get_TableIDPROD_SPRNOM , write = set_TableIDPROD_SPRNOM};
   virtual TFIBLargeIntField * get_TableIDPROD_SPRNOM(void)=0;
   virtual void set_TableIDPROD_SPRNOM(TFIBLargeIntField * TableIDPROD_SPRNOM)=0;

   __property TFIBIntegerField * TableCODE_SPRNOM = {read = get_TableCODE_SPRNOM , write = set_TableCODE_SPRNOM};
   virtual TFIBIntegerField * get_TableCODE_SPRNOM(void)=0;
   virtual void set_TableCODE_SPRNOM(TFIBIntegerField * TableCODE_SPRNOM)=0;

   __property TFIBWideStringField * TableART_SPRNOM = {read = get_TableART_SPRNOM , write = set_TableART_SPRNOM};
   virtual TFIBWideStringField * get_TableART_SPRNOM(void)=0;
   virtual void set_TableART_SPRNOM(TFIBWideStringField * TableART_SPRNOM)=0;

   __property TFIBWideStringField * TableNAME_SPRNOM = {read = get_TableNAME_SPRNOM , write = set_TableNAME_SPRNOM};
   virtual TFIBWideStringField * get_TableNAME_SPRNOM(void)=0;
   virtual void set_TableNAME_SPRNOM(TFIBWideStringField * TableNAME_SPRNOM)=0;

   __property TFIBWideStringField * TableNAME_SPRED = {read = get_TableNAME_SPRED , write = set_TableNAME_SPRED};
   virtual TFIBWideStringField * get_TableNAME_SPRED(void)=0;
   virtual void set_TableNAME_SPRED(TFIBWideStringField * TableNAME_SPRED)=0;

   __property TFIBWideStringField * TableBARCODE_SPRED = {read = get_TableBARCODE_SPRED , write = set_TableBARCODE_SPRED};
   virtual TFIBWideStringField * get_TableBARCODE_SPRED(void)=0;
   virtual void set_TableBARCODE_SPRED(TFIBWideStringField * TableBARCODE_SPRED)=0;

   __property TFIBBCDField * TableVALUE_SPRPRICE = {read = get_TableVALUE_SPRPRICE , write = set_TableVALUE_SPRPRICE};
   virtual TFIBBCDField * get_TableVALUE_SPRPRICE(void)=0;
   virtual void set_TableVALUE_SPRPRICE(TFIBBCDField * TableVALUE_SPRPRICE)=0;

   __property TFIBLargeIntField * SpTPriceID_SPRTYPE_PRICE = {read = get_SpTPriceID_SPRTYPE_PRICE , write = set_SpTPriceID_SPRTYPE_PRICE};
   virtual TFIBLargeIntField * get_SpTPriceID_SPRTYPE_PRICE(void)=0;
   virtual void set_SpTPriceID_SPRTYPE_PRICE(TFIBLargeIntField * SpTPriceID_SPRTYPE_PRICE)=0;

   __property TFIBWideStringField * SpTPriceNAME_SPRTYPE_PRICE = {read = get_SpTPriceNAME_SPRTYPE_PRICE , write = set_SpTPriceNAME_SPRTYPE_PRICE};
   virtual TFIBWideStringField * get_SpTPriceNAME_SPRTYPE_PRICE(void)=0;
   virtual void set_SpTPriceNAME_SPRTYPE_PRICE(TFIBWideStringField * SpTPriceNAME_SPRTYPE_PRICE)=0;

   __property TFIBWideStringField * TableMODEL_STR_SPRNOM = {read = get_TableMODEL_STR_SPRNOM , write = set_TableMODEL_STR_SPRNOM};
   virtual TFIBWideStringField * get_TableMODEL_STR_SPRNOM(void)=0;
   virtual void set_TableMODEL_STR_SPRNOM(TFIBWideStringField * TableMODEL_STR_SPRNOM)=0;

   __property TFIBWideStringField * TableCODE_ANALOG_STR_SPRNOM = {read = get_TableCODE_ANALOG_STR_SPRNOM , write = set_TableCODE_ANALOG_STR_SPRNOM};
   virtual TFIBWideStringField * get_TableCODE_ANALOG_STR_SPRNOM(void)=0;
   virtual void set_TableCODE_ANALOG_STR_SPRNOM(TFIBWideStringField * TableCODE_ANALOG_STR_SPRNOM)=0;

   __property TFIBSmallIntField * TableFL_DOSTUPNO_SPRNOM = {read = get_TableFL_DOSTUPNO_SPRNOM , write = set_TableFL_DOSTUPNO_SPRNOM};
   virtual TFIBSmallIntField * get_TableFL_DOSTUPNO_SPRNOM(void)=0;
   virtual void set_TableFL_DOSTUPNO_SPRNOM(TFIBSmallIntField * TableFL_DOSTUPNO_SPRNOM)=0;

   __property TFIBBCDField * TablePRICE_ZAKUP_SPRNOM = {read = get_TablePRICE_ZAKUP_SPRNOM , write = set_TablePRICE_ZAKUP_SPRNOM};
   virtual TFIBBCDField * get_TablePRICE_ZAKUP_SPRNOM(void)=0;
   virtual void set_TablePRICE_ZAKUP_SPRNOM(TFIBBCDField * TablePRICE_ZAKUP_SPRNOM)=0;

   __property TFIBBCDField * TablePRICE_SPRNOM = {read = get_TablePRICE_SPRNOM , write = set_TablePRICE_SPRNOM};
   virtual TFIBBCDField * get_TablePRICE_SPRNOM(void)=0;
   virtual void set_TablePRICE_SPRNOM(TFIBBCDField * TablePRICE_SPRNOM)=0;

   __property TFIBWideStringField * ElementMODEL_STR_SPRNOM = {read = get_ElementMODEL_STR_SPRNOM , write = set_ElementMODEL_STR_SPRNOM};
   virtual TFIBWideStringField * get_ElementMODEL_STR_SPRNOM(void)=0;
   virtual void set_ElementMODEL_STR_SPRNOM(TFIBWideStringField * ElementMODEL_STR_SPRNOM)=0;

   __property TFIBWideStringField * ElementCODE_ANALOG_STR_SPRNOM = {read = get_ElementCODE_ANALOG_STR_SPRNOM , write = set_ElementCODE_ANALOG_STR_SPRNOM};
   virtual TFIBWideStringField * get_ElementCODE_ANALOG_STR_SPRNOM(void)=0;
   virtual void set_ElementCODE_ANALOG_STR_SPRNOM(TFIBWideStringField * ElementCODE_ANALOG_STR_SPRNOM)=0;

   __property TFIBSmallIntField * ElementFL_DOSTUPNO_SPRNOM = {read = get_ElementFL_DOSTUPNO_SPRNOM , write = set_ElementFL_DOSTUPNO_SPRNOM};
   virtual TFIBSmallIntField * get_ElementFL_DOSTUPNO_SPRNOM(void)=0;
   virtual void set_ElementFL_DOSTUPNO_SPRNOM(TFIBSmallIntField * ElementFL_DOSTUPNO_SPRNOM)=0;

   __property TFIBBCDField * ElementPRICE_ZAKUP_SPRNOM = {read = get_ElementPRICE_ZAKUP_SPRNOM , write = set_ElementPRICE_ZAKUP_SPRNOM};
   virtual TFIBBCDField * get_ElementPRICE_ZAKUP_SPRNOM(void)=0;
   virtual void set_ElementPRICE_ZAKUP_SPRNOM(TFIBBCDField * ElementPRICE_ZAKUP_SPRNOM)=0;

   __property TFIBBCDField * ElementPRICE_SPRNOM = {read = get_ElementPRICE_SPRNOM , write = set_ElementPRICE_SPRNOM};
   virtual TFIBBCDField * get_ElementPRICE_SPRNOM(void)=0;
   virtual void set_ElementPRICE_SPRNOM(TFIBBCDField * ElementPRICE_SPRNOM)=0;

   __property TFIBIntegerField * TableCODENOM = {read = get_TableCODENOM , write = set_TableCODENOM};
   virtual TFIBIntegerField * get_TableCODENOM(void)=0;
   virtual void set_TableCODENOM(TFIBIntegerField * TableCODENOM)=0;

   __property TFIBWideStringField * TableARTNOM = {read = get_TableARTNOM , write = set_TableARTNOM};
   virtual TFIBWideStringField * get_TableARTNOM(void)=0;
   virtual void set_TableARTNOM(TFIBWideStringField * TableARTNOM)=0;

   __property TFIBWideStringField * TableNAMENOM = {read = get_TableNAMENOM , write = set_TableNAMENOM};
   virtual TFIBWideStringField * get_TableNAMENOM(void)=0;
   virtual void set_TableNAMENOM(TFIBWideStringField * TableNAMENOM)=0;

   __property TFIBWideStringField * TableSHED = {read = get_TableSHED , write = set_TableSHED};
   virtual TFIBWideStringField * get_TableSHED(void)=0;
   virtual void set_TableSHED(TFIBWideStringField * TableSHED)=0;

   __property TFIBWideStringField * TableNAMEED = {read = get_TableNAMEED , write = set_TableNAMEED};
   virtual TFIBWideStringField * get_TableNAMEED(void)=0;
   virtual void set_TableNAMEED(TFIBWideStringField * TableNAMEED)=0;

   __property TFIBLargeIntField * ElementIDNOM_SPRNOM = {read = get_ElementIDNOM_SPRNOM , write = set_ElementIDNOM_SPRNOM};
   virtual TFIBLargeIntField * get_ElementIDNOM_SPRNOM(void)=0;
   virtual void set_ElementIDNOM_SPRNOM(TFIBLargeIntField * ElementIDNOM_SPRNOM)=0;

   __property TFIBIntegerField * ElementCODENOM = {read = get_ElementCODENOM , write = set_ElementCODENOM};
   virtual TFIBIntegerField * get_ElementCODENOM(void)=0;
   virtual void set_ElementCODENOM(TFIBIntegerField * ElementCODENOM)=0;

   __property TFIBWideStringField * ElementARTNOM = {read = get_ElementARTNOM , write = set_ElementARTNOM};
   virtual TFIBWideStringField * get_ElementARTNOM(void)=0;
   virtual void set_ElementARTNOM(TFIBWideStringField * ElementARTNOM)=0;

   __property TFIBWideStringField * ElementNAMENOM = {read = get_ElementNAMENOM , write = set_ElementNAMENOM};
   virtual TFIBWideStringField * get_ElementNAMENOM(void)=0;
   virtual void set_ElementNAMENOM(TFIBWideStringField * ElementNAMENOM)=0;

   __property TFIBWideStringField * ElementSHED = {read = get_ElementSHED , write = set_ElementSHED};
   virtual TFIBWideStringField * get_ElementSHED(void)=0;
   virtual void set_ElementSHED(TFIBWideStringField * ElementSHED)=0;

   __property TFIBWideStringField * ElementNAMEED = {read = get_ElementNAMEED , write = set_ElementNAMEED};
   virtual TFIBWideStringField * get_ElementNAMEED(void)=0;
   virtual void set_ElementNAMEED(TFIBWideStringField * ElementNAMEED)=0;

   __property TpFIBQuery * pFIBQuery = {read = get_pFIBQuery , write = set_pFIBQuery};
   virtual TpFIBQuery * get_pFIBQuery(void)=0;
   virtual void set_pFIBQuery(TpFIBQuery * pFIBQuery)=0;

   __property TFIBDateTimeField * ElementISM_SPRNOM = {read = get_ElementISM_SPRNOM , write = set_ElementISM_SPRNOM};
   virtual TFIBDateTimeField * get_ElementISM_SPRNOM(void)=0;
   virtual void set_ElementISM_SPRNOM(TFIBDateTimeField * ElementISM_SPRNOM)=0;

   __property TFIBDateTimeField * TableISM_SPRNOM = {read = get_TableISM_SPRNOM , write = set_TableISM_SPRNOM};
   virtual TFIBDateTimeField * get_TableISM_SPRNOM(void)=0;
   virtual void set_TableISM_SPRNOM(TFIBDateTimeField * TableISM_SPRNOM)=0;

   __property TFIBWideStringField * ElementREPAIRCODE_SPRNOM = {read = get_ElementREPAIRCODE_SPRNOM , write = set_ElementREPAIRCODE_SPRNOM};
   virtual TFIBWideStringField * get_ElementREPAIRCODE_SPRNOM(void)=0;
   virtual void set_ElementREPAIRCODE_SPRNOM(TFIBWideStringField * ElementREPAIRCODE_SPRNOM)=0;

   __property TFIBWideStringField * ElementLOCATION_SPRNOM = {read = get_ElementLOCATION_SPRNOM , write = set_ElementLOCATION_SPRNOM};
   virtual TFIBWideStringField * get_ElementLOCATION_SPRNOM(void)=0;
   virtual void set_ElementLOCATION_SPRNOM(TFIBWideStringField * ElementLOCATION_SPRNOM)=0;

   __property TFIBWideStringField * ElementART2_SPRNOM = {read = get_ElementART2_SPRNOM , write = set_ElementART2_SPRNOM};
   virtual TFIBWideStringField * get_ElementART2_SPRNOM(void)=0;
   virtual void set_ElementART2_SPRNOM(TFIBWideStringField * ElementART2_SPRNOM)=0;

   __property TFIBWideStringField * ElementANGL_NAME_SPRNOM = {read = get_ElementANGL_NAME_SPRNOM , write = set_ElementANGL_NAME_SPRNOM};
   virtual TFIBWideStringField * get_ElementANGL_NAME_SPRNOM(void)=0;
   virtual void set_ElementANGL_NAME_SPRNOM(TFIBWideStringField * ElementANGL_NAME_SPRNOM)=0;

   __property TFIBWideStringField * TableART2_SPRNOM = {read = get_TableART2_SPRNOM , write = set_TableART2_SPRNOM};
   virtual TFIBWideStringField * get_TableART2_SPRNOM(void)=0;
   virtual void set_TableART2_SPRNOM(TFIBWideStringField * TableART2_SPRNOM)=0;



   __property __int64 IdProducer = {read = get_IdProducer , write = set_IdProducer};
   virtual __int64 get_IdProducer(void)=0;
   virtual void set_IdProducer(__int64 IdProducer)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   __property __int64 IdProducerTypePrice = {read = get_IdProducerTypePrice , write = set_IdProducerTypePrice};
   virtual __int64 get_IdProducerTypePrice(void)=0;
   virtual void set_IdProducerTypePrice(__int64 IdProducerTypePrice)=0;

   virtual void OpenTable(__int64 id_producer, __int64 id_grp, __int64 id_producer_type_price, bool all,	UnicodeString in_str, int fl_poisk)=0;
   virtual bool NewElement(__int64 id_producer, __int64 id_grp)=0;
   virtual bool OpenElement(__int64 id)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual bool SaveElement(void)=0;
   virtual void ChancheGrp(__int64 id_new_grp,__int64 id_producer_nom)=0;
   virtual __int64 FindPoCodu(__int64 id_producer, UnicodeString model, int Code)=0;
   virtual __int64 FindPoShtrihCodu(__int64 id_producer, UnicodeString model,UnicodeString shtrih_cod)=0;
   virtual __int64 FindPoName(__int64 id_producer, UnicodeString model,UnicodeString name)=0;
   virtual __int64 FindPoArtikulu(__int64 id_producer, UnicodeString model,UnicodeString artikul)=0;
   virtual __int64 GetIdGrpNom(__int64 id_nom)=0;
};
#define IID_IDMSprProducerNom __uuidof(IDMSprProducerNom)
#endif
