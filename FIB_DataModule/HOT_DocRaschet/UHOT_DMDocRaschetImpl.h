#ifndef UHOT_DMDocRaschetImplH
#define UHOT_DMDocRaschetImplH
#include "IHOT_DMDocRaschet.h"
#include "UHOT_DMDocRaschet.h"
//---------------------------------------------------------------
class __declspec(uuid("{FD7219DE-B39F-450A-9B69-5AD194B240B9}")) THOT_DMDocRaschetImpl : public IHOT_DMDocRaschet
{
public:
   THOT_DMDocRaschetImpl();
   ~THOT_DMDocRaschetImpl();
   THOT_DMDocRaschet * Object;
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

//IHOT_DMDocRaschet
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

   virtual TpFIBQuery * get_QueryDvReg(void);
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg);

   virtual TpFIBQuery * get_QueryCancelDvReg(void);
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg);

   virtual TpFIBDataSet * get_TypePriceDataSet(void);
   virtual void set_TypePriceDataSet(TpFIBDataSet * TypePriceDataSet);

   virtual TFIBSmallIntField * get_DocTTUSL_HOT_DRASCHETT(void);
   virtual void set_DocTTUSL_HOT_DRASCHETT(TFIBSmallIntField * DocTTUSL_HOT_DRASCHETT);

   virtual TFIBBCDField * get_DocTKOL_HOT_DRASCHETT(void);
   virtual void set_DocTKOL_HOT_DRASCHETT(TFIBBCDField * DocTKOL_HOT_DRASCHETT);

   virtual TFIBBCDField * get_DocTKF_HOT_DRASCHETT(void);
   virtual void set_DocTKF_HOT_DRASCHETT(TFIBBCDField * DocTKF_HOT_DRASCHETT);

   virtual TFIBBCDField * get_DocTPRICE_HOT_DRASCHETT(void);
   virtual void set_DocTPRICE_HOT_DRASCHETT(TFIBBCDField * DocTPRICE_HOT_DRASCHETT);

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

   virtual TFIBBCDField * get_DocTSUM_HOT_DRASCHETT(void);
   virtual void set_DocTSUM_HOT_DRASCHETT(TFIBBCDField * DocTSUM_HOT_DRASCHETT);

   virtual TFIBDateTimeField * get_DocTPOSNACH_HOT_DRASCHETT(void);
   virtual void set_DocTPOSNACH_HOT_DRASCHETT(TFIBDateTimeField * DocTPOSNACH_HOT_DRASCHETT);

   virtual TFIBDateTimeField * get_DocTPOSCON_HOT_DRASCHETT(void);
   virtual void set_DocTPOSCON_HOT_DRASCHETT(TFIBDateTimeField * DocTPOSCON_HOT_DRASCHETT);

   virtual TStringField * get_DocTVIBOR_TYPE_PRICE(void);
   virtual void set_DocTVIBOR_TYPE_PRICE(TStringField * DocTVIBOR_TYPE_PRICE);

   virtual TpFIBDataSet * get_SpisokGuestOsnUslug(void);
   virtual void set_SpisokGuestOsnUslug(TpFIBDataSet * SpisokGuestOsnUslug);

   virtual TpFIBDataSet * get_SpisokGuestDopUslug(void);
   virtual void set_SpisokGuestDopUslug(TpFIBDataSet * SpisokGuestDopUslug);

   virtual TFIBFloatField * get_SpisokGuestOsnUslugSUMKOL(void);
   virtual void set_SpisokGuestOsnUslugSUMKOL(TFIBFloatField * SpisokGuestOsnUslugSUMKOL);

   virtual TFIBBCDField * get_SpisokGuestDopUslugSUM(void);
   virtual void set_SpisokGuestDopUslugSUM(TFIBBCDField * SpisokGuestDopUslugSUM);

   virtual TFIBBCDField * get_SpisokGuestOsnUslugIDKLIENT(void);
   virtual void set_SpisokGuestOsnUslugIDKLIENT(TFIBBCDField * SpisokGuestOsnUslugIDKLIENT);

   virtual TFIBBCDField * get_SpisokGuestDopUslugIDKLIENT(void);
   virtual void set_SpisokGuestDopUslugIDKLIENT(TFIBBCDField * SpisokGuestDopUslugIDKLIENT);

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

   virtual TFIBWideStringField * get_DocPRIM_HOT_DRASCHET(void);
   virtual void set_DocPRIM_HOT_DRASCHET(TFIBWideStringField * DocPRIM_HOT_DRASCHET);

   virtual TFIBWideStringField * get_DocNAMEBSCHET(void);
   virtual void set_DocNAMEBSCHET(TFIBWideStringField * DocNAMEBSCHET);

   virtual TFIBWideStringField * get_DocTNAMENOM(void);
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM);

   virtual TFIBWideStringField * get_DocTNAMEED(void);
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED);

   virtual TFIBSmallIntField * get_DocTTNOM(void);
   virtual void set_DocTTNOM(TFIBSmallIntField * DocTTNOM);

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

   virtual TFIBLargeIntField * get_DocID_HOT_DRASCHET(void);
   virtual void set_DocID_HOT_DRASCHET(TFIBLargeIntField * DocID_HOT_DRASCHET);

   virtual TFIBLargeIntField * get_DocIDDOCH_HOT_DRASCHET(void);
   virtual void set_DocIDDOCH_HOT_DRASCHET(TFIBLargeIntField * DocIDDOCH_HOT_DRASCHET);

   virtual TFIBLargeIntField * get_DocIDBSCHET_HOT_DRASCHET(void);
   virtual void set_DocIDBSCHET_HOT_DRASCHET(TFIBLargeIntField * DocIDBSCHET_HOT_DRASCHET);

   virtual TFIBLargeIntField * get_DocIDBASE_HOT_DRASCHET(void);
   virtual void set_DocIDBASE_HOT_DRASCHET(TFIBLargeIntField * DocIDBASE_HOT_DRASCHET);

   virtual TFIBLargeIntField * get_DocIDTPRICE_HOT_DRASCHET(void);
   virtual void set_DocIDTPRICE_HOT_DRASCHET(TFIBLargeIntField * DocIDTPRICE_HOT_DRASCHET);

   virtual TFIBLargeIntField * get_DocTID_HOT_DRASCHETT(void);
   virtual void set_DocTID_HOT_DRASCHETT(TFIBLargeIntField * DocTID_HOT_DRASCHETT);

   virtual TFIBLargeIntField * get_DocTIDDOCH_HOT_DRASCHETT(void);
   virtual void set_DocTIDDOCH_HOT_DRASCHETT(TFIBLargeIntField * DocTIDDOCH_HOT_DRASCHETT);

   virtual TFIBLargeIntField * get_DocTIDTPRICE_HOT_DRASCHETT(void);
   virtual void set_DocTIDTPRICE_HOT_DRASCHETT(TFIBLargeIntField * DocTIDTPRICE_HOT_DRASCHETT);

   virtual TFIBLargeIntField * get_DocTIDNOM_HOT_DRASCHETT(void);
   virtual void set_DocTIDNOM_HOT_DRASCHETT(TFIBLargeIntField * DocTIDNOM_HOT_DRASCHETT);

   virtual TFIBLargeIntField * get_DocTIDED_HOT_DRASCHETT(void);
   virtual void set_DocTIDED_HOT_DRASCHETT(TFIBLargeIntField * DocTIDED_HOT_DRASCHETT);

   virtual TFIBLargeIntField * get_DocTIDNOMER_HOT_DRASCHETT(void);
   virtual void set_DocTIDNOMER_HOT_DRASCHETT(TFIBLargeIntField * DocTIDNOMER_HOT_DRASCHETT);

   virtual TFIBLargeIntField * get_DocTIDCAT_HOT_DRASCHETT(void);
   virtual void set_DocTIDCAT_HOT_DRASCHETT(TFIBLargeIntField * DocTIDCAT_HOT_DRASCHETT);

   virtual TFIBLargeIntField * get_DocTIDGUEST_HOT_DRASCHETT(void);
   virtual void set_DocTIDGUEST_HOT_DRASCHETT(TFIBLargeIntField * DocTIDGUEST_HOT_DRASCHETT);

   virtual TFIBLargeIntField * get_DocTIDTPOS_HOT_DRASCHETT(void);
   virtual void set_DocTIDTPOS_HOT_DRASCHETT(TFIBLargeIntField * DocTIDTPOS_HOT_DRASCHETT);

   virtual TFIBLargeIntField * get_DocTIDBASE_HOT_DRASCHETT(void);
   virtual void set_DocTIDBASE_HOT_DRASCHETT(TFIBLargeIntField * DocTIDBASE_HOT_DRASCHETT);

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
   virtual void AddString(void);
   virtual void DeleteString(void);
   virtual void CloseDoc(void);
   virtual bool DeleteDoc(__int64 id);
   virtual void GetSpisokGuest(void);
   virtual double GetKolOsnUslugGuest(__int64 id_guest);
   virtual double GetSumDopUslugGuest(__int64 id_guest);
};
#define CLSID_THOT_DMDocRaschetImpl __uuidof(THOT_DMDocRaschetImpl)
#endif
