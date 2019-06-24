#include "vcl.h"
#pragma hdrstop


#include "UART_DMSprInfBlockSostavImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TART_DMSprInfBlockSostavImpl::TART_DMSprInfBlockSostavImpl()           
{                                            
Object=new TART_DMSprInfBlockSostav(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TART_DMSprInfBlockSostavImpl::~TART_DMSprInfBlockSostavImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TART_DMSprInfBlockSostavImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IART_DMSprInfBlockSostav)                        
   {                                                                     
   *ppv=static_cast<IART_DMSprInfBlockSostav*> (this);                                
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
int TART_DMSprInfBlockSostavImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TART_DMSprInfBlockSostavImpl::kanRelease(void)                                  
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
int  TART_DMSprInfBlockSostavImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TART_DMSprInfBlockSostavImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TART_DMSprInfBlockSostavImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TART_DMSprInfBlockSostavImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TART_DMSprInfBlockSostavImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IART_DMSprInfBlockSostav
TDataSource * TART_DMSprInfBlockSostavImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TART_DMSprInfBlockSostavImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TART_DMSprInfBlockSostavImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TART_DMSprInfBlockSostavImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TDataSource * TART_DMSprInfBlockSostavImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TART_DMSprInfBlockSostavImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprInfBlockSostavImpl::get_TableID_ART_IB_S(void)
{
return Object->TableID_ART_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_TableID_ART_IB_S(TFIBLargeIntField * TableID_ART_IB_S)
{
Object->TableID_ART_IB_S=TableID_ART_IB_S;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprInfBlockSostavImpl::get_TableIDBASE_ART_IB_S(void)
{
return Object->TableIDBASE_ART_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_TableIDBASE_ART_IB_S(TFIBLargeIntField * TableIDBASE_ART_IB_S)
{
Object->TableIDBASE_ART_IB_S=TableIDBASE_ART_IB_S;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprInfBlockSostavImpl::get_TableGUID_ART_IB_S(void)
{
return Object->TableGUID_ART_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_TableGUID_ART_IB_S(TFIBWideStringField * TableGUID_ART_IB_S)
{
Object->TableGUID_ART_IB_S=TableGUID_ART_IB_S;
}
//---------------------------------------------------------------
TFIBDateTimeField * TART_DMSprInfBlockSostavImpl::get_TablePOS_ISM_ART_IB_S(void)
{
return Object->TablePOS_ISM_ART_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_TablePOS_ISM_ART_IB_S(TFIBDateTimeField * TablePOS_ISM_ART_IB_S)
{
Object->TablePOS_ISM_ART_IB_S=TablePOS_ISM_ART_IB_S;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprInfBlockSostavImpl::get_TableIDIB_ART_IB_S(void)
{
return Object->TableIDIB_ART_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_TableIDIB_ART_IB_S(TFIBLargeIntField * TableIDIB_ART_IB_S)
{
Object->TableIDIB_ART_IB_S=TableIDIB_ART_IB_S;
}
//---------------------------------------------------------------
TFIBSmallIntField * TART_DMSprInfBlockSostavImpl::get_TableTYPE_ART_IB_S(void)
{
return Object->TableTYPE_ART_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_TableTYPE_ART_IB_S(TFIBSmallIntField * TableTYPE_ART_IB_S)
{
Object->TableTYPE_ART_IB_S=TableTYPE_ART_IB_S;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprInfBlockSostavImpl::get_TableTEXT_ART_IB_S(void)
{
return Object->TableTEXT_ART_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_TableTEXT_ART_IB_S(TFIBWideStringField * TableTEXT_ART_IB_S)
{
Object->TableTEXT_ART_IB_S=TableTEXT_ART_IB_S;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprInfBlockSostavImpl::get_TableIDIMG_ART_IB_S(void)
{
return Object->TableIDIMG_ART_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_TableIDIMG_ART_IB_S(TFIBLargeIntField * TableIDIMG_ART_IB_S)
{
Object->TableIDIMG_ART_IB_S=TableIDIMG_ART_IB_S;
}
//---------------------------------------------------------------
TFIBIntegerField * TART_DMSprInfBlockSostavImpl::get_TableINDEX_ART_IB_S(void)
{
return Object->TableINDEX_ART_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_TableINDEX_ART_IB_S(TFIBIntegerField * TableINDEX_ART_IB_S)
{
Object->TableINDEX_ART_IB_S=TableINDEX_ART_IB_S;
}
//---------------------------------------------------------------
TFIBIntegerField * TART_DMSprInfBlockSostavImpl::get_TableH_ALIGN_ART_IB_S(void)
{
return Object->TableH_ALIGN_ART_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_TableH_ALIGN_ART_IB_S(TFIBIntegerField * TableH_ALIGN_ART_IB_S)
{
Object->TableH_ALIGN_ART_IB_S=TableH_ALIGN_ART_IB_S;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprInfBlockSostavImpl::get_TableNAME_ART_IMG(void)
{
return Object->TableNAME_ART_IMG;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_TableNAME_ART_IMG(TFIBWideStringField * TableNAME_ART_IMG)
{
Object->TableNAME_ART_IMG=TableNAME_ART_IMG;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprInfBlockSostavImpl::get_ElementID_ART_IB_S(void)
{
return Object->ElementID_ART_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_ElementID_ART_IB_S(TFIBLargeIntField * ElementID_ART_IB_S)
{
Object->ElementID_ART_IB_S=ElementID_ART_IB_S;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprInfBlockSostavImpl::get_ElementIDBASE_ART_IB_S(void)
{
return Object->ElementIDBASE_ART_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_ElementIDBASE_ART_IB_S(TFIBLargeIntField * ElementIDBASE_ART_IB_S)
{
Object->ElementIDBASE_ART_IB_S=ElementIDBASE_ART_IB_S;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprInfBlockSostavImpl::get_ElementGUID_ART_IB_S(void)
{
return Object->ElementGUID_ART_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_ElementGUID_ART_IB_S(TFIBWideStringField * ElementGUID_ART_IB_S)
{
Object->ElementGUID_ART_IB_S=ElementGUID_ART_IB_S;
}
//---------------------------------------------------------------
TFIBDateTimeField * TART_DMSprInfBlockSostavImpl::get_ElementPOS_ISM_ART_IB_S(void)
{
return Object->ElementPOS_ISM_ART_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_ElementPOS_ISM_ART_IB_S(TFIBDateTimeField * ElementPOS_ISM_ART_IB_S)
{
Object->ElementPOS_ISM_ART_IB_S=ElementPOS_ISM_ART_IB_S;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprInfBlockSostavImpl::get_ElementIDIB_ART_IB_S(void)
{
return Object->ElementIDIB_ART_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_ElementIDIB_ART_IB_S(TFIBLargeIntField * ElementIDIB_ART_IB_S)
{
Object->ElementIDIB_ART_IB_S=ElementIDIB_ART_IB_S;
}
//---------------------------------------------------------------
TFIBSmallIntField * TART_DMSprInfBlockSostavImpl::get_ElementTYPE_ART_IB_S(void)
{
return Object->ElementTYPE_ART_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_ElementTYPE_ART_IB_S(TFIBSmallIntField * ElementTYPE_ART_IB_S)
{
Object->ElementTYPE_ART_IB_S=ElementTYPE_ART_IB_S;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprInfBlockSostavImpl::get_ElementTEXT_ART_IB_S(void)
{
return Object->ElementTEXT_ART_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_ElementTEXT_ART_IB_S(TFIBWideStringField * ElementTEXT_ART_IB_S)
{
Object->ElementTEXT_ART_IB_S=ElementTEXT_ART_IB_S;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprInfBlockSostavImpl::get_ElementIDIMG_ART_IB_S(void)
{
return Object->ElementIDIMG_ART_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_ElementIDIMG_ART_IB_S(TFIBLargeIntField * ElementIDIMG_ART_IB_S)
{
Object->ElementIDIMG_ART_IB_S=ElementIDIMG_ART_IB_S;
}
//---------------------------------------------------------------
TFIBIntegerField * TART_DMSprInfBlockSostavImpl::get_ElementINDEX_ART_IB_S(void)
{
return Object->ElementINDEX_ART_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_ElementINDEX_ART_IB_S(TFIBIntegerField * ElementINDEX_ART_IB_S)
{
Object->ElementINDEX_ART_IB_S=ElementINDEX_ART_IB_S;
}
//---------------------------------------------------------------
TFIBIntegerField * TART_DMSprInfBlockSostavImpl::get_ElementH_ALIGN_ART_IB_S(void)
{
return Object->ElementH_ALIGN_ART_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_ElementH_ALIGN_ART_IB_S(TFIBIntegerField * ElementH_ALIGN_ART_IB_S)
{
Object->ElementH_ALIGN_ART_IB_S=ElementH_ALIGN_ART_IB_S;
}
//---------------------------------------------------------------
TFIBIntegerField * TART_DMSprInfBlockSostavImpl::get_ElementV_ALIGN_ART_IB_S(void)
{
return Object->ElementV_ALIGN_ART_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_ElementV_ALIGN_ART_IB_S(TFIBIntegerField * ElementV_ALIGN_ART_IB_S)
{
Object->ElementV_ALIGN_ART_IB_S=ElementV_ALIGN_ART_IB_S;
}
//---------------------------------------------------------------
TFIBIntegerField * TART_DMSprInfBlockSostavImpl::get_ElementTYPE_TEXT_ART_IB_S(void)
{
return Object->ElementTYPE_TEXT_ART_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_ElementTYPE_TEXT_ART_IB_S(TFIBIntegerField * ElementTYPE_TEXT_ART_IB_S)
{
Object->ElementTYPE_TEXT_ART_IB_S=ElementTYPE_TEXT_ART_IB_S;
}
//---------------------------------------------------------------
TFIBIntegerField * TART_DMSprInfBlockSostavImpl::get_TableV_ALIGN_ART_IB_S(void)
{
return Object->TableV_ALIGN_ART_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_TableV_ALIGN_ART_IB_S(TFIBIntegerField * TableV_ALIGN_ART_IB_S)
{
Object->TableV_ALIGN_ART_IB_S=TableV_ALIGN_ART_IB_S;
}
//---------------------------------------------------------------
TFIBIntegerField * TART_DMSprInfBlockSostavImpl::get_TableTYPE_TEXT_ART_IB_S(void)
{
return Object->TableTYPE_TEXT_ART_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_TableTYPE_TEXT_ART_IB_S(TFIBIntegerField * TableTYPE_TEXT_ART_IB_S)
{
Object->TableTYPE_TEXT_ART_IB_S=TableTYPE_TEXT_ART_IB_S;
}
//---------------------------------------------------------------
TFIBIntegerField * TART_DMSprInfBlockSostavImpl::get_TableFONT_SIZE_ART_IB_S(void)
{
return Object->TableFONT_SIZE_ART_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_TableFONT_SIZE_ART_IB_S(TFIBIntegerField * TableFONT_SIZE_ART_IB_S)
{
Object->TableFONT_SIZE_ART_IB_S=TableFONT_SIZE_ART_IB_S;
}
//---------------------------------------------------------------
TFIBIntegerField * TART_DMSprInfBlockSostavImpl::get_ElementFONT_SIZE_ART_IB_S(void)
{
return Object->ElementFONT_SIZE_ART_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_ElementFONT_SIZE_ART_IB_S(TFIBIntegerField * ElementFONT_SIZE_ART_IB_S)
{
Object->ElementFONT_SIZE_ART_IB_S=ElementFONT_SIZE_ART_IB_S;
}
//---------------------------------------------------------------
__int64 TART_DMSprInfBlockSostavImpl::get_IdIB(void)
{
return Object->IdIB;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_IdIB(__int64 IdIB)
{
Object->IdIB=IdIB;
}
//---------------------------------------------------------------
__int64 TART_DMSprInfBlockSostavImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockSostavImpl::OpenTable(__int64 id_ib)
{
return Object->OpenTable(id_ib);
}
//---------------------------------------------------------------
bool TART_DMSprInfBlockSostavImpl::SaveIsmen(void)
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
bool TART_DMSprInfBlockSostavImpl::CancelIsmen(void)
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
bool TART_DMSprInfBlockSostavImpl::TableAppend(__int64 id_ib)
{
return Object->TableAppend(id_ib);
}
//---------------------------------------------------------------
bool TART_DMSprInfBlockSostavImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
bool TART_DMSprInfBlockSostavImpl::NewElement(__int64 id_ib)
{
return Object->NewElement(id_ib);
}
//---------------------------------------------------------------
int TART_DMSprInfBlockSostavImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool TART_DMSprInfBlockSostavImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TART_DMSprInfBlockSostavImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
