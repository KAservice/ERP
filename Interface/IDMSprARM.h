#ifndef UIDMSprARMH
#define UIDMSprARMH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprARM)) IDMSprARM : public IMainInterface
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

   __property TpFIBQuery * Query = {read = get_Query , write = set_Query};
   virtual TpFIBQuery * get_Query(void)=0;
   virtual void set_Query(TpFIBQuery * Query)=0;

   __property TFIBLargeIntField * TableID_SARM = {read = get_TableID_SARM , write = set_TableID_SARM};
   virtual TFIBLargeIntField * get_TableID_SARM(void)=0;
   virtual void set_TableID_SARM(TFIBLargeIntField * TableID_SARM)=0;

   __property TFIBWideStringField * TableGID_SARM = {read = get_TableGID_SARM , write = set_TableGID_SARM};
   virtual TFIBWideStringField * get_TableGID_SARM(void)=0;
   virtual void set_TableGID_SARM(TFIBWideStringField * TableGID_SARM)=0;

   __property TFIBWideStringField * TableNAME_SARM = {read = get_TableNAME_SARM , write = set_TableNAME_SARM};
   virtual TFIBWideStringField * get_TableNAME_SARM(void)=0;
   virtual void set_TableNAME_SARM(TFIBWideStringField * TableNAME_SARM)=0;

   __property TFIBIntegerField * TableCODE_SARM = {read = get_TableCODE_SARM , write = set_TableCODE_SARM};
   virtual TFIBIntegerField * get_TableCODE_SARM(void)=0;
   virtual void set_TableCODE_SARM(TFIBIntegerField * TableCODE_SARM)=0;

   __property TFIBLargeIntField * TableIDFIRM_SARM = {read = get_TableIDFIRM_SARM , write = set_TableIDFIRM_SARM};
   virtual TFIBLargeIntField * get_TableIDFIRM_SARM(void)=0;
   virtual void set_TableIDFIRM_SARM(TFIBLargeIntField * TableIDFIRM_SARM)=0;

   __property TFIBLargeIntField * TableIDSKLAD_SARM = {read = get_TableIDSKLAD_SARM , write = set_TableIDSKLAD_SARM};
   virtual TFIBLargeIntField * get_TableIDSKLAD_SARM(void)=0;
   virtual void set_TableIDSKLAD_SARM(TFIBLargeIntField * TableIDSKLAD_SARM)=0;

   __property TFIBLargeIntField * TableIDPODR_SARM = {read = get_TableIDPODR_SARM , write = set_TableIDPODR_SARM};
   virtual TFIBLargeIntField * get_TableIDPODR_SARM(void)=0;
   virtual void set_TableIDPODR_SARM(TFIBLargeIntField * TableIDPODR_SARM)=0;

   __property TFIBLargeIntField * TableIDKKM_SARM = {read = get_TableIDKKM_SARM , write = set_TableIDKKM_SARM};
   virtual TFIBLargeIntField * get_TableIDKKM_SARM(void)=0;
   virtual void set_TableIDKKM_SARM(TFIBLargeIntField * TableIDKKM_SARM)=0;

   __property TFIBWideStringField * TableSTRPAR_SARM = {read = get_TableSTRPAR_SARM , write = set_TableSTRPAR_SARM};
   virtual TFIBWideStringField * get_TableSTRPAR_SARM(void)=0;
   virtual void set_TableSTRPAR_SARM(TFIBWideStringField * TableSTRPAR_SARM)=0;

   __property TFIBWideStringField * TablePREFIKS_SARM = {read = get_TablePREFIKS_SARM , write = set_TablePREFIKS_SARM};
   virtual TFIBWideStringField * get_TablePREFIKS_SARM(void)=0;
   virtual void set_TablePREFIKS_SARM(TFIBWideStringField * TablePREFIKS_SARM)=0;

   __property TFIBLargeIntField * TableIDBASE_SARM = {read = get_TableIDBASE_SARM , write = set_TableIDBASE_SARM};
   virtual TFIBLargeIntField * get_TableIDBASE_SARM(void)=0;
   virtual void set_TableIDBASE_SARM(TFIBLargeIntField * TableIDBASE_SARM)=0;

   __property TFIBLargeIntField * TableIDACTCATEGORY_SARM = {read = get_TableIDACTCATEGORY_SARM , write = set_TableIDACTCATEGORY_SARM};
   virtual TFIBLargeIntField * get_TableIDACTCATEGORY_SARM(void)=0;
   virtual void set_TableIDACTCATEGORY_SARM(TFIBLargeIntField * TableIDACTCATEGORY_SARM)=0;

   __property TFIBLargeIntField * ElementID_SARM = {read = get_ElementID_SARM , write = set_ElementID_SARM};
   virtual TFIBLargeIntField * get_ElementID_SARM(void)=0;
   virtual void set_ElementID_SARM(TFIBLargeIntField * ElementID_SARM)=0;

   __property TFIBWideStringField * ElementGID_SARM = {read = get_ElementGID_SARM , write = set_ElementGID_SARM};
   virtual TFIBWideStringField * get_ElementGID_SARM(void)=0;
   virtual void set_ElementGID_SARM(TFIBWideStringField * ElementGID_SARM)=0;

   __property TFIBWideStringField * ElementNAME_SARM = {read = get_ElementNAME_SARM , write = set_ElementNAME_SARM};
   virtual TFIBWideStringField * get_ElementNAME_SARM(void)=0;
   virtual void set_ElementNAME_SARM(TFIBWideStringField * ElementNAME_SARM)=0;

   __property TFIBIntegerField * ElementCODE_SARM = {read = get_ElementCODE_SARM , write = set_ElementCODE_SARM};
   virtual TFIBIntegerField * get_ElementCODE_SARM(void)=0;
   virtual void set_ElementCODE_SARM(TFIBIntegerField * ElementCODE_SARM)=0;

   __property TFIBLargeIntField * ElementIDFIRM_SARM = {read = get_ElementIDFIRM_SARM , write = set_ElementIDFIRM_SARM};
   virtual TFIBLargeIntField * get_ElementIDFIRM_SARM(void)=0;
   virtual void set_ElementIDFIRM_SARM(TFIBLargeIntField * ElementIDFIRM_SARM)=0;

   __property TFIBLargeIntField * ElementIDSKLAD_SARM = {read = get_ElementIDSKLAD_SARM , write = set_ElementIDSKLAD_SARM};
   virtual TFIBLargeIntField * get_ElementIDSKLAD_SARM(void)=0;
   virtual void set_ElementIDSKLAD_SARM(TFIBLargeIntField * ElementIDSKLAD_SARM)=0;

   __property TFIBLargeIntField * ElementIDPODR_SARM = {read = get_ElementIDPODR_SARM , write = set_ElementIDPODR_SARM};
   virtual TFIBLargeIntField * get_ElementIDPODR_SARM(void)=0;
   virtual void set_ElementIDPODR_SARM(TFIBLargeIntField * ElementIDPODR_SARM)=0;

   __property TFIBLargeIntField * ElementIDKKM_SARM = {read = get_ElementIDKKM_SARM , write = set_ElementIDKKM_SARM};
   virtual TFIBLargeIntField * get_ElementIDKKM_SARM(void)=0;
   virtual void set_ElementIDKKM_SARM(TFIBLargeIntField * ElementIDKKM_SARM)=0;

   __property TFIBWideStringField * ElementSTRPAR_SARM = {read = get_ElementSTRPAR_SARM , write = set_ElementSTRPAR_SARM};
   virtual TFIBWideStringField * get_ElementSTRPAR_SARM(void)=0;
   virtual void set_ElementSTRPAR_SARM(TFIBWideStringField * ElementSTRPAR_SARM)=0;

   __property TFIBWideStringField * ElementPREFIKS_SARM = {read = get_ElementPREFIKS_SARM , write = set_ElementPREFIKS_SARM};
   virtual TFIBWideStringField * get_ElementPREFIKS_SARM(void)=0;
   virtual void set_ElementPREFIKS_SARM(TFIBWideStringField * ElementPREFIKS_SARM)=0;

   __property TFIBLargeIntField * ElementIDBASE_SARM = {read = get_ElementIDBASE_SARM , write = set_ElementIDBASE_SARM};
   virtual TFIBLargeIntField * get_ElementIDBASE_SARM(void)=0;
   virtual void set_ElementIDBASE_SARM(TFIBLargeIntField * ElementIDBASE_SARM)=0;

   __property TFIBLargeIntField * ElementIDACTCATEGORY_SARM = {read = get_ElementIDACTCATEGORY_SARM , write = set_ElementIDACTCATEGORY_SARM};
   virtual TFIBLargeIntField * get_ElementIDACTCATEGORY_SARM(void)=0;
   virtual void set_ElementIDACTCATEGORY_SARM(TFIBLargeIntField * ElementIDACTCATEGORY_SARM)=0;

   __property TFIBWideStringField * ElementNAMEFIRM = {read = get_ElementNAMEFIRM , write = set_ElementNAMEFIRM};
   virtual TFIBWideStringField * get_ElementNAMEFIRM(void)=0;
   virtual void set_ElementNAMEFIRM(TFIBWideStringField * ElementNAMEFIRM)=0;

   __property TFIBWideStringField * ElementNAMESKLAD = {read = get_ElementNAMESKLAD , write = set_ElementNAMESKLAD};
   virtual TFIBWideStringField * get_ElementNAMESKLAD(void)=0;
   virtual void set_ElementNAMESKLAD(TFIBWideStringField * ElementNAMESKLAD)=0;

   __property TFIBWideStringField * ElementNAMEKKM = {read = get_ElementNAMEKKM , write = set_ElementNAMEKKM};
   virtual TFIBWideStringField * get_ElementNAMEKKM(void)=0;
   virtual void set_ElementNAMEKKM(TFIBWideStringField * ElementNAMEKKM)=0;

   __property TFIBWideStringField * ElementNAMEPOD = {read = get_ElementNAMEPOD , write = set_ElementNAMEPOD};
   virtual TFIBWideStringField * get_ElementNAMEPOD(void)=0;
   virtual void set_ElementNAMEPOD(TFIBWideStringField * ElementNAMEPOD)=0;

   __property TFIBLargeIntField * ElementIDTPRICEPOD = {read = get_ElementIDTPRICEPOD , write = set_ElementIDTPRICEPOD};
   virtual TFIBLargeIntField * get_ElementIDTPRICEPOD(void)=0;
   virtual void set_ElementIDTPRICEPOD(TFIBLargeIntField * ElementIDTPRICEPOD)=0;

   __property TFIBWideStringField * ElementNAME_TPRICE = {read = get_ElementNAME_TPRICE , write = set_ElementNAME_TPRICE};
   virtual TFIBWideStringField * get_ElementNAME_TPRICE(void)=0;
   virtual void set_ElementNAME_TPRICE(TFIBWideStringField * ElementNAME_TPRICE)=0;

   __property TFIBWideStringField * ElementNAME_SINFBASE_OBMEN = {read = get_ElementNAME_SINFBASE_OBMEN , write = set_ElementNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_ElementNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_ElementNAME_SINFBASE_OBMEN(TFIBWideStringField * ElementNAME_SINFBASE_OBMEN)=0;

   __property TFIBWideStringField * ElementNAME_REM_SACTCATEGORY = {read = get_ElementNAME_REM_SACTCATEGORY , write = set_ElementNAME_REM_SACTCATEGORY};
   virtual TFIBWideStringField * get_ElementNAME_REM_SACTCATEGORY(void)=0;
   virtual void set_ElementNAME_REM_SACTCATEGORY(TFIBWideStringField * ElementNAME_REM_SACTCATEGORY)=0;

   __property bool flSaveElement = {read = get_flSaveElement , write = set_flSaveElement};
   virtual bool get_flSaveElement(void)=0;
   virtual void set_flSaveElement(bool flSaveElement)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 Id)=0;
   virtual void NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void DeleteElement(__int64 Id)=0;
   virtual int FindPoCodu(int code)=0;
   virtual int FindPoName(String name)=0;
   virtual AnsiString GetGIDElement(__int64 id)=0;
   virtual AnsiString GetParameter(AnsiString parameter)=0;
   virtual int GetMaxCode(void)=0;
};
#define IID_IDMSprARM __uuidof(IDMSprARM)
#endif
