#ifndef UIDMRegVsRaschH
#define UIDMRegVsRaschH
#include "IMainInterface.h"
class IDMRegVsRasch : public IMainInterface
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

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TFIBDateTimeField * DvRegOstPOSDOC_VSRASCH_DV = {read = get_DvRegOstPOSDOC_VSRASCH_DV , write = set_DvRegOstPOSDOC_VSRASCH_DV};
   virtual TFIBDateTimeField * get_DvRegOstPOSDOC_VSRASCH_DV(void)=0;
   virtual void set_DvRegOstPOSDOC_VSRASCH_DV(TFIBDateTimeField * DvRegOstPOSDOC_VSRASCH_DV)=0;

   __property TFIBSmallIntField * DvRegOstTDV_VSRASCH_DV = {read = get_DvRegOstTDV_VSRASCH_DV , write = set_DvRegOstTDV_VSRASCH_DV};
   virtual TFIBSmallIntField * get_DvRegOstTDV_VSRASCH_DV(void)=0;
   virtual void set_DvRegOstTDV_VSRASCH_DV(TFIBSmallIntField * DvRegOstTDV_VSRASCH_DV)=0;

   __property TFIBBCDField * DvRegOstSUM_VSRASCH_DV = {read = get_DvRegOstSUM_VSRASCH_DV , write = set_DvRegOstSUM_VSRASCH_DV};
   virtual TFIBBCDField * get_DvRegOstSUM_VSRASCH_DV(void)=0;
   virtual void set_DvRegOstSUM_VSRASCH_DV(TFIBBCDField * DvRegOstSUM_VSRASCH_DV)=0;

   __property TFIBBCDField * RegOstSUM_VSRASCH = {read = get_RegOstSUM_VSRASCH , write = set_RegOstSUM_VSRASCH};
   virtual TFIBBCDField * get_RegOstSUM_VSRASCH(void)=0;
   virtual void set_RegOstSUM_VSRASCH(TFIBBCDField * RegOstSUM_VSRASCH)=0;

   __property TFIBBCDField * DvSUMDV = {read = get_DvSUMDV , write = set_DvSUMDV};
   virtual TFIBBCDField * get_DvSUMDV(void)=0;
   virtual void set_DvSUMDV(TFIBBCDField * DvSUMDV)=0;

   __property TFIBBCDField * OstatokSUMOST = {read = get_OstatokSUMOST , write = set_OstatokSUMOST};
   virtual TFIBBCDField * get_OstatokSUMOST(void)=0;
   virtual void set_OstatokSUMOST(TFIBBCDField * OstatokSUMOST)=0;

   __property TFIBBCDField * RegOstID_VSRASCH = {read = get_RegOstID_VSRASCH , write = set_RegOstID_VSRASCH};
   virtual TFIBBCDField * get_RegOstID_VSRASCH(void)=0;
   virtual void set_RegOstID_VSRASCH(TFIBBCDField * RegOstID_VSRASCH)=0;

   __property TFIBBCDField * RegOstIDFIRM_VSRASCH = {read = get_RegOstIDFIRM_VSRASCH , write = set_RegOstIDFIRM_VSRASCH};
   virtual TFIBBCDField * get_RegOstIDFIRM_VSRASCH(void)=0;
   virtual void set_RegOstIDFIRM_VSRASCH(TFIBBCDField * RegOstIDFIRM_VSRASCH)=0;

   __property TFIBBCDField * RegOstIDKLIENT_VSRASCH = {read = get_RegOstIDKLIENT_VSRASCH , write = set_RegOstIDKLIENT_VSRASCH};
   virtual TFIBBCDField * get_RegOstIDKLIENT_VSRASCH(void)=0;
   virtual void set_RegOstIDKLIENT_VSRASCH(TFIBBCDField * RegOstIDKLIENT_VSRASCH)=0;

   __property TFIBBCDField * RegOstIDDOG_VSRASCH = {read = get_RegOstIDDOG_VSRASCH , write = set_RegOstIDDOG_VSRASCH};
   virtual TFIBBCDField * get_RegOstIDDOG_VSRASCH(void)=0;
   virtual void set_RegOstIDDOG_VSRASCH(TFIBBCDField * RegOstIDDOG_VSRASCH)=0;

   __property TFIBBCDField * DvRegOstID_VSRASCH_DV = {read = get_DvRegOstID_VSRASCH_DV , write = set_DvRegOstID_VSRASCH_DV};
   virtual TFIBBCDField * get_DvRegOstID_VSRASCH_DV(void)=0;
   virtual void set_DvRegOstID_VSRASCH_DV(TFIBBCDField * DvRegOstID_VSRASCH_DV)=0;

   __property TFIBBCDField * DvRegOstIDDOC_VSRASCH_DV = {read = get_DvRegOstIDDOC_VSRASCH_DV , write = set_DvRegOstIDDOC_VSRASCH_DV};
   virtual TFIBBCDField * get_DvRegOstIDDOC_VSRASCH_DV(void)=0;
   virtual void set_DvRegOstIDDOC_VSRASCH_DV(TFIBBCDField * DvRegOstIDDOC_VSRASCH_DV)=0;

   __property TFIBBCDField * DvRegOstIDFIRM_VSRASCH_DV = {read = get_DvRegOstIDFIRM_VSRASCH_DV , write = set_DvRegOstIDFIRM_VSRASCH_DV};
   virtual TFIBBCDField * get_DvRegOstIDFIRM_VSRASCH_DV(void)=0;
   virtual void set_DvRegOstIDFIRM_VSRASCH_DV(TFIBBCDField * DvRegOstIDFIRM_VSRASCH_DV)=0;

   __property TFIBBCDField * DvRegOstIDKLIENT_VSRASCH_DV = {read = get_DvRegOstIDKLIENT_VSRASCH_DV , write = set_DvRegOstIDKLIENT_VSRASCH_DV};
   virtual TFIBBCDField * get_DvRegOstIDKLIENT_VSRASCH_DV(void)=0;
   virtual void set_DvRegOstIDKLIENT_VSRASCH_DV(TFIBBCDField * DvRegOstIDKLIENT_VSRASCH_DV)=0;

   __property TFIBBCDField * DvRegOstIDDOG_VSRASCH_DV = {read = get_DvRegOstIDDOG_VSRASCH_DV , write = set_DvRegOstIDDOG_VSRASCH_DV};
   virtual TFIBBCDField * get_DvRegOstIDDOG_VSRASCH_DV(void)=0;
   virtual void set_DvRegOstIDDOG_VSRASCH_DV(TFIBBCDField * DvRegOstIDDOG_VSRASCH_DV)=0;

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

   __property float SumOstNa = {read = get_SumOstNa , write = set_SumOstNa};
   virtual float get_SumOstNa(void)=0;
   virtual void set_SumOstNa(float SumOstNa)=0;

   virtual int GetOstatok(void)=0;
   virtual bool AddRecordPrihod(void)=0;
   virtual bool AddRecordRashod(void)=0;
   virtual bool UpdateTableOst(bool provedenie)=0;
   virtual bool CancelDvReg(void)=0;
   virtual bool GetOstatokNa(TDateTime Pos, __int64 idFirm,__int64 idKlient)=0;
};
#define IID_IDMRegVsRasch __uuidof(IDMRegVsRasch)
#endif
