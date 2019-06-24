#include "vcl.h"
#pragma hdrstop


#include "UART_DMSprNaborInfBlockImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TART_DMSprNaborInfBlockImpl::TART_DMSprNaborInfBlockImpl()           
{                                            
Object=new TART_DMSprNaborInfBlock(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TART_DMSprNaborInfBlockImpl::~TART_DMSprNaborInfBlockImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TART_DMSprNaborInfBlockImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IART_DMSprNaborInfBlock)                        
   {                                                                     
   *ppv=static_cast<IART_DMSprNaborInfBlock*> (this);                                
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
int TART_DMSprNaborInfBlockImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TART_DMSprNaborInfBlockImpl::kanRelease(void)                                  
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
int  TART_DMSprNaborInfBlockImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TART_DMSprNaborInfBlockImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TART_DMSprNaborInfBlockImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TART_DMSprNaborInfBlockImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TART_DMSprNaborInfBlockImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IART_DMSprNaborInfBlock
TDataSource * TART_DMSprNaborInfBlockImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TART_DMSprNaborInfBlockImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TART_DMSprNaborInfBlockImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TART_DMSprNaborInfBlockImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TART_DMSprNaborInfBlockImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TART_DMSprNaborInfBlockImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TART_DMSprNaborInfBlockImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprNaborInfBlockImpl::get_TableID_ART_N_IB(void)
{
return Object->TableID_ART_N_IB;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockImpl::set_TableID_ART_N_IB(TFIBLargeIntField * TableID_ART_N_IB)
{
Object->TableID_ART_N_IB=TableID_ART_N_IB;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprNaborInfBlockImpl::get_TableIDBASE_ART_N_IB(void)
{
return Object->TableIDBASE_ART_N_IB;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockImpl::set_TableIDBASE_ART_N_IB(TFIBLargeIntField * TableIDBASE_ART_N_IB)
{
Object->TableIDBASE_ART_N_IB=TableIDBASE_ART_N_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprNaborInfBlockImpl::get_TableGUID_ART_N_IB(void)
{
return Object->TableGUID_ART_N_IB;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockImpl::set_TableGUID_ART_N_IB(TFIBWideStringField * TableGUID_ART_N_IB)
{
Object->TableGUID_ART_N_IB=TableGUID_ART_N_IB;
}
//---------------------------------------------------------------
TFIBDateTimeField * TART_DMSprNaborInfBlockImpl::get_TablePOS_ISM_ART_N_IB(void)
{
return Object->TablePOS_ISM_ART_N_IB;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockImpl::set_TablePOS_ISM_ART_N_IB(TFIBDateTimeField * TablePOS_ISM_ART_N_IB)
{
Object->TablePOS_ISM_ART_N_IB=TablePOS_ISM_ART_N_IB;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprNaborInfBlockImpl::get_TableIDGRP_ART_N_IB(void)
{
return Object->TableIDGRP_ART_N_IB;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockImpl::set_TableIDGRP_ART_N_IB(TFIBLargeIntField * TableIDGRP_ART_N_IB)
{
Object->TableIDGRP_ART_N_IB=TableIDGRP_ART_N_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprNaborInfBlockImpl::get_TableNAME_ART_N_IB(void)
{
return Object->TableNAME_ART_N_IB;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockImpl::set_TableNAME_ART_N_IB(TFIBWideStringField * TableNAME_ART_N_IB)
{
Object->TableNAME_ART_N_IB=TableNAME_ART_N_IB;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprNaborInfBlockImpl::get_ElementID_ART_N_IB(void)
{
return Object->ElementID_ART_N_IB;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockImpl::set_ElementID_ART_N_IB(TFIBLargeIntField * ElementID_ART_N_IB)
{
Object->ElementID_ART_N_IB=ElementID_ART_N_IB;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprNaborInfBlockImpl::get_ElementIDBASE_ART_N_IB(void)
{
return Object->ElementIDBASE_ART_N_IB;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockImpl::set_ElementIDBASE_ART_N_IB(TFIBLargeIntField * ElementIDBASE_ART_N_IB)
{
Object->ElementIDBASE_ART_N_IB=ElementIDBASE_ART_N_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprNaborInfBlockImpl::get_ElementGUID_ART_N_IB(void)
{
return Object->ElementGUID_ART_N_IB;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockImpl::set_ElementGUID_ART_N_IB(TFIBWideStringField * ElementGUID_ART_N_IB)
{
Object->ElementGUID_ART_N_IB=ElementGUID_ART_N_IB;
}
//---------------------------------------------------------------
TFIBDateTimeField * TART_DMSprNaborInfBlockImpl::get_ElementPOS_ISM_ART_N_IB(void)
{
return Object->ElementPOS_ISM_ART_N_IB;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockImpl::set_ElementPOS_ISM_ART_N_IB(TFIBDateTimeField * ElementPOS_ISM_ART_N_IB)
{
Object->ElementPOS_ISM_ART_N_IB=ElementPOS_ISM_ART_N_IB;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprNaborInfBlockImpl::get_ElementIDGRP_ART_N_IB(void)
{
return Object->ElementIDGRP_ART_N_IB;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockImpl::set_ElementIDGRP_ART_N_IB(TFIBLargeIntField * ElementIDGRP_ART_N_IB)
{
Object->ElementIDGRP_ART_N_IB=ElementIDGRP_ART_N_IB;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprNaborInfBlockImpl::get_ElementNAME_ART_N_IB(void)
{
return Object->ElementNAME_ART_N_IB;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockImpl::set_ElementNAME_ART_N_IB(TFIBWideStringField * ElementNAME_ART_N_IB)
{
Object->ElementNAME_ART_N_IB=ElementNAME_ART_N_IB;
}
//---------------------------------------------------------------
__int64 TART_DMSprNaborInfBlockImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TART_DMSprNaborInfBlockImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
__int64 TART_DMSprNaborInfBlockImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockImpl::OpenTable(__int64 id_grp, bool all)
{
return Object->OpenTable(id_grp,all);
}
//---------------------------------------------------------------
UnicodeString TART_DMSprNaborInfBlockImpl::GetTextQuery(__int64 id_grp, bool all)
{
return Object->GetTextQuery(id_grp,all);
}
//---------------------------------------------------------------
int TART_DMSprNaborInfBlockImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool TART_DMSprNaborInfBlockImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TART_DMSprNaborInfBlockImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TART_DMSprNaborInfBlockImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockImpl::ChancheGrp(__int64 id_new_grp,__int64 id_element)
{
return Object->ChancheGrp(id_new_grp,id_element);
}
//---------------------------------------------------------------
__int64 TART_DMSprNaborInfBlockImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
__int64 TART_DMSprNaborInfBlockImpl::GetIdGrp(__int64 id_el)
{
return Object->GetIdGrp(id_el);
}
//---------------------------------------------------------------
