#include "vcl.h"
#pragma hdrstop


#include "UUDMSprSkladImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TUDMSprSkladImpl::TUDMSprSkladImpl()           
{                                            
Object=new TUDMSprSklad(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TUDMSprSkladImpl::~TUDMSprSkladImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TUDMSprSkladImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TUDMSprSkladImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IUDMSprSklad)                        
   {                                                                     
   *ppv=static_cast<IUDMSprSklad*> (this);                                
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
int TUDMSprSkladImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TUDMSprSkladImpl::kanRelease(void)                                  
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
int  TUDMSprSkladImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TUDMSprSkladImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TUDMSprSkladImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TUDMSprSkladImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TUDMSprSkladImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TUDMSprSkladImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TUDMSprSkladImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IUDMSprSklad
TDataSource * TUDMSprSkladImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TUDMSprSkladImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TUDMSprSkladImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TUDMSprSkladImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TUDMSprSkladImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TUDMSprSkladImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TUDMSprSkladImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TUDMSprSkladImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TUDMSprSkladImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TUDMSprSkladImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TUDMSprSkladImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TUDMSprSkladImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBIntegerField * TUDMSprSkladImpl::get_TableTSKLAD(void)
{
return Object->TableTSKLAD;
}
//---------------------------------------------------------------
void TUDMSprSkladImpl::set_TableTSKLAD(TFIBIntegerField * TableTSKLAD)
{
Object->TableTSKLAD=TableTSKLAD;
}
//---------------------------------------------------------------
TIntegerField * TUDMSprSkladImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TUDMSprSkladImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBIntegerField * TUDMSprSkladImpl::get_ElementTSKLAD(void)
{
return Object->ElementTSKLAD;
}
//---------------------------------------------------------------
void TUDMSprSkladImpl::set_ElementTSKLAD(TFIBIntegerField * ElementTSKLAD)
{
Object->ElementTSKLAD=ElementTSKLAD;
}
//---------------------------------------------------------------
TpFIBQuery * TUDMSprSkladImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TUDMSprSkladImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBBCDField * TUDMSprSkladImpl::get_TableIDSKLAD(void)
{
return Object->TableIDSKLAD;
}
//---------------------------------------------------------------
void TUDMSprSkladImpl::set_TableIDSKLAD(TFIBBCDField * TableIDSKLAD)
{
Object->TableIDSKLAD=TableIDSKLAD;
}
//---------------------------------------------------------------
TFIBBCDField * TUDMSprSkladImpl::get_ElementIDSKLAD(void)
{
return Object->ElementIDSKLAD;
}
//---------------------------------------------------------------
void TUDMSprSkladImpl::set_ElementIDSKLAD(TFIBBCDField * ElementIDSKLAD)
{
Object->ElementIDSKLAD=ElementIDSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TUDMSprSkladImpl::get_TableNAMESKLAD(void)
{
return Object->TableNAMESKLAD;
}
//---------------------------------------------------------------
void TUDMSprSkladImpl::set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)
{
Object->TableNAMESKLAD=TableNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TUDMSprSkladImpl::get_TableMOLSKLAD(void)
{
return Object->TableMOLSKLAD;
}
//---------------------------------------------------------------
void TUDMSprSkladImpl::set_TableMOLSKLAD(TFIBWideStringField * TableMOLSKLAD)
{
Object->TableMOLSKLAD=TableMOLSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TUDMSprSkladImpl::get_TableADRSKLAD(void)
{
return Object->TableADRSKLAD;
}
//---------------------------------------------------------------
void TUDMSprSkladImpl::set_TableADRSKLAD(TFIBWideStringField * TableADRSKLAD)
{
Object->TableADRSKLAD=TableADRSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TUDMSprSkladImpl::get_TableGID_SSKLAD(void)
{
return Object->TableGID_SSKLAD;
}
//---------------------------------------------------------------
void TUDMSprSkladImpl::set_TableGID_SSKLAD(TFIBWideStringField * TableGID_SSKLAD)
{
Object->TableGID_SSKLAD=TableGID_SSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TUDMSprSkladImpl::get_ElementNAMESKLAD(void)
{
return Object->ElementNAMESKLAD;
}
//---------------------------------------------------------------
void TUDMSprSkladImpl::set_ElementNAMESKLAD(TFIBWideStringField * ElementNAMESKLAD)
{
Object->ElementNAMESKLAD=ElementNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TUDMSprSkladImpl::get_ElementMOLSKLAD(void)
{
return Object->ElementMOLSKLAD;
}
//---------------------------------------------------------------
void TUDMSprSkladImpl::set_ElementMOLSKLAD(TFIBWideStringField * ElementMOLSKLAD)
{
Object->ElementMOLSKLAD=ElementMOLSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TUDMSprSkladImpl::get_ElementADRSKLAD(void)
{
return Object->ElementADRSKLAD;
}
//---------------------------------------------------------------
void TUDMSprSkladImpl::set_ElementADRSKLAD(TFIBWideStringField * ElementADRSKLAD)
{
Object->ElementADRSKLAD=ElementADRSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TUDMSprSkladImpl::get_ElementGID_SSKLAD(void)
{
return Object->ElementGID_SSKLAD;
}
//---------------------------------------------------------------
void TUDMSprSkladImpl::set_ElementGID_SSKLAD(TFIBWideStringField * ElementGID_SSKLAD)
{
Object->ElementGID_SSKLAD=ElementGID_SSKLAD;
}
//---------------------------------------------------------------
TFIBSmallIntField * TUDMSprSkladImpl::get_ElementDBLUCHETALLNOM_SSKLAD(void)
{
return Object->ElementDBLUCHETALLNOM_SSKLAD;
}
//---------------------------------------------------------------
void TUDMSprSkladImpl::set_ElementDBLUCHETALLNOM_SSKLAD(TFIBSmallIntField * ElementDBLUCHETALLNOM_SSKLAD)
{
Object->ElementDBLUCHETALLNOM_SSKLAD=ElementDBLUCHETALLNOM_SSKLAD;
}
//---------------------------------------------------------------
TFIBSmallIntField * TUDMSprSkladImpl::get_ElementDBLUCHET_SSKLAD(void)
{
return Object->ElementDBLUCHET_SSKLAD;
}
//---------------------------------------------------------------
void TUDMSprSkladImpl::set_ElementDBLUCHET_SSKLAD(TFIBSmallIntField * ElementDBLUCHET_SSKLAD)
{
Object->ElementDBLUCHET_SSKLAD=ElementDBLUCHET_SSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TUDMSprSkladImpl::get_ElementPREFIKS_NUM_SSKLAD(void)
{
return Object->ElementPREFIKS_NUM_SSKLAD;
}
//---------------------------------------------------------------
void TUDMSprSkladImpl::set_ElementPREFIKS_NUM_SSKLAD(TFIBWideStringField * ElementPREFIKS_NUM_SSKLAD)
{
Object->ElementPREFIKS_NUM_SSKLAD=ElementPREFIKS_NUM_SSKLAD;
}
//---------------------------------------------------------------
TFIBBCDField * TUDMSprSkladImpl::get_ElementIDBASE_SSKLAD(void)
{
return Object->ElementIDBASE_SSKLAD;
}
//---------------------------------------------------------------
void TUDMSprSkladImpl::set_ElementIDBASE_SSKLAD(TFIBBCDField * ElementIDBASE_SSKLAD)
{
Object->ElementIDBASE_SSKLAD=ElementIDBASE_SSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TUDMSprSkladImpl::get_ElementPHONE_SSKLAD(void)
{
return Object->ElementPHONE_SSKLAD;
}
//---------------------------------------------------------------
void TUDMSprSkladImpl::set_ElementPHONE_SSKLAD(TFIBWideStringField * ElementPHONE_SSKLAD)
{
Object->ElementPHONE_SSKLAD=ElementPHONE_SSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TUDMSprSkladImpl::get_ElementEMAIL_SSKLAD(void)
{
return Object->ElementEMAIL_SSKLAD;
}
//---------------------------------------------------------------
void TUDMSprSkladImpl::set_ElementEMAIL_SSKLAD(TFIBWideStringField * ElementEMAIL_SSKLAD)
{
Object->ElementEMAIL_SSKLAD=ElementEMAIL_SSKLAD;
}
//---------------------------------------------------------------
void TUDMSprSkladImpl::OpenTable(void)
{
return Object->OpenTable(void);
}
//---------------------------------------------------------------
int TUDMSprSkladImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(__int64 Id);
}
//---------------------------------------------------------------
void TUDMSprSkladImpl::NewElement(void)
{
return Object->NewElement(void);
}
//---------------------------------------------------------------
bool TUDMSprSkladImpl::SaveElement(void)
{
return Object->SaveElement(void);
}
//---------------------------------------------------------------
void TUDMSprSkladImpl::CloseElement(void)
{
return Object->CloseElement(void);
}
//---------------------------------------------------------------
void TUDMSprSkladImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(__int64 Id);
}
//---------------------------------------------------------------
__int64 TUDMSprSkladImpl::GetIDElement(String gid)
{
return Object->GetIDElement(String gid);
}
//---------------------------------------------------------------
AnsiString TUDMSprSkladImpl::GetGIDElement(__int64 id)
{
return Object->GetGIDElement(__int64 id);
}
//---------------------------------------------------------------
int TUDMSprSkladImpl::GetIndexElementaPoID(__int64 id)
{
return Object->GetIndexElementaPoID(__int64 id);
}
//---------------------------------------------------------------
