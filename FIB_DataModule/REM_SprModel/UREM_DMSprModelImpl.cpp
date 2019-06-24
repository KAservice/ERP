#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprModelImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprModelImpl::TREM_DMSprModelImpl()           
{                                            
Object=new TREM_DMSprModel(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprModelImpl::~TREM_DMSprModelImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprModelImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprModelImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprModel)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprModel*> (this);                                
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
int TREM_DMSprModelImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprModelImpl::kanRelease(void)                                  
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
int  TREM_DMSprModelImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprModelImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprModelImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprModelImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprModelImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprModel
TDataSource * TREM_DMSprModelImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprModelImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprModelImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprModelImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprModelImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprModelImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprModelImpl::get_pFIBQuery(void)
{
return Object->pFIBQuery;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_pFIBQuery(TpFIBQuery * pFIBQuery)
{
Object->pFIBQuery=pFIBQuery;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprModelImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelImpl::get_TableID_REM_SMODEL(void)
{
return Object->TableID_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_TableID_REM_SMODEL(TFIBLargeIntField * TableID_REM_SMODEL)
{
Object->TableID_REM_SMODEL=TableID_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelImpl::get_TableGID_REM_SMODEL(void)
{
return Object->TableGID_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_TableGID_REM_SMODEL(TFIBWideStringField * TableGID_REM_SMODEL)
{
Object->TableGID_REM_SMODEL=TableGID_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelImpl::get_TableIDGRP_REM_SMODEL(void)
{
return Object->TableIDGRP_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_TableIDGRP_REM_SMODEL(TFIBLargeIntField * TableIDGRP_REM_SMODEL)
{
Object->TableIDGRP_REM_SMODEL=TableIDGRP_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelImpl::get_TableNAME_REM_SMODEL(void)
{
return Object->TableNAME_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_TableNAME_REM_SMODEL(TFIBWideStringField * TableNAME_REM_SMODEL)
{
Object->TableNAME_REM_SMODEL=TableNAME_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelImpl::get_TableIDBASE_REM_SMODEL(void)
{
return Object->TableIDBASE_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_TableIDBASE_REM_SMODEL(TFIBLargeIntField * TableIDBASE_REM_SMODEL)
{
Object->TableIDBASE_REM_SMODEL=TableIDBASE_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelImpl::get_ElementID_REM_SMODEL(void)
{
return Object->ElementID_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_ElementID_REM_SMODEL(TFIBLargeIntField * ElementID_REM_SMODEL)
{
Object->ElementID_REM_SMODEL=ElementID_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelImpl::get_ElementGID_REM_SMODEL(void)
{
return Object->ElementGID_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_ElementGID_REM_SMODEL(TFIBWideStringField * ElementGID_REM_SMODEL)
{
Object->ElementGID_REM_SMODEL=ElementGID_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelImpl::get_ElementIDGRP_REM_SMODEL(void)
{
return Object->ElementIDGRP_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_ElementIDGRP_REM_SMODEL(TFIBLargeIntField * ElementIDGRP_REM_SMODEL)
{
Object->ElementIDGRP_REM_SMODEL=ElementIDGRP_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelImpl::get_ElementNAME_REM_SMODEL(void)
{
return Object->ElementNAME_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_ElementNAME_REM_SMODEL(TFIBWideStringField * ElementNAME_REM_SMODEL)
{
Object->ElementNAME_REM_SMODEL=ElementNAME_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelImpl::get_ElementIDBASE_REM_SMODEL(void)
{
return Object->ElementIDBASE_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_ElementIDBASE_REM_SMODEL(TFIBLargeIntField * ElementIDBASE_REM_SMODEL)
{
Object->ElementIDBASE_REM_SMODEL=ElementIDBASE_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelImpl::get_ElementIDNOM_REM_SMODEL(void)
{
return Object->ElementIDNOM_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_ElementIDNOM_REM_SMODEL(TFIBLargeIntField * ElementIDNOM_REM_SMODEL)
{
Object->ElementIDNOM_REM_SMODEL=ElementIDNOM_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelImpl::get_ElementSTRCODE_REM_SMODEL(void)
{
return Object->ElementSTRCODE_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_ElementSTRCODE_REM_SMODEL(TFIBWideStringField * ElementSTRCODE_REM_SMODEL)
{
Object->ElementSTRCODE_REM_SMODEL=ElementSTRCODE_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelImpl::get_ElementNAMENOM(void)
{
return Object->ElementNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_ElementNAMENOM(TFIBWideStringField * ElementNAMENOM)
{
Object->ElementNAMENOM=ElementNAMENOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelImpl::get_ElementIDBRAND_REM_SMODEL(void)
{
return Object->ElementIDBRAND_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_ElementIDBRAND_REM_SMODEL(TFIBLargeIntField * ElementIDBRAND_REM_SMODEL)
{
Object->ElementIDBRAND_REM_SMODEL=ElementIDBRAND_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelImpl::get_ElementNAME_SBRAND(void)
{
return Object->ElementNAME_SBRAND;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_ElementNAME_SBRAND(TFIBWideStringField * ElementNAME_SBRAND)
{
Object->ElementNAME_SBRAND=ElementNAME_SBRAND;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelImpl::get_TableSTRCODE_REM_SMODEL(void)
{
return Object->TableSTRCODE_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_TableSTRCODE_REM_SMODEL(TFIBWideStringField * TableSTRCODE_REM_SMODEL)
{
Object->TableSTRCODE_REM_SMODEL=TableSTRCODE_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelImpl::get_TableIDBRAND_REM_SMODEL(void)
{
return Object->TableIDBRAND_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_TableIDBRAND_REM_SMODEL(TFIBLargeIntField * TableIDBRAND_REM_SMODEL)
{
Object->TableIDBRAND_REM_SMODEL=TableIDBRAND_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelImpl::get_TableIDPRMODEL_REM_SMODEL(void)
{
return Object->TableIDPRMODEL_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_TableIDPRMODEL_REM_SMODEL(TFIBLargeIntField * TableIDPRMODEL_REM_SMODEL)
{
Object->TableIDPRMODEL_REM_SMODEL=TableIDPRMODEL_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelImpl::get_TableDESCR_REM_SMODEL(void)
{
return Object->TableDESCR_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_TableDESCR_REM_SMODEL(TFIBWideStringField * TableDESCR_REM_SMODEL)
{
Object->TableDESCR_REM_SMODEL=TableDESCR_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelImpl::get_TableNAME_REM_SPRMODEL(void)
{
return Object->TableNAME_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_TableNAME_REM_SPRMODEL(TFIBWideStringField * TableNAME_REM_SPRMODEL)
{
Object->TableNAME_REM_SPRMODEL=TableNAME_REM_SPRMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelImpl::get_TableNAME_SBRAND(void)
{
return Object->TableNAME_SBRAND;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_TableNAME_SBRAND(TFIBWideStringField * TableNAME_SBRAND)
{
Object->TableNAME_SBRAND=TableNAME_SBRAND;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelImpl::get_TableIDNOM_REM_SMODEL(void)
{
return Object->TableIDNOM_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_TableIDNOM_REM_SMODEL(TFIBLargeIntField * TableIDNOM_REM_SMODEL)
{
Object->TableIDNOM_REM_SMODEL=TableIDNOM_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelImpl::get_TableNAMENOM(void)
{
return Object->TableNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_TableNAMENOM(TFIBWideStringField * TableNAMENOM)
{
Object->TableNAMENOM=TableNAMENOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelImpl::get_ElementIDPRMODEL_REM_SMODEL(void)
{
return Object->ElementIDPRMODEL_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_ElementIDPRMODEL_REM_SMODEL(TFIBLargeIntField * ElementIDPRMODEL_REM_SMODEL)
{
Object->ElementIDPRMODEL_REM_SMODEL=ElementIDPRMODEL_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelImpl::get_ElementDESCR_REM_SMODEL(void)
{
return Object->ElementDESCR_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_ElementDESCR_REM_SMODEL(TFIBWideStringField * ElementDESCR_REM_SMODEL)
{
Object->ElementDESCR_REM_SMODEL=ElementDESCR_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelImpl::get_ElementCODE_REM_SMODEL(void)
{
return Object->ElementCODE_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_ElementCODE_REM_SMODEL(TFIBWideStringField * ElementCODE_REM_SMODEL)
{
Object->ElementCODE_REM_SMODEL=ElementCODE_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelImpl::get_ElementNAME_REM_SPRMODEL(void)
{
return Object->ElementNAME_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_ElementNAME_REM_SPRMODEL(TFIBWideStringField * ElementNAME_REM_SPRMODEL)
{
Object->ElementNAME_REM_SPRMODEL=ElementNAME_REM_SPRMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelImpl::get_ElementIDMODELNEISPR_REM_SMODEL(void)
{
return Object->ElementIDMODELNEISPR_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_ElementIDMODELNEISPR_REM_SMODEL(TFIBLargeIntField * ElementIDMODELNEISPR_REM_SMODEL)
{
Object->ElementIDMODELNEISPR_REM_SMODEL=ElementIDMODELNEISPR_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelImpl::get_ElementNAME_REM_SMODEL_NEISPR(void)
{
return Object->ElementNAME_REM_SMODEL_NEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_ElementNAME_REM_SMODEL_NEISPR(TFIBWideStringField * ElementNAME_REM_SMODEL_NEISPR)
{
Object->ElementNAME_REM_SMODEL_NEISPR=ElementNAME_REM_SMODEL_NEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelImpl::get_TableCODE_REM_SMODEL(void)
{
return Object->TableCODE_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_TableCODE_REM_SMODEL(TFIBWideStringField * TableCODE_REM_SMODEL)
{
Object->TableCODE_REM_SMODEL=TableCODE_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelImpl::get_TableIDMODELNEISPR_REM_SMODEL(void)
{
return Object->TableIDMODELNEISPR_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_TableIDMODELNEISPR_REM_SMODEL(TFIBLargeIntField * TableIDMODELNEISPR_REM_SMODEL)
{
Object->TableIDMODELNEISPR_REM_SMODEL=TableIDMODELNEISPR_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelImpl::get_TableNAME_REM_SMODEL_NEISPR(void)
{
return Object->TableNAME_REM_SMODEL_NEISPR;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_TableNAME_REM_SMODEL_NEISPR(TFIBWideStringField * TableNAME_REM_SMODEL_NEISPR)
{
Object->TableNAME_REM_SMODEL_NEISPR=TableNAME_REM_SMODEL_NEISPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelImpl::get_ElementIDPRODUCER_REM_SMODEL(void)
{
return Object->ElementIDPRODUCER_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_ElementIDPRODUCER_REM_SMODEL(TFIBLargeIntField * ElementIDPRODUCER_REM_SMODEL)
{
Object->ElementIDPRODUCER_REM_SMODEL=ElementIDPRODUCER_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelImpl::get_ElementIDACTCATEGORY_REM_SMODEL(void)
{
return Object->ElementIDACTCATEGORY_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_ElementIDACTCATEGORY_REM_SMODEL(TFIBLargeIntField * ElementIDACTCATEGORY_REM_SMODEL)
{
Object->ElementIDACTCATEGORY_REM_SMODEL=ElementIDACTCATEGORY_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelImpl::get_ElementIDTYPEDEVICE_REM_SMODEL(void)
{
return Object->ElementIDTYPEDEVICE_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_ElementIDTYPEDEVICE_REM_SMODEL(TFIBLargeIntField * ElementIDTYPEDEVICE_REM_SMODEL)
{
Object->ElementIDTYPEDEVICE_REM_SMODEL=ElementIDTYPEDEVICE_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelImpl::get_ElementNAME_SPRODUCER(void)
{
return Object->ElementNAME_SPRODUCER;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_ElementNAME_SPRODUCER(TFIBWideStringField * ElementNAME_SPRODUCER)
{
Object->ElementNAME_SPRODUCER=ElementNAME_SPRODUCER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelImpl::get_ElementNAME_REM_SACTCATEGORY(void)
{
return Object->ElementNAME_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_ElementNAME_REM_SACTCATEGORY(TFIBWideStringField * ElementNAME_REM_SACTCATEGORY)
{
Object->ElementNAME_REM_SACTCATEGORY=ElementNAME_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelImpl::get_ElementNAME_REM_STYPEDEVICE(void)
{
return Object->ElementNAME_REM_STYPEDEVICE;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_ElementNAME_REM_STYPEDEVICE(TFIBWideStringField * ElementNAME_REM_STYPEDEVICE)
{
Object->ElementNAME_REM_STYPEDEVICE=ElementNAME_REM_STYPEDEVICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelImpl::get_TableIDPRODUCER_REM_SMODEL(void)
{
return Object->TableIDPRODUCER_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_TableIDPRODUCER_REM_SMODEL(TFIBLargeIntField * TableIDPRODUCER_REM_SMODEL)
{
Object->TableIDPRODUCER_REM_SMODEL=TableIDPRODUCER_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelImpl::get_TableIDACTCATEGORY_REM_SMODEL(void)
{
return Object->TableIDACTCATEGORY_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_TableIDACTCATEGORY_REM_SMODEL(TFIBLargeIntField * TableIDACTCATEGORY_REM_SMODEL)
{
Object->TableIDACTCATEGORY_REM_SMODEL=TableIDACTCATEGORY_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprModelImpl::get_TableIDTYPEDEVICE_REM_SMODEL(void)
{
return Object->TableIDTYPEDEVICE_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_TableIDTYPEDEVICE_REM_SMODEL(TFIBLargeIntField * TableIDTYPEDEVICE_REM_SMODEL)
{
Object->TableIDTYPEDEVICE_REM_SMODEL=TableIDTYPEDEVICE_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelImpl::get_TableNAME_SPRODUCER(void)
{
return Object->TableNAME_SPRODUCER;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_TableNAME_SPRODUCER(TFIBWideStringField * TableNAME_SPRODUCER)
{
Object->TableNAME_SPRODUCER=TableNAME_SPRODUCER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelImpl::get_TableNAME_REM_SACTCATEGORY(void)
{
return Object->TableNAME_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_TableNAME_REM_SACTCATEGORY(TFIBWideStringField * TableNAME_REM_SACTCATEGORY)
{
Object->TableNAME_REM_SACTCATEGORY=TableNAME_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprModelImpl::get_TableNAME_REM_STYPEDEVICE(void)
{
return Object->TableNAME_REM_STYPEDEVICE;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_TableNAME_REM_STYPEDEVICE(TFIBWideStringField * TableNAME_REM_STYPEDEVICE)
{
Object->TableNAME_REM_STYPEDEVICE=TableNAME_REM_STYPEDEVICE;
}
//---------------------------------------------------------------
__int64 TREM_DMSprModelImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TREM_DMSprModelImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
UnicodeString TREM_DMSprModelImpl::GetTextQuery(__int64 id_grp, bool all)
{
return Object->GetTextQuery(id_grp,all);
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::OpenTable(__int64 id_grp, bool all)
{
return Object->OpenTable(id_grp,all);
}
//---------------------------------------------------------------
int TREM_DMSprModelImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprModelImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TREM_DMSprModelImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMSprModelImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
void TREM_DMSprModelImpl::ChancheGrp(__int64 id_new_grp, __int64 id_el)
{
return Object->ChancheGrp(id_new_grp, id_el);
}
//---------------------------------------------------------------
__int64 TREM_DMSprModelImpl::GetIDElement(UnicodeString gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
UnicodeString TREM_DMSprModelImpl::GetGIDElement(__int64 id)
{
return Object->GetGIDElement(id);
}
//---------------------------------------------------------------
__int64 TREM_DMSprModelImpl::GetIdGrpNom(__int64 id)
{
return Object->GetIdGrpNom(id);
}
//---------------------------------------------------------------
__int64 TREM_DMSprModelImpl::FindPoNom(__int64 id_nom)
{
return Object->FindPoNom(id_nom);
}
//---------------------------------------------------------------
