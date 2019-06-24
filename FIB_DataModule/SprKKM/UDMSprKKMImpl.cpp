#include "vcl.h"
#pragma hdrstop


#include "UDMSprKKMImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprKKMImpl::TDMSprKKMImpl()           
{                                            
Object=new TDMSprKKM(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprKKMImpl::~TDMSprKKMImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprKKMImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprKKMImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprKKM)                        
   {                                                                     
   *ppv=static_cast<IDMSprKKM*> (this);                                
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
int TDMSprKKMImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprKKMImpl::kanRelease(void)                                  
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
int  TDMSprKKMImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprKKMImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprKKMImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprKKMImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprKKMImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprKKMImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprKKMImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprKKM
TDataSource * TDMSprKKMImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprKKMImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprKKMImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprKKMImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprKKMImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprKKMImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprKKMImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprKKMImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprKKMImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprKKMImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprKKMImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprKKMImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TIntegerField * TDMSprKKMImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprKKMImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprKKMImpl::get_TableIDKKM(void)
{
return Object->TableIDKKM;
}
//---------------------------------------------------------------
void TDMSprKKMImpl::set_TableIDKKM(TFIBBCDField * TableIDKKM)
{
Object->TableIDKKM=TableIDKKM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprKKMImpl::get_ElementIDKKM(void)
{
return Object->ElementIDKKM;
}
//---------------------------------------------------------------
void TDMSprKKMImpl::set_ElementIDKKM(TFIBBCDField * ElementIDKKM)
{
Object->ElementIDKKM=ElementIDKKM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKKMImpl::get_TableNAMEKKM(void)
{
return Object->TableNAMEKKM;
}
//---------------------------------------------------------------
void TDMSprKKMImpl::set_TableNAMEKKM(TFIBWideStringField * TableNAMEKKM)
{
Object->TableNAMEKKM=TableNAMEKKM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKKMImpl::get_TableGID_SKKM(void)
{
return Object->TableGID_SKKM;
}
//---------------------------------------------------------------
void TDMSprKKMImpl::set_TableGID_SKKM(TFIBWideStringField * TableGID_SKKM)
{
Object->TableGID_SKKM=TableGID_SKKM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKKMImpl::get_TableCATOBMKKM(void)
{
return Object->TableCATOBMKKM;
}
//---------------------------------------------------------------
void TDMSprKKMImpl::set_TableCATOBMKKM(TFIBWideStringField * TableCATOBMKKM)
{
Object->TableCATOBMKKM=TableCATOBMKKM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKKMImpl::get_ElementNAMEKKM(void)
{
return Object->ElementNAMEKKM;
}
//---------------------------------------------------------------
void TDMSprKKMImpl::set_ElementNAMEKKM(TFIBWideStringField * ElementNAMEKKM)
{
Object->ElementNAMEKKM=ElementNAMEKKM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKKMImpl::get_ElementGID_SKKM(void)
{
return Object->ElementGID_SKKM;
}
//---------------------------------------------------------------
void TDMSprKKMImpl::set_ElementGID_SKKM(TFIBWideStringField * ElementGID_SKKM)
{
Object->ElementGID_SKKM=ElementGID_SKKM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKKMImpl::get_ElementCATOBMKKM(void)
{
return Object->ElementCATOBMKKM;
}
//---------------------------------------------------------------
void TDMSprKKMImpl::set_ElementCATOBMKKM(TFIBWideStringField * ElementCATOBMKKM)
{
Object->ElementCATOBMKKM=ElementCATOBMKKM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKKMImpl::get_ElementPREFIKS_NUM_SKKM(void)
{
return Object->ElementPREFIKS_NUM_SKKM;
}
//---------------------------------------------------------------
void TDMSprKKMImpl::set_ElementPREFIKS_NUM_SKKM(TFIBWideStringField * ElementPREFIKS_NUM_SKKM)
{
Object->ElementPREFIKS_NUM_SKKM=ElementPREFIKS_NUM_SKKM;
}
//---------------------------------------------------------------
void TDMSprKKMImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprKKMImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
void TDMSprKKMImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprKKMImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprKKMImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
AnsiString TDMSprKKMImpl::GetGIDElement(__int64 id)
{
return Object->GetGIDElement(id);
}
//---------------------------------------------------------------
