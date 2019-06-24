#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprGrpTypRabotImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprGrpTypRabotImpl::TREM_DMSprGrpTypRabotImpl()           
{                                            
Object=new TREM_DMSprGrpTypRabot(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprGrpTypRabotImpl::~TREM_DMSprGrpTypRabotImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprGrpTypRabotImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprGrpTypRabotImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprGrpTypRabot)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprGrpTypRabot*> (this);                                
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
int TREM_DMSprGrpTypRabotImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprGrpTypRabotImpl::kanRelease(void)                                  
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
int  TREM_DMSprGrpTypRabotImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprGrpTypRabotImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprGrpTypRabotImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprGrpTypRabotImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprGrpTypRabotImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprGrpTypRabotImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprGrpTypRabotImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprGrpTypRabot
TDataSource * TREM_DMSprGrpTypRabotImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypRabotImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprGrpTypRabotImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypRabotImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprGrpTypRabotImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypRabotImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprGrpTypRabotImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypRabotImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprGrpTypRabotImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypRabotImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprGrpTypRabotImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypRabotImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprGrpTypRabotImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypRabotImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprGrpTypRabotImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypRabotImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpTypRabotImpl::get_TableID_REM_STYPRABOT_GRP(void)
{
return Object->TableID_REM_STYPRABOT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypRabotImpl::set_TableID_REM_STYPRABOT_GRP(TFIBLargeIntField * TableID_REM_STYPRABOT_GRP)
{
Object->TableID_REM_STYPRABOT_GRP=TableID_REM_STYPRABOT_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprGrpTypRabotImpl::get_TableGID_REM_STYPRABOT_GRP(void)
{
return Object->TableGID_REM_STYPRABOT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypRabotImpl::set_TableGID_REM_STYPRABOT_GRP(TFIBWideStringField * TableGID_REM_STYPRABOT_GRP)
{
Object->TableGID_REM_STYPRABOT_GRP=TableGID_REM_STYPRABOT_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpTypRabotImpl::get_TableIDBASE_REM_STYPRABOT_GRP(void)
{
return Object->TableIDBASE_REM_STYPRABOT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypRabotImpl::set_TableIDBASE_REM_STYPRABOT_GRP(TFIBLargeIntField * TableIDBASE_REM_STYPRABOT_GRP)
{
Object->TableIDBASE_REM_STYPRABOT_GRP=TableIDBASE_REM_STYPRABOT_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpTypRabotImpl::get_TableIDGRP_REM_STYPRABOT_GRP(void)
{
return Object->TableIDGRP_REM_STYPRABOT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypRabotImpl::set_TableIDGRP_REM_STYPRABOT_GRP(TFIBLargeIntField * TableIDGRP_REM_STYPRABOT_GRP)
{
Object->TableIDGRP_REM_STYPRABOT_GRP=TableIDGRP_REM_STYPRABOT_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprGrpTypRabotImpl::get_TableNAME_REM_STYPRABOT_GRP(void)
{
return Object->TableNAME_REM_STYPRABOT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypRabotImpl::set_TableNAME_REM_STYPRABOT_GRP(TFIBWideStringField * TableNAME_REM_STYPRABOT_GRP)
{
Object->TableNAME_REM_STYPRABOT_GRP=TableNAME_REM_STYPRABOT_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpTypRabotImpl::get_ElementID_REM_STYPRABOT_GRP(void)
{
return Object->ElementID_REM_STYPRABOT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypRabotImpl::set_ElementID_REM_STYPRABOT_GRP(TFIBLargeIntField * ElementID_REM_STYPRABOT_GRP)
{
Object->ElementID_REM_STYPRABOT_GRP=ElementID_REM_STYPRABOT_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprGrpTypRabotImpl::get_ElementGID_REM_STYPRABOT_GRP(void)
{
return Object->ElementGID_REM_STYPRABOT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypRabotImpl::set_ElementGID_REM_STYPRABOT_GRP(TFIBWideStringField * ElementGID_REM_STYPRABOT_GRP)
{
Object->ElementGID_REM_STYPRABOT_GRP=ElementGID_REM_STYPRABOT_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpTypRabotImpl::get_ElementIDBASE_REM_STYPRABOT_GRP(void)
{
return Object->ElementIDBASE_REM_STYPRABOT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypRabotImpl::set_ElementIDBASE_REM_STYPRABOT_GRP(TFIBLargeIntField * ElementIDBASE_REM_STYPRABOT_GRP)
{
Object->ElementIDBASE_REM_STYPRABOT_GRP=ElementIDBASE_REM_STYPRABOT_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpTypRabotImpl::get_ElementIDGRP_REM_STYPRABOT_GRP(void)
{
return Object->ElementIDGRP_REM_STYPRABOT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypRabotImpl::set_ElementIDGRP_REM_STYPRABOT_GRP(TFIBLargeIntField * ElementIDGRP_REM_STYPRABOT_GRP)
{
Object->ElementIDGRP_REM_STYPRABOT_GRP=ElementIDGRP_REM_STYPRABOT_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprGrpTypRabotImpl::get_ElementNAME_REM_STYPRABOT_GRP(void)
{
return Object->ElementNAME_REM_STYPRABOT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypRabotImpl::set_ElementNAME_REM_STYPRABOT_GRP(TFIBWideStringField * ElementNAME_REM_STYPRABOT_GRP)
{
Object->ElementNAME_REM_STYPRABOT_GRP=ElementNAME_REM_STYPRABOT_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprGrpTypRabotImpl::get_TableNAME_ENG_REM_STYPRABOT_GRP(void)
{
return Object->TableNAME_ENG_REM_STYPRABOT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypRabotImpl::set_TableNAME_ENG_REM_STYPRABOT_GRP(TFIBWideStringField * TableNAME_ENG_REM_STYPRABOT_GRP)
{
Object->TableNAME_ENG_REM_STYPRABOT_GRP=TableNAME_ENG_REM_STYPRABOT_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprGrpTypRabotImpl::get_ElementNAME_ENG_REM_STYPRABOT_GRP(void)
{
return Object->ElementNAME_ENG_REM_STYPRABOT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypRabotImpl::set_ElementNAME_ENG_REM_STYPRABOT_GRP(TFIBWideStringField * ElementNAME_ENG_REM_STYPRABOT_GRP)
{
Object->ElementNAME_ENG_REM_STYPRABOT_GRP=ElementNAME_ENG_REM_STYPRABOT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypRabotImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TREM_DMSprGrpTypRabotImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypRabotImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TREM_DMSprGrpTypRabotImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypRabotImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TREM_DMSprGrpTypRabotImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
