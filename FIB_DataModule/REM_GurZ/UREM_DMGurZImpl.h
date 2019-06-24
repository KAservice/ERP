#ifndef UREM_DMGurZImplH
#define UREM_DMGurZImplH
#include "IREM_DMGurZ.h"
#include "UREM_DMGurZ.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMGurZImpl)) TREM_DMGurZImpl : public IREM_DMGurZ
{
public:
   TREM_DMGurZImpl();
   ~TREM_DMGurZImpl();
   TREM_DMGurZ * Object;
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

//IREM_DMGurZ
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBLargeIntField * get_TableID_REM_Z(void);
   virtual void set_TableID_REM_Z(TFIBLargeIntField * TableID_REM_Z);

   virtual TFIBWideStringField * get_TableGID_REM_Z(void);
   virtual void set_TableGID_REM_Z(TFIBWideStringField * TableGID_REM_Z);

   virtual TFIBWideStringField * get_TablePREFIKS_REM_Z(void);
   virtual void set_TablePREFIKS_REM_Z(TFIBWideStringField * TablePREFIKS_REM_Z);

   virtual TFIBIntegerField * get_TableNUM_REM_Z(void);
   virtual void set_TableNUM_REM_Z(TFIBIntegerField * TableNUM_REM_Z);

   virtual TFIBDateTimeField * get_TablePOS_REM_Z(void);
   virtual void set_TablePOS_REM_Z(TFIBDateTimeField * TablePOS_REM_Z);

   virtual TFIBLargeIntField * get_TableIDBASE_REM_Z(void);
   virtual void set_TableIDBASE_REM_Z(TFIBLargeIntField * TableIDBASE_REM_Z);

   virtual TFIBLargeIntField * get_TableIDMODEL_REM_Z(void);
   virtual void set_TableIDMODEL_REM_Z(TFIBLargeIntField * TableIDMODEL_REM_Z);

   virtual TFIBLargeIntField * get_TableIDSKLPR_REM_Z(void);
   virtual void set_TableIDSKLPR_REM_Z(TFIBLargeIntField * TableIDSKLPR_REM_Z);

   virtual TFIBLargeIntField * get_TableIDKLIENT_REM_Z(void);
   virtual void set_TableIDKLIENT_REM_Z(TFIBLargeIntField * TableIDKLIENT_REM_Z);

   virtual TFIBLargeIntField * get_TableIDDILER_REM_Z(void);
   virtual void set_TableIDDILER_REM_Z(TFIBLargeIntField * TableIDDILER_REM_Z);

   virtual TFIBWideStringField * get_TableSERNUM_REM_Z(void);
   virtual void set_TableSERNUM_REM_Z(TFIBWideStringField * TableSERNUM_REM_Z);

   virtual TFIBWideStringField * get_TableNAME_REM_Z(void);
   virtual void set_TableNAME_REM_Z(TFIBWideStringField * TableNAME_REM_Z);

   virtual TFIBWideStringField * get_TableDESCR_REM_Z(void);
   virtual void set_TableDESCR_REM_Z(TFIBWideStringField * TableDESCR_REM_Z);

   virtual TFIBLargeIntField * get_TableIDTYPEREM_REM_Z(void);
   virtual void set_TableIDTYPEREM_REM_Z(TFIBLargeIntField * TableIDTYPEREM_REM_Z);

   virtual TFIBLargeIntField * get_TableIDSOST_REM_Z(void);
   virtual void set_TableIDSOST_REM_Z(TFIBLargeIntField * TableIDSOST_REM_Z);

   virtual TFIBLargeIntField * get_TableIDTECSKL_REM_Z(void);
   virtual void set_TableIDTECSKL_REM_Z(TFIBLargeIntField * TableIDTECSKL_REM_Z);

   virtual TFIBLargeIntField * get_TableIDUSER_REM_Z(void);
   virtual void set_TableIDUSER_REM_Z(TFIBLargeIntField * TableIDUSER_REM_Z);

   virtual TFIBIntegerField * get_TableOPER_REM_Z(void);
   virtual void set_TableOPER_REM_Z(TFIBIntegerField * TableOPER_REM_Z);

   virtual TFIBBCDField * get_TableSUM_REM_Z(void);
   virtual void set_TableSUM_REM_Z(TFIBBCDField * TableSUM_REM_Z);

   virtual TFIBDateField * get_TableSROK_REM_Z(void);
   virtual void set_TableSROK_REM_Z(TFIBDateField * TableSROK_REM_Z);

   virtual TFIBIntegerField * get_TableOUT_REM_Z(void);
   virtual void set_TableOUT_REM_Z(TFIBIntegerField * TableOUT_REM_Z);

   virtual TFIBLargeIntField * get_TableIDFIRM_REM_Z(void);
   virtual void set_TableIDFIRM_REM_Z(TFIBLargeIntField * TableIDFIRM_REM_Z);

   virtual TFIBWideStringField * get_TableNAMEFIRM(void);
   virtual void set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM);

   virtual TFIBWideStringField * get_TableNAME_REM_SMODEL(void);
   virtual void set_TableNAME_REM_SMODEL(TFIBWideStringField * TableNAME_REM_SMODEL);

   virtual TFIBWideStringField * get_TableNAME_SKLAD_PR(void);
   virtual void set_TableNAME_SKLAD_PR(TFIBWideStringField * TableNAME_SKLAD_PR);

   virtual TFIBWideStringField * get_TableNAMEKLIENT(void);
   virtual void set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT);

   virtual TFIBWideStringField * get_TableNAMEDILER(void);
   virtual void set_TableNAMEDILER(TFIBWideStringField * TableNAMEDILER);

   virtual TFIBWideStringField * get_TableNAME_STREMONT(void);
   virtual void set_TableNAME_STREMONT(TFIBWideStringField * TableNAME_STREMONT);

   virtual TFIBWideStringField * get_TableNAME_REMSSOST(void);
   virtual void set_TableNAME_REMSSOST(TFIBWideStringField * TableNAME_REMSSOST);

   virtual TFIBWideStringField * get_TableNAME_SKLAD_TEC(void);
   virtual void set_TableNAME_SKLAD_TEC(TFIBWideStringField * TableNAME_SKLAD_TEC);

   virtual TFIBWideStringField * get_TableNAME_USER(void);
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER);

   virtual TFIBWideStringField * get_TableKLIENT_NAME_REM_Z(void);
   virtual void set_TableKLIENT_NAME_REM_Z(TFIBWideStringField * TableKLIENT_NAME_REM_Z);

   virtual TFIBWideStringField * get_TableMODEL_REM_Z(void);
   virtual void set_TableMODEL_REM_Z(TFIBWideStringField * TableMODEL_REM_Z);

   virtual TFIBWideStringField * get_TableSERNUM2_REM_Z(void);
   virtual void set_TableSERNUM2_REM_Z(TFIBWideStringField * TableSERNUM2_REM_Z);

   virtual TFIBIntegerField * get_TableFL_KLIENT_UVEDOML_REM_Z(void);
   virtual void set_TableFL_KLIENT_UVEDOML_REM_Z(TFIBIntegerField * TableFL_KLIENT_UVEDOML_REM_Z);

   virtual TFIBIntegerField * get_TableFL_TREB_KONS_KL_REM_Z(void);
   virtual void set_TableFL_TREB_KONS_KL_REM_Z(TFIBIntegerField * TableFL_TREB_KONS_KL_REM_Z);

   virtual TFIBIntegerField * get_TableFL_KL_OTV_NA_ZAPROS_REM_Z(void);
   virtual void set_TableFL_KL_OTV_NA_ZAPROS_REM_Z(TFIBIntegerField * TableFL_KL_OTV_NA_ZAPROS_REM_Z);

   virtual TFIBWideStringField * get_TablePREFIKS_NUM_REM_Z(void);
   virtual void set_TablePREFIKS_NUM_REM_Z(TFIBWideStringField * TablePREFIKS_NUM_REM_Z);

   virtual TFIBWideStringField * get_TableNAME_SINFBASE_OBMEN(void);
   virtual void set_TableNAME_SINFBASE_OBMEN(TFIBWideStringField * TableNAME_SINFBASE_OBMEN);

   virtual TFIBLargeIntField * get_TableIDBRAND_REM_Z(void);
   virtual void set_TableIDBRAND_REM_Z(TFIBLargeIntField * TableIDBRAND_REM_Z);

   virtual TFIBSmallIntField * get_TableFL_POVTOR_REM_Z(void);
   virtual void set_TableFL_POVTOR_REM_Z(TFIBSmallIntField * TableFL_POVTOR_REM_Z);

   virtual TFIBSmallIntField * get_TableFL_ADDREPORT_REM_Z(void);
   virtual void set_TableFL_ADDREPORT_REM_Z(TFIBSmallIntField * TableFL_ADDREPORT_REM_Z);

   virtual TFIBWideStringField * get_TableNUM_GARDOC_REM_Z(void);
   virtual void set_TableNUM_GARDOC_REM_Z(TFIBWideStringField * TableNUM_GARDOC_REM_Z);

   virtual TFIBWideStringField * get_TableNAME_SBRAND(void);
   virtual void set_TableNAME_SBRAND(TFIBWideStringField * TableNAME_SBRAND);

   virtual TFIBIntegerField * get_TableFL_FICTIV_REM_Z(void);
   virtual void set_TableFL_FICTIV_REM_Z(TFIBIntegerField * TableFL_FICTIV_REM_Z);

   virtual TFIBSmallIntField * get_TableFL_NE_OTCH_REM_Z(void);
   virtual void set_TableFL_NE_OTCH_REM_Z(TFIBSmallIntField * TableFL_NE_OTCH_REM_Z);

   virtual TFIBSmallIntField * get_TableFL_NADO_OTCH_REM_Z(void);
   virtual void set_TableFL_NADO_OTCH_REM_Z(TFIBSmallIntField * TableFL_NADO_OTCH_REM_Z);

   virtual TFIBSmallIntField * get_TableSOST_CQUERY(void);
   virtual void set_TableSOST_CQUERY(TFIBSmallIntField * TableSOST_CQUERY);

   virtual TFIBLargeIntField * get_TableID_REM_CQUERY(void);
   virtual void set_TableID_REM_CQUERY(TFIBLargeIntField * TableID_REM_CQUERY);

   virtual TIntegerField * get_TableSROK_REMONTA(void);
   virtual void set_TableSROK_REMONTA(TIntegerField * TableSROK_REMONTA);

   virtual TIntegerField * get_TableSROK_REMONTA_NOW(void);
   virtual void set_TableSROK_REMONTA_NOW(TIntegerField * TableSROK_REMONTA_NOW);

   virtual TFIBDateTimeField * get_TablePOSOUT_REM_Z(void);
   virtual void set_TablePOSOUT_REM_Z(TFIBDateTimeField * TablePOSOUT_REM_Z);

   virtual TFIBDateTimeField * get_TablePOSREMONT_REM_Z(void);
   virtual void set_TablePOSREMONT_REM_Z(TFIBDateTimeField * TablePOSREMONT_REM_Z);

   virtual TFIBSmallIntField * get_TableGOTOVO_K_VIDACHE_REM_Z(void);
   virtual void set_TableGOTOVO_K_VIDACHE_REM_Z(TFIBSmallIntField * TableGOTOVO_K_VIDACHE_REM_Z);

   virtual TFIBWideStringField * get_TableNAME_SKLAD_OST(void);
   virtual void set_TableNAME_SKLAD_OST(TFIBWideStringField * TableNAME_SKLAD_OST);

   virtual TFIBLargeIntField * get_TableIDREC_RGOTPRZ(void);
   virtual void set_TableIDREC_RGOTPRZ(TFIBLargeIntField * TableIDREC_RGOTPRZ);

   virtual TFIBLargeIntField * get_TableIDDOC_VIDACHA_HW(void);
   virtual void set_TableIDDOC_VIDACHA_HW(TFIBLargeIntField * TableIDDOC_VIDACHA_HW);

   virtual TFIBLargeIntField * get_TableIDDOC_VOSVRAT_HW(void);
   virtual void set_TableIDDOC_VOSVRAT_HW(TFIBLargeIntField * TableIDDOC_VOSVRAT_HW);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual __int64 get_IdZ(void);
   virtual void set_IdZ(__int64 IdZ);

   virtual TDateTime get_PosNach(void);
   virtual void set_PosNach(TDateTime PosNach);

   virtual TDateTime get_PosCon(void);
   virtual void set_PosCon(TDateTime PosCon);

   virtual void OpenTable();
   virtual void UpdateTable(void);
   virtual void PoiskPoSerNum1(UnicodeString ser_num);
   virtual void PoiskPoSerNum2(UnicodeString ser_num);
   virtual void PoiskPoKlient(UnicodeString value);
   virtual void PoiskPoModel(UnicodeString value);
   virtual void PoiskPoIdHardware(__int64 id_hw);
   virtual void PoiskPoNumGarDoc(UnicodeString num_gar_doc);
   virtual void OpenTableOtbor(TDateTime pos_start,TDateTime pos_end,int poisk,UnicodeString str_value,__int64 int64_value);
};
#define CLSID_TREM_DMGurZImpl __uuidof(TREM_DMGurZImpl)
#endif
