#ifndef UDMSprGrafikPlatImplH
#define UDMSprGrafikPlatImplH
#include "IDMSprGrafikPlat.h"
#include "UDMSprGrafikPlat.h"
//---------------------------------------------------------------
class __declspec(uuid("{AA33E29D-C622-4AE0-9293-7E3AA8F26181}")) TDMSprGrafikPlatImpl : public IDMSprGrafikPlat
{
public:
   TDMSprGrafikPlatImpl();
   ~TDMSprGrafikPlatImpl();
   TDMSprGrafikPlat * Object;
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

//IDMSprGrafikPlat
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TFIBDateField * get_TableDO_SGRPLAT(void);
   virtual void set_TableDO_SGRPLAT(TFIBDateField * TableDO_SGRPLAT);

   virtual TFIBBCDField * get_TableSUM_SGRPLAT(void);
   virtual void set_TableSUM_SGRPLAT(TFIBBCDField * TableSUM_SGRPLAT);

   virtual TFIBBCDField * get_TableID_SGRPLAT(void);
   virtual void set_TableID_SGRPLAT(TFIBBCDField * TableID_SGRPLAT);

   virtual TFIBBCDField * get_TableIDDOG_SGRPLAT(void);
   virtual void set_TableIDDOG_SGRPLAT(TFIBBCDField * TableIDDOG_SGRPLAT);

   virtual TFIBWideStringField * get_TableGID_SGRPLAT(void);
   virtual void set_TableGID_SGRPLAT(TFIBWideStringField * TableGID_SGRPLAT);

   virtual __int64 get_IdDogovor(void);
   virtual void set_IdDogovor(__int64 IdDogovor);

   virtual void OpenTable(__int64 idDogovor);
   virtual void NewElement(__int64 idDogovor);
   virtual void DeleteElement();
   virtual void SaveIsmen();
   virtual void CancelIsmen();
};
#define CLSID_TDMSprGrafikPlatImpl __uuidof(TDMSprGrafikPlatImpl)
#endif
