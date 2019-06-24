#ifndef UIDMSprBVNomH
#define UIDMSprBVNomH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>
class __declspec(uuid("{47123947-5B76-4D18-B81E-AC6F1E44DCC9}")) IDMSprBVNom : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TDataSource * DataSourcePodr = {read = get_DataSourcePodr , write = set_DataSourcePodr};
   virtual TDataSource * get_DataSourcePodr(void)=0;
   virtual void set_DataSourcePodr(TDataSource * DataSourcePodr)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

   __property TpFIBDataSet * Podr = {read = get_Podr , write = set_Podr};
   virtual TpFIBDataSet * get_Podr(void)=0;
   virtual void set_Podr(TpFIBDataSet * Podr)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TFIBIntegerField * TableCODE_BVNOM = {read = get_TableCODE_BVNOM , write = set_TableCODE_BVNOM};
   virtual TFIBIntegerField * get_TableCODE_BVNOM(void)=0;
   virtual void set_TableCODE_BVNOM(TFIBIntegerField * TableCODE_BVNOM)=0;

   __property TFIBBCDField * TableZNACH_PRICE = {read = get_TableZNACH_PRICE , write = set_TableZNACH_PRICE};
   virtual TFIBBCDField * get_TableZNACH_PRICE(void)=0;
   virtual void set_TableZNACH_PRICE(TFIBBCDField * TableZNACH_PRICE)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TFIBIntegerField * ElementCODE_BVNOM = {read = get_ElementCODE_BVNOM , write = set_ElementCODE_BVNOM};
   virtual TFIBIntegerField * get_ElementCODE_BVNOM(void)=0;
   virtual void set_ElementCODE_BVNOM(TFIBIntegerField * ElementCODE_BVNOM)=0;

   __property TFIBBCDField * ElementID_BVNOM = {read = get_ElementID_BVNOM , write = set_ElementID_BVNOM};
   virtual TFIBBCDField * get_ElementID_BVNOM(void)=0;
   virtual void set_ElementID_BVNOM(TFIBBCDField * ElementID_BVNOM)=0;

   __property TFIBBCDField * ElementIDPOD_BVNOM = {read = get_ElementIDPOD_BVNOM , write = set_ElementIDPOD_BVNOM};
   virtual TFIBBCDField * get_ElementIDPOD_BVNOM(void)=0;
   virtual void set_ElementIDPOD_BVNOM(TFIBBCDField * ElementIDPOD_BVNOM)=0;

   __property TFIBBCDField * ElementIDNOM_BVNOM = {read = get_ElementIDNOM_BVNOM , write = set_ElementIDNOM_BVNOM};
   virtual TFIBBCDField * get_ElementIDNOM_BVNOM(void)=0;
   virtual void set_ElementIDNOM_BVNOM(TFIBBCDField * ElementIDNOM_BVNOM)=0;

   __property TFIBBCDField * ElementIDGRP_BVNOM = {read = get_ElementIDGRP_BVNOM , write = set_ElementIDGRP_BVNOM};
   virtual TFIBBCDField * get_ElementIDGRP_BVNOM(void)=0;
   virtual void set_ElementIDGRP_BVNOM(TFIBBCDField * ElementIDGRP_BVNOM)=0;

   __property TFIBBCDField * PodrIDPOD = {read = get_PodrIDPOD , write = set_PodrIDPOD};
   virtual TFIBBCDField * get_PodrIDPOD(void)=0;
   virtual void set_PodrIDPOD(TFIBBCDField * PodrIDPOD)=0;

   __property TFIBBCDField * PodrIDTPRICEPOD = {read = get_PodrIDTPRICEPOD , write = set_PodrIDTPRICEPOD};
   virtual TFIBBCDField * get_PodrIDTPRICEPOD(void)=0;
   virtual void set_PodrIDTPRICEPOD(TFIBBCDField * PodrIDTPRICEPOD)=0;

   __property TFIBBCDField * TableID_BVNOM = {read = get_TableID_BVNOM , write = set_TableID_BVNOM};
   virtual TFIBBCDField * get_TableID_BVNOM(void)=0;
   virtual void set_TableID_BVNOM(TFIBBCDField * TableID_BVNOM)=0;

   __property TFIBBCDField * TableIDPOD_BVNOM = {read = get_TableIDPOD_BVNOM , write = set_TableIDPOD_BVNOM};
   virtual TFIBBCDField * get_TableIDPOD_BVNOM(void)=0;
   virtual void set_TableIDPOD_BVNOM(TFIBBCDField * TableIDPOD_BVNOM)=0;

   __property TFIBBCDField * TableIDNOM_BVNOM = {read = get_TableIDNOM_BVNOM , write = set_TableIDNOM_BVNOM};
   virtual TFIBBCDField * get_TableIDNOM_BVNOM(void)=0;
   virtual void set_TableIDNOM_BVNOM(TFIBBCDField * TableIDNOM_BVNOM)=0;

   __property TFIBBCDField * TableIDGRP_BVNOM = {read = get_TableIDGRP_BVNOM , write = set_TableIDGRP_BVNOM};
   virtual TFIBBCDField * get_TableIDGRP_BVNOM(void)=0;
   virtual void set_TableIDGRP_BVNOM(TFIBBCDField * TableIDGRP_BVNOM)=0;

   __property TFIBWideStringField * TableGID_SBVNOM = {read = get_TableGID_SBVNOM , write = set_TableGID_SBVNOM};
   virtual TFIBWideStringField * get_TableGID_SBVNOM(void)=0;
   virtual void set_TableGID_SBVNOM(TFIBWideStringField * TableGID_SBVNOM)=0;

   __property TFIBWideStringField * TableNAMENOM = {read = get_TableNAMENOM , write = set_TableNAMENOM};
   virtual TFIBWideStringField * get_TableNAMENOM(void)=0;
   virtual void set_TableNAMENOM(TFIBWideStringField * TableNAMENOM)=0;

   __property TFIBWideStringField * TableNAMEED = {read = get_TableNAMEED , write = set_TableNAMEED};
   virtual TFIBWideStringField * get_TableNAMEED(void)=0;
   virtual void set_TableNAMEED(TFIBWideStringField * TableNAMEED)=0;

   __property TFIBWideStringField * PodrNAMEPOD = {read = get_PodrNAMEPOD , write = set_PodrNAMEPOD};
   virtual TFIBWideStringField * get_PodrNAMEPOD(void)=0;
   virtual void set_PodrNAMEPOD(TFIBWideStringField * PodrNAMEPOD)=0;

   __property TFIBWideStringField * PodrNAME_TPRICE = {read = get_PodrNAME_TPRICE , write = set_PodrNAME_TPRICE};
   virtual TFIBWideStringField * get_PodrNAME_TPRICE(void)=0;
   virtual void set_PodrNAME_TPRICE(TFIBWideStringField * PodrNAME_TPRICE)=0;

   __property TFIBWideStringField * ElementGID_SBVNOM = {read = get_ElementGID_SBVNOM , write = set_ElementGID_SBVNOM};
   virtual TFIBWideStringField * get_ElementGID_SBVNOM(void)=0;
   virtual void set_ElementGID_SBVNOM(TFIBWideStringField * ElementGID_SBVNOM)=0;

   __property __int64 IdPod = {read = get_IdPod , write = set_IdPod};
   virtual __int64 get_IdPod(void)=0;
   virtual void set_IdPod(__int64 IdPod)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   __property __int64 IdTypePrice = {read = get_IdTypePrice , write = set_IdTypePrice};
   virtual __int64 get_IdTypePrice(void)=0;
   virtual void set_IdTypePrice(__int64 IdTypePrice)=0;

   __property __int64 IdNomBV = {read = get_IdNomBV , write = set_IdNomBV};
   virtual __int64 get_IdNomBV(void)=0;
   virtual void set_IdNomBV(__int64 IdNomBV)=0;


   virtual void OpenTable(__int64 Pod, __int64 Grp,bool All)=0;
   virtual void NewElement(__int64 Pod, __int64 Grp)=0;
   virtual bool OpenElement(__int64 id)=0;
   virtual void InsertElement(__int64 Pod, __int64 Grp, __int64 id_nom)=0;
   virtual void DeleteElement()=0;
   virtual void SaveIsmen()=0;
   virtual void CancelIsmen()=0;
   virtual void ChancheGrp(__int64 id_new_grp)=0;
   virtual int FindPoCoduBV(int codeBV)=0;
   virtual bool FindPoPodrAndNom(__int64 id_podr, __int64 id_nom)=0;
};
#define IID_IDMSprBVNom __uuidof(IDMSprBVNom)
#endif
