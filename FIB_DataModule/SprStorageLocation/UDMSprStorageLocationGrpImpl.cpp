#include "vcl.h"
#pragma hdrstop


#include "UDMSprStorageLocationGrpImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprStorageLocationGrpImpl::TDMSprStorageLocationGrpImpl()           
{                                            
Object=new TDMSprStorageLocationGrp(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprStorageLocationGrpImpl::~TDMSprStorageLocationGrpImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprStorageLocationGrpImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprStorageLocationGrpImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprStorageLocationGrp)                        
   {                                                                     
   *ppv=static_cast<IDMSprStorageLocationGrp*> (this);                                
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
int TDMSprStorageLocationGrpImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprStorageLocationGrpImpl::kanRelease(void)                                  
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
int  TDMSprStorageLocationGrpImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprStorageLocationGrpImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprStorageLocationGrpImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprStorageLocationGrpImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprStorageLocationGrpImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprStorageLocationGrpImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprStorageLocationGrpImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprStorageLocationGrp
TDataSource * TDMSprStorageLocationGrpImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprStorageLocationGrpImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprStorageLocationGrpImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprStorageLocationGrpImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprStorageLocationGrpImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprStorageLocationGrpImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprStorageLocationGrpImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprStorageLocationGrpImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprStorageLocationGrpImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprStorageLocationGrpImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprStorageLocationGrpImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprStorageLocationGrpImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMSprStorageLocationGrpImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprStorageLocationGrpImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprStorageLocationGrpImpl::get_TableID_SMHRAN_GRP(void)
{
return Object->TableID_SMHRAN_GRP;
}
//---------------------------------------------------------------
void TDMSprStorageLocationGrpImpl::set_TableID_SMHRAN_GRP(TFIBLargeIntField * TableID_SMHRAN_GRP)
{
Object->TableID_SMHRAN_GRP=TableID_SMHRAN_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprStorageLocationGrpImpl::get_TableIDBASE_SMHRAN_GRP(void)
{
return Object->TableIDBASE_SMHRAN_GRP;
}
//---------------------------------------------------------------
void TDMSprStorageLocationGrpImpl::set_TableIDBASE_SMHRAN_GRP(TFIBLargeIntField * TableIDBASE_SMHRAN_GRP)
{
Object->TableIDBASE_SMHRAN_GRP=TableIDBASE_SMHRAN_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprStorageLocationGrpImpl::get_TableIDGRP_SMHRAN_GRP(void)
{
return Object->TableIDGRP_SMHRAN_GRP;
}
//---------------------------------------------------------------
void TDMSprStorageLocationGrpImpl::set_TableIDGRP_SMHRAN_GRP(TFIBLargeIntField * TableIDGRP_SMHRAN_GRP)
{
Object->TableIDGRP_SMHRAN_GRP=TableIDGRP_SMHRAN_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprStorageLocationGrpImpl::get_TableNAME_SMHRAN_GRP(void)
{
return Object->TableNAME_SMHRAN_GRP;
}
//---------------------------------------------------------------
void TDMSprStorageLocationGrpImpl::set_TableNAME_SMHRAN_GRP(TFIBWideStringField * TableNAME_SMHRAN_GRP)
{
Object->TableNAME_SMHRAN_GRP=TableNAME_SMHRAN_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprStorageLocationGrpImpl::get_TableIDSKLAD_SMHRAN_GRP(void)
{
return Object->TableIDSKLAD_SMHRAN_GRP;
}
//---------------------------------------------------------------
void TDMSprStorageLocationGrpImpl::set_TableIDSKLAD_SMHRAN_GRP(TFIBLargeIntField * TableIDSKLAD_SMHRAN_GRP)
{
Object->TableIDSKLAD_SMHRAN_GRP=TableIDSKLAD_SMHRAN_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprStorageLocationGrpImpl::get_ElementID_SMHRAN_GRP(void)
{
return Object->ElementID_SMHRAN_GRP;
}
//---------------------------------------------------------------
void TDMSprStorageLocationGrpImpl::set_ElementID_SMHRAN_GRP(TFIBLargeIntField * ElementID_SMHRAN_GRP)
{
Object->ElementID_SMHRAN_GRP=ElementID_SMHRAN_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprStorageLocationGrpImpl::get_ElementIDBASE_SMHRAN_GRP(void)
{
return Object->ElementIDBASE_SMHRAN_GRP;
}
//---------------------------------------------------------------
void TDMSprStorageLocationGrpImpl::set_ElementIDBASE_SMHRAN_GRP(TFIBLargeIntField * ElementIDBASE_SMHRAN_GRP)
{
Object->ElementIDBASE_SMHRAN_GRP=ElementIDBASE_SMHRAN_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprStorageLocationGrpImpl::get_ElementIDGRP_SMHRAN_GRP(void)
{
return Object->ElementIDGRP_SMHRAN_GRP;
}
//---------------------------------------------------------------
void TDMSprStorageLocationGrpImpl::set_ElementIDGRP_SMHRAN_GRP(TFIBLargeIntField * ElementIDGRP_SMHRAN_GRP)
{
Object->ElementIDGRP_SMHRAN_GRP=ElementIDGRP_SMHRAN_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprStorageLocationGrpImpl::get_ElementNAME_SMHRAN_GRP(void)
{
return Object->ElementNAME_SMHRAN_GRP;
}
//---------------------------------------------------------------
void TDMSprStorageLocationGrpImpl::set_ElementNAME_SMHRAN_GRP(TFIBWideStringField * ElementNAME_SMHRAN_GRP)
{
Object->ElementNAME_SMHRAN_GRP=ElementNAME_SMHRAN_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprStorageLocationGrpImpl::get_ElementIDSKLAD_SMHRAN_GRP(void)
{
return Object->ElementIDSKLAD_SMHRAN_GRP;
}
//---------------------------------------------------------------
void TDMSprStorageLocationGrpImpl::set_ElementIDSKLAD_SMHRAN_GRP(TFIBLargeIntField * ElementIDSKLAD_SMHRAN_GRP)
{
Object->ElementIDSKLAD_SMHRAN_GRP=ElementIDSKLAD_SMHRAN_GRP;
}
//---------------------------------------------------------------
__int64 TDMSprStorageLocationGrpImpl::get_IdSklad(void)
{
return Object->IdSklad;
}
//---------------------------------------------------------------
void TDMSprStorageLocationGrpImpl::set_IdSklad(__int64 IdSklad)
{
Object->IdSklad=IdSklad;
}
//---------------------------------------------------------------
void TDMSprStorageLocationGrpImpl::OpenTable(__int64 id_sklad)
{
return Object->OpenTable( id_sklad);
}
//---------------------------------------------------------------
int TDMSprStorageLocationGrpImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TDMSprStorageLocationGrpImpl::NewElement(__int64 id_sklad, __int64 id_grp)
{
return Object->NewElement(id_sklad, id_grp);
}
//---------------------------------------------------------------
bool TDMSprStorageLocationGrpImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprStorageLocationGrpImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
