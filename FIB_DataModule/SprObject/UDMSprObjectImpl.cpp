#include "vcl.h"
#pragma hdrstop


#include "UDMSprObjectImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprObjectImpl::TDMSprObjectImpl()           
{                                            
Object=new TDMSprObject(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprObjectImpl::~TDMSprObjectImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprObjectImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprObjectImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprObject)                        
   {                                                                     
   *ppv=static_cast<IDMSprObject*> (this);                                
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
int TDMSprObjectImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprObjectImpl::kanRelease(void)                                  
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
int  TDMSprObjectImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprObjectImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprObjectImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprObjectImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprObjectImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprObjectImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprObjectImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprObject
TDataSource * TDMSprObjectImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprObjectImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprObjectImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprObjectImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprObjectImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprObjectImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMSprObjectImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprObjectImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprObjectImpl::get_TableID_SOBJECT(void)
{
return Object->TableID_SOBJECT;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_TableID_SOBJECT(TFIBLargeIntField * TableID_SOBJECT)
{
Object->TableID_SOBJECT=TableID_SOBJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprObjectImpl::get_TableNAME_SOBJECT(void)
{
return Object->TableNAME_SOBJECT;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_TableNAME_SOBJECT(TFIBWideStringField * TableNAME_SOBJECT)
{
Object->TableNAME_SOBJECT=TableNAME_SOBJECT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprObjectImpl::get_TableIDINFBASE_SOBJECT(void)
{
return Object->TableIDINFBASE_SOBJECT;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_TableIDINFBASE_SOBJECT(TFIBLargeIntField * TableIDINFBASE_SOBJECT)
{
Object->TableIDINFBASE_SOBJECT=TableIDINFBASE_SOBJECT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprObjectImpl::get_TableIDFIRM_SOBJECT(void)
{
return Object->TableIDFIRM_SOBJECT;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_TableIDFIRM_SOBJECT(TFIBLargeIntField * TableIDFIRM_SOBJECT)
{
Object->TableIDFIRM_SOBJECT=TableIDFIRM_SOBJECT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprObjectImpl::get_TableIDSKLAD_SOBJECT(void)
{
return Object->TableIDSKLAD_SOBJECT;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_TableIDSKLAD_SOBJECT(TFIBLargeIntField * TableIDSKLAD_SOBJECT)
{
Object->TableIDSKLAD_SOBJECT=TableIDSKLAD_SOBJECT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprObjectImpl::get_TableIDKASSA_SOBJECT(void)
{
return Object->TableIDKASSA_SOBJECT;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_TableIDKASSA_SOBJECT(TFIBLargeIntField * TableIDKASSA_SOBJECT)
{
Object->TableIDKASSA_SOBJECT=TableIDKASSA_SOBJECT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprObjectImpl::get_TableIDPODR_SOBJECT(void)
{
return Object->TableIDPODR_SOBJECT;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_TableIDPODR_SOBJECT(TFIBLargeIntField * TableIDPODR_SOBJECT)
{
Object->TableIDPODR_SOBJECT=TableIDPODR_SOBJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprObjectImpl::get_TableNAME_SINFBASE_OBMEN(void)
{
return Object->TableNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_TableNAME_SINFBASE_OBMEN(TFIBWideStringField * TableNAME_SINFBASE_OBMEN)
{
Object->TableNAME_SINFBASE_OBMEN=TableNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprObjectImpl::get_TableNAMEFIRM(void)
{
return Object->TableNAMEFIRM;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM)
{
Object->TableNAMEFIRM=TableNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprObjectImpl::get_TableNAMESKLAD(void)
{
return Object->TableNAMESKLAD;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)
{
Object->TableNAMESKLAD=TableNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprObjectImpl::get_TableNAMEKKM(void)
{
return Object->TableNAMEKKM;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_TableNAMEKKM(TFIBWideStringField * TableNAMEKKM)
{
Object->TableNAMEKKM=TableNAMEKKM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprObjectImpl::get_TableNAMEPOD(void)
{
return Object->TableNAMEPOD;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_TableNAMEPOD(TFIBWideStringField * TableNAMEPOD)
{
Object->TableNAMEPOD=TableNAMEPOD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprObjectImpl::get_ElementID_SOBJECT(void)
{
return Object->ElementID_SOBJECT;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_ElementID_SOBJECT(TFIBLargeIntField * ElementID_SOBJECT)
{
Object->ElementID_SOBJECT=ElementID_SOBJECT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprObjectImpl::get_ElementIDBASE_SOBJECT(void)
{
return Object->ElementIDBASE_SOBJECT;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_ElementIDBASE_SOBJECT(TFIBLargeIntField * ElementIDBASE_SOBJECT)
{
Object->ElementIDBASE_SOBJECT=ElementIDBASE_SOBJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprObjectImpl::get_ElementNAME_SOBJECT(void)
{
return Object->ElementNAME_SOBJECT;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_ElementNAME_SOBJECT(TFIBWideStringField * ElementNAME_SOBJECT)
{
Object->ElementNAME_SOBJECT=ElementNAME_SOBJECT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprObjectImpl::get_ElementIDINFBASE_SOBJECT(void)
{
return Object->ElementIDINFBASE_SOBJECT;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_ElementIDINFBASE_SOBJECT(TFIBLargeIntField * ElementIDINFBASE_SOBJECT)
{
Object->ElementIDINFBASE_SOBJECT=ElementIDINFBASE_SOBJECT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprObjectImpl::get_ElementIDFIRM_SOBJECT(void)
{
return Object->ElementIDFIRM_SOBJECT;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_ElementIDFIRM_SOBJECT(TFIBLargeIntField * ElementIDFIRM_SOBJECT)
{
Object->ElementIDFIRM_SOBJECT=ElementIDFIRM_SOBJECT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprObjectImpl::get_ElementIDSKLAD_SOBJECT(void)
{
return Object->ElementIDSKLAD_SOBJECT;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_ElementIDSKLAD_SOBJECT(TFIBLargeIntField * ElementIDSKLAD_SOBJECT)
{
Object->ElementIDSKLAD_SOBJECT=ElementIDSKLAD_SOBJECT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprObjectImpl::get_ElementIDKASSA_SOBJECT(void)
{
return Object->ElementIDKASSA_SOBJECT;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_ElementIDKASSA_SOBJECT(TFIBLargeIntField * ElementIDKASSA_SOBJECT)
{
Object->ElementIDKASSA_SOBJECT=ElementIDKASSA_SOBJECT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprObjectImpl::get_ElementIDPODR_SOBJECT(void)
{
return Object->ElementIDPODR_SOBJECT;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_ElementIDPODR_SOBJECT(TFIBLargeIntField * ElementIDPODR_SOBJECT)
{
Object->ElementIDPODR_SOBJECT=ElementIDPODR_SOBJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprObjectImpl::get_ElementNAME_SINFBASE_OBMEN(void)
{
return Object->ElementNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_ElementNAME_SINFBASE_OBMEN(TFIBWideStringField * ElementNAME_SINFBASE_OBMEN)
{
Object->ElementNAME_SINFBASE_OBMEN=ElementNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprObjectImpl::get_ElementNAMEFIRM(void)
{
return Object->ElementNAMEFIRM;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_ElementNAMEFIRM(TFIBWideStringField * ElementNAMEFIRM)
{
Object->ElementNAMEFIRM=ElementNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprObjectImpl::get_ElementNAMESKLAD(void)
{
return Object->ElementNAMESKLAD;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_ElementNAMESKLAD(TFIBWideStringField * ElementNAMESKLAD)
{
Object->ElementNAMESKLAD=ElementNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprObjectImpl::get_ElementNAMEKKM(void)
{
return Object->ElementNAMEKKM;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_ElementNAMEKKM(TFIBWideStringField * ElementNAMEKKM)
{
Object->ElementNAMEKKM=ElementNAMEKKM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprObjectImpl::get_ElementNAMEPOD(void)
{
return Object->ElementNAMEPOD;
}
//---------------------------------------------------------------
void TDMSprObjectImpl::set_ElementNAMEPOD(TFIBWideStringField * ElementNAMEPOD)
{
Object->ElementNAMEPOD=ElementNAMEPOD;
}
//---------------------------------------------------------------
bool TDMSprObjectImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
bool TDMSprObjectImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TDMSprObjectImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprObjectImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprObjectImpl::CloseElement(void)
{
return Object->CloseElement();
}
//---------------------------------------------------------------
bool TDMSprObjectImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TDMSprObjectImpl::GetIdElementPoName(UnicodeString   name)
{
return Object->GetIdElementPoName(name);
}
//---------------------------------------------------------------
int TDMSprObjectImpl::GetIndexInTablePoId(__int64 id_element)
{
return Object->GetIndexInTablePoId(id_element);
}
//---------------------------------------------------------------
__int64 TDMSprObjectImpl::GetIdElementPoGid(UnicodeString gid)
{
return Object->GetIdElementPoGid(gid);
}
//---------------------------------------------------------------
UnicodeString TDMSprObjectImpl::GetGidElementPoId(__int64 id)
{
return Object->GetGidElementPoId(id);
}
//---------------------------------------------------------------
