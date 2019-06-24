#include <vcl.h>
#pragma hdrstop


#include "UDMTableNumberDocImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMTableNumberDocImpl::TDMTableNumberDocImpl()           
{                                            
Object=new TDMTableNumberDoc(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMTableNumberDocImpl::~TDMTableNumberDocImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMTableNumberDocImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMTableNumberDocImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMTableNumberDoc)                        
   {                                                                     
   *ppv=static_cast<IDMTableNumberDoc*> (this);                                
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
int TDMTableNumberDocImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMTableNumberDocImpl::kanRelease(void)                                  
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
int  TDMTableNumberDocImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMTableNumberDocImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMTableNumberDocImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMTableNumberDocImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMTableNumberDocImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMTableNumberDocImpl::Done(void)
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMTableNumberDocImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMTableNumberDocImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMTableNumberDocImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMTableNumberDocImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMTableNumberDocImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMTableNumberDocImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMTableNumberDocImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMTableNumberDocImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMTableNumberDocImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMTableNumberDocImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TIntegerField * TDMTableNumberDocImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMTableNumberDocImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * TDMTableNumberDocImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TDMTableNumberDocImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBBCDField * TDMTableNumberDocImpl::get_TableID_TNUM_DOC(void)
{
return Object->TableID_TNUM_DOC;
}
//---------------------------------------------------------------
void TDMTableNumberDocImpl::set_TableID_TNUM_DOC(TFIBBCDField * TableID_TNUM_DOC)
{
Object->TableID_TNUM_DOC=TableID_TNUM_DOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMTableNumberDocImpl::get_ElementID_TNUM_DOC(void)
{
return Object->ElementID_TNUM_DOC;
}
//---------------------------------------------------------------
void TDMTableNumberDocImpl::set_ElementID_TNUM_DOC(TFIBBCDField * ElementID_TNUM_DOC)
{
Object->ElementID_TNUM_DOC=ElementID_TNUM_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMTableNumberDocImpl::get_TableGID_TNUM_DOC(void)
{
return Object->TableGID_TNUM_DOC;
}
//---------------------------------------------------------------
void TDMTableNumberDocImpl::set_TableGID_TNUM_DOC(TFIBWideStringField * TableGID_TNUM_DOC)
{
Object->TableGID_TNUM_DOC=TableGID_TNUM_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMTableNumberDocImpl::get_TableDOC_TNUM_DOC(void)
{
return Object->TableDOC_TNUM_DOC;
}
//---------------------------------------------------------------
void TDMTableNumberDocImpl::set_TableDOC_TNUM_DOC(TFIBWideStringField * TableDOC_TNUM_DOC)
{
Object->TableDOC_TNUM_DOC=TableDOC_TNUM_DOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMTableNumberDocImpl::get_TableTYPE_TNUM_DOC(void)
{
return Object->TableTYPE_TNUM_DOC;
}
//---------------------------------------------------------------
void TDMTableNumberDocImpl::set_TableTYPE_TNUM_DOC(TFIBSmallIntField * TableTYPE_TNUM_DOC)
{
Object->TableTYPE_TNUM_DOC=TableTYPE_TNUM_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMTableNumberDocImpl::get_ElementGID_TNUM_DOC(void)
{
return Object->ElementGID_TNUM_DOC;
}
//---------------------------------------------------------------
void TDMTableNumberDocImpl::set_ElementGID_TNUM_DOC(TFIBWideStringField * ElementGID_TNUM_DOC)
{
Object->ElementGID_TNUM_DOC=ElementGID_TNUM_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMTableNumberDocImpl::get_ElementDOC_TNUM_DOC(void)
{
return Object->ElementDOC_TNUM_DOC;
}
//---------------------------------------------------------------
void TDMTableNumberDocImpl::set_ElementDOC_TNUM_DOC(TFIBWideStringField * ElementDOC_TNUM_DOC)
{
Object->ElementDOC_TNUM_DOC=ElementDOC_TNUM_DOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMTableNumberDocImpl::get_ElementTYPE_TNUM_DOC(void)
{
return Object->ElementTYPE_TNUM_DOC;
}
//---------------------------------------------------------------
void TDMTableNumberDocImpl::set_ElementTYPE_TNUM_DOC(TFIBSmallIntField * ElementTYPE_TNUM_DOC)
{
Object->ElementTYPE_TNUM_DOC=ElementTYPE_TNUM_DOC;
}
//---------------------------------------------------------------
void TDMTableNumberDocImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
void TDMTableNumberDocImpl::SaveIsmen()
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
void TDMTableNumberDocImpl::CancelIsmen()
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
int TDMTableNumberDocImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
void TDMTableNumberDocImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
void TDMTableNumberDocImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMTableNumberDocImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
TDateTime TDMTableNumberDocImpl::GetPosNachNumDoc(AnsiString type_doc)
{
return Object->GetPosNachNumDoc(type_doc);

}
//---------------------------------------------------------------
