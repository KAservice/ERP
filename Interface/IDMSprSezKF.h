#ifndef UIDMSprSezKFH
#define UIDMSprSezKFH
#include "IMainInterface.h"
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{25440870-C702-493D-9A98-F58ED023CBED}")) IDMSprSezKF : public IMainInterface
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

   __property TFIBIntegerField * TableMONTH_SSEZKF = {read = get_TableMONTH_SSEZKF , write = set_TableMONTH_SSEZKF};
   virtual TFIBIntegerField * get_TableMONTH_SSEZKF(void)=0;
   virtual void set_TableMONTH_SSEZKF(TFIBIntegerField * TableMONTH_SSEZKF)=0;

   __property TFIBBCDField * TableVALUE_SSEZKF = {read = get_TableVALUE_SSEZKF , write = set_TableVALUE_SSEZKF};
   virtual TFIBBCDField * get_TableVALUE_SSEZKF(void)=0;
   virtual void set_TableVALUE_SSEZKF(TFIBBCDField * TableVALUE_SSEZKF)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBBCDField * TableID_SSEZKF = {read = get_TableID_SSEZKF , write = set_TableID_SSEZKF};
   virtual TFIBBCDField * get_TableID_SSEZKF(void)=0;
   virtual void set_TableID_SSEZKF(TFIBBCDField * TableID_SSEZKF)=0;

   __property TFIBBCDField * TableIDNOM_SSEZKF = {read = get_TableIDNOM_SSEZKF , write = set_TableIDNOM_SSEZKF};
   virtual TFIBBCDField * get_TableIDNOM_SSEZKF(void)=0;
   virtual void set_TableIDNOM_SSEZKF(TFIBBCDField * TableIDNOM_SSEZKF)=0;

   __property TFIBWideStringField * TableGID_SSEZKF = {read = get_TableGID_SSEZKF , write = set_TableGID_SSEZKF};
   virtual TFIBWideStringField * get_TableGID_SSEZKF(void)=0;
   virtual void set_TableGID_SSEZKF(TFIBWideStringField * TableGID_SSEZKF)=0;

   __property __int64 IdNom = {read = get_IdNom , write = set_IdNom};
   virtual __int64 get_IdNom(void)=0;
   virtual void set_IdNom(__int64 IdNom)=0;

   __property float KolEdProd = {read = get_KolEdProd , write = set_KolEdProd};
   virtual float get_KolEdProd(void)=0;
   virtual void set_KolEdProd(float KolEdProd)=0;

   __property float KFEdProd = {read = get_KFEdProd , write = set_KFEdProd};
   virtual float get_KFEdProd(void)=0;
   virtual void set_KFEdProd(float KFEdProd)=0;

   virtual void OpenTable(__int64 Nom)=0;
   virtual void NewElement(__int64 Nom)=0;
   virtual void DeleteElement()=0;
   virtual void SaveIsmen()=0;
   virtual void CancelIsmen()=0;
};
#define IID_IDMSprSezKF __uuidof(IDMSprSezKF)
#endif
