#ifndef UHOT_DMGurAllDocImplH
#define UHOT_DMGurAllDocImplH
#include "IHOT_DMGurAllDoc.h"
#include "UHOT_DMGurAllDoc.h"
//---------------------------------------------------------------
class __declspec(uuid("{428DED48-5633-42FD-A968-D774A6A132D5}")) THOT_DMGurAllDocImpl : public IHOT_DMGurAllDoc
{
public:
   THOT_DMGurAllDocImpl();
   ~THOT_DMGurAllDocImpl();
   THOT_DMGurAllDoc * Object;
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

//IHOT_DMGurAllDoc
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBDateTimeField * get_TablePOS_HOT_GALLDOC(void);
   virtual void set_TablePOS_HOT_GALLDOC(TFIBDateTimeField * TablePOS_HOT_GALLDOC);

   virtual TFIBSmallIntField * get_TablePR_HOT_GALLDOC(void);
   virtual void set_TablePR_HOT_GALLDOC(TFIBSmallIntField * TablePR_HOT_GALLDOC);

   virtual TFIBBCDField * get_TableSUM_HOT_GALLDOC(void);
   virtual void set_TableSUM_HOT_GALLDOC(TFIBBCDField * TableSUM_HOT_GALLDOC);

   virtual TpFIBDataSet * get_IBQ(void);
   virtual void set_IBQ(TpFIBDataSet * IBQ);

   virtual TFIBBCDField * get_TableID_HOT_GALLDOC(void);
   virtual void set_TableID_HOT_GALLDOC(TFIBBCDField * TableID_HOT_GALLDOC);

   virtual TFIBBCDField * get_TableIDFIRM_HOT_GALLDOC(void);
   virtual void set_TableIDFIRM_HOT_GALLDOC(TFIBBCDField * TableIDFIRM_HOT_GALLDOC);

   virtual TFIBBCDField * get_TableIDKL_HOT_GALLDOC(void);
   virtual void set_TableIDKL_HOT_GALLDOC(TFIBBCDField * TableIDKL_HOT_GALLDOC);

   virtual TFIBBCDField * get_TableIDUSER_HOT_GALLDOC(void);
   virtual void set_TableIDUSER_HOT_GALLDOC(TFIBBCDField * TableIDUSER_HOT_GALLDOC);

   virtual TFIBBCDField * get_TableIDDOCOSN_HOT_GALLDOC(void);
   virtual void set_TableIDDOCOSN_HOT_GALLDOC(TFIBBCDField * TableIDDOCOSN_HOT_GALLDOC);

   virtual TFIBBCDField * get_TableIDBASE_HOT_GALLDOC(void);
   virtual void set_TableIDBASE_HOT_GALLDOC(TFIBBCDField * TableIDBASE_HOT_GALLDOC);

   virtual TFIBWideStringField * get_TableTDOC_HOT_GALLDOC(void);
   virtual void set_TableTDOC_HOT_GALLDOC(TFIBWideStringField * TableTDOC_HOT_GALLDOC);

   virtual TFIBWideStringField * get_TableNAMEFIRM(void);
   virtual void set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM);

   virtual TFIBWideStringField * get_TableNAMEKLIENT(void);
   virtual void set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT);

   virtual TFIBWideStringField * get_TableNAME_USER(void);
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER);

   virtual TFIBIntegerField * get_TableNUMBER_HOT_GALLDOC(void);
   virtual void set_TableNUMBER_HOT_GALLDOC(TFIBIntegerField * TableNUMBER_HOT_GALLDOC);

   virtual __int64 get_IdDocH(void);
   virtual void set_IdDocH(__int64 IdDocH);

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

   virtual bool get_OtborPoKlient(void);
   virtual void set_OtborPoKlient(bool OtborPoKlient);

   virtual bool get_OtborPoFirm(void);
   virtual void set_OtborPoFirm(bool OtborPoFirm);

   virtual bool get_OtborPoSklad(void);
   virtual void set_OtborPoSklad(bool OtborPoSklad);

   virtual bool get_OtborPoTypeDoc(void);
   virtual void set_OtborPoTypeDoc(bool OtborPoTypeDoc);

   virtual bool get_NoCheck(void);
   virtual void set_NoCheck(bool NoCheck);

   virtual TDateTime get_PosNach(void);
   virtual void set_PosNach(TDateTime PosNach);

   virtual TDateTime get_PosCon(void);
   virtual void set_PosCon(TDateTime PosCon);

   virtual void OpenTable();
   virtual void UpdateTable(void);
   virtual bool CancelDvRegDoc(AnsiString type_doc, __int64 id_doc);
   virtual bool DvRegDoc(AnsiString type_doc, __int64 id_doc);
   virtual void AllCancelDvRegDoc(void);
   virtual void AllDvRegDoc(void);
};
#define CLSID_THOT_DMGurAllDocImpl __uuidof(THOT_DMGurAllDocImpl)
#endif
