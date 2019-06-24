#include "vcl.h"
#pragma hdrstop


#include "UDMExtModuleGrpImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMExtModuleGrpImpl::TDMExtModuleGrpImpl()           
{                                            
Object=new TDMExtModuleGrp(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMExtModuleGrpImpl::~TDMExtModuleGrpImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMExtModuleGrpImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMExtModuleGrpImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMExtModuleGrp)                        
   {                                                                     
   *ppv=static_cast<IDMExtModuleGrp*> (this);                                
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
int TDMExtModuleGrpImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMExtModuleGrpImpl::kanRelease(void)                                  
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
int  TDMExtModuleGrpImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMExtModuleGrpImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMExtModuleGrpImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMExtModuleGrpImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMExtModuleGrpImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMExtModuleGrpImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMExtModuleGrpImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMExtModuleGrp
TDataSource * TDMExtModuleGrpImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMExtModuleGrpImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMExtModuleGrpImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMExtModuleGrpImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMExtModuleGrpImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMExtModuleGrpImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMExtModuleGrpImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMExtModuleGrpImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMExtModuleGrpImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMExtModuleGrpImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMExtModuleGrpImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMExtModuleGrpImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TDMExtModuleGrpImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMExtModuleGrpImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBBCDField * TDMExtModuleGrpImpl::get_TableID_EXT_MODULE_GRP(void)
{
return Object->TableID_EXT_MODULE_GRP;
}
//---------------------------------------------------------------
void TDMExtModuleGrpImpl::set_TableID_EXT_MODULE_GRP(TFIBBCDField * TableID_EXT_MODULE_GRP)
{
Object->TableID_EXT_MODULE_GRP=TableID_EXT_MODULE_GRP;
}
//---------------------------------------------------------------
TFIBBCDField * TDMExtModuleGrpImpl::get_TableIDGRP_EXT_MODULE_GRP(void)
{
return Object->TableIDGRP_EXT_MODULE_GRP;
}
//---------------------------------------------------------------
void TDMExtModuleGrpImpl::set_TableIDGRP_EXT_MODULE_GRP(TFIBBCDField * TableIDGRP_EXT_MODULE_GRP)
{
Object->TableIDGRP_EXT_MODULE_GRP=TableIDGRP_EXT_MODULE_GRP;
}
//---------------------------------------------------------------
TFIBBCDField * TDMExtModuleGrpImpl::get_ElementID_EXT_MODULE_GRP(void)
{
return Object->ElementID_EXT_MODULE_GRP;
}
//---------------------------------------------------------------
void TDMExtModuleGrpImpl::set_ElementID_EXT_MODULE_GRP(TFIBBCDField * ElementID_EXT_MODULE_GRP)
{
Object->ElementID_EXT_MODULE_GRP=ElementID_EXT_MODULE_GRP;
}
//---------------------------------------------------------------
TFIBBCDField * TDMExtModuleGrpImpl::get_ElementIDGRP_EXT_MODULE_GRP(void)
{
return Object->ElementIDGRP_EXT_MODULE_GRP;
}
//---------------------------------------------------------------
void TDMExtModuleGrpImpl::set_ElementIDGRP_EXT_MODULE_GRP(TFIBBCDField * ElementIDGRP_EXT_MODULE_GRP)
{
Object->ElementIDGRP_EXT_MODULE_GRP=ElementIDGRP_EXT_MODULE_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMExtModuleGrpImpl::get_TableNAME_EXT_MODULE_GRP(void)
{
return Object->TableNAME_EXT_MODULE_GRP;
}
//---------------------------------------------------------------
void TDMExtModuleGrpImpl::set_TableNAME_EXT_MODULE_GRP(TFIBWideStringField * TableNAME_EXT_MODULE_GRP)
{
Object->TableNAME_EXT_MODULE_GRP=TableNAME_EXT_MODULE_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMExtModuleGrpImpl::get_ElementNAME_EXT_MODULE_GRP(void)
{
return Object->ElementNAME_EXT_MODULE_GRP;
}
//---------------------------------------------------------------
void TDMExtModuleGrpImpl::set_ElementNAME_EXT_MODULE_GRP(TFIBWideStringField * ElementNAME_EXT_MODULE_GRP)
{
Object->ElementNAME_EXT_MODULE_GRP=ElementNAME_EXT_MODULE_GRP;
}
//---------------------------------------------------------------
void TDMExtModuleGrpImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMExtModuleGrpImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TDMExtModuleGrpImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TDMExtModuleGrpImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMExtModuleGrpImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TDMExtModuleGrpImpl::FindPoName(AnsiString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
