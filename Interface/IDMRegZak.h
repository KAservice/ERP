#ifndef UIDMRegZakH
#define UIDMRegZakH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{F3A84106-992A-4815-AC5C-4F25D151122F}")) IDMRegZak : public IMainInterface
{
public:
   __property TDataSource * DataSourceDoc = {read = get_DataSourceDoc , write = set_DataSourceDoc};
   virtual TDataSource * get_DataSourceDoc(void)=0;
   virtual void set_DataSourceDoc(TDataSource * DataSourceDoc)=0;

   __property TDataSource * DataSourceDocT = {read = get_DataSourceDocT , write = set_DataSourceDocT};
   virtual TDataSource * get_DataSourceDocT(void)=0;
   virtual void set_DataSourceDocT(TDataSource * DataSourceDocT)=0;

   __property TDataSource * DataSourceOb = {read = get_DataSourceOb , write = set_DataSourceOb};
   virtual TDataSource * get_DataSourceOb(void)=0;
   virtual void set_DataSourceOb(TDataSource * DataSourceOb)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TpFIBDataSet * Doc = {read = get_Doc , write = set_Doc};
   virtual TpFIBDataSet * get_Doc(void)=0;
   virtual void set_Doc(TpFIBDataSet * Doc)=0;

   __property TFIBBCDField * DocSUM_ZAK = {read = get_DocSUM_ZAK , write = set_DocSUM_ZAK};
   virtual TFIBBCDField * get_DocSUM_ZAK(void)=0;
   virtual void set_DocSUM_ZAK(TFIBBCDField * DocSUM_ZAK)=0;

   __property TFIBSmallIntField * DocSOST_ZAK = {read = get_DocSOST_ZAK , write = set_DocSOST_ZAK};
   virtual TFIBSmallIntField * get_DocSOST_ZAK(void)=0;
   virtual void set_DocSOST_ZAK(TFIBSmallIntField * DocSOST_ZAK)=0;

   __property TpFIBDataSet * DocT = {read = get_DocT , write = set_DocT};
   virtual TpFIBDataSet * get_DocT(void)=0;
   virtual void set_DocT(TpFIBDataSet * DocT)=0;

   __property TFIBBCDField * DocTKOLPR_ZAKT = {read = get_DocTKOLPR_ZAKT , write = set_DocTKOLPR_ZAKT};
   virtual TFIBBCDField * get_DocTKOLPR_ZAKT(void)=0;
   virtual void set_DocTKOLPR_ZAKT(TFIBBCDField * DocTKOLPR_ZAKT)=0;

   __property TFIBBCDField * DocTKOLOT_ZAKT = {read = get_DocTKOLOT_ZAKT , write = set_DocTKOLOT_ZAKT};
   virtual TFIBBCDField * get_DocTKOLOT_ZAKT(void)=0;
   virtual void set_DocTKOLOT_ZAKT(TFIBBCDField * DocTKOLOT_ZAKT)=0;

   __property TFIBBCDField * DocTKOLZ_ZAKT = {read = get_DocTKOLZ_ZAKT , write = set_DocTKOLZ_ZAKT};
   virtual TFIBBCDField * get_DocTKOLZ_ZAKT(void)=0;
   virtual void set_DocTKOLZ_ZAKT(TFIBBCDField * DocTKOLZ_ZAKT)=0;

   __property TFIBBCDField * DocTKF_ZAKT = {read = get_DocTKF_ZAKT , write = set_DocTKF_ZAKT};
   virtual TFIBBCDField * get_DocTKF_ZAKT(void)=0;
   virtual void set_DocTKF_ZAKT(TFIBBCDField * DocTKF_ZAKT)=0;

   __property TFIBBCDField * DocTPRICE_ZAKT = {read = get_DocTPRICE_ZAKT , write = set_DocTPRICE_ZAKT};
   virtual TFIBBCDField * get_DocTPRICE_ZAKT(void)=0;
   virtual void set_DocTPRICE_ZAKT(TFIBBCDField * DocTPRICE_ZAKT)=0;

   __property TFIBBCDField * DocTSUM_ZAKT = {read = get_DocTSUM_ZAKT , write = set_DocTSUM_ZAKT};
   virtual TFIBBCDField * get_DocTSUM_ZAKT(void)=0;
   virtual void set_DocTSUM_ZAKT(TFIBBCDField * DocTSUM_ZAKT)=0;

   __property TFIBBCDField * DocTOTKAZ_ZAKT = {read = get_DocTOTKAZ_ZAKT , write = set_DocTOTKAZ_ZAKT};
   virtual TFIBBCDField * get_DocTOTKAZ_ZAKT(void)=0;
   virtual void set_DocTOTKAZ_ZAKT(TFIBBCDField * DocTOTKAZ_ZAKT)=0;

   __property TFIBIntegerField * DocTTNOM = {read = get_DocTTNOM , write = set_DocTTNOM};
   virtual TFIBIntegerField * get_DocTTNOM(void)=0;
   virtual void set_DocTTNOM(TFIBIntegerField * DocTTNOM)=0;

   __property TFIBBCDField * DocTZNACH_PRICE = {read = get_DocTZNACH_PRICE , write = set_DocTZNACH_PRICE};
   virtual TFIBBCDField * get_DocTZNACH_PRICE(void)=0;
   virtual void set_DocTZNACH_PRICE(TFIBBCDField * DocTZNACH_PRICE)=0;

   __property TpFIBDataSet * Ob = {read = get_Ob , write = set_Ob};
   virtual TpFIBDataSet * get_Ob(void)=0;
   virtual void set_Ob(TpFIBDataSet * Ob)=0;

   __property TFIBSmallIntField * ObGRP_STROB = {read = get_ObGRP_STROB , write = set_ObGRP_STROB};
   virtual TFIBSmallIntField * get_ObGRP_STROB(void)=0;
   virtual void set_ObGRP_STROB(TFIBSmallIntField * ObGRP_STROB)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

   __property TFIBBCDField * TableSUM_ZAK = {read = get_TableSUM_ZAK , write = set_TableSUM_ZAK};
   virtual TFIBBCDField * get_TableSUM_ZAK(void)=0;
   virtual void set_TableSUM_ZAK(TFIBBCDField * TableSUM_ZAK)=0;

   __property TFIBSmallIntField * TableSOST_ZAK = {read = get_TableSOST_ZAK , write = set_TableSOST_ZAK};
   virtual TFIBSmallIntField * get_TableSOST_ZAK(void)=0;
   virtual void set_TableSOST_ZAK(TFIBSmallIntField * TableSOST_ZAK)=0;

   __property TpFIBDataSet * IBQPrint = {read = get_IBQPrint , write = set_IBQPrint};
   virtual TpFIBDataSet * get_IBQPrint(void)=0;
   virtual void set_IBQPrint(TpFIBDataSet * IBQPrint)=0;

   __property TpFIBDataSet * IBQMPrig = {read = get_IBQMPrig , write = set_IBQMPrig};
   virtual TpFIBDataSet * get_IBQMPrig(void)=0;
   virtual void set_IBQMPrig(TpFIBDataSet * IBQMPrig)=0;

   __property TpFIBDataSet * IBQNom = {read = get_IBQNom , write = set_IBQNom};
   virtual TpFIBDataSet * get_IBQNom(void)=0;
   virtual void set_IBQNom(TpFIBDataSet * IBQNom)=0;

   __property TFIBBCDField * IBQPrintKF_ZAKT = {read = get_IBQPrintKF_ZAKT , write = set_IBQPrintKF_ZAKT};
   virtual TFIBBCDField * get_IBQPrintKF_ZAKT(void)=0;
   virtual void set_IBQPrintKF_ZAKT(TFIBBCDField * IBQPrintKF_ZAKT)=0;

   __property TFIBBCDField * IBQPrintKOLZ_ZAKT = {read = get_IBQPrintKOLZ_ZAKT , write = set_IBQPrintKOLZ_ZAKT};
   virtual TFIBBCDField * get_IBQPrintKOLZ_ZAKT(void)=0;
   virtual void set_IBQPrintKOLZ_ZAKT(TFIBBCDField * IBQPrintKOLZ_ZAKT)=0;

   __property TFIBBCDField * IBQPrintKOLPR_ZAKT = {read = get_IBQPrintKOLPR_ZAKT , write = set_IBQPrintKOLPR_ZAKT};
   virtual TFIBBCDField * get_IBQPrintKOLPR_ZAKT(void)=0;
   virtual void set_IBQPrintKOLPR_ZAKT(TFIBBCDField * IBQPrintKOLPR_ZAKT)=0;

   __property TFIBBCDField * IBQPrintOTKAZ_ZAKT = {read = get_IBQPrintOTKAZ_ZAKT , write = set_IBQPrintOTKAZ_ZAKT};
   virtual TFIBBCDField * get_IBQPrintOTKAZ_ZAKT(void)=0;
   virtual void set_IBQPrintOTKAZ_ZAKT(TFIBBCDField * IBQPrintOTKAZ_ZAKT)=0;

   __property TIntegerField * DocTRECNO = {read = get_DocTRECNO , write = set_DocTRECNO};
   virtual TIntegerField * get_DocTRECNO(void)=0;
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO)=0;

   __property TFIBBCDField * IBQPrintID_ZAKT = {read = get_IBQPrintID_ZAKT , write = set_IBQPrintID_ZAKT};
   virtual TFIBBCDField * get_IBQPrintID_ZAKT(void)=0;
   virtual void set_IBQPrintID_ZAKT(TFIBBCDField * IBQPrintID_ZAKT)=0;

   __property TFIBBCDField * IBQPrintIDMPRIG_ZAKT = {read = get_IBQPrintIDMPRIG_ZAKT , write = set_IBQPrintIDMPRIG_ZAKT};
   virtual TFIBBCDField * get_IBQPrintIDMPRIG_ZAKT(void)=0;
   virtual void set_IBQPrintIDMPRIG_ZAKT(TFIBBCDField * IBQPrintIDMPRIG_ZAKT)=0;

   __property TFIBBCDField * TableID_ZAK = {read = get_TableID_ZAK , write = set_TableID_ZAK};
   virtual TFIBBCDField * get_TableID_ZAK(void)=0;
   virtual void set_TableID_ZAK(TFIBBCDField * TableID_ZAK)=0;

   __property TFIBBCDField * TableIDOB_ZAK = {read = get_TableIDOB_ZAK , write = set_TableIDOB_ZAK};
   virtual TFIBBCDField * get_TableIDOB_ZAK(void)=0;
   virtual void set_TableIDOB_ZAK(TFIBBCDField * TableIDOB_ZAK)=0;

   __property TFIBBCDField * TableIDKLIENT_ZAK = {read = get_TableIDKLIENT_ZAK , write = set_TableIDKLIENT_ZAK};
   virtual TFIBBCDField * get_TableIDKLIENT_ZAK(void)=0;
   virtual void set_TableIDKLIENT_ZAK(TFIBBCDField * TableIDKLIENT_ZAK)=0;

   __property TFIBBCDField * TableIDUSER_ZAK = {read = get_TableIDUSER_ZAK , write = set_TableIDUSER_ZAK};
   virtual TFIBBCDField * get_TableIDUSER_ZAK(void)=0;
   virtual void set_TableIDUSER_ZAK(TFIBBCDField * TableIDUSER_ZAK)=0;

   __property TFIBBCDField * DocID_ZAK = {read = get_DocID_ZAK , write = set_DocID_ZAK};
   virtual TFIBBCDField * get_DocID_ZAK(void)=0;
   virtual void set_DocID_ZAK(TFIBBCDField * DocID_ZAK)=0;

   __property TFIBBCDField * DocIDOB_ZAK = {read = get_DocIDOB_ZAK , write = set_DocIDOB_ZAK};
   virtual TFIBBCDField * get_DocIDOB_ZAK(void)=0;
   virtual void set_DocIDOB_ZAK(TFIBBCDField * DocIDOB_ZAK)=0;

   __property TFIBBCDField * DocIDKLIENT_ZAK = {read = get_DocIDKLIENT_ZAK , write = set_DocIDKLIENT_ZAK};
   virtual TFIBBCDField * get_DocIDKLIENT_ZAK(void)=0;
   virtual void set_DocIDKLIENT_ZAK(TFIBBCDField * DocIDKLIENT_ZAK)=0;

   __property TFIBBCDField * DocIDUSER_ZAK = {read = get_DocIDUSER_ZAK , write = set_DocIDUSER_ZAK};
   virtual TFIBBCDField * get_DocIDUSER_ZAK(void)=0;
   virtual void set_DocIDUSER_ZAK(TFIBBCDField * DocIDUSER_ZAK)=0;

   __property TFIBBCDField * DocIDKLIENT = {read = get_DocIDKLIENT , write = set_DocIDKLIENT};
   virtual TFIBBCDField * get_DocIDKLIENT(void)=0;
   virtual void set_DocIDKLIENT(TFIBBCDField * DocIDKLIENT)=0;

   __property TFIBBCDField * DocIDTYPEPRICE_ZAK = {read = get_DocIDTYPEPRICE_ZAK , write = set_DocIDTYPEPRICE_ZAK};
   virtual TFIBBCDField * get_DocIDTYPEPRICE_ZAK(void)=0;
   virtual void set_DocIDTYPEPRICE_ZAK(TFIBBCDField * DocIDTYPEPRICE_ZAK)=0;

   __property TFIBBCDField * DocIDDISCOUNTCARD_ZAK = {read = get_DocIDDISCOUNTCARD_ZAK , write = set_DocIDDISCOUNTCARD_ZAK};
   virtual TFIBBCDField * get_DocIDDISCOUNTCARD_ZAK(void)=0;
   virtual void set_DocIDDISCOUNTCARD_ZAK(TFIBBCDField * DocIDDISCOUNTCARD_ZAK)=0;

   __property TFIBBCDField * DocTPRSK_ZAKT = {read = get_DocTPRSK_ZAKT , write = set_DocTPRSK_ZAKT};
   virtual TFIBBCDField * get_DocTPRSK_ZAKT(void)=0;
   virtual void set_DocTPRSK_ZAKT(TFIBBCDField * DocTPRSK_ZAKT)=0;

   __property TFIBBCDField * DocTPRNAD_ZAKT = {read = get_DocTPRNAD_ZAKT , write = set_DocTPRNAD_ZAKT};
   virtual TFIBBCDField * get_DocTPRNAD_ZAKT(void)=0;
   virtual void set_DocTPRNAD_ZAKT(TFIBBCDField * DocTPRNAD_ZAKT)=0;

   __property TFIBBCDField * DocTSUMSK_ZAKT = {read = get_DocTSUMSK_ZAKT , write = set_DocTSUMSK_ZAKT};
   virtual TFIBBCDField * get_DocTSUMSK_ZAKT(void)=0;
   virtual void set_DocTSUMSK_ZAKT(TFIBBCDField * DocTSUMSK_ZAKT)=0;

   __property TFIBBCDField * DocTSUMNAD_ZAKT = {read = get_DocTSUMNAD_ZAKT , write = set_DocTSUMNAD_ZAKT};
   virtual TFIBBCDField * get_DocTSUMNAD_ZAKT(void)=0;
   virtual void set_DocTSUMNAD_ZAKT(TFIBBCDField * DocTSUMNAD_ZAKT)=0;

   __property TFIBBCDField * ObID_STROB = {read = get_ObID_STROB , write = set_ObID_STROB};
   virtual TFIBBCDField * get_ObID_STROB(void)=0;
   virtual void set_ObID_STROB(TFIBBCDField * ObID_STROB)=0;

   __property TFIBBCDField * ObIDGRP_STROB = {read = get_ObIDGRP_STROB , write = set_ObIDGRP_STROB};
   virtual TFIBBCDField * get_ObIDGRP_STROB(void)=0;
   virtual void set_ObIDGRP_STROB(TFIBBCDField * ObIDGRP_STROB)=0;

   __property TFIBBCDField * DocTID_ZAKT = {read = get_DocTID_ZAKT , write = set_DocTID_ZAKT};
   virtual TFIBBCDField * get_DocTID_ZAKT(void)=0;
   virtual void set_DocTID_ZAKT(TFIBBCDField * DocTID_ZAKT)=0;

   __property TFIBBCDField * DocTIDZ_ZAKT = {read = get_DocTIDZ_ZAKT , write = set_DocTIDZ_ZAKT};
   virtual TFIBBCDField * get_DocTIDZ_ZAKT(void)=0;
   virtual void set_DocTIDZ_ZAKT(TFIBBCDField * DocTIDZ_ZAKT)=0;

   __property TFIBBCDField * DocTIDNOM_ZAKT = {read = get_DocTIDNOM_ZAKT , write = set_DocTIDNOM_ZAKT};
   virtual TFIBBCDField * get_DocTIDNOM_ZAKT(void)=0;
   virtual void set_DocTIDNOM_ZAKT(TFIBBCDField * DocTIDNOM_ZAKT)=0;

   __property TFIBBCDField * DocTIDED_ZAKT = {read = get_DocTIDED_ZAKT , write = set_DocTIDED_ZAKT};
   virtual TFIBBCDField * get_DocTIDED_ZAKT(void)=0;
   virtual void set_DocTIDED_ZAKT(TFIBBCDField * DocTIDED_ZAKT)=0;

   __property TFIBBCDField * DocTIDMPRIG_ZAKT = {read = get_DocTIDMPRIG_ZAKT , write = set_DocTIDMPRIG_ZAKT};
   virtual TFIBBCDField * get_DocTIDMPRIG_ZAKT(void)=0;
   virtual void set_DocTIDMPRIG_ZAKT(TFIBBCDField * DocTIDMPRIG_ZAKT)=0;

   __property TFIBBCDField * DocTIDBASE_RGZAKT = {read = get_DocTIDBASE_RGZAKT , write = set_DocTIDBASE_RGZAKT};
   virtual TFIBBCDField * get_DocTIDBASE_RGZAKT(void)=0;
   virtual void set_DocTIDBASE_RGZAKT(TFIBBCDField * DocTIDBASE_RGZAKT)=0;

   __property TFIBBCDField * DocTPRSK_CARD_RGZAKT = {read = get_DocTPRSK_CARD_RGZAKT , write = set_DocTPRSK_CARD_RGZAKT};
   virtual TFIBBCDField * get_DocTPRSK_CARD_RGZAKT(void)=0;
   virtual void set_DocTPRSK_CARD_RGZAKT(TFIBBCDField * DocTPRSK_CARD_RGZAKT)=0;

   __property TFIBBCDField * DocTPRSK_AUTO_RGZAKT = {read = get_DocTPRSK_AUTO_RGZAKT , write = set_DocTPRSK_AUTO_RGZAKT};
   virtual TFIBBCDField * get_DocTPRSK_AUTO_RGZAKT(void)=0;
   virtual void set_DocTPRSK_AUTO_RGZAKT(TFIBBCDField * DocTPRSK_AUTO_RGZAKT)=0;

   __property TFIBWideStringField * IBQPrintKRNAMENOM = {read = get_IBQPrintKRNAMENOM , write = set_IBQPrintKRNAMENOM};
   virtual TFIBWideStringField * get_IBQPrintKRNAMENOM(void)=0;
   virtual void set_IBQPrintKRNAMENOM(TFIBWideStringField * IBQPrintKRNAMENOM)=0;

   __property TFIBWideStringField * IBQPrintNAMEED = {read = get_IBQPrintNAMEED , write = set_IBQPrintNAMEED};
   virtual TFIBWideStringField * get_IBQPrintNAMEED(void)=0;
   virtual void set_IBQPrintNAMEED(TFIBWideStringField * IBQPrintNAMEED)=0;

   __property TFIBWideStringField * IBQMPrigNAME_MPRIG = {read = get_IBQMPrigNAME_MPRIG , write = set_IBQMPrigNAME_MPRIG};
   virtual TFIBWideStringField * get_IBQMPrigNAME_MPRIG(void)=0;
   virtual void set_IBQMPrigNAME_MPRIG(TFIBWideStringField * IBQMPrigNAME_MPRIG)=0;

   __property TFIBWideStringField * IBQMPrigCOMPNAME_OBORUD = {read = get_IBQMPrigCOMPNAME_OBORUD , write = set_IBQMPrigCOMPNAME_OBORUD};
   virtual TFIBWideStringField * get_IBQMPrigCOMPNAME_OBORUD(void)=0;
   virtual void set_IBQMPrigCOMPNAME_OBORUD(TFIBWideStringField * IBQMPrigCOMPNAME_OBORUD)=0;

   __property TFIBWideStringField * IBQMPrigCOMNAME_OBORUD = {read = get_IBQMPrigCOMNAME_OBORUD , write = set_IBQMPrigCOMNAME_OBORUD};
   virtual TFIBWideStringField * get_IBQMPrigCOMNAME_OBORUD(void)=0;
   virtual void set_IBQMPrigCOMNAME_OBORUD(TFIBWideStringField * IBQMPrigCOMNAME_OBORUD)=0;

   __property TFIBWideStringField * IBQMPrigBAUDRATE_OBORUD = {read = get_IBQMPrigBAUDRATE_OBORUD , write = set_IBQMPrigBAUDRATE_OBORUD};
   virtual TFIBWideStringField * get_IBQMPrigBAUDRATE_OBORUD(void)=0;
   virtual void set_IBQMPrigBAUDRATE_OBORUD(TFIBWideStringField * IBQMPrigBAUDRATE_OBORUD)=0;

   __property TFIBWideStringField * IBQNomNAME_MPRIG = {read = get_IBQNomNAME_MPRIG , write = set_IBQNomNAME_MPRIG};
   virtual TFIBWideStringField * get_IBQNomNAME_MPRIG(void)=0;
   virtual void set_IBQNomNAME_MPRIG(TFIBWideStringField * IBQNomNAME_MPRIG)=0;

   __property TFIBWideStringField * ObNAME_STROB = {read = get_ObNAME_STROB , write = set_ObNAME_STROB};
   virtual TFIBWideStringField * get_ObNAME_STROB(void)=0;
   virtual void set_ObNAME_STROB(TFIBWideStringField * ObNAME_STROB)=0;

   __property TFIBIntegerField * ObCODE_STROB = {read = get_ObCODE_STROB , write = set_ObCODE_STROB};
   virtual TFIBIntegerField * get_ObCODE_STROB(void)=0;
   virtual void set_ObCODE_STROB(TFIBIntegerField * ObCODE_STROB)=0;

   __property TFIBWideStringField * ObGID_SSTROB = {read = get_ObGID_SSTROB , write = set_ObGID_SSTROB};
   virtual TFIBWideStringField * get_ObGID_SSTROB(void)=0;
   virtual void set_ObGID_SSTROB(TFIBWideStringField * ObGID_SSTROB)=0;

   __property TFIBWideStringField * DocTNAMENOM = {read = get_DocTNAMENOM , write = set_DocTNAMENOM};
   virtual TFIBWideStringField * get_DocTNAMENOM(void)=0;
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)=0;

   __property TFIBWideStringField * DocTKRNAMENOM = {read = get_DocTKRNAMENOM , write = set_DocTKRNAMENOM};
   virtual TFIBWideStringField * get_DocTKRNAMENOM(void)=0;
   virtual void set_DocTKRNAMENOM(TFIBWideStringField * DocTKRNAMENOM)=0;

   __property TFIBWideStringField * DocTNAMEED = {read = get_DocTNAMEED , write = set_DocTNAMEED};
   virtual TFIBWideStringField * get_DocTNAMEED(void)=0;
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)=0;

   __property TFIBWideStringField * DocTNAME_MPRIG = {read = get_DocTNAME_MPRIG , write = set_DocTNAME_MPRIG};
   virtual TFIBWideStringField * get_DocTNAME_MPRIG(void)=0;
   virtual void set_DocTNAME_MPRIG(TFIBWideStringField * DocTNAME_MPRIG)=0;

   __property TFIBWideStringField * DocNAME_STROB = {read = get_DocNAME_STROB , write = set_DocNAME_STROB};
   virtual TFIBWideStringField * get_DocNAME_STROB(void)=0;
   virtual void set_DocNAME_STROB(TFIBWideStringField * DocNAME_STROB)=0;

   __property TFIBWideStringField * DocNAMEKLIENT = {read = get_DocNAMEKLIENT , write = set_DocNAMEKLIENT};
   virtual TFIBWideStringField * get_DocNAMEKLIENT(void)=0;
   virtual void set_DocNAMEKLIENT(TFIBWideStringField * DocNAMEKLIENT)=0;

   __property TFIBWideStringField * DocNAME_USER = {read = get_DocNAME_USER , write = set_DocNAME_USER};
   virtual TFIBWideStringField * get_DocNAME_USER(void)=0;
   virtual void set_DocNAME_USER(TFIBWideStringField * DocNAME_USER)=0;

   __property TFIBWideStringField * DocNAME_TPRICE = {read = get_DocNAME_TPRICE , write = set_DocNAME_TPRICE};
   virtual TFIBWideStringField * get_DocNAME_TPRICE(void)=0;
   virtual void set_DocNAME_TPRICE(TFIBWideStringField * DocNAME_TPRICE)=0;

   __property TFIBWideStringField * DocNAME_SDISCOUNT_CARD = {read = get_DocNAME_SDISCOUNT_CARD , write = set_DocNAME_SDISCOUNT_CARD};
   virtual TFIBWideStringField * get_DocNAME_SDISCOUNT_CARD(void)=0;
   virtual void set_DocNAME_SDISCOUNT_CARD(TFIBWideStringField * DocNAME_SDISCOUNT_CARD)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property __int64 IdOb = {read = get_IdOb , write = set_IdOb};
   virtual __int64 get_IdOb(void)=0;
   virtual void set_IdOb(__int64 IdOb)=0;

   __property __int64 IdTypePrice = {read = get_IdTypePrice , write = set_IdTypePrice};
   virtual __int64 get_IdTypePrice(void)=0;
   virtual void set_IdTypePrice(__int64 IdTypePrice)=0;

   virtual void NewDoc(__int64 ob)=0;
   virtual void OpenDoc(__int64 id)=0;
   virtual bool SaveDoc(void)=0;
   virtual void CloseDoc(void)=0;
   virtual void AddDocNewString(void)=0;
   virtual void DeleteStringDoc(void)=0;
   virtual bool DeleteDoc(__int64 id)=0;
   virtual void OpenMPrig(void)=0;
};
#define IID_IDMRegZak __uuidof(IDMRegZak)
#endif
