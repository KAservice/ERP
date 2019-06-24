#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprGrpKKTImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprGrpKKTImpl::TREM_DMSprGrpKKTImpl()           
{                                            
Object=new TREM_DMSprGrpKKT(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprGrpKKTImpl::~TREM_DMSprGrpKKTImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprGrpKKTImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprGrpKKTImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprGrpKKT)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprGrpKKT*> (this);                                
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
int TREM_DMSprGrpKKTImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprGrpKKTImpl::kanRelease(void)                                  
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
int  TREM_DMSprGrpKKTImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprGrpKKTImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprGrpKKTImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprGrpKKTImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprGrpKKTImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprGrpKKTImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprGrpKKTImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprGrpKKT
TDataSource * TREM_DMSprGrpKKTImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprGrpKKTImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprGrpKKTImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprGrpKKTImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprGrpKKTImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprGrpKKTImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprGrpKKTImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprGrpKKTImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprGrpKKTImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprGrpKKTImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprGrpKKTImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprGrpKKTImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprGrpKKTImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMSprGrpKKTImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprGrpKKTImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprGrpKKTImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpKKTImpl::get_TableID_REM_SGRPKKT(void)
{
return Object->TableID_REM_SGRPKKT;
}
//---------------------------------------------------------------
void TREM_DMSprGrpKKTImpl::set_TableID_REM_SGRPKKT(TFIBLargeIntField * TableID_REM_SGRPKKT)
{
Object->TableID_REM_SGRPKKT=TableID_REM_SGRPKKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpKKTImpl::get_TableIDBASE_REM_SGRPKKT(void)
{
return Object->TableIDBASE_REM_SGRPKKT;
}
//---------------------------------------------------------------
void TREM_DMSprGrpKKTImpl::set_TableIDBASE_REM_SGRPKKT(TFIBLargeIntField * TableIDBASE_REM_SGRPKKT)
{
Object->TableIDBASE_REM_SGRPKKT=TableIDBASE_REM_SGRPKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprGrpKKTImpl::get_TableNAME_REM_SGRPKKT(void)
{
return Object->TableNAME_REM_SGRPKKT;
}
//---------------------------------------------------------------
void TREM_DMSprGrpKKTImpl::set_TableNAME_REM_SGRPKKT(TFIBWideStringField * TableNAME_REM_SGRPKKT)
{
Object->TableNAME_REM_SGRPKKT=TableNAME_REM_SGRPKKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpKKTImpl::get_TableIDGRP_REM_SGRPKKT(void)
{
return Object->TableIDGRP_REM_SGRPKKT;
}
//---------------------------------------------------------------
void TREM_DMSprGrpKKTImpl::set_TableIDGRP_REM_SGRPKKT(TFIBLargeIntField * TableIDGRP_REM_SGRPKKT)
{
Object->TableIDGRP_REM_SGRPKKT=TableIDGRP_REM_SGRPKKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpKKTImpl::get_ElementID_REM_SGRPKKT(void)
{
return Object->ElementID_REM_SGRPKKT;
}
//---------------------------------------------------------------
void TREM_DMSprGrpKKTImpl::set_ElementID_REM_SGRPKKT(TFIBLargeIntField * ElementID_REM_SGRPKKT)
{
Object->ElementID_REM_SGRPKKT=ElementID_REM_SGRPKKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpKKTImpl::get_ElementIDBASE_REM_SGRPKKT(void)
{
return Object->ElementIDBASE_REM_SGRPKKT;
}
//---------------------------------------------------------------
void TREM_DMSprGrpKKTImpl::set_ElementIDBASE_REM_SGRPKKT(TFIBLargeIntField * ElementIDBASE_REM_SGRPKKT)
{
Object->ElementIDBASE_REM_SGRPKKT=ElementIDBASE_REM_SGRPKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprGrpKKTImpl::get_ElementNAME_REM_SGRPKKT(void)
{
return Object->ElementNAME_REM_SGRPKKT;
}
//---------------------------------------------------------------
void TREM_DMSprGrpKKTImpl::set_ElementNAME_REM_SGRPKKT(TFIBWideStringField * ElementNAME_REM_SGRPKKT)
{
Object->ElementNAME_REM_SGRPKKT=ElementNAME_REM_SGRPKKT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprGrpKKTImpl::get_ElementIDGRP_REM_SGRPKKT(void)
{
return Object->ElementIDGRP_REM_SGRPKKT;
}
//---------------------------------------------------------------
void TREM_DMSprGrpKKTImpl::set_ElementIDGRP_REM_SGRPKKT(TFIBLargeIntField * ElementIDGRP_REM_SGRPKKT)
{
Object->ElementIDGRP_REM_SGRPKKT=ElementIDGRP_REM_SGRPKKT;
}
//---------------------------------------------------------------
void TREM_DMSprGrpKKTImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TREM_DMSprGrpKKTImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TREM_DMSprGrpKKTImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TREM_DMSprGrpKKTImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMSprGrpKKTImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TREM_DMSprGrpKKTImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
