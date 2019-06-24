#ifndef UREM_DMGurVigrusokImplH
#define UREM_DMGurVigrusokImplH
#include "IREM_DMGurVigrusok.h"
#include "UREM_DMGurVigrusok.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMGurVigrusokImpl)) TREM_DMGurVigrusokImpl : public IREM_DMGurVigrusok
{
public:
   TREM_DMGurVigrusokImpl();
   ~TREM_DMGurVigrusokImpl();
   TREM_DMGurVigrusok * Object;
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

//IREM_DMGurVigrusok
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBDataSet * get_IBQ(void);
   virtual void set_IBQ(TpFIBDataSet * IBQ);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBLargeIntField * get_TableID_REM_GUR_VIGR(void);
   virtual void set_TableID_REM_GUR_VIGR(TFIBLargeIntField * TableID_REM_GUR_VIGR);

   virtual TFIBLargeIntField * get_TableIDBASE_REM_GUR_VIGR(void);
   virtual void set_TableIDBASE_REM_GUR_VIGR(TFIBLargeIntField * TableIDBASE_REM_GUR_VIGR);

   virtual TFIBLargeIntField * get_TableIDUSER_REM_GUR_VIGR(void);
   virtual void set_TableIDUSER_REM_GUR_VIGR(TFIBLargeIntField * TableIDUSER_REM_GUR_VIGR);

   virtual TFIBDateTimeField * get_TablePOS_REM_GUR_VIGR(void);
   virtual void set_TablePOS_REM_GUR_VIGR(TFIBDateTimeField * TablePOS_REM_GUR_VIGR);

   virtual TFIBIntegerField * get_TableNUM_REM_GUR_VIGR(void);
   virtual void set_TableNUM_REM_GUR_VIGR(TFIBIntegerField * TableNUM_REM_GUR_VIGR);

   virtual TFIBWideStringField * get_TableGUID_TRANSACTION_REM_GUR_VIGR(void);
   virtual void set_TableGUID_TRANSACTION_REM_GUR_VIGR(TFIBWideStringField * TableGUID_TRANSACTION_REM_GUR_VIGR);

   virtual TFIBWideStringField * get_TableCODE_STR_VIGR_REM_GUR_VIGR(void);
   virtual void set_TableCODE_STR_VIGR_REM_GUR_VIGR(TFIBWideStringField * TableCODE_STR_VIGR_REM_GUR_VIGR);

   virtual TFIBWideStringField * get_TableGUID_VIGR_REM_GUR_VIGR(void);
   virtual void set_TableGUID_VIGR_REM_GUR_VIGR(TFIBWideStringField * TableGUID_VIGR_REM_GUR_VIGR);

   virtual TFIBLargeIntField * get_TableIDKLIENT_REM_GUR_VIGR(void);
   virtual void set_TableIDKLIENT_REM_GUR_VIGR(TFIBLargeIntField * TableIDKLIENT_REM_GUR_VIGR);

   virtual TFIBLargeIntField * get_TableIDPRODUCER_REM_GUR_VIGR(void);
   virtual void set_TableIDPRODUCER_REM_GUR_VIGR(TFIBLargeIntField * TableIDPRODUCER_REM_GUR_VIGR);

   virtual TFIBWideStringField * get_TableNAME_SPRODUCER(void);
   virtual void set_TableNAME_SPRODUCER(TFIBWideStringField * TableNAME_SPRODUCER);

   virtual TFIBWideStringField * get_TableNAMEKLIENT(void);
   virtual void set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT);

   virtual TFIBWideStringField * get_TableNAME_USER(void);
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER);

   virtual TFIBWideStringField * get_TableNAME_SINFBASE_OBMEN(void);
   virtual void set_TableNAME_SINFBASE_OBMEN(TFIBWideStringField * TableNAME_SINFBASE_OBMEN);

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

   virtual UnicodeString get_StringTypeDoc(void);
   virtual void set_StringTypeDoc(UnicodeString StringTypeDoc);

   virtual bool get_OtborVkl(void);
   virtual void set_OtborVkl(bool OtborVkl);

   virtual void OpenTable();
   virtual void UpdateTable(void);
};
#define CLSID_TREM_DMGurVigrusokImpl __uuidof(TREM_DMGurVigrusokImpl)
#endif
