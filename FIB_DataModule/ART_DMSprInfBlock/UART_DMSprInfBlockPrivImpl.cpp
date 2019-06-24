#include "vcl.h"
#pragma hdrstop


#include "UART_DMSprInfBlockPrivImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TART_DMSprInfBlockPrivImpl::TART_DMSprInfBlockPrivImpl()           
{                                            
Object=new TART_DMSprInfBlockPriv(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TART_DMSprInfBlockPrivImpl::~TART_DMSprInfBlockPrivImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TART_DMSprInfBlockPrivImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IART_DMSprInfBlockPriv)                        
   {                                                                     
   *ppv=static_cast<IART_DMSprInfBlockPriv*> (this);                                
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
int TART_DMSprInfBlockPrivImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TART_DMSprInfBlockPrivImpl::kanRelease(void)                                  
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
int  TART_DMSprInfBlockPrivImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TART_DMSprInfBlockPrivImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TART_DMSprInfBlockPrivImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TART_DMSprInfBlockPrivImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TART_DMSprInfBlockPrivImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IART_DMSprInfBlockPriv
TDataSource * TART_DMSprInfBlockPrivImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TART_DMSprInfBlockPrivImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TART_DMSprInfBlockPrivImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TART_DMSprInfBlockPrivImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TDataSource * TART_DMSprInfBlockPrivImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TART_DMSprInfBlockPrivImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBDataSet * TART_DMSprInfBlockPrivImpl::get_GrpUser(void)
{
return Object->GrpUser;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::set_GrpUser(TpFIBDataSet * GrpUser)
{
Object->GrpUser=GrpUser;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprInfBlockPrivImpl::get_GrpUserID_SGRPUSER(void)
{
return Object->GrpUserID_SGRPUSER;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::set_GrpUserID_SGRPUSER(TFIBLargeIntField * GrpUserID_SGRPUSER)
{
Object->GrpUserID_SGRPUSER=GrpUserID_SGRPUSER;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprInfBlockPrivImpl::get_GrpUserNAME_SGRPUSER(void)
{
return Object->GrpUserNAME_SGRPUSER;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::set_GrpUserNAME_SGRPUSER(TFIBWideStringField * GrpUserNAME_SGRPUSER)
{
Object->GrpUserNAME_SGRPUSER=GrpUserNAME_SGRPUSER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprInfBlockPrivImpl::get_TableID_ART_IB_PRIV(void)
{
return Object->TableID_ART_IB_PRIV;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::set_TableID_ART_IB_PRIV(TFIBLargeIntField * TableID_ART_IB_PRIV)
{
Object->TableID_ART_IB_PRIV=TableID_ART_IB_PRIV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprInfBlockPrivImpl::get_TableIDBASE_ART_IB_PRIV(void)
{
return Object->TableIDBASE_ART_IB_PRIV;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::set_TableIDBASE_ART_IB_PRIV(TFIBLargeIntField * TableIDBASE_ART_IB_PRIV)
{
Object->TableIDBASE_ART_IB_PRIV=TableIDBASE_ART_IB_PRIV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprInfBlockPrivImpl::get_TableIDIB_ART_IB_PRIV(void)
{
return Object->TableIDIB_ART_IB_PRIV;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::set_TableIDIB_ART_IB_PRIV(TFIBLargeIntField * TableIDIB_ART_IB_PRIV)
{
Object->TableIDIB_ART_IB_PRIV=TableIDIB_ART_IB_PRIV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprInfBlockPrivImpl::get_TableIDGRPUSER_ART_IB_PRIV(void)
{
return Object->TableIDGRPUSER_ART_IB_PRIV;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::set_TableIDGRPUSER_ART_IB_PRIV(TFIBLargeIntField * TableIDGRPUSER_ART_IB_PRIV)
{
Object->TableIDGRPUSER_ART_IB_PRIV=TableIDGRPUSER_ART_IB_PRIV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TART_DMSprInfBlockPrivImpl::get_TableSEL_ART_IB_PRIV(void)
{
return Object->TableSEL_ART_IB_PRIV;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::set_TableSEL_ART_IB_PRIV(TFIBSmallIntField * TableSEL_ART_IB_PRIV)
{
Object->TableSEL_ART_IB_PRIV=TableSEL_ART_IB_PRIV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TART_DMSprInfBlockPrivImpl::get_TableINS_ART_IB_PRIV(void)
{
return Object->TableINS_ART_IB_PRIV;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::set_TableINS_ART_IB_PRIV(TFIBSmallIntField * TableINS_ART_IB_PRIV)
{
Object->TableINS_ART_IB_PRIV=TableINS_ART_IB_PRIV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TART_DMSprInfBlockPrivImpl::get_TableUPD_ART_IB_PRIV(void)
{
return Object->TableUPD_ART_IB_PRIV;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::set_TableUPD_ART_IB_PRIV(TFIBSmallIntField * TableUPD_ART_IB_PRIV)
{
Object->TableUPD_ART_IB_PRIV=TableUPD_ART_IB_PRIV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TART_DMSprInfBlockPrivImpl::get_TableDEL_ART_IB_PRIV(void)
{
return Object->TableDEL_ART_IB_PRIV;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::set_TableDEL_ART_IB_PRIV(TFIBSmallIntField * TableDEL_ART_IB_PRIV)
{
Object->TableDEL_ART_IB_PRIV=TableDEL_ART_IB_PRIV;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprInfBlockPrivImpl::get_TableNAME_SGRPUSER(void)
{
return Object->TableNAME_SGRPUSER;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::set_TableNAME_SGRPUSER(TFIBWideStringField * TableNAME_SGRPUSER)
{
Object->TableNAME_SGRPUSER=TableNAME_SGRPUSER;
}
//---------------------------------------------------------------
TStringField * TART_DMSprInfBlockPrivImpl::get_TableNAME_GRPUSER_LOOKUP(void)
{
return Object->TableNAME_GRPUSER_LOOKUP;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::set_TableNAME_GRPUSER_LOOKUP(TStringField * TableNAME_GRPUSER_LOOKUP)
{
Object->TableNAME_GRPUSER_LOOKUP=TableNAME_GRPUSER_LOOKUP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprInfBlockPrivImpl::get_ElementID_ART_IB_PRIV(void)
{
return Object->ElementID_ART_IB_PRIV;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::set_ElementID_ART_IB_PRIV(TFIBLargeIntField * ElementID_ART_IB_PRIV)
{
Object->ElementID_ART_IB_PRIV=ElementID_ART_IB_PRIV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprInfBlockPrivImpl::get_ElementIDBASE_ART_IB_PRIV(void)
{
return Object->ElementIDBASE_ART_IB_PRIV;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::set_ElementIDBASE_ART_IB_PRIV(TFIBLargeIntField * ElementIDBASE_ART_IB_PRIV)
{
Object->ElementIDBASE_ART_IB_PRIV=ElementIDBASE_ART_IB_PRIV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprInfBlockPrivImpl::get_ElementIDIB_ART_IB_PRIV(void)
{
return Object->ElementIDIB_ART_IB_PRIV;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::set_ElementIDIB_ART_IB_PRIV(TFIBLargeIntField * ElementIDIB_ART_IB_PRIV)
{
Object->ElementIDIB_ART_IB_PRIV=ElementIDIB_ART_IB_PRIV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprInfBlockPrivImpl::get_ElementIDGRPUSER_ART_IB_PRIV(void)
{
return Object->ElementIDGRPUSER_ART_IB_PRIV;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::set_ElementIDGRPUSER_ART_IB_PRIV(TFIBLargeIntField * ElementIDGRPUSER_ART_IB_PRIV)
{
Object->ElementIDGRPUSER_ART_IB_PRIV=ElementIDGRPUSER_ART_IB_PRIV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TART_DMSprInfBlockPrivImpl::get_ElementSEL_ART_IB_PRIV(void)
{
return Object->ElementSEL_ART_IB_PRIV;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::set_ElementSEL_ART_IB_PRIV(TFIBSmallIntField * ElementSEL_ART_IB_PRIV)
{
Object->ElementSEL_ART_IB_PRIV=ElementSEL_ART_IB_PRIV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TART_DMSprInfBlockPrivImpl::get_ElementINS_ART_IB_PRIV(void)
{
return Object->ElementINS_ART_IB_PRIV;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::set_ElementINS_ART_IB_PRIV(TFIBSmallIntField * ElementINS_ART_IB_PRIV)
{
Object->ElementINS_ART_IB_PRIV=ElementINS_ART_IB_PRIV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TART_DMSprInfBlockPrivImpl::get_ElementUPD_ART_IB_PRIV(void)
{
return Object->ElementUPD_ART_IB_PRIV;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::set_ElementUPD_ART_IB_PRIV(TFIBSmallIntField * ElementUPD_ART_IB_PRIV)
{
Object->ElementUPD_ART_IB_PRIV=ElementUPD_ART_IB_PRIV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TART_DMSprInfBlockPrivImpl::get_ElementDEL_ART_IB_PRIV(void)
{
return Object->ElementDEL_ART_IB_PRIV;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::set_ElementDEL_ART_IB_PRIV(TFIBSmallIntField * ElementDEL_ART_IB_PRIV)
{
Object->ElementDEL_ART_IB_PRIV=ElementDEL_ART_IB_PRIV;
}
//---------------------------------------------------------------
__int64 TART_DMSprInfBlockPrivImpl::get_IdIB(void)
{
return Object->IdIB;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::set_IdIB(__int64 IdIB)
{
Object->IdIB=IdIB;
}
//---------------------------------------------------------------
__int64 TART_DMSprInfBlockPrivImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void TART_DMSprInfBlockPrivImpl::OpenTable(__int64 id_ib)
{
return Object->OpenTable(id_ib);
}
//---------------------------------------------------------------
bool TART_DMSprInfBlockPrivImpl::SaveIsmen(void)
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
bool TART_DMSprInfBlockPrivImpl::CancelIsmen(void)
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
bool TART_DMSprInfBlockPrivImpl::TableAppend(__int64 id_ib)
{
return Object->TableAppend(id_ib);
}
//---------------------------------------------------------------
bool TART_DMSprInfBlockPrivImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
bool TART_DMSprInfBlockPrivImpl::NewElement(__int64 id_ib)
{
return Object->NewElement(id_ib);
}
//---------------------------------------------------------------
int TART_DMSprInfBlockPrivImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool TART_DMSprInfBlockPrivImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TART_DMSprInfBlockPrivImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
