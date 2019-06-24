#include <vcl.h>
#pragma hdrstop


#include "UDMSprGrpUserImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprGrpUserImpl::TDMSprGrpUserImpl()           
{                                            
Object=new TDMSprGrpUser(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprGrpUserImpl::~TDMSprGrpUserImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprGrpUserImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprGrpUserImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprGrpUser)                        
   {                                                                     
   *ppv=static_cast<IDMSprGrpUser*> (this);                                
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
int TDMSprGrpUserImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprGrpUserImpl::kanRelease(void)
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

//---------------------------------------------------------------
int  TDMSprGrpUserImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprGrpUserImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprGrpUserImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprGrpUserImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprGrpUserImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMSprGrpUserImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprGrpUserImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprGrpUserImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprGrpUserImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprGrpUserImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprGrpUserImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprGrpUserImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprGrpUserImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprGrpUserImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprGrpUserImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprGrpUserImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprGrpUserImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprGrpUserImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprGrpUserImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprGrpUserImpl::get_TableINTERF_SGRPUSER(void)
{
return Object->TableINTERF_SGRPUSER;
}
//---------------------------------------------------------------
void TDMSprGrpUserImpl::set_TableINTERF_SGRPUSER(TFIBIntegerField * TableINTERF_SGRPUSER)
{
Object->TableINTERF_SGRPUSER=TableINTERF_SGRPUSER;
}
//---------------------------------------------------------------
TIntegerField * TDMSprGrpUserImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprGrpUserImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrpUserImpl::get_TableID_SGRPUSER(void)
{
return Object->TableID_SGRPUSER;
}
//---------------------------------------------------------------
void TDMSprGrpUserImpl::set_TableID_SGRPUSER(TFIBBCDField * TableID_SGRPUSER)
{
Object->TableID_SGRPUSER=TableID_SGRPUSER;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrpUserImpl::get_TableIDGRP_SGRPUSER(void)
{
return Object->TableIDGRP_SGRPUSER;
}
//---------------------------------------------------------------
void TDMSprGrpUserImpl::set_TableIDGRP_SGRPUSER(TFIBBCDField * TableIDGRP_SGRPUSER)
{
Object->TableIDGRP_SGRPUSER=TableIDGRP_SGRPUSER;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrpUserImpl::get_ElementID_SGRPUSER(void)
{
return Object->ElementID_SGRPUSER;
}
//---------------------------------------------------------------
void TDMSprGrpUserImpl::set_ElementID_SGRPUSER(TFIBBCDField * ElementID_SGRPUSER)
{
Object->ElementID_SGRPUSER=ElementID_SGRPUSER;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrpUserImpl::get_ElementIDGRP_SGRPUSER(void)
{
return Object->ElementIDGRP_SGRPUSER;
}
//---------------------------------------------------------------
void TDMSprGrpUserImpl::set_ElementIDGRP_SGRPUSER(TFIBBCDField * ElementIDGRP_SGRPUSER)
{
Object->ElementIDGRP_SGRPUSER=ElementIDGRP_SGRPUSER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpUserImpl::get_TableGID_SGRPUSER(void)
{
return Object->TableGID_SGRPUSER;
}
//---------------------------------------------------------------
void TDMSprGrpUserImpl::set_TableGID_SGRPUSER(TFIBWideStringField * TableGID_SGRPUSER)
{
Object->TableGID_SGRPUSER=TableGID_SGRPUSER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpUserImpl::get_TableNAME_SGRPUSER(void)
{
return Object->TableNAME_SGRPUSER;
}
//---------------------------------------------------------------
void TDMSprGrpUserImpl::set_TableNAME_SGRPUSER(TFIBWideStringField * TableNAME_SGRPUSER)
{
Object->TableNAME_SGRPUSER=TableNAME_SGRPUSER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpUserImpl::get_TableROLE_SGRPUSER(void)
{
return Object->TableROLE_SGRPUSER;
}
//---------------------------------------------------------------
void TDMSprGrpUserImpl::set_TableROLE_SGRPUSER(TFIBWideStringField * TableROLE_SGRPUSER)
{
Object->TableROLE_SGRPUSER=TableROLE_SGRPUSER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpUserImpl::get_ElementGID_SGRPUSER(void)
{
return Object->ElementGID_SGRPUSER;
}
//---------------------------------------------------------------
void TDMSprGrpUserImpl::set_ElementGID_SGRPUSER(TFIBWideStringField * ElementGID_SGRPUSER)
{
Object->ElementGID_SGRPUSER=ElementGID_SGRPUSER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpUserImpl::get_ElementNAME_SGRPUSER(void)
{
return Object->ElementNAME_SGRPUSER;
}
//---------------------------------------------------------------
void TDMSprGrpUserImpl::set_ElementNAME_SGRPUSER(TFIBWideStringField * ElementNAME_SGRPUSER)
{
Object->ElementNAME_SGRPUSER=ElementNAME_SGRPUSER;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprGrpUserImpl::get_ElementINTERF_SGRPUSER(void)
{
return Object->ElementINTERF_SGRPUSER;
}
//---------------------------------------------------------------
void TDMSprGrpUserImpl::set_ElementINTERF_SGRPUSER(TFIBSmallIntField * ElementINTERF_SGRPUSER)
{
Object->ElementINTERF_SGRPUSER=ElementINTERF_SGRPUSER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpUserImpl::get_ElementROLE_SGRPUSER(void)
{
return Object->ElementROLE_SGRPUSER;
}
//---------------------------------------------------------------
void TDMSprGrpUserImpl::set_ElementROLE_SGRPUSER(TFIBWideStringField * ElementROLE_SGRPUSER)
{
Object->ElementROLE_SGRPUSER=ElementROLE_SGRPUSER;
}
//---------------------------------------------------------------
void TDMSprGrpUserImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprGrpUserImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TDMSprGrpUserImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TDMSprGrpUserImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprGrpUserImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TDMSprGrpUserImpl::GetIDElement(String gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
