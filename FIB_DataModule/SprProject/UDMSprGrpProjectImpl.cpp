#include <vcl.h>
#pragma hdrstop


#include "UDMSprGrpProjectImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprGrpProjectImpl::TDMSprGrpProjectImpl()           
{                                            
Object=new TDMSprGrpProject(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprGrpProjectImpl::~TDMSprGrpProjectImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprGrpProjectImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprGrpProjectImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprGrpProject)                        
   {                                                                     
   *ppv=static_cast<IDMSprGrpProject*> (this);                                
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
int TDMSprGrpProjectImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprGrpProjectImpl::kanRelease(void)                                  
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
int  TDMSprGrpProjectImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprGrpProjectImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprGrpProjectImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprGrpProjectImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprGrpProjectImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMSprGrpProjectImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprGrpProjectImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprGrpProjectImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprGrpProjectImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprGrpProjectImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprGrpProjectImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprGrpProjectImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprGrpProjectImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprGrpProjectImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprGrpProjectImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprGrpProjectImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprGrpProjectImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprGrpProjectImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprGrpProjectImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprGrpProjectImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprGrpProjectImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrpProjectImpl::get_TableID_SGRPPROJECT(void)
{
return Object->TableID_SGRPPROJECT;
}
//---------------------------------------------------------------
void TDMSprGrpProjectImpl::set_TableID_SGRPPROJECT(TFIBBCDField * TableID_SGRPPROJECT)
{
Object->TableID_SGRPPROJECT=TableID_SGRPPROJECT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrpProjectImpl::get_TableIDGRP_SGRPPROJECT(void)
{
return Object->TableIDGRP_SGRPPROJECT;
}
//---------------------------------------------------------------
void TDMSprGrpProjectImpl::set_TableIDGRP_SGRPPROJECT(TFIBBCDField * TableIDGRP_SGRPPROJECT)
{
Object->TableIDGRP_SGRPPROJECT=TableIDGRP_SGRPPROJECT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrpProjectImpl::get_ElementID_SGRPPROJECT(void)
{
return Object->ElementID_SGRPPROJECT;
}
//---------------------------------------------------------------
void TDMSprGrpProjectImpl::set_ElementID_SGRPPROJECT(TFIBBCDField * ElementID_SGRPPROJECT)
{
Object->ElementID_SGRPPROJECT=ElementID_SGRPPROJECT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrpProjectImpl::get_ElementIDGRP_SGRPPROJECT(void)
{
return Object->ElementIDGRP_SGRPPROJECT;
}
//---------------------------------------------------------------
void TDMSprGrpProjectImpl::set_ElementIDGRP_SGRPPROJECT(TFIBBCDField * ElementIDGRP_SGRPPROJECT)
{
Object->ElementIDGRP_SGRPPROJECT=ElementIDGRP_SGRPPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpProjectImpl::get_TableNAME_SGRPPROJECT(void)
{
return Object->TableNAME_SGRPPROJECT;
}
//---------------------------------------------------------------
void TDMSprGrpProjectImpl::set_TableNAME_SGRPPROJECT(TFIBWideStringField * TableNAME_SGRPPROJECT)
{
Object->TableNAME_SGRPPROJECT=TableNAME_SGRPPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpProjectImpl::get_ElementNAME_SGRPPROJECT(void)
{
return Object->ElementNAME_SGRPPROJECT;
}
//---------------------------------------------------------------
void TDMSprGrpProjectImpl::set_ElementNAME_SGRPPROJECT(TFIBWideStringField * ElementNAME_SGRPPROJECT)
{
Object->ElementNAME_SGRPPROJECT=ElementNAME_SGRPPROJECT;
}
//---------------------------------------------------------------
void TDMSprGrpProjectImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprGrpProjectImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TDMSprGrpProjectImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TDMSprGrpProjectImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprGrpProjectImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TDMSprGrpProjectImpl::FindPoName(AnsiString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
