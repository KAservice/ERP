#ifndef UREM_DMSprNeisprModelImplH
#define UREM_DMSprNeisprModelImplH
#include "IREM_DMSprNeisprModel.h"
#include "UREM_DMSprNeisprModel.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMSprNeisprModelImpl)) TREM_DMSprNeisprModelImpl : public IREM_DMSprNeisprModel
{
public:
   TREM_DMSprNeisprModelImpl();
   ~TREM_DMSprNeisprModelImpl();
   TREM_DMSprNeisprModel * Object;
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

//IREM_DMSprNeisprModel
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

   virtual TFIBLargeIntField * get_TableID_REM_SNEISPMODEL(void);
   virtual void set_TableID_REM_SNEISPMODEL(TFIBLargeIntField * TableID_REM_SNEISPMODEL);

   virtual TFIBWideStringField * get_TableGID_REM_SNEISPMODEL(void);
   virtual void set_TableGID_REM_SNEISPMODEL(TFIBWideStringField * TableGID_REM_SNEISPMODEL);

   virtual TFIBLargeIntField * get_TableIDBASE_REM_SNEISPMODEL(void);
   virtual void set_TableIDBASE_REM_SNEISPMODEL(TFIBLargeIntField * TableIDBASE_REM_SNEISPMODEL);

   virtual TFIBWideStringField * get_TableDESCR_REM_SNEISPMODEL(void);
   virtual void set_TableDESCR_REM_SNEISPMODEL(TFIBWideStringField * TableDESCR_REM_SNEISPMODEL);

   virtual TFIBLargeIntField * get_TableIDMODEL_REM_SNEISPMODEL(void);
   virtual void set_TableIDMODEL_REM_SNEISPMODEL(TFIBLargeIntField * TableIDMODEL_REM_SNEISPMODEL);

   virtual TFIBLargeIntField * get_TableIDNEISPR_REM_SNEISPMODEL(void);
   virtual void set_TableIDNEISPR_REM_SNEISPMODEL(TFIBLargeIntField * TableIDNEISPR_REM_SNEISPMODEL);

   virtual TFIBWideStringField * get_TableNAME_REM_SNEISPR(void);
   virtual void set_TableNAME_REM_SNEISPR(TFIBWideStringField * TableNAME_REM_SNEISPR);

   virtual TFIBLargeIntField * get_ElementID_REM_SNEISPMODEL(void);
   virtual void set_ElementID_REM_SNEISPMODEL(TFIBLargeIntField * ElementID_REM_SNEISPMODEL);

   virtual TFIBWideStringField * get_ElementGID_REM_SNEISPMODEL(void);
   virtual void set_ElementGID_REM_SNEISPMODEL(TFIBWideStringField * ElementGID_REM_SNEISPMODEL);

   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SNEISPMODEL(void);
   virtual void set_ElementIDBASE_REM_SNEISPMODEL(TFIBLargeIntField * ElementIDBASE_REM_SNEISPMODEL);

   virtual TFIBWideStringField * get_ElementDESCR_REM_SNEISPMODEL(void);
   virtual void set_ElementDESCR_REM_SNEISPMODEL(TFIBWideStringField * ElementDESCR_REM_SNEISPMODEL);

   virtual TFIBLargeIntField * get_ElementIDMODEL_REM_SNEISPMODEL(void);
   virtual void set_ElementIDMODEL_REM_SNEISPMODEL(TFIBLargeIntField * ElementIDMODEL_REM_SNEISPMODEL);

   virtual TFIBLargeIntField * get_ElementIDNEISPR_REM_SNEISPMODEL(void);
   virtual void set_ElementIDNEISPR_REM_SNEISPMODEL(TFIBLargeIntField * ElementIDNEISPR_REM_SNEISPMODEL);

   virtual TFIBWideStringField * get_ElementNAME_REM_SNEISPR(void);
   virtual void set_ElementNAME_REM_SNEISPR(TFIBWideStringField * ElementNAME_REM_SNEISPR);

   virtual TFIBWideStringField * get_TableNAME_REM_SNEISPMODEL(void);
   virtual void set_TableNAME_REM_SNEISPMODEL(TFIBWideStringField * TableNAME_REM_SNEISPMODEL);

   virtual TFIBWideStringField * get_ElementNAME_REM_SNEISPMODEL(void);
   virtual void set_ElementNAME_REM_SNEISPMODEL(TFIBWideStringField * ElementNAME_REM_SNEISPMODEL);

   virtual TFIBLargeIntField * get_ElementIDMODELNEISPR_REM_SNEISPMODEL(void);
   virtual void set_ElementIDMODELNEISPR_REM_SNEISPMODEL(TFIBLargeIntField * ElementIDMODELNEISPR_REM_SNEISPMODEL);

   virtual TFIBWideStringField * get_ElementNAME_REM_SMODEL(void);
   virtual void set_ElementNAME_REM_SMODEL(TFIBWideStringField * ElementNAME_REM_SMODEL);

   virtual TFIBLargeIntField * get_TableIDMODELNEISPR_REM_SNEISPMODEL(void);
   virtual void set_TableIDMODELNEISPR_REM_SNEISPMODEL(TFIBLargeIntField * TableIDMODELNEISPR_REM_SNEISPMODEL);

   virtual TFIBWideStringField * get_TableNAME_REM_SMODEL(void);
   virtual void set_TableNAME_REM_SMODEL(TFIBWideStringField * TableNAME_REM_SMODEL);

   virtual void OpenTable(__int64 id_model);
   virtual int OpenElement(__int64 id);
   virtual bool NewElement(__int64 id_model);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
};
#define CLSID_TREM_DMSprNeisprModelImpl __uuidof(TREM_DMSprNeisprModelImpl)
#endif
