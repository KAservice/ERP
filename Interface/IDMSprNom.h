#ifndef UIDMSprNomH
#define UIDMSprNomH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
class __declspec(uuid(Global_IID_IDMSprNom)) IDMSprNom : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TDataSource * DataSourceElement = {read = get_DataSourceElement , write = set_DataSourceElement};
   virtual TDataSource * get_DataSourceElement(void)=0;
   virtual void set_DataSourceElement(TDataSource * DataSourceElement)=0;

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

   __property TpFIBDataSet * BasEd = {read = get_BasEd , write = set_BasEd};
   virtual TpFIBDataSet * get_BasEd(void)=0;
   virtual void set_BasEd(TpFIBDataSet * BasEd)=0;

   __property TpFIBDataSet * OsnEd = {read = get_OsnEd , write = set_OsnEd};
   virtual TpFIBDataSet * get_OsnEd(void)=0;
   virtual void set_OsnEd(TpFIBDataSet * OsnEd)=0;

   __property TFIBBCDField * BasEdKFED = {read = get_BasEdKFED , write = set_BasEdKFED};
   virtual TFIBBCDField * get_BasEdKFED(void)=0;
   virtual void set_BasEdKFED(TFIBBCDField * BasEdKFED)=0;

   __property TFIBIntegerField * BasEdTSHED = {read = get_BasEdTSHED , write = set_BasEdTSHED};
   virtual TFIBIntegerField * get_BasEdTSHED(void)=0;
   virtual void set_BasEdTSHED(TFIBIntegerField * BasEdTSHED)=0;

   __property TFIBSmallIntField * BasEdNEISPED = {read = get_BasEdNEISPED , write = set_BasEdNEISPED};
   virtual TFIBSmallIntField * get_BasEdNEISPED(void)=0;
   virtual void set_BasEdNEISPED(TFIBSmallIntField * BasEdNEISPED)=0;

   __property TFIBBCDField * OsnEdKFED = {read = get_OsnEdKFED , write = set_OsnEdKFED};
   virtual TFIBBCDField * get_OsnEdKFED(void)=0;
   virtual void set_OsnEdKFED(TFIBBCDField * OsnEdKFED)=0;

   __property TFIBIntegerField * OsnEdTSHED = {read = get_OsnEdTSHED , write = set_OsnEdTSHED};
   virtual TFIBIntegerField * get_OsnEdTSHED(void)=0;
   virtual void set_OsnEdTSHED(TFIBIntegerField * OsnEdTSHED)=0;

   __property TFIBSmallIntField * OsnEdNEISPED = {read = get_OsnEdNEISPED , write = set_OsnEdNEISPED};
   virtual TFIBSmallIntField * get_OsnEdNEISPED(void)=0;
   virtual void set_OsnEdNEISPED(TFIBSmallIntField * OsnEdNEISPED)=0;

   __property TpFIBDataSet * IBQSprGrpBV = {read = get_IBQSprGrpBV , write = set_IBQSprGrpBV};
   virtual TpFIBDataSet * get_IBQSprGrpBV(void)=0;
   virtual void set_IBQSprGrpBV(TpFIBDataSet * IBQSprGrpBV)=0;

   __property TpFIBDataSet * SpTPrice = {read = get_SpTPrice , write = set_SpTPrice};
   virtual TpFIBDataSet * get_SpTPrice(void)=0;
   virtual void set_SpTPrice(TpFIBDataSet * SpTPrice)=0;

   __property TpFIBDataSet * Code = {read = get_Code , write = set_Code};
   virtual TpFIBDataSet * get_Code(void)=0;
   virtual void set_Code(TpFIBDataSet * Code)=0;

   __property TFIBIntegerField * CodeMAXCODE = {read = get_CodeMAXCODE , write = set_CodeMAXCODE};
   virtual TFIBIntegerField * get_CodeMAXCODE(void)=0;
   virtual void set_CodeMAXCODE(TFIBIntegerField * CodeMAXCODE)=0;

   __property TFIBIntegerField * ElementTNOM = {read = get_ElementTNOM , write = set_ElementTNOM};
   virtual TFIBIntegerField * get_ElementTNOM(void)=0;
   virtual void set_ElementTNOM(TFIBIntegerField * ElementTNOM)=0;

   __property TFIBIntegerField * ElementCODENOM = {read = get_ElementCODENOM , write = set_ElementCODENOM};
   virtual TFIBIntegerField * get_ElementCODENOM(void)=0;
   virtual void set_ElementCODENOM(TFIBIntegerField * ElementCODENOM)=0;

   __property TFIBIntegerField * ElementSTNDSNOM = {read = get_ElementSTNDSNOM , write = set_ElementSTNDSNOM};
   virtual TFIBIntegerField * get_ElementSTNDSNOM(void)=0;
   virtual void set_ElementSTNDSNOM(TFIBIntegerField * ElementSTNDSNOM)=0;

   __property TFIBBCDField * ElementZNACH_PRICE = {read = get_ElementZNACH_PRICE , write = set_ElementZNACH_PRICE};
   virtual TFIBBCDField * get_ElementZNACH_PRICE(void)=0;
   virtual void set_ElementZNACH_PRICE(TFIBBCDField * ElementZNACH_PRICE)=0;

   __property TpFIBQuery * pFIBQuery = {read = get_pFIBQuery , write = set_pFIBQuery};
   virtual TpFIBQuery * get_pFIBQuery(void)=0;
   virtual void set_pFIBQuery(TpFIBQuery * pFIBQuery)=0;

   __property TpFIBTransaction * pFIBTrUpdate = {read = get_pFIBTrUpdate , write = set_pFIBTrUpdate};
   virtual TpFIBTransaction * get_pFIBTrUpdate(void)=0;
   virtual void set_pFIBTrUpdate(TpFIBTransaction * pFIBTrUpdate)=0;

   __property TpFIBTransaction * pFIBTr = {read = get_pFIBTr , write = set_pFIBTr};
   virtual TpFIBTransaction * get_pFIBTr(void)=0;
   virtual void set_pFIBTr(TpFIBTransaction * pFIBTr)=0;

   __property TFIBSmallIntField * ElementFL_CHANGE_NOM = {read = get_ElementFL_CHANGE_NOM , write = set_ElementFL_CHANGE_NOM};
   virtual TFIBSmallIntField * get_ElementFL_CHANGE_NOM(void)=0;
   virtual void set_ElementFL_CHANGE_NOM(TFIBSmallIntField * ElementFL_CHANGE_NOM)=0;

   __property TFIBBCDField * ElementMINOSTNOM = {read = get_ElementMINOSTNOM , write = set_ElementMINOSTNOM};
   virtual TFIBBCDField * get_ElementMINOSTNOM(void)=0;
   virtual void set_ElementMINOSTNOM(TFIBBCDField * ElementMINOSTNOM)=0;

   __property TFIBBCDField * BasEdIDED = {read = get_BasEdIDED , write = set_BasEdIDED};
   virtual TFIBBCDField * get_BasEdIDED(void)=0;
   virtual void set_BasEdIDED(TFIBBCDField * BasEdIDED)=0;

   __property TFIBBCDField * BasEdIDNOMED = {read = get_BasEdIDNOMED , write = set_BasEdIDNOMED};
   virtual TFIBBCDField * get_BasEdIDNOMED(void)=0;
   virtual void set_BasEdIDNOMED(TFIBBCDField * BasEdIDNOMED)=0;

   __property TFIBBCDField * BasEdIDOKEIED = {read = get_BasEdIDOKEIED , write = set_BasEdIDOKEIED};
   virtual TFIBBCDField * get_BasEdIDOKEIED(void)=0;
   virtual void set_BasEdIDOKEIED(TFIBBCDField * BasEdIDOKEIED)=0;

   __property TFIBBCDField * OsnEdIDED = {read = get_OsnEdIDED , write = set_OsnEdIDED};
   virtual TFIBBCDField * get_OsnEdIDED(void)=0;
   virtual void set_OsnEdIDED(TFIBBCDField * OsnEdIDED)=0;

   __property TFIBBCDField * OsnEdIDNOMED = {read = get_OsnEdIDNOMED , write = set_OsnEdIDNOMED};
   virtual TFIBBCDField * get_OsnEdIDNOMED(void)=0;
   virtual void set_OsnEdIDNOMED(TFIBBCDField * OsnEdIDNOMED)=0;

   __property TFIBBCDField * OsnEdIDOKEIED = {read = get_OsnEdIDOKEIED , write = set_OsnEdIDOKEIED};
   virtual TFIBBCDField * get_OsnEdIDOKEIED(void)=0;
   virtual void set_OsnEdIDOKEIED(TFIBBCDField * OsnEdIDOKEIED)=0;

   __property TFIBBCDField * SpTPriceID_TPRICE = {read = get_SpTPriceID_TPRICE , write = set_SpTPriceID_TPRICE};
   virtual TFIBBCDField * get_SpTPriceID_TPRICE(void)=0;
   virtual void set_SpTPriceID_TPRICE(TFIBBCDField * SpTPriceID_TPRICE)=0;

   __property TFIBBCDField * IBQSprGrpBVIDPOD_GBVNOM = {read = get_IBQSprGrpBVIDPOD_GBVNOM , write = set_IBQSprGrpBVIDPOD_GBVNOM};
   virtual TFIBBCDField * get_IBQSprGrpBVIDPOD_GBVNOM(void)=0;
   virtual void set_IBQSprGrpBVIDPOD_GBVNOM(TFIBBCDField * IBQSprGrpBVIDPOD_GBVNOM)=0;

   __property TFIBBCDField * IBQSprGrpBVID_GBVNOM = {read = get_IBQSprGrpBVID_GBVNOM , write = set_IBQSprGrpBVID_GBVNOM};
   virtual TFIBBCDField * get_IBQSprGrpBVID_GBVNOM(void)=0;
   virtual void set_IBQSprGrpBVID_GBVNOM(TFIBBCDField * IBQSprGrpBVID_GBVNOM)=0;

   __property TFIBBCDField * ElementSKIDKA1_SNOM = {read = get_ElementSKIDKA1_SNOM , write = set_ElementSKIDKA1_SNOM};
   virtual TFIBBCDField * get_ElementSKIDKA1_SNOM(void)=0;
   virtual void set_ElementSKIDKA1_SNOM(TFIBBCDField * ElementSKIDKA1_SNOM)=0;

   __property TFIBBCDField * ElementSKIDKA2_SNOM = {read = get_ElementSKIDKA2_SNOM , write = set_ElementSKIDKA2_SNOM};
   virtual TFIBBCDField * get_ElementSKIDKA2_SNOM(void)=0;
   virtual void set_ElementSKIDKA2_SNOM(TFIBBCDField * ElementSKIDKA2_SNOM)=0;

   __property TFIBBCDField * ElementSKIDKA3_SNOM = {read = get_ElementSKIDKA3_SNOM , write = set_ElementSKIDKA3_SNOM};
   virtual TFIBBCDField * get_ElementSKIDKA3_SNOM(void)=0;
   virtual void set_ElementSKIDKA3_SNOM(TFIBBCDField * ElementSKIDKA3_SNOM)=0;

   __property TFIBSmallIntField * ElementTYPESRGODN_SNOM = {read = get_ElementTYPESRGODN_SNOM , write = set_ElementTYPESRGODN_SNOM};
   virtual TFIBSmallIntField * get_ElementTYPESRGODN_SNOM(void)=0;
   virtual void set_ElementTYPESRGODN_SNOM(TFIBSmallIntField * ElementTYPESRGODN_SNOM)=0;

   __property TFIBSmallIntField * ElementSRGODN_SNOM = {read = get_ElementSRGODN_SNOM , write = set_ElementSRGODN_SNOM};
   virtual TFIBSmallIntField * get_ElementSRGODN_SNOM(void)=0;
   virtual void set_ElementSRGODN_SNOM(TFIBSmallIntField * ElementSRGODN_SNOM)=0;

   __property TpFIBDataSet * SprScaleAndGrpVesNom = {read = get_SprScaleAndGrpVesNom , write = set_SprScaleAndGrpVesNom};
   virtual TpFIBDataSet * get_SprScaleAndGrpVesNom(void)=0;
   virtual void set_SprScaleAndGrpVesNom(TpFIBDataSet * SprScaleAndGrpVesNom)=0;

   __property TFIBBCDField * SprScaleAndGrpVesNomIDSCALE_SGRPVESNOM = {read = get_SprScaleAndGrpVesNomIDSCALE_SGRPVESNOM , write = set_SprScaleAndGrpVesNomIDSCALE_SGRPVESNOM};
   virtual TFIBBCDField * get_SprScaleAndGrpVesNomIDSCALE_SGRPVESNOM(void)=0;
   virtual void set_SprScaleAndGrpVesNomIDSCALE_SGRPVESNOM(TFIBBCDField * SprScaleAndGrpVesNomIDSCALE_SGRPVESNOM)=0;

   __property TFIBBCDField * SprScaleAndGrpVesNomID_SGRPVESNOM = {read = get_SprScaleAndGrpVesNomID_SGRPVESNOM , write = set_SprScaleAndGrpVesNomID_SGRPVESNOM};
   virtual TFIBBCDField * get_SprScaleAndGrpVesNomID_SGRPVESNOM(void)=0;
   virtual void set_SprScaleAndGrpVesNomID_SGRPVESNOM(TFIBBCDField * SprScaleAndGrpVesNomID_SGRPVESNOM)=0;

   __property TpFIBDataSet * FisEd = {read = get_FisEd , write = set_FisEd};
   virtual TpFIBDataSet * get_FisEd(void)=0;
   virtual void set_FisEd(TpFIBDataSet * FisEd)=0;

   __property TFIBBCDField * FIBBCDField1 = {read = get_FIBBCDField1 , write = set_FIBBCDField1};
   virtual TFIBBCDField * get_FIBBCDField1(void)=0;
   virtual void set_FIBBCDField1(TFIBBCDField * FIBBCDField1)=0;

   __property TFIBIntegerField * FIBIntegerField1 = {read = get_FIBIntegerField1 , write = set_FIBIntegerField1};
   virtual TFIBIntegerField * get_FIBIntegerField1(void)=0;
   virtual void set_FIBIntegerField1(TFIBIntegerField * FIBIntegerField1)=0;

   __property TFIBSmallIntField * FIBSmallIntField1 = {read = get_FIBSmallIntField1 , write = set_FIBSmallIntField1};
   virtual TFIBSmallIntField * get_FIBSmallIntField1(void)=0;
   virtual void set_FIBSmallIntField1(TFIBSmallIntField * FIBSmallIntField1)=0;

   __property TFIBBCDField * FIBBCDField2 = {read = get_FIBBCDField2 , write = set_FIBBCDField2};
   virtual TFIBBCDField * get_FIBBCDField2(void)=0;
   virtual void set_FIBBCDField2(TFIBBCDField * FIBBCDField2)=0;

   __property TFIBBCDField * FIBBCDField3 = {read = get_FIBBCDField3 , write = set_FIBBCDField3};
   virtual TFIBBCDField * get_FIBBCDField3(void)=0;
   virtual void set_FIBBCDField3(TFIBBCDField * FIBBCDField3)=0;

   __property TFIBBCDField * FIBBCDField4 = {read = get_FIBBCDField4 , write = set_FIBBCDField4};
   virtual TFIBBCDField * get_FIBBCDField4(void)=0;
   virtual void set_FIBBCDField4(TFIBBCDField * FIBBCDField4)=0;

   __property TpFIBDataSet * SpisokEd = {read = get_SpisokEd , write = set_SpisokEd};
   virtual TpFIBDataSet * get_SpisokEd(void)=0;
   virtual void set_SpisokEd(TpFIBDataSet * SpisokEd)=0;

   __property TDataSource * DataSourceSpisokEd = {read = get_DataSourceSpisokEd , write = set_DataSourceSpisokEd};
   virtual TDataSource * get_DataSourceSpisokEd(void)=0;
   virtual void set_DataSourceSpisokEd(TDataSource * DataSourceSpisokEd)=0;

   __property TFIBBCDField * SpisokEdKFED = {read = get_SpisokEdKFED , write = set_SpisokEdKFED};
   virtual TFIBBCDField * get_SpisokEdKFED(void)=0;
   virtual void set_SpisokEdKFED(TFIBBCDField * SpisokEdKFED)=0;

   __property TDataSource * DataSourceBasEd = {read = get_DataSourceBasEd , write = set_DataSourceBasEd};
   virtual TDataSource * get_DataSourceBasEd(void)=0;
   virtual void set_DataSourceBasEd(TDataSource * DataSourceBasEd)=0;

   __property TDataSource * DataSourceOsnEd = {read = get_DataSourceOsnEd , write = set_DataSourceOsnEd};
   virtual TDataSource * get_DataSourceOsnEd(void)=0;
   virtual void set_DataSourceOsnEd(TDataSource * DataSourceOsnEd)=0;

   __property TDataSource * DataSourceFisEd = {read = get_DataSourceFisEd , write = set_DataSourceFisEd};
   virtual TDataSource * get_DataSourceFisEd(void)=0;
   virtual void set_DataSourceFisEd(TDataSource * DataSourceFisEd)=0;

   __property TFIBIntegerField * BasEdCODE_SED = {read = get_BasEdCODE_SED , write = set_BasEdCODE_SED};
   virtual TFIBIntegerField * get_BasEdCODE_SED(void)=0;
   virtual void set_BasEdCODE_SED(TFIBIntegerField * BasEdCODE_SED)=0;

   __property TFIBBCDField * BasEdKF2_SED = {read = get_BasEdKF2_SED , write = set_BasEdKF2_SED};
   virtual TFIBBCDField * get_BasEdKF2_SED(void)=0;
   virtual void set_BasEdKF2_SED(TFIBBCDField * BasEdKF2_SED)=0;

   __property TFIBBCDField * BasEdVES_SED = {read = get_BasEdVES_SED , write = set_BasEdVES_SED};
   virtual TFIBBCDField * get_BasEdVES_SED(void)=0;
   virtual void set_BasEdVES_SED(TFIBBCDField * BasEdVES_SED)=0;

   __property TFIBIntegerField * OsnEdCODE_SED = {read = get_OsnEdCODE_SED , write = set_OsnEdCODE_SED};
   virtual TFIBIntegerField * get_OsnEdCODE_SED(void)=0;
   virtual void set_OsnEdCODE_SED(TFIBIntegerField * OsnEdCODE_SED)=0;

   __property TFIBBCDField * OsnEdKF2_SED = {read = get_OsnEdKF2_SED , write = set_OsnEdKF2_SED};
   virtual TFIBBCDField * get_OsnEdKF2_SED(void)=0;
   virtual void set_OsnEdKF2_SED(TFIBBCDField * OsnEdKF2_SED)=0;

   __property TFIBBCDField * OsnEdVES_SED = {read = get_OsnEdVES_SED , write = set_OsnEdVES_SED};
   virtual TFIBBCDField * get_OsnEdVES_SED(void)=0;
   virtual void set_OsnEdVES_SED(TFIBBCDField * OsnEdVES_SED)=0;

   __property TFIBIntegerField * FisEdCODE_SED = {read = get_FisEdCODE_SED , write = set_FisEdCODE_SED};
   virtual TFIBIntegerField * get_FisEdCODE_SED(void)=0;
   virtual void set_FisEdCODE_SED(TFIBIntegerField * FisEdCODE_SED)=0;

   __property TFIBBCDField * FisEdKF2_SED = {read = get_FisEdKF2_SED , write = set_FisEdKF2_SED};
   virtual TFIBBCDField * get_FisEdKF2_SED(void)=0;
   virtual void set_FisEdKF2_SED(TFIBBCDField * FisEdKF2_SED)=0;

   __property TFIBBCDField * FisEdVES_SED = {read = get_FisEdVES_SED , write = set_FisEdVES_SED};
   virtual TFIBBCDField * get_FisEdVES_SED(void)=0;
   virtual void set_FisEdVES_SED(TFIBBCDField * FisEdVES_SED)=0;

   __property TFIBDateTimeField * ElementGODEN_DO_SNOM = {read = get_ElementGODEN_DO_SNOM , write = set_ElementGODEN_DO_SNOM};
   virtual TFIBDateTimeField * get_ElementGODEN_DO_SNOM(void)=0;
   virtual void set_ElementGODEN_DO_SNOM(TFIBDateTimeField * ElementGODEN_DO_SNOM)=0;

   __property TFIBIntegerField * ElementWARRANTY_SNOM = {read = get_ElementWARRANTY_SNOM , write = set_ElementWARRANTY_SNOM};
   virtual TFIBIntegerField * get_ElementWARRANTY_SNOM(void)=0;
   virtual void set_ElementWARRANTY_SNOM(TFIBIntegerField * ElementWARRANTY_SNOM)=0;

   __property TFIBSmallIntField * ElementFL_CREDIT_SNOM = {read = get_ElementFL_CREDIT_SNOM , write = set_ElementFL_CREDIT_SNOM};
   virtual TFIBSmallIntField * get_ElementFL_CREDIT_SNOM(void)=0;
   virtual void set_ElementFL_CREDIT_SNOM(TFIBSmallIntField * ElementFL_CREDIT_SNOM)=0;

   __property TFIBSmallIntField * ElementFL_TRANSPORT_SNOM = {read = get_ElementFL_TRANSPORT_SNOM , write = set_ElementFL_TRANSPORT_SNOM};
   virtual TFIBSmallIntField * get_ElementFL_TRANSPORT_SNOM(void)=0;
   virtual void set_ElementFL_TRANSPORT_SNOM(TFIBSmallIntField * ElementFL_TRANSPORT_SNOM)=0;

   __property TFIBLargeIntField * SpisokEdIDED = {read = get_SpisokEdIDED , write = set_SpisokEdIDED};
   virtual TFIBLargeIntField * get_SpisokEdIDED(void)=0;
   virtual void set_SpisokEdIDED(TFIBLargeIntField * SpisokEdIDED)=0;

   __property TFIBBCDField * ElementPOGR_SNOM = {read = get_ElementPOGR_SNOM , write = set_ElementPOGR_SNOM};
   virtual TFIBBCDField * get_ElementPOGR_SNOM(void)=0;
   virtual void set_ElementPOGR_SNOM(TFIBBCDField * ElementPOGR_SNOM)=0;

   __property TFIBLargeIntField * ElementIDNOM = {read = get_ElementIDNOM , write = set_ElementIDNOM};
   virtual TFIBLargeIntField * get_ElementIDNOM(void)=0;
   virtual void set_ElementIDNOM(TFIBLargeIntField * ElementIDNOM)=0;

   __property TFIBLargeIntField * ElementIDBASEDNOM = {read = get_ElementIDBASEDNOM , write = set_ElementIDBASEDNOM};
   virtual TFIBLargeIntField * get_ElementIDBASEDNOM(void)=0;
   virtual void set_ElementIDBASEDNOM(TFIBLargeIntField * ElementIDBASEDNOM)=0;

   __property TFIBLargeIntField * ElementIDOSNEDNOM = {read = get_ElementIDOSNEDNOM , write = set_ElementIDOSNEDNOM};
   virtual TFIBLargeIntField * get_ElementIDOSNEDNOM(void)=0;
   virtual void set_ElementIDOSNEDNOM(TFIBLargeIntField * ElementIDOSNEDNOM)=0;

   __property TFIBLargeIntField * ElementIDFISED_SNOM = {read = get_ElementIDFISED_SNOM , write = set_ElementIDFISED_SNOM};
   virtual TFIBLargeIntField * get_ElementIDFISED_SNOM(void)=0;
   virtual void set_ElementIDFISED_SNOM(TFIBLargeIntField * ElementIDFISED_SNOM)=0;

   __property TFIBLargeIntField * ElementIDGRPNOM = {read = get_ElementIDGRPNOM , write = set_ElementIDGRPNOM};
   virtual TFIBLargeIntField * get_ElementIDGRPNOM(void)=0;
   virtual void set_ElementIDGRPNOM(TFIBLargeIntField * ElementIDGRPNOM)=0;

   __property TFIBLargeIntField * ElementIDFIRMNOM = {read = get_ElementIDFIRMNOM , write = set_ElementIDFIRMNOM};
   virtual TFIBLargeIntField * get_ElementIDFIRMNOM(void)=0;
   virtual void set_ElementIDFIRMNOM(TFIBLargeIntField * ElementIDFIRMNOM)=0;

   __property TFIBLargeIntField * ElementIDCOUNTRYNOM = {read = get_ElementIDCOUNTRYNOM , write = set_ElementIDCOUNTRYNOM};
   virtual TFIBLargeIntField * get_ElementIDCOUNTRYNOM(void)=0;
   virtual void set_ElementIDCOUNTRYNOM(TFIBLargeIntField * ElementIDCOUNTRYNOM)=0;

   __property TFIBLargeIntField * ElementIDVID_SNOM = {read = get_ElementIDVID_SNOM , write = set_ElementIDVID_SNOM};
   virtual TFIBLargeIntField * get_ElementIDVID_SNOM(void)=0;
   virtual void set_ElementIDVID_SNOM(TFIBLargeIntField * ElementIDVID_SNOM)=0;

   __property TFIBLargeIntField * ElementIDSUPPLIER_SNOM = {read = get_ElementIDSUPPLIER_SNOM , write = set_ElementIDSUPPLIER_SNOM};
   virtual TFIBLargeIntField * get_ElementIDSUPPLIER_SNOM(void)=0;
   virtual void set_ElementIDSUPPLIER_SNOM(TFIBLargeIntField * ElementIDSUPPLIER_SNOM)=0;

   __property TFIBLargeIntField * ElementIDPRODUCER_SNOM = {read = get_ElementIDPRODUCER_SNOM , write = set_ElementIDPRODUCER_SNOM};
   virtual TFIBLargeIntField * get_ElementIDPRODUCER_SNOM(void)=0;
   virtual void set_ElementIDPRODUCER_SNOM(TFIBLargeIntField * ElementIDPRODUCER_SNOM)=0;

   __property TFIBLargeIntField * ElementIDBRAND_SNOM = {read = get_ElementIDBRAND_SNOM , write = set_ElementIDBRAND_SNOM};
   virtual TFIBLargeIntField * get_ElementIDBRAND_SNOM(void)=0;
   virtual void set_ElementIDBRAND_SNOM(TFIBLargeIntField * ElementIDBRAND_SNOM)=0;

   __property TFIBWideStringField * ElementNAMENOM = {read = get_ElementNAMENOM , write = set_ElementNAMENOM};
   virtual TFIBWideStringField * get_ElementNAMENOM(void)=0;
   virtual void set_ElementNAMENOM(TFIBWideStringField * ElementNAMENOM)=0;

   __property TFIBWideStringField * ElementFNAMENOM = {read = get_ElementFNAMENOM , write = set_ElementFNAMENOM};
   virtual TFIBWideStringField * get_ElementFNAMENOM(void)=0;
   virtual void set_ElementFNAMENOM(TFIBWideStringField * ElementFNAMENOM)=0;

   __property TFIBWideStringField * ElementKRNAMENOM = {read = get_ElementKRNAMENOM , write = set_ElementKRNAMENOM};
   virtual TFIBWideStringField * get_ElementKRNAMENOM(void)=0;
   virtual void set_ElementKRNAMENOM(TFIBWideStringField * ElementKRNAMENOM)=0;

   __property TFIBWideStringField * ElementARTNOM = {read = get_ElementARTNOM , write = set_ElementARTNOM};
   virtual TFIBWideStringField * get_ElementARTNOM(void)=0;
   virtual void set_ElementARTNOM(TFIBWideStringField * ElementARTNOM)=0;

   __property TFIBWideStringField * ElementDESCR_SNOM = {read = get_ElementDESCR_SNOM , write = set_ElementDESCR_SNOM};
   virtual TFIBWideStringField * get_ElementDESCR_SNOM(void)=0;
   virtual void set_ElementDESCR_SNOM(TFIBWideStringField * ElementDESCR_SNOM)=0;

   __property TFIBWideStringField * ElementGTDNOM = {read = get_ElementGTDNOM , write = set_ElementGTDNOM};
   virtual TFIBWideStringField * get_ElementGTDNOM(void)=0;
   virtual void set_ElementGTDNOM(TFIBWideStringField * ElementGTDNOM)=0;

   __property TFIBLargeIntField * ElementIDBASE_SNOM = {read = get_ElementIDBASE_SNOM , write = set_ElementIDBASE_SNOM};
   virtual TFIBLargeIntField * get_ElementIDBASE_SNOM(void)=0;
   virtual void set_ElementIDBASE_SNOM(TFIBLargeIntField * ElementIDBASE_SNOM)=0;

   __property TFIBLargeIntField * ElementIDEXT_DOUT_SNOM = {read = get_ElementIDEXT_DOUT_SNOM , write = set_ElementIDEXT_DOUT_SNOM};
   virtual TFIBLargeIntField * get_ElementIDEXT_DOUT_SNOM(void)=0;
   virtual void set_ElementIDEXT_DOUT_SNOM(TFIBLargeIntField * ElementIDEXT_DOUT_SNOM)=0;

   __property TFIBLargeIntField * ElementIDEXT_BASE_SNOM = {read = get_ElementIDEXT_BASE_SNOM , write = set_ElementIDEXT_BASE_SNOM};
   virtual TFIBLargeIntField * get_ElementIDEXT_BASE_SNOM(void)=0;
   virtual void set_ElementIDEXT_BASE_SNOM(TFIBLargeIntField * ElementIDEXT_BASE_SNOM)=0;

   __property TFIBWideStringField * ElementNAMEFIRM = {read = get_ElementNAMEFIRM , write = set_ElementNAMEFIRM};
   virtual TFIBWideStringField * get_ElementNAMEFIRM(void)=0;
   virtual void set_ElementNAMEFIRM(TFIBWideStringField * ElementNAMEFIRM)=0;

   __property TFIBWideStringField * ElementNAME_SCOUNTRY = {read = get_ElementNAME_SCOUNTRY , write = set_ElementNAME_SCOUNTRY};
   virtual TFIBWideStringField * get_ElementNAME_SCOUNTRY(void)=0;
   virtual void set_ElementNAME_SCOUNTRY(TFIBWideStringField * ElementNAME_SCOUNTRY)=0;

   __property TFIBWideStringField * ElementNAME_SVIDNOM = {read = get_ElementNAME_SVIDNOM , write = set_ElementNAME_SVIDNOM};
   virtual TFIBWideStringField * get_ElementNAME_SVIDNOM(void)=0;
   virtual void set_ElementNAME_SVIDNOM(TFIBWideStringField * ElementNAME_SVIDNOM)=0;

   __property TFIBWideStringField * ElementSUPPLIER_NAME = {read = get_ElementSUPPLIER_NAME , write = set_ElementSUPPLIER_NAME};
   virtual TFIBWideStringField * get_ElementSUPPLIER_NAME(void)=0;
   virtual void set_ElementSUPPLIER_NAME(TFIBWideStringField * ElementSUPPLIER_NAME)=0;

   __property TFIBWideStringField * ElementPRODUCER_NAME = {read = get_ElementPRODUCER_NAME , write = set_ElementPRODUCER_NAME};
   virtual TFIBWideStringField * get_ElementPRODUCER_NAME(void)=0;
   virtual void set_ElementPRODUCER_NAME(TFIBWideStringField * ElementPRODUCER_NAME)=0;

   __property TFIBWideStringField * ElementNAME_SBRAND = {read = get_ElementNAME_SBRAND , write = set_ElementNAME_SBRAND};
   virtual TFIBWideStringField * get_ElementNAME_SBRAND(void)=0;
   virtual void set_ElementNAME_SBRAND(TFIBWideStringField * ElementNAME_SBRAND)=0;

   __property TFIBWideStringField * SpTPriceNAME_TPRICE = {read = get_SpTPriceNAME_TPRICE , write = set_SpTPriceNAME_TPRICE};
   virtual TFIBWideStringField * get_SpTPriceNAME_TPRICE(void)=0;
   virtual void set_SpTPriceNAME_TPRICE(TFIBWideStringField * SpTPriceNAME_TPRICE)=0;

   __property TFIBWideStringField * IBQSprGrpBVNAMEPOD = {read = get_IBQSprGrpBVNAMEPOD , write = set_IBQSprGrpBVNAMEPOD};
   virtual TFIBWideStringField * get_IBQSprGrpBVNAMEPOD(void)=0;
   virtual void set_IBQSprGrpBVNAMEPOD(TFIBWideStringField * IBQSprGrpBVNAMEPOD)=0;

   __property TFIBWideStringField * IBQSprGrpBVNAME_GBVNOM = {read = get_IBQSprGrpBVNAME_GBVNOM , write = set_IBQSprGrpBVNAME_GBVNOM};
   virtual TFIBWideStringField * get_IBQSprGrpBVNAME_GBVNOM(void)=0;
   virtual void set_IBQSprGrpBVNAME_GBVNOM(TFIBWideStringField * IBQSprGrpBVNAME_GBVNOM)=0;

   __property TFIBWideStringField * SprScaleAndGrpVesNomNAME_SSCALE = {read = get_SprScaleAndGrpVesNomNAME_SSCALE , write = set_SprScaleAndGrpVesNomNAME_SSCALE};
   virtual TFIBWideStringField * get_SprScaleAndGrpVesNomNAME_SSCALE(void)=0;
   virtual void set_SprScaleAndGrpVesNomNAME_SSCALE(TFIBWideStringField * SprScaleAndGrpVesNomNAME_SSCALE)=0;

   __property TFIBWideStringField * SprScaleAndGrpVesNomNAME_SGRPVESNOM = {read = get_SprScaleAndGrpVesNomNAME_SGRPVESNOM , write = set_SprScaleAndGrpVesNomNAME_SGRPVESNOM};
   virtual TFIBWideStringField * get_SprScaleAndGrpVesNomNAME_SGRPVESNOM(void)=0;
   virtual void set_SprScaleAndGrpVesNomNAME_SGRPVESNOM(TFIBWideStringField * SprScaleAndGrpVesNomNAME_SGRPVESNOM)=0;

   __property TFIBWideStringField * BasEdNAMEED = {read = get_BasEdNAMEED , write = set_BasEdNAMEED};
   virtual TFIBWideStringField * get_BasEdNAMEED(void)=0;
   virtual void set_BasEdNAMEED(TFIBWideStringField * BasEdNAMEED)=0;

   __property TFIBWideStringField * BasEdSHED = {read = get_BasEdSHED , write = set_BasEdSHED};
   virtual TFIBWideStringField * get_BasEdSHED(void)=0;
   virtual void set_BasEdSHED(TFIBWideStringField * BasEdSHED)=0;

   __property TFIBWideStringField * OsnEdNAMEED = {read = get_OsnEdNAMEED , write = set_OsnEdNAMEED};
   virtual TFIBWideStringField * get_OsnEdNAMEED(void)=0;
   virtual void set_OsnEdNAMEED(TFIBWideStringField * OsnEdNAMEED)=0;

   __property TFIBWideStringField * OsnEdSHED = {read = get_OsnEdSHED , write = set_OsnEdSHED};
   virtual TFIBWideStringField * get_OsnEdSHED(void)=0;
   virtual void set_OsnEdSHED(TFIBWideStringField * OsnEdSHED)=0;

   __property TFIBWideStringField * FisEdNAMEED = {read = get_FisEdNAMEED , write = set_FisEdNAMEED};
   virtual TFIBWideStringField * get_FisEdNAMEED(void)=0;
   virtual void set_FisEdNAMEED(TFIBWideStringField * FisEdNAMEED)=0;

   __property TFIBWideStringField * FisEdSHED = {read = get_FisEdSHED , write = set_FisEdSHED};
   virtual TFIBWideStringField * get_FisEdSHED(void)=0;
   virtual void set_FisEdSHED(TFIBWideStringField * FisEdSHED)=0;

   __property TFIBWideStringField * SpisokEdNAMEED = {read = get_SpisokEdNAMEED , write = set_SpisokEdNAMEED};
   virtual TFIBWideStringField * get_SpisokEdNAMEED(void)=0;
   virtual void set_SpisokEdNAMEED(TFIBWideStringField * SpisokEdNAMEED)=0;

   __property TFIBWideStringField * ElementGID_SNOM = {read = get_ElementGID_SNOM , write = set_ElementGID_SNOM};
   virtual TFIBWideStringField * get_ElementGID_SNOM(void)=0;
   virtual void set_ElementGID_SNOM(TFIBWideStringField * ElementGID_SNOM)=0;

   __property TFIBSmallIntField * ElementFL_ADD_IN_SOBORUD_SNOM = {read = get_ElementFL_ADD_IN_SOBORUD_SNOM , write = set_ElementFL_ADD_IN_SOBORUD_SNOM};
   virtual TFIBSmallIntField * get_ElementFL_ADD_IN_SOBORUD_SNOM(void)=0;
   virtual void set_ElementFL_ADD_IN_SOBORUD_SNOM(TFIBSmallIntField * ElementFL_ADD_IN_SOBORUD_SNOM)=0;

   __property TFIBSmallIntField * ElementFL_DVREG_SNOM = {read = get_ElementFL_DVREG_SNOM , write = set_ElementFL_DVREG_SNOM};
   virtual TFIBSmallIntField * get_ElementFL_DVREG_SNOM(void)=0;
   virtual void set_ElementFL_DVREG_SNOM(TFIBSmallIntField * ElementFL_DVREG_SNOM)=0;

   __property TFIBLargeIntField * TableIDNOM = {read = get_TableIDNOM , write = set_TableIDNOM};
   virtual TFIBLargeIntField * get_TableIDNOM(void)=0;
   virtual void set_TableIDNOM(TFIBLargeIntField * TableIDNOM)=0;

   __property TFIBWideStringField * TableARTNOM = {read = get_TableARTNOM , write = set_TableARTNOM};
   virtual TFIBWideStringField * get_TableARTNOM(void)=0;
   virtual void set_TableARTNOM(TFIBWideStringField * TableARTNOM)=0;

   __property TFIBIntegerField * TableCODENOM = {read = get_TableCODENOM , write = set_TableCODENOM};
   virtual TFIBIntegerField * get_TableCODENOM(void)=0;
   virtual void set_TableCODENOM(TFIBIntegerField * TableCODENOM)=0;

   __property TFIBSmallIntField * TableTNOM = {read = get_TableTNOM , write = set_TableTNOM};
   virtual TFIBSmallIntField * get_TableTNOM(void)=0;
   virtual void set_TableTNOM(TFIBSmallIntField * TableTNOM)=0;

   __property TFIBWideStringField * TableNAMENOM = {read = get_TableNAMENOM , write = set_TableNAMENOM};
   virtual TFIBWideStringField * get_TableNAMENOM(void)=0;
   virtual void set_TableNAMENOM(TFIBWideStringField * TableNAMENOM)=0;

   __property TFIBWideStringField * TableNAMEED = {read = get_TableNAMEED , write = set_TableNAMEED};
   virtual TFIBWideStringField * get_TableNAMEED(void)=0;
   virtual void set_TableNAMEED(TFIBWideStringField * TableNAMEED)=0;

   __property TFIBBCDField * TableZNACH_PRICE = {read = get_TableZNACH_PRICE , write = set_TableZNACH_PRICE};
   virtual TFIBBCDField * get_TableZNACH_PRICE(void)=0;
   virtual void set_TableZNACH_PRICE(TFIBBCDField * TableZNACH_PRICE)=0;

   __property TFIBLargeIntField * TableIDGRPNOM = {read = get_TableIDGRPNOM , write = set_TableIDGRPNOM};
   virtual TFIBLargeIntField * get_TableIDGRPNOM(void)=0;
   virtual void set_TableIDGRPNOM(TFIBLargeIntField * TableIDGRPNOM)=0;

   __property TFIBLargeIntField * TableID_SNOMINETCAT = {read = get_TableID_SNOMINETCAT , write = set_TableID_SNOMINETCAT};
   virtual TFIBLargeIntField * get_TableID_SNOMINETCAT(void)=0;
   virtual void set_TableID_SNOMINETCAT(TFIBLargeIntField * TableID_SNOMINETCAT)=0;

   __property TFIBBCDField * TableSUMKOL = {read = get_TableSUMKOL , write = set_TableSUMKOL};
   virtual TFIBBCDField * get_TableSUMKOL(void)=0;
   virtual void set_TableSUMKOL(TFIBBCDField * TableSUMKOL)=0;

   __property TFIBWideStringField * TableSHED = {read = get_TableSHED , write = set_TableSHED};
   virtual TFIBWideStringField * get_TableSHED(void)=0;
   virtual void set_TableSHED(TFIBWideStringField * TableSHED)=0;

   __property TFIBBCDField * TableREM_OST = {read = get_TableREM_OST , write = set_TableREM_OST};
   virtual TFIBBCDField * get_TableREM_OST(void)=0;
   virtual void set_TableREM_OST(TFIBBCDField * TableREM_OST)=0;

   __property TFIBLargeIntField * TableIDFIRM = {read = get_TableIDFIRM , write = set_TableIDFIRM};
   virtual TFIBLargeIntField * get_TableIDFIRM(void)=0;
   virtual void set_TableIDFIRM(TFIBLargeIntField * TableIDFIRM)=0;

   __property TFIBWideStringField * TableNAMEFIRM = {read = get_TableNAMEFIRM , write = set_TableNAMEFIRM};
   virtual TFIBWideStringField * get_TableNAMEFIRM(void)=0;
   virtual void set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM)=0;

   __property TFIBLargeIntField * TableIDSKLAD = {read = get_TableIDSKLAD , write = set_TableIDSKLAD};
   virtual TFIBLargeIntField * get_TableIDSKLAD(void)=0;
   virtual void set_TableIDSKLAD(TFIBLargeIntField * TableIDSKLAD)=0;

   __property TFIBWideStringField * TableNAMESKLAD = {read = get_TableNAMESKLAD , write = set_TableNAMESKLAD};
   virtual TFIBWideStringField * get_TableNAMESKLAD(void)=0;
   virtual void set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)=0;

   __property TFIBLargeIntField * TableIDTNOM = {read = get_TableIDTNOM , write = set_TableIDTNOM};
   virtual TFIBLargeIntField * get_TableIDTNOM(void)=0;
   virtual void set_TableIDTNOM(TFIBLargeIntField * TableIDTNOM)=0;

   __property TFIBWideStringField * TableNAME_STNOM = {read = get_TableNAME_STNOM , write = set_TableNAME_STNOM};
   virtual TFIBWideStringField * get_TableNAME_STNOM(void)=0;
   virtual void set_TableNAME_STNOM(TFIBWideStringField * TableNAME_STNOM)=0;

   __property TFIBLargeIntField * TableIDED = {read = get_TableIDED , write = set_TableIDED};
   virtual TFIBLargeIntField * get_TableIDED(void)=0;
   virtual void set_TableIDED(TFIBLargeIntField * TableIDED)=0;

   __property TFIBBCDField * TableOUT_PRICE_SKLAD = {read = get_TableOUT_PRICE_SKLAD , write = set_TableOUT_PRICE_SKLAD};
   virtual TFIBBCDField * get_TableOUT_PRICE_SKLAD(void)=0;
   virtual void set_TableOUT_PRICE_SKLAD(TFIBBCDField * TableOUT_PRICE_SKLAD)=0;

   __property TFIBBCDField * TableOUT_KFED = {read = get_TableOUT_KFED , write = set_TableOUT_KFED};
   virtual TFIBBCDField * get_TableOUT_KFED(void)=0;
   virtual void set_TableOUT_KFED(TFIBBCDField * TableOUT_KFED)=0;

   __property TFIBBCDField * TableOUT_KF2ED = {read = get_TableOUT_KF2ED , write = set_TableOUT_KF2ED};
   virtual TFIBBCDField * get_TableOUT_KF2ED(void)=0;
   virtual void set_TableOUT_KF2ED(TFIBBCDField * TableOUT_KF2ED)=0;

   __property TFIBLargeIntField * TableOUT_IDMHRAN = {read = get_TableOUT_IDMHRAN , write = set_TableOUT_IDMHRAN};
   virtual TFIBLargeIntField * get_TableOUT_IDMHRAN(void)=0;
   virtual void set_TableOUT_IDMHRAN(TFIBLargeIntField * TableOUT_IDMHRAN)=0;

   __property TFIBWideStringField * TableOUT_NAME_MHRAN = {read = get_TableOUT_NAME_MHRAN , write = set_TableOUT_NAME_MHRAN};
   virtual TFIBWideStringField * get_TableOUT_NAME_MHRAN(void)=0;
   virtual void set_TableOUT_NAME_MHRAN(TFIBWideStringField * TableOUT_NAME_MHRAN)=0;

   __property TFIBLargeIntField * TableOUT_IDMHRAN_REM = {read = get_TableOUT_IDMHRAN_REM , write = set_TableOUT_IDMHRAN_REM};
   virtual TFIBLargeIntField * get_TableOUT_IDMHRAN_REM(void)=0;
   virtual void set_TableOUT_IDMHRAN_REM(TFIBLargeIntField * TableOUT_IDMHRAN_REM)=0;

   __property TFIBWideStringField * TableOUT_NAME_MHRAN_REM = {read = get_TableOUT_NAME_MHRAN_REM , write = set_TableOUT_NAME_MHRAN_REM};
   virtual TFIBWideStringField * get_TableOUT_NAME_MHRAN_REM(void)=0;
   virtual void set_TableOUT_NAME_MHRAN_REM(TFIBWideStringField * TableOUT_NAME_MHRAN_REM)=0;




   //	TFIBLargeIntField *ElementIDVIDIMAGENABOR_SNOM;
   //	TFIBLargeIntField *ElementIDPROPNABOR_SNOM;
   //	TFIBLargeIntField *ElementIDDEPARTMENT_SNOM;
	//TFIBWideStringField *ElementNAME_SDEPARTMENT;
	//TFIBWideStringField *ElementNAME_SPROPNABOR;
   //	TFIBWideStringField *ElementNAME_SVIDIMAGE_NABOR;


   __property TFIBLargeIntField * ElementIDVIDIMAGENABOR_SNOM = {read = get_ElementIDVIDIMAGENABOR_SNOM , write = set_ElementIDVIDIMAGENABOR_SNOM};
   virtual TFIBLargeIntField * get_ElementIDVIDIMAGENABOR_SNOM(void)=0;
   virtual void set_ElementIDVIDIMAGENABOR_SNOM(TFIBLargeIntField * ElementIDVIDIMAGENABOR_SNOM)=0;

   __property TFIBLargeIntField * ElementIDPROPNABOR_SNOM = {read = get_ElementIDPROPNABOR_SNOM , write = set_ElementIDPROPNABOR_SNOM};
   virtual TFIBLargeIntField * get_ElementIDPROPNABOR_SNOM(void)=0;
   virtual void set_ElementIDPROPNABOR_SNOM(TFIBLargeIntField * ElementIDPROPNABOR_SNOM)=0;

	  __property TFIBLargeIntField * ElementIDDEPARTMENT_SNOM = {read = get_ElementIDDEPARTMENT_SNOM , write = set_ElementIDDEPARTMENT_SNOM};
   virtual TFIBLargeIntField * get_ElementIDDEPARTMENT_SNOM(void)=0;
   virtual void set_ElementIDDEPARTMENT_SNOM(TFIBLargeIntField * ElementIDDEPARTMENT_SNOM)=0;




   __property TFIBWideStringField * ElementNAME_SDEPARTMENT = {read = get_ElementNAME_SDEPARTMENT , write = set_ElementNAME_SDEPARTMENT};
   virtual TFIBWideStringField * get_ElementNAME_SDEPARTMENT(void)=0;
   virtual void set_ElementNAME_SDEPARTMENT(TFIBWideStringField * ElementNAME_SDEPARTMENT)=0;

	  __property TFIBWideStringField * ElementNAME_SPROPNABOR = {read = get_ElementNAME_SPROPNABOR , write = set_ElementNAME_SPROPNABOR};
   virtual TFIBWideStringField * get_ElementNAME_SPROPNABOR(void)=0;
   virtual void set_ElementNAME_SPROPNABOR(TFIBWideStringField * ElementNAME_SPROPNABOR)=0;

	  __property TFIBWideStringField * ElementNAME_SVIDIMAGE_NABOR = {read = get_ElementNAME_SVIDIMAGE_NABOR , write = set_ElementNAME_SVIDIMAGE_NABOR};
   virtual TFIBWideStringField * get_ElementNAME_SVIDIMAGE_NABOR(void)=0;
   virtual void set_ElementNAME_SVIDIMAGE_NABOR(TFIBWideStringField * ElementNAME_SVIDIMAGE_NABOR)=0;



   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   __property __int64 IdTypePrice = {read = get_IdTypePrice , write = set_IdTypePrice};
   virtual __int64 get_IdTypePrice(void)=0;
   virtual void set_IdTypePrice(__int64 IdTypePrice)=0;

   __property __int64 IdFirm = {read = get_IdFirm , write = set_IdFirm};
   virtual __int64 get_IdFirm(void)=0;
   virtual void set_IdFirm(__int64 IdFirm)=0;

   __property __int64 IdSklad = {read = get_IdSklad , write = set_IdSklad};
   virtual __int64 get_IdSklad(void)=0;
   virtual void set_IdSklad(__int64 IdSklad)=0;

   __property __int64 IdInetCatalog = {read = get_IdInetCatalog , write = set_IdInetCatalog};
   virtual __int64 get_IdInetCatalog(void)=0;
   virtual void set_IdInetCatalog(__int64 IdInetCatalog)=0;

   __property int CheckOst = {read = get_CheckOst , write = set_CheckOst};
   virtual int get_CheckOst(void)=0;
   virtual void set_CheckOst(int CheckOst)=0;

   __property bool OnlyChange = {read = get_OnlyChange , write = set_OnlyChange};
   virtual bool get_OnlyChange(void)=0;
   virtual void set_OnlyChange(bool OnlyChange)=0;

   __property bool PriceSklad = {read = get_PriceSklad , write = set_PriceSklad};
   virtual bool get_PriceSklad(void)=0;
   virtual void set_PriceSklad(bool PriceSklad)=0;

   __property bool OnlyOstatok = {read = get_OnlyOstatok , write = set_OnlyOstatok};
   virtual bool get_OnlyOstatok(void)=0;
   virtual void set_OnlyOstatok(bool OnlyOstatok)=0;

   __property int PorNumberString = {read = get_PorNumberString , write = set_PorNumberString};
   virtual int get_PorNumberString(void)=0;
   virtual void set_PorNumberString(int PorNumberString)=0;

   virtual void OpenTable(__int64 Grp, bool All)=0;
   virtual int OpenElement(__int64 Id )=0;
   virtual bool NewElement(__int64 IdGrp)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 Id)=0;
   virtual void ChancheGrp(__int64 NewGrp,__int64 id_nom)=0;
   virtual __int64 FindPoCodu(int Code)=0;
   virtual __int64 FindPoShtrihCodu(AnsiString shtrih_cod)=0;
   virtual __int64 FindPoName(AnsiString name)=0;
   virtual __int64 FindPoArtikulu(UnicodeString artikul)=0;
   virtual int GetIndexTypePrice(void)=0;
   virtual __int64 GetIdBasEd(__int64 id_nom)=0;
   virtual __int64 GetIDElement(String gid)=0;
   virtual AnsiString GetGIDElement(__int64 id)=0;
   virtual __int64 GetIdGrpNom(__int64 id_nom)=0;
   virtual bool ClearFlagChange(void)=0;
   virtual bool DeleteNom(__int64 id_nom)=0;
   virtual int GetCodeNom(void)=0;
   virtual bool CheckCode(__int64 id_nom, int code)=0;
   virtual void OpenSpisokEd(__int64 id_nom)=0;
   virtual void OpenEd(void)=0;
   virtual void OpenBasEd(void)=0;
   virtual void OpenOsnEd(void)=0;
   virtual void OpenFisEd(void)=0;
};
#define IID_IDMSprNom __uuidof(IDMSprNom)
#endif
