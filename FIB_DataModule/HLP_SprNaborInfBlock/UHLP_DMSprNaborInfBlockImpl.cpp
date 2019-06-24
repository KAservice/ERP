#include "vcl.h"
#pragma hdrstop


#include "UHLP_DMSprNaborInfBlockImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THLP_DMSprNaborInfBlockImpl::THLP_DMSprNaborInfBlockImpl()           
{                                            
Object=new THLP_DMSprNaborInfBlock(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THLP_DMSprNaborInfBlockImpl::~THLP_DMSprNaborInfBlockImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THLP_DMSprNaborInfBlockImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHLP_DMSprNaborInfBlock)                        
   {                                                                     
   *ppv=static_cast<IHLP_DMSprNaborInfBlock*> (this);                                
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
int THLP_DMSprNaborInfBlockImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THLP_DMSprNaborInfBlockImpl::kanRelease(void)                                  
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
int  THLP_DMSprNaborInfBlockImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THLP_DMSprNaborInfBlockImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THLP_DMSprNaborInfBlockImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_THLP_DMSprNaborInfBlockImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THLP_DMSprNaborInfBlockImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IHLP_DMSprNaborInfBlock
TDataSource * THLP_DMSprNaborInfBlockImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * THLP_DMSprNaborInfBlockImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * THLP_DMSprNaborInfBlockImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * THLP_DMSprNaborInfBlockImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * THLP_DMSprNaborInfBlockImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * THLP_DMSprNaborInfBlockImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * THLP_DMSprNaborInfBlockImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprNaborInfBlockImpl::get_TableID_HLP_N_IB(void)
{
return Object->TableID_HLP_N_IB;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockImpl::set_TableID_HLP_N_IB(TFIBLargeIntField * TableID_HLP_N_IB)
{
Object->TableID_HLP_N_IB=TableID_HLP_N_IB;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprNaborInfBlockImpl::get_TableIDBASE_HLP_N_IB(void)
{
return Object->TableIDBASE_HLP_N_IB;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockImpl::set_TableIDBASE_HLP_N_IB(TFIBLargeIntField * TableIDBASE_HLP_N_IB)
{
Object->TableIDBASE_HLP_N_IB=TableIDBASE_HLP_N_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprNaborInfBlockImpl::get_TableGUID_HLP_N_IB(void)
{
return Object->TableGUID_HLP_N_IB;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockImpl::set_TableGUID_HLP_N_IB(TFIBWideStringField * TableGUID_HLP_N_IB)
{
Object->TableGUID_HLP_N_IB=TableGUID_HLP_N_IB;
}
//---------------------------------------------------------------
TFIBDateTimeField * THLP_DMSprNaborInfBlockImpl::get_TablePOS_ISM_HLP_N_IB(void)
{
return Object->TablePOS_ISM_HLP_N_IB;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockImpl::set_TablePOS_ISM_HLP_N_IB(TFIBDateTimeField * TablePOS_ISM_HLP_N_IB)
{
Object->TablePOS_ISM_HLP_N_IB=TablePOS_ISM_HLP_N_IB;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprNaborInfBlockImpl::get_TableIDGRP_HLP_N_IB(void)
{
return Object->TableIDGRP_HLP_N_IB;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockImpl::set_TableIDGRP_HLP_N_IB(TFIBLargeIntField * TableIDGRP_HLP_N_IB)
{
Object->TableIDGRP_HLP_N_IB=TableIDGRP_HLP_N_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprNaborInfBlockImpl::get_TableNAME_HLP_N_IB(void)
{
return Object->TableNAME_HLP_N_IB;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockImpl::set_TableNAME_HLP_N_IB(TFIBWideStringField * TableNAME_HLP_N_IB)
{
Object->TableNAME_HLP_N_IB=TableNAME_HLP_N_IB;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprNaborInfBlockImpl::get_TableINDEX_HLP_N_IB(void)
{
return Object->TableINDEX_HLP_N_IB;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockImpl::set_TableINDEX_HLP_N_IB(TFIBIntegerField * TableINDEX_HLP_N_IB)
{
Object->TableINDEX_HLP_N_IB=TableINDEX_HLP_N_IB;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprNaborInfBlockImpl::get_ElementID_HLP_N_IB(void)
{
return Object->ElementID_HLP_N_IB;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockImpl::set_ElementID_HLP_N_IB(TFIBLargeIntField * ElementID_HLP_N_IB)
{
Object->ElementID_HLP_N_IB=ElementID_HLP_N_IB;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprNaborInfBlockImpl::get_ElementIDBASE_HLP_N_IB(void)
{
return Object->ElementIDBASE_HLP_N_IB;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockImpl::set_ElementIDBASE_HLP_N_IB(TFIBLargeIntField * ElementIDBASE_HLP_N_IB)
{
Object->ElementIDBASE_HLP_N_IB=ElementIDBASE_HLP_N_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprNaborInfBlockImpl::get_ElementGUID_HLP_N_IB(void)
{
return Object->ElementGUID_HLP_N_IB;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockImpl::set_ElementGUID_HLP_N_IB(TFIBWideStringField * ElementGUID_HLP_N_IB)
{
Object->ElementGUID_HLP_N_IB=ElementGUID_HLP_N_IB;
}
//---------------------------------------------------------------
TFIBDateTimeField * THLP_DMSprNaborInfBlockImpl::get_ElementPOS_ISM_HLP_N_IB(void)
{
return Object->ElementPOS_ISM_HLP_N_IB;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockImpl::set_ElementPOS_ISM_HLP_N_IB(TFIBDateTimeField * ElementPOS_ISM_HLP_N_IB)
{
Object->ElementPOS_ISM_HLP_N_IB=ElementPOS_ISM_HLP_N_IB;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprNaborInfBlockImpl::get_ElementIDGRP_HLP_N_IB(void)
{
return Object->ElementIDGRP_HLP_N_IB;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockImpl::set_ElementIDGRP_HLP_N_IB(TFIBLargeIntField * ElementIDGRP_HLP_N_IB)
{
Object->ElementIDGRP_HLP_N_IB=ElementIDGRP_HLP_N_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprNaborInfBlockImpl::get_ElementNAME_HLP_N_IB(void)
{
return Object->ElementNAME_HLP_N_IB;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockImpl::set_ElementNAME_HLP_N_IB(TFIBWideStringField * ElementNAME_HLP_N_IB)
{
Object->ElementNAME_HLP_N_IB=ElementNAME_HLP_N_IB;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprNaborInfBlockImpl::get_ElementINDEX_HLP_N_IB(void)
{
return Object->ElementINDEX_HLP_N_IB;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockImpl::set_ElementINDEX_HLP_N_IB(TFIBIntegerField * ElementINDEX_HLP_N_IB)
{
Object->ElementINDEX_HLP_N_IB=ElementINDEX_HLP_N_IB;
}
//---------------------------------------------------------------
__int64 THLP_DMSprNaborInfBlockImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool THLP_DMSprNaborInfBlockImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
__int64 THLP_DMSprNaborInfBlockImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockImpl::OpenTable(__int64 id_grp, bool all)
{
return Object->OpenTable(id_grp,all);
}
//---------------------------------------------------------------
UnicodeString THLP_DMSprNaborInfBlockImpl::GetTextQuery(__int64 id_grp, bool all)
{
return Object->GetTextQuery(id_grp,all);
}
//---------------------------------------------------------------
int THLP_DMSprNaborInfBlockImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool THLP_DMSprNaborInfBlockImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool THLP_DMSprNaborInfBlockImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool THLP_DMSprNaborInfBlockImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockImpl::ChancheGrp(__int64 id_new_grp,__int64 id_element)
{
return Object->ChancheGrp(id_new_grp,id_element);
}
//---------------------------------------------------------------
__int64 THLP_DMSprNaborInfBlockImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
__int64 THLP_DMSprNaborInfBlockImpl::GetIdGrp(__int64 id_el)
{
return Object->GetIdGrp(id_el);
}
//---------------------------------------------------------------
