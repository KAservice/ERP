#ifndef UREM_DMSprHardwareVZipImplH
#define UREM_DMSprHardwareVZipImplH
#include "IREM_DMSprHardwareVZip.h"
#include "UREM_DMSprHardwareVZip.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMSprHardwareVZipImpl)) TREM_DMSprHardwareVZipImpl : public IREM_DMSprHardwareVZip
{
public:
   TREM_DMSprHardwareVZipImpl();
   ~TREM_DMSprHardwareVZipImpl();
   TREM_DMSprHardwareVZip * Object;
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

//IREM_DMSprHardwareVZip
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBQuery * get_Query(void);
   virtual void set_Query(TpFIBQuery * Query);

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

   virtual TFIBLargeIntField * get_TableOUT_IDHW(void);
   virtual void set_TableOUT_IDHW(TFIBLargeIntField * TableOUT_IDHW);

   virtual TFIBWideStringField * get_TableOUT_NAME_HW(void);
   virtual void set_TableOUT_NAME_HW(TFIBWideStringField * TableOUT_NAME_HW);

   virtual TFIBWideStringField * get_TableOUT_SERNUM1_HW(void);
   virtual void set_TableOUT_SERNUM1_HW(TFIBWideStringField * TableOUT_SERNUM1_HW);

   virtual TFIBWideStringField * get_TableOUT_SERNUM2_HW(void);
   virtual void set_TableOUT_SERNUM2_HW(TFIBWideStringField * TableOUT_SERNUM2_HW);

   virtual TFIBWideStringField * get_TableOUT_MODEL_HW(void);
   virtual void set_TableOUT_MODEL_HW(TFIBWideStringField * TableOUT_MODEL_HW);

   virtual TFIBWideStringField * get_TableOUT_PRMODEL_HW(void);
   virtual void set_TableOUT_PRMODEL_HW(TFIBWideStringField * TableOUT_PRMODEL_HW);

   virtual TFIBIntegerField * get_TableOUT_CODE_HW(void);
   virtual void set_TableOUT_CODE_HW(TFIBIntegerField * TableOUT_CODE_HW);

   virtual TFIBWideStringField * get_TableOUT_ARTIKUL_HW(void);
   virtual void set_TableOUT_ARTIKUL_HW(TFIBWideStringField * TableOUT_ARTIKUL_HW);

   virtual TFIBWideStringField * get_TableOUT_NAME_ENG_HW(void);
   virtual void set_TableOUT_NAME_ENG_HW(TFIBWideStringField * TableOUT_NAME_ENG_HW);

   virtual TFIBSmallIntField * get_TableOUT_FL_ACT_HW(void);
   virtual void set_TableOUT_FL_ACT_HW(TFIBSmallIntField * TableOUT_FL_ACT_HW);

   virtual TFIBSmallIntField * get_TableOUT_FL_REMONT_HW(void);
   virtual void set_TableOUT_FL_REMONT_HW(TFIBSmallIntField * TableOUT_FL_REMONT_HW);

   virtual TFIBSmallIntField * get_TableOUT_FL_NECOND_HW(void);
   virtual void set_TableOUT_FL_NECOND_HW(TFIBSmallIntField * TableOUT_FL_NECOND_HW);

   virtual TFIBWideStringField * get_TableOUT_NAME_BRAND_HW(void);
   virtual void set_TableOUT_NAME_BRAND_HW(TFIBWideStringField * TableOUT_NAME_BRAND_HW);

   virtual TFIBWideStringField * get_TableOUT_NAME_PRODUCER_HW(void);
   virtual void set_TableOUT_NAME_PRODUCER_HW(TFIBWideStringField * TableOUT_NAME_PRODUCER_HW);

   virtual TFIBLargeIntField * get_TableOUT_IDGRPHW(void);
   virtual void set_TableOUT_IDGRPHW(TFIBLargeIntField * TableOUT_IDGRPHW);

   virtual TFIBLargeIntField * get_TableOUT_IDMHRAN(void);
   virtual void set_TableOUT_IDMHRAN(TFIBLargeIntField * TableOUT_IDMHRAN);

   virtual TFIBWideStringField * get_TableOUT_NAME_MHRAN(void);
   virtual void set_TableOUT_NAME_MHRAN(TFIBWideStringField * TableOUT_NAME_MHRAN);

   virtual TFIBSmallIntField * get_TableOUT_FL_OTCH_PROIZV(void);
   virtual void set_TableOUT_FL_OTCH_PROIZV(TFIBSmallIntField * TableOUT_FL_OTCH_PROIZV);

   virtual TFIBSmallIntField * get_TableOUT_FL_NO_RAZBOR(void);
   virtual void set_TableOUT_FL_NO_RAZBOR(TFIBSmallIntField * TableOUT_FL_NO_RAZBOR);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

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

   virtual void OpenTable(__int64 id_grp, bool all);
   virtual __int64 GetIdGrpElementa(__int64 id_element);
   virtual __int64 FindPoName(UnicodeString name);
   virtual bool Table_FindPoSerNum1Like(__int64 id_grp, bool all, UnicodeString ser_num);
   virtual bool Table_FindPoSerNum2Like(__int64 id_grp, bool all, UnicodeString ser_num);
   virtual bool Table_FindPoSerNumStrLike(__int64 id_grp, bool all, UnicodeString ser_num);
};
#define CLSID_TREM_DMSprHardwareVZipImpl __uuidof(TREM_DMSprHardwareVZipImpl)
#endif
