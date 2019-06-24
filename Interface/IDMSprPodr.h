#ifndef UIDMSprPodrH
#define UIDMSprPodrH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>
class __declspec(uuid("{D634E705-067E-4C41-84CB-A10579CBB82F}")) IDMSprPodr : public IMainInterface
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

   __property TFIBBCDField * TableIDPOD = {read = get_TableIDPOD , write = set_TableIDPOD};
   virtual TFIBBCDField * get_TableIDPOD(void)=0;
   virtual void set_TableIDPOD(TFIBBCDField * TableIDPOD)=0;

   __property TFIBBCDField * TableIDTPRICEPOD = {read = get_TableIDTPRICEPOD , write = set_TableIDTPRICEPOD};
   virtual TFIBBCDField * get_TableIDTPRICEPOD(void)=0;
   virtual void set_TableIDTPRICEPOD(TFIBBCDField * TableIDTPRICEPOD)=0;

   __property TFIBBCDField * ElementIDPOD = {read = get_ElementIDPOD , write = set_ElementIDPOD};
   virtual TFIBBCDField * get_ElementIDPOD(void)=0;
   virtual void set_ElementIDPOD(TFIBBCDField * ElementIDPOD)=0;

   __property TFIBBCDField * ElementIDTPRICEPOD = {read = get_ElementIDTPRICEPOD , write = set_ElementIDTPRICEPOD};
   virtual TFIBBCDField * get_ElementIDTPRICEPOD(void)=0;
   virtual void set_ElementIDTPRICEPOD(TFIBBCDField * ElementIDTPRICEPOD)=0;

   __property TFIBWideStringField * TableNAMEPOD = {read = get_TableNAMEPOD , write = set_TableNAMEPOD};
   virtual TFIBWideStringField * get_TableNAMEPOD(void)=0;
   virtual void set_TableNAMEPOD(TFIBWideStringField * TableNAMEPOD)=0;

   __property TFIBWideStringField * TableGID_SPOD = {read = get_TableGID_SPOD , write = set_TableGID_SPOD};
   virtual TFIBWideStringField * get_TableGID_SPOD(void)=0;
   virtual void set_TableGID_SPOD(TFIBWideStringField * TableGID_SPOD)=0;

   __property TFIBBCDField * TableIDBASE_SPOD = {read = get_TableIDBASE_SPOD , write = set_TableIDBASE_SPOD};
   virtual TFIBBCDField * get_TableIDBASE_SPOD(void)=0;
   virtual void set_TableIDBASE_SPOD(TFIBBCDField * TableIDBASE_SPOD)=0;

   __property TFIBWideStringField * TableNAME_TPRICE = {read = get_TableNAME_TPRICE , write = set_TableNAME_TPRICE};
   virtual TFIBWideStringField * get_TableNAME_TPRICE(void)=0;
   virtual void set_TableNAME_TPRICE(TFIBWideStringField * TableNAME_TPRICE)=0;

   __property TFIBWideStringField * ElementNAMEPOD = {read = get_ElementNAMEPOD , write = set_ElementNAMEPOD};
   virtual TFIBWideStringField * get_ElementNAMEPOD(void)=0;
   virtual void set_ElementNAMEPOD(TFIBWideStringField * ElementNAMEPOD)=0;

   __property TFIBWideStringField * ElementGID_SPOD = {read = get_ElementGID_SPOD , write = set_ElementGID_SPOD};
   virtual TFIBWideStringField * get_ElementGID_SPOD(void)=0;
   virtual void set_ElementGID_SPOD(TFIBWideStringField * ElementGID_SPOD)=0;

   __property TFIBBCDField * ElementIDBASE_SPOD = {read = get_ElementIDBASE_SPOD , write = set_ElementIDBASE_SPOD};
   virtual TFIBBCDField * get_ElementIDBASE_SPOD(void)=0;
   virtual void set_ElementIDBASE_SPOD(TFIBBCDField * ElementIDBASE_SPOD)=0;

   __property TFIBWideStringField * ElementNAME_TPRICE = {read = get_ElementNAME_TPRICE , write = set_ElementNAME_TPRICE};
   virtual TFIBWideStringField * get_ElementNAME_TPRICE(void)=0;
   virtual void set_ElementNAME_TPRICE(TFIBWideStringField * ElementNAME_TPRICE)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 Id)=0;
   virtual void NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void DeleteElement(__int64 Id)=0;
};
#define IID_IDMSprPodr __uuidof(IDMSprPodr)
#endif
