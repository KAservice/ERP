#ifndef UREM_DMGurZAktPrImplH
#define UREM_DMGurZAktPrImplH
#include "IREM_DMGurZAktPr.h"
#include "UREM_DMGurZAktPr.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMGurZAktPrImpl)) TREM_DMGurZAktPrImpl : public IREM_DMGurZAktPr
{
public:
   TREM_DMGurZAktPrImpl();
   ~TREM_DMGurZAktPrImpl();
   TREM_DMGurZAktPr * Object;
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

//IREM_DMGurZAktPr
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBDateTimeField * get_TablePOS_REM_GALLDOC(void);
   virtual void set_TablePOS_REM_GALLDOC(TFIBDateTimeField * TablePOS_REM_GALLDOC);

   virtual TFIBIntegerField * get_TableNUM_REM_GALLDOC(void);
   virtual void set_TableNUM_REM_GALLDOC(TFIBIntegerField * TableNUM_REM_GALLDOC);

   virtual TFIBDateTimeField * get_TablePOS_REM_Z(void);
   virtual void set_TablePOS_REM_Z(TFIBDateTimeField * TablePOS_REM_Z);

   virtual TFIBWideStringField * get_TablePREFIKS_NUM_REM_Z(void);
   virtual void set_TablePREFIKS_NUM_REM_Z(TFIBWideStringField * TablePREFIKS_NUM_REM_Z);

   virtual TFIBIntegerField * get_TableNUM_REM_Z(void);
   virtual void set_TableNUM_REM_Z(TFIBIntegerField * TableNUM_REM_Z);

   virtual TFIBWideStringField * get_TableNUM_GARDOC_REM_Z(void);
   virtual void set_TableNUM_GARDOC_REM_Z(TFIBWideStringField * TableNUM_GARDOC_REM_Z);

   virtual TFIBWideStringField * get_TableSERNUM_REM_Z(void);
   virtual void set_TableSERNUM_REM_Z(TFIBWideStringField * TableSERNUM_REM_Z);

   virtual TFIBWideStringField * get_TableSERNUM2_REM_Z(void);
   virtual void set_TableSERNUM2_REM_Z(TFIBWideStringField * TableSERNUM2_REM_Z);

   virtual TFIBWideStringField * get_TableNAMEFIRM(void);
   virtual void set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM);

   virtual TFIBWideStringField * get_TableNAMESKLAD(void);
   virtual void set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD);

   virtual TFIBWideStringField * get_TableNAMEKLIENT(void);
   virtual void set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT);

   virtual TFIBWideStringField * get_TableNAME_USER(void);
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER);

   virtual TFIBWideStringField * get_TableNAME_SINFBASE_OBMEN(void);
   virtual void set_TableNAME_SINFBASE_OBMEN(TFIBWideStringField * TableNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_TableKLIENT_NAME_REM_DZAKTPR(void);
   virtual void set_TableKLIENT_NAME_REM_DZAKTPR(TFIBWideStringField * TableKLIENT_NAME_REM_DZAKTPR);

   virtual TFIBWideStringField * get_TableKLIENT_ADR_REM_DZAKTPR(void);
   virtual void set_TableKLIENT_ADR_REM_DZAKTPR(TFIBWideStringField * TableKLIENT_ADR_REM_DZAKTPR);

   virtual TFIBWideStringField * get_TableKLIENT_PHONE_REM_DZAKTPR(void);
   virtual void set_TableKLIENT_PHONE_REM_DZAKTPR(TFIBWideStringField * TableKLIENT_PHONE_REM_DZAKTPR);

   virtual TFIBLargeIntField * get_TableIDDOC_REM_DZAKTPR(void);
   virtual void set_TableIDDOC_REM_DZAKTPR(TFIBLargeIntField * TableIDDOC_REM_DZAKTPR);

   virtual TFIBIntegerField * get_TableFL_FICTIV_REM_DZAKTPR(void);
   virtual void set_TableFL_FICTIV_REM_DZAKTPR(TFIBIntegerField * TableFL_FICTIV_REM_DZAKTPR);

   virtual TFIBSmallIntField * get_TablePR_REM_GALLDOC(void);
   virtual void set_TablePR_REM_GALLDOC(TFIBSmallIntField * TablePR_REM_GALLDOC);

   virtual TFIBWideStringField * get_TablePREFIKS_NUM_REM_GALLDOC(void);
   virtual void set_TablePREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * TablePREFIKS_NUM_REM_GALLDOC);

   virtual TFIBBCDField * get_TableSUM_REM_GALLDOC(void);
   virtual void set_TableSUM_REM_GALLDOC(TFIBBCDField * TableSUM_REM_GALLDOC);

   virtual TFIBWideStringField * get_TableNAME_REM_SPRMODEL(void);
   virtual void set_TableNAME_REM_SPRMODEL(TFIBWideStringField * TableNAME_REM_SPRMODEL);

   virtual TFIBWideStringField * get_TableNUMGARTALON_REM_DZAKTPR(void);
   virtual void set_TableNUMGARTALON_REM_DZAKTPR(TFIBWideStringField * TableNUMGARTALON_REM_DZAKTPR);

   virtual TFIBSmallIntField * get_TableFL_POVTOR_REM_Z(void);
   virtual void set_TableFL_POVTOR_REM_Z(TFIBSmallIntField * TableFL_POVTOR_REM_Z);

   virtual TFIBSmallIntField * get_TableFL_ADDREPORT_REM_Z(void);
   virtual void set_TableFL_ADDREPORT_REM_Z(TFIBSmallIntField * TableFL_ADDREPORT_REM_Z);

   virtual TFIBIntegerField * get_TableFL_FICTIV_REM_Z(void);
   virtual void set_TableFL_FICTIV_REM_Z(TFIBIntegerField * TableFL_FICTIV_REM_Z);

   virtual TFIBSmallIntField * get_TableFL_NE_OTCH_REM_Z(void);
   virtual void set_TableFL_NE_OTCH_REM_Z(TFIBSmallIntField * TableFL_NE_OTCH_REM_Z);

   virtual TFIBSmallIntField * get_TableFL_NADO_OTCH_REM_Z(void);
   virtual void set_TableFL_NADO_OTCH_REM_Z(TFIBSmallIntField * TableFL_NADO_OTCH_REM_Z);

   virtual TFIBSmallIntField * get_TableFL_NE_OTCH_REM_DZAKTPR(void);
   virtual void set_TableFL_NE_OTCH_REM_DZAKTPR(TFIBSmallIntField * TableFL_NE_OTCH_REM_DZAKTPR);

   virtual TFIBSmallIntField * get_TableFL_NADO_OTCH_REM_DZAKTPR(void);
   virtual void set_TableFL_NADO_OTCH_REM_DZAKTPR(TFIBSmallIntField * TableFL_NADO_OTCH_REM_DZAKTPR);

   virtual TIntegerField * get_TableSROK_REMONTA(void);
   virtual void set_TableSROK_REMONTA(TIntegerField * TableSROK_REMONTA);

   virtual TIntegerField * get_TableSROK_REMONTA_NOW(void);
   virtual void set_TableSROK_REMONTA_NOW(TIntegerField * TableSROK_REMONTA_NOW);

   virtual TIntegerField * get_TableSROK_REMONTA_IS_DOC(void);
   virtual void set_TableSROK_REMONTA_IS_DOC(TIntegerField * TableSROK_REMONTA_IS_DOC);

   virtual TFIBDateTimeField * get_TablePOSPRIEMA_REM_DZAKTPR(void);
   virtual void set_TablePOSPRIEMA_REM_DZAKTPR(TFIBDateTimeField * TablePOSPRIEMA_REM_DZAKTPR);

   virtual TDateTime get_PosNach(void);
   virtual void set_PosNach(TDateTime PosNach);

   virtual TDateTime get_PosCon(void);
   virtual void set_PosCon(TDateTime PosCon);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual __int64 get_IdKlient(void);
   virtual void set_IdKlient(__int64 IdKlient);

   virtual __int64 get_IdSklad(void);
   virtual void set_IdSklad(__int64 IdSklad);

   virtual __int64 get_IdFirm(void);
   virtual void set_IdFirm(__int64 IdFirm);

   virtual void OpenTable();
   virtual void UpdateTable(void);
   virtual bool OpenTableOnlyHardware(__int64 id_hw);
   virtual bool OpenTableOnlyZayavka(__int64 id_z);
   virtual void PoiskPoSerNum1(UnicodeString ser_num);
   virtual void PoiskPoSerNum2(UnicodeString ser_num);
   virtual void PoiskPoKlient(UnicodeString value);
   virtual void PoiskPoModel(UnicodeString value);
   virtual void PoiskPoIdHardware(__int64 id_hw);
   virtual void PoiskPoNumGarDoc(UnicodeString num_gar_doc);
};
#define CLSID_TREM_DMGurZAktPrImpl __uuidof(TREM_DMGurZAktPrImpl)
#endif
