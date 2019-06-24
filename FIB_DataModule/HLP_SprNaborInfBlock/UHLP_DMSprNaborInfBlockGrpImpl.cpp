#include "vcl.h"
#pragma hdrstop


#include "UHLP_DMSprNaborInfBlockGrpImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THLP_DMSprNaborInfBlockGrpImpl::THLP_DMSprNaborInfBlockGrpImpl()           
{                                            
Object=new THLP_DMSprNaborInfBlockGrp(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THLP_DMSprNaborInfBlockGrpImpl::~THLP_DMSprNaborInfBlockGrpImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockGrpImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THLP_DMSprNaborInfBlockGrpImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHLP_DMSprNaborInfBlockGrp)                        
   {                                                                     
   *ppv=static_cast<IHLP_DMSprNaborInfBlockGrp*> (this);                                
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
int THLP_DMSprNaborInfBlockGrpImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THLP_DMSprNaborInfBlockGrpImpl::kanRelease(void)                                  
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
int  THLP_DMSprNaborInfBlockGrpImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockGrpImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THLP_DMSprNaborInfBlockGrpImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockGrpImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THLP_DMSprNaborInfBlockGrpImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_THLP_DMSprNaborInfBlockGrpImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THLP_DMSprNaborInfBlockGrpImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IHLP_DMSprNaborInfBlockGrp
TDataSource * THLP_DMSprNaborInfBlockGrpImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockGrpImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * THLP_DMSprNaborInfBlockGrpImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockGrpImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * THLP_DMSprNaborInfBlockGrpImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockGrpImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * THLP_DMSprNaborInfBlockGrpImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockGrpImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * THLP_DMSprNaborInfBlockGrpImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockGrpImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * THLP_DMSprNaborInfBlockGrpImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockGrpImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprNaborInfBlockGrpImpl::get_TableID_HLP_N_IB_GRP(void)
{
return Object->TableID_HLP_N_IB_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockGrpImpl::set_TableID_HLP_N_IB_GRP(TFIBLargeIntField * TableID_HLP_N_IB_GRP)
{
Object->TableID_HLP_N_IB_GRP=TableID_HLP_N_IB_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprNaborInfBlockGrpImpl::get_TableIDBASE_HLP_N_IB_GRP(void)
{
return Object->TableIDBASE_HLP_N_IB_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockGrpImpl::set_TableIDBASE_HLP_N_IB_GRP(TFIBLargeIntField * TableIDBASE_HLP_N_IB_GRP)
{
Object->TableIDBASE_HLP_N_IB_GRP=TableIDBASE_HLP_N_IB_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprNaborInfBlockGrpImpl::get_TableGUID_HLP_N_IB_GRP(void)
{
return Object->TableGUID_HLP_N_IB_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockGrpImpl::set_TableGUID_HLP_N_IB_GRP(TFIBWideStringField * TableGUID_HLP_N_IB_GRP)
{
Object->TableGUID_HLP_N_IB_GRP=TableGUID_HLP_N_IB_GRP;
}
//---------------------------------------------------------------
TFIBDateTimeField * THLP_DMSprNaborInfBlockGrpImpl::get_TablePOS_ISM_HLP_N_IB_GRP(void)
{
return Object->TablePOS_ISM_HLP_N_IB_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockGrpImpl::set_TablePOS_ISM_HLP_N_IB_GRP(TFIBDateTimeField * TablePOS_ISM_HLP_N_IB_GRP)
{
Object->TablePOS_ISM_HLP_N_IB_GRP=TablePOS_ISM_HLP_N_IB_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprNaborInfBlockGrpImpl::get_TableIDGRP_HLP_N_IB_GRP(void)
{
return Object->TableIDGRP_HLP_N_IB_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockGrpImpl::set_TableIDGRP_HLP_N_IB_GRP(TFIBLargeIntField * TableIDGRP_HLP_N_IB_GRP)
{
Object->TableIDGRP_HLP_N_IB_GRP=TableIDGRP_HLP_N_IB_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprNaborInfBlockGrpImpl::get_TableNAME_HLP_N_IB_GRP(void)
{
return Object->TableNAME_HLP_N_IB_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockGrpImpl::set_TableNAME_HLP_N_IB_GRP(TFIBWideStringField * TableNAME_HLP_N_IB_GRP)
{
Object->TableNAME_HLP_N_IB_GRP=TableNAME_HLP_N_IB_GRP;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprNaborInfBlockGrpImpl::get_TableINDEX_HLP_N_IB_GRP(void)
{
return Object->TableINDEX_HLP_N_IB_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockGrpImpl::set_TableINDEX_HLP_N_IB_GRP(TFIBIntegerField * TableINDEX_HLP_N_IB_GRP)
{
Object->TableINDEX_HLP_N_IB_GRP=TableINDEX_HLP_N_IB_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprNaborInfBlockGrpImpl::get_ElementID_HLP_N_IB_GRP(void)
{
return Object->ElementID_HLP_N_IB_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockGrpImpl::set_ElementID_HLP_N_IB_GRP(TFIBLargeIntField * ElementID_HLP_N_IB_GRP)
{
Object->ElementID_HLP_N_IB_GRP=ElementID_HLP_N_IB_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprNaborInfBlockGrpImpl::get_ElementIDBASE_HLP_N_IB_GRP(void)
{
return Object->ElementIDBASE_HLP_N_IB_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockGrpImpl::set_ElementIDBASE_HLP_N_IB_GRP(TFIBLargeIntField * ElementIDBASE_HLP_N_IB_GRP)
{
Object->ElementIDBASE_HLP_N_IB_GRP=ElementIDBASE_HLP_N_IB_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprNaborInfBlockGrpImpl::get_ElementGUID_HLP_N_IB_GRP(void)
{
return Object->ElementGUID_HLP_N_IB_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockGrpImpl::set_ElementGUID_HLP_N_IB_GRP(TFIBWideStringField * ElementGUID_HLP_N_IB_GRP)
{
Object->ElementGUID_HLP_N_IB_GRP=ElementGUID_HLP_N_IB_GRP;
}
//---------------------------------------------------------------
TFIBDateTimeField * THLP_DMSprNaborInfBlockGrpImpl::get_ElementPOS_ISM_HLP_N_IB_GRP(void)
{
return Object->ElementPOS_ISM_HLP_N_IB_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockGrpImpl::set_ElementPOS_ISM_HLP_N_IB_GRP(TFIBDateTimeField * ElementPOS_ISM_HLP_N_IB_GRP)
{
Object->ElementPOS_ISM_HLP_N_IB_GRP=ElementPOS_ISM_HLP_N_IB_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprNaborInfBlockGrpImpl::get_ElementIDGRP_HLP_N_IB_GRP(void)
{
return Object->ElementIDGRP_HLP_N_IB_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockGrpImpl::set_ElementIDGRP_HLP_N_IB_GRP(TFIBLargeIntField * ElementIDGRP_HLP_N_IB_GRP)
{
Object->ElementIDGRP_HLP_N_IB_GRP=ElementIDGRP_HLP_N_IB_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprNaborInfBlockGrpImpl::get_ElementNAME_HLP_N_IB_GRP(void)
{
return Object->ElementNAME_HLP_N_IB_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockGrpImpl::set_ElementNAME_HLP_N_IB_GRP(TFIBWideStringField * ElementNAME_HLP_N_IB_GRP)
{
Object->ElementNAME_HLP_N_IB_GRP=ElementNAME_HLP_N_IB_GRP;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprNaborInfBlockGrpImpl::get_ElementINDEX_HLP_N_IB_GRP(void)
{
return Object->ElementINDEX_HLP_N_IB_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockGrpImpl::set_ElementINDEX_HLP_N_IB_GRP(TFIBIntegerField * ElementINDEX_HLP_N_IB_GRP)
{
Object->ElementINDEX_HLP_N_IB_GRP=ElementINDEX_HLP_N_IB_GRP;
}
//---------------------------------------------------------------
__int64 THLP_DMSprNaborInfBlockGrpImpl::get_IdGroupElement(void)
{
return Object->IdGroupElement;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockGrpImpl::set_IdGroupElement(__int64 IdGroupElement)
{
Object->IdGroupElement=IdGroupElement;
}
//---------------------------------------------------------------
__int64 THLP_DMSprNaborInfBlockGrpImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockGrpImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
__int64 THLP_DMSprNaborInfBlockGrpImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockGrpImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
bool THLP_DMSprNaborInfBlockGrpImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockGrpImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
bool THLP_DMSprNaborInfBlockGrpImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
bool THLP_DMSprNaborInfBlockGrpImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool THLP_DMSprNaborInfBlockGrpImpl::NewElement( __int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool THLP_DMSprNaborInfBlockGrpImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool THLP_DMSprNaborInfBlockGrpImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
