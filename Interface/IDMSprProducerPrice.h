#ifndef UIDMSprProducerPriceH
#define UIDMSprProducerPriceH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprProducerPrice)) IDMSprProducerPrice : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

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

   __property TpFIBDataSet * TPrice = {read = get_TPrice , write = set_TPrice};
   virtual TpFIBDataSet * get_TPrice(void)=0;
   virtual void set_TPrice(TpFIBDataSet * TPrice)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBLargeIntField * TPriceID_SPRTYPE_PRICE = {read = get_TPriceID_SPRTYPE_PRICE , write = set_TPriceID_SPRTYPE_PRICE};
   virtual TFIBLargeIntField * get_TPriceID_SPRTYPE_PRICE(void)=0;
   virtual void set_TPriceID_SPRTYPE_PRICE(TFIBLargeIntField * TPriceID_SPRTYPE_PRICE)=0;

   __property TFIBWideStringField * TPriceNAME_SPRTYPE_PRICE = {read = get_TPriceNAME_SPRTYPE_PRICE , write = set_TPriceNAME_SPRTYPE_PRICE};
   virtual TFIBWideStringField * get_TPriceNAME_SPRTYPE_PRICE(void)=0;
   virtual void set_TPriceNAME_SPRTYPE_PRICE(TFIBWideStringField * TPriceNAME_SPRTYPE_PRICE)=0;

   __property TFIBLargeIntField * TableID_SPRPRICE = {read = get_TableID_SPRPRICE , write = set_TableID_SPRPRICE};
   virtual TFIBLargeIntField * get_TableID_SPRPRICE(void)=0;
   virtual void set_TableID_SPRPRICE(TFIBLargeIntField * TableID_SPRPRICE)=0;

   __property TFIBLargeIntField * TableIDBASE_SPRPRICE = {read = get_TableIDBASE_SPRPRICE , write = set_TableIDBASE_SPRPRICE};
   virtual TFIBLargeIntField * get_TableIDBASE_SPRPRICE(void)=0;
   virtual void set_TableIDBASE_SPRPRICE(TFIBLargeIntField * TableIDBASE_SPRPRICE)=0;

   __property TFIBWideStringField * TableGID_SPRPRICE = {read = get_TableGID_SPRPRICE , write = set_TableGID_SPRPRICE};
   virtual TFIBWideStringField * get_TableGID_SPRPRICE(void)=0;
   virtual void set_TableGID_SPRPRICE(TFIBWideStringField * TableGID_SPRPRICE)=0;

   __property TFIBLargeIntField * TableIDPRNOM_SPRPRICE = {read = get_TableIDPRNOM_SPRPRICE , write = set_TableIDPRNOM_SPRPRICE};
   virtual TFIBLargeIntField * get_TableIDPRNOM_SPRPRICE(void)=0;
   virtual void set_TableIDPRNOM_SPRPRICE(TFIBLargeIntField * TableIDPRNOM_SPRPRICE)=0;

   __property TFIBLargeIntField * TableIDPRTPRICE_SPRPRICE = {read = get_TableIDPRTPRICE_SPRPRICE , write = set_TableIDPRTPRICE_SPRPRICE};
   virtual TFIBLargeIntField * get_TableIDPRTPRICE_SPRPRICE(void)=0;
   virtual void set_TableIDPRTPRICE_SPRPRICE(TFIBLargeIntField * TableIDPRTPRICE_SPRPRICE)=0;

   __property TFIBBCDField * TableVALUE_SPRPRICE = {read = get_TableVALUE_SPRPRICE , write = set_TableVALUE_SPRPRICE};
   virtual TFIBBCDField * get_TableVALUE_SPRPRICE(void)=0;
   virtual void set_TableVALUE_SPRPRICE(TFIBBCDField * TableVALUE_SPRPRICE)=0;

   __property TFIBWideStringField * TableNAME_SPRTYPE_PRICE = {read = get_TableNAME_SPRTYPE_PRICE , write = set_TableNAME_SPRTYPE_PRICE};
   virtual TFIBWideStringField * get_TableNAME_SPRTYPE_PRICE(void)=0;
   virtual void set_TableNAME_SPRTYPE_PRICE(TFIBWideStringField * TableNAME_SPRTYPE_PRICE)=0;

   __property TFIBBCDField * ElementID_SPRPRICE = {read = get_ElementID_SPRPRICE , write = set_ElementID_SPRPRICE};
   virtual TFIBBCDField * get_ElementID_SPRPRICE(void)=0;
   virtual void set_ElementID_SPRPRICE(TFIBBCDField * ElementID_SPRPRICE)=0;

   __property TFIBBCDField * ElementIDBASE_SPRPRICE = {read = get_ElementIDBASE_SPRPRICE , write = set_ElementIDBASE_SPRPRICE};
   virtual TFIBBCDField * get_ElementIDBASE_SPRPRICE(void)=0;
   virtual void set_ElementIDBASE_SPRPRICE(TFIBBCDField * ElementIDBASE_SPRPRICE)=0;

   __property TFIBWideStringField * ElementGID_SPRPRICE = {read = get_ElementGID_SPRPRICE , write = set_ElementGID_SPRPRICE};
   virtual TFIBWideStringField * get_ElementGID_SPRPRICE(void)=0;
   virtual void set_ElementGID_SPRPRICE(TFIBWideStringField * ElementGID_SPRPRICE)=0;

   __property TFIBBCDField * ElementIDPRNOM_SPRPRICE = {read = get_ElementIDPRNOM_SPRPRICE , write = set_ElementIDPRNOM_SPRPRICE};
   virtual TFIBBCDField * get_ElementIDPRNOM_SPRPRICE(void)=0;
   virtual void set_ElementIDPRNOM_SPRPRICE(TFIBBCDField * ElementIDPRNOM_SPRPRICE)=0;

   __property TFIBBCDField * ElementIDPRTPRICE_SPRPRICE = {read = get_ElementIDPRTPRICE_SPRPRICE , write = set_ElementIDPRTPRICE_SPRPRICE};
   virtual TFIBBCDField * get_ElementIDPRTPRICE_SPRPRICE(void)=0;
   virtual void set_ElementIDPRTPRICE_SPRPRICE(TFIBBCDField * ElementIDPRTPRICE_SPRPRICE)=0;

   __property TFIBBCDField * ElementVALUE_SPRPRICE = {read = get_ElementVALUE_SPRPRICE , write = set_ElementVALUE_SPRPRICE};
   virtual TFIBBCDField * get_ElementVALUE_SPRPRICE(void)=0;
   virtual void set_ElementVALUE_SPRPRICE(TFIBBCDField * ElementVALUE_SPRPRICE)=0;

   __property __int64 IdProducerNom = {read = get_IdProducerNom , write = set_IdProducerNom};
   virtual __int64 get_IdProducerNom(void)=0;
   virtual void set_IdProducerNom(__int64 IdProducerNom)=0;

   __property __int64 IdProducerTypePrice = {read = get_IdProducerTypePrice , write = set_IdProducerTypePrice};
   virtual __int64 get_IdProducerTypePrice(void)=0;
   virtual void set_IdProducerTypePrice(__int64 IdProducerTypePrice)=0;

   virtual void OpenTable(__int64 id_producer_nom)=0;
   virtual bool SaveIsmen(void)=0;
   virtual void CancelIsmen(void)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual void NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual __int64 FindElement(__int64 id_producer_type_price, __int64 id_producer_nom)=0;
};
#define IID_IDMSprProducerPrice __uuidof(IDMSprProducerPrice)
#endif
