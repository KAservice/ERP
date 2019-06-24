#ifndef UDMSprProducerImplH
#define UDMSprProducerImplH
#include "IDMSprProducer.h"
#include "UDMSprProducer.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprProducerImpl)) TDMSprProducerImpl : public IDMSprProducer
{
public:
   TDMSprProducerImpl();
   ~TDMSprProducerImpl();
   TDMSprProducer * Object;
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

//IDMSprProducer
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

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBLargeIntField * get_TableID_SPRODUCER(void);
   virtual void set_TableID_SPRODUCER(TFIBLargeIntField * TableID_SPRODUCER);

   virtual TFIBLargeIntField * get_TableIDBASE_SPRODUCER(void);
   virtual void set_TableIDBASE_SPRODUCER(TFIBLargeIntField * TableIDBASE_SPRODUCER);

   virtual TFIBWideStringField * get_TableGID_SPRODUCER(void);
   virtual void set_TableGID_SPRODUCER(TFIBWideStringField * TableGID_SPRODUCER);

   virtual TFIBWideStringField * get_TableNAME_SPRODUCER(void);
   virtual void set_TableNAME_SPRODUCER(TFIBWideStringField * TableNAME_SPRODUCER);

   virtual TFIBLargeIntField * get_TableIDKLIENT_SPRODUCER(void);
   virtual void set_TableIDKLIENT_SPRODUCER(TFIBLargeIntField * TableIDKLIENT_SPRODUCER);

   virtual TFIBWideStringField * get_TableNAMEKLIENT(void);
   virtual void set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT);

   virtual TFIBWideStringField * get_TableINNKLIENT(void);
   virtual void set_TableINNKLIENT(TFIBWideStringField * TableINNKLIENT);

   virtual TFIBLargeIntField * get_ElementID_SPRODUCER(void);
   virtual void set_ElementID_SPRODUCER(TFIBLargeIntField * ElementID_SPRODUCER);

   virtual TFIBLargeIntField * get_ElementIDBASE_SPRODUCER(void);
   virtual void set_ElementIDBASE_SPRODUCER(TFIBLargeIntField * ElementIDBASE_SPRODUCER);

   virtual TFIBWideStringField * get_ElementGID_SPRODUCER(void);
   virtual void set_ElementGID_SPRODUCER(TFIBWideStringField * ElementGID_SPRODUCER);

   virtual TFIBWideStringField * get_ElementNAME_SPRODUCER(void);
   virtual void set_ElementNAME_SPRODUCER(TFIBWideStringField * ElementNAME_SPRODUCER);

   virtual TFIBLargeIntField * get_ElementIDKLIENT_SPRODUCER(void);
   virtual void set_ElementIDKLIENT_SPRODUCER(TFIBLargeIntField * ElementIDKLIENT_SPRODUCER);

   virtual TFIBWideStringField * get_ElementNAMEKLIENT(void);
   virtual void set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT);

   virtual TFIBLargeIntField * get_ElementIDPOST_ZIP_SPRODUCER(void);
   virtual void set_ElementIDPOST_ZIP_SPRODUCER(TFIBLargeIntField * ElementIDPOST_ZIP_SPRODUCER);

   virtual TFIBWideStringField * get_ElementPOST_ZIP_NAME(void);
   virtual void set_ElementPOST_ZIP_NAME(TFIBWideStringField * ElementPOST_ZIP_NAME);

   virtual TFIBDateTimeField * get_TablePOSZAGRNOM_SPRODUCER(void);
   virtual void set_TablePOSZAGRNOM_SPRODUCER(TFIBDateTimeField * TablePOSZAGRNOM_SPRODUCER);

   virtual TFIBDateTimeField * get_ElementPOSZAGRNOM_SPRODUCER(void);
   virtual void set_ElementPOSZAGRNOM_SPRODUCER(TFIBDateTimeField * ElementPOSZAGRNOM_SPRODUCER);

   virtual TFIBIntegerField * get_ElementTYPE_POISK_SPRNOM_SPRODUCER(void);
   virtual void set_ElementTYPE_POISK_SPRNOM_SPRODUCER(TFIBIntegerField * ElementTYPE_POISK_SPRNOM_SPRODUCER);

   virtual TFIBLargeIntField * get_ElementIDINETCAT_USL_SPRODUCER(void);
   virtual void set_ElementIDINETCAT_USL_SPRODUCER(TFIBLargeIntField * ElementIDINETCAT_USL_SPRODUCER);

   virtual TFIBLargeIntField * get_ElementIDGRPINETCAT_USL_SPRODUCER(void);
   virtual void set_ElementIDGRPINETCAT_USL_SPRODUCER(TFIBLargeIntField * ElementIDGRPINETCAT_USL_SPRODUCER);

   virtual TFIBWideStringField * get_ElementNAME_SINETCATALOG(void);
   virtual void set_ElementNAME_SINETCATALOG(TFIBWideStringField * ElementNAME_SINETCATALOG);

   virtual TFIBWideStringField * get_ElementNAME_SNOMINETCAT_GRP(void);
   virtual void set_ElementNAME_SNOMINETCAT_GRP(TFIBWideStringField * ElementNAME_SNOMINETCAT_GRP);

   virtual TFIBLargeIntField * get_ElementIDGRPNOM_ZIP_SPRODUCER(void);
   virtual void set_ElementIDGRPNOM_ZIP_SPRODUCER(TFIBLargeIntField * ElementIDGRPNOM_ZIP_SPRODUCER);

   virtual TFIBLargeIntField * get_ElementIDGRPNOM_RAB_SPRODUCER(void);
   virtual void set_ElementIDGRPNOM_RAB_SPRODUCER(TFIBLargeIntField * ElementIDGRPNOM_RAB_SPRODUCER);

   virtual TFIBLargeIntField * get_ElementIDGRP_HW_SPRODUCER(void);
   virtual void set_ElementIDGRP_HW_SPRODUCER(TFIBLargeIntField * ElementIDGRP_HW_SPRODUCER);

   virtual TFIBWideStringField * get_ElementNAMEGN(void);
   virtual void set_ElementNAMEGN(TFIBWideStringField * ElementNAMEGN);

   virtual TFIBWideStringField * get_ElementRAB_NAMEGN(void);
   virtual void set_ElementRAB_NAMEGN(TFIBWideStringField * ElementRAB_NAMEGN);

   virtual TFIBWideStringField * get_ElementNAME_REM_SGRP_HARDWARE(void);
   virtual void set_ElementNAME_REM_SGRP_HARDWARE(TFIBWideStringField * ElementNAME_REM_SGRP_HARDWARE);

   virtual bool OpenTable();
   virtual bool  OpenElement(__int64 id);
   virtual bool NewElement();
   virtual bool SaveElement(void);
   virtual void CloseElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual __int64 GetIdElementPoName(UnicodeString   name);
   virtual int GetIndexInTablePoId(__int64 id_element);
   virtual __int64 GetIdElementPoGid(UnicodeString gid);
   virtual UnicodeString GetGidElementPoId(__int64 id);
};
#define CLSID_TDMSprProducerImpl __uuidof(TDMSprProducerImpl)
#endif
