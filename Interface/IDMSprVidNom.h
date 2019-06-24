#ifndef UIDMSprVidNomH
#define UIDMSprVidNomH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{B0C6EAFA-5851-481B-9670-D23BEF2FAA4E}"))IDMSprVidNom : public IMainInterface
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

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBBCDField * TableID_SVIDNOM = {read = get_TableID_SVIDNOM , write = set_TableID_SVIDNOM};
   virtual TFIBBCDField * get_TableID_SVIDNOM(void)=0;
   virtual void set_TableID_SVIDNOM(TFIBBCDField * TableID_SVIDNOM)=0;

   __property TFIBBCDField * ElementID_SVIDNOM = {read = get_ElementID_SVIDNOM , write = set_ElementID_SVIDNOM};
   virtual TFIBBCDField * get_ElementID_SVIDNOM(void)=0;
   virtual void set_ElementID_SVIDNOM(TFIBBCDField * ElementID_SVIDNOM)=0;

   __property TFIBWideStringField * TableGID_SVIDNOM = {read = get_TableGID_SVIDNOM , write = set_TableGID_SVIDNOM};
   virtual TFIBWideStringField * get_TableGID_SVIDNOM(void)=0;
   virtual void set_TableGID_SVIDNOM(TFIBWideStringField * TableGID_SVIDNOM)=0;

   __property TFIBWideStringField * TableNAME_SVIDNOM = {read = get_TableNAME_SVIDNOM , write = set_TableNAME_SVIDNOM};
   virtual TFIBWideStringField * get_TableNAME_SVIDNOM(void)=0;
   virtual void set_TableNAME_SVIDNOM(TFIBWideStringField * TableNAME_SVIDNOM)=0;

   __property TFIBWideStringField * ElementNAME_SVIDNOM = {read = get_ElementNAME_SVIDNOM , write = set_ElementNAME_SVIDNOM};
   virtual TFIBWideStringField * get_ElementNAME_SVIDNOM(void)=0;
   virtual void set_ElementNAME_SVIDNOM(TFIBWideStringField * ElementNAME_SVIDNOM)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 Id)=0;
   virtual bool NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual bool SaveIsmen(void)=0;
   virtual bool CancelIsmen(void)=0;
   virtual void CloseElement(void)=0;
   virtual bool DeleteElement(__int64 Id)=0;
   virtual int GetIndexElementaPoID(__int64 id)=0;
};
#define IID_IDMSprVidNom __uuidof(IDMSprVidNom)
#endif
