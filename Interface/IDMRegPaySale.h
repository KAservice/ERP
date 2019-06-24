#ifndef UIDMRegPaySaleH
#define UIDMRegPaySaleH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{DB7DB87E-1C62-432A-8838-1CB47DBD8C44}")) IDMRegPaySale : public IMainInterface
{
public:
   __property TpFIBDataSet * DvRegOst = {read = get_DvRegOst , write = set_DvRegOst};
   virtual TpFIBDataSet * get_DvRegOst(void)=0;
   virtual void set_DvRegOst(TpFIBDataSet * DvRegOst)=0;

   __property TpFIBDataSet * RegOst = {read = get_RegOst , write = set_RegOst};
   virtual TpFIBDataSet * get_RegOst(void)=0;
   virtual void set_RegOst(TpFIBDataSet * RegOst)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TFIBDateTimeField * DvRegOstPOS_RGPAYSALE_DV = {read = get_DvRegOstPOS_RGPAYSALE_DV , write = set_DvRegOstPOS_RGPAYSALE_DV};
   virtual TFIBDateTimeField * get_DvRegOstPOS_RGPAYSALE_DV(void)=0;
   virtual void set_DvRegOstPOS_RGPAYSALE_DV(TFIBDateTimeField * DvRegOstPOS_RGPAYSALE_DV)=0;

   __property TFIBIntegerField * DvRegOstTDV_RGPAYSALE_DV = {read = get_DvRegOstTDV_RGPAYSALE_DV , write = set_DvRegOstTDV_RGPAYSALE_DV};
   virtual TFIBIntegerField * get_DvRegOstTDV_RGPAYSALE_DV(void)=0;
   virtual void set_DvRegOstTDV_RGPAYSALE_DV(TFIBIntegerField * DvRegOstTDV_RGPAYSALE_DV)=0;

   __property TFIBDateField * DvRegOstDATE_RGPAYSALE_DV = {read = get_DvRegOstDATE_RGPAYSALE_DV , write = set_DvRegOstDATE_RGPAYSALE_DV};
   virtual TFIBDateField * get_DvRegOstDATE_RGPAYSALE_DV(void)=0;
   virtual void set_DvRegOstDATE_RGPAYSALE_DV(TFIBDateField * DvRegOstDATE_RGPAYSALE_DV)=0;

   __property TFIBBCDField * DvRegOstSUM_RGPAYSALE_DV = {read = get_DvRegOstSUM_RGPAYSALE_DV , write = set_DvRegOstSUM_RGPAYSALE_DV};
   virtual TFIBBCDField * get_DvRegOstSUM_RGPAYSALE_DV(void)=0;
   virtual void set_DvRegOstSUM_RGPAYSALE_DV(TFIBBCDField * DvRegOstSUM_RGPAYSALE_DV)=0;

   __property TFIBDateField * RegOstDATE_RGPAYSALE = {read = get_RegOstDATE_RGPAYSALE , write = set_RegOstDATE_RGPAYSALE};
   virtual TFIBDateField * get_RegOstDATE_RGPAYSALE(void)=0;
   virtual void set_RegOstDATE_RGPAYSALE(TFIBDateField * RegOstDATE_RGPAYSALE)=0;

   __property TFIBBCDField * RegOstSUM_RGPAYSALE = {read = get_RegOstSUM_RGPAYSALE , write = set_RegOstSUM_RGPAYSALE};
   virtual TFIBBCDField * get_RegOstSUM_RGPAYSALE(void)=0;
   virtual void set_RegOstSUM_RGPAYSALE(TFIBBCDField * RegOstSUM_RGPAYSALE)=0;

   __property TFIBBCDField * RegOstID_RGPAYSALE = {read = get_RegOstID_RGPAYSALE , write = set_RegOstID_RGPAYSALE};
   virtual TFIBBCDField * get_RegOstID_RGPAYSALE(void)=0;
   virtual void set_RegOstID_RGPAYSALE(TFIBBCDField * RegOstID_RGPAYSALE)=0;

   __property TFIBBCDField * RegOstIDFIRM_RGPAYSALE = {read = get_RegOstIDFIRM_RGPAYSALE , write = set_RegOstIDFIRM_RGPAYSALE};
   virtual TFIBBCDField * get_RegOstIDFIRM_RGPAYSALE(void)=0;
   virtual void set_RegOstIDFIRM_RGPAYSALE(TFIBBCDField * RegOstIDFIRM_RGPAYSALE)=0;

   __property TFIBBCDField * RegOstIDKLIENT_RGPAYSALE = {read = get_RegOstIDKLIENT_RGPAYSALE , write = set_RegOstIDKLIENT_RGPAYSALE};
   virtual TFIBBCDField * get_RegOstIDKLIENT_RGPAYSALE(void)=0;
   virtual void set_RegOstIDKLIENT_RGPAYSALE(TFIBBCDField * RegOstIDKLIENT_RGPAYSALE)=0;

   __property TFIBBCDField * RegOstIDDOG_RGPAYSALE = {read = get_RegOstIDDOG_RGPAYSALE , write = set_RegOstIDDOG_RGPAYSALE};
   virtual TFIBBCDField * get_RegOstIDDOG_RGPAYSALE(void)=0;
   virtual void set_RegOstIDDOG_RGPAYSALE(TFIBBCDField * RegOstIDDOG_RGPAYSALE)=0;

   __property TFIBBCDField * RegOstIDDOCSALE_RGPAYSALE = {read = get_RegOstIDDOCSALE_RGPAYSALE , write = set_RegOstIDDOCSALE_RGPAYSALE};
   virtual TFIBBCDField * get_RegOstIDDOCSALE_RGPAYSALE(void)=0;
   virtual void set_RegOstIDDOCSALE_RGPAYSALE(TFIBBCDField * RegOstIDDOCSALE_RGPAYSALE)=0;

   __property TFIBBCDField * DvRegOstID_RGPAYSALE_DV = {read = get_DvRegOstID_RGPAYSALE_DV , write = set_DvRegOstID_RGPAYSALE_DV};
   virtual TFIBBCDField * get_DvRegOstID_RGPAYSALE_DV(void)=0;
   virtual void set_DvRegOstID_RGPAYSALE_DV(TFIBBCDField * DvRegOstID_RGPAYSALE_DV)=0;

   __property TFIBBCDField * DvRegOstIDDOC_RGPAYSALE_DV = {read = get_DvRegOstIDDOC_RGPAYSALE_DV , write = set_DvRegOstIDDOC_RGPAYSALE_DV};
   virtual TFIBBCDField * get_DvRegOstIDDOC_RGPAYSALE_DV(void)=0;
   virtual void set_DvRegOstIDDOC_RGPAYSALE_DV(TFIBBCDField * DvRegOstIDDOC_RGPAYSALE_DV)=0;

   __property TFIBBCDField * DvRegOstIDFIRM_RGPAYSALE_DV = {read = get_DvRegOstIDFIRM_RGPAYSALE_DV , write = set_DvRegOstIDFIRM_RGPAYSALE_DV};
   virtual TFIBBCDField * get_DvRegOstIDFIRM_RGPAYSALE_DV(void)=0;
   virtual void set_DvRegOstIDFIRM_RGPAYSALE_DV(TFIBBCDField * DvRegOstIDFIRM_RGPAYSALE_DV)=0;

   __property TFIBBCDField * DvRegOstIDKLIENT_RGPAYSALE_DV = {read = get_DvRegOstIDKLIENT_RGPAYSALE_DV , write = set_DvRegOstIDKLIENT_RGPAYSALE_DV};
   virtual TFIBBCDField * get_DvRegOstIDKLIENT_RGPAYSALE_DV(void)=0;
   virtual void set_DvRegOstIDKLIENT_RGPAYSALE_DV(TFIBBCDField * DvRegOstIDKLIENT_RGPAYSALE_DV)=0;

   __property TFIBBCDField * DvRegOstIDDOG_RGPAYSALE_DV = {read = get_DvRegOstIDDOG_RGPAYSALE_DV , write = set_DvRegOstIDDOG_RGPAYSALE_DV};
   virtual TFIBBCDField * get_DvRegOstIDDOG_RGPAYSALE_DV(void)=0;
   virtual void set_DvRegOstIDDOG_RGPAYSALE_DV(TFIBBCDField * DvRegOstIDDOG_RGPAYSALE_DV)=0;

   __property TFIBBCDField * DvRegOstIDDOCSALE_RGPAYSALE_DV = {read = get_DvRegOstIDDOCSALE_RGPAYSALE_DV , write = set_DvRegOstIDDOCSALE_RGPAYSALE_DV};
   virtual TFIBBCDField * get_DvRegOstIDDOCSALE_RGPAYSALE_DV(void)=0;
   virtual void set_DvRegOstIDDOCSALE_RGPAYSALE_DV(TFIBBCDField * DvRegOstIDDOCSALE_RGPAYSALE_DV)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property TDateTime PosDoc = {read = get_PosDoc , write = set_PosDoc};
   virtual TDateTime get_PosDoc(void)=0;
   virtual void set_PosDoc(TDateTime PosDoc)=0;

   __property __int64 IdFirm = {read = get_IdFirm , write = set_IdFirm};
   virtual __int64 get_IdFirm(void)=0;
   virtual void set_IdFirm(__int64 IdFirm)=0;

   __property __int64 IdKlient = {read = get_IdKlient , write = set_IdKlient};
   virtual __int64 get_IdKlient(void)=0;
   virtual void set_IdKlient(__int64 IdKlient)=0;

   __property __int64 IdDogovor = {read = get_IdDogovor , write = set_IdDogovor};
   virtual __int64 get_IdDogovor(void)=0;
   virtual void set_IdDogovor(__int64 IdDogovor)=0;

   __property __int64 IdDocSale = {read = get_IdDocSale , write = set_IdDocSale};
   virtual __int64 get_IdDocSale(void)=0;
   virtual void set_IdDocSale(__int64 IdDocSale)=0;

   __property TDate DatePay = {read = get_DatePay , write = set_DatePay};
   virtual TDate get_DatePay(void)=0;
   virtual void set_DatePay(TDate DatePay)=0;

   __property float Sum = {read = get_Sum , write = set_Sum};
   virtual float get_Sum(void)=0;
   virtual void set_Sum(float Sum)=0;

   virtual bool AddRecordPrihod(void)=0;
   virtual bool AddRecordRashod(void)=0;
   virtual bool UpdateTableOst(void)=0;
   virtual bool CancelDvReg(void)=0;
};
#define IID_IDMRegPaySale __uuidof(IDMRegPaySale)
#endif
