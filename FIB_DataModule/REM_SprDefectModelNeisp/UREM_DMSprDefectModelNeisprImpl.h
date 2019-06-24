#ifndef UREM_DMSprDefectModelNeisprImplH
#define UREM_DMSprDefectModelNeisprImplH
#include "IREM_DMSprDefectModelNeispr.h"
#include "UREM_DMSprDefectModelNeispr.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMSprDefectModelNeisprImpl)) TREM_DMSprDefectModelNeisprImpl : public IREM_DMSprDefectModelNeispr
{
public:
   TREM_DMSprDefectModelNeisprImpl();
   ~TREM_DMSprDefectModelNeisprImpl();
   TREM_DMSprDefectModelNeispr * Object;
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

//IREM_DMSprDefectModelNeispr
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

   virtual TFIBLargeIntField * get_TableID_REM_SDEFECT_MODNE(void);
   virtual void set_TableID_REM_SDEFECT_MODNE(TFIBLargeIntField * TableID_REM_SDEFECT_MODNE);

   virtual TFIBWideStringField * get_TableGID_REM_SDEFECT_MODNE(void);
   virtual void set_TableGID_REM_SDEFECT_MODNE(TFIBWideStringField * TableGID_REM_SDEFECT_MODNE);

   virtual TFIBLargeIntField * get_TableIDBASE_REM_SDEFECT_MODNE(void);
   virtual void set_TableIDBASE_REM_SDEFECT_MODNE(TFIBLargeIntField * TableIDBASE_REM_SDEFECT_MODNE);

   virtual TFIBLargeIntField * get_TableIDNEISMOD_REM_SDEFECT_MODNE(void);
   virtual void set_TableIDNEISMOD_REM_SDEFECT_MODNE(TFIBLargeIntField * TableIDNEISMOD_REM_SDEFECT_MODNE);

   virtual TFIBWideStringField * get_TableNAME_REM_SDEFECT_MODNE(void);
   virtual void set_TableNAME_REM_SDEFECT_MODNE(TFIBWideStringField * TableNAME_REM_SDEFECT_MODNE);

   virtual TFIBWideStringField * get_TableDESCR_REM_SDEFECT_MODNE(void);
   virtual void set_TableDESCR_REM_SDEFECT_MODNE(TFIBWideStringField * TableDESCR_REM_SDEFECT_MODNE);

   virtual TFIBLargeIntField * get_TableIDTDEF_REM_SDEFECT_MODNE(void);
   virtual void set_TableIDTDEF_REM_SDEFECT_MODNE(TFIBLargeIntField * TableIDTDEF_REM_SDEFECT_MODNE);

   virtual TFIBWideStringField * get_TableNAME_REM_STYPDEFECT(void);
   virtual void set_TableNAME_REM_STYPDEFECT(TFIBWideStringField * TableNAME_REM_STYPDEFECT);

   virtual TFIBWideStringField * get_TableCODE_REM_STYPDEFECT(void);
   virtual void set_TableCODE_REM_STYPDEFECT(TFIBWideStringField * TableCODE_REM_STYPDEFECT);

   virtual TFIBLargeIntField * get_ElementID_REM_SDEFECT_MODNE(void);
   virtual void set_ElementID_REM_SDEFECT_MODNE(TFIBLargeIntField * ElementID_REM_SDEFECT_MODNE);

   virtual TFIBWideStringField * get_ElementGID_REM_SDEFECT_MODNE(void);
   virtual void set_ElementGID_REM_SDEFECT_MODNE(TFIBWideStringField * ElementGID_REM_SDEFECT_MODNE);

   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SDEFECT_MODNE(void);
   virtual void set_ElementIDBASE_REM_SDEFECT_MODNE(TFIBLargeIntField * ElementIDBASE_REM_SDEFECT_MODNE);

   virtual TFIBLargeIntField * get_ElementIDNEISMOD_REM_SDEFECT_MODNE(void);
   virtual void set_ElementIDNEISMOD_REM_SDEFECT_MODNE(TFIBLargeIntField * ElementIDNEISMOD_REM_SDEFECT_MODNE);

   virtual TFIBWideStringField * get_ElementNAME_REM_SDEFECT_MODNE(void);
   virtual void set_ElementNAME_REM_SDEFECT_MODNE(TFIBWideStringField * ElementNAME_REM_SDEFECT_MODNE);

   virtual TFIBWideStringField * get_ElementDESCR_REM_SDEFECT_MODNE(void);
   virtual void set_ElementDESCR_REM_SDEFECT_MODNE(TFIBWideStringField * ElementDESCR_REM_SDEFECT_MODNE);

   virtual TFIBLargeIntField * get_ElementIDTDEF_REM_SDEFECT_MODNE(void);
   virtual void set_ElementIDTDEF_REM_SDEFECT_MODNE(TFIBLargeIntField * ElementIDTDEF_REM_SDEFECT_MODNE);

   virtual TFIBWideStringField * get_ElementNAME_REM_STYPDEFECT(void);
   virtual void set_ElementNAME_REM_STYPDEFECT(TFIBWideStringField * ElementNAME_REM_STYPDEFECT);

   virtual TFIBWideStringField * get_ElementCODE_REM_STYPDEFECT(void);
   virtual void set_ElementCODE_REM_STYPDEFECT(TFIBWideStringField * ElementCODE_REM_STYPDEFECT);

   virtual void OpenTable(__int64 id_model_neispr);
   virtual int OpenElement(__int64 id);
   virtual bool NewElement(__int64 id_model_neispr);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
};
#define CLSID_TREM_DMSprDefectModelNeisprImpl __uuidof(TREM_DMSprDefectModelNeisprImpl)
#endif
