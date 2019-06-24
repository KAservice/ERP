#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprGrpModelImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprGrpModelImpl::TREM_DMSprGrpModelImpl()           
{                                            
Object=new TREM_DMSprGrpModel(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprGrpModelImpl::~TREM_DMSprGrpModelImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprGrpModelImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprGrpModelImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprGrpModel)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprGrpModel*> (this);                                
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
int TREM_DMSprGrpModelImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprGrpModelImpl::kanRelease(void)                                  
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
int  TREM_DMSprGrpModelImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprGrpModelImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprGrpModelImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprGrpModelImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprGrpModelImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprGrpModelImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprGrpModelImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprGrpModel
TDataSource * TREM_DMSprGrpModelImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprGrpModelImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprGrpModelImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprGrpModelImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprGrpModelImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprGrpModelImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprGrpModelImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprGrpModelImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprGrpModelImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprGrpModelImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprGrpModelImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprGrpModelImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprGrpModelImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMSprGrpModelImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprGrpModelImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprGrpModelImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpModelImpl::get_TableID_REM_SGRPMODEL(void)
{
return Object->TableID_REM_SGRPMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprGrpModelImpl::set_TableID_REM_SGRPMODEL(TFIBLargeIntField * TableID_REM_SGRPMODEL)
{
Object->TableID_REM_SGRPMODEL=TableID_REM_SGRPMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprGrpModelImpl::get_TableGID_REM_SGRPMODEL(void)
{
return Object->TableGID_REM_SGRPMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprGrpModelImpl::set_TableGID_REM_SGRPMODEL(TFIBWideStringField * TableGID_REM_SGRPMODEL)
{
Object->TableGID_REM_SGRPMODEL=TableGID_REM_SGRPMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpModelImpl::get_TableIDGRP_REM_SGRPMODEL(void)
{
return Object->TableIDGRP_REM_SGRPMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprGrpModelImpl::set_TableIDGRP_REM_SGRPMODEL(TFIBLargeIntField * TableIDGRP_REM_SGRPMODEL)
{
Object->TableIDGRP_REM_SGRPMODEL=TableIDGRP_REM_SGRPMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprGrpModelImpl::get_TableNAME_REM_SGRPMODEL(void)
{
return Object->TableNAME_REM_SGRPMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprGrpModelImpl::set_TableNAME_REM_SGRPMODEL(TFIBWideStringField * TableNAME_REM_SGRPMODEL)
{
Object->TableNAME_REM_SGRPMODEL=TableNAME_REM_SGRPMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpModelImpl::get_TableIDBASE_REM_SGRPMODEL(void)
{
return Object->TableIDBASE_REM_SGRPMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprGrpModelImpl::set_TableIDBASE_REM_SGRPMODEL(TFIBLargeIntField * TableIDBASE_REM_SGRPMODEL)
{
Object->TableIDBASE_REM_SGRPMODEL=TableIDBASE_REM_SGRPMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpModelImpl::get_ElementID_REM_SGRPMODEL(void)
{
return Object->ElementID_REM_SGRPMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprGrpModelImpl::set_ElementID_REM_SGRPMODEL(TFIBLargeIntField * ElementID_REM_SGRPMODEL)
{
Object->ElementID_REM_SGRPMODEL=ElementID_REM_SGRPMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprGrpModelImpl::get_ElementGID_REM_SGRPMODEL(void)
{
return Object->ElementGID_REM_SGRPMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprGrpModelImpl::set_ElementGID_REM_SGRPMODEL(TFIBWideStringField * ElementGID_REM_SGRPMODEL)
{
Object->ElementGID_REM_SGRPMODEL=ElementGID_REM_SGRPMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpModelImpl::get_ElementIDGRP_REM_SGRPMODEL(void)
{
return Object->ElementIDGRP_REM_SGRPMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprGrpModelImpl::set_ElementIDGRP_REM_SGRPMODEL(TFIBLargeIntField * ElementIDGRP_REM_SGRPMODEL)
{
Object->ElementIDGRP_REM_SGRPMODEL=ElementIDGRP_REM_SGRPMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprGrpModelImpl::get_ElementNAME_REM_SGRPMODEL(void)
{
return Object->ElementNAME_REM_SGRPMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprGrpModelImpl::set_ElementNAME_REM_SGRPMODEL(TFIBWideStringField * ElementNAME_REM_SGRPMODEL)
{
Object->ElementNAME_REM_SGRPMODEL=ElementNAME_REM_SGRPMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpModelImpl::get_ElementIDBASE_REM_SGRPMODEL(void)
{
return Object->ElementIDBASE_REM_SGRPMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprGrpModelImpl::set_ElementIDBASE_REM_SGRPMODEL(TFIBLargeIntField * ElementIDBASE_REM_SGRPMODEL)
{
Object->ElementIDBASE_REM_SGRPMODEL=ElementIDBASE_REM_SGRPMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprGrpModelImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TREM_DMSprGrpModelImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TREM_DMSprGrpModelImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TREM_DMSprGrpModelImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TREM_DMSprGrpModelImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
int TREM_DMSprGrpModelImpl::GetIDElement(UnicodeString gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
__int64 TREM_DMSprGrpModelImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
