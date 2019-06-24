#include "vcl.h"
#pragma hdrstop


#include "UDMSprTypeNachislImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprTypeNachislImpl::TDMSprTypeNachislImpl()           
{                                            
Object=new TDMSprTypeNachisl(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprTypeNachislImpl::~TDMSprTypeNachislImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprTypeNachislImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprTypeNachislImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprTypeNachisl)                        
   {                                                                     
   *ppv=static_cast<IDMSprTypeNachisl*> (this);                                
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
int TDMSprTypeNachislImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprTypeNachislImpl::kanRelease(void)                                  
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
int  TDMSprTypeNachislImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprTypeNachislImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprTypeNachislImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprTypeNachislImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprTypeNachislImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprTypeNachislImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprTypeNachislImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprTypeNachisl
TDataSource * TDMSprTypeNachislImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprTypeNachislImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprTypeNachislImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprTypeNachislImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprTypeNachislImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprTypeNachislImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprTypeNachislImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprTypeNachislImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprTypeNachislImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprTypeNachislImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprTypeNachislImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprTypeNachislImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMSprTypeNachislImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprTypeNachislImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprTypeNachislImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprTypeNachislImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprTypeNachislImpl::get_TableID_STNACHISL(void)
{
return Object->TableID_STNACHISL;
}
//---------------------------------------------------------------
void TDMSprTypeNachislImpl::set_TableID_STNACHISL(TFIBBCDField * TableID_STNACHISL)
{
Object->TableID_STNACHISL=TableID_STNACHISL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprTypeNachislImpl::get_TableIDBASE_STNACHISL(void)
{
return Object->TableIDBASE_STNACHISL;
}
//---------------------------------------------------------------
void TDMSprTypeNachislImpl::set_TableIDBASE_STNACHISL(TFIBBCDField * TableIDBASE_STNACHISL)
{
Object->TableIDBASE_STNACHISL=TableIDBASE_STNACHISL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprTypeNachislImpl::get_TableNAME_STNACHISL(void)
{
return Object->TableNAME_STNACHISL;
}
//---------------------------------------------------------------
void TDMSprTypeNachislImpl::set_TableNAME_STNACHISL(TFIBWideStringField * TableNAME_STNACHISL)
{
Object->TableNAME_STNACHISL=TableNAME_STNACHISL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprTypeNachislImpl::get_TableGID_STNACHISL(void)
{
return Object->TableGID_STNACHISL;
}
//---------------------------------------------------------------
void TDMSprTypeNachislImpl::set_TableGID_STNACHISL(TFIBWideStringField * TableGID_STNACHISL)
{
Object->TableGID_STNACHISL=TableGID_STNACHISL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprTypeNachislImpl::get_ElementID_STNACHISL(void)
{
return Object->ElementID_STNACHISL;
}
//---------------------------------------------------------------
void TDMSprTypeNachislImpl::set_ElementID_STNACHISL(TFIBBCDField * ElementID_STNACHISL)
{
Object->ElementID_STNACHISL=ElementID_STNACHISL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprTypeNachislImpl::get_ElementIDBASE_STNACHISL(void)
{
return Object->ElementIDBASE_STNACHISL;
}
//---------------------------------------------------------------
void TDMSprTypeNachislImpl::set_ElementIDBASE_STNACHISL(TFIBBCDField * ElementIDBASE_STNACHISL)
{
Object->ElementIDBASE_STNACHISL=ElementIDBASE_STNACHISL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprTypeNachislImpl::get_ElementNAME_STNACHISL(void)
{
return Object->ElementNAME_STNACHISL;
}
//---------------------------------------------------------------
void TDMSprTypeNachislImpl::set_ElementNAME_STNACHISL(TFIBWideStringField * ElementNAME_STNACHISL)
{
Object->ElementNAME_STNACHISL=ElementNAME_STNACHISL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprTypeNachislImpl::get_ElementGID_STNACHISL(void)
{
return Object->ElementGID_STNACHISL;
}
//---------------------------------------------------------------
void TDMSprTypeNachislImpl::set_ElementGID_STNACHISL(TFIBWideStringField * ElementGID_STNACHISL)
{
Object->ElementGID_STNACHISL=ElementGID_STNACHISL;
}
//---------------------------------------------------------------
void TDMSprTypeNachislImpl::OpenTable()
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprTypeNachislImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
void TDMSprTypeNachislImpl::NewElement()
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprTypeNachislImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprTypeNachislImpl::CloseElement(void)
{
return Object->CloseElement();
}
//---------------------------------------------------------------
void TDMSprTypeNachislImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
__int64 TDMSprTypeNachislImpl::GetIDTypePrice(String   name)
{
return Object->GetIDTypePrice(name);
}
//---------------------------------------------------------------
int TDMSprTypeNachislImpl::GetIndexTypePricePoId(__int64 id_type_price)
{
return Object->GetIndexTypePricePoId(id_type_price);
}
//---------------------------------------------------------------
__int64 TDMSprTypeNachislImpl::GetIDElement(String gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
AnsiString TDMSprTypeNachislImpl::GetGIDElement(__int64 id)
{
return Object->GetGIDElement(id);
}
//---------------------------------------------------------------
