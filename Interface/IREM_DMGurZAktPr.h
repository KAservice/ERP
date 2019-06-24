#ifndef UIREM_DMGurZAktPrH
#define UIREM_DMGurZAktPrH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMGurZAktPr)) IREM_DMGurZAktPr : public IMainInterface
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

   __property TFIBDateTimeField * TablePOS_REM_GALLDOC = {read = get_TablePOS_REM_GALLDOC , write = set_TablePOS_REM_GALLDOC};
   virtual TFIBDateTimeField * get_TablePOS_REM_GALLDOC(void)=0;
   virtual void set_TablePOS_REM_GALLDOC(TFIBDateTimeField * TablePOS_REM_GALLDOC)=0;

   __property TFIBIntegerField * TableNUM_REM_GALLDOC = {read = get_TableNUM_REM_GALLDOC , write = set_TableNUM_REM_GALLDOC};
   virtual TFIBIntegerField * get_TableNUM_REM_GALLDOC(void)=0;
   virtual void set_TableNUM_REM_GALLDOC(TFIBIntegerField * TableNUM_REM_GALLDOC)=0;

   __property TFIBDateTimeField * TablePOS_REM_Z = {read = get_TablePOS_REM_Z , write = set_TablePOS_REM_Z};
   virtual TFIBDateTimeField * get_TablePOS_REM_Z(void)=0;
   virtual void set_TablePOS_REM_Z(TFIBDateTimeField * TablePOS_REM_Z)=0;

   __property TFIBWideStringField * TablePREFIKS_NUM_REM_Z = {read = get_TablePREFIKS_NUM_REM_Z , write = set_TablePREFIKS_NUM_REM_Z};
   virtual TFIBWideStringField * get_TablePREFIKS_NUM_REM_Z(void)=0;
   virtual void set_TablePREFIKS_NUM_REM_Z(TFIBWideStringField * TablePREFIKS_NUM_REM_Z)=0;

   __property TFIBIntegerField * TableNUM_REM_Z = {read = get_TableNUM_REM_Z , write = set_TableNUM_REM_Z};
   virtual TFIBIntegerField * get_TableNUM_REM_Z(void)=0;
   virtual void set_TableNUM_REM_Z(TFIBIntegerField * TableNUM_REM_Z)=0;

   __property TFIBWideStringField * TableNUM_GARDOC_REM_Z = {read = get_TableNUM_GARDOC_REM_Z , write = set_TableNUM_GARDOC_REM_Z};
   virtual TFIBWideStringField * get_TableNUM_GARDOC_REM_Z(void)=0;
   virtual void set_TableNUM_GARDOC_REM_Z(TFIBWideStringField * TableNUM_GARDOC_REM_Z)=0;

   __property TFIBWideStringField * TableSERNUM_REM_Z = {read = get_TableSERNUM_REM_Z , write = set_TableSERNUM_REM_Z};
   virtual TFIBWideStringField * get_TableSERNUM_REM_Z(void)=0;
   virtual void set_TableSERNUM_REM_Z(TFIBWideStringField * TableSERNUM_REM_Z)=0;

   __property TFIBWideStringField * TableSERNUM2_REM_Z = {read = get_TableSERNUM2_REM_Z , write = set_TableSERNUM2_REM_Z};
   virtual TFIBWideStringField * get_TableSERNUM2_REM_Z(void)=0;
   virtual void set_TableSERNUM2_REM_Z(TFIBWideStringField * TableSERNUM2_REM_Z)=0;

   __property TFIBWideStringField * TableNAMEFIRM = {read = get_TableNAMEFIRM , write = set_TableNAMEFIRM};
   virtual TFIBWideStringField * get_TableNAMEFIRM(void)=0;
   virtual void set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM)=0;

   __property TFIBWideStringField * TableNAMESKLAD = {read = get_TableNAMESKLAD , write = set_TableNAMESKLAD};
   virtual TFIBWideStringField * get_TableNAMESKLAD(void)=0;
   virtual void set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)=0;

   __property TFIBWideStringField * TableNAMEKLIENT = {read = get_TableNAMEKLIENT , write = set_TableNAMEKLIENT};
   virtual TFIBWideStringField * get_TableNAMEKLIENT(void)=0;
   virtual void set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)=0;

   __property TFIBWideStringField * TableNAME_USER = {read = get_TableNAME_USER , write = set_TableNAME_USER};
   virtual TFIBWideStringField * get_TableNAME_USER(void)=0;
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)=0;

   __property TFIBWideStringField * TableNAME_SINFBASE_OBMEN = {read = get_TableNAME_SINFBASE_OBMEN , write = set_TableNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_TableNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_TableNAME_SINFBASE_OBMEN(TFIBWideStringField * TableNAME_SINFBASE_OBMEN)=0;

   __property TFIBWideStringField * TableKLIENT_NAME_REM_DZAKTPR = {read = get_TableKLIENT_NAME_REM_DZAKTPR , write = set_TableKLIENT_NAME_REM_DZAKTPR};
   virtual TFIBWideStringField * get_TableKLIENT_NAME_REM_DZAKTPR(void)=0;
   virtual void set_TableKLIENT_NAME_REM_DZAKTPR(TFIBWideStringField * TableKLIENT_NAME_REM_DZAKTPR)=0;

   __property TFIBWideStringField * TableKLIENT_ADR_REM_DZAKTPR = {read = get_TableKLIENT_ADR_REM_DZAKTPR , write = set_TableKLIENT_ADR_REM_DZAKTPR};
   virtual TFIBWideStringField * get_TableKLIENT_ADR_REM_DZAKTPR(void)=0;
   virtual void set_TableKLIENT_ADR_REM_DZAKTPR(TFIBWideStringField * TableKLIENT_ADR_REM_DZAKTPR)=0;

   __property TFIBWideStringField * TableKLIENT_PHONE_REM_DZAKTPR = {read = get_TableKLIENT_PHONE_REM_DZAKTPR , write = set_TableKLIENT_PHONE_REM_DZAKTPR};
   virtual TFIBWideStringField * get_TableKLIENT_PHONE_REM_DZAKTPR(void)=0;
   virtual void set_TableKLIENT_PHONE_REM_DZAKTPR(TFIBWideStringField * TableKLIENT_PHONE_REM_DZAKTPR)=0;

   __property TFIBLargeIntField * TableIDDOC_REM_DZAKTPR = {read = get_TableIDDOC_REM_DZAKTPR , write = set_TableIDDOC_REM_DZAKTPR};
   virtual TFIBLargeIntField * get_TableIDDOC_REM_DZAKTPR(void)=0;
   virtual void set_TableIDDOC_REM_DZAKTPR(TFIBLargeIntField * TableIDDOC_REM_DZAKTPR)=0;

   __property TFIBIntegerField * TableFL_FICTIV_REM_DZAKTPR = {read = get_TableFL_FICTIV_REM_DZAKTPR , write = set_TableFL_FICTIV_REM_DZAKTPR};
   virtual TFIBIntegerField * get_TableFL_FICTIV_REM_DZAKTPR(void)=0;
   virtual void set_TableFL_FICTIV_REM_DZAKTPR(TFIBIntegerField * TableFL_FICTIV_REM_DZAKTPR)=0;

   __property TFIBSmallIntField * TablePR_REM_GALLDOC = {read = get_TablePR_REM_GALLDOC , write = set_TablePR_REM_GALLDOC};
   virtual TFIBSmallIntField * get_TablePR_REM_GALLDOC(void)=0;
   virtual void set_TablePR_REM_GALLDOC(TFIBSmallIntField * TablePR_REM_GALLDOC)=0;

   __property TFIBWideStringField * TablePREFIKS_NUM_REM_GALLDOC = {read = get_TablePREFIKS_NUM_REM_GALLDOC , write = set_TablePREFIKS_NUM_REM_GALLDOC};
   virtual TFIBWideStringField * get_TablePREFIKS_NUM_REM_GALLDOC(void)=0;
   virtual void set_TablePREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * TablePREFIKS_NUM_REM_GALLDOC)=0;

   __property TFIBBCDField * TableSUM_REM_GALLDOC = {read = get_TableSUM_REM_GALLDOC , write = set_TableSUM_REM_GALLDOC};
   virtual TFIBBCDField * get_TableSUM_REM_GALLDOC(void)=0;
   virtual void set_TableSUM_REM_GALLDOC(TFIBBCDField * TableSUM_REM_GALLDOC)=0;

   __property TFIBWideStringField * TableNAME_REM_SPRMODEL = {read = get_TableNAME_REM_SPRMODEL , write = set_TableNAME_REM_SPRMODEL};
   virtual TFIBWideStringField * get_TableNAME_REM_SPRMODEL(void)=0;
   virtual void set_TableNAME_REM_SPRMODEL(TFIBWideStringField * TableNAME_REM_SPRMODEL)=0;

   __property TFIBWideStringField * TableNUMGARTALON_REM_DZAKTPR = {read = get_TableNUMGARTALON_REM_DZAKTPR , write = set_TableNUMGARTALON_REM_DZAKTPR};
   virtual TFIBWideStringField * get_TableNUMGARTALON_REM_DZAKTPR(void)=0;
   virtual void set_TableNUMGARTALON_REM_DZAKTPR(TFIBWideStringField * TableNUMGARTALON_REM_DZAKTPR)=0;

   __property TFIBSmallIntField * TableFL_POVTOR_REM_Z = {read = get_TableFL_POVTOR_REM_Z , write = set_TableFL_POVTOR_REM_Z};
   virtual TFIBSmallIntField * get_TableFL_POVTOR_REM_Z(void)=0;
   virtual void set_TableFL_POVTOR_REM_Z(TFIBSmallIntField * TableFL_POVTOR_REM_Z)=0;

   __property TFIBSmallIntField * TableFL_ADDREPORT_REM_Z = {read = get_TableFL_ADDREPORT_REM_Z , write = set_TableFL_ADDREPORT_REM_Z};
   virtual TFIBSmallIntField * get_TableFL_ADDREPORT_REM_Z(void)=0;
   virtual void set_TableFL_ADDREPORT_REM_Z(TFIBSmallIntField * TableFL_ADDREPORT_REM_Z)=0;

   __property TFIBIntegerField * TableFL_FICTIV_REM_Z = {read = get_TableFL_FICTIV_REM_Z , write = set_TableFL_FICTIV_REM_Z};
   virtual TFIBIntegerField * get_TableFL_FICTIV_REM_Z(void)=0;
   virtual void set_TableFL_FICTIV_REM_Z(TFIBIntegerField * TableFL_FICTIV_REM_Z)=0;

   __property TFIBSmallIntField * TableFL_NE_OTCH_REM_Z = {read = get_TableFL_NE_OTCH_REM_Z , write = set_TableFL_NE_OTCH_REM_Z};
   virtual TFIBSmallIntField * get_TableFL_NE_OTCH_REM_Z(void)=0;
   virtual void set_TableFL_NE_OTCH_REM_Z(TFIBSmallIntField * TableFL_NE_OTCH_REM_Z)=0;

   __property TFIBSmallIntField * TableFL_NADO_OTCH_REM_Z = {read = get_TableFL_NADO_OTCH_REM_Z , write = set_TableFL_NADO_OTCH_REM_Z};
   virtual TFIBSmallIntField * get_TableFL_NADO_OTCH_REM_Z(void)=0;
   virtual void set_TableFL_NADO_OTCH_REM_Z(TFIBSmallIntField * TableFL_NADO_OTCH_REM_Z)=0;

   __property TFIBSmallIntField * TableFL_NE_OTCH_REM_DZAKTPR = {read = get_TableFL_NE_OTCH_REM_DZAKTPR , write = set_TableFL_NE_OTCH_REM_DZAKTPR};
   virtual TFIBSmallIntField * get_TableFL_NE_OTCH_REM_DZAKTPR(void)=0;
   virtual void set_TableFL_NE_OTCH_REM_DZAKTPR(TFIBSmallIntField * TableFL_NE_OTCH_REM_DZAKTPR)=0;

   __property TFIBSmallIntField * TableFL_NADO_OTCH_REM_DZAKTPR = {read = get_TableFL_NADO_OTCH_REM_DZAKTPR , write = set_TableFL_NADO_OTCH_REM_DZAKTPR};
   virtual TFIBSmallIntField * get_TableFL_NADO_OTCH_REM_DZAKTPR(void)=0;
   virtual void set_TableFL_NADO_OTCH_REM_DZAKTPR(TFIBSmallIntField * TableFL_NADO_OTCH_REM_DZAKTPR)=0;

   __property TIntegerField * TableSROK_REMONTA = {read = get_TableSROK_REMONTA , write = set_TableSROK_REMONTA};
   virtual TIntegerField * get_TableSROK_REMONTA(void)=0;
   virtual void set_TableSROK_REMONTA(TIntegerField * TableSROK_REMONTA)=0;

   __property TIntegerField * TableSROK_REMONTA_NOW = {read = get_TableSROK_REMONTA_NOW , write = set_TableSROK_REMONTA_NOW};
   virtual TIntegerField * get_TableSROK_REMONTA_NOW(void)=0;
   virtual void set_TableSROK_REMONTA_NOW(TIntegerField * TableSROK_REMONTA_NOW)=0;

   __property TIntegerField * TableSROK_REMONTA_IS_DOC = {read = get_TableSROK_REMONTA_IS_DOC , write = set_TableSROK_REMONTA_IS_DOC};
   virtual TIntegerField * get_TableSROK_REMONTA_IS_DOC(void)=0;
   virtual void set_TableSROK_REMONTA_IS_DOC(TIntegerField * TableSROK_REMONTA_IS_DOC)=0;

   __property TFIBDateTimeField * TablePOSPRIEMA_REM_DZAKTPR = {read = get_TablePOSPRIEMA_REM_DZAKTPR , write = set_TablePOSPRIEMA_REM_DZAKTPR};
   virtual TFIBDateTimeField * get_TablePOSPRIEMA_REM_DZAKTPR(void)=0;
   virtual void set_TablePOSPRIEMA_REM_DZAKTPR(TFIBDateTimeField * TablePOSPRIEMA_REM_DZAKTPR)=0;

   __property TDateTime PosNach = {read = get_PosNach , write = set_PosNach};
   virtual TDateTime get_PosNach(void)=0;
   virtual void set_PosNach(TDateTime PosNach)=0;

   __property TDateTime PosCon = {read = get_PosCon , write = set_PosCon};
   virtual TDateTime get_PosCon(void)=0;
   virtual void set_PosCon(TDateTime PosCon)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property __int64 IdKlient = {read = get_IdKlient , write = set_IdKlient};
   virtual __int64 get_IdKlient(void)=0;
   virtual void set_IdKlient(__int64 IdKlient)=0;

   __property __int64 IdSklad = {read = get_IdSklad , write = set_IdSklad};
   virtual __int64 get_IdSklad(void)=0;
   virtual void set_IdSklad(__int64 IdSklad)=0;

   __property __int64 IdFirm = {read = get_IdFirm , write = set_IdFirm};
   virtual __int64 get_IdFirm(void)=0;
   virtual void set_IdFirm(__int64 IdFirm)=0;

   virtual void OpenTable()=0;
   virtual void UpdateTable(void)=0;
   virtual bool OpenTableOnlyHardware(__int64 id_hw)=0;
   virtual bool OpenTableOnlyZayavka(__int64 id_z)=0;
   virtual void PoiskPoSerNum1(UnicodeString ser_num)=0;
   virtual void PoiskPoSerNum2(UnicodeString ser_num)=0;
   virtual void PoiskPoKlient(UnicodeString value)=0;
   virtual void PoiskPoModel(UnicodeString value)=0;
   virtual void PoiskPoIdHardware(__int64 id_hw)=0;
   virtual void PoiskPoNumGarDoc(UnicodeString num_gar_doc)=0;
};
#define IID_IREM_DMGurZAktPr __uuidof(IREM_DMGurZAktPr)
#endif
