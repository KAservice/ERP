#include "vcl.h"
#pragma hdrstop


#include "UHLP_DMSprInfBlockImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THLP_DMSprInfBlockImpl::THLP_DMSprInfBlockImpl()           
{                                            
Object=new THLP_DMSprInfBlock(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THLP_DMSprInfBlockImpl::~THLP_DMSprInfBlockImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THLP_DMSprInfBlockImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHLP_DMSprInfBlock)                        
   {                                                                     
   *ppv=static_cast<IHLP_DMSprInfBlock*> (this);                                
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
int THLP_DMSprInfBlockImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THLP_DMSprInfBlockImpl::kanRelease(void)                                  
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
int  THLP_DMSprInfBlockImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THLP_DMSprInfBlockImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THLP_DMSprInfBlockImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_THLP_DMSprInfBlockImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THLP_DMSprInfBlockImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IHLP_DMSprInfBlock
TDataSource * THLP_DMSprInfBlockImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * THLP_DMSprInfBlockImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * THLP_DMSprInfBlockImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * THLP_DMSprInfBlockImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * THLP_DMSprInfBlockImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * THLP_DMSprInfBlockImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * THLP_DMSprInfBlockImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprInfBlockImpl::get_TableID_HLP_IB(void)
{
return Object->TableID_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_TableID_HLP_IB(TFIBLargeIntField * TableID_HLP_IB)
{
Object->TableID_HLP_IB=TableID_HLP_IB;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprInfBlockImpl::get_TableIDBASE_HLP_IB(void)
{
return Object->TableIDBASE_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_TableIDBASE_HLP_IB(TFIBLargeIntField * TableIDBASE_HLP_IB)
{
Object->TableIDBASE_HLP_IB=TableIDBASE_HLP_IB;
}
//---------------------------------------------------------------
TFIBDateTimeField * THLP_DMSprInfBlockImpl::get_TablePOS_ISM_HLP_IB(void)
{
return Object->TablePOS_ISM_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_TablePOS_ISM_HLP_IB(TFIBDateTimeField * TablePOS_ISM_HLP_IB)
{
Object->TablePOS_ISM_HLP_IB=TablePOS_ISM_HLP_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockImpl::get_TableGUID_HLP_IB(void)
{
return Object->TableGUID_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_TableGUID_HLP_IB(TFIBWideStringField * TableGUID_HLP_IB)
{
Object->TableGUID_HLP_IB=TableGUID_HLP_IB;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprInfBlockImpl::get_TableIDGRP_HLP_IB(void)
{
return Object->TableIDGRP_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_TableIDGRP_HLP_IB(TFIBLargeIntField * TableIDGRP_HLP_IB)
{
Object->TableIDGRP_HLP_IB=TableIDGRP_HLP_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockImpl::get_TableGUIDGRP_HLP_IB(void)
{
return Object->TableGUIDGRP_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_TableGUIDGRP_HLP_IB(TFIBWideStringField * TableGUIDGRP_HLP_IB)
{
Object->TableGUIDGRP_HLP_IB=TableGUIDGRP_HLP_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockImpl::get_TableNAME_HLP_IB(void)
{
return Object->TableNAME_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_TableNAME_HLP_IB(TFIBWideStringField * TableNAME_HLP_IB)
{
Object->TableNAME_HLP_IB=TableNAME_HLP_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockImpl::get_TableKEYWORDS_HLP_IB(void)
{
return Object->TableKEYWORDS_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_TableKEYWORDS_HLP_IB(TFIBWideStringField * TableKEYWORDS_HLP_IB)
{
Object->TableKEYWORDS_HLP_IB=TableKEYWORDS_HLP_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockImpl::get_TableTITLE_HLP_IB(void)
{
return Object->TableTITLE_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_TableTITLE_HLP_IB(TFIBWideStringField * TableTITLE_HLP_IB)
{
Object->TableTITLE_HLP_IB=TableTITLE_HLP_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockImpl::get_TableDESCR_HLP_IB(void)
{
return Object->TableDESCR_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_TableDESCR_HLP_IB(TFIBWideStringField * TableDESCR_HLP_IB)
{
Object->TableDESCR_HLP_IB=TableDESCR_HLP_IB;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprInfBlockImpl::get_TableINDEX_HLP_IB(void)
{
return Object->TableINDEX_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_TableINDEX_HLP_IB(TFIBIntegerField * TableINDEX_HLP_IB)
{
Object->TableINDEX_HLP_IB=TableINDEX_HLP_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockImpl::get_TableWEB_KEYWORDS_HLP_IB(void)
{
return Object->TableWEB_KEYWORDS_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_TableWEB_KEYWORDS_HLP_IB(TFIBWideStringField * TableWEB_KEYWORDS_HLP_IB)
{
Object->TableWEB_KEYWORDS_HLP_IB=TableWEB_KEYWORDS_HLP_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockImpl::get_TableWEB_TITLE_HLP_IB(void)
{
return Object->TableWEB_TITLE_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_TableWEB_TITLE_HLP_IB(TFIBWideStringField * TableWEB_TITLE_HLP_IB)
{
Object->TableWEB_TITLE_HLP_IB=TableWEB_TITLE_HLP_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockImpl::get_TableWEB_DESCR_HLP_IB(void)
{
return Object->TableWEB_DESCR_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_TableWEB_DESCR_HLP_IB(TFIBWideStringField * TableWEB_DESCR_HLP_IB)
{
Object->TableWEB_DESCR_HLP_IB=TableWEB_DESCR_HLP_IB;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprInfBlockImpl::get_ElementID_HLP_IB(void)
{
return Object->ElementID_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_ElementID_HLP_IB(TFIBLargeIntField * ElementID_HLP_IB)
{
Object->ElementID_HLP_IB=ElementID_HLP_IB;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprInfBlockImpl::get_ElementIDBASE_HLP_IB(void)
{
return Object->ElementIDBASE_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_ElementIDBASE_HLP_IB(TFIBLargeIntField * ElementIDBASE_HLP_IB)
{
Object->ElementIDBASE_HLP_IB=ElementIDBASE_HLP_IB;
}
//---------------------------------------------------------------
TFIBDateTimeField * THLP_DMSprInfBlockImpl::get_ElementPOS_ISM_HLP_IB(void)
{
return Object->ElementPOS_ISM_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_ElementPOS_ISM_HLP_IB(TFIBDateTimeField * ElementPOS_ISM_HLP_IB)
{
Object->ElementPOS_ISM_HLP_IB=ElementPOS_ISM_HLP_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockImpl::get_ElementGUID_HLP_IB(void)
{
return Object->ElementGUID_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_ElementGUID_HLP_IB(TFIBWideStringField * ElementGUID_HLP_IB)
{
Object->ElementGUID_HLP_IB=ElementGUID_HLP_IB;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprInfBlockImpl::get_ElementIDGRP_HLP_IB(void)
{
return Object->ElementIDGRP_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_ElementIDGRP_HLP_IB(TFIBLargeIntField * ElementIDGRP_HLP_IB)
{
Object->ElementIDGRP_HLP_IB=ElementIDGRP_HLP_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockImpl::get_ElementGUIDGRP_HLP_IB(void)
{
return Object->ElementGUIDGRP_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_ElementGUIDGRP_HLP_IB(TFIBWideStringField * ElementGUIDGRP_HLP_IB)
{
Object->ElementGUIDGRP_HLP_IB=ElementGUIDGRP_HLP_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockImpl::get_ElementNAME_HLP_IB(void)
{
return Object->ElementNAME_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_ElementNAME_HLP_IB(TFIBWideStringField * ElementNAME_HLP_IB)
{
Object->ElementNAME_HLP_IB=ElementNAME_HLP_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockImpl::get_ElementKEYWORDS_HLP_IB(void)
{
return Object->ElementKEYWORDS_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_ElementKEYWORDS_HLP_IB(TFIBWideStringField * ElementKEYWORDS_HLP_IB)
{
Object->ElementKEYWORDS_HLP_IB=ElementKEYWORDS_HLP_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockImpl::get_ElementTITLE_HLP_IB(void)
{
return Object->ElementTITLE_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_ElementTITLE_HLP_IB(TFIBWideStringField * ElementTITLE_HLP_IB)
{
Object->ElementTITLE_HLP_IB=ElementTITLE_HLP_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockImpl::get_ElementDESCR_HLP_IB(void)
{
return Object->ElementDESCR_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_ElementDESCR_HLP_IB(TFIBWideStringField * ElementDESCR_HLP_IB)
{
Object->ElementDESCR_HLP_IB=ElementDESCR_HLP_IB;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprInfBlockImpl::get_ElementINDEX_HLP_IB(void)
{
return Object->ElementINDEX_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_ElementINDEX_HLP_IB(TFIBIntegerField * ElementINDEX_HLP_IB)
{
Object->ElementINDEX_HLP_IB=ElementINDEX_HLP_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockImpl::get_ElementWEB_KEYWORDS_HLP_IB(void)
{
return Object->ElementWEB_KEYWORDS_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_ElementWEB_KEYWORDS_HLP_IB(TFIBWideStringField * ElementWEB_KEYWORDS_HLP_IB)
{
Object->ElementWEB_KEYWORDS_HLP_IB=ElementWEB_KEYWORDS_HLP_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockImpl::get_ElementWEB_TITLE_HLP_IB(void)
{
return Object->ElementWEB_TITLE_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_ElementWEB_TITLE_HLP_IB(TFIBWideStringField * ElementWEB_TITLE_HLP_IB)
{
Object->ElementWEB_TITLE_HLP_IB=ElementWEB_TITLE_HLP_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockImpl::get_ElementWEB_DESCR_HLP_IB(void)
{
return Object->ElementWEB_DESCR_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_ElementWEB_DESCR_HLP_IB(TFIBWideStringField * ElementWEB_DESCR_HLP_IB)
{
Object->ElementWEB_DESCR_HLP_IB=ElementWEB_DESCR_HLP_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockImpl::get_TableGUID_PROG_MODULE_HLP_IB(void)
{
return Object->TableGUID_PROG_MODULE_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_TableGUID_PROG_MODULE_HLP_IB(TFIBWideStringField * TableGUID_PROG_MODULE_HLP_IB)
{
Object->TableGUID_PROG_MODULE_HLP_IB=TableGUID_PROG_MODULE_HLP_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockImpl::get_TableNAME_PROGRAM_MODULE(void)
{
return Object->TableNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_TableNAME_PROGRAM_MODULE(TFIBWideStringField * TableNAME_PROGRAM_MODULE)
{
Object->TableNAME_PROGRAM_MODULE=TableNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockImpl::get_TableMODULE_PROGRAM_MODULE(void)
{
return Object->TableMODULE_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_TableMODULE_PROGRAM_MODULE(TFIBWideStringField * TableMODULE_PROGRAM_MODULE)
{
Object->TableMODULE_PROGRAM_MODULE=TableMODULE_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockImpl::get_TableDESCR_PROGRAM_MODULE(void)
{
return Object->TableDESCR_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_TableDESCR_PROGRAM_MODULE(TFIBWideStringField * TableDESCR_PROGRAM_MODULE)
{
Object->TableDESCR_PROGRAM_MODULE=TableDESCR_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockImpl::get_TablePATCH_PROGRAM_MODULE(void)
{
return Object->TablePATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_TablePATCH_PROGRAM_MODULE(TFIBWideStringField * TablePATCH_PROGRAM_MODULE)
{
Object->TablePATCH_PROGRAM_MODULE=TablePATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockImpl::get_ElementGUID_PROG_MODULE_HLP_IB(void)
{
return Object->ElementGUID_PROG_MODULE_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_ElementGUID_PROG_MODULE_HLP_IB(TFIBWideStringField * ElementGUID_PROG_MODULE_HLP_IB)
{
Object->ElementGUID_PROG_MODULE_HLP_IB=ElementGUID_PROG_MODULE_HLP_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockImpl::get_ElementNAME_PROGRAM_MODULE(void)
{
return Object->ElementNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_ElementNAME_PROGRAM_MODULE(TFIBWideStringField * ElementNAME_PROGRAM_MODULE)
{
Object->ElementNAME_PROGRAM_MODULE=ElementNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockImpl::get_ElementMODULE_PROGRAM_MODULE(void)
{
return Object->ElementMODULE_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_ElementMODULE_PROGRAM_MODULE(TFIBWideStringField * ElementMODULE_PROGRAM_MODULE)
{
Object->ElementMODULE_PROGRAM_MODULE=ElementMODULE_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockImpl::get_ElementDESCR_PROGRAM_MODULE(void)
{
return Object->ElementDESCR_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_ElementDESCR_PROGRAM_MODULE(TFIBWideStringField * ElementDESCR_PROGRAM_MODULE)
{
Object->ElementDESCR_PROGRAM_MODULE=ElementDESCR_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockImpl::get_ElementPATCH_PROGRAM_MODULE(void)
{
return Object->ElementPATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_ElementPATCH_PROGRAM_MODULE(TFIBWideStringField * ElementPATCH_PROGRAM_MODULE)
{
Object->ElementPATCH_PROGRAM_MODULE=ElementPATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBSmallIntField * THLP_DMSprInfBlockImpl::get_TableFL_ADD_SITEMAP_HLP_IB(void)
{
return Object->TableFL_ADD_SITEMAP_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_TableFL_ADD_SITEMAP_HLP_IB(TFIBSmallIntField * TableFL_ADD_SITEMAP_HLP_IB)
{
Object->TableFL_ADD_SITEMAP_HLP_IB=TableFL_ADD_SITEMAP_HLP_IB;
}
//---------------------------------------------------------------
TFIBSmallIntField * THLP_DMSprInfBlockImpl::get_ElementFL_ADD_SITEMAP_HLP_IB(void)
{
return Object->ElementFL_ADD_SITEMAP_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_ElementFL_ADD_SITEMAP_HLP_IB(TFIBSmallIntField * ElementFL_ADD_SITEMAP_HLP_IB)
{
Object->ElementFL_ADD_SITEMAP_HLP_IB=ElementFL_ADD_SITEMAP_HLP_IB;
}
//---------------------------------------------------------------
__int64 THLP_DMSprInfBlockImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool THLP_DMSprInfBlockImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
__int64 THLP_DMSprInfBlockImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::OpenTable(__int64 id_grp, bool all)
{
return Object->OpenTable(id_grp,all);
}
//---------------------------------------------------------------
UnicodeString THLP_DMSprInfBlockImpl::GetTextQuery(__int64 id_grp, bool all)
{
return Object->GetTextQuery(id_grp,all);
}
//---------------------------------------------------------------
int THLP_DMSprInfBlockImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool THLP_DMSprInfBlockImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool THLP_DMSprInfBlockImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool THLP_DMSprInfBlockImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockImpl::ChancheGrp(__int64 id_new_grp,__int64 id_element)
{
return Object->ChancheGrp(id_new_grp,id_element);
}
//---------------------------------------------------------------
__int64 THLP_DMSprInfBlockImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
__int64 THLP_DMSprInfBlockImpl::GetIdGrp(__int64 id_el)
{
return Object->GetIdGrp( id_el);
}
//---------------------------------------------------------------
__int64 THLP_DMSprInfBlockImpl::GetIdPoGuidProgModule(UnicodeString guid_str)
{
return Object->GetIdPoGuidProgModule(guid_str);
}
//---------------------------------------------------------------
