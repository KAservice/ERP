#include "vcl.h"
#pragma hdrstop


#include "UART_DMSprImageGrpImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TART_DMSprImageGrpImpl::TART_DMSprImageGrpImpl()           
{                                            
Object=new TART_DMSprImageGrp(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TART_DMSprImageGrpImpl::~TART_DMSprImageGrpImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TART_DMSprImageGrpImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TART_DMSprImageGrpImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IART_DMSprImageGrp)                        
   {                                                                     
   *ppv=static_cast<IART_DMSprImageGrp*> (this);                                
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
int TART_DMSprImageGrpImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TART_DMSprImageGrpImpl::kanRelease(void)                                  
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
int  TART_DMSprImageGrpImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TART_DMSprImageGrpImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TART_DMSprImageGrpImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TART_DMSprImageGrpImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TART_DMSprImageGrpImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TART_DMSprImageGrpImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TART_DMSprImageGrpImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IART_DMSprImageGrp
TDataSource * TART_DMSprImageGrpImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TART_DMSprImageGrpImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TART_DMSprImageGrpImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TART_DMSprImageGrpImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TART_DMSprImageGrpImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TART_DMSprImageGrpImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TART_DMSprImageGrpImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TART_DMSprImageGrpImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TART_DMSprImageGrpImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TART_DMSprImageGrpImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TART_DMSprImageGrpImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TART_DMSprImageGrpImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TART_DMSprImageGrpImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TART_DMSprImageGrpImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprImageGrpImpl::get_TableID_ART_IMG_GRP(void)
{
return Object->TableID_ART_IMG_GRP;
}
//---------------------------------------------------------------
void TART_DMSprImageGrpImpl::set_TableID_ART_IMG_GRP(TFIBLargeIntField * TableID_ART_IMG_GRP)
{
Object->TableID_ART_IMG_GRP=TableID_ART_IMG_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprImageGrpImpl::get_TableIDBASE_ART_IMG_GRP(void)
{
return Object->TableIDBASE_ART_IMG_GRP;
}
//---------------------------------------------------------------
void TART_DMSprImageGrpImpl::set_TableIDBASE_ART_IMG_GRP(TFIBLargeIntField * TableIDBASE_ART_IMG_GRP)
{
Object->TableIDBASE_ART_IMG_GRP=TableIDBASE_ART_IMG_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprImageGrpImpl::get_TableGUID_ART_IMG_GRP(void)
{
return Object->TableGUID_ART_IMG_GRP;
}
//---------------------------------------------------------------
void TART_DMSprImageGrpImpl::set_TableGUID_ART_IMG_GRP(TFIBWideStringField * TableGUID_ART_IMG_GRP)
{
Object->TableGUID_ART_IMG_GRP=TableGUID_ART_IMG_GRP;
}
//---------------------------------------------------------------
TFIBDateTimeField * TART_DMSprImageGrpImpl::get_TablePOS_ISM_ART_IMG_GRP(void)
{
return Object->TablePOS_ISM_ART_IMG_GRP;
}
//---------------------------------------------------------------
void TART_DMSprImageGrpImpl::set_TablePOS_ISM_ART_IMG_GRP(TFIBDateTimeField * TablePOS_ISM_ART_IMG_GRP)
{
Object->TablePOS_ISM_ART_IMG_GRP=TablePOS_ISM_ART_IMG_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprImageGrpImpl::get_TableIDGRP_ART_IMG_GRP(void)
{
return Object->TableIDGRP_ART_IMG_GRP;
}
//---------------------------------------------------------------
void TART_DMSprImageGrpImpl::set_TableIDGRP_ART_IMG_GRP(TFIBLargeIntField * TableIDGRP_ART_IMG_GRP)
{
Object->TableIDGRP_ART_IMG_GRP=TableIDGRP_ART_IMG_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprImageGrpImpl::get_TableGUIDGRP_ART_IMG_GRP(void)
{
return Object->TableGUIDGRP_ART_IMG_GRP;
}
//---------------------------------------------------------------
void TART_DMSprImageGrpImpl::set_TableGUIDGRP_ART_IMG_GRP(TFIBWideStringField * TableGUIDGRP_ART_IMG_GRP)
{
Object->TableGUIDGRP_ART_IMG_GRP=TableGUIDGRP_ART_IMG_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprImageGrpImpl::get_TableNAME_ART_IMG_GRP(void)
{
return Object->TableNAME_ART_IMG_GRP;
}
//---------------------------------------------------------------
void TART_DMSprImageGrpImpl::set_TableNAME_ART_IMG_GRP(TFIBWideStringField * TableNAME_ART_IMG_GRP)
{
Object->TableNAME_ART_IMG_GRP=TableNAME_ART_IMG_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprImageGrpImpl::get_ElementID_ART_IMG_GRP(void)
{
return Object->ElementID_ART_IMG_GRP;
}
//---------------------------------------------------------------
void TART_DMSprImageGrpImpl::set_ElementID_ART_IMG_GRP(TFIBLargeIntField * ElementID_ART_IMG_GRP)
{
Object->ElementID_ART_IMG_GRP=ElementID_ART_IMG_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprImageGrpImpl::get_ElementIDBASE_ART_IMG_GRP(void)
{
return Object->ElementIDBASE_ART_IMG_GRP;
}
//---------------------------------------------------------------
void TART_DMSprImageGrpImpl::set_ElementIDBASE_ART_IMG_GRP(TFIBLargeIntField * ElementIDBASE_ART_IMG_GRP)
{
Object->ElementIDBASE_ART_IMG_GRP=ElementIDBASE_ART_IMG_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprImageGrpImpl::get_ElementGUID_ART_IMG_GRP(void)
{
return Object->ElementGUID_ART_IMG_GRP;
}
//---------------------------------------------------------------
void TART_DMSprImageGrpImpl::set_ElementGUID_ART_IMG_GRP(TFIBWideStringField * ElementGUID_ART_IMG_GRP)
{
Object->ElementGUID_ART_IMG_GRP=ElementGUID_ART_IMG_GRP;
}
//---------------------------------------------------------------
TFIBDateTimeField * TART_DMSprImageGrpImpl::get_ElementPOS_ISM_ART_IMG_GRP(void)
{
return Object->ElementPOS_ISM_ART_IMG_GRP;
}
//---------------------------------------------------------------
void TART_DMSprImageGrpImpl::set_ElementPOS_ISM_ART_IMG_GRP(TFIBDateTimeField * ElementPOS_ISM_ART_IMG_GRP)
{
Object->ElementPOS_ISM_ART_IMG_GRP=ElementPOS_ISM_ART_IMG_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprImageGrpImpl::get_ElementIDGRP_ART_IMG_GRP(void)
{
return Object->ElementIDGRP_ART_IMG_GRP;
}
//---------------------------------------------------------------
void TART_DMSprImageGrpImpl::set_ElementIDGRP_ART_IMG_GRP(TFIBLargeIntField * ElementIDGRP_ART_IMG_GRP)
{
Object->ElementIDGRP_ART_IMG_GRP=ElementIDGRP_ART_IMG_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprImageGrpImpl::get_ElementGUIDGRP_ART_IMG_GRP(void)
{
return Object->ElementGUIDGRP_ART_IMG_GRP;
}
//---------------------------------------------------------------
void TART_DMSprImageGrpImpl::set_ElementGUIDGRP_ART_IMG_GRP(TFIBWideStringField * ElementGUIDGRP_ART_IMG_GRP)
{
Object->ElementGUIDGRP_ART_IMG_GRP=ElementGUIDGRP_ART_IMG_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprImageGrpImpl::get_ElementNAME_ART_IMG_GRP(void)
{
return Object->ElementNAME_ART_IMG_GRP;
}
//---------------------------------------------------------------
void TART_DMSprImageGrpImpl::set_ElementNAME_ART_IMG_GRP(TFIBWideStringField * ElementNAME_ART_IMG_GRP)
{
Object->ElementNAME_ART_IMG_GRP=ElementNAME_ART_IMG_GRP;
}
//---------------------------------------------------------------
void TART_DMSprImageGrpImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TART_DMSprImageGrpImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TART_DMSprImageGrpImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TART_DMSprImageGrpImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TART_DMSprImageGrpImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TART_DMSprImageGrpImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
