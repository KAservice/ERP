#include "vcl.h"
#pragma hdrstop


#include "UART_DMSprInfBlockGrpImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TART_DMSprInfBlockGrpImpl::TART_DMSprInfBlockGrpImpl()           
{                                            
Object=new TART_DMSprInfBlockGrp(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TART_DMSprInfBlockGrpImpl::~TART_DMSprInfBlockGrpImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TART_DMSprInfBlockGrpImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TART_DMSprInfBlockGrpImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IART_DMSprInfBlockGrp)                        
   {                                                                     
   *ppv=static_cast<IART_DMSprInfBlockGrp*> (this);                                
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
int TART_DMSprInfBlockGrpImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TART_DMSprInfBlockGrpImpl::kanRelease(void)                                  
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
int  TART_DMSprInfBlockGrpImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TART_DMSprInfBlockGrpImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TART_DMSprInfBlockGrpImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TART_DMSprInfBlockGrpImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TART_DMSprInfBlockGrpImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TART_DMSprInfBlockGrpImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TART_DMSprInfBlockGrpImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IART_DMSprInfBlockGrp
TDataSource * TART_DMSprInfBlockGrpImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockGrpImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TART_DMSprInfBlockGrpImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockGrpImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TART_DMSprInfBlockGrpImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockGrpImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TART_DMSprInfBlockGrpImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockGrpImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TART_DMSprInfBlockGrpImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockGrpImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TART_DMSprInfBlockGrpImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockGrpImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TART_DMSprInfBlockGrpImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockGrpImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprInfBlockGrpImpl::get_TableID_ART_IB_GRP(void)
{
return Object->TableID_ART_IB_GRP;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockGrpImpl::set_TableID_ART_IB_GRP(TFIBLargeIntField * TableID_ART_IB_GRP)
{
Object->TableID_ART_IB_GRP=TableID_ART_IB_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprInfBlockGrpImpl::get_TableIDBASE_ART_IB_GRP(void)
{
return Object->TableIDBASE_ART_IB_GRP;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockGrpImpl::set_TableIDBASE_ART_IB_GRP(TFIBLargeIntField * TableIDBASE_ART_IB_GRP)
{
Object->TableIDBASE_ART_IB_GRP=TableIDBASE_ART_IB_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprInfBlockGrpImpl::get_TableGUID_ART_IB_GRP(void)
{
return Object->TableGUID_ART_IB_GRP;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockGrpImpl::set_TableGUID_ART_IB_GRP(TFIBWideStringField * TableGUID_ART_IB_GRP)
{
Object->TableGUID_ART_IB_GRP=TableGUID_ART_IB_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprInfBlockGrpImpl::get_TableNAME_ART_IB_GRP(void)
{
return Object->TableNAME_ART_IB_GRP;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockGrpImpl::set_TableNAME_ART_IB_GRP(TFIBWideStringField * TableNAME_ART_IB_GRP)
{
Object->TableNAME_ART_IB_GRP=TableNAME_ART_IB_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprInfBlockGrpImpl::get_TableIDGRP_ART_IB_GRP(void)
{
return Object->TableIDGRP_ART_IB_GRP;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockGrpImpl::set_TableIDGRP_ART_IB_GRP(TFIBLargeIntField * TableIDGRP_ART_IB_GRP)
{
Object->TableIDGRP_ART_IB_GRP=TableIDGRP_ART_IB_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprInfBlockGrpImpl::get_TableGUID_GRP_ART_IB_GRP(void)
{
return Object->TableGUID_GRP_ART_IB_GRP;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockGrpImpl::set_TableGUID_GRP_ART_IB_GRP(TFIBWideStringField * TableGUID_GRP_ART_IB_GRP)
{
Object->TableGUID_GRP_ART_IB_GRP=TableGUID_GRP_ART_IB_GRP;
}
//---------------------------------------------------------------
TFIBDateTimeField * TART_DMSprInfBlockGrpImpl::get_TablePOS_ISM_ART_IB_GRP(void)
{
return Object->TablePOS_ISM_ART_IB_GRP;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockGrpImpl::set_TablePOS_ISM_ART_IB_GRP(TFIBDateTimeField * TablePOS_ISM_ART_IB_GRP)
{
Object->TablePOS_ISM_ART_IB_GRP=TablePOS_ISM_ART_IB_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprInfBlockGrpImpl::get_ElementID_ART_IB_GRP(void)
{
return Object->ElementID_ART_IB_GRP;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockGrpImpl::set_ElementID_ART_IB_GRP(TFIBLargeIntField * ElementID_ART_IB_GRP)
{
Object->ElementID_ART_IB_GRP=ElementID_ART_IB_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprInfBlockGrpImpl::get_ElementIDBASE_ART_IB_GRP(void)
{
return Object->ElementIDBASE_ART_IB_GRP;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockGrpImpl::set_ElementIDBASE_ART_IB_GRP(TFIBLargeIntField * ElementIDBASE_ART_IB_GRP)
{
Object->ElementIDBASE_ART_IB_GRP=ElementIDBASE_ART_IB_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprInfBlockGrpImpl::get_ElementGUID_ART_IB_GRP(void)
{
return Object->ElementGUID_ART_IB_GRP;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockGrpImpl::set_ElementGUID_ART_IB_GRP(TFIBWideStringField * ElementGUID_ART_IB_GRP)
{
Object->ElementGUID_ART_IB_GRP=ElementGUID_ART_IB_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprInfBlockGrpImpl::get_ElementNAME_ART_IB_GRP(void)
{
return Object->ElementNAME_ART_IB_GRP;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockGrpImpl::set_ElementNAME_ART_IB_GRP(TFIBWideStringField * ElementNAME_ART_IB_GRP)
{
Object->ElementNAME_ART_IB_GRP=ElementNAME_ART_IB_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprInfBlockGrpImpl::get_ElementIDGRP_ART_IB_GRP(void)
{
return Object->ElementIDGRP_ART_IB_GRP;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockGrpImpl::set_ElementIDGRP_ART_IB_GRP(TFIBLargeIntField * ElementIDGRP_ART_IB_GRP)
{
Object->ElementIDGRP_ART_IB_GRP=ElementIDGRP_ART_IB_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprInfBlockGrpImpl::get_ElementGUID_GRP_ART_IB_GRP(void)
{
return Object->ElementGUID_GRP_ART_IB_GRP;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockGrpImpl::set_ElementGUID_GRP_ART_IB_GRP(TFIBWideStringField * ElementGUID_GRP_ART_IB_GRP)
{
Object->ElementGUID_GRP_ART_IB_GRP=ElementGUID_GRP_ART_IB_GRP;
}
//---------------------------------------------------------------
TFIBDateTimeField * TART_DMSprInfBlockGrpImpl::get_ElementPOS_ISM_ART_IB_GRP(void)
{
return Object->ElementPOS_ISM_ART_IB_GRP;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockGrpImpl::set_ElementPOS_ISM_ART_IB_GRP(TFIBDateTimeField * ElementPOS_ISM_ART_IB_GRP)
{
Object->ElementPOS_ISM_ART_IB_GRP=ElementPOS_ISM_ART_IB_GRP;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockGrpImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TART_DMSprInfBlockGrpImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TART_DMSprInfBlockGrpImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TART_DMSprInfBlockGrpImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TART_DMSprInfBlockGrpImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TART_DMSprInfBlockGrpImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
