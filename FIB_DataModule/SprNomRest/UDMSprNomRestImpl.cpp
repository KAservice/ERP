#include "vcl.h"
#pragma hdrstop


#include "UDMSprNomRestImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprNomRestImpl::TDMSprNomRestImpl()           
{                                            
Object=new TDMSprNomRest(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprNomRestImpl::~TDMSprNomRestImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprNomRestImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprNomRestImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprNomRest)                        
   {                                                                     
   *ppv=static_cast<IDMSprNomRest*> (this);                                
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
int TDMSprNomRestImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprNomRestImpl::kanRelease(void)                                  
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
int  TDMSprNomRestImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprNomRestImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprNomRestImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprNomRestImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprNomRestImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprNomRest
TDataSource * TDMSprNomRestImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TDataSource * TDMSprNomRestImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNomRestImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNomRestImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprNomRestImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprNomRestImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMSprNomRestImpl::get_TablePOS_NOMREST(void)
{
return Object->TablePOS_NOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_TablePOS_NOMREST(TFIBDateTimeField * TablePOS_NOMREST)
{
Object->TablePOS_NOMREST=TablePOS_NOMREST;
}
//---------------------------------------------------------------
TIntegerField * TDMSprNomRestImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNomRestImpl::get_IBQ(void)
{
return Object->IBQ;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_IBQ(TpFIBDataSet * IBQ)
{
Object->IBQ=IBQ;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomRestImpl::get_IBQNKOL_SPROD(void)
{
return Object->IBQNKOL_SPROD;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_IBQNKOL_SPROD(TFIBBCDField * IBQNKOL_SPROD)
{
Object->IBQNKOL_SPROD=IBQNKOL_SPROD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomRestImpl::get_IBQBKOL_SPROD(void)
{
return Object->IBQBKOL_SPROD;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_IBQBKOL_SPROD(TFIBBCDField * IBQBKOL_SPROD)
{
Object->IBQBKOL_SPROD=IBQBKOL_SPROD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomRestImpl::get_IBQKFPRICE_SPROD(void)
{
return Object->IBQKFPRICE_SPROD;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_IBQKFPRICE_SPROD(TFIBBCDField * IBQKFPRICE_SPROD)
{
Object->IBQKFPRICE_SPROD=IBQKFPRICE_SPROD;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprNomRestImpl::get_IBQSPIS_SPROD(void)
{
return Object->IBQSPIS_SPROD;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_IBQSPIS_SPROD(TFIBSmallIntField * IBQSPIS_SPROD)
{
Object->IBQSPIS_SPROD=IBQSPIS_SPROD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomRestImpl::get_IBQVALUE_SSEZKF(void)
{
return Object->IBQVALUE_SSEZKF;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_IBQVALUE_SSEZKF(TFIBBCDField * IBQVALUE_SSEZKF)
{
Object->IBQVALUE_SSEZKF=IBQVALUE_SSEZKF;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomRestImpl::get_IBQVALUE_SSEZKF_SPROD(void)
{
return Object->IBQVALUE_SSEZKF_SPROD;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_IBQVALUE_SSEZKF_SPROD(TFIBBCDField * IBQVALUE_SSEZKF_SPROD)
{
Object->IBQVALUE_SSEZKF_SPROD=IBQVALUE_SSEZKF_SPROD;
}
//---------------------------------------------------------------
TFloatField * TDMSprNomRestImpl::get_IBQSEZKF_SPROD(void)
{
return Object->IBQSEZKF_SPROD;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_IBQSEZKF_SPROD(TFloatField * IBQSEZKF_SPROD)
{
Object->IBQSEZKF_SPROD=IBQSEZKF_SPROD;
}
//---------------------------------------------------------------
TFloatField * TDMSprNomRestImpl::get_IBQSEZKF(void)
{
return Object->IBQSEZKF;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_IBQSEZKF(TFloatField * IBQSEZKF)
{
Object->IBQSEZKF=IBQSEZKF;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomRestImpl::get_TableID_NOMREST(void)
{
return Object->TableID_NOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_TableID_NOMREST(TFIBBCDField * TableID_NOMREST)
{
Object->TableID_NOMREST=TableID_NOMREST;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomRestImpl::get_TableIDNOM_NOMREST(void)
{
return Object->TableIDNOM_NOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_TableIDNOM_NOMREST(TFIBBCDField * TableIDNOM_NOMREST)
{
Object->TableIDNOM_NOMREST=TableIDNOM_NOMREST;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomRestImpl::get_IBQID_SPROD(void)
{
return Object->IBQID_SPROD;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_IBQID_SPROD(TFIBBCDField * IBQID_SPROD)
{
Object->IBQID_SPROD=IBQID_SPROD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomRestImpl::get_IBQIDKOMPL_SPROD(void)
{
return Object->IBQIDKOMPL_SPROD;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_IBQIDKOMPL_SPROD(TFIBBCDField * IBQIDKOMPL_SPROD)
{
Object->IBQIDKOMPL_SPROD=IBQIDKOMPL_SPROD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomRestImpl::get_TableNAME_NOMREST(void)
{
return Object->TableNAME_NOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_TableNAME_NOMREST(TFIBWideStringField * TableNAME_NOMREST)
{
Object->TableNAME_NOMREST=TableNAME_NOMREST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomRestImpl::get_IBQNAMENOM(void)
{
return Object->IBQNAMENOM;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_IBQNAMENOM(TFIBWideStringField * IBQNAMENOM)
{
Object->IBQNAMENOM=IBQNAMENOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomRestImpl::get_ElementID_NOMREST(void)
{
return Object->ElementID_NOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementID_NOMREST(TFIBBCDField * ElementID_NOMREST)
{
Object->ElementID_NOMREST=ElementID_NOMREST;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomRestImpl::get_ElementIDNOM_NOMREST(void)
{
return Object->ElementIDNOM_NOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementIDNOM_NOMREST(TFIBBCDField * ElementIDNOM_NOMREST)
{
Object->ElementIDNOM_NOMREST=ElementIDNOM_NOMREST;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomRestImpl::get_ElementIDMPRIG_NOMREST(void)
{
return Object->ElementIDMPRIG_NOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementIDMPRIG_NOMREST(TFIBBCDField * ElementIDMPRIG_NOMREST)
{
Object->ElementIDMPRIG_NOMREST=ElementIDMPRIG_NOMREST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomRestImpl::get_ElementSOST_NOMREST(void)
{
return Object->ElementSOST_NOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementSOST_NOMREST(TFIBWideStringField * ElementSOST_NOMREST)
{
Object->ElementSOST_NOMREST=ElementSOST_NOMREST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomRestImpl::get_ElementTEHN_NOMREST(void)
{
return Object->ElementTEHN_NOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementTEHN_NOMREST(TFIBWideStringField * ElementTEHN_NOMREST)
{
Object->ElementTEHN_NOMREST=ElementTEHN_NOMREST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomRestImpl::get_ElementVIH_NOMREST(void)
{
return Object->ElementVIH_NOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementVIH_NOMREST(TFIBWideStringField * ElementVIH_NOMREST)
{
Object->ElementVIH_NOMREST=ElementVIH_NOMREST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomRestImpl::get_ElementSROK_NOMREST(void)
{
return Object->ElementSROK_NOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementSROK_NOMREST(TFIBWideStringField * ElementSROK_NOMREST)
{
Object->ElementSROK_NOMREST=ElementSROK_NOMREST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomRestImpl::get_ElementNOMER_NOMREST(void)
{
return Object->ElementNOMER_NOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementNOMER_NOMREST(TFIBWideStringField * ElementNOMER_NOMREST)
{
Object->ElementNOMER_NOMREST=ElementNOMER_NOMREST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomRestImpl::get_ElementNAME_NOMREST(void)
{
return Object->ElementNAME_NOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementNAME_NOMREST(TFIBWideStringField * ElementNAME_NOMREST)
{
Object->ElementNAME_NOMREST=ElementNAME_NOMREST;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMSprNomRestImpl::get_ElementPOS_NOMREST(void)
{
return Object->ElementPOS_NOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementPOS_NOMREST(TFIBDateTimeField * ElementPOS_NOMREST)
{
Object->ElementPOS_NOMREST=ElementPOS_NOMREST;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomRestImpl::get_ElementIDEDPROD_NOMREST(void)
{
return Object->ElementIDEDPROD_NOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementIDEDPROD_NOMREST(TFIBBCDField * ElementIDEDPROD_NOMREST)
{
Object->ElementIDEDPROD_NOMREST=ElementIDEDPROD_NOMREST;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomRestImpl::get_ElementKOLEDPROD_NOMREST(void)
{
return Object->ElementKOLEDPROD_NOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementKOLEDPROD_NOMREST(TFIBBCDField * ElementKOLEDPROD_NOMREST)
{
Object->ElementKOLEDPROD_NOMREST=ElementKOLEDPROD_NOMREST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomRestImpl::get_ElementGID_SNOMREST(void)
{
return Object->ElementGID_SNOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementGID_SNOMREST(TFIBWideStringField * ElementGID_SNOMREST)
{
Object->ElementGID_SNOMREST=ElementGID_SNOMREST;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomRestImpl::get_ElementIDBASE_SNOMREST(void)
{
return Object->ElementIDBASE_SNOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementIDBASE_SNOMREST(TFIBBCDField * ElementIDBASE_SNOMREST)
{
Object->ElementIDBASE_SNOMREST=ElementIDBASE_SNOMREST;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomRestImpl::get_ElementIDEDFACTOR_SNOMREST(void)
{
return Object->ElementIDEDFACTOR_SNOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementIDEDFACTOR_SNOMREST(TFIBBCDField * ElementIDEDFACTOR_SNOMREST)
{
Object->ElementIDEDFACTOR_SNOMREST=ElementIDEDFACTOR_SNOMREST;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomRestImpl::get_ElementENCEN_SNOMREST(void)
{
return Object->ElementENCEN_SNOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementENCEN_SNOMREST(TFIBBCDField * ElementENCEN_SNOMREST)
{
Object->ElementENCEN_SNOMREST=ElementENCEN_SNOMREST;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomRestImpl::get_ElementIDPRODUCE_SNOMREST(void)
{
return Object->ElementIDPRODUCE_SNOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementIDPRODUCE_SNOMREST(TFIBBCDField * ElementIDPRODUCE_SNOMREST)
{
Object->ElementIDPRODUCE_SNOMREST=ElementIDPRODUCE_SNOMREST;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomRestImpl::get_ElementIDLOSSFACTOR_SNOMREST(void)
{
return Object->ElementIDLOSSFACTOR_SNOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementIDLOSSFACTOR_SNOMREST(TFIBBCDField * ElementIDLOSSFACTOR_SNOMREST)
{
Object->ElementIDLOSSFACTOR_SNOMREST=ElementIDLOSSFACTOR_SNOMREST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomRestImpl::get_ElementVID_SNOMREST(void)
{
return Object->ElementVID_SNOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementVID_SNOMREST(TFIBWideStringField * ElementVID_SNOMREST)
{
Object->ElementVID_SNOMREST=ElementVID_SNOMREST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomRestImpl::get_ElementTEMP_SNOMREST(void)
{
return Object->ElementTEMP_SNOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementTEMP_SNOMREST(TFIBWideStringField * ElementTEMP_SNOMREST)
{
Object->ElementTEMP_SNOMREST=ElementTEMP_SNOMREST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomRestImpl::get_ElementAPPERANCE_SNOMREST(void)
{
return Object->ElementAPPERANCE_SNOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementAPPERANCE_SNOMREST(TFIBWideStringField * ElementAPPERANCE_SNOMREST)
{
Object->ElementAPPERANCE_SNOMREST=ElementAPPERANCE_SNOMREST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomRestImpl::get_ElementCOLOUR_SNOMREST(void)
{
return Object->ElementCOLOUR_SNOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementCOLOUR_SNOMREST(TFIBWideStringField * ElementCOLOUR_SNOMREST)
{
Object->ElementCOLOUR_SNOMREST=ElementCOLOUR_SNOMREST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomRestImpl::get_ElementTASTE_SNOMREST(void)
{
return Object->ElementTASTE_SNOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementTASTE_SNOMREST(TFIBWideStringField * ElementTASTE_SNOMREST)
{
Object->ElementTASTE_SNOMREST=ElementTASTE_SNOMREST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomRestImpl::get_ElementSMELL_SNOMREST(void)
{
return Object->ElementSMELL_SNOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementSMELL_SNOMREST(TFIBWideStringField * ElementSMELL_SNOMREST)
{
Object->ElementSMELL_SNOMREST=ElementSMELL_SNOMREST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomRestImpl::get_ElementCONSISTENCE_SNOMREST(void)
{
return Object->ElementCONSISTENCE_SNOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementCONSISTENCE_SNOMREST(TFIBWideStringField * ElementCONSISTENCE_SNOMREST)
{
Object->ElementCONSISTENCE_SNOMREST=ElementCONSISTENCE_SNOMREST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomRestImpl::get_ElementMDSV_SNOMREST(void)
{
return Object->ElementMDSV_SNOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementMDSV_SNOMREST(TFIBWideStringField * ElementMDSV_SNOMREST)
{
Object->ElementMDSV_SNOMREST=ElementMDSV_SNOMREST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomRestImpl::get_ElementMDG_SNOMREST(void)
{
return Object->ElementMDG_SNOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementMDG_SNOMREST(TFIBWideStringField * ElementMDG_SNOMREST)
{
Object->ElementMDG_SNOMREST=ElementMDG_SNOMREST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomRestImpl::get_ElementMDS_SNOMREST(void)
{
return Object->ElementMDS_SNOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementMDS_SNOMREST(TFIBWideStringField * ElementMDS_SNOMREST)
{
Object->ElementMDS_SNOMREST=ElementMDS_SNOMREST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomRestImpl::get_ElementKMAM_SNOMREST(void)
{
return Object->ElementKMAM_SNOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementKMAM_SNOMREST(TFIBWideStringField * ElementKMAM_SNOMREST)
{
Object->ElementKMAM_SNOMREST=ElementKMAM_SNOMREST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomRestImpl::get_ElementBGKR_SNOMREST(void)
{
return Object->ElementBGKR_SNOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementBGKR_SNOMREST(TFIBWideStringField * ElementBGKR_SNOMREST)
{
Object->ElementBGKR_SNOMREST=ElementBGKR_SNOMREST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomRestImpl::get_ElementECOLI_SNOMREST(void)
{
return Object->ElementECOLI_SNOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementECOLI_SNOMREST(TFIBWideStringField * ElementECOLI_SNOMREST)
{
Object->ElementECOLI_SNOMREST=ElementECOLI_SNOMREST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomRestImpl::get_ElementKPS_SNOMREST(void)
{
return Object->ElementKPS_SNOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementKPS_SNOMREST(TFIBWideStringField * ElementKPS_SNOMREST)
{
Object->ElementKPS_SNOMREST=ElementKPS_SNOMREST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomRestImpl::get_ElementPROTEUS_SNOMREST(void)
{
return Object->ElementPROTEUS_SNOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementPROTEUS_SNOMREST(TFIBWideStringField * ElementPROTEUS_SNOMREST)
{
Object->ElementPROTEUS_SNOMREST=ElementPROTEUS_SNOMREST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomRestImpl::get_ElementPMS_SNOMREST(void)
{
return Object->ElementPMS_SNOMREST;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementPMS_SNOMREST(TFIBWideStringField * ElementPMS_SNOMREST)
{
Object->ElementPMS_SNOMREST=ElementPMS_SNOMREST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomRestImpl::get_ElementNAME_MPRIG(void)
{
return Object->ElementNAME_MPRIG;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementNAME_MPRIG(TFIBWideStringField * ElementNAME_MPRIG)
{
Object->ElementNAME_MPRIG=ElementNAME_MPRIG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomRestImpl::get_ElementNAMENOM(void)
{
return Object->ElementNAMENOM;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementNAMENOM(TFIBWideStringField * ElementNAMENOM)
{
Object->ElementNAMENOM=ElementNAMENOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomRestImpl::get_ElementIDSKLAD_MPRIG(void)
{
return Object->ElementIDSKLAD_MPRIG;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementIDSKLAD_MPRIG(TFIBBCDField * ElementIDSKLAD_MPRIG)
{
Object->ElementIDSKLAD_MPRIG=ElementIDSKLAD_MPRIG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomRestImpl::get_ElementNAMEED(void)
{
return Object->ElementNAMEED;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementNAMEED(TFIBWideStringField * ElementNAMEED)
{
Object->ElementNAMEED=ElementNAMEED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomRestImpl::get_ElementKFED(void)
{
return Object->ElementKFED;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementKFED(TFIBBCDField * ElementKFED)
{
Object->ElementKFED=ElementKFED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomRestImpl::get_ElementNAME_ED_FACTOR(void)
{
return Object->ElementNAME_ED_FACTOR;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementNAME_ED_FACTOR(TFIBWideStringField * ElementNAME_ED_FACTOR)
{
Object->ElementNAME_ED_FACTOR=ElementNAME_ED_FACTOR;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomRestImpl::get_ElementKF_ED_FACTOR(void)
{
return Object->ElementKF_ED_FACTOR;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementKF_ED_FACTOR(TFIBBCDField * ElementKF_ED_FACTOR)
{
Object->ElementKF_ED_FACTOR=ElementKF_ED_FACTOR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomRestImpl::get_ElementNAME_SPRODUCE(void)
{
return Object->ElementNAME_SPRODUCE;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementNAME_SPRODUCE(TFIBWideStringField * ElementNAME_SPRODUCE)
{
Object->ElementNAME_SPRODUCE=ElementNAME_SPRODUCE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomRestImpl::get_ElementNAME_SLOSS_FACTOR(void)
{
return Object->ElementNAME_SLOSS_FACTOR;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_ElementNAME_SLOSS_FACTOR(TFIBWideStringField * ElementNAME_SLOSS_FACTOR)
{
Object->ElementNAME_SLOSS_FACTOR=ElementNAME_SLOSS_FACTOR;
}
//---------------------------------------------------------------
__int64 TDMSprNomRestImpl::get_Id(void)
{
return Object->Id;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_Id(__int64 Id)
{
Object->Id=Id;
}
//---------------------------------------------------------------
__int64 TDMSprNomRestImpl::get_IdNom(void)
{
return Object->IdNom;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_IdNom(__int64 IdNom)
{
Object->IdNom=IdNom;
}

//---------------------------------------------------------------
bool TDMSprNomRestImpl::get_flSaveElement(void)
{
return Object->flSaveElement;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::set_flSaveElement(bool flSaveElement)
{
Object->flSaveElement=flSaveElement;
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprNomRestImpl::OpenElement(void)
{
return Object->OpenElement();
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprNomRestImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprNomRestImpl::DeleteElement(void)
{
return Object->DeleteElement();
}
//---------------------------------------------------------------
__int64 TDMSprNomRestImpl::GetTekSostav(__int64 idNom, TDateTime pos)
{
return Object->GetTekSostav( idNom,  pos);
}
//---------------------------------------------------------------
