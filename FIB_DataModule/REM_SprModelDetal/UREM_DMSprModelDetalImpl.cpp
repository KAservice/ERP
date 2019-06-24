#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprModelDetalImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprModelDetalImpl::TREM_DMSprModelDetalImpl()           
{                                            
Object=new TREM_DMSprModelDetal(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprModelDetalImpl::~TREM_DMSprModelDetalImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprModelDetalImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprModelDetal)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprModelDetal*> (this);                                
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
int TREM_DMSprModelDetalImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprModelDetalImpl::kanRelease(void)                                  
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
int  TREM_DMSprModelDetalImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprModelDetalImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprModelDetalImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprModelDetalImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprModelDetalImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprModelDetal
TDataSource * TREM_DMSprModelDetalImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprModelDetalImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprModelDetalImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprModelDetalImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprModelDetalImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprModelDetalImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprModelDetalImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprModelDetalImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelDetalImpl::get_TableID_REM_SMODEL_DETAL(void)
{
return Object->TableID_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_TableID_REM_SMODEL_DETAL(TFIBLargeIntField * TableID_REM_SMODEL_DETAL)
{
Object->TableID_REM_SMODEL_DETAL=TableID_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelDetalImpl::get_TableGID_REM_SMODEL_DETAL(void)
{
return Object->TableGID_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_TableGID_REM_SMODEL_DETAL(TFIBWideStringField * TableGID_REM_SMODEL_DETAL)
{
Object->TableGID_REM_SMODEL_DETAL=TableGID_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelDetalImpl::get_TableIDBASE_REM_SMODEL_DETAL(void)
{
return Object->TableIDBASE_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_TableIDBASE_REM_SMODEL_DETAL(TFIBLargeIntField * TableIDBASE_REM_SMODEL_DETAL)
{
Object->TableIDBASE_REM_SMODEL_DETAL=TableIDBASE_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelDetalImpl::get_TableIDMODEL_REM_SMODEL_DETAL(void)
{
return Object->TableIDMODEL_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_TableIDMODEL_REM_SMODEL_DETAL(TFIBLargeIntField * TableIDMODEL_REM_SMODEL_DETAL)
{
Object->TableIDMODEL_REM_SMODEL_DETAL=TableIDMODEL_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelDetalImpl::get_TableIDTYPUSLA_REM_SMODEL_DETAL(void)
{
return Object->TableIDTYPUSLA_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_TableIDTYPUSLA_REM_SMODEL_DETAL(TFIBLargeIntField * TableIDTYPUSLA_REM_SMODEL_DETAL)
{
Object->TableIDTYPUSLA_REM_SMODEL_DETAL=TableIDTYPUSLA_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelDetalImpl::get_TableIDNOM_REM_SMODEL_DETAL(void)
{
return Object->TableIDNOM_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_TableIDNOM_REM_SMODEL_DETAL(TFIBLargeIntField * TableIDNOM_REM_SMODEL_DETAL)
{
Object->TableIDNOM_REM_SMODEL_DETAL=TableIDNOM_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelDetalImpl::get_TableIDPRNOM_REM_SMODEL_DETAL(void)
{
return Object->TableIDPRNOM_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_TableIDPRNOM_REM_SMODEL_DETAL(TFIBLargeIntField * TableIDPRNOM_REM_SMODEL_DETAL)
{
Object->TableIDPRNOM_REM_SMODEL_DETAL=TableIDPRNOM_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelDetalImpl::get_TableNAME_REM_SMODEL_DETAL(void)
{
return Object->TableNAME_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_TableNAME_REM_SMODEL_DETAL(TFIBWideStringField * TableNAME_REM_SMODEL_DETAL)
{
Object->TableNAME_REM_SMODEL_DETAL=TableNAME_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelDetalImpl::get_TablePARTNUM_REM_SMODEL_DETAL(void)
{
return Object->TablePARTNUM_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_TablePARTNUM_REM_SMODEL_DETAL(TFIBWideStringField * TablePARTNUM_REM_SMODEL_DETAL)
{
Object->TablePARTNUM_REM_SMODEL_DETAL=TablePARTNUM_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelDetalImpl::get_TableDESCR_REM_SMODEL_DETAL(void)
{
return Object->TableDESCR_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_TableDESCR_REM_SMODEL_DETAL(TFIBWideStringField * TableDESCR_REM_SMODEL_DETAL)
{
Object->TableDESCR_REM_SMODEL_DETAL=TableDESCR_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMSprModelDetalImpl::get_TableKOL_REM_SMODEL_DETAL(void)
{
return Object->TableKOL_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_TableKOL_REM_SMODEL_DETAL(TFIBBCDField * TableKOL_REM_SMODEL_DETAL)
{
Object->TableKOL_REM_SMODEL_DETAL=TableKOL_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelDetalImpl::get_TableNAME_REM_STYPUSLOV(void)
{
return Object->TableNAME_REM_STYPUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_TableNAME_REM_STYPUSLOV(TFIBWideStringField * TableNAME_REM_STYPUSLOV)
{
Object->TableNAME_REM_STYPUSLOV=TableNAME_REM_STYPUSLOV;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMSprModelDetalImpl::get_TableCODENOM(void)
{
return Object->TableCODENOM;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_TableCODENOM(TFIBIntegerField * TableCODENOM)
{
Object->TableCODENOM=TableCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelDetalImpl::get_TableARTNOM(void)
{
return Object->TableARTNOM;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_TableARTNOM(TFIBWideStringField * TableARTNOM)
{
Object->TableARTNOM=TableARTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelDetalImpl::get_TableNAMENOM(void)
{
return Object->TableNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_TableNAMENOM(TFIBWideStringField * TableNAMENOM)
{
Object->TableNAMENOM=TableNAMENOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMSprModelDetalImpl::get_TableCODE_SPRNOM(void)
{
return Object->TableCODE_SPRNOM;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_TableCODE_SPRNOM(TFIBIntegerField * TableCODE_SPRNOM)
{
Object->TableCODE_SPRNOM=TableCODE_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelDetalImpl::get_TableART_SPRNOM(void)
{
return Object->TableART_SPRNOM;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_TableART_SPRNOM(TFIBWideStringField * TableART_SPRNOM)
{
Object->TableART_SPRNOM=TableART_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelDetalImpl::get_TableNAME_SPRNOM(void)
{
return Object->TableNAME_SPRNOM;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_TableNAME_SPRNOM(TFIBWideStringField * TableNAME_SPRNOM)
{
Object->TableNAME_SPRNOM=TableNAME_SPRNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelDetalImpl::get_ElementID_REM_SMODEL_DETAL(void)
{
return Object->ElementID_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_ElementID_REM_SMODEL_DETAL(TFIBLargeIntField * ElementID_REM_SMODEL_DETAL)
{
Object->ElementID_REM_SMODEL_DETAL=ElementID_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelDetalImpl::get_ElementGID_REM_SMODEL_DETAL(void)
{
return Object->ElementGID_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_ElementGID_REM_SMODEL_DETAL(TFIBWideStringField * ElementGID_REM_SMODEL_DETAL)
{
Object->ElementGID_REM_SMODEL_DETAL=ElementGID_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelDetalImpl::get_ElementIDBASE_REM_SMODEL_DETAL(void)
{
return Object->ElementIDBASE_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_ElementIDBASE_REM_SMODEL_DETAL(TFIBLargeIntField * ElementIDBASE_REM_SMODEL_DETAL)
{
Object->ElementIDBASE_REM_SMODEL_DETAL=ElementIDBASE_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelDetalImpl::get_ElementIDMODEL_REM_SMODEL_DETAL(void)
{
return Object->ElementIDMODEL_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_ElementIDMODEL_REM_SMODEL_DETAL(TFIBLargeIntField * ElementIDMODEL_REM_SMODEL_DETAL)
{
Object->ElementIDMODEL_REM_SMODEL_DETAL=ElementIDMODEL_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelDetalImpl::get_ElementIDTYPUSLA_REM_SMODEL_DETAL(void)
{
return Object->ElementIDTYPUSLA_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_ElementIDTYPUSLA_REM_SMODEL_DETAL(TFIBLargeIntField * ElementIDTYPUSLA_REM_SMODEL_DETAL)
{
Object->ElementIDTYPUSLA_REM_SMODEL_DETAL=ElementIDTYPUSLA_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelDetalImpl::get_ElementIDNOM_REM_SMODEL_DETAL(void)
{
return Object->ElementIDNOM_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_ElementIDNOM_REM_SMODEL_DETAL(TFIBLargeIntField * ElementIDNOM_REM_SMODEL_DETAL)
{
Object->ElementIDNOM_REM_SMODEL_DETAL=ElementIDNOM_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelDetalImpl::get_ElementIDPRNOM_REM_SMODEL_DETAL(void)
{
return Object->ElementIDPRNOM_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_ElementIDPRNOM_REM_SMODEL_DETAL(TFIBLargeIntField * ElementIDPRNOM_REM_SMODEL_DETAL)
{
Object->ElementIDPRNOM_REM_SMODEL_DETAL=ElementIDPRNOM_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelDetalImpl::get_ElementNAME_REM_SMODEL_DETAL(void)
{
return Object->ElementNAME_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_ElementNAME_REM_SMODEL_DETAL(TFIBWideStringField * ElementNAME_REM_SMODEL_DETAL)
{
Object->ElementNAME_REM_SMODEL_DETAL=ElementNAME_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelDetalImpl::get_ElementPARTNUM_REM_SMODEL_DETAL(void)
{
return Object->ElementPARTNUM_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_ElementPARTNUM_REM_SMODEL_DETAL(TFIBWideStringField * ElementPARTNUM_REM_SMODEL_DETAL)
{
Object->ElementPARTNUM_REM_SMODEL_DETAL=ElementPARTNUM_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelDetalImpl::get_ElementDESCR_REM_SMODEL_DETAL(void)
{
return Object->ElementDESCR_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_ElementDESCR_REM_SMODEL_DETAL(TFIBWideStringField * ElementDESCR_REM_SMODEL_DETAL)
{
Object->ElementDESCR_REM_SMODEL_DETAL=ElementDESCR_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMSprModelDetalImpl::get_ElementKOL_REM_SMODEL_DETAL(void)
{
return Object->ElementKOL_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_ElementKOL_REM_SMODEL_DETAL(TFIBBCDField * ElementKOL_REM_SMODEL_DETAL)
{
Object->ElementKOL_REM_SMODEL_DETAL=ElementKOL_REM_SMODEL_DETAL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelDetalImpl::get_ElementNAME_REM_STYPUSLOV(void)
{
return Object->ElementNAME_REM_STYPUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_ElementNAME_REM_STYPUSLOV(TFIBWideStringField * ElementNAME_REM_STYPUSLOV)
{
Object->ElementNAME_REM_STYPUSLOV=ElementNAME_REM_STYPUSLOV;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMSprModelDetalImpl::get_ElementCODENOM(void)
{
return Object->ElementCODENOM;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_ElementCODENOM(TFIBIntegerField * ElementCODENOM)
{
Object->ElementCODENOM=ElementCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelDetalImpl::get_ElementARTNOM(void)
{
return Object->ElementARTNOM;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_ElementARTNOM(TFIBWideStringField * ElementARTNOM)
{
Object->ElementARTNOM=ElementARTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelDetalImpl::get_ElementNAMENOM(void)
{
return Object->ElementNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_ElementNAMENOM(TFIBWideStringField * ElementNAMENOM)
{
Object->ElementNAMENOM=ElementNAMENOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMSprModelDetalImpl::get_ElementCODE_SPRNOM(void)
{
return Object->ElementCODE_SPRNOM;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_ElementCODE_SPRNOM(TFIBIntegerField * ElementCODE_SPRNOM)
{
Object->ElementCODE_SPRNOM=ElementCODE_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelDetalImpl::get_ElementART_SPRNOM(void)
{
return Object->ElementART_SPRNOM;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_ElementART_SPRNOM(TFIBWideStringField * ElementART_SPRNOM)
{
Object->ElementART_SPRNOM=ElementART_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelDetalImpl::get_ElementNAME_SPRNOM(void)
{
return Object->ElementNAME_SPRNOM;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::set_ElementNAME_SPRNOM(TFIBWideStringField * ElementNAME_SPRNOM)
{
Object->ElementNAME_SPRNOM=ElementNAME_SPRNOM;
}
//---------------------------------------------------------------
void TREM_DMSprModelDetalImpl::OpenTable(__int64 id_model)
{
return Object->OpenTable(id_model);
}
//---------------------------------------------------------------
int TREM_DMSprModelDetalImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprModelDetalImpl::NewElement(__int64 id_model)
{
return Object->NewElement(id_model);
}
//---------------------------------------------------------------
bool TREM_DMSprModelDetalImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMSprModelDetalImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
