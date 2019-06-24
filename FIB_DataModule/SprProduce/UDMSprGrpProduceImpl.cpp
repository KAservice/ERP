#include "vcl.h"
#pragma hdrstop


#include "UDMSprGrpProduceImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprGrpProduceImpl::TDMSprGrpProduceImpl()           
{                                            
Object=new TDMSprGrpProduce(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprGrpProduceImpl::~TDMSprGrpProduceImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprGrpProduceImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprGrpProduceImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprGrpProduce)                        
   {                                                                     
   *ppv=static_cast<IDMSprGrpProduce*> (this);                                
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
int TDMSprGrpProduceImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprGrpProduceImpl::kanRelease(void)                                  
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
int  TDMSprGrpProduceImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprGrpProduceImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprGrpProduceImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprGrpProduceImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprGrpProduceImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprGrpProduceImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprGrpProduceImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprGrpProduce
TDataSource * TDMSprGrpProduceImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprGrpProduceImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprGrpProduceImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprGrpProduceImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprGrpProduceImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprGrpProduceImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprGrpProduceImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprGrpProduceImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprGrpProduceImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprGrpProduceImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprGrpProduceImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprGrpProduceImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprGrpProduceImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprGrpProduceImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TIntegerField * TDMSprGrpProduceImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprGrpProduceImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprGrpProduceImpl::get_TableID_SPRODUCE_GRP(void)
{
return Object->TableID_SPRODUCE_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpProduceImpl::set_TableID_SPRODUCE_GRP(TFIBLargeIntField * TableID_SPRODUCE_GRP)
{
Object->TableID_SPRODUCE_GRP=TableID_SPRODUCE_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpProduceImpl::get_TableGID_SPRODUCE_GRP(void)
{
return Object->TableGID_SPRODUCE_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpProduceImpl::set_TableGID_SPRODUCE_GRP(TFIBWideStringField * TableGID_SPRODUCE_GRP)
{
Object->TableGID_SPRODUCE_GRP=TableGID_SPRODUCE_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprGrpProduceImpl::get_TableIDBASE_SPRODUCE_GRP(void)
{
return Object->TableIDBASE_SPRODUCE_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpProduceImpl::set_TableIDBASE_SPRODUCE_GRP(TFIBLargeIntField * TableIDBASE_SPRODUCE_GRP)
{
Object->TableIDBASE_SPRODUCE_GRP=TableIDBASE_SPRODUCE_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpProduceImpl::get_TableNAME_SPRODUCE_GRP(void)
{
return Object->TableNAME_SPRODUCE_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpProduceImpl::set_TableNAME_SPRODUCE_GRP(TFIBWideStringField * TableNAME_SPRODUCE_GRP)
{
Object->TableNAME_SPRODUCE_GRP=TableNAME_SPRODUCE_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprGrpProduceImpl::get_TableIDGRP_SPRODUCE_GRP(void)
{
return Object->TableIDGRP_SPRODUCE_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpProduceImpl::set_TableIDGRP_SPRODUCE_GRP(TFIBLargeIntField * TableIDGRP_SPRODUCE_GRP)
{
Object->TableIDGRP_SPRODUCE_GRP=TableIDGRP_SPRODUCE_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprGrpProduceImpl::get_ElementID_SPRODUCE_GRP(void)
{
return Object->ElementID_SPRODUCE_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpProduceImpl::set_ElementID_SPRODUCE_GRP(TFIBLargeIntField * ElementID_SPRODUCE_GRP)
{
Object->ElementID_SPRODUCE_GRP=ElementID_SPRODUCE_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpProduceImpl::get_ElementGID_SPRODUCE_GRP(void)
{
return Object->ElementGID_SPRODUCE_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpProduceImpl::set_ElementGID_SPRODUCE_GRP(TFIBWideStringField * ElementGID_SPRODUCE_GRP)
{
Object->ElementGID_SPRODUCE_GRP=ElementGID_SPRODUCE_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprGrpProduceImpl::get_ElementIDBASE_SPRODUCE_GRP(void)
{
return Object->ElementIDBASE_SPRODUCE_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpProduceImpl::set_ElementIDBASE_SPRODUCE_GRP(TFIBLargeIntField * ElementIDBASE_SPRODUCE_GRP)
{
Object->ElementIDBASE_SPRODUCE_GRP=ElementIDBASE_SPRODUCE_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpProduceImpl::get_ElementNAME_SPRODUCE_GRP(void)
{
return Object->ElementNAME_SPRODUCE_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpProduceImpl::set_ElementNAME_SPRODUCE_GRP(TFIBWideStringField * ElementNAME_SPRODUCE_GRP)
{
Object->ElementNAME_SPRODUCE_GRP=ElementNAME_SPRODUCE_GRP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprGrpProduceImpl::get_ElementIDGRP_SPRODUCE_GRP(void)
{
return Object->ElementIDGRP_SPRODUCE_GRP;
}
//---------------------------------------------------------------
void TDMSprGrpProduceImpl::set_ElementIDGRP_SPRODUCE_GRP(TFIBLargeIntField * ElementIDGRP_SPRODUCE_GRP)
{
Object->ElementIDGRP_SPRODUCE_GRP=ElementIDGRP_SPRODUCE_GRP;
}
//---------------------------------------------------------------
bool TDMSprGrpProduceImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
bool TDMSprGrpProduceImpl::OpenElement(__int64 id)
{
return Object->OpenElement( id);
}
//---------------------------------------------------------------
bool TDMSprGrpProduceImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TDMSprGrpProduceImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprGrpProduceImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TDMSprGrpProduceImpl::GetIDElement(UnicodeString gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
UnicodeString TDMSprGrpProduceImpl::GetGIDElement(__int64 id)
{
return Object->GetGIDElement(id);
}
//---------------------------------------------------------------
__int64 TDMSprGrpProduceImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
