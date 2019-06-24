#ifndef UIDMSprVidKlientH
#define UIDMSprVidKlientH
#include "IMainInterface.h"
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{B067C0FB-1CD6-4A04-A70D-BED9A57D32CB}")) IDMSprVidKlient : public IMainInterface
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

   __property TFIBBCDField * TableID_SVIDKLIENT = {read = get_TableID_SVIDKLIENT , write = set_TableID_SVIDKLIENT};
   virtual TFIBBCDField * get_TableID_SVIDKLIENT(void)=0;
   virtual void set_TableID_SVIDKLIENT(TFIBBCDField * TableID_SVIDKLIENT)=0;

   __property TFIBBCDField * ElementID_SVIDKLIENT = {read = get_ElementID_SVIDKLIENT , write = set_ElementID_SVIDKLIENT};
   virtual TFIBBCDField * get_ElementID_SVIDKLIENT(void)=0;
   virtual void set_ElementID_SVIDKLIENT(TFIBBCDField * ElementID_SVIDKLIENT)=0;

   __property TFIBWideStringField * TableGID_SVIDKLIENT = {read = get_TableGID_SVIDKLIENT , write = set_TableGID_SVIDKLIENT};
   virtual TFIBWideStringField * get_TableGID_SVIDKLIENT(void)=0;
   virtual void set_TableGID_SVIDKLIENT(TFIBWideStringField * TableGID_SVIDKLIENT)=0;

   __property TFIBWideStringField * TableNAME_SVIDKLIENT = {read = get_TableNAME_SVIDKLIENT , write = set_TableNAME_SVIDKLIENT};
   virtual TFIBWideStringField * get_TableNAME_SVIDKLIENT(void)=0;
   virtual void set_TableNAME_SVIDKLIENT(TFIBWideStringField * TableNAME_SVIDKLIENT)=0;

   __property TFIBWideStringField * ElementGID_SVIDKLIENT = {read = get_ElementGID_SVIDKLIENT , write = set_ElementGID_SVIDKLIENT};
   virtual TFIBWideStringField * get_ElementGID_SVIDKLIENT(void)=0;
   virtual void set_ElementGID_SVIDKLIENT(TFIBWideStringField * ElementGID_SVIDKLIENT)=0;

   __property TFIBWideStringField * ElementNAME_SVIDKLIENT = {read = get_ElementNAME_SVIDKLIENT , write = set_ElementNAME_SVIDKLIENT};
   virtual TFIBWideStringField * get_ElementNAME_SVIDKLIENT(void)=0;
   virtual void set_ElementNAME_SVIDKLIENT(TFIBWideStringField * ElementNAME_SVIDKLIENT)=0;

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
#define IID_IDMSprVidKlient __uuidof(IDMSprVidKlient)
#endif
