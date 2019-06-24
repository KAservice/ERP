#ifndef UIDMSprBankH
#define UIDMSprBankH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{893E6213-43F5-496D-BE97-1623D1E25D4C}")) IDMSprBank : public IMainInterface
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

   __property TFIBBCDField * TableIDBANK = {read = get_TableIDBANK , write = set_TableIDBANK};
   virtual TFIBBCDField * get_TableIDBANK(void)=0;
   virtual void set_TableIDBANK(TFIBBCDField * TableIDBANK)=0;

   __property TFIBBCDField * ElementIDBANK = {read = get_ElementIDBANK , write = set_ElementIDBANK};
   virtual TFIBBCDField * get_ElementIDBANK(void)=0;
   virtual void set_ElementIDBANK(TFIBBCDField * ElementIDBANK)=0;

   __property TFIBWideStringField * TableNAMEBANK = {read = get_TableNAMEBANK , write = set_TableNAMEBANK};
   virtual TFIBWideStringField * get_TableNAMEBANK(void)=0;
   virtual void set_TableNAMEBANK(TFIBWideStringField * TableNAMEBANK)=0;

   __property TFIBWideStringField * TableGORBANK = {read = get_TableGORBANK , write = set_TableGORBANK};
   virtual TFIBWideStringField * get_TableGORBANK(void)=0;
   virtual void set_TableGORBANK(TFIBWideStringField * TableGORBANK)=0;

   __property TFIBWideStringField * ElementNAMEBANK = {read = get_ElementNAMEBANK , write = set_ElementNAMEBANK};
   virtual TFIBWideStringField * get_ElementNAMEBANK(void)=0;
   virtual void set_ElementNAMEBANK(TFIBWideStringField * ElementNAMEBANK)=0;

   __property TFIBWideStringField * ElementBIKBANK = {read = get_ElementBIKBANK , write = set_ElementBIKBANK};
   virtual TFIBWideStringField * get_ElementBIKBANK(void)=0;
   virtual void set_ElementBIKBANK(TFIBWideStringField * ElementBIKBANK)=0;

   __property TFIBWideStringField * ElementGORBANK = {read = get_ElementGORBANK , write = set_ElementGORBANK};
   virtual TFIBWideStringField * get_ElementGORBANK(void)=0;
   virtual void set_ElementGORBANK(TFIBWideStringField * ElementGORBANK)=0;

   __property TFIBWideStringField * ElementKSBANK = {read = get_ElementKSBANK , write = set_ElementKSBANK};
   virtual TFIBWideStringField * get_ElementKSBANK(void)=0;
   virtual void set_ElementKSBANK(TFIBWideStringField * ElementKSBANK)=0;

   __property TFIBWideStringField * ElementGID_SBANK = {read = get_ElementGID_SBANK , write = set_ElementGID_SBANK};
   virtual TFIBWideStringField * get_ElementGID_SBANK(void)=0;
   virtual void set_ElementGID_SBANK(TFIBWideStringField * ElementGID_SBANK)=0;

   __property bool Error = {read = get_Error , write = set_Error};
   virtual bool get_Error(void)=0;
   virtual void set_Error(bool Error)=0;

   virtual void OpenTable()=0;
   virtual int  OpenElement(__int64 Id)=0;
   virtual void NewElement()=0;
   virtual bool SaveElement(void)=0;
   virtual void DeleteElement(__int64 Id)=0;
};
#define IID_IDMSprBank __uuidof(IDMSprBank)
#endif
