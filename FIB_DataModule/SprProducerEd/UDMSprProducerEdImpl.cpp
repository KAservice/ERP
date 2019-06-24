#include "vcl.h"
#pragma hdrstop


#include "UDMSprProducerEdImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprProducerEdImpl::TDMSprProducerEdImpl()           
{                                            
Object=new TDMSprProducerEd(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprProducerEdImpl::~TDMSprProducerEdImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprProducerEdImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprProducerEdImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprProducerEd)                        
   {                                                                     
   *ppv=static_cast<IDMSprProducerEd*> (this);                                
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
int TDMSprProducerEdImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprProducerEdImpl::kanRelease(void)                                  
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
int  TDMSprProducerEdImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprProducerEdImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprProducerEdImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprProducerEdImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprProducerEdImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprProducerEdImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprProducerEdImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprProducerEd
TDataSource * TDMSprProducerEdImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprProducerEdImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprProducerEdImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprProducerEdImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprProducerEdImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprProducerEdImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprProducerEdImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprProducerEdImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprProducerEdImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprProducerEdImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprProducerEdImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprProducerEdImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMSprProducerEdImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprProducerEdImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprProducerEdImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprProducerEdImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerEdImpl::get_TableID_SPRED(void)
{
return Object->TableID_SPRED;
}
//---------------------------------------------------------------
void TDMSprProducerEdImpl::set_TableID_SPRED(TFIBLargeIntField * TableID_SPRED)
{
Object->TableID_SPRED=TableID_SPRED;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerEdImpl::get_TableIDBASE_SPRED(void)
{
return Object->TableIDBASE_SPRED;
}
//---------------------------------------------------------------
void TDMSprProducerEdImpl::set_TableIDBASE_SPRED(TFIBLargeIntField * TableIDBASE_SPRED)
{
Object->TableIDBASE_SPRED=TableIDBASE_SPRED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerEdImpl::get_TableGID_SPRED(void)
{
return Object->TableGID_SPRED;
}
//---------------------------------------------------------------
void TDMSprProducerEdImpl::set_TableGID_SPRED(TFIBWideStringField * TableGID_SPRED)
{
Object->TableGID_SPRED=TableGID_SPRED;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerEdImpl::get_TableIDPRNOM_SPRED(void)
{
return Object->TableIDPRNOM_SPRED;
}
//---------------------------------------------------------------
void TDMSprProducerEdImpl::set_TableIDPRNOM_SPRED(TFIBLargeIntField * TableIDPRNOM_SPRED)
{
Object->TableIDPRNOM_SPRED=TableIDPRNOM_SPRED;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprProducerEdImpl::get_TableCODE_SPRED(void)
{
return Object->TableCODE_SPRED;
}
//---------------------------------------------------------------
void TDMSprProducerEdImpl::set_TableCODE_SPRED(TFIBIntegerField * TableCODE_SPRED)
{
Object->TableCODE_SPRED=TableCODE_SPRED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerEdImpl::get_TableBARCODE_SPRED(void)
{
return Object->TableBARCODE_SPRED;
}
//---------------------------------------------------------------
void TDMSprProducerEdImpl::set_TableBARCODE_SPRED(TFIBWideStringField * TableBARCODE_SPRED)
{
Object->TableBARCODE_SPRED=TableBARCODE_SPRED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprProducerEdImpl::get_TableKF_SPRED(void)
{
return Object->TableKF_SPRED;
}
//---------------------------------------------------------------
void TDMSprProducerEdImpl::set_TableKF_SPRED(TFIBBCDField * TableKF_SPRED)
{
Object->TableKF_SPRED=TableKF_SPRED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerEdImpl::get_TableNAME_SPRED(void)
{
return Object->TableNAME_SPRED;
}
//---------------------------------------------------------------
void TDMSprProducerEdImpl::set_TableNAME_SPRED(TFIBWideStringField * TableNAME_SPRED)
{
Object->TableNAME_SPRED=TableNAME_SPRED;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerEdImpl::get_ElementID_SPRED(void)
{
return Object->ElementID_SPRED;
}
//---------------------------------------------------------------
void TDMSprProducerEdImpl::set_ElementID_SPRED(TFIBLargeIntField * ElementID_SPRED)
{
Object->ElementID_SPRED=ElementID_SPRED;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerEdImpl::get_ElementIDBASE_SPRED(void)
{
return Object->ElementIDBASE_SPRED;
}
//---------------------------------------------------------------
void TDMSprProducerEdImpl::set_ElementIDBASE_SPRED(TFIBLargeIntField * ElementIDBASE_SPRED)
{
Object->ElementIDBASE_SPRED=ElementIDBASE_SPRED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerEdImpl::get_ElementGID_SPRED(void)
{
return Object->ElementGID_SPRED;
}
//---------------------------------------------------------------
void TDMSprProducerEdImpl::set_ElementGID_SPRED(TFIBWideStringField * ElementGID_SPRED)
{
Object->ElementGID_SPRED=ElementGID_SPRED;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprProducerEdImpl::get_ElementIDPRNOM_SPRED(void)
{
return Object->ElementIDPRNOM_SPRED;
}
//---------------------------------------------------------------
void TDMSprProducerEdImpl::set_ElementIDPRNOM_SPRED(TFIBLargeIntField * ElementIDPRNOM_SPRED)
{
Object->ElementIDPRNOM_SPRED=ElementIDPRNOM_SPRED;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprProducerEdImpl::get_ElementCODE_SPRED(void)
{
return Object->ElementCODE_SPRED;
}
//---------------------------------------------------------------
void TDMSprProducerEdImpl::set_ElementCODE_SPRED(TFIBIntegerField * ElementCODE_SPRED)
{
Object->ElementCODE_SPRED=ElementCODE_SPRED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerEdImpl::get_ElementBARCODE_SPRED(void)
{
return Object->ElementBARCODE_SPRED;
}
//---------------------------------------------------------------
void TDMSprProducerEdImpl::set_ElementBARCODE_SPRED(TFIBWideStringField * ElementBARCODE_SPRED)
{
Object->ElementBARCODE_SPRED=ElementBARCODE_SPRED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprProducerEdImpl::get_ElementKF_SPRED(void)
{
return Object->ElementKF_SPRED;
}
//---------------------------------------------------------------
void TDMSprProducerEdImpl::set_ElementKF_SPRED(TFIBBCDField * ElementKF_SPRED)
{
Object->ElementKF_SPRED=ElementKF_SPRED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprProducerEdImpl::get_ElementNAME_SPRED(void)
{
return Object->ElementNAME_SPRED;
}
//---------------------------------------------------------------
void TDMSprProducerEdImpl::set_ElementNAME_SPRED(TFIBWideStringField * ElementNAME_SPRED)
{
Object->ElementNAME_SPRED=ElementNAME_SPRED;
}
//---------------------------------------------------------------
void TDMSprProducerEdImpl::OpenTable(__int64 id_producer_nom)
{
return Object->OpenTable(id_producer_nom);
}
//---------------------------------------------------------------
int TDMSprProducerEdImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TDMSprProducerEdImpl::NewElement(__int64 id_producer_nom)
{
return Object->NewElement(id_producer_nom);
}
//---------------------------------------------------------------
bool TDMSprProducerEdImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprProducerEdImpl::DeleteElement(__int64 num)
{
return Object->DeleteElement(num);
}
//---------------------------------------------------------------
