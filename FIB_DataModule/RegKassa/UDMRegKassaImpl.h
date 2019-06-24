#ifndef UDMRegKassaImplH
#define UDMRegKassaImplH
#include "IDMRegKassa.h"
#include "UDMRegKassa.h"
//---------------------------------------------------------------
class __declspec(uuid("{09295B71-76DF-4422-9A51-B35718EFD31B}")) TDMRegKassaImpl : public IDMRegKassa
{
public:
   TDMRegKassaImpl();
   ~TDMRegKassaImpl();
   TDMRegKassa * Object;
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

//IDMRegKassa
   virtual TpFIBDataSet * get_DvRegOst(void);
   virtual void set_DvRegOst(TpFIBDataSet * DvRegOst);

   virtual TpFIBDataSet * get_RegOst(void);
   virtual void set_RegOst(TpFIBDataSet * RegOst);

   virtual TpFIBDataSet * get_Dv(void);
   virtual void set_Dv(TpFIBDataSet * Dv);

   virtual TpFIBDataSet * get_Ostatok(void);
   virtual void set_Ostatok(TpFIBDataSet * Ostatok);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TFIBDateTimeField * get_DvRegOstPOSDOC_RGKASSA_DV(void);
   virtual void set_DvRegOstPOSDOC_RGKASSA_DV(TFIBDateTimeField * DvRegOstPOSDOC_RGKASSA_DV);

   virtual TFIBSmallIntField * get_DvRegOstTDV_RGKASSA_DV(void);
   virtual void set_DvRegOstTDV_RGKASSA_DV(TFIBSmallIntField * DvRegOstTDV_RGKASSA_DV);

   virtual TFIBBCDField * get_DvRegOstSUM_RGKASSA_DV(void);
   virtual void set_DvRegOstSUM_RGKASSA_DV(TFIBBCDField * DvRegOstSUM_RGKASSA_DV);

   virtual TFIBIntegerField * get_DvRegOstOPER_RGKASSA_DV(void);
   virtual void set_DvRegOstOPER_RGKASSA_DV(TFIBIntegerField * DvRegOstOPER_RGKASSA_DV);

   virtual TFIBBCDField * get_RegOstSUM_RGKASSA(void);
   virtual void set_RegOstSUM_RGKASSA(TFIBBCDField * RegOstSUM_RGKASSA);

   virtual TFIBBCDField * get_DvSUMDV(void);
   virtual void set_DvSUMDV(TFIBBCDField * DvSUMDV);

   virtual TFIBBCDField * get_OstatokSUMOST(void);
   virtual void set_OstatokSUMOST(TFIBBCDField * OstatokSUMOST);

   virtual TFIBBCDField * get_RegOstID_RGKASSA(void);
   virtual void set_RegOstID_RGKASSA(TFIBBCDField * RegOstID_RGKASSA);

   virtual TFIBBCDField * get_RegOstIDFIRM_RGKASSA(void);
   virtual void set_RegOstIDFIRM_RGKASSA(TFIBBCDField * RegOstIDFIRM_RGKASSA);

   virtual TFIBBCDField * get_RegOstIDKKM_RGKASSA(void);
   virtual void set_RegOstIDKKM_RGKASSA(TFIBBCDField * RegOstIDKKM_RGKASSA);

   virtual TFIBBCDField * get_DvRegOstID_RGKASSA_DV(void);
   virtual void set_DvRegOstID_RGKASSA_DV(TFIBBCDField * DvRegOstID_RGKASSA_DV);

   virtual TFIBBCDField * get_DvRegOstIDDOC_RGKASSA_DV(void);
   virtual void set_DvRegOstIDDOC_RGKASSA_DV(TFIBBCDField * DvRegOstIDDOC_RGKASSA_DV);

   virtual TFIBBCDField * get_DvRegOstIDFIRM_RGKASSA_DV(void);
   virtual void set_DvRegOstIDFIRM_RGKASSA_DV(TFIBBCDField * DvRegOstIDFIRM_RGKASSA_DV);

   virtual TFIBBCDField * get_DvRegOstIDKKM_RGKASSA_DV(void);
   virtual void set_DvRegOstIDKKM_RGKASSA_DV(TFIBBCDField * DvRegOstIDKKM_RGKASSA_DV);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual TDateTime get_PosDoc(void);
   virtual void set_PosDoc(TDateTime PosDoc);

   virtual __int64 get_IdFirm(void);
   virtual void set_IdFirm(__int64 IdFirm);

   virtual __int64 get_IdKKM(void);
   virtual void set_IdKKM(__int64 IdKKM);

   virtual double get_Sum(void);
   virtual void set_Sum(double Sum);

   virtual int get_Operation(void);
   virtual void set_Operation(int Operation);

   virtual double get_SumOstNa(void);
   virtual void set_SumOstNa(double SumOstNa);

   virtual int GetOstatok(void);
   virtual bool AddRecordPrihod(void);
   virtual bool AddRecordRashod(void);
   virtual bool UpdateTableOst(void);
   virtual bool CancelDvReg(void);
   virtual bool GetOstatokNa(TDateTime Pos, __int64 id_firm, __int64 id_kassa);
};
#define CLSID_TDMRegKassaImpl __uuidof(TDMRegKassaImpl)
#endif
