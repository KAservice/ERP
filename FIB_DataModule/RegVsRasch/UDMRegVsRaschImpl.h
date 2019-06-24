#ifndef UDMRegVsRaschImplH
#define UDMRegVsRaschImplH
#include "IDMRegVsRasch.h"
#include "UDMRegVsRasch.h"
//---------------------------------------------------------------
class __declspec(uuid("{D31A7ECA-0FDD-48E8-8654-EB0B9B778B80}")) TDMRegVsRaschImpl : public IDMRegVsRasch
{
public:
   TDMRegVsRaschImpl();
   ~TDMRegVsRaschImpl();
   TDMRegVsRasch * Object;
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

//IDMRegVsRasch
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

   virtual TFIBDateTimeField * get_DvRegOstPOSDOC_VSRASCH_DV(void);
   virtual void set_DvRegOstPOSDOC_VSRASCH_DV(TFIBDateTimeField * DvRegOstPOSDOC_VSRASCH_DV);

   virtual TFIBSmallIntField * get_DvRegOstTDV_VSRASCH_DV(void);
   virtual void set_DvRegOstTDV_VSRASCH_DV(TFIBSmallIntField * DvRegOstTDV_VSRASCH_DV);

   virtual TFIBBCDField * get_DvRegOstSUM_VSRASCH_DV(void);
   virtual void set_DvRegOstSUM_VSRASCH_DV(TFIBBCDField * DvRegOstSUM_VSRASCH_DV);

   virtual TFIBBCDField * get_RegOstSUM_VSRASCH(void);
   virtual void set_RegOstSUM_VSRASCH(TFIBBCDField * RegOstSUM_VSRASCH);

   virtual TFIBBCDField * get_DvSUMDV(void);
   virtual void set_DvSUMDV(TFIBBCDField * DvSUMDV);

   virtual TFIBBCDField * get_OstatokSUMOST(void);
   virtual void set_OstatokSUMOST(TFIBBCDField * OstatokSUMOST);

   virtual TFIBBCDField * get_RegOstID_VSRASCH(void);
   virtual void set_RegOstID_VSRASCH(TFIBBCDField * RegOstID_VSRASCH);

   virtual TFIBBCDField * get_RegOstIDFIRM_VSRASCH(void);
   virtual void set_RegOstIDFIRM_VSRASCH(TFIBBCDField * RegOstIDFIRM_VSRASCH);

   virtual TFIBBCDField * get_RegOstIDKLIENT_VSRASCH(void);
   virtual void set_RegOstIDKLIENT_VSRASCH(TFIBBCDField * RegOstIDKLIENT_VSRASCH);

   virtual TFIBBCDField * get_RegOstIDDOG_VSRASCH(void);
   virtual void set_RegOstIDDOG_VSRASCH(TFIBBCDField * RegOstIDDOG_VSRASCH);

   virtual TFIBBCDField * get_DvRegOstID_VSRASCH_DV(void);
   virtual void set_DvRegOstID_VSRASCH_DV(TFIBBCDField * DvRegOstID_VSRASCH_DV);

   virtual TFIBBCDField * get_DvRegOstIDDOC_VSRASCH_DV(void);
   virtual void set_DvRegOstIDDOC_VSRASCH_DV(TFIBBCDField * DvRegOstIDDOC_VSRASCH_DV);

   virtual TFIBBCDField * get_DvRegOstIDFIRM_VSRASCH_DV(void);
   virtual void set_DvRegOstIDFIRM_VSRASCH_DV(TFIBBCDField * DvRegOstIDFIRM_VSRASCH_DV);

   virtual TFIBBCDField * get_DvRegOstIDKLIENT_VSRASCH_DV(void);
   virtual void set_DvRegOstIDKLIENT_VSRASCH_DV(TFIBBCDField * DvRegOstIDKLIENT_VSRASCH_DV);

   virtual TFIBBCDField * get_DvRegOstIDDOG_VSRASCH_DV(void);
   virtual void set_DvRegOstIDDOG_VSRASCH_DV(TFIBBCDField * DvRegOstIDDOG_VSRASCH_DV);

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

   virtual float get_SumOstNa(void);
   virtual void set_SumOstNa(float SumOstNa);

   virtual int GetOstatok(void);
   virtual bool AddRecordPrihod(void);
   virtual bool AddRecordRashod(void);
   virtual bool UpdateTableOst(bool provedenie);
   virtual bool CancelDvReg(void);
   virtual bool GetOstatokNa(TDateTime Pos, __int64 idFirm,__int64 idKlient);
};
#define CLSID_TDMRegVsRaschImpl __uuidof(TDMRegVsRaschImpl)
#endif
