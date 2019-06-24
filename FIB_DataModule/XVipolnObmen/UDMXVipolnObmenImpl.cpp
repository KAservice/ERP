#include "vcl.h"
#pragma hdrstop


#include "UDMXVipolnObmenImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMXVipolnObmenImpl::TDMXVipolnObmenImpl()           
{                                            
Object=new TDMXVipolnObmen(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMXVipolnObmenImpl::~TDMXVipolnObmenImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMXVipolnObmenImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMXVipolnObmenImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMXVipolnObmen)                        
   {                                                                     
   *ppv=static_cast<IDMXVipolnObmen*> (this);                                
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
int TDMXVipolnObmenImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMXVipolnObmenImpl::kanRelease(void)                                  
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
int  TDMXVipolnObmenImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMXVipolnObmenImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMXVipolnObmenImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMXVipolnObmenImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMXVipolnObmenImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMXVipolnObmenImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMXVipolnObmenImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMXVipolnObmen
TDataSource * TDMXVipolnObmenImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMXVipolnObmenImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMXVipolnObmenImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMXVipolnObmenImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMXVipolnObmenImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMXVipolnObmenImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMXVipolnObmenImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMXVipolnObmenImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMXVipolnObmenImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMXVipolnObmenImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMXVipolnObmenImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMXVipolnObmenImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TDMXVipolnObmenImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TDMXVipolnObmenImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMXVipolnObmenImpl::get_TableID_XVIPOLN_OBMEN(void)
{
return Object->TableID_XVIPOLN_OBMEN;
}
//---------------------------------------------------------------
void TDMXVipolnObmenImpl::set_TableID_XVIPOLN_OBMEN(TFIBLargeIntField * TableID_XVIPOLN_OBMEN)
{
Object->TableID_XVIPOLN_OBMEN=TableID_XVIPOLN_OBMEN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMXVipolnObmenImpl::get_TableIDBASE_XVIPOLN_OBMEN(void)
{
return Object->TableIDBASE_XVIPOLN_OBMEN;
}
//---------------------------------------------------------------
void TDMXVipolnObmenImpl::set_TableIDBASE_XVIPOLN_OBMEN(TFIBLargeIntField * TableIDBASE_XVIPOLN_OBMEN)
{
Object->TableIDBASE_XVIPOLN_OBMEN=TableIDBASE_XVIPOLN_OBMEN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMXVipolnObmenImpl::get_TableIDINFBASE_XVIPOLN_OBMEN(void)
{
return Object->TableIDINFBASE_XVIPOLN_OBMEN;
}
//---------------------------------------------------------------
void TDMXVipolnObmenImpl::set_TableIDINFBASE_XVIPOLN_OBMEN(TFIBLargeIntField * TableIDINFBASE_XVIPOLN_OBMEN)
{
Object->TableIDINFBASE_XVIPOLN_OBMEN=TableIDINFBASE_XVIPOLN_OBMEN;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMXVipolnObmenImpl::get_TablePOS_ZAGR_XVIPOLN_OBMEN(void)
{
return Object->TablePOS_ZAGR_XVIPOLN_OBMEN;
}
//---------------------------------------------------------------
void TDMXVipolnObmenImpl::set_TablePOS_ZAGR_XVIPOLN_OBMEN(TFIBDateTimeField * TablePOS_ZAGR_XVIPOLN_OBMEN)
{
Object->TablePOS_ZAGR_XVIPOLN_OBMEN=TablePOS_ZAGR_XVIPOLN_OBMEN;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMXVipolnObmenImpl::get_TablePOS_VIGR_XVIPOLN_OBMEN(void)
{
return Object->TablePOS_VIGR_XVIPOLN_OBMEN;
}
//---------------------------------------------------------------
void TDMXVipolnObmenImpl::set_TablePOS_VIGR_XVIPOLN_OBMEN(TFIBDateTimeField * TablePOS_VIGR_XVIPOLN_OBMEN)
{
Object->TablePOS_VIGR_XVIPOLN_OBMEN=TablePOS_VIGR_XVIPOLN_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMXVipolnObmenImpl::get_TableNAME_SINFBASE_OBMEN(void)
{
return Object->TableNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMXVipolnObmenImpl::set_TableNAME_SINFBASE_OBMEN(TFIBWideStringField * TableNAME_SINFBASE_OBMEN)
{
Object->TableNAME_SINFBASE_OBMEN=TableNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMXVipolnObmenImpl::get_TableNOACT_SINFBASE_OBMEN(void)
{
return Object->TableNOACT_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMXVipolnObmenImpl::set_TableNOACT_SINFBASE_OBMEN(TFIBSmallIntField * TableNOACT_SINFBASE_OBMEN)
{
Object->TableNOACT_SINFBASE_OBMEN=TableNOACT_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMXVipolnObmenImpl::get_ElementID_XVIPOLN_OBMEN(void)
{
return Object->ElementID_XVIPOLN_OBMEN;
}
//---------------------------------------------------------------
void TDMXVipolnObmenImpl::set_ElementID_XVIPOLN_OBMEN(TFIBLargeIntField * ElementID_XVIPOLN_OBMEN)
{
Object->ElementID_XVIPOLN_OBMEN=ElementID_XVIPOLN_OBMEN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMXVipolnObmenImpl::get_ElementIDBASE_XVIPOLN_OBMEN(void)
{
return Object->ElementIDBASE_XVIPOLN_OBMEN;
}
//---------------------------------------------------------------
void TDMXVipolnObmenImpl::set_ElementIDBASE_XVIPOLN_OBMEN(TFIBLargeIntField * ElementIDBASE_XVIPOLN_OBMEN)
{
Object->ElementIDBASE_XVIPOLN_OBMEN=ElementIDBASE_XVIPOLN_OBMEN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMXVipolnObmenImpl::get_ElementIDINFBASE_XVIPOLN_OBMEN(void)
{
return Object->ElementIDINFBASE_XVIPOLN_OBMEN;
}
//---------------------------------------------------------------
void TDMXVipolnObmenImpl::set_ElementIDINFBASE_XVIPOLN_OBMEN(TFIBLargeIntField * ElementIDINFBASE_XVIPOLN_OBMEN)
{
Object->ElementIDINFBASE_XVIPOLN_OBMEN=ElementIDINFBASE_XVIPOLN_OBMEN;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMXVipolnObmenImpl::get_ElementPOS_ZAGR_XVIPOLN_OBMEN(void)
{
return Object->ElementPOS_ZAGR_XVIPOLN_OBMEN;
}
//---------------------------------------------------------------
void TDMXVipolnObmenImpl::set_ElementPOS_ZAGR_XVIPOLN_OBMEN(TFIBDateTimeField * ElementPOS_ZAGR_XVIPOLN_OBMEN)
{
Object->ElementPOS_ZAGR_XVIPOLN_OBMEN=ElementPOS_ZAGR_XVIPOLN_OBMEN;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMXVipolnObmenImpl::get_ElementPOS_VIGR_XVIPOLN_OBMEN(void)
{
return Object->ElementPOS_VIGR_XVIPOLN_OBMEN;
}
//---------------------------------------------------------------
void TDMXVipolnObmenImpl::set_ElementPOS_VIGR_XVIPOLN_OBMEN(TFIBDateTimeField * ElementPOS_VIGR_XVIPOLN_OBMEN)
{
Object->ElementPOS_VIGR_XVIPOLN_OBMEN=ElementPOS_VIGR_XVIPOLN_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMXVipolnObmenImpl::get_ElementNAME_SINFBASE_OBMEN(void)
{
return Object->ElementNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMXVipolnObmenImpl::set_ElementNAME_SINFBASE_OBMEN(TFIBWideStringField * ElementNAME_SINFBASE_OBMEN)
{
Object->ElementNAME_SINFBASE_OBMEN=ElementNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMXVipolnObmenImpl::get_ElementNOACT_SINFBASE_OBMEN(void)
{
return Object->ElementNOACT_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMXVipolnObmenImpl::set_ElementNOACT_SINFBASE_OBMEN(TFIBSmallIntField * ElementNOACT_SINFBASE_OBMEN)
{
Object->ElementNOACT_SINFBASE_OBMEN=ElementNOACT_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
__int64 TDMXVipolnObmenImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMXVipolnObmenImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TDMXVipolnObmenImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TDMXVipolnObmenImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
__int64 TDMXVipolnObmenImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TDMXVipolnObmenImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void TDMXVipolnObmenImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
UnicodeString TDMXVipolnObmenImpl::GetTextQuery(__int64 id_grp, bool all)
{
return Object->GetTextQuery(id_grp,all);
}
//---------------------------------------------------------------
int TDMXVipolnObmenImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool TDMXVipolnObmenImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMXVipolnObmenImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMXVipolnObmenImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
void TDMXVipolnObmenImpl::ChancheGrp(__int64 id_new_grp,__int64 id_element)
{
return Object->ChancheGrp(id_new_grp,id_element);
}
//---------------------------------------------------------------
__int64 TDMXVipolnObmenImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
__int64 TDMXVipolnObmenImpl::FindPoIdBase(__int64 id_base)
{
return Object->FindPoIdBase(id_base);
}
//---------------------------------------------------------------
__int64 TDMXVipolnObmenImpl::GetIdGrp(__int64 id_el)
{
return Object->GetIdGrp(id_el);
}
//---------------------------------------------------------------
