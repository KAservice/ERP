#ifndef UIDMSprPartH
#define UIDMSprPartH
#include "IMainInterface.h"
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{5D042B01-0D93-42E5-9D95-985062D94807}")) IDMSprPart : public IMainInterface
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

   __property TFIBBCDField * TablePRICEZPART = {read = get_TablePRICEZPART , write = set_TablePRICEZPART};
   virtual TFIBBCDField * get_TablePRICEZPART(void)=0;
   virtual void set_TablePRICEZPART(TFIBBCDField * TablePRICEZPART)=0;

   __property TFIBBCDField * TableKOLOSTNOM = {read = get_TableKOLOSTNOM , write = set_TableKOLOSTNOM};
   virtual TFIBBCDField * get_TableKOLOSTNOM(void)=0;
   virtual void set_TableKOLOSTNOM(TFIBBCDField * TableKOLOSTNOM)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBBCDField * ElementPRICEZPART = {read = get_ElementPRICEZPART , write = set_ElementPRICEZPART};
   virtual TFIBBCDField * get_ElementPRICEZPART(void)=0;
   virtual void set_ElementPRICEZPART(TFIBBCDField * ElementPRICEZPART)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBBCDField * TableIDPART = {read = get_TableIDPART , write = set_TableIDPART};
   virtual TFIBBCDField * get_TableIDPART(void)=0;
   virtual void set_TableIDPART(TFIBBCDField * TableIDPART)=0;

   __property TFIBBCDField * TableIDKLPART = {read = get_TableIDKLPART , write = set_TableIDKLPART};
   virtual TFIBBCDField * get_TableIDKLPART(void)=0;
   virtual void set_TableIDKLPART(TFIBBCDField * TableIDKLPART)=0;

   __property TFIBBCDField * TableIDFIRMPART = {read = get_TableIDFIRMPART , write = set_TableIDFIRMPART};
   virtual TFIBBCDField * get_TableIDFIRMPART(void)=0;
   virtual void set_TableIDFIRMPART(TFIBBCDField * TableIDFIRMPART)=0;

   __property TFIBBCDField * TableIDNOMPART = {read = get_TableIDNOMPART , write = set_TableIDNOMPART};
   virtual TFIBBCDField * get_TableIDNOMPART(void)=0;
   virtual void set_TableIDNOMPART(TFIBBCDField * TableIDNOMPART)=0;

   __property TFIBBCDField * ElementIDKLPART = {read = get_ElementIDKLPART , write = set_ElementIDKLPART};
   virtual TFIBBCDField * get_ElementIDKLPART(void)=0;
   virtual void set_ElementIDKLPART(TFIBBCDField * ElementIDKLPART)=0;

   __property TFIBBCDField * ElementIDFIRMPART = {read = get_ElementIDFIRMPART , write = set_ElementIDFIRMPART};
   virtual TFIBBCDField * get_ElementIDFIRMPART(void)=0;
   virtual void set_ElementIDFIRMPART(TFIBBCDField * ElementIDFIRMPART)=0;

   __property TFIBBCDField * ElementIDNOMPART = {read = get_ElementIDNOMPART , write = set_ElementIDNOMPART};
   virtual TFIBBCDField * get_ElementIDNOMPART(void)=0;
   virtual void set_ElementIDNOMPART(TFIBBCDField * ElementIDNOMPART)=0;

   __property TFIBBCDField * TableIDDOCPART = {read = get_TableIDDOCPART , write = set_TableIDDOCPART};
   virtual TFIBBCDField * get_TableIDDOCPART(void)=0;
   virtual void set_TableIDDOCPART(TFIBBCDField * TableIDDOCPART)=0;

   __property TFIBBCDField * ElementIDDOCPART = {read = get_ElementIDDOCPART , write = set_ElementIDDOCPART};
   virtual TFIBBCDField * get_ElementIDDOCPART(void)=0;
   virtual void set_ElementIDDOCPART(TFIBBCDField * ElementIDDOCPART)=0;

   __property TFIBBCDField * ElementIDPART = {read = get_ElementIDPART , write = set_ElementIDPART};
   virtual TFIBBCDField * get_ElementIDPART(void)=0;
   virtual void set_ElementIDPART(TFIBBCDField * ElementIDPART)=0;

   __property TFIBDateTimeField * TableSRGODNPART = {read = get_TableSRGODNPART , write = set_TableSRGODNPART};
   virtual TFIBDateTimeField * get_TableSRGODNPART(void)=0;
   virtual void set_TableSRGODNPART(TFIBDateTimeField * TableSRGODNPART)=0;

   __property TFIBDateTimeField * ElementSRGODNPART = {read = get_ElementSRGODNPART , write = set_ElementSRGODNPART};
   virtual TFIBDateTimeField * get_ElementSRGODNPART(void)=0;
   virtual void set_ElementSRGODNPART(TFIBDateTimeField * ElementSRGODNPART)=0;

   __property TFIBIntegerField * TableCODEPART = {read = get_TableCODEPART , write = set_TableCODEPART};
   virtual TFIBIntegerField * get_TableCODEPART(void)=0;
   virtual void set_TableCODEPART(TFIBIntegerField * TableCODEPART)=0;

   __property TFIBWideStringField * TableDOCPART = {read = get_TableDOCPART , write = set_TableDOCPART};
   virtual TFIBWideStringField * get_TableDOCPART(void)=0;
   virtual void set_TableDOCPART(TFIBWideStringField * TableDOCPART)=0;

   __property TFIBWideStringField * TableGTDPART = {read = get_TableGTDPART , write = set_TableGTDPART};
   virtual TFIBWideStringField * get_TableGTDPART(void)=0;
   virtual void set_TableGTDPART(TFIBWideStringField * TableGTDPART)=0;

   __property TFIBWideStringField * TableSERTPART = {read = get_TableSERTPART , write = set_TableSERTPART};
   virtual TFIBWideStringField * get_TableSERTPART(void)=0;
   virtual void set_TableSERTPART(TFIBWideStringField * TableSERTPART)=0;

   __property TFIBWideStringField * TableGID_SPART = {read = get_TableGID_SPART , write = set_TableGID_SPART};
   virtual TFIBWideStringField * get_TableGID_SPART(void)=0;
   virtual void set_TableGID_SPART(TFIBWideStringField * TableGID_SPART)=0;

   __property TFIBBCDField * TableIDBASE_SPART = {read = get_TableIDBASE_SPART , write = set_TableIDBASE_SPART};
   virtual TFIBBCDField * get_TableIDBASE_SPART(void)=0;
   virtual void set_TableIDBASE_SPART(TFIBBCDField * TableIDBASE_SPART)=0;

   __property TFIBBCDField * TableIDEXT_DOUT_SPART = {read = get_TableIDEXT_DOUT_SPART , write = set_TableIDEXT_DOUT_SPART};
   virtual TFIBBCDField * get_TableIDEXT_DOUT_SPART(void)=0;
   virtual void set_TableIDEXT_DOUT_SPART(TFIBBCDField * TableIDEXT_DOUT_SPART)=0;

   __property TFIBBCDField * TableIDEXT_BASE_SPART = {read = get_TableIDEXT_BASE_SPART , write = set_TableIDEXT_BASE_SPART};
   virtual TFIBBCDField * get_TableIDEXT_BASE_SPART(void)=0;
   virtual void set_TableIDEXT_BASE_SPART(TFIBBCDField * TableIDEXT_BASE_SPART)=0;

   __property TFIBWideStringField * TableNAMEFIRM = {read = get_TableNAMEFIRM , write = set_TableNAMEFIRM};
   virtual TFIBWideStringField * get_TableNAMEFIRM(void)=0;
   virtual void set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM)=0;

   __property TFIBWideStringField * TableNAMEKLIENT = {read = get_TableNAMEKLIENT , write = set_TableNAMEKLIENT};
   virtual TFIBWideStringField * get_TableNAMEKLIENT(void)=0;
   virtual void set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)=0;

   __property TFIBIntegerField * ElementCODEPART = {read = get_ElementCODEPART , write = set_ElementCODEPART};
   virtual TFIBIntegerField * get_ElementCODEPART(void)=0;
   virtual void set_ElementCODEPART(TFIBIntegerField * ElementCODEPART)=0;

   __property TFIBWideStringField * ElementDOCPART = {read = get_ElementDOCPART , write = set_ElementDOCPART};
   virtual TFIBWideStringField * get_ElementDOCPART(void)=0;
   virtual void set_ElementDOCPART(TFIBWideStringField * ElementDOCPART)=0;

   __property TFIBWideStringField * ElementGTDPART = {read = get_ElementGTDPART , write = set_ElementGTDPART};
   virtual TFIBWideStringField * get_ElementGTDPART(void)=0;
   virtual void set_ElementGTDPART(TFIBWideStringField * ElementGTDPART)=0;

   __property TFIBWideStringField * ElementGID_SPART = {read = get_ElementGID_SPART , write = set_ElementGID_SPART};
   virtual TFIBWideStringField * get_ElementGID_SPART(void)=0;
   virtual void set_ElementGID_SPART(TFIBWideStringField * ElementGID_SPART)=0;

   __property TFIBBCDField * ElementIDBASE_SPART = {read = get_ElementIDBASE_SPART , write = set_ElementIDBASE_SPART};
   virtual TFIBBCDField * get_ElementIDBASE_SPART(void)=0;
   virtual void set_ElementIDBASE_SPART(TFIBBCDField * ElementIDBASE_SPART)=0;

   __property TFIBWideStringField * ElementNAMEKLIENT = {read = get_ElementNAMEKLIENT , write = set_ElementNAMEKLIENT};
   virtual TFIBWideStringField * get_ElementNAMEKLIENT(void)=0;
   virtual void set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT)=0;

   __property TFIBWideStringField * ElementNAMENOM = {read = get_ElementNAMENOM , write = set_ElementNAMENOM};
   virtual TFIBWideStringField * get_ElementNAMENOM(void)=0;
   virtual void set_ElementNAMENOM(TFIBWideStringField * ElementNAMENOM)=0;

   __property TFIBWideStringField * ElementNAMEFIRM = {read = get_ElementNAMEFIRM , write = set_ElementNAMEFIRM};
   virtual TFIBWideStringField * get_ElementNAMEFIRM(void)=0;
   virtual void set_ElementNAMEFIRM(TFIBWideStringField * ElementNAMEFIRM)=0;

   __property TFIBWideStringField * ElementSERTPART = {read = get_ElementSERTPART , write = set_ElementSERTPART};
   virtual TFIBWideStringField * get_ElementSERTPART(void)=0;
   virtual void set_ElementSERTPART(TFIBWideStringField * ElementSERTPART)=0;

   virtual void OpenTable(__int64 IdNom)=0;
   virtual int OpenElement(__int64 Id)=0;
   virtual void NewElement(__int64 IdNom)=0;
   virtual bool SaveElement(void)=0;
   virtual void DeleteElement(__int64 Id)=0;
};
#define IID_IDMSprPart __uuidof(IDMSprPart)
#endif
