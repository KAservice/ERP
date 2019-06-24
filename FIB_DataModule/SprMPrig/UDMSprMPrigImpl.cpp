#include <vcl.h>
#pragma hdrstop


#include "UDMSprMPrigImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprMPrigImpl::TDMSprMPrigImpl()           
{                                            
Object=new TDMSprMPrig(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprMPrigImpl::~TDMSprMPrigImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprMPrigImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprMPrigImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprMPrig)                        
   {                                                                     
   *ppv=static_cast<IDMSprMPrig*> (this);                                
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
int TDMSprMPrigImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprMPrigImpl::kanRelease(void)
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
int  TDMSprMPrigImpl::get_CodeError(void)
{
return Object->CodeError;
}
//---------------------------------------------------------------
void TDMSprMPrigImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprMPrigImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprMPrigImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprMPrigImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMSprMPrigImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprMPrigImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprMPrigImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprMPrigImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprMPrigImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprMPrigImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprMPrigImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprMPrigImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprMPrigImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprMPrigImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprMPrigImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprMPrigImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprMPrigImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprMPrigImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMSprMPrigImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprMPrigImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprMPrigImpl::get_TableID_MPRIG(void)
{
return Object->TableID_MPRIG;
}
//---------------------------------------------------------------
void TDMSprMPrigImpl::set_TableID_MPRIG(TFIBBCDField * TableID_MPRIG)
{
Object->TableID_MPRIG=TableID_MPRIG;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprMPrigImpl::get_TableIDSKLAD_MPRIG(void)
{
return Object->TableIDSKLAD_MPRIG;
}
//---------------------------------------------------------------
void TDMSprMPrigImpl::set_TableIDSKLAD_MPRIG(TFIBBCDField * TableIDSKLAD_MPRIG)
{
Object->TableIDSKLAD_MPRIG=TableIDSKLAD_MPRIG;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprMPrigImpl::get_TableIDOBORUD_MPRIG(void)
{
return Object->TableIDOBORUD_MPRIG;
}
//---------------------------------------------------------------
void TDMSprMPrigImpl::set_TableIDOBORUD_MPRIG(TFIBBCDField * TableIDOBORUD_MPRIG)
{
Object->TableIDOBORUD_MPRIG=TableIDOBORUD_MPRIG;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprMPrigImpl::get_ElementID_MPRIG(void)
{
return Object->ElementID_MPRIG;
}
//---------------------------------------------------------------
void TDMSprMPrigImpl::set_ElementID_MPRIG(TFIBBCDField * ElementID_MPRIG)
{
Object->ElementID_MPRIG=ElementID_MPRIG;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprMPrigImpl::get_ElementIDSKLAD_MPRIG(void)
{
return Object->ElementIDSKLAD_MPRIG;
}
//---------------------------------------------------------------
void TDMSprMPrigImpl::set_ElementIDSKLAD_MPRIG(TFIBBCDField * ElementIDSKLAD_MPRIG)
{
Object->ElementIDSKLAD_MPRIG=ElementIDSKLAD_MPRIG;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprMPrigImpl::get_ElementIDOBORUD_MPRIG(void)
{
return Object->ElementIDOBORUD_MPRIG;
}
//---------------------------------------------------------------
void TDMSprMPrigImpl::set_ElementIDOBORUD_MPRIG(TFIBBCDField * ElementIDOBORUD_MPRIG)
{
Object->ElementIDOBORUD_MPRIG=ElementIDOBORUD_MPRIG;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprMPrigImpl::get_TableIDBASE_SMPRIG(void)
{
return Object->TableIDBASE_SMPRIG;
}
//---------------------------------------------------------------
void TDMSprMPrigImpl::set_TableIDBASE_SMPRIG(TFIBBCDField * TableIDBASE_SMPRIG)
{
Object->TableIDBASE_SMPRIG=TableIDBASE_SMPRIG;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprMPrigImpl::get_ElementIDBASE_SMPRIG(void)
{
return Object->ElementIDBASE_SMPRIG;
}
//---------------------------------------------------------------
void TDMSprMPrigImpl::set_ElementIDBASE_SMPRIG(TFIBBCDField * ElementIDBASE_SMPRIG)
{
Object->ElementIDBASE_SMPRIG=ElementIDBASE_SMPRIG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprMPrigImpl::get_TableNAME_MPRIG(void)
{
return Object->TableNAME_MPRIG;
}
//---------------------------------------------------------------
void TDMSprMPrigImpl::set_TableNAME_MPRIG(TFIBWideStringField * TableNAME_MPRIG)
{
Object->TableNAME_MPRIG=TableNAME_MPRIG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprMPrigImpl::get_TableGID_SMPRIG(void)
{
return Object->TableGID_SMPRIG;
}
//---------------------------------------------------------------
void TDMSprMPrigImpl::set_TableGID_SMPRIG(TFIBWideStringField * TableGID_SMPRIG)
{
Object->TableGID_SMPRIG=TableGID_SMPRIG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprMPrigImpl::get_TableNAMESKLAD(void)
{
return Object->TableNAMESKLAD;
}
//---------------------------------------------------------------
void TDMSprMPrigImpl::set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)
{
Object->TableNAMESKLAD=TableNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprMPrigImpl::get_TableNAME_OBORUD(void)
{
return Object->TableNAME_OBORUD;
}
//---------------------------------------------------------------
void TDMSprMPrigImpl::set_TableNAME_OBORUD(TFIBWideStringField * TableNAME_OBORUD)
{
Object->TableNAME_OBORUD=TableNAME_OBORUD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprMPrigImpl::get_ElementNAME_MPRIG(void)
{
return Object->ElementNAME_MPRIG;
}
//---------------------------------------------------------------
void TDMSprMPrigImpl::set_ElementNAME_MPRIG(TFIBWideStringField * ElementNAME_MPRIG)
{
Object->ElementNAME_MPRIG=ElementNAME_MPRIG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprMPrigImpl::get_ElementGID_SMPRIG(void)
{
return Object->ElementGID_SMPRIG;
}
//---------------------------------------------------------------
void TDMSprMPrigImpl::set_ElementGID_SMPRIG(TFIBWideStringField * ElementGID_SMPRIG)
{
Object->ElementGID_SMPRIG=ElementGID_SMPRIG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprMPrigImpl::get_ElementNAMESKLAD(void)
{
return Object->ElementNAMESKLAD;
}
//---------------------------------------------------------------
void TDMSprMPrigImpl::set_ElementNAMESKLAD(TFIBWideStringField * ElementNAMESKLAD)
{
Object->ElementNAMESKLAD=ElementNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprMPrigImpl::get_ElementNAME_OBORUD(void)
{
return Object->ElementNAME_OBORUD;
}
//---------------------------------------------------------------
void TDMSprMPrigImpl::set_ElementNAME_OBORUD(TFIBWideStringField * ElementNAME_OBORUD)
{
Object->ElementNAME_OBORUD=ElementNAME_OBORUD;
}
//---------------------------------------------------------------
void TDMSprMPrigImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprMPrigImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
void TDMSprMPrigImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprMPrigImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprMPrigImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
