#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprTrebRabotImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprTrebRabotImpl::TREM_DMSprTrebRabotImpl()           
{                                            
Object=new TREM_DMSprTrebRabot(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprTrebRabotImpl::~TREM_DMSprTrebRabotImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprTrebRabotImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprTrebRabotImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprTrebRabot)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprTrebRabot*> (this);                                
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
int TREM_DMSprTrebRabotImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprTrebRabotImpl::kanRelease(void)                                  
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
int  TREM_DMSprTrebRabotImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprTrebRabotImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprTrebRabotImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprTrebRabotImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprTrebRabotImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprTrebRabotImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprTrebRabotImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprTrebRabot
TDataSource * TREM_DMSprTrebRabotImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprTrebRabotImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprTrebRabotImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprTrebRabotImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprTrebRabotImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprTrebRabotImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprTrebRabotImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprTrebRabotImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprTrebRabotImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprTrebRabotImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprTrebRabotImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprTrebRabotImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprTrebRabotImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprTrebRabotImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprTrebRabotImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMSprTrebRabotImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTrebRabotImpl::get_TableID_REM_STREBRABOT(void)
{
return Object->TableID_REM_STREBRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprTrebRabotImpl::set_TableID_REM_STREBRABOT(TFIBLargeIntField * TableID_REM_STREBRABOT)
{
Object->TableID_REM_STREBRABOT=TableID_REM_STREBRABOT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTrebRabotImpl::get_TableGID_REM_STREBRABOT(void)
{
return Object->TableGID_REM_STREBRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprTrebRabotImpl::set_TableGID_REM_STREBRABOT(TFIBWideStringField * TableGID_REM_STREBRABOT)
{
Object->TableGID_REM_STREBRABOT=TableGID_REM_STREBRABOT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTrebRabotImpl::get_TableIDBASE_REM_STREBRABOT(void)
{
return Object->TableIDBASE_REM_STREBRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprTrebRabotImpl::set_TableIDBASE_REM_STREBRABOT(TFIBLargeIntField * TableIDBASE_REM_STREBRABOT)
{
Object->TableIDBASE_REM_STREBRABOT=TableIDBASE_REM_STREBRABOT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTrebRabotImpl::get_TableIDDMN_REM_STREBRABOT(void)
{
return Object->TableIDDMN_REM_STREBRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprTrebRabotImpl::set_TableIDDMN_REM_STREBRABOT(TFIBLargeIntField * TableIDDMN_REM_STREBRABOT)
{
Object->TableIDDMN_REM_STREBRABOT=TableIDDMN_REM_STREBRABOT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTrebRabotImpl::get_TableIDTYPRABOT_REM_STREBRABOT(void)
{
return Object->TableIDTYPRABOT_REM_STREBRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprTrebRabotImpl::set_TableIDTYPRABOT_REM_STREBRABOT(TFIBLargeIntField * TableIDTYPRABOT_REM_STREBRABOT)
{
Object->TableIDTYPRABOT_REM_STREBRABOT=TableIDTYPRABOT_REM_STREBRABOT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTrebRabotImpl::get_TableNAME_REM_STREBRABOT(void)
{
return Object->TableNAME_REM_STREBRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprTrebRabotImpl::set_TableNAME_REM_STREBRABOT(TFIBWideStringField * TableNAME_REM_STREBRABOT)
{
Object->TableNAME_REM_STREBRABOT=TableNAME_REM_STREBRABOT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTrebRabotImpl::get_TableNAME_REM_STYPRABOT(void)
{
return Object->TableNAME_REM_STYPRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprTrebRabotImpl::set_TableNAME_REM_STYPRABOT(TFIBWideStringField * TableNAME_REM_STYPRABOT)
{
Object->TableNAME_REM_STYPRABOT=TableNAME_REM_STYPRABOT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTrebRabotImpl::get_ElementID_REM_STREBRABOT(void)
{
return Object->ElementID_REM_STREBRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprTrebRabotImpl::set_ElementID_REM_STREBRABOT(TFIBLargeIntField * ElementID_REM_STREBRABOT)
{
Object->ElementID_REM_STREBRABOT=ElementID_REM_STREBRABOT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTrebRabotImpl::get_ElementGID_REM_STREBRABOT(void)
{
return Object->ElementGID_REM_STREBRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprTrebRabotImpl::set_ElementGID_REM_STREBRABOT(TFIBWideStringField * ElementGID_REM_STREBRABOT)
{
Object->ElementGID_REM_STREBRABOT=ElementGID_REM_STREBRABOT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTrebRabotImpl::get_ElementIDBASE_REM_STREBRABOT(void)
{
return Object->ElementIDBASE_REM_STREBRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprTrebRabotImpl::set_ElementIDBASE_REM_STREBRABOT(TFIBLargeIntField * ElementIDBASE_REM_STREBRABOT)
{
Object->ElementIDBASE_REM_STREBRABOT=ElementIDBASE_REM_STREBRABOT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTrebRabotImpl::get_ElementIDDMN_REM_STREBRABOT(void)
{
return Object->ElementIDDMN_REM_STREBRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprTrebRabotImpl::set_ElementIDDMN_REM_STREBRABOT(TFIBLargeIntField * ElementIDDMN_REM_STREBRABOT)
{
Object->ElementIDDMN_REM_STREBRABOT=ElementIDDMN_REM_STREBRABOT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTrebRabotImpl::get_ElementIDTYPRABOT_REM_STREBRABOT(void)
{
return Object->ElementIDTYPRABOT_REM_STREBRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprTrebRabotImpl::set_ElementIDTYPRABOT_REM_STREBRABOT(TFIBLargeIntField * ElementIDTYPRABOT_REM_STREBRABOT)
{
Object->ElementIDTYPRABOT_REM_STREBRABOT=ElementIDTYPRABOT_REM_STREBRABOT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTrebRabotImpl::get_ElementNAME_REM_STREBRABOT(void)
{
return Object->ElementNAME_REM_STREBRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprTrebRabotImpl::set_ElementNAME_REM_STREBRABOT(TFIBWideStringField * ElementNAME_REM_STREBRABOT)
{
Object->ElementNAME_REM_STREBRABOT=ElementNAME_REM_STREBRABOT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTrebRabotImpl::get_ElementNAME_REM_STYPRABOT(void)
{
return Object->ElementNAME_REM_STYPRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprTrebRabotImpl::set_ElementNAME_REM_STYPRABOT(TFIBWideStringField * ElementNAME_REM_STYPRABOT)
{
Object->ElementNAME_REM_STYPRABOT=ElementNAME_REM_STYPRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprTrebRabotImpl::OpenTable(__int64 id_defect_model_neispr)
{
return Object->OpenTable(id_defect_model_neispr);
}
//---------------------------------------------------------------
int TREM_DMSprTrebRabotImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprTrebRabotImpl::NewElement(__int64 id_defect_model_neispr)
{
return Object->NewElement(id_defect_model_neispr);
}
//---------------------------------------------------------------
bool TREM_DMSprTrebRabotImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMSprTrebRabotImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
