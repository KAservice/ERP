#ifndef UREM_DMSprKKTDvImplH
#define UREM_DMSprKKTDvImplH
#include "IREM_DMSprKKTDv.h"
#include "UREM_DMSprKKTDv.h"
//---------------------------------------------------------------
class __declspec(uuid("{6F40F2BA-DB10-4E6B-AAA5-853571E47E75}")) TREM_DMSprKKTDvImpl : public IREM_DMSprKKTDv
{
public:
   TREM_DMSprKKTDvImpl();
   ~TREM_DMSprKKTDvImpl();
   TREM_DMSprKKTDv * Object;
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

//IREM_DMSprKKTDv
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

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBLargeIntField * get_TableID_REM_SKKT_DV(void);
   virtual void set_TableID_REM_SKKT_DV(TFIBLargeIntField * TableID_REM_SKKT_DV);

   virtual TFIBLargeIntField * get_TableIDBASE_REM_SKKT_DV(void);
   virtual void set_TableIDBASE_REM_SKKT_DV(TFIBLargeIntField * TableIDBASE_REM_SKKT_DV);

   virtual TFIBLargeIntField * get_TableIDKKT_REM_SKKT_DV(void);
   virtual void set_TableIDKKT_REM_SKKT_DV(TFIBLargeIntField * TableIDKKT_REM_SKKT_DV);

   virtual TFIBDateTimeField * get_TablePOS_REM_SKKT_DV(void);
   virtual void set_TablePOS_REM_SKKT_DV(TFIBDateTimeField * TablePOS_REM_SKKT_DV);

   virtual TFIBLargeIntField * get_TableIDKLIENT_REM_SKKT_DV(void);
   virtual void set_TableIDKLIENT_REM_SKKT_DV(TFIBLargeIntField * TableIDKLIENT_REM_SKKT_DV);

   virtual TFIBWideStringField * get_TableMESTOUST_REM_SKKT_DV(void);
   virtual void set_TableMESTOUST_REM_SKKT_DV(TFIBWideStringField * TableMESTOUST_REM_SKKT_DV);

   virtual TFIBWideStringField * get_TableREGNUM_REM_SKKT_DV(void);
   virtual void set_TableREGNUM_REM_SKKT_DV(TFIBWideStringField * TableREGNUM_REM_SKKT_DV);

   virtual TFIBWideStringField * get_TableCBKGR_REM_SKKT_DV(void);
   virtual void set_TableCBKGR_REM_SKKT_DV(TFIBWideStringField * TableCBKGR_REM_SKKT_DV);

   virtual TFIBWideStringField * get_TableCBKCO_REM_SKKT_DV(void);
   virtual void set_TableCBKCO_REM_SKKT_DV(TFIBWideStringField * TableCBKCO_REM_SKKT_DV);

   virtual TFIBWideStringField * get_TableNUMCONTRACT_REM_SKKT_DV(void);
   virtual void set_TableNUMCONTRACT_REM_SKKT_DV(TFIBWideStringField * TableNUMCONTRACT_REM_SKKT_DV);

   virtual TFIBDateField * get_TableDATECONTRACT_REM_SKKT_DV(void);
   virtual void set_TableDATECONTRACT_REM_SKKT_DV(TFIBDateField * TableDATECONTRACT_REM_SKKT_DV);

   virtual TFIBBCDField * get_TableSUMCONTRACT_REM_SKKT_DV(void);
   virtual void set_TableSUMCONTRACT_REM_SKKT_DV(TFIBBCDField * TableSUMCONTRACT_REM_SKKT_DV);

   virtual TFIBWideStringField * get_TableEKLZ_SERNUM_REM_SKKT_DV(void);
   virtual void set_TableEKLZ_SERNUM_REM_SKKT_DV(TFIBWideStringField * TableEKLZ_SERNUM_REM_SKKT_DV);

   virtual TFIBWideStringField * get_TableEKLZ_REGNUM_REM_SKKT_DV(void);
   virtual void set_TableEKLZ_REGNUM_REM_SKKT_DV(TFIBWideStringField * TableEKLZ_REGNUM_REM_SKKT_DV);

   virtual TFIBDateField * get_TableEKLZ_ACT_REM_SKKT_DV(void);
   virtual void set_TableEKLZ_ACT_REM_SKKT_DV(TFIBDateField * TableEKLZ_ACT_REM_SKKT_DV);

   virtual TFIBLargeIntField * get_TableIDUSER_REM_SKKT_DV(void);
   virtual void set_TableIDUSER_REM_SKKT_DV(TFIBLargeIntField * TableIDUSER_REM_SKKT_DV);

   virtual TFIBWideStringField * get_TableNAMEKLIENT(void);
   virtual void set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT);

   virtual TFIBWideStringField * get_TableNAME_USER(void);
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER);

   virtual TFIBLargeIntField * get_ElementID_REM_SKKT_DV(void);
   virtual void set_ElementID_REM_SKKT_DV(TFIBLargeIntField * ElementID_REM_SKKT_DV);

   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SKKT_DV(void);
   virtual void set_ElementIDBASE_REM_SKKT_DV(TFIBLargeIntField * ElementIDBASE_REM_SKKT_DV);

   virtual TFIBLargeIntField * get_ElementIDKKT_REM_SKKT_DV(void);
   virtual void set_ElementIDKKT_REM_SKKT_DV(TFIBLargeIntField * ElementIDKKT_REM_SKKT_DV);

   virtual TFIBDateTimeField * get_ElementPOS_REM_SKKT_DV(void);
   virtual void set_ElementPOS_REM_SKKT_DV(TFIBDateTimeField * ElementPOS_REM_SKKT_DV);

   virtual TFIBLargeIntField * get_ElementIDKLIENT_REM_SKKT_DV(void);
   virtual void set_ElementIDKLIENT_REM_SKKT_DV(TFIBLargeIntField * ElementIDKLIENT_REM_SKKT_DV);

   virtual TFIBWideStringField * get_ElementMESTOUST_REM_SKKT_DV(void);
   virtual void set_ElementMESTOUST_REM_SKKT_DV(TFIBWideStringField * ElementMESTOUST_REM_SKKT_DV);

   virtual TFIBWideStringField * get_ElementREGNUM_REM_SKKT_DV(void);
   virtual void set_ElementREGNUM_REM_SKKT_DV(TFIBWideStringField * ElementREGNUM_REM_SKKT_DV);

   virtual TFIBWideStringField * get_ElementCBKGR_REM_SKKT_DV(void);
   virtual void set_ElementCBKGR_REM_SKKT_DV(TFIBWideStringField * ElementCBKGR_REM_SKKT_DV);

   virtual TFIBWideStringField * get_ElementCBKCO_REM_SKKT_DV(void);
   virtual void set_ElementCBKCO_REM_SKKT_DV(TFIBWideStringField * ElementCBKCO_REM_SKKT_DV);

   virtual TFIBWideStringField * get_ElementNUMCONTRACT_REM_SKKT_DV(void);
   virtual void set_ElementNUMCONTRACT_REM_SKKT_DV(TFIBWideStringField * ElementNUMCONTRACT_REM_SKKT_DV);

   virtual TFIBDateField * get_ElementDATECONTRACT_REM_SKKT_DV(void);
   virtual void set_ElementDATECONTRACT_REM_SKKT_DV(TFIBDateField * ElementDATECONTRACT_REM_SKKT_DV);

   virtual TFIBBCDField * get_ElementSUMCONTRACT_REM_SKKT_DV(void);
   virtual void set_ElementSUMCONTRACT_REM_SKKT_DV(TFIBBCDField * ElementSUMCONTRACT_REM_SKKT_DV);

   virtual TFIBWideStringField * get_ElementEKLZ_SERNUM_REM_SKKT_DV(void);
   virtual void set_ElementEKLZ_SERNUM_REM_SKKT_DV(TFIBWideStringField * ElementEKLZ_SERNUM_REM_SKKT_DV);

   virtual TFIBWideStringField * get_ElementEKLZ_REGNUM_REM_SKKT_DV(void);
   virtual void set_ElementEKLZ_REGNUM_REM_SKKT_DV(TFIBWideStringField * ElementEKLZ_REGNUM_REM_SKKT_DV);

   virtual TFIBDateField * get_ElementEKLZ_ACT_REM_SKKT_DV(void);
   virtual void set_ElementEKLZ_ACT_REM_SKKT_DV(TFIBDateField * ElementEKLZ_ACT_REM_SKKT_DV);

   virtual TFIBLargeIntField * get_ElementIDUSER_REM_SKKT_DV(void);
   virtual void set_ElementIDUSER_REM_SKKT_DV(TFIBLargeIntField * ElementIDUSER_REM_SKKT_DV);

   virtual TFIBWideStringField * get_ElementNAMEKLIENT(void);
   virtual void set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT);

   virtual TFIBWideStringField * get_ElementNAME_USER(void);
   virtual void set_ElementNAME_USER(TFIBWideStringField * ElementNAME_USER);

   virtual __int64 get_IdOwner(void);
   virtual void set_IdOwner(__int64 IdOwner);

   virtual void OpenTable(__int64 id_owner);
   virtual int OpenElement(__int64 id);
   virtual bool NewElement(__int64 id_owner);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual bool AddRecordDv(TDateTime pos,__int64 id_owner,__int64 id_klient,UnicodeString mesto_ust,UnicodeString reg_num,UnicodeString svk_gr,UnicodeString svk_so,UnicodeString num_contract,TDate date_contract,double sum_contract,UnicodeString eklz_ser_num,UnicodeString eklz_reg_num,TDate eklz_act,__int64 id_user);
};
#define CLSID_TREM_DMSprKKTDvImpl __uuidof(TREM_DMSprKKTDvImpl)
#endif
