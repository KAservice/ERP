#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprTrebUslovImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprTrebUslovImpl::TREM_DMSprTrebUslovImpl()           
{                                            
Object=new TREM_DMSprTrebUslov(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprTrebUslovImpl::~TREM_DMSprTrebUslovImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprTrebUslovImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprTrebUslovImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprTrebUslov)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprTrebUslov*> (this);                                
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
int TREM_DMSprTrebUslovImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprTrebUslovImpl::kanRelease(void)                                  
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
int  TREM_DMSprTrebUslovImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprTrebUslovImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprTrebUslovImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprTrebUslovImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprTrebUslovImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprTrebUslovImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprTrebUslovImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprTrebUslov
TDataSource * TREM_DMSprTrebUslovImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprTrebUslovImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprTrebUslovImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprTrebUslovImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprTrebUslovImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprTrebUslovImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprTrebUslovImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprTrebUslovImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprTrebUslovImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprTrebUslovImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprTrebUslovImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprTrebUslovImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprTrebUslovImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprTrebUslovImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprTrebUslovImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMSprTrebUslovImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTrebUslovImpl::get_TableID_REM_STREBUSLOV(void)
{
return Object->TableID_REM_STREBUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprTrebUslovImpl::set_TableID_REM_STREBUSLOV(TFIBLargeIntField * TableID_REM_STREBUSLOV)
{
Object->TableID_REM_STREBUSLOV=TableID_REM_STREBUSLOV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTrebUslovImpl::get_TableGID_REM_STREBUSLOV(void)
{
return Object->TableGID_REM_STREBUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprTrebUslovImpl::set_TableGID_REM_STREBUSLOV(TFIBWideStringField * TableGID_REM_STREBUSLOV)
{
Object->TableGID_REM_STREBUSLOV=TableGID_REM_STREBUSLOV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTrebUslovImpl::get_TableIDBASE_REM_STREBUSLOV(void)
{
return Object->TableIDBASE_REM_STREBUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprTrebUslovImpl::set_TableIDBASE_REM_STREBUSLOV(TFIBLargeIntField * TableIDBASE_REM_STREBUSLOV)
{
Object->TableIDBASE_REM_STREBUSLOV=TableIDBASE_REM_STREBUSLOV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTrebUslovImpl::get_TableIDDMN_REM_STREBUSLOV(void)
{
return Object->TableIDDMN_REM_STREBUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprTrebUslovImpl::set_TableIDDMN_REM_STREBUSLOV(TFIBLargeIntField * TableIDDMN_REM_STREBUSLOV)
{
Object->TableIDDMN_REM_STREBUSLOV=TableIDDMN_REM_STREBUSLOV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTrebUslovImpl::get_TableIDTYPUSLA_REM_STREBUSLOV(void)
{
return Object->TableIDTYPUSLA_REM_STREBUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprTrebUslovImpl::set_TableIDTYPUSLA_REM_STREBUSLOV(TFIBLargeIntField * TableIDTYPUSLA_REM_STREBUSLOV)
{
Object->TableIDTYPUSLA_REM_STREBUSLOV=TableIDTYPUSLA_REM_STREBUSLOV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTrebUslovImpl::get_TableNAME_REM_STREBUSLOV(void)
{
return Object->TableNAME_REM_STREBUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprTrebUslovImpl::set_TableNAME_REM_STREBUSLOV(TFIBWideStringField * TableNAME_REM_STREBUSLOV)
{
Object->TableNAME_REM_STREBUSLOV=TableNAME_REM_STREBUSLOV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTrebUslovImpl::get_TableNAME_REM_STYPUSLOV(void)
{
return Object->TableNAME_REM_STYPUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprTrebUslovImpl::set_TableNAME_REM_STYPUSLOV(TFIBWideStringField * TableNAME_REM_STYPUSLOV)
{
Object->TableNAME_REM_STYPUSLOV=TableNAME_REM_STYPUSLOV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTrebUslovImpl::get_ElementID_REM_STREBUSLOV(void)
{
return Object->ElementID_REM_STREBUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprTrebUslovImpl::set_ElementID_REM_STREBUSLOV(TFIBLargeIntField * ElementID_REM_STREBUSLOV)
{
Object->ElementID_REM_STREBUSLOV=ElementID_REM_STREBUSLOV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTrebUslovImpl::get_ElementGID_REM_STREBUSLOV(void)
{
return Object->ElementGID_REM_STREBUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprTrebUslovImpl::set_ElementGID_REM_STREBUSLOV(TFIBWideStringField * ElementGID_REM_STREBUSLOV)
{
Object->ElementGID_REM_STREBUSLOV=ElementGID_REM_STREBUSLOV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTrebUslovImpl::get_ElementIDBASE_REM_STREBUSLOV(void)
{
return Object->ElementIDBASE_REM_STREBUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprTrebUslovImpl::set_ElementIDBASE_REM_STREBUSLOV(TFIBLargeIntField * ElementIDBASE_REM_STREBUSLOV)
{
Object->ElementIDBASE_REM_STREBUSLOV=ElementIDBASE_REM_STREBUSLOV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTrebUslovImpl::get_ElementIDDMN_REM_STREBUSLOV(void)
{
return Object->ElementIDDMN_REM_STREBUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprTrebUslovImpl::set_ElementIDDMN_REM_STREBUSLOV(TFIBLargeIntField * ElementIDDMN_REM_STREBUSLOV)
{
Object->ElementIDDMN_REM_STREBUSLOV=ElementIDDMN_REM_STREBUSLOV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTrebUslovImpl::get_ElementIDTYPUSLA_REM_STREBUSLOV(void)
{
return Object->ElementIDTYPUSLA_REM_STREBUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprTrebUslovImpl::set_ElementIDTYPUSLA_REM_STREBUSLOV(TFIBLargeIntField * ElementIDTYPUSLA_REM_STREBUSLOV)
{
Object->ElementIDTYPUSLA_REM_STREBUSLOV=ElementIDTYPUSLA_REM_STREBUSLOV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTrebUslovImpl::get_ElementNAME_REM_STREBUSLOV(void)
{
return Object->ElementNAME_REM_STREBUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprTrebUslovImpl::set_ElementNAME_REM_STREBUSLOV(TFIBWideStringField * ElementNAME_REM_STREBUSLOV)
{
Object->ElementNAME_REM_STREBUSLOV=ElementNAME_REM_STREBUSLOV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTrebUslovImpl::get_ElementNAME_REM_STYPUSLOV(void)
{
return Object->ElementNAME_REM_STYPUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprTrebUslovImpl::set_ElementNAME_REM_STYPUSLOV(TFIBWideStringField * ElementNAME_REM_STYPUSLOV)
{
Object->ElementNAME_REM_STYPUSLOV=ElementNAME_REM_STYPUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprTrebUslovImpl::OpenTable(__int64 id_defect_model_neispr)
{
return Object->OpenTable(id_defect_model_neispr);
}
//---------------------------------------------------------------
int TREM_DMSprTrebUslovImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprTrebUslovImpl::NewElement(__int64 id_defect_model_neispr)
{
return Object->NewElement(id_defect_model_neispr);
}
//---------------------------------------------------------------
bool TREM_DMSprTrebUslovImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMSprTrebUslovImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
