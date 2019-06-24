#ifndef UIDMSprKKMH
#define UIDMSprKKMH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprKKM)) IDMSprKKM : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TDataSource * DataSourceElement = {read = get_DataSourceElement , write = set_DataSourceElement};
   virtual TDataSource * get_DataSourceElement(void)=0;
   virtual void set_DataSourceElement(TDataSource * DataSourceElement)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBBCDField * TableIDKKM = {read = get_TableIDKKM , write = set_TableIDKKM};
   virtual TFIBBCDField * get_TableIDKKM(void)=0;
   virtual void set_TableIDKKM(TFIBBCDField * TableIDKKM)=0;

   __property TFIBBCDField * ElementIDKKM = {read = get_ElementIDKKM , write = set_ElementIDKKM};
   virtual TFIBBCDField * get_ElementIDKKM(void)=0;
   virtual void set_ElementIDKKM(TFIBBCDField * ElementIDKKM)=0;

   __property TFIBWideStringField * TableNAMEKKM = {read = get_TableNAMEKKM , write = set_TableNAMEKKM};
   virtual TFIBWideStringField * get_TableNAMEKKM(void)=0;
   virtual void set_TableNAMEKKM(TFIBWideStringField * TableNAMEKKM)=0;

   __property TFIBWideStringField * TableGID_SKKM = {read = get_TableGID_SKKM , write = set_TableGID_SKKM};
   virtual TFIBWideStringField * get_TableGID_SKKM(void)=0;
   virtual void set_TableGID_SKKM(TFIBWideStringField * TableGID_SKKM)=0;

   __property TFIBWideStringField * TableCATOBMKKM = {read = get_TableCATOBMKKM , write = set_TableCATOBMKKM};
   virtual TFIBWideStringField * get_TableCATOBMKKM(void)=0;
   virtual void set_TableCATOBMKKM(TFIBWideStringField * TableCATOBMKKM)=0;

   __property TFIBWideStringField * ElementNAMEKKM = {read = get_ElementNAMEKKM , write = set_ElementNAMEKKM};
   virtual TFIBWideStringField * get_ElementNAMEKKM(void)=0;
   virtual void set_ElementNAMEKKM(TFIBWideStringField * ElementNAMEKKM)=0;

   __property TFIBWideStringField * ElementGID_SKKM = {read = get_ElementGID_SKKM , write = set_ElementGID_SKKM};
   virtual TFIBWideStringField * get_ElementGID_SKKM(void)=0;
   virtual void set_ElementGID_SKKM(TFIBWideStringField * ElementGID_SKKM)=0;

   __property TFIBWideStringField * ElementCATOBMKKM = {read = get_ElementCATOBMKKM , write = set_ElementCATOBMKKM};
   virtual TFIBWideStringField * get_ElementCATOBMKKM(void)=0;
   virtual void set_ElementCATOBMKKM(TFIBWideStringField * ElementCATOBMKKM)=0;

   __property TFIBWideStringField * ElementPREFIKS_NUM_SKKM = {read = get_ElementPREFIKS_NUM_SKKM , write = set_ElementPREFIKS_NUM_SKKM};
   virtual TFIBWideStringField * get_ElementPREFIKS_NUM_SKKM(void)=0;
   virtual void set_ElementPREFIKS_NUM_SKKM(TFIBWideStringField * ElementPREFIKS_NUM_SKKM)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 Id)=0;
   virtual void NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void DeleteElement(__int64 Id)=0;
   virtual AnsiString GetGIDElement(__int64 id)=0;
};
#define IID_IDMSprKKM __uuidof(IDMSprKKM)
#endif
