#include "vcl.h"
#pragma hdrstop


#include "UHLP_DMSprImageGrpImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THLP_DMSprImageGrpImpl::THLP_DMSprImageGrpImpl()           
{                                            
Object=new THLP_DMSprImageGrp(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THLP_DMSprImageGrpImpl::~THLP_DMSprImageGrpImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THLP_DMSprImageGrpImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THLP_DMSprImageGrpImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHLP_DMSprImageGrp)                        
   {                                                                     
   *ppv=static_cast<IHLP_DMSprImageGrp*> (this);                                
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
int THLP_DMSprImageGrpImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THLP_DMSprImageGrpImpl::kanRelease(void)                                  
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
int  THLP_DMSprImageGrpImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THLP_DMSprImageGrpImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THLP_DMSprImageGrpImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THLP_DMSprImageGrpImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THLP_DMSprImageGrpImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_THLP_DMSprImageGrpImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THLP_DMSprImageGrpImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IHLP_DMSprImageGrp
TDataSource * THLP_DMSprImageGrpImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void THLP_DMSprImageGrpImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * THLP_DMSprImageGrpImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void THLP_DMSprImageGrpImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * THLP_DMSprImageGrpImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void THLP_DMSprImageGrpImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * THLP_DMSprImageGrpImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void THLP_DMSprImageGrpImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * THLP_DMSprImageGrpImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void THLP_DMSprImageGrpImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * THLP_DMSprImageGrpImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void THLP_DMSprImageGrpImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * THLP_DMSprImageGrpImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void THLP_DMSprImageGrpImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprImageGrpImpl::get_TableID_HLP_IMG_GRP(void)
{
return Object->TableID_HLP_IMG_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprImageGrpImpl::set_TableID_HLP_IMG_GRP(TFIBLargeIntField * TableID_HLP_IMG_GRP)
{
Object->TableID_HLP_IMG_GRP=TableID_HLP_IMG_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprImageGrpImpl::get_TableIDBASE_HLP_IMG_GRP(void)
{
return Object->TableIDBASE_HLP_IMG_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprImageGrpImpl::set_TableIDBASE_HLP_IMG_GRP(TFIBLargeIntField * TableIDBASE_HLP_IMG_GRP)
{
Object->TableIDBASE_HLP_IMG_GRP=TableIDBASE_HLP_IMG_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprImageGrpImpl::get_TableGUID_HLP_IMG_GRP(void)
{
return Object->TableGUID_HLP_IMG_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprImageGrpImpl::set_TableGUID_HLP_IMG_GRP(TFIBWideStringField * TableGUID_HLP_IMG_GRP)
{
Object->TableGUID_HLP_IMG_GRP=TableGUID_HLP_IMG_GRP;
}
//---------------------------------------------------------------
TFIBDateTimeField * THLP_DMSprImageGrpImpl::get_TablePOS_ISM_HLP_IMG_GRP(void)
{
return Object->TablePOS_ISM_HLP_IMG_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprImageGrpImpl::set_TablePOS_ISM_HLP_IMG_GRP(TFIBDateTimeField * TablePOS_ISM_HLP_IMG_GRP)
{
Object->TablePOS_ISM_HLP_IMG_GRP=TablePOS_ISM_HLP_IMG_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprImageGrpImpl::get_TableIDGRP_HLP_IMG_GRP(void)
{
return Object->TableIDGRP_HLP_IMG_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprImageGrpImpl::set_TableIDGRP_HLP_IMG_GRP(TFIBLargeIntField * TableIDGRP_HLP_IMG_GRP)
{
Object->TableIDGRP_HLP_IMG_GRP=TableIDGRP_HLP_IMG_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprImageGrpImpl::get_TableGUIDGRP_HLP_IMG_GRP(void)
{
return Object->TableGUIDGRP_HLP_IMG_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprImageGrpImpl::set_TableGUIDGRP_HLP_IMG_GRP(TFIBWideStringField * TableGUIDGRP_HLP_IMG_GRP)
{
Object->TableGUIDGRP_HLP_IMG_GRP=TableGUIDGRP_HLP_IMG_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprImageGrpImpl::get_TableNAME_HLP_IMG_GRP(void)
{
return Object->TableNAME_HLP_IMG_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprImageGrpImpl::set_TableNAME_HLP_IMG_GRP(TFIBWideStringField * TableNAME_HLP_IMG_GRP)
{
Object->TableNAME_HLP_IMG_GRP=TableNAME_HLP_IMG_GRP;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprImageGrpImpl::get_TableINDEX_HLP_IMG_GRP(void)
{
return Object->TableINDEX_HLP_IMG_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprImageGrpImpl::set_TableINDEX_HLP_IMG_GRP(TFIBIntegerField * TableINDEX_HLP_IMG_GRP)
{
Object->TableINDEX_HLP_IMG_GRP=TableINDEX_HLP_IMG_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprImageGrpImpl::get_ElementID_HLP_IMG_GRP(void)
{
return Object->ElementID_HLP_IMG_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprImageGrpImpl::set_ElementID_HLP_IMG_GRP(TFIBLargeIntField * ElementID_HLP_IMG_GRP)
{
Object->ElementID_HLP_IMG_GRP=ElementID_HLP_IMG_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprImageGrpImpl::get_ElementIDBASE_HLP_IMG_GRP(void)
{
return Object->ElementIDBASE_HLP_IMG_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprImageGrpImpl::set_ElementIDBASE_HLP_IMG_GRP(TFIBLargeIntField * ElementIDBASE_HLP_IMG_GRP)
{
Object->ElementIDBASE_HLP_IMG_GRP=ElementIDBASE_HLP_IMG_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprImageGrpImpl::get_ElementGUID_HLP_IMG_GRP(void)
{
return Object->ElementGUID_HLP_IMG_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprImageGrpImpl::set_ElementGUID_HLP_IMG_GRP(TFIBWideStringField * ElementGUID_HLP_IMG_GRP)
{
Object->ElementGUID_HLP_IMG_GRP=ElementGUID_HLP_IMG_GRP;
}
//---------------------------------------------------------------
TFIBDateTimeField * THLP_DMSprImageGrpImpl::get_ElementPOS_ISM_HLP_IMG_GRP(void)
{
return Object->ElementPOS_ISM_HLP_IMG_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprImageGrpImpl::set_ElementPOS_ISM_HLP_IMG_GRP(TFIBDateTimeField * ElementPOS_ISM_HLP_IMG_GRP)
{
Object->ElementPOS_ISM_HLP_IMG_GRP=ElementPOS_ISM_HLP_IMG_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprImageGrpImpl::get_ElementIDGRP_HLP_IMG_GRP(void)
{
return Object->ElementIDGRP_HLP_IMG_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprImageGrpImpl::set_ElementIDGRP_HLP_IMG_GRP(TFIBLargeIntField * ElementIDGRP_HLP_IMG_GRP)
{
Object->ElementIDGRP_HLP_IMG_GRP=ElementIDGRP_HLP_IMG_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprImageGrpImpl::get_ElementGUIDGRP_HLP_IMG_GRP(void)
{
return Object->ElementGUIDGRP_HLP_IMG_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprImageGrpImpl::set_ElementGUIDGRP_HLP_IMG_GRP(TFIBWideStringField * ElementGUIDGRP_HLP_IMG_GRP)
{
Object->ElementGUIDGRP_HLP_IMG_GRP=ElementGUIDGRP_HLP_IMG_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprImageGrpImpl::get_ElementNAME_HLP_IMG_GRP(void)
{
return Object->ElementNAME_HLP_IMG_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprImageGrpImpl::set_ElementNAME_HLP_IMG_GRP(TFIBWideStringField * ElementNAME_HLP_IMG_GRP)
{
Object->ElementNAME_HLP_IMG_GRP=ElementNAME_HLP_IMG_GRP;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprImageGrpImpl::get_ElementINDEX_HLP_IMG_GRP(void)
{
return Object->ElementINDEX_HLP_IMG_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprImageGrpImpl::set_ElementINDEX_HLP_IMG_GRP(TFIBIntegerField * ElementINDEX_HLP_IMG_GRP)
{
Object->ElementINDEX_HLP_IMG_GRP=ElementINDEX_HLP_IMG_GRP;
}
//---------------------------------------------------------------
void THLP_DMSprImageGrpImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int THLP_DMSprImageGrpImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void THLP_DMSprImageGrpImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool THLP_DMSprImageGrpImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool THLP_DMSprImageGrpImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 THLP_DMSprImageGrpImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
