#ifndef UIDMRegBankH
#define UIDMRegBankH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{D746C5D8-02FE-4AF7-B232-EC6BAF994DD5}")) IDMRegBank : public IMainInterface
{
public:
   __property TpFIBDataSet * DvRegOst = {read = get_DvRegOst , write = set_DvRegOst};
   virtual TpFIBDataSet * get_DvRegOst(void)=0;
   virtual void set_DvRegOst(TpFIBDataSet * DvRegOst)=0;

   __property TpFIBDataSet * RegOst = {read = get_RegOst , write = set_RegOst};
   virtual TpFIBDataSet * get_RegOst(void)=0;
   virtual void set_RegOst(TpFIBDataSet * RegOst)=0;

   __property TpFIBDataSet * Dv = {read = get_Dv , write = set_Dv};
   virtual TpFIBDataSet * get_Dv(void)=0;
   virtual void set_Dv(TpFIBDataSet * Dv)=0;

   __property TpFIBDataSet * Ostatok = {read = get_Ostatok , write = set_Ostatok};
   virtual TpFIBDataSet * get_Ostatok(void)=0;
   virtual void set_Ostatok(TpFIBDataSet * Ostatok)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TFIBDateTimeField * DvRegOstPOSDOC_RGBANK_DV = {read = get_DvRegOstPOSDOC_RGBANK_DV , write = set_DvRegOstPOSDOC_RGBANK_DV};
   virtual TFIBDateTimeField * get_DvRegOstPOSDOC_RGBANK_DV(void)=0;
   virtual void set_DvRegOstPOSDOC_RGBANK_DV(TFIBDateTimeField * DvRegOstPOSDOC_RGBANK_DV)=0;

   __property TFIBSmallIntField * DvRegOstTDV_RGBANK_DV = {read = get_DvRegOstTDV_RGBANK_DV , write = set_DvRegOstTDV_RGBANK_DV};
   virtual TFIBSmallIntField * get_DvRegOstTDV_RGBANK_DV(void)=0;
   virtual void set_DvRegOstTDV_RGBANK_DV(TFIBSmallIntField * DvRegOstTDV_RGBANK_DV)=0;

   __property TFIBBCDField * DvRegOstSUM_RGBANK_DV = {read = get_DvRegOstSUM_RGBANK_DV , write = set_DvRegOstSUM_RGBANK_DV};
   virtual TFIBBCDField * get_DvRegOstSUM_RGBANK_DV(void)=0;
   virtual void set_DvRegOstSUM_RGBANK_DV(TFIBBCDField * DvRegOstSUM_RGBANK_DV)=0;

   __property TFIBIntegerField * DvRegOstOPER_RGBANK_DV = {read = get_DvRegOstOPER_RGBANK_DV , write = set_DvRegOstOPER_RGBANK_DV};
   virtual TFIBIntegerField * get_DvRegOstOPER_RGBANK_DV(void)=0;
   virtual void set_DvRegOstOPER_RGBANK_DV(TFIBIntegerField * DvRegOstOPER_RGBANK_DV)=0;

   __property TFIBBCDField * RegOstSUM_RGBANK = {read = get_RegOstSUM_RGBANK , write = set_RegOstSUM_RGBANK};
   virtual TFIBBCDField * get_RegOstSUM_RGBANK(void)=0;
   virtual void set_RegOstSUM_RGBANK(TFIBBCDField * RegOstSUM_RGBANK)=0;

   __property TFIBBCDField * DvSUMDV = {read = get_DvSUMDV , write = set_DvSUMDV};
   virtual TFIBBCDField * get_DvSUMDV(void)=0;
   virtual void set_DvSUMDV(TFIBBCDField * DvSUMDV)=0;

   __property TFIBBCDField * OstatokSUMOST = {read = get_OstatokSUMOST , write = set_OstatokSUMOST};
   virtual TFIBBCDField * get_OstatokSUMOST(void)=0;
   virtual void set_OstatokSUMOST(TFIBBCDField * OstatokSUMOST)=0;

   __property TFIBBCDField * RegOstID_RGBANK = {read = get_RegOstID_RGBANK , write = set_RegOstID_RGBANK};
   virtual TFIBBCDField * get_RegOstID_RGBANK(void)=0;
   virtual void set_RegOstID_RGBANK(TFIBBCDField * RegOstID_RGBANK)=0;

   __property TFIBBCDField * RegOstIDFIRM_RGBANK = {read = get_RegOstIDFIRM_RGBANK , write = set_RegOstIDFIRM_RGBANK};
   virtual TFIBBCDField * get_RegOstIDFIRM_RGBANK(void)=0;
   virtual void set_RegOstIDFIRM_RGBANK(TFIBBCDField * RegOstIDFIRM_RGBANK)=0;

   __property TFIBBCDField * RegOstIDBSCHET_RGBANK = {read = get_RegOstIDBSCHET_RGBANK , write = set_RegOstIDBSCHET_RGBANK};
   virtual TFIBBCDField * get_RegOstIDBSCHET_RGBANK(void)=0;
   virtual void set_RegOstIDBSCHET_RGBANK(TFIBBCDField * RegOstIDBSCHET_RGBANK)=0;

   __property TFIBBCDField * DvRegOstID_RGBANK_DV = {read = get_DvRegOstID_RGBANK_DV , write = set_DvRegOstID_RGBANK_DV};
   virtual TFIBBCDField * get_DvRegOstID_RGBANK_DV(void)=0;
   virtual void set_DvRegOstID_RGBANK_DV(TFIBBCDField * DvRegOstID_RGBANK_DV)=0;

   __property TFIBBCDField * DvRegOstIDDOC_RGBANK_DV = {read = get_DvRegOstIDDOC_RGBANK_DV , write = set_DvRegOstIDDOC_RGBANK_DV};
   virtual TFIBBCDField * get_DvRegOstIDDOC_RGBANK_DV(void)=0;
   virtual void set_DvRegOstIDDOC_RGBANK_DV(TFIBBCDField * DvRegOstIDDOC_RGBANK_DV)=0;

   __property TFIBBCDField * DvRegOstIDFIRM_RGBANK_DV = {read = get_DvRegOstIDFIRM_RGBANK_DV , write = set_DvRegOstIDFIRM_RGBANK_DV};
   virtual TFIBBCDField * get_DvRegOstIDFIRM_RGBANK_DV(void)=0;
   virtual void set_DvRegOstIDFIRM_RGBANK_DV(TFIBBCDField * DvRegOstIDFIRM_RGBANK_DV)=0;

   __property TFIBBCDField * DvRegOstIDBSCHET_RGBANK_DV = {read = get_DvRegOstIDBSCHET_RGBANK_DV , write = set_DvRegOstIDBSCHET_RGBANK_DV};
   virtual TFIBBCDField * get_DvRegOstIDBSCHET_RGBANK_DV(void)=0;
   virtual void set_DvRegOstIDBSCHET_RGBANK_DV(TFIBBCDField * DvRegOstIDBSCHET_RGBANK_DV)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property TDateTime PosDoc = {read = get_PosDoc , write = set_PosDoc};
   virtual TDateTime get_PosDoc(void)=0;
   virtual void set_PosDoc(TDateTime PosDoc)=0;

   __property __int64 IdFirm = {read = get_IdFirm , write = set_IdFirm};
   virtual __int64 get_IdFirm(void)=0;
   virtual void set_IdFirm(__int64 IdFirm)=0;

   __property __int64 IdBSchet = {read = get_IdBSchet , write = set_IdBSchet};
   virtual __int64 get_IdBSchet(void)=0;
   virtual void set_IdBSchet(__int64 IdBSchet)=0;

   __property float Sum = {read = get_Sum , write = set_Sum};
   virtual float get_Sum(void)=0;
   virtual void set_Sum(float Sum)=0;

   __property int Operation = {read = get_Operation , write = set_Operation};
   virtual int get_Operation(void)=0;
   virtual void set_Operation(int Operation)=0;

   __property double SumOstNa = {read = get_SumOstNa , write = set_SumOstNa};
   virtual double get_SumOstNa(void)=0;
   virtual void set_SumOstNa(double SumOstNa)=0;

   virtual int GetOstatok(void)=0;
   virtual bool AddRecordPrihod(void)=0;
   virtual bool AddRecordRashod(void)=0;
   virtual bool UpdateTableOst(void)=0;
   virtual bool CancelDvReg(void)=0;
   virtual bool GetOstatokNa(TDateTime Pos, __int64 id_firm, __int64 id_bschet)=0;
};
#define IID_IDMRegBank __uuidof(IDMRegBank)
#endif
