#ifndef UDMRegZakImplH
#define UDMRegZakImplH
#include "IDMRegZak.h"
#include "UDMRegZak.h"
//---------------------------------------------------------------
class __declspec(uuid("{C6592FBD-354F-4540-A05F-D13406FD5E6E}")) TDMRegZakImpl : public IDMRegZak
{
public:
   TDMRegZakImpl();
   ~TDMRegZakImpl();
   TDMRegZak * Object;
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

//IDMRegZak
   virtual TDataSource * get_DataSourceDoc(void);
   virtual void set_DataSourceDoc(TDataSource * DataSourceDoc);

   virtual TDataSource * get_DataSourceDocT(void);
   virtual void set_DataSourceDocT(TDataSource * DataSourceDocT);

   virtual TDataSource * get_DataSourceOb(void);
   virtual void set_DataSourceOb(TDataSource * DataSourceOb);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBDataSet * get_Doc(void);
   virtual void set_Doc(TpFIBDataSet * Doc);

   virtual TFIBBCDField * get_DocSUM_ZAK(void);
   virtual void set_DocSUM_ZAK(TFIBBCDField * DocSUM_ZAK);

   virtual TFIBSmallIntField * get_DocSOST_ZAK(void);
   virtual void set_DocSOST_ZAK(TFIBSmallIntField * DocSOST_ZAK);

   virtual TpFIBDataSet * get_DocT(void);
   virtual void set_DocT(TpFIBDataSet * DocT);

   virtual TFIBBCDField * get_DocTKOLPR_ZAKT(void);
   virtual void set_DocTKOLPR_ZAKT(TFIBBCDField * DocTKOLPR_ZAKT);

   virtual TFIBBCDField * get_DocTKOLOT_ZAKT(void);
   virtual void set_DocTKOLOT_ZAKT(TFIBBCDField * DocTKOLOT_ZAKT);

   virtual TFIBBCDField * get_DocTKOLZ_ZAKT(void);
   virtual void set_DocTKOLZ_ZAKT(TFIBBCDField * DocTKOLZ_ZAKT);

   virtual TFIBBCDField * get_DocTKF_ZAKT(void);
   virtual void set_DocTKF_ZAKT(TFIBBCDField * DocTKF_ZAKT);

   virtual TFIBBCDField * get_DocTPRICE_ZAKT(void);
   virtual void set_DocTPRICE_ZAKT(TFIBBCDField * DocTPRICE_ZAKT);

   virtual TFIBBCDField * get_DocTSUM_ZAKT(void);
   virtual void set_DocTSUM_ZAKT(TFIBBCDField * DocTSUM_ZAKT);

   virtual TFIBBCDField * get_DocTOTKAZ_ZAKT(void);
   virtual void set_DocTOTKAZ_ZAKT(TFIBBCDField * DocTOTKAZ_ZAKT);

   virtual TFIBIntegerField * get_DocTTNOM(void);
   virtual void set_DocTTNOM(TFIBIntegerField * DocTTNOM);

   virtual TFIBBCDField * get_DocTZNACH_PRICE(void);
   virtual void set_DocTZNACH_PRICE(TFIBBCDField * DocTZNACH_PRICE);

   virtual TpFIBDataSet * get_Ob(void);
   virtual void set_Ob(TpFIBDataSet * Ob);

   virtual TFIBSmallIntField * get_ObGRP_STROB(void);
   virtual void set_ObGRP_STROB(TFIBSmallIntField * ObGRP_STROB);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TFIBBCDField * get_TableSUM_ZAK(void);
   virtual void set_TableSUM_ZAK(TFIBBCDField * TableSUM_ZAK);

   virtual TFIBSmallIntField * get_TableSOST_ZAK(void);
   virtual void set_TableSOST_ZAK(TFIBSmallIntField * TableSOST_ZAK);

   virtual TpFIBDataSet * get_IBQPrint(void);
   virtual void set_IBQPrint(TpFIBDataSet * IBQPrint);

   virtual TpFIBDataSet * get_IBQMPrig(void);
   virtual void set_IBQMPrig(TpFIBDataSet * IBQMPrig);

   virtual TpFIBDataSet * get_IBQNom(void);
   virtual void set_IBQNom(TpFIBDataSet * IBQNom);

   virtual TFIBBCDField * get_IBQPrintKF_ZAKT(void);
   virtual void set_IBQPrintKF_ZAKT(TFIBBCDField * IBQPrintKF_ZAKT);

   virtual TFIBBCDField * get_IBQPrintKOLZ_ZAKT(void);
   virtual void set_IBQPrintKOLZ_ZAKT(TFIBBCDField * IBQPrintKOLZ_ZAKT);

   virtual TFIBBCDField * get_IBQPrintKOLPR_ZAKT(void);
   virtual void set_IBQPrintKOLPR_ZAKT(TFIBBCDField * IBQPrintKOLPR_ZAKT);

   virtual TFIBBCDField * get_IBQPrintOTKAZ_ZAKT(void);
   virtual void set_IBQPrintOTKAZ_ZAKT(TFIBBCDField * IBQPrintOTKAZ_ZAKT);

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

   virtual TFIBBCDField * get_IBQPrintID_ZAKT(void);
   virtual void set_IBQPrintID_ZAKT(TFIBBCDField * IBQPrintID_ZAKT);

   virtual TFIBBCDField * get_IBQPrintIDMPRIG_ZAKT(void);
   virtual void set_IBQPrintIDMPRIG_ZAKT(TFIBBCDField * IBQPrintIDMPRIG_ZAKT);

   virtual TFIBBCDField * get_TableID_ZAK(void);
   virtual void set_TableID_ZAK(TFIBBCDField * TableID_ZAK);

   virtual TFIBBCDField * get_TableIDOB_ZAK(void);
   virtual void set_TableIDOB_ZAK(TFIBBCDField * TableIDOB_ZAK);

   virtual TFIBBCDField * get_TableIDKLIENT_ZAK(void);
   virtual void set_TableIDKLIENT_ZAK(TFIBBCDField * TableIDKLIENT_ZAK);

   virtual TFIBBCDField * get_TableIDUSER_ZAK(void);
   virtual void set_TableIDUSER_ZAK(TFIBBCDField * TableIDUSER_ZAK);

   virtual TFIBBCDField * get_DocID_ZAK(void);
   virtual void set_DocID_ZAK(TFIBBCDField * DocID_ZAK);

   virtual TFIBBCDField * get_DocIDOB_ZAK(void);
   virtual void set_DocIDOB_ZAK(TFIBBCDField * DocIDOB_ZAK);

   virtual TFIBBCDField * get_DocIDKLIENT_ZAK(void);
   virtual void set_DocIDKLIENT_ZAK(TFIBBCDField * DocIDKLIENT_ZAK);

   virtual TFIBBCDField * get_DocIDUSER_ZAK(void);
   virtual void set_DocIDUSER_ZAK(TFIBBCDField * DocIDUSER_ZAK);

   virtual TFIBBCDField * get_DocIDKLIENT(void);
   virtual void set_DocIDKLIENT(TFIBBCDField * DocIDKLIENT);

   virtual TFIBBCDField * get_DocIDTYPEPRICE_ZAK(void);
   virtual void set_DocIDTYPEPRICE_ZAK(TFIBBCDField * DocIDTYPEPRICE_ZAK);

   virtual TFIBBCDField * get_DocIDDISCOUNTCARD_ZAK(void);
   virtual void set_DocIDDISCOUNTCARD_ZAK(TFIBBCDField * DocIDDISCOUNTCARD_ZAK);

   virtual TFIBBCDField * get_DocTPRSK_ZAKT(void);
   virtual void set_DocTPRSK_ZAKT(TFIBBCDField * DocTPRSK_ZAKT);

   virtual TFIBBCDField * get_DocTPRNAD_ZAKT(void);
   virtual void set_DocTPRNAD_ZAKT(TFIBBCDField * DocTPRNAD_ZAKT);

   virtual TFIBBCDField * get_DocTSUMSK_ZAKT(void);
   virtual void set_DocTSUMSK_ZAKT(TFIBBCDField * DocTSUMSK_ZAKT);

   virtual TFIBBCDField * get_DocTSUMNAD_ZAKT(void);
   virtual void set_DocTSUMNAD_ZAKT(TFIBBCDField * DocTSUMNAD_ZAKT);

   virtual TFIBBCDField * get_ObID_STROB(void);
   virtual void set_ObID_STROB(TFIBBCDField * ObID_STROB);

   virtual TFIBBCDField * get_ObIDGRP_STROB(void);
   virtual void set_ObIDGRP_STROB(TFIBBCDField * ObIDGRP_STROB);

   virtual TFIBBCDField * get_DocTID_ZAKT(void);
   virtual void set_DocTID_ZAKT(TFIBBCDField * DocTID_ZAKT);

   virtual TFIBBCDField * get_DocTIDZ_ZAKT(void);
   virtual void set_DocTIDZ_ZAKT(TFIBBCDField * DocTIDZ_ZAKT);

   virtual TFIBBCDField * get_DocTIDNOM_ZAKT(void);
   virtual void set_DocTIDNOM_ZAKT(TFIBBCDField * DocTIDNOM_ZAKT);

   virtual TFIBBCDField * get_DocTIDED_ZAKT(void);
   virtual void set_DocTIDED_ZAKT(TFIBBCDField * DocTIDED_ZAKT);

   virtual TFIBBCDField * get_DocTIDMPRIG_ZAKT(void);
   virtual void set_DocTIDMPRIG_ZAKT(TFIBBCDField * DocTIDMPRIG_ZAKT);

   virtual TFIBBCDField * get_DocTIDBASE_RGZAKT(void);
   virtual void set_DocTIDBASE_RGZAKT(TFIBBCDField * DocTIDBASE_RGZAKT);

   virtual TFIBBCDField * get_DocTPRSK_CARD_RGZAKT(void);
   virtual void set_DocTPRSK_CARD_RGZAKT(TFIBBCDField * DocTPRSK_CARD_RGZAKT);

   virtual TFIBBCDField * get_DocTPRSK_AUTO_RGZAKT(void);
   virtual void set_DocTPRSK_AUTO_RGZAKT(TFIBBCDField * DocTPRSK_AUTO_RGZAKT);

   virtual TFIBWideStringField * get_IBQPrintKRNAMENOM(void);
   virtual void set_IBQPrintKRNAMENOM(TFIBWideStringField * IBQPrintKRNAMENOM);

   virtual TFIBWideStringField * get_IBQPrintNAMEED(void);
   virtual void set_IBQPrintNAMEED(TFIBWideStringField * IBQPrintNAMEED);

   virtual TFIBWideStringField * get_IBQMPrigNAME_MPRIG(void);
   virtual void set_IBQMPrigNAME_MPRIG(TFIBWideStringField * IBQMPrigNAME_MPRIG);

   virtual TFIBWideStringField * get_IBQMPrigCOMPNAME_OBORUD(void);
   virtual void set_IBQMPrigCOMPNAME_OBORUD(TFIBWideStringField * IBQMPrigCOMPNAME_OBORUD);

   virtual TFIBWideStringField * get_IBQMPrigCOMNAME_OBORUD(void);
   virtual void set_IBQMPrigCOMNAME_OBORUD(TFIBWideStringField * IBQMPrigCOMNAME_OBORUD);

   virtual TFIBWideStringField * get_IBQMPrigBAUDRATE_OBORUD(void);
   virtual void set_IBQMPrigBAUDRATE_OBORUD(TFIBWideStringField * IBQMPrigBAUDRATE_OBORUD);

   virtual TFIBWideStringField * get_IBQNomNAME_MPRIG(void);
   virtual void set_IBQNomNAME_MPRIG(TFIBWideStringField * IBQNomNAME_MPRIG);

   virtual TFIBWideStringField * get_ObNAME_STROB(void);
   virtual void set_ObNAME_STROB(TFIBWideStringField * ObNAME_STROB);

   virtual TFIBIntegerField * get_ObCODE_STROB(void);
   virtual void set_ObCODE_STROB(TFIBIntegerField * ObCODE_STROB);

   virtual TFIBWideStringField * get_ObGID_SSTROB(void);
   virtual void set_ObGID_SSTROB(TFIBWideStringField * ObGID_SSTROB);

   virtual TFIBWideStringField * get_DocTNAMENOM(void);
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM);

   virtual TFIBWideStringField * get_DocTKRNAMENOM(void);
   virtual void set_DocTKRNAMENOM(TFIBWideStringField * DocTKRNAMENOM);

   virtual TFIBWideStringField * get_DocTNAMEED(void);
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED);

   virtual TFIBWideStringField * get_DocTNAME_MPRIG(void);
   virtual void set_DocTNAME_MPRIG(TFIBWideStringField * DocTNAME_MPRIG);

   virtual TFIBWideStringField * get_DocNAME_STROB(void);
   virtual void set_DocNAME_STROB(TFIBWideStringField * DocNAME_STROB);

   virtual TFIBWideStringField * get_DocNAMEKLIENT(void);
   virtual void set_DocNAMEKLIENT(TFIBWideStringField * DocNAMEKLIENT);

   virtual TFIBWideStringField * get_DocNAME_USER(void);
   virtual void set_DocNAME_USER(TFIBWideStringField * DocNAME_USER);

   virtual TFIBWideStringField * get_DocNAME_TPRICE(void);
   virtual void set_DocNAME_TPRICE(TFIBWideStringField * DocNAME_TPRICE);

   virtual TFIBWideStringField * get_DocNAME_SDISCOUNT_CARD(void);
   virtual void set_DocNAME_SDISCOUNT_CARD(TFIBWideStringField * DocNAME_SDISCOUNT_CARD);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual __int64 get_IdOb(void);
   virtual void set_IdOb(__int64 IdOb);

   virtual __int64 get_IdTypePrice(void);
   virtual void set_IdTypePrice(__int64 IdTypePrice);

   virtual void NewDoc(__int64 ob);
   virtual void OpenDoc(__int64 id);
   virtual bool SaveDoc(void);
   virtual void CloseDoc(void);
   virtual void AddDocNewString(void);
   virtual void DeleteStringDoc(void);
   virtual bool DeleteDoc(__int64 id);
   virtual void OpenMPrig(void);
};
#define CLSID_TDMRegZakImpl __uuidof(TDMRegZakImpl)
#endif
