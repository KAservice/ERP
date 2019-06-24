#ifndef UIDMRegAdvanceCustomerH
#define UIDMRegAdvanceCustomerH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{7F398CB6-C3ED-4327-844C-30D7230EDF65}")) IDMRegAdvanceCustomer : public IMainInterface
{
public:
   __property TpFIBDataSet * DvRegOst = {read = get_DvRegOst , write = set_DvRegOst};
   virtual TpFIBDataSet * get_DvRegOst(void)=0;
   virtual void set_DvRegOst(TpFIBDataSet * DvRegOst)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TpFIBDataSet * RegOst = {read = get_RegOst , write = set_RegOst};
   virtual TpFIBDataSet * get_RegOst(void)=0;
   virtual void set_RegOst(TpFIBDataSet * RegOst)=0;

   __property TFIBDateTimeField * DvRegOstPOS_RGADVCUST_DV = {read = get_DvRegOstPOS_RGADVCUST_DV , write = set_DvRegOstPOS_RGADVCUST_DV};
   virtual TFIBDateTimeField * get_DvRegOstPOS_RGADVCUST_DV(void)=0;
   virtual void set_DvRegOstPOS_RGADVCUST_DV(TFIBDateTimeField * DvRegOstPOS_RGADVCUST_DV)=0;

   __property TFIBIntegerField * DvRegOstTDV_RGADVCUST_DV = {read = get_DvRegOstTDV_RGADVCUST_DV , write = set_DvRegOstTDV_RGADVCUST_DV};
   virtual TFIBIntegerField * get_DvRegOstTDV_RGADVCUST_DV(void)=0;
   virtual void set_DvRegOstTDV_RGADVCUST_DV(TFIBIntegerField * DvRegOstTDV_RGADVCUST_DV)=0;

   __property TFIBBCDField * DvRegOstSUM_RGADVCUST_DV = {read = get_DvRegOstSUM_RGADVCUST_DV , write = set_DvRegOstSUM_RGADVCUST_DV};
   virtual TFIBBCDField * get_DvRegOstSUM_RGADVCUST_DV(void)=0;
   virtual void set_DvRegOstSUM_RGADVCUST_DV(TFIBBCDField * DvRegOstSUM_RGADVCUST_DV)=0;

   __property TFIBBCDField * RegOstSUM_RGADVCUST = {read = get_RegOstSUM_RGADVCUST , write = set_RegOstSUM_RGADVCUST};
   virtual TFIBBCDField * get_RegOstSUM_RGADVCUST(void)=0;
   virtual void set_RegOstSUM_RGADVCUST(TFIBBCDField * RegOstSUM_RGADVCUST)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TFIBBCDField * DvRegOstID_RGADVCUST_DV = {read = get_DvRegOstID_RGADVCUST_DV , write = set_DvRegOstID_RGADVCUST_DV};
   virtual TFIBBCDField * get_DvRegOstID_RGADVCUST_DV(void)=0;
   virtual void set_DvRegOstID_RGADVCUST_DV(TFIBBCDField * DvRegOstID_RGADVCUST_DV)=0;

   __property TFIBBCDField * DvRegOstIDDOC_RGADVCUST_DV = {read = get_DvRegOstIDDOC_RGADVCUST_DV , write = set_DvRegOstIDDOC_RGADVCUST_DV};
   virtual TFIBBCDField * get_DvRegOstIDDOC_RGADVCUST_DV(void)=0;
   virtual void set_DvRegOstIDDOC_RGADVCUST_DV(TFIBBCDField * DvRegOstIDDOC_RGADVCUST_DV)=0;

   __property TFIBBCDField * DvRegOstIDFIRM_RGADVCUST_DV = {read = get_DvRegOstIDFIRM_RGADVCUST_DV , write = set_DvRegOstIDFIRM_RGADVCUST_DV};
   virtual TFIBBCDField * get_DvRegOstIDFIRM_RGADVCUST_DV(void)=0;
   virtual void set_DvRegOstIDFIRM_RGADVCUST_DV(TFIBBCDField * DvRegOstIDFIRM_RGADVCUST_DV)=0;

   __property TFIBBCDField * DvRegOstIDKLIENT_RGADVCUST_DV = {read = get_DvRegOstIDKLIENT_RGADVCUST_DV , write = set_DvRegOstIDKLIENT_RGADVCUST_DV};
   virtual TFIBBCDField * get_DvRegOstIDKLIENT_RGADVCUST_DV(void)=0;
   virtual void set_DvRegOstIDKLIENT_RGADVCUST_DV(TFIBBCDField * DvRegOstIDKLIENT_RGADVCUST_DV)=0;

   __property TFIBBCDField * RegOstID_RGADVCUST = {read = get_RegOstID_RGADVCUST , write = set_RegOstID_RGADVCUST};
   virtual TFIBBCDField * get_RegOstID_RGADVCUST(void)=0;
   virtual void set_RegOstID_RGADVCUST(TFIBBCDField * RegOstID_RGADVCUST)=0;

   __property TFIBBCDField * RegOstIDFIRM_RGADVCUST = {read = get_RegOstIDFIRM_RGADVCUST , write = set_RegOstIDFIRM_RGADVCUST};
   virtual TFIBBCDField * get_RegOstIDFIRM_RGADVCUST(void)=0;
   virtual void set_RegOstIDFIRM_RGADVCUST(TFIBBCDField * RegOstIDFIRM_RGADVCUST)=0;

   __property TFIBBCDField * RegOstIDKLIENT_RGADVCUST = {read = get_RegOstIDKLIENT_RGADVCUST , write = set_RegOstIDKLIENT_RGADVCUST};
   virtual TFIBBCDField * get_RegOstIDKLIENT_RGADVCUST(void)=0;
   virtual void set_RegOstIDKLIENT_RGADVCUST(TFIBBCDField * RegOstIDKLIENT_RGADVCUST)=0;

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

   __property float Sum = {read = get_Sum , write = set_Sum};
   virtual float get_Sum(void)=0;
   virtual void set_Sum(float Sum)=0;

   virtual bool AddRecordPrihod(void)=0;
   virtual bool AddRecordRashod(void)=0;
   virtual bool UpdateTableOst(void)=0;
   virtual bool CancelDvReg(void)=0;
   virtual double GetOstatokAdvance(__int64 id_firm, __int64 id_klient)=0;
};
#define IID_IDMRegAdvanceCustomer __uuidof(IDMRegAdvanceCustomer)
#endif
