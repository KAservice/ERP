#ifndef UIDMSprVesNomH
#define UIDMSprVesNomH
#include "IMainInterface.h"
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{063BD97E-195B-487C-A9AE-EBA4DC5A8972}")) IDMSprVesNom : public IMainInterface
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

   __property TFIBIntegerField * TableCODE_SVESNOM = {read = get_TableCODE_SVESNOM , write = set_TableCODE_SVESNOM};
   virtual TFIBIntegerField * get_TableCODE_SVESNOM(void)=0;
   virtual void set_TableCODE_SVESNOM(TFIBIntegerField * TableCODE_SVESNOM)=0;

   __property TFIBBCDField * TableZNACH_PRICE = {read = get_TableZNACH_PRICE , write = set_TableZNACH_PRICE};
   virtual TFIBBCDField * get_TableZNACH_PRICE(void)=0;
   virtual void set_TableZNACH_PRICE(TFIBBCDField * TableZNACH_PRICE)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBIntegerField * ElementCODE_SVESNOM = {read = get_ElementCODE_SVESNOM , write = set_ElementCODE_SVESNOM};
   virtual TFIBIntegerField * get_ElementCODE_SVESNOM(void)=0;
   virtual void set_ElementCODE_SVESNOM(TFIBIntegerField * ElementCODE_SVESNOM)=0;

   __property TpFIBDataSet * MaxCode = {read = get_MaxCode , write = set_MaxCode};
   virtual TpFIBDataSet * get_MaxCode(void)=0;
   virtual void set_MaxCode(TpFIBDataSet * MaxCode)=0;

   __property TpFIBDataSet * SpTPrice = {read = get_SpTPrice , write = set_SpTPrice};
   virtual TpFIBDataSet * get_SpTPrice(void)=0;
   virtual void set_SpTPrice(TpFIBDataSet * SpTPrice)=0;

   __property TFIBIntegerField * MaxCodeMAXCODE = {read = get_MaxCodeMAXCODE , write = set_MaxCodeMAXCODE};
   virtual TFIBIntegerField * get_MaxCodeMAXCODE(void)=0;
   virtual void set_MaxCodeMAXCODE(TFIBIntegerField * MaxCodeMAXCODE)=0;

   __property TFIBBCDField * SpTPriceID_TPRICE = {read = get_SpTPriceID_TPRICE , write = set_SpTPriceID_TPRICE};
   virtual TFIBBCDField * get_SpTPriceID_TPRICE(void)=0;
   virtual void set_SpTPriceID_TPRICE(TFIBBCDField * SpTPriceID_TPRICE)=0;

   __property TFIBBCDField * ElementID_SVESNOM = {read = get_ElementID_SVESNOM , write = set_ElementID_SVESNOM};
   virtual TFIBBCDField * get_ElementID_SVESNOM(void)=0;
   virtual void set_ElementID_SVESNOM(TFIBBCDField * ElementID_SVESNOM)=0;

   __property TFIBBCDField * ElementIDSCALE_SVESNOM = {read = get_ElementIDSCALE_SVESNOM , write = set_ElementIDSCALE_SVESNOM};
   virtual TFIBBCDField * get_ElementIDSCALE_SVESNOM(void)=0;
   virtual void set_ElementIDSCALE_SVESNOM(TFIBBCDField * ElementIDSCALE_SVESNOM)=0;

   __property TFIBBCDField * ElementIDNOM_SVESNOM = {read = get_ElementIDNOM_SVESNOM , write = set_ElementIDNOM_SVESNOM};
   virtual TFIBBCDField * get_ElementIDNOM_SVESNOM(void)=0;
   virtual void set_ElementIDNOM_SVESNOM(TFIBBCDField * ElementIDNOM_SVESNOM)=0;

   __property TFIBBCDField * TableID_SVESNOM = {read = get_TableID_SVESNOM , write = set_TableID_SVESNOM};
   virtual TFIBBCDField * get_TableID_SVESNOM(void)=0;
   virtual void set_TableID_SVESNOM(TFIBBCDField * TableID_SVESNOM)=0;

   __property TFIBBCDField * TableIDNOM_SVESNOM = {read = get_TableIDNOM_SVESNOM , write = set_TableIDNOM_SVESNOM};
   virtual TFIBBCDField * get_TableIDNOM_SVESNOM(void)=0;
   virtual void set_TableIDNOM_SVESNOM(TFIBBCDField * TableIDNOM_SVESNOM)=0;

   __property TFIBBCDField * TableIDSCALE_SVESNOM = {read = get_TableIDSCALE_SVESNOM , write = set_TableIDSCALE_SVESNOM};
   virtual TFIBBCDField * get_TableIDSCALE_SVESNOM(void)=0;
   virtual void set_TableIDSCALE_SVESNOM(TFIBBCDField * TableIDSCALE_SVESNOM)=0;

   __property TFIBBCDField * TableIDGRP_SVESNOM = {read = get_TableIDGRP_SVESNOM , write = set_TableIDGRP_SVESNOM};
   virtual TFIBBCDField * get_TableIDGRP_SVESNOM(void)=0;
   virtual void set_TableIDGRP_SVESNOM(TFIBBCDField * TableIDGRP_SVESNOM)=0;

   __property TFIBBCDField * ElementIDGRP_SVESNOM = {read = get_ElementIDGRP_SVESNOM , write = set_ElementIDGRP_SVESNOM};
   virtual TFIBBCDField * get_ElementIDGRP_SVESNOM(void)=0;
   virtual void set_ElementIDGRP_SVESNOM(TFIBBCDField * ElementIDGRP_SVESNOM)=0;

   __property TFIBWideStringField * TableGID_SVESNOM = {read = get_TableGID_SVESNOM , write = set_TableGID_SVESNOM};
   virtual TFIBWideStringField * get_TableGID_SVESNOM(void)=0;
   virtual void set_TableGID_SVESNOM(TFIBWideStringField * TableGID_SVESNOM)=0;

   __property TFIBBCDField * TableIDBASE_SVESNOM = {read = get_TableIDBASE_SVESNOM , write = set_TableIDBASE_SVESNOM};
   virtual TFIBBCDField * get_TableIDBASE_SVESNOM(void)=0;
   virtual void set_TableIDBASE_SVESNOM(TFIBBCDField * TableIDBASE_SVESNOM)=0;

   __property TFIBWideStringField * TableNAMENOM = {read = get_TableNAMENOM , write = set_TableNAMENOM};
   virtual TFIBWideStringField * get_TableNAMENOM(void)=0;
   virtual void set_TableNAMENOM(TFIBWideStringField * TableNAMENOM)=0;

   __property TFIBWideStringField * TableNAMEED = {read = get_TableNAMEED , write = set_TableNAMEED};
   virtual TFIBWideStringField * get_TableNAMEED(void)=0;
   virtual void set_TableNAMEED(TFIBWideStringField * TableNAMEED)=0;

   __property TFIBWideStringField * ElementGID_SVESNOM = {read = get_ElementGID_SVESNOM , write = set_ElementGID_SVESNOM};
   virtual TFIBWideStringField * get_ElementGID_SVESNOM(void)=0;
   virtual void set_ElementGID_SVESNOM(TFIBWideStringField * ElementGID_SVESNOM)=0;

   __property TFIBWideStringField * SpTPriceNAME_TPRICE = {read = get_SpTPriceNAME_TPRICE , write = set_SpTPriceNAME_TPRICE};
   virtual TFIBWideStringField * get_SpTPriceNAME_TPRICE(void)=0;
   virtual void set_SpTPriceNAME_TPRICE(TFIBWideStringField * SpTPriceNAME_TPRICE)=0;

   __property __int64 IdScale = {read = get_IdScale , write = set_IdScale};
   virtual __int64 get_IdScale(void)=0;
   virtual void set_IdScale(__int64 IdScale)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   __property __int64 IdTypePrice = {read = get_IdTypePrice , write = set_IdTypePrice};
   virtual __int64 get_IdTypePrice(void)=0;
   virtual void set_IdTypePrice(__int64 IdTypePrice)=0;

   __property int NumberAddElement = {read = get_NumberAddElement , write = set_NumberAddElement};
   virtual int get_NumberAddElement(void)=0;
   virtual void set_NumberAddElement(int NumberAddElement)=0;

   virtual void OpenTable(__int64 id_scale, __int64 id_grp, __int64 id_type_price, bool all)=0;
   virtual bool SaveIsmen()=0;
   virtual void CancelIsmen()=0;
   virtual void NewElement(__int64 id_scale, __int64 id_grp)=0;
   virtual bool OpenElement(__int64 id)=0;
   virtual void DeleteElement()=0;
   virtual bool InsertElement(__int64 id_scale, __int64 id_grp, __int64 id_nom)=0;
   virtual void ChancheGrp(__int64 id_new_grp)=0;
   virtual __int64 FindElementPoScaleAndNom(__int64 id_scale, __int64 id_nom)=0;
};
#define IID_IDMSprVesNom __uuidof(IDMSprVesNom)
#endif
