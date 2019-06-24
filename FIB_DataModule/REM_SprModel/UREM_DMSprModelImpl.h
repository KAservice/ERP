#ifndef UREM_DMSprModelImplH
#define UREM_DMSprModelImplH
#include "IREM_DMSprModel.h"
#include "UREM_DMSprModel.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMSprModelImpl)) TREM_DMSprModelImpl : public IREM_DMSprModel
{
public:
   TREM_DMSprModelImpl();
   ~TREM_DMSprModelImpl();
   TREM_DMSprModel * Object;
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

//IREM_DMSprModel
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

   virtual TpFIBQuery * get_pFIBQuery(void);
   virtual void set_pFIBQuery(TpFIBQuery * pFIBQuery);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBLargeIntField * get_TableID_REM_SMODEL(void);
   virtual void set_TableID_REM_SMODEL(TFIBLargeIntField * TableID_REM_SMODEL);

   virtual TFIBWideStringField * get_TableGID_REM_SMODEL(void);
   virtual void set_TableGID_REM_SMODEL(TFIBWideStringField * TableGID_REM_SMODEL);

   virtual TFIBLargeIntField * get_TableIDGRP_REM_SMODEL(void);
   virtual void set_TableIDGRP_REM_SMODEL(TFIBLargeIntField * TableIDGRP_REM_SMODEL);

   virtual TFIBWideStringField * get_TableNAME_REM_SMODEL(void);
   virtual void set_TableNAME_REM_SMODEL(TFIBWideStringField * TableNAME_REM_SMODEL);

   virtual TFIBLargeIntField * get_TableIDBASE_REM_SMODEL(void);
   virtual void set_TableIDBASE_REM_SMODEL(TFIBLargeIntField * TableIDBASE_REM_SMODEL);

   virtual TFIBLargeIntField * get_ElementID_REM_SMODEL(void);
   virtual void set_ElementID_REM_SMODEL(TFIBLargeIntField * ElementID_REM_SMODEL);

   virtual TFIBWideStringField * get_ElementGID_REM_SMODEL(void);
   virtual void set_ElementGID_REM_SMODEL(TFIBWideStringField * ElementGID_REM_SMODEL);

   virtual TFIBLargeIntField * get_ElementIDGRP_REM_SMODEL(void);
   virtual void set_ElementIDGRP_REM_SMODEL(TFIBLargeIntField * ElementIDGRP_REM_SMODEL);

   virtual TFIBWideStringField * get_ElementNAME_REM_SMODEL(void);
   virtual void set_ElementNAME_REM_SMODEL(TFIBWideStringField * ElementNAME_REM_SMODEL);

   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SMODEL(void);
   virtual void set_ElementIDBASE_REM_SMODEL(TFIBLargeIntField * ElementIDBASE_REM_SMODEL);

   virtual TFIBLargeIntField * get_ElementIDNOM_REM_SMODEL(void);
   virtual void set_ElementIDNOM_REM_SMODEL(TFIBLargeIntField * ElementIDNOM_REM_SMODEL);

   virtual TFIBWideStringField * get_ElementSTRCODE_REM_SMODEL(void);
   virtual void set_ElementSTRCODE_REM_SMODEL(TFIBWideStringField * ElementSTRCODE_REM_SMODEL);

   virtual TFIBWideStringField * get_ElementNAMENOM(void);
   virtual void set_ElementNAMENOM(TFIBWideStringField * ElementNAMENOM);

   virtual TFIBLargeIntField * get_ElementIDBRAND_REM_SMODEL(void);
   virtual void set_ElementIDBRAND_REM_SMODEL(TFIBLargeIntField * ElementIDBRAND_REM_SMODEL);

   virtual TFIBWideStringField * get_ElementNAME_SBRAND(void);
   virtual void set_ElementNAME_SBRAND(TFIBWideStringField * ElementNAME_SBRAND);

   virtual TFIBWideStringField * get_TableSTRCODE_REM_SMODEL(void);
   virtual void set_TableSTRCODE_REM_SMODEL(TFIBWideStringField * TableSTRCODE_REM_SMODEL);

   virtual TFIBLargeIntField * get_TableIDBRAND_REM_SMODEL(void);
   virtual void set_TableIDBRAND_REM_SMODEL(TFIBLargeIntField * TableIDBRAND_REM_SMODEL);

   virtual TFIBLargeIntField * get_TableIDPRMODEL_REM_SMODEL(void);
   virtual void set_TableIDPRMODEL_REM_SMODEL(TFIBLargeIntField * TableIDPRMODEL_REM_SMODEL);

   virtual TFIBWideStringField * get_TableDESCR_REM_SMODEL(void);
   virtual void set_TableDESCR_REM_SMODEL(TFIBWideStringField * TableDESCR_REM_SMODEL);

   virtual TFIBWideStringField * get_TableNAME_REM_SPRMODEL(void);
   virtual void set_TableNAME_REM_SPRMODEL(TFIBWideStringField * TableNAME_REM_SPRMODEL);

   virtual TFIBWideStringField * get_TableNAME_SBRAND(void);
   virtual void set_TableNAME_SBRAND(TFIBWideStringField * TableNAME_SBRAND);

   virtual TFIBLargeIntField * get_TableIDNOM_REM_SMODEL(void);
   virtual void set_TableIDNOM_REM_SMODEL(TFIBLargeIntField * TableIDNOM_REM_SMODEL);

   virtual TFIBWideStringField * get_TableNAMENOM(void);
   virtual void set_TableNAMENOM(TFIBWideStringField * TableNAMENOM);

   virtual TFIBLargeIntField * get_ElementIDPRMODEL_REM_SMODEL(void);
   virtual void set_ElementIDPRMODEL_REM_SMODEL(TFIBLargeIntField * ElementIDPRMODEL_REM_SMODEL);

   virtual TFIBWideStringField * get_ElementDESCR_REM_SMODEL(void);
   virtual void set_ElementDESCR_REM_SMODEL(TFIBWideStringField * ElementDESCR_REM_SMODEL);

   virtual TFIBWideStringField * get_ElementCODE_REM_SMODEL(void);
   virtual void set_ElementCODE_REM_SMODEL(TFIBWideStringField * ElementCODE_REM_SMODEL);

   virtual TFIBWideStringField * get_ElementNAME_REM_SPRMODEL(void);
   virtual void set_ElementNAME_REM_SPRMODEL(TFIBWideStringField * ElementNAME_REM_SPRMODEL);

   virtual TFIBLargeIntField * get_ElementIDMODELNEISPR_REM_SMODEL(void);
   virtual void set_ElementIDMODELNEISPR_REM_SMODEL(TFIBLargeIntField * ElementIDMODELNEISPR_REM_SMODEL);

   virtual TFIBWideStringField * get_ElementNAME_REM_SMODEL_NEISPR(void);
   virtual void set_ElementNAME_REM_SMODEL_NEISPR(TFIBWideStringField * ElementNAME_REM_SMODEL_NEISPR);

   virtual TFIBWideStringField * get_TableCODE_REM_SMODEL(void);
   virtual void set_TableCODE_REM_SMODEL(TFIBWideStringField * TableCODE_REM_SMODEL);

   virtual TFIBLargeIntField * get_TableIDMODELNEISPR_REM_SMODEL(void);
   virtual void set_TableIDMODELNEISPR_REM_SMODEL(TFIBLargeIntField * TableIDMODELNEISPR_REM_SMODEL);

   virtual TFIBWideStringField * get_TableNAME_REM_SMODEL_NEISPR(void);
   virtual void set_TableNAME_REM_SMODEL_NEISPR(TFIBWideStringField * TableNAME_REM_SMODEL_NEISPR);

   virtual TFIBLargeIntField * get_ElementIDPRODUCER_REM_SMODEL(void);
   virtual void set_ElementIDPRODUCER_REM_SMODEL(TFIBLargeIntField * ElementIDPRODUCER_REM_SMODEL);

   virtual TFIBLargeIntField * get_ElementIDACTCATEGORY_REM_SMODEL(void);
   virtual void set_ElementIDACTCATEGORY_REM_SMODEL(TFIBLargeIntField * ElementIDACTCATEGORY_REM_SMODEL);

   virtual TFIBLargeIntField * get_ElementIDTYPEDEVICE_REM_SMODEL(void);
   virtual void set_ElementIDTYPEDEVICE_REM_SMODEL(TFIBLargeIntField * ElementIDTYPEDEVICE_REM_SMODEL);

   virtual TFIBWideStringField * get_ElementNAME_SPRODUCER(void);
   virtual void set_ElementNAME_SPRODUCER(TFIBWideStringField * ElementNAME_SPRODUCER);

   virtual TFIBWideStringField * get_ElementNAME_REM_SACTCATEGORY(void);
   virtual void set_ElementNAME_REM_SACTCATEGORY(TFIBWideStringField * ElementNAME_REM_SACTCATEGORY);

   virtual TFIBWideStringField * get_ElementNAME_REM_STYPEDEVICE(void);
   virtual void set_ElementNAME_REM_STYPEDEVICE(TFIBWideStringField * ElementNAME_REM_STYPEDEVICE);

   virtual TFIBLargeIntField * get_TableIDPRODUCER_REM_SMODEL(void);
   virtual void set_TableIDPRODUCER_REM_SMODEL(TFIBLargeIntField * TableIDPRODUCER_REM_SMODEL);

   virtual TFIBLargeIntField * get_TableIDACTCATEGORY_REM_SMODEL(void);
   virtual void set_TableIDACTCATEGORY_REM_SMODEL(TFIBLargeIntField * TableIDACTCATEGORY_REM_SMODEL);

   virtual TFIBLargeIntField * get_TableIDTYPEDEVICE_REM_SMODEL(void);
   virtual void set_TableIDTYPEDEVICE_REM_SMODEL(TFIBLargeIntField * TableIDTYPEDEVICE_REM_SMODEL);

   virtual TFIBWideStringField * get_TableNAME_SPRODUCER(void);
   virtual void set_TableNAME_SPRODUCER(TFIBWideStringField * TableNAME_SPRODUCER);

   virtual TFIBWideStringField * get_TableNAME_REM_SACTCATEGORY(void);
   virtual void set_TableNAME_REM_SACTCATEGORY(TFIBWideStringField * TableNAME_REM_SACTCATEGORY);

   virtual TFIBWideStringField * get_TableNAME_REM_STYPEDEVICE(void);
   virtual void set_TableNAME_REM_STYPEDEVICE(TFIBWideStringField * TableNAME_REM_STYPEDEVICE);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual UnicodeString GetTextQuery(__int64 id_grp, bool all);
   virtual void OpenTable(__int64 id_grp, bool all);
   virtual int OpenElement(__int64 id);
   virtual bool NewElement(__int64 id_grp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual void ChancheGrp(__int64 id_new_grp, __int64 id_el);
   virtual __int64 GetIDElement(UnicodeString gid);
   virtual UnicodeString GetGIDElement(__int64 id);
   virtual __int64 GetIdGrpNom(__int64 id);
   virtual __int64 FindPoNom(__int64 id_nom);
};
#define CLSID_TREM_DMSprModelImpl __uuidof(TREM_DMSprModelImpl)
#endif
