#include <vcl.h>
#pragma hdrstop


#include "UDMSprNumTelImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprNumTelImpl::TDMSprNumTelImpl()           
{                                            
Object=new TDMSprNumTel(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprNumTelImpl::~TDMSprNumTelImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprNumTelImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprNumTelImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprNumTel)                        
   {                                                                     
   *ppv=static_cast<IDMSprNumTel*> (this);                                
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
int TDMSprNumTelImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprNumTelImpl::kanRelease(void)                                  
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

//---------------------------------------------------------------
int  TDMSprNumTelImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprNumTelImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprNumTelImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprNumTelImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprNumTelImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMSprNumTelImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprNumTelImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprNumTelImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprNumTelImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprNumTelImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprNumTelImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNumTelImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprNumTelImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNumTelImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprNumTelImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprNumTelImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprNumTelImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprNumTelImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprNumTelImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMSprNumTelImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprNumTelImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNumTelImpl::get_TableID_NUMTEL(void)
{
return Object->TableID_NUMTEL;
}
//---------------------------------------------------------------
void TDMSprNumTelImpl::set_TableID_NUMTEL(TFIBBCDField * TableID_NUMTEL)
{
Object->TableID_NUMTEL=TableID_NUMTEL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNumTelImpl::get_TableIDKLIENT_NUMTEL(void)
{
return Object->TableIDKLIENT_NUMTEL;
}
//---------------------------------------------------------------
void TDMSprNumTelImpl::set_TableIDKLIENT_NUMTEL(TFIBBCDField * TableIDKLIENT_NUMTEL)
{
Object->TableIDKLIENT_NUMTEL=TableIDKLIENT_NUMTEL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNumTelImpl::get_ElementID_NUMTEL(void)
{
return Object->ElementID_NUMTEL;
}
//---------------------------------------------------------------
void TDMSprNumTelImpl::set_ElementID_NUMTEL(TFIBBCDField * ElementID_NUMTEL)
{
Object->ElementID_NUMTEL=ElementID_NUMTEL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNumTelImpl::get_ElementIDKLIENT_NUMTEL(void)
{
return Object->ElementIDKLIENT_NUMTEL;
}
//---------------------------------------------------------------
void TDMSprNumTelImpl::set_ElementIDKLIENT_NUMTEL(TFIBBCDField * ElementIDKLIENT_NUMTEL)
{
Object->ElementIDKLIENT_NUMTEL=ElementIDKLIENT_NUMTEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNumTelImpl::get_TableCODE_NUMTEL(void)
{
return Object->TableCODE_NUMTEL;
}
//---------------------------------------------------------------
void TDMSprNumTelImpl::set_TableCODE_NUMTEL(TFIBWideStringField * TableCODE_NUMTEL)
{
Object->TableCODE_NUMTEL=TableCODE_NUMTEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNumTelImpl::get_TableNUMBER_NUMTEL(void)
{
return Object->TableNUMBER_NUMTEL;
}
//---------------------------------------------------------------
void TDMSprNumTelImpl::set_TableNUMBER_NUMTEL(TFIBWideStringField * TableNUMBER_NUMTEL)
{
Object->TableNUMBER_NUMTEL=TableNUMBER_NUMTEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNumTelImpl::get_TableGID_SNUMTEL(void)
{
return Object->TableGID_SNUMTEL;
}
//---------------------------------------------------------------
void TDMSprNumTelImpl::set_TableGID_SNUMTEL(TFIBWideStringField * TableGID_SNUMTEL)
{
Object->TableGID_SNUMTEL=TableGID_SNUMTEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNumTelImpl::get_ElementCODE_NUMTEL(void)
{
return Object->ElementCODE_NUMTEL;
}
//---------------------------------------------------------------
void TDMSprNumTelImpl::set_ElementCODE_NUMTEL(TFIBWideStringField * ElementCODE_NUMTEL)
{
Object->ElementCODE_NUMTEL=ElementCODE_NUMTEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNumTelImpl::get_ElementNUMBER_NUMTEL(void)
{
return Object->ElementNUMBER_NUMTEL;
}
//---------------------------------------------------------------
void TDMSprNumTelImpl::set_ElementNUMBER_NUMTEL(TFIBWideStringField * ElementNUMBER_NUMTEL)
{
Object->ElementNUMBER_NUMTEL=ElementNUMBER_NUMTEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNumTelImpl::get_ElementGID_SNUMTEL(void)
{
return Object->ElementGID_SNUMTEL;
}
//---------------------------------------------------------------
void TDMSprNumTelImpl::set_ElementGID_SNUMTEL(TFIBWideStringField * ElementGID_SNUMTEL)
{
Object->ElementGID_SNUMTEL=ElementGID_SNUMTEL;
}
//---------------------------------------------------------------
__int64 TDMSprNumTelImpl::get_IdKlient(void)
{
return Object->IdKlient;
}
//---------------------------------------------------------------
void TDMSprNumTelImpl::set_IdKlient(__int64 IdKlient)
{
Object->IdKlient=IdKlient;
}
//---------------------------------------------------------------
void TDMSprNumTelImpl::OpenTable(__int64 IdKl)
{
return Object->OpenTable(IdKl);
}
//---------------------------------------------------------------
int TDMSprNumTelImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
void TDMSprNumTelImpl::NewElement(__int64 IdKl)
{
return Object->NewElement(IdKl);
}
//---------------------------------------------------------------
bool TDMSprNumTelImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprNumTelImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
