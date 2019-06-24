#ifndef UDMGurOperDiscountCardImplH
#define UDMGurOperDiscountCardImplH
#include "IDMGurOperDiscountCard.h"
#include "UDMGurOperDiscountCard.h"
//---------------------------------------------------------------
class __declspec(uuid("{56974B45-2D95-4D2D-BD79-7749B71C6D07}")) TDMGurOperDiscountCardImpl : public IDMGurOperDiscountCard
{
public:
   TDMGurOperDiscountCardImpl();
   ~TDMGurOperDiscountCardImpl();
   TDMGurOperDiscountCard * Object;
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

//IDMGurOperDiscountCard
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBBCDField * get_TableSUM_GUROPER_DCARD(void);
   virtual void set_TableSUM_GUROPER_DCARD(TFIBBCDField * TableSUM_GUROPER_DCARD);

   virtual TFIBDateTimeField * get_TablePOS_GUROPER_DCARD(void);
   virtual void set_TablePOS_GUROPER_DCARD(TFIBDateTimeField * TablePOS_GUROPER_DCARD);

   virtual TFIBBCDField * get_ElementSUM_GUROPER_DCARD(void);
   virtual void set_ElementSUM_GUROPER_DCARD(TFIBBCDField * ElementSUM_GUROPER_DCARD);

   virtual TFIBDateTimeField * get_ElementPOS_GUROPER_DCARD(void);
   virtual void set_ElementPOS_GUROPER_DCARD(TFIBDateTimeField * ElementPOS_GUROPER_DCARD);

   virtual TpFIBQuery * get_Query(void);
   virtual void set_Query(TpFIBQuery * Query);

   virtual TFIBBCDField * get_ElementID_GUROPER_DCARD(void);
   virtual void set_ElementID_GUROPER_DCARD(TFIBBCDField * ElementID_GUROPER_DCARD);

   virtual TFIBBCDField * get_ElementIDKLIENT_GUROPER_DCARD(void);
   virtual void set_ElementIDKLIENT_GUROPER_DCARD(TFIBBCDField * ElementIDKLIENT_GUROPER_DCARD);

   virtual TFIBBCDField * get_ElementIDSKLAD_GUROPER_DCARD(void);
   virtual void set_ElementIDSKLAD_GUROPER_DCARD(TFIBBCDField * ElementIDSKLAD_GUROPER_DCARD);

   virtual TFIBBCDField * get_ElementIDCARD_GUROPER_DCARD(void);
   virtual void set_ElementIDCARD_GUROPER_DCARD(TFIBBCDField * ElementIDCARD_GUROPER_DCARD);

   virtual TFIBBCDField * get_ElementIDDOC_GUROPER_DCARD(void);
   virtual void set_ElementIDDOC_GUROPER_DCARD(TFIBBCDField * ElementIDDOC_GUROPER_DCARD);

   virtual TFIBBCDField * get_TableID_GUROPER_DCARD(void);
   virtual void set_TableID_GUROPER_DCARD(TFIBBCDField * TableID_GUROPER_DCARD);

   virtual TFIBBCDField * get_TableIDKLIENT_GUROPER_DCARD(void);
   virtual void set_TableIDKLIENT_GUROPER_DCARD(TFIBBCDField * TableIDKLIENT_GUROPER_DCARD);

   virtual TFIBBCDField * get_TableIDSKLAD_GUROPER_DCARD(void);
   virtual void set_TableIDSKLAD_GUROPER_DCARD(TFIBBCDField * TableIDSKLAD_GUROPER_DCARD);

   virtual TFIBBCDField * get_TableIDCARD_GUROPER_DCARD(void);
   virtual void set_TableIDCARD_GUROPER_DCARD(TFIBBCDField * TableIDCARD_GUROPER_DCARD);

   virtual TFIBBCDField * get_TableIDDOC_GUROPER_DCARD(void);
   virtual void set_TableIDDOC_GUROPER_DCARD(TFIBBCDField * TableIDDOC_GUROPER_DCARD);

   virtual TFIBWideStringField * get_TableNAMEKLIENT(void);
   virtual void set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT);

   virtual TFIBWideStringField * get_TableNAMESKLAD(void);
   virtual void set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD);

   virtual TFIBWideStringField * get_TableNAME_SDISCOUNT_CARD(void);
   virtual void set_TableNAME_SDISCOUNT_CARD(TFIBWideStringField * TableNAME_SDISCOUNT_CARD);

   virtual TFIBWideStringField * get_ElementGID_GUROPER_DCARD(void);
   virtual void set_ElementGID_GUROPER_DCARD(TFIBWideStringField * ElementGID_GUROPER_DCARD);

   virtual TFIBWideStringField * get_ElementNAMEKLIENT(void);
   virtual void set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT);

   virtual TFIBWideStringField * get_ElementNAMESKLAD(void);
   virtual void set_ElementNAMESKLAD(TFIBWideStringField * ElementNAMESKLAD);

   virtual TFIBWideStringField * get_ElementNAME_SDISCOUNT_CARD(void);
   virtual void set_ElementNAME_SDISCOUNT_CARD(TFIBWideStringField * ElementNAME_SDISCOUNT_CARD);

   virtual bool get_elSave(void);
   virtual void set_elSave(bool elSave);

   virtual TDateTime get_PosNach(void);
   virtual void set_PosNach(TDateTime PosNach);

   virtual TDateTime get_PosCon(void);
   virtual void set_PosCon(TDateTime PosCon);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(void);
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 id);
   virtual double GetSumPokupok(__int64 id_klient, TDateTime pos_nach);
   virtual __int64 PoiskPoCoduDoc(__int64 code_doc);
};
#define CLSID_TDMGurOperDiscountCardImpl __uuidof(TDMGurOperDiscountCardImpl)
#endif
