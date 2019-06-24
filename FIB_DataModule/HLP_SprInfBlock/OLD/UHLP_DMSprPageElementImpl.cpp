#include "vcl.h"
#pragma hdrstop


#include "UHLP_DMSprPageElementImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THLP_DMSprPageElementImpl::THLP_DMSprPageElementImpl()           
{                                            
Object=new THLP_DMSprPageElement(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THLP_DMSprPageElementImpl::~THLP_DMSprPageElementImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THLP_DMSprPageElementImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHLP_DMSprPageElement)                        
   {                                                                     
   *ppv=static_cast<IHLP_DMSprPageElement*> (this);                                
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
int THLP_DMSprPageElementImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THLP_DMSprPageElementImpl::kanRelease(void)                                  
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
int  THLP_DMSprPageElementImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THLP_DMSprPageElementImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THLP_DMSprPageElementImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_THLP_DMSprPageElementImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THLP_DMSprPageElementImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IHLP_DMSprPageElement
TDataSource * THLP_DMSprPageElementImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * THLP_DMSprPageElementImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * THLP_DMSprPageElementImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * THLP_DMSprPageElementImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TDataSource * THLP_DMSprPageElementImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * THLP_DMSprPageElementImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprPageElementImpl::get_TableID_HLP_PAGE_ELEMENT(void)
{
return Object->TableID_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_TableID_HLP_PAGE_ELEMENT(TFIBLargeIntField * TableID_HLP_PAGE_ELEMENT)
{
Object->TableID_HLP_PAGE_ELEMENT=TableID_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprPageElementImpl::get_TableIDBASE_HLP_PAGE_ELEMENT(void)
{
return Object->TableIDBASE_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_TableIDBASE_HLP_PAGE_ELEMENT(TFIBLargeIntField * TableIDBASE_HLP_PAGE_ELEMENT)
{
Object->TableIDBASE_HLP_PAGE_ELEMENT=TableIDBASE_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageElementImpl::get_TableGID_HLP_PAGE_ELEMENT(void)
{
return Object->TableGID_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_TableGID_HLP_PAGE_ELEMENT(TFIBWideStringField * TableGID_HLP_PAGE_ELEMENT)
{
Object->TableGID_HLP_PAGE_ELEMENT=TableGID_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageElementImpl::get_TableGUID_HLP_PAGE_ELEMENT(void)
{
return Object->TableGUID_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_TableGUID_HLP_PAGE_ELEMENT(TFIBWideStringField * TableGUID_HLP_PAGE_ELEMENT)
{
Object->TableGUID_HLP_PAGE_ELEMENT=TableGUID_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprPageElementImpl::get_TableIDPAGE_HLP_PAGE_ELEMENT(void)
{
return Object->TableIDPAGE_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_TableIDPAGE_HLP_PAGE_ELEMENT(TFIBLargeIntField * TableIDPAGE_HLP_PAGE_ELEMENT)
{
Object->TableIDPAGE_HLP_PAGE_ELEMENT=TableIDPAGE_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
TFIBSmallIntField * THLP_DMSprPageElementImpl::get_TableTYPE_HLP_PAGE_ELEMENT(void)
{
return Object->TableTYPE_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_TableTYPE_HLP_PAGE_ELEMENT(TFIBSmallIntField * TableTYPE_HLP_PAGE_ELEMENT)
{
Object->TableTYPE_HLP_PAGE_ELEMENT=TableTYPE_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageElementImpl::get_TableTEXT_HLP_PAGE_ELEMENT(void)
{
return Object->TableTEXT_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_TableTEXT_HLP_PAGE_ELEMENT(TFIBWideStringField * TableTEXT_HLP_PAGE_ELEMENT)
{
Object->TableTEXT_HLP_PAGE_ELEMENT=TableTEXT_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageElementImpl::get_TableGUIDPAGE_HLP_PAGE_ELEMENT(void)
{
return Object->TableGUIDPAGE_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_TableGUIDPAGE_HLP_PAGE_ELEMENT(TFIBWideStringField * TableGUIDPAGE_HLP_PAGE_ELEMENT)
{
Object->TableGUIDPAGE_HLP_PAGE_ELEMENT=TableGUIDPAGE_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageElementImpl::get_TableGUIDIMAGE_HLP_PAGE_ELEMENT(void)
{
return Object->TableGUIDIMAGE_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_TableGUIDIMAGE_HLP_PAGE_ELEMENT(TFIBWideStringField * TableGUIDIMAGE_HLP_PAGE_ELEMENT)
{
Object->TableGUIDIMAGE_HLP_PAGE_ELEMENT=TableGUIDIMAGE_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprPageElementImpl::get_ElementID_HLP_PAGE_ELEMENT(void)
{
return Object->ElementID_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_ElementID_HLP_PAGE_ELEMENT(TFIBLargeIntField * ElementID_HLP_PAGE_ELEMENT)
{
Object->ElementID_HLP_PAGE_ELEMENT=ElementID_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprPageElementImpl::get_ElementIDBASE_HLP_PAGE_ELEMENT(void)
{
return Object->ElementIDBASE_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_ElementIDBASE_HLP_PAGE_ELEMENT(TFIBLargeIntField * ElementIDBASE_HLP_PAGE_ELEMENT)
{
Object->ElementIDBASE_HLP_PAGE_ELEMENT=ElementIDBASE_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageElementImpl::get_ElementGID_HLP_PAGE_ELEMENT(void)
{
return Object->ElementGID_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_ElementGID_HLP_PAGE_ELEMENT(TFIBWideStringField * ElementGID_HLP_PAGE_ELEMENT)
{
Object->ElementGID_HLP_PAGE_ELEMENT=ElementGID_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageElementImpl::get_ElementGUID_HLP_PAGE_ELEMENT(void)
{
return Object->ElementGUID_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_ElementGUID_HLP_PAGE_ELEMENT(TFIBWideStringField * ElementGUID_HLP_PAGE_ELEMENT)
{
Object->ElementGUID_HLP_PAGE_ELEMENT=ElementGUID_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprPageElementImpl::get_ElementIDPAGE_HLP_PAGE_ELEMENT(void)
{
return Object->ElementIDPAGE_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_ElementIDPAGE_HLP_PAGE_ELEMENT(TFIBLargeIntField * ElementIDPAGE_HLP_PAGE_ELEMENT)
{
Object->ElementIDPAGE_HLP_PAGE_ELEMENT=ElementIDPAGE_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
TFIBSmallIntField * THLP_DMSprPageElementImpl::get_ElementTYPE_HLP_PAGE_ELEMENT(void)
{
return Object->ElementTYPE_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_ElementTYPE_HLP_PAGE_ELEMENT(TFIBSmallIntField * ElementTYPE_HLP_PAGE_ELEMENT)
{
Object->ElementTYPE_HLP_PAGE_ELEMENT=ElementTYPE_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageElementImpl::get_ElementTEXT_HLP_PAGE_ELEMENT(void)
{
return Object->ElementTEXT_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_ElementTEXT_HLP_PAGE_ELEMENT(TFIBWideStringField * ElementTEXT_HLP_PAGE_ELEMENT)
{
Object->ElementTEXT_HLP_PAGE_ELEMENT=ElementTEXT_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageElementImpl::get_ElementGUIDPAGE_HLP_PAGE_ELEMENT(void)
{
return Object->ElementGUIDPAGE_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_ElementGUIDPAGE_HLP_PAGE_ELEMENT(TFIBWideStringField * ElementGUIDPAGE_HLP_PAGE_ELEMENT)
{
Object->ElementGUIDPAGE_HLP_PAGE_ELEMENT=ElementGUIDPAGE_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageElementImpl::get_ElementGUIDIMAGE_HLP_PAGE_ELEMENT(void)
{
return Object->ElementGUIDIMAGE_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_ElementGUIDIMAGE_HLP_PAGE_ELEMENT(TFIBWideStringField * ElementGUIDIMAGE_HLP_PAGE_ELEMENT)
{
Object->ElementGUIDIMAGE_HLP_PAGE_ELEMENT=ElementGUIDIMAGE_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprPageElementImpl::get_TableIDIMAGE_HLP_PAGE_ELEMENT(void)
{
return Object->TableIDIMAGE_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_TableIDIMAGE_HLP_PAGE_ELEMENT(TFIBLargeIntField * TableIDIMAGE_HLP_PAGE_ELEMENT)
{
Object->TableIDIMAGE_HLP_PAGE_ELEMENT=TableIDIMAGE_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprPageElementImpl::get_TableINDEX_HLP_PAGE_ELEMENT(void)
{
return Object->TableINDEX_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_TableINDEX_HLP_PAGE_ELEMENT(TFIBIntegerField * TableINDEX_HLP_PAGE_ELEMENT)
{
Object->TableINDEX_HLP_PAGE_ELEMENT=TableINDEX_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprPageElementImpl::get_ElementIDIMAGE_HLP_PAGE_ELEMENT(void)
{
return Object->ElementIDIMAGE_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_ElementIDIMAGE_HLP_PAGE_ELEMENT(TFIBLargeIntField * ElementIDIMAGE_HLP_PAGE_ELEMENT)
{
Object->ElementIDIMAGE_HLP_PAGE_ELEMENT=ElementIDIMAGE_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
TFIBSmallIntField * THLP_DMSprPageElementImpl::get_ElementTYPE_TBL_HLP_PAGE_ELEMENT(void)
{
return Object->ElementTYPE_TBL_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_ElementTYPE_TBL_HLP_PAGE_ELEMENT(TFIBSmallIntField * ElementTYPE_TBL_HLP_PAGE_ELEMENT)
{
Object->ElementTYPE_TBL_HLP_PAGE_ELEMENT=ElementTYPE_TBL_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprPageElementImpl::get_ElementINDEX_HLP_PAGE_ELEMENT(void)
{
return Object->ElementINDEX_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_ElementINDEX_HLP_PAGE_ELEMENT(TFIBIntegerField * ElementINDEX_HLP_PAGE_ELEMENT)
{
Object->ElementINDEX_HLP_PAGE_ELEMENT=ElementINDEX_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageElementImpl::get_TableNAME_HLP_IMAGE(void)
{
return Object->TableNAME_HLP_IMAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_TableNAME_HLP_IMAGE(TFIBWideStringField * TableNAME_HLP_IMAGE)
{
Object->TableNAME_HLP_IMAGE=TableNAME_HLP_IMAGE;
}
//---------------------------------------------------------------
TFIBBlobField * THLP_DMSprPageElementImpl::get_TableIMAGE_HLP_IMAGE(void)
{
return Object->TableIMAGE_HLP_IMAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_TableIMAGE_HLP_IMAGE(TFIBBlobField * TableIMAGE_HLP_IMAGE)
{
Object->TableIMAGE_HLP_IMAGE=TableIMAGE_HLP_IMAGE;
}
//---------------------------------------------------------------
TFIBSmallIntField * THLP_DMSprPageElementImpl::get_TableTYPE_HLP_IMAGE(void)
{
return Object->TableTYPE_HLP_IMAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_TableTYPE_HLP_IMAGE(TFIBSmallIntField * TableTYPE_HLP_IMAGE)
{
Object->TableTYPE_HLP_IMAGE=TableTYPE_HLP_IMAGE;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprPageElementImpl::get_TableH_ALIGN_HLP_PAGE_ELEMENT(void)
{
return Object->TableH_ALIGN_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_TableH_ALIGN_HLP_PAGE_ELEMENT(TFIBIntegerField * TableH_ALIGN_HLP_PAGE_ELEMENT)
{
Object->TableH_ALIGN_HLP_PAGE_ELEMENT=TableH_ALIGN_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprPageElementImpl::get_ElementH_ALIGN_HLP_PAGE_ELEMENT(void)
{
return Object->ElementH_ALIGN_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_ElementH_ALIGN_HLP_PAGE_ELEMENT(TFIBIntegerField * ElementH_ALIGN_HLP_PAGE_ELEMENT)
{
Object->ElementH_ALIGN_HLP_PAGE_ELEMENT=ElementH_ALIGN_HLP_PAGE_ELEMENT;
}
//---------------------------------------------------------------
__int64 THLP_DMSprPageElementImpl::get_IdPage(void)
{
return Object->IdPage;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_IdPage(__int64 IdPage)
{
Object->IdPage=IdPage;
}
//---------------------------------------------------------------
__int64 THLP_DMSprPageElementImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void THLP_DMSprPageElementImpl::OpenTable(__int64 id_page)
{
return Object->OpenTable(id_page);
}
//---------------------------------------------------------------
bool THLP_DMSprPageElementImpl::SaveIsmen(void)
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
bool THLP_DMSprPageElementImpl::CancelIsmen(void)
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
bool THLP_DMSprPageElementImpl::TableAppend(__int64 id_page)
{
return Object->TableAppend(id_page);
}
//---------------------------------------------------------------
bool THLP_DMSprPageElementImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
bool THLP_DMSprPageElementImpl::NewElement(__int64 id_page)
{
return Object->NewElement(id_page);
}
//---------------------------------------------------------------
int THLP_DMSprPageElementImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool THLP_DMSprPageElementImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool THLP_DMSprPageElementImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
