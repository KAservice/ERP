#include "vcl.h"
#pragma hdrstop


#include "UDMSprProducerNomGrpImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprProducerNomGrpImpl::TDMSprProducerNomGrpImpl()           
{                                            
Object=new TDMSprProducerNomGrp(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprProducerNomGrpImpl::~TDMSprProducerNomGrpImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprProducerNomGrpImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprProducerNomGrpImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprProducerNomGrp)                        
   {                                                                     
   *ppv=static_cast<IDMSprProducerNomGrp*> (this);                                
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
int TDMSprProducerNomGrpImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprProducerNomGrpImpl::kanRelease(void)                                  
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
int  TDMSprProducerNomGrpImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprProducerNomGrpImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprProducerNomGrpImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprProducerNomGrpImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprProducerNomGrpImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprProducerNomGrpImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprProducerNomGrpImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprProducerNomGrp
TDataSource * TDMSprProducerNomGrpImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprProducerNomGrpImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprProducerNomGrpImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprProducerNomGrpImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprProducerNomGrpImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprProducerNomGrpImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprProducerNomGrpImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprProducerNomGrpImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprProducerNomGrpImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprProducerNomGrpImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprProducerNomGrpImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprProducerNomGrpImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMSprProducerNomGrpImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprProducerNomGrpImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerNomGrpImpl::get_TableID_SPRNOMGRP(void)
{
return Object->TableID_SPRNOMGRP;
}
//---------------------------------------------------------------
void TDMSprProducerNomGrpImpl::set_TableID_SPRNOMGRP(TFIBLargeIntField * TableID_SPRNOMGRP)
{
Object->TableID_SPRNOMGRP=TableID_SPRNOMGRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerNomGrpImpl::get_TableIDBASE_SPRNOMGRP(void)
{
return Object->TableIDBASE_SPRNOMGRP;
}
//---------------------------------------------------------------
void TDMSprProducerNomGrpImpl::set_TableIDBASE_SPRNOMGRP(TFIBLargeIntField * TableIDBASE_SPRNOMGRP)
{
Object->TableIDBASE_SPRNOMGRP=TableIDBASE_SPRNOMGRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerNomGrpImpl::get_TableGID_SPRNOMGRP(void)
{
return Object->TableGID_SPRNOMGRP;
}
//---------------------------------------------------------------
void TDMSprProducerNomGrpImpl::set_TableGID_SPRNOMGRP(TFIBWideStringField * TableGID_SPRNOMGRP)
{
Object->TableGID_SPRNOMGRP=TableGID_SPRNOMGRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerNomGrpImpl::get_TableIDGRP_SPRNOMGRP(void)
{
return Object->TableIDGRP_SPRNOMGRP;
}
//---------------------------------------------------------------
void TDMSprProducerNomGrpImpl::set_TableIDGRP_SPRNOMGRP(TFIBLargeIntField * TableIDGRP_SPRNOMGRP)
{
Object->TableIDGRP_SPRNOMGRP=TableIDGRP_SPRNOMGRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerNomGrpImpl::get_TableIDPROD_SPRNOMGRP(void)
{
return Object->TableIDPROD_SPRNOMGRP;
}
//---------------------------------------------------------------
void TDMSprProducerNomGrpImpl::set_TableIDPROD_SPRNOMGRP(TFIBLargeIntField * TableIDPROD_SPRNOMGRP)
{
Object->TableIDPROD_SPRNOMGRP=TableIDPROD_SPRNOMGRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerNomGrpImpl::get_TableNAME_SPRNOMGRP(void)
{
return Object->TableNAME_SPRNOMGRP;
}
//---------------------------------------------------------------
void TDMSprProducerNomGrpImpl::set_TableNAME_SPRNOMGRP(TFIBWideStringField * TableNAME_SPRNOMGRP)
{
Object->TableNAME_SPRNOMGRP=TableNAME_SPRNOMGRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerNomGrpImpl::get_ElementID_SPRNOMGRP(void)
{
return Object->ElementID_SPRNOMGRP;
}
//---------------------------------------------------------------
void TDMSprProducerNomGrpImpl::set_ElementID_SPRNOMGRP(TFIBLargeIntField * ElementID_SPRNOMGRP)
{
Object->ElementID_SPRNOMGRP=ElementID_SPRNOMGRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerNomGrpImpl::get_ElementIDBASE_SPRNOMGRP(void)
{
return Object->ElementIDBASE_SPRNOMGRP;
}
//---------------------------------------------------------------
void TDMSprProducerNomGrpImpl::set_ElementIDBASE_SPRNOMGRP(TFIBLargeIntField * ElementIDBASE_SPRNOMGRP)
{
Object->ElementIDBASE_SPRNOMGRP=ElementIDBASE_SPRNOMGRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerNomGrpImpl::get_ElementGID_SPRNOMGRP(void)
{
return Object->ElementGID_SPRNOMGRP;
}
//---------------------------------------------------------------
void TDMSprProducerNomGrpImpl::set_ElementGID_SPRNOMGRP(TFIBWideStringField * ElementGID_SPRNOMGRP)
{
Object->ElementGID_SPRNOMGRP=ElementGID_SPRNOMGRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerNomGrpImpl::get_ElementIDGRP_SPRNOMGRP(void)
{
return Object->ElementIDGRP_SPRNOMGRP;
}
//---------------------------------------------------------------
void TDMSprProducerNomGrpImpl::set_ElementIDGRP_SPRNOMGRP(TFIBLargeIntField * ElementIDGRP_SPRNOMGRP)
{
Object->ElementIDGRP_SPRNOMGRP=ElementIDGRP_SPRNOMGRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerNomGrpImpl::get_ElementIDPROD_SPRNOMGRP(void)
{
return Object->ElementIDPROD_SPRNOMGRP;
}
//---------------------------------------------------------------
void TDMSprProducerNomGrpImpl::set_ElementIDPROD_SPRNOMGRP(TFIBLargeIntField * ElementIDPROD_SPRNOMGRP)
{
Object->ElementIDPROD_SPRNOMGRP=ElementIDPROD_SPRNOMGRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerNomGrpImpl::get_ElementNAME_SPRNOMGRP(void)
{
return Object->ElementNAME_SPRNOMGRP;
}
//---------------------------------------------------------------
void TDMSprProducerNomGrpImpl::set_ElementNAME_SPRNOMGRP(TFIBWideStringField * ElementNAME_SPRNOMGRP)
{
Object->ElementNAME_SPRNOMGRP=ElementNAME_SPRNOMGRP;
}
//---------------------------------------------------------------
__int64 TDMSprProducerNomGrpImpl::get_IdProducer(void)
{
return Object->IdProducer;
}
//---------------------------------------------------------------
void TDMSprProducerNomGrpImpl::set_IdProducer(__int64 IdProducer)
{
Object->IdProducer=IdProducer;
}
//---------------------------------------------------------------
void TDMSprProducerNomGrpImpl::OpenTable(__int64 id_producer)
{
return Object->OpenTable(id_producer);
}
//---------------------------------------------------------------
int TDMSprProducerNomGrpImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TDMSprProducerNomGrpImpl::NewElement(__int64 id_producer, __int64 id_grp)
{
return Object->NewElement(id_producer,id_grp);
}
//---------------------------------------------------------------
bool TDMSprProducerNomGrpImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprProducerNomGrpImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
