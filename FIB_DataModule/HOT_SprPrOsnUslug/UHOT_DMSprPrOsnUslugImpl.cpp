#include "vcl.h"
#pragma hdrstop


#include "UHOT_DMSprPrOsnUslugImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THOT_DMSprPrOsnUslugImpl::THOT_DMSprPrOsnUslugImpl()           
{                                            
Object=new THOT_DMSprPrOsnUslug(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THOT_DMSprPrOsnUslugImpl::~THOT_DMSprPrOsnUslugImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THOT_DMSprPrOsnUslugImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHOT_DMSprPrOsnUslug)                        
   {                                                                     
   *ppv=static_cast<IHOT_DMSprPrOsnUslug*> (this);                                
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
int THOT_DMSprPrOsnUslugImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THOT_DMSprPrOsnUslugImpl::kanRelease(void)                                  
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
int  THOT_DMSprPrOsnUslugImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THOT_DMSprPrOsnUslugImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THOT_DMSprPrOsnUslugImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_THOT_DMSprPrOsnUslugImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THOT_DMSprPrOsnUslugImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IHOT_DMSprPrOsnUslug
TDataSource * THOT_DMSprPrOsnUslugImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * THOT_DMSprPrOsnUslugImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMSprPrOsnUslugImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMSprPrOsnUslugImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBQuery * THOT_DMSprPrOsnUslugImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMSprPrOsnUslugImpl::get_ElementID_HOT_SPROSNUSL(void)
{
return Object->ElementID_HOT_SPROSNUSL;
}
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::set_ElementID_HOT_SPROSNUSL(TFIBBCDField * ElementID_HOT_SPROSNUSL)
{
Object->ElementID_HOT_SPROSNUSL=ElementID_HOT_SPROSNUSL;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMSprPrOsnUslugImpl::get_ElementIDCAT_HOT_SPROSNUSL(void)
{
return Object->ElementIDCAT_HOT_SPROSNUSL;
}
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::set_ElementIDCAT_HOT_SPROSNUSL(TFIBBCDField * ElementIDCAT_HOT_SPROSNUSL)
{
Object->ElementIDCAT_HOT_SPROSNUSL=ElementIDCAT_HOT_SPROSNUSL;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMSprPrOsnUslugImpl::get_ElementIDNOMPR_HOT_SPROSNUSL(void)
{
return Object->ElementIDNOMPR_HOT_SPROSNUSL;
}
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::set_ElementIDNOMPR_HOT_SPROSNUSL(TFIBBCDField * ElementIDNOMPR_HOT_SPROSNUSL)
{
Object->ElementIDNOMPR_HOT_SPROSNUSL=ElementIDNOMPR_HOT_SPROSNUSL;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMSprPrOsnUslugImpl::get_ElementIDNOMBR_HOT_SPROSNUSL(void)
{
return Object->ElementIDNOMBR_HOT_SPROSNUSL;
}
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::set_ElementIDNOMBR_HOT_SPROSNUSL(TFIBBCDField * ElementIDNOMBR_HOT_SPROSNUSL)
{
Object->ElementIDNOMBR_HOT_SPROSNUSL=ElementIDNOMBR_HOT_SPROSNUSL;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMSprPrOsnUslugImpl::get_ElementIDTPOS_HOT_SPROSNUSL(void)
{
return Object->ElementIDTPOS_HOT_SPROSNUSL;
}
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::set_ElementIDTPOS_HOT_SPROSNUSL(TFIBBCDField * ElementIDTPOS_HOT_SPROSNUSL)
{
Object->ElementIDTPOS_HOT_SPROSNUSL=ElementIDTPOS_HOT_SPROSNUSL;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMSprPrOsnUslugImpl::get_TableID_HOT_SPROSNUSL(void)
{
return Object->TableID_HOT_SPROSNUSL;
}
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::set_TableID_HOT_SPROSNUSL(TFIBBCDField * TableID_HOT_SPROSNUSL)
{
Object->TableID_HOT_SPROSNUSL=TableID_HOT_SPROSNUSL;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMSprPrOsnUslugImpl::get_TableIDCAT_HOT_SPROSNUSL(void)
{
return Object->TableIDCAT_HOT_SPROSNUSL;
}
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::set_TableIDCAT_HOT_SPROSNUSL(TFIBBCDField * TableIDCAT_HOT_SPROSNUSL)
{
Object->TableIDCAT_HOT_SPROSNUSL=TableIDCAT_HOT_SPROSNUSL;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMSprPrOsnUslugImpl::get_TableIDNOMPR_HOT_SPROSNUSL(void)
{
return Object->TableIDNOMPR_HOT_SPROSNUSL;
}
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::set_TableIDNOMPR_HOT_SPROSNUSL(TFIBBCDField * TableIDNOMPR_HOT_SPROSNUSL)
{
Object->TableIDNOMPR_HOT_SPROSNUSL=TableIDNOMPR_HOT_SPROSNUSL;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMSprPrOsnUslugImpl::get_TableIDNOMBR_HOT_SPROSNUSL(void)
{
return Object->TableIDNOMBR_HOT_SPROSNUSL;
}
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::set_TableIDNOMBR_HOT_SPROSNUSL(TFIBBCDField * TableIDNOMBR_HOT_SPROSNUSL)
{
Object->TableIDNOMBR_HOT_SPROSNUSL=TableIDNOMBR_HOT_SPROSNUSL;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMSprPrOsnUslugImpl::get_TableIDTPOS_HOT_SPROSNUSL(void)
{
return Object->TableIDTPOS_HOT_SPROSNUSL;
}
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::set_TableIDTPOS_HOT_SPROSNUSL(TFIBBCDField * TableIDTPOS_HOT_SPROSNUSL)
{
Object->TableIDTPOS_HOT_SPROSNUSL=TableIDTPOS_HOT_SPROSNUSL;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMSprPrOsnUslugImpl::get_TableIDBASE_HOT_SPROSNUSL(void)
{
return Object->TableIDBASE_HOT_SPROSNUSL;
}
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::set_TableIDBASE_HOT_SPROSNUSL(TFIBBCDField * TableIDBASE_HOT_SPROSNUSL)
{
Object->TableIDBASE_HOT_SPROSNUSL=TableIDBASE_HOT_SPROSNUSL;
}
//---------------------------------------------------------------
TIntegerField * THOT_DMSprPrOsnUslugImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMSprPrOsnUslugImpl::get_TableNAME_HOT_SCATNOM(void)
{
return Object->TableNAME_HOT_SCATNOM;
}
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::set_TableNAME_HOT_SCATNOM(TFIBWideStringField * TableNAME_HOT_SCATNOM)
{
Object->TableNAME_HOT_SCATNOM=TableNAME_HOT_SCATNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMSprPrOsnUslugImpl::get_TableNAME_HOT_STYPEPOS(void)
{
return Object->TableNAME_HOT_STYPEPOS;
}
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::set_TableNAME_HOT_STYPEPOS(TFIBWideStringField * TableNAME_HOT_STYPEPOS)
{
Object->TableNAME_HOT_STYPEPOS=TableNAME_HOT_STYPEPOS;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMSprPrOsnUslugImpl::get_TableNAMENOMPR(void)
{
return Object->TableNAMENOMPR;
}
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::set_TableNAMENOMPR(TFIBWideStringField * TableNAMENOMPR)
{
Object->TableNAMENOMPR=TableNAMENOMPR;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMSprPrOsnUslugImpl::get_TableNAMENOMBR(void)
{
return Object->TableNAMENOMBR;
}
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::set_TableNAMENOMBR(TFIBWideStringField * TableNAMENOMBR)
{
Object->TableNAMENOMBR=TableNAMENOMBR;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMSprPrOsnUslugImpl::get_ElementNAME_HOT_SCATNOM(void)
{
return Object->ElementNAME_HOT_SCATNOM;
}
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::set_ElementNAME_HOT_SCATNOM(TFIBWideStringField * ElementNAME_HOT_SCATNOM)
{
Object->ElementNAME_HOT_SCATNOM=ElementNAME_HOT_SCATNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMSprPrOsnUslugImpl::get_ElementNAME_HOT_STYPEPOS(void)
{
return Object->ElementNAME_HOT_STYPEPOS;
}
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::set_ElementNAME_HOT_STYPEPOS(TFIBWideStringField * ElementNAME_HOT_STYPEPOS)
{
Object->ElementNAME_HOT_STYPEPOS=ElementNAME_HOT_STYPEPOS;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMSprPrOsnUslugImpl::get_ElementNAMENOMPR(void)
{
return Object->ElementNAMENOMPR;
}
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::set_ElementNAMENOMPR(TFIBWideStringField * ElementNAMENOMPR)
{
Object->ElementNAMENOMPR=ElementNAMENOMPR;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMSprPrOsnUslugImpl::get_ElementNAMENOMBR(void)
{
return Object->ElementNAMENOMBR;
}
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::set_ElementNAMENOMBR(TFIBWideStringField * ElementNAMENOMBR)
{
Object->ElementNAMENOMBR=ElementNAMENOMBR;
}
//---------------------------------------------------------------
__int64 THOT_DMSprPrOsnUslugImpl::get_IdNomBron(void)
{
return Object->IdNomBron;
}
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::set_IdNomBron(__int64 IdNomBron)
{
Object->IdNomBron=IdNomBron;
}
//---------------------------------------------------------------
__int64 THOT_DMSprPrOsnUslugImpl::get_IdNomProg(void)
{
return Object->IdNomProg;
}
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::set_IdNomProg(__int64 IdNomProg)
{
Object->IdNomProg=IdNomProg;
}
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::UpdateTable(void)
{
return Object->UpdateTable();
}
//---------------------------------------------------------------
int THOT_DMSprPrOsnUslugImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
bool THOT_DMSprPrOsnUslugImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool THOT_DMSprPrOsnUslugImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::CloseElement(void)
{
return Object->CloseElement();
}
//---------------------------------------------------------------
bool THOT_DMSprPrOsnUslugImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
int THOT_DMSprPrOsnUslugImpl::GetIndexElementaPoID(__int64 id)
{
return Object->GetIndexElementaPoID(id);
}
//---------------------------------------------------------------
void THOT_DMSprPrOsnUslugImpl::GetNomBronAndProg(__int64 id_cat,__int64 id_type_pos)
{
return Object->GetNomBronAndProg(id_cat, id_type_pos);
}
//---------------------------------------------------------------
