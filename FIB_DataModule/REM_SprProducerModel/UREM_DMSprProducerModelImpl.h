#ifndef UREM_DMSprProducerModelImplH
#define UREM_DMSprProducerModelImplH
#include "IREM_DMSprProducerModel.h"
#include "UREM_DMSprProducerModel.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMSprProducerModelImpl)) TREM_DMSprProducerModelImpl : public IREM_DMSprProducerModel
{
public:
   TREM_DMSprProducerModelImpl();
   ~TREM_DMSprProducerModelImpl();
   TREM_DMSprProducerModel * Object;
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

//IREM_DMSprProducerModel
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TFIBLargeIntField * get_TableID_REM_SPRMODEL(void);
   virtual void set_TableID_REM_SPRMODEL(TFIBLargeIntField * TableID_REM_SPRMODEL);

   virtual TFIBWideStringField * get_TableCODE_REM_SPRMODEL(void);
   virtual void set_TableCODE_REM_SPRMODEL(TFIBWideStringField * TableCODE_REM_SPRMODEL);

   virtual TFIBWideStringField * get_TableNAME_REM_SPRMODEL(void);
   virtual void set_TableNAME_REM_SPRMODEL(TFIBWideStringField * TableNAME_REM_SPRMODEL);

   virtual TFIBLargeIntField * get_ElementID_REM_SPRMODEL(void);
   virtual void set_ElementID_REM_SPRMODEL(TFIBLargeIntField * ElementID_REM_SPRMODEL);

   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SPRMODEL(void);
   virtual void set_ElementIDBASE_REM_SPRMODEL(TFIBLargeIntField * ElementIDBASE_REM_SPRMODEL);

   virtual TFIBWideStringField * get_ElementGID_REM_SPRMODEL(void);
   virtual void set_ElementGID_REM_SPRMODEL(TFIBWideStringField * ElementGID_REM_SPRMODEL);

   virtual TFIBLargeIntField * get_ElementIDPR_REM_SPRMODEL(void);
   virtual void set_ElementIDPR_REM_SPRMODEL(TFIBLargeIntField * ElementIDPR_REM_SPRMODEL);

   virtual TFIBLargeIntField * get_ElementIDGRP_REM_SPRMODEL(void);
   virtual void set_ElementIDGRP_REM_SPRMODEL(TFIBLargeIntField * ElementIDGRP_REM_SPRMODEL);

   virtual TFIBLargeIntField * get_ElementIDMODEL_REM_SPRMODEL(void);
   virtual void set_ElementIDMODEL_REM_SPRMODEL(TFIBLargeIntField * ElementIDMODEL_REM_SPRMODEL);

   virtual TFIBWideStringField * get_ElementCODE_REM_SPRMODEL(void);
   virtual void set_ElementCODE_REM_SPRMODEL(TFIBWideStringField * ElementCODE_REM_SPRMODEL);

   virtual TFIBWideStringField * get_ElementNAME_REM_SPRMODEL(void);
   virtual void set_ElementNAME_REM_SPRMODEL(TFIBWideStringField * ElementNAME_REM_SPRMODEL);

   virtual TFIBWideStringField * get_ElementNAME_REM_SMODEL(void);
   virtual void set_ElementNAME_REM_SMODEL(TFIBWideStringField * ElementNAME_REM_SMODEL);

   virtual TFIBWideStringField * get_TableNAME_REM_SMODEL(void);
   virtual void set_TableNAME_REM_SMODEL(TFIBWideStringField * TableNAME_REM_SMODEL);

   virtual TFIBLargeIntField * get_TableIDPR_REM_SPRMODEL(void);
   virtual void set_TableIDPR_REM_SPRMODEL(TFIBLargeIntField * TableIDPR_REM_SPRMODEL);

   virtual TFIBLargeIntField * get_TableIDGRP_REM_SPRMODEL(void);
   virtual void set_TableIDGRP_REM_SPRMODEL(TFIBLargeIntField * TableIDGRP_REM_SPRMODEL);

   virtual TFIBWideStringField * get_TableNAME_SBRAND(void);
   virtual void set_TableNAME_SBRAND(TFIBWideStringField * TableNAME_SBRAND);

   virtual TFIBWideStringField * get_TableNAME_SPRODUCER(void);
   virtual void set_TableNAME_SPRODUCER(TFIBWideStringField * TableNAME_SPRODUCER);

   virtual TFIBWideStringField * get_TableNAME_REM_SACTCATEGORY(void);
   virtual void set_TableNAME_REM_SACTCATEGORY(TFIBWideStringField * TableNAME_REM_SACTCATEGORY);

   virtual TFIBWideStringField * get_TableNAME_REM_STYPEDEVICE(void);
   virtual void set_TableNAME_REM_STYPEDEVICE(TFIBWideStringField * TableNAME_REM_STYPEDEVICE);

   virtual TFIBLargeIntField * get_ElementIDBRAND_REM_SPRMODEL(void);
   virtual void set_ElementIDBRAND_REM_SPRMODEL(TFIBLargeIntField * ElementIDBRAND_REM_SPRMODEL);

   virtual TFIBLargeIntField * get_ElementIDACTCATEGORY_REM_SPRMODEL(void);
   virtual void set_ElementIDACTCATEGORY_REM_SPRMODEL(TFIBLargeIntField * ElementIDACTCATEGORY_REM_SPRMODEL);

   virtual TFIBLargeIntField * get_ElementIDTYPEDEVICE_REM_SPRMODEL(void);
   virtual void set_ElementIDTYPEDEVICE_REM_SPRMODEL(TFIBLargeIntField * ElementIDTYPEDEVICE_REM_SPRMODEL);

   virtual TFIBWideStringField * get_ElementNAME_SBRAND(void);
   virtual void set_ElementNAME_SBRAND(TFIBWideStringField * ElementNAME_SBRAND);

   virtual TFIBWideStringField * get_ElementNAME_SPRODUCER(void);
   virtual void set_ElementNAME_SPRODUCER(TFIBWideStringField * ElementNAME_SPRODUCER);

   virtual TFIBWideStringField * get_ElementNAME_REM_SACTCATEGORY(void);
   virtual void set_ElementNAME_REM_SACTCATEGORY(TFIBWideStringField * ElementNAME_REM_SACTCATEGORY);

   virtual TFIBWideStringField * get_ElementNAME_REM_STYPEDEVICE(void);
   virtual void set_ElementNAME_REM_STYPEDEVICE(TFIBWideStringField * ElementNAME_REM_STYPEDEVICE);

   virtual __int64 get_IdGroupElement(void);
   virtual void set_IdGroupElement(__int64 IdGroupElement);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual void OpenTable(__int64 id_group_element, __int64 id_grp, bool all);
   virtual bool NewElement(__int64 id_group_element, __int64 id_grp);
   virtual bool OpenElement(__int64 id);
   virtual bool DeleteElement(__int64 id);
   virtual bool SaveElement(void);
   virtual void ChancheGrp(__int64 id_new_grp,__int64 id_element);
};
#define CLSID_TREM_DMSprProducerModelImpl __uuidof(TREM_DMSprProducerModelImpl)
#endif
