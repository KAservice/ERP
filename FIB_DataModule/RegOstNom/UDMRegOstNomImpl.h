#ifndef UDMRegOstNomImplH
#define UDMRegOstNomImplH
#include "IDMRegOstNom.h"
#include "UDMRegOstNom.h"
//---------------------------------------------------------------
class __declspec(uuid("{D483F260-C63D-46FB-9BC2-BB96238454DB}")) TDMRegOstNomImpl : public IDMRegOstNom
{
public:
   TDMRegOstNomImpl();
   ~TDMRegOstNomImpl();
   TDMRegOstNom * Object;
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

//IDMRegOstNom
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

   virtual TFIBDateTimeField * get_DvRegOstPOSDOC_OSTNOMDV(void);
   virtual void set_DvRegOstPOSDOC_OSTNOMDV(TFIBDateTimeField * DvRegOstPOSDOC_OSTNOMDV);

   virtual TFIBSmallIntField * get_DvRegOstTDV_OSTNOMDV(void);
   virtual void set_DvRegOstTDV_OSTNOMDV(TFIBSmallIntField * DvRegOstTDV_OSTNOMDV);

   virtual TFIBBCDField * get_DvRegOstSUM_OSTNOMDV(void);
   virtual void set_DvRegOstSUM_OSTNOMDV(TFIBBCDField * DvRegOstSUM_OSTNOMDV);

   virtual TFIBBCDField * get_DvRegOstKOL_OSTNOMDV(void);
   virtual void set_DvRegOstKOL_OSTNOMDV(TFIBBCDField * DvRegOstKOL_OSTNOMDV);

   virtual TFIBIntegerField * get_DvRegOstOPER_OSTNOMDV(void);
   virtual void set_DvRegOstOPER_OSTNOMDV(TFIBIntegerField * DvRegOstOPER_OSTNOMDV);

   virtual TFIBBCDField * get_DvRegOstSUM2_OSTNOMDV(void);
   virtual void set_DvRegOstSUM2_OSTNOMDV(TFIBBCDField * DvRegOstSUM2_OSTNOMDV);

   virtual TFIBBCDField * get_RegOstSUMOSTNOM(void);
   virtual void set_RegOstSUMOSTNOM(TFIBBCDField * RegOstSUMOSTNOM);

   virtual TFIBBCDField * get_RegOstKOLOSTNOM(void);
   virtual void set_RegOstKOLOSTNOM(TFIBBCDField * RegOstKOLOSTNOM);

   virtual TFIBBCDField * get_DvNomKOLDV(void);
   virtual void set_DvNomKOLDV(TFIBBCDField * DvNomKOLDV);

   virtual TFIBBCDField * get_DvNomSUMDV(void);
   virtual void set_DvNomSUMDV(TFIBBCDField * DvNomSUMDV);

   virtual TFIBBCDField * get_OstatokKOLOST(void);
   virtual void set_OstatokKOLOST(TFIBBCDField * OstatokKOLOST);

   virtual TFIBBCDField * get_OstatokSUMOST(void);
   virtual void set_OstatokSUMOST(TFIBBCDField * OstatokSUMOST);

   virtual TFIBBCDField * get_RegOstIDOSTNOM(void);
   virtual void set_RegOstIDOSTNOM(TFIBBCDField * RegOstIDOSTNOM);

   virtual TFIBBCDField * get_RegOstIDFIRMOSTNOM(void);
   virtual void set_RegOstIDFIRMOSTNOM(TFIBBCDField * RegOstIDFIRMOSTNOM);

   virtual TFIBBCDField * get_RegOstIDSKLOSTNOM(void);
   virtual void set_RegOstIDSKLOSTNOM(TFIBBCDField * RegOstIDSKLOSTNOM);

   virtual TFIBBCDField * get_RegOstIDNOMOSTNOM(void);
   virtual void set_RegOstIDNOMOSTNOM(TFIBBCDField * RegOstIDNOMOSTNOM);

   virtual TFIBBCDField * get_RegOstIDPARTOSTNOM(void);
   virtual void set_RegOstIDPARTOSTNOM(TFIBBCDField * RegOstIDPARTOSTNOM);

   virtual TFIBBCDField * get_DvRegOstID_OSTNOMDV(void);
   virtual void set_DvRegOstID_OSTNOMDV(TFIBBCDField * DvRegOstID_OSTNOMDV);

   virtual TFIBBCDField * get_DvRegOstIDDOC_OSTNOMDV(void);
   virtual void set_DvRegOstIDDOC_OSTNOMDV(TFIBBCDField * DvRegOstIDDOC_OSTNOMDV);

   virtual TFIBBCDField * get_DvRegOstIDFIRM_OSTNOMDV(void);
   virtual void set_DvRegOstIDFIRM_OSTNOMDV(TFIBBCDField * DvRegOstIDFIRM_OSTNOMDV);

   virtual TFIBBCDField * get_DvRegOstIDSKL_OSTNOMDV(void);
   virtual void set_DvRegOstIDSKL_OSTNOMDV(TFIBBCDField * DvRegOstIDSKL_OSTNOMDV);

   virtual TFIBBCDField * get_DvRegOstIDNOM_OSTNOMDV(void);
   virtual void set_DvRegOstIDNOM_OSTNOMDV(TFIBBCDField * DvRegOstIDNOM_OSTNOMDV);

   virtual TFIBBCDField * get_DvRegOstIDPART_OSTNOMDV(void);
   virtual void set_DvRegOstIDPART_OSTNOMDV(TFIBBCDField * DvRegOstIDPART_OSTNOMDV);

   virtual TFIBBCDField * get_DvRegOstIDSTRDOC_OSTNOMDV(void);
   virtual void set_DvRegOstIDSTRDOC_OSTNOMDV(TFIBBCDField * DvRegOstIDSTRDOC_OSTNOMDV);

   virtual __int64 get_IdFirm(void);
   virtual void set_IdFirm(__int64 IdFirm);

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

   virtual __int64 get_IdPart(void);
   virtual void set_IdPart(__int64 IdPart);

   virtual __int64 get_IdStr(void);
   virtual void set_IdStr(__int64 IdStr);

   virtual float get_Kol(void);
   virtual void set_Kol(float Kol);

   virtual float get_Sum(void);
   virtual void set_Sum(float Sum);

   virtual int get_Operation(void);
   virtual void set_Operation(int Operation);

   virtual float get_Sum2(void);
   virtual void set_Sum2(float Sum2);

   virtual float get_SumOstNa(void);
   virtual void set_SumOstNa(float SumOstNa);

   virtual float get_KolOstNa(void);
   virtual void set_KolOstNa(float KolOstNa);

   virtual int GetOstatok(void);
   virtual bool AddRecordPrihod(void);
   virtual bool AddRecordRashod(void);
   virtual bool UpdateTableOst(void);
   virtual bool CancelDvReg(void);
   virtual bool GetOstatokNa(TDateTime Pos, __int64 idFirm, __int64 idSklad, __int64 idNom);
};
#define CLSID_TDMRegOstNomImpl __uuidof(TDMRegOstNomImpl)
#endif
