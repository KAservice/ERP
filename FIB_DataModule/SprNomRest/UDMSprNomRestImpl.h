#ifndef UDMSprNomRestImplH
#define UDMSprNomRestImplH
#include "IDMSprNomRest.h"
#include "UDMSprNomRest.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprNomRestImpl)) TDMSprNomRestImpl : public IDMSprNomRest
{
public:
   TDMSprNomRestImpl();
   ~TDMSprNomRestImpl();
   TDMSprNomRest * Object;
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

//IDMSprNomRest
   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TFIBDateTimeField * get_TablePOS_NOMREST(void);
   virtual void set_TablePOS_NOMREST(TFIBDateTimeField * TablePOS_NOMREST);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TpFIBDataSet * get_IBQ(void);
   virtual void set_IBQ(TpFIBDataSet * IBQ);

   virtual TFIBBCDField * get_IBQNKOL_SPROD(void);
   virtual void set_IBQNKOL_SPROD(TFIBBCDField * IBQNKOL_SPROD);

   virtual TFIBBCDField * get_IBQBKOL_SPROD(void);
   virtual void set_IBQBKOL_SPROD(TFIBBCDField * IBQBKOL_SPROD);

   virtual TFIBBCDField * get_IBQKFPRICE_SPROD(void);
   virtual void set_IBQKFPRICE_SPROD(TFIBBCDField * IBQKFPRICE_SPROD);

   virtual TFIBSmallIntField * get_IBQSPIS_SPROD(void);
   virtual void set_IBQSPIS_SPROD(TFIBSmallIntField * IBQSPIS_SPROD);

   virtual TFIBBCDField * get_IBQVALUE_SSEZKF(void);
   virtual void set_IBQVALUE_SSEZKF(TFIBBCDField * IBQVALUE_SSEZKF);

   virtual TFIBBCDField * get_IBQVALUE_SSEZKF_SPROD(void);
   virtual void set_IBQVALUE_SSEZKF_SPROD(TFIBBCDField * IBQVALUE_SSEZKF_SPROD);

   virtual TFloatField * get_IBQSEZKF_SPROD(void);
   virtual void set_IBQSEZKF_SPROD(TFloatField * IBQSEZKF_SPROD);

   virtual TFloatField * get_IBQSEZKF(void);
   virtual void set_IBQSEZKF(TFloatField * IBQSEZKF);

   virtual TFIBBCDField * get_TableID_NOMREST(void);
   virtual void set_TableID_NOMREST(TFIBBCDField * TableID_NOMREST);

   virtual TFIBBCDField * get_TableIDNOM_NOMREST(void);
   virtual void set_TableIDNOM_NOMREST(TFIBBCDField * TableIDNOM_NOMREST);

   virtual TFIBBCDField * get_IBQID_SPROD(void);
   virtual void set_IBQID_SPROD(TFIBBCDField * IBQID_SPROD);

   virtual TFIBBCDField * get_IBQIDKOMPL_SPROD(void);
   virtual void set_IBQIDKOMPL_SPROD(TFIBBCDField * IBQIDKOMPL_SPROD);

   virtual TFIBWideStringField * get_TableNAME_NOMREST(void);
   virtual void set_TableNAME_NOMREST(TFIBWideStringField * TableNAME_NOMREST);

   virtual TFIBWideStringField * get_IBQNAMENOM(void);
   virtual void set_IBQNAMENOM(TFIBWideStringField * IBQNAMENOM);

   virtual TFIBBCDField * get_ElementID_NOMREST(void);
   virtual void set_ElementID_NOMREST(TFIBBCDField * ElementID_NOMREST);

   virtual TFIBBCDField * get_ElementIDNOM_NOMREST(void);
   virtual void set_ElementIDNOM_NOMREST(TFIBBCDField * ElementIDNOM_NOMREST);

   virtual TFIBBCDField * get_ElementIDMPRIG_NOMREST(void);
   virtual void set_ElementIDMPRIG_NOMREST(TFIBBCDField * ElementIDMPRIG_NOMREST);

   virtual TFIBWideStringField * get_ElementSOST_NOMREST(void);
   virtual void set_ElementSOST_NOMREST(TFIBWideStringField * ElementSOST_NOMREST);

   virtual TFIBWideStringField * get_ElementTEHN_NOMREST(void);
   virtual void set_ElementTEHN_NOMREST(TFIBWideStringField * ElementTEHN_NOMREST);

   virtual TFIBWideStringField * get_ElementVIH_NOMREST(void);
   virtual void set_ElementVIH_NOMREST(TFIBWideStringField * ElementVIH_NOMREST);

   virtual TFIBWideStringField * get_ElementSROK_NOMREST(void);
   virtual void set_ElementSROK_NOMREST(TFIBWideStringField * ElementSROK_NOMREST);

   virtual TFIBWideStringField * get_ElementNOMER_NOMREST(void);
   virtual void set_ElementNOMER_NOMREST(TFIBWideStringField * ElementNOMER_NOMREST);

   virtual TFIBWideStringField * get_ElementNAME_NOMREST(void);
   virtual void set_ElementNAME_NOMREST(TFIBWideStringField * ElementNAME_NOMREST);

   virtual TFIBDateTimeField * get_ElementPOS_NOMREST(void);
   virtual void set_ElementPOS_NOMREST(TFIBDateTimeField * ElementPOS_NOMREST);

   virtual TFIBBCDField * get_ElementIDEDPROD_NOMREST(void);
   virtual void set_ElementIDEDPROD_NOMREST(TFIBBCDField * ElementIDEDPROD_NOMREST);

   virtual TFIBBCDField * get_ElementKOLEDPROD_NOMREST(void);
   virtual void set_ElementKOLEDPROD_NOMREST(TFIBBCDField * ElementKOLEDPROD_NOMREST);

   virtual TFIBWideStringField * get_ElementGID_SNOMREST(void);
   virtual void set_ElementGID_SNOMREST(TFIBWideStringField * ElementGID_SNOMREST);

   virtual TFIBBCDField * get_ElementIDBASE_SNOMREST(void);
   virtual void set_ElementIDBASE_SNOMREST(TFIBBCDField * ElementIDBASE_SNOMREST);

   virtual TFIBBCDField * get_ElementIDEDFACTOR_SNOMREST(void);
   virtual void set_ElementIDEDFACTOR_SNOMREST(TFIBBCDField * ElementIDEDFACTOR_SNOMREST);

   virtual TFIBBCDField * get_ElementENCEN_SNOMREST(void);
   virtual void set_ElementENCEN_SNOMREST(TFIBBCDField * ElementENCEN_SNOMREST);

   virtual TFIBBCDField * get_ElementIDPRODUCE_SNOMREST(void);
   virtual void set_ElementIDPRODUCE_SNOMREST(TFIBBCDField * ElementIDPRODUCE_SNOMREST);

   virtual TFIBBCDField * get_ElementIDLOSSFACTOR_SNOMREST(void);
   virtual void set_ElementIDLOSSFACTOR_SNOMREST(TFIBBCDField * ElementIDLOSSFACTOR_SNOMREST);

   virtual TFIBWideStringField * get_ElementVID_SNOMREST(void);
   virtual void set_ElementVID_SNOMREST(TFIBWideStringField * ElementVID_SNOMREST);

   virtual TFIBWideStringField * get_ElementTEMP_SNOMREST(void);
   virtual void set_ElementTEMP_SNOMREST(TFIBWideStringField * ElementTEMP_SNOMREST);

   virtual TFIBWideStringField * get_ElementAPPERANCE_SNOMREST(void);
   virtual void set_ElementAPPERANCE_SNOMREST(TFIBWideStringField * ElementAPPERANCE_SNOMREST);

   virtual TFIBWideStringField * get_ElementCOLOUR_SNOMREST(void);
   virtual void set_ElementCOLOUR_SNOMREST(TFIBWideStringField * ElementCOLOUR_SNOMREST);

   virtual TFIBWideStringField * get_ElementTASTE_SNOMREST(void);
   virtual void set_ElementTASTE_SNOMREST(TFIBWideStringField * ElementTASTE_SNOMREST);

   virtual TFIBWideStringField * get_ElementSMELL_SNOMREST(void);
   virtual void set_ElementSMELL_SNOMREST(TFIBWideStringField * ElementSMELL_SNOMREST);

   virtual TFIBWideStringField * get_ElementCONSISTENCE_SNOMREST(void);
   virtual void set_ElementCONSISTENCE_SNOMREST(TFIBWideStringField * ElementCONSISTENCE_SNOMREST);

   virtual TFIBWideStringField * get_ElementMDSV_SNOMREST(void);
   virtual void set_ElementMDSV_SNOMREST(TFIBWideStringField * ElementMDSV_SNOMREST);

   virtual TFIBWideStringField * get_ElementMDG_SNOMREST(void);
   virtual void set_ElementMDG_SNOMREST(TFIBWideStringField * ElementMDG_SNOMREST);

   virtual TFIBWideStringField * get_ElementMDS_SNOMREST(void);
   virtual void set_ElementMDS_SNOMREST(TFIBWideStringField * ElementMDS_SNOMREST);

   virtual TFIBWideStringField * get_ElementKMAM_SNOMREST(void);
   virtual void set_ElementKMAM_SNOMREST(TFIBWideStringField * ElementKMAM_SNOMREST);

   virtual TFIBWideStringField * get_ElementBGKR_SNOMREST(void);
   virtual void set_ElementBGKR_SNOMREST(TFIBWideStringField * ElementBGKR_SNOMREST);

   virtual TFIBWideStringField * get_ElementECOLI_SNOMREST(void);
   virtual void set_ElementECOLI_SNOMREST(TFIBWideStringField * ElementECOLI_SNOMREST);

   virtual TFIBWideStringField * get_ElementKPS_SNOMREST(void);
   virtual void set_ElementKPS_SNOMREST(TFIBWideStringField * ElementKPS_SNOMREST);

   virtual TFIBWideStringField * get_ElementPROTEUS_SNOMREST(void);
   virtual void set_ElementPROTEUS_SNOMREST(TFIBWideStringField * ElementPROTEUS_SNOMREST);

   virtual TFIBWideStringField * get_ElementPMS_SNOMREST(void);
   virtual void set_ElementPMS_SNOMREST(TFIBWideStringField * ElementPMS_SNOMREST);

   virtual TFIBWideStringField * get_ElementNAME_MPRIG(void);
   virtual void set_ElementNAME_MPRIG(TFIBWideStringField * ElementNAME_MPRIG);

   virtual TFIBWideStringField * get_ElementNAMENOM(void);
   virtual void set_ElementNAMENOM(TFIBWideStringField * ElementNAMENOM);

   virtual TFIBBCDField * get_ElementIDSKLAD_MPRIG(void);
   virtual void set_ElementIDSKLAD_MPRIG(TFIBBCDField * ElementIDSKLAD_MPRIG);

   virtual TFIBWideStringField * get_ElementNAMEED(void);
   virtual void set_ElementNAMEED(TFIBWideStringField * ElementNAMEED);

   virtual TFIBBCDField * get_ElementKFED(void);
   virtual void set_ElementKFED(TFIBBCDField * ElementKFED);

   virtual TFIBWideStringField * get_ElementNAME_ED_FACTOR(void);
   virtual void set_ElementNAME_ED_FACTOR(TFIBWideStringField * ElementNAME_ED_FACTOR);

   virtual TFIBBCDField * get_ElementKF_ED_FACTOR(void);
   virtual void set_ElementKF_ED_FACTOR(TFIBBCDField * ElementKF_ED_FACTOR);

   virtual TFIBWideStringField * get_ElementNAME_SPRODUCE(void);
   virtual void set_ElementNAME_SPRODUCE(TFIBWideStringField * ElementNAME_SPRODUCE);

   virtual TFIBWideStringField * get_ElementNAME_SLOSS_FACTOR(void);
   virtual void set_ElementNAME_SLOSS_FACTOR(TFIBWideStringField * ElementNAME_SLOSS_FACTOR);

   virtual __int64 get_Id(void);
   virtual void set_Id(__int64 Id);

   virtual __int64 get_IdNom(void);
   virtual void set_IdNom(__int64 IdNom);

   virtual bool get_flSaveElement(void);
   virtual void set_flSaveElement(bool flSaveElement);

   virtual void OpenTable(void);
   virtual int OpenElement(void);
   virtual void NewElement(void);
   virtual bool SaveElement(void);
   virtual void DeleteElement(void);
   virtual __int64 GetTekSostav(__int64 idNom, TDateTime pos);
};
#define CLSID_TDMSprNomRestImpl __uuidof(TDMSprNomRestImpl)
#endif
