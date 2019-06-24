#ifndef UDMRegBankImplH
#define UDMRegBankImplH
#include "IDMRegBank.h"
#include "UDMRegBank.h"
//---------------------------------------------------------------
class __declspec(uuid("{A8C53344-0B6D-4A29-9AEE-C50AA1A97FC6}")) TDMRegBankImpl : public IDMRegBank
{
public:
   TDMRegBankImpl();
   ~TDMRegBankImpl();
   TDMRegBank * Object;
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

//IDMRegBank
   virtual TpFIBDataSet * get_DvRegOst(void);
   virtual void set_DvRegOst(TpFIBDataSet * DvRegOst);

   virtual TpFIBDataSet * get_RegOst(void);
   virtual void set_RegOst(TpFIBDataSet * RegOst);

   virtual TpFIBDataSet * get_Dv(void);
   virtual void set_Dv(TpFIBDataSet * Dv);

   virtual TpFIBDataSet * get_Ostatok(void);
   virtual void set_Ostatok(TpFIBDataSet * Ostatok);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TFIBDateTimeField * get_DvRegOstPOSDOC_RGBANK_DV(void);
   virtual void set_DvRegOstPOSDOC_RGBANK_DV(TFIBDateTimeField * DvRegOstPOSDOC_RGBANK_DV);

   virtual TFIBSmallIntField * get_DvRegOstTDV_RGBANK_DV(void);
   virtual void set_DvRegOstTDV_RGBANK_DV(TFIBSmallIntField * DvRegOstTDV_RGBANK_DV);

   virtual TFIBBCDField * get_DvRegOstSUM_RGBANK_DV(void);
   virtual void set_DvRegOstSUM_RGBANK_DV(TFIBBCDField * DvRegOstSUM_RGBANK_DV);

   virtual TFIBIntegerField * get_DvRegOstOPER_RGBANK_DV(void);
   virtual void set_DvRegOstOPER_RGBANK_DV(TFIBIntegerField * DvRegOstOPER_RGBANK_DV);

   virtual TFIBBCDField * get_RegOstSUM_RGBANK(void);
   virtual void set_RegOstSUM_RGBANK(TFIBBCDField * RegOstSUM_RGBANK);

   virtual TFIBBCDField * get_DvSUMDV(void);
   virtual void set_DvSUMDV(TFIBBCDField * DvSUMDV);

   virtual TFIBBCDField * get_OstatokSUMOST(void);
   virtual void set_OstatokSUMOST(TFIBBCDField * OstatokSUMOST);

   virtual TFIBBCDField * get_RegOstID_RGBANK(void);
   virtual void set_RegOstID_RGBANK(TFIBBCDField * RegOstID_RGBANK);

   virtual TFIBBCDField * get_RegOstIDFIRM_RGBANK(void);
   virtual void set_RegOstIDFIRM_RGBANK(TFIBBCDField * RegOstIDFIRM_RGBANK);

   virtual TFIBBCDField * get_RegOstIDBSCHET_RGBANK(void);
   virtual void set_RegOstIDBSCHET_RGBANK(TFIBBCDField * RegOstIDBSCHET_RGBANK);

   virtual TFIBBCDField * get_DvRegOstID_RGBANK_DV(void);
   virtual void set_DvRegOstID_RGBANK_DV(TFIBBCDField * DvRegOstID_RGBANK_DV);

   virtual TFIBBCDField * get_DvRegOstIDDOC_RGBANK_DV(void);
   virtual void set_DvRegOstIDDOC_RGBANK_DV(TFIBBCDField * DvRegOstIDDOC_RGBANK_DV);

   virtual TFIBBCDField * get_DvRegOstIDFIRM_RGBANK_DV(void);
   virtual void set_DvRegOstIDFIRM_RGBANK_DV(TFIBBCDField * DvRegOstIDFIRM_RGBANK_DV);

   virtual TFIBBCDField * get_DvRegOstIDBSCHET_RGBANK_DV(void);
   virtual void set_DvRegOstIDBSCHET_RGBANK_DV(TFIBBCDField * DvRegOstIDBSCHET_RGBANK_DV);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual TDateTime get_PosDoc(void);
   virtual void set_PosDoc(TDateTime PosDoc);

   virtual __int64 get_IdFirm(void);
   virtual void set_IdFirm(__int64 IdFirm);

   virtual __int64 get_IdBSchet(void);
   virtual void set_IdBSchet(__int64 IdBSchet);

   virtual float get_Sum(void);
   virtual void set_Sum(float Sum);

   virtual int get_Operation(void);
   virtual void set_Operation(int Operation);

   virtual double get_SumOstNa(void);
   virtual void set_SumOstNa(double SumOstNa);

   virtual int GetOstatok(void);
   virtual bool AddRecordPrihod(void);
   virtual bool AddRecordRashod(void);
   virtual bool UpdateTableOst(void);
   virtual bool CancelDvReg(void);
   virtual bool GetOstatokNa(TDateTime Pos, __int64 id_firm, __int64 id_bschet);
};
#define CLSID_TDMRegBankImpl __uuidof(TDMRegBankImpl)
#endif
