#ifndef UDMSprSezKFImplH
#define UDMSprSezKFImplH
#include "IDMSprSezKF.h"
#include "UDMSprSezKF.h"
//---------------------------------------------------------------
class __declspec(uuid("{05C55055-5073-4CE9-AB1A-CAA9C2D9E87E}")) TDMSprSezKFImpl : public IDMSprSezKF
{
public:
   TDMSprSezKFImpl();
   ~TDMSprSezKFImpl();
   TDMSprSezKF * Object;
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

//IDMSprSezKF
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TFIBIntegerField * get_TableMONTH_SSEZKF(void);
   virtual void set_TableMONTH_SSEZKF(TFIBIntegerField * TableMONTH_SSEZKF);

   virtual TFIBBCDField * get_TableVALUE_SSEZKF(void);
   virtual void set_TableVALUE_SSEZKF(TFIBBCDField * TableVALUE_SSEZKF);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBBCDField * get_TableID_SSEZKF(void);
   virtual void set_TableID_SSEZKF(TFIBBCDField * TableID_SSEZKF);

   virtual TFIBBCDField * get_TableIDNOM_SSEZKF(void);
   virtual void set_TableIDNOM_SSEZKF(TFIBBCDField * TableIDNOM_SSEZKF);

   virtual TFIBWideStringField * get_TableGID_SSEZKF(void);
   virtual void set_TableGID_SSEZKF(TFIBWideStringField * TableGID_SSEZKF);

   virtual __int64 get_IdNom(void);
   virtual void set_IdNom(__int64 IdNom);

   virtual float get_KolEdProd(void);
   virtual void set_KolEdProd(float KolEdProd);

   virtual float get_KFEdProd(void);
   virtual void set_KFEdProd(float KFEdProd);

   virtual void OpenTable(__int64 Nom);
   virtual void NewElement(__int64 Nom);
   virtual void DeleteElement();
   virtual void SaveIsmen();
   virtual void CancelIsmen();
};
#define CLSID_TDMSprSezKFImpl __uuidof(TDMSprSezKFImpl)
#endif
