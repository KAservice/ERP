#ifndef UDMSprPriceImplH
#define UDMSprPriceImplH
#include "IDMSprPrice.h"
#include "UDMSprPrice.h"
//---------------------------------------------------------------
class __declspec(uuid("{F5797974-E34B-43BC-A2CA-0D8A7ABBD5C7}")) TDMSprPriceImpl : public IDMSprPrice
{
public:
   TDMSprPriceImpl();
   ~TDMSprPriceImpl();
   TDMSprPrice * Object;
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

//IDMSprPrice
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TFIBBCDField * get_TableZNACH_PRICE(void);
   virtual void set_TableZNACH_PRICE(TFIBBCDField * TableZNACH_PRICE);

   virtual TFIBBCDField * get_ElementZNACH_PRICE(void);
   virtual void set_ElementZNACH_PRICE(TFIBBCDField * ElementZNACH_PRICE);

   virtual TpFIBDataSet * get_TPrice(void);
   virtual void set_TPrice(TpFIBDataSet * TPrice);

   virtual TFIBSmallIntField * get_TableFL_CHANGE_PRICE(void);
   virtual void set_TableFL_CHANGE_PRICE(TFIBSmallIntField * TableFL_CHANGE_PRICE);

   virtual TFIBSmallIntField * get_ElementFL_CHANGE_PRICE(void);
   virtual void set_ElementFL_CHANGE_PRICE(TFIBSmallIntField * ElementFL_CHANGE_PRICE);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBBCDField * get_ElementID_PRICE(void);
   virtual void set_ElementID_PRICE(TFIBBCDField * ElementID_PRICE);

   virtual TFIBBCDField * get_ElementIDNOM_PRICE(void);
   virtual void set_ElementIDNOM_PRICE(TFIBBCDField * ElementIDNOM_PRICE);

   virtual TFIBBCDField * get_ElementIDTYPE_PRICE(void);
   virtual void set_ElementIDTYPE_PRICE(TFIBBCDField * ElementIDTYPE_PRICE);

   virtual TFIBBCDField * get_ElementIDED_SPRICE(void);
   virtual void set_ElementIDED_SPRICE(TFIBBCDField * ElementIDED_SPRICE);

   virtual TpFIBDataSet * get_SpisokEd(void);
   virtual void set_SpisokEd(TpFIBDataSet * SpisokEd);

   virtual TFIBBCDField * get_SpisokEdKFED(void);
   virtual void set_SpisokEdKFED(TFIBBCDField * SpisokEdKFED);

   virtual TDataSource * get_DataSourceSpisokEd(void);
   virtual void set_DataSourceSpisokEd(TDataSource * DataSourceSpisokEd);

   virtual TFIBLargeIntField * get_TPriceID_TPRICE(void);
   virtual void set_TPriceID_TPRICE(TFIBLargeIntField * TPriceID_TPRICE);

   virtual TFIBLargeIntField * get_TableID_PRICE(void);
   virtual void set_TableID_PRICE(TFIBLargeIntField * TableID_PRICE);

   virtual TFIBLargeIntField * get_TableIDNOM_PRICE(void);
   virtual void set_TableIDNOM_PRICE(TFIBLargeIntField * TableIDNOM_PRICE);

   virtual TFIBLargeIntField * get_TableIDTYPE_PRICE(void);
   virtual void set_TableIDTYPE_PRICE(TFIBLargeIntField * TableIDTYPE_PRICE);

   virtual TFIBLargeIntField * get_TableIDED_SPRICE(void);
   virtual void set_TableIDED_SPRICE(TFIBLargeIntField * TableIDED_SPRICE);

   virtual TFIBLargeIntField * get_SpisokEdIDED(void);
   virtual void set_SpisokEdIDED(TFIBLargeIntField * SpisokEdIDED);

   virtual TFIBWideStringField * get_TableGID_SPRICE(void);
   virtual void set_TableGID_SPRICE(TFIBWideStringField * TableGID_SPRICE);

   virtual TFIBLargeIntField * get_TableIDBASE_SPRICE(void);
   virtual void set_TableIDBASE_SPRICE(TFIBLargeIntField * TableIDBASE_SPRICE);

   virtual TFIBWideStringField * get_TableNAME_TPRICE(void);
   virtual void set_TableNAME_TPRICE(TFIBWideStringField * TableNAME_TPRICE);

   virtual TFIBWideStringField * get_ElementGID_SPRICE(void);
   virtual void set_ElementGID_SPRICE(TFIBWideStringField * ElementGID_SPRICE);

   virtual TFIBWideStringField * get_TPriceNAME_TPRICE(void);
   virtual void set_TPriceNAME_TPRICE(TFIBWideStringField * TPriceNAME_TPRICE);

   virtual TFIBWideStringField * get_SpisokEdNAMEED(void);
   virtual void set_SpisokEdNAMEED(TFIBWideStringField * SpisokEdNAMEED);

   virtual TStringField * get_TableNAMETPRICE(void);
   virtual void set_TableNAMETPRICE(TStringField * TableNAMETPRICE);

   virtual __int64 get_IdNom(void);
   virtual void set_IdNom(__int64 IdNom);

   virtual __int64 get_IdTypePrice(void);
   virtual void set_IdTypePrice(__int64 IdTypePrice);

   virtual __int64 get_IdBasEd(void);
   virtual void set_IdBasEd(__int64 IdBasEd);

   virtual void OpenTable(__int64 IdNom);
   virtual bool SaveIsmen(void);
   virtual void CancelIsmen(void);
   virtual int OpenElement(__int64 Id);
   virtual void NewElement(void);
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 Id);
   virtual __int64 FindElement(__int64 idTypePrice, __int64 idNom);
   virtual __int64 FindElementPoEd(__int64 idTypePrice, __int64 idNom, __int64 id_ed);
   virtual double GetValuePrice(__int64 id_type_price,__int64 id_nom,__int64 id_ed,double kf_ed,__int64 id_bas_ed);
   virtual void UpdateSpisokEd(__int64 id_nom);
};
#define CLSID_TDMSprPriceImpl __uuidof(TDMSprPriceImpl)
#endif
