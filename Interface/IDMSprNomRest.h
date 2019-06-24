#ifndef UIDMSprNomRestH
#define UIDMSprNomRestH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprNomRest)) IDMSprNomRest : public IMainInterface
{
public:
   __property TDataSource * DataSourceElement = {read = get_DataSourceElement , write = set_DataSourceElement};
   virtual TDataSource * get_DataSourceElement(void)=0;
   virtual void set_DataSourceElement(TDataSource * DataSourceElement)=0;

   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TFIBDateTimeField * TablePOS_NOMREST = {read = get_TablePOS_NOMREST , write = set_TablePOS_NOMREST};
   virtual TFIBDateTimeField * get_TablePOS_NOMREST(void)=0;
   virtual void set_TablePOS_NOMREST(TFIBDateTimeField * TablePOS_NOMREST)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TpFIBDataSet * IBQ = {read = get_IBQ , write = set_IBQ};
   virtual TpFIBDataSet * get_IBQ(void)=0;
   virtual void set_IBQ(TpFIBDataSet * IBQ)=0;

   __property TFIBBCDField * IBQNKOL_SPROD = {read = get_IBQNKOL_SPROD , write = set_IBQNKOL_SPROD};
   virtual TFIBBCDField * get_IBQNKOL_SPROD(void)=0;
   virtual void set_IBQNKOL_SPROD(TFIBBCDField * IBQNKOL_SPROD)=0;

   __property TFIBBCDField * IBQBKOL_SPROD = {read = get_IBQBKOL_SPROD , write = set_IBQBKOL_SPROD};
   virtual TFIBBCDField * get_IBQBKOL_SPROD(void)=0;
   virtual void set_IBQBKOL_SPROD(TFIBBCDField * IBQBKOL_SPROD)=0;

   __property TFIBBCDField * IBQKFPRICE_SPROD = {read = get_IBQKFPRICE_SPROD , write = set_IBQKFPRICE_SPROD};
   virtual TFIBBCDField * get_IBQKFPRICE_SPROD(void)=0;
   virtual void set_IBQKFPRICE_SPROD(TFIBBCDField * IBQKFPRICE_SPROD)=0;

   __property TFIBSmallIntField * IBQSPIS_SPROD = {read = get_IBQSPIS_SPROD , write = set_IBQSPIS_SPROD};
   virtual TFIBSmallIntField * get_IBQSPIS_SPROD(void)=0;
   virtual void set_IBQSPIS_SPROD(TFIBSmallIntField * IBQSPIS_SPROD)=0;

   __property TFIBBCDField * IBQVALUE_SSEZKF = {read = get_IBQVALUE_SSEZKF , write = set_IBQVALUE_SSEZKF};
   virtual TFIBBCDField * get_IBQVALUE_SSEZKF(void)=0;
   virtual void set_IBQVALUE_SSEZKF(TFIBBCDField * IBQVALUE_SSEZKF)=0;

   __property TFIBBCDField * IBQVALUE_SSEZKF_SPROD = {read = get_IBQVALUE_SSEZKF_SPROD , write = set_IBQVALUE_SSEZKF_SPROD};
   virtual TFIBBCDField * get_IBQVALUE_SSEZKF_SPROD(void)=0;
   virtual void set_IBQVALUE_SSEZKF_SPROD(TFIBBCDField * IBQVALUE_SSEZKF_SPROD)=0;

   __property TFloatField * IBQSEZKF_SPROD = {read = get_IBQSEZKF_SPROD , write = set_IBQSEZKF_SPROD};
   virtual TFloatField * get_IBQSEZKF_SPROD(void)=0;
   virtual void set_IBQSEZKF_SPROD(TFloatField * IBQSEZKF_SPROD)=0;

   __property TFloatField * IBQSEZKF = {read = get_IBQSEZKF , write = set_IBQSEZKF};
   virtual TFloatField * get_IBQSEZKF(void)=0;
   virtual void set_IBQSEZKF(TFloatField * IBQSEZKF)=0;

   __property TFIBBCDField * TableID_NOMREST = {read = get_TableID_NOMREST , write = set_TableID_NOMREST};
   virtual TFIBBCDField * get_TableID_NOMREST(void)=0;
   virtual void set_TableID_NOMREST(TFIBBCDField * TableID_NOMREST)=0;

   __property TFIBBCDField * TableIDNOM_NOMREST = {read = get_TableIDNOM_NOMREST , write = set_TableIDNOM_NOMREST};
   virtual TFIBBCDField * get_TableIDNOM_NOMREST(void)=0;
   virtual void set_TableIDNOM_NOMREST(TFIBBCDField * TableIDNOM_NOMREST)=0;

   __property TFIBBCDField * IBQID_SPROD = {read = get_IBQID_SPROD , write = set_IBQID_SPROD};
   virtual TFIBBCDField * get_IBQID_SPROD(void)=0;
   virtual void set_IBQID_SPROD(TFIBBCDField * IBQID_SPROD)=0;

   __property TFIBBCDField * IBQIDKOMPL_SPROD = {read = get_IBQIDKOMPL_SPROD , write = set_IBQIDKOMPL_SPROD};
   virtual TFIBBCDField * get_IBQIDKOMPL_SPROD(void)=0;
   virtual void set_IBQIDKOMPL_SPROD(TFIBBCDField * IBQIDKOMPL_SPROD)=0;

   __property TFIBWideStringField * TableNAME_NOMREST = {read = get_TableNAME_NOMREST , write = set_TableNAME_NOMREST};
   virtual TFIBWideStringField * get_TableNAME_NOMREST(void)=0;
   virtual void set_TableNAME_NOMREST(TFIBWideStringField * TableNAME_NOMREST)=0;

   __property TFIBWideStringField * IBQNAMENOM = {read = get_IBQNAMENOM , write = set_IBQNAMENOM};
   virtual TFIBWideStringField * get_IBQNAMENOM(void)=0;
   virtual void set_IBQNAMENOM(TFIBWideStringField * IBQNAMENOM)=0;

   __property TFIBBCDField * ElementID_NOMREST = {read = get_ElementID_NOMREST , write = set_ElementID_NOMREST};
   virtual TFIBBCDField * get_ElementID_NOMREST(void)=0;
   virtual void set_ElementID_NOMREST(TFIBBCDField * ElementID_NOMREST)=0;

   __property TFIBBCDField * ElementIDNOM_NOMREST = {read = get_ElementIDNOM_NOMREST , write = set_ElementIDNOM_NOMREST};
   virtual TFIBBCDField * get_ElementIDNOM_NOMREST(void)=0;
   virtual void set_ElementIDNOM_NOMREST(TFIBBCDField * ElementIDNOM_NOMREST)=0;

   __property TFIBBCDField * ElementIDMPRIG_NOMREST = {read = get_ElementIDMPRIG_NOMREST , write = set_ElementIDMPRIG_NOMREST};
   virtual TFIBBCDField * get_ElementIDMPRIG_NOMREST(void)=0;
   virtual void set_ElementIDMPRIG_NOMREST(TFIBBCDField * ElementIDMPRIG_NOMREST)=0;

   __property TFIBWideStringField * ElementSOST_NOMREST = {read = get_ElementSOST_NOMREST , write = set_ElementSOST_NOMREST};
   virtual TFIBWideStringField * get_ElementSOST_NOMREST(void)=0;
   virtual void set_ElementSOST_NOMREST(TFIBWideStringField * ElementSOST_NOMREST)=0;

   __property TFIBWideStringField * ElementTEHN_NOMREST = {read = get_ElementTEHN_NOMREST , write = set_ElementTEHN_NOMREST};
   virtual TFIBWideStringField * get_ElementTEHN_NOMREST(void)=0;
   virtual void set_ElementTEHN_NOMREST(TFIBWideStringField * ElementTEHN_NOMREST)=0;

   __property TFIBWideStringField * ElementVIH_NOMREST = {read = get_ElementVIH_NOMREST , write = set_ElementVIH_NOMREST};
   virtual TFIBWideStringField * get_ElementVIH_NOMREST(void)=0;
   virtual void set_ElementVIH_NOMREST(TFIBWideStringField * ElementVIH_NOMREST)=0;

   __property TFIBWideStringField * ElementSROK_NOMREST = {read = get_ElementSROK_NOMREST , write = set_ElementSROK_NOMREST};
   virtual TFIBWideStringField * get_ElementSROK_NOMREST(void)=0;
   virtual void set_ElementSROK_NOMREST(TFIBWideStringField * ElementSROK_NOMREST)=0;

   __property TFIBWideStringField * ElementNOMER_NOMREST = {read = get_ElementNOMER_NOMREST , write = set_ElementNOMER_NOMREST};
   virtual TFIBWideStringField * get_ElementNOMER_NOMREST(void)=0;
   virtual void set_ElementNOMER_NOMREST(TFIBWideStringField * ElementNOMER_NOMREST)=0;

   __property TFIBWideStringField * ElementNAME_NOMREST = {read = get_ElementNAME_NOMREST , write = set_ElementNAME_NOMREST};
   virtual TFIBWideStringField * get_ElementNAME_NOMREST(void)=0;
   virtual void set_ElementNAME_NOMREST(TFIBWideStringField * ElementNAME_NOMREST)=0;

   __property TFIBDateTimeField * ElementPOS_NOMREST = {read = get_ElementPOS_NOMREST , write = set_ElementPOS_NOMREST};
   virtual TFIBDateTimeField * get_ElementPOS_NOMREST(void)=0;
   virtual void set_ElementPOS_NOMREST(TFIBDateTimeField * ElementPOS_NOMREST)=0;

   __property TFIBBCDField * ElementIDEDPROD_NOMREST = {read = get_ElementIDEDPROD_NOMREST , write = set_ElementIDEDPROD_NOMREST};
   virtual TFIBBCDField * get_ElementIDEDPROD_NOMREST(void)=0;
   virtual void set_ElementIDEDPROD_NOMREST(TFIBBCDField * ElementIDEDPROD_NOMREST)=0;

   __property TFIBBCDField * ElementKOLEDPROD_NOMREST = {read = get_ElementKOLEDPROD_NOMREST , write = set_ElementKOLEDPROD_NOMREST};
   virtual TFIBBCDField * get_ElementKOLEDPROD_NOMREST(void)=0;
   virtual void set_ElementKOLEDPROD_NOMREST(TFIBBCDField * ElementKOLEDPROD_NOMREST)=0;

   __property TFIBWideStringField * ElementGID_SNOMREST = {read = get_ElementGID_SNOMREST , write = set_ElementGID_SNOMREST};
   virtual TFIBWideStringField * get_ElementGID_SNOMREST(void)=0;
   virtual void set_ElementGID_SNOMREST(TFIBWideStringField * ElementGID_SNOMREST)=0;

   __property TFIBBCDField * ElementIDBASE_SNOMREST = {read = get_ElementIDBASE_SNOMREST , write = set_ElementIDBASE_SNOMREST};
   virtual TFIBBCDField * get_ElementIDBASE_SNOMREST(void)=0;
   virtual void set_ElementIDBASE_SNOMREST(TFIBBCDField * ElementIDBASE_SNOMREST)=0;

   __property TFIBBCDField * ElementIDEDFACTOR_SNOMREST = {read = get_ElementIDEDFACTOR_SNOMREST , write = set_ElementIDEDFACTOR_SNOMREST};
   virtual TFIBBCDField * get_ElementIDEDFACTOR_SNOMREST(void)=0;
   virtual void set_ElementIDEDFACTOR_SNOMREST(TFIBBCDField * ElementIDEDFACTOR_SNOMREST)=0;

   __property TFIBBCDField * ElementENCEN_SNOMREST = {read = get_ElementENCEN_SNOMREST , write = set_ElementENCEN_SNOMREST};
   virtual TFIBBCDField * get_ElementENCEN_SNOMREST(void)=0;
   virtual void set_ElementENCEN_SNOMREST(TFIBBCDField * ElementENCEN_SNOMREST)=0;

   __property TFIBBCDField * ElementIDPRODUCE_SNOMREST = {read = get_ElementIDPRODUCE_SNOMREST , write = set_ElementIDPRODUCE_SNOMREST};
   virtual TFIBBCDField * get_ElementIDPRODUCE_SNOMREST(void)=0;
   virtual void set_ElementIDPRODUCE_SNOMREST(TFIBBCDField * ElementIDPRODUCE_SNOMREST)=0;

   __property TFIBBCDField * ElementIDLOSSFACTOR_SNOMREST = {read = get_ElementIDLOSSFACTOR_SNOMREST , write = set_ElementIDLOSSFACTOR_SNOMREST};
   virtual TFIBBCDField * get_ElementIDLOSSFACTOR_SNOMREST(void)=0;
   virtual void set_ElementIDLOSSFACTOR_SNOMREST(TFIBBCDField * ElementIDLOSSFACTOR_SNOMREST)=0;

   __property TFIBWideStringField * ElementVID_SNOMREST = {read = get_ElementVID_SNOMREST , write = set_ElementVID_SNOMREST};
   virtual TFIBWideStringField * get_ElementVID_SNOMREST(void)=0;
   virtual void set_ElementVID_SNOMREST(TFIBWideStringField * ElementVID_SNOMREST)=0;

   __property TFIBWideStringField * ElementTEMP_SNOMREST = {read = get_ElementTEMP_SNOMREST , write = set_ElementTEMP_SNOMREST};
   virtual TFIBWideStringField * get_ElementTEMP_SNOMREST(void)=0;
   virtual void set_ElementTEMP_SNOMREST(TFIBWideStringField * ElementTEMP_SNOMREST)=0;

   __property TFIBWideStringField * ElementAPPERANCE_SNOMREST = {read = get_ElementAPPERANCE_SNOMREST , write = set_ElementAPPERANCE_SNOMREST};
   virtual TFIBWideStringField * get_ElementAPPERANCE_SNOMREST(void)=0;
   virtual void set_ElementAPPERANCE_SNOMREST(TFIBWideStringField * ElementAPPERANCE_SNOMREST)=0;

   __property TFIBWideStringField * ElementCOLOUR_SNOMREST = {read = get_ElementCOLOUR_SNOMREST , write = set_ElementCOLOUR_SNOMREST};
   virtual TFIBWideStringField * get_ElementCOLOUR_SNOMREST(void)=0;
   virtual void set_ElementCOLOUR_SNOMREST(TFIBWideStringField * ElementCOLOUR_SNOMREST)=0;

   __property TFIBWideStringField * ElementTASTE_SNOMREST = {read = get_ElementTASTE_SNOMREST , write = set_ElementTASTE_SNOMREST};
   virtual TFIBWideStringField * get_ElementTASTE_SNOMREST(void)=0;
   virtual void set_ElementTASTE_SNOMREST(TFIBWideStringField * ElementTASTE_SNOMREST)=0;

   __property TFIBWideStringField * ElementSMELL_SNOMREST = {read = get_ElementSMELL_SNOMREST , write = set_ElementSMELL_SNOMREST};
   virtual TFIBWideStringField * get_ElementSMELL_SNOMREST(void)=0;
   virtual void set_ElementSMELL_SNOMREST(TFIBWideStringField * ElementSMELL_SNOMREST)=0;

   __property TFIBWideStringField * ElementCONSISTENCE_SNOMREST = {read = get_ElementCONSISTENCE_SNOMREST , write = set_ElementCONSISTENCE_SNOMREST};
   virtual TFIBWideStringField * get_ElementCONSISTENCE_SNOMREST(void)=0;
   virtual void set_ElementCONSISTENCE_SNOMREST(TFIBWideStringField * ElementCONSISTENCE_SNOMREST)=0;

   __property TFIBWideStringField * ElementMDSV_SNOMREST = {read = get_ElementMDSV_SNOMREST , write = set_ElementMDSV_SNOMREST};
   virtual TFIBWideStringField * get_ElementMDSV_SNOMREST(void)=0;
   virtual void set_ElementMDSV_SNOMREST(TFIBWideStringField * ElementMDSV_SNOMREST)=0;

   __property TFIBWideStringField * ElementMDG_SNOMREST = {read = get_ElementMDG_SNOMREST , write = set_ElementMDG_SNOMREST};
   virtual TFIBWideStringField * get_ElementMDG_SNOMREST(void)=0;
   virtual void set_ElementMDG_SNOMREST(TFIBWideStringField * ElementMDG_SNOMREST)=0;

   __property TFIBWideStringField * ElementMDS_SNOMREST = {read = get_ElementMDS_SNOMREST , write = set_ElementMDS_SNOMREST};
   virtual TFIBWideStringField * get_ElementMDS_SNOMREST(void)=0;
   virtual void set_ElementMDS_SNOMREST(TFIBWideStringField * ElementMDS_SNOMREST)=0;

   __property TFIBWideStringField * ElementKMAM_SNOMREST = {read = get_ElementKMAM_SNOMREST , write = set_ElementKMAM_SNOMREST};
   virtual TFIBWideStringField * get_ElementKMAM_SNOMREST(void)=0;
   virtual void set_ElementKMAM_SNOMREST(TFIBWideStringField * ElementKMAM_SNOMREST)=0;

   __property TFIBWideStringField * ElementBGKR_SNOMREST = {read = get_ElementBGKR_SNOMREST , write = set_ElementBGKR_SNOMREST};
   virtual TFIBWideStringField * get_ElementBGKR_SNOMREST(void)=0;
   virtual void set_ElementBGKR_SNOMREST(TFIBWideStringField * ElementBGKR_SNOMREST)=0;

   __property TFIBWideStringField * ElementECOLI_SNOMREST = {read = get_ElementECOLI_SNOMREST , write = set_ElementECOLI_SNOMREST};
   virtual TFIBWideStringField * get_ElementECOLI_SNOMREST(void)=0;
   virtual void set_ElementECOLI_SNOMREST(TFIBWideStringField * ElementECOLI_SNOMREST)=0;

   __property TFIBWideStringField * ElementKPS_SNOMREST = {read = get_ElementKPS_SNOMREST , write = set_ElementKPS_SNOMREST};
   virtual TFIBWideStringField * get_ElementKPS_SNOMREST(void)=0;
   virtual void set_ElementKPS_SNOMREST(TFIBWideStringField * ElementKPS_SNOMREST)=0;

   __property TFIBWideStringField * ElementPROTEUS_SNOMREST = {read = get_ElementPROTEUS_SNOMREST , write = set_ElementPROTEUS_SNOMREST};
   virtual TFIBWideStringField * get_ElementPROTEUS_SNOMREST(void)=0;
   virtual void set_ElementPROTEUS_SNOMREST(TFIBWideStringField * ElementPROTEUS_SNOMREST)=0;

   __property TFIBWideStringField * ElementPMS_SNOMREST = {read = get_ElementPMS_SNOMREST , write = set_ElementPMS_SNOMREST};
   virtual TFIBWideStringField * get_ElementPMS_SNOMREST(void)=0;
   virtual void set_ElementPMS_SNOMREST(TFIBWideStringField * ElementPMS_SNOMREST)=0;

   __property TFIBWideStringField * ElementNAME_MPRIG = {read = get_ElementNAME_MPRIG , write = set_ElementNAME_MPRIG};
   virtual TFIBWideStringField * get_ElementNAME_MPRIG(void)=0;
   virtual void set_ElementNAME_MPRIG(TFIBWideStringField * ElementNAME_MPRIG)=0;

   __property TFIBWideStringField * ElementNAMENOM = {read = get_ElementNAMENOM , write = set_ElementNAMENOM};
   virtual TFIBWideStringField * get_ElementNAMENOM(void)=0;
   virtual void set_ElementNAMENOM(TFIBWideStringField * ElementNAMENOM)=0;

   __property TFIBBCDField * ElementIDSKLAD_MPRIG = {read = get_ElementIDSKLAD_MPRIG , write = set_ElementIDSKLAD_MPRIG};
   virtual TFIBBCDField * get_ElementIDSKLAD_MPRIG(void)=0;
   virtual void set_ElementIDSKLAD_MPRIG(TFIBBCDField * ElementIDSKLAD_MPRIG)=0;

   __property TFIBWideStringField * ElementNAMEED = {read = get_ElementNAMEED , write = set_ElementNAMEED};
   virtual TFIBWideStringField * get_ElementNAMEED(void)=0;
   virtual void set_ElementNAMEED(TFIBWideStringField * ElementNAMEED)=0;

   __property TFIBBCDField * ElementKFED = {read = get_ElementKFED , write = set_ElementKFED};
   virtual TFIBBCDField * get_ElementKFED(void)=0;
   virtual void set_ElementKFED(TFIBBCDField * ElementKFED)=0;

   __property TFIBWideStringField * ElementNAME_ED_FACTOR = {read = get_ElementNAME_ED_FACTOR , write = set_ElementNAME_ED_FACTOR};
   virtual TFIBWideStringField * get_ElementNAME_ED_FACTOR(void)=0;
   virtual void set_ElementNAME_ED_FACTOR(TFIBWideStringField * ElementNAME_ED_FACTOR)=0;

   __property TFIBBCDField * ElementKF_ED_FACTOR = {read = get_ElementKF_ED_FACTOR , write = set_ElementKF_ED_FACTOR};
   virtual TFIBBCDField * get_ElementKF_ED_FACTOR(void)=0;
   virtual void set_ElementKF_ED_FACTOR(TFIBBCDField * ElementKF_ED_FACTOR)=0;

   __property TFIBWideStringField * ElementNAME_SPRODUCE = {read = get_ElementNAME_SPRODUCE , write = set_ElementNAME_SPRODUCE};
   virtual TFIBWideStringField * get_ElementNAME_SPRODUCE(void)=0;
   virtual void set_ElementNAME_SPRODUCE(TFIBWideStringField * ElementNAME_SPRODUCE)=0;

   __property TFIBWideStringField * ElementNAME_SLOSS_FACTOR = {read = get_ElementNAME_SLOSS_FACTOR , write = set_ElementNAME_SLOSS_FACTOR};
   virtual TFIBWideStringField * get_ElementNAME_SLOSS_FACTOR(void)=0;
   virtual void set_ElementNAME_SLOSS_FACTOR(TFIBWideStringField * ElementNAME_SLOSS_FACTOR)=0;

   __property __int64 Id = {read = get_Id , write = set_Id};
   virtual __int64 get_Id(void)=0;
   virtual void set_Id(__int64 Id)=0;

   __property __int64 IdNom = {read = get_IdNom , write = set_IdNom};
   virtual __int64 get_IdNom(void)=0;
   virtual void set_IdNom(__int64 IdNom)=0;

   __property bool flSaveElement = {read = get_flSaveElement , write = set_flSaveElement};
   virtual bool get_flSaveElement(void)=0;
   virtual void set_flSaveElement(bool flSaveElement)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(void)=0;
   virtual void NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void DeleteElement(void)=0;
   virtual __int64 GetTekSostav(__int64 idNom, TDateTime pos)=0;
};
#define IID_IDMSprNomRest __uuidof(IDMSprNomRest)
#endif
