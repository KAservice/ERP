#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprNeisprModelImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprNeisprModelImpl::TREM_DMSprNeisprModelImpl()           
{                                            
Object=new TREM_DMSprNeisprModel(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprNeisprModelImpl::~TREM_DMSprNeisprModelImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprNeisprModelImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprNeisprModelImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprNeisprModel)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprNeisprModel*> (this);                                
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
int TREM_DMSprNeisprModelImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprNeisprModelImpl::kanRelease(void)                                  
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
int  TREM_DMSprNeisprModelImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprNeisprModelImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprNeisprModelImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprNeisprModelImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprNeisprModelImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprNeisprModelImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprNeisprModelImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprNeisprModel
TDataSource * TREM_DMSprNeisprModelImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprModelImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprNeisprModelImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprModelImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprNeisprModelImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprModelImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprNeisprModelImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprModelImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprNeisprModelImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprModelImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprNeisprModelImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprModelImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprNeisprModelImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprModelImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprNeisprModelImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprModelImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprNeisprModelImpl::get_TableID_REM_SNEISPMODEL(void)
{
return Object->TableID_REM_SNEISPMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprModelImpl::set_TableID_REM_SNEISPMODEL(TFIBLargeIntField * TableID_REM_SNEISPMODEL)
{
Object->TableID_REM_SNEISPMODEL=TableID_REM_SNEISPMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprNeisprModelImpl::get_TableGID_REM_SNEISPMODEL(void)
{
return Object->TableGID_REM_SNEISPMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprModelImpl::set_TableGID_REM_SNEISPMODEL(TFIBWideStringField * TableGID_REM_SNEISPMODEL)
{
Object->TableGID_REM_SNEISPMODEL=TableGID_REM_SNEISPMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprNeisprModelImpl::get_TableIDBASE_REM_SNEISPMODEL(void)
{
return Object->TableIDBASE_REM_SNEISPMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprModelImpl::set_TableIDBASE_REM_SNEISPMODEL(TFIBLargeIntField * TableIDBASE_REM_SNEISPMODEL)
{
Object->TableIDBASE_REM_SNEISPMODEL=TableIDBASE_REM_SNEISPMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprNeisprModelImpl::get_TableDESCR_REM_SNEISPMODEL(void)
{
return Object->TableDESCR_REM_SNEISPMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprModelImpl::set_TableDESCR_REM_SNEISPMODEL(TFIBWideStringField * TableDESCR_REM_SNEISPMODEL)
{
Object->TableDESCR_REM_SNEISPMODEL=TableDESCR_REM_SNEISPMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprNeisprModelImpl::get_TableIDMODEL_REM_SNEISPMODEL(void)
{
return Object->TableIDMODEL_REM_SNEISPMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprModelImpl::set_TableIDMODEL_REM_SNEISPMODEL(TFIBLargeIntField * TableIDMODEL_REM_SNEISPMODEL)
{
Object->TableIDMODEL_REM_SNEISPMODEL=TableIDMODEL_REM_SNEISPMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprNeisprModelImpl::get_TableIDNEISPR_REM_SNEISPMODEL(void)
{
return Object->TableIDNEISPR_REM_SNEISPMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprModelImpl::set_TableIDNEISPR_REM_SNEISPMODEL(TFIBLargeIntField * TableIDNEISPR_REM_SNEISPMODEL)
{
Object->TableIDNEISPR_REM_SNEISPMODEL=TableIDNEISPR_REM_SNEISPMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprNeisprModelImpl::get_TableNAME_REM_SNEISPR(void)
{
return Object->TableNAME_REM_SNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprModelImpl::set_TableNAME_REM_SNEISPR(TFIBWideStringField * TableNAME_REM_SNEISPR)
{
Object->TableNAME_REM_SNEISPR=TableNAME_REM_SNEISPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprNeisprModelImpl::get_ElementID_REM_SNEISPMODEL(void)
{
return Object->ElementID_REM_SNEISPMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprModelImpl::set_ElementID_REM_SNEISPMODEL(TFIBLargeIntField * ElementID_REM_SNEISPMODEL)
{
Object->ElementID_REM_SNEISPMODEL=ElementID_REM_SNEISPMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprNeisprModelImpl::get_ElementGID_REM_SNEISPMODEL(void)
{
return Object->ElementGID_REM_SNEISPMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprModelImpl::set_ElementGID_REM_SNEISPMODEL(TFIBWideStringField * ElementGID_REM_SNEISPMODEL)
{
Object->ElementGID_REM_SNEISPMODEL=ElementGID_REM_SNEISPMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprNeisprModelImpl::get_ElementIDBASE_REM_SNEISPMODEL(void)
{
return Object->ElementIDBASE_REM_SNEISPMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprModelImpl::set_ElementIDBASE_REM_SNEISPMODEL(TFIBLargeIntField * ElementIDBASE_REM_SNEISPMODEL)
{
Object->ElementIDBASE_REM_SNEISPMODEL=ElementIDBASE_REM_SNEISPMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprNeisprModelImpl::get_ElementDESCR_REM_SNEISPMODEL(void)
{
return Object->ElementDESCR_REM_SNEISPMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprModelImpl::set_ElementDESCR_REM_SNEISPMODEL(TFIBWideStringField * ElementDESCR_REM_SNEISPMODEL)
{
Object->ElementDESCR_REM_SNEISPMODEL=ElementDESCR_REM_SNEISPMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprNeisprModelImpl::get_ElementIDMODEL_REM_SNEISPMODEL(void)
{
return Object->ElementIDMODEL_REM_SNEISPMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprModelImpl::set_ElementIDMODEL_REM_SNEISPMODEL(TFIBLargeIntField * ElementIDMODEL_REM_SNEISPMODEL)
{
Object->ElementIDMODEL_REM_SNEISPMODEL=ElementIDMODEL_REM_SNEISPMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprNeisprModelImpl::get_ElementIDNEISPR_REM_SNEISPMODEL(void)
{
return Object->ElementIDNEISPR_REM_SNEISPMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprModelImpl::set_ElementIDNEISPR_REM_SNEISPMODEL(TFIBLargeIntField * ElementIDNEISPR_REM_SNEISPMODEL)
{
Object->ElementIDNEISPR_REM_SNEISPMODEL=ElementIDNEISPR_REM_SNEISPMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprNeisprModelImpl::get_ElementNAME_REM_SNEISPR(void)
{
return Object->ElementNAME_REM_SNEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprModelImpl::set_ElementNAME_REM_SNEISPR(TFIBWideStringField * ElementNAME_REM_SNEISPR)
{
Object->ElementNAME_REM_SNEISPR=ElementNAME_REM_SNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprNeisprModelImpl::get_TableNAME_REM_SNEISPMODEL(void)
{
return Object->TableNAME_REM_SNEISPMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprModelImpl::set_TableNAME_REM_SNEISPMODEL(TFIBWideStringField * TableNAME_REM_SNEISPMODEL)
{
Object->TableNAME_REM_SNEISPMODEL=TableNAME_REM_SNEISPMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprNeisprModelImpl::get_ElementNAME_REM_SNEISPMODEL(void)
{
return Object->ElementNAME_REM_SNEISPMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprModelImpl::set_ElementNAME_REM_SNEISPMODEL(TFIBWideStringField * ElementNAME_REM_SNEISPMODEL)
{
Object->ElementNAME_REM_SNEISPMODEL=ElementNAME_REM_SNEISPMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprNeisprModelImpl::get_ElementIDMODELNEISPR_REM_SNEISPMODEL(void)
{
return Object->ElementIDMODELNEISPR_REM_SNEISPMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprModelImpl::set_ElementIDMODELNEISPR_REM_SNEISPMODEL(TFIBLargeIntField * ElementIDMODELNEISPR_REM_SNEISPMODEL)
{
Object->ElementIDMODELNEISPR_REM_SNEISPMODEL=ElementIDMODELNEISPR_REM_SNEISPMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprNeisprModelImpl::get_ElementNAME_REM_SMODEL(void)
{
return Object->ElementNAME_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprModelImpl::set_ElementNAME_REM_SMODEL(TFIBWideStringField * ElementNAME_REM_SMODEL)
{
Object->ElementNAME_REM_SMODEL=ElementNAME_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprNeisprModelImpl::get_TableIDMODELNEISPR_REM_SNEISPMODEL(void)
{
return Object->TableIDMODELNEISPR_REM_SNEISPMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprModelImpl::set_TableIDMODELNEISPR_REM_SNEISPMODEL(TFIBLargeIntField * TableIDMODELNEISPR_REM_SNEISPMODEL)
{
Object->TableIDMODELNEISPR_REM_SNEISPMODEL=TableIDMODELNEISPR_REM_SNEISPMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprNeisprModelImpl::get_TableNAME_REM_SMODEL(void)
{
return Object->TableNAME_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprModelImpl::set_TableNAME_REM_SMODEL(TFIBWideStringField * TableNAME_REM_SMODEL)
{
Object->TableNAME_REM_SMODEL=TableNAME_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprNeisprModelImpl::OpenTable(__int64 id_model)
{
return Object->OpenTable(id_model);
}
//---------------------------------------------------------------
int TREM_DMSprNeisprModelImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprNeisprModelImpl::NewElement(__int64 id_model)
{
return Object->NewElement(id_model);
}
//---------------------------------------------------------------
bool TREM_DMSprNeisprModelImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMSprNeisprModelImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
