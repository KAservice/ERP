#ifndef UREM_DMSprHardwareImplH
#define UREM_DMSprHardwareImplH
#include "IREM_DMSprHardware.h"
#include "UREM_DMSprHardware.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMSprHardwareImpl)) TREM_DMSprHardwareImpl : public IREM_DMSprHardware
{
public:
   TREM_DMSprHardwareImpl();
   ~TREM_DMSprHardwareImpl();
   TREM_DMSprHardware * Object;
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

//IREM_DMSprHardware
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

   virtual TFIBLargeIntField * get_TableID_REM_SHARDWARE(void);
   virtual void set_TableID_REM_SHARDWARE(TFIBLargeIntField * TableID_REM_SHARDWARE);

   virtual TFIBWideStringField * get_TableNAME_REM_SHARDWARE(void);
   virtual void set_TableNAME_REM_SHARDWARE(TFIBWideStringField * TableNAME_REM_SHARDWARE);

   virtual TFIBWideStringField * get_TableSERNUM_REM_SHARDWARE(void);
   virtual void set_TableSERNUM_REM_SHARDWARE(TFIBWideStringField * TableSERNUM_REM_SHARDWARE);

   virtual TFIBIntegerField * get_TableCODE_REM_SHARDWARE(void);
   virtual void set_TableCODE_REM_SHARDWARE(TFIBIntegerField * TableCODE_REM_SHARDWARE);

   virtual TFIBIntegerField * get_TableSROKWARRANTY_REM_SHARDWARE(void);
   virtual void set_TableSROKWARRANTY_REM_SHARDWARE(TFIBIntegerField * TableSROKWARRANTY_REM_SHARDWARE);

   virtual TFIBWideStringField * get_TableSERNUM2_REM_SHARDWARE(void);
   virtual void set_TableSERNUM2_REM_SHARDWARE(TFIBWideStringField * TableSERNUM2_REM_SHARDWARE);

   virtual TFIBWideStringField * get_TableSERNUM_STR_REM_SHARDWARE(void);
   virtual void set_TableSERNUM_STR_REM_SHARDWARE(TFIBWideStringField * TableSERNUM_STR_REM_SHARDWARE);

   virtual TFIBSmallIntField * get_TableFL_NECOND_REM_SHARDWARE(void);
   virtual void set_TableFL_NECOND_REM_SHARDWARE(TFIBSmallIntField * TableFL_NECOND_REM_SHARDWARE);

   virtual TFIBBCDField * get_TablePRICE_REM_SHARDWARE(void);
   virtual void set_TablePRICE_REM_SHARDWARE(TFIBBCDField * TablePRICE_REM_SHARDWARE);

   virtual TFIBSmallIntField * get_TableFL_FICT_REMONT_REM_SHARDWARE(void);
   virtual void set_TableFL_FICT_REMONT_REM_SHARDWARE(TFIBSmallIntField * TableFL_FICT_REMONT_REM_SHARDWARE);

   virtual TFIBSmallIntField * get_TableFL_REMONT_REM_SHARDWARE(void);
   virtual void set_TableFL_REMONT_REM_SHARDWARE(TFIBSmallIntField * TableFL_REMONT_REM_SHARDWARE);

   virtual TFIBSmallIntField * get_TableFL_ACT_REM_SHARDWARE(void);
   virtual void set_TableFL_ACT_REM_SHARDWARE(TFIBSmallIntField * TableFL_ACT_REM_SHARDWARE);

   virtual TFIBLargeIntField * get_ElementID_REM_SHARDWARE(void);
   virtual void set_ElementID_REM_SHARDWARE(TFIBLargeIntField * ElementID_REM_SHARDWARE);

   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SHARDWARE(void);
   virtual void set_ElementIDBASE_REM_SHARDWARE(TFIBLargeIntField * ElementIDBASE_REM_SHARDWARE);

   virtual TFIBWideStringField * get_ElementNAME_REM_SHARDWARE(void);
   virtual void set_ElementNAME_REM_SHARDWARE(TFIBWideStringField * ElementNAME_REM_SHARDWARE);

   virtual TFIBLargeIntField * get_ElementIDGRP_REM_SHARDWARE(void);
   virtual void set_ElementIDGRP_REM_SHARDWARE(TFIBLargeIntField * ElementIDGRP_REM_SHARDWARE);

   virtual TFIBLargeIntField * get_ElementIDMODEL_REM_SHARDWARE(void);
   virtual void set_ElementIDMODEL_REM_SHARDWARE(TFIBLargeIntField * ElementIDMODEL_REM_SHARDWARE);

   virtual TFIBLargeIntField * get_ElementIDPOST_REM_SHARDWARE(void);
   virtual void set_ElementIDPOST_REM_SHARDWARE(TFIBLargeIntField * ElementIDPOST_REM_SHARDWARE);

   virtual TFIBSmallIntField * get_ElementTYPESYSPOST_REM_SHARDWARE(void);
   virtual void set_ElementTYPESYSPOST_REM_SHARDWARE(TFIBSmallIntField * ElementTYPESYSPOST_REM_SHARDWARE);

   virtual TFIBLargeIntField * get_ElementIDDOCPOST_REM_SHARDWARE(void);
   virtual void set_ElementIDDOCPOST_REM_SHARDWARE(TFIBLargeIntField * ElementIDDOCPOST_REM_SHARDWARE);

   virtual TFIBWideStringField * get_ElementSERNUM_REM_SHARDWARE(void);
   virtual void set_ElementSERNUM_REM_SHARDWARE(TFIBWideStringField * ElementSERNUM_REM_SHARDWARE);

   virtual TFIBDateField * get_ElementWARRANTY_REM_SHARDWARE(void);
   virtual void set_ElementWARRANTY_REM_SHARDWARE(TFIBDateField * ElementWARRANTY_REM_SHARDWARE);

   virtual TFIBDateField * get_ElementSALE_REM_SHARDWARE(void);
   virtual void set_ElementSALE_REM_SHARDWARE(TFIBDateField * ElementSALE_REM_SHARDWARE);

   virtual TFIBLargeIntField * get_ElementIDVLAD_REM_SHARDWARE(void);
   virtual void set_ElementIDVLAD_REM_SHARDWARE(TFIBLargeIntField * ElementIDVLAD_REM_SHARDWARE);

   virtual TFIBWideStringField * get_ElementNAMEVLAD_REM_SHARDWARE(void);
   virtual void set_ElementNAMEVLAD_REM_SHARDWARE(TFIBWideStringField * ElementNAMEVLAD_REM_SHARDWARE);

   virtual TFIBSmallIntField * get_ElementTYPESYSSALE_REM_SHARDWARE(void);
   virtual void set_ElementTYPESYSSALE_REM_SHARDWARE(TFIBSmallIntField * ElementTYPESYSSALE_REM_SHARDWARE);

   virtual TFIBLargeIntField * get_ElementIDDOCSALE_REM_SHARDWARE(void);
   virtual void set_ElementIDDOCSALE_REM_SHARDWARE(TFIBLargeIntField * ElementIDDOCSALE_REM_SHARDWARE);

   virtual TFIBIntegerField * get_ElementCODE_REM_SHARDWARE(void);
   virtual void set_ElementCODE_REM_SHARDWARE(TFIBIntegerField * ElementCODE_REM_SHARDWARE);

   virtual TFIBIntegerField * get_ElementSROKWARRANTY_REM_SHARDWARE(void);
   virtual void set_ElementSROKWARRANTY_REM_SHARDWARE(TFIBIntegerField * ElementSROKWARRANTY_REM_SHARDWARE);

   virtual TFIBLargeIntField * get_ElementIDDOCREM_SALE_REM_SHARDWARE(void);
   virtual void set_ElementIDDOCREM_SALE_REM_SHARDWARE(TFIBLargeIntField * ElementIDDOCREM_SALE_REM_SHARDWARE);

   virtual TFIBWideStringField * get_ElementSERNUM2_REM_SHARDWARE(void);
   virtual void set_ElementSERNUM2_REM_SHARDWARE(TFIBWideStringField * ElementSERNUM2_REM_SHARDWARE);

   virtual TFIBWideStringField * get_ElementSERNUM_STR_REM_SHARDWARE(void);
   virtual void set_ElementSERNUM_STR_REM_SHARDWARE(TFIBWideStringField * ElementSERNUM_STR_REM_SHARDWARE);

   virtual TFIBSmallIntField * get_ElementFL_NECOND_REM_SHARDWARE(void);
   virtual void set_ElementFL_NECOND_REM_SHARDWARE(TFIBSmallIntField * ElementFL_NECOND_REM_SHARDWARE);

   virtual TFIBBCDField * get_ElementPRICE_REM_SHARDWARE(void);
   virtual void set_ElementPRICE_REM_SHARDWARE(TFIBBCDField * ElementPRICE_REM_SHARDWARE);

   virtual TFIBWideStringField * get_ElementPRICHINA_REM_SHARDWARE(void);
   virtual void set_ElementPRICHINA_REM_SHARDWARE(TFIBWideStringField * ElementPRICHINA_REM_SHARDWARE);

   virtual TFIBWideStringField * get_ElementPRIM_REM_SHARDWARE(void);
   virtual void set_ElementPRIM_REM_SHARDWARE(TFIBWideStringField * ElementPRIM_REM_SHARDWARE);

   virtual TFIBSmallIntField * get_ElementFL_FICT_REMONT_REM_SHARDWARE(void);
   virtual void set_ElementFL_FICT_REMONT_REM_SHARDWARE(TFIBSmallIntField * ElementFL_FICT_REMONT_REM_SHARDWARE);

   virtual TFIBSmallIntField * get_ElementFL_REMONT_REM_SHARDWARE(void);
   virtual void set_ElementFL_REMONT_REM_SHARDWARE(TFIBSmallIntField * ElementFL_REMONT_REM_SHARDWARE);

   virtual TFIBLargeIntField * get_ElementIDPRODUCER_REM_SHARDWARE(void);
   virtual void set_ElementIDPRODUCER_REM_SHARDWARE(TFIBLargeIntField * ElementIDPRODUCER_REM_SHARDWARE);

   virtual TFIBLargeIntField * get_ElementIDBRAND_REM_SHARDWARE(void);
   virtual void set_ElementIDBRAND_REM_SHARDWARE(TFIBLargeIntField * ElementIDBRAND_REM_SHARDWARE);

   virtual TFIBLargeIntField * get_ElementIDZ_REM_SHARDWARE(void);
   virtual void set_ElementIDZ_REM_SHARDWARE(TFIBLargeIntField * ElementIDZ_REM_SHARDWARE);

   virtual TFIBIntegerField * get_ElementTYPE_ELEMENTA_REM_SHARDWARE(void);
   virtual void set_ElementTYPE_ELEMENTA_REM_SHARDWARE(TFIBIntegerField * ElementTYPE_ELEMENTA_REM_SHARDWARE);

   virtual TFIBSmallIntField * get_ElementFL_ACT_REM_SHARDWARE(void);
   virtual void set_ElementFL_ACT_REM_SHARDWARE(TFIBSmallIntField * ElementFL_ACT_REM_SHARDWARE);

   virtual TFIBSmallIntField * get_ElementFL_UTILIZ_REM_SHARDWARE(void);
   virtual void set_ElementFL_UTILIZ_REM_SHARDWARE(TFIBSmallIntField * ElementFL_UTILIZ_REM_SHARDWARE);

   virtual TFIBDateTimeField * get_ElementPOS_POST_REM_SHARDWARE(void);
   virtual void set_ElementPOS_POST_REM_SHARDWARE(TFIBDateTimeField * ElementPOS_POST_REM_SHARDWARE);

   virtual TFIBDateTimeField * get_ElementPOS_UTILIZ_REM_SHARDWARE(void);
   virtual void set_ElementPOS_UTILIZ_REM_SHARDWARE(TFIBDateTimeField * ElementPOS_UTILIZ_REM_SHARDWARE);

   virtual TFIBDateTimeField * get_ElementPOS_HRAN_DO_REM_SHARDWARE(void);
   virtual void set_ElementPOS_HRAN_DO_REM_SHARDWARE(TFIBDateTimeField * ElementPOS_HRAN_DO_REM_SHARDWARE);

   virtual TFIBLargeIntField * get_ElementIDPRMODEL_REM_SHARDWARE(void);
   virtual void set_ElementIDPRMODEL_REM_SHARDWARE(TFIBLargeIntField * ElementIDPRMODEL_REM_SHARDWARE);

   virtual TFIBWideStringField * get_ElementNAME_REM_SMODEL(void);
   virtual void set_ElementNAME_REM_SMODEL(TFIBWideStringField * ElementNAME_REM_SMODEL);

   virtual TFIBWideStringField * get_ElementSUPPLIER_NAME(void);
   virtual void set_ElementSUPPLIER_NAME(TFIBWideStringField * ElementSUPPLIER_NAME);

   virtual TFIBWideStringField * get_ElementOWNER_NAME(void);
   virtual void set_ElementOWNER_NAME(TFIBWideStringField * ElementOWNER_NAME);

   virtual TFIBWideStringField * get_ElementTDOC_DOCPOST(void);
   virtual void set_ElementTDOC_DOCPOST(TFIBWideStringField * ElementTDOC_DOCPOST);

   virtual TFIBDateTimeField * get_ElementPOSDOC_DOCPOST(void);
   virtual void set_ElementPOSDOC_DOCPOST(TFIBDateTimeField * ElementPOSDOC_DOCPOST);

   virtual TFIBIntegerField * get_ElementNUMDOC_DOCPOST(void);
   virtual void set_ElementNUMDOC_DOCPOST(TFIBIntegerField * ElementNUMDOC_DOCPOST);

   virtual TFIBWideStringField * get_ElementTDOC_DOCSALE(void);
   virtual void set_ElementTDOC_DOCSALE(TFIBWideStringField * ElementTDOC_DOCSALE);

   virtual TFIBDateTimeField * get_ElementPOSDOC_DOCSALE(void);
   virtual void set_ElementPOSDOC_DOCSALE(TFIBDateTimeField * ElementPOSDOC_DOCSALE);

   virtual TFIBIntegerField * get_ElementNUMDOC_DOCSALE(void);
   virtual void set_ElementNUMDOC_DOCSALE(TFIBIntegerField * ElementNUMDOC_DOCSALE);

   virtual TFIBWideStringField * get_ElementNAME_SBRAND(void);
   virtual void set_ElementNAME_SBRAND(TFIBWideStringField * ElementNAME_SBRAND);

   virtual TFIBWideStringField * get_ElementNAME_SPRODUCER(void);
   virtual void set_ElementNAME_SPRODUCER(TFIBWideStringField * ElementNAME_SPRODUCER);

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

   virtual TFIBWideStringField * get_ElementNAME_REM_SPRMODEL(void);
   virtual void set_ElementNAME_REM_SPRMODEL(TFIBWideStringField * ElementNAME_REM_SPRMODEL);

   virtual TFIBWideStringField * get_TableNAME_ENG_REM_SHARDWARE(void);
   virtual void set_TableNAME_ENG_REM_SHARDWARE(TFIBWideStringField * TableNAME_ENG_REM_SHARDWARE);

   virtual TFIBWideStringField * get_TableARTIKUL_REM_SHARDWARE(void);
   virtual void set_TableARTIKUL_REM_SHARDWARE(TFIBWideStringField * TableARTIKUL_REM_SHARDWARE);

   virtual TFIBWideStringField * get_TablePARTNUM_REM_SHARDWARE(void);
   virtual void set_TablePARTNUM_REM_SHARDWARE(TFIBWideStringField * TablePARTNUM_REM_SHARDWARE);

   virtual TFIBWideStringField * get_ElementSERNUM3_REM_SHARDWARE(void);
   virtual void set_ElementSERNUM3_REM_SHARDWARE(TFIBWideStringField * ElementSERNUM3_REM_SHARDWARE);

   virtual TFIBWideStringField * get_ElementSERNUM4_REM_SHARDWARE(void);
   virtual void set_ElementSERNUM4_REM_SHARDWARE(TFIBWideStringField * ElementSERNUM4_REM_SHARDWARE);

   virtual TFIBWideStringField * get_ElementNUMBAT_REM_SHARDWARE(void);
   virtual void set_ElementNUMBAT_REM_SHARDWARE(TFIBWideStringField * ElementNUMBAT_REM_SHARDWARE);

   virtual TFIBWideStringField * get_ElementNUMGARTALON_REM_SHARDWARE(void);
   virtual void set_ElementNUMGARTALON_REM_SHARDWARE(TFIBWideStringField * ElementNUMGARTALON_REM_SHARDWARE);

   virtual TFIBWideStringField * get_ElementSWCODE_REM_SHARDWARE(void);
   virtual void set_ElementSWCODE_REM_SHARDWARE(TFIBWideStringField * ElementSWCODE_REM_SHARDWARE);

   virtual TFIBWideStringField * get_ElementHWCODE_REM_SHARDWARE(void);
   virtual void set_ElementHWCODE_REM_SHARDWARE(TFIBWideStringField * ElementHWCODE_REM_SHARDWARE);

   virtual TFIBWideStringField * get_ElementVERPO_REM_SHARDWARE(void);
   virtual void set_ElementVERPO_REM_SHARDWARE(TFIBWideStringField * ElementVERPO_REM_SHARDWARE);

   virtual TFIBWideStringField * get_ElementPARTNUM_REM_SHARDWARE(void);
   virtual void set_ElementPARTNUM_REM_SHARDWARE(TFIBWideStringField * ElementPARTNUM_REM_SHARDWARE);

   virtual TFIBWideStringField * get_ElementMTM_REM_SHARDWARE(void);
   virtual void set_ElementMTM_REM_SHARDWARE(TFIBWideStringField * ElementMTM_REM_SHARDWARE);

   virtual TFIBWideStringField * get_ElementFRU_REM_SHARDWARE(void);
   virtual void set_ElementFRU_REM_SHARDWARE(TFIBWideStringField * ElementFRU_REM_SHARDWARE);

   virtual TFIBWideStringField * get_ElementNAME_ENG_REM_SHARDWARE(void);
   virtual void set_ElementNAME_ENG_REM_SHARDWARE(TFIBWideStringField * ElementNAME_ENG_REM_SHARDWARE);

   virtual TFIBWideStringField * get_ElementCRU_REM_SHARDWARE(void);
   virtual void set_ElementCRU_REM_SHARDWARE(TFIBWideStringField * ElementCRU_REM_SHARDWARE);

   virtual TFIBWideStringField * get_ElementARTIKUL_REM_SHARDWARE(void);
   virtual void set_ElementARTIKUL_REM_SHARDWARE(TFIBWideStringField * ElementARTIKUL_REM_SHARDWARE);

   virtual TFIBLargeIntField * get_TableOUT_IDFIRM(void);
   virtual void set_TableOUT_IDFIRM(TFIBLargeIntField * TableOUT_IDFIRM);

   virtual TFIBWideStringField * get_TableOUT_NAME_FIRM(void);
   virtual void set_TableOUT_NAME_FIRM(TFIBWideStringField * TableOUT_NAME_FIRM);

   virtual TFIBLargeIntField * get_TableOUT_IDSKLAD(void);
   virtual void set_TableOUT_IDSKLAD(TFIBLargeIntField * TableOUT_IDSKLAD);

   virtual TFIBWideStringField * get_TableOUT_NAME_SKLAD(void);
   virtual void set_TableOUT_NAME_SKLAD(TFIBWideStringField * TableOUT_NAME_SKLAD);

   virtual TFIBLargeIntField * get_TableOUT_IDTNOM(void);
   virtual void set_TableOUT_IDTNOM(TFIBLargeIntField * TableOUT_IDTNOM);

   virtual TFIBWideStringField * get_TableOUT_NAME_TYPE_NOM(void);
   virtual void set_TableOUT_NAME_TYPE_NOM(TFIBWideStringField * TableOUT_NAME_TYPE_NOM);

   virtual TFIBBCDField * get_TableOUT_OST(void);
   virtual void set_TableOUT_OST(TFIBBCDField * TableOUT_OST);

   virtual TFIBLargeIntField * get_TableIDGRP_REM_SHARDWARE(void);
   virtual void set_TableIDGRP_REM_SHARDWARE(TFIBLargeIntField * TableIDGRP_REM_SHARDWARE);

   virtual TFIBLargeIntField * get_TableOUT_IDMHRAN(void);
   virtual void set_TableOUT_IDMHRAN(TFIBLargeIntField * TableOUT_IDMHRAN);

   virtual TFIBWideStringField * get_TableOUT_NAME_MHRAN(void);
   virtual void set_TableOUT_NAME_MHRAN(TFIBWideStringField * TableOUT_NAME_MHRAN);

   virtual TFIBSmallIntField * get_TableOUT_FL_OTCH_PROIZV(void);
   virtual void set_TableOUT_FL_OTCH_PROIZV(TFIBSmallIntField * TableOUT_FL_OTCH_PROIZV);

   virtual TFIBSmallIntField * get_TableOUT_FL_NO_RAZBOR(void);
   virtual void set_TableOUT_FL_NO_RAZBOR(TFIBSmallIntField * TableOUT_FL_NO_RAZBOR);

   virtual TFIBSmallIntField * get_ElementFL_OTCH_PROIZV_REM_SHARDWARE(void);
   virtual void set_ElementFL_OTCH_PROIZV_REM_SHARDWARE(TFIBSmallIntField * ElementFL_OTCH_PROIZV_REM_SHARDWARE);

   virtual TFIBSmallIntField * get_ElementFL_NO_RAZBOR_REM_SHARDWARE(void);
   virtual void set_ElementFL_NO_RAZBOR_REM_SHARDWARE(TFIBSmallIntField * ElementFL_NO_RAZBOR_REM_SHARDWARE);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual void OpenTable(__int64 id_grp, bool all);
   virtual UnicodeString GetTextQuery(__int64 id_grp, bool all);
   virtual int OpenElement(__int64 id);
   virtual bool NewElement(__int64 id_grp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual void ChancheGrp(__int64 new_id_grp, __int64 id_el);
   virtual __int64 FindPoName(UnicodeString name);
   virtual __int64 GetIdGrpElementa(__int64 id_element);
   virtual __int64 GetIdPoCodu(int code);
   virtual bool Table_FindPoSerNum1Like(__int64 id_grp, bool all, UnicodeString ser_num);
   virtual bool Table_FindPoSerNum2Like(__int64 id_grp, bool all, UnicodeString ser_num);
   virtual bool Table_FindPoSerNumStrLike(__int64 id_grp, bool all, UnicodeString ser_num);
};
#define CLSID_TREM_DMSprHardwareImpl __uuidof(TREM_DMSprHardwareImpl)
#endif
