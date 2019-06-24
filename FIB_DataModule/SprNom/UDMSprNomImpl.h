#ifndef UDMSprNomImplH
#define UDMSprNomImplH
#include "IDMSprNom.h"
#include "UDMSprNom.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprNomImpl)) TDMSprNomImpl : public IDMSprNom
{
public:
   TDMSprNomImpl();
   ~TDMSprNomImpl();
   TDMSprNom * Object;
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

//IDMSprNom
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

   virtual TpFIBDataSet * get_BasEd(void);
   virtual void set_BasEd(TpFIBDataSet * BasEd);

   virtual TpFIBDataSet * get_OsnEd(void);
   virtual void set_OsnEd(TpFIBDataSet * OsnEd);

   virtual TFIBBCDField * get_BasEdKFED(void);
   virtual void set_BasEdKFED(TFIBBCDField * BasEdKFED);

   virtual TFIBIntegerField * get_BasEdTSHED(void);
   virtual void set_BasEdTSHED(TFIBIntegerField * BasEdTSHED);

   virtual TFIBSmallIntField * get_BasEdNEISPED(void);
   virtual void set_BasEdNEISPED(TFIBSmallIntField * BasEdNEISPED);

   virtual TFIBBCDField * get_OsnEdKFED(void);
   virtual void set_OsnEdKFED(TFIBBCDField * OsnEdKFED);

   virtual TFIBIntegerField * get_OsnEdTSHED(void);
   virtual void set_OsnEdTSHED(TFIBIntegerField * OsnEdTSHED);

   virtual TFIBSmallIntField * get_OsnEdNEISPED(void);
   virtual void set_OsnEdNEISPED(TFIBSmallIntField * OsnEdNEISPED);

   virtual TpFIBDataSet * get_IBQSprGrpBV(void);
   virtual void set_IBQSprGrpBV(TpFIBDataSet * IBQSprGrpBV);

   virtual TpFIBDataSet * get_SpTPrice(void);
   virtual void set_SpTPrice(TpFIBDataSet * SpTPrice);

   virtual TpFIBDataSet * get_Code(void);
   virtual void set_Code(TpFIBDataSet * Code);

   virtual TFIBIntegerField * get_CodeMAXCODE(void);
   virtual void set_CodeMAXCODE(TFIBIntegerField * CodeMAXCODE);

   virtual TFIBIntegerField * get_ElementTNOM(void);
   virtual void set_ElementTNOM(TFIBIntegerField * ElementTNOM);

   virtual TFIBIntegerField * get_ElementCODENOM(void);
   virtual void set_ElementCODENOM(TFIBIntegerField * ElementCODENOM);

   virtual TFIBIntegerField * get_ElementSTNDSNOM(void);
   virtual void set_ElementSTNDSNOM(TFIBIntegerField * ElementSTNDSNOM);

   virtual TFIBBCDField * get_ElementZNACH_PRICE(void);
   virtual void set_ElementZNACH_PRICE(TFIBBCDField * ElementZNACH_PRICE);

   virtual TpFIBQuery * get_pFIBQuery(void);
   virtual void set_pFIBQuery(TpFIBQuery * pFIBQuery);

   virtual TpFIBTransaction * get_pFIBTrUpdate(void);
   virtual void set_pFIBTrUpdate(TpFIBTransaction * pFIBTrUpdate);

   virtual TpFIBTransaction * get_pFIBTr(void);
   virtual void set_pFIBTr(TpFIBTransaction * pFIBTr);

   virtual TFIBSmallIntField * get_ElementFL_CHANGE_NOM(void);
   virtual void set_ElementFL_CHANGE_NOM(TFIBSmallIntField * ElementFL_CHANGE_NOM);

   virtual TFIBBCDField * get_ElementMINOSTNOM(void);
   virtual void set_ElementMINOSTNOM(TFIBBCDField * ElementMINOSTNOM);

   virtual TFIBBCDField * get_BasEdIDED(void);
   virtual void set_BasEdIDED(TFIBBCDField * BasEdIDED);

   virtual TFIBBCDField * get_BasEdIDNOMED(void);
   virtual void set_BasEdIDNOMED(TFIBBCDField * BasEdIDNOMED);

   virtual TFIBBCDField * get_BasEdIDOKEIED(void);
   virtual void set_BasEdIDOKEIED(TFIBBCDField * BasEdIDOKEIED);

   virtual TFIBBCDField * get_OsnEdIDED(void);
   virtual void set_OsnEdIDED(TFIBBCDField * OsnEdIDED);

   virtual TFIBBCDField * get_OsnEdIDNOMED(void);
   virtual void set_OsnEdIDNOMED(TFIBBCDField * OsnEdIDNOMED);

   virtual TFIBBCDField * get_OsnEdIDOKEIED(void);
   virtual void set_OsnEdIDOKEIED(TFIBBCDField * OsnEdIDOKEIED);

   virtual TFIBBCDField * get_SpTPriceID_TPRICE(void);
   virtual void set_SpTPriceID_TPRICE(TFIBBCDField * SpTPriceID_TPRICE);

   virtual TFIBBCDField * get_IBQSprGrpBVIDPOD_GBVNOM(void);
   virtual void set_IBQSprGrpBVIDPOD_GBVNOM(TFIBBCDField * IBQSprGrpBVIDPOD_GBVNOM);

   virtual TFIBBCDField * get_IBQSprGrpBVID_GBVNOM(void);
   virtual void set_IBQSprGrpBVID_GBVNOM(TFIBBCDField * IBQSprGrpBVID_GBVNOM);

   virtual TFIBBCDField * get_ElementSKIDKA1_SNOM(void);
   virtual void set_ElementSKIDKA1_SNOM(TFIBBCDField * ElementSKIDKA1_SNOM);

   virtual TFIBBCDField * get_ElementSKIDKA2_SNOM(void);
   virtual void set_ElementSKIDKA2_SNOM(TFIBBCDField * ElementSKIDKA2_SNOM);

   virtual TFIBBCDField * get_ElementSKIDKA3_SNOM(void);
   virtual void set_ElementSKIDKA3_SNOM(TFIBBCDField * ElementSKIDKA3_SNOM);

   virtual TFIBSmallIntField * get_ElementTYPESRGODN_SNOM(void);
   virtual void set_ElementTYPESRGODN_SNOM(TFIBSmallIntField * ElementTYPESRGODN_SNOM);

   virtual TFIBSmallIntField * get_ElementSRGODN_SNOM(void);
   virtual void set_ElementSRGODN_SNOM(TFIBSmallIntField * ElementSRGODN_SNOM);

   virtual TpFIBDataSet * get_SprScaleAndGrpVesNom(void);
   virtual void set_SprScaleAndGrpVesNom(TpFIBDataSet * SprScaleAndGrpVesNom);

   virtual TFIBBCDField * get_SprScaleAndGrpVesNomIDSCALE_SGRPVESNOM(void);
   virtual void set_SprScaleAndGrpVesNomIDSCALE_SGRPVESNOM(TFIBBCDField * SprScaleAndGrpVesNomIDSCALE_SGRPVESNOM);

   virtual TFIBBCDField * get_SprScaleAndGrpVesNomID_SGRPVESNOM(void);
   virtual void set_SprScaleAndGrpVesNomID_SGRPVESNOM(TFIBBCDField * SprScaleAndGrpVesNomID_SGRPVESNOM);

   virtual TpFIBDataSet * get_FisEd(void);
   virtual void set_FisEd(TpFIBDataSet * FisEd);

   virtual TFIBBCDField * get_FIBBCDField1(void);
   virtual void set_FIBBCDField1(TFIBBCDField * FIBBCDField1);

   virtual TFIBIntegerField * get_FIBIntegerField1(void);
   virtual void set_FIBIntegerField1(TFIBIntegerField * FIBIntegerField1);

   virtual TFIBSmallIntField * get_FIBSmallIntField1(void);
   virtual void set_FIBSmallIntField1(TFIBSmallIntField * FIBSmallIntField1);

   virtual TFIBBCDField * get_FIBBCDField2(void);
   virtual void set_FIBBCDField2(TFIBBCDField * FIBBCDField2);

   virtual TFIBBCDField * get_FIBBCDField3(void);
   virtual void set_FIBBCDField3(TFIBBCDField * FIBBCDField3);

   virtual TFIBBCDField * get_FIBBCDField4(void);
   virtual void set_FIBBCDField4(TFIBBCDField * FIBBCDField4);

   virtual TpFIBDataSet * get_SpisokEd(void);
   virtual void set_SpisokEd(TpFIBDataSet * SpisokEd);

   virtual TDataSource * get_DataSourceSpisokEd(void);
   virtual void set_DataSourceSpisokEd(TDataSource * DataSourceSpisokEd);

   virtual TFIBBCDField * get_SpisokEdKFED(void);
   virtual void set_SpisokEdKFED(TFIBBCDField * SpisokEdKFED);

   virtual TDataSource * get_DataSourceBasEd(void);
   virtual void set_DataSourceBasEd(TDataSource * DataSourceBasEd);

   virtual TDataSource * get_DataSourceOsnEd(void);
   virtual void set_DataSourceOsnEd(TDataSource * DataSourceOsnEd);

   virtual TDataSource * get_DataSourceFisEd(void);
   virtual void set_DataSourceFisEd(TDataSource * DataSourceFisEd);

   virtual TFIBIntegerField * get_BasEdCODE_SED(void);
   virtual void set_BasEdCODE_SED(TFIBIntegerField * BasEdCODE_SED);

   virtual TFIBBCDField * get_BasEdKF2_SED(void);
   virtual void set_BasEdKF2_SED(TFIBBCDField * BasEdKF2_SED);

   virtual TFIBBCDField * get_BasEdVES_SED(void);
   virtual void set_BasEdVES_SED(TFIBBCDField * BasEdVES_SED);

   virtual TFIBIntegerField * get_OsnEdCODE_SED(void);
   virtual void set_OsnEdCODE_SED(TFIBIntegerField * OsnEdCODE_SED);

   virtual TFIBBCDField * get_OsnEdKF2_SED(void);
   virtual void set_OsnEdKF2_SED(TFIBBCDField * OsnEdKF2_SED);

   virtual TFIBBCDField * get_OsnEdVES_SED(void);
   virtual void set_OsnEdVES_SED(TFIBBCDField * OsnEdVES_SED);

   virtual TFIBIntegerField * get_FisEdCODE_SED(void);
   virtual void set_FisEdCODE_SED(TFIBIntegerField * FisEdCODE_SED);

   virtual TFIBBCDField * get_FisEdKF2_SED(void);
   virtual void set_FisEdKF2_SED(TFIBBCDField * FisEdKF2_SED);

   virtual TFIBBCDField * get_FisEdVES_SED(void);
   virtual void set_FisEdVES_SED(TFIBBCDField * FisEdVES_SED);

   virtual TFIBDateTimeField * get_ElementGODEN_DO_SNOM(void);
   virtual void set_ElementGODEN_DO_SNOM(TFIBDateTimeField * ElementGODEN_DO_SNOM);

   virtual TFIBIntegerField * get_ElementWARRANTY_SNOM(void);
   virtual void set_ElementWARRANTY_SNOM(TFIBIntegerField * ElementWARRANTY_SNOM);

   virtual TFIBSmallIntField * get_ElementFL_CREDIT_SNOM(void);
   virtual void set_ElementFL_CREDIT_SNOM(TFIBSmallIntField * ElementFL_CREDIT_SNOM);

   virtual TFIBSmallIntField * get_ElementFL_TRANSPORT_SNOM(void);
   virtual void set_ElementFL_TRANSPORT_SNOM(TFIBSmallIntField * ElementFL_TRANSPORT_SNOM);

   virtual TFIBLargeIntField * get_SpisokEdIDED(void);
   virtual void set_SpisokEdIDED(TFIBLargeIntField * SpisokEdIDED);

   virtual TFIBBCDField * get_ElementPOGR_SNOM(void);
   virtual void set_ElementPOGR_SNOM(TFIBBCDField * ElementPOGR_SNOM);

   virtual TFIBLargeIntField * get_ElementIDNOM(void);
   virtual void set_ElementIDNOM(TFIBLargeIntField * ElementIDNOM);

   virtual TFIBLargeIntField * get_ElementIDBASEDNOM(void);
   virtual void set_ElementIDBASEDNOM(TFIBLargeIntField * ElementIDBASEDNOM);

   virtual TFIBLargeIntField * get_ElementIDOSNEDNOM(void);
   virtual void set_ElementIDOSNEDNOM(TFIBLargeIntField * ElementIDOSNEDNOM);

   virtual TFIBLargeIntField * get_ElementIDFISED_SNOM(void);
   virtual void set_ElementIDFISED_SNOM(TFIBLargeIntField * ElementIDFISED_SNOM);

   virtual TFIBLargeIntField * get_ElementIDGRPNOM(void);
   virtual void set_ElementIDGRPNOM(TFIBLargeIntField * ElementIDGRPNOM);

   virtual TFIBLargeIntField * get_ElementIDFIRMNOM(void);
   virtual void set_ElementIDFIRMNOM(TFIBLargeIntField * ElementIDFIRMNOM);

   virtual TFIBLargeIntField * get_ElementIDCOUNTRYNOM(void);
   virtual void set_ElementIDCOUNTRYNOM(TFIBLargeIntField * ElementIDCOUNTRYNOM);

   virtual TFIBLargeIntField * get_ElementIDVID_SNOM(void);
   virtual void set_ElementIDVID_SNOM(TFIBLargeIntField * ElementIDVID_SNOM);

   virtual TFIBLargeIntField * get_ElementIDSUPPLIER_SNOM(void);
   virtual void set_ElementIDSUPPLIER_SNOM(TFIBLargeIntField * ElementIDSUPPLIER_SNOM);

   virtual TFIBLargeIntField * get_ElementIDPRODUCER_SNOM(void);
   virtual void set_ElementIDPRODUCER_SNOM(TFIBLargeIntField * ElementIDPRODUCER_SNOM);

   virtual TFIBLargeIntField * get_ElementIDBRAND_SNOM(void);
   virtual void set_ElementIDBRAND_SNOM(TFIBLargeIntField * ElementIDBRAND_SNOM);

   virtual TFIBWideStringField * get_ElementNAMENOM(void);
   virtual void set_ElementNAMENOM(TFIBWideStringField * ElementNAMENOM);

   virtual TFIBWideStringField * get_ElementFNAMENOM(void);
   virtual void set_ElementFNAMENOM(TFIBWideStringField * ElementFNAMENOM);

   virtual TFIBWideStringField * get_ElementKRNAMENOM(void);
   virtual void set_ElementKRNAMENOM(TFIBWideStringField * ElementKRNAMENOM);

   virtual TFIBWideStringField * get_ElementARTNOM(void);
   virtual void set_ElementARTNOM(TFIBWideStringField * ElementARTNOM);

   virtual TFIBWideStringField * get_ElementDESCR_SNOM(void);
   virtual void set_ElementDESCR_SNOM(TFIBWideStringField * ElementDESCR_SNOM);

   virtual TFIBWideStringField * get_ElementGTDNOM(void);
   virtual void set_ElementGTDNOM(TFIBWideStringField * ElementGTDNOM);

   virtual TFIBLargeIntField * get_ElementIDBASE_SNOM(void);
   virtual void set_ElementIDBASE_SNOM(TFIBLargeIntField * ElementIDBASE_SNOM);

   virtual TFIBLargeIntField * get_ElementIDEXT_DOUT_SNOM(void);
   virtual void set_ElementIDEXT_DOUT_SNOM(TFIBLargeIntField * ElementIDEXT_DOUT_SNOM);

   virtual TFIBLargeIntField * get_ElementIDEXT_BASE_SNOM(void);
   virtual void set_ElementIDEXT_BASE_SNOM(TFIBLargeIntField * ElementIDEXT_BASE_SNOM);

   virtual TFIBWideStringField * get_ElementNAMEFIRM(void);
   virtual void set_ElementNAMEFIRM(TFIBWideStringField * ElementNAMEFIRM);

   virtual TFIBWideStringField * get_ElementNAME_SCOUNTRY(void);
   virtual void set_ElementNAME_SCOUNTRY(TFIBWideStringField * ElementNAME_SCOUNTRY);

   virtual TFIBWideStringField * get_ElementNAME_SVIDNOM(void);
   virtual void set_ElementNAME_SVIDNOM(TFIBWideStringField * ElementNAME_SVIDNOM);

   virtual TFIBWideStringField * get_ElementSUPPLIER_NAME(void);
   virtual void set_ElementSUPPLIER_NAME(TFIBWideStringField * ElementSUPPLIER_NAME);

   virtual TFIBWideStringField * get_ElementPRODUCER_NAME(void);
   virtual void set_ElementPRODUCER_NAME(TFIBWideStringField * ElementPRODUCER_NAME);

   virtual TFIBWideStringField * get_ElementNAME_SBRAND(void);
   virtual void set_ElementNAME_SBRAND(TFIBWideStringField * ElementNAME_SBRAND);

   virtual TFIBWideStringField * get_SpTPriceNAME_TPRICE(void);
   virtual void set_SpTPriceNAME_TPRICE(TFIBWideStringField * SpTPriceNAME_TPRICE);

   virtual TFIBWideStringField * get_IBQSprGrpBVNAMEPOD(void);
   virtual void set_IBQSprGrpBVNAMEPOD(TFIBWideStringField * IBQSprGrpBVNAMEPOD);

   virtual TFIBWideStringField * get_IBQSprGrpBVNAME_GBVNOM(void);
   virtual void set_IBQSprGrpBVNAME_GBVNOM(TFIBWideStringField * IBQSprGrpBVNAME_GBVNOM);

   virtual TFIBWideStringField * get_SprScaleAndGrpVesNomNAME_SSCALE(void);
   virtual void set_SprScaleAndGrpVesNomNAME_SSCALE(TFIBWideStringField * SprScaleAndGrpVesNomNAME_SSCALE);

   virtual TFIBWideStringField * get_SprScaleAndGrpVesNomNAME_SGRPVESNOM(void);
   virtual void set_SprScaleAndGrpVesNomNAME_SGRPVESNOM(TFIBWideStringField * SprScaleAndGrpVesNomNAME_SGRPVESNOM);

   virtual TFIBWideStringField * get_BasEdNAMEED(void);
   virtual void set_BasEdNAMEED(TFIBWideStringField * BasEdNAMEED);

   virtual TFIBWideStringField * get_BasEdSHED(void);
   virtual void set_BasEdSHED(TFIBWideStringField * BasEdSHED);

   virtual TFIBWideStringField * get_OsnEdNAMEED(void);
   virtual void set_OsnEdNAMEED(TFIBWideStringField * OsnEdNAMEED);

   virtual TFIBWideStringField * get_OsnEdSHED(void);
   virtual void set_OsnEdSHED(TFIBWideStringField * OsnEdSHED);

   virtual TFIBWideStringField * get_FisEdNAMEED(void);
   virtual void set_FisEdNAMEED(TFIBWideStringField * FisEdNAMEED);

   virtual TFIBWideStringField * get_FisEdSHED(void);
   virtual void set_FisEdSHED(TFIBWideStringField * FisEdSHED);

   virtual TFIBWideStringField * get_SpisokEdNAMEED(void);
   virtual void set_SpisokEdNAMEED(TFIBWideStringField * SpisokEdNAMEED);

   virtual TFIBWideStringField * get_ElementGID_SNOM(void);
   virtual void set_ElementGID_SNOM(TFIBWideStringField * ElementGID_SNOM);

   virtual TFIBSmallIntField * get_ElementFL_ADD_IN_SOBORUD_SNOM(void);
   virtual void set_ElementFL_ADD_IN_SOBORUD_SNOM(TFIBSmallIntField * ElementFL_ADD_IN_SOBORUD_SNOM);

   virtual TFIBSmallIntField * get_ElementFL_DVREG_SNOM(void);
   virtual void set_ElementFL_DVREG_SNOM(TFIBSmallIntField * ElementFL_DVREG_SNOM);

   virtual TFIBLargeIntField * get_TableIDNOM(void);
   virtual void set_TableIDNOM(TFIBLargeIntField * TableIDNOM);

   virtual TFIBWideStringField * get_TableARTNOM(void);
   virtual void set_TableARTNOM(TFIBWideStringField * TableARTNOM);

   virtual TFIBIntegerField * get_TableCODENOM(void);
   virtual void set_TableCODENOM(TFIBIntegerField * TableCODENOM);

   virtual TFIBSmallIntField * get_TableTNOM(void);
   virtual void set_TableTNOM(TFIBSmallIntField * TableTNOM);

   virtual TFIBWideStringField * get_TableNAMENOM(void);
   virtual void set_TableNAMENOM(TFIBWideStringField * TableNAMENOM);

   virtual TFIBWideStringField * get_TableNAMEED(void);
   virtual void set_TableNAMEED(TFIBWideStringField * TableNAMEED);

   virtual TFIBBCDField * get_TableZNACH_PRICE(void);
   virtual void set_TableZNACH_PRICE(TFIBBCDField * TableZNACH_PRICE);

   virtual TFIBLargeIntField * get_TableIDGRPNOM(void);
   virtual void set_TableIDGRPNOM(TFIBLargeIntField * TableIDGRPNOM);

   virtual TFIBLargeIntField * get_TableID_SNOMINETCAT(void);
   virtual void set_TableID_SNOMINETCAT(TFIBLargeIntField * TableID_SNOMINETCAT);

   virtual TFIBBCDField * get_TableSUMKOL(void);
   virtual void set_TableSUMKOL(TFIBBCDField * TableSUMKOL);

   virtual TFIBWideStringField * get_TableSHED(void);
   virtual void set_TableSHED(TFIBWideStringField * TableSHED);

   virtual TFIBBCDField * get_TableREM_OST(void);
   virtual void set_TableREM_OST(TFIBBCDField * TableREM_OST);

   virtual TFIBLargeIntField * get_TableIDFIRM(void);
   virtual void set_TableIDFIRM(TFIBLargeIntField * TableIDFIRM);

   virtual TFIBWideStringField * get_TableNAMEFIRM(void);
   virtual void set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM);

   virtual TFIBLargeIntField * get_TableIDSKLAD(void);
   virtual void set_TableIDSKLAD(TFIBLargeIntField * TableIDSKLAD);

   virtual TFIBWideStringField * get_TableNAMESKLAD(void);
   virtual void set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD);

   virtual TFIBLargeIntField * get_TableIDTNOM(void);
   virtual void set_TableIDTNOM(TFIBLargeIntField * TableIDTNOM);

   virtual TFIBWideStringField * get_TableNAME_STNOM(void);
   virtual void set_TableNAME_STNOM(TFIBWideStringField * TableNAME_STNOM);

   virtual TFIBLargeIntField * get_TableIDED(void);
   virtual void set_TableIDED(TFIBLargeIntField * TableIDED);

   virtual TFIBBCDField * get_TableOUT_PRICE_SKLAD(void);
   virtual void set_TableOUT_PRICE_SKLAD(TFIBBCDField * TableOUT_PRICE_SKLAD);

   virtual TFIBBCDField * get_TableOUT_KFED(void);
   virtual void set_TableOUT_KFED(TFIBBCDField * TableOUT_KFED);

   virtual TFIBBCDField * get_TableOUT_KF2ED(void);
   virtual void set_TableOUT_KF2ED(TFIBBCDField * TableOUT_KF2ED);

   virtual TFIBLargeIntField * get_TableOUT_IDMHRAN(void);
   virtual void set_TableOUT_IDMHRAN(TFIBLargeIntField * TableOUT_IDMHRAN);

   virtual TFIBWideStringField * get_TableOUT_NAME_MHRAN(void);
   virtual void set_TableOUT_NAME_MHRAN(TFIBWideStringField * TableOUT_NAME_MHRAN);

   virtual TFIBLargeIntField * get_TableOUT_IDMHRAN_REM(void);
   virtual void set_TableOUT_IDMHRAN_REM(TFIBLargeIntField * TableOUT_IDMHRAN_REM);

   virtual TFIBWideStringField * get_TableOUT_NAME_MHRAN_REM(void);
   virtual void set_TableOUT_NAME_MHRAN_REM(TFIBWideStringField * TableOUT_NAME_MHRAN_REM);



   virtual TFIBLargeIntField * get_ElementIDVIDIMAGENABOR_SNOM(void);
   virtual void set_ElementIDVIDIMAGENABOR_SNOM(TFIBLargeIntField * ElementIDVIDIMAGENABOR_SNOM);

   virtual TFIBLargeIntField * get_ElementIDPROPNABOR_SNOM(void);
   virtual void set_ElementIDPROPNABOR_SNOM(TFIBLargeIntField * ElementIDPROPNABOR_SNOM);

   virtual TFIBLargeIntField * get_ElementIDDEPARTMENT_SNOM(void);
   virtual void set_ElementIDDEPARTMENT_SNOM(TFIBLargeIntField * ElementIDDEPARTMENT_SNOM);



   virtual TFIBWideStringField * get_ElementNAME_SDEPARTMENT(void);
   virtual void set_ElementNAME_SDEPARTMENT(TFIBWideStringField * ElementNAME_SDEPARTMENT);

   virtual TFIBWideStringField * get_ElementNAME_SPROPNABOR(void);
   virtual void set_ElementNAME_SPROPNABOR(TFIBWideStringField * ElementNAME_SPROPNABOR);

   virtual TFIBWideStringField * get_ElementNAME_SVIDIMAGE_NABOR(void);
   virtual void set_ElementNAME_SVIDIMAGE_NABOR(TFIBWideStringField * ElementNAME_SVIDIMAGE_NABOR);





   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual __int64 get_IdTypePrice(void);
   virtual void set_IdTypePrice(__int64 IdTypePrice);

   virtual __int64 get_IdFirm(void);
   virtual void set_IdFirm(__int64 IdFirm);

   virtual __int64 get_IdSklad(void);
   virtual void set_IdSklad(__int64 IdSklad);

   virtual __int64 get_IdInetCatalog(void);
   virtual void set_IdInetCatalog(__int64 IdInetCatalog);

   virtual int get_CheckOst(void);
   virtual void set_CheckOst(int CheckOst);

   virtual bool get_OnlyChange(void);
   virtual void set_OnlyChange(bool OnlyChange);

   virtual bool get_PriceSklad(void);
   virtual void set_PriceSklad(bool PriceSklad);

   virtual bool get_OnlyOstatok(void);
   virtual void set_OnlyOstatok(bool OnlyOstatok);

   virtual int get_PorNumberString(void);
   virtual void set_PorNumberString(int PorNumberString);

   virtual void OpenTable(__int64 Grp, bool All);
   virtual int OpenElement(__int64 Id );
   virtual bool NewElement(__int64 IdGrp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 Id);
   virtual void ChancheGrp(__int64 NewGrp,__int64 id_nom);
   virtual __int64 FindPoCodu(int Code);
   virtual __int64 FindPoShtrihCodu(AnsiString shtrih_cod);
   virtual __int64 FindPoName(AnsiString name);
   virtual __int64 FindPoArtikulu(UnicodeString artikul);
   virtual int GetIndexTypePrice(void);
   virtual __int64 GetIdBasEd(__int64 id_nom);
   virtual __int64 GetIDElement(String gid);
   virtual AnsiString GetGIDElement(__int64 id);
   virtual __int64 GetIdGrpNom(__int64 id_nom);
   virtual bool ClearFlagChange(void);
   virtual bool DeleteNom(__int64 id_nom);
   virtual int GetCodeNom(void);
   virtual bool CheckCode(__int64 id_nom, int code);
   virtual void OpenSpisokEd(__int64 id_nom);
   virtual void OpenEd(void);
   virtual void OpenBasEd(void);
   virtual void OpenOsnEd(void);
   virtual void OpenFisEd(void);
};
#define CLSID_TDMSprNomImpl __uuidof(TDMSprNomImpl)
#endif
