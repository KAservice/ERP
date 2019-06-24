#ifndef UIDMSprGrpKlientH
#define UIDMSprGrpKlientH
#include "IMainInterface.h"
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{937FA28A-B36A-413C-8392-DE9B2A1902B9}")) IDMSprGrpKlient : public IMainInterface
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

   __property TFIBBCDField * TableIDGRPKL = {read = get_TableIDGRPKL , write = set_TableIDGRPKL};
   virtual TFIBBCDField * get_TableIDGRPKL(void)=0;
   virtual void set_TableIDGRPKL(TFIBBCDField * TableIDGRPKL)=0;

   __property TFIBBCDField * TableGRPKL = {read = get_TableGRPKL , write = set_TableGRPKL};
   virtual TFIBBCDField * get_TableGRPKL(void)=0;
   virtual void set_TableGRPKL(TFIBBCDField * TableGRPKL)=0;

   __property TFIBBCDField * ElementIDGRPKL = {read = get_ElementIDGRPKL , write = set_ElementIDGRPKL};
   virtual TFIBBCDField * get_ElementIDGRPKL(void)=0;
   virtual void set_ElementIDGRPKL(TFIBBCDField * ElementIDGRPKL)=0;

   __property TFIBBCDField * ElementGRPKL = {read = get_ElementGRPKL , write = set_ElementGRPKL};
   virtual TFIBBCDField * get_ElementGRPKL(void)=0;
   virtual void set_ElementGRPKL(TFIBBCDField * ElementGRPKL)=0;

   __property TFIBWideStringField * TableNAMEGRPKL = {read = get_TableNAMEGRPKL , write = set_TableNAMEGRPKL};
   virtual TFIBWideStringField * get_TableNAMEGRPKL(void)=0;
   virtual void set_TableNAMEGRPKL(TFIBWideStringField * TableNAMEGRPKL)=0;

   __property TFIBWideStringField * TableGID_SGRPKL = {read = get_TableGID_SGRPKL , write = set_TableGID_SGRPKL};
   virtual TFIBWideStringField * get_TableGID_SGRPKL(void)=0;
   virtual void set_TableGID_SGRPKL(TFIBWideStringField * TableGID_SGRPKL)=0;

   __property TFIBWideStringField * ElementNAMEGRPKL = {read = get_ElementNAMEGRPKL , write = set_ElementNAMEGRPKL};
   virtual TFIBWideStringField * get_ElementNAMEGRPKL(void)=0;
   virtual void set_ElementNAMEGRPKL(TFIBWideStringField * ElementNAMEGRPKL)=0;

   __property TFIBWideStringField * ElementGID_SGRPKL = {read = get_ElementGID_SGRPKL , write = set_ElementGID_SGRPKL};
   virtual TFIBWideStringField * get_ElementGID_SGRPKL(void)=0;
   virtual void set_ElementGID_SGRPKL(TFIBWideStringField * ElementGID_SGRPKL)=0;

   virtual bool OpenTable(void)=0;
   virtual int OpenElement(__int64 Id)=0;
   virtual void NewElement(__int64 IdGrp)=0;
   virtual bool SaveElement(void)=0;
   virtual void DeleteElement(__int64 Id)=0;
};
#define IID_IDMSprGrpKlient __uuidof(IDMSprGrpKlient)
#endif
