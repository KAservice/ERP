#ifndef UDMSprDiscountCardImplH
#define UDMSprDiscountCardImplH
#include "IDMSprDiscountCard.h"
#include "UDMSprDiscountCard.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprDiscountCardImpl)) TDMSprDiscountCardImpl : public IDMSprDiscountCard
{
public:
   TDMSprDiscountCardImpl();
   ~TDMSprDiscountCardImpl();
   TDMSprDiscountCard * Object;
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

//IDMSprDiscountCard
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

   virtual TFIBIntegerField * get_TableCODE_SDISCOUNT_CARD(void);
   virtual void set_TableCODE_SDISCOUNT_CARD(TFIBIntegerField * TableCODE_SDISCOUNT_CARD);

   virtual TFIBIntegerField * get_TableTYPE_SDISCOUNT_CARD(void);
   virtual void set_TableTYPE_SDISCOUNT_CARD(TFIBIntegerField * TableTYPE_SDISCOUNT_CARD);

   virtual TFIBDateTimeField * get_TableNACH_SDISCOUNT_CARD(void);
   virtual void set_TableNACH_SDISCOUNT_CARD(TFIBDateTimeField * TableNACH_SDISCOUNT_CARD);

   virtual TFIBDateTimeField * get_TableCON_SDISCOUNT_CARD(void);
   virtual void set_TableCON_SDISCOUNT_CARD(TFIBDateTimeField * TableCON_SDISCOUNT_CARD);

   virtual TFIBBCDField * get_TablePRSK_SDISCOUNT_CARD(void);
   virtual void set_TablePRSK_SDISCOUNT_CARD(TFIBBCDField * TablePRSK_SDISCOUNT_CARD);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBIntegerField * get_ElementCODE_SDISCOUNT_CARD(void);
   virtual void set_ElementCODE_SDISCOUNT_CARD(TFIBIntegerField * ElementCODE_SDISCOUNT_CARD);

   virtual TFIBIntegerField * get_ElementTYPE_SDISCOUNT_CARD(void);
   virtual void set_ElementTYPE_SDISCOUNT_CARD(TFIBIntegerField * ElementTYPE_SDISCOUNT_CARD);

   virtual TFIBDateTimeField * get_ElementNACH_SDISCOUNT_CARD(void);
   virtual void set_ElementNACH_SDISCOUNT_CARD(TFIBDateTimeField * ElementNACH_SDISCOUNT_CARD);

   virtual TFIBDateTimeField * get_ElementCON_SDISCOUNT_CARD(void);
   virtual void set_ElementCON_SDISCOUNT_CARD(TFIBDateTimeField * ElementCON_SDISCOUNT_CARD);

   virtual TFIBBCDField * get_ElementPRSK_SDISCOUNT_CARD(void);
   virtual void set_ElementPRSK_SDISCOUNT_CARD(TFIBBCDField * ElementPRSK_SDISCOUNT_CARD);

   virtual TFIBIntegerField * get_TableACT_SDISCOUNT_CARD(void);
   virtual void set_TableACT_SDISCOUNT_CARD(TFIBIntegerField * TableACT_SDISCOUNT_CARD);

   virtual TFIBIntegerField * get_ElementACT_SDISCOUNT_CARD(void);
   virtual void set_ElementACT_SDISCOUNT_CARD(TFIBIntegerField * ElementACT_SDISCOUNT_CARD);

   virtual TpFIBQuery * get_Query(void);
   virtual void set_Query(TpFIBQuery * Query);

   virtual TFIBSmallIntField * get_ElementFL_DISC_SDISCOUNT_CARD(void);
   virtual void set_ElementFL_DISC_SDISCOUNT_CARD(TFIBSmallIntField * ElementFL_DISC_SDISCOUNT_CARD);

   virtual TFIBSmallIntField * get_ElementFL_PLAT_SDISCOUNT_CARD(void);
   virtual void set_ElementFL_PLAT_SDISCOUNT_CARD(TFIBSmallIntField * ElementFL_PLAT_SDISCOUNT_CARD);

   virtual TFIBSmallIntField * get_ElementFL_CREDIT_SDISCOUNT_CARD(void);
   virtual void set_ElementFL_CREDIT_SDISCOUNT_CARD(TFIBSmallIntField * ElementFL_CREDIT_SDISCOUNT_CARD);

   virtual TFIBLargeIntField * get_TableID_SDISCOUNT_CARD(void);
   virtual void set_TableID_SDISCOUNT_CARD(TFIBLargeIntField * TableID_SDISCOUNT_CARD);

   virtual TFIBLargeIntField * get_TableIDKLIENT_SDISCOUNT_CARD(void);
   virtual void set_TableIDKLIENT_SDISCOUNT_CARD(TFIBLargeIntField * TableIDKLIENT_SDISCOUNT_CARD);

   virtual TFIBLargeIntField * get_TableIDVID_SDISCOUNT_CARD(void);
   virtual void set_TableIDVID_SDISCOUNT_CARD(TFIBLargeIntField * TableIDVID_SDISCOUNT_CARD);

   virtual TFIBLargeIntField * get_TableIDBASE_SDISCOUNT_CARD(void);
   virtual void set_TableIDBASE_SDISCOUNT_CARD(TFIBLargeIntField * TableIDBASE_SDISCOUNT_CARD);

   virtual TFIBSmallIntField * get_TableFL_DISC_SDISCOUNT_CARD(void);
   virtual void set_TableFL_DISC_SDISCOUNT_CARD(TFIBSmallIntField * TableFL_DISC_SDISCOUNT_CARD);

   virtual TFIBSmallIntField * get_TableFL_PLAT_SDISCOUNT_CARD(void);
   virtual void set_TableFL_PLAT_SDISCOUNT_CARD(TFIBSmallIntField * TableFL_PLAT_SDISCOUNT_CARD);

   virtual TFIBSmallIntField * get_TableFL_CREDIT_SDISCOUNT_CARD(void);
   virtual void set_TableFL_CREDIT_SDISCOUNT_CARD(TFIBSmallIntField * TableFL_CREDIT_SDISCOUNT_CARD);

   virtual TFIBLargeIntField * get_TableIDDOG_SDISCOUNT_CARD(void);
   virtual void set_TableIDDOG_SDISCOUNT_CARD(TFIBLargeIntField * TableIDDOG_SDISCOUNT_CARD);

   virtual TFIBLargeIntField * get_ElementID_SDISCOUNT_CARD(void);
   virtual void set_ElementID_SDISCOUNT_CARD(TFIBLargeIntField * ElementID_SDISCOUNT_CARD);

   virtual TFIBLargeIntField * get_ElementIDKLIENT_SDISCOUNT_CARD(void);
   virtual void set_ElementIDKLIENT_SDISCOUNT_CARD(TFIBLargeIntField * ElementIDKLIENT_SDISCOUNT_CARD);

   virtual TFIBLargeIntField * get_ElementIDVID_SDISCOUNT_CARD(void);
   virtual void set_ElementIDVID_SDISCOUNT_CARD(TFIBLargeIntField * ElementIDVID_SDISCOUNT_CARD);

   virtual TFIBLargeIntField * get_ElementIDBASE_SDISCOUNT_CARD(void);
   virtual void set_ElementIDBASE_SDISCOUNT_CARD(TFIBLargeIntField * ElementIDBASE_SDISCOUNT_CARD);

   virtual TFIBLargeIntField * get_ElementIDDOG_SDISCOUNT_CARD(void);
   virtual void set_ElementIDDOG_SDISCOUNT_CARD(TFIBLargeIntField * ElementIDDOG_SDISCOUNT_CARD);

   virtual TFIBWideStringField * get_TableNAME_SDISCOUNT_CARD(void);
   virtual void set_TableNAME_SDISCOUNT_CARD(TFIBWideStringField * TableNAME_SDISCOUNT_CARD);

   virtual TFIBWideStringField * get_TableNAME_SVID_DCARD(void);
   virtual void set_TableNAME_SVID_DCARD(TFIBWideStringField * TableNAME_SVID_DCARD);

   virtual TFIBWideStringField * get_ElementGID_SDISCOUNT_CARD(void);
   virtual void set_ElementGID_SDISCOUNT_CARD(TFIBWideStringField * ElementGID_SDISCOUNT_CARD);

   virtual TFIBWideStringField * get_ElementNAME_SDISCOUNT_CARD(void);
   virtual void set_ElementNAME_SDISCOUNT_CARD(TFIBWideStringField * ElementNAME_SDISCOUNT_CARD);

   virtual TFIBWideStringField * get_ElementNAMEKLIENT(void);
   virtual void set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT);

   virtual TFIBWideStringField * get_ElementNAME_SVID_DCARD(void);
   virtual void set_ElementNAME_SVID_DCARD(TFIBWideStringField * ElementNAME_SVID_DCARD);

   virtual TFIBWideStringField * get_ElementNAME_SDOG(void);
   virtual void set_ElementNAME_SDOG(TFIBWideStringField * ElementNAME_SDOG);

   virtual TFIBWideStringField * get_TableSHCODE_SDISCOUNT_CARD(void);
   virtual void set_TableSHCODE_SDISCOUNT_CARD(TFIBWideStringField * TableSHCODE_SDISCOUNT_CARD);

   virtual TFIBWideStringField * get_ElementSHCODE_SDISCOUNT_CARD(void);
   virtual void set_ElementSHCODE_SDISCOUNT_CARD(TFIBWideStringField * ElementSHCODE_SDISCOUNT_CARD);

   virtual TFIBWideStringField * get_TableGID_SDISCOUNT_CARD(void);
   virtual void set_TableGID_SDISCOUNT_CARD(TFIBWideStringField * TableGID_SDISCOUNT_CARD);

   virtual TFIBSmallIntField * get_TableSINGLE_SDISCOUNT_CARD(void);
   virtual void set_TableSINGLE_SDISCOUNT_CARD(TFIBSmallIntField * TableSINGLE_SDISCOUNT_CARD);

   virtual TFIBSmallIntField * get_ElementSINGLE_SDISCOUNT_CARD(void);
   virtual void set_ElementSINGLE_SDISCOUNT_CARD(TFIBSmallIntField * ElementSINGLE_SDISCOUNT_CARD);

   virtual __int64 get_IdKlient(void);
   virtual void set_IdKlient(__int64 IdKlient);

   virtual bool get_elSave(void);
   virtual void set_elSave(bool elSave);

   virtual void OpenTable(__int64 id_klient);
   virtual int OpenElement(__int64 id);
   virtual bool NewElement(__int64 id_klient);
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 id);
   virtual __int64 PoiskPoCodu(AnsiString code);
   virtual __int64 PoiskPoShCodu(AnsiString sh_code);
   virtual int GetCodeCard(void);
   virtual bool CheckBarCode(__int64 id_card, AnsiString sh);
   virtual bool CheckCode(__int64 id_card, int code);
};
#define CLSID_TDMSprDiscountCardImpl __uuidof(TDMSprDiscountCardImpl)
#endif
