#ifndef UDMSprModImplH
#define UDMSprModImplH
#include "IDMSprMod.h"
#include "UDMSprMod.h"
//---------------------------------------------------------------
class __declspec(uuid("{ED3438E0-72FF-4161-8368-2FABA20CE6D1}")) TDMSprModImpl : public IDMSprMod
{
public:
   TDMSprModImpl();
   ~TDMSprModImpl();
   TDMSprMod * Object;
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

//IDMSprMod
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBBCDField * get_TableID_MOD(void);
   virtual void set_TableID_MOD(TFIBBCDField * TableID_MOD);

   virtual TFIBBCDField * get_TableIDNOM_MOD(void);
   virtual void set_TableIDNOM_MOD(TFIBBCDField * TableIDNOM_MOD);

   virtual __int64 get_IdNom(void);
   virtual void set_IdNom(__int64 IdNom);

   virtual void OpenTable(__int64 Nom);
   virtual void NewElement(__int64 Nom);
   virtual void DeleteElement();
   virtual void SaveIsmen();
   virtual void CancelIsmen();
};
#define CLSID_TDMSprModImpl __uuidof(TDMSprModImpl)
#endif
