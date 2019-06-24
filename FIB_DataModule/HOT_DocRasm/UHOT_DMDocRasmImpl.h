#ifndef UHOT_DMDocRasmImplH
#define UHOT_DMDocRasmImplH
#include "IHOT_DMDocRasm.h"
#include "UHOT_DMDocRasm.h"
//---------------------------------------------------------------
class __declspec(uuid("{52886F72-62AF-4FC3-98B0-F5B519D5B24F}")) THOT_DMDocRasmImpl : public IHOT_DMDocRasm
{
public:
   THOT_DMDocRasmImpl();
   ~THOT_DMDocRasmImpl();
   THOT_DMDocRasm * Object;
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

//IHOT_DMDocRasm
   virtual TDataSource * get_DataSourceDoc(void);
   virtual void set_DataSourceDoc(TDataSource * DataSourceDoc);

   virtual TDataSource * get_DataSourceDocAll(void);
   virtual void set_DataSourceDocAll(TDataSource * DataSourceDocAll);

   virtual TpFIBDataSet * get_DocAll(void);
   virtual void set_DocAll(TpFIBDataSet * DocAll);

   virtual TpFIBDataSet * get_Doc(void);
   virtual void set_Doc(TpFIBDataSet * Doc);

   virtual TpFIBDataSet * get_NumDoc(void);
   virtual void set_NumDoc(TpFIBDataSet * NumDoc);

   virtual TFIBIntegerField * get_NumDocMAXNUMBER(void);
   virtual void set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER);

   virtual TFIBDateTimeField * get_DocAllPOS_HOT_GALLDOC(void);
   virtual void set_DocAllPOS_HOT_GALLDOC(TFIBDateTimeField * DocAllPOS_HOT_GALLDOC);

   virtual TFIBSmallIntField * get_DocAllPR_HOT_GALLDOC(void);
   virtual void set_DocAllPR_HOT_GALLDOC(TFIBSmallIntField * DocAllPR_HOT_GALLDOC);

   virtual TFIBBCDField * get_DocAllSUM_HOT_GALLDOC(void);
   virtual void set_DocAllSUM_HOT_GALLDOC(TFIBBCDField * DocAllSUM_HOT_GALLDOC);

   virtual TFIBIntegerField * get_DocAllNUMBER_HOT_GALLDOC(void);
   virtual void set_DocAllNUMBER_HOT_GALLDOC(TFIBIntegerField * DocAllNUMBER_HOT_GALLDOC);

   virtual TpFIBQuery * get_QueryDvReg(void);
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg);

   virtual TpFIBQuery * get_QueryCancelDvReg(void);
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg);

   virtual TpFIBDataSet * get_DocT(void);
   virtual void set_DocT(TpFIBDataSet * DocT);

   virtual TDataSource * get_DataSourceDocT(void);
   virtual void set_DataSourceDocT(TDataSource * DataSourceDocT);

   virtual TFIBWideStringField * get_DocAllTDOC_HOT_GALLDOC(void);
   virtual void set_DocAllTDOC_HOT_GALLDOC(TFIBWideStringField * DocAllTDOC_HOT_GALLDOC);

   virtual TFIBWideStringField * get_DocAllFNAME_USER(void);
   virtual void set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER);

   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void);
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_DocAllNAMEFIRM(void);
   virtual void set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM);

   virtual TFIBWideStringField * get_DocAllNAMEKLIENT(void);
   virtual void set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT);

   virtual TFIBWideStringField * get_DocDESCR_HOT_DRASM(void);
   virtual void set_DocDESCR_HOT_DRASM(TFIBWideStringField * DocDESCR_HOT_DRASM);

   virtual TFIBWideStringField * get_DocORG_HOT_DRASM(void);
   virtual void set_DocORG_HOT_DRASM(TFIBWideStringField * DocORG_HOT_DRASM);

   virtual TFIBWideStringField * get_DocNAME_HOT_SCELPR(void);
   virtual void set_DocNAME_HOT_SCELPR(TFIBWideStringField * DocNAME_HOT_SCELPR);

   virtual TFIBWideStringField * get_DocTBR_NAME_HOT_SNF(void);
   virtual void set_DocTBR_NAME_HOT_SNF(TFIBWideStringField * DocTBR_NAME_HOT_SNF);

   virtual TFIBWideStringField * get_DocTBR_NAME_HOT_SCATNOM(void);
   virtual void set_DocTBR_NAME_HOT_SCATNOM(TFIBWideStringField * DocTBR_NAME_HOT_SCATNOM);

   virtual TFIBWideStringField * get_DocTBR_NAME_HOT_STYPEPOS(void);
   virtual void set_DocTBR_NAME_HOT_STYPEPOS(TFIBWideStringField * DocTBR_NAME_HOT_STYPEPOS);

   virtual TFIBWideStringField * get_DocTBR_NAMEGUEST(void);
   virtual void set_DocTBR_NAMEGUEST(TFIBWideStringField * DocTBR_NAMEGUEST);

   virtual TFIBWideStringField * get_DocTBR_NAME_HOT_SSOSTNOM(void);
   virtual void set_DocTBR_NAME_HOT_SSOSTNOM(TFIBWideStringField * DocTBR_NAME_HOT_SSOSTNOM);

   virtual TFIBDateTimeField * get_DocTBR_POSNACH_HOT_SOSTNF(void);
   virtual void set_DocTBR_POSNACH_HOT_SOSTNF(TFIBDateTimeField * DocTBR_POSNACH_HOT_SOSTNF);

   virtual TFIBDateTimeField * get_DocTBR_POSCON_HOT_SOSTNF(void);
   virtual void set_DocTBR_POSCON_HOT_SOSTNF(TFIBDateTimeField * DocTBR_POSCON_HOT_SOSTNF);

   virtual TFIBIntegerField * get_DocTBR_KOLM_HOT_SOSTNF(void);
   virtual void set_DocTBR_KOLM_HOT_SOSTNF(TFIBIntegerField * DocTBR_KOLM_HOT_SOSTNF);

   virtual TFIBWideStringField * get_DocTRASM_NAME_HOT_SNF(void);
   virtual void set_DocTRASM_NAME_HOT_SNF(TFIBWideStringField * DocTRASM_NAME_HOT_SNF);

   virtual TFIBWideStringField * get_DocTRASM_NAME_HOT_SCATNOM(void);
   virtual void set_DocTRASM_NAME_HOT_SCATNOM(TFIBWideStringField * DocTRASM_NAME_HOT_SCATNOM);

   virtual TFIBWideStringField * get_DocTRASM_NAME_HOT_STYPEPOS(void);
   virtual void set_DocTRASM_NAME_HOT_STYPEPOS(TFIBWideStringField * DocTRASM_NAME_HOT_STYPEPOS);

   virtual TFIBWideStringField * get_DocTRASM_NAMEGUEST(void);
   virtual void set_DocTRASM_NAMEGUEST(TFIBWideStringField * DocTRASM_NAMEGUEST);

   virtual TFIBWideStringField * get_DocTRASM_NAME_HOT_SSOSTNOM(void);
   virtual void set_DocTRASM_NAME_HOT_SSOSTNOM(TFIBWideStringField * DocTRASM_NAME_HOT_SSOSTNOM);

   virtual TFIBDateTimeField * get_DocTRASM_POSNACH_HOT_SOSTNF(void);
   virtual void set_DocTRASM_POSNACH_HOT_SOSTNF(TFIBDateTimeField * DocTRASM_POSNACH_HOT_SOSTNF);

   virtual TFIBDateTimeField * get_DocTRASM_POSCON_HOT_SOSTNF(void);
   virtual void set_DocTRASM_POSCON_HOT_SOSTNF(TFIBDateTimeField * DocTRASM_POSCON_HOT_SOSTNF);

   virtual TFIBIntegerField * get_DocTRASM_KOLM_HOT_SOSTNF(void);
   virtual void set_DocTRASM_KOLM_HOT_SOSTNF(TFIBIntegerField * DocTRASM_KOLM_HOT_SOSTNF);

   virtual TFIBWideStringField * get_DocTBR2_NAME_HOT_SNF(void);
   virtual void set_DocTBR2_NAME_HOT_SNF(TFIBWideStringField * DocTBR2_NAME_HOT_SNF);

   virtual TFIBWideStringField * get_DocTBR2_NAME_HOT_SCATNOM(void);
   virtual void set_DocTBR2_NAME_HOT_SCATNOM(TFIBWideStringField * DocTBR2_NAME_HOT_SCATNOM);

   virtual TFIBWideStringField * get_DocTBR2_NAME_HOT_STYPEPOS(void);
   virtual void set_DocTBR2_NAME_HOT_STYPEPOS(TFIBWideStringField * DocTBR2_NAME_HOT_STYPEPOS);

   virtual TFIBWideStringField * get_DocTBR2_NAMEGUEST(void);
   virtual void set_DocTBR2_NAMEGUEST(TFIBWideStringField * DocTBR2_NAMEGUEST);

   virtual TFIBWideStringField * get_DocTBR2_NAME_HOT_SSOSTNOM(void);
   virtual void set_DocTBR2_NAME_HOT_SSOSTNOM(TFIBWideStringField * DocTBR2_NAME_HOT_SSOSTNOM);

   virtual TFIBDateTimeField * get_DocTBR2_POSNACH_HOT_SOSTNF(void);
   virtual void set_DocTBR2_POSNACH_HOT_SOSTNF(TFIBDateTimeField * DocTBR2_POSNACH_HOT_SOSTNF);

   virtual TFIBDateTimeField * get_DocTBR2_POSCON_HOT_SOSTNF(void);
   virtual void set_DocTBR2_POSCON_HOT_SOSTNF(TFIBDateTimeField * DocTBR2_POSCON_HOT_SOSTNF);

   virtual TFIBIntegerField * get_DocTBR2_KOLM_HOT_SOSTNF(void);
   virtual void set_DocTBR2_KOLM_HOT_SOSTNF(TFIBIntegerField * DocTBR2_KOLM_HOT_SOSTNF);

   virtual TStringField * get_DocTBR(void);
   virtual void set_DocTBR(TStringField * DocTBR);

   virtual TStringField * get_DocTRASM(void);
   virtual void set_DocTRASM(TStringField * DocTRASM);

   virtual TStringField * get_DocTBR2(void);
   virtual void set_DocTBR2(TStringField * DocTBR2);

   virtual TFIBLargeIntField * get_DocAllID_HOT_GALLDOC(void);
   virtual void set_DocAllID_HOT_GALLDOC(TFIBLargeIntField * DocAllID_HOT_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDFIRM_HOT_GALLDOC(void);
   virtual void set_DocAllIDFIRM_HOT_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_HOT_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDKL_HOT_GALLDOC(void);
   virtual void set_DocAllIDKL_HOT_GALLDOC(TFIBLargeIntField * DocAllIDKL_HOT_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDUSER_HOT_GALLDOC(void);
   virtual void set_DocAllIDUSER_HOT_GALLDOC(TFIBLargeIntField * DocAllIDUSER_HOT_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDDOCOSN_HOT_GALLDOC(void);
   virtual void set_DocAllIDDOCOSN_HOT_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_HOT_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDBASE_HOT_GALLDOC(void);
   virtual void set_DocAllIDBASE_HOT_GALLDOC(TFIBLargeIntField * DocAllIDBASE_HOT_GALLDOC);

   virtual TFIBLargeIntField * get_DocID_HOT_DRASM(void);
   virtual void set_DocID_HOT_DRASM(TFIBLargeIntField * DocID_HOT_DRASM);

   virtual TFIBLargeIntField * get_DocIDDOCH_HOT_DRASM(void);
   virtual void set_DocIDDOCH_HOT_DRASM(TFIBLargeIntField * DocIDDOCH_HOT_DRASM);

   virtual TFIBLargeIntField * get_DocIDCELPR_HOT_DRASM(void);
   virtual void set_DocIDCELPR_HOT_DRASM(TFIBLargeIntField * DocIDCELPR_HOT_DRASM);

   virtual TFIBLargeIntField * get_DocIDBASE_HOT_DRASM(void);
   virtual void set_DocIDBASE_HOT_DRASM(TFIBLargeIntField * DocIDBASE_HOT_DRASM);

   virtual TFIBLargeIntField * get_DocIDTPRICE_HOT_DRASM(void);
   virtual void set_DocIDTPRICE_HOT_DRASM(TFIBLargeIntField * DocIDTPRICE_HOT_DRASM);

   virtual TFIBLargeIntField * get_DocTID_HOT_DRASMT(void);
   virtual void set_DocTID_HOT_DRASMT(TFIBLargeIntField * DocTID_HOT_DRASMT);

   virtual TFIBLargeIntField * get_DocTIDDOCH_HOT_DRASMT(void);
   virtual void set_DocTIDDOCH_HOT_DRASMT(TFIBLargeIntField * DocTIDDOCH_HOT_DRASMT);

   virtual TFIBLargeIntField * get_DocTIDSOSTBR_HOT_DRASMT(void);
   virtual void set_DocTIDSOSTBR_HOT_DRASMT(TFIBLargeIntField * DocTIDSOSTBR_HOT_DRASMT);

   virtual TFIBLargeIntField * get_DocTIDSOSTRASM_HOT_DRASMT(void);
   virtual void set_DocTIDSOSTRASM_HOT_DRASMT(TFIBLargeIntField * DocTIDSOSTRASM_HOT_DRASMT);

   virtual TFIBLargeIntField * get_DocTIDSOSTBR2_HOT_DRASMT(void);
   virtual void set_DocTIDSOSTBR2_HOT_DRASMT(TFIBLargeIntField * DocTIDSOSTBR2_HOT_DRASMT);

   virtual TFIBLargeIntField * get_DocTIDBASE_HOT_DRASMT(void);
   virtual void set_DocTIDBASE_HOT_DRASMT(TFIBLargeIntField * DocTIDBASE_HOT_DRASMT);

   virtual TFIBLargeIntField * get_DocTRASM_ID_HOT_SNF(void);
   virtual void set_DocTRASM_ID_HOT_SNF(TFIBLargeIntField * DocTRASM_ID_HOT_SNF);

   virtual TFIBLargeIntField * get_DocTRASM_ID_HOT_SCATNOM(void);
   virtual void set_DocTRASM_ID_HOT_SCATNOM(TFIBLargeIntField * DocTRASM_ID_HOT_SCATNOM);

   virtual TFIBLargeIntField * get_DocTRASM_ID_HOT_STYPEPOS(void);
   virtual void set_DocTRASM_ID_HOT_STYPEPOS(TFIBLargeIntField * DocTRASM_ID_HOT_STYPEPOS);

   virtual TFIBLargeIntField * get_DocTRASM_IDGUEST(void);
   virtual void set_DocTRASM_IDGUEST(TFIBLargeIntField * DocTRASM_IDGUEST);

   virtual TFIBLargeIntField * get_DocTRASM_ID_HOT_SSOSTNOM(void);
   virtual void set_DocTRASM_ID_HOT_SSOSTNOM(TFIBLargeIntField * DocTRASM_ID_HOT_SSOSTNOM);

   virtual TFIBLargeIntField * get_DocTBR2_ID_HOT_SNF(void);
   virtual void set_DocTBR2_ID_HOT_SNF(TFIBLargeIntField * DocTBR2_ID_HOT_SNF);

   virtual TFIBLargeIntField * get_DocTBR2_ID_HOT_SCATNOM(void);
   virtual void set_DocTBR2_ID_HOT_SCATNOM(TFIBLargeIntField * DocTBR2_ID_HOT_SCATNOM);

   virtual TFIBLargeIntField * get_DocTBR2_ID_HOT_STYPEPOS(void);
   virtual void set_DocTBR2_ID_HOT_STYPEPOS(TFIBLargeIntField * DocTBR2_ID_HOT_STYPEPOS);

   virtual TFIBLargeIntField * get_DocTBR2_IDGUEST(void);
   virtual void set_DocTBR2_IDGUEST(TFIBLargeIntField * DocTBR2_IDGUEST);

   virtual TFIBLargeIntField * get_DocTBR2_ID_HOT_SSOSTNOM(void);
   virtual void set_DocTBR2_ID_HOT_SSOSTNOM(TFIBLargeIntField * DocTBR2_ID_HOT_SSOSTNOM);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual void NewDoc(void);
   virtual void OpenDoc(__int64 IdDoc);
   virtual bool SaveDoc(void);
   virtual bool DvRegDoc(void);
   virtual bool CancelDvRegDoc(void);
   virtual void CloseDoc(void);
   virtual bool DeleteDoc(__int64 id);
   virtual void AddString(void);
   virtual void DeleteString(void);
};
#define CLSID_THOT_DMDocRasmImpl __uuidof(THOT_DMDocRasmImpl)
#endif
