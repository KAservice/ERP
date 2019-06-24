#ifndef UIDMSprEdH
#define UIDMSprEdH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>
class __declspec(uuid("{6DA820A2-6569-44C4-850B-A426D69728D6}")) IDMSprEd : public IMainInterface
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

   __property TFIBBCDField * TableKFED = {read = get_TableKFED , write = set_TableKFED};
   virtual TFIBBCDField * get_TableKFED(void)=0;
   virtual void set_TableKFED(TFIBBCDField * TableKFED)=0;

   __property TFIBIntegerField * TableTSHED = {read = get_TableTSHED , write = set_TableTSHED};
   virtual TFIBIntegerField * get_TableTSHED(void)=0;
   virtual void set_TableTSHED(TFIBIntegerField * TableTSHED)=0;

   __property TFIBSmallIntField * TableNEISPED = {read = get_TableNEISPED , write = set_TableNEISPED};
   virtual TFIBSmallIntField * get_TableNEISPED(void)=0;
   virtual void set_TableNEISPED(TFIBSmallIntField * TableNEISPED)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBBCDField * ElementKFED = {read = get_ElementKFED , write = set_ElementKFED};
   virtual TFIBBCDField * get_ElementKFED(void)=0;
   virtual void set_ElementKFED(TFIBBCDField * ElementKFED)=0;

   __property TFIBIntegerField * ElementTSHED = {read = get_ElementTSHED , write = set_ElementTSHED};
   virtual TFIBIntegerField * get_ElementTSHED(void)=0;
   virtual void set_ElementTSHED(TFIBIntegerField * ElementTSHED)=0;

   __property TFIBSmallIntField * ElementNEISPED = {read = get_ElementNEISPED , write = set_ElementNEISPED};
   virtual TFIBSmallIntField * get_ElementNEISPED(void)=0;
   virtual void set_ElementNEISPED(TFIBSmallIntField * ElementNEISPED)=0;

   __property TpFIBDataSet * OKEI = {read = get_OKEI , write = set_OKEI};
   virtual TpFIBDataSet * get_OKEI(void)=0;
   virtual void set_OKEI(TpFIBDataSet * OKEI)=0;

   __property TFIBIntegerField * OKEICODEOKEI = {read = get_OKEICODEOKEI , write = set_OKEICODEOKEI};
   virtual TFIBIntegerField * get_OKEICODEOKEI(void)=0;
   virtual void set_OKEICODEOKEI(TFIBIntegerField * OKEICODEOKEI)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBBCDField * ElementIDED = {read = get_ElementIDED , write = set_ElementIDED};
   virtual TFIBBCDField * get_ElementIDED(void)=0;
   virtual void set_ElementIDED(TFIBBCDField * ElementIDED)=0;

   __property TFIBBCDField * ElementIDNOMED = {read = get_ElementIDNOMED , write = set_ElementIDNOMED};
   virtual TFIBBCDField * get_ElementIDNOMED(void)=0;
   virtual void set_ElementIDNOMED(TFIBBCDField * ElementIDNOMED)=0;

   __property TFIBBCDField * ElementIDOKEIED = {read = get_ElementIDOKEIED , write = set_ElementIDOKEIED};
   virtual TFIBBCDField * get_ElementIDOKEIED(void)=0;
   virtual void set_ElementIDOKEIED(TFIBBCDField * ElementIDOKEIED)=0;

   __property TFIBBCDField * OKEIIDOKEI = {read = get_OKEIIDOKEI , write = set_OKEIIDOKEI};
   virtual TFIBBCDField * get_OKEIIDOKEI(void)=0;
   virtual void set_OKEIIDOKEI(TFIBBCDField * OKEIIDOKEI)=0;

   __property TFIBIntegerField * TableCODE_SED = {read = get_TableCODE_SED , write = set_TableCODE_SED};
   virtual TFIBIntegerField * get_TableCODE_SED(void)=0;
   virtual void set_TableCODE_SED(TFIBIntegerField * TableCODE_SED)=0;

   __property TFIBIntegerField * ElementCODE_SED = {read = get_ElementCODE_SED , write = set_ElementCODE_SED};
   virtual TFIBIntegerField * get_ElementCODE_SED(void)=0;
   virtual void set_ElementCODE_SED(TFIBIntegerField * ElementCODE_SED)=0;

   __property TFIBBCDField * TableKF2_SED = {read = get_TableKF2_SED , write = set_TableKF2_SED};
   virtual TFIBBCDField * get_TableKF2_SED(void)=0;
   virtual void set_TableKF2_SED(TFIBBCDField * TableKF2_SED)=0;

   __property TFIBBCDField * TableVES_SED = {read = get_TableVES_SED , write = set_TableVES_SED};
   virtual TFIBBCDField * get_TableVES_SED(void)=0;
   virtual void set_TableVES_SED(TFIBBCDField * TableVES_SED)=0;

   __property TFIBBCDField * ElementKF2_SED = {read = get_ElementKF2_SED , write = set_ElementKF2_SED};
   virtual TFIBBCDField * get_ElementKF2_SED(void)=0;
   virtual void set_ElementKF2_SED(TFIBBCDField * ElementKF2_SED)=0;

   __property TFIBBCDField * ElementVES_SED = {read = get_ElementVES_SED , write = set_ElementVES_SED};
   virtual TFIBBCDField * get_ElementVES_SED(void)=0;
   virtual void set_ElementVES_SED(TFIBBCDField * ElementVES_SED)=0;

   __property TFIBLargeIntField * TableIDED = {read = get_TableIDED , write = set_TableIDED};
   virtual TFIBLargeIntField * get_TableIDED(void)=0;
   virtual void set_TableIDED(TFIBLargeIntField * TableIDED)=0;

   __property TFIBLargeIntField * TableIDNOMED = {read = get_TableIDNOMED , write = set_TableIDNOMED};
   virtual TFIBLargeIntField * get_TableIDNOMED(void)=0;
   virtual void set_TableIDNOMED(TFIBLargeIntField * TableIDNOMED)=0;

   __property TFIBLargeIntField * TableIDOKEIED = {read = get_TableIDOKEIED , write = set_TableIDOKEIED};
   virtual TFIBLargeIntField * get_TableIDOKEIED(void)=0;
   virtual void set_TableIDOKEIED(TFIBLargeIntField * TableIDOKEIED)=0;

   __property TFIBWideStringField * TableNAMEED = {read = get_TableNAMEED , write = set_TableNAMEED};
   virtual TFIBWideStringField * get_TableNAMEED(void)=0;
   virtual void set_TableNAMEED(TFIBWideStringField * TableNAMEED)=0;

   __property TFIBWideStringField * TableSHED = {read = get_TableSHED , write = set_TableSHED};
   virtual TFIBWideStringField * get_TableSHED(void)=0;
   virtual void set_TableSHED(TFIBWideStringField * TableSHED)=0;

   __property TFIBWideStringField * TableGID_SED = {read = get_TableGID_SED , write = set_TableGID_SED};
   virtual TFIBWideStringField * get_TableGID_SED(void)=0;
   virtual void set_TableGID_SED(TFIBWideStringField * TableGID_SED)=0;

   __property TFIBWideStringField * ElementNAMEED = {read = get_ElementNAMEED , write = set_ElementNAMEED};
   virtual TFIBWideStringField * get_ElementNAMEED(void)=0;
   virtual void set_ElementNAMEED(TFIBWideStringField * ElementNAMEED)=0;

   __property TFIBWideStringField * ElementSHED = {read = get_ElementSHED , write = set_ElementSHED};
   virtual TFIBWideStringField * get_ElementSHED(void)=0;
   virtual void set_ElementSHED(TFIBWideStringField * ElementSHED)=0;

   __property TFIBWideStringField * ElementGID_SED = {read = get_ElementGID_SED , write = set_ElementGID_SED};
   virtual TFIBWideStringField * get_ElementGID_SED(void)=0;
   virtual void set_ElementGID_SED(TFIBWideStringField * ElementGID_SED)=0;

   __property TFIBWideStringField * OKEINAMEOKEI = {read = get_OKEINAMEOKEI , write = set_OKEINAMEOKEI};
   virtual TFIBWideStringField * get_OKEINAMEOKEI(void)=0;
   virtual void set_OKEINAMEOKEI(TFIBWideStringField * OKEINAMEOKEI)=0;

   __property TFIBWideStringField * ElementNAMEOKEI = {read = get_ElementNAMEOKEI , write = set_ElementNAMEOKEI};
   virtual TFIBWideStringField * get_ElementNAMEOKEI(void)=0;
   virtual void set_ElementNAMEOKEI(TFIBWideStringField * ElementNAMEOKEI)=0;

   virtual void OpenTable(__int64 IdNom)=0;
   virtual int OpenElement(__int64 Id)=0;
   virtual bool NewElement(__int64 IdNom)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 Id)=0;
   virtual void NewShtrihCod(void)=0;
   virtual __int64 FindEdPoSh(String ShtrihCod)=0;
   virtual __int64 FindEdPoCodu(int code)=0;
   virtual __int64 GetIDElement(String gid)=0;
   virtual AnsiString GetGIDElement(__int64 id)=0;
   virtual __int64 GetIdNomPoShtrihCodu(AnsiString shtrih_cod)=0;
   virtual bool CheckBarCode(__int64 id_ed, AnsiString sh)=0;
   virtual bool CheckCode(__int64 id_ed, int code)=0;
   virtual int GetCodeEd(void)=0;
};
#define IID_IDMSprEd __uuidof(IDMSprEd)
#endif
