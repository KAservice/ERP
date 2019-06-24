#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprDefectModelNeisprImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprDefectModelNeisprImpl::TREM_DMSprDefectModelNeisprImpl()           
{                                            
Object=new TREM_DMSprDefectModelNeispr(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprDefectModelNeisprImpl::~TREM_DMSprDefectModelNeisprImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprDefectModelNeisprImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprDefectModelNeisprImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprDefectModelNeispr)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprDefectModelNeispr*> (this);                                
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
int TREM_DMSprDefectModelNeisprImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprDefectModelNeisprImpl::kanRelease(void)                                  
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
int  TREM_DMSprDefectModelNeisprImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprDefectModelNeisprImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprDefectModelNeisprImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprDefectModelNeisprImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprDefectModelNeisprImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprDefectModelNeisprImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprDefectModelNeisprImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprDefectModelNeispr
TDataSource * TREM_DMSprDefectModelNeisprImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprDefectModelNeisprImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprDefectModelNeisprImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprDefectModelNeisprImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprDefectModelNeisprImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprDefectModelNeisprImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprDefectModelNeisprImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprDefectModelNeisprImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprDefectModelNeisprImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprDefectModelNeisprImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprDefectModelNeisprImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprDefectModelNeisprImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprDefectModelNeisprImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprDefectModelNeisprImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprDefectModelNeisprImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMSprDefectModelNeisprImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprDefectModelNeisprImpl::get_TableID_REM_SDEFECT_MODNE(void)
{
return Object->TableID_REM_SDEFECT_MODNE;
}
//---------------------------------------------------------------
void TREM_DMSprDefectModelNeisprImpl::set_TableID_REM_SDEFECT_MODNE(TFIBLargeIntField * TableID_REM_SDEFECT_MODNE)
{
Object->TableID_REM_SDEFECT_MODNE=TableID_REM_SDEFECT_MODNE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprDefectModelNeisprImpl::get_TableGID_REM_SDEFECT_MODNE(void)
{
return Object->TableGID_REM_SDEFECT_MODNE;
}
//---------------------------------------------------------------
void TREM_DMSprDefectModelNeisprImpl::set_TableGID_REM_SDEFECT_MODNE(TFIBWideStringField * TableGID_REM_SDEFECT_MODNE)
{
Object->TableGID_REM_SDEFECT_MODNE=TableGID_REM_SDEFECT_MODNE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprDefectModelNeisprImpl::get_TableIDBASE_REM_SDEFECT_MODNE(void)
{
return Object->TableIDBASE_REM_SDEFECT_MODNE;
}
//---------------------------------------------------------------
void TREM_DMSprDefectModelNeisprImpl::set_TableIDBASE_REM_SDEFECT_MODNE(TFIBLargeIntField * TableIDBASE_REM_SDEFECT_MODNE)
{
Object->TableIDBASE_REM_SDEFECT_MODNE=TableIDBASE_REM_SDEFECT_MODNE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprDefectModelNeisprImpl::get_TableIDNEISMOD_REM_SDEFECT_MODNE(void)
{
return Object->TableIDNEISMOD_REM_SDEFECT_MODNE;
}
//---------------------------------------------------------------
void TREM_DMSprDefectModelNeisprImpl::set_TableIDNEISMOD_REM_SDEFECT_MODNE(TFIBLargeIntField * TableIDNEISMOD_REM_SDEFECT_MODNE)
{
Object->TableIDNEISMOD_REM_SDEFECT_MODNE=TableIDNEISMOD_REM_SDEFECT_MODNE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprDefectModelNeisprImpl::get_TableNAME_REM_SDEFECT_MODNE(void)
{
return Object->TableNAME_REM_SDEFECT_MODNE;
}
//---------------------------------------------------------------
void TREM_DMSprDefectModelNeisprImpl::set_TableNAME_REM_SDEFECT_MODNE(TFIBWideStringField * TableNAME_REM_SDEFECT_MODNE)
{
Object->TableNAME_REM_SDEFECT_MODNE=TableNAME_REM_SDEFECT_MODNE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprDefectModelNeisprImpl::get_TableDESCR_REM_SDEFECT_MODNE(void)
{
return Object->TableDESCR_REM_SDEFECT_MODNE;
}
//---------------------------------------------------------------
void TREM_DMSprDefectModelNeisprImpl::set_TableDESCR_REM_SDEFECT_MODNE(TFIBWideStringField * TableDESCR_REM_SDEFECT_MODNE)
{
Object->TableDESCR_REM_SDEFECT_MODNE=TableDESCR_REM_SDEFECT_MODNE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprDefectModelNeisprImpl::get_TableIDTDEF_REM_SDEFECT_MODNE(void)
{
return Object->TableIDTDEF_REM_SDEFECT_MODNE;
}
//---------------------------------------------------------------
void TREM_DMSprDefectModelNeisprImpl::set_TableIDTDEF_REM_SDEFECT_MODNE(TFIBLargeIntField * TableIDTDEF_REM_SDEFECT_MODNE)
{
Object->TableIDTDEF_REM_SDEFECT_MODNE=TableIDTDEF_REM_SDEFECT_MODNE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprDefectModelNeisprImpl::get_TableNAME_REM_STYPDEFECT(void)
{
return Object->TableNAME_REM_STYPDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprDefectModelNeisprImpl::set_TableNAME_REM_STYPDEFECT(TFIBWideStringField * TableNAME_REM_STYPDEFECT)
{
Object->TableNAME_REM_STYPDEFECT=TableNAME_REM_STYPDEFECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprDefectModelNeisprImpl::get_TableCODE_REM_STYPDEFECT(void)
{
return Object->TableCODE_REM_STYPDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprDefectModelNeisprImpl::set_TableCODE_REM_STYPDEFECT(TFIBWideStringField * TableCODE_REM_STYPDEFECT)
{
Object->TableCODE_REM_STYPDEFECT=TableCODE_REM_STYPDEFECT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprDefectModelNeisprImpl::get_ElementID_REM_SDEFECT_MODNE(void)
{
return Object->ElementID_REM_SDEFECT_MODNE;
}
//---------------------------------------------------------------
void TREM_DMSprDefectModelNeisprImpl::set_ElementID_REM_SDEFECT_MODNE(TFIBLargeIntField * ElementID_REM_SDEFECT_MODNE)
{
Object->ElementID_REM_SDEFECT_MODNE=ElementID_REM_SDEFECT_MODNE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprDefectModelNeisprImpl::get_ElementGID_REM_SDEFECT_MODNE(void)
{
return Object->ElementGID_REM_SDEFECT_MODNE;
}
//---------------------------------------------------------------
void TREM_DMSprDefectModelNeisprImpl::set_ElementGID_REM_SDEFECT_MODNE(TFIBWideStringField * ElementGID_REM_SDEFECT_MODNE)
{
Object->ElementGID_REM_SDEFECT_MODNE=ElementGID_REM_SDEFECT_MODNE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprDefectModelNeisprImpl::get_ElementIDBASE_REM_SDEFECT_MODNE(void)
{
return Object->ElementIDBASE_REM_SDEFECT_MODNE;
}
//---------------------------------------------------------------
void TREM_DMSprDefectModelNeisprImpl::set_ElementIDBASE_REM_SDEFECT_MODNE(TFIBLargeIntField * ElementIDBASE_REM_SDEFECT_MODNE)
{
Object->ElementIDBASE_REM_SDEFECT_MODNE=ElementIDBASE_REM_SDEFECT_MODNE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprDefectModelNeisprImpl::get_ElementIDNEISMOD_REM_SDEFECT_MODNE(void)
{
return Object->ElementIDNEISMOD_REM_SDEFECT_MODNE;
}
//---------------------------------------------------------------
void TREM_DMSprDefectModelNeisprImpl::set_ElementIDNEISMOD_REM_SDEFECT_MODNE(TFIBLargeIntField * ElementIDNEISMOD_REM_SDEFECT_MODNE)
{
Object->ElementIDNEISMOD_REM_SDEFECT_MODNE=ElementIDNEISMOD_REM_SDEFECT_MODNE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprDefectModelNeisprImpl::get_ElementNAME_REM_SDEFECT_MODNE(void)
{
return Object->ElementNAME_REM_SDEFECT_MODNE;
}
//---------------------------------------------------------------
void TREM_DMSprDefectModelNeisprImpl::set_ElementNAME_REM_SDEFECT_MODNE(TFIBWideStringField * ElementNAME_REM_SDEFECT_MODNE)
{
Object->ElementNAME_REM_SDEFECT_MODNE=ElementNAME_REM_SDEFECT_MODNE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprDefectModelNeisprImpl::get_ElementDESCR_REM_SDEFECT_MODNE(void)
{
return Object->ElementDESCR_REM_SDEFECT_MODNE;
}
//---------------------------------------------------------------
void TREM_DMSprDefectModelNeisprImpl::set_ElementDESCR_REM_SDEFECT_MODNE(TFIBWideStringField * ElementDESCR_REM_SDEFECT_MODNE)
{
Object->ElementDESCR_REM_SDEFECT_MODNE=ElementDESCR_REM_SDEFECT_MODNE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprDefectModelNeisprImpl::get_ElementIDTDEF_REM_SDEFECT_MODNE(void)
{
return Object->ElementIDTDEF_REM_SDEFECT_MODNE;
}
//---------------------------------------------------------------
void TREM_DMSprDefectModelNeisprImpl::set_ElementIDTDEF_REM_SDEFECT_MODNE(TFIBLargeIntField * ElementIDTDEF_REM_SDEFECT_MODNE)
{
Object->ElementIDTDEF_REM_SDEFECT_MODNE=ElementIDTDEF_REM_SDEFECT_MODNE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprDefectModelNeisprImpl::get_ElementNAME_REM_STYPDEFECT(void)
{
return Object->ElementNAME_REM_STYPDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprDefectModelNeisprImpl::set_ElementNAME_REM_STYPDEFECT(TFIBWideStringField * ElementNAME_REM_STYPDEFECT)
{
Object->ElementNAME_REM_STYPDEFECT=ElementNAME_REM_STYPDEFECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprDefectModelNeisprImpl::get_ElementCODE_REM_STYPDEFECT(void)
{
return Object->ElementCODE_REM_STYPDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprDefectModelNeisprImpl::set_ElementCODE_REM_STYPDEFECT(TFIBWideStringField * ElementCODE_REM_STYPDEFECT)
{
Object->ElementCODE_REM_STYPDEFECT=ElementCODE_REM_STYPDEFECT;
}
//---------------------------------------------------------------
void TREM_DMSprDefectModelNeisprImpl::OpenTable(__int64 id_model_neispr)
{
return Object->OpenTable(id_model_neispr);
}
//---------------------------------------------------------------
int TREM_DMSprDefectModelNeisprImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprDefectModelNeisprImpl::NewElement(__int64 id_model_neispr)
{
return Object->NewElement(id_model_neispr);
}
//---------------------------------------------------------------
bool TREM_DMSprDefectModelNeisprImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMSprDefectModelNeisprImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
