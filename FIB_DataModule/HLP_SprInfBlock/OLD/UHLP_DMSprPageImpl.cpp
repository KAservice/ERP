#include "vcl.h"
#pragma hdrstop


#include "UHLP_DMSprPageImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THLP_DMSprPageImpl::THLP_DMSprPageImpl()           
{                                            
Object=new THLP_DMSprPage(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THLP_DMSprPageImpl::~THLP_DMSprPageImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THLP_DMSprPageImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THLP_DMSprPageImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHLP_DMSprPage)                        
   {                                                                     
   *ppv=static_cast<IHLP_DMSprPage*> (this);                                
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
int THLP_DMSprPageImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THLP_DMSprPageImpl::kanRelease(void)                                  
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
int  THLP_DMSprPageImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THLP_DMSprPageImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THLP_DMSprPageImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_THLP_DMSprPageImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THLP_DMSprPageImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IHLP_DMSprPage
TDataSource * THLP_DMSprPageImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * THLP_DMSprPageImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * THLP_DMSprPageImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * THLP_DMSprPageImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * THLP_DMSprPageImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * THLP_DMSprPageImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * THLP_DMSprPageImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * THLP_DMSprPageImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprPageImpl::get_TableID_HLP_PAGE(void)
{
return Object->TableID_HLP_PAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_TableID_HLP_PAGE(TFIBLargeIntField * TableID_HLP_PAGE)
{
Object->TableID_HLP_PAGE=TableID_HLP_PAGE;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprPageImpl::get_TableIDBASE_HLP_PAGE(void)
{
return Object->TableIDBASE_HLP_PAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_TableIDBASE_HLP_PAGE(TFIBLargeIntField * TableIDBASE_HLP_PAGE)
{
Object->TableIDBASE_HLP_PAGE=TableIDBASE_HLP_PAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageImpl::get_TableGID_HLP_PAGE(void)
{
return Object->TableGID_HLP_PAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_TableGID_HLP_PAGE(TFIBWideStringField * TableGID_HLP_PAGE)
{
Object->TableGID_HLP_PAGE=TableGID_HLP_PAGE;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprPageImpl::get_TableIDGRP_HLP_PAGE(void)
{
return Object->TableIDGRP_HLP_PAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_TableIDGRP_HLP_PAGE(TFIBLargeIntField * TableIDGRP_HLP_PAGE)
{
Object->TableIDGRP_HLP_PAGE=TableIDGRP_HLP_PAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageImpl::get_TableNAME_HLP_PAGE(void)
{
return Object->TableNAME_HLP_PAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_TableNAME_HLP_PAGE(TFIBWideStringField * TableNAME_HLP_PAGE)
{
Object->TableNAME_HLP_PAGE=TableNAME_HLP_PAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageImpl::get_TableKEYWORDS_HLP_PAGE(void)
{
return Object->TableKEYWORDS_HLP_PAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_TableKEYWORDS_HLP_PAGE(TFIBWideStringField * TableKEYWORDS_HLP_PAGE)
{
Object->TableKEYWORDS_HLP_PAGE=TableKEYWORDS_HLP_PAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageImpl::get_TableTITLE_HLP_PAGE(void)
{
return Object->TableTITLE_HLP_PAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_TableTITLE_HLP_PAGE(TFIBWideStringField * TableTITLE_HLP_PAGE)
{
Object->TableTITLE_HLP_PAGE=TableTITLE_HLP_PAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageImpl::get_TableDESCR_HLP_PAGE(void)
{
return Object->TableDESCR_HLP_PAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_TableDESCR_HLP_PAGE(TFIBWideStringField * TableDESCR_HLP_PAGE)
{
Object->TableDESCR_HLP_PAGE=TableDESCR_HLP_PAGE;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprPageImpl::get_TableINDEX_HLP_PAGE(void)
{
return Object->TableINDEX_HLP_PAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_TableINDEX_HLP_PAGE(TFIBIntegerField * TableINDEX_HLP_PAGE)
{
Object->TableINDEX_HLP_PAGE=TableINDEX_HLP_PAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageImpl::get_TableWEBKEYWORDS_HLP_PAGE(void)
{
return Object->TableWEBKEYWORDS_HLP_PAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_TableWEBKEYWORDS_HLP_PAGE(TFIBWideStringField * TableWEBKEYWORDS_HLP_PAGE)
{
Object->TableWEBKEYWORDS_HLP_PAGE=TableWEBKEYWORDS_HLP_PAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageImpl::get_TableWEBTITLE_HLP_PAGE(void)
{
return Object->TableWEBTITLE_HLP_PAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_TableWEBTITLE_HLP_PAGE(TFIBWideStringField * TableWEBTITLE_HLP_PAGE)
{
Object->TableWEBTITLE_HLP_PAGE=TableWEBTITLE_HLP_PAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageImpl::get_TableWEBDESCR_HLP_PAGE(void)
{
return Object->TableWEBDESCR_HLP_PAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_TableWEBDESCR_HLP_PAGE(TFIBWideStringField * TableWEBDESCR_HLP_PAGE)
{
Object->TableWEBDESCR_HLP_PAGE=TableWEBDESCR_HLP_PAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageImpl::get_TableGUIDGRP_HLP_PAGE(void)
{
return Object->TableGUIDGRP_HLP_PAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_TableGUIDGRP_HLP_PAGE(TFIBWideStringField * TableGUIDGRP_HLP_PAGE)
{
Object->TableGUIDGRP_HLP_PAGE=TableGUIDGRP_HLP_PAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageImpl::get_TableSTRCODE_HLP_PAGE(void)
{
return Object->TableSTRCODE_HLP_PAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_TableSTRCODE_HLP_PAGE(TFIBWideStringField * TableSTRCODE_HLP_PAGE)
{
Object->TableSTRCODE_HLP_PAGE=TableSTRCODE_HLP_PAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageImpl::get_TableGUID_HLP_PAGE(void)
{
return Object->TableGUID_HLP_PAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_TableGUID_HLP_PAGE(TFIBWideStringField * TableGUID_HLP_PAGE)
{
Object->TableGUID_HLP_PAGE=TableGUID_HLP_PAGE;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprPageImpl::get_ElementID_HLP_PAGE(void)
{
return Object->ElementID_HLP_PAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_ElementID_HLP_PAGE(TFIBLargeIntField * ElementID_HLP_PAGE)
{
Object->ElementID_HLP_PAGE=ElementID_HLP_PAGE;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprPageImpl::get_ElementIDBASE_HLP_PAGE(void)
{
return Object->ElementIDBASE_HLP_PAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_ElementIDBASE_HLP_PAGE(TFIBLargeIntField * ElementIDBASE_HLP_PAGE)
{
Object->ElementIDBASE_HLP_PAGE=ElementIDBASE_HLP_PAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageImpl::get_ElementGID_HLP_PAGE(void)
{
return Object->ElementGID_HLP_PAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_ElementGID_HLP_PAGE(TFIBWideStringField * ElementGID_HLP_PAGE)
{
Object->ElementGID_HLP_PAGE=ElementGID_HLP_PAGE;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprPageImpl::get_ElementIDGRP_HLP_PAGE(void)
{
return Object->ElementIDGRP_HLP_PAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_ElementIDGRP_HLP_PAGE(TFIBLargeIntField * ElementIDGRP_HLP_PAGE)
{
Object->ElementIDGRP_HLP_PAGE=ElementIDGRP_HLP_PAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageImpl::get_ElementNAME_HLP_PAGE(void)
{
return Object->ElementNAME_HLP_PAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_ElementNAME_HLP_PAGE(TFIBWideStringField * ElementNAME_HLP_PAGE)
{
Object->ElementNAME_HLP_PAGE=ElementNAME_HLP_PAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageImpl::get_ElementKEYWORDS_HLP_PAGE(void)
{
return Object->ElementKEYWORDS_HLP_PAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_ElementKEYWORDS_HLP_PAGE(TFIBWideStringField * ElementKEYWORDS_HLP_PAGE)
{
Object->ElementKEYWORDS_HLP_PAGE=ElementKEYWORDS_HLP_PAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageImpl::get_ElementTITLE_HLP_PAGE(void)
{
return Object->ElementTITLE_HLP_PAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_ElementTITLE_HLP_PAGE(TFIBWideStringField * ElementTITLE_HLP_PAGE)
{
Object->ElementTITLE_HLP_PAGE=ElementTITLE_HLP_PAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageImpl::get_ElementDESCR_HLP_PAGE(void)
{
return Object->ElementDESCR_HLP_PAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_ElementDESCR_HLP_PAGE(TFIBWideStringField * ElementDESCR_HLP_PAGE)
{
Object->ElementDESCR_HLP_PAGE=ElementDESCR_HLP_PAGE;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprPageImpl::get_ElementINDEX_HLP_PAGE(void)
{
return Object->ElementINDEX_HLP_PAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_ElementINDEX_HLP_PAGE(TFIBIntegerField * ElementINDEX_HLP_PAGE)
{
Object->ElementINDEX_HLP_PAGE=ElementINDEX_HLP_PAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageImpl::get_ElementWEBKEYWORDS_HLP_PAGE(void)
{
return Object->ElementWEBKEYWORDS_HLP_PAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_ElementWEBKEYWORDS_HLP_PAGE(TFIBWideStringField * ElementWEBKEYWORDS_HLP_PAGE)
{
Object->ElementWEBKEYWORDS_HLP_PAGE=ElementWEBKEYWORDS_HLP_PAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageImpl::get_ElementWEBTITLE_HLP_PAGE(void)
{
return Object->ElementWEBTITLE_HLP_PAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_ElementWEBTITLE_HLP_PAGE(TFIBWideStringField * ElementWEBTITLE_HLP_PAGE)
{
Object->ElementWEBTITLE_HLP_PAGE=ElementWEBTITLE_HLP_PAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageImpl::get_ElementWEBDESCR_HLP_PAGE(void)
{
return Object->ElementWEBDESCR_HLP_PAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_ElementWEBDESCR_HLP_PAGE(TFIBWideStringField * ElementWEBDESCR_HLP_PAGE)
{
Object->ElementWEBDESCR_HLP_PAGE=ElementWEBDESCR_HLP_PAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageImpl::get_ElementGUIDGRP_HLP_PAGE(void)
{
return Object->ElementGUIDGRP_HLP_PAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_ElementGUIDGRP_HLP_PAGE(TFIBWideStringField * ElementGUIDGRP_HLP_PAGE)
{
Object->ElementGUIDGRP_HLP_PAGE=ElementGUIDGRP_HLP_PAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageImpl::get_ElementSTRCODE_HLP_PAGE(void)
{
return Object->ElementSTRCODE_HLP_PAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_ElementSTRCODE_HLP_PAGE(TFIBWideStringField * ElementSTRCODE_HLP_PAGE)
{
Object->ElementSTRCODE_HLP_PAGE=ElementSTRCODE_HLP_PAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageImpl::get_ElementGUID_HLP_PAGE(void)
{
return Object->ElementGUID_HLP_PAGE;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_ElementGUID_HLP_PAGE(TFIBWideStringField * ElementGUID_HLP_PAGE)
{
Object->ElementGUID_HLP_PAGE=ElementGUID_HLP_PAGE;
}
//---------------------------------------------------------------
__int64 THLP_DMSprPageImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool THLP_DMSprPageImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
__int64 THLP_DMSprPageImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::OpenTable(__int64 id_grp, bool all)
{
return Object->OpenTable(id_grp,all);
}
//---------------------------------------------------------------
UnicodeString THLP_DMSprPageImpl::GetTextQuery(__int64 id_grp, bool all)
{
return Object->GetTextQuery(id_grp,all);
}
//---------------------------------------------------------------
int THLP_DMSprPageImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool THLP_DMSprPageImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool THLP_DMSprPageImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool THLP_DMSprPageImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
void THLP_DMSprPageImpl::ChancheGrp(__int64 id_new_grp,__int64 id_element)
{
return Object->ChancheGrp(id_new_grp,id_element);
}
//---------------------------------------------------------------
__int64 THLP_DMSprPageImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
__int64 THLP_DMSprPageImpl::GetIdGrp(__int64 id_el)
{
return Object->GetIdGrp(id_el);
}
//---------------------------------------------------------------
