#include "vcl.h"
#pragma hdrstop


#include "UHLP_DMSprNaborInfBlockSostavGrpImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THLP_DMSprNaborInfBlockSostavGrpImpl::THLP_DMSprNaborInfBlockSostavGrpImpl()           
{                                            
Object=new THLP_DMSprNaborInfBlockSostavGrp(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THLP_DMSprNaborInfBlockSostavGrpImpl::~THLP_DMSprNaborInfBlockSostavGrpImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavGrpImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THLP_DMSprNaborInfBlockSostavGrpImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHLP_DMSprNaborInfBlockSostavGrp)                        
   {                                                                     
   *ppv=static_cast<IHLP_DMSprNaborInfBlockSostavGrp*> (this);                                
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
int THLP_DMSprNaborInfBlockSostavGrpImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THLP_DMSprNaborInfBlockSostavGrpImpl::kanRelease(void)                                  
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
int  THLP_DMSprNaborInfBlockSostavGrpImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavGrpImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THLP_DMSprNaborInfBlockSostavGrpImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavGrpImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THLP_DMSprNaborInfBlockSostavGrpImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_THLP_DMSprNaborInfBlockSostavGrpImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THLP_DMSprNaborInfBlockSostavGrpImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IHLP_DMSprNaborInfBlockSostavGrp
TDataSource * THLP_DMSprNaborInfBlockSostavGrpImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavGrpImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * THLP_DMSprNaborInfBlockSostavGrpImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavGrpImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * THLP_DMSprNaborInfBlockSostavGrpImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavGrpImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * THLP_DMSprNaborInfBlockSostavGrpImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavGrpImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * THLP_DMSprNaborInfBlockSostavGrpImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavGrpImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * THLP_DMSprNaborInfBlockSostavGrpImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavGrpImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprNaborInfBlockSostavGrpImpl::get_TableID_HLP_N_IB_S_GRP(void)
{
return Object->TableID_HLP_N_IB_S_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavGrpImpl::set_TableID_HLP_N_IB_S_GRP(TFIBLargeIntField * TableID_HLP_N_IB_S_GRP)
{
Object->TableID_HLP_N_IB_S_GRP=TableID_HLP_N_IB_S_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprNaborInfBlockSostavGrpImpl::get_TableIDBASE_HLP_N_IB_S_GRP(void)
{
return Object->TableIDBASE_HLP_N_IB_S_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavGrpImpl::set_TableIDBASE_HLP_N_IB_S_GRP(TFIBLargeIntField * TableIDBASE_HLP_N_IB_S_GRP)
{
Object->TableIDBASE_HLP_N_IB_S_GRP=TableIDBASE_HLP_N_IB_S_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprNaborInfBlockSostavGrpImpl::get_TableGUID_HLP_N_IB_S_GRP(void)
{
return Object->TableGUID_HLP_N_IB_S_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavGrpImpl::set_TableGUID_HLP_N_IB_S_GRP(TFIBWideStringField * TableGUID_HLP_N_IB_S_GRP)
{
Object->TableGUID_HLP_N_IB_S_GRP=TableGUID_HLP_N_IB_S_GRP;
}
//---------------------------------------------------------------
TFIBDateTimeField * THLP_DMSprNaborInfBlockSostavGrpImpl::get_TablePOS_ISM_HLP_N_IB_S_GRP(void)
{
return Object->TablePOS_ISM_HLP_N_IB_S_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavGrpImpl::set_TablePOS_ISM_HLP_N_IB_S_GRP(TFIBDateTimeField * TablePOS_ISM_HLP_N_IB_S_GRP)
{
Object->TablePOS_ISM_HLP_N_IB_S_GRP=TablePOS_ISM_HLP_N_IB_S_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprNaborInfBlockSostavGrpImpl::get_TableIDGRP_HLP_N_IB_S_GRP(void)
{
return Object->TableIDGRP_HLP_N_IB_S_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavGrpImpl::set_TableIDGRP_HLP_N_IB_S_GRP(TFIBLargeIntField * TableIDGRP_HLP_N_IB_S_GRP)
{
Object->TableIDGRP_HLP_N_IB_S_GRP=TableIDGRP_HLP_N_IB_S_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprNaborInfBlockSostavGrpImpl::get_TableNAME_HLP_N_IB_S_GRP(void)
{
return Object->TableNAME_HLP_N_IB_S_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavGrpImpl::set_TableNAME_HLP_N_IB_S_GRP(TFIBWideStringField * TableNAME_HLP_N_IB_S_GRP)
{
Object->TableNAME_HLP_N_IB_S_GRP=TableNAME_HLP_N_IB_S_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprNaborInfBlockSostavGrpImpl::get_TableIDNABOR_HLP_N_IB_S_GRP(void)
{
return Object->TableIDNABOR_HLP_N_IB_S_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavGrpImpl::set_TableIDNABOR_HLP_N_IB_S_GRP(TFIBLargeIntField * TableIDNABOR_HLP_N_IB_S_GRP)
{
Object->TableIDNABOR_HLP_N_IB_S_GRP=TableIDNABOR_HLP_N_IB_S_GRP;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprNaborInfBlockSostavGrpImpl::get_TableINDEX_HLP_N_IB_S_GRP(void)
{
return Object->TableINDEX_HLP_N_IB_S_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavGrpImpl::set_TableINDEX_HLP_N_IB_S_GRP(TFIBIntegerField * TableINDEX_HLP_N_IB_S_GRP)
{
Object->TableINDEX_HLP_N_IB_S_GRP=TableINDEX_HLP_N_IB_S_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprNaborInfBlockSostavGrpImpl::get_ElementID_HLP_N_IB_S_GRP(void)
{
return Object->ElementID_HLP_N_IB_S_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavGrpImpl::set_ElementID_HLP_N_IB_S_GRP(TFIBLargeIntField * ElementID_HLP_N_IB_S_GRP)
{
Object->ElementID_HLP_N_IB_S_GRP=ElementID_HLP_N_IB_S_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprNaborInfBlockSostavGrpImpl::get_ElementIDBASE_HLP_N_IB_S_GRP(void)
{
return Object->ElementIDBASE_HLP_N_IB_S_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavGrpImpl::set_ElementIDBASE_HLP_N_IB_S_GRP(TFIBLargeIntField * ElementIDBASE_HLP_N_IB_S_GRP)
{
Object->ElementIDBASE_HLP_N_IB_S_GRP=ElementIDBASE_HLP_N_IB_S_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprNaborInfBlockSostavGrpImpl::get_ElementGUID_HLP_N_IB_S_GRP(void)
{
return Object->ElementGUID_HLP_N_IB_S_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavGrpImpl::set_ElementGUID_HLP_N_IB_S_GRP(TFIBWideStringField * ElementGUID_HLP_N_IB_S_GRP)
{
Object->ElementGUID_HLP_N_IB_S_GRP=ElementGUID_HLP_N_IB_S_GRP;
}
//---------------------------------------------------------------
TFIBDateTimeField * THLP_DMSprNaborInfBlockSostavGrpImpl::get_ElementPOS_ISM_HLP_N_IB_S_GRP(void)
{
return Object->ElementPOS_ISM_HLP_N_IB_S_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavGrpImpl::set_ElementPOS_ISM_HLP_N_IB_S_GRP(TFIBDateTimeField * ElementPOS_ISM_HLP_N_IB_S_GRP)
{
Object->ElementPOS_ISM_HLP_N_IB_S_GRP=ElementPOS_ISM_HLP_N_IB_S_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprNaborInfBlockSostavGrpImpl::get_ElementIDGRP_HLP_N_IB_S_GRP(void)
{
return Object->ElementIDGRP_HLP_N_IB_S_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavGrpImpl::set_ElementIDGRP_HLP_N_IB_S_GRP(TFIBLargeIntField * ElementIDGRP_HLP_N_IB_S_GRP)
{
Object->ElementIDGRP_HLP_N_IB_S_GRP=ElementIDGRP_HLP_N_IB_S_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprNaborInfBlockSostavGrpImpl::get_ElementNAME_HLP_N_IB_S_GRP(void)
{
return Object->ElementNAME_HLP_N_IB_S_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavGrpImpl::set_ElementNAME_HLP_N_IB_S_GRP(TFIBWideStringField * ElementNAME_HLP_N_IB_S_GRP)
{
Object->ElementNAME_HLP_N_IB_S_GRP=ElementNAME_HLP_N_IB_S_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprNaborInfBlockSostavGrpImpl::get_ElementIDNABOR_HLP_N_IB_S_GRP(void)
{
return Object->ElementIDNABOR_HLP_N_IB_S_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavGrpImpl::set_ElementIDNABOR_HLP_N_IB_S_GRP(TFIBLargeIntField * ElementIDNABOR_HLP_N_IB_S_GRP)
{
Object->ElementIDNABOR_HLP_N_IB_S_GRP=ElementIDNABOR_HLP_N_IB_S_GRP;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprNaborInfBlockSostavGrpImpl::get_ElementINDEX_HLP_N_IB_S_GRP(void)
{
return Object->ElementINDEX_HLP_N_IB_S_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavGrpImpl::set_ElementINDEX_HLP_N_IB_S_GRP(TFIBIntegerField * ElementINDEX_HLP_N_IB_S_GRP)
{
Object->ElementINDEX_HLP_N_IB_S_GRP=ElementINDEX_HLP_N_IB_S_GRP;
}
//---------------------------------------------------------------
__int64 THLP_DMSprNaborInfBlockSostavGrpImpl::get_IdGroupElement(void)
{
return Object->IdGroupElement;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavGrpImpl::set_IdGroupElement(__int64 IdGroupElement)
{
Object->IdGroupElement=IdGroupElement;
}
//---------------------------------------------------------------
__int64 THLP_DMSprNaborInfBlockSostavGrpImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavGrpImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
__int64 THLP_DMSprNaborInfBlockSostavGrpImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavGrpImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
bool THLP_DMSprNaborInfBlockSostavGrpImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavGrpImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
bool THLP_DMSprNaborInfBlockSostavGrpImpl::OpenTable(__int64 id_group_element)
{
return Object->OpenTable(id_group_element);
}
//---------------------------------------------------------------
bool THLP_DMSprNaborInfBlockSostavGrpImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool THLP_DMSprNaborInfBlockSostavGrpImpl::NewElement(__int64 id_group_element, __int64 id_grp)
{
return Object->NewElement(id_group_element,  id_grp);
}
//---------------------------------------------------------------
bool THLP_DMSprNaborInfBlockSostavGrpImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool THLP_DMSprNaborInfBlockSostavGrpImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
