#ifndef UIDMSprSezKFSProdH
#define UIDMSprSezKFSProdH
#include "IMainInterface.h"
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{3C312C33-ED43-44D7-97C3-20D489C5FA6B}")) IDMSprSezKFSProd : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TFIBIntegerField * TableMONTH_SSEZKF_SPROD = {read = get_TableMONTH_SSEZKF_SPROD , write = set_TableMONTH_SSEZKF_SPROD};
   virtual TFIBIntegerField * get_TableMONTH_SSEZKF_SPROD(void)=0;
   virtual void set_TableMONTH_SSEZKF_SPROD(TFIBIntegerField * TableMONTH_SSEZKF_SPROD)=0;

   __property TFIBBCDField * TableVALUE_SSEZKF_SPROD = {read = get_TableVALUE_SSEZKF_SPROD , write = set_TableVALUE_SSEZKF_SPROD};
   virtual TFIBBCDField * get_TableVALUE_SSEZKF_SPROD(void)=0;
   virtual void set_TableVALUE_SSEZKF_SPROD(TFIBBCDField * TableVALUE_SSEZKF_SPROD)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBBCDField * TableID_SSEZKF_SPROD = {read = get_TableID_SSEZKF_SPROD , write = set_TableID_SSEZKF_SPROD};
   virtual TFIBBCDField * get_TableID_SSEZKF_SPROD(void)=0;
   virtual void set_TableID_SSEZKF_SPROD(TFIBBCDField * TableID_SSEZKF_SPROD)=0;

   __property TFIBBCDField * TableIDSSPROD_SSEZKF_SPROD = {read = get_TableIDSSPROD_SSEZKF_SPROD , write = set_TableIDSSPROD_SSEZKF_SPROD};
   virtual TFIBBCDField * get_TableIDSSPROD_SSEZKF_SPROD(void)=0;
   virtual void set_TableIDSSPROD_SSEZKF_SPROD(TFIBBCDField * TableIDSSPROD_SSEZKF_SPROD)=0;

   __property TFIBWideStringField * TableGID_SSEZKF_SPROD = {read = get_TableGID_SSEZKF_SPROD , write = set_TableGID_SSEZKF_SPROD};
   virtual TFIBWideStringField * get_TableGID_SSEZKF_SPROD(void)=0;
   virtual void set_TableGID_SSEZKF_SPROD(TFIBWideStringField * TableGID_SSEZKF_SPROD)=0;

   __property __int64 IdSProd = {read = get_IdSProd , write = set_IdSProd};
   virtual __int64 get_IdSProd(void)=0;
   virtual void set_IdSProd(__int64 IdSProd)=0;

   virtual void OpenTable(__int64 idSProd)=0;
   virtual void NewElement(__int64 idSProd)=0;
   virtual void DeleteElement()=0;
   virtual void SaveIsmen()=0;
   virtual void CancelIsmen()=0;
};
#define IID_IDMSprSezKFSProd __uuidof(IDMSprSezKFSProd)
#endif
