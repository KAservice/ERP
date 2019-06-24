#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprKomplModelImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprKomplModelImpl::TREM_DMSprKomplModelImpl()           
{                                            
Object=new TREM_DMSprKomplModel(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprKomplModelImpl::~TREM_DMSprKomplModelImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprKomplModelImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprKomplModel)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprKomplModel*> (this);                                
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
int TREM_DMSprKomplModelImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprKomplModelImpl::kanRelease(void)                                  
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
int  TREM_DMSprKomplModelImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprKomplModelImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprKomplModelImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprKomplModelImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprKomplModelImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprKomplModel
TDataSource * TREM_DMSprKomplModelImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprKomplModelImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprKomplModelImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprKomplModelImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprKomplModelImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprKomplModelImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprKomplModelImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprKomplModelImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprKomplModelImpl::get_TableID_REM_SKOMPLMODEL(void)
{
return Object->TableID_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_TableID_REM_SKOMPLMODEL(TFIBLargeIntField * TableID_REM_SKOMPLMODEL)
{
Object->TableID_REM_SKOMPLMODEL=TableID_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKomplModelImpl::get_TableGID_REM_SKOMPLMODEL(void)
{
return Object->TableGID_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_TableGID_REM_SKOMPLMODEL(TFIBWideStringField * TableGID_REM_SKOMPLMODEL)
{
Object->TableGID_REM_SKOMPLMODEL=TableGID_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprKomplModelImpl::get_TableIDMODEL_REM_SKOMPLMODEL(void)
{
return Object->TableIDMODEL_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_TableIDMODEL_REM_SKOMPLMODEL(TFIBLargeIntField * TableIDMODEL_REM_SKOMPLMODEL)
{
Object->TableIDMODEL_REM_SKOMPLMODEL=TableIDMODEL_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKomplModelImpl::get_TableNAME_REM_SKOMPLMODEL(void)
{
return Object->TableNAME_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_TableNAME_REM_SKOMPLMODEL(TFIBWideStringField * TableNAME_REM_SKOMPLMODEL)
{
Object->TableNAME_REM_SKOMPLMODEL=TableNAME_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMSprKomplModelImpl::get_TableKOL_REM_SKOMPLMODEL(void)
{
return Object->TableKOL_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_TableKOL_REM_SKOMPLMODEL(TFIBBCDField * TableKOL_REM_SKOMPLMODEL)
{
Object->TableKOL_REM_SKOMPLMODEL=TableKOL_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMSprKomplModelImpl::get_TableNEISP_REM_SKOMPLMODEL(void)
{
return Object->TableNEISP_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_TableNEISP_REM_SKOMPLMODEL(TFIBSmallIntField * TableNEISP_REM_SKOMPLMODEL)
{
Object->TableNEISP_REM_SKOMPLMODEL=TableNEISP_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMSprKomplModelImpl::get_TableOSN_REM_SKOMPLMODEL(void)
{
return Object->TableOSN_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_TableOSN_REM_SKOMPLMODEL(TFIBSmallIntField * TableOSN_REM_SKOMPLMODEL)
{
Object->TableOSN_REM_SKOMPLMODEL=TableOSN_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprKomplModelImpl::get_TableIDBASE_REM_SKOMPLMODEL(void)
{
return Object->TableIDBASE_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_TableIDBASE_REM_SKOMPLMODEL(TFIBLargeIntField * TableIDBASE_REM_SKOMPLMODEL)
{
Object->TableIDBASE_REM_SKOMPLMODEL=TableIDBASE_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprKomplModelImpl::get_ElementID_REM_SKOMPLMODEL(void)
{
return Object->ElementID_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_ElementID_REM_SKOMPLMODEL(TFIBLargeIntField * ElementID_REM_SKOMPLMODEL)
{
Object->ElementID_REM_SKOMPLMODEL=ElementID_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKomplModelImpl::get_ElementGID_REM_SKOMPLMODEL(void)
{
return Object->ElementGID_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_ElementGID_REM_SKOMPLMODEL(TFIBWideStringField * ElementGID_REM_SKOMPLMODEL)
{
Object->ElementGID_REM_SKOMPLMODEL=ElementGID_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprKomplModelImpl::get_ElementIDMODEL_REM_SKOMPLMODEL(void)
{
return Object->ElementIDMODEL_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_ElementIDMODEL_REM_SKOMPLMODEL(TFIBLargeIntField * ElementIDMODEL_REM_SKOMPLMODEL)
{
Object->ElementIDMODEL_REM_SKOMPLMODEL=ElementIDMODEL_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKomplModelImpl::get_ElementNAME_REM_SKOMPLMODEL(void)
{
return Object->ElementNAME_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_ElementNAME_REM_SKOMPLMODEL(TFIBWideStringField * ElementNAME_REM_SKOMPLMODEL)
{
Object->ElementNAME_REM_SKOMPLMODEL=ElementNAME_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMSprKomplModelImpl::get_ElementKOL_REM_SKOMPLMODEL(void)
{
return Object->ElementKOL_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_ElementKOL_REM_SKOMPLMODEL(TFIBBCDField * ElementKOL_REM_SKOMPLMODEL)
{
Object->ElementKOL_REM_SKOMPLMODEL=ElementKOL_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMSprKomplModelImpl::get_ElementNEISP_REM_SKOMPLMODEL(void)
{
return Object->ElementNEISP_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_ElementNEISP_REM_SKOMPLMODEL(TFIBSmallIntField * ElementNEISP_REM_SKOMPLMODEL)
{
Object->ElementNEISP_REM_SKOMPLMODEL=ElementNEISP_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMSprKomplModelImpl::get_ElementOSN_REM_SKOMPLMODEL(void)
{
return Object->ElementOSN_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_ElementOSN_REM_SKOMPLMODEL(TFIBSmallIntField * ElementOSN_REM_SKOMPLMODEL)
{
Object->ElementOSN_REM_SKOMPLMODEL=ElementOSN_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprKomplModelImpl::get_ElementIDBASE_REM_SKOMPLMODEL(void)
{
return Object->ElementIDBASE_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_ElementIDBASE_REM_SKOMPLMODEL(TFIBLargeIntField * ElementIDBASE_REM_SKOMPLMODEL)
{
Object->ElementIDBASE_REM_SKOMPLMODEL=ElementIDBASE_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprKomplModelImpl::get_TableIDTYPUSLA_REM_SKOMPLMODEL(void)
{
return Object->TableIDTYPUSLA_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_TableIDTYPUSLA_REM_SKOMPLMODEL(TFIBLargeIntField * TableIDTYPUSLA_REM_SKOMPLMODEL)
{
Object->TableIDTYPUSLA_REM_SKOMPLMODEL=TableIDTYPUSLA_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKomplModelImpl::get_TablePARTNUM_REM_SKOMPLMODEL(void)
{
return Object->TablePARTNUM_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_TablePARTNUM_REM_SKOMPLMODEL(TFIBWideStringField * TablePARTNUM_REM_SKOMPLMODEL)
{
Object->TablePARTNUM_REM_SKOMPLMODEL=TablePARTNUM_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKomplModelImpl::get_TableDESCR_REM_SKOMPLMODEL(void)
{
return Object->TableDESCR_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_TableDESCR_REM_SKOMPLMODEL(TFIBWideStringField * TableDESCR_REM_SKOMPLMODEL)
{
Object->TableDESCR_REM_SKOMPLMODEL=TableDESCR_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprKomplModelImpl::get_TableIDNOM_REM_SKOMPLMODEL(void)
{
return Object->TableIDNOM_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_TableIDNOM_REM_SKOMPLMODEL(TFIBLargeIntField * TableIDNOM_REM_SKOMPLMODEL)
{
Object->TableIDNOM_REM_SKOMPLMODEL=TableIDNOM_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprKomplModelImpl::get_TableIDPRNOM_REM_SKOMPLMODEL(void)
{
return Object->TableIDPRNOM_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_TableIDPRNOM_REM_SKOMPLMODEL(TFIBLargeIntField * TableIDPRNOM_REM_SKOMPLMODEL)
{
Object->TableIDPRNOM_REM_SKOMPLMODEL=TableIDPRNOM_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKomplModelImpl::get_TableNAME_REM_STYPUSLOV(void)
{
return Object->TableNAME_REM_STYPUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_TableNAME_REM_STYPUSLOV(TFIBWideStringField * TableNAME_REM_STYPUSLOV)
{
Object->TableNAME_REM_STYPUSLOV=TableNAME_REM_STYPUSLOV;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMSprKomplModelImpl::get_TableCODENOM(void)
{
return Object->TableCODENOM;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_TableCODENOM(TFIBIntegerField * TableCODENOM)
{
Object->TableCODENOM=TableCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKomplModelImpl::get_TableARTNOM(void)
{
return Object->TableARTNOM;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_TableARTNOM(TFIBWideStringField * TableARTNOM)
{
Object->TableARTNOM=TableARTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKomplModelImpl::get_TableNAMENOM(void)
{
return Object->TableNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_TableNAMENOM(TFIBWideStringField * TableNAMENOM)
{
Object->TableNAMENOM=TableNAMENOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMSprKomplModelImpl::get_TableCODE_SPRNOM(void)
{
return Object->TableCODE_SPRNOM;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_TableCODE_SPRNOM(TFIBIntegerField * TableCODE_SPRNOM)
{
Object->TableCODE_SPRNOM=TableCODE_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKomplModelImpl::get_TableART_SPRNOM(void)
{
return Object->TableART_SPRNOM;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_TableART_SPRNOM(TFIBWideStringField * TableART_SPRNOM)
{
Object->TableART_SPRNOM=TableART_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKomplModelImpl::get_TableNAME_SPRNOM(void)
{
return Object->TableNAME_SPRNOM;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_TableNAME_SPRNOM(TFIBWideStringField * TableNAME_SPRNOM)
{
Object->TableNAME_SPRNOM=TableNAME_SPRNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprKomplModelImpl::get_ElementIDTYPUSLA_REM_SKOMPLMODEL(void)
{
return Object->ElementIDTYPUSLA_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_ElementIDTYPUSLA_REM_SKOMPLMODEL(TFIBLargeIntField * ElementIDTYPUSLA_REM_SKOMPLMODEL)
{
Object->ElementIDTYPUSLA_REM_SKOMPLMODEL=ElementIDTYPUSLA_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKomplModelImpl::get_ElementPARTNUM_REM_SKOMPLMODEL(void)
{
return Object->ElementPARTNUM_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_ElementPARTNUM_REM_SKOMPLMODEL(TFIBWideStringField * ElementPARTNUM_REM_SKOMPLMODEL)
{
Object->ElementPARTNUM_REM_SKOMPLMODEL=ElementPARTNUM_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKomplModelImpl::get_ElementDESCR_REM_SKOMPLMODEL(void)
{
return Object->ElementDESCR_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_ElementDESCR_REM_SKOMPLMODEL(TFIBWideStringField * ElementDESCR_REM_SKOMPLMODEL)
{
Object->ElementDESCR_REM_SKOMPLMODEL=ElementDESCR_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprKomplModelImpl::get_ElementIDNOM_REM_SKOMPLMODEL(void)
{
return Object->ElementIDNOM_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_ElementIDNOM_REM_SKOMPLMODEL(TFIBLargeIntField * ElementIDNOM_REM_SKOMPLMODEL)
{
Object->ElementIDNOM_REM_SKOMPLMODEL=ElementIDNOM_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprKomplModelImpl::get_ElementIDPRNOM_REM_SKOMPLMODEL(void)
{
return Object->ElementIDPRNOM_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_ElementIDPRNOM_REM_SKOMPLMODEL(TFIBLargeIntField * ElementIDPRNOM_REM_SKOMPLMODEL)
{
Object->ElementIDPRNOM_REM_SKOMPLMODEL=ElementIDPRNOM_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKomplModelImpl::get_ElementNAME_REM_STYPUSLOV(void)
{
return Object->ElementNAME_REM_STYPUSLOV;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_ElementNAME_REM_STYPUSLOV(TFIBWideStringField * ElementNAME_REM_STYPUSLOV)
{
Object->ElementNAME_REM_STYPUSLOV=ElementNAME_REM_STYPUSLOV;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMSprKomplModelImpl::get_ElementCODENOM(void)
{
return Object->ElementCODENOM;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_ElementCODENOM(TFIBIntegerField * ElementCODENOM)
{
Object->ElementCODENOM=ElementCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKomplModelImpl::get_ElementARTNOM(void)
{
return Object->ElementARTNOM;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_ElementARTNOM(TFIBWideStringField * ElementARTNOM)
{
Object->ElementARTNOM=ElementARTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKomplModelImpl::get_ElementNAMENOM(void)
{
return Object->ElementNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_ElementNAMENOM(TFIBWideStringField * ElementNAMENOM)
{
Object->ElementNAMENOM=ElementNAMENOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMSprKomplModelImpl::get_ElementCODE_SPRNOM(void)
{
return Object->ElementCODE_SPRNOM;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_ElementCODE_SPRNOM(TFIBIntegerField * ElementCODE_SPRNOM)
{
Object->ElementCODE_SPRNOM=ElementCODE_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKomplModelImpl::get_ElementART_SPRNOM(void)
{
return Object->ElementART_SPRNOM;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_ElementART_SPRNOM(TFIBWideStringField * ElementART_SPRNOM)
{
Object->ElementART_SPRNOM=ElementART_SPRNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprKomplModelImpl::get_ElementNAME_SPRNOM(void)
{
return Object->ElementNAME_SPRNOM;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::set_ElementNAME_SPRNOM(TFIBWideStringField * ElementNAME_SPRNOM)
{
Object->ElementNAME_SPRNOM=ElementNAME_SPRNOM;
}
//---------------------------------------------------------------
void TREM_DMSprKomplModelImpl::OpenTable(__int64 id_model)
{
return Object->OpenTable(id_model);
}
//---------------------------------------------------------------
int TREM_DMSprKomplModelImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprKomplModelImpl::NewElement(__int64 id_model)
{
return Object->NewElement(id_model);
}
//---------------------------------------------------------------
bool TREM_DMSprKomplModelImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMSprKomplModelImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TREM_DMSprKomplModelImpl::GetIDElement(String gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
UnicodeString TREM_DMSprKomplModelImpl::GetGIDElement(__int64 id)
{
return Object->GetGIDElement(id);
}
//---------------------------------------------------------------
