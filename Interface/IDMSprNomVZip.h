#ifndef UIDMSprNomVZipH
#define UIDMSprNomVZipH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprNomVZip)) IDMSprNomVZip : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBQuery * pFIBQuery = {read = get_pFIBQuery , write = set_pFIBQuery};
   virtual TpFIBQuery * get_pFIBQuery(void)=0;
   virtual void set_pFIBQuery(TpFIBQuery * pFIBQuery)=0;

   __property TFIBLargeIntField * TableOUT_IDNOM = {read = get_TableOUT_IDNOM , write = set_TableOUT_IDNOM};
   virtual TFIBLargeIntField * get_TableOUT_IDNOM(void)=0;
   virtual void set_TableOUT_IDNOM(TFIBLargeIntField * TableOUT_IDNOM)=0;

   __property TFIBWideStringField * TableOUT_NAME_NOM = {read = get_TableOUT_NAME_NOM , write = set_TableOUT_NAME_NOM};
   virtual TFIBWideStringField * get_TableOUT_NAME_NOM(void)=0;
   virtual void set_TableOUT_NAME_NOM(TFIBWideStringField * TableOUT_NAME_NOM)=0;

   __property TFIBIntegerField * TableOUT_CODE = {read = get_TableOUT_CODE , write = set_TableOUT_CODE};
   virtual TFIBIntegerField * get_TableOUT_CODE(void)=0;
   virtual void set_TableOUT_CODE(TFIBIntegerField * TableOUT_CODE)=0;

   __property TFIBWideStringField * TableOUT_ARTIKUL = {read = get_TableOUT_ARTIKUL , write = set_TableOUT_ARTIKUL};
   virtual TFIBWideStringField * get_TableOUT_ARTIKUL(void)=0;
   virtual void set_TableOUT_ARTIKUL(TFIBWideStringField * TableOUT_ARTIKUL)=0;

   __property TFIBLargeIntField * TableOUT_IDED = {read = get_TableOUT_IDED , write = set_TableOUT_IDED};
   virtual TFIBLargeIntField * get_TableOUT_IDED(void)=0;
   virtual void set_TableOUT_IDED(TFIBLargeIntField * TableOUT_IDED)=0;

   __property TFIBWideStringField * TableOUT_NAME_ED = {read = get_TableOUT_NAME_ED , write = set_TableOUT_NAME_ED};
   virtual TFIBWideStringField * get_TableOUT_NAME_ED(void)=0;
   virtual void set_TableOUT_NAME_ED(TFIBWideStringField * TableOUT_NAME_ED)=0;

   __property TFIBWideStringField * TableOUT_SHED = {read = get_TableOUT_SHED , write = set_TableOUT_SHED};
   virtual TFIBWideStringField * get_TableOUT_SHED(void)=0;
   virtual void set_TableOUT_SHED(TFIBWideStringField * TableOUT_SHED)=0;

   __property TFIBBCDField * TableOUT_PRICE = {read = get_TableOUT_PRICE , write = set_TableOUT_PRICE};
   virtual TFIBBCDField * get_TableOUT_PRICE(void)=0;
   virtual void set_TableOUT_PRICE(TFIBBCDField * TableOUT_PRICE)=0;

   __property TFIBBCDField * TableOUT_OST = {read = get_TableOUT_OST , write = set_TableOUT_OST};
   virtual TFIBBCDField * get_TableOUT_OST(void)=0;
   virtual void set_TableOUT_OST(TFIBBCDField * TableOUT_OST)=0;

   __property TFIBLargeIntField * TableOUT_IDFIRM = {read = get_TableOUT_IDFIRM , write = set_TableOUT_IDFIRM};
   virtual TFIBLargeIntField * get_TableOUT_IDFIRM(void)=0;
   virtual void set_TableOUT_IDFIRM(TFIBLargeIntField * TableOUT_IDFIRM)=0;

   __property TFIBWideStringField * TableOUT_NAME_FIRM = {read = get_TableOUT_NAME_FIRM , write = set_TableOUT_NAME_FIRM};
   virtual TFIBWideStringField * get_TableOUT_NAME_FIRM(void)=0;
   virtual void set_TableOUT_NAME_FIRM(TFIBWideStringField * TableOUT_NAME_FIRM)=0;

   __property TFIBLargeIntField * TableOUT_IDSKLAD = {read = get_TableOUT_IDSKLAD , write = set_TableOUT_IDSKLAD};
   virtual TFIBLargeIntField * get_TableOUT_IDSKLAD(void)=0;
   virtual void set_TableOUT_IDSKLAD(TFIBLargeIntField * TableOUT_IDSKLAD)=0;

   __property TFIBWideStringField * TableOUT_NAME_SKLAD = {read = get_TableOUT_NAME_SKLAD , write = set_TableOUT_NAME_SKLAD};
   virtual TFIBWideStringField * get_TableOUT_NAME_SKLAD(void)=0;
   virtual void set_TableOUT_NAME_SKLAD(TFIBWideStringField * TableOUT_NAME_SKLAD)=0;

   __property TFIBLargeIntField * TableOUT_IDKLIENT = {read = get_TableOUT_IDKLIENT , write = set_TableOUT_IDKLIENT};
   virtual TFIBLargeIntField * get_TableOUT_IDKLIENT(void)=0;
   virtual void set_TableOUT_IDKLIENT(TFIBLargeIntField * TableOUT_IDKLIENT)=0;

   __property TFIBWideStringField * TableOUT_NAME_KLIENT = {read = get_TableOUT_NAME_KLIENT , write = set_TableOUT_NAME_KLIENT};
   virtual TFIBWideStringField * get_TableOUT_NAME_KLIENT(void)=0;
   virtual void set_TableOUT_NAME_KLIENT(TFIBWideStringField * TableOUT_NAME_KLIENT)=0;

   __property TFIBLargeIntField * TableOUT_IDTNOM = {read = get_TableOUT_IDTNOM , write = set_TableOUT_IDTNOM};
   virtual TFIBLargeIntField * get_TableOUT_IDTNOM(void)=0;
   virtual void set_TableOUT_IDTNOM(TFIBLargeIntField * TableOUT_IDTNOM)=0;

   __property TFIBWideStringField * TableOUT_NAME_TNOM = {read = get_TableOUT_NAME_TNOM , write = set_TableOUT_NAME_TNOM};
   virtual TFIBWideStringField * get_TableOUT_NAME_TNOM(void)=0;
   virtual void set_TableOUT_NAME_TNOM(TFIBWideStringField * TableOUT_NAME_TNOM)=0;

   __property TFIBLargeIntField * TableOUT_IDZ = {read = get_TableOUT_IDZ , write = set_TableOUT_IDZ};
   virtual TFIBLargeIntField * get_TableOUT_IDZ(void)=0;
   virtual void set_TableOUT_IDZ(TFIBLargeIntField * TableOUT_IDZ)=0;

   __property TFIBWideStringField * TableOUT_NAME_Z = {read = get_TableOUT_NAME_Z , write = set_TableOUT_NAME_Z};
   virtual TFIBWideStringField * get_TableOUT_NAME_Z(void)=0;
   virtual void set_TableOUT_NAME_Z(TFIBWideStringField * TableOUT_NAME_Z)=0;

   __property TFIBLargeIntField * TableOUT_IDGRPNOM = {read = get_TableOUT_IDGRPNOM , write = set_TableOUT_IDGRPNOM};
   virtual TFIBLargeIntField * get_TableOUT_IDGRPNOM(void)=0;
   virtual void set_TableOUT_IDGRPNOM(TFIBLargeIntField * TableOUT_IDGRPNOM)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TpFIBDataSet * SpTPrice = {read = get_SpTPrice , write = set_SpTPrice};
   virtual TpFIBDataSet * get_SpTPrice(void)=0;
   virtual void set_SpTPrice(TpFIBDataSet * SpTPrice)=0;

   __property TFIBBCDField * SpTPriceID_TPRICE = {read = get_SpTPriceID_TPRICE , write = set_SpTPriceID_TPRICE};
   virtual TFIBBCDField * get_SpTPriceID_TPRICE(void)=0;
   virtual void set_SpTPriceID_TPRICE(TFIBBCDField * SpTPriceID_TPRICE)=0;

   __property TFIBWideStringField * SpTPriceNAME_TPRICE = {read = get_SpTPriceNAME_TPRICE , write = set_SpTPriceNAME_TPRICE};
   virtual TFIBWideStringField * get_SpTPriceNAME_TPRICE(void)=0;
   virtual void set_SpTPriceNAME_TPRICE(TFIBWideStringField * SpTPriceNAME_TPRICE)=0;

   __property TFIBLargeIntField * TableOUT_IDMHRAN = {read = get_TableOUT_IDMHRAN , write = set_TableOUT_IDMHRAN};
   virtual TFIBLargeIntField * get_TableOUT_IDMHRAN(void)=0;
   virtual void set_TableOUT_IDMHRAN(TFIBLargeIntField * TableOUT_IDMHRAN)=0;

   __property TFIBWideStringField * TableOUT_NAME_MHRAN = {read = get_TableOUT_NAME_MHRAN , write = set_TableOUT_NAME_MHRAN};
   virtual TFIBWideStringField * get_TableOUT_NAME_MHRAN(void)=0;
   virtual void set_TableOUT_NAME_MHRAN(TFIBWideStringField * TableOUT_NAME_MHRAN)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   __property __int64 IdTypePrice = {read = get_IdTypePrice , write = set_IdTypePrice};
   virtual __int64 get_IdTypePrice(void)=0;
   virtual void set_IdTypePrice(__int64 IdTypePrice)=0;

   __property __int64 IdFirm = {read = get_IdFirm , write = set_IdFirm};
   virtual __int64 get_IdFirm(void)=0;
   virtual void set_IdFirm(__int64 IdFirm)=0;

   __property __int64 IdSklad = {read = get_IdSklad , write = set_IdSklad};
   virtual __int64 get_IdSklad(void)=0;
   virtual void set_IdSklad(__int64 IdSklad)=0;

   __property __int64 IdKlient = {read = get_IdKlient , write = set_IdKlient};
   virtual __int64 get_IdKlient(void)=0;
   virtual void set_IdKlient(__int64 IdKlient)=0;

   __property __int64 IdTNom = {read = get_IdTNom , write = set_IdTNom};
   virtual __int64 get_IdTNom(void)=0;
   virtual void set_IdTNom(__int64 IdTNom)=0;

   __property __int64 IdNom = {read = get_IdNom , write = set_IdNom};
   virtual __int64 get_IdNom(void)=0;
   virtual void set_IdNom(__int64 IdNom)=0;

   __property __int64 IdZ = {read = get_IdZ , write = set_IdZ};
   virtual __int64 get_IdZ(void)=0;
   virtual void set_IdZ(__int64 IdZ)=0;

   __property bool CheckOst = {read = get_CheckOst , write = set_CheckOst};
   virtual bool get_CheckOst(void)=0;
   virtual void set_CheckOst(bool CheckOst)=0;

   __property bool OnlyChange = {read = get_OnlyChange , write = set_OnlyChange};
   virtual bool get_OnlyChange(void)=0;
   virtual void set_OnlyChange(bool OnlyChange)=0;

   __property bool PriceSklad = {read = get_PriceSklad , write = set_PriceSklad};
   virtual bool get_PriceSklad(void)=0;
   virtual void set_PriceSklad(bool PriceSklad)=0;

   __property bool OnlyOstatok = {read = get_OnlyOstatok , write = set_OnlyOstatok};
   virtual bool get_OnlyOstatok(void)=0;
   virtual void set_OnlyOstatok(bool OnlyOstatok)=0;

   __property int PorNumberString = {read = get_PorNumberString , write = set_PorNumberString};
   virtual int get_PorNumberString(void)=0;
   virtual void set_PorNumberString(int PorNumberString)=0;

   virtual void OpenTable(__int64 Grp, bool All)=0;
   virtual __int64 FindPoCodu(int Code)=0;
   virtual __int64 FindPoShtrihCodu(AnsiString shtrih_cod)=0;
   virtual __int64 FindPoName(AnsiString name)=0;
   virtual __int64 FindPoArtikulu(UnicodeString artikul)=0;
   virtual int GetIndexTypePrice(void)=0;
   virtual __int64 GetIdBasEd(__int64 id_nom)=0;
   virtual __int64 GetIDElement(String gid)=0;
   virtual AnsiString GetGIDElement(__int64 id)=0;
   virtual __int64 GetIdGrpNom(__int64 id_nom)=0;
};
#define IID_IDMSprNomVZip __uuidof(IDMSprNomVZip)
#endif
