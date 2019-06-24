#include "vcl.h"
#pragma hdrstop


#include "UDMSprNachislImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprNachislImpl::TDMSprNachislImpl()           
{                                            
Object=new TDMSprNachisl(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprNachislImpl::~TDMSprNachislImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprNachislImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprNachislImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprNachisl)                        
   {                                                                     
   *ppv=static_cast<IDMSprNachisl*> (this);                                
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
int TDMSprNachislImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprNachislImpl::kanRelease(void)                                  
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
int  TDMSprNachislImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprNachislImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprNachislImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprNachislImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprNachislImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprNachislImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprNachislImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprNachisl
TDataSource * TDMSprNachislImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprNachislImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNachislImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprNachislImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNachislImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprNachislImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprNachislImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprNachislImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprNachislImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprNachislImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNachislImpl::get_TypeNachisl(void)
{
return Object->TypeNachisl;
}
//---------------------------------------------------------------
void TDMSprNachislImpl::set_TypeNachisl(TpFIBDataSet * TypeNachisl)
{
Object->TypeNachisl=TypeNachisl;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprNachislImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprNachislImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNachislImpl::get_TypeNachislID_STNACHISL(void)
{
return Object->TypeNachislID_STNACHISL;
}
//---------------------------------------------------------------
void TDMSprNachislImpl::set_TypeNachislID_STNACHISL(TFIBLargeIntField * TypeNachislID_STNACHISL)
{
Object->TypeNachislID_STNACHISL=TypeNachislID_STNACHISL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNachislImpl::get_TypeNachislNAME_STNACHISL(void)
{
return Object->TypeNachislNAME_STNACHISL;
}
//---------------------------------------------------------------
void TDMSprNachislImpl::set_TypeNachislNAME_STNACHISL(TFIBWideStringField * TypeNachislNAME_STNACHISL)
{
Object->TypeNachislNAME_STNACHISL=TypeNachislNAME_STNACHISL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNachislImpl::get_TableID_SNACHISL(void)
{
return Object->TableID_SNACHISL;
}
//---------------------------------------------------------------
void TDMSprNachislImpl::set_TableID_SNACHISL(TFIBLargeIntField * TableID_SNACHISL)
{
Object->TableID_SNACHISL=TableID_SNACHISL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNachislImpl::get_TableIDBASE_SNACHISL(void)
{
return Object->TableIDBASE_SNACHISL;
}
//---------------------------------------------------------------
void TDMSprNachislImpl::set_TableIDBASE_SNACHISL(TFIBLargeIntField * TableIDBASE_SNACHISL)
{
Object->TableIDBASE_SNACHISL=TableIDBASE_SNACHISL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNachislImpl::get_TableGID_SNACHISL(void)
{
return Object->TableGID_SNACHISL;
}
//---------------------------------------------------------------
void TDMSprNachislImpl::set_TableGID_SNACHISL(TFIBWideStringField * TableGID_SNACHISL)
{
Object->TableGID_SNACHISL=TableGID_SNACHISL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNachislImpl::get_TableIDNOM_SNACHISL(void)
{
return Object->TableIDNOM_SNACHISL;
}
//---------------------------------------------------------------
void TDMSprNachislImpl::set_TableIDNOM_SNACHISL(TFIBLargeIntField * TableIDNOM_SNACHISL)
{
Object->TableIDNOM_SNACHISL=TableIDNOM_SNACHISL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNachislImpl::get_TableIDTNACH_SNACHISL(void)
{
return Object->TableIDTNACH_SNACHISL;
}
//---------------------------------------------------------------
void TDMSprNachislImpl::set_TableIDTNACH_SNACHISL(TFIBLargeIntField * TableIDTNACH_SNACHISL)
{
Object->TableIDTNACH_SNACHISL=TableIDTNACH_SNACHISL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNachislImpl::get_TableVALUE_SNACHISL(void)
{
return Object->TableVALUE_SNACHISL;
}
//---------------------------------------------------------------
void TDMSprNachislImpl::set_TableVALUE_SNACHISL(TFIBBCDField * TableVALUE_SNACHISL)
{
Object->TableVALUE_SNACHISL=TableVALUE_SNACHISL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNachislImpl::get_TableNAME_STNACHISL(void)
{
return Object->TableNAME_STNACHISL;
}
//---------------------------------------------------------------
void TDMSprNachislImpl::set_TableNAME_STNACHISL(TFIBWideStringField * TableNAME_STNACHISL)
{
Object->TableNAME_STNACHISL=TableNAME_STNACHISL;
}
//---------------------------------------------------------------
TStringField * TDMSprNachislImpl::get_TableNAME_TYPE_NACHISL_LOOKUP(void)
{
return Object->TableNAME_TYPE_NACHISL_LOOKUP;
}
//---------------------------------------------------------------
void TDMSprNachislImpl::set_TableNAME_TYPE_NACHISL_LOOKUP(TStringField * TableNAME_TYPE_NACHISL_LOOKUP)
{
Object->TableNAME_TYPE_NACHISL_LOOKUP=TableNAME_TYPE_NACHISL_LOOKUP;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNachislImpl::get_ElementID_SNACHISL(void)
{
return Object->ElementID_SNACHISL;
}
//---------------------------------------------------------------
void TDMSprNachislImpl::set_ElementID_SNACHISL(TFIBBCDField * ElementID_SNACHISL)
{
Object->ElementID_SNACHISL=ElementID_SNACHISL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNachislImpl::get_ElementIDBASE_SNACHISL(void)
{
return Object->ElementIDBASE_SNACHISL;
}
//---------------------------------------------------------------
void TDMSprNachislImpl::set_ElementIDBASE_SNACHISL(TFIBBCDField * ElementIDBASE_SNACHISL)
{
Object->ElementIDBASE_SNACHISL=ElementIDBASE_SNACHISL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNachislImpl::get_ElementGID_SNACHISL(void)
{
return Object->ElementGID_SNACHISL;
}
//---------------------------------------------------------------
void TDMSprNachislImpl::set_ElementGID_SNACHISL(TFIBWideStringField * ElementGID_SNACHISL)
{
Object->ElementGID_SNACHISL=ElementGID_SNACHISL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNachislImpl::get_ElementIDNOM_SNACHISL(void)
{
return Object->ElementIDNOM_SNACHISL;
}
//---------------------------------------------------------------
void TDMSprNachislImpl::set_ElementIDNOM_SNACHISL(TFIBBCDField * ElementIDNOM_SNACHISL)
{
Object->ElementIDNOM_SNACHISL=ElementIDNOM_SNACHISL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNachislImpl::get_ElementIDTNACH_SNACHISL(void)
{
return Object->ElementIDTNACH_SNACHISL;
}
//---------------------------------------------------------------
void TDMSprNachislImpl::set_ElementIDTNACH_SNACHISL(TFIBBCDField * ElementIDTNACH_SNACHISL)
{
Object->ElementIDTNACH_SNACHISL=ElementIDTNACH_SNACHISL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNachislImpl::get_ElementVALUE_SNACHISL(void)
{
return Object->ElementVALUE_SNACHISL;
}
//---------------------------------------------------------------
void TDMSprNachislImpl::set_ElementVALUE_SNACHISL(TFIBBCDField * ElementVALUE_SNACHISL)
{
Object->ElementVALUE_SNACHISL=ElementVALUE_SNACHISL;
}
//---------------------------------------------------------------
__int64 TDMSprNachislImpl::get_IdNom(void)
{
return Object->IdNom;
}
//---------------------------------------------------------------
void TDMSprNachislImpl::set_IdNom(__int64 IdNom)
{
Object->IdNom=IdNom;
}
//---------------------------------------------------------------
__int64 TDMSprNachislImpl::get_IdTypeNachisl(void)
{
return Object->IdTypeNachisl;
}
//---------------------------------------------------------------
void TDMSprNachislImpl::set_IdTypeNachisl(__int64 IdTypeNachisl)
{
Object->IdTypeNachisl=IdTypeNachisl;
}
//---------------------------------------------------------------
void TDMSprNachislImpl::OpenTable(__int64 id_nom)
{
return Object->OpenTable(id_nom);
}
//---------------------------------------------------------------
bool TDMSprNachislImpl::SaveIsmen(void)
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
void TDMSprNachislImpl::CancelIsmen(void)
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
int TDMSprNachislImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TDMSprNachislImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprNachislImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprNachislImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TDMSprNachislImpl::FindElement(__int64 id_type_nachisl, __int64 id_nom)
{
return Object->FindElement(id_type_nachisl,id_nom);
}
//---------------------------------------------------------------
