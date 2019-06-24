#ifndef UIDMRegGoodsH
#define UIDMRegGoodsH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>
class __declspec(uuid("{08009062-8436-4A14-954D-3D723F09DD53}"))IDMRegGoods : public IMainInterface
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

   __property TFIBDateTimeField * DvRegOstPOSDOC_RGGOODS_DV = {read = get_DvRegOstPOSDOC_RGGOODS_DV , write = set_DvRegOstPOSDOC_RGGOODS_DV};
   virtual TFIBDateTimeField * get_DvRegOstPOSDOC_RGGOODS_DV(void)=0;
   virtual void set_DvRegOstPOSDOC_RGGOODS_DV(TFIBDateTimeField * DvRegOstPOSDOC_RGGOODS_DV)=0;

   __property TFIBSmallIntField * DvRegOstTDV_RGGOODS_DV = {read = get_DvRegOstTDV_RGGOODS_DV , write = set_DvRegOstTDV_RGGOODS_DV};
   virtual TFIBSmallIntField * get_DvRegOstTDV_RGGOODS_DV(void)=0;
   virtual void set_DvRegOstTDV_RGGOODS_DV(TFIBSmallIntField * DvRegOstTDV_RGGOODS_DV)=0;

   __property TFIBBCDField * DvRegOstRPRICE_RGGOODS_DV = {read = get_DvRegOstRPRICE_RGGOODS_DV , write = set_DvRegOstRPRICE_RGGOODS_DV};
   virtual TFIBBCDField * get_DvRegOstRPRICE_RGGOODS_DV(void)=0;
   virtual void set_DvRegOstRPRICE_RGGOODS_DV(TFIBBCDField * DvRegOstRPRICE_RGGOODS_DV)=0;

   __property TFIBBCDField * DvRegOstKOL_RGGOODS_DV = {read = get_DvRegOstKOL_RGGOODS_DV , write = set_DvRegOstKOL_RGGOODS_DV};
   virtual TFIBBCDField * get_DvRegOstKOL_RGGOODS_DV(void)=0;
   virtual void set_DvRegOstKOL_RGGOODS_DV(TFIBBCDField * DvRegOstKOL_RGGOODS_DV)=0;

   __property TFIBIntegerField * DvRegOstOPER_RGGOODS_DV = {read = get_DvRegOstOPER_RGGOODS_DV , write = set_DvRegOstOPER_RGGOODS_DV};
   virtual TFIBIntegerField * get_DvRegOstOPER_RGGOODS_DV(void)=0;
   virtual void set_DvRegOstOPER_RGGOODS_DV(TFIBIntegerField * DvRegOstOPER_RGGOODS_DV)=0;

   __property TFIBIntegerField * DvRegOstTYPE_RGGOODS_DV = {read = get_DvRegOstTYPE_RGGOODS_DV , write = set_DvRegOstTYPE_RGGOODS_DV};
   virtual TFIBIntegerField * get_DvRegOstTYPE_RGGOODS_DV(void)=0;
   virtual void set_DvRegOstTYPE_RGGOODS_DV(TFIBIntegerField * DvRegOstTYPE_RGGOODS_DV)=0;

   __property TFIBBCDField * RegOstRPRICE_RGGOODS = {read = get_RegOstRPRICE_RGGOODS , write = set_RegOstRPRICE_RGGOODS};
   virtual TFIBBCDField * get_RegOstRPRICE_RGGOODS(void)=0;
   virtual void set_RegOstRPRICE_RGGOODS(TFIBBCDField * RegOstRPRICE_RGGOODS)=0;

   __property TFIBBCDField * RegOstKOL_RGGOODS = {read = get_RegOstKOL_RGGOODS , write = set_RegOstKOL_RGGOODS};
   virtual TFIBBCDField * get_RegOstKOL_RGGOODS(void)=0;
   virtual void set_RegOstKOL_RGGOODS(TFIBBCDField * RegOstKOL_RGGOODS)=0;

   __property TFIBBCDField * DvNomKOLDV = {read = get_DvNomKOLDV , write = set_DvNomKOLDV};
   virtual TFIBBCDField * get_DvNomKOLDV(void)=0;
   virtual void set_DvNomKOLDV(TFIBBCDField * DvNomKOLDV)=0;

   __property TFIBBCDField * OstatokKOLOST = {read = get_OstatokKOLOST , write = set_OstatokKOLOST};
   virtual TFIBBCDField * get_OstatokKOLOST(void)=0;
   virtual void set_OstatokKOLOST(TFIBBCDField * OstatokKOLOST)=0;

   __property TFIBBCDField * RegOstID_RGGOODS = {read = get_RegOstID_RGGOODS , write = set_RegOstID_RGGOODS};
   virtual TFIBBCDField * get_RegOstID_RGGOODS(void)=0;
   virtual void set_RegOstID_RGGOODS(TFIBBCDField * RegOstID_RGGOODS)=0;

   __property TFIBBCDField * RegOstIDFIRM_RGGOODS = {read = get_RegOstIDFIRM_RGGOODS , write = set_RegOstIDFIRM_RGGOODS};
   virtual TFIBBCDField * get_RegOstIDFIRM_RGGOODS(void)=0;
   virtual void set_RegOstIDFIRM_RGGOODS(TFIBBCDField * RegOstIDFIRM_RGGOODS)=0;

   __property TFIBBCDField * RegOstIDSKLAD_RGGOODS = {read = get_RegOstIDSKLAD_RGGOODS , write = set_RegOstIDSKLAD_RGGOODS};
   virtual TFIBBCDField * get_RegOstIDSKLAD_RGGOODS(void)=0;
   virtual void set_RegOstIDSKLAD_RGGOODS(TFIBBCDField * RegOstIDSKLAD_RGGOODS)=0;

   __property TFIBBCDField * RegOstIDNOM_RGGOODS = {read = get_RegOstIDNOM_RGGOODS , write = set_RegOstIDNOM_RGGOODS};
   virtual TFIBBCDField * get_RegOstIDNOM_RGGOODS(void)=0;
   virtual void set_RegOstIDNOM_RGGOODS(TFIBBCDField * RegOstIDNOM_RGGOODS)=0;

   __property TFIBBCDField * DvRegOstID_RGGOODS_DV = {read = get_DvRegOstID_RGGOODS_DV , write = set_DvRegOstID_RGGOODS_DV};
   virtual TFIBBCDField * get_DvRegOstID_RGGOODS_DV(void)=0;
   virtual void set_DvRegOstID_RGGOODS_DV(TFIBBCDField * DvRegOstID_RGGOODS_DV)=0;

   __property TFIBBCDField * DvRegOstIDDOC_RGGOODS_DV = {read = get_DvRegOstIDDOC_RGGOODS_DV , write = set_DvRegOstIDDOC_RGGOODS_DV};
   virtual TFIBBCDField * get_DvRegOstIDDOC_RGGOODS_DV(void)=0;
   virtual void set_DvRegOstIDDOC_RGGOODS_DV(TFIBBCDField * DvRegOstIDDOC_RGGOODS_DV)=0;

   __property TFIBBCDField * DvRegOstIDFIRM_RGGOODS_DV = {read = get_DvRegOstIDFIRM_RGGOODS_DV , write = set_DvRegOstIDFIRM_RGGOODS_DV};
   virtual TFIBBCDField * get_DvRegOstIDFIRM_RGGOODS_DV(void)=0;
   virtual void set_DvRegOstIDFIRM_RGGOODS_DV(TFIBBCDField * DvRegOstIDFIRM_RGGOODS_DV)=0;

   __property TFIBBCDField * DvRegOstIDSKLAD_RGGOODS_DV = {read = get_DvRegOstIDSKLAD_RGGOODS_DV , write = set_DvRegOstIDSKLAD_RGGOODS_DV};
   virtual TFIBBCDField * get_DvRegOstIDSKLAD_RGGOODS_DV(void)=0;
   virtual void set_DvRegOstIDSKLAD_RGGOODS_DV(TFIBBCDField * DvRegOstIDSKLAD_RGGOODS_DV)=0;

   __property TFIBBCDField * DvRegOstIDNOM_RGGOODS_DV = {read = get_DvRegOstIDNOM_RGGOODS_DV , write = set_DvRegOstIDNOM_RGGOODS_DV};
   virtual TFIBBCDField * get_DvRegOstIDNOM_RGGOODS_DV(void)=0;
   virtual void set_DvRegOstIDNOM_RGGOODS_DV(TFIBBCDField * DvRegOstIDNOM_RGGOODS_DV)=0;

   __property TpFIBDataSet * TableOst = {read = get_TableOst , write = set_TableOst};
   virtual TpFIBDataSet * get_TableOst(void)=0;
   virtual void set_TableOst(TpFIBDataSet * TableOst)=0;

   __property TpFIBDataSet * Query = {read = get_Query , write = set_Query};
   virtual TpFIBDataSet * get_Query(void)=0;
   virtual void set_Query(TpFIBDataSet * Query)=0;

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

   __property __int64 IdFirm = {read = get_IdFirm , write = set_IdFirm};
   virtual __int64 get_IdFirm(void)=0;
   virtual void set_IdFirm(__int64 IdFirm)=0;

   __property double RPrice = {read = get_RPrice , write = set_RPrice};
   virtual double get_RPrice(void)=0;
   virtual void set_RPrice(double RPrice)=0;

   __property __int64 IdStr = {read = get_IdStr , write = set_IdStr};
   virtual __int64 get_IdStr(void)=0;
   virtual void set_IdStr(__int64 IdStr)=0;

   __property float Kol = {read = get_Kol , write = set_Kol};
   virtual float get_Kol(void)=0;
   virtual void set_Kol(float Kol)=0;

   __property int Operation = {read = get_Operation , write = set_Operation};
   virtual int get_Operation(void)=0;
   virtual void set_Operation(int Operation)=0;

   __property int Type = {read = get_Type , write = set_Type};
   virtual int get_Type(void)=0;
   virtual void set_Type(int Type)=0;

   __property float Sum2 = {read = get_Sum2 , write = set_Sum2};
   virtual float get_Sum2(void)=0;
   virtual void set_Sum2(float Sum2)=0;

   __property double KolOstNa = {read = get_KolOstNa , write = set_KolOstNa};
   virtual double get_KolOstNa(void)=0;
   virtual void set_KolOstNa(double KolOstNa)=0;

   __property bool SkladRozn = {read = get_SkladRozn , write = set_SkladRozn};
   virtual bool get_SkladRozn(void)=0;
   virtual void set_SkladRozn(bool SkladRozn)=0;

   __property bool NoOtrOstatok = {read = get_NoOtrOstatok , write = set_NoOtrOstatok};
   virtual bool get_NoOtrOstatok(void)=0;
   virtual void set_NoOtrOstatok(bool NoOtrOstatok)=0;

   virtual bool AddRecordPrihod(void)=0;
   virtual bool AddRecordRashod(void)=0;
   virtual bool UpdateTableOst(void)=0;
   virtual bool CancelDvReg(void)=0;
   virtual double GetOstatok(__int64 id_firm, __int64 id_sklad, __int64 id_nom)=0;
   virtual void GetOstatokPoPrice(__int64 id_firm, __int64 id_sklad, __int64 id_nom)=0;
   virtual double GetOstatokNa(TDateTime pos,__int64 id_firm, __int64 id_sklad, __int64 id_nom)=0;
   virtual double GetOstatokNaRoznSkladeNa(TDateTime pos,	__int64 id_firm,__int64 id_sklad,__int64 id_nom,bool rozn_sklad,double rprice)=0;
};
#define IID_IDMRegGoods __uuidof(IDMRegGoods)
#endif
