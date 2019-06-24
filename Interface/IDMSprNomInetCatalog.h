#ifndef UIDMSprNomInetCatalogH
#define UIDMSprNomInetCatalogH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprNomInetCatalog)) IDMSprNomInetCatalog : public IMainInterface
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

   __property TFIBLargeIntField * TableID_SNOMINETCAT = {read = get_TableID_SNOMINETCAT , write = set_TableID_SNOMINETCAT};
   virtual TFIBLargeIntField * get_TableID_SNOMINETCAT(void)=0;
   virtual void set_TableID_SNOMINETCAT(TFIBLargeIntField * TableID_SNOMINETCAT)=0;

   __property TFIBLargeIntField * TableIDBASE_SNOMINETCAT = {read = get_TableIDBASE_SNOMINETCAT , write = set_TableIDBASE_SNOMINETCAT};
   virtual TFIBLargeIntField * get_TableIDBASE_SNOMINETCAT(void)=0;
   virtual void set_TableIDBASE_SNOMINETCAT(TFIBLargeIntField * TableIDBASE_SNOMINETCAT)=0;

   __property TFIBWideStringField * TableGID_SNOMINETCAT = {read = get_TableGID_SNOMINETCAT , write = set_TableGID_SNOMINETCAT};
   virtual TFIBWideStringField * get_TableGID_SNOMINETCAT(void)=0;
   virtual void set_TableGID_SNOMINETCAT(TFIBWideStringField * TableGID_SNOMINETCAT)=0;

   __property TFIBLargeIntField * TableIDINETCAT_SNOMINETCAT = {read = get_TableIDINETCAT_SNOMINETCAT , write = set_TableIDINETCAT_SNOMINETCAT};
   virtual TFIBLargeIntField * get_TableIDINETCAT_SNOMINETCAT(void)=0;
   virtual void set_TableIDINETCAT_SNOMINETCAT(TFIBLargeIntField * TableIDINETCAT_SNOMINETCAT)=0;

   __property TFIBLargeIntField * TableIDGRP_SNOMINETCAT = {read = get_TableIDGRP_SNOMINETCAT , write = set_TableIDGRP_SNOMINETCAT};
   virtual TFIBLargeIntField * get_TableIDGRP_SNOMINETCAT(void)=0;
   virtual void set_TableIDGRP_SNOMINETCAT(TFIBLargeIntField * TableIDGRP_SNOMINETCAT)=0;

   __property TFIBLargeIntField * TableIDNOM_SNOMINETCAT = {read = get_TableIDNOM_SNOMINETCAT , write = set_TableIDNOM_SNOMINETCAT};
   virtual TFIBLargeIntField * get_TableIDNOM_SNOMINETCAT(void)=0;
   virtual void set_TableIDNOM_SNOMINETCAT(TFIBLargeIntField * TableIDNOM_SNOMINETCAT)=0;

   __property TFIBWideStringField * TableNAMENOM = {read = get_TableNAMENOM , write = set_TableNAMENOM};
   virtual TFIBWideStringField * get_TableNAMENOM(void)=0;
   virtual void set_TableNAMENOM(TFIBWideStringField * TableNAMENOM)=0;

   __property TFIBBCDField * TableZNACH_PRICE = {read = get_TableZNACH_PRICE , write = set_TableZNACH_PRICE};
   virtual TFIBBCDField * get_TableZNACH_PRICE(void)=0;
   virtual void set_TableZNACH_PRICE(TFIBBCDField * TableZNACH_PRICE)=0;

   __property TFIBWideStringField * TableNAMEED = {read = get_TableNAMEED , write = set_TableNAMEED};
   virtual TFIBWideStringField * get_TableNAMEED(void)=0;
   virtual void set_TableNAMEED(TFIBWideStringField * TableNAMEED)=0;

   __property TFIBLargeIntField * ElementID_SNOMINETCAT = {read = get_ElementID_SNOMINETCAT , write = set_ElementID_SNOMINETCAT};
   virtual TFIBLargeIntField * get_ElementID_SNOMINETCAT(void)=0;
   virtual void set_ElementID_SNOMINETCAT(TFIBLargeIntField * ElementID_SNOMINETCAT)=0;

   __property TFIBLargeIntField * ElementIDBASE_SNOMINETCAT = {read = get_ElementIDBASE_SNOMINETCAT , write = set_ElementIDBASE_SNOMINETCAT};
   virtual TFIBLargeIntField * get_ElementIDBASE_SNOMINETCAT(void)=0;
   virtual void set_ElementIDBASE_SNOMINETCAT(TFIBLargeIntField * ElementIDBASE_SNOMINETCAT)=0;

   __property TFIBWideStringField * ElementGID_SNOMINETCAT = {read = get_ElementGID_SNOMINETCAT , write = set_ElementGID_SNOMINETCAT};
   virtual TFIBWideStringField * get_ElementGID_SNOMINETCAT(void)=0;
   virtual void set_ElementGID_SNOMINETCAT(TFIBWideStringField * ElementGID_SNOMINETCAT)=0;

   __property TFIBLargeIntField * ElementIDINETCAT_SNOMINETCAT = {read = get_ElementIDINETCAT_SNOMINETCAT , write = set_ElementIDINETCAT_SNOMINETCAT};
   virtual TFIBLargeIntField * get_ElementIDINETCAT_SNOMINETCAT(void)=0;
   virtual void set_ElementIDINETCAT_SNOMINETCAT(TFIBLargeIntField * ElementIDINETCAT_SNOMINETCAT)=0;

   __property TFIBLargeIntField * ElementIDGRP_SNOMINETCAT = {read = get_ElementIDGRP_SNOMINETCAT , write = set_ElementIDGRP_SNOMINETCAT};
   virtual TFIBLargeIntField * get_ElementIDGRP_SNOMINETCAT(void)=0;
   virtual void set_ElementIDGRP_SNOMINETCAT(TFIBLargeIntField * ElementIDGRP_SNOMINETCAT)=0;

   __property TFIBLargeIntField * ElementIDNOM_SNOMINETCAT = {read = get_ElementIDNOM_SNOMINETCAT , write = set_ElementIDNOM_SNOMINETCAT};
   virtual TFIBLargeIntField * get_ElementIDNOM_SNOMINETCAT(void)=0;
   virtual void set_ElementIDNOM_SNOMINETCAT(TFIBLargeIntField * ElementIDNOM_SNOMINETCAT)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBIntegerField * TableCODENOM = {read = get_TableCODENOM , write = set_TableCODENOM};
   virtual TFIBIntegerField * get_TableCODENOM(void)=0;
   virtual void set_TableCODENOM(TFIBIntegerField * TableCODENOM)=0;

   __property TFIBWideStringField * TableARTNOM = {read = get_TableARTNOM , write = set_TableARTNOM};
   virtual TFIBWideStringField * get_TableARTNOM(void)=0;
   virtual void set_TableARTNOM(TFIBWideStringField * TableARTNOM)=0;

   __property TFIBWideStringField * TableSHED = {read = get_TableSHED , write = set_TableSHED};
   virtual TFIBWideStringField * get_TableSHED(void)=0;
   virtual void set_TableSHED(TFIBWideStringField * TableSHED)=0;

   __property __int64 IdInetCatalog = {read = get_IdInetCatalog , write = set_IdInetCatalog};
   virtual __int64 get_IdInetCatalog(void)=0;
   virtual void set_IdInetCatalog(__int64 IdInetCatalog)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   __property __int64 IdTypePrice = {read = get_IdTypePrice , write = set_IdTypePrice};
   virtual __int64 get_IdTypePrice(void)=0;
   virtual void set_IdTypePrice(__int64 IdTypePrice)=0;

   virtual void OpenTable(__int64 id_inet_catalog, __int64 id_grp,bool all)=0;
   virtual void NewElement(__int64 id_inet_catalog, __int64 id_grp)=0;
   virtual bool OpenElement(__int64 id)=0;
   virtual void InsertElement(__int64 id_inet_catalog, __int64 id_grp, __int64 id_nom)=0;
   virtual void DeleteElement()=0;
   virtual void SaveIsmen()=0;
   virtual void CancelIsmen()=0;
   virtual void ChancheGrp(__int64 id_new_grp)=0;
   virtual bool FindPoInetCatalogAndNom(__int64 id_inet_catalog, __int64 id_nom)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
};
#define IID_IDMSprNomInetCatalog __uuidof(IDMSprNomInetCatalog)
#endif
