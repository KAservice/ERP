#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprGrpNeisprImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprGrpNeisprImpl::TREM_DMSprGrpNeisprImpl()           
{                                            
Object=new TREM_DMSprGrpNeispr(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprGrpNeisprImpl::~TREM_DMSprGrpNeisprImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprGrpNeisprImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprGrpNeisprImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprGrpNeispr)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprGrpNeispr*> (this);                                
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
int TREM_DMSprGrpNeisprImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprGrpNeisprImpl::kanRelease(void)                                  
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
int  TREM_DMSprGrpNeisprImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprGrpNeisprImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprGrpNeisprImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprGrpNeisprImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprGrpNeisprImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprGrpNeisprImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprGrpNeisprImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprGrpNeispr
TDataSource * TREM_DMSprGrpNeisprImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprGrpNeisprImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprGrpNeisprImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprGrpNeisprImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprGrpNeisprImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprGrpNeisprImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprGrpNeisprImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprGrpNeisprImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprGrpNeisprImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprGrpNeisprImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprGrpNeisprImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprGrpNeisprImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprGrpNeisprImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMSprGrpNeisprImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprGrpNeisprImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprGrpNeisprImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpNeisprImpl::get_TableID_REM_SGRPNEISPR(void)
{
return Object->TableID_REM_SGRPNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprGrpNeisprImpl::set_TableID_REM_SGRPNEISPR(TFIBLargeIntField * TableID_REM_SGRPNEISPR)
{
Object->TableID_REM_SGRPNEISPR=TableID_REM_SGRPNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprGrpNeisprImpl::get_TableGID_REM_SGRPNEISPR(void)
{
return Object->TableGID_REM_SGRPNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprGrpNeisprImpl::set_TableGID_REM_SGRPNEISPR(TFIBWideStringField * TableGID_REM_SGRPNEISPR)
{
Object->TableGID_REM_SGRPNEISPR=TableGID_REM_SGRPNEISPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpNeisprImpl::get_TableIDGRP_REM_SGRPNEISPR(void)
{
return Object->TableIDGRP_REM_SGRPNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprGrpNeisprImpl::set_TableIDGRP_REM_SGRPNEISPR(TFIBLargeIntField * TableIDGRP_REM_SGRPNEISPR)
{
Object->TableIDGRP_REM_SGRPNEISPR=TableIDGRP_REM_SGRPNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprGrpNeisprImpl::get_TableNAME_REM_SGRPNEISPR(void)
{
return Object->TableNAME_REM_SGRPNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprGrpNeisprImpl::set_TableNAME_REM_SGRPNEISPR(TFIBWideStringField * TableNAME_REM_SGRPNEISPR)
{
Object->TableNAME_REM_SGRPNEISPR=TableNAME_REM_SGRPNEISPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpNeisprImpl::get_TableIDBASE_REM_SGRPNEISPR(void)
{
return Object->TableIDBASE_REM_SGRPNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprGrpNeisprImpl::set_TableIDBASE_REM_SGRPNEISPR(TFIBLargeIntField * TableIDBASE_REM_SGRPNEISPR)
{
Object->TableIDBASE_REM_SGRPNEISPR=TableIDBASE_REM_SGRPNEISPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpNeisprImpl::get_ElementID_REM_SGRPNEISPR(void)
{
return Object->ElementID_REM_SGRPNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprGrpNeisprImpl::set_ElementID_REM_SGRPNEISPR(TFIBLargeIntField * ElementID_REM_SGRPNEISPR)
{
Object->ElementID_REM_SGRPNEISPR=ElementID_REM_SGRPNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprGrpNeisprImpl::get_ElementGID_REM_SGRPNEISPR(void)
{
return Object->ElementGID_REM_SGRPNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprGrpNeisprImpl::set_ElementGID_REM_SGRPNEISPR(TFIBWideStringField * ElementGID_REM_SGRPNEISPR)
{
Object->ElementGID_REM_SGRPNEISPR=ElementGID_REM_SGRPNEISPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpNeisprImpl::get_ElementIDGRP_REM_SGRPNEISPR(void)
{
return Object->ElementIDGRP_REM_SGRPNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprGrpNeisprImpl::set_ElementIDGRP_REM_SGRPNEISPR(TFIBLargeIntField * ElementIDGRP_REM_SGRPNEISPR)
{
Object->ElementIDGRP_REM_SGRPNEISPR=ElementIDGRP_REM_SGRPNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprGrpNeisprImpl::get_ElementNAME_REM_SGRPNEISPR(void)
{
return Object->ElementNAME_REM_SGRPNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprGrpNeisprImpl::set_ElementNAME_REM_SGRPNEISPR(TFIBWideStringField * ElementNAME_REM_SGRPNEISPR)
{
Object->ElementNAME_REM_SGRPNEISPR=ElementNAME_REM_SGRPNEISPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpNeisprImpl::get_ElementIDBASE_REM_SGRPNEISPR(void)
{
return Object->ElementIDBASE_REM_SGRPNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprGrpNeisprImpl::set_ElementIDBASE_REM_SGRPNEISPR(TFIBLargeIntField * ElementIDBASE_REM_SGRPNEISPR)
{
Object->ElementIDBASE_REM_SGRPNEISPR=ElementIDBASE_REM_SGRPNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprGrpNeisprImpl::get_ElementNAME_ENG_REM_SGRPNEISPR(void)
{
return Object->ElementNAME_ENG_REM_SGRPNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprGrpNeisprImpl::set_ElementNAME_ENG_REM_SGRPNEISPR(TFIBWideStringField * ElementNAME_ENG_REM_SGRPNEISPR)
{
Object->ElementNAME_ENG_REM_SGRPNEISPR=ElementNAME_ENG_REM_SGRPNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprGrpNeisprImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TREM_DMSprGrpNeisprImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TREM_DMSprGrpNeisprImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TREM_DMSprGrpNeisprImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TREM_DMSprGrpNeisprImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
int TREM_DMSprGrpNeisprImpl::GetIDElement(UnicodeString gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
