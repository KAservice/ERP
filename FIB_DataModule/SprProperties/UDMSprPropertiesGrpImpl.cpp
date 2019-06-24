#include "vcl.h"
#pragma hdrstop


#include "UDMSprPropertiesGrpImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprPropertiesGrpImpl::TDMSprPropertiesGrpImpl()           
{                                            
Object=new TDMSprPropertiesGrp(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprPropertiesGrpImpl::~TDMSprPropertiesGrpImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprPropertiesGrpImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprPropertiesGrpImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprPropertiesGrp)                        
   {                                                                     
   *ppv=static_cast<IDMSprPropertiesGrp*> (this);                                
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
int TDMSprPropertiesGrpImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprPropertiesGrpImpl::kanRelease(void)                                  
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
int  TDMSprPropertiesGrpImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprPropertiesGrpImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprPropertiesGrpImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprPropertiesGrpImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprPropertiesGrpImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprPropertiesGrpImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprPropertiesGrpImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprPropertiesGrp
TDataSource * TDMSprPropertiesGrpImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprPropertiesGrpImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprPropertiesGrpImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprPropertiesGrpImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprPropertiesGrpImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprPropertiesGrpImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprPropertiesGrpImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprPropertiesGrpImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprPropertiesGrpImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprPropertiesGrpImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprPropertiesGrpImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprPropertiesGrpImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprPropertiesGrpImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprPropertiesGrpImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesGrpImpl::get_TableID_SPROP_GRP(void)
{
return Object->TableID_SPROP_GRP;
}
//---------------------------------------------------------------
void TDMSprPropertiesGrpImpl::set_TableID_SPROP_GRP(TFIBLargeIntField * TableID_SPROP_GRP)
{
Object->TableID_SPROP_GRP=TableID_SPROP_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesGrpImpl::get_TableIDBASE_SPROP_GRP(void)
{
return Object->TableIDBASE_SPROP_GRP;
}
//---------------------------------------------------------------
void TDMSprPropertiesGrpImpl::set_TableIDBASE_SPROP_GRP(TFIBLargeIntField * TableIDBASE_SPROP_GRP)
{
Object->TableIDBASE_SPROP_GRP=TableIDBASE_SPROP_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPropertiesGrpImpl::get_TableGID_SPROP_GRP(void)
{
return Object->TableGID_SPROP_GRP;
}
//---------------------------------------------------------------
void TDMSprPropertiesGrpImpl::set_TableGID_SPROP_GRP(TFIBWideStringField * TableGID_SPROP_GRP)
{
Object->TableGID_SPROP_GRP=TableGID_SPROP_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesGrpImpl::get_TableIDGRP_SPROP_GRP(void)
{
return Object->TableIDGRP_SPROP_GRP;
}
//---------------------------------------------------------------
void TDMSprPropertiesGrpImpl::set_TableIDGRP_SPROP_GRP(TFIBLargeIntField * TableIDGRP_SPROP_GRP)
{
Object->TableIDGRP_SPROP_GRP=TableIDGRP_SPROP_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPropertiesGrpImpl::get_TableNAME_SPROP_GRP(void)
{
return Object->TableNAME_SPROP_GRP;
}
//---------------------------------------------------------------
void TDMSprPropertiesGrpImpl::set_TableNAME_SPROP_GRP(TFIBWideStringField * TableNAME_SPROP_GRP)
{
Object->TableNAME_SPROP_GRP=TableNAME_SPROP_GRP;
}
//---------------------------------------------------------------
TIntegerField * TDMSprPropertiesGrpImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprPropertiesGrpImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesGrpImpl::get_ElementID_SPROP_GRP(void)
{
return Object->ElementID_SPROP_GRP;
}
//---------------------------------------------------------------
void TDMSprPropertiesGrpImpl::set_ElementID_SPROP_GRP(TFIBLargeIntField * ElementID_SPROP_GRP)
{
Object->ElementID_SPROP_GRP=ElementID_SPROP_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesGrpImpl::get_ElementIDBASE_SPROP_GRP(void)
{
return Object->ElementIDBASE_SPROP_GRP;
}
//---------------------------------------------------------------
void TDMSprPropertiesGrpImpl::set_ElementIDBASE_SPROP_GRP(TFIBLargeIntField * ElementIDBASE_SPROP_GRP)
{
Object->ElementIDBASE_SPROP_GRP=ElementIDBASE_SPROP_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPropertiesGrpImpl::get_ElementGID_SPROP_GRP(void)
{
return Object->ElementGID_SPROP_GRP;
}
//---------------------------------------------------------------
void TDMSprPropertiesGrpImpl::set_ElementGID_SPROP_GRP(TFIBWideStringField * ElementGID_SPROP_GRP)
{
Object->ElementGID_SPROP_GRP=ElementGID_SPROP_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesGrpImpl::get_ElementIDGRP_SPROP_GRP(void)
{
return Object->ElementIDGRP_SPROP_GRP;
}
//---------------------------------------------------------------
void TDMSprPropertiesGrpImpl::set_ElementIDGRP_SPROP_GRP(TFIBLargeIntField * ElementIDGRP_SPROP_GRP)
{
Object->ElementIDGRP_SPROP_GRP=ElementIDGRP_SPROP_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPropertiesGrpImpl::get_ElementNAME_SPROP_GRP(void)
{
return Object->ElementNAME_SPROP_GRP;
}
//---------------------------------------------------------------
void TDMSprPropertiesGrpImpl::set_ElementNAME_SPROP_GRP(TFIBWideStringField * ElementNAME_SPROP_GRP)
{
Object->ElementNAME_SPROP_GRP=ElementNAME_SPROP_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPropertiesGrpImpl::get_ElementNAME_FOR_PRINT_SPROP_GRP(void)
{
return Object->ElementNAME_FOR_PRINT_SPROP_GRP;
}
//---------------------------------------------------------------
void TDMSprPropertiesGrpImpl::set_ElementNAME_FOR_PRINT_SPROP_GRP(TFIBWideStringField * ElementNAME_FOR_PRINT_SPROP_GRP)
{
Object->ElementNAME_FOR_PRINT_SPROP_GRP=ElementNAME_FOR_PRINT_SPROP_GRP;
}
//---------------------------------------------------------------
void TDMSprPropertiesGrpImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprPropertiesGrpImpl::OpenElement(__int64 id)
{
return Object->OpenElement( id);
}
//---------------------------------------------------------------
void TDMSprPropertiesGrpImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TDMSprPropertiesGrpImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprPropertiesGrpImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TDMSprPropertiesGrpImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
