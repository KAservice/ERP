#ifndef UIREM_DMGurCustQueryH
#define UIREM_DMGurCustQueryH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMGurCustQuery)) IREM_DMGurCustQuery : public IMainInterface
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

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBLargeIntField * TableID_REM_CQUERY = {read = get_TableID_REM_CQUERY , write = set_TableID_REM_CQUERY};
   virtual TFIBLargeIntField * get_TableID_REM_CQUERY(void)=0;
   virtual void set_TableID_REM_CQUERY(TFIBLargeIntField * TableID_REM_CQUERY)=0;

   __property TFIBWideStringField * TableGID_REM_CQUERY = {read = get_TableGID_REM_CQUERY , write = set_TableGID_REM_CQUERY};
   virtual TFIBWideStringField * get_TableGID_REM_CQUERY(void)=0;
   virtual void set_TableGID_REM_CQUERY(TFIBWideStringField * TableGID_REM_CQUERY)=0;

   __property TFIBLargeIntField * TableIDBASE_REM_CQUERY = {read = get_TableIDBASE_REM_CQUERY , write = set_TableIDBASE_REM_CQUERY};
   virtual TFIBLargeIntField * get_TableIDBASE_REM_CQUERY(void)=0;
   virtual void set_TableIDBASE_REM_CQUERY(TFIBLargeIntField * TableIDBASE_REM_CQUERY)=0;

   __property TFIBDateTimeField * TablePOS_REM_CQUERY = {read = get_TablePOS_REM_CQUERY , write = set_TablePOS_REM_CQUERY};
   virtual TFIBDateTimeField * get_TablePOS_REM_CQUERY(void)=0;
   virtual void set_TablePOS_REM_CQUERY(TFIBDateTimeField * TablePOS_REM_CQUERY)=0;

   __property TFIBIntegerField * TableNUM_REM_CQUERY = {read = get_TableNUM_REM_CQUERY , write = set_TableNUM_REM_CQUERY};
   virtual TFIBIntegerField * get_TableNUM_REM_CQUERY(void)=0;
   virtual void set_TableNUM_REM_CQUERY(TFIBIntegerField * TableNUM_REM_CQUERY)=0;

   __property TFIBLargeIntField * TableIDFIRM_REM_CQUERY = {read = get_TableIDFIRM_REM_CQUERY , write = set_TableIDFIRM_REM_CQUERY};
   virtual TFIBLargeIntField * get_TableIDFIRM_REM_CQUERY(void)=0;
   virtual void set_TableIDFIRM_REM_CQUERY(TFIBLargeIntField * TableIDFIRM_REM_CQUERY)=0;

   __property TFIBLargeIntField * TableIDSKLAD_REM_CQUERY = {read = get_TableIDSKLAD_REM_CQUERY , write = set_TableIDSKLAD_REM_CQUERY};
   virtual TFIBLargeIntField * get_TableIDSKLAD_REM_CQUERY(void)=0;
   virtual void set_TableIDSKLAD_REM_CQUERY(TFIBLargeIntField * TableIDSKLAD_REM_CQUERY)=0;

   __property TFIBLargeIntField * TableIDUSER_REM_CQUERY = {read = get_TableIDUSER_REM_CQUERY , write = set_TableIDUSER_REM_CQUERY};
   virtual TFIBLargeIntField * get_TableIDUSER_REM_CQUERY(void)=0;
   virtual void set_TableIDUSER_REM_CQUERY(TFIBLargeIntField * TableIDUSER_REM_CQUERY)=0;

   __property TFIBLargeIntField * TableIDKLIENT_REM_CQUERY = {read = get_TableIDKLIENT_REM_CQUERY , write = set_TableIDKLIENT_REM_CQUERY};
   virtual TFIBLargeIntField * get_TableIDKLIENT_REM_CQUERY(void)=0;
   virtual void set_TableIDKLIENT_REM_CQUERY(TFIBLargeIntField * TableIDKLIENT_REM_CQUERY)=0;

   __property TFIBWideStringField * TableKLIENT_NAME_REM_CQUERY = {read = get_TableKLIENT_NAME_REM_CQUERY , write = set_TableKLIENT_NAME_REM_CQUERY};
   virtual TFIBWideStringField * get_TableKLIENT_NAME_REM_CQUERY(void)=0;
   virtual void set_TableKLIENT_NAME_REM_CQUERY(TFIBWideStringField * TableKLIENT_NAME_REM_CQUERY)=0;

   __property TFIBWideStringField * TableKLIENT_ADR_REM_CQUERY = {read = get_TableKLIENT_ADR_REM_CQUERY , write = set_TableKLIENT_ADR_REM_CQUERY};
   virtual TFIBWideStringField * get_TableKLIENT_ADR_REM_CQUERY(void)=0;
   virtual void set_TableKLIENT_ADR_REM_CQUERY(TFIBWideStringField * TableKLIENT_ADR_REM_CQUERY)=0;

   __property TFIBWideStringField * TableKLIENT_PHONE_REM_CQUERY = {read = get_TableKLIENT_PHONE_REM_CQUERY , write = set_TableKLIENT_PHONE_REM_CQUERY};
   virtual TFIBWideStringField * get_TableKLIENT_PHONE_REM_CQUERY(void)=0;
   virtual void set_TableKLIENT_PHONE_REM_CQUERY(TFIBWideStringField * TableKLIENT_PHONE_REM_CQUERY)=0;

   __property TFIBWideStringField * TableCOMMENTS_REM_CQUERY = {read = get_TableCOMMENTS_REM_CQUERY , write = set_TableCOMMENTS_REM_CQUERY};
   virtual TFIBWideStringField * get_TableCOMMENTS_REM_CQUERY(void)=0;
   virtual void set_TableCOMMENTS_REM_CQUERY(TFIBWideStringField * TableCOMMENTS_REM_CQUERY)=0;

   __property TFIBSmallIntField * TableRUN_REM_CQUERY = {read = get_TableRUN_REM_CQUERY , write = set_TableRUN_REM_CQUERY};
   virtual TFIBSmallIntField * get_TableRUN_REM_CQUERY(void)=0;
   virtual void set_TableRUN_REM_CQUERY(TFIBSmallIntField * TableRUN_REM_CQUERY)=0;

   __property TFIBBCDField * TableDO_SUM_REM_CQUERY = {read = get_TableDO_SUM_REM_CQUERY , write = set_TableDO_SUM_REM_CQUERY};
   virtual TFIBBCDField * get_TableDO_SUM_REM_CQUERY(void)=0;
   virtual void set_TableDO_SUM_REM_CQUERY(TFIBBCDField * TableDO_SUM_REM_CQUERY)=0;

   __property TFIBBCDField * TableTEC_SUM_REM_CQUERY = {read = get_TableTEC_SUM_REM_CQUERY , write = set_TableTEC_SUM_REM_CQUERY};
   virtual TFIBBCDField * get_TableTEC_SUM_REM_CQUERY(void)=0;
   virtual void set_TableTEC_SUM_REM_CQUERY(TFIBBCDField * TableTEC_SUM_REM_CQUERY)=0;

   __property TFIBBCDField * TableSOGL_SUM_REM_CQUERY = {read = get_TableSOGL_SUM_REM_CQUERY , write = set_TableSOGL_SUM_REM_CQUERY};
   virtual TFIBBCDField * get_TableSOGL_SUM_REM_CQUERY(void)=0;
   virtual void set_TableSOGL_SUM_REM_CQUERY(TFIBBCDField * TableSOGL_SUM_REM_CQUERY)=0;

   __property TFIBLargeIntField * TableIDZ_REM_CQUERY = {read = get_TableIDZ_REM_CQUERY , write = set_TableIDZ_REM_CQUERY};
   virtual TFIBLargeIntField * get_TableIDZ_REM_CQUERY(void)=0;
   virtual void set_TableIDZ_REM_CQUERY(TFIBLargeIntField * TableIDZ_REM_CQUERY)=0;

   __property TFIBLargeIntField * TableIDMODEL_REM_CQUERY = {read = get_TableIDMODEL_REM_CQUERY , write = set_TableIDMODEL_REM_CQUERY};
   virtual TFIBLargeIntField * get_TableIDMODEL_REM_CQUERY(void)=0;
   virtual void set_TableIDMODEL_REM_CQUERY(TFIBLargeIntField * TableIDMODEL_REM_CQUERY)=0;

   __property TFIBWideStringField * TableNAME_MODEL_REM_CQUERY = {read = get_TableNAME_MODEL_REM_CQUERY , write = set_TableNAME_MODEL_REM_CQUERY};
   virtual TFIBWideStringField * get_TableNAME_MODEL_REM_CQUERY(void)=0;
   virtual void set_TableNAME_MODEL_REM_CQUERY(TFIBWideStringField * TableNAME_MODEL_REM_CQUERY)=0;

   __property TFIBWideStringField * TableNAMEFIRM = {read = get_TableNAMEFIRM , write = set_TableNAMEFIRM};
   virtual TFIBWideStringField * get_TableNAMEFIRM(void)=0;
   virtual void set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM)=0;

   __property TFIBWideStringField * TableNAME_REM_SMODEL = {read = get_TableNAME_REM_SMODEL , write = set_TableNAME_REM_SMODEL};
   virtual TFIBWideStringField * get_TableNAME_REM_SMODEL(void)=0;
   virtual void set_TableNAME_REM_SMODEL(TFIBWideStringField * TableNAME_REM_SMODEL)=0;

   __property TFIBWideStringField * TableNAMESKLAD = {read = get_TableNAMESKLAD , write = set_TableNAMESKLAD};
   virtual TFIBWideStringField * get_TableNAMESKLAD(void)=0;
   virtual void set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)=0;

   __property TFIBWideStringField * TableNAMEKLIENT = {read = get_TableNAMEKLIENT , write = set_TableNAMEKLIENT};
   virtual TFIBWideStringField * get_TableNAMEKLIENT(void)=0;
   virtual void set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)=0;

   __property TFIBWideStringField * TableNAME_USER = {read = get_TableNAME_USER , write = set_TableNAME_USER};
   virtual TFIBWideStringField * get_TableNAME_USER(void)=0;
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)=0;

   __property TFIBLargeIntField * TableIDBRAND_REM_CQUERY = {read = get_TableIDBRAND_REM_CQUERY , write = set_TableIDBRAND_REM_CQUERY};
   virtual TFIBLargeIntField * get_TableIDBRAND_REM_CQUERY(void)=0;
   virtual void set_TableIDBRAND_REM_CQUERY(TFIBLargeIntField * TableIDBRAND_REM_CQUERY)=0;

   __property TFIBLargeIntField * TableIDPRODUCER_REM_CQUERY = {read = get_TableIDPRODUCER_REM_CQUERY , write = set_TableIDPRODUCER_REM_CQUERY};
   virtual TFIBLargeIntField * get_TableIDPRODUCER_REM_CQUERY(void)=0;
   virtual void set_TableIDPRODUCER_REM_CQUERY(TFIBLargeIntField * TableIDPRODUCER_REM_CQUERY)=0;

   __property TFIBSmallIntField * TableFL_KLIENT_UVEDOML_REM_CQUERY = {read = get_TableFL_KLIENT_UVEDOML_REM_CQUERY , write = set_TableFL_KLIENT_UVEDOML_REM_CQUERY};
   virtual TFIBSmallIntField * get_TableFL_KLIENT_UVEDOML_REM_CQUERY(void)=0;
   virtual void set_TableFL_KLIENT_UVEDOML_REM_CQUERY(TFIBSmallIntField * TableFL_KLIENT_UVEDOML_REM_CQUERY)=0;

   __property TFIBWideStringField * TableNAME_SBRAND = {read = get_TableNAME_SBRAND , write = set_TableNAME_SBRAND};
   virtual TFIBWideStringField * get_TableNAME_SBRAND(void)=0;
   virtual void set_TableNAME_SBRAND(TFIBWideStringField * TableNAME_SBRAND)=0;

   __property TFIBWideStringField * TableNAME_SPRODUCER = {read = get_TableNAME_SPRODUCER , write = set_TableNAME_SPRODUCER};
   virtual TFIBWideStringField * get_TableNAME_SPRODUCER(void)=0;
   virtual void set_TableNAME_SPRODUCER(TFIBWideStringField * TableNAME_SPRODUCER)=0;

   __property TFIBIntegerField * TableNUM_ZAKAZA_REM_CQUERY = {read = get_TableNUM_ZAKAZA_REM_CQUERY , write = set_TableNUM_ZAKAZA_REM_CQUERY};
   virtual TFIBIntegerField * get_TableNUM_ZAKAZA_REM_CQUERY(void)=0;
   virtual void set_TableNUM_ZAKAZA_REM_CQUERY(TFIBIntegerField * TableNUM_ZAKAZA_REM_CQUERY)=0;

   __property TFIBDateField * TableDATE_ZAKAZA_REM_CQUERY = {read = get_TableDATE_ZAKAZA_REM_CQUERY , write = set_TableDATE_ZAKAZA_REM_CQUERY};
   virtual TFIBDateField * get_TableDATE_ZAKAZA_REM_CQUERY(void)=0;
   virtual void set_TableDATE_ZAKAZA_REM_CQUERY(TFIBDateField * TableDATE_ZAKAZA_REM_CQUERY)=0;

   __property TFIBIntegerField * TableTYPE_REM_CQUERY = {read = get_TableTYPE_REM_CQUERY , write = set_TableTYPE_REM_CQUERY};
   virtual TFIBIntegerField * get_TableTYPE_REM_CQUERY(void)=0;
   virtual void set_TableTYPE_REM_CQUERY(TFIBIntegerField * TableTYPE_REM_CQUERY)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property __int64 IdCustQuery = {read = get_IdCustQuery , write = set_IdCustQuery};
   virtual __int64 get_IdCustQuery(void)=0;
   virtual void set_IdCustQuery(__int64 IdCustQuery)=0;

   __property TDateTime PosNach = {read = get_PosNach , write = set_PosNach};
   virtual TDateTime get_PosNach(void)=0;
   virtual void set_PosNach(TDateTime PosNach)=0;

   __property TDateTime PosCon = {read = get_PosCon , write = set_PosCon};
   virtual TDateTime get_PosCon(void)=0;
   virtual void set_PosCon(TDateTime PosCon)=0;

   virtual void OpenTable()=0;
   virtual void UpdateTable(void)=0;
   virtual bool OpenTableOnlyZayavka(__int64 id_z)=0;
   virtual void PoiskPoKlient(UnicodeString value)=0;
   virtual void PoiskPoModel(UnicodeString value)=0;
   virtual void OpenTableGur (__int64 id_user, int poisk, TDateTime pos_nach, TDateTime pos_con, UnicodeString value_str, __int64 value_int64)=0;
   virtual void OpenTablePoNumZakaza (__int64 id_user, __int64 id_producer,int number_zakaza, TDate date_zakaza)=0;
};
#define IID_IREM_DMGurCustQuery __uuidof(IREM_DMGurCustQuery)
#endif
