#ifndef UIHOT_DMSprPrOsnUslugH
#define UIHOT_DMSprPrOsnUslugH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>
class __declspec(uuid("{3B8E6220-E120-4EB5-BD7F-E74C2FAFBB5F}")) IHOT_DMSprPrOsnUslug : public IMainInterface
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

   __property TpFIBQuery * Query = {read = get_Query , write = set_Query};
   virtual TpFIBQuery * get_Query(void)=0;
   virtual void set_Query(TpFIBQuery * Query)=0;

   __property TFIBBCDField * ElementID_HOT_SPROSNUSL = {read = get_ElementID_HOT_SPROSNUSL , write = set_ElementID_HOT_SPROSNUSL};
   virtual TFIBBCDField * get_ElementID_HOT_SPROSNUSL(void)=0;
   virtual void set_ElementID_HOT_SPROSNUSL(TFIBBCDField * ElementID_HOT_SPROSNUSL)=0;

   __property TFIBBCDField * ElementIDCAT_HOT_SPROSNUSL = {read = get_ElementIDCAT_HOT_SPROSNUSL , write = set_ElementIDCAT_HOT_SPROSNUSL};
   virtual TFIBBCDField * get_ElementIDCAT_HOT_SPROSNUSL(void)=0;
   virtual void set_ElementIDCAT_HOT_SPROSNUSL(TFIBBCDField * ElementIDCAT_HOT_SPROSNUSL)=0;

   __property TFIBBCDField * ElementIDNOMPR_HOT_SPROSNUSL = {read = get_ElementIDNOMPR_HOT_SPROSNUSL , write = set_ElementIDNOMPR_HOT_SPROSNUSL};
   virtual TFIBBCDField * get_ElementIDNOMPR_HOT_SPROSNUSL(void)=0;
   virtual void set_ElementIDNOMPR_HOT_SPROSNUSL(TFIBBCDField * ElementIDNOMPR_HOT_SPROSNUSL)=0;

   __property TFIBBCDField * ElementIDNOMBR_HOT_SPROSNUSL = {read = get_ElementIDNOMBR_HOT_SPROSNUSL , write = set_ElementIDNOMBR_HOT_SPROSNUSL};
   virtual TFIBBCDField * get_ElementIDNOMBR_HOT_SPROSNUSL(void)=0;
   virtual void set_ElementIDNOMBR_HOT_SPROSNUSL(TFIBBCDField * ElementIDNOMBR_HOT_SPROSNUSL)=0;

   __property TFIBBCDField * ElementIDTPOS_HOT_SPROSNUSL = {read = get_ElementIDTPOS_HOT_SPROSNUSL , write = set_ElementIDTPOS_HOT_SPROSNUSL};
   virtual TFIBBCDField * get_ElementIDTPOS_HOT_SPROSNUSL(void)=0;
   virtual void set_ElementIDTPOS_HOT_SPROSNUSL(TFIBBCDField * ElementIDTPOS_HOT_SPROSNUSL)=0;

   __property TFIBBCDField * TableID_HOT_SPROSNUSL = {read = get_TableID_HOT_SPROSNUSL , write = set_TableID_HOT_SPROSNUSL};
   virtual TFIBBCDField * get_TableID_HOT_SPROSNUSL(void)=0;
   virtual void set_TableID_HOT_SPROSNUSL(TFIBBCDField * TableID_HOT_SPROSNUSL)=0;

   __property TFIBBCDField * TableIDCAT_HOT_SPROSNUSL = {read = get_TableIDCAT_HOT_SPROSNUSL , write = set_TableIDCAT_HOT_SPROSNUSL};
   virtual TFIBBCDField * get_TableIDCAT_HOT_SPROSNUSL(void)=0;
   virtual void set_TableIDCAT_HOT_SPROSNUSL(TFIBBCDField * TableIDCAT_HOT_SPROSNUSL)=0;

   __property TFIBBCDField * TableIDNOMPR_HOT_SPROSNUSL = {read = get_TableIDNOMPR_HOT_SPROSNUSL , write = set_TableIDNOMPR_HOT_SPROSNUSL};
   virtual TFIBBCDField * get_TableIDNOMPR_HOT_SPROSNUSL(void)=0;
   virtual void set_TableIDNOMPR_HOT_SPROSNUSL(TFIBBCDField * TableIDNOMPR_HOT_SPROSNUSL)=0;

   __property TFIBBCDField * TableIDNOMBR_HOT_SPROSNUSL = {read = get_TableIDNOMBR_HOT_SPROSNUSL , write = set_TableIDNOMBR_HOT_SPROSNUSL};
   virtual TFIBBCDField * get_TableIDNOMBR_HOT_SPROSNUSL(void)=0;
   virtual void set_TableIDNOMBR_HOT_SPROSNUSL(TFIBBCDField * TableIDNOMBR_HOT_SPROSNUSL)=0;

   __property TFIBBCDField * TableIDTPOS_HOT_SPROSNUSL = {read = get_TableIDTPOS_HOT_SPROSNUSL , write = set_TableIDTPOS_HOT_SPROSNUSL};
   virtual TFIBBCDField * get_TableIDTPOS_HOT_SPROSNUSL(void)=0;
   virtual void set_TableIDTPOS_HOT_SPROSNUSL(TFIBBCDField * TableIDTPOS_HOT_SPROSNUSL)=0;

   __property TFIBBCDField * TableIDBASE_HOT_SPROSNUSL = {read = get_TableIDBASE_HOT_SPROSNUSL , write = set_TableIDBASE_HOT_SPROSNUSL};
   virtual TFIBBCDField * get_TableIDBASE_HOT_SPROSNUSL(void)=0;
   virtual void set_TableIDBASE_HOT_SPROSNUSL(TFIBBCDField * TableIDBASE_HOT_SPROSNUSL)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBWideStringField * TableNAME_HOT_SCATNOM = {read = get_TableNAME_HOT_SCATNOM , write = set_TableNAME_HOT_SCATNOM};
   virtual TFIBWideStringField * get_TableNAME_HOT_SCATNOM(void)=0;
   virtual void set_TableNAME_HOT_SCATNOM(TFIBWideStringField * TableNAME_HOT_SCATNOM)=0;

   __property TFIBWideStringField * TableNAME_HOT_STYPEPOS = {read = get_TableNAME_HOT_STYPEPOS , write = set_TableNAME_HOT_STYPEPOS};
   virtual TFIBWideStringField * get_TableNAME_HOT_STYPEPOS(void)=0;
   virtual void set_TableNAME_HOT_STYPEPOS(TFIBWideStringField * TableNAME_HOT_STYPEPOS)=0;

   __property TFIBWideStringField * TableNAMENOMPR = {read = get_TableNAMENOMPR , write = set_TableNAMENOMPR};
   virtual TFIBWideStringField * get_TableNAMENOMPR(void)=0;
   virtual void set_TableNAMENOMPR(TFIBWideStringField * TableNAMENOMPR)=0;

   __property TFIBWideStringField * TableNAMENOMBR = {read = get_TableNAMENOMBR , write = set_TableNAMENOMBR};
   virtual TFIBWideStringField * get_TableNAMENOMBR(void)=0;
   virtual void set_TableNAMENOMBR(TFIBWideStringField * TableNAMENOMBR)=0;

   __property TFIBWideStringField * ElementNAME_HOT_SCATNOM = {read = get_ElementNAME_HOT_SCATNOM , write = set_ElementNAME_HOT_SCATNOM};
   virtual TFIBWideStringField * get_ElementNAME_HOT_SCATNOM(void)=0;
   virtual void set_ElementNAME_HOT_SCATNOM(TFIBWideStringField * ElementNAME_HOT_SCATNOM)=0;

   __property TFIBWideStringField * ElementNAME_HOT_STYPEPOS = {read = get_ElementNAME_HOT_STYPEPOS , write = set_ElementNAME_HOT_STYPEPOS};
   virtual TFIBWideStringField * get_ElementNAME_HOT_STYPEPOS(void)=0;
   virtual void set_ElementNAME_HOT_STYPEPOS(TFIBWideStringField * ElementNAME_HOT_STYPEPOS)=0;

   __property TFIBWideStringField * ElementNAMENOMPR = {read = get_ElementNAMENOMPR , write = set_ElementNAMENOMPR};
   virtual TFIBWideStringField * get_ElementNAMENOMPR(void)=0;
   virtual void set_ElementNAMENOMPR(TFIBWideStringField * ElementNAMENOMPR)=0;

   __property TFIBWideStringField * ElementNAMENOMBR = {read = get_ElementNAMENOMBR , write = set_ElementNAMENOMBR};
   virtual TFIBWideStringField * get_ElementNAMENOMBR(void)=0;
   virtual void set_ElementNAMENOMBR(TFIBWideStringField * ElementNAMENOMBR)=0;

   __property __int64 IdNomBron = {read = get_IdNomBron , write = set_IdNomBron};
   virtual __int64 get_IdNomBron(void)=0;
   virtual void set_IdNomBron(__int64 IdNomBron)=0;

   __property __int64 IdNomProg = {read = get_IdNomProg , write = set_IdNomProg};
   virtual __int64 get_IdNomProg(void)=0;
   virtual void set_IdNomProg(__int64 IdNomProg)=0;

   virtual void OpenTable(void)=0;
   virtual void UpdateTable(void)=0;
   virtual int OpenElement(__int64 Id)=0;
   virtual bool NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void CloseElement(void)=0;
   virtual bool DeleteElement(__int64 Id)=0;
   virtual int GetIndexElementaPoID(__int64 id)=0;
   virtual void GetNomBronAndProg(__int64 id_cat,__int64 id_type_pos)=0;
};
#define IID_IHOT_DMSprPrOsnUslug __uuidof(IHOT_DMSprPrOsnUslug)
#endif
