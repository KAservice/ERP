#ifndef UDMSprPriceScheduleImplH
#define UDMSprPriceScheduleImplH
#include "IDMSprPriceSchedule.h"
#include "UDMSprPriceSchedule.h"
//---------------------------------------------------------------
class __declspec(uuid("{D986BAC3-71D9-4368-B31E-50DA013E003D}")) TDMSprPriceScheduleImpl : public IDMSprPriceSchedule
{
public:
   TDMSprPriceScheduleImpl();
   ~TDMSprPriceScheduleImpl();
   TDMSprPriceSchedule * Object;
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

//IDMSprPriceSchedule
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

   virtual TpFIBDataSet * get_TPrice(void);
   virtual void set_TPrice(TpFIBDataSet * TPrice);

   virtual TpFIBQuery * get_Query(void);
   virtual void set_Query(TpFIBQuery * Query);

   virtual TpFIBDataSet * get_SpisokEd(void);
   virtual void set_SpisokEd(TpFIBDataSet * SpisokEd);

   virtual TFIBBCDField * get_SpisokEdIDED(void);
   virtual void set_SpisokEdIDED(TFIBBCDField * SpisokEdIDED);

   virtual TFIBBCDField * get_SpisokEdKFED(void);
   virtual void set_SpisokEdKFED(TFIBBCDField * SpisokEdKFED);

   virtual TDataSource * get_DataSourceSpisokEd(void);
   virtual void set_DataSourceSpisokEd(TDataSource * DataSourceSpisokEd);

   virtual TDataSource * get_DataSourceTypePrice(void);
   virtual void set_DataSourceTypePrice(TDataSource * DataSourceTypePrice);

   virtual TFIBBCDField * get_TableID_SPRICE_SCHEDULE(void);
   virtual void set_TableID_SPRICE_SCHEDULE(TFIBBCDField * TableID_SPRICE_SCHEDULE);

   virtual TFIBBCDField * get_TableIDBASE_SPRICE_SCHEDULE(void);
   virtual void set_TableIDBASE_SPRICE_SCHEDULE(TFIBBCDField * TableIDBASE_SPRICE_SCHEDULE);

   virtual TFIBBCDField * get_TableIDNOM_SPRICE_SCHEDULE(void);
   virtual void set_TableIDNOM_SPRICE_SCHEDULE(TFIBBCDField * TableIDNOM_SPRICE_SCHEDULE);

   virtual TFIBBCDField * get_TableIDTYPE_SPRICE_SCHEDULE(void);
   virtual void set_TableIDTYPE_SPRICE_SCHEDULE(TFIBBCDField * TableIDTYPE_SPRICE_SCHEDULE);

   virtual TFIBBCDField * get_TableIDED_SPRICE_SCHEDULE(void);
   virtual void set_TableIDED_SPRICE_SCHEDULE(TFIBBCDField * TableIDED_SPRICE_SCHEDULE);

   virtual TFIBBCDField * get_TableVALUE_SPRICE_SCHEDULE(void);
   virtual void set_TableVALUE_SPRICE_SCHEDULE(TFIBBCDField * TableVALUE_SPRICE_SCHEDULE);

   virtual TFIBDateTimeField * get_TablePOS_SPRICE_SCHEDULE(void);
   virtual void set_TablePOS_SPRICE_SCHEDULE(TFIBDateTimeField * TablePOS_SPRICE_SCHEDULE);

   virtual TFIBBCDField * get_ElementID_SPRICE_SCHEDULE(void);
   virtual void set_ElementID_SPRICE_SCHEDULE(TFIBBCDField * ElementID_SPRICE_SCHEDULE);

   virtual TFIBBCDField * get_ElementIDBASE_SPRICE_SCHEDULE(void);
   virtual void set_ElementIDBASE_SPRICE_SCHEDULE(TFIBBCDField * ElementIDBASE_SPRICE_SCHEDULE);

   virtual TFIBBCDField * get_ElementIDNOM_SPRICE_SCHEDULE(void);
   virtual void set_ElementIDNOM_SPRICE_SCHEDULE(TFIBBCDField * ElementIDNOM_SPRICE_SCHEDULE);

   virtual TFIBBCDField * get_ElementIDTYPE_SPRICE_SCHEDULE(void);
   virtual void set_ElementIDTYPE_SPRICE_SCHEDULE(TFIBBCDField * ElementIDTYPE_SPRICE_SCHEDULE);

   virtual TFIBBCDField * get_ElementIDED_SPRICE_SCHEDULE(void);
   virtual void set_ElementIDED_SPRICE_SCHEDULE(TFIBBCDField * ElementIDED_SPRICE_SCHEDULE);

   virtual TFIBBCDField * get_ElementVALUE_SPRICE_SCHEDULE(void);
   virtual void set_ElementVALUE_SPRICE_SCHEDULE(TFIBBCDField * ElementVALUE_SPRICE_SCHEDULE);

   virtual TFIBDateTimeField * get_ElementPOS_SPRICE_SCHEDULE(void);
   virtual void set_ElementPOS_SPRICE_SCHEDULE(TFIBDateTimeField * ElementPOS_SPRICE_SCHEDULE);

   virtual TFIBWideStringField * get_TableNAME_TPRICE(void);
   virtual void set_TableNAME_TPRICE(TFIBWideStringField * TableNAME_TPRICE);

   virtual TFIBWideStringField * get_SpisokEdNAMEED(void);
   virtual void set_SpisokEdNAMEED(TFIBWideStringField * SpisokEdNAMEED);

   virtual __int64 get_IdNom(void);
   virtual void set_IdNom(__int64 IdNom);

   virtual __int64 get_IdTypePrice(void);
   virtual void set_IdTypePrice(__int64 IdTypePrice);

   virtual __int64 get_IdBasEd(void);
   virtual void set_IdBasEd(__int64 IdBasEd);

   virtual void OpenTable(__int64 id_nom);
   virtual bool SaveIsmen(void);
   virtual void CancelIsmen(void);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(void);
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 id);
   virtual void UpdateSpisokEd(__int64 id_nom);
   virtual double GetValuePrice(__int64 id_nom,	__int64 id_type_price,__int64 id_ed, TDateTime pos);
};
#define CLSID_TDMSprPriceScheduleImpl __uuidof(TDMSprPriceScheduleImpl)
#endif
