#ifndef UDMRegAdvanceCustomerImplH
#define UDMRegAdvanceCustomerImplH
#include "IDMRegAdvanceCustomer.h"
#include "UDMRegAdvanceCustomer.h"
//---------------------------------------------------------------
class __declspec(uuid("{4617DE5A-A60F-42E9-9652-3F40BC8F8F47}")) TDMRegAdvanceCustomerImpl : public IDMRegAdvanceCustomer
{
public:
   TDMRegAdvanceCustomerImpl();
   ~TDMRegAdvanceCustomerImpl();
   TDMRegAdvanceCustomer * Object;
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

//IDMRegAdvanceCustomer
   virtual TpFIBDataSet * get_DvRegOst(void);
   virtual void set_DvRegOst(TpFIBDataSet * DvRegOst);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBDataSet * get_RegOst(void);
   virtual void set_RegOst(TpFIBDataSet * RegOst);

   virtual TFIBDateTimeField * get_DvRegOstPOS_RGADVCUST_DV(void);
   virtual void set_DvRegOstPOS_RGADVCUST_DV(TFIBDateTimeField * DvRegOstPOS_RGADVCUST_DV);

   virtual TFIBIntegerField * get_DvRegOstTDV_RGADVCUST_DV(void);
   virtual void set_DvRegOstTDV_RGADVCUST_DV(TFIBIntegerField * DvRegOstTDV_RGADVCUST_DV);

   virtual TFIBBCDField * get_DvRegOstSUM_RGADVCUST_DV(void);
   virtual void set_DvRegOstSUM_RGADVCUST_DV(TFIBBCDField * DvRegOstSUM_RGADVCUST_DV);

   virtual TFIBBCDField * get_RegOstSUM_RGADVCUST(void);
   virtual void set_RegOstSUM_RGADVCUST(TFIBBCDField * RegOstSUM_RGADVCUST);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TFIBBCDField * get_DvRegOstID_RGADVCUST_DV(void);
   virtual void set_DvRegOstID_RGADVCUST_DV(TFIBBCDField * DvRegOstID_RGADVCUST_DV);

   virtual TFIBBCDField * get_DvRegOstIDDOC_RGADVCUST_DV(void);
   virtual void set_DvRegOstIDDOC_RGADVCUST_DV(TFIBBCDField * DvRegOstIDDOC_RGADVCUST_DV);

   virtual TFIBBCDField * get_DvRegOstIDFIRM_RGADVCUST_DV(void);
   virtual void set_DvRegOstIDFIRM_RGADVCUST_DV(TFIBBCDField * DvRegOstIDFIRM_RGADVCUST_DV);

   virtual TFIBBCDField * get_DvRegOstIDKLIENT_RGADVCUST_DV(void);
   virtual void set_DvRegOstIDKLIENT_RGADVCUST_DV(TFIBBCDField * DvRegOstIDKLIENT_RGADVCUST_DV);

   virtual TFIBBCDField * get_RegOstID_RGADVCUST(void);
   virtual void set_RegOstID_RGADVCUST(TFIBBCDField * RegOstID_RGADVCUST);

   virtual TFIBBCDField * get_RegOstIDFIRM_RGADVCUST(void);
   virtual void set_RegOstIDFIRM_RGADVCUST(TFIBBCDField * RegOstIDFIRM_RGADVCUST);

   virtual TFIBBCDField * get_RegOstIDKLIENT_RGADVCUST(void);
   virtual void set_RegOstIDKLIENT_RGADVCUST(TFIBBCDField * RegOstIDKLIENT_RGADVCUST);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual TDateTime get_PosDoc(void);
   virtual void set_PosDoc(TDateTime PosDoc);

   virtual __int64 get_IdFirm(void);
   virtual void set_IdFirm(__int64 IdFirm);

   virtual __int64 get_IdKlient(void);
   virtual void set_IdKlient(__int64 IdKlient);

   virtual float get_Sum(void);
   virtual void set_Sum(float Sum);

   virtual bool AddRecordPrihod(void);
   virtual bool AddRecordRashod(void);
   virtual bool UpdateTableOst(void);
   virtual bool CancelDvReg(void);
   virtual double GetOstatokAdvance(__int64 id_firm, __int64 id_klient);
};
#define CLSID_TDMRegAdvanceCustomerImpl __uuidof(TDMRegAdvanceCustomerImpl)
#endif
