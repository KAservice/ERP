#include "vcl.h"
#pragma hdrstop


#include "UDMSprVidImageGrpImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprVidImageGrpImpl::TDMSprVidImageGrpImpl()           
{                                            
Object=new TDMSprVidImageGrp(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprVidImageGrpImpl::~TDMSprVidImageGrpImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprVidImageGrpImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprVidImageGrpImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprVidImageGrp)                        
   {                                                                     
   *ppv=static_cast<IDMSprVidImageGrp*> (this);                                
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
int TDMSprVidImageGrpImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprVidImageGrpImpl::kanRelease(void)                                  
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
int  TDMSprVidImageGrpImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprVidImageGrpImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprVidImageGrpImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprVidImageGrpImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprVidImageGrpImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprVidImageGrpImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprVidImageGrpImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprVidImageGrp
TDataSource * TDMSprVidImageGrpImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprVidImageGrpImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprVidImageGrpImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprVidImageGrpImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprVidImageGrpImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprVidImageGrpImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprVidImageGrpImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprVidImageGrpImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprVidImageGrpImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprVidImageGrpImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprVidImageGrpImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprVidImageGrpImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprVidImageGrpImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprVidImageGrpImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprVidImageGrpImpl::get_TableID_SVIDIMAGE_GRP(void)
{
return Object->TableID_SVIDIMAGE_GRP;
}
//---------------------------------------------------------------
void TDMSprVidImageGrpImpl::set_TableID_SVIDIMAGE_GRP(TFIBLargeIntField * TableID_SVIDIMAGE_GRP)
{
Object->TableID_SVIDIMAGE_GRP=TableID_SVIDIMAGE_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprVidImageGrpImpl::get_TableIDBASE_SVIDIMAGE_GRP(void)
{
return Object->TableIDBASE_SVIDIMAGE_GRP;
}
//---------------------------------------------------------------
void TDMSprVidImageGrpImpl::set_TableIDBASE_SVIDIMAGE_GRP(TFIBLargeIntField * TableIDBASE_SVIDIMAGE_GRP)
{
Object->TableIDBASE_SVIDIMAGE_GRP=TableIDBASE_SVIDIMAGE_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprVidImageGrpImpl::get_TableGID_SVIDIMAGE_GRP(void)
{
return Object->TableGID_SVIDIMAGE_GRP;
}
//---------------------------------------------------------------
void TDMSprVidImageGrpImpl::set_TableGID_SVIDIMAGE_GRP(TFIBWideStringField * TableGID_SVIDIMAGE_GRP)
{
Object->TableGID_SVIDIMAGE_GRP=TableGID_SVIDIMAGE_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprVidImageGrpImpl::get_TableIDGRP_SVIDIMAGE_GRP(void)
{
return Object->TableIDGRP_SVIDIMAGE_GRP;
}
//---------------------------------------------------------------
void TDMSprVidImageGrpImpl::set_TableIDGRP_SVIDIMAGE_GRP(TFIBLargeIntField * TableIDGRP_SVIDIMAGE_GRP)
{
Object->TableIDGRP_SVIDIMAGE_GRP=TableIDGRP_SVIDIMAGE_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprVidImageGrpImpl::get_TableNAME_SVIDIMAGE_GRP(void)
{
return Object->TableNAME_SVIDIMAGE_GRP;
}
//---------------------------------------------------------------
void TDMSprVidImageGrpImpl::set_TableNAME_SVIDIMAGE_GRP(TFIBWideStringField * TableNAME_SVIDIMAGE_GRP)
{
Object->TableNAME_SVIDIMAGE_GRP=TableNAME_SVIDIMAGE_GRP;
}
//---------------------------------------------------------------
TIntegerField * TDMSprVidImageGrpImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprVidImageGrpImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprVidImageGrpImpl::get_ElementID_SVIDIMAGE_GRP(void)
{
return Object->ElementID_SVIDIMAGE_GRP;
}
//---------------------------------------------------------------
void TDMSprVidImageGrpImpl::set_ElementID_SVIDIMAGE_GRP(TFIBLargeIntField * ElementID_SVIDIMAGE_GRP)
{
Object->ElementID_SVIDIMAGE_GRP=ElementID_SVIDIMAGE_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprVidImageGrpImpl::get_ElementIDBASE_SVIDIMAGE_GRP(void)
{
return Object->ElementIDBASE_SVIDIMAGE_GRP;
}
//---------------------------------------------------------------
void TDMSprVidImageGrpImpl::set_ElementIDBASE_SVIDIMAGE_GRP(TFIBLargeIntField * ElementIDBASE_SVIDIMAGE_GRP)
{
Object->ElementIDBASE_SVIDIMAGE_GRP=ElementIDBASE_SVIDIMAGE_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprVidImageGrpImpl::get_ElementGID_SVIDIMAGE_GRP(void)
{
return Object->ElementGID_SVIDIMAGE_GRP;
}
//---------------------------------------------------------------
void TDMSprVidImageGrpImpl::set_ElementGID_SVIDIMAGE_GRP(TFIBWideStringField * ElementGID_SVIDIMAGE_GRP)
{
Object->ElementGID_SVIDIMAGE_GRP=ElementGID_SVIDIMAGE_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprVidImageGrpImpl::get_ElementIDGRP_SVIDIMAGE_GRP(void)
{
return Object->ElementIDGRP_SVIDIMAGE_GRP;
}
//---------------------------------------------------------------
void TDMSprVidImageGrpImpl::set_ElementIDGRP_SVIDIMAGE_GRP(TFIBLargeIntField * ElementIDGRP_SVIDIMAGE_GRP)
{
Object->ElementIDGRP_SVIDIMAGE_GRP=ElementIDGRP_SVIDIMAGE_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprVidImageGrpImpl::get_ElementNAME_SVIDIMAGE_GRP(void)
{
return Object->ElementNAME_SVIDIMAGE_GRP;
}
//---------------------------------------------------------------
void TDMSprVidImageGrpImpl::set_ElementNAME_SVIDIMAGE_GRP(TFIBWideStringField * ElementNAME_SVIDIMAGE_GRP)
{
Object->ElementNAME_SVIDIMAGE_GRP=ElementNAME_SVIDIMAGE_GRP;
}
//---------------------------------------------------------------
void TDMSprVidImageGrpImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprVidImageGrpImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TDMSprVidImageGrpImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TDMSprVidImageGrpImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprVidImageGrpImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TDMSprVidImageGrpImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
