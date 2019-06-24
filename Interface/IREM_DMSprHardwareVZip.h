#ifndef UIREM_DMSprHardwareVZipH
#define UIREM_DMSprHardwareVZipH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMSprHardwareVZip)) IREM_DMSprHardwareVZip : public IMainInterface
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

   __property TpFIBQuery * Query = {read = get_Query , write = set_Query};
   virtual TpFIBQuery * get_Query(void)=0;
   virtual void set_Query(TpFIBQuery * Query)=0;

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

   __property TFIBLargeIntField * TableOUT_IDHW = {read = get_TableOUT_IDHW , write = set_TableOUT_IDHW};
   virtual TFIBLargeIntField * get_TableOUT_IDHW(void)=0;
   virtual void set_TableOUT_IDHW(TFIBLargeIntField * TableOUT_IDHW)=0;

   __property TFIBWideStringField * TableOUT_NAME_HW = {read = get_TableOUT_NAME_HW , write = set_TableOUT_NAME_HW};
   virtual TFIBWideStringField * get_TableOUT_NAME_HW(void)=0;
   virtual void set_TableOUT_NAME_HW(TFIBWideStringField * TableOUT_NAME_HW)=0;

   __property TFIBWideStringField * TableOUT_SERNUM1_HW = {read = get_TableOUT_SERNUM1_HW , write = set_TableOUT_SERNUM1_HW};
   virtual TFIBWideStringField * get_TableOUT_SERNUM1_HW(void)=0;
   virtual void set_TableOUT_SERNUM1_HW(TFIBWideStringField * TableOUT_SERNUM1_HW)=0;

   __property TFIBWideStringField * TableOUT_SERNUM2_HW = {read = get_TableOUT_SERNUM2_HW , write = set_TableOUT_SERNUM2_HW};
   virtual TFIBWideStringField * get_TableOUT_SERNUM2_HW(void)=0;
   virtual void set_TableOUT_SERNUM2_HW(TFIBWideStringField * TableOUT_SERNUM2_HW)=0;

   __property TFIBWideStringField * TableOUT_MODEL_HW = {read = get_TableOUT_MODEL_HW , write = set_TableOUT_MODEL_HW};
   virtual TFIBWideStringField * get_TableOUT_MODEL_HW(void)=0;
   virtual void set_TableOUT_MODEL_HW(TFIBWideStringField * TableOUT_MODEL_HW)=0;

   __property TFIBWideStringField * TableOUT_PRMODEL_HW = {read = get_TableOUT_PRMODEL_HW , write = set_TableOUT_PRMODEL_HW};
   virtual TFIBWideStringField * get_TableOUT_PRMODEL_HW(void)=0;
   virtual void set_TableOUT_PRMODEL_HW(TFIBWideStringField * TableOUT_PRMODEL_HW)=0;

   __property TFIBIntegerField * TableOUT_CODE_HW = {read = get_TableOUT_CODE_HW , write = set_TableOUT_CODE_HW};
   virtual TFIBIntegerField * get_TableOUT_CODE_HW(void)=0;
   virtual void set_TableOUT_CODE_HW(TFIBIntegerField * TableOUT_CODE_HW)=0;

   __property TFIBWideStringField * TableOUT_ARTIKUL_HW = {read = get_TableOUT_ARTIKUL_HW , write = set_TableOUT_ARTIKUL_HW};
   virtual TFIBWideStringField * get_TableOUT_ARTIKUL_HW(void)=0;
   virtual void set_TableOUT_ARTIKUL_HW(TFIBWideStringField * TableOUT_ARTIKUL_HW)=0;

   __property TFIBWideStringField * TableOUT_NAME_ENG_HW = {read = get_TableOUT_NAME_ENG_HW , write = set_TableOUT_NAME_ENG_HW};
   virtual TFIBWideStringField * get_TableOUT_NAME_ENG_HW(void)=0;
   virtual void set_TableOUT_NAME_ENG_HW(TFIBWideStringField * TableOUT_NAME_ENG_HW)=0;

   __property TFIBSmallIntField * TableOUT_FL_ACT_HW = {read = get_TableOUT_FL_ACT_HW , write = set_TableOUT_FL_ACT_HW};
   virtual TFIBSmallIntField * get_TableOUT_FL_ACT_HW(void)=0;
   virtual void set_TableOUT_FL_ACT_HW(TFIBSmallIntField * TableOUT_FL_ACT_HW)=0;

   __property TFIBSmallIntField * TableOUT_FL_REMONT_HW = {read = get_TableOUT_FL_REMONT_HW , write = set_TableOUT_FL_REMONT_HW};
   virtual TFIBSmallIntField * get_TableOUT_FL_REMONT_HW(void)=0;
   virtual void set_TableOUT_FL_REMONT_HW(TFIBSmallIntField * TableOUT_FL_REMONT_HW)=0;

   __property TFIBSmallIntField * TableOUT_FL_NECOND_HW = {read = get_TableOUT_FL_NECOND_HW , write = set_TableOUT_FL_NECOND_HW};
   virtual TFIBSmallIntField * get_TableOUT_FL_NECOND_HW(void)=0;
   virtual void set_TableOUT_FL_NECOND_HW(TFIBSmallIntField * TableOUT_FL_NECOND_HW)=0;

   __property TFIBWideStringField * TableOUT_NAME_BRAND_HW = {read = get_TableOUT_NAME_BRAND_HW , write = set_TableOUT_NAME_BRAND_HW};
   virtual TFIBWideStringField * get_TableOUT_NAME_BRAND_HW(void)=0;
   virtual void set_TableOUT_NAME_BRAND_HW(TFIBWideStringField * TableOUT_NAME_BRAND_HW)=0;

   __property TFIBWideStringField * TableOUT_NAME_PRODUCER_HW = {read = get_TableOUT_NAME_PRODUCER_HW , write = set_TableOUT_NAME_PRODUCER_HW};
   virtual TFIBWideStringField * get_TableOUT_NAME_PRODUCER_HW(void)=0;
   virtual void set_TableOUT_NAME_PRODUCER_HW(TFIBWideStringField * TableOUT_NAME_PRODUCER_HW)=0;

   __property TFIBLargeIntField * TableOUT_IDGRPHW = {read = get_TableOUT_IDGRPHW , write = set_TableOUT_IDGRPHW};
   virtual TFIBLargeIntField * get_TableOUT_IDGRPHW(void)=0;
   virtual void set_TableOUT_IDGRPHW(TFIBLargeIntField * TableOUT_IDGRPHW)=0;

   __property TFIBLargeIntField * TableOUT_IDMHRAN = {read = get_TableOUT_IDMHRAN , write = set_TableOUT_IDMHRAN};
   virtual TFIBLargeIntField * get_TableOUT_IDMHRAN(void)=0;
   virtual void set_TableOUT_IDMHRAN(TFIBLargeIntField * TableOUT_IDMHRAN)=0;

   __property TFIBWideStringField * TableOUT_NAME_MHRAN = {read = get_TableOUT_NAME_MHRAN , write = set_TableOUT_NAME_MHRAN};
   virtual TFIBWideStringField * get_TableOUT_NAME_MHRAN(void)=0;
   virtual void set_TableOUT_NAME_MHRAN(TFIBWideStringField * TableOUT_NAME_MHRAN)=0;

   __property TFIBSmallIntField * TableOUT_FL_OTCH_PROIZV = {read = get_TableOUT_FL_OTCH_PROIZV , write = set_TableOUT_FL_OTCH_PROIZV};
   virtual TFIBSmallIntField * get_TableOUT_FL_OTCH_PROIZV(void)=0;
   virtual void set_TableOUT_FL_OTCH_PROIZV(TFIBSmallIntField * TableOUT_FL_OTCH_PROIZV)=0;

   __property TFIBSmallIntField * TableOUT_FL_NO_RAZBOR = {read = get_TableOUT_FL_NO_RAZBOR , write = set_TableOUT_FL_NO_RAZBOR};
   virtual TFIBSmallIntField * get_TableOUT_FL_NO_RAZBOR(void)=0;
   virtual void set_TableOUT_FL_NO_RAZBOR(TFIBSmallIntField * TableOUT_FL_NO_RAZBOR)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

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

   virtual void OpenTable(__int64 id_grp, bool all)=0;
   virtual __int64 GetIdGrpElementa(__int64 id_element)=0;
   virtual __int64 FindPoName(UnicodeString name)=0;
   virtual bool Table_FindPoSerNum1Like(__int64 id_grp, bool all, UnicodeString ser_num)=0;
   virtual bool Table_FindPoSerNum2Like(__int64 id_grp, bool all, UnicodeString ser_num)=0;
   virtual bool Table_FindPoSerNumStrLike(__int64 id_grp, bool all, UnicodeString ser_num)=0;
};
#define IID_IREM_DMSprHardwareVZip __uuidof(IREM_DMSprHardwareVZip)
#endif
