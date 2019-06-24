#ifndef UIDMSprPriceScheduleH
#define UIDMSprPriceScheduleH
#include "IMainInterface.h"
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{F8BB5EAF-5A17-4949-B479-9D70BE2DEEF4}")) IDMSprPriceSchedule : public IMainInterface
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

   __property TpFIBQuery * Query = {read = get_Query , write = set_Query};
   virtual TpFIBQuery * get_Query(void)=0;
   virtual void set_Query(TpFIBQuery * Query)=0;

   __property TpFIBDataSet * SpisokEd = {read = get_SpisokEd , write = set_SpisokEd};
   virtual TpFIBDataSet * get_SpisokEd(void)=0;
   virtual void set_SpisokEd(TpFIBDataSet * SpisokEd)=0;

   __property TFIBBCDField * SpisokEdIDED = {read = get_SpisokEdIDED , write = set_SpisokEdIDED};
   virtual TFIBBCDField * get_SpisokEdIDED(void)=0;
   virtual void set_SpisokEdIDED(TFIBBCDField * SpisokEdIDED)=0;

   __property TFIBBCDField * SpisokEdKFED = {read = get_SpisokEdKFED , write = set_SpisokEdKFED};
   virtual TFIBBCDField * get_SpisokEdKFED(void)=0;
   virtual void set_SpisokEdKFED(TFIBBCDField * SpisokEdKFED)=0;

   __property TDataSource * DataSourceSpisokEd = {read = get_DataSourceSpisokEd , write = set_DataSourceSpisokEd};
   virtual TDataSource * get_DataSourceSpisokEd(void)=0;
   virtual void set_DataSourceSpisokEd(TDataSource * DataSourceSpisokEd)=0;

   __property TDataSource * DataSourceTypePrice = {read = get_DataSourceTypePrice , write = set_DataSourceTypePrice};
   virtual TDataSource * get_DataSourceTypePrice(void)=0;
   virtual void set_DataSourceTypePrice(TDataSource * DataSourceTypePrice)=0;

   __property TFIBBCDField * TableID_SPRICE_SCHEDULE = {read = get_TableID_SPRICE_SCHEDULE , write = set_TableID_SPRICE_SCHEDULE};
   virtual TFIBBCDField * get_TableID_SPRICE_SCHEDULE(void)=0;
   virtual void set_TableID_SPRICE_SCHEDULE(TFIBBCDField * TableID_SPRICE_SCHEDULE)=0;

   __property TFIBBCDField * TableIDBASE_SPRICE_SCHEDULE = {read = get_TableIDBASE_SPRICE_SCHEDULE , write = set_TableIDBASE_SPRICE_SCHEDULE};
   virtual TFIBBCDField * get_TableIDBASE_SPRICE_SCHEDULE(void)=0;
   virtual void set_TableIDBASE_SPRICE_SCHEDULE(TFIBBCDField * TableIDBASE_SPRICE_SCHEDULE)=0;

   __property TFIBBCDField * TableIDNOM_SPRICE_SCHEDULE = {read = get_TableIDNOM_SPRICE_SCHEDULE , write = set_TableIDNOM_SPRICE_SCHEDULE};
   virtual TFIBBCDField * get_TableIDNOM_SPRICE_SCHEDULE(void)=0;
   virtual void set_TableIDNOM_SPRICE_SCHEDULE(TFIBBCDField * TableIDNOM_SPRICE_SCHEDULE)=0;

   __property TFIBBCDField * TableIDTYPE_SPRICE_SCHEDULE = {read = get_TableIDTYPE_SPRICE_SCHEDULE , write = set_TableIDTYPE_SPRICE_SCHEDULE};
   virtual TFIBBCDField * get_TableIDTYPE_SPRICE_SCHEDULE(void)=0;
   virtual void set_TableIDTYPE_SPRICE_SCHEDULE(TFIBBCDField * TableIDTYPE_SPRICE_SCHEDULE)=0;

   __property TFIBBCDField * TableIDED_SPRICE_SCHEDULE = {read = get_TableIDED_SPRICE_SCHEDULE , write = set_TableIDED_SPRICE_SCHEDULE};
   virtual TFIBBCDField * get_TableIDED_SPRICE_SCHEDULE(void)=0;
   virtual void set_TableIDED_SPRICE_SCHEDULE(TFIBBCDField * TableIDED_SPRICE_SCHEDULE)=0;

   __property TFIBBCDField * TableVALUE_SPRICE_SCHEDULE = {read = get_TableVALUE_SPRICE_SCHEDULE , write = set_TableVALUE_SPRICE_SCHEDULE};
   virtual TFIBBCDField * get_TableVALUE_SPRICE_SCHEDULE(void)=0;
   virtual void set_TableVALUE_SPRICE_SCHEDULE(TFIBBCDField * TableVALUE_SPRICE_SCHEDULE)=0;

   __property TFIBDateTimeField * TablePOS_SPRICE_SCHEDULE = {read = get_TablePOS_SPRICE_SCHEDULE , write = set_TablePOS_SPRICE_SCHEDULE};
   virtual TFIBDateTimeField * get_TablePOS_SPRICE_SCHEDULE(void)=0;
   virtual void set_TablePOS_SPRICE_SCHEDULE(TFIBDateTimeField * TablePOS_SPRICE_SCHEDULE)=0;

   __property TFIBBCDField * ElementID_SPRICE_SCHEDULE = {read = get_ElementID_SPRICE_SCHEDULE , write = set_ElementID_SPRICE_SCHEDULE};
   virtual TFIBBCDField * get_ElementID_SPRICE_SCHEDULE(void)=0;
   virtual void set_ElementID_SPRICE_SCHEDULE(TFIBBCDField * ElementID_SPRICE_SCHEDULE)=0;

   __property TFIBBCDField * ElementIDBASE_SPRICE_SCHEDULE = {read = get_ElementIDBASE_SPRICE_SCHEDULE , write = set_ElementIDBASE_SPRICE_SCHEDULE};
   virtual TFIBBCDField * get_ElementIDBASE_SPRICE_SCHEDULE(void)=0;
   virtual void set_ElementIDBASE_SPRICE_SCHEDULE(TFIBBCDField * ElementIDBASE_SPRICE_SCHEDULE)=0;

   __property TFIBBCDField * ElementIDNOM_SPRICE_SCHEDULE = {read = get_ElementIDNOM_SPRICE_SCHEDULE , write = set_ElementIDNOM_SPRICE_SCHEDULE};
   virtual TFIBBCDField * get_ElementIDNOM_SPRICE_SCHEDULE(void)=0;
   virtual void set_ElementIDNOM_SPRICE_SCHEDULE(TFIBBCDField * ElementIDNOM_SPRICE_SCHEDULE)=0;

   __property TFIBBCDField * ElementIDTYPE_SPRICE_SCHEDULE = {read = get_ElementIDTYPE_SPRICE_SCHEDULE , write = set_ElementIDTYPE_SPRICE_SCHEDULE};
   virtual TFIBBCDField * get_ElementIDTYPE_SPRICE_SCHEDULE(void)=0;
   virtual void set_ElementIDTYPE_SPRICE_SCHEDULE(TFIBBCDField * ElementIDTYPE_SPRICE_SCHEDULE)=0;

   __property TFIBBCDField * ElementIDED_SPRICE_SCHEDULE = {read = get_ElementIDED_SPRICE_SCHEDULE , write = set_ElementIDED_SPRICE_SCHEDULE};
   virtual TFIBBCDField * get_ElementIDED_SPRICE_SCHEDULE(void)=0;
   virtual void set_ElementIDED_SPRICE_SCHEDULE(TFIBBCDField * ElementIDED_SPRICE_SCHEDULE)=0;

   __property TFIBBCDField * ElementVALUE_SPRICE_SCHEDULE = {read = get_ElementVALUE_SPRICE_SCHEDULE , write = set_ElementVALUE_SPRICE_SCHEDULE};
   virtual TFIBBCDField * get_ElementVALUE_SPRICE_SCHEDULE(void)=0;
   virtual void set_ElementVALUE_SPRICE_SCHEDULE(TFIBBCDField * ElementVALUE_SPRICE_SCHEDULE)=0;

   __property TFIBDateTimeField * ElementPOS_SPRICE_SCHEDULE = {read = get_ElementPOS_SPRICE_SCHEDULE , write = set_ElementPOS_SPRICE_SCHEDULE};
   virtual TFIBDateTimeField * get_ElementPOS_SPRICE_SCHEDULE(void)=0;
   virtual void set_ElementPOS_SPRICE_SCHEDULE(TFIBDateTimeField * ElementPOS_SPRICE_SCHEDULE)=0;

   __property TFIBWideStringField * TableNAME_TPRICE = {read = get_TableNAME_TPRICE , write = set_TableNAME_TPRICE};
   virtual TFIBWideStringField * get_TableNAME_TPRICE(void)=0;
   virtual void set_TableNAME_TPRICE(TFIBWideStringField * TableNAME_TPRICE)=0;

   __property TFIBWideStringField * SpisokEdNAMEED = {read = get_SpisokEdNAMEED , write = set_SpisokEdNAMEED};
   virtual TFIBWideStringField * get_SpisokEdNAMEED(void)=0;
   virtual void set_SpisokEdNAMEED(TFIBWideStringField * SpisokEdNAMEED)=0;

   __property __int64 IdNom = {read = get_IdNom , write = set_IdNom};
   virtual __int64 get_IdNom(void)=0;
   virtual void set_IdNom(__int64 IdNom)=0;

   __property __int64 IdTypePrice = {read = get_IdTypePrice , write = set_IdTypePrice};
   virtual __int64 get_IdTypePrice(void)=0;
   virtual void set_IdTypePrice(__int64 IdTypePrice)=0;

   __property __int64 IdBasEd = {read = get_IdBasEd , write = set_IdBasEd};
   virtual __int64 get_IdBasEd(void)=0;
   virtual void set_IdBasEd(__int64 IdBasEd)=0;

   virtual void OpenTable(__int64 id_nom)=0;
   virtual bool SaveIsmen(void)=0;
   virtual void CancelIsmen(void)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual void NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void DeleteElement(__int64 id)=0;
   virtual void UpdateSpisokEd(__int64 id_nom)=0;
   virtual double GetValuePrice(__int64 id_nom,	__int64 id_type_price,__int64 id_ed, TDateTime pos)=0;
};
#define IID_IDMSprPriceSchedule __uuidof(IDMSprPriceSchedule)
#endif
