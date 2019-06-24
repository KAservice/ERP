#ifndef UDMSetupImplH
#define UDMSetupImplH
#include "IDMSetup.h"
#include "UDMSetup.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSetupImpl))TDMSetupImpl : public IDMSetup
{
public:
   TDMSetupImpl();
   ~TDMSetupImpl();
   TDMSetup * Object;
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

//IDMSetup
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TpFIBQuery * get_pFIBQKolPrDoc(void);
   virtual void set_pFIBQKolPrDoc(TpFIBQuery * pFIBQKolPrDoc);

   virtual TFIBBCDField * get_ElementID_SETUP(void);
   virtual void set_ElementID_SETUP(TFIBBCDField * ElementID_SETUP);

   virtual TFIBBCDField * get_TableID_SETUP(void);
   virtual void set_TableID_SETUP(TFIBBCDField * TableID_SETUP);

   virtual TFIBDateTimeField * get_TableVALUE_TIMESTAMP_SETUP(void);
   virtual void set_TableVALUE_TIMESTAMP_SETUP(TFIBDateTimeField * TableVALUE_TIMESTAMP_SETUP);

   virtual TFIBDateTimeField * get_ElementVALUE_TIMESTAMP_SETUP(void);
   virtual void set_ElementVALUE_TIMESTAMP_SETUP(TFIBDateTimeField * ElementVALUE_TIMESTAMP_SETUP);

   virtual TFIBSmallIntField * get_TableTYPE_VALUE_SETUP(void);
   virtual void set_TableTYPE_VALUE_SETUP(TFIBSmallIntField * TableTYPE_VALUE_SETUP);

   virtual TFIBSmallIntField * get_ElementTYPE_VALUE_SETUP(void);
   virtual void set_ElementTYPE_VALUE_SETUP(TFIBSmallIntField * ElementTYPE_VALUE_SETUP);

   virtual TFIBWideStringField * get_TableDESCRIPTION_SETUP(void);
   virtual void set_TableDESCRIPTION_SETUP(TFIBWideStringField * TableDESCRIPTION_SETUP);

   virtual TFIBWideStringField * get_TableVALUE_SETUP(void);
   virtual void set_TableVALUE_SETUP(TFIBWideStringField * TableVALUE_SETUP);

   virtual TFIBWideStringField * get_TableGID_SETUP(void);
   virtual void set_TableGID_SETUP(TFIBWideStringField * TableGID_SETUP);

   virtual TFIBWideStringField * get_ElementDESCRIPTION_SETUP(void);
   virtual void set_ElementDESCRIPTION_SETUP(TFIBWideStringField * ElementDESCRIPTION_SETUP);

   virtual TFIBWideStringField * get_ElementVALUE_SETUP(void);
   virtual void set_ElementVALUE_SETUP(TFIBWideStringField * ElementVALUE_SETUP);

   virtual TFIBWideStringField * get_ElementGID_SETUP(void);
   virtual void set_ElementGID_SETUP(TFIBWideStringField * ElementGID_SETUP);

   virtual void OpenTable(void);
   virtual void SaveIsmen();
   virtual void CancelIsmen();
   virtual int OpenElement(__int64 Id);
   virtual void NewElement(void);
   virtual void SaveElement(void);
   virtual void DeleteElement(__int64 Id);
   virtual void ProveritPosled( TDateTime  posDoc);
   virtual int  GetKolProvDoc( TDateTime  posDoc);
   virtual bool ProveritPosZapretaRed( TDateTime  posDoc);
   virtual void ProveritPosledHotel( TDateTime  posDoc);
   virtual int  GetKolProvDocHotel( TDateTime  posDoc);
   virtual bool ProveritPosZapretaRedHotel( TDateTime  posDoc);
   virtual void ProveritPosledRemont( TDateTime  posDoc);
   virtual int  GetKolProvDocRemont( TDateTime  posDoc);
   virtual bool ProveritPosZapretaRedRemont( TDateTime  posDoc);
};
#define CLSID_TDMSetupImpl __uuidof(TDMSetupImpl)
#endif
