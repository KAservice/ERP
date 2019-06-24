#ifndef UDMSprSostProdImplH
#define UDMSprSostProdImplH
#include "IDMSprSostProd.h"
#include "UDMSprSostProd.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprSostProdImpl)) TDMSprSostProdImpl : public IDMSprSostProd
{
public:
   TDMSprSostProdImpl();
   ~TDMSprSostProdImpl();
   TDMSprSostProd * Object;
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

//IDMSprSostProd
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TFIBBCDField * get_TableNKOL_SPROD(void);
   virtual void set_TableNKOL_SPROD(TFIBBCDField * TableNKOL_SPROD);

   virtual TFIBBCDField * get_TableBKOL_SPROD(void);
   virtual void set_TableBKOL_SPROD(TFIBBCDField * TableBKOL_SPROD);

   virtual TFIBBCDField * get_TableKFPRICE_SPROD(void);
   virtual void set_TableKFPRICE_SPROD(TFIBBCDField * TableKFPRICE_SPROD);

   virtual TFIBSmallIntField * get_TableSPIS_SPROD(void);
   virtual void set_TableSPIS_SPROD(TFIBSmallIntField * TableSPIS_SPROD);

   virtual TFIBBCDField * get_TableKF_SPROD(void);
   virtual void set_TableKF_SPROD(TFIBBCDField * TableKF_SPROD);

   virtual TFIBIntegerField * get_TableTNOM(void);
   virtual void set_TableTNOM(TFIBIntegerField * TableTNOM);

   virtual TFIBBCDField * get_TableVALUE_SSEZKF(void);
   virtual void set_TableVALUE_SSEZKF(TFIBBCDField * TableVALUE_SSEZKF);

   virtual TFIBBCDField * get_TableVALUE_SSEZKF_SPROD(void);
   virtual void set_TableVALUE_SSEZKF_SPROD(TFIBBCDField * TableVALUE_SSEZKF_SPROD);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFloatField * get_TableNABASED(void);
   virtual void set_TableNABASED(TFloatField * TableNABASED);

   virtual TFloatField * get_TableNNABASED(void);
   virtual void set_TableNNABASED(TFloatField * TableNNABASED);

   virtual TFloatField * get_TableSEZKF(void);
   virtual void set_TableSEZKF(TFloatField * TableSEZKF);

   virtual TFloatField * get_TableSEZKF_SPROD(void);
   virtual void set_TableSEZKF_SPROD(TFloatField * TableSEZKF_SPROD);

   virtual TFIBBCDField * get_TableID_SPROD(void);
   virtual void set_TableID_SPROD(TFIBBCDField * TableID_SPROD);

   virtual TFIBBCDField * get_TableIDNOMREST_SPROD(void);
   virtual void set_TableIDNOMREST_SPROD(TFIBBCDField * TableIDNOMREST_SPROD);

   virtual TFIBBCDField * get_TableIDKOMPL_SPROD(void);
   virtual void set_TableIDKOMPL_SPROD(TFIBBCDField * TableIDKOMPL_SPROD);

   virtual TFIBBCDField * get_TableIDED_SPROD(void);
   virtual void set_TableIDED_SPROD(TFIBBCDField * TableIDED_SPROD);

   virtual TFIBWideStringField * get_TableGID_SSPROD(void);
   virtual void set_TableGID_SSPROD(TFIBWideStringField * TableGID_SSPROD);

   virtual TFIBWideStringField * get_TableNAMENOM(void);
   virtual void set_TableNAMENOM(TFIBWideStringField * TableNAMENOM);

   virtual TFIBWideStringField * get_TableNAMEED(void);
   virtual void set_TableNAMEED(TFIBWideStringField * TableNAMEED);

   virtual TFIBBCDField * get_TableIDPRODUCE_SSPROD(void);
   virtual void set_TableIDPRODUCE_SSPROD(TFIBBCDField * TableIDPRODUCE_SSPROD);

   virtual TFIBBCDField * get_TableIDLOSTFACTOR_SSPROD(void);
   virtual void set_TableIDLOSTFACTOR_SSPROD(TFIBBCDField * TableIDLOSTFACTOR_SSPROD);

   virtual TFIBWideStringField * get_TableNAME_SPRODUCE(void);
   virtual void set_TableNAME_SPRODUCE(TFIBWideStringField * TableNAME_SPRODUCE);

   virtual TFIBWideStringField * get_TableNAME_SLOSS_FACTOR(void);
   virtual void set_TableNAME_SLOSS_FACTOR(TFIBWideStringField * TableNAME_SLOSS_FACTOR);

   virtual __int64 get_IdNom(void);
   virtual void set_IdNom(__int64 IdNom);

   virtual __int64 get_IdNomRest(void);
   virtual void set_IdNomRest(__int64 IdNomRest);

   virtual float get_KolEdProd(void);
   virtual void set_KolEdProd(float KolEdProd);

   virtual float get_KFEdProd(void);
   virtual void set_KFEdProd(float KFEdProd);

   virtual TDateTime get_Pos(void);
   virtual void set_Pos(TDateTime Pos);

   virtual void OpenTable(__int64 Nom);
   virtual void NewElement(__int64 Nom);
   virtual void DeleteElement();
   virtual void SaveIsmen();
   virtual void CancelIsmen();
};
#define CLSID_TDMSprSostProdImpl __uuidof(TDMSprSostProdImpl)
#endif
