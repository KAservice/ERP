#ifndef UREM_DMSprProducerModelInfBlockImplH
#define UREM_DMSprProducerModelInfBlockImplH
#include "IREM_DMSprProducerModelInfBlock.h"
#include "UREM_DMSprProducerModelInfBlock.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMSprProducerModelInfBlockImpl)) TREM_DMSprProducerModelInfBlockImpl : public IREM_DMSprProducerModelInfBlock
{
public:
   TREM_DMSprProducerModelInfBlockImpl();
   ~TREM_DMSprProducerModelInfBlockImpl();
   TREM_DMSprProducerModelInfBlock * Object;
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

//IREM_DMSprProducerModelInfBlock
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TpFIBQuery * get_Query(void);
   virtual void set_Query(TpFIBQuery * Query);

   virtual TFIBLargeIntField * get_TableID_REM_SPRMODEL_INF(void);
   virtual void set_TableID_REM_SPRMODEL_INF(TFIBLargeIntField * TableID_REM_SPRMODEL_INF);

   virtual TFIBLargeIntField * get_TableIDBASE_REM_SPRMODEL_INF(void);
   virtual void set_TableIDBASE_REM_SPRMODEL_INF(TFIBLargeIntField * TableIDBASE_REM_SPRMODEL_INF);

   virtual TFIBWideStringField * get_TableGID_REM_SPRMODEL_INF(void);
   virtual void set_TableGID_REM_SPRMODEL_INF(TFIBWideStringField * TableGID_REM_SPRMODEL_INF);

   virtual TFIBLargeIntField * get_TableIDPRMODEL_REM_SPRMODEL_INF(void);
   virtual void set_TableIDPRMODEL_REM_SPRMODEL_INF(TFIBLargeIntField * TableIDPRMODEL_REM_SPRMODEL_INF);

   virtual TFIBLargeIntField * get_TableIDIB_REM_SPRMODEL_INF(void);
   virtual void set_TableIDIB_REM_SPRMODEL_INF(TFIBLargeIntField * TableIDIB_REM_SPRMODEL_INF);

   virtual TFIBDateTimeField * get_TableISM_REM_SPRMODEL_INF(void);
   virtual void set_TableISM_REM_SPRMODEL_INF(TFIBDateTimeField * TableISM_REM_SPRMODEL_INF);

   virtual TFIBWideStringField * get_TableNAME_ART_IB(void);
   virtual void set_TableNAME_ART_IB(TFIBWideStringField * TableNAME_ART_IB);

   virtual TFIBWideStringField * get_TableDESCR_ART_IB(void);
   virtual void set_TableDESCR_ART_IB(TFIBWideStringField * TableDESCR_ART_IB);

   virtual TFIBLargeIntField * get_ElementID_REM_SPRMODEL_INF(void);
   virtual void set_ElementID_REM_SPRMODEL_INF(TFIBLargeIntField * ElementID_REM_SPRMODEL_INF);

   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SPRMODEL_INF(void);
   virtual void set_ElementIDBASE_REM_SPRMODEL_INF(TFIBLargeIntField * ElementIDBASE_REM_SPRMODEL_INF);

   virtual TFIBWideStringField * get_ElementGID_REM_SPRMODEL_INF(void);
   virtual void set_ElementGID_REM_SPRMODEL_INF(TFIBWideStringField * ElementGID_REM_SPRMODEL_INF);

   virtual TFIBLargeIntField * get_ElementIDPRMODEL_REM_SPRMODEL_INF(void);
   virtual void set_ElementIDPRMODEL_REM_SPRMODEL_INF(TFIBLargeIntField * ElementIDPRMODEL_REM_SPRMODEL_INF);

   virtual TFIBLargeIntField * get_ElementIDIB_REM_SPRMODEL_INF(void);
   virtual void set_ElementIDIB_REM_SPRMODEL_INF(TFIBLargeIntField * ElementIDIB_REM_SPRMODEL_INF);

   virtual TFIBDateTimeField * get_ElementISM_REM_SPRMODEL_INF(void);
   virtual void set_ElementISM_REM_SPRMODEL_INF(TFIBDateTimeField * ElementISM_REM_SPRMODEL_INF);

   virtual TFIBWideStringField * get_ElementNAME_ART_IB(void);
   virtual void set_ElementNAME_ART_IB(TFIBWideStringField * ElementNAME_ART_IB);

   virtual TFIBWideStringField * get_ElementDESCR_ART_IB(void);
   virtual void set_ElementDESCR_ART_IB(TFIBWideStringField * ElementDESCR_ART_IB);

   virtual __int64 get_IdOwner(void);
   virtual void set_IdOwner(__int64 IdOwner);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual void OpenTable(__int64 id_owner);
   virtual bool NewElement(__int64 id_owner);
   virtual int OpenElement(__int64 id );
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
};
#define CLSID_TREM_DMSprProducerModelInfBlockImpl __uuidof(TREM_DMSprProducerModelInfBlockImpl)
#endif
