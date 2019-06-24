#include <vcl.h>
#pragma hdrstop


#include "UDMSprGrpVesNomImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprGrpVesNomImpl::TDMSprGrpVesNomImpl()           
{                                            
Object=new TDMSprGrpVesNom(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprGrpVesNomImpl::~TDMSprGrpVesNomImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprGrpVesNomImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprGrpVesNomImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprGrpVesNom)                        
   {                                                                     
   *ppv=static_cast<IDMSprGrpVesNom*> (this);                                
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
int TDMSprGrpVesNomImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprGrpVesNomImpl::kanRelease(void)                                  
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
int  TDMSprGrpVesNomImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprGrpVesNomImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprGrpVesNomImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprGrpVesNomImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprGrpVesNomImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMSprGrpVesNomImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprGrpVesNomImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprGrpVesNomImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprGrpVesNomImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprGrpVesNomImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprGrpVesNomImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprGrpVesNomImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprGrpVesNomImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprGrpVesNomImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprGrpVesNomImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprGrpVesNomImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprGrpVesNomImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprGrpVesNomImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprGrpVesNomImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrpVesNomImpl::get_TableID_SGRPVESNOM(void)
{
return Object->TableID_SGRPVESNOM;
}
//---------------------------------------------------------------
void TDMSprGrpVesNomImpl::set_TableID_SGRPVESNOM(TFIBBCDField * TableID_SGRPVESNOM)
{
Object->TableID_SGRPVESNOM=TableID_SGRPVESNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrpVesNomImpl::get_TableIDGRP_SGRPVESNOM(void)
{
return Object->TableIDGRP_SGRPVESNOM;
}
//---------------------------------------------------------------
void TDMSprGrpVesNomImpl::set_TableIDGRP_SGRPVESNOM(TFIBBCDField * TableIDGRP_SGRPVESNOM)
{
Object->TableIDGRP_SGRPVESNOM=TableIDGRP_SGRPVESNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrpVesNomImpl::get_TableIDBASE_SGRPVESNOM(void)
{
return Object->TableIDBASE_SGRPVESNOM;
}
//---------------------------------------------------------------
void TDMSprGrpVesNomImpl::set_TableIDBASE_SGRPVESNOM(TFIBBCDField * TableIDBASE_SGRPVESNOM)
{
Object->TableIDBASE_SGRPVESNOM=TableIDBASE_SGRPVESNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrpVesNomImpl::get_TableIDSCALE_SGRPVESNOM(void)
{
return Object->TableIDSCALE_SGRPVESNOM;
}
//---------------------------------------------------------------
void TDMSprGrpVesNomImpl::set_TableIDSCALE_SGRPVESNOM(TFIBBCDField * TableIDSCALE_SGRPVESNOM)
{
Object->TableIDSCALE_SGRPVESNOM=TableIDSCALE_SGRPVESNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrpVesNomImpl::get_ElementID_SGRPVESNOM(void)
{
return Object->ElementID_SGRPVESNOM;
}
//---------------------------------------------------------------
void TDMSprGrpVesNomImpl::set_ElementID_SGRPVESNOM(TFIBBCDField * ElementID_SGRPVESNOM)
{
Object->ElementID_SGRPVESNOM=ElementID_SGRPVESNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrpVesNomImpl::get_ElementIDGRP_SGRPVESNOM(void)
{
return Object->ElementIDGRP_SGRPVESNOM;
}
//---------------------------------------------------------------
void TDMSprGrpVesNomImpl::set_ElementIDGRP_SGRPVESNOM(TFIBBCDField * ElementIDGRP_SGRPVESNOM)
{
Object->ElementIDGRP_SGRPVESNOM=ElementIDGRP_SGRPVESNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrpVesNomImpl::get_ElementIDBASE_SGRPVESNOM(void)
{
return Object->ElementIDBASE_SGRPVESNOM;
}
//---------------------------------------------------------------
void TDMSprGrpVesNomImpl::set_ElementIDBASE_SGRPVESNOM(TFIBBCDField * ElementIDBASE_SGRPVESNOM)
{
Object->ElementIDBASE_SGRPVESNOM=ElementIDBASE_SGRPVESNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrpVesNomImpl::get_ElementIDSCALE_SGRPVESNOM(void)
{
return Object->ElementIDSCALE_SGRPVESNOM;
}
//---------------------------------------------------------------
void TDMSprGrpVesNomImpl::set_ElementIDSCALE_SGRPVESNOM(TFIBBCDField * ElementIDSCALE_SGRPVESNOM)
{
Object->ElementIDSCALE_SGRPVESNOM=ElementIDSCALE_SGRPVESNOM;
}
//---------------------------------------------------------------
TIntegerField * TDMSprGrpVesNomImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprGrpVesNomImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpVesNomImpl::get_TableNAME_SGRPVESNOM(void)
{
return Object->TableNAME_SGRPVESNOM;
}
//---------------------------------------------------------------
void TDMSprGrpVesNomImpl::set_TableNAME_SGRPVESNOM(TFIBWideStringField * TableNAME_SGRPVESNOM)
{
Object->TableNAME_SGRPVESNOM=TableNAME_SGRPVESNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpVesNomImpl::get_ElementNAME_SGRPVESNOM(void)
{
return Object->ElementNAME_SGRPVESNOM;
}
//---------------------------------------------------------------
void TDMSprGrpVesNomImpl::set_ElementNAME_SGRPVESNOM(TFIBWideStringField * ElementNAME_SGRPVESNOM)
{
Object->ElementNAME_SGRPVESNOM=ElementNAME_SGRPVESNOM;
}
//---------------------------------------------------------------
__int64 TDMSprGrpVesNomImpl::get_IdScale(void)
{
return Object->IdScale;
}
//---------------------------------------------------------------
void TDMSprGrpVesNomImpl::set_IdScale(__int64 IdScale)
{
Object->IdScale=IdScale;
}
//---------------------------------------------------------------
void TDMSprGrpVesNomImpl::OpenTable(__int64 id_scale)
{
return Object->OpenTable(id_scale);
}
//---------------------------------------------------------------
int TDMSprGrpVesNomImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TDMSprGrpVesNomImpl::NewElement(__int64 id_scale, __int64 id_grp)
{
return Object->NewElement(id_scale, id_grp);
}
//---------------------------------------------------------------
bool TDMSprGrpVesNomImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprGrpVesNomImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
