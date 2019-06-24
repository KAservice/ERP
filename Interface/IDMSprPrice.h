#ifndef UIDMSprPriceH
#define UIDMSprPriceH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>
class __declspec(uuid("{36760A67-A4E1-4E6C-A3D3-13FA07E950F5}")) IDMSprPrice : public IMainInterface
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

   __property TFIBBCDField * TableZNACH_PRICE = {read = get_TableZNACH_PRICE , write = set_TableZNACH_PRICE};
   virtual TFIBBCDField * get_TableZNACH_PRICE(void)=0;
   virtual void set_TableZNACH_PRICE(TFIBBCDField * TableZNACH_PRICE)=0;

   __property TFIBBCDField * ElementZNACH_PRICE = {read = get_ElementZNACH_PRICE , write = set_ElementZNACH_PRICE};
   virtual TFIBBCDField * get_ElementZNACH_PRICE(void)=0;
   virtual void set_ElementZNACH_PRICE(TFIBBCDField * ElementZNACH_PRICE)=0;

   __property TpFIBDataSet * TPrice = {read = get_TPrice , write = set_TPrice};
   virtual TpFIBDataSet * get_TPrice(void)=0;
   virtual void set_TPrice(TpFIBDataSet * TPrice)=0;

   __property TFIBSmallIntField * TableFL_CHANGE_PRICE = {read = get_TableFL_CHANGE_PRICE , write = set_TableFL_CHANGE_PRICE};
   virtual TFIBSmallIntField * get_TableFL_CHANGE_PRICE(void)=0;
   virtual void set_TableFL_CHANGE_PRICE(TFIBSmallIntField * TableFL_CHANGE_PRICE)=0;

   __property TFIBSmallIntField * ElementFL_CHANGE_PRICE = {read = get_ElementFL_CHANGE_PRICE , write = set_ElementFL_CHANGE_PRICE};
   virtual TFIBSmallIntField * get_ElementFL_CHANGE_PRICE(void)=0;
   virtual void set_ElementFL_CHANGE_PRICE(TFIBSmallIntField * ElementFL_CHANGE_PRICE)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBBCDField * ElementID_PRICE = {read = get_ElementID_PRICE , write = set_ElementID_PRICE};
   virtual TFIBBCDField * get_ElementID_PRICE(void)=0;
   virtual void set_ElementID_PRICE(TFIBBCDField * ElementID_PRICE)=0;

   __property TFIBBCDField * ElementIDNOM_PRICE = {read = get_ElementIDNOM_PRICE , write = set_ElementIDNOM_PRICE};
   virtual TFIBBCDField * get_ElementIDNOM_PRICE(void)=0;
   virtual void set_ElementIDNOM_PRICE(TFIBBCDField * ElementIDNOM_PRICE)=0;

   __property TFIBBCDField * ElementIDTYPE_PRICE = {read = get_ElementIDTYPE_PRICE , write = set_ElementIDTYPE_PRICE};
   virtual TFIBBCDField * get_ElementIDTYPE_PRICE(void)=0;
   virtual void set_ElementIDTYPE_PRICE(TFIBBCDField * ElementIDTYPE_PRICE)=0;

   __property TFIBBCDField * ElementIDED_SPRICE = {read = get_ElementIDED_SPRICE , write = set_ElementIDED_SPRICE};
   virtual TFIBBCDField * get_ElementIDED_SPRICE(void)=0;
   virtual void set_ElementIDED_SPRICE(TFIBBCDField * ElementIDED_SPRICE)=0;

   __property TpFIBDataSet * SpisokEd = {read = get_SpisokEd , write = set_SpisokEd};
   virtual TpFIBDataSet * get_SpisokEd(void)=0;
   virtual void set_SpisokEd(TpFIBDataSet * SpisokEd)=0;

   __property TFIBBCDField * SpisokEdKFED = {read = get_SpisokEdKFED , write = set_SpisokEdKFED};
   virtual TFIBBCDField * get_SpisokEdKFED(void)=0;
   virtual void set_SpisokEdKFED(TFIBBCDField * SpisokEdKFED)=0;

   __property TDataSource * DataSourceSpisokEd = {read = get_DataSourceSpisokEd , write = set_DataSourceSpisokEd};
   virtual TDataSource * get_DataSourceSpisokEd(void)=0;
   virtual void set_DataSourceSpisokEd(TDataSource * DataSourceSpisokEd)=0;

   __property TFIBLargeIntField * TPriceID_TPRICE = {read = get_TPriceID_TPRICE , write = set_TPriceID_TPRICE};
   virtual TFIBLargeIntField * get_TPriceID_TPRICE(void)=0;
   virtual void set_TPriceID_TPRICE(TFIBLargeIntField * TPriceID_TPRICE)=0;

   __property TFIBLargeIntField * TableID_PRICE = {read = get_TableID_PRICE , write = set_TableID_PRICE};
   virtual TFIBLargeIntField * get_TableID_PRICE(void)=0;
   virtual void set_TableID_PRICE(TFIBLargeIntField * TableID_PRICE)=0;

   __property TFIBLargeIntField * TableIDNOM_PRICE = {read = get_TableIDNOM_PRICE , write = set_TableIDNOM_PRICE};
   virtual TFIBLargeIntField * get_TableIDNOM_PRICE(void)=0;
   virtual void set_TableIDNOM_PRICE(TFIBLargeIntField * TableIDNOM_PRICE)=0;

   __property TFIBLargeIntField * TableIDTYPE_PRICE = {read = get_TableIDTYPE_PRICE , write = set_TableIDTYPE_PRICE};
   virtual TFIBLargeIntField * get_TableIDTYPE_PRICE(void)=0;
   virtual void set_TableIDTYPE_PRICE(TFIBLargeIntField * TableIDTYPE_PRICE)=0;

   __property TFIBLargeIntField * TableIDED_SPRICE = {read = get_TableIDED_SPRICE , write = set_TableIDED_SPRICE};
   virtual TFIBLargeIntField * get_TableIDED_SPRICE(void)=0;
   virtual void set_TableIDED_SPRICE(TFIBLargeIntField * TableIDED_SPRICE)=0;

   __property TFIBLargeIntField * SpisokEdIDED = {read = get_SpisokEdIDED , write = set_SpisokEdIDED};
   virtual TFIBLargeIntField * get_SpisokEdIDED(void)=0;
   virtual void set_SpisokEdIDED(TFIBLargeIntField * SpisokEdIDED)=0;

   __property TFIBWideStringField * TableGID_SPRICE = {read = get_TableGID_SPRICE , write = set_TableGID_SPRICE};
   virtual TFIBWideStringField * get_TableGID_SPRICE(void)=0;
   virtual void set_TableGID_SPRICE(TFIBWideStringField * TableGID_SPRICE)=0;

   __property TFIBLargeIntField * TableIDBASE_SPRICE = {read = get_TableIDBASE_SPRICE , write = set_TableIDBASE_SPRICE};
   virtual TFIBLargeIntField * get_TableIDBASE_SPRICE(void)=0;
   virtual void set_TableIDBASE_SPRICE(TFIBLargeIntField * TableIDBASE_SPRICE)=0;

   __property TFIBWideStringField * TableNAME_TPRICE = {read = get_TableNAME_TPRICE , write = set_TableNAME_TPRICE};
   virtual TFIBWideStringField * get_TableNAME_TPRICE(void)=0;
   virtual void set_TableNAME_TPRICE(TFIBWideStringField * TableNAME_TPRICE)=0;

   __property TFIBWideStringField * ElementGID_SPRICE = {read = get_ElementGID_SPRICE , write = set_ElementGID_SPRICE};
   virtual TFIBWideStringField * get_ElementGID_SPRICE(void)=0;
   virtual void set_ElementGID_SPRICE(TFIBWideStringField * ElementGID_SPRICE)=0;

   __property TFIBWideStringField * TPriceNAME_TPRICE = {read = get_TPriceNAME_TPRICE , write = set_TPriceNAME_TPRICE};
   virtual TFIBWideStringField * get_TPriceNAME_TPRICE(void)=0;
   virtual void set_TPriceNAME_TPRICE(TFIBWideStringField * TPriceNAME_TPRICE)=0;

   __property TFIBWideStringField * SpisokEdNAMEED = {read = get_SpisokEdNAMEED , write = set_SpisokEdNAMEED};
   virtual TFIBWideStringField * get_SpisokEdNAMEED(void)=0;
   virtual void set_SpisokEdNAMEED(TFIBWideStringField * SpisokEdNAMEED)=0;

   __property TStringField * TableNAMETPRICE = {read = get_TableNAMETPRICE , write = set_TableNAMETPRICE};
   virtual TStringField * get_TableNAMETPRICE(void)=0;
   virtual void set_TableNAMETPRICE(TStringField * TableNAMETPRICE)=0;

   __property __int64 IdNom = {read = get_IdNom , write = set_IdNom};
   virtual __int64 get_IdNom(void)=0;
   virtual void set_IdNom(__int64 IdNom)=0;

   __property __int64 IdTypePrice = {read = get_IdTypePrice , write = set_IdTypePrice};
   virtual __int64 get_IdTypePrice(void)=0;
   virtual void set_IdTypePrice(__int64 IdTypePrice)=0;

   __property __int64 IdBasEd = {read = get_IdBasEd , write = set_IdBasEd};
   virtual __int64 get_IdBasEd(void)=0;
   virtual void set_IdBasEd(__int64 IdBasEd)=0;

   virtual void OpenTable(__int64 IdNom)=0;
   virtual bool SaveIsmen(void)=0;
   virtual void CancelIsmen(void)=0;
   virtual int OpenElement(__int64 Id)=0;
   virtual void NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void DeleteElement(__int64 Id)=0;
   virtual __int64 FindElement(__int64 idTypePrice, __int64 idNom)=0;
   virtual __int64 FindElementPoEd(__int64 idTypePrice, __int64 idNom, __int64 id_ed)=0;
   virtual double GetValuePrice(__int64 id_type_price,__int64 id_nom,__int64 id_ed,double kf_ed,__int64 id_bas_ed)=0;
   virtual void UpdateSpisokEd(__int64 id_nom)=0;
};
#define IID_IDMSprPrice __uuidof(IDMSprPrice)
#endif
