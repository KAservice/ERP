#ifndef UIDMRegOstNomH
#define UIDMRegOstNomH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{CBFFB1D7-A6D3-42BD-8F70-4DDC14CD04E8}")) IDMRegOstNom : public IMainInterface
{
public:
   __property TpFIBDataSet * DvRegOst = {read = get_DvRegOst , write = set_DvRegOst};
   virtual TpFIBDataSet * get_DvRegOst(void)=0;
   virtual void set_DvRegOst(TpFIBDataSet * DvRegOst)=0;

   __property TpFIBDataSet * RegOst = {read = get_RegOst , write = set_RegOst};
   virtual TpFIBDataSet * get_RegOst(void)=0;
   virtual void set_RegOst(TpFIBDataSet * RegOst)=0;

   __property TpFIBDataSet * DvNom = {read = get_DvNom , write = set_DvNom};
   virtual TpFIBDataSet * get_DvNom(void)=0;
   virtual void set_DvNom(TpFIBDataSet * DvNom)=0;

   __property TpFIBDataSet * Ostatok = {read = get_Ostatok , write = set_Ostatok};
   virtual TpFIBDataSet * get_Ostatok(void)=0;
   virtual void set_Ostatok(TpFIBDataSet * Ostatok)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TFIBDateTimeField * DvRegOstPOSDOC_OSTNOMDV = {read = get_DvRegOstPOSDOC_OSTNOMDV , write = set_DvRegOstPOSDOC_OSTNOMDV};
   virtual TFIBDateTimeField * get_DvRegOstPOSDOC_OSTNOMDV(void)=0;
   virtual void set_DvRegOstPOSDOC_OSTNOMDV(TFIBDateTimeField * DvRegOstPOSDOC_OSTNOMDV)=0;

   __property TFIBSmallIntField * DvRegOstTDV_OSTNOMDV = {read = get_DvRegOstTDV_OSTNOMDV , write = set_DvRegOstTDV_OSTNOMDV};
   virtual TFIBSmallIntField * get_DvRegOstTDV_OSTNOMDV(void)=0;
   virtual void set_DvRegOstTDV_OSTNOMDV(TFIBSmallIntField * DvRegOstTDV_OSTNOMDV)=0;

   __property TFIBBCDField * DvRegOstSUM_OSTNOMDV = {read = get_DvRegOstSUM_OSTNOMDV , write = set_DvRegOstSUM_OSTNOMDV};
   virtual TFIBBCDField * get_DvRegOstSUM_OSTNOMDV(void)=0;
   virtual void set_DvRegOstSUM_OSTNOMDV(TFIBBCDField * DvRegOstSUM_OSTNOMDV)=0;

   __property TFIBBCDField * DvRegOstKOL_OSTNOMDV = {read = get_DvRegOstKOL_OSTNOMDV , write = set_DvRegOstKOL_OSTNOMDV};
   virtual TFIBBCDField * get_DvRegOstKOL_OSTNOMDV(void)=0;
   virtual void set_DvRegOstKOL_OSTNOMDV(TFIBBCDField * DvRegOstKOL_OSTNOMDV)=0;

   __property TFIBIntegerField * DvRegOstOPER_OSTNOMDV = {read = get_DvRegOstOPER_OSTNOMDV , write = set_DvRegOstOPER_OSTNOMDV};
   virtual TFIBIntegerField * get_DvRegOstOPER_OSTNOMDV(void)=0;
   virtual void set_DvRegOstOPER_OSTNOMDV(TFIBIntegerField * DvRegOstOPER_OSTNOMDV)=0;

   __property TFIBBCDField * DvRegOstSUM2_OSTNOMDV = {read = get_DvRegOstSUM2_OSTNOMDV , write = set_DvRegOstSUM2_OSTNOMDV};
   virtual TFIBBCDField * get_DvRegOstSUM2_OSTNOMDV(void)=0;
   virtual void set_DvRegOstSUM2_OSTNOMDV(TFIBBCDField * DvRegOstSUM2_OSTNOMDV)=0;

   __property TFIBBCDField * RegOstSUMOSTNOM = {read = get_RegOstSUMOSTNOM , write = set_RegOstSUMOSTNOM};
   virtual TFIBBCDField * get_RegOstSUMOSTNOM(void)=0;
   virtual void set_RegOstSUMOSTNOM(TFIBBCDField * RegOstSUMOSTNOM)=0;

   __property TFIBBCDField * RegOstKOLOSTNOM = {read = get_RegOstKOLOSTNOM , write = set_RegOstKOLOSTNOM};
   virtual TFIBBCDField * get_RegOstKOLOSTNOM(void)=0;
   virtual void set_RegOstKOLOSTNOM(TFIBBCDField * RegOstKOLOSTNOM)=0;

   __property TFIBBCDField * DvNomKOLDV = {read = get_DvNomKOLDV , write = set_DvNomKOLDV};
   virtual TFIBBCDField * get_DvNomKOLDV(void)=0;
   virtual void set_DvNomKOLDV(TFIBBCDField * DvNomKOLDV)=0;

   __property TFIBBCDField * DvNomSUMDV = {read = get_DvNomSUMDV , write = set_DvNomSUMDV};
   virtual TFIBBCDField * get_DvNomSUMDV(void)=0;
   virtual void set_DvNomSUMDV(TFIBBCDField * DvNomSUMDV)=0;

   __property TFIBBCDField * OstatokKOLOST = {read = get_OstatokKOLOST , write = set_OstatokKOLOST};
   virtual TFIBBCDField * get_OstatokKOLOST(void)=0;
   virtual void set_OstatokKOLOST(TFIBBCDField * OstatokKOLOST)=0;

   __property TFIBBCDField * OstatokSUMOST = {read = get_OstatokSUMOST , write = set_OstatokSUMOST};
   virtual TFIBBCDField * get_OstatokSUMOST(void)=0;
   virtual void set_OstatokSUMOST(TFIBBCDField * OstatokSUMOST)=0;

   __property TFIBBCDField * RegOstIDOSTNOM = {read = get_RegOstIDOSTNOM , write = set_RegOstIDOSTNOM};
   virtual TFIBBCDField * get_RegOstIDOSTNOM(void)=0;
   virtual void set_RegOstIDOSTNOM(TFIBBCDField * RegOstIDOSTNOM)=0;

   __property TFIBBCDField * RegOstIDFIRMOSTNOM = {read = get_RegOstIDFIRMOSTNOM , write = set_RegOstIDFIRMOSTNOM};
   virtual TFIBBCDField * get_RegOstIDFIRMOSTNOM(void)=0;
   virtual void set_RegOstIDFIRMOSTNOM(TFIBBCDField * RegOstIDFIRMOSTNOM)=0;

   __property TFIBBCDField * RegOstIDSKLOSTNOM = {read = get_RegOstIDSKLOSTNOM , write = set_RegOstIDSKLOSTNOM};
   virtual TFIBBCDField * get_RegOstIDSKLOSTNOM(void)=0;
   virtual void set_RegOstIDSKLOSTNOM(TFIBBCDField * RegOstIDSKLOSTNOM)=0;

   __property TFIBBCDField * RegOstIDNOMOSTNOM = {read = get_RegOstIDNOMOSTNOM , write = set_RegOstIDNOMOSTNOM};
   virtual TFIBBCDField * get_RegOstIDNOMOSTNOM(void)=0;
   virtual void set_RegOstIDNOMOSTNOM(TFIBBCDField * RegOstIDNOMOSTNOM)=0;

   __property TFIBBCDField * RegOstIDPARTOSTNOM = {read = get_RegOstIDPARTOSTNOM , write = set_RegOstIDPARTOSTNOM};
   virtual TFIBBCDField * get_RegOstIDPARTOSTNOM(void)=0;
   virtual void set_RegOstIDPARTOSTNOM(TFIBBCDField * RegOstIDPARTOSTNOM)=0;

   __property TFIBBCDField * DvRegOstID_OSTNOMDV = {read = get_DvRegOstID_OSTNOMDV , write = set_DvRegOstID_OSTNOMDV};
   virtual TFIBBCDField * get_DvRegOstID_OSTNOMDV(void)=0;
   virtual void set_DvRegOstID_OSTNOMDV(TFIBBCDField * DvRegOstID_OSTNOMDV)=0;

   __property TFIBBCDField * DvRegOstIDDOC_OSTNOMDV = {read = get_DvRegOstIDDOC_OSTNOMDV , write = set_DvRegOstIDDOC_OSTNOMDV};
   virtual TFIBBCDField * get_DvRegOstIDDOC_OSTNOMDV(void)=0;
   virtual void set_DvRegOstIDDOC_OSTNOMDV(TFIBBCDField * DvRegOstIDDOC_OSTNOMDV)=0;

   __property TFIBBCDField * DvRegOstIDFIRM_OSTNOMDV = {read = get_DvRegOstIDFIRM_OSTNOMDV , write = set_DvRegOstIDFIRM_OSTNOMDV};
   virtual TFIBBCDField * get_DvRegOstIDFIRM_OSTNOMDV(void)=0;
   virtual void set_DvRegOstIDFIRM_OSTNOMDV(TFIBBCDField * DvRegOstIDFIRM_OSTNOMDV)=0;

   __property TFIBBCDField * DvRegOstIDSKL_OSTNOMDV = {read = get_DvRegOstIDSKL_OSTNOMDV , write = set_DvRegOstIDSKL_OSTNOMDV};
   virtual TFIBBCDField * get_DvRegOstIDSKL_OSTNOMDV(void)=0;
   virtual void set_DvRegOstIDSKL_OSTNOMDV(TFIBBCDField * DvRegOstIDSKL_OSTNOMDV)=0;

   __property TFIBBCDField * DvRegOstIDNOM_OSTNOMDV = {read = get_DvRegOstIDNOM_OSTNOMDV , write = set_DvRegOstIDNOM_OSTNOMDV};
   virtual TFIBBCDField * get_DvRegOstIDNOM_OSTNOMDV(void)=0;
   virtual void set_DvRegOstIDNOM_OSTNOMDV(TFIBBCDField * DvRegOstIDNOM_OSTNOMDV)=0;

   __property TFIBBCDField * DvRegOstIDPART_OSTNOMDV = {read = get_DvRegOstIDPART_OSTNOMDV , write = set_DvRegOstIDPART_OSTNOMDV};
   virtual TFIBBCDField * get_DvRegOstIDPART_OSTNOMDV(void)=0;
   virtual void set_DvRegOstIDPART_OSTNOMDV(TFIBBCDField * DvRegOstIDPART_OSTNOMDV)=0;

   __property TFIBBCDField * DvRegOstIDSTRDOC_OSTNOMDV = {read = get_DvRegOstIDSTRDOC_OSTNOMDV , write = set_DvRegOstIDSTRDOC_OSTNOMDV};
   virtual TFIBBCDField * get_DvRegOstIDSTRDOC_OSTNOMDV(void)=0;
   virtual void set_DvRegOstIDSTRDOC_OSTNOMDV(TFIBBCDField * DvRegOstIDSTRDOC_OSTNOMDV)=0;

   __property __int64 IdFirm = {read = get_IdFirm , write = set_IdFirm};
   virtual __int64 get_IdFirm(void)=0;
   virtual void set_IdFirm(__int64 IdFirm)=0;

   __property __int64 IdSklad = {read = get_IdSklad , write = set_IdSklad};
   virtual __int64 get_IdSklad(void)=0;
   virtual void set_IdSklad(__int64 IdSklad)=0;

   __property __int64 IdNom = {read = get_IdNom , write = set_IdNom};
   virtual __int64 get_IdNom(void)=0;
   virtual void set_IdNom(__int64 IdNom)=0;

   __property float SumOst = {read = get_SumOst , write = set_SumOst};
   virtual float get_SumOst(void)=0;
   virtual void set_SumOst(float SumOst)=0;

   __property float KolOst = {read = get_KolOst , write = set_KolOst};
   virtual float get_KolOst(void)=0;
   virtual void set_KolOst(float KolOst)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property TDateTime PosDoc = {read = get_PosDoc , write = set_PosDoc};
   virtual TDateTime get_PosDoc(void)=0;
   virtual void set_PosDoc(TDateTime PosDoc)=0;

   __property __int64 IdPart = {read = get_IdPart , write = set_IdPart};
   virtual __int64 get_IdPart(void)=0;
   virtual void set_IdPart(__int64 IdPart)=0;

   __property __int64 IdStr = {read = get_IdStr , write = set_IdStr};
   virtual __int64 get_IdStr(void)=0;
   virtual void set_IdStr(__int64 IdStr)=0;

   __property float Kol = {read = get_Kol , write = set_Kol};
   virtual float get_Kol(void)=0;
   virtual void set_Kol(float Kol)=0;

   __property float Sum = {read = get_Sum , write = set_Sum};
   virtual float get_Sum(void)=0;
   virtual void set_Sum(float Sum)=0;

   __property int Operation = {read = get_Operation , write = set_Operation};
   virtual int get_Operation(void)=0;
   virtual void set_Operation(int Operation)=0;

   __property float Sum2 = {read = get_Sum2 , write = set_Sum2};
   virtual float get_Sum2(void)=0;
   virtual void set_Sum2(float Sum2)=0;

   __property float SumOstNa = {read = get_SumOstNa , write = set_SumOstNa};
   virtual float get_SumOstNa(void)=0;
   virtual void set_SumOstNa(float SumOstNa)=0;

   __property float KolOstNa = {read = get_KolOstNa , write = set_KolOstNa};
   virtual float get_KolOstNa(void)=0;
   virtual void set_KolOstNa(float KolOstNa)=0;

   virtual int GetOstatok(void)=0;
   virtual bool AddRecordPrihod(void)=0;
   virtual bool AddRecordRashod(void)=0;
   virtual bool UpdateTableOst(void)=0;
   virtual bool CancelDvReg(void)=0;
   virtual bool GetOstatokNa(TDateTime Pos, __int64 idFirm, __int64 idSklad, __int64 idNom)=0;
};
#define IID_IDMRegOstNom __uuidof(IDMRegOstNom)
#endif
