#include "vcl.h"
#pragma hdrstop


#include "UART_DMSprNaborInfBlockSostavImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TART_DMSprNaborInfBlockSostavImpl::TART_DMSprNaborInfBlockSostavImpl()           
{                                            
Object=new TART_DMSprNaborInfBlockSostav(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TART_DMSprNaborInfBlockSostavImpl::~TART_DMSprNaborInfBlockSostavImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TART_DMSprNaborInfBlockSostavImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IART_DMSprNaborInfBlockSostav)                        
   {                                                                     
   *ppv=static_cast<IART_DMSprNaborInfBlockSostav*> (this);                                
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
int TART_DMSprNaborInfBlockSostavImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TART_DMSprNaborInfBlockSostavImpl::kanRelease(void)                                  
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
int  TART_DMSprNaborInfBlockSostavImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TART_DMSprNaborInfBlockSostavImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TART_DMSprNaborInfBlockSostavImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TART_DMSprNaborInfBlockSostavImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TART_DMSprNaborInfBlockSostavImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IART_DMSprNaborInfBlockSostav
TDataSource * TART_DMSprNaborInfBlockSostavImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TART_DMSprNaborInfBlockSostavImpl::get_DataSourcePodr(void)
{
return Object->DataSourcePodr;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavImpl::set_DataSourcePodr(TDataSource * DataSourcePodr)
{
Object->DataSourcePodr=DataSourcePodr;
}
//---------------------------------------------------------------
TpFIBDataSet * TART_DMSprNaborInfBlockSostavImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TART_DMSprNaborInfBlockSostavImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TART_DMSprNaborInfBlockSostavImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TART_DMSprNaborInfBlockSostavImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprNaborInfBlockSostavImpl::get_TableID_ART_N_IB_S(void)
{
return Object->TableID_ART_N_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavImpl::set_TableID_ART_N_IB_S(TFIBLargeIntField * TableID_ART_N_IB_S)
{
Object->TableID_ART_N_IB_S=TableID_ART_N_IB_S;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprNaborInfBlockSostavImpl::get_TableIDBASE_ART_N_IB_S(void)
{
return Object->TableIDBASE_ART_N_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavImpl::set_TableIDBASE_ART_N_IB_S(TFIBLargeIntField * TableIDBASE_ART_N_IB_S)
{
Object->TableIDBASE_ART_N_IB_S=TableIDBASE_ART_N_IB_S;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprNaborInfBlockSostavImpl::get_TableGUID_ART_N_IB_S(void)
{
return Object->TableGUID_ART_N_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavImpl::set_TableGUID_ART_N_IB_S(TFIBWideStringField * TableGUID_ART_N_IB_S)
{
Object->TableGUID_ART_N_IB_S=TableGUID_ART_N_IB_S;
}
//---------------------------------------------------------------
TFIBDateTimeField * TART_DMSprNaborInfBlockSostavImpl::get_TablePOS_ISM_ART_N_IB_S(void)
{
return Object->TablePOS_ISM_ART_N_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavImpl::set_TablePOS_ISM_ART_N_IB_S(TFIBDateTimeField * TablePOS_ISM_ART_N_IB_S)
{
Object->TablePOS_ISM_ART_N_IB_S=TablePOS_ISM_ART_N_IB_S;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprNaborInfBlockSostavImpl::get_TableIDGRP_ART_N_IB_S(void)
{
return Object->TableIDGRP_ART_N_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavImpl::set_TableIDGRP_ART_N_IB_S(TFIBLargeIntField * TableIDGRP_ART_N_IB_S)
{
Object->TableIDGRP_ART_N_IB_S=TableIDGRP_ART_N_IB_S;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprNaborInfBlockSostavImpl::get_TableIDNABOR_ART_N_IB_S(void)
{
return Object->TableIDNABOR_ART_N_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavImpl::set_TableIDNABOR_ART_N_IB_S(TFIBLargeIntField * TableIDNABOR_ART_N_IB_S)
{
Object->TableIDNABOR_ART_N_IB_S=TableIDNABOR_ART_N_IB_S;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprNaborInfBlockSostavImpl::get_TableIDIB_ART_N_IB_S(void)
{
return Object->TableIDIB_ART_N_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavImpl::set_TableIDIB_ART_N_IB_S(TFIBLargeIntField * TableIDIB_ART_N_IB_S)
{
Object->TableIDIB_ART_N_IB_S=TableIDIB_ART_N_IB_S;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprNaborInfBlockSostavImpl::get_TableNAME_ART_IB(void)
{
return Object->TableNAME_ART_IB;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavImpl::set_TableNAME_ART_IB(TFIBWideStringField * TableNAME_ART_IB)
{
Object->TableNAME_ART_IB=TableNAME_ART_IB;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprNaborInfBlockSostavImpl::get_ElementID_ART_N_IB_S(void)
{
return Object->ElementID_ART_N_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavImpl::set_ElementID_ART_N_IB_S(TFIBLargeIntField * ElementID_ART_N_IB_S)
{
Object->ElementID_ART_N_IB_S=ElementID_ART_N_IB_S;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprNaborInfBlockSostavImpl::get_ElementIDBASE_ART_N_IB_S(void)
{
return Object->ElementIDBASE_ART_N_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavImpl::set_ElementIDBASE_ART_N_IB_S(TFIBLargeIntField * ElementIDBASE_ART_N_IB_S)
{
Object->ElementIDBASE_ART_N_IB_S=ElementIDBASE_ART_N_IB_S;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprNaborInfBlockSostavImpl::get_ElementGUID_ART_N_IB_S(void)
{
return Object->ElementGUID_ART_N_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavImpl::set_ElementGUID_ART_N_IB_S(TFIBWideStringField * ElementGUID_ART_N_IB_S)
{
Object->ElementGUID_ART_N_IB_S=ElementGUID_ART_N_IB_S;
}
//---------------------------------------------------------------
TFIBDateTimeField * TART_DMSprNaborInfBlockSostavImpl::get_ElementPOS_ISM_ART_N_IB_S(void)
{
return Object->ElementPOS_ISM_ART_N_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavImpl::set_ElementPOS_ISM_ART_N_IB_S(TFIBDateTimeField * ElementPOS_ISM_ART_N_IB_S)
{
Object->ElementPOS_ISM_ART_N_IB_S=ElementPOS_ISM_ART_N_IB_S;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprNaborInfBlockSostavImpl::get_ElementIDGRP_ART_N_IB_S(void)
{
return Object->ElementIDGRP_ART_N_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavImpl::set_ElementIDGRP_ART_N_IB_S(TFIBLargeIntField * ElementIDGRP_ART_N_IB_S)
{
Object->ElementIDGRP_ART_N_IB_S=ElementIDGRP_ART_N_IB_S;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprNaborInfBlockSostavImpl::get_ElementIDNABOR_ART_N_IB_S(void)
{
return Object->ElementIDNABOR_ART_N_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavImpl::set_ElementIDNABOR_ART_N_IB_S(TFIBLargeIntField * ElementIDNABOR_ART_N_IB_S)
{
Object->ElementIDNABOR_ART_N_IB_S=ElementIDNABOR_ART_N_IB_S;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprNaborInfBlockSostavImpl::get_ElementIDIB_ART_N_IB_S(void)
{
return Object->ElementIDIB_ART_N_IB_S;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavImpl::set_ElementIDIB_ART_N_IB_S(TFIBLargeIntField * ElementIDIB_ART_N_IB_S)
{
Object->ElementIDIB_ART_N_IB_S=ElementIDIB_ART_N_IB_S;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprNaborInfBlockSostavImpl::get_ElementNAME_ART_IB(void)
{
return Object->ElementNAME_ART_IB;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavImpl::set_ElementNAME_ART_IB(TFIBWideStringField * ElementNAME_ART_IB)
{
Object->ElementNAME_ART_IB=ElementNAME_ART_IB;
}
//---------------------------------------------------------------
__int64 TART_DMSprNaborInfBlockSostavImpl::get_IdGroupElement(void)
{
return Object->IdGroupElement;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavImpl::set_IdGroupElement(__int64 IdGroupElement)
{
Object->IdGroupElement=IdGroupElement;
}
//---------------------------------------------------------------
__int64 TART_DMSprNaborInfBlockSostavImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
__int64 TART_DMSprNaborInfBlockSostavImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
bool TART_DMSprNaborInfBlockSostavImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TART_DMSprNaborInfBlockSostavImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
bool TART_DMSprNaborInfBlockSostavImpl::NewElement(__int64 id_group_element, __int64 id_grp)
{
return Object->NewElement(id_group_element,id_grp);
}
//---------------------------------------------------------------
bool TART_DMSprNaborInfBlockSostavImpl::InsertElement(__int64 id_group_element, __int64 id_grp, __int64 id_ib)
{
return Object->InsertElement(id_group_element,id_grp,id_ib);
}
//---------------------------------------------------------------
bool TART_DMSprNaborInfBlockSostavImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TART_DMSprNaborInfBlockSostavImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
bool TART_DMSprNaborInfBlockSostavImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TART_DMSprNaborInfBlockSostavImpl::ChancheGrp(__int64 id_new_grp,__int64 id_element)
{
return Object->ChancheGrp(id_new_grp,id_element);
}
//---------------------------------------------------------------
bool TART_DMSprNaborInfBlockSostavImpl::OpenTable(__int64 id_group_element, __int64 id_grp, bool all)
{
return Object->OpenTable(id_group_element,id_grp,all);
}
//---------------------------------------------------------------
bool TART_DMSprNaborInfBlockSostavImpl::TableSaveIsmen(void)
{
return Object->TableSaveIsmen();
}
//---------------------------------------------------------------
bool TART_DMSprNaborInfBlockSostavImpl::TableCancelIsmen(void)
{
return Object->TableCancelIsmen();
}
//---------------------------------------------------------------
bool TART_DMSprNaborInfBlockSostavImpl::TableNewElement(__int64 id_group_element, __int64 id_grp)
{
return Object->TableNewElement(id_group_element,id_grp);
}
//---------------------------------------------------------------
bool TART_DMSprNaborInfBlockSostavImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
bool TART_DMSprNaborInfBlockSostavImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
bool TART_DMSprNaborInfBlockSostavImpl::TableEdit(void)
{
return Object->TableEdit();
}
//---------------------------------------------------------------
bool TART_DMSprNaborInfBlockSostavImpl::TablePost(void)
{
return Object->TablePost();
}
//---------------------------------------------------------------
