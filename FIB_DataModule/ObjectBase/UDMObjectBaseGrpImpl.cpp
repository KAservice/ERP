#include "vcl.h"
#pragma hdrstop


#include "UDMObjectBaseGrpImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMObjectBaseGrpImpl::TDMObjectBaseGrpImpl()           
{                                            
Object=new TDMObjectBaseGrp(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMObjectBaseGrpImpl::~TDMObjectBaseGrpImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMObjectBaseGrpImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMObjectBaseGrpImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMObjectBaseGrp)                        
   {                                                                     
   *ppv=static_cast<IDMObjectBaseGrp*> (this);                                
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
int TDMObjectBaseGrpImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMObjectBaseGrpImpl::kanRelease(void)                                  
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
int  TDMObjectBaseGrpImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMObjectBaseGrpImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMObjectBaseGrpImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMObjectBaseGrpImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMObjectBaseGrpImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMObjectBaseGrpImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMObjectBaseGrpImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMObjectBaseGrp
TDataSource * TDMObjectBaseGrpImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMObjectBaseGrpImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMObjectBaseGrpImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMObjectBaseGrpImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMObjectBaseGrpImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMObjectBaseGrpImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMObjectBaseGrpImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMObjectBaseGrpImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMObjectBaseGrpImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMObjectBaseGrpImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMObjectBaseGrpImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMObjectBaseGrpImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMObjectBaseGrpImpl::get_TableID_OBJECT_BASE_GRP(void)
{
return Object->TableID_OBJECT_BASE_GRP;
}
//---------------------------------------------------------------
void TDMObjectBaseGrpImpl::set_TableID_OBJECT_BASE_GRP(TFIBLargeIntField * TableID_OBJECT_BASE_GRP)
{
Object->TableID_OBJECT_BASE_GRP=TableID_OBJECT_BASE_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMObjectBaseGrpImpl::get_TableIDBASE_OBJECT_BASE_GRP(void)
{
return Object->TableIDBASE_OBJECT_BASE_GRP;
}
//---------------------------------------------------------------
void TDMObjectBaseGrpImpl::set_TableIDBASE_OBJECT_BASE_GRP(TFIBLargeIntField * TableIDBASE_OBJECT_BASE_GRP)
{
Object->TableIDBASE_OBJECT_BASE_GRP=TableIDBASE_OBJECT_BASE_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMObjectBaseGrpImpl::get_TableNAME_OBJECT_BASE_GRP(void)
{
return Object->TableNAME_OBJECT_BASE_GRP;
}
//---------------------------------------------------------------
void TDMObjectBaseGrpImpl::set_TableNAME_OBJECT_BASE_GRP(TFIBWideStringField * TableNAME_OBJECT_BASE_GRP)
{
Object->TableNAME_OBJECT_BASE_GRP=TableNAME_OBJECT_BASE_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMObjectBaseGrpImpl::get_TableIDGRP_OBJECT_BASE_GRP(void)
{
return Object->TableIDGRP_OBJECT_BASE_GRP;
}
//---------------------------------------------------------------
void TDMObjectBaseGrpImpl::set_TableIDGRP_OBJECT_BASE_GRP(TFIBLargeIntField * TableIDGRP_OBJECT_BASE_GRP)
{
Object->TableIDGRP_OBJECT_BASE_GRP=TableIDGRP_OBJECT_BASE_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMObjectBaseGrpImpl::get_ElementID_OBJECT_BASE_GRP(void)
{
return Object->ElementID_OBJECT_BASE_GRP;
}
//---------------------------------------------------------------
void TDMObjectBaseGrpImpl::set_ElementID_OBJECT_BASE_GRP(TFIBLargeIntField * ElementID_OBJECT_BASE_GRP)
{
Object->ElementID_OBJECT_BASE_GRP=ElementID_OBJECT_BASE_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMObjectBaseGrpImpl::get_ElementIDBASE_OBJECT_BASE_GRP(void)
{
return Object->ElementIDBASE_OBJECT_BASE_GRP;
}
//---------------------------------------------------------------
void TDMObjectBaseGrpImpl::set_ElementIDBASE_OBJECT_BASE_GRP(TFIBLargeIntField * ElementIDBASE_OBJECT_BASE_GRP)
{
Object->ElementIDBASE_OBJECT_BASE_GRP=ElementIDBASE_OBJECT_BASE_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMObjectBaseGrpImpl::get_ElementNAME_OBJECT_BASE_GRP(void)
{
return Object->ElementNAME_OBJECT_BASE_GRP;
}
//---------------------------------------------------------------
void TDMObjectBaseGrpImpl::set_ElementNAME_OBJECT_BASE_GRP(TFIBWideStringField * ElementNAME_OBJECT_BASE_GRP)
{
Object->ElementNAME_OBJECT_BASE_GRP=ElementNAME_OBJECT_BASE_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMObjectBaseGrpImpl::get_ElementIDGRP_OBJECT_BASE_GRP(void)
{
return Object->ElementIDGRP_OBJECT_BASE_GRP;
}
//---------------------------------------------------------------
void TDMObjectBaseGrpImpl::set_ElementIDGRP_OBJECT_BASE_GRP(TFIBLargeIntField * ElementIDGRP_OBJECT_BASE_GRP)
{
Object->ElementIDGRP_OBJECT_BASE_GRP=ElementIDGRP_OBJECT_BASE_GRP;
}
//---------------------------------------------------------------
TIntegerField * TDMObjectBaseGrpImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMObjectBaseGrpImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
__int64 TDMObjectBaseGrpImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMObjectBaseGrpImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
void TDMObjectBaseGrpImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
void TDMObjectBaseGrpImpl::Table_First(void)
{
return Object->Table_First();
}
//---------------------------------------------------------------
void TDMObjectBaseGrpImpl::Table_Next(void)
{
return Object->Table_Next();
}
//---------------------------------------------------------------
int TDMObjectBaseGrpImpl::OpenElement(__int64 id)
{
return Object->OpenElement( id);
}
//---------------------------------------------------------------
void TDMObjectBaseGrpImpl::NewElement( __int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TDMObjectBaseGrpImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMObjectBaseGrpImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
void TDMObjectBaseGrpImpl::Element_Edit(void)
{
return Object->Element_Edit();
}
//---------------------------------------------------------------
void TDMObjectBaseGrpImpl::Element_Post(void)
{
return Object->Element_Post();
}
//---------------------------------------------------------------
