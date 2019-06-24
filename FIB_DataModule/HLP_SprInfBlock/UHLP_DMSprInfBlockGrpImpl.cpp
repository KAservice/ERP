#include "vcl.h"
#pragma hdrstop


#include "UHLP_DMSprInfBlockGrpImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THLP_DMSprInfBlockGrpImpl::THLP_DMSprInfBlockGrpImpl()           
{                                            
Object=new THLP_DMSprInfBlockGrp(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THLP_DMSprInfBlockGrpImpl::~THLP_DMSprInfBlockGrpImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THLP_DMSprInfBlockGrpImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THLP_DMSprInfBlockGrpImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHLP_DMSprInfBlockGrp)                        
   {                                                                     
   *ppv=static_cast<IHLP_DMSprInfBlockGrp*> (this);                                
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
int THLP_DMSprInfBlockGrpImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THLP_DMSprInfBlockGrpImpl::kanRelease(void)                                  
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
int  THLP_DMSprInfBlockGrpImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THLP_DMSprInfBlockGrpImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THLP_DMSprInfBlockGrpImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THLP_DMSprInfBlockGrpImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THLP_DMSprInfBlockGrpImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_THLP_DMSprInfBlockGrpImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THLP_DMSprInfBlockGrpImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IHLP_DMSprInfBlockGrp
TDataSource * THLP_DMSprInfBlockGrpImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockGrpImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * THLP_DMSprInfBlockGrpImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockGrpImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * THLP_DMSprInfBlockGrpImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockGrpImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * THLP_DMSprInfBlockGrpImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockGrpImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * THLP_DMSprInfBlockGrpImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockGrpImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * THLP_DMSprInfBlockGrpImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockGrpImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * THLP_DMSprInfBlockGrpImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockGrpImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprInfBlockGrpImpl::get_TableID_HLP_IB_GRP(void)
{
return Object->TableID_HLP_IB_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockGrpImpl::set_TableID_HLP_IB_GRP(TFIBLargeIntField * TableID_HLP_IB_GRP)
{
Object->TableID_HLP_IB_GRP=TableID_HLP_IB_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprInfBlockGrpImpl::get_TableIDBASE_HLP_IB_GRP(void)
{
return Object->TableIDBASE_HLP_IB_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockGrpImpl::set_TableIDBASE_HLP_IB_GRP(TFIBLargeIntField * TableIDBASE_HLP_IB_GRP)
{
Object->TableIDBASE_HLP_IB_GRP=TableIDBASE_HLP_IB_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockGrpImpl::get_TableGUID_HLP_IB_GRP(void)
{
return Object->TableGUID_HLP_IB_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockGrpImpl::set_TableGUID_HLP_IB_GRP(TFIBWideStringField * TableGUID_HLP_IB_GRP)
{
Object->TableGUID_HLP_IB_GRP=TableGUID_HLP_IB_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockGrpImpl::get_TableNAME_HLP_IB_GRP(void)
{
return Object->TableNAME_HLP_IB_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockGrpImpl::set_TableNAME_HLP_IB_GRP(TFIBWideStringField * TableNAME_HLP_IB_GRP)
{
Object->TableNAME_HLP_IB_GRP=TableNAME_HLP_IB_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprInfBlockGrpImpl::get_TableIDGRP_HLP_IB_GRP(void)
{
return Object->TableIDGRP_HLP_IB_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockGrpImpl::set_TableIDGRP_HLP_IB_GRP(TFIBLargeIntField * TableIDGRP_HLP_IB_GRP)
{
Object->TableIDGRP_HLP_IB_GRP=TableIDGRP_HLP_IB_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockGrpImpl::get_TableGUID_GRP_HLP_IB_GRP(void)
{
return Object->TableGUID_GRP_HLP_IB_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockGrpImpl::set_TableGUID_GRP_HLP_IB_GRP(TFIBWideStringField * TableGUID_GRP_HLP_IB_GRP)
{
Object->TableGUID_GRP_HLP_IB_GRP=TableGUID_GRP_HLP_IB_GRP;
}
//---------------------------------------------------------------
TFIBDateTimeField * THLP_DMSprInfBlockGrpImpl::get_TablePOS_ISM_HLP_IB_GRP(void)
{
return Object->TablePOS_ISM_HLP_IB_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockGrpImpl::set_TablePOS_ISM_HLP_IB_GRP(TFIBDateTimeField * TablePOS_ISM_HLP_IB_GRP)
{
Object->TablePOS_ISM_HLP_IB_GRP=TablePOS_ISM_HLP_IB_GRP;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprInfBlockGrpImpl::get_TableINDEX_HLP_IB_GRP(void)
{
return Object->TableINDEX_HLP_IB_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockGrpImpl::set_TableINDEX_HLP_IB_GRP(TFIBIntegerField * TableINDEX_HLP_IB_GRP)
{
Object->TableINDEX_HLP_IB_GRP=TableINDEX_HLP_IB_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprInfBlockGrpImpl::get_ElementID_HLP_IB_GRP(void)
{
return Object->ElementID_HLP_IB_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockGrpImpl::set_ElementID_HLP_IB_GRP(TFIBLargeIntField * ElementID_HLP_IB_GRP)
{
Object->ElementID_HLP_IB_GRP=ElementID_HLP_IB_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprInfBlockGrpImpl::get_ElementIDBASE_HLP_IB_GRP(void)
{
return Object->ElementIDBASE_HLP_IB_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockGrpImpl::set_ElementIDBASE_HLP_IB_GRP(TFIBLargeIntField * ElementIDBASE_HLP_IB_GRP)
{
Object->ElementIDBASE_HLP_IB_GRP=ElementIDBASE_HLP_IB_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockGrpImpl::get_ElementGUID_HLP_IB_GRP(void)
{
return Object->ElementGUID_HLP_IB_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockGrpImpl::set_ElementGUID_HLP_IB_GRP(TFIBWideStringField * ElementGUID_HLP_IB_GRP)
{
Object->ElementGUID_HLP_IB_GRP=ElementGUID_HLP_IB_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockGrpImpl::get_ElementNAME_HLP_IB_GRP(void)
{
return Object->ElementNAME_HLP_IB_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockGrpImpl::set_ElementNAME_HLP_IB_GRP(TFIBWideStringField * ElementNAME_HLP_IB_GRP)
{
Object->ElementNAME_HLP_IB_GRP=ElementNAME_HLP_IB_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprInfBlockGrpImpl::get_ElementIDGRP_HLP_IB_GRP(void)
{
return Object->ElementIDGRP_HLP_IB_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockGrpImpl::set_ElementIDGRP_HLP_IB_GRP(TFIBLargeIntField * ElementIDGRP_HLP_IB_GRP)
{
Object->ElementIDGRP_HLP_IB_GRP=ElementIDGRP_HLP_IB_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockGrpImpl::get_ElementGUID_GRP_HLP_IB_GRP(void)
{
return Object->ElementGUID_GRP_HLP_IB_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockGrpImpl::set_ElementGUID_GRP_HLP_IB_GRP(TFIBWideStringField * ElementGUID_GRP_HLP_IB_GRP)
{
Object->ElementGUID_GRP_HLP_IB_GRP=ElementGUID_GRP_HLP_IB_GRP;
}
//---------------------------------------------------------------
TFIBDateTimeField * THLP_DMSprInfBlockGrpImpl::get_ElementPOS_ISM_HLP_IB_GRP(void)
{
return Object->ElementPOS_ISM_HLP_IB_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockGrpImpl::set_ElementPOS_ISM_HLP_IB_GRP(TFIBDateTimeField * ElementPOS_ISM_HLP_IB_GRP)
{
Object->ElementPOS_ISM_HLP_IB_GRP=ElementPOS_ISM_HLP_IB_GRP;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprInfBlockGrpImpl::get_ElementINDEX_HLP_IB_GRP(void)
{
return Object->ElementINDEX_HLP_IB_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockGrpImpl::set_ElementINDEX_HLP_IB_GRP(TFIBIntegerField * ElementINDEX_HLP_IB_GRP)
{
Object->ElementINDEX_HLP_IB_GRP=ElementINDEX_HLP_IB_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockGrpImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int THLP_DMSprInfBlockGrpImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockGrpImpl::NewElement(__int64 id_grp)
{
return Object->NewElement( id_grp);
}
//---------------------------------------------------------------
bool THLP_DMSprInfBlockGrpImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool THLP_DMSprInfBlockGrpImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 THLP_DMSprInfBlockGrpImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
