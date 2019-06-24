#ifndef UIDMSprStorageLocationGrpH
#define UIDMSprStorageLocationGrpH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprStorageLocationGrp)) IDMSprStorageLocationGrp : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TDataSource * DataSourceElement = {read = get_DataSourceElement , write = set_DataSourceElement};
   virtual TDataSource * get_DataSourceElement(void)=0;
   virtual void set_DataSourceElement(TDataSource * DataSourceElement)=0;

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

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBLargeIntField * TableID_SMHRAN_GRP = {read = get_TableID_SMHRAN_GRP , write = set_TableID_SMHRAN_GRP};
   virtual TFIBLargeIntField * get_TableID_SMHRAN_GRP(void)=0;
   virtual void set_TableID_SMHRAN_GRP(TFIBLargeIntField * TableID_SMHRAN_GRP)=0;

   __property TFIBLargeIntField * TableIDBASE_SMHRAN_GRP = {read = get_TableIDBASE_SMHRAN_GRP , write = set_TableIDBASE_SMHRAN_GRP};
   virtual TFIBLargeIntField * get_TableIDBASE_SMHRAN_GRP(void)=0;
   virtual void set_TableIDBASE_SMHRAN_GRP(TFIBLargeIntField * TableIDBASE_SMHRAN_GRP)=0;

   __property TFIBLargeIntField * TableIDGRP_SMHRAN_GRP = {read = get_TableIDGRP_SMHRAN_GRP , write = set_TableIDGRP_SMHRAN_GRP};
   virtual TFIBLargeIntField * get_TableIDGRP_SMHRAN_GRP(void)=0;
   virtual void set_TableIDGRP_SMHRAN_GRP(TFIBLargeIntField * TableIDGRP_SMHRAN_GRP)=0;

   __property TFIBWideStringField * TableNAME_SMHRAN_GRP = {read = get_TableNAME_SMHRAN_GRP , write = set_TableNAME_SMHRAN_GRP};
   virtual TFIBWideStringField * get_TableNAME_SMHRAN_GRP(void)=0;
   virtual void set_TableNAME_SMHRAN_GRP(TFIBWideStringField * TableNAME_SMHRAN_GRP)=0;

   __property TFIBLargeIntField * TableIDSKLAD_SMHRAN_GRP = {read = get_TableIDSKLAD_SMHRAN_GRP , write = set_TableIDSKLAD_SMHRAN_GRP};
   virtual TFIBLargeIntField * get_TableIDSKLAD_SMHRAN_GRP(void)=0;
   virtual void set_TableIDSKLAD_SMHRAN_GRP(TFIBLargeIntField * TableIDSKLAD_SMHRAN_GRP)=0;

   __property TFIBLargeIntField * ElementID_SMHRAN_GRP = {read = get_ElementID_SMHRAN_GRP , write = set_ElementID_SMHRAN_GRP};
   virtual TFIBLargeIntField * get_ElementID_SMHRAN_GRP(void)=0;
   virtual void set_ElementID_SMHRAN_GRP(TFIBLargeIntField * ElementID_SMHRAN_GRP)=0;

   __property TFIBLargeIntField * ElementIDBASE_SMHRAN_GRP = {read = get_ElementIDBASE_SMHRAN_GRP , write = set_ElementIDBASE_SMHRAN_GRP};
   virtual TFIBLargeIntField * get_ElementIDBASE_SMHRAN_GRP(void)=0;
   virtual void set_ElementIDBASE_SMHRAN_GRP(TFIBLargeIntField * ElementIDBASE_SMHRAN_GRP)=0;

   __property TFIBLargeIntField * ElementIDGRP_SMHRAN_GRP = {read = get_ElementIDGRP_SMHRAN_GRP , write = set_ElementIDGRP_SMHRAN_GRP};
   virtual TFIBLargeIntField * get_ElementIDGRP_SMHRAN_GRP(void)=0;
   virtual void set_ElementIDGRP_SMHRAN_GRP(TFIBLargeIntField * ElementIDGRP_SMHRAN_GRP)=0;

   __property TFIBWideStringField * ElementNAME_SMHRAN_GRP = {read = get_ElementNAME_SMHRAN_GRP , write = set_ElementNAME_SMHRAN_GRP};
   virtual TFIBWideStringField * get_ElementNAME_SMHRAN_GRP(void)=0;
   virtual void set_ElementNAME_SMHRAN_GRP(TFIBWideStringField * ElementNAME_SMHRAN_GRP)=0;

   __property TFIBLargeIntField * ElementIDSKLAD_SMHRAN_GRP = {read = get_ElementIDSKLAD_SMHRAN_GRP , write = set_ElementIDSKLAD_SMHRAN_GRP};
   virtual TFIBLargeIntField * get_ElementIDSKLAD_SMHRAN_GRP(void)=0;
   virtual void set_ElementIDSKLAD_SMHRAN_GRP(TFIBLargeIntField * ElementIDSKLAD_SMHRAN_GRP)=0;

   __property __int64 IdSklad = {read = get_IdSklad , write = set_IdSklad};
   virtual __int64 get_IdSklad(void)=0;
   virtual void set_IdSklad(__int64 IdSklad)=0;

   virtual void OpenTable(__int64 id_sklad)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual void NewElement(__int64 id_sklad, __int64 id_grp)=0;
   virtual bool SaveElement(void)=0;
   virtual void DeleteElement(__int64 id)=0;
};
#define IID_IDMSprStorageLocationGrp __uuidof(IDMSprStorageLocationGrp)
#endif
