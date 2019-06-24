#include <vcl.h>
#pragma hdrstop


#include "UDMSprScaleImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprScaleImpl::TDMSprScaleImpl()           
{                                            
Object=new TDMSprScale(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprScaleImpl::~TDMSprScaleImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprScaleImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprScaleImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprScale)                        
   {                                                                     
   *ppv=static_cast<IDMSprScale*> (this);                                
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
int TDMSprScaleImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprScaleImpl::kanRelease(void)                                  
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
int  TDMSprScaleImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprScaleImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprScaleImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprScaleImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprScaleImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMSprScaleImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprScaleImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprScaleImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprScaleImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprScaleImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprScaleImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprScaleImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprScaleImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprScaleImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprScaleImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprScaleImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprScaleImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprScaleImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprScaleImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMSprScaleImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprScaleImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprScaleImpl::get_ElementID_SSCALE(void)
{
return Object->ElementID_SSCALE;
}
//---------------------------------------------------------------
void TDMSprScaleImpl::set_ElementID_SSCALE(TFIBBCDField * ElementID_SSCALE)
{
Object->ElementID_SSCALE=ElementID_SSCALE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprScaleImpl::get_TableID_SSCALE(void)
{
return Object->TableID_SSCALE;
}
//---------------------------------------------------------------
void TDMSprScaleImpl::set_TableID_SSCALE(TFIBBCDField * TableID_SSCALE)
{
Object->TableID_SSCALE=TableID_SSCALE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprScaleImpl::get_TableGID_SSCALE(void)
{
return Object->TableGID_SSCALE;
}
//---------------------------------------------------------------
void TDMSprScaleImpl::set_TableGID_SSCALE(TFIBWideStringField * TableGID_SSCALE)
{
Object->TableGID_SSCALE=TableGID_SSCALE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprScaleImpl::get_TableNAME_SSCALE(void)
{
return Object->TableNAME_SSCALE;
}
//---------------------------------------------------------------
void TDMSprScaleImpl::set_TableNAME_SSCALE(TFIBWideStringField * TableNAME_SSCALE)
{
Object->TableNAME_SSCALE=TableNAME_SSCALE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprScaleImpl::get_ElementGID_SSCALE(void)
{
return Object->ElementGID_SSCALE;
}
//---------------------------------------------------------------
void TDMSprScaleImpl::set_ElementGID_SSCALE(TFIBWideStringField * ElementGID_SSCALE)
{
Object->ElementGID_SSCALE=ElementGID_SSCALE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprScaleImpl::get_ElementNAME_SSCALE(void)
{
return Object->ElementNAME_SSCALE;
}
//---------------------------------------------------------------
void TDMSprScaleImpl::set_ElementNAME_SSCALE(TFIBWideStringField * ElementNAME_SSCALE)
{
Object->ElementNAME_SSCALE=ElementNAME_SSCALE;
}
//---------------------------------------------------------------
void TDMSprScaleImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprScaleImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TDMSprScaleImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprScaleImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprScaleImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TDMSprScaleImpl::GetIDElement(String gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
