#ifndef UDMSprNacenkaImplH
#define UDMSprNacenkaImplH
#include "IDMSprNacenka.h"
#include "UDMSprNacenka.h"
//---------------------------------------------------------------
class __declspec(uuid("{F1EE76E6-E1BE-4C0B-A80E-0D634C9E90E5}")) TDMSprNacenkaImpl : public IDMSprNacenka
{
public:
   TDMSprNacenkaImpl();
   ~TDMSprNacenkaImpl();
   TDMSprNacenka * Object;
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

//IDMSprNacenka
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

   virtual TFIBBCDField * get_TableVALUE_SNACENKA(void);
   virtual void set_TableVALUE_SNACENKA(TFIBBCDField * TableVALUE_SNACENKA);

   virtual TFIBBCDField * get_ElementVALUE_SNACENKA(void);
   virtual void set_ElementVALUE_SNACENKA(TFIBBCDField * ElementVALUE_SNACENKA);

   virtual TFIBIntegerField * get_TableOKR_SNACENKA(void);
   virtual void set_TableOKR_SNACENKA(TFIBIntegerField * TableOKR_SNACENKA);

   virtual TFIBIntegerField * get_ElementOKR_SNACENKA(void);
   virtual void set_ElementOKR_SNACENKA(TFIBIntegerField * ElementOKR_SNACENKA);

   virtual TFIBBCDField * get_TableID_SNACENKA(void);
   virtual void set_TableID_SNACENKA(TFIBBCDField * TableID_SNACENKA);

   virtual TFIBBCDField * get_TableIDGRPNOM_SNACENKA(void);
   virtual void set_TableIDGRPNOM_SNACENKA(TFIBBCDField * TableIDGRPNOM_SNACENKA);

   virtual TFIBBCDField * get_TableIDTPRICE_SNACENKA(void);
   virtual void set_TableIDTPRICE_SNACENKA(TFIBBCDField * TableIDTPRICE_SNACENKA);

   virtual TFIBBCDField * get_ElementID_SNACENKA(void);
   virtual void set_ElementID_SNACENKA(TFIBBCDField * ElementID_SNACENKA);

   virtual TFIBBCDField * get_ElementIDGRPNOM_SNACENKA(void);
   virtual void set_ElementIDGRPNOM_SNACENKA(TFIBBCDField * ElementIDGRPNOM_SNACENKA);

   virtual TFIBBCDField * get_ElementIDTPRICE_SNACENKA(void);
   virtual void set_ElementIDTPRICE_SNACENKA(TFIBBCDField * ElementIDTPRICE_SNACENKA);

   virtual TFIBWideStringField * get_TableGID_SNACENKA(void);
   virtual void set_TableGID_SNACENKA(TFIBWideStringField * TableGID_SNACENKA);

   virtual TFIBBCDField * get_TableIDBASE_SNACENKA(void);
   virtual void set_TableIDBASE_SNACENKA(TFIBBCDField * TableIDBASE_SNACENKA);

   virtual TFIBWideStringField * get_TableNAME_TPRICE(void);
   virtual void set_TableNAME_TPRICE(TFIBWideStringField * TableNAME_TPRICE);

   virtual TFIBWideStringField * get_ElementGID_SNACENKA(void);
   virtual void set_ElementGID_SNACENKA(TFIBWideStringField * ElementGID_SNACENKA);

   virtual __int64 get_IdGrpNom(void);
   virtual void set_IdGrpNom(__int64 IdGrpNom);

   virtual __int64 get_IdTypePrice(void);
   virtual void set_IdTypePrice(__int64 IdTypePrice);

   virtual void OpenTable(__int64 id_grp_nom);
   virtual void SaveIsmen(void);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(void);
   virtual void SaveElement(void);
   virtual void DeleteElement(__int64 id);
   virtual int FindElement(__int64 id_type_price, __int64 id_grp_nom);
   virtual void CancelIsmen(void);
};
#define CLSID_TDMSprNacenkaImpl __uuidof(TDMSprNacenkaImpl)
#endif
