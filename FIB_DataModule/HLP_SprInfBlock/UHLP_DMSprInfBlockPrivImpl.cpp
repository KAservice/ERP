#include "vcl.h"
#pragma hdrstop


#include "UHLP_DMSprInfBlockPrivImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THLP_DMSprInfBlockPrivImpl::THLP_DMSprInfBlockPrivImpl()           
{                                            
Object=new THLP_DMSprInfBlockPriv(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THLP_DMSprInfBlockPrivImpl::~THLP_DMSprInfBlockPrivImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THLP_DMSprInfBlockPrivImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHLP_DMSprInfBlockPriv)                        
   {                                                                     
   *ppv=static_cast<IHLP_DMSprInfBlockPriv*> (this);                                
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
int THLP_DMSprInfBlockPrivImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THLP_DMSprInfBlockPrivImpl::kanRelease(void)                                  
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
int  THLP_DMSprInfBlockPrivImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THLP_DMSprInfBlockPrivImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THLP_DMSprInfBlockPrivImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_THLP_DMSprInfBlockPrivImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THLP_DMSprInfBlockPrivImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IHLP_DMSprInfBlockPriv
TDataSource * THLP_DMSprInfBlockPrivImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * THLP_DMSprInfBlockPrivImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * THLP_DMSprInfBlockPrivImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * THLP_DMSprInfBlockPrivImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TDataSource * THLP_DMSprInfBlockPrivImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * THLP_DMSprInfBlockPrivImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprInfBlockPrivImpl::get_TableID_HLP_IB_PRIV(void)
{
return Object->TableID_HLP_IB_PRIV;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::set_TableID_HLP_IB_PRIV(TFIBLargeIntField * TableID_HLP_IB_PRIV)
{
Object->TableID_HLP_IB_PRIV=TableID_HLP_IB_PRIV;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprInfBlockPrivImpl::get_TableIDBASE_HLP_IB_PRIV(void)
{
return Object->TableIDBASE_HLP_IB_PRIV;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::set_TableIDBASE_HLP_IB_PRIV(TFIBLargeIntField * TableIDBASE_HLP_IB_PRIV)
{
Object->TableIDBASE_HLP_IB_PRIV=TableIDBASE_HLP_IB_PRIV;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprInfBlockPrivImpl::get_TableIDIB_HLP_IB_PRIV(void)
{
return Object->TableIDIB_HLP_IB_PRIV;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::set_TableIDIB_HLP_IB_PRIV(TFIBLargeIntField * TableIDIB_HLP_IB_PRIV)
{
Object->TableIDIB_HLP_IB_PRIV=TableIDIB_HLP_IB_PRIV;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprInfBlockPrivImpl::get_TableIDGRPUSER_HLP_IB_PRIV(void)
{
return Object->TableIDGRPUSER_HLP_IB_PRIV;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::set_TableIDGRPUSER_HLP_IB_PRIV(TFIBLargeIntField * TableIDGRPUSER_HLP_IB_PRIV)
{
Object->TableIDGRPUSER_HLP_IB_PRIV=TableIDGRPUSER_HLP_IB_PRIV;
}
//---------------------------------------------------------------
TFIBSmallIntField * THLP_DMSprInfBlockPrivImpl::get_TableSEL_HLP_IB_PRIV(void)
{
return Object->TableSEL_HLP_IB_PRIV;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::set_TableSEL_HLP_IB_PRIV(TFIBSmallIntField * TableSEL_HLP_IB_PRIV)
{
Object->TableSEL_HLP_IB_PRIV=TableSEL_HLP_IB_PRIV;
}
//---------------------------------------------------------------
TFIBSmallIntField * THLP_DMSprInfBlockPrivImpl::get_TableINS_HLP_IB_PRIV(void)
{
return Object->TableINS_HLP_IB_PRIV;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::set_TableINS_HLP_IB_PRIV(TFIBSmallIntField * TableINS_HLP_IB_PRIV)
{
Object->TableINS_HLP_IB_PRIV=TableINS_HLP_IB_PRIV;
}
//---------------------------------------------------------------
TFIBSmallIntField * THLP_DMSprInfBlockPrivImpl::get_TableUPD_HLP_IB_PRIV(void)
{
return Object->TableUPD_HLP_IB_PRIV;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::set_TableUPD_HLP_IB_PRIV(TFIBSmallIntField * TableUPD_HLP_IB_PRIV)
{
Object->TableUPD_HLP_IB_PRIV=TableUPD_HLP_IB_PRIV;
}
//---------------------------------------------------------------
TFIBSmallIntField * THLP_DMSprInfBlockPrivImpl::get_TableDEL_HLP_IB_PRIV(void)
{
return Object->TableDEL_HLP_IB_PRIV;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::set_TableDEL_HLP_IB_PRIV(TFIBSmallIntField * TableDEL_HLP_IB_PRIV)
{
Object->TableDEL_HLP_IB_PRIV=TableDEL_HLP_IB_PRIV;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockPrivImpl::get_TableNAME_SGRPUSER(void)
{
return Object->TableNAME_SGRPUSER;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::set_TableNAME_SGRPUSER(TFIBWideStringField * TableNAME_SGRPUSER)
{
Object->TableNAME_SGRPUSER=TableNAME_SGRPUSER;
}
//---------------------------------------------------------------
TpFIBDataSet * THLP_DMSprInfBlockPrivImpl::get_GrpUser(void)
{
return Object->GrpUser;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::set_GrpUser(TpFIBDataSet * GrpUser)
{
Object->GrpUser=GrpUser;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprInfBlockPrivImpl::get_GrpUserID_SGRPUSER(void)
{
return Object->GrpUserID_SGRPUSER;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::set_GrpUserID_SGRPUSER(TFIBLargeIntField * GrpUserID_SGRPUSER)
{
Object->GrpUserID_SGRPUSER=GrpUserID_SGRPUSER;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprInfBlockPrivImpl::get_GrpUserNAME_SGRPUSER(void)
{
return Object->GrpUserNAME_SGRPUSER;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::set_GrpUserNAME_SGRPUSER(TFIBWideStringField * GrpUserNAME_SGRPUSER)
{
Object->GrpUserNAME_SGRPUSER=GrpUserNAME_SGRPUSER;
}
//---------------------------------------------------------------
TStringField * THLP_DMSprInfBlockPrivImpl::get_TableNAME_GRP_USER_LOOKUP(void)
{
return Object->TableNAME_GRP_USER_LOOKUP;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::set_TableNAME_GRP_USER_LOOKUP(TStringField * TableNAME_GRP_USER_LOOKUP)
{
Object->TableNAME_GRP_USER_LOOKUP=TableNAME_GRP_USER_LOOKUP;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprInfBlockPrivImpl::get_ElementID_HLP_IB_PRIV(void)
{
return Object->ElementID_HLP_IB_PRIV;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::set_ElementID_HLP_IB_PRIV(TFIBLargeIntField * ElementID_HLP_IB_PRIV)
{
Object->ElementID_HLP_IB_PRIV=ElementID_HLP_IB_PRIV;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprInfBlockPrivImpl::get_ElementIDBASE_HLP_IB_PRIV(void)
{
return Object->ElementIDBASE_HLP_IB_PRIV;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::set_ElementIDBASE_HLP_IB_PRIV(TFIBLargeIntField * ElementIDBASE_HLP_IB_PRIV)
{
Object->ElementIDBASE_HLP_IB_PRIV=ElementIDBASE_HLP_IB_PRIV;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprInfBlockPrivImpl::get_ElementIDIB_HLP_IB_PRIV(void)
{
return Object->ElementIDIB_HLP_IB_PRIV;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::set_ElementIDIB_HLP_IB_PRIV(TFIBLargeIntField * ElementIDIB_HLP_IB_PRIV)
{
Object->ElementIDIB_HLP_IB_PRIV=ElementIDIB_HLP_IB_PRIV;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprInfBlockPrivImpl::get_ElementIDGRPUSER_HLP_IB_PRIV(void)
{
return Object->ElementIDGRPUSER_HLP_IB_PRIV;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::set_ElementIDGRPUSER_HLP_IB_PRIV(TFIBLargeIntField * ElementIDGRPUSER_HLP_IB_PRIV)
{
Object->ElementIDGRPUSER_HLP_IB_PRIV=ElementIDGRPUSER_HLP_IB_PRIV;
}
//---------------------------------------------------------------
TFIBSmallIntField * THLP_DMSprInfBlockPrivImpl::get_ElementSEL_HLP_IB_PRIV(void)
{
return Object->ElementSEL_HLP_IB_PRIV;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::set_ElementSEL_HLP_IB_PRIV(TFIBSmallIntField * ElementSEL_HLP_IB_PRIV)
{
Object->ElementSEL_HLP_IB_PRIV=ElementSEL_HLP_IB_PRIV;
}
//---------------------------------------------------------------
TFIBSmallIntField * THLP_DMSprInfBlockPrivImpl::get_ElementINS_HLP_IB_PRIV(void)
{
return Object->ElementINS_HLP_IB_PRIV;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::set_ElementINS_HLP_IB_PRIV(TFIBSmallIntField * ElementINS_HLP_IB_PRIV)
{
Object->ElementINS_HLP_IB_PRIV=ElementINS_HLP_IB_PRIV;
}
//---------------------------------------------------------------
TFIBSmallIntField * THLP_DMSprInfBlockPrivImpl::get_ElementUPD_HLP_IB_PRIV(void)
{
return Object->ElementUPD_HLP_IB_PRIV;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::set_ElementUPD_HLP_IB_PRIV(TFIBSmallIntField * ElementUPD_HLP_IB_PRIV)
{
Object->ElementUPD_HLP_IB_PRIV=ElementUPD_HLP_IB_PRIV;
}
//---------------------------------------------------------------
TFIBSmallIntField * THLP_DMSprInfBlockPrivImpl::get_ElementDEL_HLP_IB_PRIV(void)
{
return Object->ElementDEL_HLP_IB_PRIV;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::set_ElementDEL_HLP_IB_PRIV(TFIBSmallIntField * ElementDEL_HLP_IB_PRIV)
{
Object->ElementDEL_HLP_IB_PRIV=ElementDEL_HLP_IB_PRIV;
}
//---------------------------------------------------------------
__int64 THLP_DMSprInfBlockPrivImpl::get_IdIB(void)
{
return Object->IdIB;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::set_IdIB(__int64 IdIB)
{
Object->IdIB=IdIB;
}
//---------------------------------------------------------------
__int64 THLP_DMSprInfBlockPrivImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void THLP_DMSprInfBlockPrivImpl::OpenTable(__int64 id_ib)
{
return Object->OpenTable(id_ib);
}
//---------------------------------------------------------------
bool THLP_DMSprInfBlockPrivImpl::SaveIsmen(void)
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
bool THLP_DMSprInfBlockPrivImpl::CancelIsmen(void)
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
bool THLP_DMSprInfBlockPrivImpl::TableAppend(__int64 id_ib)
{
return Object->TableAppend(id_ib);
}
//---------------------------------------------------------------
bool THLP_DMSprInfBlockPrivImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
bool THLP_DMSprInfBlockPrivImpl::NewElement(__int64 id_ib)
{
return Object->NewElement(id_ib);
}
//---------------------------------------------------------------
int THLP_DMSprInfBlockPrivImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool THLP_DMSprInfBlockPrivImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool THLP_DMSprInfBlockPrivImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
