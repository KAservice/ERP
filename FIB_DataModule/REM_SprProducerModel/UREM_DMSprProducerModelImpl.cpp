#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprProducerModelImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprProducerModelImpl::TREM_DMSprProducerModelImpl()           
{                                            
Object=new TREM_DMSprProducerModel(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprProducerModelImpl::~TREM_DMSprProducerModelImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprProducerModelImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprProducerModel)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprProducerModel*> (this);                                
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
int TREM_DMSprProducerModelImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprProducerModelImpl::kanRelease(void)                                  
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
int  TREM_DMSprProducerModelImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprProducerModelImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprProducerModelImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprProducerModelImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprProducerModelImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprProducerModel
TDataSource * TREM_DMSprProducerModelImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprProducerModelImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprProducerModelImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprProducerModelImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprProducerModelImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMSprProducerModelImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TDataSource * TREM_DMSprProducerModelImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelImpl::get_TableID_REM_SPRMODEL(void)
{
return Object->TableID_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_TableID_REM_SPRMODEL(TFIBLargeIntField * TableID_REM_SPRMODEL)
{
Object->TableID_REM_SPRMODEL=TableID_REM_SPRMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelImpl::get_TableCODE_REM_SPRMODEL(void)
{
return Object->TableCODE_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_TableCODE_REM_SPRMODEL(TFIBWideStringField * TableCODE_REM_SPRMODEL)
{
Object->TableCODE_REM_SPRMODEL=TableCODE_REM_SPRMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelImpl::get_TableNAME_REM_SPRMODEL(void)
{
return Object->TableNAME_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_TableNAME_REM_SPRMODEL(TFIBWideStringField * TableNAME_REM_SPRMODEL)
{
Object->TableNAME_REM_SPRMODEL=TableNAME_REM_SPRMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelImpl::get_ElementID_REM_SPRMODEL(void)
{
return Object->ElementID_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_ElementID_REM_SPRMODEL(TFIBLargeIntField * ElementID_REM_SPRMODEL)
{
Object->ElementID_REM_SPRMODEL=ElementID_REM_SPRMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelImpl::get_ElementIDBASE_REM_SPRMODEL(void)
{
return Object->ElementIDBASE_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_ElementIDBASE_REM_SPRMODEL(TFIBLargeIntField * ElementIDBASE_REM_SPRMODEL)
{
Object->ElementIDBASE_REM_SPRMODEL=ElementIDBASE_REM_SPRMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelImpl::get_ElementGID_REM_SPRMODEL(void)
{
return Object->ElementGID_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_ElementGID_REM_SPRMODEL(TFIBWideStringField * ElementGID_REM_SPRMODEL)
{
Object->ElementGID_REM_SPRMODEL=ElementGID_REM_SPRMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelImpl::get_ElementIDPR_REM_SPRMODEL(void)
{
return Object->ElementIDPR_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_ElementIDPR_REM_SPRMODEL(TFIBLargeIntField * ElementIDPR_REM_SPRMODEL)
{
Object->ElementIDPR_REM_SPRMODEL=ElementIDPR_REM_SPRMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelImpl::get_ElementIDGRP_REM_SPRMODEL(void)
{
return Object->ElementIDGRP_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_ElementIDGRP_REM_SPRMODEL(TFIBLargeIntField * ElementIDGRP_REM_SPRMODEL)
{
Object->ElementIDGRP_REM_SPRMODEL=ElementIDGRP_REM_SPRMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelImpl::get_ElementIDMODEL_REM_SPRMODEL(void)
{
return Object->ElementIDMODEL_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_ElementIDMODEL_REM_SPRMODEL(TFIBLargeIntField * ElementIDMODEL_REM_SPRMODEL)
{
Object->ElementIDMODEL_REM_SPRMODEL=ElementIDMODEL_REM_SPRMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelImpl::get_ElementCODE_REM_SPRMODEL(void)
{
return Object->ElementCODE_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_ElementCODE_REM_SPRMODEL(TFIBWideStringField * ElementCODE_REM_SPRMODEL)
{
Object->ElementCODE_REM_SPRMODEL=ElementCODE_REM_SPRMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelImpl::get_ElementNAME_REM_SPRMODEL(void)
{
return Object->ElementNAME_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_ElementNAME_REM_SPRMODEL(TFIBWideStringField * ElementNAME_REM_SPRMODEL)
{
Object->ElementNAME_REM_SPRMODEL=ElementNAME_REM_SPRMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelImpl::get_ElementNAME_REM_SMODEL(void)
{
return Object->ElementNAME_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_ElementNAME_REM_SMODEL(TFIBWideStringField * ElementNAME_REM_SMODEL)
{
Object->ElementNAME_REM_SMODEL=ElementNAME_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelImpl::get_TableNAME_REM_SMODEL(void)
{
return Object->TableNAME_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_TableNAME_REM_SMODEL(TFIBWideStringField * TableNAME_REM_SMODEL)
{
Object->TableNAME_REM_SMODEL=TableNAME_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelImpl::get_TableIDPR_REM_SPRMODEL(void)
{
return Object->TableIDPR_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_TableIDPR_REM_SPRMODEL(TFIBLargeIntField * TableIDPR_REM_SPRMODEL)
{
Object->TableIDPR_REM_SPRMODEL=TableIDPR_REM_SPRMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelImpl::get_TableIDGRP_REM_SPRMODEL(void)
{
return Object->TableIDGRP_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_TableIDGRP_REM_SPRMODEL(TFIBLargeIntField * TableIDGRP_REM_SPRMODEL)
{
Object->TableIDGRP_REM_SPRMODEL=TableIDGRP_REM_SPRMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelImpl::get_TableNAME_SBRAND(void)
{
return Object->TableNAME_SBRAND;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_TableNAME_SBRAND(TFIBWideStringField * TableNAME_SBRAND)
{
Object->TableNAME_SBRAND=TableNAME_SBRAND;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelImpl::get_TableNAME_SPRODUCER(void)
{
return Object->TableNAME_SPRODUCER;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_TableNAME_SPRODUCER(TFIBWideStringField * TableNAME_SPRODUCER)
{
Object->TableNAME_SPRODUCER=TableNAME_SPRODUCER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelImpl::get_TableNAME_REM_SACTCATEGORY(void)
{
return Object->TableNAME_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_TableNAME_REM_SACTCATEGORY(TFIBWideStringField * TableNAME_REM_SACTCATEGORY)
{
Object->TableNAME_REM_SACTCATEGORY=TableNAME_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelImpl::get_TableNAME_REM_STYPEDEVICE(void)
{
return Object->TableNAME_REM_STYPEDEVICE;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_TableNAME_REM_STYPEDEVICE(TFIBWideStringField * TableNAME_REM_STYPEDEVICE)
{
Object->TableNAME_REM_STYPEDEVICE=TableNAME_REM_STYPEDEVICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelImpl::get_ElementIDBRAND_REM_SPRMODEL(void)
{
return Object->ElementIDBRAND_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_ElementIDBRAND_REM_SPRMODEL(TFIBLargeIntField * ElementIDBRAND_REM_SPRMODEL)
{
Object->ElementIDBRAND_REM_SPRMODEL=ElementIDBRAND_REM_SPRMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelImpl::get_ElementIDACTCATEGORY_REM_SPRMODEL(void)
{
return Object->ElementIDACTCATEGORY_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_ElementIDACTCATEGORY_REM_SPRMODEL(TFIBLargeIntField * ElementIDACTCATEGORY_REM_SPRMODEL)
{
Object->ElementIDACTCATEGORY_REM_SPRMODEL=ElementIDACTCATEGORY_REM_SPRMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprProducerModelImpl::get_ElementIDTYPEDEVICE_REM_SPRMODEL(void)
{
return Object->ElementIDTYPEDEVICE_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_ElementIDTYPEDEVICE_REM_SPRMODEL(TFIBLargeIntField * ElementIDTYPEDEVICE_REM_SPRMODEL)
{
Object->ElementIDTYPEDEVICE_REM_SPRMODEL=ElementIDTYPEDEVICE_REM_SPRMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelImpl::get_ElementNAME_SBRAND(void)
{
return Object->ElementNAME_SBRAND;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_ElementNAME_SBRAND(TFIBWideStringField * ElementNAME_SBRAND)
{
Object->ElementNAME_SBRAND=ElementNAME_SBRAND;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelImpl::get_ElementNAME_SPRODUCER(void)
{
return Object->ElementNAME_SPRODUCER;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_ElementNAME_SPRODUCER(TFIBWideStringField * ElementNAME_SPRODUCER)
{
Object->ElementNAME_SPRODUCER=ElementNAME_SPRODUCER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelImpl::get_ElementNAME_REM_SACTCATEGORY(void)
{
return Object->ElementNAME_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_ElementNAME_REM_SACTCATEGORY(TFIBWideStringField * ElementNAME_REM_SACTCATEGORY)
{
Object->ElementNAME_REM_SACTCATEGORY=ElementNAME_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprProducerModelImpl::get_ElementNAME_REM_STYPEDEVICE(void)
{
return Object->ElementNAME_REM_STYPEDEVICE;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_ElementNAME_REM_STYPEDEVICE(TFIBWideStringField * ElementNAME_REM_STYPEDEVICE)
{
Object->ElementNAME_REM_STYPEDEVICE=ElementNAME_REM_STYPEDEVICE;
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerModelImpl::get_IdGroupElement(void)
{
return Object->IdGroupElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_IdGroupElement(__int64 IdGroupElement)
{
Object->IdGroupElement=IdGroupElement;
}
//---------------------------------------------------------------
__int64 TREM_DMSprProducerModelImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TREM_DMSprProducerModelImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::OpenTable(__int64 id_group_element, __int64 id_grp, bool all)
{
return Object->OpenTable(id_group_element,id_grp,all);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerModelImpl::NewElement(__int64 id_group_element, __int64 id_grp)
{
return Object->NewElement(id_group_element,id_grp);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerModelImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerModelImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
bool TREM_DMSprProducerModelImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TREM_DMSprProducerModelImpl::ChancheGrp(__int64 id_new_grp,__int64 id_element)
{
return Object->ChancheGrp(id_new_grp,id_element);
}
//---------------------------------------------------------------
