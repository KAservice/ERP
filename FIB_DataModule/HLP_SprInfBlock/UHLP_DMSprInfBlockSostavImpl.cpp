#include "vcl.h"
#pragma hdrstop


#include "UHLP_DMSprInfBlockSostavImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THLP_DMSprInfBlockSostavImpl::THLP_DMSprInfBlockSostavImpl()           
{                                            
Object=new THLP_DMSprInfBlockSostav(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THLP_DMSprInfBlockSostavImpl::~THLP_DMSprInfBlockSostavImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THLP_DMSprInfBlockSostavImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHLP_DMSprInfBlockSostav)                        
   {                                                                     
   *ppv=static_cast<IHLP_DMSprInfBlockSostav*> (this);                                
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
int THLP_DMSprInfBlockSostavImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THLP_DMSprInfBlockSostavImpl::kanRelease(void)                                  
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
int  THLP_DMSprInfBlockSostavImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THLP_DMSprInfBlockSostavImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THLP_DMSprInfBlockSostavImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_THLP_DMSprInfBlockSostavImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THLP_DMSprInfBlockSostavImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IHLP_DMSprInfBlockSostav
TDataSource * THLP_DMSprInfBlockSostavImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * THLP_DMSprInfBlockSostavImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * THLP_DMSprInfBlockSostavImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * THLP_DMSprInfBlockSostavImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TDataSource * THLP_DMSprInfBlockSostavImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * THLP_DMSprInfBlockSostavImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprInfBlockSostavImpl::get_TableID_HLP_IB_S(void)
{
return Object->TableID_HLP_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_TableID_HLP_IB_S(TFIBLargeIntField * TableID_HLP_IB_S)
{
Object->TableID_HLP_IB_S=TableID_HLP_IB_S;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprInfBlockSostavImpl::get_TableIDBASE_HLP_IB_S(void)
{
return Object->TableIDBASE_HLP_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_TableIDBASE_HLP_IB_S(TFIBLargeIntField * TableIDBASE_HLP_IB_S)
{
Object->TableIDBASE_HLP_IB_S=TableIDBASE_HLP_IB_S;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockSostavImpl::get_TableGUID_HLP_IB_S(void)
{
return Object->TableGUID_HLP_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_TableGUID_HLP_IB_S(TFIBWideStringField * TableGUID_HLP_IB_S)
{
Object->TableGUID_HLP_IB_S=TableGUID_HLP_IB_S;
}
//---------------------------------------------------------------
TFIBDateTimeField * THLP_DMSprInfBlockSostavImpl::get_TablePOS_ISM_HLP_IB_S(void)
{
return Object->TablePOS_ISM_HLP_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_TablePOS_ISM_HLP_IB_S(TFIBDateTimeField * TablePOS_ISM_HLP_IB_S)
{
Object->TablePOS_ISM_HLP_IB_S=TablePOS_ISM_HLP_IB_S;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprInfBlockSostavImpl::get_TableIDIB_HLP_IB_S(void)
{
return Object->TableIDIB_HLP_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_TableIDIB_HLP_IB_S(TFIBLargeIntField * TableIDIB_HLP_IB_S)
{
Object->TableIDIB_HLP_IB_S=TableIDIB_HLP_IB_S;
}
//---------------------------------------------------------------
TFIBSmallIntField * THLP_DMSprInfBlockSostavImpl::get_TableTYPE_HLP_IB_S(void)
{
return Object->TableTYPE_HLP_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_TableTYPE_HLP_IB_S(TFIBSmallIntField * TableTYPE_HLP_IB_S)
{
Object->TableTYPE_HLP_IB_S=TableTYPE_HLP_IB_S;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockSostavImpl::get_TableTEXT_HLP_IB_S(void)
{
return Object->TableTEXT_HLP_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_TableTEXT_HLP_IB_S(TFIBWideStringField * TableTEXT_HLP_IB_S)
{
Object->TableTEXT_HLP_IB_S=TableTEXT_HLP_IB_S;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprInfBlockSostavImpl::get_TableIDIMG_HLP_IB_S(void)
{
return Object->TableIDIMG_HLP_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_TableIDIMG_HLP_IB_S(TFIBLargeIntField * TableIDIMG_HLP_IB_S)
{
Object->TableIDIMG_HLP_IB_S=TableIDIMG_HLP_IB_S;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprInfBlockSostavImpl::get_TableINDEX_HLP_IB_S(void)
{
return Object->TableINDEX_HLP_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_TableINDEX_HLP_IB_S(TFIBIntegerField * TableINDEX_HLP_IB_S)
{
Object->TableINDEX_HLP_IB_S=TableINDEX_HLP_IB_S;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprInfBlockSostavImpl::get_TableH_ALIGN_HLP_IB_S(void)
{
return Object->TableH_ALIGN_HLP_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_TableH_ALIGN_HLP_IB_S(TFIBIntegerField * TableH_ALIGN_HLP_IB_S)
{
Object->TableH_ALIGN_HLP_IB_S=TableH_ALIGN_HLP_IB_S;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprInfBlockSostavImpl::get_TableV_ALIGN_HLP_IB_S(void)
{
return Object->TableV_ALIGN_HLP_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_TableV_ALIGN_HLP_IB_S(TFIBIntegerField * TableV_ALIGN_HLP_IB_S)
{
Object->TableV_ALIGN_HLP_IB_S=TableV_ALIGN_HLP_IB_S;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprInfBlockSostavImpl::get_TableTYPE_TEXT_HLP_IB_S(void)
{
return Object->TableTYPE_TEXT_HLP_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_TableTYPE_TEXT_HLP_IB_S(TFIBIntegerField * TableTYPE_TEXT_HLP_IB_S)
{
Object->TableTYPE_TEXT_HLP_IB_S=TableTYPE_TEXT_HLP_IB_S;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprInfBlockSostavImpl::get_TableFONT_SIZE_HLP_IB_S(void)
{
return Object->TableFONT_SIZE_HLP_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_TableFONT_SIZE_HLP_IB_S(TFIBIntegerField * TableFONT_SIZE_HLP_IB_S)
{
Object->TableFONT_SIZE_HLP_IB_S=TableFONT_SIZE_HLP_IB_S;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockSostavImpl::get_TableNAME_HLP_IMG(void)
{
return Object->TableNAME_HLP_IMG;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_TableNAME_HLP_IMG(TFIBWideStringField * TableNAME_HLP_IMG)
{
Object->TableNAME_HLP_IMG=TableNAME_HLP_IMG;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprInfBlockSostavImpl::get_ElementID_HLP_IB_S(void)
{
return Object->ElementID_HLP_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_ElementID_HLP_IB_S(TFIBLargeIntField * ElementID_HLP_IB_S)
{
Object->ElementID_HLP_IB_S=ElementID_HLP_IB_S;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprInfBlockSostavImpl::get_ElementIDBASE_HLP_IB_S(void)
{
return Object->ElementIDBASE_HLP_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_ElementIDBASE_HLP_IB_S(TFIBLargeIntField * ElementIDBASE_HLP_IB_S)
{
Object->ElementIDBASE_HLP_IB_S=ElementIDBASE_HLP_IB_S;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockSostavImpl::get_ElementGUID_HLP_IB_S(void)
{
return Object->ElementGUID_HLP_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_ElementGUID_HLP_IB_S(TFIBWideStringField * ElementGUID_HLP_IB_S)
{
Object->ElementGUID_HLP_IB_S=ElementGUID_HLP_IB_S;
}
//---------------------------------------------------------------
TFIBDateTimeField * THLP_DMSprInfBlockSostavImpl::get_ElementPOS_ISM_HLP_IB_S(void)
{
return Object->ElementPOS_ISM_HLP_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_ElementPOS_ISM_HLP_IB_S(TFIBDateTimeField * ElementPOS_ISM_HLP_IB_S)
{
Object->ElementPOS_ISM_HLP_IB_S=ElementPOS_ISM_HLP_IB_S;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprInfBlockSostavImpl::get_ElementIDIB_HLP_IB_S(void)
{
return Object->ElementIDIB_HLP_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_ElementIDIB_HLP_IB_S(TFIBLargeIntField * ElementIDIB_HLP_IB_S)
{
Object->ElementIDIB_HLP_IB_S=ElementIDIB_HLP_IB_S;
}
//---------------------------------------------------------------
TFIBSmallIntField * THLP_DMSprInfBlockSostavImpl::get_ElementTYPE_HLP_IB_S(void)
{
return Object->ElementTYPE_HLP_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_ElementTYPE_HLP_IB_S(TFIBSmallIntField * ElementTYPE_HLP_IB_S)
{
Object->ElementTYPE_HLP_IB_S=ElementTYPE_HLP_IB_S;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockSostavImpl::get_ElementTEXT_HLP_IB_S(void)
{
return Object->ElementTEXT_HLP_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_ElementTEXT_HLP_IB_S(TFIBWideStringField * ElementTEXT_HLP_IB_S)
{
Object->ElementTEXT_HLP_IB_S=ElementTEXT_HLP_IB_S;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprInfBlockSostavImpl::get_ElementIDIMG_HLP_IB_S(void)
{
return Object->ElementIDIMG_HLP_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_ElementIDIMG_HLP_IB_S(TFIBLargeIntField * ElementIDIMG_HLP_IB_S)
{
Object->ElementIDIMG_HLP_IB_S=ElementIDIMG_HLP_IB_S;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprInfBlockSostavImpl::get_ElementINDEX_HLP_IB_S(void)
{
return Object->ElementINDEX_HLP_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_ElementINDEX_HLP_IB_S(TFIBIntegerField * ElementINDEX_HLP_IB_S)
{
Object->ElementINDEX_HLP_IB_S=ElementINDEX_HLP_IB_S;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprInfBlockSostavImpl::get_ElementH_ALIGN_HLP_IB_S(void)
{
return Object->ElementH_ALIGN_HLP_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_ElementH_ALIGN_HLP_IB_S(TFIBIntegerField * ElementH_ALIGN_HLP_IB_S)
{
Object->ElementH_ALIGN_HLP_IB_S=ElementH_ALIGN_HLP_IB_S;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprInfBlockSostavImpl::get_ElementV_ALIGN_HLP_IB_S(void)
{
return Object->ElementV_ALIGN_HLP_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_ElementV_ALIGN_HLP_IB_S(TFIBIntegerField * ElementV_ALIGN_HLP_IB_S)
{
Object->ElementV_ALIGN_HLP_IB_S=ElementV_ALIGN_HLP_IB_S;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprInfBlockSostavImpl::get_ElementTYPE_TEXT_HLP_IB_S(void)
{
return Object->ElementTYPE_TEXT_HLP_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_ElementTYPE_TEXT_HLP_IB_S(TFIBIntegerField * ElementTYPE_TEXT_HLP_IB_S)
{
Object->ElementTYPE_TEXT_HLP_IB_S=ElementTYPE_TEXT_HLP_IB_S;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprInfBlockSostavImpl::get_ElementFONT_SIZE_HLP_IB_S(void)
{
return Object->ElementFONT_SIZE_HLP_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_ElementFONT_SIZE_HLP_IB_S(TFIBIntegerField * ElementFONT_SIZE_HLP_IB_S)
{
Object->ElementFONT_SIZE_HLP_IB_S=ElementFONT_SIZE_HLP_IB_S;
}
//---------------------------------------------------------------
__int64 THLP_DMSprInfBlockSostavImpl::get_IdIB(void)
{
return Object->IdIB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_IdIB(__int64 IdIB)
{
Object->IdIB=IdIB;
}
//---------------------------------------------------------------
__int64 THLP_DMSprInfBlockSostavImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockSostavImpl::OpenTable(__int64 id_ib)
{
return Object->OpenTable(id_ib);
}
//---------------------------------------------------------------
bool THLP_DMSprInfBlockSostavImpl::SaveIsmen(void)
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
bool THLP_DMSprInfBlockSostavImpl::CancelIsmen(void)
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
bool THLP_DMSprInfBlockSostavImpl::TableAppend(__int64 id_ib)
{
return Object->TableAppend(id_ib);
}
//---------------------------------------------------------------
bool THLP_DMSprInfBlockSostavImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
bool THLP_DMSprInfBlockSostavImpl::NewElement(__int64 id_ib)
{
return Object->NewElement(id_ib);
}
//---------------------------------------------------------------
int THLP_DMSprInfBlockSostavImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool THLP_DMSprInfBlockSostavImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool THLP_DMSprInfBlockSostavImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
