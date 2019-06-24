#include "vcl.h"
#pragma hdrstop


#include "UDMSprStorageLocationImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprStorageLocationImpl::TDMSprStorageLocationImpl()           
{                                            
Object=new TDMSprStorageLocation(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprStorageLocationImpl::~TDMSprStorageLocationImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprStorageLocationImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprStorageLocationImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprStorageLocation)                        
   {                                                                     
   *ppv=static_cast<IDMSprStorageLocation*> (this);                                
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
int TDMSprStorageLocationImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprStorageLocationImpl::kanRelease(void)                                  
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
int  TDMSprStorageLocationImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprStorageLocationImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprStorageLocationImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprStorageLocationImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprStorageLocationImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprStorageLocationImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprStorageLocationImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprStorageLocation
TDataSource * TDMSprStorageLocationImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprStorageLocationImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprStorageLocationImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprStorageLocationImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprStorageLocationImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprStorageLocationImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprStorageLocationImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprStorageLocationImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprStorageLocationImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprStorageLocationImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprStorageLocationImpl::get_TableID_SMHRAN(void)
{
return Object->TableID_SMHRAN;
}
//---------------------------------------------------------------
void TDMSprStorageLocationImpl::set_TableID_SMHRAN(TFIBLargeIntField * TableID_SMHRAN)
{
Object->TableID_SMHRAN=TableID_SMHRAN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprStorageLocationImpl::get_TableIDBASE_SMHRAN(void)
{
return Object->TableIDBASE_SMHRAN;
}
//---------------------------------------------------------------
void TDMSprStorageLocationImpl::set_TableIDBASE_SMHRAN(TFIBLargeIntField * TableIDBASE_SMHRAN)
{
Object->TableIDBASE_SMHRAN=TableIDBASE_SMHRAN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprStorageLocationImpl::get_TableIDGRP_SMHRAN(void)
{
return Object->TableIDGRP_SMHRAN;
}
//---------------------------------------------------------------
void TDMSprStorageLocationImpl::set_TableIDGRP_SMHRAN(TFIBLargeIntField * TableIDGRP_SMHRAN)
{
Object->TableIDGRP_SMHRAN=TableIDGRP_SMHRAN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprStorageLocationImpl::get_TableNAME_SMHRAN(void)
{
return Object->TableNAME_SMHRAN;
}
//---------------------------------------------------------------
void TDMSprStorageLocationImpl::set_TableNAME_SMHRAN(TFIBWideStringField * TableNAME_SMHRAN)
{
Object->TableNAME_SMHRAN=TableNAME_SMHRAN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprStorageLocationImpl::get_TableIDSKLAD_SMHRAN(void)
{
return Object->TableIDSKLAD_SMHRAN;
}
//---------------------------------------------------------------
void TDMSprStorageLocationImpl::set_TableIDSKLAD_SMHRAN(TFIBLargeIntField * TableIDSKLAD_SMHRAN)
{
Object->TableIDSKLAD_SMHRAN=TableIDSKLAD_SMHRAN;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprStorageLocationImpl::get_TableFL_DOSTUPNO_SMHRAN(void)
{
return Object->TableFL_DOSTUPNO_SMHRAN;
}
//---------------------------------------------------------------
void TDMSprStorageLocationImpl::set_TableFL_DOSTUPNO_SMHRAN(TFIBSmallIntField * TableFL_DOSTUPNO_SMHRAN)
{
Object->TableFL_DOSTUPNO_SMHRAN=TableFL_DOSTUPNO_SMHRAN;
}
//---------------------------------------------------------------
TDataSource * TDMSprStorageLocationImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprStorageLocationImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprStorageLocationImpl::get_ElementID_SMHRAN(void)
{
return Object->ElementID_SMHRAN;
}
//---------------------------------------------------------------
void TDMSprStorageLocationImpl::set_ElementID_SMHRAN(TFIBLargeIntField * ElementID_SMHRAN)
{
Object->ElementID_SMHRAN=ElementID_SMHRAN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprStorageLocationImpl::get_ElementIDBASE_SMHRAN(void)
{
return Object->ElementIDBASE_SMHRAN;
}
//---------------------------------------------------------------
void TDMSprStorageLocationImpl::set_ElementIDBASE_SMHRAN(TFIBLargeIntField * ElementIDBASE_SMHRAN)
{
Object->ElementIDBASE_SMHRAN=ElementIDBASE_SMHRAN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprStorageLocationImpl::get_ElementIDGRP_SMHRAN(void)
{
return Object->ElementIDGRP_SMHRAN;
}
//---------------------------------------------------------------
void TDMSprStorageLocationImpl::set_ElementIDGRP_SMHRAN(TFIBLargeIntField * ElementIDGRP_SMHRAN)
{
Object->ElementIDGRP_SMHRAN=ElementIDGRP_SMHRAN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprStorageLocationImpl::get_ElementNAME_SMHRAN(void)
{
return Object->ElementNAME_SMHRAN;
}
//---------------------------------------------------------------
void TDMSprStorageLocationImpl::set_ElementNAME_SMHRAN(TFIBWideStringField * ElementNAME_SMHRAN)
{
Object->ElementNAME_SMHRAN=ElementNAME_SMHRAN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprStorageLocationImpl::get_ElementIDSKLAD_SMHRAN(void)
{
return Object->ElementIDSKLAD_SMHRAN;
}
//---------------------------------------------------------------
void TDMSprStorageLocationImpl::set_ElementIDSKLAD_SMHRAN(TFIBLargeIntField * ElementIDSKLAD_SMHRAN)
{
Object->ElementIDSKLAD_SMHRAN=ElementIDSKLAD_SMHRAN;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprStorageLocationImpl::get_ElementFL_DOSTUPNO_SMHRAN(void)
{
return Object->ElementFL_DOSTUPNO_SMHRAN;
}
//---------------------------------------------------------------
void TDMSprStorageLocationImpl::set_ElementFL_DOSTUPNO_SMHRAN(TFIBSmallIntField * ElementFL_DOSTUPNO_SMHRAN)
{
Object->ElementFL_DOSTUPNO_SMHRAN=ElementFL_DOSTUPNO_SMHRAN;
}
//---------------------------------------------------------------
__int64 TDMSprStorageLocationImpl::get_IdSklad(void)
{
return Object->IdSklad;
}
//---------------------------------------------------------------
void TDMSprStorageLocationImpl::set_IdSklad(__int64 IdSklad)
{
Object->IdSklad=IdSklad;
}
//---------------------------------------------------------------
__int64 TDMSprStorageLocationImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMSprStorageLocationImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TDMSprStorageLocationImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TDMSprStorageLocationImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
bool TDMSprStorageLocationImpl::OpenTable(__int64 id_sklad, __int64 id_grp,bool all)
{
return Object->OpenTable(id_sklad, id_grp,all);
}
//---------------------------------------------------------------
bool TDMSprStorageLocationImpl::NewElement(__int64 id_sklad, __int64 id_grp)
{
return Object->NewElement(id_sklad,  id_grp);
}
//---------------------------------------------------------------
bool TDMSprStorageLocationImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TDMSprStorageLocationImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
bool TDMSprStorageLocationImpl::ChangeGrp(__int64 id_new_grp,__int64 id_mhran)
{
return Object->ChangeGrp(id_new_grp, id_mhran);
}
//---------------------------------------------------------------
bool TDMSprStorageLocationImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
