#ifndef UIDMSprSostProdH
#define UIDMSprSostProdH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprSostProd)) IDMSprSostProd : public IMainInterface
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

   __property TFIBBCDField * TableNKOL_SPROD = {read = get_TableNKOL_SPROD , write = set_TableNKOL_SPROD};
   virtual TFIBBCDField * get_TableNKOL_SPROD(void)=0;
   virtual void set_TableNKOL_SPROD(TFIBBCDField * TableNKOL_SPROD)=0;

   __property TFIBBCDField * TableBKOL_SPROD = {read = get_TableBKOL_SPROD , write = set_TableBKOL_SPROD};
   virtual TFIBBCDField * get_TableBKOL_SPROD(void)=0;
   virtual void set_TableBKOL_SPROD(TFIBBCDField * TableBKOL_SPROD)=0;

   __property TFIBBCDField * TableKFPRICE_SPROD = {read = get_TableKFPRICE_SPROD , write = set_TableKFPRICE_SPROD};
   virtual TFIBBCDField * get_TableKFPRICE_SPROD(void)=0;
   virtual void set_TableKFPRICE_SPROD(TFIBBCDField * TableKFPRICE_SPROD)=0;

   __property TFIBSmallIntField * TableSPIS_SPROD = {read = get_TableSPIS_SPROD , write = set_TableSPIS_SPROD};
   virtual TFIBSmallIntField * get_TableSPIS_SPROD(void)=0;
   virtual void set_TableSPIS_SPROD(TFIBSmallIntField * TableSPIS_SPROD)=0;

   __property TFIBBCDField * TableKF_SPROD = {read = get_TableKF_SPROD , write = set_TableKF_SPROD};
   virtual TFIBBCDField * get_TableKF_SPROD(void)=0;
   virtual void set_TableKF_SPROD(TFIBBCDField * TableKF_SPROD)=0;

   __property TFIBIntegerField * TableTNOM = {read = get_TableTNOM , write = set_TableTNOM};
   virtual TFIBIntegerField * get_TableTNOM(void)=0;
   virtual void set_TableTNOM(TFIBIntegerField * TableTNOM)=0;

   __property TFIBBCDField * TableVALUE_SSEZKF = {read = get_TableVALUE_SSEZKF , write = set_TableVALUE_SSEZKF};
   virtual TFIBBCDField * get_TableVALUE_SSEZKF(void)=0;
   virtual void set_TableVALUE_SSEZKF(TFIBBCDField * TableVALUE_SSEZKF)=0;

   __property TFIBBCDField * TableVALUE_SSEZKF_SPROD = {read = get_TableVALUE_SSEZKF_SPROD , write = set_TableVALUE_SSEZKF_SPROD};
   virtual TFIBBCDField * get_TableVALUE_SSEZKF_SPROD(void)=0;
   virtual void set_TableVALUE_SSEZKF_SPROD(TFIBBCDField * TableVALUE_SSEZKF_SPROD)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFloatField * TableNABASED = {read = get_TableNABASED , write = set_TableNABASED};
   virtual TFloatField * get_TableNABASED(void)=0;
   virtual void set_TableNABASED(TFloatField * TableNABASED)=0;

   __property TFloatField * TableNNABASED = {read = get_TableNNABASED , write = set_TableNNABASED};
   virtual TFloatField * get_TableNNABASED(void)=0;
   virtual void set_TableNNABASED(TFloatField * TableNNABASED)=0;

   __property TFloatField * TableSEZKF = {read = get_TableSEZKF , write = set_TableSEZKF};
   virtual TFloatField * get_TableSEZKF(void)=0;
   virtual void set_TableSEZKF(TFloatField * TableSEZKF)=0;

   __property TFloatField * TableSEZKF_SPROD = {read = get_TableSEZKF_SPROD , write = set_TableSEZKF_SPROD};
   virtual TFloatField * get_TableSEZKF_SPROD(void)=0;
   virtual void set_TableSEZKF_SPROD(TFloatField * TableSEZKF_SPROD)=0;

   __property TFIBBCDField * TableID_SPROD = {read = get_TableID_SPROD , write = set_TableID_SPROD};
   virtual TFIBBCDField * get_TableID_SPROD(void)=0;
   virtual void set_TableID_SPROD(TFIBBCDField * TableID_SPROD)=0;

   __property TFIBBCDField * TableIDNOMREST_SPROD = {read = get_TableIDNOMREST_SPROD , write = set_TableIDNOMREST_SPROD};
   virtual TFIBBCDField * get_TableIDNOMREST_SPROD(void)=0;
   virtual void set_TableIDNOMREST_SPROD(TFIBBCDField * TableIDNOMREST_SPROD)=0;

   __property TFIBBCDField * TableIDKOMPL_SPROD = {read = get_TableIDKOMPL_SPROD , write = set_TableIDKOMPL_SPROD};
   virtual TFIBBCDField * get_TableIDKOMPL_SPROD(void)=0;
   virtual void set_TableIDKOMPL_SPROD(TFIBBCDField * TableIDKOMPL_SPROD)=0;

   __property TFIBBCDField * TableIDED_SPROD = {read = get_TableIDED_SPROD , write = set_TableIDED_SPROD};
   virtual TFIBBCDField * get_TableIDED_SPROD(void)=0;
   virtual void set_TableIDED_SPROD(TFIBBCDField * TableIDED_SPROD)=0;

   __property TFIBWideStringField * TableGID_SSPROD = {read = get_TableGID_SSPROD , write = set_TableGID_SSPROD};
   virtual TFIBWideStringField * get_TableGID_SSPROD(void)=0;
   virtual void set_TableGID_SSPROD(TFIBWideStringField * TableGID_SSPROD)=0;

   __property TFIBWideStringField * TableNAMENOM = {read = get_TableNAMENOM , write = set_TableNAMENOM};
   virtual TFIBWideStringField * get_TableNAMENOM(void)=0;
   virtual void set_TableNAMENOM(TFIBWideStringField * TableNAMENOM)=0;

   __property TFIBWideStringField * TableNAMEED = {read = get_TableNAMEED , write = set_TableNAMEED};
   virtual TFIBWideStringField * get_TableNAMEED(void)=0;
   virtual void set_TableNAMEED(TFIBWideStringField * TableNAMEED)=0;

   __property TFIBBCDField * TableIDPRODUCE_SSPROD = {read = get_TableIDPRODUCE_SSPROD , write = set_TableIDPRODUCE_SSPROD};
   virtual TFIBBCDField * get_TableIDPRODUCE_SSPROD(void)=0;
   virtual void set_TableIDPRODUCE_SSPROD(TFIBBCDField * TableIDPRODUCE_SSPROD)=0;

   __property TFIBBCDField * TableIDLOSTFACTOR_SSPROD = {read = get_TableIDLOSTFACTOR_SSPROD , write = set_TableIDLOSTFACTOR_SSPROD};
   virtual TFIBBCDField * get_TableIDLOSTFACTOR_SSPROD(void)=0;
   virtual void set_TableIDLOSTFACTOR_SSPROD(TFIBBCDField * TableIDLOSTFACTOR_SSPROD)=0;

   __property TFIBWideStringField * TableNAME_SPRODUCE = {read = get_TableNAME_SPRODUCE , write = set_TableNAME_SPRODUCE};
   virtual TFIBWideStringField * get_TableNAME_SPRODUCE(void)=0;
   virtual void set_TableNAME_SPRODUCE(TFIBWideStringField * TableNAME_SPRODUCE)=0;

   __property TFIBWideStringField * TableNAME_SLOSS_FACTOR = {read = get_TableNAME_SLOSS_FACTOR , write = set_TableNAME_SLOSS_FACTOR};
   virtual TFIBWideStringField * get_TableNAME_SLOSS_FACTOR(void)=0;
   virtual void set_TableNAME_SLOSS_FACTOR(TFIBWideStringField * TableNAME_SLOSS_FACTOR)=0;

   __property __int64 IdNom = {read = get_IdNom , write = set_IdNom};
   virtual __int64 get_IdNom(void)=0;
   virtual void set_IdNom(__int64 IdNom)=0;

   __property __int64 IdNomRest = {read = get_IdNomRest , write = set_IdNomRest};
   virtual __int64 get_IdNomRest(void)=0;
   virtual void set_IdNomRest(__int64 IdNomRest)=0;

   __property float KolEdProd = {read = get_KolEdProd , write = set_KolEdProd};
   virtual float get_KolEdProd(void)=0;
   virtual void set_KolEdProd(float KolEdProd)=0;

   __property float KFEdProd = {read = get_KFEdProd , write = set_KFEdProd};
   virtual float get_KFEdProd(void)=0;
   virtual void set_KFEdProd(float KFEdProd)=0;

   __property TDateTime Pos = {read = get_Pos , write = set_Pos};
   virtual TDateTime get_Pos(void)=0;
   virtual void set_Pos(TDateTime Pos)=0;

   virtual void OpenTable(__int64 Nom)=0;
   virtual void NewElement(__int64 Nom)=0;
   virtual void DeleteElement()=0;
   virtual void SaveIsmen()=0;
   virtual void CancelIsmen()=0;
};
#define IID_IDMSprSostProd __uuidof(IDMSprSostProd)
#endif
