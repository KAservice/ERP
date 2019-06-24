#ifndef UREM_DMSprHardwareIspImplH
#define UREM_DMSprHardwareIspImplH
#include "IREM_DMSprHardwareIsp.h"
#include "UREM_DMSprHardwareIsp.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMSprHardwareIspImpl)) TREM_DMSprHardwareIspImpl : public IREM_DMSprHardwareIsp
{
public:
   TREM_DMSprHardwareIspImpl();
   ~TREM_DMSprHardwareIspImpl();
   TREM_DMSprHardwareIsp * Object;
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

//IREM_DMSprHardwareIsp
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

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBLargeIntField * get_TableID_REM_SHARDWARE_ISP(void);
   virtual void set_TableID_REM_SHARDWARE_ISP(TFIBLargeIntField * TableID_REM_SHARDWARE_ISP);

   virtual TFIBLargeIntField * get_TableIDBASE_REM_SHARDWARE_ISP(void);
   virtual void set_TableIDBASE_REM_SHARDWARE_ISP(TFIBLargeIntField * TableIDBASE_REM_SHARDWARE_ISP);

   virtual TFIBLargeIntField * get_TableIDHW_REM_SHARDWARE_ISP(void);
   virtual void set_TableIDHW_REM_SHARDWARE_ISP(TFIBLargeIntField * TableIDHW_REM_SHARDWARE_ISP);

   virtual TFIBDateTimeField * get_TablePOS_REM_SHARDWARE_ISP(void);
   virtual void set_TablePOS_REM_SHARDWARE_ISP(TFIBDateTimeField * TablePOS_REM_SHARDWARE_ISP);

   virtual TFIBLargeIntField * get_TableIDUSER_REM_SHARDWARE_ISP(void);
   virtual void set_TableIDUSER_REM_SHARDWARE_ISP(TFIBLargeIntField * TableIDUSER_REM_SHARDWARE_ISP);

   virtual TFIBLargeIntField * get_TableIDTYPEUSEL_REM_SHARDWARE_ISP(void);
   virtual void set_TableIDTYPEUSEL_REM_SHARDWARE_ISP(TFIBLargeIntField * TableIDTYPEUSEL_REM_SHARDWARE_ISP);

   virtual TFIBBCDField * get_TableKOL_REM_SHARDWARE_ISP(void);
   virtual void set_TableKOL_REM_SHARDWARE_ISP(TFIBBCDField * TableKOL_REM_SHARDWARE_ISP);

   virtual TFIBWideStringField * get_TableDESCR_REM_SHARDWARE_ISP(void);
   virtual void set_TableDESCR_REM_SHARDWARE_ISP(TFIBWideStringField * TableDESCR_REM_SHARDWARE_ISP);

   virtual TFIBSmallIntField * get_TableFL_OTCH_PR_REM_SHARDWARE_ISP(void);
   virtual void set_TableFL_OTCH_PR_REM_SHARDWARE_ISP(TFIBSmallIntField * TableFL_OTCH_PR_REM_SHARDWARE_ISP);

   virtual TFIBSmallIntField * get_TableFL_REAL_ISP_REM_SHARDWARE_ISP(void);
   virtual void set_TableFL_REAL_ISP_REM_SHARDWARE_ISP(TFIBSmallIntField * TableFL_REAL_ISP_REM_SHARDWARE_ISP);

   virtual TFIBLargeIntField * get_TableIDZ_REM_SHARDWARE_ISP(void);
   virtual void set_TableIDZ_REM_SHARDWARE_ISP(TFIBLargeIntField * TableIDZ_REM_SHARDWARE_ISP);

   virtual TFIBWideStringField * get_TableNAME_REM_STYPUSLOV(void);
   virtual void set_TableNAME_REM_STYPUSLOV(TFIBWideStringField * TableNAME_REM_STYPUSLOV);

   virtual TFIBWideStringField * get_TableNAME_USER(void);
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER);

   virtual TFIBWideStringField * get_TableNAME_REM_Z(void);
   virtual void set_TableNAME_REM_Z(TFIBWideStringField * TableNAME_REM_Z);

   virtual TFIBWideStringField * get_TablePREFIKS_NUM_REM_Z(void);
   virtual void set_TablePREFIKS_NUM_REM_Z(TFIBWideStringField * TablePREFIKS_NUM_REM_Z);

   virtual TFIBDateTimeField * get_TablePOS_REM_Z(void);
   virtual void set_TablePOS_REM_Z(TFIBDateTimeField * TablePOS_REM_Z);

   virtual TFIBIntegerField * get_TableNUM_REM_Z(void);
   virtual void set_TableNUM_REM_Z(TFIBIntegerField * TableNUM_REM_Z);

   virtual TFIBWideStringField * get_TableMODEL_REM_Z(void);
   virtual void set_TableMODEL_REM_Z(TFIBWideStringField * TableMODEL_REM_Z);

   virtual TFIBWideStringField * get_TableSERNUM_REM_Z(void);
   virtual void set_TableSERNUM_REM_Z(TFIBWideStringField * TableSERNUM_REM_Z);

   virtual TFIBLargeIntField * get_ElementID_REM_SHARDWARE_ISP(void);
   virtual void set_ElementID_REM_SHARDWARE_ISP(TFIBLargeIntField * ElementID_REM_SHARDWARE_ISP);

   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SHARDWARE_ISP(void);
   virtual void set_ElementIDBASE_REM_SHARDWARE_ISP(TFIBLargeIntField * ElementIDBASE_REM_SHARDWARE_ISP);

   virtual TFIBLargeIntField * get_ElementIDHW_REM_SHARDWARE_ISP(void);
   virtual void set_ElementIDHW_REM_SHARDWARE_ISP(TFIBLargeIntField * ElementIDHW_REM_SHARDWARE_ISP);

   virtual TFIBDateTimeField * get_ElementPOS_REM_SHARDWARE_ISP(void);
   virtual void set_ElementPOS_REM_SHARDWARE_ISP(TFIBDateTimeField * ElementPOS_REM_SHARDWARE_ISP);

   virtual TFIBLargeIntField * get_ElementIDUSER_REM_SHARDWARE_ISP(void);
   virtual void set_ElementIDUSER_REM_SHARDWARE_ISP(TFIBLargeIntField * ElementIDUSER_REM_SHARDWARE_ISP);

   virtual TFIBLargeIntField * get_ElementIDTYPEUSEL_REM_SHARDWARE_ISP(void);
   virtual void set_ElementIDTYPEUSEL_REM_SHARDWARE_ISP(TFIBLargeIntField * ElementIDTYPEUSEL_REM_SHARDWARE_ISP);

   virtual TFIBBCDField * get_ElementKOL_REM_SHARDWARE_ISP(void);
   virtual void set_ElementKOL_REM_SHARDWARE_ISP(TFIBBCDField * ElementKOL_REM_SHARDWARE_ISP);

   virtual TFIBWideStringField * get_ElementDESCR_REM_SHARDWARE_ISP(void);
   virtual void set_ElementDESCR_REM_SHARDWARE_ISP(TFIBWideStringField * ElementDESCR_REM_SHARDWARE_ISP);

   virtual TFIBSmallIntField * get_ElementFL_OTCH_PR_REM_SHARDWARE_ISP(void);
   virtual void set_ElementFL_OTCH_PR_REM_SHARDWARE_ISP(TFIBSmallIntField * ElementFL_OTCH_PR_REM_SHARDWARE_ISP);

   virtual TFIBSmallIntField * get_ElementFL_REAL_ISP_REM_SHARDWARE_ISP(void);
   virtual void set_ElementFL_REAL_ISP_REM_SHARDWARE_ISP(TFIBSmallIntField * ElementFL_REAL_ISP_REM_SHARDWARE_ISP);

   virtual TFIBLargeIntField * get_ElementIDZ_REM_SHARDWARE_ISP(void);
   virtual void set_ElementIDZ_REM_SHARDWARE_ISP(TFIBLargeIntField * ElementIDZ_REM_SHARDWARE_ISP);

   virtual TFIBWideStringField * get_ElementNAME_REM_STYPUSLOV(void);
   virtual void set_ElementNAME_REM_STYPUSLOV(TFIBWideStringField * ElementNAME_REM_STYPUSLOV);

   virtual TFIBWideStringField * get_ElementNAME_USER(void);
   virtual void set_ElementNAME_USER(TFIBWideStringField * ElementNAME_USER);

   virtual TFIBWideStringField * get_ElementNAME_REM_Z(void);
   virtual void set_ElementNAME_REM_Z(TFIBWideStringField * ElementNAME_REM_Z);

   virtual TFIBWideStringField * get_ElementPREFIKS_NUM_REM_Z(void);
   virtual void set_ElementPREFIKS_NUM_REM_Z(TFIBWideStringField * ElementPREFIKS_NUM_REM_Z);

   virtual TFIBDateTimeField * get_ElementPOS_REM_Z(void);
   virtual void set_ElementPOS_REM_Z(TFIBDateTimeField * ElementPOS_REM_Z);

   virtual TFIBIntegerField * get_ElementNUM_REM_Z(void);
   virtual void set_ElementNUM_REM_Z(TFIBIntegerField * ElementNUM_REM_Z);

   virtual TFIBWideStringField * get_ElementMODEL_REM_Z(void);
   virtual void set_ElementMODEL_REM_Z(TFIBWideStringField * ElementMODEL_REM_Z);

   virtual TFIBWideStringField * get_ElementSERNUM_REM_Z(void);
   virtual void set_ElementSERNUM_REM_Z(TFIBWideStringField * ElementSERNUM_REM_Z);

   virtual __int64 get_IdOwner(void);
   virtual void set_IdOwner(__int64 IdOwner);

   virtual void OpenTable(__int64 id_owner);
   virtual int OpenElement(__int64 id);
   virtual bool NewElement(__int64 id_owner);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
};
#define CLSID_TREM_DMSprHardwareIspImpl __uuidof(TREM_DMSprHardwareIspImpl)
#endif
