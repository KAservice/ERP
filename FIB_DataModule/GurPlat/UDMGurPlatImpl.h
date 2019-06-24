#ifndef UDMGurPlatImplH
#define UDMGurPlatImplH
#include "IDMGurPlat.h"
#include "UDMGurPlat.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMGurPlatImpl)) TDMGurPlatImpl : public IDMGurPlat
{
public:
   TDMGurPlatImpl();
   ~TDMGurPlatImpl();
   TDMGurPlat * Object;
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

//IDMGurPlat
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TpFIBDataSet * get_IBQ(void);
   virtual void set_IBQ(TpFIBDataSet * IBQ);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TpFIBDataSet * get_GurPlat(void);
   virtual void set_GurPlat(TpFIBDataSet * GurPlat);

   virtual TFIBLargeIntField * get_TableID_GURNALPLAT(void);
   virtual void set_TableID_GURNALPLAT(TFIBLargeIntField * TableID_GURNALPLAT);

   virtual TFIBWideStringField * get_TableGID_GURNALPLAT(void);
   virtual void set_TableGID_GURNALPLAT(TFIBWideStringField * TableGID_GURNALPLAT);

   virtual TFIBWideStringField * get_TableCODE_GURNALPLAT(void);
   virtual void set_TableCODE_GURNALPLAT(TFIBWideStringField * TableCODE_GURNALPLAT);

   virtual TFIBWideStringField * get_TableNUMTEL_GURNALPLAT(void);
   virtual void set_TableNUMTEL_GURNALPLAT(TFIBWideStringField * TableNUMTEL_GURNALPLAT);

   virtual TFIBIntegerField * get_TableNUMKV_GURNALPLAT(void);
   virtual void set_TableNUMKV_GURNALPLAT(TFIBIntegerField * TableNUMKV_GURNALPLAT);

   virtual TFIBDateTimeField * get_TablePOS_GURNALPLAT(void);
   virtual void set_TablePOS_GURNALPLAT(TFIBDateTimeField * TablePOS_GURNALPLAT);

   virtual TFIBLargeIntField * get_TableIDUSER_GURNALPLAT(void);
   virtual void set_TableIDUSER_GURNALPLAT(TFIBLargeIntField * TableIDUSER_GURNALPLAT);

   virtual TFIBBCDField * get_TableSUM_GURNALPLAT(void);
   virtual void set_TableSUM_GURNALPLAT(TFIBBCDField * TableSUM_GURNALPLAT);

   virtual TFIBSmallIntField * get_TableOUT_GURNALPLAT(void);
   virtual void set_TableOUT_GURNALPLAT(TFIBSmallIntField * TableOUT_GURNALPLAT);

   virtual TFIBWideStringField * get_TableCODOPER_GURNALPLAT(void);
   virtual void set_TableCODOPER_GURNALPLAT(TFIBWideStringField * TableCODOPER_GURNALPLAT);

   virtual TFIBBCDField * get_TableSUMKL_GURNALPLAT(void);
   virtual void set_TableSUMKL_GURNALPLAT(TFIBBCDField * TableSUMKL_GURNALPLAT);

   virtual TFIBBCDField * get_TablePROCENT_COMMISSION_GURNALPLAT(void);
   virtual void set_TablePROCENT_COMMISSION_GURNALPLAT(TFIBBCDField * TablePROCENT_COMMISSION_GURNALPLAT);

   virtual TFIBLargeIntField * get_TableIDKLIENT_GURNALPLAT(void);
   virtual void set_TableIDKLIENT_GURNALPLAT(TFIBLargeIntField * TableIDKLIENT_GURNALPLAT);

   virtual TFIBLargeIntField * get_TableIDBASE_GURNALPLAT(void);
   virtual void set_TableIDBASE_GURNALPLAT(TFIBLargeIntField * TableIDBASE_GURNALPLAT);

   virtual TFIBLargeIntField * get_TableIDOPERATOR_GURNALPLAT(void);
   virtual void set_TableIDOPERATOR_GURNALPLAT(TFIBLargeIntField * TableIDOPERATOR_GURNALPLAT);

   virtual TFIBLargeIntField * get_TableIDCODETEL_GURNALPLAT(void);
   virtual void set_TableIDCODETEL_GURNALPLAT(TFIBLargeIntField * TableIDCODETEL_GURNALPLAT);

   virtual TFIBWideStringField * get_TableNAME_USER(void);
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER);

   virtual TFIBWideStringField * get_TableNAMEKLIENT(void);
   virtual void set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT);

   virtual TFIBWideStringField * get_TableNAME_CODETEL(void);
   virtual void set_TableNAME_CODETEL(TFIBWideStringField * TableNAME_CODETEL);

   virtual TFIBWideStringField * get_TableCODOPER_CODETEL(void);
   virtual void set_TableCODOPER_CODETEL(TFIBWideStringField * TableCODOPER_CODETEL);

   virtual TFIBLargeIntField * get_GurPlatID_GURNALPLAT(void);
   virtual void set_GurPlatID_GURNALPLAT(TFIBLargeIntField * GurPlatID_GURNALPLAT);

   virtual TFIBLargeIntField * get_ElementID_GURNALPLAT(void);
   virtual void set_ElementID_GURNALPLAT(TFIBLargeIntField * ElementID_GURNALPLAT);

   virtual TFIBWideStringField * get_ElementGID_GURNALPLAT(void);
   virtual void set_ElementGID_GURNALPLAT(TFIBWideStringField * ElementGID_GURNALPLAT);

   virtual TFIBWideStringField * get_ElementCODE_GURNALPLAT(void);
   virtual void set_ElementCODE_GURNALPLAT(TFIBWideStringField * ElementCODE_GURNALPLAT);

   virtual TFIBWideStringField * get_ElementNUMTEL_GURNALPLAT(void);
   virtual void set_ElementNUMTEL_GURNALPLAT(TFIBWideStringField * ElementNUMTEL_GURNALPLAT);

   virtual TFIBIntegerField * get_ElementNUMKV_GURNALPLAT(void);
   virtual void set_ElementNUMKV_GURNALPLAT(TFIBIntegerField * ElementNUMKV_GURNALPLAT);

   virtual TFIBDateTimeField * get_ElementPOS_GURNALPLAT(void);
   virtual void set_ElementPOS_GURNALPLAT(TFIBDateTimeField * ElementPOS_GURNALPLAT);

   virtual TFIBLargeIntField * get_ElementIDUSER_GURNALPLAT(void);
   virtual void set_ElementIDUSER_GURNALPLAT(TFIBLargeIntField * ElementIDUSER_GURNALPLAT);

   virtual TFIBBCDField * get_ElementSUM_GURNALPLAT(void);
   virtual void set_ElementSUM_GURNALPLAT(TFIBBCDField * ElementSUM_GURNALPLAT);

   virtual TFIBSmallIntField * get_ElementOUT_GURNALPLAT(void);
   virtual void set_ElementOUT_GURNALPLAT(TFIBSmallIntField * ElementOUT_GURNALPLAT);

   virtual TFIBWideStringField * get_ElementCODOPER_GURNALPLAT(void);
   virtual void set_ElementCODOPER_GURNALPLAT(TFIBWideStringField * ElementCODOPER_GURNALPLAT);

   virtual TFIBBCDField * get_ElementSUMKL_GURNALPLAT(void);
   virtual void set_ElementSUMKL_GURNALPLAT(TFIBBCDField * ElementSUMKL_GURNALPLAT);

   virtual TFIBBCDField * get_ElementPROCENT_COMMISSION_GURNALPLAT(void);
   virtual void set_ElementPROCENT_COMMISSION_GURNALPLAT(TFIBBCDField * ElementPROCENT_COMMISSION_GURNALPLAT);

   virtual TFIBLargeIntField * get_ElementIDKLIENT_GURNALPLAT(void);
   virtual void set_ElementIDKLIENT_GURNALPLAT(TFIBLargeIntField * ElementIDKLIENT_GURNALPLAT);

   virtual TFIBLargeIntField * get_ElementIDBASE_GURNALPLAT(void);
   virtual void set_ElementIDBASE_GURNALPLAT(TFIBLargeIntField * ElementIDBASE_GURNALPLAT);

   virtual TFIBLargeIntField * get_ElementIDOPERATOR_GURNALPLAT(void);
   virtual void set_ElementIDOPERATOR_GURNALPLAT(TFIBLargeIntField * ElementIDOPERATOR_GURNALPLAT);

   virtual TFIBLargeIntField * get_ElementIDCODETEL_GURNALPLAT(void);
   virtual void set_ElementIDCODETEL_GURNALPLAT(TFIBLargeIntField * ElementIDCODETEL_GURNALPLAT);

   virtual TFIBWideStringField * get_ElementNAME_USER(void);
   virtual void set_ElementNAME_USER(TFIBWideStringField * ElementNAME_USER);

   virtual TFIBWideStringField * get_ElementNAMEKLIENT(void);
   virtual void set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT);

   virtual TFIBWideStringField * get_ElementNAME_CODETEL(void);
   virtual void set_ElementNAME_CODETEL(TFIBWideStringField * ElementNAME_CODETEL);

   virtual TFIBWideStringField * get_ElementCODOPER_CODETEL(void);
   virtual void set_ElementCODOPER_CODETEL(TFIBWideStringField * ElementCODOPER_CODETEL);

   virtual bool get_NoOnlyOut(void);
   virtual void set_NoOnlyOut(bool NoOnlyOut);

   virtual AnsiString get_CodeTel(void);
   virtual void set_CodeTel(AnsiString CodeTel);

   virtual __int64 get_IdPlat(void);
   virtual void set_IdPlat(__int64 IdPlat);

   virtual TDateTime get_PosNach(void);
   virtual void set_PosNach(TDateTime PosNach);

   virtual TDateTime get_PosCon(void);
   virtual void set_PosCon(TDateTime PosCon);

   virtual void OpenTable();
   virtual void UpdateTable(void);
   virtual void  NewElement(void);
   virtual int OpenElement(__int64 id);
   virtual void  SaveElement();
   virtual void DeleteElement(__int64 id);
   virtual void DeleteAllElement(bool NoDeleteEndRecord);
   virtual bool AddPlat(AnsiString cod, AnsiString number, double sum, int number_kv, AnsiString code_operator, double procent_commission, double sum_klient, __int64 id_klient, __int64 id_spr_code_tel);
   virtual bool CheckPlat(AnsiString cod,AnsiString number,double sum,int number_kv, __int64 id_spr_code_tel);
   virtual int GetNumberKv(AnsiString cod);
};
#define CLSID_TDMGurPlatImpl __uuidof(TDMGurPlatImpl)
#endif
