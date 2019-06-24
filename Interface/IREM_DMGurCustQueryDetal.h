#ifndef UIREM_DMGurCustQueryDetalH
#define UIREM_DMGurCustQueryDetalH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMGurCustQueryDetal)) IREM_DMGurCustQueryDetal : public IMainInterface
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

   __property TFIBWideStringField * TableNAMENOM_REM_CQUERYT = {read = get_TableNAMENOM_REM_CQUERYT , write = set_TableNAMENOM_REM_CQUERYT};
   virtual TFIBWideStringField * get_TableNAMENOM_REM_CQUERYT(void)=0;
   virtual void set_TableNAMENOM_REM_CQUERYT(TFIBWideStringField * TableNAMENOM_REM_CQUERYT)=0;

   __property TFIBIntegerField * TableCODENOM = {read = get_TableCODENOM , write = set_TableCODENOM};
   virtual TFIBIntegerField * get_TableCODENOM(void)=0;
   virtual void set_TableCODENOM(TFIBIntegerField * TableCODENOM)=0;

   __property TFIBWideStringField * TableARTNOM = {read = get_TableARTNOM , write = set_TableARTNOM};
   virtual TFIBWideStringField * get_TableARTNOM(void)=0;
   virtual void set_TableARTNOM(TFIBWideStringField * TableARTNOM)=0;

   __property TFIBWideStringField * TableNAMENOM = {read = get_TableNAMENOM , write = set_TableNAMENOM};
   virtual TFIBWideStringField * get_TableNAMENOM(void)=0;
   virtual void set_TableNAMENOM(TFIBWideStringField * TableNAMENOM)=0;

   __property TFIBBCDField * TableKOL_REM_CQUERYT = {read = get_TableKOL_REM_CQUERYT , write = set_TableKOL_REM_CQUERYT};
   virtual TFIBBCDField * get_TableKOL_REM_CQUERYT(void)=0;
   virtual void set_TableKOL_REM_CQUERYT(TFIBBCDField * TableKOL_REM_CQUERYT)=0;

   __property TFIBBCDField * TableKF_REM_CQUERYT = {read = get_TableKF_REM_CQUERYT , write = set_TableKF_REM_CQUERYT};
   virtual TFIBBCDField * get_TableKF_REM_CQUERYT(void)=0;
   virtual void set_TableKF_REM_CQUERYT(TFIBBCDField * TableKF_REM_CQUERYT)=0;

   __property TFIBBCDField * TablePRICE_REM_CQUERYT = {read = get_TablePRICE_REM_CQUERYT , write = set_TablePRICE_REM_CQUERYT};
   virtual TFIBBCDField * get_TablePRICE_REM_CQUERYT(void)=0;
   virtual void set_TablePRICE_REM_CQUERYT(TFIBBCDField * TablePRICE_REM_CQUERYT)=0;

   __property TFIBBCDField * TableNOM_SUM_STR = {read = get_TableNOM_SUM_STR , write = set_TableNOM_SUM_STR};
   virtual TFIBBCDField * get_TableNOM_SUM_STR(void)=0;
   virtual void set_TableNOM_SUM_STR(TFIBBCDField * TableNOM_SUM_STR)=0;

   __property TFIBIntegerField * TableCODE_SPRNOM = {read = get_TableCODE_SPRNOM , write = set_TableCODE_SPRNOM};
   virtual TFIBIntegerField * get_TableCODE_SPRNOM(void)=0;
   virtual void set_TableCODE_SPRNOM(TFIBIntegerField * TableCODE_SPRNOM)=0;

   __property TFIBWideStringField * TableART_SPRNOM = {read = get_TableART_SPRNOM , write = set_TableART_SPRNOM};
   virtual TFIBWideStringField * get_TableART_SPRNOM(void)=0;
   virtual void set_TableART_SPRNOM(TFIBWideStringField * TableART_SPRNOM)=0;

   __property TFIBWideStringField * TableNAME_SPRNOM = {read = get_TableNAME_SPRNOM , write = set_TableNAME_SPRNOM};
   virtual TFIBWideStringField * get_TableNAME_SPRNOM(void)=0;
   virtual void set_TableNAME_SPRNOM(TFIBWideStringField * TableNAME_SPRNOM)=0;

   __property TFIBSmallIntField * TableFL_DOSTUPNO_SPRNOM = {read = get_TableFL_DOSTUPNO_SPRNOM , write = set_TableFL_DOSTUPNO_SPRNOM};
   virtual TFIBSmallIntField * get_TableFL_DOSTUPNO_SPRNOM(void)=0;
   virtual void set_TableFL_DOSTUPNO_SPRNOM(TFIBSmallIntField * TableFL_DOSTUPNO_SPRNOM)=0;

   __property TFIBBCDField * TablePRICE_ZAKUP_SPRNOM = {read = get_TablePRICE_ZAKUP_SPRNOM , write = set_TablePRICE_ZAKUP_SPRNOM};
   virtual TFIBBCDField * get_TablePRICE_ZAKUP_SPRNOM(void)=0;
   virtual void set_TablePRICE_ZAKUP_SPRNOM(TFIBBCDField * TablePRICE_ZAKUP_SPRNOM)=0;

   __property TFIBBCDField * TablePRNOM_SUM_STR = {read = get_TablePRNOM_SUM_STR , write = set_TablePRNOM_SUM_STR};
   virtual TFIBBCDField * get_TablePRNOM_SUM_STR(void)=0;
   virtual void set_TablePRNOM_SUM_STR(TFIBBCDField * TablePRNOM_SUM_STR)=0;

   __property TFIBLargeIntField * TableID_REM_CQUERYT = {read = get_TableID_REM_CQUERYT , write = set_TableID_REM_CQUERYT};
   virtual TFIBLargeIntField * get_TableID_REM_CQUERYT(void)=0;
   virtual void set_TableID_REM_CQUERYT(TFIBLargeIntField * TableID_REM_CQUERYT)=0;

   __property TFIBWideStringField * TablePRODAVEC_NAME = {read = get_TablePRODAVEC_NAME , write = set_TablePRODAVEC_NAME};
   virtual TFIBWideStringField * get_TablePRODAVEC_NAME(void)=0;
   virtual void set_TablePRODAVEC_NAME(TFIBWideStringField * TablePRODAVEC_NAME)=0;

   __property TFIBWideStringField * TableNUM_STR_ZAK_POST_REM_CQUERY = {read = get_TableNUM_STR_ZAK_POST_REM_CQUERY , write = set_TableNUM_STR_ZAK_POST_REM_CQUERY};
   virtual TFIBWideStringField * get_TableNUM_STR_ZAK_POST_REM_CQUERY(void)=0;
   virtual void set_TableNUM_STR_ZAK_POST_REM_CQUERY(TFIBWideStringField * TableNUM_STR_ZAK_POST_REM_CQUERY)=0;

   __property TFIBWideStringField * TableNUM_STR_ZAK_SPROV_REM_CQUERY = {read = get_TableNUM_STR_ZAK_SPROV_REM_CQUERY , write = set_TableNUM_STR_ZAK_SPROV_REM_CQUERY};
   virtual TFIBWideStringField * get_TableNUM_STR_ZAK_SPROV_REM_CQUERY(void)=0;
   virtual void set_TableNUM_STR_ZAK_SPROV_REM_CQUERY(TFIBWideStringField * TableNUM_STR_ZAK_SPROV_REM_CQUERY)=0;

   __property TFIBWideStringField * TableNUMDOCTK_REM_CQUERY = {read = get_TableNUMDOCTK_REM_CQUERY , write = set_TableNUMDOCTK_REM_CQUERY};
   virtual TFIBWideStringField * get_TableNUMDOCTK_REM_CQUERY(void)=0;
   virtual void set_TableNUMDOCTK_REM_CQUERY(TFIBWideStringField * TableNUMDOCTK_REM_CQUERY)=0;

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
#define IID_IREM_DMGurCustQueryDetal __uuidof(IREM_DMGurCustQueryDetal)
#endif
