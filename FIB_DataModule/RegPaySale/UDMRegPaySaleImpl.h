#ifndef UDMRegPaySaleImplH
#define UDMRegPaySaleImplH
#include "IDMRegPaySale.h"
#include "UDMRegPaySale.h"
//---------------------------------------------------------------
class __declspec(uuid("{5352F413-C63C-43DE-A60D-77EE6B116B1E}")) TDMRegPaySaleImpl : public IDMRegPaySale
{
public:
   TDMRegPaySaleImpl();
   ~TDMRegPaySaleImpl();
   TDMRegPaySale * Object;
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

//IDMRegPaySale
   virtual TpFIBDataSet * get_DvRegOst(void);
   virtual void set_DvRegOst(TpFIBDataSet * DvRegOst);

   virtual TpFIBDataSet * get_RegOst(void);
   virtual void set_RegOst(TpFIBDataSet * RegOst);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TFIBDateTimeField * get_DvRegOstPOS_RGPAYSALE_DV(void);
   virtual void set_DvRegOstPOS_RGPAYSALE_DV(TFIBDateTimeField * DvRegOstPOS_RGPAYSALE_DV);

   virtual TFIBIntegerField * get_DvRegOstTDV_RGPAYSALE_DV(void);
   virtual void set_DvRegOstTDV_RGPAYSALE_DV(TFIBIntegerField * DvRegOstTDV_RGPAYSALE_DV);

   virtual TFIBDateField * get_DvRegOstDATE_RGPAYSALE_DV(void);
   virtual void set_DvRegOstDATE_RGPAYSALE_DV(TFIBDateField * DvRegOstDATE_RGPAYSALE_DV);

   virtual TFIBBCDField * get_DvRegOstSUM_RGPAYSALE_DV(void);
   virtual void set_DvRegOstSUM_RGPAYSALE_DV(TFIBBCDField * DvRegOstSUM_RGPAYSALE_DV);

   virtual TFIBDateField * get_RegOstDATE_RGPAYSALE(void);
   virtual void set_RegOstDATE_RGPAYSALE(TFIBDateField * RegOstDATE_RGPAYSALE);

   virtual TFIBBCDField * get_RegOstSUM_RGPAYSALE(void);
   virtual void set_RegOstSUM_RGPAYSALE(TFIBBCDField * RegOstSUM_RGPAYSALE);

   virtual TFIBBCDField * get_RegOstID_RGPAYSALE(void);
   virtual void set_RegOstID_RGPAYSALE(TFIBBCDField * RegOstID_RGPAYSALE);

   virtual TFIBBCDField * get_RegOstIDFIRM_RGPAYSALE(void);
   virtual void set_RegOstIDFIRM_RGPAYSALE(TFIBBCDField * RegOstIDFIRM_RGPAYSALE);

   virtual TFIBBCDField * get_RegOstIDKLIENT_RGPAYSALE(void);
   virtual void set_RegOstIDKLIENT_RGPAYSALE(TFIBBCDField * RegOstIDKLIENT_RGPAYSALE);

   virtual TFIBBCDField * get_RegOstIDDOG_RGPAYSALE(void);
   virtual void set_RegOstIDDOG_RGPAYSALE(TFIBBCDField * RegOstIDDOG_RGPAYSALE);

   virtual TFIBBCDField * get_RegOstIDDOCSALE_RGPAYSALE(void);
   virtual void set_RegOstIDDOCSALE_RGPAYSALE(TFIBBCDField * RegOstIDDOCSALE_RGPAYSALE);

   virtual TFIBBCDField * get_DvRegOstID_RGPAYSALE_DV(void);
   virtual void set_DvRegOstID_RGPAYSALE_DV(TFIBBCDField * DvRegOstID_RGPAYSALE_DV);

   virtual TFIBBCDField * get_DvRegOstIDDOC_RGPAYSALE_DV(void);
   virtual void set_DvRegOstIDDOC_RGPAYSALE_DV(TFIBBCDField * DvRegOstIDDOC_RGPAYSALE_DV);

   virtual TFIBBCDField * get_DvRegOstIDFIRM_RGPAYSALE_DV(void);
   virtual void set_DvRegOstIDFIRM_RGPAYSALE_DV(TFIBBCDField * DvRegOstIDFIRM_RGPAYSALE_DV);

   virtual TFIBBCDField * get_DvRegOstIDKLIENT_RGPAYSALE_DV(void);
   virtual void set_DvRegOstIDKLIENT_RGPAYSALE_DV(TFIBBCDField * DvRegOstIDKLIENT_RGPAYSALE_DV);

   virtual TFIBBCDField * get_DvRegOstIDDOG_RGPAYSALE_DV(void);
   virtual void set_DvRegOstIDDOG_RGPAYSALE_DV(TFIBBCDField * DvRegOstIDDOG_RGPAYSALE_DV);

   virtual TFIBBCDField * get_DvRegOstIDDOCSALE_RGPAYSALE_DV(void);
   virtual void set_DvRegOstIDDOCSALE_RGPAYSALE_DV(TFIBBCDField * DvRegOstIDDOCSALE_RGPAYSALE_DV);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual TDateTime get_PosDoc(void);
   virtual void set_PosDoc(TDateTime PosDoc);

   virtual __int64 get_IdFirm(void);
   virtual void set_IdFirm(__int64 IdFirm);

   virtual __int64 get_IdKlient(void);
   virtual void set_IdKlient(__int64 IdKlient);

   virtual __int64 get_IdDogovor(void);
   virtual void set_IdDogovor(__int64 IdDogovor);

   virtual __int64 get_IdDocSale(void);
   virtual void set_IdDocSale(__int64 IdDocSale);

   virtual TDate get_DatePay(void);
   virtual void set_DatePay(TDate DatePay);

   virtual float get_Sum(void);
   virtual void set_Sum(float Sum);

   virtual bool AddRecordPrihod(void);
   virtual bool AddRecordRashod(void);
   virtual bool UpdateTableOst(void);
   virtual bool CancelDvReg(void);
};
#define CLSID_TDMRegPaySaleImpl __uuidof(TDMRegPaySaleImpl)
#endif
