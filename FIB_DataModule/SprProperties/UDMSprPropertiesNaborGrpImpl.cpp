#include "vcl.h"
#pragma hdrstop


#include "UDMSprPropertiesNaborGrpImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprPropertiesNaborGrpImpl::TDMSprPropertiesNaborGrpImpl()           
{                                            
Object=new TDMSprPropertiesNaborGrp(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprPropertiesNaborGrpImpl::~TDMSprPropertiesNaborGrpImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprPropertiesNaborGrpImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprPropertiesNaborGrpImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprPropertiesNaborGrp)                        
   {                                                                     
   *ppv=static_cast<IDMSprPropertiesNaborGrp*> (this);                                
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
int TDMSprPropertiesNaborGrpImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprPropertiesNaborGrpImpl::kanRelease(void)                                  
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
int  TDMSprPropertiesNaborGrpImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprPropertiesNaborGrpImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprPropertiesNaborGrpImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprPropertiesNaborGrpImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprPropertiesNaborGrpImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprPropertiesNaborGrpImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprPropertiesNaborGrpImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprPropertiesNaborGrp
TDataSource * TDMSprPropertiesNaborGrpImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborGrpImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprPropertiesNaborGrpImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborGrpImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprPropertiesNaborGrpImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborGrpImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprPropertiesNaborGrpImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborGrpImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprPropertiesNaborGrpImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborGrpImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprPropertiesNaborGrpImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborGrpImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprPropertiesNaborGrpImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborGrpImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TIntegerField * TDMSprPropertiesNaborGrpImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborGrpImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesNaborGrpImpl::get_TableID_SPROPNABOR_GRP(void)
{
return Object->TableID_SPROPNABOR_GRP;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborGrpImpl::set_TableID_SPROPNABOR_GRP(TFIBLargeIntField * TableID_SPROPNABOR_GRP)
{
Object->TableID_SPROPNABOR_GRP=TableID_SPROPNABOR_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesNaborGrpImpl::get_TableIDBASE_SPROPNABOR_GRP(void)
{
return Object->TableIDBASE_SPROPNABOR_GRP;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborGrpImpl::set_TableIDBASE_SPROPNABOR_GRP(TFIBLargeIntField * TableIDBASE_SPROPNABOR_GRP)
{
Object->TableIDBASE_SPROPNABOR_GRP=TableIDBASE_SPROPNABOR_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPropertiesNaborGrpImpl::get_TableGID_SPROPNABOR_GRP(void)
{
return Object->TableGID_SPROPNABOR_GRP;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborGrpImpl::set_TableGID_SPROPNABOR_GRP(TFIBWideStringField * TableGID_SPROPNABOR_GRP)
{
Object->TableGID_SPROPNABOR_GRP=TableGID_SPROPNABOR_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesNaborGrpImpl::get_TableIDGRP_SPROPNABOR_GRP(void)
{
return Object->TableIDGRP_SPROPNABOR_GRP;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborGrpImpl::set_TableIDGRP_SPROPNABOR_GRP(TFIBLargeIntField * TableIDGRP_SPROPNABOR_GRP)
{
Object->TableIDGRP_SPROPNABOR_GRP=TableIDGRP_SPROPNABOR_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPropertiesNaborGrpImpl::get_TableNAME_SPROPNABOR_GRP(void)
{
return Object->TableNAME_SPROPNABOR_GRP;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborGrpImpl::set_TableNAME_SPROPNABOR_GRP(TFIBWideStringField * TableNAME_SPROPNABOR_GRP)
{
Object->TableNAME_SPROPNABOR_GRP=TableNAME_SPROPNABOR_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesNaborGrpImpl::get_ElementID_SPROPNABOR_GRP(void)
{
return Object->ElementID_SPROPNABOR_GRP;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborGrpImpl::set_ElementID_SPROPNABOR_GRP(TFIBLargeIntField * ElementID_SPROPNABOR_GRP)
{
Object->ElementID_SPROPNABOR_GRP=ElementID_SPROPNABOR_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesNaborGrpImpl::get_ElementIDBASE_SPROPNABOR_GRP(void)
{
return Object->ElementIDBASE_SPROPNABOR_GRP;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborGrpImpl::set_ElementIDBASE_SPROPNABOR_GRP(TFIBLargeIntField * ElementIDBASE_SPROPNABOR_GRP)
{
Object->ElementIDBASE_SPROPNABOR_GRP=ElementIDBASE_SPROPNABOR_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPropertiesNaborGrpImpl::get_ElementGID_SPROPNABOR_GRP(void)
{
return Object->ElementGID_SPROPNABOR_GRP;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborGrpImpl::set_ElementGID_SPROPNABOR_GRP(TFIBWideStringField * ElementGID_SPROPNABOR_GRP)
{
Object->ElementGID_SPROPNABOR_GRP=ElementGID_SPROPNABOR_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesNaborGrpImpl::get_ElementIDGRP_SPROPNABOR_GRP(void)
{
return Object->ElementIDGRP_SPROPNABOR_GRP;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborGrpImpl::set_ElementIDGRP_SPROPNABOR_GRP(TFIBLargeIntField * ElementIDGRP_SPROPNABOR_GRP)
{
Object->ElementIDGRP_SPROPNABOR_GRP=ElementIDGRP_SPROPNABOR_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPropertiesNaborGrpImpl::get_ElementNAME_SPROPNABOR_GRP(void)
{
return Object->ElementNAME_SPROPNABOR_GRP;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborGrpImpl::set_ElementNAME_SPROPNABOR_GRP(TFIBWideStringField * ElementNAME_SPROPNABOR_GRP)
{
Object->ElementNAME_SPROPNABOR_GRP=ElementNAME_SPROPNABOR_GRP;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborGrpImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprPropertiesNaborGrpImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborGrpImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TDMSprPropertiesNaborGrpImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprPropertiesNaborGrpImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TDMSprPropertiesNaborGrpImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
