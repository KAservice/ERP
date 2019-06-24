#ifndef UREM_DMGurZPredvImplH
#define UREM_DMGurZPredvImplH
#include "IREM_DMGurZPredv.h"
#include "UREM_DMGurZPredv.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMGurZPredvImpl)) TREM_DMGurZPredvImpl : public IREM_DMGurZPredv
{
public:
   TREM_DMGurZPredvImpl();
   ~TREM_DMGurZPredvImpl();
   TREM_DMGurZPredv * Object;
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

//IREM_DMGurZPredv
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBLargeIntField * get_TableID_REM_Z2(void);
   virtual void set_TableID_REM_Z2(TFIBLargeIntField * TableID_REM_Z2);

   virtual TFIBLargeIntField * get_TableIDBASE_REM_Z2(void);
   virtual void set_TableIDBASE_REM_Z2(TFIBLargeIntField * TableIDBASE_REM_Z2);

   virtual TFIBWideStringField * get_TablePREFIKS_REM_Z2(void);
   virtual void set_TablePREFIKS_REM_Z2(TFIBWideStringField * TablePREFIKS_REM_Z2);

   virtual TFIBIntegerField * get_TableNUM_REM_Z2(void);
   virtual void set_TableNUM_REM_Z2(TFIBIntegerField * TableNUM_REM_Z2);

   virtual TFIBWideStringField * get_TableGUID_REM_Z2(void);
   virtual void set_TableGUID_REM_Z2(TFIBWideStringField * TableGUID_REM_Z2);

   virtual TFIBDateTimeField * get_TablePOS_REM_Z2(void);
   virtual void set_TablePOS_REM_Z2(TFIBDateTimeField * TablePOS_REM_Z2);

   virtual TFIBLargeIntField * get_TableIDMODEL_REM_Z2(void);
   virtual void set_TableIDMODEL_REM_Z2(TFIBLargeIntField * TableIDMODEL_REM_Z2);

   virtual TFIBLargeIntField * get_TableIDPRMODEL_REM_Z2(void);
   virtual void set_TableIDPRMODEL_REM_Z2(TFIBLargeIntField * TableIDPRMODEL_REM_Z2);

   virtual TFIBLargeIntField * get_TableIDFIRM_REM_Z2(void);
   virtual void set_TableIDFIRM_REM_Z2(TFIBLargeIntField * TableIDFIRM_REM_Z2);

   virtual TFIBLargeIntField * get_TableIDSKLPR_REM_Z2(void);
   virtual void set_TableIDSKLPR_REM_Z2(TFIBLargeIntField * TableIDSKLPR_REM_Z2);

   virtual TFIBLargeIntField * get_TableIDKLIENT_REM_Z2(void);
   virtual void set_TableIDKLIENT_REM_Z2(TFIBLargeIntField * TableIDKLIENT_REM_Z2);

   virtual TFIBLargeIntField * get_TableIDDILER_REM_Z2(void);
   virtual void set_TableIDDILER_REM_Z2(TFIBLargeIntField * TableIDDILER_REM_Z2);

   virtual TFIBWideStringField * get_TableNAME_REM_Z2(void);
   virtual void set_TableNAME_REM_Z2(TFIBWideStringField * TableNAME_REM_Z2);

   virtual TFIBWideStringField * get_TableDESCR_REM_Z2(void);
   virtual void set_TableDESCR_REM_Z2(TFIBWideStringField * TableDESCR_REM_Z2);

   virtual TFIBWideStringField * get_TableKLIENT_NAME_REM_Z2(void);
   virtual void set_TableKLIENT_NAME_REM_Z2(TFIBWideStringField * TableKLIENT_NAME_REM_Z2);

   virtual TFIBWideStringField * get_TableKLIENT_ADR_REM_Z2(void);
   virtual void set_TableKLIENT_ADR_REM_Z2(TFIBWideStringField * TableKLIENT_ADR_REM_Z2);

   virtual TFIBWideStringField * get_TableKLIENT_PHONE_REM_Z2(void);
   virtual void set_TableKLIENT_PHONE_REM_Z2(TFIBWideStringField * TableKLIENT_PHONE_REM_Z2);

   virtual TFIBWideStringField * get_TableKLIENT_EMAIL_REM_Z2(void);
   virtual void set_TableKLIENT_EMAIL_REM_Z2(TFIBWideStringField * TableKLIENT_EMAIL_REM_Z2);

   virtual TFIBLargeIntField * get_TableIDBRAND_REM_Z2(void);
   virtual void set_TableIDBRAND_REM_Z2(TFIBLargeIntField * TableIDBRAND_REM_Z2);

   virtual TFIBLargeIntField * get_TableIDPRODUCER_REM_Z2(void);
   virtual void set_TableIDPRODUCER_REM_Z2(TFIBLargeIntField * TableIDPRODUCER_REM_Z2);

   virtual TFIBWideStringField * get_TableNEISPR_REM_Z2(void);
   virtual void set_TableNEISPR_REM_Z2(TFIBWideStringField * TableNEISPR_REM_Z2);

   virtual TFIBWideStringField * get_TableSOST_REM_Z2(void);
   virtual void set_TableSOST_REM_Z2(TFIBWideStringField * TableSOST_REM_Z2);

   virtual TFIBWideStringField * get_TableMODEL_STR_REM_Z2(void);
   virtual void set_TableMODEL_STR_REM_Z2(TFIBWideStringField * TableMODEL_STR_REM_Z2);

   virtual TFIBWideStringField * get_TableSERNUM1_REM_Z2(void);
   virtual void set_TableSERNUM1_REM_Z2(TFIBWideStringField * TableSERNUM1_REM_Z2);

   virtual TFIBWideStringField * get_TableSERNUM2_REM_Z2(void);
   virtual void set_TableSERNUM2_REM_Z2(TFIBWideStringField * TableSERNUM2_REM_Z2);

   virtual TFIBLargeIntField * get_TableIDKKT_REM_Z2(void);
   virtual void set_TableIDKKT_REM_Z2(TFIBLargeIntField * TableIDKKT_REM_Z2);

   virtual TFIBLargeIntField * get_TableIDHW_REM_Z2(void);
   virtual void set_TableIDHW_REM_Z2(TFIBLargeIntField * TableIDHW_REM_Z2);

   virtual TFIBLargeIntField * get_TableIDSELLER_REM_Z2(void);
   virtual void set_TableIDSELLER_REM_Z2(TFIBLargeIntField * TableIDSELLER_REM_Z2);

   virtual TFIBWideStringField * get_TableDOPOPISANIE_REM_Z2(void);
   virtual void set_TableDOPOPISANIE_REM_Z2(TFIBWideStringField * TableDOPOPISANIE_REM_Z2);

   virtual TFIBBCDField * get_TableSUMKLIENTA_REM_Z2(void);
   virtual void set_TableSUMKLIENTA_REM_Z2(TFIBBCDField * TableSUMKLIENTA_REM_Z2);

   virtual TFIBBCDField * get_TableSUMNACHA_REM_Z2(void);
   virtual void set_TableSUMNACHA_REM_Z2(TFIBBCDField * TableSUMNACHA_REM_Z2);

   virtual TFIBIntegerField * get_TableRESULT_REM_Z2(void);
   virtual void set_TableRESULT_REM_Z2(TFIBIntegerField * TableRESULT_REM_Z2);

   virtual TFIBWideStringField * get_TablePRICHINA_REM_Z2(void);
   virtual void set_TablePRICHINA_REM_Z2(TFIBWideStringField * TablePRICHINA_REM_Z2);

   virtual TFIBIntegerField * get_TablePRICHINA_LIST_REM_Z2(void);
   virtual void set_TablePRICHINA_LIST_REM_Z2(TFIBIntegerField * TablePRICHINA_LIST_REM_Z2);

   virtual TFIBIntegerField * get_TableSROK_REM_Z2(void);
   virtual void set_TableSROK_REM_Z2(TFIBIntegerField * TableSROK_REM_Z2);

   virtual TFIBLargeIntField * get_TableIDUSER_REM_Z2(void);
   virtual void set_TableIDUSER_REM_Z2(TFIBLargeIntField * TableIDUSER_REM_Z2);

   virtual TFIBWideStringField * get_TableNAME_SINFBASE_OBMEN(void);
   virtual void set_TableNAME_SINFBASE_OBMEN(TFIBWideStringField * TableNAME_SINFBASE_OBMEN);

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

   virtual TFIBWideStringField * get_TableNAME_USER(void);
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER);

   virtual TFIBWideStringField * get_TableNAME_SBRAND(void);
   virtual void set_TableNAME_SBRAND(TFIBWideStringField * TableNAME_SBRAND);

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
#define CLSID_TREM_DMGurZPredvImpl __uuidof(TREM_DMGurZPredvImpl)
#endif
