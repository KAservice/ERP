#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprGrpTypDefectImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprGrpTypDefectImpl::TREM_DMSprGrpTypDefectImpl()           
{                                            
Object=new TREM_DMSprGrpTypDefect(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprGrpTypDefectImpl::~TREM_DMSprGrpTypDefectImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprGrpTypDefectImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprGrpTypDefectImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprGrpTypDefect)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprGrpTypDefect*> (this);                                
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
int TREM_DMSprGrpTypDefectImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprGrpTypDefectImpl::kanRelease(void)                                  
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
int  TREM_DMSprGrpTypDefectImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprGrpTypDefectImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprGrpTypDefectImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprGrpTypDefectImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprGrpTypDefectImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprGrpTypDefectImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprGrpTypDefectImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprGrpTypDefect
TDataSource * TREM_DMSprGrpTypDefectImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypDefectImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprGrpTypDefectImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypDefectImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprGrpTypDefectImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypDefectImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprGrpTypDefectImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypDefectImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprGrpTypDefectImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypDefectImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprGrpTypDefectImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypDefectImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprGrpTypDefectImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypDefectImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprGrpTypDefectImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypDefectImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpTypDefectImpl::get_TableID_REM_STYPDEFECT_GRP(void)
{
return Object->TableID_REM_STYPDEFECT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypDefectImpl::set_TableID_REM_STYPDEFECT_GRP(TFIBLargeIntField * TableID_REM_STYPDEFECT_GRP)
{
Object->TableID_REM_STYPDEFECT_GRP=TableID_REM_STYPDEFECT_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpTypDefectImpl::get_TableIDBASE_REM_STYPDEFECT_GRP(void)
{
return Object->TableIDBASE_REM_STYPDEFECT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypDefectImpl::set_TableIDBASE_REM_STYPDEFECT_GRP(TFIBLargeIntField * TableIDBASE_REM_STYPDEFECT_GRP)
{
Object->TableIDBASE_REM_STYPDEFECT_GRP=TableIDBASE_REM_STYPDEFECT_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprGrpTypDefectImpl::get_TableNAME_REM_STYPDEFECT_GRP(void)
{
return Object->TableNAME_REM_STYPDEFECT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypDefectImpl::set_TableNAME_REM_STYPDEFECT_GRP(TFIBWideStringField * TableNAME_REM_STYPDEFECT_GRP)
{
Object->TableNAME_REM_STYPDEFECT_GRP=TableNAME_REM_STYPDEFECT_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpTypDefectImpl::get_TableIDGRP_REM_STYPDEFECT_GRP(void)
{
return Object->TableIDGRP_REM_STYPDEFECT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypDefectImpl::set_TableIDGRP_REM_STYPDEFECT_GRP(TFIBLargeIntField * TableIDGRP_REM_STYPDEFECT_GRP)
{
Object->TableIDGRP_REM_STYPDEFECT_GRP=TableIDGRP_REM_STYPDEFECT_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprGrpTypDefectImpl::get_TableGID_REM_STYPDEFECT_GRP(void)
{
return Object->TableGID_REM_STYPDEFECT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypDefectImpl::set_TableGID_REM_STYPDEFECT_GRP(TFIBWideStringField * TableGID_REM_STYPDEFECT_GRP)
{
Object->TableGID_REM_STYPDEFECT_GRP=TableGID_REM_STYPDEFECT_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpTypDefectImpl::get_ElementID_REM_STYPDEFECT_GRP(void)
{
return Object->ElementID_REM_STYPDEFECT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypDefectImpl::set_ElementID_REM_STYPDEFECT_GRP(TFIBLargeIntField * ElementID_REM_STYPDEFECT_GRP)
{
Object->ElementID_REM_STYPDEFECT_GRP=ElementID_REM_STYPDEFECT_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpTypDefectImpl::get_ElementIDBASE_REM_STYPDEFECT_GRP(void)
{
return Object->ElementIDBASE_REM_STYPDEFECT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypDefectImpl::set_ElementIDBASE_REM_STYPDEFECT_GRP(TFIBLargeIntField * ElementIDBASE_REM_STYPDEFECT_GRP)
{
Object->ElementIDBASE_REM_STYPDEFECT_GRP=ElementIDBASE_REM_STYPDEFECT_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprGrpTypDefectImpl::get_ElementNAME_REM_STYPDEFECT_GRP(void)
{
return Object->ElementNAME_REM_STYPDEFECT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypDefectImpl::set_ElementNAME_REM_STYPDEFECT_GRP(TFIBWideStringField * ElementNAME_REM_STYPDEFECT_GRP)
{
Object->ElementNAME_REM_STYPDEFECT_GRP=ElementNAME_REM_STYPDEFECT_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpTypDefectImpl::get_ElementIDGRP_REM_STYPDEFECT_GRP(void)
{
return Object->ElementIDGRP_REM_STYPDEFECT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypDefectImpl::set_ElementIDGRP_REM_STYPDEFECT_GRP(TFIBLargeIntField * ElementIDGRP_REM_STYPDEFECT_GRP)
{
Object->ElementIDGRP_REM_STYPDEFECT_GRP=ElementIDGRP_REM_STYPDEFECT_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprGrpTypDefectImpl::get_ElementGID_REM_STYPDEFECT_GRP(void)
{
return Object->ElementGID_REM_STYPDEFECT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypDefectImpl::set_ElementGID_REM_STYPDEFECT_GRP(TFIBWideStringField * ElementGID_REM_STYPDEFECT_GRP)
{
Object->ElementGID_REM_STYPDEFECT_GRP=ElementGID_REM_STYPDEFECT_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprGrpTypDefectImpl::get_TableNAME_ENG_REM_STYPDEFECT_GRP(void)
{
return Object->TableNAME_ENG_REM_STYPDEFECT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypDefectImpl::set_TableNAME_ENG_REM_STYPDEFECT_GRP(TFIBWideStringField * TableNAME_ENG_REM_STYPDEFECT_GRP)
{
Object->TableNAME_ENG_REM_STYPDEFECT_GRP=TableNAME_ENG_REM_STYPDEFECT_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypDefectImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TREM_DMSprGrpTypDefectImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypDefectImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TREM_DMSprGrpTypDefectImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypDefectImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TREM_DMSprGrpTypDefectImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
