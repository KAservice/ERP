#ifndef UHOT_DMDocRealImplH
#define UHOT_DMDocRealImplH
#include "IHOT_DMDocReal.h"
#include "UHOT_DMDocReal.h"
//---------------------------------------------------------------
class __declspec(uuid("{81CF4A6C-EDD7-4C73-8E8A-78C1AAE5FA1A}")) THOT_DMDocRealImpl : public IHOT_DMDocReal
{
public:
   THOT_DMDocRealImpl();
   ~THOT_DMDocRealImpl();
   THOT_DMDocReal * Object;
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

//IHOT_DMDocReal
   virtual TDataSource * get_DataSourceDoc(void);
   virtual void set_DataSourceDoc(TDataSource * DataSourceDoc);

   virtual TDataSource * get_DataSourceDocT(void);
   virtual void set_DataSourceDocT(TDataSource * DataSourceDocT);

   virtual TDataSource * get_DataSourceDocAll(void);
   virtual void set_DataSourceDocAll(TDataSource * DataSourceDocAll);

   virtual TpFIBDataSet * get_DocAll(void);
   virtual void set_DocAll(TpFIBDataSet * DocAll);

   virtual TpFIBDataSet * get_Doc(void);
   virtual void set_Doc(TpFIBDataSet * Doc);

   virtual TpFIBDataSet * get_DocT(void);
   virtual void set_DocT(TpFIBDataSet * DocT);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBDateTimeField * get_DocAllPOS_HOT_GALLDOC(void);
   virtual void set_DocAllPOS_HOT_GALLDOC(TFIBDateTimeField * DocAllPOS_HOT_GALLDOC);

   virtual TFIBSmallIntField * get_DocAllPR_HOT_GALLDOC(void);
   virtual void set_DocAllPR_HOT_GALLDOC(TFIBSmallIntField * DocAllPR_HOT_GALLDOC);

   virtual TFIBBCDField * get_DocAllSUM_HOT_GALLDOC(void);
   virtual void set_DocAllSUM_HOT_GALLDOC(TFIBBCDField * DocAllSUM_HOT_GALLDOC);

   virtual TFIBSmallIntField * get_DocTTUSL_HOT_DREALT(void);
   virtual void set_DocTTUSL_HOT_DREALT(TFIBSmallIntField * DocTTUSL_HOT_DREALT);

   virtual TFIBBCDField * get_DocTKOL_HOT_DREALT(void);
   virtual void set_DocTKOL_HOT_DREALT(TFIBBCDField * DocTKOL_HOT_DREALT);

   virtual TFIBBCDField * get_DocTKF_HOT_DREALT(void);
   virtual void set_DocTKF_HOT_DREALT(TFIBBCDField * DocTKF_HOT_DREALT);

   virtual TFIBBCDField * get_DocTPRICE_HOT_DREALT(void);
   virtual void set_DocTPRICE_HOT_DREALT(TFIBBCDField * DocTPRICE_HOT_DREALT);

   virtual TFIBBCDField * get_DocTSUM_HOT_DREALT(void);
   virtual void set_DocTSUM_HOT_DREALT(TFIBBCDField * DocTSUM_HOT_DREALT);

   virtual TFIBIntegerField * get_DocTTNOM(void);
   virtual void set_DocTTNOM(TFIBIntegerField * DocTTNOM);

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

   virtual TpFIBQuery * get_QueryDvReg(void);
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg);

   virtual TpFIBQuery * get_QueryCancelDvReg(void);
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg);

   virtual TpFIBDataSet * get_TypePriceDataSet(void);
   virtual void set_TypePriceDataSet(TpFIBDataSet * TypePriceDataSet);

   virtual TFIBDateTimeField * get_DocTPOSNACH_HOT_DREALT(void);
   virtual void set_DocTPOSNACH_HOT_DREALT(TFIBDateTimeField * DocTPOSNACH_HOT_DREALT);

   virtual TFIBDateTimeField * get_DocTPOSCON_HOT_DREALT(void);
   virtual void set_DocTPOSCON_HOT_DREALT(TFIBDateTimeField * DocTPOSCON_HOT_DREALT);

   virtual TpFIBDataSet * get_SpisokGuestOsnUslug(void);
   virtual void set_SpisokGuestOsnUslug(TpFIBDataSet * SpisokGuestOsnUslug);

   virtual TpFIBDataSet * get_SpisokGuestDopUslug(void);
   virtual void set_SpisokGuestDopUslug(TpFIBDataSet * SpisokGuestDopUslug);

   virtual TFIBFloatField * get_SpisokGuestOsnUslugSUMKOL(void);
   virtual void set_SpisokGuestOsnUslugSUMKOL(TFIBFloatField * SpisokGuestOsnUslugSUMKOL);

   virtual TFIBBCDField * get_SpisokGuestDopUslugSUM(void);
   virtual void set_SpisokGuestDopUslugSUM(TFIBBCDField * SpisokGuestDopUslugSUM);

   virtual TFIBBCDField * get_SpisokGuestDopUslugIDKLIENT(void);
   virtual void set_SpisokGuestDopUslugIDKLIENT(TFIBBCDField * SpisokGuestDopUslugIDKLIENT);

   virtual TFIBBCDField * get_SpisokGuestOsnUslugIDKLIENT(void);
   virtual void set_SpisokGuestOsnUslugIDKLIENT(TFIBBCDField * SpisokGuestOsnUslugIDKLIENT);

   virtual TpFIBDataSet * get_NumDoc(void);
   virtual void set_NumDoc(TpFIBDataSet * NumDoc);

   virtual TFIBIntegerField * get_NumDocMAXNUMBER(void);
   virtual void set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER);

   virtual TFIBWideStringField * get_SpisokGuestOsnUslugNAMEKLIENT(void);
   virtual void set_SpisokGuestOsnUslugNAMEKLIENT(TFIBWideStringField * SpisokGuestOsnUslugNAMEKLIENT);

   virtual TFIBWideStringField * get_SpisokGuestDopUslugNAMEKLIENT(void);
   virtual void set_SpisokGuestDopUslugNAMEKLIENT(TFIBWideStringField * SpisokGuestDopUslugNAMEKLIENT);

   virtual TFIBWideStringField * get_DocAllTDOC_HOT_GALLDOC(void);
   virtual void set_DocAllTDOC_HOT_GALLDOC(TFIBWideStringField * DocAllTDOC_HOT_GALLDOC);

   virtual TFIBIntegerField * get_DocAllNUMBER_HOT_GALLDOC(void);
   virtual void set_DocAllNUMBER_HOT_GALLDOC(TFIBIntegerField * DocAllNUMBER_HOT_GALLDOC);

   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void);
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_DocAllNAMEFIRM(void);
   virtual void set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM);

   virtual TFIBWideStringField * get_DocAllNAMEKLIENT(void);
   virtual void set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT);

   virtual TFIBWideStringField * get_DocAllFNAME_USER(void);
   virtual void set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER);

   virtual TFIBWideStringField * get_DocAllNAMESKLAD(void);
   virtual void set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD);

   virtual TFIBWideStringField * get_DocPRIM_HOT_DREAL(void);
   virtual void set_DocPRIM_HOT_DREAL(TFIBWideStringField * DocPRIM_HOT_DREAL);

   virtual TFIBWideStringField * get_DocNAMEKKM_HOT_DREAL(void);
   virtual void set_DocNAMEKKM_HOT_DREAL(TFIBWideStringField * DocNAMEKKM_HOT_DREAL);

   virtual TFIBWideStringField * get_DocZAVNUM_HOT_DREAL(void);
   virtual void set_DocZAVNUM_HOT_DREAL(TFIBWideStringField * DocZAVNUM_HOT_DREAL);

   virtual TFIBWideStringField * get_DocREGNUM_HOT_DREAL(void);
   virtual void set_DocREGNUM_HOT_DREAL(TFIBWideStringField * DocREGNUM_HOT_DREAL);

   virtual TFIBWideStringField * get_DocNUMCHECK_HOT_DREAL(void);
   virtual void set_DocNUMCHECK_HOT_DREAL(TFIBWideStringField * DocNUMCHECK_HOT_DREAL);

   virtual TFIBWideStringField * get_DocNUMKL_HOT_DREAL(void);
   virtual void set_DocNUMKL_HOT_DREAL(TFIBWideStringField * DocNUMKL_HOT_DREAL);

   virtual TFIBWideStringField * get_DocTNAMENOM(void);
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM);

   virtual TFIBWideStringField * get_DocTNAMEED(void);
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED);

   virtual TFIBWideStringField * get_DocTNAME_TPRICE(void);
   virtual void set_DocTNAME_TPRICE(TFIBWideStringField * DocTNAME_TPRICE);

   virtual TFIBWideStringField * get_DocTNAME_HOT_SNF(void);
   virtual void set_DocTNAME_HOT_SNF(TFIBWideStringField * DocTNAME_HOT_SNF);

   virtual TFIBWideStringField * get_DocTNAME_HOT_SCATNOM(void);
   virtual void set_DocTNAME_HOT_SCATNOM(TFIBWideStringField * DocTNAME_HOT_SCATNOM);

   virtual TFIBWideStringField * get_DocTNAME_HOT_STYPEPOS(void);
   virtual void set_DocTNAME_HOT_STYPEPOS(TFIBWideStringField * DocTNAME_HOT_STYPEPOS);

   virtual TFIBWideStringField * get_DocTNAMEKLIENT(void);
   virtual void set_DocTNAMEKLIENT(TFIBWideStringField * DocTNAMEKLIENT);

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

   virtual TFIBLargeIntField * get_DocAllIDSKLAD_HOT_GALLDOC(void);
   virtual void set_DocAllIDSKLAD_HOT_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_HOT_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDBASE_HOT_GALLDOC(void);
   virtual void set_DocAllIDBASE_HOT_GALLDOC(TFIBLargeIntField * DocAllIDBASE_HOT_GALLDOC);

   virtual TFIBLargeIntField * get_DocID_HOT_DREAL(void);
   virtual void set_DocID_HOT_DREAL(TFIBLargeIntField * DocID_HOT_DREAL);

   virtual TFIBLargeIntField * get_DocIDDOCH_HOT_DREAL(void);
   virtual void set_DocIDDOCH_HOT_DREAL(TFIBLargeIntField * DocIDDOCH_HOT_DREAL);

   virtual TFIBLargeIntField * get_DocIDBASE_HOT_DREAL(void);
   virtual void set_DocIDBASE_HOT_DREAL(TFIBLargeIntField * DocIDBASE_HOT_DREAL);

   virtual TFIBLargeIntField * get_DocIDTPRICE_HOT_DREAL(void);
   virtual void set_DocIDTPRICE_HOT_DREAL(TFIBLargeIntField * DocIDTPRICE_HOT_DREAL);

   virtual TFIBLargeIntField * get_DocTID_HOT_DREALT(void);
   virtual void set_DocTID_HOT_DREALT(TFIBLargeIntField * DocTID_HOT_DREALT);

   virtual TFIBLargeIntField * get_DocTIDDOCH_HOT_DREALT(void);
   virtual void set_DocTIDDOCH_HOT_DREALT(TFIBLargeIntField * DocTIDDOCH_HOT_DREALT);

   virtual TFIBLargeIntField * get_DocTIDTPRICE_HOT_DREALT(void);
   virtual void set_DocTIDTPRICE_HOT_DREALT(TFIBLargeIntField * DocTIDTPRICE_HOT_DREALT);

   virtual TFIBLargeIntField * get_DocTIDNOM_HOT_DREALT(void);
   virtual void set_DocTIDNOM_HOT_DREALT(TFIBLargeIntField * DocTIDNOM_HOT_DREALT);

   virtual TFIBLargeIntField * get_DocTIDED_HOT_DREALT(void);
   virtual void set_DocTIDED_HOT_DREALT(TFIBLargeIntField * DocTIDED_HOT_DREALT);

   virtual TFIBLargeIntField * get_DocTIDNOMER_HOT_DREALT(void);
   virtual void set_DocTIDNOMER_HOT_DREALT(TFIBLargeIntField * DocTIDNOMER_HOT_DREALT);

   virtual TFIBLargeIntField * get_DocTIDCAT_HOT_DREALT(void);
   virtual void set_DocTIDCAT_HOT_DREALT(TFIBLargeIntField * DocTIDCAT_HOT_DREALT);

   virtual TFIBLargeIntField * get_DocTIDGUEST_HOT_DREALT(void);
   virtual void set_DocTIDGUEST_HOT_DREALT(TFIBLargeIntField * DocTIDGUEST_HOT_DREALT);

   virtual TFIBLargeIntField * get_DocTIDTPOS_HOT_DREALT(void);
   virtual void set_DocTIDTPOS_HOT_DREALT(TFIBLargeIntField * DocTIDTPOS_HOT_DREALT);

   virtual TFIBLargeIntField * get_DocTIDBASE_HOT_DREALT(void);
   virtual void set_DocTIDBASE_HOT_DREALT(TFIBLargeIntField * DocTIDBASE_HOT_DREALT);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_NoEdit(void);
   virtual void set_NoEdit(bool NoEdit);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual void NewDoc(void);
   virtual void OpenDoc(__int64 IdDoc);
   virtual bool SaveDoc(void);
   virtual bool DvRegDoc(void);
   virtual bool CancelDvRegDoc(void);
   virtual void AddDocNewString(void);
   virtual void DeleteStringDoc(void);
   virtual void CloseDoc(void);
   virtual bool DeleteDoc(__int64 id);
   virtual void GetSpisokGuest(void);
   virtual double GetKolOsnUslugGuest(__int64 id_guest);
   virtual double GetSumDopUslugGuest(__int64 id_guest);
};
#define CLSID_THOT_DMDocRealImpl __uuidof(THOT_DMDocRealImpl)
#endif
