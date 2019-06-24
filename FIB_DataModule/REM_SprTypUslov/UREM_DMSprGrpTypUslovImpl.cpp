#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprGrpTypUslovImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprGrpTypUslovImpl::TREM_DMSprGrpTypUslovImpl()           
{                                            
Object=new TREM_DMSprGrpTypUslov(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprGrpTypUslovImpl::~TREM_DMSprGrpTypUslovImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprGrpTypUslovImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprGrpTypUslovImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprGrpTypUslov)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprGrpTypUslov*> (this);                                
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
int TREM_DMSprGrpTypUslovImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprGrpTypUslovImpl::kanRelease(void)                                  
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
int  TREM_DMSprGrpTypUslovImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprGrpTypUslovImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprGrpTypUslovImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprGrpTypUslovImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprGrpTypUslovImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprGrpTypUslovImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprGrpTypUslovImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprGrpTypUslov
TDataSource * TREM_DMSprGrpTypUslovImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypUslovImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprGrpTypUslovImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypUslovImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprGrpTypUslovImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypUslovImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprGrpTypUslovImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypUslovImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprGrpTypUslovImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypUslovImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprGrpTypUslovImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypUslovImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprGrpTypUslovImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypUslovImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprGrpTypUslovImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypUslovImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpTypUslovImpl::get_ElementID_REM_STYPUSLOV_GRP(void)
{
return Object->ElementID_REM_STYPUSLOV_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypUslovImpl::set_ElementID_REM_STYPUSLOV_GRP(TFIBLargeIntField * ElementID_REM_STYPUSLOV_GRP)
{
Object->ElementID_REM_STYPUSLOV_GRP=ElementID_REM_STYPUSLOV_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprGrpTypUslovImpl::get_ElementGID_REM_STYPUSLOV_GRP(void)
{
return Object->ElementGID_REM_STYPUSLOV_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypUslovImpl::set_ElementGID_REM_STYPUSLOV_GRP(TFIBWideStringField * ElementGID_REM_STYPUSLOV_GRP)
{
Object->ElementGID_REM_STYPUSLOV_GRP=ElementGID_REM_STYPUSLOV_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpTypUslovImpl::get_ElementIDBASE_REM_STYPUSLOV_GRP(void)
{
return Object->ElementIDBASE_REM_STYPUSLOV_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypUslovImpl::set_ElementIDBASE_REM_STYPUSLOV_GRP(TFIBLargeIntField * ElementIDBASE_REM_STYPUSLOV_GRP)
{
Object->ElementIDBASE_REM_STYPUSLOV_GRP=ElementIDBASE_REM_STYPUSLOV_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpTypUslovImpl::get_ElementIDGRP_REM_STYPUSLOV_GRP(void)
{
return Object->ElementIDGRP_REM_STYPUSLOV_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypUslovImpl::set_ElementIDGRP_REM_STYPUSLOV_GRP(TFIBLargeIntField * ElementIDGRP_REM_STYPUSLOV_GRP)
{
Object->ElementIDGRP_REM_STYPUSLOV_GRP=ElementIDGRP_REM_STYPUSLOV_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprGrpTypUslovImpl::get_ElementNAME_REM_STYPUSLOV_GRP(void)
{
return Object->ElementNAME_REM_STYPUSLOV_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypUslovImpl::set_ElementNAME_REM_STYPUSLOV_GRP(TFIBWideStringField * ElementNAME_REM_STYPUSLOV_GRP)
{
Object->ElementNAME_REM_STYPUSLOV_GRP=ElementNAME_REM_STYPUSLOV_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpTypUslovImpl::get_TableID_REM_STYPUSLOV_GRP(void)
{
return Object->TableID_REM_STYPUSLOV_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypUslovImpl::set_TableID_REM_STYPUSLOV_GRP(TFIBLargeIntField * TableID_REM_STYPUSLOV_GRP)
{
Object->TableID_REM_STYPUSLOV_GRP=TableID_REM_STYPUSLOV_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprGrpTypUslovImpl::get_TableGID_REM_STYPUSLOV_GRP(void)
{
return Object->TableGID_REM_STYPUSLOV_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypUslovImpl::set_TableGID_REM_STYPUSLOV_GRP(TFIBWideStringField * TableGID_REM_STYPUSLOV_GRP)
{
Object->TableGID_REM_STYPUSLOV_GRP=TableGID_REM_STYPUSLOV_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpTypUslovImpl::get_TableIDBASE_REM_STYPUSLOV_GRP(void)
{
return Object->TableIDBASE_REM_STYPUSLOV_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypUslovImpl::set_TableIDBASE_REM_STYPUSLOV_GRP(TFIBLargeIntField * TableIDBASE_REM_STYPUSLOV_GRP)
{
Object->TableIDBASE_REM_STYPUSLOV_GRP=TableIDBASE_REM_STYPUSLOV_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpTypUslovImpl::get_TableIDGRP_REM_STYPUSLOV_GRP(void)
{
return Object->TableIDGRP_REM_STYPUSLOV_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypUslovImpl::set_TableIDGRP_REM_STYPUSLOV_GRP(TFIBLargeIntField * TableIDGRP_REM_STYPUSLOV_GRP)
{
Object->TableIDGRP_REM_STYPUSLOV_GRP=TableIDGRP_REM_STYPUSLOV_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprGrpTypUslovImpl::get_TableNAME_REM_STYPUSLOV_GRP(void)
{
return Object->TableNAME_REM_STYPUSLOV_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypUslovImpl::set_TableNAME_REM_STYPUSLOV_GRP(TFIBWideStringField * TableNAME_REM_STYPUSLOV_GRP)
{
Object->TableNAME_REM_STYPUSLOV_GRP=TableNAME_REM_STYPUSLOV_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprGrpTypUslovImpl::get_TableNAME_ENG_REM_STYPUSLOV_GRP(void)
{
return Object->TableNAME_ENG_REM_STYPUSLOV_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypUslovImpl::set_TableNAME_ENG_REM_STYPUSLOV_GRP(TFIBWideStringField * TableNAME_ENG_REM_STYPUSLOV_GRP)
{
Object->TableNAME_ENG_REM_STYPUSLOV_GRP=TableNAME_ENG_REM_STYPUSLOV_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprGrpTypUslovImpl::get_ElementNAME_ENG_REM_STYPUSLOV_GRP(void)
{
return Object->ElementNAME_ENG_REM_STYPUSLOV_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypUslovImpl::set_ElementNAME_ENG_REM_STYPUSLOV_GRP(TFIBWideStringField * ElementNAME_ENG_REM_STYPUSLOV_GRP)
{
Object->ElementNAME_ENG_REM_STYPUSLOV_GRP=ElementNAME_ENG_REM_STYPUSLOV_GRP;
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypUslovImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TREM_DMSprGrpTypUslovImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypUslovImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TREM_DMSprGrpTypUslovImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TREM_DMSprGrpTypUslovImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
int TREM_DMSprGrpTypUslovImpl::GetIDElement(UnicodeString gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
__int64 TREM_DMSprGrpTypUslovImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
