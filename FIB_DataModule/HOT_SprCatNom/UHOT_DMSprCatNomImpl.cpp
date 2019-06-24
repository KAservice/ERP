#include "vcl.h"
#pragma hdrstop


#include "UHOT_DMSprCatNomImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THOT_DMSprCatNomImpl::THOT_DMSprCatNomImpl()           
{                                            
Object=new THOT_DMSprCatNom(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THOT_DMSprCatNomImpl::~THOT_DMSprCatNomImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THOT_DMSprCatNomImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THOT_DMSprCatNomImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHOT_DMSprCatNom)                        
   {                                                                     
   *ppv=static_cast<IHOT_DMSprCatNom*> (this);                                
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
int THOT_DMSprCatNomImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THOT_DMSprCatNomImpl::kanRelease(void)                                  
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
int  THOT_DMSprCatNomImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THOT_DMSprCatNomImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THOT_DMSprCatNomImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THOT_DMSprCatNomImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THOT_DMSprCatNomImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_THOT_DMSprCatNomImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THOT_DMSprCatNomImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IHOT_DMSprCatNom
TDataSource * THOT_DMSprCatNomImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void THOT_DMSprCatNomImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * THOT_DMSprCatNomImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void THOT_DMSprCatNomImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMSprCatNomImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void THOT_DMSprCatNomImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMSprCatNomImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void THOT_DMSprCatNomImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TIntegerField * THOT_DMSprCatNomImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void THOT_DMSprCatNomImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * THOT_DMSprCatNomImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void THOT_DMSprCatNomImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMSprCatNomImpl::get_ElementID_HOT_SCATNOM(void)
{
return Object->ElementID_HOT_SCATNOM;
}
//---------------------------------------------------------------
void THOT_DMSprCatNomImpl::set_ElementID_HOT_SCATNOM(TFIBBCDField * ElementID_HOT_SCATNOM)
{
Object->ElementID_HOT_SCATNOM=ElementID_HOT_SCATNOM;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMSprCatNomImpl::get_TableID_HOT_SCATNOM(void)
{
return Object->TableID_HOT_SCATNOM;
}
//---------------------------------------------------------------
void THOT_DMSprCatNomImpl::set_TableID_HOT_SCATNOM(TFIBBCDField * TableID_HOT_SCATNOM)
{
Object->TableID_HOT_SCATNOM=TableID_HOT_SCATNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMSprCatNomImpl::get_ElementNAME_HOT_SCATNOM(void)
{
return Object->ElementNAME_HOT_SCATNOM;
}
//---------------------------------------------------------------
void THOT_DMSprCatNomImpl::set_ElementNAME_HOT_SCATNOM(TFIBWideStringField * ElementNAME_HOT_SCATNOM)
{
Object->ElementNAME_HOT_SCATNOM=ElementNAME_HOT_SCATNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMSprCatNomImpl::get_ElementDESCR_HOT_SCATNOM(void)
{
return Object->ElementDESCR_HOT_SCATNOM;
}
//---------------------------------------------------------------
void THOT_DMSprCatNomImpl::set_ElementDESCR_HOT_SCATNOM(TFIBWideStringField * ElementDESCR_HOT_SCATNOM)
{
Object->ElementDESCR_HOT_SCATNOM=ElementDESCR_HOT_SCATNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMSprCatNomImpl::get_TableNAME_HOT_SCATNOM(void)
{
return Object->TableNAME_HOT_SCATNOM;
}
//---------------------------------------------------------------
void THOT_DMSprCatNomImpl::set_TableNAME_HOT_SCATNOM(TFIBWideStringField * TableNAME_HOT_SCATNOM)
{
Object->TableNAME_HOT_SCATNOM=TableNAME_HOT_SCATNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMSprCatNomImpl::get_TableDESCR_HOT_SCATNOM(void)
{
return Object->TableDESCR_HOT_SCATNOM;
}
//---------------------------------------------------------------
void THOT_DMSprCatNomImpl::set_TableDESCR_HOT_SCATNOM(TFIBWideStringField * TableDESCR_HOT_SCATNOM)
{
Object->TableDESCR_HOT_SCATNOM=TableDESCR_HOT_SCATNOM;
}
//---------------------------------------------------------------
void THOT_DMSprCatNomImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int THOT_DMSprCatNomImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
bool THOT_DMSprCatNomImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool THOT_DMSprCatNomImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void THOT_DMSprCatNomImpl::CloseElement(void)
{
return Object->CloseElement();
}
//---------------------------------------------------------------
bool THOT_DMSprCatNomImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
__int64 THOT_DMSprCatNomImpl::GetIDElement(String gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
AnsiString THOT_DMSprCatNomImpl::GetGIDElement(__int64 id)
{
return Object->GetGIDElement(id);
}
//---------------------------------------------------------------
int THOT_DMSprCatNomImpl::GetIndexElementaPoID(__int64 id)
{
return Object->GetIndexElementaPoID(id);
}
//---------------------------------------------------------------
