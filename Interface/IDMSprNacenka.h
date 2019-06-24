#ifndef UIDMSprNacenkaH
#define UIDMSprNacenkaH
#include "IMainInterface.h"
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{BEAB9A7A-5AA4-4B1B-BEE9-F4009F84EDA5}")) IDMSprNacenka : public IMainInterface
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

   __property TFIBBCDField * TableVALUE_SNACENKA = {read = get_TableVALUE_SNACENKA , write = set_TableVALUE_SNACENKA};
   virtual TFIBBCDField * get_TableVALUE_SNACENKA(void)=0;
   virtual void set_TableVALUE_SNACENKA(TFIBBCDField * TableVALUE_SNACENKA)=0;

   __property TFIBBCDField * ElementVALUE_SNACENKA = {read = get_ElementVALUE_SNACENKA , write = set_ElementVALUE_SNACENKA};
   virtual TFIBBCDField * get_ElementVALUE_SNACENKA(void)=0;
   virtual void set_ElementVALUE_SNACENKA(TFIBBCDField * ElementVALUE_SNACENKA)=0;

   __property TFIBIntegerField * TableOKR_SNACENKA = {read = get_TableOKR_SNACENKA , write = set_TableOKR_SNACENKA};
   virtual TFIBIntegerField * get_TableOKR_SNACENKA(void)=0;
   virtual void set_TableOKR_SNACENKA(TFIBIntegerField * TableOKR_SNACENKA)=0;

   __property TFIBIntegerField * ElementOKR_SNACENKA = {read = get_ElementOKR_SNACENKA , write = set_ElementOKR_SNACENKA};
   virtual TFIBIntegerField * get_ElementOKR_SNACENKA(void)=0;
   virtual void set_ElementOKR_SNACENKA(TFIBIntegerField * ElementOKR_SNACENKA)=0;

   __property TFIBBCDField * TableID_SNACENKA = {read = get_TableID_SNACENKA , write = set_TableID_SNACENKA};
   virtual TFIBBCDField * get_TableID_SNACENKA(void)=0;
   virtual void set_TableID_SNACENKA(TFIBBCDField * TableID_SNACENKA)=0;

   __property TFIBBCDField * TableIDGRPNOM_SNACENKA = {read = get_TableIDGRPNOM_SNACENKA , write = set_TableIDGRPNOM_SNACENKA};
   virtual TFIBBCDField * get_TableIDGRPNOM_SNACENKA(void)=0;
   virtual void set_TableIDGRPNOM_SNACENKA(TFIBBCDField * TableIDGRPNOM_SNACENKA)=0;

   __property TFIBBCDField * TableIDTPRICE_SNACENKA = {read = get_TableIDTPRICE_SNACENKA , write = set_TableIDTPRICE_SNACENKA};
   virtual TFIBBCDField * get_TableIDTPRICE_SNACENKA(void)=0;
   virtual void set_TableIDTPRICE_SNACENKA(TFIBBCDField * TableIDTPRICE_SNACENKA)=0;

   __property TFIBBCDField * ElementID_SNACENKA = {read = get_ElementID_SNACENKA , write = set_ElementID_SNACENKA};
   virtual TFIBBCDField * get_ElementID_SNACENKA(void)=0;
   virtual void set_ElementID_SNACENKA(TFIBBCDField * ElementID_SNACENKA)=0;

   __property TFIBBCDField * ElementIDGRPNOM_SNACENKA = {read = get_ElementIDGRPNOM_SNACENKA , write = set_ElementIDGRPNOM_SNACENKA};
   virtual TFIBBCDField * get_ElementIDGRPNOM_SNACENKA(void)=0;
   virtual void set_ElementIDGRPNOM_SNACENKA(TFIBBCDField * ElementIDGRPNOM_SNACENKA)=0;

   __property TFIBBCDField * ElementIDTPRICE_SNACENKA = {read = get_ElementIDTPRICE_SNACENKA , write = set_ElementIDTPRICE_SNACENKA};
   virtual TFIBBCDField * get_ElementIDTPRICE_SNACENKA(void)=0;
   virtual void set_ElementIDTPRICE_SNACENKA(TFIBBCDField * ElementIDTPRICE_SNACENKA)=0;

   __property TFIBWideStringField * TableGID_SNACENKA = {read = get_TableGID_SNACENKA , write = set_TableGID_SNACENKA};
   virtual TFIBWideStringField * get_TableGID_SNACENKA(void)=0;
   virtual void set_TableGID_SNACENKA(TFIBWideStringField * TableGID_SNACENKA)=0;

   __property TFIBBCDField * TableIDBASE_SNACENKA = {read = get_TableIDBASE_SNACENKA , write = set_TableIDBASE_SNACENKA};
   virtual TFIBBCDField * get_TableIDBASE_SNACENKA(void)=0;
   virtual void set_TableIDBASE_SNACENKA(TFIBBCDField * TableIDBASE_SNACENKA)=0;

   __property TFIBWideStringField * TableNAME_TPRICE = {read = get_TableNAME_TPRICE , write = set_TableNAME_TPRICE};
   virtual TFIBWideStringField * get_TableNAME_TPRICE(void)=0;
   virtual void set_TableNAME_TPRICE(TFIBWideStringField * TableNAME_TPRICE)=0;

   __property TFIBWideStringField * ElementGID_SNACENKA = {read = get_ElementGID_SNACENKA , write = set_ElementGID_SNACENKA};
   virtual TFIBWideStringField * get_ElementGID_SNACENKA(void)=0;
   virtual void set_ElementGID_SNACENKA(TFIBWideStringField * ElementGID_SNACENKA)=0;

   __property __int64 IdGrpNom = {read = get_IdGrpNom , write = set_IdGrpNom};
   virtual __int64 get_IdGrpNom(void)=0;
   virtual void set_IdGrpNom(__int64 IdGrpNom)=0;

   __property __int64 IdTypePrice = {read = get_IdTypePrice , write = set_IdTypePrice};
   virtual __int64 get_IdTypePrice(void)=0;
   virtual void set_IdTypePrice(__int64 IdTypePrice)=0;

   virtual void OpenTable(__int64 id_grp_nom)=0;
   virtual void SaveIsmen(void)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual void NewElement(void)=0;
   virtual void SaveElement(void)=0;
   virtual void DeleteElement(__int64 id)=0;
   virtual int FindElement(__int64 id_type_price, __int64 id_grp_nom)=0;
   virtual void CancelIsmen(void)=0;
};
#define IID_IDMSprNacenka __uuidof(IDMSprNacenka)
#endif
