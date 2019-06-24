#include "vcl.h"
#pragma hdrstop


#include "UHLP_DMSprNaborInfBlockSostavImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THLP_DMSprNaborInfBlockSostavImpl::THLP_DMSprNaborInfBlockSostavImpl()           
{                                            
Object=new THLP_DMSprNaborInfBlockSostav(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THLP_DMSprNaborInfBlockSostavImpl::~THLP_DMSprNaborInfBlockSostavImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THLP_DMSprNaborInfBlockSostavImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHLP_DMSprNaborInfBlockSostav)                        
   {                                                                     
   *ppv=static_cast<IHLP_DMSprNaborInfBlockSostav*> (this);                                
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
int THLP_DMSprNaborInfBlockSostavImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THLP_DMSprNaborInfBlockSostavImpl::kanRelease(void)                                  
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
int  THLP_DMSprNaborInfBlockSostavImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THLP_DMSprNaborInfBlockSostavImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THLP_DMSprNaborInfBlockSostavImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_THLP_DMSprNaborInfBlockSostavImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THLP_DMSprNaborInfBlockSostavImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IHLP_DMSprNaborInfBlockSostav
TDataSource * THLP_DMSprNaborInfBlockSostavImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * THLP_DMSprNaborInfBlockSostavImpl::get_DataSourcePodr(void)
{
return Object->DataSourcePodr;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavImpl::set_DataSourcePodr(TDataSource * DataSourcePodr)
{
Object->DataSourcePodr=DataSourcePodr;
}
//---------------------------------------------------------------
TpFIBDataSet * THLP_DMSprNaborInfBlockSostavImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * THLP_DMSprNaborInfBlockSostavImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * THLP_DMSprNaborInfBlockSostavImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * THLP_DMSprNaborInfBlockSostavImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprNaborInfBlockSostavImpl::get_TableID_HLP_N_IB_S(void)
{
return Object->TableID_HLP_N_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavImpl::set_TableID_HLP_N_IB_S(TFIBLargeIntField * TableID_HLP_N_IB_S)
{
Object->TableID_HLP_N_IB_S=TableID_HLP_N_IB_S;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprNaborInfBlockSostavImpl::get_TableIDBASE_HLP_N_IB_S(void)
{
return Object->TableIDBASE_HLP_N_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavImpl::set_TableIDBASE_HLP_N_IB_S(TFIBLargeIntField * TableIDBASE_HLP_N_IB_S)
{
Object->TableIDBASE_HLP_N_IB_S=TableIDBASE_HLP_N_IB_S;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprNaborInfBlockSostavImpl::get_TableGUID_HLP_N_IB_S(void)
{
return Object->TableGUID_HLP_N_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavImpl::set_TableGUID_HLP_N_IB_S(TFIBWideStringField * TableGUID_HLP_N_IB_S)
{
Object->TableGUID_HLP_N_IB_S=TableGUID_HLP_N_IB_S;
}
//---------------------------------------------------------------
TFIBDateTimeField * THLP_DMSprNaborInfBlockSostavImpl::get_TablePOS_ISM_HLP_N_IB_S(void)
{
return Object->TablePOS_ISM_HLP_N_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavImpl::set_TablePOS_ISM_HLP_N_IB_S(TFIBDateTimeField * TablePOS_ISM_HLP_N_IB_S)
{
Object->TablePOS_ISM_HLP_N_IB_S=TablePOS_ISM_HLP_N_IB_S;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprNaborInfBlockSostavImpl::get_TableIDGRP_HLP_N_IB_S(void)
{
return Object->TableIDGRP_HLP_N_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavImpl::set_TableIDGRP_HLP_N_IB_S(TFIBLargeIntField * TableIDGRP_HLP_N_IB_S)
{
Object->TableIDGRP_HLP_N_IB_S=TableIDGRP_HLP_N_IB_S;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprNaborInfBlockSostavImpl::get_TableIDNABOR_HLP_N_IB_S(void)
{
return Object->TableIDNABOR_HLP_N_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavImpl::set_TableIDNABOR_HLP_N_IB_S(TFIBLargeIntField * TableIDNABOR_HLP_N_IB_S)
{
Object->TableIDNABOR_HLP_N_IB_S=TableIDNABOR_HLP_N_IB_S;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprNaborInfBlockSostavImpl::get_TableIDIB_HLP_N_IB_S(void)
{
return Object->TableIDIB_HLP_N_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavImpl::set_TableIDIB_HLP_N_IB_S(TFIBLargeIntField * TableIDIB_HLP_N_IB_S)
{
Object->TableIDIB_HLP_N_IB_S=TableIDIB_HLP_N_IB_S;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprNaborInfBlockSostavImpl::get_TableINDEX_HLP_N_IB_S(void)
{
return Object->TableINDEX_HLP_N_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavImpl::set_TableINDEX_HLP_N_IB_S(TFIBIntegerField * TableINDEX_HLP_N_IB_S)
{
Object->TableINDEX_HLP_N_IB_S=TableINDEX_HLP_N_IB_S;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprNaborInfBlockSostavImpl::get_TableNAME_HLP_IB(void)
{
return Object->TableNAME_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavImpl::set_TableNAME_HLP_IB(TFIBWideStringField * TableNAME_HLP_IB)
{
Object->TableNAME_HLP_IB=TableNAME_HLP_IB;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprNaborInfBlockSostavImpl::get_ElementID_HLP_N_IB_S(void)
{
return Object->ElementID_HLP_N_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavImpl::set_ElementID_HLP_N_IB_S(TFIBLargeIntField * ElementID_HLP_N_IB_S)
{
Object->ElementID_HLP_N_IB_S=ElementID_HLP_N_IB_S;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprNaborInfBlockSostavImpl::get_ElementIDBASE_HLP_N_IB_S(void)
{
return Object->ElementIDBASE_HLP_N_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavImpl::set_ElementIDBASE_HLP_N_IB_S(TFIBLargeIntField * ElementIDBASE_HLP_N_IB_S)
{
Object->ElementIDBASE_HLP_N_IB_S=ElementIDBASE_HLP_N_IB_S;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprNaborInfBlockSostavImpl::get_ElementGUID_HLP_N_IB_S(void)
{
return Object->ElementGUID_HLP_N_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavImpl::set_ElementGUID_HLP_N_IB_S(TFIBWideStringField * ElementGUID_HLP_N_IB_S)
{
Object->ElementGUID_HLP_N_IB_S=ElementGUID_HLP_N_IB_S;
}
//---------------------------------------------------------------
TFIBDateTimeField * THLP_DMSprNaborInfBlockSostavImpl::get_ElementPOS_ISM_HLP_N_IB_S(void)
{
return Object->ElementPOS_ISM_HLP_N_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavImpl::set_ElementPOS_ISM_HLP_N_IB_S(TFIBDateTimeField * ElementPOS_ISM_HLP_N_IB_S)
{
Object->ElementPOS_ISM_HLP_N_IB_S=ElementPOS_ISM_HLP_N_IB_S;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprNaborInfBlockSostavImpl::get_ElementIDGRP_HLP_N_IB_S(void)
{
return Object->ElementIDGRP_HLP_N_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavImpl::set_ElementIDGRP_HLP_N_IB_S(TFIBLargeIntField * ElementIDGRP_HLP_N_IB_S)
{
Object->ElementIDGRP_HLP_N_IB_S=ElementIDGRP_HLP_N_IB_S;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprNaborInfBlockSostavImpl::get_ElementIDNABOR_HLP_N_IB_S(void)
{
return Object->ElementIDNABOR_HLP_N_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavImpl::set_ElementIDNABOR_HLP_N_IB_S(TFIBLargeIntField * ElementIDNABOR_HLP_N_IB_S)
{
Object->ElementIDNABOR_HLP_N_IB_S=ElementIDNABOR_HLP_N_IB_S;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprNaborInfBlockSostavImpl::get_ElementIDIB_HLP_N_IB_S(void)
{
return Object->ElementIDIB_HLP_N_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavImpl::set_ElementIDIB_HLP_N_IB_S(TFIBLargeIntField * ElementIDIB_HLP_N_IB_S)
{
Object->ElementIDIB_HLP_N_IB_S=ElementIDIB_HLP_N_IB_S;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprNaborInfBlockSostavImpl::get_ElementINDEX_HLP_N_IB_S(void)
{
return Object->ElementINDEX_HLP_N_IB_S;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavImpl::set_ElementINDEX_HLP_N_IB_S(TFIBIntegerField * ElementINDEX_HLP_N_IB_S)
{
Object->ElementINDEX_HLP_N_IB_S=ElementINDEX_HLP_N_IB_S;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprNaborInfBlockSostavImpl::get_ElementNAME_HLP_IB(void)
{
return Object->ElementNAME_HLP_IB;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavImpl::set_ElementNAME_HLP_IB(TFIBWideStringField * ElementNAME_HLP_IB)
{
Object->ElementNAME_HLP_IB=ElementNAME_HLP_IB;
}
//---------------------------------------------------------------
__int64 THLP_DMSprNaborInfBlockSostavImpl::get_IdGroupElement(void)
{
return Object->IdGroupElement;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavImpl::set_IdGroupElement(__int64 IdGroupElement)
{
Object->IdGroupElement=IdGroupElement;
}
//---------------------------------------------------------------
__int64 THLP_DMSprNaborInfBlockSostavImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
__int64 THLP_DMSprNaborInfBlockSostavImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
bool THLP_DMSprNaborInfBlockSostavImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void THLP_DMSprNaborInfBlockSostavImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
bool THLP_DMSprNaborInfBlockSostavImpl::NewElement(__int64 id_group_element, __int64 id_grp)
{
return Object->NewElement(id_group_element,id_grp);
}
//---------------------------------------------------------------
bool THLP_DMSprNaborInfBlockSostavImpl::InsertElement(__int64 id_group_element, __int64 id_grp, __int64 id_ib)
{
return Object->InsertElement(id_group_element, id_grp, id_ib);
}
//---------------------------------------------------------------
bool THLP_DMSprNaborInfBlockSostavImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool THLP_DMSprNaborInfBlockSostavImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
bool THLP_DMSprNaborInfBlockSostavImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool THLP_DMSprNaborInfBlockSostavImpl::ChancheGrp(__int64 id_new_grp,__int64 id_element)
{
return Object->ChancheGrp(id_new_grp,id_element);
}
//---------------------------------------------------------------
bool THLP_DMSprNaborInfBlockSostavImpl::OpenTable(__int64 id_group_element, __int64 id_grp, bool all)
{
return Object->OpenTable( id_group_element,  id_grp,  all);
}
//---------------------------------------------------------------
bool THLP_DMSprNaborInfBlockSostavImpl::TableSaveIsmen(void)
{
return Object->TableSaveIsmen();
}
//---------------------------------------------------------------
bool THLP_DMSprNaborInfBlockSostavImpl::TableCancelIsmen(void)
{
return Object->TableCancelIsmen();
}
//---------------------------------------------------------------
bool THLP_DMSprNaborInfBlockSostavImpl::TableNewElement(__int64 id_group_element, __int64 id_grp)
{
return Object->TableNewElement(id_group_element,  id_grp);
}
//---------------------------------------------------------------
bool THLP_DMSprNaborInfBlockSostavImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
bool THLP_DMSprNaborInfBlockSostavImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
bool THLP_DMSprNaborInfBlockSostavImpl::TableEdit(void)
{
return Object->TableEdit();
}
//---------------------------------------------------------------
bool THLP_DMSprNaborInfBlockSostavImpl::TablePost(void)
{
return Object->TablePost();
}
//---------------------------------------------------------------
