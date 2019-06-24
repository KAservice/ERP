#ifndef UIDMSprSellerH
#define UIDMSprSellerH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprSeller)) IDMSprSeller : public IMainInterface
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

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBLargeIntField * TableID_SSELLER = {read = get_TableID_SSELLER , write = set_TableID_SSELLER};
   virtual TFIBLargeIntField * get_TableID_SSELLER(void)=0;
   virtual void set_TableID_SSELLER(TFIBLargeIntField * TableID_SSELLER)=0;

   __property TFIBLargeIntField * TableIDBASE_SSELLER = {read = get_TableIDBASE_SSELLER , write = set_TableIDBASE_SSELLER};
   virtual TFIBLargeIntField * get_TableIDBASE_SSELLER(void)=0;
   virtual void set_TableIDBASE_SSELLER(TFIBLargeIntField * TableIDBASE_SSELLER)=0;

   __property TFIBWideStringField * TableNAME_SSELLER = {read = get_TableNAME_SSELLER , write = set_TableNAME_SSELLER};
   virtual TFIBWideStringField * get_TableNAME_SSELLER(void)=0;
   virtual void set_TableNAME_SSELLER(TFIBWideStringField * TableNAME_SSELLER)=0;

   __property TFIBWideStringField * TableADR_SSELLER = {read = get_TableADR_SSELLER , write = set_TableADR_SSELLER};
   virtual TFIBWideStringField * get_TableADR_SSELLER(void)=0;
   virtual void set_TableADR_SSELLER(TFIBWideStringField * TableADR_SSELLER)=0;

   __property TFIBWideStringField * TablePHONE_SSELLER = {read = get_TablePHONE_SSELLER , write = set_TablePHONE_SSELLER};
   virtual TFIBWideStringField * get_TablePHONE_SSELLER(void)=0;
   virtual void set_TablePHONE_SSELLER(TFIBWideStringField * TablePHONE_SSELLER)=0;

   __property TFIBLargeIntField * TableIDKLIENT_SSELLER = {read = get_TableIDKLIENT_SSELLER , write = set_TableIDKLIENT_SSELLER};
   virtual TFIBLargeIntField * get_TableIDKLIENT_SSELLER(void)=0;
   virtual void set_TableIDKLIENT_SSELLER(TFIBLargeIntField * TableIDKLIENT_SSELLER)=0;

   __property TFIBWideStringField * TableNAME_FOR_PRINT_SSELLER = {read = get_TableNAME_FOR_PRINT_SSELLER , write = set_TableNAME_FOR_PRINT_SSELLER};
   virtual TFIBWideStringField * get_TableNAME_FOR_PRINT_SSELLER(void)=0;
   virtual void set_TableNAME_FOR_PRINT_SSELLER(TFIBWideStringField * TableNAME_FOR_PRINT_SSELLER)=0;

   __property TFIBWideStringField * TableNAMEKLIENT = {read = get_TableNAMEKLIENT , write = set_TableNAMEKLIENT};
   virtual TFIBWideStringField * get_TableNAMEKLIENT(void)=0;
   virtual void set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)=0;

   __property TFIBWideStringField * TableINNKLIENT = {read = get_TableINNKLIENT , write = set_TableINNKLIENT};
   virtual TFIBWideStringField * get_TableINNKLIENT(void)=0;
   virtual void set_TableINNKLIENT(TFIBWideStringField * TableINNKLIENT)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBLargeIntField * ElementID_SSELLER = {read = get_ElementID_SSELLER , write = set_ElementID_SSELLER};
   virtual TFIBLargeIntField * get_ElementID_SSELLER(void)=0;
   virtual void set_ElementID_SSELLER(TFIBLargeIntField * ElementID_SSELLER)=0;

   __property TFIBLargeIntField * ElementIDBASE_SSELLER = {read = get_ElementIDBASE_SSELLER , write = set_ElementIDBASE_SSELLER};
   virtual TFIBLargeIntField * get_ElementIDBASE_SSELLER(void)=0;
   virtual void set_ElementIDBASE_SSELLER(TFIBLargeIntField * ElementIDBASE_SSELLER)=0;

   __property TFIBWideStringField * ElementNAME_SSELLER = {read = get_ElementNAME_SSELLER , write = set_ElementNAME_SSELLER};
   virtual TFIBWideStringField * get_ElementNAME_SSELLER(void)=0;
   virtual void set_ElementNAME_SSELLER(TFIBWideStringField * ElementNAME_SSELLER)=0;

   __property TFIBWideStringField * ElementADR_SSELLER = {read = get_ElementADR_SSELLER , write = set_ElementADR_SSELLER};
   virtual TFIBWideStringField * get_ElementADR_SSELLER(void)=0;
   virtual void set_ElementADR_SSELLER(TFIBWideStringField * ElementADR_SSELLER)=0;

   __property TFIBWideStringField * ElementPHONE_SSELLER = {read = get_ElementPHONE_SSELLER , write = set_ElementPHONE_SSELLER};
   virtual TFIBWideStringField * get_ElementPHONE_SSELLER(void)=0;
   virtual void set_ElementPHONE_SSELLER(TFIBWideStringField * ElementPHONE_SSELLER)=0;

   __property TFIBLargeIntField * ElementIDKLIENT_SSELLER = {read = get_ElementIDKLIENT_SSELLER , write = set_ElementIDKLIENT_SSELLER};
   virtual TFIBLargeIntField * get_ElementIDKLIENT_SSELLER(void)=0;
   virtual void set_ElementIDKLIENT_SSELLER(TFIBLargeIntField * ElementIDKLIENT_SSELLER)=0;

   __property TFIBWideStringField * ElementNAME_FOR_PRINT_SSELLER = {read = get_ElementNAME_FOR_PRINT_SSELLER , write = set_ElementNAME_FOR_PRINT_SSELLER};
   virtual TFIBWideStringField * get_ElementNAME_FOR_PRINT_SSELLER(void)=0;
   virtual void set_ElementNAME_FOR_PRINT_SSELLER(TFIBWideStringField * ElementNAME_FOR_PRINT_SSELLER)=0;

   __property TFIBWideStringField * ElementNAMEKLIENT = {read = get_ElementNAMEKLIENT , write = set_ElementNAMEKLIENT};
   virtual TFIBWideStringField * get_ElementNAMEKLIENT(void)=0;
   virtual void set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT)=0;

   virtual bool OpenTable()=0;
   virtual bool  OpenElement(__int64 id)=0;
   virtual bool NewElement()=0;
   virtual bool SaveElement(void)=0;
   virtual void CloseElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual __int64 GetIdElementPoName(UnicodeString   name)=0;
   virtual int GetIndexInTablePoId(__int64 id_element)=0;
   virtual __int64 GetIdElementPoGid(UnicodeString gid)=0;
   virtual UnicodeString GetGidElementPoId(__int64 id)=0;
};
#define IID_IDMSprSeller __uuidof(IDMSprSeller)
#endif
