#ifndef UDMSprVesNomImplH
#define UDMSprVesNomImplH
#include "IDMSprVesNom.h"
#include "UDMSprVesNom.h"
//---------------------------------------------------------------
class __declspec(uuid("{E10C682C-BEEA-4AC8-A123-C3AE8AB06AEC}"))TDMSprVesNomImpl : public IDMSprVesNom
{
public:
   TDMSprVesNomImpl();
   ~TDMSprVesNomImpl();
   TDMSprVesNom * Object;
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

//IDMSprVesNom
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TFIBIntegerField * get_TableCODE_SVESNOM(void);
   virtual void set_TableCODE_SVESNOM(TFIBIntegerField * TableCODE_SVESNOM);

   virtual TFIBBCDField * get_TableZNACH_PRICE(void);
   virtual void set_TableZNACH_PRICE(TFIBBCDField * TableZNACH_PRICE);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBIntegerField * get_ElementCODE_SVESNOM(void);
   virtual void set_ElementCODE_SVESNOM(TFIBIntegerField * ElementCODE_SVESNOM);

   virtual TpFIBDataSet * get_MaxCode(void);
   virtual void set_MaxCode(TpFIBDataSet * MaxCode);

   virtual TpFIBDataSet * get_SpTPrice(void);
   virtual void set_SpTPrice(TpFIBDataSet * SpTPrice);

   virtual TFIBIntegerField * get_MaxCodeMAXCODE(void);
   virtual void set_MaxCodeMAXCODE(TFIBIntegerField * MaxCodeMAXCODE);

   virtual TFIBBCDField * get_SpTPriceID_TPRICE(void);
   virtual void set_SpTPriceID_TPRICE(TFIBBCDField * SpTPriceID_TPRICE);

   virtual TFIBBCDField * get_ElementID_SVESNOM(void);
   virtual void set_ElementID_SVESNOM(TFIBBCDField * ElementID_SVESNOM);

   virtual TFIBBCDField * get_ElementIDSCALE_SVESNOM(void);
   virtual void set_ElementIDSCALE_SVESNOM(TFIBBCDField * ElementIDSCALE_SVESNOM);

   virtual TFIBBCDField * get_ElementIDNOM_SVESNOM(void);
   virtual void set_ElementIDNOM_SVESNOM(TFIBBCDField * ElementIDNOM_SVESNOM);

   virtual TFIBBCDField * get_TableID_SVESNOM(void);
   virtual void set_TableID_SVESNOM(TFIBBCDField * TableID_SVESNOM);

   virtual TFIBBCDField * get_TableIDNOM_SVESNOM(void);
   virtual void set_TableIDNOM_SVESNOM(TFIBBCDField * TableIDNOM_SVESNOM);

   virtual TFIBBCDField * get_TableIDSCALE_SVESNOM(void);
   virtual void set_TableIDSCALE_SVESNOM(TFIBBCDField * TableIDSCALE_SVESNOM);

   virtual TFIBBCDField * get_TableIDGRP_SVESNOM(void);
   virtual void set_TableIDGRP_SVESNOM(TFIBBCDField * TableIDGRP_SVESNOM);

   virtual TFIBBCDField * get_ElementIDGRP_SVESNOM(void);
   virtual void set_ElementIDGRP_SVESNOM(TFIBBCDField * ElementIDGRP_SVESNOM);

   virtual TFIBWideStringField * get_TableGID_SVESNOM(void);
   virtual void set_TableGID_SVESNOM(TFIBWideStringField * TableGID_SVESNOM);

   virtual TFIBBCDField * get_TableIDBASE_SVESNOM(void);
   virtual void set_TableIDBASE_SVESNOM(TFIBBCDField * TableIDBASE_SVESNOM);

   virtual TFIBWideStringField * get_TableNAMENOM(void);
   virtual void set_TableNAMENOM(TFIBWideStringField * TableNAMENOM);

   virtual TFIBWideStringField * get_TableNAMEED(void);
   virtual void set_TableNAMEED(TFIBWideStringField * TableNAMEED);

   virtual TFIBWideStringField * get_ElementGID_SVESNOM(void);
   virtual void set_ElementGID_SVESNOM(TFIBWideStringField * ElementGID_SVESNOM);

   virtual TFIBWideStringField * get_SpTPriceNAME_TPRICE(void);
   virtual void set_SpTPriceNAME_TPRICE(TFIBWideStringField * SpTPriceNAME_TPRICE);

   virtual __int64 get_IdScale(void);
   virtual void set_IdScale(__int64 IdScale);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual __int64 get_IdTypePrice(void);
   virtual void set_IdTypePrice(__int64 IdTypePrice);

   virtual int get_NumberAddElement(void);
   virtual void set_NumberAddElement(int NumberAddElement);

   virtual void OpenTable(__int64 id_scale, __int64 id_grp, __int64 id_type_price, bool all);
   virtual bool SaveIsmen();
   virtual void CancelIsmen();
   virtual void NewElement(__int64 id_scale, __int64 id_grp);
   virtual bool OpenElement(__int64 id);
   virtual void DeleteElement();
   virtual bool InsertElement(__int64 id_scale, __int64 id_grp, __int64 id_nom);
   virtual void ChancheGrp(__int64 id_new_grp);
   virtual __int64 FindElementPoScaleAndNom(__int64 id_scale, __int64 id_nom);
};
#define CLSID_TDMSprVesNomImpl __uuidof(TDMSprVesNomImpl)
#endif
