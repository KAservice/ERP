#ifndef UREM_DMSprKKTImplH
#define UREM_DMSprKKTImplH
#include "IREM_DMSprKKT.h"
#include "UREM_DMSprKKT.h"
//---------------------------------------------------------------
class __declspec(uuid("{F18D72EA-144C-4E81-902C-65A00D75DB75}"))TREM_DMSprKKTImpl : public IREM_DMSprKKT
{
public:
   TREM_DMSprKKTImpl();
   ~TREM_DMSprKKTImpl();
   TREM_DMSprKKT * Object;
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

//IREM_DMSprKKT
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

   virtual TpFIBQuery * get_Query(void);
   virtual void set_Query(TpFIBQuery * Query);

   virtual TFIBLargeIntField * get_TableID_REM_SKKT(void);
   virtual void set_TableID_REM_SKKT(TFIBLargeIntField * TableID_REM_SKKT);

   virtual TFIBWideStringField * get_TableNAME_REM_SKKT(void);
   virtual void set_TableNAME_REM_SKKT(TFIBWideStringField * TableNAME_REM_SKKT);

   virtual TFIBWideStringField * get_TableSERNUM_REM_SKKT(void);
   virtual void set_TableSERNUM_REM_SKKT(TFIBWideStringField * TableSERNUM_REM_SKKT);

   virtual TFIBWideStringField * get_TableNAME_REM_SMODEL(void);
   virtual void set_TableNAME_REM_SMODEL(TFIBWideStringField * TableNAME_REM_SMODEL);

   virtual TFIBWideStringField * get_TableMESTOUST_REM_SKKT(void);
   virtual void set_TableMESTOUST_REM_SKKT(TFIBWideStringField * TableMESTOUST_REM_SKKT);

   virtual TFIBLargeIntField * get_TableIDGRP_REM_SKKT(void);
   virtual void set_TableIDGRP_REM_SKKT(TFIBLargeIntField * TableIDGRP_REM_SKKT);

   virtual TFIBLargeIntField * get_ElementID_REM_SKKT(void);
   virtual void set_ElementID_REM_SKKT(TFIBLargeIntField * ElementID_REM_SKKT);

   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SKKT(void);
   virtual void set_ElementIDBASE_REM_SKKT(TFIBLargeIntField * ElementIDBASE_REM_SKKT);

   virtual TFIBWideStringField * get_ElementNAME_REM_SKKT(void);
   virtual void set_ElementNAME_REM_SKKT(TFIBWideStringField * ElementNAME_REM_SKKT);

   virtual TFIBWideStringField * get_ElementSERNUM_REM_SKKT(void);
   virtual void set_ElementSERNUM_REM_SKKT(TFIBWideStringField * ElementSERNUM_REM_SKKT);

   virtual TFIBLargeIntField * get_ElementIDMODEL_REM_SKKT(void);
   virtual void set_ElementIDMODEL_REM_SKKT(TFIBLargeIntField * ElementIDMODEL_REM_SKKT);

   virtual TFIBWideStringField * get_ElementREGNUM_REM_SKKT(void);
   virtual void set_ElementREGNUM_REM_SKKT(TFIBWideStringField * ElementREGNUM_REM_SKKT);

   virtual TFIBLargeIntField * get_ElementIDKLIENT_REM_SKKT(void);
   virtual void set_ElementIDKLIENT_REM_SKKT(TFIBLargeIntField * ElementIDKLIENT_REM_SKKT);

   virtual TFIBWideStringField * get_ElementMESTOUST_REM_SKKT(void);
   virtual void set_ElementMESTOUST_REM_SKKT(TFIBWideStringField * ElementMESTOUST_REM_SKKT);

   virtual TFIBDateField * get_ElementRELEASE_REM_SKKT(void);
   virtual void set_ElementRELEASE_REM_SKKT(TFIBDateField * ElementRELEASE_REM_SKKT);

   virtual TFIBDateField * get_ElementVVOD_REM_SKKT(void);
   virtual void set_ElementVVOD_REM_SKKT(TFIBDateField * ElementVVOD_REM_SKKT);

   virtual TFIBWideStringField * get_ElementCBKGR_REM_SKKT(void);
   virtual void set_ElementCBKGR_REM_SKKT(TFIBWideStringField * ElementCBKGR_REM_SKKT);

   virtual TFIBWideStringField * get_ElementCBKCO_REM_SKKT(void);
   virtual void set_ElementCBKCO_REM_SKKT(TFIBWideStringField * ElementCBKCO_REM_SKKT);

   virtual TFIBWideStringField * get_ElementNUMCONTRACT_REM_SKKT(void);
   virtual void set_ElementNUMCONTRACT_REM_SKKT(TFIBWideStringField * ElementNUMCONTRACT_REM_SKKT);

   virtual TFIBDateField * get_ElementDATECONTRACT_REM_SKKT(void);
   virtual void set_ElementDATECONTRACT_REM_SKKT(TFIBDateField * ElementDATECONTRACT_REM_SKKT);

   virtual TFIBBCDField * get_ElementSUMCONTRACT_REM_SKKT(void);
   virtual void set_ElementSUMCONTRACT_REM_SKKT(TFIBBCDField * ElementSUMCONTRACT_REM_SKKT);

   virtual TFIBWideStringField * get_ElementEKLZ_SERNUM_REM_SKKT(void);
   virtual void set_ElementEKLZ_SERNUM_REM_SKKT(TFIBWideStringField * ElementEKLZ_SERNUM_REM_SKKT);

   virtual TFIBWideStringField * get_ElementEKLZ_REGNUM_REM_SKKT(void);
   virtual void set_ElementEKLZ_REGNUM_REM_SKKT(TFIBWideStringField * ElementEKLZ_REGNUM_REM_SKKT);

   virtual TFIBDateField * get_ElementEKLZ_ACT_REM_SKKT(void);
   virtual void set_ElementEKLZ_ACT_REM_SKKT(TFIBDateField * ElementEKLZ_ACT_REM_SKKT);

   virtual TFIBWideStringField * get_ElementPAS_NUMVER_REM_SKKT(void);
   virtual void set_ElementPAS_NUMVER_REM_SKKT(TFIBWideStringField * ElementPAS_NUMVER_REM_SKKT);

   virtual TFIBWideStringField * get_ElementPAS_NUMPAS_REM_SKKT(void);
   virtual void set_ElementPAS_NUMPAS_REM_SKKT(TFIBWideStringField * ElementPAS_NUMPAS_REM_SKKT);

   virtual TFIBWideStringField * get_ElementPAS_NUMPU_REM_SKKT(void);
   virtual void set_ElementPAS_NUMPU_REM_SKKT(TFIBWideStringField * ElementPAS_NUMPU_REM_SKKT);

   virtual TFIBWideStringField * get_ElementPAS_NUMSP_REM_SKKT(void);
   virtual void set_ElementPAS_NUMSP_REM_SKKT(TFIBWideStringField * ElementPAS_NUMSP_REM_SKKT);

   virtual TFIBWideStringField * get_ElementPAS_NUMSPPO_REM_SKKT(void);
   virtual void set_ElementPAS_NUMSPPO_REM_SKKT(TFIBWideStringField * ElementPAS_NUMSPPO_REM_SKKT);

   virtual TFIBWideStringField * get_ElementPAS_NUMFP_REM_SKKT(void);
   virtual void set_ElementPAS_NUMFP_REM_SKKT(TFIBWideStringField * ElementPAS_NUMFP_REM_SKKT);

   virtual TFIBWideStringField * get_ElementPAS_NUMFPPO_REM_SKKT(void);
   virtual void set_ElementPAS_NUMFPPO_REM_SKKT(TFIBWideStringField * ElementPAS_NUMFPPO_REM_SKKT);

   virtual TFIBWideStringField * get_ElementPAS_NUMDO_REM_SKKT(void);
   virtual void set_ElementPAS_NUMDO_REM_SKKT(TFIBWideStringField * ElementPAS_NUMDO_REM_SKKT);

   virtual TFIBWideStringField * get_ElementPAS_NUMDOPO_REM_SKKT(void);
   virtual void set_ElementPAS_NUMDOPO_REM_SKKT(TFIBWideStringField * ElementPAS_NUMDOPO_REM_SKKT);

   virtual TFIBWideStringField * get_ElementPAS_NUMPPP_REM_SKKT(void);
   virtual void set_ElementPAS_NUMPPP_REM_SKKT(TFIBWideStringField * ElementPAS_NUMPPP_REM_SKKT);

   virtual TFIBWideStringField * get_ElementPAS_DOR_REM_SKKT(void);
   virtual void set_ElementPAS_DOR_REM_SKKT(TFIBWideStringField * ElementPAS_DOR_REM_SKKT);

   virtual TFIBWideStringField * get_ElementPAS_PRIM_REM_SKKT(void);
   virtual void set_ElementPAS_PRIM_REM_SKKT(TFIBWideStringField * ElementPAS_PRIM_REM_SKKT);

   virtual TFIBLargeIntField * get_ElementIDGRP_REM_SKKT(void);
   virtual void set_ElementIDGRP_REM_SKKT(TFIBLargeIntField * ElementIDGRP_REM_SKKT);

   virtual TFIBWideStringField * get_ElementPRIM_REM_SKKT(void);
   virtual void set_ElementPRIM_REM_SKKT(TFIBWideStringField * ElementPRIM_REM_SKKT);

   virtual TFIBWideStringField * get_ElementNAME_REM_SMODEL(void);
   virtual void set_ElementNAME_REM_SMODEL(TFIBWideStringField * ElementNAME_REM_SMODEL);

   virtual TFIBWideStringField * get_ElementOWNER_NAME(void);
   virtual void set_ElementOWNER_NAME(TFIBWideStringField * ElementOWNER_NAME);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual bool get_flChangeData(void);
   virtual void set_flChangeData(bool flChangeData);

   virtual void OpenTable(__int64 id_grp, bool all);
   virtual UnicodeString GetTextQuery(__int64 id_grp, bool all);
   virtual int OpenElement(__int64 id);
   virtual bool NewElement(__int64 id_grp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual void ChancheGrp(__int64 new_id_grp);
   virtual __int64 FindPoName(UnicodeString name);
   virtual __int64 GetIdGrpElementa(__int64 id_element);
   virtual void AddNewRecordDv(void);
};
#define CLSID_TREM_DMSprKKTImpl __uuidof(TREM_DMSprKKTImpl)
#endif
