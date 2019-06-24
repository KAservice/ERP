#include "vcl.h"
#pragma hdrstop


#include "UART_DMSprNaborInfBlockGrpImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TART_DMSprNaborInfBlockGrpImpl::TART_DMSprNaborInfBlockGrpImpl()           
{                                            
Object=new TART_DMSprNaborInfBlockGrp(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TART_DMSprNaborInfBlockGrpImpl::~TART_DMSprNaborInfBlockGrpImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockGrpImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TART_DMSprNaborInfBlockGrpImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IART_DMSprNaborInfBlockGrp)                        
   {                                                                     
   *ppv=static_cast<IART_DMSprNaborInfBlockGrp*> (this);                                
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
int TART_DMSprNaborInfBlockGrpImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TART_DMSprNaborInfBlockGrpImpl::kanRelease(void)                                  
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
int  TART_DMSprNaborInfBlockGrpImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockGrpImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TART_DMSprNaborInfBlockGrpImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockGrpImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TART_DMSprNaborInfBlockGrpImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TART_DMSprNaborInfBlockGrpImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TART_DMSprNaborInfBlockGrpImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IART_DMSprNaborInfBlockGrp
TDataSource * TART_DMSprNaborInfBlockGrpImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockGrpImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TART_DMSprNaborInfBlockGrpImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockGrpImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TART_DMSprNaborInfBlockGrpImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockGrpImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TART_DMSprNaborInfBlockGrpImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockGrpImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TART_DMSprNaborInfBlockGrpImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockGrpImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TART_DMSprNaborInfBlockGrpImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockGrpImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprNaborInfBlockGrpImpl::get_TableID_ART_N_IB_GRP(void)
{
return Object->TableID_ART_N_IB_GRP;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockGrpImpl::set_TableID_ART_N_IB_GRP(TFIBLargeIntField * TableID_ART_N_IB_GRP)
{
Object->TableID_ART_N_IB_GRP=TableID_ART_N_IB_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprNaborInfBlockGrpImpl::get_TableIDBASE_ART_N_IB_GRP(void)
{
return Object->TableIDBASE_ART_N_IB_GRP;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockGrpImpl::set_TableIDBASE_ART_N_IB_GRP(TFIBLargeIntField * TableIDBASE_ART_N_IB_GRP)
{
Object->TableIDBASE_ART_N_IB_GRP=TableIDBASE_ART_N_IB_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprNaborInfBlockGrpImpl::get_TableGUID_ART_N_IB_GRP(void)
{
return Object->TableGUID_ART_N_IB_GRP;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockGrpImpl::set_TableGUID_ART_N_IB_GRP(TFIBWideStringField * TableGUID_ART_N_IB_GRP)
{
Object->TableGUID_ART_N_IB_GRP=TableGUID_ART_N_IB_GRP;
}
//---------------------------------------------------------------
TFIBDateTimeField * TART_DMSprNaborInfBlockGrpImpl::get_TablePOS_ISM_ART_N_IB_GRP(void)
{
return Object->TablePOS_ISM_ART_N_IB_GRP;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockGrpImpl::set_TablePOS_ISM_ART_N_IB_GRP(TFIBDateTimeField * TablePOS_ISM_ART_N_IB_GRP)
{
Object->TablePOS_ISM_ART_N_IB_GRP=TablePOS_ISM_ART_N_IB_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprNaborInfBlockGrpImpl::get_TableIDGRP_ART_N_IB_GRP(void)
{
return Object->TableIDGRP_ART_N_IB_GRP;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockGrpImpl::set_TableIDGRP_ART_N_IB_GRP(TFIBLargeIntField * TableIDGRP_ART_N_IB_GRP)
{
Object->TableIDGRP_ART_N_IB_GRP=TableIDGRP_ART_N_IB_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprNaborInfBlockGrpImpl::get_TableNAME_ART_N_IB_GRP(void)
{
return Object->TableNAME_ART_N_IB_GRP;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockGrpImpl::set_TableNAME_ART_N_IB_GRP(TFIBWideStringField * TableNAME_ART_N_IB_GRP)
{
Object->TableNAME_ART_N_IB_GRP=TableNAME_ART_N_IB_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprNaborInfBlockGrpImpl::get_ElementID_ART_N_IB_GRP(void)
{
return Object->ElementID_ART_N_IB_GRP;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockGrpImpl::set_ElementID_ART_N_IB_GRP(TFIBLargeIntField * ElementID_ART_N_IB_GRP)
{
Object->ElementID_ART_N_IB_GRP=ElementID_ART_N_IB_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprNaborInfBlockGrpImpl::get_ElementIDBASE_ART_N_IB_GRP(void)
{
return Object->ElementIDBASE_ART_N_IB_GRP;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockGrpImpl::set_ElementIDBASE_ART_N_IB_GRP(TFIBLargeIntField * ElementIDBASE_ART_N_IB_GRP)
{
Object->ElementIDBASE_ART_N_IB_GRP=ElementIDBASE_ART_N_IB_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprNaborInfBlockGrpImpl::get_ElementGUID_ART_N_IB_GRP(void)
{
return Object->ElementGUID_ART_N_IB_GRP;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockGrpImpl::set_ElementGUID_ART_N_IB_GRP(TFIBWideStringField * ElementGUID_ART_N_IB_GRP)
{
Object->ElementGUID_ART_N_IB_GRP=ElementGUID_ART_N_IB_GRP;
}
//---------------------------------------------------------------
TFIBDateTimeField * TART_DMSprNaborInfBlockGrpImpl::get_ElementPOS_ISM_ART_N_IB_GRP(void)
{
return Object->ElementPOS_ISM_ART_N_IB_GRP;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockGrpImpl::set_ElementPOS_ISM_ART_N_IB_GRP(TFIBDateTimeField * ElementPOS_ISM_ART_N_IB_GRP)
{
Object->ElementPOS_ISM_ART_N_IB_GRP=ElementPOS_ISM_ART_N_IB_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprNaborInfBlockGrpImpl::get_ElementIDGRP_ART_N_IB_GRP(void)
{
return Object->ElementIDGRP_ART_N_IB_GRP;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockGrpImpl::set_ElementIDGRP_ART_N_IB_GRP(TFIBLargeIntField * ElementIDGRP_ART_N_IB_GRP)
{
Object->ElementIDGRP_ART_N_IB_GRP=ElementIDGRP_ART_N_IB_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprNaborInfBlockGrpImpl::get_ElementNAME_ART_N_IB_GRP(void)
{
return Object->ElementNAME_ART_N_IB_GRP;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockGrpImpl::set_ElementNAME_ART_N_IB_GRP(TFIBWideStringField * ElementNAME_ART_N_IB_GRP)
{
Object->ElementNAME_ART_N_IB_GRP=ElementNAME_ART_N_IB_GRP;
}
//---------------------------------------------------------------
__int64 TART_DMSprNaborInfBlockGrpImpl::get_IdGroupElement(void)
{
return Object->IdGroupElement;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockGrpImpl::set_IdGroupElement(__int64 IdGroupElement)
{
Object->IdGroupElement=IdGroupElement;
}
//---------------------------------------------------------------
__int64 TART_DMSprNaborInfBlockGrpImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockGrpImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
__int64 TART_DMSprNaborInfBlockGrpImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockGrpImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
bool TART_DMSprNaborInfBlockGrpImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockGrpImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
bool TART_DMSprNaborInfBlockGrpImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
bool TART_DMSprNaborInfBlockGrpImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TART_DMSprNaborInfBlockGrpImpl::NewElement( __int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TART_DMSprNaborInfBlockGrpImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TART_DMSprNaborInfBlockGrpImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
