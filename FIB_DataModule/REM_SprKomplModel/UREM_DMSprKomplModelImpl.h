#ifndef UREM_DMSprKomplModelImplH
#define UREM_DMSprKomplModelImplH
#include "IREM_DMSprKomplModel.h"
#include "UREM_DMSprKomplModel.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMSprKomplModelImpl)) TREM_DMSprKomplModelImpl : public IREM_DMSprKomplModel
{
public:
   TREM_DMSprKomplModelImpl();
   ~TREM_DMSprKomplModelImpl();
   TREM_DMSprKomplModel * Object;
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

//IREM_DMSprKomplModel
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

   virtual TFIBLargeIntField * get_TableID_REM_SKOMPLMODEL(void);
   virtual void set_TableID_REM_SKOMPLMODEL(TFIBLargeIntField * TableID_REM_SKOMPLMODEL);

   virtual TFIBWideStringField * get_TableGID_REM_SKOMPLMODEL(void);
   virtual void set_TableGID_REM_SKOMPLMODEL(TFIBWideStringField * TableGID_REM_SKOMPLMODEL);

   virtual TFIBLargeIntField * get_TableIDMODEL_REM_SKOMPLMODEL(void);
   virtual void set_TableIDMODEL_REM_SKOMPLMODEL(TFIBLargeIntField * TableIDMODEL_REM_SKOMPLMODEL);

   virtual TFIBWideStringField * get_TableNAME_REM_SKOMPLMODEL(void);
   virtual void set_TableNAME_REM_SKOMPLMODEL(TFIBWideStringField * TableNAME_REM_SKOMPLMODEL);

   virtual TFIBBCDField * get_TableKOL_REM_SKOMPLMODEL(void);
   virtual void set_TableKOL_REM_SKOMPLMODEL(TFIBBCDField * TableKOL_REM_SKOMPLMODEL);

   virtual TFIBSmallIntField * get_TableNEISP_REM_SKOMPLMODEL(void);
   virtual void set_TableNEISP_REM_SKOMPLMODEL(TFIBSmallIntField * TableNEISP_REM_SKOMPLMODEL);

   virtual TFIBSmallIntField * get_TableOSN_REM_SKOMPLMODEL(void);
   virtual void set_TableOSN_REM_SKOMPLMODEL(TFIBSmallIntField * TableOSN_REM_SKOMPLMODEL);

   virtual TFIBLargeIntField * get_TableIDBASE_REM_SKOMPLMODEL(void);
   virtual void set_TableIDBASE_REM_SKOMPLMODEL(TFIBLargeIntField * TableIDBASE_REM_SKOMPLMODEL);

   virtual TFIBLargeIntField * get_ElementID_REM_SKOMPLMODEL(void);
   virtual void set_ElementID_REM_SKOMPLMODEL(TFIBLargeIntField * ElementID_REM_SKOMPLMODEL);

   virtual TFIBWideStringField * get_ElementGID_REM_SKOMPLMODEL(void);
   virtual void set_ElementGID_REM_SKOMPLMODEL(TFIBWideStringField * ElementGID_REM_SKOMPLMODEL);

   virtual TFIBLargeIntField * get_ElementIDMODEL_REM_SKOMPLMODEL(void);
   virtual void set_ElementIDMODEL_REM_SKOMPLMODEL(TFIBLargeIntField * ElementIDMODEL_REM_SKOMPLMODEL);

   virtual TFIBWideStringField * get_ElementNAME_REM_SKOMPLMODEL(void);
   virtual void set_ElementNAME_REM_SKOMPLMODEL(TFIBWideStringField * ElementNAME_REM_SKOMPLMODEL);

   virtual TFIBBCDField * get_ElementKOL_REM_SKOMPLMODEL(void);
   virtual void set_ElementKOL_REM_SKOMPLMODEL(TFIBBCDField * ElementKOL_REM_SKOMPLMODEL);

   virtual TFIBSmallIntField * get_ElementNEISP_REM_SKOMPLMODEL(void);
   virtual void set_ElementNEISP_REM_SKOMPLMODEL(TFIBSmallIntField * ElementNEISP_REM_SKOMPLMODEL);

   virtual TFIBSmallIntField * get_ElementOSN_REM_SKOMPLMODEL(void);
   virtual void set_ElementOSN_REM_SKOMPLMODEL(TFIBSmallIntField * ElementOSN_REM_SKOMPLMODEL);

   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SKOMPLMODEL(void);
   virtual void set_ElementIDBASE_REM_SKOMPLMODEL(TFIBLargeIntField * ElementIDBASE_REM_SKOMPLMODEL);

   virtual TFIBLargeIntField * get_TableIDTYPUSLA_REM_SKOMPLMODEL(void);
   virtual void set_TableIDTYPUSLA_REM_SKOMPLMODEL(TFIBLargeIntField * TableIDTYPUSLA_REM_SKOMPLMODEL);

   virtual TFIBWideStringField * get_TablePARTNUM_REM_SKOMPLMODEL(void);
   virtual void set_TablePARTNUM_REM_SKOMPLMODEL(TFIBWideStringField * TablePARTNUM_REM_SKOMPLMODEL);

   virtual TFIBWideStringField * get_TableDESCR_REM_SKOMPLMODEL(void);
   virtual void set_TableDESCR_REM_SKOMPLMODEL(TFIBWideStringField * TableDESCR_REM_SKOMPLMODEL);

   virtual TFIBLargeIntField * get_TableIDNOM_REM_SKOMPLMODEL(void);
   virtual void set_TableIDNOM_REM_SKOMPLMODEL(TFIBLargeIntField * TableIDNOM_REM_SKOMPLMODEL);

   virtual TFIBLargeIntField * get_TableIDPRNOM_REM_SKOMPLMODEL(void);
   virtual void set_TableIDPRNOM_REM_SKOMPLMODEL(TFIBLargeIntField * TableIDPRNOM_REM_SKOMPLMODEL);

   virtual TFIBWideStringField * get_TableNAME_REM_STYPUSLOV(void);
   virtual void set_TableNAME_REM_STYPUSLOV(TFIBWideStringField * TableNAME_REM_STYPUSLOV);

   virtual TFIBIntegerField * get_TableCODENOM(void);
   virtual void set_TableCODENOM(TFIBIntegerField * TableCODENOM);

   virtual TFIBWideStringField * get_TableARTNOM(void);
   virtual void set_TableARTNOM(TFIBWideStringField * TableARTNOM);

   virtual TFIBWideStringField * get_TableNAMENOM(void);
   virtual void set_TableNAMENOM(TFIBWideStringField * TableNAMENOM);

   virtual TFIBIntegerField * get_TableCODE_SPRNOM(void);
   virtual void set_TableCODE_SPRNOM(TFIBIntegerField * TableCODE_SPRNOM);

   virtual TFIBWideStringField * get_TableART_SPRNOM(void);
   virtual void set_TableART_SPRNOM(TFIBWideStringField * TableART_SPRNOM);

   virtual TFIBWideStringField * get_TableNAME_SPRNOM(void);
   virtual void set_TableNAME_SPRNOM(TFIBWideStringField * TableNAME_SPRNOM);

   virtual TFIBLargeIntField * get_ElementIDTYPUSLA_REM_SKOMPLMODEL(void);
   virtual void set_ElementIDTYPUSLA_REM_SKOMPLMODEL(TFIBLargeIntField * ElementIDTYPUSLA_REM_SKOMPLMODEL);

   virtual TFIBWideStringField * get_ElementPARTNUM_REM_SKOMPLMODEL(void);
   virtual void set_ElementPARTNUM_REM_SKOMPLMODEL(TFIBWideStringField * ElementPARTNUM_REM_SKOMPLMODEL);

   virtual TFIBWideStringField * get_ElementDESCR_REM_SKOMPLMODEL(void);
   virtual void set_ElementDESCR_REM_SKOMPLMODEL(TFIBWideStringField * ElementDESCR_REM_SKOMPLMODEL);

   virtual TFIBLargeIntField * get_ElementIDNOM_REM_SKOMPLMODEL(void);
   virtual void set_ElementIDNOM_REM_SKOMPLMODEL(TFIBLargeIntField * ElementIDNOM_REM_SKOMPLMODEL);

   virtual TFIBLargeIntField * get_ElementIDPRNOM_REM_SKOMPLMODEL(void);
   virtual void set_ElementIDPRNOM_REM_SKOMPLMODEL(TFIBLargeIntField * ElementIDPRNOM_REM_SKOMPLMODEL);

   virtual TFIBWideStringField * get_ElementNAME_REM_STYPUSLOV(void);
   virtual void set_ElementNAME_REM_STYPUSLOV(TFIBWideStringField * ElementNAME_REM_STYPUSLOV);

   virtual TFIBIntegerField * get_ElementCODENOM(void);
   virtual void set_ElementCODENOM(TFIBIntegerField * ElementCODENOM);

   virtual TFIBWideStringField * get_ElementARTNOM(void);
   virtual void set_ElementARTNOM(TFIBWideStringField * ElementARTNOM);

   virtual TFIBWideStringField * get_ElementNAMENOM(void);
   virtual void set_ElementNAMENOM(TFIBWideStringField * ElementNAMENOM);

   virtual TFIBIntegerField * get_ElementCODE_SPRNOM(void);
   virtual void set_ElementCODE_SPRNOM(TFIBIntegerField * ElementCODE_SPRNOM);

   virtual TFIBWideStringField * get_ElementART_SPRNOM(void);
   virtual void set_ElementART_SPRNOM(TFIBWideStringField * ElementART_SPRNOM);

   virtual TFIBWideStringField * get_ElementNAME_SPRNOM(void);
   virtual void set_ElementNAME_SPRNOM(TFIBWideStringField * ElementNAME_SPRNOM);

   virtual void OpenTable(__int64 id_model);
   virtual int OpenElement(__int64 id);
   virtual bool NewElement(__int64 id_model);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual __int64 GetIDElement(String gid);
   virtual UnicodeString GetGIDElement(__int64 id);
};
#define CLSID_TREM_DMSprKomplModelImpl __uuidof(TREM_DMSprKomplModelImpl)
#endif
