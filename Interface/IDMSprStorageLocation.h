#ifndef UIDMSprStorageLocationH
#define UIDMSprStorageLocationH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprStorageLocation)) IDMSprStorageLocation : public IMainInterface
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

   __property TFIBLargeIntField * TableID_SMHRAN = {read = get_TableID_SMHRAN , write = set_TableID_SMHRAN};
   virtual TFIBLargeIntField * get_TableID_SMHRAN(void)=0;
   virtual void set_TableID_SMHRAN(TFIBLargeIntField * TableID_SMHRAN)=0;

   __property TFIBLargeIntField * TableIDBASE_SMHRAN = {read = get_TableIDBASE_SMHRAN , write = set_TableIDBASE_SMHRAN};
   virtual TFIBLargeIntField * get_TableIDBASE_SMHRAN(void)=0;
   virtual void set_TableIDBASE_SMHRAN(TFIBLargeIntField * TableIDBASE_SMHRAN)=0;

   __property TFIBLargeIntField * TableIDGRP_SMHRAN = {read = get_TableIDGRP_SMHRAN , write = set_TableIDGRP_SMHRAN};
   virtual TFIBLargeIntField * get_TableIDGRP_SMHRAN(void)=0;
   virtual void set_TableIDGRP_SMHRAN(TFIBLargeIntField * TableIDGRP_SMHRAN)=0;

   __property TFIBWideStringField * TableNAME_SMHRAN = {read = get_TableNAME_SMHRAN , write = set_TableNAME_SMHRAN};
   virtual TFIBWideStringField * get_TableNAME_SMHRAN(void)=0;
   virtual void set_TableNAME_SMHRAN(TFIBWideStringField * TableNAME_SMHRAN)=0;

   __property TFIBLargeIntField * TableIDSKLAD_SMHRAN = {read = get_TableIDSKLAD_SMHRAN , write = set_TableIDSKLAD_SMHRAN};
   virtual TFIBLargeIntField * get_TableIDSKLAD_SMHRAN(void)=0;
   virtual void set_TableIDSKLAD_SMHRAN(TFIBLargeIntField * TableIDSKLAD_SMHRAN)=0;

   __property TFIBSmallIntField * TableFL_DOSTUPNO_SMHRAN = {read = get_TableFL_DOSTUPNO_SMHRAN , write = set_TableFL_DOSTUPNO_SMHRAN};
   virtual TFIBSmallIntField * get_TableFL_DOSTUPNO_SMHRAN(void)=0;
   virtual void set_TableFL_DOSTUPNO_SMHRAN(TFIBSmallIntField * TableFL_DOSTUPNO_SMHRAN)=0;

   __property TDataSource * DataSourceElement = {read = get_DataSourceElement , write = set_DataSourceElement};
   virtual TDataSource * get_DataSourceElement(void)=0;
   virtual void set_DataSourceElement(TDataSource * DataSourceElement)=0;

   __property TFIBLargeIntField * ElementID_SMHRAN = {read = get_ElementID_SMHRAN , write = set_ElementID_SMHRAN};
   virtual TFIBLargeIntField * get_ElementID_SMHRAN(void)=0;
   virtual void set_ElementID_SMHRAN(TFIBLargeIntField * ElementID_SMHRAN)=0;

   __property TFIBLargeIntField * ElementIDBASE_SMHRAN = {read = get_ElementIDBASE_SMHRAN , write = set_ElementIDBASE_SMHRAN};
   virtual TFIBLargeIntField * get_ElementIDBASE_SMHRAN(void)=0;
   virtual void set_ElementIDBASE_SMHRAN(TFIBLargeIntField * ElementIDBASE_SMHRAN)=0;

   __property TFIBLargeIntField * ElementIDGRP_SMHRAN = {read = get_ElementIDGRP_SMHRAN , write = set_ElementIDGRP_SMHRAN};
   virtual TFIBLargeIntField * get_ElementIDGRP_SMHRAN(void)=0;
   virtual void set_ElementIDGRP_SMHRAN(TFIBLargeIntField * ElementIDGRP_SMHRAN)=0;

   __property TFIBWideStringField * ElementNAME_SMHRAN = {read = get_ElementNAME_SMHRAN , write = set_ElementNAME_SMHRAN};
   virtual TFIBWideStringField * get_ElementNAME_SMHRAN(void)=0;
   virtual void set_ElementNAME_SMHRAN(TFIBWideStringField * ElementNAME_SMHRAN)=0;

   __property TFIBLargeIntField * ElementIDSKLAD_SMHRAN = {read = get_ElementIDSKLAD_SMHRAN , write = set_ElementIDSKLAD_SMHRAN};
   virtual TFIBLargeIntField * get_ElementIDSKLAD_SMHRAN(void)=0;
   virtual void set_ElementIDSKLAD_SMHRAN(TFIBLargeIntField * ElementIDSKLAD_SMHRAN)=0;

   __property TFIBSmallIntField * ElementFL_DOSTUPNO_SMHRAN = {read = get_ElementFL_DOSTUPNO_SMHRAN , write = set_ElementFL_DOSTUPNO_SMHRAN};
   virtual TFIBSmallIntField * get_ElementFL_DOSTUPNO_SMHRAN(void)=0;
   virtual void set_ElementFL_DOSTUPNO_SMHRAN(TFIBSmallIntField * ElementFL_DOSTUPNO_SMHRAN)=0;

   __property __int64 IdSklad = {read = get_IdSklad , write = set_IdSklad};
   virtual __int64 get_IdSklad(void)=0;
   virtual void set_IdSklad(__int64 IdSklad)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   virtual bool OpenTable(__int64 id_sklad, __int64 id_grp,bool all)=0;
   virtual bool NewElement(__int64 id_sklad, __int64 id_grp)=0;
   virtual bool OpenElement(__int64 id)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual bool ChangeGrp(__int64 id_new_grp,__int64 id_mhran)=0;
   virtual bool SaveElement(void)=0;
};
#define IID_IDMSprStorageLocation __uuidof(IDMSprStorageLocation)
#endif
