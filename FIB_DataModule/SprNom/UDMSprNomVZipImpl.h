#ifndef UDMSprNomVZipImplH
#define UDMSprNomVZipImplH
#include "IDMSprNomVZip.h"
#include "UDMSprNomVZip.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprNomVZipImpl)) TDMSprNomVZipImpl : public IDMSprNomVZip
{
public:
   TDMSprNomVZipImpl();
   ~TDMSprNomVZipImpl();
   TDMSprNomVZip * Object;
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

//IDMSprNomVZip
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBQuery * get_pFIBQuery(void);
   virtual void set_pFIBQuery(TpFIBQuery * pFIBQuery);

   virtual TFIBLargeIntField * get_TableOUT_IDNOM(void);
   virtual void set_TableOUT_IDNOM(TFIBLargeIntField * TableOUT_IDNOM);

   virtual TFIBWideStringField * get_TableOUT_NAME_NOM(void);
   virtual void set_TableOUT_NAME_NOM(TFIBWideStringField * TableOUT_NAME_NOM);

   virtual TFIBIntegerField * get_TableOUT_CODE(void);
   virtual void set_TableOUT_CODE(TFIBIntegerField * TableOUT_CODE);

   virtual TFIBWideStringField * get_TableOUT_ARTIKUL(void);
   virtual void set_TableOUT_ARTIKUL(TFIBWideStringField * TableOUT_ARTIKUL);

   virtual TFIBLargeIntField * get_TableOUT_IDED(void);
   virtual void set_TableOUT_IDED(TFIBLargeIntField * TableOUT_IDED);

   virtual TFIBWideStringField * get_TableOUT_NAME_ED(void);
   virtual void set_TableOUT_NAME_ED(TFIBWideStringField * TableOUT_NAME_ED);

   virtual TFIBWideStringField * get_TableOUT_SHED(void);
   virtual void set_TableOUT_SHED(TFIBWideStringField * TableOUT_SHED);

   virtual TFIBBCDField * get_TableOUT_PRICE(void);
   virtual void set_TableOUT_PRICE(TFIBBCDField * TableOUT_PRICE);

   virtual TFIBBCDField * get_TableOUT_OST(void);
   virtual void set_TableOUT_OST(TFIBBCDField * TableOUT_OST);

   virtual TFIBLargeIntField * get_TableOUT_IDFIRM(void);
   virtual void set_TableOUT_IDFIRM(TFIBLargeIntField * TableOUT_IDFIRM);

   virtual TFIBWideStringField * get_TableOUT_NAME_FIRM(void);
   virtual void set_TableOUT_NAME_FIRM(TFIBWideStringField * TableOUT_NAME_FIRM);

   virtual TFIBLargeIntField * get_TableOUT_IDSKLAD(void);
   virtual void set_TableOUT_IDSKLAD(TFIBLargeIntField * TableOUT_IDSKLAD);

   virtual TFIBWideStringField * get_TableOUT_NAME_SKLAD(void);
   virtual void set_TableOUT_NAME_SKLAD(TFIBWideStringField * TableOUT_NAME_SKLAD);

   virtual TFIBLargeIntField * get_TableOUT_IDKLIENT(void);
   virtual void set_TableOUT_IDKLIENT(TFIBLargeIntField * TableOUT_IDKLIENT);

   virtual TFIBWideStringField * get_TableOUT_NAME_KLIENT(void);
   virtual void set_TableOUT_NAME_KLIENT(TFIBWideStringField * TableOUT_NAME_KLIENT);

   virtual TFIBLargeIntField * get_TableOUT_IDTNOM(void);
   virtual void set_TableOUT_IDTNOM(TFIBLargeIntField * TableOUT_IDTNOM);

   virtual TFIBWideStringField * get_TableOUT_NAME_TNOM(void);
   virtual void set_TableOUT_NAME_TNOM(TFIBWideStringField * TableOUT_NAME_TNOM);

   virtual TFIBLargeIntField * get_TableOUT_IDZ(void);
   virtual void set_TableOUT_IDZ(TFIBLargeIntField * TableOUT_IDZ);

   virtual TFIBWideStringField * get_TableOUT_NAME_Z(void);
   virtual void set_TableOUT_NAME_Z(TFIBWideStringField * TableOUT_NAME_Z);

   virtual TFIBLargeIntField * get_TableOUT_IDGRPNOM(void);
   virtual void set_TableOUT_IDGRPNOM(TFIBLargeIntField * TableOUT_IDGRPNOM);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TpFIBDataSet * get_SpTPrice(void);
   virtual void set_SpTPrice(TpFIBDataSet * SpTPrice);

   virtual TFIBBCDField * get_SpTPriceID_TPRICE(void);
   virtual void set_SpTPriceID_TPRICE(TFIBBCDField * SpTPriceID_TPRICE);

   virtual TFIBWideStringField * get_SpTPriceNAME_TPRICE(void);
   virtual void set_SpTPriceNAME_TPRICE(TFIBWideStringField * SpTPriceNAME_TPRICE);

   virtual TFIBLargeIntField * get_TableOUT_IDMHRAN(void);
   virtual void set_TableOUT_IDMHRAN(TFIBLargeIntField * TableOUT_IDMHRAN);

   virtual TFIBWideStringField * get_TableOUT_NAME_MHRAN(void);
   virtual void set_TableOUT_NAME_MHRAN(TFIBWideStringField * TableOUT_NAME_MHRAN);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual __int64 get_IdTypePrice(void);
   virtual void set_IdTypePrice(__int64 IdTypePrice);

   virtual __int64 get_IdFirm(void);
   virtual void set_IdFirm(__int64 IdFirm);

   virtual __int64 get_IdSklad(void);
   virtual void set_IdSklad(__int64 IdSklad);

   virtual __int64 get_IdKlient(void);
   virtual void set_IdKlient(__int64 IdKlient);

   virtual __int64 get_IdTNom(void);
   virtual void set_IdTNom(__int64 IdTNom);

   virtual __int64 get_IdNom(void);
   virtual void set_IdNom(__int64 IdNom);

   virtual __int64 get_IdZ(void);
   virtual void set_IdZ(__int64 IdZ);

   virtual bool get_CheckOst(void);
   virtual void set_CheckOst(bool CheckOst);

   virtual bool get_OnlyChange(void);
   virtual void set_OnlyChange(bool OnlyChange);

   virtual bool get_PriceSklad(void);
   virtual void set_PriceSklad(bool PriceSklad);

   virtual bool get_OnlyOstatok(void);
   virtual void set_OnlyOstatok(bool OnlyOstatok);

   virtual int get_PorNumberString(void);
   virtual void set_PorNumberString(int PorNumberString);

   virtual void OpenTable(__int64 Grp, bool All);
   virtual __int64 FindPoCodu(int Code);
   virtual __int64 FindPoShtrihCodu(AnsiString shtrih_cod);
   virtual __int64 FindPoName(AnsiString name);
   virtual __int64 FindPoArtikulu(UnicodeString artikul);
   virtual int GetIndexTypePrice(void);
   virtual __int64 GetIdBasEd(__int64 id_nom);
   virtual __int64 GetIDElement(String gid);
   virtual AnsiString GetGIDElement(__int64 id);
   virtual __int64 GetIdGrpNom(__int64 id_nom);
};
#define CLSID_TDMSprNomVZipImpl __uuidof(TDMSprNomVZipImpl)
#endif
