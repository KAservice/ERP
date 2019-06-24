#ifndef UDMXSetupObmenImplH
#define UDMXSetupObmenImplH
#include "IDMXSetupObmen.h"
#include "UDMXSetupObmen.h"
//---------------------------------------------------------------
class __declspec(uuid("{8DC83FCA-2DA7-4604-98CA-AC24BEF1C501}")) TDMXSetupObmenImpl : public IDMXSetupObmen
{
public:
   TDMXSetupObmenImpl();
   ~TDMXSetupObmenImpl();
   TDMXSetupObmen * Object;
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

//IDMXSetupObmen
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TFIBBCDField * get_TableID_XSETUP_OBMEN(void);
   virtual void set_TableID_XSETUP_OBMEN(TFIBBCDField * TableID_XSETUP_OBMEN);

   virtual TFIBBCDField * get_TableIDBASE_OBMEN_XSETUP_OBMEN(void);
   virtual void set_TableIDBASE_OBMEN_XSETUP_OBMEN(TFIBBCDField * TableIDBASE_OBMEN_XSETUP_OBMEN);

   virtual TFIBBCDField * get_TableIDTISM_XSETUP_OBMEN(void);
   virtual void set_TableIDTISM_XSETUP_OBMEN(TFIBBCDField * TableIDTISM_XSETUP_OBMEN);

   virtual TFIBSmallIntField * get_TableALLDOC_XSETUP_OBMEN(void);
   virtual void set_TableALLDOC_XSETUP_OBMEN(TFIBSmallIntField * TableALLDOC_XSETUP_OBMEN);

   virtual TFIBSmallIntField * get_TableOUTNAC_XSETUP_OBMEN(void);
   virtual void set_TableOUTNAC_XSETUP_OBMEN(TFIBSmallIntField * TableOUTNAC_XSETUP_OBMEN);

   virtual TFIBSmallIntField * get_TableOUTZPRICE_XSETUP_OBMEN(void);
   virtual void set_TableOUTZPRICE_XSETUP_OBMEN(TFIBSmallIntField * TableOUTZPRICE_XSETUP_OBMEN);

   virtual TFIBSmallIntField * get_TableNOEDIT_XSETUP_OBMEN(void);
   virtual void set_TableNOEDIT_XSETUP_OBMEN(TFIBSmallIntField * TableNOEDIT_XSETUP_OBMEN);

   virtual TFIBBCDField * get_TableIDBASE_XSETUP_OBMEN(void);
   virtual void set_TableIDBASE_XSETUP_OBMEN(TFIBBCDField * TableIDBASE_XSETUP_OBMEN);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TFIBBCDField * get_ElementID_XSETUP_OBMEN(void);
   virtual void set_ElementID_XSETUP_OBMEN(TFIBBCDField * ElementID_XSETUP_OBMEN);

   virtual TFIBBCDField * get_ElementIDBASE_OBMEN_XSETUP_OBMEN(void);
   virtual void set_ElementIDBASE_OBMEN_XSETUP_OBMEN(TFIBBCDField * ElementIDBASE_OBMEN_XSETUP_OBMEN);

   virtual TFIBBCDField * get_ElementIDTISM_XSETUP_OBMEN(void);
   virtual void set_ElementIDTISM_XSETUP_OBMEN(TFIBBCDField * ElementIDTISM_XSETUP_OBMEN);

   virtual TFIBSmallIntField * get_ElementALLDOC_XSETUP_OBMEN(void);
   virtual void set_ElementALLDOC_XSETUP_OBMEN(TFIBSmallIntField * ElementALLDOC_XSETUP_OBMEN);

   virtual TFIBSmallIntField * get_ElementOUTNAC_XSETUP_OBMEN(void);
   virtual void set_ElementOUTNAC_XSETUP_OBMEN(TFIBSmallIntField * ElementOUTNAC_XSETUP_OBMEN);

   virtual TFIBSmallIntField * get_ElementOUTZPRICE_XSETUP_OBMEN(void);
   virtual void set_ElementOUTZPRICE_XSETUP_OBMEN(TFIBSmallIntField * ElementOUTZPRICE_XSETUP_OBMEN);

   virtual TFIBSmallIntField * get_ElementNOEDIT_XSETUP_OBMEN(void);
   virtual void set_ElementNOEDIT_XSETUP_OBMEN(TFIBSmallIntField * ElementNOEDIT_XSETUP_OBMEN);

   virtual TFIBBCDField * get_ElementIDBASE_XSETUP_OBMEN(void);
   virtual void set_ElementIDBASE_XSETUP_OBMEN(TFIBBCDField * ElementIDBASE_XSETUP_OBMEN);

   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TpFIBDataSet * get_BaseForObmen(void);
   virtual void set_BaseForObmen(TpFIBDataSet * BaseForObmen);

   virtual TpFIBDataSet * get_TypePriceForObmen(void);
   virtual void set_TypePriceForObmen(TpFIBDataSet * TypePriceForObmen);

   virtual TDataSource * get_DataSourceBaseForObmen(void);
   virtual void set_DataSourceBaseForObmen(TDataSource * DataSourceBaseForObmen);

   virtual TDataSource * get_DataSourceTypePriceForObmen(void);
   virtual void set_DataSourceTypePriceForObmen(TDataSource * DataSourceTypePriceForObmen);

   virtual TFIBBCDField * get_BaseForObmenID_XBASE_FOR_OBMEN(void);
   virtual void set_BaseForObmenID_XBASE_FOR_OBMEN(TFIBBCDField * BaseForObmenID_XBASE_FOR_OBMEN);

   virtual TFIBBCDField * get_BaseForObmenIDBASE_OBMEN_XBASE_FOR_OBMEN(void);
   virtual void set_BaseForObmenIDBASE_OBMEN_XBASE_FOR_OBMEN(TFIBBCDField * BaseForObmenIDBASE_OBMEN_XBASE_FOR_OBMEN);

   virtual TFIBBCDField * get_BaseForObmenIDBASE_OBJECT_XBASE_FOR_OBMEN(void);
   virtual void set_BaseForObmenIDBASE_OBJECT_XBASE_FOR_OBMEN(TFIBBCDField * BaseForObmenIDBASE_OBJECT_XBASE_FOR_OBMEN);

   virtual TFIBBCDField * get_BaseForObmenIDBASE_XBASE_FOR_OBMEN(void);
   virtual void set_BaseForObmenIDBASE_XBASE_FOR_OBMEN(TFIBBCDField * BaseForObmenIDBASE_XBASE_FOR_OBMEN);

   virtual TFIBBCDField * get_TypePriceForObmenID_XTPRICE_FOR_OBMEN(void);
   virtual void set_TypePriceForObmenID_XTPRICE_FOR_OBMEN(TFIBBCDField * TypePriceForObmenID_XTPRICE_FOR_OBMEN);

   virtual TFIBBCDField * get_TypePriceForObmenIDBASE_OBMEN_XTPRICE_FOR_OBMEN(void);
   virtual void set_TypePriceForObmenIDBASE_OBMEN_XTPRICE_FOR_OBMEN(TFIBBCDField * TypePriceForObmenIDBASE_OBMEN_XTPRICE_FOR_OBMEN);

   virtual TFIBBCDField * get_TypePriceForObmenIDTPRICE_XTPRICE_FOR_OBMEN(void);
   virtual void set_TypePriceForObmenIDTPRICE_XTPRICE_FOR_OBMEN(TFIBBCDField * TypePriceForObmenIDTPRICE_XTPRICE_FOR_OBMEN);

   virtual TFIBBCDField * get_TypePriceForObmenIDBASE_XTPRICE_FOR_OBMEN(void);
   virtual void set_TypePriceForObmenIDBASE_XTPRICE_FOR_OBMEN(TFIBBCDField * TypePriceForObmenIDBASE_XTPRICE_FOR_OBMEN);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBBCDField * get_ElementIDFIRST_DO_XSETUP_OBMEN(void);
   virtual void set_ElementIDFIRST_DO_XSETUP_OBMEN(TFIBBCDField * ElementIDFIRST_DO_XSETUP_OBMEN);

   virtual TFIBIntegerField * get_ElementOPER_XSETUP_OBMEN(void);
   virtual void set_ElementOPER_XSETUP_OBMEN(TFIBIntegerField * ElementOPER_XSETUP_OBMEN);

   virtual TFIBWideStringField * get_TableNAME_SINFBASE_OBMEN(void);
   virtual void set_TableNAME_SINFBASE_OBMEN(TFIBWideStringField * TableNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_ElementNAME_SINFBASE_OBMEN(void);
   virtual void set_ElementNAME_SINFBASE_OBMEN(TFIBWideStringField * ElementNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_BaseForObmenNAME_SINFBASE_OBMEN(void);
   virtual void set_BaseForObmenNAME_SINFBASE_OBMEN(TFIBWideStringField * BaseForObmenNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_TypePriceForObmenNAME_TPRICE(void);
   virtual void set_TypePriceForObmenNAME_TPRICE(TFIBWideStringField * TypePriceForObmenNAME_TPRICE);

   virtual __int64 get_IdBase(void);
   virtual void set_IdBase(__int64 IdBase);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual void OpenTable(void);
   virtual bool OpenElement(__int64 id_base);
   virtual void NewElement(void);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id_base);
   virtual bool AddBase(__int64 id_base, AnsiString name_base);
   virtual bool AddTypePrice(__int64 id_type_price, AnsiString name_type_price);
   virtual bool DeleteBase(void);
   virtual bool DeleteTypePrice(void);
};
#define CLSID_TDMXSetupObmenImpl __uuidof(TDMXSetupObmenImpl)
#endif
