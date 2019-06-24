#include <vcl.h>
#pragma hdrstop


#include "UDMSprDocKlientImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprDocKlientImpl::TDMSprDocKlientImpl()           
{                                            
Object=new TDMSprDocKlient(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprDocKlientImpl::~TDMSprDocKlientImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprDocKlientImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprDocKlientImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprDocKlient)                        
   {                                                                     
   *ppv=static_cast<IDMSprDocKlient*> (this);                                
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
int TDMSprDocKlientImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprDocKlientImpl::kanRelease(void)                                  
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
int  TDMSprDocKlientImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprDocKlientImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprDocKlientImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprDocKlientImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprDocKlientImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMSprDocKlientImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprDocKlientImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprDocKlientImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprDocKlientImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprDocKlientImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprDocKlientImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprDocKlientImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprDocKlientImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprDocKlientImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprDocKlientImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprDocKlientImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprDocKlientImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprDocKlientImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprDocKlientImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBDateField * TDMSprDocKlientImpl::get_TableDATEVID_SDOCKLIENT(void)
{
return Object->TableDATEVID_SDOCKLIENT;
}
//---------------------------------------------------------------
void TDMSprDocKlientImpl::set_TableDATEVID_SDOCKLIENT(TFIBDateField * TableDATEVID_SDOCKLIENT)
{
Object->TableDATEVID_SDOCKLIENT=TableDATEVID_SDOCKLIENT;
}
//---------------------------------------------------------------
TIntegerField * TDMSprDocKlientImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprDocKlientImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBDateField * TDMSprDocKlientImpl::get_ElementDATEVID_SDOCKLIENT(void)
{
return Object->ElementDATEVID_SDOCKLIENT;
}
//---------------------------------------------------------------
void TDMSprDocKlientImpl::set_ElementDATEVID_SDOCKLIENT(TFIBDateField * ElementDATEVID_SDOCKLIENT)
{
Object->ElementDATEVID_SDOCKLIENT=ElementDATEVID_SDOCKLIENT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprDocKlientImpl::get_TableID_SDOCKLIENT(void)
{
return Object->TableID_SDOCKLIENT;
}
//---------------------------------------------------------------
void TDMSprDocKlientImpl::set_TableID_SDOCKLIENT(TFIBBCDField * TableID_SDOCKLIENT)
{
Object->TableID_SDOCKLIENT=TableID_SDOCKLIENT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprDocKlientImpl::get_TableIDKLIENT_SDOCKLIENT(void)
{
return Object->TableIDKLIENT_SDOCKLIENT;
}
//---------------------------------------------------------------
void TDMSprDocKlientImpl::set_TableIDKLIENT_SDOCKLIENT(TFIBBCDField * TableIDKLIENT_SDOCKLIENT)
{
Object->TableIDKLIENT_SDOCKLIENT=TableIDKLIENT_SDOCKLIENT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprDocKlientImpl::get_ElementID_SDOCKLIENT(void)
{
return Object->ElementID_SDOCKLIENT;
}
//---------------------------------------------------------------
void TDMSprDocKlientImpl::set_ElementID_SDOCKLIENT(TFIBBCDField * ElementID_SDOCKLIENT)
{
Object->ElementID_SDOCKLIENT=ElementID_SDOCKLIENT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprDocKlientImpl::get_ElementIDKLIENT_SDOCKLIENT(void)
{
return Object->ElementIDKLIENT_SDOCKLIENT;
}
//---------------------------------------------------------------
void TDMSprDocKlientImpl::set_ElementIDKLIENT_SDOCKLIENT(TFIBBCDField * ElementIDKLIENT_SDOCKLIENT)
{
Object->ElementIDKLIENT_SDOCKLIENT=ElementIDKLIENT_SDOCKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDocKlientImpl::get_TableNAME_SDOCKLIENT(void)
{
return Object->TableNAME_SDOCKLIENT;
}
//---------------------------------------------------------------
void TDMSprDocKlientImpl::set_TableNAME_SDOCKLIENT(TFIBWideStringField * TableNAME_SDOCKLIENT)
{
Object->TableNAME_SDOCKLIENT=TableNAME_SDOCKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDocKlientImpl::get_TableSER_SDOCKLIENT(void)
{
return Object->TableSER_SDOCKLIENT;
}
//---------------------------------------------------------------
void TDMSprDocKlientImpl::set_TableSER_SDOCKLIENT(TFIBWideStringField * TableSER_SDOCKLIENT)
{
Object->TableSER_SDOCKLIENT=TableSER_SDOCKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDocKlientImpl::get_TableNUM_SDOCKLIENT(void)
{
return Object->TableNUM_SDOCKLIENT;
}
//---------------------------------------------------------------
void TDMSprDocKlientImpl::set_TableNUM_SDOCKLIENT(TFIBWideStringField * TableNUM_SDOCKLIENT)
{
Object->TableNUM_SDOCKLIENT=TableNUM_SDOCKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDocKlientImpl::get_TableVID_SDOCKLIENT(void)
{
return Object->TableVID_SDOCKLIENT;
}
//---------------------------------------------------------------
void TDMSprDocKlientImpl::set_TableVID_SDOCKLIENT(TFIBWideStringField * TableVID_SDOCKLIENT)
{
Object->TableVID_SDOCKLIENT=TableVID_SDOCKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDocKlientImpl::get_TableGID_SDOCKLIENT(void)
{
return Object->TableGID_SDOCKLIENT;
}
//---------------------------------------------------------------
void TDMSprDocKlientImpl::set_TableGID_SDOCKLIENT(TFIBWideStringField * TableGID_SDOCKLIENT)
{
Object->TableGID_SDOCKLIENT=TableGID_SDOCKLIENT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprDocKlientImpl::get_TableIDBASE_SDOCKLIENT(void)
{
return Object->TableIDBASE_SDOCKLIENT;
}
//---------------------------------------------------------------
void TDMSprDocKlientImpl::set_TableIDBASE_SDOCKLIENT(TFIBBCDField * TableIDBASE_SDOCKLIENT)
{
Object->TableIDBASE_SDOCKLIENT=TableIDBASE_SDOCKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDocKlientImpl::get_ElementNAME_SDOCKLIENT(void)
{
return Object->ElementNAME_SDOCKLIENT;
}
//---------------------------------------------------------------
void TDMSprDocKlientImpl::set_ElementNAME_SDOCKLIENT(TFIBWideStringField * ElementNAME_SDOCKLIENT)
{
Object->ElementNAME_SDOCKLIENT=ElementNAME_SDOCKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDocKlientImpl::get_ElementSER_SDOCKLIENT(void)
{
return Object->ElementSER_SDOCKLIENT;
}
//---------------------------------------------------------------
void TDMSprDocKlientImpl::set_ElementSER_SDOCKLIENT(TFIBWideStringField * ElementSER_SDOCKLIENT)
{
Object->ElementSER_SDOCKLIENT=ElementSER_SDOCKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDocKlientImpl::get_ElementNUM_SDOCKLIENT(void)
{
return Object->ElementNUM_SDOCKLIENT;
}
//---------------------------------------------------------------
void TDMSprDocKlientImpl::set_ElementNUM_SDOCKLIENT(TFIBWideStringField * ElementNUM_SDOCKLIENT)
{
Object->ElementNUM_SDOCKLIENT=ElementNUM_SDOCKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDocKlientImpl::get_ElementVID_SDOCKLIENT(void)
{
return Object->ElementVID_SDOCKLIENT;
}
//---------------------------------------------------------------
void TDMSprDocKlientImpl::set_ElementVID_SDOCKLIENT(TFIBWideStringField * ElementVID_SDOCKLIENT)
{
Object->ElementVID_SDOCKLIENT=ElementVID_SDOCKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDocKlientImpl::get_ElementGID_SDOCKLIENT(void)
{
return Object->ElementGID_SDOCKLIENT;
}
//---------------------------------------------------------------
void TDMSprDocKlientImpl::set_ElementGID_SDOCKLIENT(TFIBWideStringField * ElementGID_SDOCKLIENT)
{
Object->ElementGID_SDOCKLIENT=ElementGID_SDOCKLIENT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprDocKlientImpl::get_ElementIDBASE_SDOCKLIENT(void)
{
return Object->ElementIDBASE_SDOCKLIENT;
}
//---------------------------------------------------------------
void TDMSprDocKlientImpl::set_ElementIDBASE_SDOCKLIENT(TFIBBCDField * ElementIDBASE_SDOCKLIENT)
{
Object->ElementIDBASE_SDOCKLIENT=ElementIDBASE_SDOCKLIENT;
}
//---------------------------------------------------------------
__int64 TDMSprDocKlientImpl::get_IdKlient(void)
{
return Object->IdKlient;
}
//---------------------------------------------------------------
void TDMSprDocKlientImpl::set_IdKlient(__int64 IdKlient)
{
Object->IdKlient=IdKlient;
}
//---------------------------------------------------------------
void TDMSprDocKlientImpl::OpenTable(__int64 IdKl)
{
return Object->OpenTable(IdKl);
}
//---------------------------------------------------------------
int TDMSprDocKlientImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);;
}
//---------------------------------------------------------------
void TDMSprDocKlientImpl::NewElement(__int64 IdKl)
{
return Object->NewElement(IdKl);
}
//---------------------------------------------------------------
bool TDMSprDocKlientImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprDocKlientImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
