#ifndef UIDMSprNachislH
#define UIDMSprNachislH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprNachisl)) IDMSprNachisl : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

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

   __property TpFIBDataSet * TypeNachisl = {read = get_TypeNachisl , write = set_TypeNachisl};
   virtual TpFIBDataSet * get_TypeNachisl(void)=0;
   virtual void set_TypeNachisl(TpFIBDataSet * TypeNachisl)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBLargeIntField * TypeNachislID_STNACHISL = {read = get_TypeNachislID_STNACHISL , write = set_TypeNachislID_STNACHISL};
   virtual TFIBLargeIntField * get_TypeNachislID_STNACHISL(void)=0;
   virtual void set_TypeNachislID_STNACHISL(TFIBLargeIntField * TypeNachislID_STNACHISL)=0;

   __property TFIBWideStringField * TypeNachislNAME_STNACHISL = {read = get_TypeNachislNAME_STNACHISL , write = set_TypeNachislNAME_STNACHISL};
   virtual TFIBWideStringField * get_TypeNachislNAME_STNACHISL(void)=0;
   virtual void set_TypeNachislNAME_STNACHISL(TFIBWideStringField * TypeNachislNAME_STNACHISL)=0;

   __property TFIBLargeIntField * TableID_SNACHISL = {read = get_TableID_SNACHISL , write = set_TableID_SNACHISL};
   virtual TFIBLargeIntField * get_TableID_SNACHISL(void)=0;
   virtual void set_TableID_SNACHISL(TFIBLargeIntField * TableID_SNACHISL)=0;

   __property TFIBLargeIntField * TableIDBASE_SNACHISL = {read = get_TableIDBASE_SNACHISL , write = set_TableIDBASE_SNACHISL};
   virtual TFIBLargeIntField * get_TableIDBASE_SNACHISL(void)=0;
   virtual void set_TableIDBASE_SNACHISL(TFIBLargeIntField * TableIDBASE_SNACHISL)=0;

   __property TFIBWideStringField * TableGID_SNACHISL = {read = get_TableGID_SNACHISL , write = set_TableGID_SNACHISL};
   virtual TFIBWideStringField * get_TableGID_SNACHISL(void)=0;
   virtual void set_TableGID_SNACHISL(TFIBWideStringField * TableGID_SNACHISL)=0;

   __property TFIBLargeIntField * TableIDNOM_SNACHISL = {read = get_TableIDNOM_SNACHISL , write = set_TableIDNOM_SNACHISL};
   virtual TFIBLargeIntField * get_TableIDNOM_SNACHISL(void)=0;
   virtual void set_TableIDNOM_SNACHISL(TFIBLargeIntField * TableIDNOM_SNACHISL)=0;

   __property TFIBLargeIntField * TableIDTNACH_SNACHISL = {read = get_TableIDTNACH_SNACHISL , write = set_TableIDTNACH_SNACHISL};
   virtual TFIBLargeIntField * get_TableIDTNACH_SNACHISL(void)=0;
   virtual void set_TableIDTNACH_SNACHISL(TFIBLargeIntField * TableIDTNACH_SNACHISL)=0;

   __property TFIBBCDField * TableVALUE_SNACHISL = {read = get_TableVALUE_SNACHISL , write = set_TableVALUE_SNACHISL};
   virtual TFIBBCDField * get_TableVALUE_SNACHISL(void)=0;
   virtual void set_TableVALUE_SNACHISL(TFIBBCDField * TableVALUE_SNACHISL)=0;

   __property TFIBWideStringField * TableNAME_STNACHISL = {read = get_TableNAME_STNACHISL , write = set_TableNAME_STNACHISL};
   virtual TFIBWideStringField * get_TableNAME_STNACHISL(void)=0;
   virtual void set_TableNAME_STNACHISL(TFIBWideStringField * TableNAME_STNACHISL)=0;

   __property TStringField * TableNAME_TYPE_NACHISL_LOOKUP = {read = get_TableNAME_TYPE_NACHISL_LOOKUP , write = set_TableNAME_TYPE_NACHISL_LOOKUP};
   virtual TStringField * get_TableNAME_TYPE_NACHISL_LOOKUP(void)=0;
   virtual void set_TableNAME_TYPE_NACHISL_LOOKUP(TStringField * TableNAME_TYPE_NACHISL_LOOKUP)=0;

   __property TFIBBCDField * ElementID_SNACHISL = {read = get_ElementID_SNACHISL , write = set_ElementID_SNACHISL};
   virtual TFIBBCDField * get_ElementID_SNACHISL(void)=0;
   virtual void set_ElementID_SNACHISL(TFIBBCDField * ElementID_SNACHISL)=0;

   __property TFIBBCDField * ElementIDBASE_SNACHISL = {read = get_ElementIDBASE_SNACHISL , write = set_ElementIDBASE_SNACHISL};
   virtual TFIBBCDField * get_ElementIDBASE_SNACHISL(void)=0;
   virtual void set_ElementIDBASE_SNACHISL(TFIBBCDField * ElementIDBASE_SNACHISL)=0;

   __property TFIBWideStringField * ElementGID_SNACHISL = {read = get_ElementGID_SNACHISL , write = set_ElementGID_SNACHISL};
   virtual TFIBWideStringField * get_ElementGID_SNACHISL(void)=0;
   virtual void set_ElementGID_SNACHISL(TFIBWideStringField * ElementGID_SNACHISL)=0;

   __property TFIBBCDField * ElementIDNOM_SNACHISL = {read = get_ElementIDNOM_SNACHISL , write = set_ElementIDNOM_SNACHISL};
   virtual TFIBBCDField * get_ElementIDNOM_SNACHISL(void)=0;
   virtual void set_ElementIDNOM_SNACHISL(TFIBBCDField * ElementIDNOM_SNACHISL)=0;

   __property TFIBBCDField * ElementIDTNACH_SNACHISL = {read = get_ElementIDTNACH_SNACHISL , write = set_ElementIDTNACH_SNACHISL};
   virtual TFIBBCDField * get_ElementIDTNACH_SNACHISL(void)=0;
   virtual void set_ElementIDTNACH_SNACHISL(TFIBBCDField * ElementIDTNACH_SNACHISL)=0;

   __property TFIBBCDField * ElementVALUE_SNACHISL = {read = get_ElementVALUE_SNACHISL , write = set_ElementVALUE_SNACHISL};
   virtual TFIBBCDField * get_ElementVALUE_SNACHISL(void)=0;
   virtual void set_ElementVALUE_SNACHISL(TFIBBCDField * ElementVALUE_SNACHISL)=0;

   __property __int64 IdNom = {read = get_IdNom , write = set_IdNom};
   virtual __int64 get_IdNom(void)=0;
   virtual void set_IdNom(__int64 IdNom)=0;

   __property __int64 IdTypeNachisl = {read = get_IdTypeNachisl , write = set_IdTypeNachisl};
   virtual __int64 get_IdTypeNachisl(void)=0;
   virtual void set_IdTypeNachisl(__int64 IdTypeNachisl)=0;

   virtual void OpenTable(__int64 id_nom)=0;
   virtual bool SaveIsmen(void)=0;
   virtual void CancelIsmen(void)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual void NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void DeleteElement(__int64 id)=0;
   virtual __int64 FindElement(__int64 id_type_nachisl, __int64 id_nom)=0;
};
#define IID_IDMSprNachisl __uuidof(IDMSprNachisl)
#endif
