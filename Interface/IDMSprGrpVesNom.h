#ifndef UIDMSprGrpVesNomH
#define UIDMSprGrpVesNomH
#include "IMainInterface.h"
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{AAEEF1E8-51BE-47FE-8A0B-6B30152EDB82}"))IDMSprGrpVesNom : public IMainInterface
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

   __property TFIBBCDField * TableID_SGRPVESNOM = {read = get_TableID_SGRPVESNOM , write = set_TableID_SGRPVESNOM};
   virtual TFIBBCDField * get_TableID_SGRPVESNOM(void)=0;
   virtual void set_TableID_SGRPVESNOM(TFIBBCDField * TableID_SGRPVESNOM)=0;

   __property TFIBBCDField * TableIDGRP_SGRPVESNOM = {read = get_TableIDGRP_SGRPVESNOM , write = set_TableIDGRP_SGRPVESNOM};
   virtual TFIBBCDField * get_TableIDGRP_SGRPVESNOM(void)=0;
   virtual void set_TableIDGRP_SGRPVESNOM(TFIBBCDField * TableIDGRP_SGRPVESNOM)=0;

   __property TFIBBCDField * TableIDBASE_SGRPVESNOM = {read = get_TableIDBASE_SGRPVESNOM , write = set_TableIDBASE_SGRPVESNOM};
   virtual TFIBBCDField * get_TableIDBASE_SGRPVESNOM(void)=0;
   virtual void set_TableIDBASE_SGRPVESNOM(TFIBBCDField * TableIDBASE_SGRPVESNOM)=0;

   __property TFIBBCDField * TableIDSCALE_SGRPVESNOM = {read = get_TableIDSCALE_SGRPVESNOM , write = set_TableIDSCALE_SGRPVESNOM};
   virtual TFIBBCDField * get_TableIDSCALE_SGRPVESNOM(void)=0;
   virtual void set_TableIDSCALE_SGRPVESNOM(TFIBBCDField * TableIDSCALE_SGRPVESNOM)=0;

   __property TFIBBCDField * ElementID_SGRPVESNOM = {read = get_ElementID_SGRPVESNOM , write = set_ElementID_SGRPVESNOM};
   virtual TFIBBCDField * get_ElementID_SGRPVESNOM(void)=0;
   virtual void set_ElementID_SGRPVESNOM(TFIBBCDField * ElementID_SGRPVESNOM)=0;

   __property TFIBBCDField * ElementIDGRP_SGRPVESNOM = {read = get_ElementIDGRP_SGRPVESNOM , write = set_ElementIDGRP_SGRPVESNOM};
   virtual TFIBBCDField * get_ElementIDGRP_SGRPVESNOM(void)=0;
   virtual void set_ElementIDGRP_SGRPVESNOM(TFIBBCDField * ElementIDGRP_SGRPVESNOM)=0;

   __property TFIBBCDField * ElementIDBASE_SGRPVESNOM = {read = get_ElementIDBASE_SGRPVESNOM , write = set_ElementIDBASE_SGRPVESNOM};
   virtual TFIBBCDField * get_ElementIDBASE_SGRPVESNOM(void)=0;
   virtual void set_ElementIDBASE_SGRPVESNOM(TFIBBCDField * ElementIDBASE_SGRPVESNOM)=0;

   __property TFIBBCDField * ElementIDSCALE_SGRPVESNOM = {read = get_ElementIDSCALE_SGRPVESNOM , write = set_ElementIDSCALE_SGRPVESNOM};
   virtual TFIBBCDField * get_ElementIDSCALE_SGRPVESNOM(void)=0;
   virtual void set_ElementIDSCALE_SGRPVESNOM(TFIBBCDField * ElementIDSCALE_SGRPVESNOM)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBWideStringField * TableNAME_SGRPVESNOM = {read = get_TableNAME_SGRPVESNOM , write = set_TableNAME_SGRPVESNOM};
   virtual TFIBWideStringField * get_TableNAME_SGRPVESNOM(void)=0;
   virtual void set_TableNAME_SGRPVESNOM(TFIBWideStringField * TableNAME_SGRPVESNOM)=0;

   __property TFIBWideStringField * ElementNAME_SGRPVESNOM = {read = get_ElementNAME_SGRPVESNOM , write = set_ElementNAME_SGRPVESNOM};
   virtual TFIBWideStringField * get_ElementNAME_SGRPVESNOM(void)=0;
   virtual void set_ElementNAME_SGRPVESNOM(TFIBWideStringField * ElementNAME_SGRPVESNOM)=0;

   __property __int64 IdScale = {read = get_IdScale , write = set_IdScale};
   virtual __int64 get_IdScale(void)=0;
   virtual void set_IdScale(__int64 IdScale)=0;

   virtual void OpenTable(__int64 id_scale)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual void NewElement(__int64 id_scale, __int64 id_grp)=0;
   virtual bool SaveElement(void)=0;
   virtual void DeleteElement(__int64 id)=0;
};
#define IID_IDMSprGrpVesNom __uuidof(IDMSprGrpVesNom)
#endif
