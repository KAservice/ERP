#ifndef UDMRegGoodsImplH
#define UDMRegGoodsImplH
#include "IDMRegGoods.h"
#include "UDMRegGoods.h"
//---------------------------------------------------------------
class __declspec(uuid("{6BE2A7B9-90BC-4D4C-BDC0-293AB0912D5B}")) TDMRegGoodsImpl : public IDMRegGoods
{
public:
   TDMRegGoodsImpl();
   ~TDMRegGoodsImpl();
   TDMRegGoods * Object;
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

//IDMRegGoods
   virtual TpFIBDataSet * get_DvRegOst(void);
   virtual void set_DvRegOst(TpFIBDataSet * DvRegOst);

   virtual TpFIBDataSet * get_RegOst(void);
   virtual void set_RegOst(TpFIBDataSet * RegOst);

   virtual TpFIBDataSet * get_DvNom(void);
   virtual void set_DvNom(TpFIBDataSet * DvNom);

   virtual TpFIBDataSet * get_Ostatok(void);
   virtual void set_Ostatok(TpFIBDataSet * Ostatok);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TFIBDateTimeField * get_DvRegOstPOSDOC_RGGOODS_DV(void);
   virtual void set_DvRegOstPOSDOC_RGGOODS_DV(TFIBDateTimeField * DvRegOstPOSDOC_RGGOODS_DV);

   virtual TFIBSmallIntField * get_DvRegOstTDV_RGGOODS_DV(void);
   virtual void set_DvRegOstTDV_RGGOODS_DV(TFIBSmallIntField * DvRegOstTDV_RGGOODS_DV);

   virtual TFIBBCDField * get_DvRegOstRPRICE_RGGOODS_DV(void);
   virtual void set_DvRegOstRPRICE_RGGOODS_DV(TFIBBCDField * DvRegOstRPRICE_RGGOODS_DV);

   virtual TFIBBCDField * get_DvRegOstKOL_RGGOODS_DV(void);
   virtual void set_DvRegOstKOL_RGGOODS_DV(TFIBBCDField * DvRegOstKOL_RGGOODS_DV);

   virtual TFIBIntegerField * get_DvRegOstOPER_RGGOODS_DV(void);
   virtual void set_DvRegOstOPER_RGGOODS_DV(TFIBIntegerField * DvRegOstOPER_RGGOODS_DV);

   virtual TFIBIntegerField * get_DvRegOstTYPE_RGGOODS_DV(void);
   virtual void set_DvRegOstTYPE_RGGOODS_DV(TFIBIntegerField * DvRegOstTYPE_RGGOODS_DV);

   virtual TFIBBCDField * get_RegOstRPRICE_RGGOODS(void);
   virtual void set_RegOstRPRICE_RGGOODS(TFIBBCDField * RegOstRPRICE_RGGOODS);

   virtual TFIBBCDField * get_RegOstKOL_RGGOODS(void);
   virtual void set_RegOstKOL_RGGOODS(TFIBBCDField * RegOstKOL_RGGOODS);

   virtual TFIBBCDField * get_DvNomKOLDV(void);
   virtual void set_DvNomKOLDV(TFIBBCDField * DvNomKOLDV);

   virtual TFIBBCDField * get_OstatokKOLOST(void);
   virtual void set_OstatokKOLOST(TFIBBCDField * OstatokKOLOST);

   virtual TFIBBCDField * get_RegOstID_RGGOODS(void);
   virtual void set_RegOstID_RGGOODS(TFIBBCDField * RegOstID_RGGOODS);

   virtual TFIBBCDField * get_RegOstIDFIRM_RGGOODS(void);
   virtual void set_RegOstIDFIRM_RGGOODS(TFIBBCDField * RegOstIDFIRM_RGGOODS);

   virtual TFIBBCDField * get_RegOstIDSKLAD_RGGOODS(void);
   virtual void set_RegOstIDSKLAD_RGGOODS(TFIBBCDField * RegOstIDSKLAD_RGGOODS);

   virtual TFIBBCDField * get_RegOstIDNOM_RGGOODS(void);
   virtual void set_RegOstIDNOM_RGGOODS(TFIBBCDField * RegOstIDNOM_RGGOODS);

   virtual TFIBBCDField * get_DvRegOstID_RGGOODS_DV(void);
   virtual void set_DvRegOstID_RGGOODS_DV(TFIBBCDField * DvRegOstID_RGGOODS_DV);

   virtual TFIBBCDField * get_DvRegOstIDDOC_RGGOODS_DV(void);
   virtual void set_DvRegOstIDDOC_RGGOODS_DV(TFIBBCDField * DvRegOstIDDOC_RGGOODS_DV);

   virtual TFIBBCDField * get_DvRegOstIDFIRM_RGGOODS_DV(void);
   virtual void set_DvRegOstIDFIRM_RGGOODS_DV(TFIBBCDField * DvRegOstIDFIRM_RGGOODS_DV);

   virtual TFIBBCDField * get_DvRegOstIDSKLAD_RGGOODS_DV(void);
   virtual void set_DvRegOstIDSKLAD_RGGOODS_DV(TFIBBCDField * DvRegOstIDSKLAD_RGGOODS_DV);

   virtual TFIBBCDField * get_DvRegOstIDNOM_RGGOODS_DV(void);
   virtual void set_DvRegOstIDNOM_RGGOODS_DV(TFIBBCDField * DvRegOstIDNOM_RGGOODS_DV);

   virtual TpFIBDataSet * get_TableOst(void);
   virtual void set_TableOst(TpFIBDataSet * TableOst);

   virtual TpFIBDataSet * get_Query(void);
   virtual void set_Query(TpFIBDataSet * Query);

   virtual __int64 get_IdSklad(void);
   virtual void set_IdSklad(__int64 IdSklad);

   virtual __int64 get_IdNom(void);
   virtual void set_IdNom(__int64 IdNom);

   virtual float get_SumOst(void);
   virtual void set_SumOst(float SumOst);

   virtual float get_KolOst(void);
   virtual void set_KolOst(float KolOst);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual TDateTime get_PosDoc(void);
   virtual void set_PosDoc(TDateTime PosDoc);

   virtual __int64 get_IdFirm(void);
   virtual void set_IdFirm(__int64 IdFirm);

   virtual double get_RPrice(void);
   virtual void set_RPrice(double RPrice);

   virtual __int64 get_IdStr(void);
   virtual void set_IdStr(__int64 IdStr);

   virtual float get_Kol(void);
   virtual void set_Kol(float Kol);

   virtual int get_Operation(void);
   virtual void set_Operation(int Operation);

   virtual int get_Type(void);
   virtual void set_Type(int Type);

   virtual float get_Sum2(void);
   virtual void set_Sum2(float Sum2);

   virtual double get_KolOstNa(void);
   virtual void set_KolOstNa(double KolOstNa);

   virtual bool get_SkladRozn(void);
   virtual void set_SkladRozn(bool SkladRozn);

   virtual bool get_NoOtrOstatok(void);
   virtual void set_NoOtrOstatok(bool NoOtrOstatok);

   virtual bool AddRecordPrihod(void);
   virtual bool AddRecordRashod(void);
   virtual bool UpdateTableOst(void);
   virtual bool CancelDvReg(void);
   virtual double GetOstatok(__int64 id_firm, __int64 id_sklad, __int64 id_nom);
   virtual void GetOstatokPoPrice(__int64 id_firm, __int64 id_sklad, __int64 id_nom);
   virtual double GetOstatokNa(TDateTime pos,__int64 id_firm, __int64 id_sklad, __int64 id_nom);
   virtual double GetOstatokNaRoznSkladeNa(TDateTime pos,	__int64 id_firm,__int64 id_sklad,__int64 id_nom,bool rozn_sklad,double rprice);
};
#define CLSID_TDMRegGoodsImpl __uuidof(TDMRegGoodsImpl)
#endif
