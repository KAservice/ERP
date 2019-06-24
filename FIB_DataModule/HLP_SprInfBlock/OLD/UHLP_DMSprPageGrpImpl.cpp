#include "vcl.h"
#pragma hdrstop


#include "UHLP_DMSprPageGrpImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THLP_DMSprPageGrpImpl::THLP_DMSprPageGrpImpl()           
{                                            
Object=new THLP_DMSprPageGrp(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THLP_DMSprPageGrpImpl::~THLP_DMSprPageGrpImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THLP_DMSprPageGrpImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THLP_DMSprPageGrpImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHLP_DMSprPageGrp)                        
   {                                                                     
   *ppv=static_cast<IHLP_DMSprPageGrp*> (this);                                
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
int THLP_DMSprPageGrpImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THLP_DMSprPageGrpImpl::kanRelease(void)                                  
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
int  THLP_DMSprPageGrpImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THLP_DMSprPageGrpImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THLP_DMSprPageGrpImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THLP_DMSprPageGrpImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THLP_DMSprPageGrpImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_THLP_DMSprPageGrpImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THLP_DMSprPageGrpImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IHLP_DMSprPageGrp
TDataSource * THLP_DMSprPageGrpImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void THLP_DMSprPageGrpImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * THLP_DMSprPageGrpImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void THLP_DMSprPageGrpImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * THLP_DMSprPageGrpImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void THLP_DMSprPageGrpImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * THLP_DMSprPageGrpImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void THLP_DMSprPageGrpImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * THLP_DMSprPageGrpImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void THLP_DMSprPageGrpImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * THLP_DMSprPageGrpImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void THLP_DMSprPageGrpImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * THLP_DMSprPageGrpImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void THLP_DMSprPageGrpImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TIntegerField * THLP_DMSprPageGrpImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void THLP_DMSprPageGrpImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprPageGrpImpl::get_TableID_HLP_PAGE_GRP(void)
{
return Object->TableID_HLP_PAGE_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprPageGrpImpl::set_TableID_HLP_PAGE_GRP(TFIBLargeIntField * TableID_HLP_PAGE_GRP)
{
Object->TableID_HLP_PAGE_GRP=TableID_HLP_PAGE_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprPageGrpImpl::get_TableIDBASE_HLP_PAGE_GRP(void)
{
return Object->TableIDBASE_HLP_PAGE_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprPageGrpImpl::set_TableIDBASE_HLP_PAGE_GRP(TFIBLargeIntField * TableIDBASE_HLP_PAGE_GRP)
{
Object->TableIDBASE_HLP_PAGE_GRP=TableIDBASE_HLP_PAGE_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageGrpImpl::get_TableGID_HLP_PAGE_GRP(void)
{
return Object->TableGID_HLP_PAGE_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprPageGrpImpl::set_TableGID_HLP_PAGE_GRP(TFIBWideStringField * TableGID_HLP_PAGE_GRP)
{
Object->TableGID_HLP_PAGE_GRP=TableGID_HLP_PAGE_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageGrpImpl::get_TableGUID_HLP_PAGE_GRP(void)
{
return Object->TableGUID_HLP_PAGE_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprPageGrpImpl::set_TableGUID_HLP_PAGE_GRP(TFIBWideStringField * TableGUID_HLP_PAGE_GRP)
{
Object->TableGUID_HLP_PAGE_GRP=TableGUID_HLP_PAGE_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprPageGrpImpl::get_TableIDGRP_HLP_PAGE_GRP(void)
{
return Object->TableIDGRP_HLP_PAGE_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprPageGrpImpl::set_TableIDGRP_HLP_PAGE_GRP(TFIBLargeIntField * TableIDGRP_HLP_PAGE_GRP)
{
Object->TableIDGRP_HLP_PAGE_GRP=TableIDGRP_HLP_PAGE_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageGrpImpl::get_TableNAME_HLP_PAGE_GRP(void)
{
return Object->TableNAME_HLP_PAGE_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprPageGrpImpl::set_TableNAME_HLP_PAGE_GRP(TFIBWideStringField * TableNAME_HLP_PAGE_GRP)
{
Object->TableNAME_HLP_PAGE_GRP=TableNAME_HLP_PAGE_GRP;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprPageGrpImpl::get_TableINDEX_HLP_PAGE_GRP(void)
{
return Object->TableINDEX_HLP_PAGE_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprPageGrpImpl::set_TableINDEX_HLP_PAGE_GRP(TFIBIntegerField * TableINDEX_HLP_PAGE_GRP)
{
Object->TableINDEX_HLP_PAGE_GRP=TableINDEX_HLP_PAGE_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageGrpImpl::get_TableGUIDGRP_HLP_PAGE_GRP(void)
{
return Object->TableGUIDGRP_HLP_PAGE_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprPageGrpImpl::set_TableGUIDGRP_HLP_PAGE_GRP(TFIBWideStringField * TableGUIDGRP_HLP_PAGE_GRP)
{
Object->TableGUIDGRP_HLP_PAGE_GRP=TableGUIDGRP_HLP_PAGE_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprPageGrpImpl::get_ElementID_HLP_PAGE_GRP(void)
{
return Object->ElementID_HLP_PAGE_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprPageGrpImpl::set_ElementID_HLP_PAGE_GRP(TFIBLargeIntField * ElementID_HLP_PAGE_GRP)
{
Object->ElementID_HLP_PAGE_GRP=ElementID_HLP_PAGE_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprPageGrpImpl::get_ElementIDBASE_HLP_PAGE_GRP(void)
{
return Object->ElementIDBASE_HLP_PAGE_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprPageGrpImpl::set_ElementIDBASE_HLP_PAGE_GRP(TFIBLargeIntField * ElementIDBASE_HLP_PAGE_GRP)
{
Object->ElementIDBASE_HLP_PAGE_GRP=ElementIDBASE_HLP_PAGE_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageGrpImpl::get_ElementGID_HLP_PAGE_GRP(void)
{
return Object->ElementGID_HLP_PAGE_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprPageGrpImpl::set_ElementGID_HLP_PAGE_GRP(TFIBWideStringField * ElementGID_HLP_PAGE_GRP)
{
Object->ElementGID_HLP_PAGE_GRP=ElementGID_HLP_PAGE_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageGrpImpl::get_ElementGUID_HLP_PAGE_GRP(void)
{
return Object->ElementGUID_HLP_PAGE_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprPageGrpImpl::set_ElementGUID_HLP_PAGE_GRP(TFIBWideStringField * ElementGUID_HLP_PAGE_GRP)
{
Object->ElementGUID_HLP_PAGE_GRP=ElementGUID_HLP_PAGE_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprPageGrpImpl::get_ElementIDGRP_HLP_PAGE_GRP(void)
{
return Object->ElementIDGRP_HLP_PAGE_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprPageGrpImpl::set_ElementIDGRP_HLP_PAGE_GRP(TFIBLargeIntField * ElementIDGRP_HLP_PAGE_GRP)
{
Object->ElementIDGRP_HLP_PAGE_GRP=ElementIDGRP_HLP_PAGE_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageGrpImpl::get_ElementNAME_HLP_PAGE_GRP(void)
{
return Object->ElementNAME_HLP_PAGE_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprPageGrpImpl::set_ElementNAME_HLP_PAGE_GRP(TFIBWideStringField * ElementNAME_HLP_PAGE_GRP)
{
Object->ElementNAME_HLP_PAGE_GRP=ElementNAME_HLP_PAGE_GRP;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprPageGrpImpl::get_ElementINDEX_HLP_PAGE_GRP(void)
{
return Object->ElementINDEX_HLP_PAGE_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprPageGrpImpl::set_ElementINDEX_HLP_PAGE_GRP(TFIBIntegerField * ElementINDEX_HLP_PAGE_GRP)
{
Object->ElementINDEX_HLP_PAGE_GRP=ElementINDEX_HLP_PAGE_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprPageGrpImpl::get_ElementGUIDGRP_HLP_PAGE_GRP(void)
{
return Object->ElementGUIDGRP_HLP_PAGE_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprPageGrpImpl::set_ElementGUIDGRP_HLP_PAGE_GRP(TFIBWideStringField * ElementGUIDGRP_HLP_PAGE_GRP)
{
Object->ElementGUIDGRP_HLP_PAGE_GRP=ElementGUIDGRP_HLP_PAGE_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprPageGrpImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int THLP_DMSprPageGrpImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void THLP_DMSprPageGrpImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool THLP_DMSprPageGrpImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool THLP_DMSprPageGrpImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 THLP_DMSprPageGrpImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
