#ifndef UIREM_DMCustQueryH
#define UIREM_DMCustQueryH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMCustQuery)) IREM_DMCustQuery : public IMainInterface
{
public:
   __property TDataSource * DataSourceDocT = {read = get_DataSourceDocT , write = set_DataSourceDocT};
   virtual TDataSource * get_DataSourceDocT(void)=0;
   virtual void set_DataSourceDocT(TDataSource * DataSourceDocT)=0;

   __property TDataSource * DataSourceDoc = {read = get_DataSourceDoc , write = set_DataSourceDoc};
   virtual TDataSource * get_DataSourceDoc(void)=0;
   virtual void set_DataSourceDoc(TDataSource * DataSourceDoc)=0;

   __property TpFIBDataSet * Doc = {read = get_Doc , write = set_Doc};
   virtual TpFIBDataSet * get_Doc(void)=0;
   virtual void set_Doc(TpFIBDataSet * Doc)=0;

   __property TpFIBDataSet * DocT = {read = get_DocT , write = set_DocT};
   virtual TpFIBDataSet * get_DocT(void)=0;
   virtual void set_DocT(TpFIBDataSet * DocT)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TpFIBDataSet * NumDoc = {read = get_NumDoc , write = set_NumDoc};
   virtual TpFIBDataSet * get_NumDoc(void)=0;
   virtual void set_NumDoc(TpFIBDataSet * NumDoc)=0;

   __property TFIBLargeIntField * DocID_REM_CQUERY = {read = get_DocID_REM_CQUERY , write = set_DocID_REM_CQUERY};
   virtual TFIBLargeIntField * get_DocID_REM_CQUERY(void)=0;
   virtual void set_DocID_REM_CQUERY(TFIBLargeIntField * DocID_REM_CQUERY)=0;

   __property TFIBWideStringField * DocGID_REM_CQUERY = {read = get_DocGID_REM_CQUERY , write = set_DocGID_REM_CQUERY};
   virtual TFIBWideStringField * get_DocGID_REM_CQUERY(void)=0;
   virtual void set_DocGID_REM_CQUERY(TFIBWideStringField * DocGID_REM_CQUERY)=0;

   __property TFIBLargeIntField * DocIDBASE_REM_CQUERY = {read = get_DocIDBASE_REM_CQUERY , write = set_DocIDBASE_REM_CQUERY};
   virtual TFIBLargeIntField * get_DocIDBASE_REM_CQUERY(void)=0;
   virtual void set_DocIDBASE_REM_CQUERY(TFIBLargeIntField * DocIDBASE_REM_CQUERY)=0;

   __property TFIBDateTimeField * DocPOS_REM_CQUERY = {read = get_DocPOS_REM_CQUERY , write = set_DocPOS_REM_CQUERY};
   virtual TFIBDateTimeField * get_DocPOS_REM_CQUERY(void)=0;
   virtual void set_DocPOS_REM_CQUERY(TFIBDateTimeField * DocPOS_REM_CQUERY)=0;

   __property TFIBIntegerField * DocNUM_REM_CQUERY = {read = get_DocNUM_REM_CQUERY , write = set_DocNUM_REM_CQUERY};
   virtual TFIBIntegerField * get_DocNUM_REM_CQUERY(void)=0;
   virtual void set_DocNUM_REM_CQUERY(TFIBIntegerField * DocNUM_REM_CQUERY)=0;

   __property TFIBLargeIntField * DocIDFIRM_REM_CQUERY = {read = get_DocIDFIRM_REM_CQUERY , write = set_DocIDFIRM_REM_CQUERY};
   virtual TFIBLargeIntField * get_DocIDFIRM_REM_CQUERY(void)=0;
   virtual void set_DocIDFIRM_REM_CQUERY(TFIBLargeIntField * DocIDFIRM_REM_CQUERY)=0;

   __property TFIBLargeIntField * DocIDSKLAD_REM_CQUERY = {read = get_DocIDSKLAD_REM_CQUERY , write = set_DocIDSKLAD_REM_CQUERY};
   virtual TFIBLargeIntField * get_DocIDSKLAD_REM_CQUERY(void)=0;
   virtual void set_DocIDSKLAD_REM_CQUERY(TFIBLargeIntField * DocIDSKLAD_REM_CQUERY)=0;

   __property TFIBLargeIntField * DocIDUSER_REM_CQUERY = {read = get_DocIDUSER_REM_CQUERY , write = set_DocIDUSER_REM_CQUERY};
   virtual TFIBLargeIntField * get_DocIDUSER_REM_CQUERY(void)=0;
   virtual void set_DocIDUSER_REM_CQUERY(TFIBLargeIntField * DocIDUSER_REM_CQUERY)=0;

   __property TFIBLargeIntField * DocIDKLIENT_REM_CQUERY = {read = get_DocIDKLIENT_REM_CQUERY , write = set_DocIDKLIENT_REM_CQUERY};
   virtual TFIBLargeIntField * get_DocIDKLIENT_REM_CQUERY(void)=0;
   virtual void set_DocIDKLIENT_REM_CQUERY(TFIBLargeIntField * DocIDKLIENT_REM_CQUERY)=0;

   __property TFIBWideStringField * DocKLIENT_NAME_REM_CQUERY = {read = get_DocKLIENT_NAME_REM_CQUERY , write = set_DocKLIENT_NAME_REM_CQUERY};
   virtual TFIBWideStringField * get_DocKLIENT_NAME_REM_CQUERY(void)=0;
   virtual void set_DocKLIENT_NAME_REM_CQUERY(TFIBWideStringField * DocKLIENT_NAME_REM_CQUERY)=0;

   __property TFIBWideStringField * DocKLIENT_ADR_REM_CQUERY = {read = get_DocKLIENT_ADR_REM_CQUERY , write = set_DocKLIENT_ADR_REM_CQUERY};
   virtual TFIBWideStringField * get_DocKLIENT_ADR_REM_CQUERY(void)=0;
   virtual void set_DocKLIENT_ADR_REM_CQUERY(TFIBWideStringField * DocKLIENT_ADR_REM_CQUERY)=0;

   __property TFIBWideStringField * DocKLIENT_PHONE_REM_CQUERY = {read = get_DocKLIENT_PHONE_REM_CQUERY , write = set_DocKLIENT_PHONE_REM_CQUERY};
   virtual TFIBWideStringField * get_DocKLIENT_PHONE_REM_CQUERY(void)=0;
   virtual void set_DocKLIENT_PHONE_REM_CQUERY(TFIBWideStringField * DocKLIENT_PHONE_REM_CQUERY)=0;

   __property TFIBWideStringField * DocCOMMENTS_REM_CQUERY = {read = get_DocCOMMENTS_REM_CQUERY , write = set_DocCOMMENTS_REM_CQUERY};
   virtual TFIBWideStringField * get_DocCOMMENTS_REM_CQUERY(void)=0;
   virtual void set_DocCOMMENTS_REM_CQUERY(TFIBWideStringField * DocCOMMENTS_REM_CQUERY)=0;

   __property TFIBSmallIntField * DocRUN_REM_CQUERY = {read = get_DocRUN_REM_CQUERY , write = set_DocRUN_REM_CQUERY};
   virtual TFIBSmallIntField * get_DocRUN_REM_CQUERY(void)=0;
   virtual void set_DocRUN_REM_CQUERY(TFIBSmallIntField * DocRUN_REM_CQUERY)=0;

   __property TFIBBCDField * DocDO_SUM_REM_CQUERY = {read = get_DocDO_SUM_REM_CQUERY , write = set_DocDO_SUM_REM_CQUERY};
   virtual TFIBBCDField * get_DocDO_SUM_REM_CQUERY(void)=0;
   virtual void set_DocDO_SUM_REM_CQUERY(TFIBBCDField * DocDO_SUM_REM_CQUERY)=0;

   __property TFIBBCDField * DocTEC_SUM_REM_CQUERY = {read = get_DocTEC_SUM_REM_CQUERY , write = set_DocTEC_SUM_REM_CQUERY};
   virtual TFIBBCDField * get_DocTEC_SUM_REM_CQUERY(void)=0;
   virtual void set_DocTEC_SUM_REM_CQUERY(TFIBBCDField * DocTEC_SUM_REM_CQUERY)=0;

   __property TFIBBCDField * DocSOGL_SUM_REM_CQUERY = {read = get_DocSOGL_SUM_REM_CQUERY , write = set_DocSOGL_SUM_REM_CQUERY};
   virtual TFIBBCDField * get_DocSOGL_SUM_REM_CQUERY(void)=0;
   virtual void set_DocSOGL_SUM_REM_CQUERY(TFIBBCDField * DocSOGL_SUM_REM_CQUERY)=0;

   __property TFIBLargeIntField * DocIDZ_REM_CQUERY = {read = get_DocIDZ_REM_CQUERY , write = set_DocIDZ_REM_CQUERY};
   virtual TFIBLargeIntField * get_DocIDZ_REM_CQUERY(void)=0;
   virtual void set_DocIDZ_REM_CQUERY(TFIBLargeIntField * DocIDZ_REM_CQUERY)=0;

   __property TFIBLargeIntField * DocIDMODEL_REM_CQUERY = {read = get_DocIDMODEL_REM_CQUERY , write = set_DocIDMODEL_REM_CQUERY};
   virtual TFIBLargeIntField * get_DocIDMODEL_REM_CQUERY(void)=0;
   virtual void set_DocIDMODEL_REM_CQUERY(TFIBLargeIntField * DocIDMODEL_REM_CQUERY)=0;

   __property TFIBWideStringField * DocNAME_MODEL_REM_CQUERY = {read = get_DocNAME_MODEL_REM_CQUERY , write = set_DocNAME_MODEL_REM_CQUERY};
   virtual TFIBWideStringField * get_DocNAME_MODEL_REM_CQUERY(void)=0;
   virtual void set_DocNAME_MODEL_REM_CQUERY(TFIBWideStringField * DocNAME_MODEL_REM_CQUERY)=0;

   __property TFIBWideStringField * DocNAMEFIRM = {read = get_DocNAMEFIRM , write = set_DocNAMEFIRM};
   virtual TFIBWideStringField * get_DocNAMEFIRM(void)=0;
   virtual void set_DocNAMEFIRM(TFIBWideStringField * DocNAMEFIRM)=0;

   __property TFIBWideStringField * DocNAME_SINFBASE_OBMEN = {read = get_DocNAME_SINFBASE_OBMEN , write = set_DocNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_DocNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_DocNAME_SINFBASE_OBMEN(TFIBWideStringField * DocNAME_SINFBASE_OBMEN)=0;

   __property TFIBWideStringField * DocNAME_REM_SMODEL = {read = get_DocNAME_REM_SMODEL , write = set_DocNAME_REM_SMODEL};
   virtual TFIBWideStringField * get_DocNAME_REM_SMODEL(void)=0;
   virtual void set_DocNAME_REM_SMODEL(TFIBWideStringField * DocNAME_REM_SMODEL)=0;

   __property TFIBWideStringField * DocNAMESKLAD = {read = get_DocNAMESKLAD , write = set_DocNAMESKLAD};
   virtual TFIBWideStringField * get_DocNAMESKLAD(void)=0;
   virtual void set_DocNAMESKLAD(TFIBWideStringField * DocNAMESKLAD)=0;

   __property TFIBWideStringField * DocNAMEKLIENT = {read = get_DocNAMEKLIENT , write = set_DocNAMEKLIENT};
   virtual TFIBWideStringField * get_DocNAMEKLIENT(void)=0;
   virtual void set_DocNAMEKLIENT(TFIBWideStringField * DocNAMEKLIENT)=0;

   __property TFIBWideStringField * DocNAME_REM_Z = {read = get_DocNAME_REM_Z , write = set_DocNAME_REM_Z};
   virtual TFIBWideStringField * get_DocNAME_REM_Z(void)=0;
   virtual void set_DocNAME_REM_Z(TFIBWideStringField * DocNAME_REM_Z)=0;

   __property TFIBIntegerField * DocNUM_REM_Z = {read = get_DocNUM_REM_Z , write = set_DocNUM_REM_Z};
   virtual TFIBIntegerField * get_DocNUM_REM_Z(void)=0;
   virtual void set_DocNUM_REM_Z(TFIBIntegerField * DocNUM_REM_Z)=0;

   __property TFIBDateTimeField * DocPOS_REM_Z = {read = get_DocPOS_REM_Z , write = set_DocPOS_REM_Z};
   virtual TFIBDateTimeField * get_DocPOS_REM_Z(void)=0;
   virtual void set_DocPOS_REM_Z(TFIBDateTimeField * DocPOS_REM_Z)=0;

   __property TFIBWideStringField * DocKLIENT_NAME_REM_Z = {read = get_DocKLIENT_NAME_REM_Z , write = set_DocKLIENT_NAME_REM_Z};
   virtual TFIBWideStringField * get_DocKLIENT_NAME_REM_Z(void)=0;
   virtual void set_DocKLIENT_NAME_REM_Z(TFIBWideStringField * DocKLIENT_NAME_REM_Z)=0;

   __property TFIBWideStringField * DocMODEL_REM_Z = {read = get_DocMODEL_REM_Z , write = set_DocMODEL_REM_Z};
   virtual TFIBWideStringField * get_DocMODEL_REM_Z(void)=0;
   virtual void set_DocMODEL_REM_Z(TFIBWideStringField * DocMODEL_REM_Z)=0;

   __property TFIBWideStringField * DocNAME_USER = {read = get_DocNAME_USER , write = set_DocNAME_USER};
   virtual TFIBWideStringField * get_DocNAME_USER(void)=0;
   virtual void set_DocNAME_USER(TFIBWideStringField * DocNAME_USER)=0;

   __property TFIBLargeIntField * DocTID_REM_CQUERYT = {read = get_DocTID_REM_CQUERYT , write = set_DocTID_REM_CQUERYT};
   virtual TFIBLargeIntField * get_DocTID_REM_CQUERYT(void)=0;
   virtual void set_DocTID_REM_CQUERYT(TFIBLargeIntField * DocTID_REM_CQUERYT)=0;

   __property TFIBWideStringField * DocTGID_REM_CQUERYT = {read = get_DocTGID_REM_CQUERYT , write = set_DocTGID_REM_CQUERYT};
   virtual TFIBWideStringField * get_DocTGID_REM_CQUERYT(void)=0;
   virtual void set_DocTGID_REM_CQUERYT(TFIBWideStringField * DocTGID_REM_CQUERYT)=0;

   __property TFIBLargeIntField * DocTIDBASE_REM_CQUERYT = {read = get_DocTIDBASE_REM_CQUERYT , write = set_DocTIDBASE_REM_CQUERYT};
   virtual TFIBLargeIntField * get_DocTIDBASE_REM_CQUERYT(void)=0;
   virtual void set_DocTIDBASE_REM_CQUERYT(TFIBLargeIntField * DocTIDBASE_REM_CQUERYT)=0;

   __property TFIBLargeIntField * DocTIDCQ_REM_CQUERYT = {read = get_DocTIDCQ_REM_CQUERYT , write = set_DocTIDCQ_REM_CQUERYT};
   virtual TFIBLargeIntField * get_DocTIDCQ_REM_CQUERYT(void)=0;
   virtual void set_DocTIDCQ_REM_CQUERYT(TFIBLargeIntField * DocTIDCQ_REM_CQUERYT)=0;

   __property TFIBLargeIntField * DocTIDNOM_REM_CQUERYT = {read = get_DocTIDNOM_REM_CQUERYT , write = set_DocTIDNOM_REM_CQUERYT};
   virtual TFIBLargeIntField * get_DocTIDNOM_REM_CQUERYT(void)=0;
   virtual void set_DocTIDNOM_REM_CQUERYT(TFIBLargeIntField * DocTIDNOM_REM_CQUERYT)=0;

   __property TFIBLargeIntField * DocTIDED_REM_CQUERYT = {read = get_DocTIDED_REM_CQUERYT , write = set_DocTIDED_REM_CQUERYT};
   virtual TFIBLargeIntField * get_DocTIDED_REM_CQUERYT(void)=0;
   virtual void set_DocTIDED_REM_CQUERYT(TFIBLargeIntField * DocTIDED_REM_CQUERYT)=0;

   __property TFIBLargeIntField * DocTIDSOST_REM_CQUERYT = {read = get_DocTIDSOST_REM_CQUERYT , write = set_DocTIDSOST_REM_CQUERYT};
   virtual TFIBLargeIntField * get_DocTIDSOST_REM_CQUERYT(void)=0;
   virtual void set_DocTIDSOST_REM_CQUERYT(TFIBLargeIntField * DocTIDSOST_REM_CQUERYT)=0;

   __property TFIBWideStringField * DocTNAMENOM_REM_CQUERYT = {read = get_DocTNAMENOM_REM_CQUERYT , write = set_DocTNAMENOM_REM_CQUERYT};
   virtual TFIBWideStringField * get_DocTNAMENOM_REM_CQUERYT(void)=0;
   virtual void set_DocTNAMENOM_REM_CQUERYT(TFIBWideStringField * DocTNAMENOM_REM_CQUERYT)=0;

   __property TFIBBCDField * DocTKOL_REM_CQUERYT = {read = get_DocTKOL_REM_CQUERYT , write = set_DocTKOL_REM_CQUERYT};
   virtual TFIBBCDField * get_DocTKOL_REM_CQUERYT(void)=0;
   virtual void set_DocTKOL_REM_CQUERYT(TFIBBCDField * DocTKOL_REM_CQUERYT)=0;

   __property TFIBBCDField * DocTKF_REM_CQUERYT = {read = get_DocTKF_REM_CQUERYT , write = set_DocTKF_REM_CQUERYT};
   virtual TFIBBCDField * get_DocTKF_REM_CQUERYT(void)=0;
   virtual void set_DocTKF_REM_CQUERYT(TFIBBCDField * DocTKF_REM_CQUERYT)=0;

   __property TFIBBCDField * DocTPRICE_REM_CQUERYT = {read = get_DocTPRICE_REM_CQUERYT , write = set_DocTPRICE_REM_CQUERYT};
   virtual TFIBBCDField * get_DocTPRICE_REM_CQUERYT(void)=0;
   virtual void set_DocTPRICE_REM_CQUERYT(TFIBBCDField * DocTPRICE_REM_CQUERYT)=0;

   __property TFIBBCDField * DocTSUM_REM_CQUERYT = {read = get_DocTSUM_REM_CQUERYT , write = set_DocTSUM_REM_CQUERYT};
   virtual TFIBBCDField * get_DocTSUM_REM_CQUERYT(void)=0;
   virtual void set_DocTSUM_REM_CQUERYT(TFIBBCDField * DocTSUM_REM_CQUERYT)=0;

   __property TFIBBCDField * DocTPRICE_DO_REM_CQUERYT = {read = get_DocTPRICE_DO_REM_CQUERYT , write = set_DocTPRICE_DO_REM_CQUERYT};
   virtual TFIBBCDField * get_DocTPRICE_DO_REM_CQUERYT(void)=0;
   virtual void set_DocTPRICE_DO_REM_CQUERYT(TFIBBCDField * DocTPRICE_DO_REM_CQUERYT)=0;

   __property TFIBBCDField * DocTPRICE_TEC_REM_CQUERYT = {read = get_DocTPRICE_TEC_REM_CQUERYT , write = set_DocTPRICE_TEC_REM_CQUERYT};
   virtual TFIBBCDField * get_DocTPRICE_TEC_REM_CQUERYT(void)=0;
   virtual void set_DocTPRICE_TEC_REM_CQUERYT(TFIBBCDField * DocTPRICE_TEC_REM_CQUERYT)=0;

   __property TFIBBCDField * DocTPRICE_SOGL_REM_CQUERYT = {read = get_DocTPRICE_SOGL_REM_CQUERYT , write = set_DocTPRICE_SOGL_REM_CQUERYT};
   virtual TFIBBCDField * get_DocTPRICE_SOGL_REM_CQUERYT(void)=0;
   virtual void set_DocTPRICE_SOGL_REM_CQUERYT(TFIBBCDField * DocTPRICE_SOGL_REM_CQUERYT)=0;

   __property TFIBIntegerField * DocTSROK_POST_REM_CQUERYT = {read = get_DocTSROK_POST_REM_CQUERYT , write = set_DocTSROK_POST_REM_CQUERYT};
   virtual TFIBIntegerField * get_DocTSROK_POST_REM_CQUERYT(void)=0;
   virtual void set_DocTSROK_POST_REM_CQUERYT(TFIBIntegerField * DocTSROK_POST_REM_CQUERYT)=0;

   __property TFIBDateTimeField * DocTPOS_POST_REM_CQUERYT = {read = get_DocTPOS_POST_REM_CQUERYT , write = set_DocTPOS_POST_REM_CQUERYT};
   virtual TFIBDateTimeField * get_DocTPOS_POST_REM_CQUERYT(void)=0;
   virtual void set_DocTPOS_POST_REM_CQUERYT(TFIBDateTimeField * DocTPOS_POST_REM_CQUERYT)=0;

   __property TFIBSmallIntField * DocTRUN_REM_CQUERYT = {read = get_DocTRUN_REM_CQUERYT , write = set_DocTRUN_REM_CQUERYT};
   virtual TFIBSmallIntField * get_DocTRUN_REM_CQUERYT(void)=0;
   virtual void set_DocTRUN_REM_CQUERYT(TFIBSmallIntField * DocTRUN_REM_CQUERYT)=0;

   __property TFIBWideStringField * DocTCOMMENTS_REM_CQUERYT = {read = get_DocTCOMMENTS_REM_CQUERYT , write = set_DocTCOMMENTS_REM_CQUERYT};
   virtual TFIBWideStringField * get_DocTCOMMENTS_REM_CQUERYT(void)=0;
   virtual void set_DocTCOMMENTS_REM_CQUERYT(TFIBWideStringField * DocTCOMMENTS_REM_CQUERYT)=0;

   __property TFIBWideStringField * DocTNAMENOM = {read = get_DocTNAMENOM , write = set_DocTNAMENOM};
   virtual TFIBWideStringField * get_DocTNAMENOM(void)=0;
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)=0;

   __property TFIBWideStringField * DocTNAMEED = {read = get_DocTNAMEED , write = set_DocTNAMEED};
   virtual TFIBWideStringField * get_DocTNAMEED(void)=0;
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)=0;

   __property TFIBWideStringField * DocTNAME_REM_SSOST_CQUERY = {read = get_DocTNAME_REM_SSOST_CQUERY , write = set_DocTNAME_REM_SSOST_CQUERY};
   virtual TFIBWideStringField * get_DocTNAME_REM_SSOST_CQUERY(void)=0;
   virtual void set_DocTNAME_REM_SSOST_CQUERY(TFIBWideStringField * DocTNAME_REM_SSOST_CQUERY)=0;

   __property TIntegerField * DocTRECNO = {read = get_DocTRECNO , write = set_DocTRECNO};
   virtual TIntegerField * get_DocTRECNO(void)=0;
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO)=0;

   __property TFIBIntegerField * NumDocMAXNUMBER = {read = get_NumDocMAXNUMBER , write = set_NumDocMAXNUMBER};
   virtual TFIBIntegerField * get_NumDocMAXNUMBER(void)=0;
   virtual void set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)=0;

   __property TFIBSmallIntField * DocTACT_REM_CQUERYT = {read = get_DocTACT_REM_CQUERYT , write = set_DocTACT_REM_CQUERYT};
   virtual TFIBSmallIntField * get_DocTACT_REM_CQUERYT(void)=0;
   virtual void set_DocTACT_REM_CQUERYT(TFIBSmallIntField * DocTACT_REM_CQUERYT)=0;

   __property TFIBLargeIntField * DocTIDPRNOM_REM_CQUERYT = {read = get_DocTIDPRNOM_REM_CQUERYT , write = set_DocTIDPRNOM_REM_CQUERYT};
   virtual TFIBLargeIntField * get_DocTIDPRNOM_REM_CQUERYT(void)=0;
   virtual void set_DocTIDPRNOM_REM_CQUERYT(TFIBLargeIntField * DocTIDPRNOM_REM_CQUERYT)=0;

   __property TFIBIntegerField * DocTCODENOM = {read = get_DocTCODENOM , write = set_DocTCODENOM};
   virtual TFIBIntegerField * get_DocTCODENOM(void)=0;
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)=0;

   __property TFIBWideStringField * DocTARTNOM = {read = get_DocTARTNOM , write = set_DocTARTNOM};
   virtual TFIBWideStringField * get_DocTARTNOM(void)=0;
   virtual void set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)=0;

   __property TFIBWideStringField * DocTSHED = {read = get_DocTSHED , write = set_DocTSHED};
   virtual TFIBWideStringField * get_DocTSHED(void)=0;
   virtual void set_DocTSHED(TFIBWideStringField * DocTSHED)=0;

   __property TFIBWideStringField * DocTART_SPRNOM = {read = get_DocTART_SPRNOM , write = set_DocTART_SPRNOM};
   virtual TFIBWideStringField * get_DocTART_SPRNOM(void)=0;
   virtual void set_DocTART_SPRNOM(TFIBWideStringField * DocTART_SPRNOM)=0;

   __property TFIBIntegerField * DocTCODE_SPRNOM = {read = get_DocTCODE_SPRNOM , write = set_DocTCODE_SPRNOM};
   virtual TFIBIntegerField * get_DocTCODE_SPRNOM(void)=0;
   virtual void set_DocTCODE_SPRNOM(TFIBIntegerField * DocTCODE_SPRNOM)=0;

   __property TFIBWideStringField * DocTNAME_SPRNOM = {read = get_DocTNAME_SPRNOM , write = set_DocTNAME_SPRNOM};
   virtual TFIBWideStringField * get_DocTNAME_SPRNOM(void)=0;
   virtual void set_DocTNAME_SPRNOM(TFIBWideStringField * DocTNAME_SPRNOM)=0;

   __property TFIBLargeIntField * DocIDBRAND_REM_CQUERY = {read = get_DocIDBRAND_REM_CQUERY , write = set_DocIDBRAND_REM_CQUERY};
   virtual TFIBLargeIntField * get_DocIDBRAND_REM_CQUERY(void)=0;
   virtual void set_DocIDBRAND_REM_CQUERY(TFIBLargeIntField * DocIDBRAND_REM_CQUERY)=0;

   __property TFIBLargeIntField * DocIDPRODUCER_REM_CQUERY = {read = get_DocIDPRODUCER_REM_CQUERY , write = set_DocIDPRODUCER_REM_CQUERY};
   virtual TFIBLargeIntField * get_DocIDPRODUCER_REM_CQUERY(void)=0;
   virtual void set_DocIDPRODUCER_REM_CQUERY(TFIBLargeIntField * DocIDPRODUCER_REM_CQUERY)=0;

   __property TFIBSmallIntField * DocFL_KLIENT_UVEDOML_REM_CQUERY = {read = get_DocFL_KLIENT_UVEDOML_REM_CQUERY , write = set_DocFL_KLIENT_UVEDOML_REM_CQUERY};
   virtual TFIBSmallIntField * get_DocFL_KLIENT_UVEDOML_REM_CQUERY(void)=0;
   virtual void set_DocFL_KLIENT_UVEDOML_REM_CQUERY(TFIBSmallIntField * DocFL_KLIENT_UVEDOML_REM_CQUERY)=0;

   __property TFIBWideStringField * DocNAME_SBRAND = {read = get_DocNAME_SBRAND , write = set_DocNAME_SBRAND};
   virtual TFIBWideStringField * get_DocNAME_SBRAND(void)=0;
   virtual void set_DocNAME_SBRAND(TFIBWideStringField * DocNAME_SBRAND)=0;

   __property TFIBWideStringField * DocNAME_SPRODUCER = {read = get_DocNAME_SPRODUCER , write = set_DocNAME_SPRODUCER};
   virtual TFIBWideStringField * get_DocNAME_SPRODUCER(void)=0;
   virtual void set_DocNAME_SPRODUCER(TFIBWideStringField * DocNAME_SPRODUCER)=0;

   __property TFIBIntegerField * DocNUM_ZAKAZA_REM_CQUERY = {read = get_DocNUM_ZAKAZA_REM_CQUERY , write = set_DocNUM_ZAKAZA_REM_CQUERY};
   virtual TFIBIntegerField * get_DocNUM_ZAKAZA_REM_CQUERY(void)=0;
   virtual void set_DocNUM_ZAKAZA_REM_CQUERY(TFIBIntegerField * DocNUM_ZAKAZA_REM_CQUERY)=0;

   __property TFIBDateField * DocDATE_ZAKAZA_REM_CQUERY = {read = get_DocDATE_ZAKAZA_REM_CQUERY , write = set_DocDATE_ZAKAZA_REM_CQUERY};
   virtual TFIBDateField * get_DocDATE_ZAKAZA_REM_CQUERY(void)=0;
   virtual void set_DocDATE_ZAKAZA_REM_CQUERY(TFIBDateField * DocDATE_ZAKAZA_REM_CQUERY)=0;

   __property TFIBLargeIntField * DocIDHW_REM_CQUERY = {read = get_DocIDHW_REM_CQUERY , write = set_DocIDHW_REM_CQUERY};
   virtual TFIBLargeIntField * get_DocIDHW_REM_CQUERY(void)=0;
   virtual void set_DocIDHW_REM_CQUERY(TFIBLargeIntField * DocIDHW_REM_CQUERY)=0;

   __property TFIBIntegerField * DocTYPE_REM_CQUERY = {read = get_DocTYPE_REM_CQUERY , write = set_DocTYPE_REM_CQUERY};
   virtual TFIBIntegerField * get_DocTYPE_REM_CQUERY(void)=0;
   virtual void set_DocTYPE_REM_CQUERY(TFIBIntegerField * DocTYPE_REM_CQUERY)=0;

   __property TFIBWideStringField * DocNAME_REM_SHARDWARE = {read = get_DocNAME_REM_SHARDWARE , write = set_DocNAME_REM_SHARDWARE};
   virtual TFIBWideStringField * get_DocNAME_REM_SHARDWARE(void)=0;
   virtual void set_DocNAME_REM_SHARDWARE(TFIBWideStringField * DocNAME_REM_SHARDWARE)=0;

   __property TFIBWideStringField * DocSERNUM_REM_SHARDWARE = {read = get_DocSERNUM_REM_SHARDWARE , write = set_DocSERNUM_REM_SHARDWARE};
   virtual TFIBWideStringField * get_DocSERNUM_REM_SHARDWARE(void)=0;
   virtual void set_DocSERNUM_REM_SHARDWARE(TFIBWideStringField * DocSERNUM_REM_SHARDWARE)=0;

   __property TFIBWideStringField * DocSERNUM2_REM_SHARDWARE = {read = get_DocSERNUM2_REM_SHARDWARE , write = set_DocSERNUM2_REM_SHARDWARE};
   virtual TFIBWideStringField * get_DocSERNUM2_REM_SHARDWARE(void)=0;
   virtual void set_DocSERNUM2_REM_SHARDWARE(TFIBWideStringField * DocSERNUM2_REM_SHARDWARE)=0;

   __property TFIBLargeIntField * DocIDPRMODEL_REM_CQUERY = {read = get_DocIDPRMODEL_REM_CQUERY , write = set_DocIDPRMODEL_REM_CQUERY};
   virtual TFIBLargeIntField * get_DocIDPRMODEL_REM_CQUERY(void)=0;
   virtual void set_DocIDPRMODEL_REM_CQUERY(TFIBLargeIntField * DocIDPRMODEL_REM_CQUERY)=0;

   __property TFIBDateTimeField * DocPOSTUPILO_REM_CQUERY = {read = get_DocPOSTUPILO_REM_CQUERY , write = set_DocPOSTUPILO_REM_CQUERY};
   virtual TFIBDateTimeField * get_DocPOSTUPILO_REM_CQUERY(void)=0;
   virtual void set_DocPOSTUPILO_REM_CQUERY(TFIBDateTimeField * DocPOSTUPILO_REM_CQUERY)=0;

   __property TFIBWideStringField * DocCODE_REM_SMODEL = {read = get_DocCODE_REM_SMODEL , write = set_DocCODE_REM_SMODEL};
   virtual TFIBWideStringField * get_DocCODE_REM_SMODEL(void)=0;
   virtual void set_DocCODE_REM_SMODEL(TFIBWideStringField * DocCODE_REM_SMODEL)=0;

   __property TFIBWideStringField * DocNAME_REM_SPRMODEL = {read = get_DocNAME_REM_SPRMODEL , write = set_DocNAME_REM_SPRMODEL};
   virtual TFIBWideStringField * get_DocNAME_REM_SPRMODEL(void)=0;
   virtual void set_DocNAME_REM_SPRMODEL(TFIBWideStringField * DocNAME_REM_SPRMODEL)=0;

   __property TFIBWideStringField * DocCODE_REM_SPRMODEL = {read = get_DocCODE_REM_SPRMODEL , write = set_DocCODE_REM_SPRMODEL};
   virtual TFIBWideStringField * get_DocCODE_REM_SPRMODEL(void)=0;
   virtual void set_DocCODE_REM_SPRMODEL(TFIBWideStringField * DocCODE_REM_SPRMODEL)=0;

   __property TFIBDateField * DocPLAN_POSTAVKI_REM_CQUERY = {read = get_DocPLAN_POSTAVKI_REM_CQUERY , write = set_DocPLAN_POSTAVKI_REM_CQUERY};
   virtual TFIBDateField * get_DocPLAN_POSTAVKI_REM_CQUERY(void)=0;
   virtual void set_DocPLAN_POSTAVKI_REM_CQUERY(TFIBDateField * DocPLAN_POSTAVKI_REM_CQUERY)=0;

   __property TFIBDateTimeField * DocZAKAZANO_REM_CQUERY = {read = get_DocZAKAZANO_REM_CQUERY , write = set_DocZAKAZANO_REM_CQUERY};
   virtual TFIBDateTimeField * get_DocZAKAZANO_REM_CQUERY(void)=0;
   virtual void set_DocZAKAZANO_REM_CQUERY(TFIBDateTimeField * DocZAKAZANO_REM_CQUERY)=0;

   __property TFIBDateTimeField * DocOTPRAVLENO_REM_CQUERY = {read = get_DocOTPRAVLENO_REM_CQUERY , write = set_DocOTPRAVLENO_REM_CQUERY};
   virtual TFIBDateTimeField * get_DocOTPRAVLENO_REM_CQUERY(void)=0;
   virtual void set_DocOTPRAVLENO_REM_CQUERY(TFIBDateTimeField * DocOTPRAVLENO_REM_CQUERY)=0;

   __property TFIBWideStringField * DocTART_REM_CQUERYT = {read = get_DocTART_REM_CQUERYT , write = set_DocTART_REM_CQUERYT};
   virtual TFIBWideStringField * get_DocTART_REM_CQUERYT(void)=0;
   virtual void set_DocTART_REM_CQUERYT(TFIBWideStringField * DocTART_REM_CQUERYT)=0;

   __property TFIBWideStringField * DocNAME_REM_CQUERY = {read = get_DocNAME_REM_CQUERY , write = set_DocNAME_REM_CQUERY};
   virtual TFIBWideStringField * get_DocNAME_REM_CQUERY(void)=0;
   virtual void set_DocNAME_REM_CQUERY(TFIBWideStringField * DocNAME_REM_CQUERY)=0;

   __property TFIBWideStringField * DocNUM_STR_ZAK_POST_REM_CQUERY = {read = get_DocNUM_STR_ZAK_POST_REM_CQUERY , write = set_DocNUM_STR_ZAK_POST_REM_CQUERY};
   virtual TFIBWideStringField * get_DocNUM_STR_ZAK_POST_REM_CQUERY(void)=0;
   virtual void set_DocNUM_STR_ZAK_POST_REM_CQUERY(TFIBWideStringField * DocNUM_STR_ZAK_POST_REM_CQUERY)=0;

   __property TFIBSmallIntField * DocTFL_ADD_IN_SOBORUD_SNOM = {read = get_DocTFL_ADD_IN_SOBORUD_SNOM , write = set_DocTFL_ADD_IN_SOBORUD_SNOM};
   virtual TFIBSmallIntField * get_DocTFL_ADD_IN_SOBORUD_SNOM(void)=0;
   virtual void set_DocTFL_ADD_IN_SOBORUD_SNOM(TFIBSmallIntField * DocTFL_ADD_IN_SOBORUD_SNOM)=0;

   __property TFIBDateTimeField * DocPOS_ZAK_POST_REM_CQUERY = {read = get_DocPOS_ZAK_POST_REM_CQUERY , write = set_DocPOS_ZAK_POST_REM_CQUERY};
   virtual TFIBDateTimeField * get_DocPOS_ZAK_POST_REM_CQUERY(void)=0;
   virtual void set_DocPOS_ZAK_POST_REM_CQUERY(TFIBDateTimeField * DocPOS_ZAK_POST_REM_CQUERY)=0;

   __property TFIBWideStringField * DocNUM_STR_ZAK_SPROV_REM_CQUERY = {read = get_DocNUM_STR_ZAK_SPROV_REM_CQUERY , write = set_DocNUM_STR_ZAK_SPROV_REM_CQUERY};
   virtual TFIBWideStringField * get_DocNUM_STR_ZAK_SPROV_REM_CQUERY(void)=0;
   virtual void set_DocNUM_STR_ZAK_SPROV_REM_CQUERY(TFIBWideStringField * DocNUM_STR_ZAK_SPROV_REM_CQUERY)=0;

   __property TFIBDateTimeField * DocPOS_ZAK_SPROV_REM_CQUERY = {read = get_DocPOS_ZAK_SPROV_REM_CQUERY , write = set_DocPOS_ZAK_SPROV_REM_CQUERY};
   virtual TFIBDateTimeField * get_DocPOS_ZAK_SPROV_REM_CQUERY(void)=0;
   virtual void set_DocPOS_ZAK_SPROV_REM_CQUERY(TFIBDateTimeField * DocPOS_ZAK_SPROV_REM_CQUERY)=0;

   __property TFIBWideStringField * DocNUM_DOC_OTPR_POST_REM_CQUERY = {read = get_DocNUM_DOC_OTPR_POST_REM_CQUERY , write = set_DocNUM_DOC_OTPR_POST_REM_CQUERY};
   virtual TFIBWideStringField * get_DocNUM_DOC_OTPR_POST_REM_CQUERY(void)=0;
   virtual void set_DocNUM_DOC_OTPR_POST_REM_CQUERY(TFIBWideStringField * DocNUM_DOC_OTPR_POST_REM_CQUERY)=0;

   __property TFIBDateTimeField * DocPOS_DOC_OTPR_POST_REM_CQUERY = {read = get_DocPOS_DOC_OTPR_POST_REM_CQUERY , write = set_DocPOS_DOC_OTPR_POST_REM_CQUERY};
   virtual TFIBDateTimeField * get_DocPOS_DOC_OTPR_POST_REM_CQUERY(void)=0;
   virtual void set_DocPOS_DOC_OTPR_POST_REM_CQUERY(TFIBDateTimeField * DocPOS_DOC_OTPR_POST_REM_CQUERY)=0;

   __property TFIBWideStringField * DocNUMDOCTK_REM_CQUERY = {read = get_DocNUMDOCTK_REM_CQUERY , write = set_DocNUMDOCTK_REM_CQUERY};
   virtual TFIBWideStringField * get_DocNUMDOCTK_REM_CQUERY(void)=0;
   virtual void set_DocNUMDOCTK_REM_CQUERY(TFIBWideStringField * DocNUMDOCTK_REM_CQUERY)=0;

   __property TFIBWideStringField * DocTK_REM_CQUERY = {read = get_DocTK_REM_CQUERY , write = set_DocTK_REM_CQUERY};
   virtual TFIBWideStringField * get_DocTK_REM_CQUERY(void)=0;
   virtual void set_DocTK_REM_CQUERY(TFIBWideStringField * DocTK_REM_CQUERY)=0;

   __property TFIBLargeIntField * DocIDPRODAVEC_REM_CQUERY = {read = get_DocIDPRODAVEC_REM_CQUERY , write = set_DocIDPRODAVEC_REM_CQUERY};
   virtual TFIBLargeIntField * get_DocIDPRODAVEC_REM_CQUERY(void)=0;
   virtual void set_DocIDPRODAVEC_REM_CQUERY(TFIBLargeIntField * DocIDPRODAVEC_REM_CQUERY)=0;

   __property TFIBWideStringField * DocPRODAVEC_NAME = {read = get_DocPRODAVEC_NAME , write = set_DocPRODAVEC_NAME};
   virtual TFIBWideStringField * get_DocPRODAVEC_NAME(void)=0;
   virtual void set_DocPRODAVEC_NAME(TFIBWideStringField * DocPRODAVEC_NAME)=0;

   __property TFIBWideStringField * DocTSER_NUM_REM_CQUERYT = {read = get_DocTSER_NUM_REM_CQUERYT , write = set_DocTSER_NUM_REM_CQUERYT};
   virtual TFIBWideStringField * get_DocTSER_NUM_REM_CQUERYT(void)=0;
   virtual void set_DocTSER_NUM_REM_CQUERYT(TFIBWideStringField * DocTSER_NUM_REM_CQUERYT)=0;

   __property TFIBWideStringField * DocTUCH_SER_NUM_REM_CQUERYT = {read = get_DocTUCH_SER_NUM_REM_CQUERYT , write = set_DocTUCH_SER_NUM_REM_CQUERYT};
   virtual TFIBWideStringField * get_DocTUCH_SER_NUM_REM_CQUERYT(void)=0;
   virtual void set_DocTUCH_SER_NUM_REM_CQUERYT(TFIBWideStringField * DocTUCH_SER_NUM_REM_CQUERYT)=0;

   __property TFIBWideStringField * DocTREF_REM_CQUERYT = {read = get_DocTREF_REM_CQUERYT , write = set_DocTREF_REM_CQUERYT};
   virtual TFIBWideStringField * get_DocTREF_REM_CQUERYT(void)=0;
   virtual void set_DocTREF_REM_CQUERYT(TFIBWideStringField * DocTREF_REM_CQUERYT)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property __int64 IdCQ = {read = get_IdCQ , write = set_IdCQ};
   virtual __int64 get_IdCQ(void)=0;
   virtual void set_IdCQ(__int64 IdCQ)=0;

   __property bool flChangeData = {read = get_flChangeData , write = set_flChangeData};
   virtual bool get_flChangeData(void)=0;
   virtual void set_flChangeData(bool flChangeData)=0;

   virtual void NewDoc(void)=0;
   virtual void OpenDoc(__int64 id)=0;
   virtual bool SaveDoc(void)=0;
   virtual bool DeleteDoc(__int64 id)=0;
   virtual void CloseDoc(void)=0;
   virtual void AddNewRecordDv(void)=0;
};
#define IID_IREM_DMCustQuery __uuidof(IREM_DMCustQuery)
#endif
