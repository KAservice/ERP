#include "vcl.h"
#pragma hdrstop


#include "UDMSprGrpNomInetCatalogImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprGrpNomInetCatalogImpl::TDMSprGrpNomInetCatalogImpl()           
{                                            
Object=new TDMSprGrpNomInetCatalog(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprGrpNomInetCatalogImpl::~TDMSprGrpNomInetCatalogImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprGrpNomInetCatalogImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprGrpNomInetCatalogImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprGrpNomInetCatalog)                        
   {                                                                     
   *ppv=static_cast<IDMSprGrpNomInetCatalog*> (this);                                
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
int TDMSprGrpNomInetCatalogImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprGrpNomInetCatalogImpl::kanRelease(void)                                  
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
int  TDMSprGrpNomInetCatalogImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprGrpNomInetCatalogImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprGrpNomInetCatalogImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprGrpNomInetCatalogImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprGrpNomInetCatalogImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprGrpNomInetCatalogImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprGrpNomInetCatalogImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprGrpNomInetCatalog
TDataSource * TDMSprGrpNomInetCatalogImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprGrpNomInetCatalogImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprGrpNomInetCatalogImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprGrpNomInetCatalogImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprGrpNomInetCatalogImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprGrpNomInetCatalogImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprGrpNomInetCatalogImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprGrpNomInetCatalogImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprGrpNomInetCatalogImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprGrpNomInetCatalogImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprGrpNomInetCatalogImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprGrpNomInetCatalogImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprGrpNomInetCatalogImpl::get_ElementID_SNOMINETCAT_GRP(void)
{
return Object->ElementID_SNOMINETCAT_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpNomInetCatalogImpl::set_ElementID_SNOMINETCAT_GRP(TFIBLargeIntField * ElementID_SNOMINETCAT_GRP)
{
Object->ElementID_SNOMINETCAT_GRP=ElementID_SNOMINETCAT_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprGrpNomInetCatalogImpl::get_ElementIDBASE_SNOMINETCAT_GRP(void)
{
return Object->ElementIDBASE_SNOMINETCAT_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpNomInetCatalogImpl::set_ElementIDBASE_SNOMINETCAT_GRP(TFIBLargeIntField * ElementIDBASE_SNOMINETCAT_GRP)
{
Object->ElementIDBASE_SNOMINETCAT_GRP=ElementIDBASE_SNOMINETCAT_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpNomInetCatalogImpl::get_ElementGID_SNOMINETCAT_GRP(void)
{
return Object->ElementGID_SNOMINETCAT_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpNomInetCatalogImpl::set_ElementGID_SNOMINETCAT_GRP(TFIBWideStringField * ElementGID_SNOMINETCAT_GRP)
{
Object->ElementGID_SNOMINETCAT_GRP=ElementGID_SNOMINETCAT_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprGrpNomInetCatalogImpl::get_ElementIDGRP_SNOMINETCAT_GRP(void)
{
return Object->ElementIDGRP_SNOMINETCAT_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpNomInetCatalogImpl::set_ElementIDGRP_SNOMINETCAT_GRP(TFIBLargeIntField * ElementIDGRP_SNOMINETCAT_GRP)
{
Object->ElementIDGRP_SNOMINETCAT_GRP=ElementIDGRP_SNOMINETCAT_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprGrpNomInetCatalogImpl::get_ElementIDINETCAT_SNOMINETCAT_GRP(void)
{
return Object->ElementIDINETCAT_SNOMINETCAT_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpNomInetCatalogImpl::set_ElementIDINETCAT_SNOMINETCAT_GRP(TFIBLargeIntField * ElementIDINETCAT_SNOMINETCAT_GRP)
{
Object->ElementIDINETCAT_SNOMINETCAT_GRP=ElementIDINETCAT_SNOMINETCAT_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpNomInetCatalogImpl::get_ElementNAME_SNOMINETCAT_GRP(void)
{
return Object->ElementNAME_SNOMINETCAT_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpNomInetCatalogImpl::set_ElementNAME_SNOMINETCAT_GRP(TFIBWideStringField * ElementNAME_SNOMINETCAT_GRP)
{
Object->ElementNAME_SNOMINETCAT_GRP=ElementNAME_SNOMINETCAT_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprGrpNomInetCatalogImpl::get_TableID_SNOMINETCAT_GRP(void)
{
return Object->TableID_SNOMINETCAT_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpNomInetCatalogImpl::set_TableID_SNOMINETCAT_GRP(TFIBLargeIntField * TableID_SNOMINETCAT_GRP)
{
Object->TableID_SNOMINETCAT_GRP=TableID_SNOMINETCAT_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprGrpNomInetCatalogImpl::get_TableIDBASE_SNOMINETCAT_GRP(void)
{
return Object->TableIDBASE_SNOMINETCAT_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpNomInetCatalogImpl::set_TableIDBASE_SNOMINETCAT_GRP(TFIBLargeIntField * TableIDBASE_SNOMINETCAT_GRP)
{
Object->TableIDBASE_SNOMINETCAT_GRP=TableIDBASE_SNOMINETCAT_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpNomInetCatalogImpl::get_TableGID_SNOMINETCAT_GRP(void)
{
return Object->TableGID_SNOMINETCAT_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpNomInetCatalogImpl::set_TableGID_SNOMINETCAT_GRP(TFIBWideStringField * TableGID_SNOMINETCAT_GRP)
{
Object->TableGID_SNOMINETCAT_GRP=TableGID_SNOMINETCAT_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprGrpNomInetCatalogImpl::get_TableIDGRP_SNOMINETCAT_GRP(void)
{
return Object->TableIDGRP_SNOMINETCAT_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpNomInetCatalogImpl::set_TableIDGRP_SNOMINETCAT_GRP(TFIBLargeIntField * TableIDGRP_SNOMINETCAT_GRP)
{
Object->TableIDGRP_SNOMINETCAT_GRP=TableIDGRP_SNOMINETCAT_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprGrpNomInetCatalogImpl::get_TableIDINETCAT_SNOMINETCAT_GRP(void)
{
return Object->TableIDINETCAT_SNOMINETCAT_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpNomInetCatalogImpl::set_TableIDINETCAT_SNOMINETCAT_GRP(TFIBLargeIntField * TableIDINETCAT_SNOMINETCAT_GRP)
{
Object->TableIDINETCAT_SNOMINETCAT_GRP=TableIDINETCAT_SNOMINETCAT_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpNomInetCatalogImpl::get_TableNAME_SNOMINETCAT_GRP(void)
{
return Object->TableNAME_SNOMINETCAT_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpNomInetCatalogImpl::set_TableNAME_SNOMINETCAT_GRP(TFIBWideStringField * TableNAME_SNOMINETCAT_GRP)
{
Object->TableNAME_SNOMINETCAT_GRP=TableNAME_SNOMINETCAT_GRP;
}
//---------------------------------------------------------------
TIntegerField * TDMSprGrpNomInetCatalogImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprGrpNomInetCatalogImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
__int64 TDMSprGrpNomInetCatalogImpl::get_IdInetCatalog(void)
{
return Object->IdInetCatalog;
}
//---------------------------------------------------------------
void TDMSprGrpNomInetCatalogImpl::set_IdInetCatalog(__int64 IdInetCatalog)
{
Object->IdInetCatalog=IdInetCatalog;
}
//---------------------------------------------------------------
void TDMSprGrpNomInetCatalogImpl::OpenTable(__int64 id_inet_catalog)
{
return Object->OpenTable(id_inet_catalog);
}
//---------------------------------------------------------------
int TDMSprGrpNomInetCatalogImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TDMSprGrpNomInetCatalogImpl::NewElement(__int64 id_inet_catalog, __int64 id_grp)
{
return Object->NewElement(id_inet_catalog,id_grp);
}
//---------------------------------------------------------------
bool TDMSprGrpNomInetCatalogImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprGrpNomInetCatalogImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
