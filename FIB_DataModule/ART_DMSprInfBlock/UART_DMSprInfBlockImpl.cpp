#include "vcl.h"
#pragma hdrstop


#include "UART_DMSprInfBlockImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TART_DMSprInfBlockImpl::TART_DMSprInfBlockImpl()           
{                                            
Object=new TART_DMSprInfBlock(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TART_DMSprInfBlockImpl::~TART_DMSprInfBlockImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TART_DMSprInfBlockImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IART_DMSprInfBlock)                        
   {                                                                     
   *ppv=static_cast<IART_DMSprInfBlock*> (this);                                
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
int TART_DMSprInfBlockImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TART_DMSprInfBlockImpl::kanRelease(void)                                  
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
int  TART_DMSprInfBlockImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TART_DMSprInfBlockImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TART_DMSprInfBlockImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TART_DMSprInfBlockImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TART_DMSprInfBlockImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IART_DMSprInfBlock
TDataSource * TART_DMSprInfBlockImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TART_DMSprInfBlockImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TART_DMSprInfBlockImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TART_DMSprInfBlockImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TART_DMSprInfBlockImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TART_DMSprInfBlockImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TART_DMSprInfBlockImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprInfBlockImpl::get_TableID_ART_IB(void)
{
return Object->TableID_ART_IB;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_TableID_ART_IB(TFIBLargeIntField * TableID_ART_IB)
{
Object->TableID_ART_IB=TableID_ART_IB;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprInfBlockImpl::get_TableIDBASE_ART_IB(void)
{
return Object->TableIDBASE_ART_IB;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_TableIDBASE_ART_IB(TFIBLargeIntField * TableIDBASE_ART_IB)
{
Object->TableIDBASE_ART_IB=TableIDBASE_ART_IB;
}
//---------------------------------------------------------------
TFIBDateTimeField * TART_DMSprInfBlockImpl::get_TablePOS_ISM_ART_IB(void)
{
return Object->TablePOS_ISM_ART_IB;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_TablePOS_ISM_ART_IB(TFIBDateTimeField * TablePOS_ISM_ART_IB)
{
Object->TablePOS_ISM_ART_IB=TablePOS_ISM_ART_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprInfBlockImpl::get_TableGUID_ART_IB(void)
{
return Object->TableGUID_ART_IB;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_TableGUID_ART_IB(TFIBWideStringField * TableGUID_ART_IB)
{
Object->TableGUID_ART_IB=TableGUID_ART_IB;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprInfBlockImpl::get_TableIDGRP_ART_IB(void)
{
return Object->TableIDGRP_ART_IB;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_TableIDGRP_ART_IB(TFIBLargeIntField * TableIDGRP_ART_IB)
{
Object->TableIDGRP_ART_IB=TableIDGRP_ART_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprInfBlockImpl::get_TableGUIDGRP_ART_IB(void)
{
return Object->TableGUIDGRP_ART_IB;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_TableGUIDGRP_ART_IB(TFIBWideStringField * TableGUIDGRP_ART_IB)
{
Object->TableGUIDGRP_ART_IB=TableGUIDGRP_ART_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprInfBlockImpl::get_TableNAME_ART_IB(void)
{
return Object->TableNAME_ART_IB;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_TableNAME_ART_IB(TFIBWideStringField * TableNAME_ART_IB)
{
Object->TableNAME_ART_IB=TableNAME_ART_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprInfBlockImpl::get_TableKEYWORDS_ART_IB(void)
{
return Object->TableKEYWORDS_ART_IB;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_TableKEYWORDS_ART_IB(TFIBWideStringField * TableKEYWORDS_ART_IB)
{
Object->TableKEYWORDS_ART_IB=TableKEYWORDS_ART_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprInfBlockImpl::get_TableTITLE_ART_IB(void)
{
return Object->TableTITLE_ART_IB;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_TableTITLE_ART_IB(TFIBWideStringField * TableTITLE_ART_IB)
{
Object->TableTITLE_ART_IB=TableTITLE_ART_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprInfBlockImpl::get_TableDESCR_ART_IB(void)
{
return Object->TableDESCR_ART_IB;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_TableDESCR_ART_IB(TFIBWideStringField * TableDESCR_ART_IB)
{
Object->TableDESCR_ART_IB=TableDESCR_ART_IB;
}
//---------------------------------------------------------------
TFIBIntegerField * TART_DMSprInfBlockImpl::get_TableINDEX_ART_IB(void)
{
return Object->TableINDEX_ART_IB;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_TableINDEX_ART_IB(TFIBIntegerField * TableINDEX_ART_IB)
{
Object->TableINDEX_ART_IB=TableINDEX_ART_IB;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprInfBlockImpl::get_ElementID_ART_IB(void)
{
return Object->ElementID_ART_IB;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_ElementID_ART_IB(TFIBLargeIntField * ElementID_ART_IB)
{
Object->ElementID_ART_IB=ElementID_ART_IB;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprInfBlockImpl::get_ElementIDBASE_ART_IB(void)
{
return Object->ElementIDBASE_ART_IB;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_ElementIDBASE_ART_IB(TFIBLargeIntField * ElementIDBASE_ART_IB)
{
Object->ElementIDBASE_ART_IB=ElementIDBASE_ART_IB;
}
//---------------------------------------------------------------
TFIBDateTimeField * TART_DMSprInfBlockImpl::get_ElementPOS_ISM_ART_IB(void)
{
return Object->ElementPOS_ISM_ART_IB;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_ElementPOS_ISM_ART_IB(TFIBDateTimeField * ElementPOS_ISM_ART_IB)
{
Object->ElementPOS_ISM_ART_IB=ElementPOS_ISM_ART_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprInfBlockImpl::get_ElementGUID_ART_IB(void)
{
return Object->ElementGUID_ART_IB;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_ElementGUID_ART_IB(TFIBWideStringField * ElementGUID_ART_IB)
{
Object->ElementGUID_ART_IB=ElementGUID_ART_IB;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprInfBlockImpl::get_ElementIDGRP_ART_IB(void)
{
return Object->ElementIDGRP_ART_IB;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_ElementIDGRP_ART_IB(TFIBLargeIntField * ElementIDGRP_ART_IB)
{
Object->ElementIDGRP_ART_IB=ElementIDGRP_ART_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprInfBlockImpl::get_ElementGUIDGRP_ART_IB(void)
{
return Object->ElementGUIDGRP_ART_IB;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_ElementGUIDGRP_ART_IB(TFIBWideStringField * ElementGUIDGRP_ART_IB)
{
Object->ElementGUIDGRP_ART_IB=ElementGUIDGRP_ART_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprInfBlockImpl::get_ElementNAME_ART_IB(void)
{
return Object->ElementNAME_ART_IB;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_ElementNAME_ART_IB(TFIBWideStringField * ElementNAME_ART_IB)
{
Object->ElementNAME_ART_IB=ElementNAME_ART_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprInfBlockImpl::get_ElementKEYWORDS_ART_IB(void)
{
return Object->ElementKEYWORDS_ART_IB;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_ElementKEYWORDS_ART_IB(TFIBWideStringField * ElementKEYWORDS_ART_IB)
{
Object->ElementKEYWORDS_ART_IB=ElementKEYWORDS_ART_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprInfBlockImpl::get_ElementTITLE_ART_IB(void)
{
return Object->ElementTITLE_ART_IB;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_ElementTITLE_ART_IB(TFIBWideStringField * ElementTITLE_ART_IB)
{
Object->ElementTITLE_ART_IB=ElementTITLE_ART_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprInfBlockImpl::get_ElementDESCR_ART_IB(void)
{
return Object->ElementDESCR_ART_IB;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_ElementDESCR_ART_IB(TFIBWideStringField * ElementDESCR_ART_IB)
{
Object->ElementDESCR_ART_IB=ElementDESCR_ART_IB;
}
//---------------------------------------------------------------
TFIBIntegerField * TART_DMSprInfBlockImpl::get_ElementINDEX_ART_IB(void)
{
return Object->ElementINDEX_ART_IB;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_ElementINDEX_ART_IB(TFIBIntegerField * ElementINDEX_ART_IB)
{
Object->ElementINDEX_ART_IB=ElementINDEX_ART_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprInfBlockImpl::get_ElementWEB_KEYWORDS_ART_IB(void)
{
return Object->ElementWEB_KEYWORDS_ART_IB;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_ElementWEB_KEYWORDS_ART_IB(TFIBWideStringField * ElementWEB_KEYWORDS_ART_IB)
{
Object->ElementWEB_KEYWORDS_ART_IB=ElementWEB_KEYWORDS_ART_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprInfBlockImpl::get_ElementWEB_TITLE_ART_IB(void)
{
return Object->ElementWEB_TITLE_ART_IB;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_ElementWEB_TITLE_ART_IB(TFIBWideStringField * ElementWEB_TITLE_ART_IB)
{
Object->ElementWEB_TITLE_ART_IB=ElementWEB_TITLE_ART_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprInfBlockImpl::get_ElementWEB_DESCR_ART_IB(void)
{
return Object->ElementWEB_DESCR_ART_IB;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_ElementWEB_DESCR_ART_IB(TFIBWideStringField * ElementWEB_DESCR_ART_IB)
{
Object->ElementWEB_DESCR_ART_IB=ElementWEB_DESCR_ART_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprInfBlockImpl::get_TableWEB_KEYWORDS_ART_IB(void)
{
return Object->TableWEB_KEYWORDS_ART_IB;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_TableWEB_KEYWORDS_ART_IB(TFIBWideStringField * TableWEB_KEYWORDS_ART_IB)
{
Object->TableWEB_KEYWORDS_ART_IB=TableWEB_KEYWORDS_ART_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprInfBlockImpl::get_TableWEB_TITLE_ART_IB(void)
{
return Object->TableWEB_TITLE_ART_IB;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_TableWEB_TITLE_ART_IB(TFIBWideStringField * TableWEB_TITLE_ART_IB)
{
Object->TableWEB_TITLE_ART_IB=TableWEB_TITLE_ART_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprInfBlockImpl::get_TableWEB_DESCR_ART_IB(void)
{
return Object->TableWEB_DESCR_ART_IB;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_TableWEB_DESCR_ART_IB(TFIBWideStringField * TableWEB_DESCR_ART_IB)
{
Object->TableWEB_DESCR_ART_IB=TableWEB_DESCR_ART_IB;
}
//---------------------------------------------------------------
TFIBSmallIntField * TART_DMSprInfBlockImpl::get_ElementFL_ADD_SITEMAP_ART_IB(void)
{
return Object->ElementFL_ADD_SITEMAP_ART_IB;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_ElementFL_ADD_SITEMAP_ART_IB(TFIBSmallIntField * ElementFL_ADD_SITEMAP_ART_IB)
{
Object->ElementFL_ADD_SITEMAP_ART_IB=ElementFL_ADD_SITEMAP_ART_IB;
}
//---------------------------------------------------------------
TFIBSmallIntField * TART_DMSprInfBlockImpl::get_TableFL_ADD_SITEMAP_ART_IB(void)
{
return Object->TableFL_ADD_SITEMAP_ART_IB;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_TableFL_ADD_SITEMAP_ART_IB(TFIBSmallIntField * TableFL_ADD_SITEMAP_ART_IB)
{
Object->TableFL_ADD_SITEMAP_ART_IB=TableFL_ADD_SITEMAP_ART_IB;
}
//---------------------------------------------------------------
__int64 TART_DMSprInfBlockImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TART_DMSprInfBlockImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
__int64 TART_DMSprInfBlockImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::OpenTable(__int64 id_grp, bool all)
{
return Object->OpenTable(id_grp, all);
}
//---------------------------------------------------------------
UnicodeString TART_DMSprInfBlockImpl::GetTextQuery(__int64 id_grp, bool all)
{
return Object->GetTextQuery(id_grp,all);
}
//---------------------------------------------------------------
int TART_DMSprInfBlockImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool TART_DMSprInfBlockImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TART_DMSprInfBlockImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TART_DMSprInfBlockImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement( id);
}
//---------------------------------------------------------------
void TART_DMSprInfBlockImpl::ChancheGrp(__int64 id_new_grp,__int64 id_element)
{
return Object->ChancheGrp(id_new_grp,id_element);
}
//---------------------------------------------------------------
__int64 TART_DMSprInfBlockImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName( name);
}
//---------------------------------------------------------------
__int64 TART_DMSprInfBlockImpl::GetIdGrp(__int64 id_el)
{
return Object->GetIdGrp( id_el);
}
//---------------------------------------------------------------
