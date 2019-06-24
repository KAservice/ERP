#include "vcl.h"
#pragma hdrstop


#include "UDMSprNomImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprNomImpl::TDMSprNomImpl()           
{                                            
Object=new TDMSprNom(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprNomImpl::~TDMSprNomImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprNomImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprNomImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
 {                                                                         
int result=0;                                                             
if (id_interface==IID_IkanUnknown)                                        
   {                                                                     
   *ppv=static_cast<IkanUnknown*> (this);                                 
   result=-1;                                                             
   }                                                                      
else if (id_interface==IID_IMainInterface)                        
   {                                                                     
   *ppv=static_cast<IMainInterface*> (this);                                
   result=-1;                                                            
   }  
else if (id_interface==IID_IDMSprNom)                        
   {                                                                     
   *ppv=static_cast<IDMSprNom*> (this);                                
   result=-1;                                                            
   }                                                                     
else                                                                     
   {                                                                     
   *ppv=NULL;                                                            
   result=1;                                                             
   return result;                                                        
   }                                                                     
kanAddRef();                       
return result;                                                           
}                                                                       
//---------------------------------------------------------------
int TDMSprNomImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprNomImpl::kanRelease(void)                                  
{                                                                      
if (--NumRefs==0)                                                     
   {                                                                  
   delete this;                                                       
   return 0;                                                       
   }                                                                  
return NumRefs;                                                       
}                                                                     
//---------------------------------------------------------------

//IMainInterface 
int  TDMSprNomImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprNomImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprNomImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprNomImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprNomImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprNomImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprNomImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprNom
TDataSource * TDMSprNomImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprNomImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNomImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNomImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprNomImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprNomImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNomImpl::get_BasEd(void)
{
return Object->BasEd;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_BasEd(TpFIBDataSet * BasEd)
{
Object->BasEd=BasEd;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNomImpl::get_OsnEd(void)
{
return Object->OsnEd;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_OsnEd(TpFIBDataSet * OsnEd)
{
Object->OsnEd=OsnEd;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_BasEdKFED(void)
{
return Object->BasEdKFED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_BasEdKFED(TFIBBCDField * BasEdKFED)
{
Object->BasEdKFED=BasEdKFED;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprNomImpl::get_BasEdTSHED(void)
{
return Object->BasEdTSHED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_BasEdTSHED(TFIBIntegerField * BasEdTSHED)
{
Object->BasEdTSHED=BasEdTSHED;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprNomImpl::get_BasEdNEISPED(void)
{
return Object->BasEdNEISPED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_BasEdNEISPED(TFIBSmallIntField * BasEdNEISPED)
{
Object->BasEdNEISPED=BasEdNEISPED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_OsnEdKFED(void)
{
return Object->OsnEdKFED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_OsnEdKFED(TFIBBCDField * OsnEdKFED)
{
Object->OsnEdKFED=OsnEdKFED;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprNomImpl::get_OsnEdTSHED(void)
{
return Object->OsnEdTSHED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_OsnEdTSHED(TFIBIntegerField * OsnEdTSHED)
{
Object->OsnEdTSHED=OsnEdTSHED;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprNomImpl::get_OsnEdNEISPED(void)
{
return Object->OsnEdNEISPED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_OsnEdNEISPED(TFIBSmallIntField * OsnEdNEISPED)
{
Object->OsnEdNEISPED=OsnEdNEISPED;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNomImpl::get_IBQSprGrpBV(void)
{
return Object->IBQSprGrpBV;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_IBQSprGrpBV(TpFIBDataSet * IBQSprGrpBV)
{
Object->IBQSprGrpBV=IBQSprGrpBV;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNomImpl::get_SpTPrice(void)
{
return Object->SpTPrice;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_SpTPrice(TpFIBDataSet * SpTPrice)
{
Object->SpTPrice=SpTPrice;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNomImpl::get_Code(void)
{
return Object->Code;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_Code(TpFIBDataSet * Code)
{
Object->Code=Code;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprNomImpl::get_CodeMAXCODE(void)
{
return Object->CodeMAXCODE;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_CodeMAXCODE(TFIBIntegerField * CodeMAXCODE)
{
Object->CodeMAXCODE=CodeMAXCODE;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprNomImpl::get_ElementTNOM(void)
{
return Object->ElementTNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementTNOM(TFIBIntegerField * ElementTNOM)
{
Object->ElementTNOM=ElementTNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprNomImpl::get_ElementCODENOM(void)
{
return Object->ElementCODENOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementCODENOM(TFIBIntegerField * ElementCODENOM)
{
Object->ElementCODENOM=ElementCODENOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprNomImpl::get_ElementSTNDSNOM(void)
{
return Object->ElementSTNDSNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementSTNDSNOM(TFIBIntegerField * ElementSTNDSNOM)
{
Object->ElementSTNDSNOM=ElementSTNDSNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_ElementZNACH_PRICE(void)
{
return Object->ElementZNACH_PRICE;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementZNACH_PRICE(TFIBBCDField * ElementZNACH_PRICE)
{
Object->ElementZNACH_PRICE=ElementZNACH_PRICE;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprNomImpl::get_pFIBQuery(void)
{
return Object->pFIBQuery;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_pFIBQuery(TpFIBQuery * pFIBQuery)
{
Object->pFIBQuery=pFIBQuery;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprNomImpl::get_pFIBTrUpdate(void)
{
return Object->pFIBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_pFIBTrUpdate(TpFIBTransaction * pFIBTrUpdate)
{
Object->pFIBTrUpdate=pFIBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprNomImpl::get_pFIBTr(void)
{
return Object->pFIBTr;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_pFIBTr(TpFIBTransaction * pFIBTr)
{
Object->pFIBTr=pFIBTr;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprNomImpl::get_ElementFL_CHANGE_NOM(void)
{
return Object->ElementFL_CHANGE_NOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementFL_CHANGE_NOM(TFIBSmallIntField * ElementFL_CHANGE_NOM)
{
Object->ElementFL_CHANGE_NOM=ElementFL_CHANGE_NOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_ElementMINOSTNOM(void)
{
return Object->ElementMINOSTNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementMINOSTNOM(TFIBBCDField * ElementMINOSTNOM)
{
Object->ElementMINOSTNOM=ElementMINOSTNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_BasEdIDED(void)
{
return Object->BasEdIDED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_BasEdIDED(TFIBBCDField * BasEdIDED)
{
Object->BasEdIDED=BasEdIDED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_BasEdIDNOMED(void)
{
return Object->BasEdIDNOMED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_BasEdIDNOMED(TFIBBCDField * BasEdIDNOMED)
{
Object->BasEdIDNOMED=BasEdIDNOMED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_BasEdIDOKEIED(void)
{
return Object->BasEdIDOKEIED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_BasEdIDOKEIED(TFIBBCDField * BasEdIDOKEIED)
{
Object->BasEdIDOKEIED=BasEdIDOKEIED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_OsnEdIDED(void)
{
return Object->OsnEdIDED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_OsnEdIDED(TFIBBCDField * OsnEdIDED)
{
Object->OsnEdIDED=OsnEdIDED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_OsnEdIDNOMED(void)
{
return Object->OsnEdIDNOMED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_OsnEdIDNOMED(TFIBBCDField * OsnEdIDNOMED)
{
Object->OsnEdIDNOMED=OsnEdIDNOMED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_OsnEdIDOKEIED(void)
{
return Object->OsnEdIDOKEIED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_OsnEdIDOKEIED(TFIBBCDField * OsnEdIDOKEIED)
{
Object->OsnEdIDOKEIED=OsnEdIDOKEIED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_SpTPriceID_TPRICE(void)
{
return Object->SpTPriceID_TPRICE;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_SpTPriceID_TPRICE(TFIBBCDField * SpTPriceID_TPRICE)
{
Object->SpTPriceID_TPRICE=SpTPriceID_TPRICE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_IBQSprGrpBVIDPOD_GBVNOM(void)
{
return Object->IBQSprGrpBVIDPOD_GBVNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_IBQSprGrpBVIDPOD_GBVNOM(TFIBBCDField * IBQSprGrpBVIDPOD_GBVNOM)
{
Object->IBQSprGrpBVIDPOD_GBVNOM=IBQSprGrpBVIDPOD_GBVNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_IBQSprGrpBVID_GBVNOM(void)
{
return Object->IBQSprGrpBVID_GBVNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_IBQSprGrpBVID_GBVNOM(TFIBBCDField * IBQSprGrpBVID_GBVNOM)
{
Object->IBQSprGrpBVID_GBVNOM=IBQSprGrpBVID_GBVNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_ElementSKIDKA1_SNOM(void)
{
return Object->ElementSKIDKA1_SNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementSKIDKA1_SNOM(TFIBBCDField * ElementSKIDKA1_SNOM)
{
Object->ElementSKIDKA1_SNOM=ElementSKIDKA1_SNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_ElementSKIDKA2_SNOM(void)
{
return Object->ElementSKIDKA2_SNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementSKIDKA2_SNOM(TFIBBCDField * ElementSKIDKA2_SNOM)
{
Object->ElementSKIDKA2_SNOM=ElementSKIDKA2_SNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_ElementSKIDKA3_SNOM(void)
{
return Object->ElementSKIDKA3_SNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementSKIDKA3_SNOM(TFIBBCDField * ElementSKIDKA3_SNOM)
{
Object->ElementSKIDKA3_SNOM=ElementSKIDKA3_SNOM;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprNomImpl::get_ElementTYPESRGODN_SNOM(void)
{
return Object->ElementTYPESRGODN_SNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementTYPESRGODN_SNOM(TFIBSmallIntField * ElementTYPESRGODN_SNOM)
{
Object->ElementTYPESRGODN_SNOM=ElementTYPESRGODN_SNOM;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprNomImpl::get_ElementSRGODN_SNOM(void)
{
return Object->ElementSRGODN_SNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementSRGODN_SNOM(TFIBSmallIntField * ElementSRGODN_SNOM)
{
Object->ElementSRGODN_SNOM=ElementSRGODN_SNOM;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNomImpl::get_SprScaleAndGrpVesNom(void)
{
return Object->SprScaleAndGrpVesNom;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_SprScaleAndGrpVesNom(TpFIBDataSet * SprScaleAndGrpVesNom)
{
Object->SprScaleAndGrpVesNom=SprScaleAndGrpVesNom;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_SprScaleAndGrpVesNomIDSCALE_SGRPVESNOM(void)
{
return Object->SprScaleAndGrpVesNomIDSCALE_SGRPVESNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_SprScaleAndGrpVesNomIDSCALE_SGRPVESNOM(TFIBBCDField * SprScaleAndGrpVesNomIDSCALE_SGRPVESNOM)
{
Object->SprScaleAndGrpVesNomIDSCALE_SGRPVESNOM=SprScaleAndGrpVesNomIDSCALE_SGRPVESNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_SprScaleAndGrpVesNomID_SGRPVESNOM(void)
{
return Object->SprScaleAndGrpVesNomID_SGRPVESNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_SprScaleAndGrpVesNomID_SGRPVESNOM(TFIBBCDField * SprScaleAndGrpVesNomID_SGRPVESNOM)
{
Object->SprScaleAndGrpVesNomID_SGRPVESNOM=SprScaleAndGrpVesNomID_SGRPVESNOM;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNomImpl::get_FisEd(void)
{
return Object->FisEd;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_FisEd(TpFIBDataSet * FisEd)
{
Object->FisEd=FisEd;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_FIBBCDField1(void)
{
return Object->FIBBCDField1;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_FIBBCDField1(TFIBBCDField * FIBBCDField1)
{
Object->FIBBCDField1=FIBBCDField1;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprNomImpl::get_FIBIntegerField1(void)
{
return Object->FIBIntegerField1;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_FIBIntegerField1(TFIBIntegerField * FIBIntegerField1)
{
Object->FIBIntegerField1=FIBIntegerField1;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprNomImpl::get_FIBSmallIntField1(void)
{
return Object->FIBSmallIntField1;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_FIBSmallIntField1(TFIBSmallIntField * FIBSmallIntField1)
{
Object->FIBSmallIntField1=FIBSmallIntField1;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_FIBBCDField2(void)
{
return Object->FIBBCDField2;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_FIBBCDField2(TFIBBCDField * FIBBCDField2)
{
Object->FIBBCDField2=FIBBCDField2;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_FIBBCDField3(void)
{
return Object->FIBBCDField3;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_FIBBCDField3(TFIBBCDField * FIBBCDField3)
{
Object->FIBBCDField3=FIBBCDField3;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_FIBBCDField4(void)
{
return Object->FIBBCDField4;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_FIBBCDField4(TFIBBCDField * FIBBCDField4)
{
Object->FIBBCDField4=FIBBCDField4;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNomImpl::get_SpisokEd(void)
{
return Object->SpisokEd;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_SpisokEd(TpFIBDataSet * SpisokEd)
{
Object->SpisokEd=SpisokEd;
}
//---------------------------------------------------------------
TDataSource * TDMSprNomImpl::get_DataSourceSpisokEd(void)
{
return Object->DataSourceSpisokEd;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_DataSourceSpisokEd(TDataSource * DataSourceSpisokEd)
{
Object->DataSourceSpisokEd=DataSourceSpisokEd;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_SpisokEdKFED(void)
{
return Object->SpisokEdKFED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_SpisokEdKFED(TFIBBCDField * SpisokEdKFED)
{
Object->SpisokEdKFED=SpisokEdKFED;
}
//---------------------------------------------------------------
TDataSource * TDMSprNomImpl::get_DataSourceBasEd(void)
{
return Object->DataSourceBasEd;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_DataSourceBasEd(TDataSource * DataSourceBasEd)
{
Object->DataSourceBasEd=DataSourceBasEd;
}
//---------------------------------------------------------------
TDataSource * TDMSprNomImpl::get_DataSourceOsnEd(void)
{
return Object->DataSourceOsnEd;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_DataSourceOsnEd(TDataSource * DataSourceOsnEd)
{
Object->DataSourceOsnEd=DataSourceOsnEd;
}
//---------------------------------------------------------------
TDataSource * TDMSprNomImpl::get_DataSourceFisEd(void)
{
return Object->DataSourceFisEd;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_DataSourceFisEd(TDataSource * DataSourceFisEd)
{
Object->DataSourceFisEd=DataSourceFisEd;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprNomImpl::get_BasEdCODE_SED(void)
{
return Object->BasEdCODE_SED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_BasEdCODE_SED(TFIBIntegerField * BasEdCODE_SED)
{
Object->BasEdCODE_SED=BasEdCODE_SED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_BasEdKF2_SED(void)
{
return Object->BasEdKF2_SED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_BasEdKF2_SED(TFIBBCDField * BasEdKF2_SED)
{
Object->BasEdKF2_SED=BasEdKF2_SED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_BasEdVES_SED(void)
{
return Object->BasEdVES_SED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_BasEdVES_SED(TFIBBCDField * BasEdVES_SED)
{
Object->BasEdVES_SED=BasEdVES_SED;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprNomImpl::get_OsnEdCODE_SED(void)
{
return Object->OsnEdCODE_SED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_OsnEdCODE_SED(TFIBIntegerField * OsnEdCODE_SED)
{
Object->OsnEdCODE_SED=OsnEdCODE_SED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_OsnEdKF2_SED(void)
{
return Object->OsnEdKF2_SED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_OsnEdKF2_SED(TFIBBCDField * OsnEdKF2_SED)
{
Object->OsnEdKF2_SED=OsnEdKF2_SED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_OsnEdVES_SED(void)
{
return Object->OsnEdVES_SED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_OsnEdVES_SED(TFIBBCDField * OsnEdVES_SED)
{
Object->OsnEdVES_SED=OsnEdVES_SED;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprNomImpl::get_FisEdCODE_SED(void)
{
return Object->FisEdCODE_SED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_FisEdCODE_SED(TFIBIntegerField * FisEdCODE_SED)
{
Object->FisEdCODE_SED=FisEdCODE_SED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_FisEdKF2_SED(void)
{
return Object->FisEdKF2_SED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_FisEdKF2_SED(TFIBBCDField * FisEdKF2_SED)
{
Object->FisEdKF2_SED=FisEdKF2_SED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_FisEdVES_SED(void)
{
return Object->FisEdVES_SED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_FisEdVES_SED(TFIBBCDField * FisEdVES_SED)
{
Object->FisEdVES_SED=FisEdVES_SED;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMSprNomImpl::get_ElementGODEN_DO_SNOM(void)
{
return Object->ElementGODEN_DO_SNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementGODEN_DO_SNOM(TFIBDateTimeField * ElementGODEN_DO_SNOM)
{
Object->ElementGODEN_DO_SNOM=ElementGODEN_DO_SNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprNomImpl::get_ElementWARRANTY_SNOM(void)
{
return Object->ElementWARRANTY_SNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementWARRANTY_SNOM(TFIBIntegerField * ElementWARRANTY_SNOM)
{
Object->ElementWARRANTY_SNOM=ElementWARRANTY_SNOM;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprNomImpl::get_ElementFL_CREDIT_SNOM(void)
{
return Object->ElementFL_CREDIT_SNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementFL_CREDIT_SNOM(TFIBSmallIntField * ElementFL_CREDIT_SNOM)
{
Object->ElementFL_CREDIT_SNOM=ElementFL_CREDIT_SNOM;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprNomImpl::get_ElementFL_TRANSPORT_SNOM(void)
{
return Object->ElementFL_TRANSPORT_SNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementFL_TRANSPORT_SNOM(TFIBSmallIntField * ElementFL_TRANSPORT_SNOM)
{
Object->ElementFL_TRANSPORT_SNOM=ElementFL_TRANSPORT_SNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomImpl::get_SpisokEdIDED(void)
{
return Object->SpisokEdIDED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_SpisokEdIDED(TFIBLargeIntField * SpisokEdIDED)
{
Object->SpisokEdIDED=SpisokEdIDED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_ElementPOGR_SNOM(void)
{
return Object->ElementPOGR_SNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementPOGR_SNOM(TFIBBCDField * ElementPOGR_SNOM)
{
Object->ElementPOGR_SNOM=ElementPOGR_SNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomImpl::get_ElementIDNOM(void)
{
return Object->ElementIDNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementIDNOM(TFIBLargeIntField * ElementIDNOM)
{
Object->ElementIDNOM=ElementIDNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomImpl::get_ElementIDBASEDNOM(void)
{
return Object->ElementIDBASEDNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementIDBASEDNOM(TFIBLargeIntField * ElementIDBASEDNOM)
{
Object->ElementIDBASEDNOM=ElementIDBASEDNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomImpl::get_ElementIDOSNEDNOM(void)
{
return Object->ElementIDOSNEDNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementIDOSNEDNOM(TFIBLargeIntField * ElementIDOSNEDNOM)
{
Object->ElementIDOSNEDNOM=ElementIDOSNEDNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomImpl::get_ElementIDFISED_SNOM(void)
{
return Object->ElementIDFISED_SNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementIDFISED_SNOM(TFIBLargeIntField * ElementIDFISED_SNOM)
{
Object->ElementIDFISED_SNOM=ElementIDFISED_SNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomImpl::get_ElementIDGRPNOM(void)
{
return Object->ElementIDGRPNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementIDGRPNOM(TFIBLargeIntField * ElementIDGRPNOM)
{
Object->ElementIDGRPNOM=ElementIDGRPNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomImpl::get_ElementIDFIRMNOM(void)
{
return Object->ElementIDFIRMNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementIDFIRMNOM(TFIBLargeIntField * ElementIDFIRMNOM)
{
Object->ElementIDFIRMNOM=ElementIDFIRMNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomImpl::get_ElementIDCOUNTRYNOM(void)
{
return Object->ElementIDCOUNTRYNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementIDCOUNTRYNOM(TFIBLargeIntField * ElementIDCOUNTRYNOM)
{
Object->ElementIDCOUNTRYNOM=ElementIDCOUNTRYNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomImpl::get_ElementIDVID_SNOM(void)
{
return Object->ElementIDVID_SNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementIDVID_SNOM(TFIBLargeIntField * ElementIDVID_SNOM)
{
Object->ElementIDVID_SNOM=ElementIDVID_SNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomImpl::get_ElementIDSUPPLIER_SNOM(void)
{
return Object->ElementIDSUPPLIER_SNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementIDSUPPLIER_SNOM(TFIBLargeIntField * ElementIDSUPPLIER_SNOM)
{
Object->ElementIDSUPPLIER_SNOM=ElementIDSUPPLIER_SNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomImpl::get_ElementIDPRODUCER_SNOM(void)
{
return Object->ElementIDPRODUCER_SNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementIDPRODUCER_SNOM(TFIBLargeIntField * ElementIDPRODUCER_SNOM)
{
Object->ElementIDPRODUCER_SNOM=ElementIDPRODUCER_SNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomImpl::get_ElementIDBRAND_SNOM(void)
{
return Object->ElementIDBRAND_SNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementIDBRAND_SNOM(TFIBLargeIntField * ElementIDBRAND_SNOM)
{
Object->ElementIDBRAND_SNOM=ElementIDBRAND_SNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_ElementNAMENOM(void)
{
return Object->ElementNAMENOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementNAMENOM(TFIBWideStringField * ElementNAMENOM)
{
Object->ElementNAMENOM=ElementNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_ElementFNAMENOM(void)
{
return Object->ElementFNAMENOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementFNAMENOM(TFIBWideStringField * ElementFNAMENOM)
{
Object->ElementFNAMENOM=ElementFNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_ElementKRNAMENOM(void)
{
return Object->ElementKRNAMENOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementKRNAMENOM(TFIBWideStringField * ElementKRNAMENOM)
{
Object->ElementKRNAMENOM=ElementKRNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_ElementARTNOM(void)
{
return Object->ElementARTNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementARTNOM(TFIBWideStringField * ElementARTNOM)
{
Object->ElementARTNOM=ElementARTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_ElementDESCR_SNOM(void)
{
return Object->ElementDESCR_SNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementDESCR_SNOM(TFIBWideStringField * ElementDESCR_SNOM)
{
Object->ElementDESCR_SNOM=ElementDESCR_SNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_ElementGTDNOM(void)
{
return Object->ElementGTDNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementGTDNOM(TFIBWideStringField * ElementGTDNOM)
{
Object->ElementGTDNOM=ElementGTDNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomImpl::get_ElementIDBASE_SNOM(void)
{
return Object->ElementIDBASE_SNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementIDBASE_SNOM(TFIBLargeIntField * ElementIDBASE_SNOM)
{
Object->ElementIDBASE_SNOM=ElementIDBASE_SNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomImpl::get_ElementIDEXT_DOUT_SNOM(void)
{
return Object->ElementIDEXT_DOUT_SNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementIDEXT_DOUT_SNOM(TFIBLargeIntField * ElementIDEXT_DOUT_SNOM)
{
Object->ElementIDEXT_DOUT_SNOM=ElementIDEXT_DOUT_SNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomImpl::get_ElementIDEXT_BASE_SNOM(void)
{
return Object->ElementIDEXT_BASE_SNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementIDEXT_BASE_SNOM(TFIBLargeIntField * ElementIDEXT_BASE_SNOM)
{
Object->ElementIDEXT_BASE_SNOM=ElementIDEXT_BASE_SNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_ElementNAMEFIRM(void)
{
return Object->ElementNAMEFIRM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementNAMEFIRM(TFIBWideStringField * ElementNAMEFIRM)
{
Object->ElementNAMEFIRM=ElementNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_ElementNAME_SCOUNTRY(void)
{
return Object->ElementNAME_SCOUNTRY;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementNAME_SCOUNTRY(TFIBWideStringField * ElementNAME_SCOUNTRY)
{
Object->ElementNAME_SCOUNTRY=ElementNAME_SCOUNTRY;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_ElementNAME_SVIDNOM(void)
{
return Object->ElementNAME_SVIDNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementNAME_SVIDNOM(TFIBWideStringField * ElementNAME_SVIDNOM)
{
Object->ElementNAME_SVIDNOM=ElementNAME_SVIDNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_ElementSUPPLIER_NAME(void)
{
return Object->ElementSUPPLIER_NAME;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementSUPPLIER_NAME(TFIBWideStringField * ElementSUPPLIER_NAME)
{
Object->ElementSUPPLIER_NAME=ElementSUPPLIER_NAME;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_ElementPRODUCER_NAME(void)
{
return Object->ElementPRODUCER_NAME;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementPRODUCER_NAME(TFIBWideStringField * ElementPRODUCER_NAME)
{
Object->ElementPRODUCER_NAME=ElementPRODUCER_NAME;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_ElementNAME_SBRAND(void)
{
return Object->ElementNAME_SBRAND;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementNAME_SBRAND(TFIBWideStringField * ElementNAME_SBRAND)
{
Object->ElementNAME_SBRAND=ElementNAME_SBRAND;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_SpTPriceNAME_TPRICE(void)
{
return Object->SpTPriceNAME_TPRICE;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_SpTPriceNAME_TPRICE(TFIBWideStringField * SpTPriceNAME_TPRICE)
{
Object->SpTPriceNAME_TPRICE=SpTPriceNAME_TPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_IBQSprGrpBVNAMEPOD(void)
{
return Object->IBQSprGrpBVNAMEPOD;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_IBQSprGrpBVNAMEPOD(TFIBWideStringField * IBQSprGrpBVNAMEPOD)
{
Object->IBQSprGrpBVNAMEPOD=IBQSprGrpBVNAMEPOD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_IBQSprGrpBVNAME_GBVNOM(void)
{
return Object->IBQSprGrpBVNAME_GBVNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_IBQSprGrpBVNAME_GBVNOM(TFIBWideStringField * IBQSprGrpBVNAME_GBVNOM)
{
Object->IBQSprGrpBVNAME_GBVNOM=IBQSprGrpBVNAME_GBVNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_SprScaleAndGrpVesNomNAME_SSCALE(void)
{
return Object->SprScaleAndGrpVesNomNAME_SSCALE;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_SprScaleAndGrpVesNomNAME_SSCALE(TFIBWideStringField * SprScaleAndGrpVesNomNAME_SSCALE)
{
Object->SprScaleAndGrpVesNomNAME_SSCALE=SprScaleAndGrpVesNomNAME_SSCALE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_SprScaleAndGrpVesNomNAME_SGRPVESNOM(void)
{
return Object->SprScaleAndGrpVesNomNAME_SGRPVESNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_SprScaleAndGrpVesNomNAME_SGRPVESNOM(TFIBWideStringField * SprScaleAndGrpVesNomNAME_SGRPVESNOM)
{
Object->SprScaleAndGrpVesNomNAME_SGRPVESNOM=SprScaleAndGrpVesNomNAME_SGRPVESNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_BasEdNAMEED(void)
{
return Object->BasEdNAMEED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_BasEdNAMEED(TFIBWideStringField * BasEdNAMEED)
{
Object->BasEdNAMEED=BasEdNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_BasEdSHED(void)
{
return Object->BasEdSHED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_BasEdSHED(TFIBWideStringField * BasEdSHED)
{
Object->BasEdSHED=BasEdSHED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_OsnEdNAMEED(void)
{
return Object->OsnEdNAMEED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_OsnEdNAMEED(TFIBWideStringField * OsnEdNAMEED)
{
Object->OsnEdNAMEED=OsnEdNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_OsnEdSHED(void)
{
return Object->OsnEdSHED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_OsnEdSHED(TFIBWideStringField * OsnEdSHED)
{
Object->OsnEdSHED=OsnEdSHED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_FisEdNAMEED(void)
{
return Object->FisEdNAMEED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_FisEdNAMEED(TFIBWideStringField * FisEdNAMEED)
{
Object->FisEdNAMEED=FisEdNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_FisEdSHED(void)
{
return Object->FisEdSHED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_FisEdSHED(TFIBWideStringField * FisEdSHED)
{
Object->FisEdSHED=FisEdSHED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_SpisokEdNAMEED(void)
{
return Object->SpisokEdNAMEED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_SpisokEdNAMEED(TFIBWideStringField * SpisokEdNAMEED)
{
Object->SpisokEdNAMEED=SpisokEdNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_ElementGID_SNOM(void)
{
return Object->ElementGID_SNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementGID_SNOM(TFIBWideStringField * ElementGID_SNOM)
{
Object->ElementGID_SNOM=ElementGID_SNOM;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprNomImpl::get_ElementFL_ADD_IN_SOBORUD_SNOM(void)
{
return Object->ElementFL_ADD_IN_SOBORUD_SNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementFL_ADD_IN_SOBORUD_SNOM(TFIBSmallIntField * ElementFL_ADD_IN_SOBORUD_SNOM)
{
Object->ElementFL_ADD_IN_SOBORUD_SNOM=ElementFL_ADD_IN_SOBORUD_SNOM;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprNomImpl::get_ElementFL_DVREG_SNOM(void)
{
return Object->ElementFL_DVREG_SNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementFL_DVREG_SNOM(TFIBSmallIntField * ElementFL_DVREG_SNOM)
{
Object->ElementFL_DVREG_SNOM=ElementFL_DVREG_SNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomImpl::get_TableIDNOM(void)
{
return Object->TableIDNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_TableIDNOM(TFIBLargeIntField * TableIDNOM)
{
Object->TableIDNOM=TableIDNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_TableARTNOM(void)
{
return Object->TableARTNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_TableARTNOM(TFIBWideStringField * TableARTNOM)
{
Object->TableARTNOM=TableARTNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprNomImpl::get_TableCODENOM(void)
{
return Object->TableCODENOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_TableCODENOM(TFIBIntegerField * TableCODENOM)
{
Object->TableCODENOM=TableCODENOM;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprNomImpl::get_TableTNOM(void)
{
return Object->TableTNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_TableTNOM(TFIBSmallIntField * TableTNOM)
{
Object->TableTNOM=TableTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_TableNAMENOM(void)
{
return Object->TableNAMENOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_TableNAMENOM(TFIBWideStringField * TableNAMENOM)
{
Object->TableNAMENOM=TableNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_TableNAMEED(void)
{
return Object->TableNAMEED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_TableNAMEED(TFIBWideStringField * TableNAMEED)
{
Object->TableNAMEED=TableNAMEED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_TableZNACH_PRICE(void)
{
return Object->TableZNACH_PRICE;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_TableZNACH_PRICE(TFIBBCDField * TableZNACH_PRICE)
{
Object->TableZNACH_PRICE=TableZNACH_PRICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomImpl::get_TableIDGRPNOM(void)
{
return Object->TableIDGRPNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_TableIDGRPNOM(TFIBLargeIntField * TableIDGRPNOM)
{
Object->TableIDGRPNOM=TableIDGRPNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomImpl::get_TableID_SNOMINETCAT(void)
{
return Object->TableID_SNOMINETCAT;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_TableID_SNOMINETCAT(TFIBLargeIntField * TableID_SNOMINETCAT)
{
Object->TableID_SNOMINETCAT=TableID_SNOMINETCAT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_TableSUMKOL(void)
{
return Object->TableSUMKOL;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_TableSUMKOL(TFIBBCDField * TableSUMKOL)
{
Object->TableSUMKOL=TableSUMKOL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_TableSHED(void)
{
return Object->TableSHED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_TableSHED(TFIBWideStringField * TableSHED)
{
Object->TableSHED=TableSHED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_TableREM_OST(void)
{
return Object->TableREM_OST;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_TableREM_OST(TFIBBCDField * TableREM_OST)
{
Object->TableREM_OST=TableREM_OST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomImpl::get_TableIDFIRM(void)
{
return Object->TableIDFIRM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_TableIDFIRM(TFIBLargeIntField * TableIDFIRM)
{
Object->TableIDFIRM=TableIDFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_TableNAMEFIRM(void)
{
return Object->TableNAMEFIRM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM)
{
Object->TableNAMEFIRM=TableNAMEFIRM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomImpl::get_TableIDSKLAD(void)
{
return Object->TableIDSKLAD;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_TableIDSKLAD(TFIBLargeIntField * TableIDSKLAD)
{
Object->TableIDSKLAD=TableIDSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_TableNAMESKLAD(void)
{
return Object->TableNAMESKLAD;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)
{
Object->TableNAMESKLAD=TableNAMESKLAD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomImpl::get_TableIDTNOM(void)
{
return Object->TableIDTNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_TableIDTNOM(TFIBLargeIntField * TableIDTNOM)
{
Object->TableIDTNOM=TableIDTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_TableNAME_STNOM(void)
{
return Object->TableNAME_STNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_TableNAME_STNOM(TFIBWideStringField * TableNAME_STNOM)
{
Object->TableNAME_STNOM=TableNAME_STNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomImpl::get_TableIDED(void)
{
return Object->TableIDED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_TableIDED(TFIBLargeIntField * TableIDED)
{
Object->TableIDED=TableIDED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_TableOUT_PRICE_SKLAD(void)
{
return Object->TableOUT_PRICE_SKLAD;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_TableOUT_PRICE_SKLAD(TFIBBCDField * TableOUT_PRICE_SKLAD)
{
Object->TableOUT_PRICE_SKLAD=TableOUT_PRICE_SKLAD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_TableOUT_KFED(void)
{
return Object->TableOUT_KFED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_TableOUT_KFED(TFIBBCDField * TableOUT_KFED)
{
Object->TableOUT_KFED=TableOUT_KFED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomImpl::get_TableOUT_KF2ED(void)
{
return Object->TableOUT_KF2ED;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_TableOUT_KF2ED(TFIBBCDField * TableOUT_KF2ED)
{
Object->TableOUT_KF2ED=TableOUT_KF2ED;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomImpl::get_TableOUT_IDMHRAN(void)
{
return Object->TableOUT_IDMHRAN;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_TableOUT_IDMHRAN(TFIBLargeIntField * TableOUT_IDMHRAN)
{
Object->TableOUT_IDMHRAN=TableOUT_IDMHRAN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_TableOUT_NAME_MHRAN(void)
{
return Object->TableOUT_NAME_MHRAN;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_TableOUT_NAME_MHRAN(TFIBWideStringField * TableOUT_NAME_MHRAN)
{
Object->TableOUT_NAME_MHRAN=TableOUT_NAME_MHRAN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomImpl::get_TableOUT_IDMHRAN_REM(void)
{
return Object->TableOUT_IDMHRAN_REM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_TableOUT_IDMHRAN_REM(TFIBLargeIntField * TableOUT_IDMHRAN_REM)
{
Object->TableOUT_IDMHRAN_REM=TableOUT_IDMHRAN_REM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImpl::get_TableOUT_NAME_MHRAN_REM(void)
{
return Object->TableOUT_NAME_MHRAN_REM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_TableOUT_NAME_MHRAN_REM(TFIBWideStringField * TableOUT_NAME_MHRAN_REM)
{
Object->TableOUT_NAME_MHRAN_REM=TableOUT_NAME_MHRAN_REM;
}
//---------------------------------------------------------------



TFIBLargeIntField * TDMSprNomImpl::get_ElementIDVIDIMAGENABOR_SNOM(void)
{
return Object->ElementIDVIDIMAGENABOR_SNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementIDVIDIMAGENABOR_SNOM(TFIBLargeIntField * ElementIDVIDIMAGENABOR_SNOM)
{
Object->ElementIDVIDIMAGENABOR_SNOM=ElementIDVIDIMAGENABOR_SNOM;
}
//---------------------------------------------------------------

TFIBLargeIntField * TDMSprNomImpl::get_ElementIDPROPNABOR_SNOM(void)
{
return Object->ElementIDPROPNABOR_SNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementIDPROPNABOR_SNOM(TFIBLargeIntField * ElementIDPROPNABOR_SNOM)
{
Object->ElementIDPROPNABOR_SNOM=ElementIDPROPNABOR_SNOM;
}
//---------------------------------------------------------------

TFIBLargeIntField * TDMSprNomImpl::get_ElementIDDEPARTMENT_SNOM(void)
{
return Object->ElementIDDEPARTMENT_SNOM;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementIDDEPARTMENT_SNOM(TFIBLargeIntField * ElementIDDEPARTMENT_SNOM)
{
Object->ElementIDDEPARTMENT_SNOM=ElementIDDEPARTMENT_SNOM;
}
//---------------------------------------------------------------



TFIBWideStringField * TDMSprNomImpl::get_ElementNAME_SDEPARTMENT(void)
{
return Object->ElementNAME_SDEPARTMENT;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementNAME_SDEPARTMENT(TFIBWideStringField * ElementNAME_SDEPARTMENT)
{
Object->ElementNAME_SDEPARTMENT=ElementNAME_SDEPARTMENT;
}
//---------------------------------------------------------------

TFIBWideStringField * TDMSprNomImpl::get_ElementNAME_SPROPNABOR(void)
{
return Object->ElementNAME_SPROPNABOR;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementNAME_SPROPNABOR(TFIBWideStringField * ElementNAME_SPROPNABOR)
{
Object->ElementNAME_SPROPNABOR=ElementNAME_SPROPNABOR;
}
//---------------------------------------------------------------

TFIBWideStringField * TDMSprNomImpl::get_ElementNAME_SVIDIMAGE_NABOR(void)
{
return Object->ElementNAME_SVIDIMAGE_NABOR;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_ElementNAME_SVIDIMAGE_NABOR(TFIBWideStringField * ElementNAME_SVIDIMAGE_NABOR)
{
Object->ElementNAME_SVIDIMAGE_NABOR=ElementNAME_SVIDIMAGE_NABOR;
}
//---------------------------------------------------------------


__int64 TDMSprNomImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TDMSprNomImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
__int64 TDMSprNomImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
__int64 TDMSprNomImpl::get_IdTypePrice(void)
{
return Object->IdTypePrice;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_IdTypePrice(__int64 IdTypePrice)
{
Object->IdTypePrice=IdTypePrice;
}
//---------------------------------------------------------------
__int64 TDMSprNomImpl::get_IdFirm(void)
{
return Object->IdFirm;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_IdFirm(__int64 IdFirm)
{
Object->IdFirm=IdFirm;
}
//---------------------------------------------------------------
__int64 TDMSprNomImpl::get_IdSklad(void)
{
return Object->IdSklad;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_IdSklad(__int64 IdSklad)
{
Object->IdSklad=IdSklad;
}
//---------------------------------------------------------------
__int64 TDMSprNomImpl::get_IdInetCatalog(void)
{
return Object->IdInetCatalog;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_IdInetCatalog(__int64 IdInetCatalog)
{
Object->IdInetCatalog=IdInetCatalog;
}
//---------------------------------------------------------------
int TDMSprNomImpl::get_CheckOst(void)
{
return Object->CheckOst;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_CheckOst(int CheckOst)
{
Object->CheckOst=CheckOst;
}
//---------------------------------------------------------------
bool TDMSprNomImpl::get_OnlyChange(void)
{
return Object->OnlyChange;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_OnlyChange(bool OnlyChange)
{
Object->OnlyChange=OnlyChange;
}
//---------------------------------------------------------------
bool TDMSprNomImpl::get_PriceSklad(void)
{
return Object->PriceSklad;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_PriceSklad(bool PriceSklad)
{
Object->PriceSklad=PriceSklad;
}
//---------------------------------------------------------------
bool TDMSprNomImpl::get_OnlyOstatok(void)
{
return Object->OnlyOstatok;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_OnlyOstatok(bool OnlyOstatok)
{
Object->OnlyOstatok=OnlyOstatok;
}
//---------------------------------------------------------------
int TDMSprNomImpl::get_PorNumberString(void)
{
return Object->PorNumberString;
}
//---------------------------------------------------------------
void TDMSprNomImpl::set_PorNumberString(int PorNumberString)
{
Object->PorNumberString=PorNumberString;
}
//---------------------------------------------------------------
void TDMSprNomImpl::OpenTable(__int64 Grp, bool All)
{
return Object->OpenTable(Grp,All);
}
//---------------------------------------------------------------
int TDMSprNomImpl::OpenElement(__int64 Id )
{
return Object->OpenElement(Id );
}
//---------------------------------------------------------------
bool TDMSprNomImpl::NewElement(__int64 IdGrp)
{
return Object->NewElement(IdGrp);
}
//---------------------------------------------------------------
bool TDMSprNomImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprNomImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
void TDMSprNomImpl::ChancheGrp(__int64 NewGrp,__int64 id_nom)
{
return Object->ChancheGrp(NewGrp,id_nom);
}
//---------------------------------------------------------------
__int64 TDMSprNomImpl::FindPoCodu(int Code)
{
return Object->FindPoCodu(Code);
}
//---------------------------------------------------------------
__int64 TDMSprNomImpl::FindPoShtrihCodu(AnsiString shtrih_cod)
{
return Object->FindPoShtrihCodu(shtrih_cod);
}
//---------------------------------------------------------------
__int64 TDMSprNomImpl::FindPoName(AnsiString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
__int64 TDMSprNomImpl::FindPoArtikulu(UnicodeString artikul)
{
return Object->FindPoArtikulu(artikul);
}
//---------------------------------------------------------------
int TDMSprNomImpl::GetIndexTypePrice(void)
{
return Object->GetIndexTypePrice();
}
//---------------------------------------------------------------
__int64 TDMSprNomImpl::GetIdBasEd(__int64 id_nom)
{
return Object->GetIdBasEd(id_nom);
}
//---------------------------------------------------------------
__int64 TDMSprNomImpl::GetIDElement(String gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
AnsiString TDMSprNomImpl::GetGIDElement(__int64 id)
{
return Object->GetGIDElement(id);
}
//---------------------------------------------------------------
__int64 TDMSprNomImpl::GetIdGrpNom(__int64 id_nom)
{
return Object->GetIdGrpNom( id_nom);
}
//---------------------------------------------------------------
bool TDMSprNomImpl::ClearFlagChange(void)
{
return Object->ClearFlagChange();
}
//---------------------------------------------------------------
bool TDMSprNomImpl::DeleteNom(__int64 id_nom)
{
return Object->DeleteNom(id_nom);
}
//---------------------------------------------------------------
int TDMSprNomImpl::GetCodeNom(void)
{
return Object->GetCodeNom();
}
//---------------------------------------------------------------
bool TDMSprNomImpl::CheckCode(__int64 id_nom, int code)
{
return Object->CheckCode(id_nom, code);
}
//---------------------------------------------------------------
void TDMSprNomImpl::OpenSpisokEd(__int64 id_nom)
{
return Object->OpenSpisokEd(id_nom);
}
//---------------------------------------------------------------
void TDMSprNomImpl::OpenEd(void)
{
return Object->OpenEd();
}
//---------------------------------------------------------------
void TDMSprNomImpl::OpenBasEd(void)
{
return Object->OpenBasEd();
}
//---------------------------------------------------------------
void TDMSprNomImpl::OpenOsnEd(void)
{
return Object->OpenOsnEd();
}
//---------------------------------------------------------------
void TDMSprNomImpl::OpenFisEd(void)
{
return Object->OpenFisEd();
}
//---------------------------------------------------------------
