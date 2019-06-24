#include "vcl.h"
#pragma hdrstop


#include "UDMSprInfBaseImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprInfBaseImpl::TDMSprInfBaseImpl()           
{                                            
Object=new TDMSprInfBase(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprInfBaseImpl::~TDMSprInfBaseImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprInfBaseImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprInfBaseImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprInfBase)                        
   {                                                                     
   *ppv=static_cast<IDMSprInfBase*> (this);                                
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
int TDMSprInfBaseImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprInfBaseImpl::kanRelease(void)                                  
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
int  TDMSprInfBaseImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprInfBaseImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprInfBaseImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprInfBaseImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprInfBaseImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprInfBaseImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprInfBaseImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprInfBase
TDataSource * TDMSprInfBaseImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprInfBaseImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprInfBaseImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprInfBaseImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprInfBaseImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprInfBaseImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprInfBaseImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprInfBaseImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprInfBaseImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprInfBaseImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprInfBaseImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprInfBaseImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMSprInfBaseImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprInfBaseImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprInfBaseImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprInfBaseImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprInfBaseImpl::get_TableID_SINFBASE_OBMEN(void)
{
return Object->TableID_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMSprInfBaseImpl::set_TableID_SINFBASE_OBMEN(TFIBBCDField * TableID_SINFBASE_OBMEN)
{
Object->TableID_SINFBASE_OBMEN=TableID_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprInfBaseImpl::get_TableIDTIZM_SINFBASE_OBMEN(void)
{
return Object->TableIDTIZM_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMSprInfBaseImpl::set_TableIDTIZM_SINFBASE_OBMEN(TFIBIntegerField * TableIDTIZM_SINFBASE_OBMEN)
{
Object->TableIDTIZM_SINFBASE_OBMEN=TableIDTIZM_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprInfBaseImpl::get_ElementID_SINFBASE_OBMEN(void)
{
return Object->ElementID_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMSprInfBaseImpl::set_ElementID_SINFBASE_OBMEN(TFIBBCDField * ElementID_SINFBASE_OBMEN)
{
Object->ElementID_SINFBASE_OBMEN=ElementID_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprInfBaseImpl::get_ElementIDTIZM_SINFBASE_OBMEN(void)
{
return Object->ElementIDTIZM_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMSprInfBaseImpl::set_ElementIDTIZM_SINFBASE_OBMEN(TFIBIntegerField * ElementIDTIZM_SINFBASE_OBMEN)
{
Object->ElementIDTIZM_SINFBASE_OBMEN=ElementIDTIZM_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprInfBaseImpl::get_ElementNOACT_SINFBASE_OBMEN(void)
{
return Object->ElementNOACT_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMSprInfBaseImpl::set_ElementNOACT_SINFBASE_OBMEN(TFIBSmallIntField * ElementNOACT_SINFBASE_OBMEN)
{
Object->ElementNOACT_SINFBASE_OBMEN=ElementNOACT_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprInfBaseImpl::get_TableNOACT_SINFBASE_OBMEN(void)
{
return Object->TableNOACT_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMSprInfBaseImpl::set_TableNOACT_SINFBASE_OBMEN(TFIBSmallIntField * TableNOACT_SINFBASE_OBMEN)
{
Object->TableNOACT_SINFBASE_OBMEN=TableNOACT_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprInfBaseImpl::get_TableGID_SINFBASE_OBMEN(void)
{
return Object->TableGID_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMSprInfBaseImpl::set_TableGID_SINFBASE_OBMEN(TFIBWideStringField * TableGID_SINFBASE_OBMEN)
{
Object->TableGID_SINFBASE_OBMEN=TableGID_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprInfBaseImpl::get_TableNAME_SINFBASE_OBMEN(void)
{
return Object->TableNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMSprInfBaseImpl::set_TableNAME_SINFBASE_OBMEN(TFIBWideStringField * TableNAME_SINFBASE_OBMEN)
{
Object->TableNAME_SINFBASE_OBMEN=TableNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprInfBaseImpl::get_ElementGID_SINFBASE_OBMEN(void)
{
return Object->ElementGID_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMSprInfBaseImpl::set_ElementGID_SINFBASE_OBMEN(TFIBWideStringField * ElementGID_SINFBASE_OBMEN)
{
Object->ElementGID_SINFBASE_OBMEN=ElementGID_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprInfBaseImpl::get_ElementNAME_SINFBASE_OBMEN(void)
{
return Object->ElementNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMSprInfBaseImpl::set_ElementNAME_SINFBASE_OBMEN(TFIBWideStringField * ElementNAME_SINFBASE_OBMEN)
{
Object->ElementNAME_SINFBASE_OBMEN=ElementNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprInfBaseImpl::get_ElementPREF_NUM_SINFBASE_OBMEN(void)
{
return Object->ElementPREF_NUM_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMSprInfBaseImpl::set_ElementPREF_NUM_SINFBASE_OBMEN(TFIBWideStringField * ElementPREF_NUM_SINFBASE_OBMEN)
{
Object->ElementPREF_NUM_SINFBASE_OBMEN=ElementPREF_NUM_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
__int64 TDMSprInfBaseImpl::GetIdPoPrefiks(AnsiString prefiks)
{
return Object->GetIdPoPrefiks(prefiks);
}
//---------------------------------------------------------------
__int64 TDMSprInfBaseImpl::GetIdPoName(AnsiString name)
{
return Object->GetIdPoName(name);
}
//---------------------------------------------------------------
void TDMSprInfBaseImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprInfBaseImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TDMSprInfBaseImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprInfBaseImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprInfBaseImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
