#ifndef UIDMSprBrandH
#define UIDMSprBrandH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{07D839AB-D977-4BE7-A836-B7438C61A12E}")) IDMSprBrand : public IMainInterface
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

   __property TFIBBCDField * TableID_SBRAND = {read = get_TableID_SBRAND , write = set_TableID_SBRAND};
   virtual TFIBBCDField * get_TableID_SBRAND(void)=0;
   virtual void set_TableID_SBRAND(TFIBBCDField * TableID_SBRAND)=0;

   __property TFIBBCDField * TableIDBASE_SBRAND = {read = get_TableIDBASE_SBRAND , write = set_TableIDBASE_SBRAND};
   virtual TFIBBCDField * get_TableIDBASE_SBRAND(void)=0;
   virtual void set_TableIDBASE_SBRAND(TFIBBCDField * TableIDBASE_SBRAND)=0;

   __property TFIBBCDField * ElementID_SBRAND = {read = get_ElementID_SBRAND , write = set_ElementID_SBRAND};
   virtual TFIBBCDField * get_ElementID_SBRAND(void)=0;
   virtual void set_ElementID_SBRAND(TFIBBCDField * ElementID_SBRAND)=0;

   __property TFIBBCDField * ElementIDBASE_SBRAND = {read = get_ElementIDBASE_SBRAND , write = set_ElementIDBASE_SBRAND};
   virtual TFIBBCDField * get_ElementIDBASE_SBRAND(void)=0;
   virtual void set_ElementIDBASE_SBRAND(TFIBBCDField * ElementIDBASE_SBRAND)=0;

   __property TFIBWideStringField * TableNAME_SBRAND = {read = get_TableNAME_SBRAND , write = set_TableNAME_SBRAND};
   virtual TFIBWideStringField * get_TableNAME_SBRAND(void)=0;
   virtual void set_TableNAME_SBRAND(TFIBWideStringField * TableNAME_SBRAND)=0;

   __property TFIBWideStringField * ElementNAME_SBRAND = {read = get_ElementNAME_SBRAND , write = set_ElementNAME_SBRAND};
   virtual TFIBWideStringField * get_ElementNAME_SBRAND(void)=0;
   virtual void set_ElementNAME_SBRAND(TFIBWideStringField * ElementNAME_SBRAND)=0;


   __property bool Error = {read = get_Error , write = set_Error};
   virtual bool get_Error(void)=0;
   virtual void set_Error(bool Error)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual void NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void CloseElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
};
#define IID_IDMSprBrand __uuidof(IDMSprBrand)
#endif
