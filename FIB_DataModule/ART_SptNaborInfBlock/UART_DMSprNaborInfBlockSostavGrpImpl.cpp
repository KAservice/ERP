#include "vcl.h"
#pragma hdrstop


#include "UART_DMSprNaborInfBlockSostavGrpImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TART_DMSprNaborInfBlockSostavGrpImpl::TART_DMSprNaborInfBlockSostavGrpImpl()           
{                                            
Object=new TART_DMSprNaborInfBlockSostavGrp(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TART_DMSprNaborInfBlockSostavGrpImpl::~TART_DMSprNaborInfBlockSostavGrpImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavGrpImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TART_DMSprNaborInfBlockSostavGrpImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IART_DMSprNaborInfBlockSostavGrp)                        
   {                                                                     
   *ppv=static_cast<IART_DMSprNaborInfBlockSostavGrp*> (this);                                
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
int TART_DMSprNaborInfBlockSostavGrpImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TART_DMSprNaborInfBlockSostavGrpImpl::kanRelease(void)                                  
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
int  TART_DMSprNaborInfBlockSostavGrpImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavGrpImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TART_DMSprNaborInfBlockSostavGrpImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavGrpImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TART_DMSprNaborInfBlockSostavGrpImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TART_DMSprNaborInfBlockSostavGrpImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TART_DMSprNaborInfBlockSostavGrpImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IART_DMSprNaborInfBlockSostavGrp
TDataSource * TART_DMSprNaborInfBlockSostavGrpImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavGrpImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TART_DMSprNaborInfBlockSostavGrpImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavGrpImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TART_DMSprNaborInfBlockSostavGrpImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavGrpImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TART_DMSprNaborInfBlockSostavGrpImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavGrpImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TART_DMSprNaborInfBlockSostavGrpImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavGrpImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TART_DMSprNaborInfBlockSostavGrpImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavGrpImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprNaborInfBlockSostavGrpImpl::get_TableID_ART_N_IB_S_GRP(void)
{
return Object->TableID_ART_N_IB_S_GRP;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavGrpImpl::set_TableID_ART_N_IB_S_GRP(TFIBLargeIntField * TableID_ART_N_IB_S_GRP)
{
Object->TableID_ART_N_IB_S_GRP=TableID_ART_N_IB_S_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprNaborInfBlockSostavGrpImpl::get_TableIDBASE_ART_N_IB_S_GRP(void)
{
return Object->TableIDBASE_ART_N_IB_S_GRP;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavGrpImpl::set_TableIDBASE_ART_N_IB_S_GRP(TFIBLargeIntField * TableIDBASE_ART_N_IB_S_GRP)
{
Object->TableIDBASE_ART_N_IB_S_GRP=TableIDBASE_ART_N_IB_S_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprNaborInfBlockSostavGrpImpl::get_TableGUID_ART_N_IB_S_GRP(void)
{
return Object->TableGUID_ART_N_IB_S_GRP;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavGrpImpl::set_TableGUID_ART_N_IB_S_GRP(TFIBWideStringField * TableGUID_ART_N_IB_S_GRP)
{
Object->TableGUID_ART_N_IB_S_GRP=TableGUID_ART_N_IB_S_GRP;
}
//---------------------------------------------------------------
TFIBDateTimeField * TART_DMSprNaborInfBlockSostavGrpImpl::get_TablePOS_ISM_ART_N_IB_S_GRP(void)
{
return Object->TablePOS_ISM_ART_N_IB_S_GRP;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavGrpImpl::set_TablePOS_ISM_ART_N_IB_S_GRP(TFIBDateTimeField * TablePOS_ISM_ART_N_IB_S_GRP)
{
Object->TablePOS_ISM_ART_N_IB_S_GRP=TablePOS_ISM_ART_N_IB_S_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprNaborInfBlockSostavGrpImpl::get_TableIDGRP_ART_N_IB_S_GRP(void)
{
return Object->TableIDGRP_ART_N_IB_S_GRP;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavGrpImpl::set_TableIDGRP_ART_N_IB_S_GRP(TFIBLargeIntField * TableIDGRP_ART_N_IB_S_GRP)
{
Object->TableIDGRP_ART_N_IB_S_GRP=TableIDGRP_ART_N_IB_S_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprNaborInfBlockSostavGrpImpl::get_TableNAME_ART_N_IB_S_GRP(void)
{
return Object->TableNAME_ART_N_IB_S_GRP;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavGrpImpl::set_TableNAME_ART_N_IB_S_GRP(TFIBWideStringField * TableNAME_ART_N_IB_S_GRP)
{
Object->TableNAME_ART_N_IB_S_GRP=TableNAME_ART_N_IB_S_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprNaborInfBlockSostavGrpImpl::get_TableIDNABOR_ART_N_IB_S_GRP(void)
{
return Object->TableIDNABOR_ART_N_IB_S_GRP;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavGrpImpl::set_TableIDNABOR_ART_N_IB_S_GRP(TFIBLargeIntField * TableIDNABOR_ART_N_IB_S_GRP)
{
Object->TableIDNABOR_ART_N_IB_S_GRP=TableIDNABOR_ART_N_IB_S_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprNaborInfBlockSostavGrpImpl::get_ElementID_ART_N_IB_S_GRP(void)
{
return Object->ElementID_ART_N_IB_S_GRP;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavGrpImpl::set_ElementID_ART_N_IB_S_GRP(TFIBLargeIntField * ElementID_ART_N_IB_S_GRP)
{
Object->ElementID_ART_N_IB_S_GRP=ElementID_ART_N_IB_S_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprNaborInfBlockSostavGrpImpl::get_ElementIDBASE_ART_N_IB_S_GRP(void)
{
return Object->ElementIDBASE_ART_N_IB_S_GRP;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavGrpImpl::set_ElementIDBASE_ART_N_IB_S_GRP(TFIBLargeIntField * ElementIDBASE_ART_N_IB_S_GRP)
{
Object->ElementIDBASE_ART_N_IB_S_GRP=ElementIDBASE_ART_N_IB_S_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprNaborInfBlockSostavGrpImpl::get_ElementGUID_ART_N_IB_S_GRP(void)
{
return Object->ElementGUID_ART_N_IB_S_GRP;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavGrpImpl::set_ElementGUID_ART_N_IB_S_GRP(TFIBWideStringField * ElementGUID_ART_N_IB_S_GRP)
{
Object->ElementGUID_ART_N_IB_S_GRP=ElementGUID_ART_N_IB_S_GRP;
}
//---------------------------------------------------------------
TFIBDateTimeField * TART_DMSprNaborInfBlockSostavGrpImpl::get_ElementPOS_ISM_ART_N_IB_S_GRP(void)
{
return Object->ElementPOS_ISM_ART_N_IB_S_GRP;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavGrpImpl::set_ElementPOS_ISM_ART_N_IB_S_GRP(TFIBDateTimeField * ElementPOS_ISM_ART_N_IB_S_GRP)
{
Object->ElementPOS_ISM_ART_N_IB_S_GRP=ElementPOS_ISM_ART_N_IB_S_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprNaborInfBlockSostavGrpImpl::get_ElementIDGRP_ART_N_IB_S_GRP(void)
{
return Object->ElementIDGRP_ART_N_IB_S_GRP;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavGrpImpl::set_ElementIDGRP_ART_N_IB_S_GRP(TFIBLargeIntField * ElementIDGRP_ART_N_IB_S_GRP)
{
Object->ElementIDGRP_ART_N_IB_S_GRP=ElementIDGRP_ART_N_IB_S_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprNaborInfBlockSostavGrpImpl::get_ElementNAME_ART_N_IB_S_GRP(void)
{
return Object->ElementNAME_ART_N_IB_S_GRP;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavGrpImpl::set_ElementNAME_ART_N_IB_S_GRP(TFIBWideStringField * ElementNAME_ART_N_IB_S_GRP)
{
Object->ElementNAME_ART_N_IB_S_GRP=ElementNAME_ART_N_IB_S_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprNaborInfBlockSostavGrpImpl::get_ElementIDNABOR_ART_N_IB_S_GRP(void)
{
return Object->ElementIDNABOR_ART_N_IB_S_GRP;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavGrpImpl::set_ElementIDNABOR_ART_N_IB_S_GRP(TFIBLargeIntField * ElementIDNABOR_ART_N_IB_S_GRP)
{
Object->ElementIDNABOR_ART_N_IB_S_GRP=ElementIDNABOR_ART_N_IB_S_GRP;
}
//---------------------------------------------------------------
__int64 TART_DMSprNaborInfBlockSostavGrpImpl::get_IdGroupElement(void)
{
return Object->IdGroupElement;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavGrpImpl::set_IdGroupElement(__int64 IdGroupElement)
{
Object->IdGroupElement=IdGroupElement;
}
//---------------------------------------------------------------
__int64 TART_DMSprNaborInfBlockSostavGrpImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavGrpImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
__int64 TART_DMSprNaborInfBlockSostavGrpImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavGrpImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
bool TART_DMSprNaborInfBlockSostavGrpImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavGrpImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
bool TART_DMSprNaborInfBlockSostavGrpImpl::OpenTable(__int64 id_group_element)
{
return Object->OpenTable(id_group_element);
}
//---------------------------------------------------------------
bool TART_DMSprNaborInfBlockSostavGrpImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TART_DMSprNaborInfBlockSostavGrpImpl::NewElement(__int64 id_group_element, __int64 id_grp)
{
return Object->NewElement(id_group_element,id_grp);
}
//---------------------------------------------------------------
bool TART_DMSprNaborInfBlockSostavGrpImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TART_DMSprNaborInfBlockSostavGrpImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement( id);
}
//---------------------------------------------------------------
