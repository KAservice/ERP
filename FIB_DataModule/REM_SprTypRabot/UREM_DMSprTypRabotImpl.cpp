#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprTypRabotImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprTypRabotImpl::TREM_DMSprTypRabotImpl()           
{                                            
Object=new TREM_DMSprTypRabot(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprTypRabotImpl::~TREM_DMSprTypRabotImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprTypRabotImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprTypRabot)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprTypRabot*> (this);                                
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
int TREM_DMSprTypRabotImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprTypRabotImpl::kanRelease(void)                                  
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
int  TREM_DMSprTypRabotImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprTypRabotImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprTypRabotImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprTypRabotImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprTypRabotImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprTypRabot
TDataSource * TREM_DMSprTypRabotImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprTypRabotImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprTypRabotImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprTypRabotImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprTypRabotImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprTypRabotImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprTypRabotImpl::get_pFIBQuery(void)
{
return Object->pFIBQuery;
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_pFIBQuery(TpFIBQuery * pFIBQuery)
{
Object->pFIBQuery=pFIBQuery;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprTypRabotImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTypRabotImpl::get_TableID_REM_STYPRABOT(void)
{
return Object->TableID_REM_STYPRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_TableID_REM_STYPRABOT(TFIBLargeIntField * TableID_REM_STYPRABOT)
{
Object->TableID_REM_STYPRABOT=TableID_REM_STYPRABOT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypRabotImpl::get_TableGID_REM_STYPRABOT(void)
{
return Object->TableGID_REM_STYPRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_TableGID_REM_STYPRABOT(TFIBWideStringField * TableGID_REM_STYPRABOT)
{
Object->TableGID_REM_STYPRABOT=TableGID_REM_STYPRABOT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTypRabotImpl::get_TableIDBASE_REM_STYPRABOT(void)
{
return Object->TableIDBASE_REM_STYPRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_TableIDBASE_REM_STYPRABOT(TFIBLargeIntField * TableIDBASE_REM_STYPRABOT)
{
Object->TableIDBASE_REM_STYPRABOT=TableIDBASE_REM_STYPRABOT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTypRabotImpl::get_TableIDGRP_REM_STYPRABOT(void)
{
return Object->TableIDGRP_REM_STYPRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_TableIDGRP_REM_STYPRABOT(TFIBLargeIntField * TableIDGRP_REM_STYPRABOT)
{
Object->TableIDGRP_REM_STYPRABOT=TableIDGRP_REM_STYPRABOT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTypRabotImpl::get_TableIDNOM_REM_STYPRABOT(void)
{
return Object->TableIDNOM_REM_STYPRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_TableIDNOM_REM_STYPRABOT(TFIBLargeIntField * TableIDNOM_REM_STYPRABOT)
{
Object->TableIDNOM_REM_STYPRABOT=TableIDNOM_REM_STYPRABOT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypRabotImpl::get_TableNAME_REM_STYPRABOT(void)
{
return Object->TableNAME_REM_STYPRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_TableNAME_REM_STYPRABOT(TFIBWideStringField * TableNAME_REM_STYPRABOT)
{
Object->TableNAME_REM_STYPRABOT=TableNAME_REM_STYPRABOT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypRabotImpl::get_TableDESCR_REM_STYPRABOT(void)
{
return Object->TableDESCR_REM_STYPRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_TableDESCR_REM_STYPRABOT(TFIBWideStringField * TableDESCR_REM_STYPRABOT)
{
Object->TableDESCR_REM_STYPRABOT=TableDESCR_REM_STYPRABOT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypRabotImpl::get_TableNAMENOM(void)
{
return Object->TableNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_TableNAMENOM(TFIBWideStringField * TableNAMENOM)
{
Object->TableNAMENOM=TableNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypRabotImpl::get_TableARTNOM(void)
{
return Object->TableARTNOM;
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_TableARTNOM(TFIBWideStringField * TableARTNOM)
{
Object->TableARTNOM=TableARTNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMSprTypRabotImpl::get_TableCODENOM(void)
{
return Object->TableCODENOM;
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_TableCODENOM(TFIBIntegerField * TableCODENOM)
{
Object->TableCODENOM=TableCODENOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTypRabotImpl::get_ElementID_REM_STYPRABOT(void)
{
return Object->ElementID_REM_STYPRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_ElementID_REM_STYPRABOT(TFIBLargeIntField * ElementID_REM_STYPRABOT)
{
Object->ElementID_REM_STYPRABOT=ElementID_REM_STYPRABOT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypRabotImpl::get_ElementGID_REM_STYPRABOT(void)
{
return Object->ElementGID_REM_STYPRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_ElementGID_REM_STYPRABOT(TFIBWideStringField * ElementGID_REM_STYPRABOT)
{
Object->ElementGID_REM_STYPRABOT=ElementGID_REM_STYPRABOT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTypRabotImpl::get_ElementIDBASE_REM_STYPRABOT(void)
{
return Object->ElementIDBASE_REM_STYPRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_ElementIDBASE_REM_STYPRABOT(TFIBLargeIntField * ElementIDBASE_REM_STYPRABOT)
{
Object->ElementIDBASE_REM_STYPRABOT=ElementIDBASE_REM_STYPRABOT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTypRabotImpl::get_ElementIDGRP_REM_STYPRABOT(void)
{
return Object->ElementIDGRP_REM_STYPRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_ElementIDGRP_REM_STYPRABOT(TFIBLargeIntField * ElementIDGRP_REM_STYPRABOT)
{
Object->ElementIDGRP_REM_STYPRABOT=ElementIDGRP_REM_STYPRABOT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprTypRabotImpl::get_ElementIDNOM_REM_STYPRABOT(void)
{
return Object->ElementIDNOM_REM_STYPRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_ElementIDNOM_REM_STYPRABOT(TFIBLargeIntField * ElementIDNOM_REM_STYPRABOT)
{
Object->ElementIDNOM_REM_STYPRABOT=ElementIDNOM_REM_STYPRABOT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypRabotImpl::get_ElementNAME_REM_STYPRABOT(void)
{
return Object->ElementNAME_REM_STYPRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_ElementNAME_REM_STYPRABOT(TFIBWideStringField * ElementNAME_REM_STYPRABOT)
{
Object->ElementNAME_REM_STYPRABOT=ElementNAME_REM_STYPRABOT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypRabotImpl::get_ElementDESCR_REM_STYPRABOT(void)
{
return Object->ElementDESCR_REM_STYPRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_ElementDESCR_REM_STYPRABOT(TFIBWideStringField * ElementDESCR_REM_STYPRABOT)
{
Object->ElementDESCR_REM_STYPRABOT=ElementDESCR_REM_STYPRABOT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypRabotImpl::get_ElementNAMENOM(void)
{
return Object->ElementNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_ElementNAMENOM(TFIBWideStringField * ElementNAMENOM)
{
Object->ElementNAMENOM=ElementNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypRabotImpl::get_ElementARTNOM(void)
{
return Object->ElementARTNOM;
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_ElementARTNOM(TFIBWideStringField * ElementARTNOM)
{
Object->ElementARTNOM=ElementARTNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMSprTypRabotImpl::get_ElementCODENOM(void)
{
return Object->ElementCODENOM;
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_ElementCODENOM(TFIBIntegerField * ElementCODENOM)
{
Object->ElementCODENOM=ElementCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypRabotImpl::get_TableNAME_ENG_REM_STYPRABOT(void)
{
return Object->TableNAME_ENG_REM_STYPRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_TableNAME_ENG_REM_STYPRABOT(TFIBWideStringField * TableNAME_ENG_REM_STYPRABOT)
{
Object->TableNAME_ENG_REM_STYPRABOT=TableNAME_ENG_REM_STYPRABOT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprTypRabotImpl::get_ElementNAME_ENG_REM_STYPRABOT(void)
{
return Object->ElementNAME_ENG_REM_STYPRABOT;
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_ElementNAME_ENG_REM_STYPRABOT(TFIBWideStringField * ElementNAME_ENG_REM_STYPRABOT)
{
Object->ElementNAME_ENG_REM_STYPRABOT=ElementNAME_ENG_REM_STYPRABOT;
}
//---------------------------------------------------------------
__int64 TREM_DMSprTypRabotImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TREM_DMSprTypRabotImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
UnicodeString TREM_DMSprTypRabotImpl::GetTextQuery(__int64 id_grp, bool all)
{
return Object->GetTextQuery(id_grp, all);
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::OpenTable(__int64 id_grp, bool all)
{
return Object->OpenTable(id_grp, all);
}
//---------------------------------------------------------------
int TREM_DMSprTypRabotImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprTypRabotImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TREM_DMSprTypRabotImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMSprTypRabotImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
void TREM_DMSprTypRabotImpl::ChancheGrp(__int64 id_new_grp, __int64 id_el)
{
return Object->ChancheGrp(id_new_grp,id_el);
}
//---------------------------------------------------------------
__int64 TREM_DMSprTypRabotImpl::GetIdGrpTypRabot(__int64 id)
{
return Object->GetIdGrpTypRabot(id);
}
//---------------------------------------------------------------
__int64 TREM_DMSprTypRabotImpl::FindPoNom(__int64 id_nom)
{
return Object->FindPoNom(id_nom);
}
//---------------------------------------------------------------
