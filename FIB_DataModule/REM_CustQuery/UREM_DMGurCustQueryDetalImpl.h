#ifndef UREM_DMGurCustQueryDetalImplH
#define UREM_DMGurCustQueryDetalImplH
#include "IREM_DMGurCustQueryDetal.h"
#include "UREM_DMGurCustQueryDetal.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMGurCustQueryDetalImpl)) TREM_DMGurCustQueryDetalImpl : public IREM_DMGurCustQueryDetal
{
public:
   TREM_DMGurCustQueryDetalImpl();
   ~TREM_DMGurCustQueryDetalImpl();
   TREM_DMGurCustQueryDetal * Object;
   int NumRefs;
   bool flDeleteObject;
   void DeleteImpl(void);

   //IUnknown
   virtual int kanQueryInterface(REFIID id_interface,void ** ppv);
   virtual int kanAddRef(void);
   virtual int kanRelease(void);

   //IMainInterface
   virtual int  get_CodeError(void);
   virtual void set_CodeError(int CodeError);
   virtual UnicodeString  get_TextError(void);
   virtual void set_TextError(UnicodeString  TextError);
   virtual int Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object);
   virtual int Done(void);

//IREM_DMGurCustQueryDetal
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBLargeIntField * get_TableID_REM_CQUERY(void);
   virtual void set_TableID_REM_CQUERY(TFIBLargeIntField * TableID_REM_CQUERY);

   virtual TFIBWideStringField * get_TableGID_REM_CQUERY(void);
   virtual void set_TableGID_REM_CQUERY(TFIBWideStringField * TableGID_REM_CQUERY);

   virtual TFIBLargeIntField * get_TableIDBASE_REM_CQUERY(void);
   virtual void set_TableIDBASE_REM_CQUERY(TFIBLargeIntField * TableIDBASE_REM_CQUERY);

   virtual TFIBDateTimeField * get_TablePOS_REM_CQUERY(void);
   virtual void set_TablePOS_REM_CQUERY(TFIBDateTimeField * TablePOS_REM_CQUERY);

   virtual TFIBIntegerField * get_TableNUM_REM_CQUERY(void);
   virtual void set_TableNUM_REM_CQUERY(TFIBIntegerField * TableNUM_REM_CQUERY);

   virtual TFIBLargeIntField * get_TableIDFIRM_REM_CQUERY(void);
   virtual void set_TableIDFIRM_REM_CQUERY(TFIBLargeIntField * TableIDFIRM_REM_CQUERY);

   virtual TFIBLargeIntField * get_TableIDSKLAD_REM_CQUERY(void);
   virtual void set_TableIDSKLAD_REM_CQUERY(TFIBLargeIntField * TableIDSKLAD_REM_CQUERY);

   virtual TFIBLargeIntField * get_TableIDUSER_REM_CQUERY(void);
   virtual void set_TableIDUSER_REM_CQUERY(TFIBLargeIntField * TableIDUSER_REM_CQUERY);

   virtual TFIBLargeIntField * get_TableIDKLIENT_REM_CQUERY(void);
   virtual void set_TableIDKLIENT_REM_CQUERY(TFIBLargeIntField * TableIDKLIENT_REM_CQUERY);

   virtual TFIBWideStringField * get_TableKLIENT_NAME_REM_CQUERY(void);
   virtual void set_TableKLIENT_NAME_REM_CQUERY(TFIBWideStringField * TableKLIENT_NAME_REM_CQUERY);

   virtual TFIBWideStringField * get_TableKLIENT_ADR_REM_CQUERY(void);
   virtual void set_TableKLIENT_ADR_REM_CQUERY(TFIBWideStringField * TableKLIENT_ADR_REM_CQUERY);

   virtual TFIBWideStringField * get_TableKLIENT_PHONE_REM_CQUERY(void);
   virtual void set_TableKLIENT_PHONE_REM_CQUERY(TFIBWideStringField * TableKLIENT_PHONE_REM_CQUERY);

   virtual TFIBWideStringField * get_TableCOMMENTS_REM_CQUERY(void);
   virtual void set_TableCOMMENTS_REM_CQUERY(TFIBWideStringField * TableCOMMENTS_REM_CQUERY);

   virtual TFIBSmallIntField * get_TableRUN_REM_CQUERY(void);
   virtual void set_TableRUN_REM_CQUERY(TFIBSmallIntField * TableRUN_REM_CQUERY);

   virtual TFIBBCDField * get_TableDO_SUM_REM_CQUERY(void);
   virtual void set_TableDO_SUM_REM_CQUERY(TFIBBCDField * TableDO_SUM_REM_CQUERY);

   virtual TFIBBCDField * get_TableTEC_SUM_REM_CQUERY(void);
   virtual void set_TableTEC_SUM_REM_CQUERY(TFIBBCDField * TableTEC_SUM_REM_CQUERY);

   virtual TFIBBCDField * get_TableSOGL_SUM_REM_CQUERY(void);
   virtual void set_TableSOGL_SUM_REM_CQUERY(TFIBBCDField * TableSOGL_SUM_REM_CQUERY);

   virtual TFIBLargeIntField * get_TableIDZ_REM_CQUERY(void);
   virtual void set_TableIDZ_REM_CQUERY(TFIBLargeIntField * TableIDZ_REM_CQUERY);

   virtual TFIBLargeIntField * get_TableIDMODEL_REM_CQUERY(void);
   virtual void set_TableIDMODEL_REM_CQUERY(TFIBLargeIntField * TableIDMODEL_REM_CQUERY);

   virtual TFIBWideStringField * get_TableNAME_MODEL_REM_CQUERY(void);
   virtual void set_TableNAME_MODEL_REM_CQUERY(TFIBWideStringField * TableNAME_MODEL_REM_CQUERY);

   virtual TFIBWideStringField * get_TableNAMEFIRM(void);
   virtual void set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM);

   virtual TFIBWideStringField * get_TableNAME_REM_SMODEL(void);
   virtual void set_TableNAME_REM_SMODEL(TFIBWideStringField * TableNAME_REM_SMODEL);

   virtual TFIBWideStringField * get_TableNAMESKLAD(void);
   virtual void set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD);

   virtual TFIBWideStringField * get_TableNAMEKLIENT(void);
   virtual void set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT);

   virtual TFIBWideStringField * get_TableNAME_USER(void);
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER);

   virtual TFIBLargeIntField * get_TableIDBRAND_REM_CQUERY(void);
   virtual void set_TableIDBRAND_REM_CQUERY(TFIBLargeIntField * TableIDBRAND_REM_CQUERY);

   virtual TFIBLargeIntField * get_TableIDPRODUCER_REM_CQUERY(void);
   virtual void set_TableIDPRODUCER_REM_CQUERY(TFIBLargeIntField * TableIDPRODUCER_REM_CQUERY);

   virtual TFIBSmallIntField * get_TableFL_KLIENT_UVEDOML_REM_CQUERY(void);
   virtual void set_TableFL_KLIENT_UVEDOML_REM_CQUERY(TFIBSmallIntField * TableFL_KLIENT_UVEDOML_REM_CQUERY);

   virtual TFIBWideStringField * get_TableNAME_SBRAND(void);
   virtual void set_TableNAME_SBRAND(TFIBWideStringField * TableNAME_SBRAND);

   virtual TFIBWideStringField * get_TableNAME_SPRODUCER(void);
   virtual void set_TableNAME_SPRODUCER(TFIBWideStringField * TableNAME_SPRODUCER);

   virtual TFIBIntegerField * get_TableNUM_ZAKAZA_REM_CQUERY(void);
   virtual void set_TableNUM_ZAKAZA_REM_CQUERY(TFIBIntegerField * TableNUM_ZAKAZA_REM_CQUERY);

   virtual TFIBDateField * get_TableDATE_ZAKAZA_REM_CQUERY(void);
   virtual void set_TableDATE_ZAKAZA_REM_CQUERY(TFIBDateField * TableDATE_ZAKAZA_REM_CQUERY);

   virtual TFIBIntegerField * get_TableTYPE_REM_CQUERY(void);
   virtual void set_TableTYPE_REM_CQUERY(TFIBIntegerField * TableTYPE_REM_CQUERY);

   virtual TFIBWideStringField * get_TableNAMENOM_REM_CQUERYT(void);
   virtual void set_TableNAMENOM_REM_CQUERYT(TFIBWideStringField * TableNAMENOM_REM_CQUERYT);

   virtual TFIBIntegerField * get_TableCODENOM(void);
   virtual void set_TableCODENOM(TFIBIntegerField * TableCODENOM);

   virtual TFIBWideStringField * get_TableARTNOM(void);
   virtual void set_TableARTNOM(TFIBWideStringField * TableARTNOM);

   virtual TFIBWideStringField * get_TableNAMENOM(void);
   virtual void set_TableNAMENOM(TFIBWideStringField * TableNAMENOM);

   virtual TFIBBCDField * get_TableKOL_REM_CQUERYT(void);
   virtual void set_TableKOL_REM_CQUERYT(TFIBBCDField * TableKOL_REM_CQUERYT);

   virtual TFIBBCDField * get_TableKF_REM_CQUERYT(void);
   virtual void set_TableKF_REM_CQUERYT(TFIBBCDField * TableKF_REM_CQUERYT);

   virtual TFIBBCDField * get_TablePRICE_REM_CQUERYT(void);
   virtual void set_TablePRICE_REM_CQUERYT(TFIBBCDField * TablePRICE_REM_CQUERYT);

   virtual TFIBBCDField * get_TableNOM_SUM_STR(void);
   virtual void set_TableNOM_SUM_STR(TFIBBCDField * TableNOM_SUM_STR);

   virtual TFIBIntegerField * get_TableCODE_SPRNOM(void);
   virtual void set_TableCODE_SPRNOM(TFIBIntegerField * TableCODE_SPRNOM);

   virtual TFIBWideStringField * get_TableART_SPRNOM(void);
   virtual void set_TableART_SPRNOM(TFIBWideStringField * TableART_SPRNOM);

   virtual TFIBWideStringField * get_TableNAME_SPRNOM(void);
   virtual void set_TableNAME_SPRNOM(TFIBWideStringField * TableNAME_SPRNOM);

   virtual TFIBSmallIntField * get_TableFL_DOSTUPNO_SPRNOM(void);
   virtual void set_TableFL_DOSTUPNO_SPRNOM(TFIBSmallIntField * TableFL_DOSTUPNO_SPRNOM);

   virtual TFIBBCDField * get_TablePRICE_ZAKUP_SPRNOM(void);
   virtual void set_TablePRICE_ZAKUP_SPRNOM(TFIBBCDField * TablePRICE_ZAKUP_SPRNOM);

   virtual TFIBBCDField * get_TablePRNOM_SUM_STR(void);
   virtual void set_TablePRNOM_SUM_STR(TFIBBCDField * TablePRNOM_SUM_STR);

   virtual TFIBLargeIntField * get_TableID_REM_CQUERYT(void);
   virtual void set_TableID_REM_CQUERYT(TFIBLargeIntField * TableID_REM_CQUERYT);

   virtual TFIBWideStringField * get_TablePRODAVEC_NAME(void);
   virtual void set_TablePRODAVEC_NAME(TFIBWideStringField * TablePRODAVEC_NAME);

   virtual TFIBWideStringField * get_TableNUM_STR_ZAK_POST_REM_CQUERY(void);
   virtual void set_TableNUM_STR_ZAK_POST_REM_CQUERY(TFIBWideStringField * TableNUM_STR_ZAK_POST_REM_CQUERY);

   virtual TFIBWideStringField * get_TableNUM_STR_ZAK_SPROV_REM_CQUERY(void);
   virtual void set_TableNUM_STR_ZAK_SPROV_REM_CQUERY(TFIBWideStringField * TableNUM_STR_ZAK_SPROV_REM_CQUERY);

   virtual TFIBWideStringField * get_TableNUMDOCTK_REM_CQUERY(void);
   virtual void set_TableNUMDOCTK_REM_CQUERY(TFIBWideStringField * TableNUMDOCTK_REM_CQUERY);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual __int64 get_IdCustQuery(void);
   virtual void set_IdCustQuery(__int64 IdCustQuery);

   virtual TDateTime get_PosNach(void);
   virtual void set_PosNach(TDateTime PosNach);

   virtual TDateTime get_PosCon(void);
   virtual void set_PosCon(TDateTime PosCon);

   virtual void OpenTable();
   virtual void UpdateTable(void);
   virtual bool OpenTableOnlyZayavka(__int64 id_z);
   virtual void PoiskPoKlient(UnicodeString value);
   virtual void PoiskPoModel(UnicodeString value);
   virtual void OpenTableGur (__int64 id_user, int poisk, TDateTime pos_nach, TDateTime pos_con, UnicodeString value_str, __int64 value_int64);
   virtual void OpenTablePoNumZakaza (__int64 id_user, __int64 id_producer,int number_zakaza, TDate date_zakaza);
};
#define CLSID_TREM_DMGurCustQueryDetalImpl __uuidof(TREM_DMGurCustQueryDetalImpl)
#endif
