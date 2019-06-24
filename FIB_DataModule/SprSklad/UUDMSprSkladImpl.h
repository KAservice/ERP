#ifndef UUDMSprSkladImplH
#define UUDMSprSkladImplH
#include "IUDMSprSklad.h"
#include "UUDMSprSklad.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TUDMSprSkladImpl)) TUDMSprSkladImpl : public IUDMSprSklad
{
public:
   TUDMSprSkladImpl();
   ~TUDMSprSkladImpl();
   TUDMSprSklad * Object;
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

//IUDMSprSklad
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TFIBIntegerField * get_TableTSKLAD(void);
   virtual void set_TableTSKLAD(TFIBIntegerField * TableTSKLAD);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBIntegerField * get_ElementTSKLAD(void);
   virtual void set_ElementTSKLAD(TFIBIntegerField * ElementTSKLAD);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBBCDField * get_TableIDSKLAD(void);
   virtual void set_TableIDSKLAD(TFIBBCDField * TableIDSKLAD);

   virtual TFIBBCDField * get_ElementIDSKLAD(void);
   virtual void set_ElementIDSKLAD(TFIBBCDField * ElementIDSKLAD);

   virtual TFIBWideStringField * get_TableNAMESKLAD(void);
   virtual void set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD);

   virtual TFIBWideStringField * get_TableMOLSKLAD(void);
   virtual void set_TableMOLSKLAD(TFIBWideStringField * TableMOLSKLAD);

   virtual TFIBWideStringField * get_TableADRSKLAD(void);
   virtual void set_TableADRSKLAD(TFIBWideStringField * TableADRSKLAD);

   virtual TFIBWideStringField * get_TableGID_SSKLAD(void);
   virtual void set_TableGID_SSKLAD(TFIBWideStringField * TableGID_SSKLAD);

   virtual TFIBWideStringField * get_ElementNAMESKLAD(void);
   virtual void set_ElementNAMESKLAD(TFIBWideStringField * ElementNAMESKLAD);

   virtual TFIBWideStringField * get_ElementMOLSKLAD(void);
   virtual void set_ElementMOLSKLAD(TFIBWideStringField * ElementMOLSKLAD);

   virtual TFIBWideStringField * get_ElementADRSKLAD(void);
   virtual void set_ElementADRSKLAD(TFIBWideStringField * ElementADRSKLAD);

   virtual TFIBWideStringField * get_ElementGID_SSKLAD(void);
   virtual void set_ElementGID_SSKLAD(TFIBWideStringField * ElementGID_SSKLAD);

   virtual TFIBSmallIntField * get_ElementDBLUCHETALLNOM_SSKLAD(void);
   virtual void set_ElementDBLUCHETALLNOM_SSKLAD(TFIBSmallIntField * ElementDBLUCHETALLNOM_SSKLAD);

   virtual TFIBSmallIntField * get_ElementDBLUCHET_SSKLAD(void);
   virtual void set_ElementDBLUCHET_SSKLAD(TFIBSmallIntField * ElementDBLUCHET_SSKLAD);

   virtual TFIBWideStringField * get_ElementPREFIKS_NUM_SSKLAD(void);
   virtual void set_ElementPREFIKS_NUM_SSKLAD(TFIBWideStringField * ElementPREFIKS_NUM_SSKLAD);

   virtual TFIBBCDField * get_ElementIDBASE_SSKLAD(void);
   virtual void set_ElementIDBASE_SSKLAD(TFIBBCDField * ElementIDBASE_SSKLAD);

   virtual TFIBWideStringField * get_ElementPHONE_SSKLAD(void);
   virtual void set_ElementPHONE_SSKLAD(TFIBWideStringField * ElementPHONE_SSKLAD);

   virtual TFIBWideStringField * get_ElementEMAIL_SSKLAD(void);
   virtual void set_ElementEMAIL_SSKLAD(TFIBWideStringField * ElementEMAIL_SSKLAD);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 Id);
   virtual void NewElement(void);
   virtual bool SaveElement(void);
   virtual void CloseElement(void);
   virtual void DeleteElement(__int64 Id);
   virtual __int64 GetIDElement(String gid);
   virtual AnsiString GetGIDElement(__int64 id);
   virtual int GetIndexElementaPoID(__int64 id);
};
#define CLSID_TUDMSprSkladImpl __uuidof(TUDMSprSkladImpl)
#endif
