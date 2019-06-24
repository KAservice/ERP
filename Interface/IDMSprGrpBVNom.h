#ifndef UIDMSprGrpBVNomH
#define UIDMSprGrpBVNomH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>
class __declspec(uuid("{D96F7548-14CC-481C-958A-D3CC8CEA8628}")) IDMSprGrpBVNom : public IMainInterface
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

   __property TFIBBCDField * TableID_GBVNOM = {read = get_TableID_GBVNOM , write = set_TableID_GBVNOM};
   virtual TFIBBCDField * get_TableID_GBVNOM(void)=0;
   virtual void set_TableID_GBVNOM(TFIBBCDField * TableID_GBVNOM)=0;

   __property TFIBBCDField * TableIDGRP_GBVNOM = {read = get_TableIDGRP_GBVNOM , write = set_TableIDGRP_GBVNOM};
   virtual TFIBBCDField * get_TableIDGRP_GBVNOM(void)=0;
   virtual void set_TableIDGRP_GBVNOM(TFIBBCDField * TableIDGRP_GBVNOM)=0;

   __property TFIBBCDField * TableIDPOD_GBVNOM = {read = get_TableIDPOD_GBVNOM , write = set_TableIDPOD_GBVNOM};
   virtual TFIBBCDField * get_TableIDPOD_GBVNOM(void)=0;
   virtual void set_TableIDPOD_GBVNOM(TFIBBCDField * TableIDPOD_GBVNOM)=0;

   __property TFIBBCDField * ElementID_GBVNOM = {read = get_ElementID_GBVNOM , write = set_ElementID_GBVNOM};
   virtual TFIBBCDField * get_ElementID_GBVNOM(void)=0;
   virtual void set_ElementID_GBVNOM(TFIBBCDField * ElementID_GBVNOM)=0;

   __property TFIBBCDField * ElementIDGRP_GBVNOM = {read = get_ElementIDGRP_GBVNOM , write = set_ElementIDGRP_GBVNOM};
   virtual TFIBBCDField * get_ElementIDGRP_GBVNOM(void)=0;
   virtual void set_ElementIDGRP_GBVNOM(TFIBBCDField * ElementIDGRP_GBVNOM)=0;

   __property TFIBBCDField * ElementIDPOD_GBVNOM = {read = get_ElementIDPOD_GBVNOM , write = set_ElementIDPOD_GBVNOM};
   virtual TFIBBCDField * get_ElementIDPOD_GBVNOM(void)=0;
   virtual void set_ElementIDPOD_GBVNOM(TFIBBCDField * ElementIDPOD_GBVNOM)=0;

   __property TFIBWideStringField * TableNAME_GBVNOM = {read = get_TableNAME_GBVNOM , write = set_TableNAME_GBVNOM};
   virtual TFIBWideStringField * get_TableNAME_GBVNOM(void)=0;
   virtual void set_TableNAME_GBVNOM(TFIBWideStringField * TableNAME_GBVNOM)=0;

   __property TFIBWideStringField * TableGID_SGBVNOM = {read = get_TableGID_SGBVNOM , write = set_TableGID_SGBVNOM};
   virtual TFIBWideStringField * get_TableGID_SGBVNOM(void)=0;
   virtual void set_TableGID_SGBVNOM(TFIBWideStringField * TableGID_SGBVNOM)=0;

   __property TFIBWideStringField * ElementNAME_GBVNOM = {read = get_ElementNAME_GBVNOM , write = set_ElementNAME_GBVNOM};
   virtual TFIBWideStringField * get_ElementNAME_GBVNOM(void)=0;
   virtual void set_ElementNAME_GBVNOM(TFIBWideStringField * ElementNAME_GBVNOM)=0;

   __property TFIBWideStringField * ElementGID_SGBVNOM = {read = get_ElementGID_SGBVNOM , write = set_ElementGID_SGBVNOM};
   virtual TFIBWideStringField * get_ElementGID_SGBVNOM(void)=0;
   virtual void set_ElementGID_SGBVNOM(TFIBWideStringField * ElementGID_SGBVNOM)=0;

   __property __int64 IdPod = {read = get_IdPod , write = set_IdPod};
   virtual __int64 get_IdPod(void)=0;
   virtual void set_IdPod(__int64 IdPod)=0;

   virtual void OpenTable(__int64 Pod)=0;
   virtual int OpenElement(__int64 Id)=0;
   virtual void NewElement(__int64 Pod, __int64 Grp)=0;
   virtual bool SaveElement(void)=0;
   virtual void DeleteElement(__int64 Id)=0;
};
#define IID_IDMSprGrpBVNom __uuidof(IDMSprGrpBVNom)
#endif
