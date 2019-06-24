#include <vcl.h>
#pragma hdrstop


#include "UDMSprImportEdImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprImportEdImpl::TDMSprImportEdImpl()           
{                                            
Object=new TDMSprImportEd(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprImportEdImpl::~TDMSprImportEdImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprImportEdImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprImportEdImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprImportEd)                        
   {                                                                     
   *ppv=static_cast<IDMSprImportEd*> (this);                                
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
int TDMSprImportEdImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprImportEdImpl::kanRelease(void)                                  
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

//---------------------------------------------------------------
int  TDMSprImportEdImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprImportEdImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprImportEdImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprImportEdImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprImportEdImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMSprImportEdImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprImportEdImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprImportEdImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprImportEdImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprImportEdImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprImportEdImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprImportEdImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprImportEdImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprImportEdImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprImportEdImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprImportEdImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprImportEdImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprImportEdImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprImportEdImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprImportEdImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprImportEdImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprImportEdImpl::get_TableID_SIMPORTED(void)
{
return Object->TableID_SIMPORTED;
}
//---------------------------------------------------------------
void TDMSprImportEdImpl::set_TableID_SIMPORTED(TFIBBCDField * TableID_SIMPORTED)
{
Object->TableID_SIMPORTED=TableID_SIMPORTED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprImportEdImpl::get_TableIDBASE_SIMPORTED(void)
{
return Object->TableIDBASE_SIMPORTED;
}
//---------------------------------------------------------------
void TDMSprImportEdImpl::set_TableIDBASE_SIMPORTED(TFIBBCDField * TableIDBASE_SIMPORTED)
{
Object->TableIDBASE_SIMPORTED=TableIDBASE_SIMPORTED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprImportEdImpl::get_TableIDNOM_SIMPORTED(void)
{
return Object->TableIDNOM_SIMPORTED;
}
//---------------------------------------------------------------
void TDMSprImportEdImpl::set_TableIDNOM_SIMPORTED(TFIBBCDField * TableIDNOM_SIMPORTED)
{
Object->TableIDNOM_SIMPORTED=TableIDNOM_SIMPORTED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprImportEdImpl::get_TableIDKLIENT_SIMPORTED(void)
{
return Object->TableIDKLIENT_SIMPORTED;
}
//---------------------------------------------------------------
void TDMSprImportEdImpl::set_TableIDKLIENT_SIMPORTED(TFIBBCDField * TableIDKLIENT_SIMPORTED)
{
Object->TableIDKLIENT_SIMPORTED=TableIDKLIENT_SIMPORTED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprImportEdImpl::get_TableIDED_SIMPORTED(void)
{
return Object->TableIDED_SIMPORTED;
}
//---------------------------------------------------------------
void TDMSprImportEdImpl::set_TableIDED_SIMPORTED(TFIBBCDField * TableIDED_SIMPORTED)
{
Object->TableIDED_SIMPORTED=TableIDED_SIMPORTED;
}
//---------------------------------------------------------------
TIntegerField * TDMSprImportEdImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprImportEdImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprImportEdImpl::get_ElementID_SIMPORTED(void)
{
return Object->ElementID_SIMPORTED;
}
//---------------------------------------------------------------
void TDMSprImportEdImpl::set_ElementID_SIMPORTED(TFIBBCDField * ElementID_SIMPORTED)
{
Object->ElementID_SIMPORTED=ElementID_SIMPORTED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprImportEdImpl::get_ElementIDBASE_SIMPORTED(void)
{
return Object->ElementIDBASE_SIMPORTED;
}
//---------------------------------------------------------------
void TDMSprImportEdImpl::set_ElementIDBASE_SIMPORTED(TFIBBCDField * ElementIDBASE_SIMPORTED)
{
Object->ElementIDBASE_SIMPORTED=ElementIDBASE_SIMPORTED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprImportEdImpl::get_ElementIDNOM_SIMPORTED(void)
{
return Object->ElementIDNOM_SIMPORTED;
}
//---------------------------------------------------------------
void TDMSprImportEdImpl::set_ElementIDNOM_SIMPORTED(TFIBBCDField * ElementIDNOM_SIMPORTED)
{
Object->ElementIDNOM_SIMPORTED=ElementIDNOM_SIMPORTED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprImportEdImpl::get_ElementIDKLIENT_SIMPORTED(void)
{
return Object->ElementIDKLIENT_SIMPORTED;
}
//---------------------------------------------------------------
void TDMSprImportEdImpl::set_ElementIDKLIENT_SIMPORTED(TFIBBCDField * ElementIDKLIENT_SIMPORTED)
{
Object->ElementIDKLIENT_SIMPORTED=ElementIDKLIENT_SIMPORTED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprImportEdImpl::get_ElementIDED_SIMPORTED(void)
{
return Object->ElementIDED_SIMPORTED;
}
//---------------------------------------------------------------
void TDMSprImportEdImpl::set_ElementIDED_SIMPORTED(TFIBBCDField * ElementIDED_SIMPORTED)
{
Object->ElementIDED_SIMPORTED=ElementIDED_SIMPORTED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprImportEdImpl::get_TableBARCODE_SIMPORTED(void)
{
return Object->TableBARCODE_SIMPORTED;
}
//---------------------------------------------------------------
void TDMSprImportEdImpl::set_TableBARCODE_SIMPORTED(TFIBWideStringField * TableBARCODE_SIMPORTED)
{
Object->TableBARCODE_SIMPORTED=TableBARCODE_SIMPORTED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprImportEdImpl::get_TableCODE_SIMPORTED(void)
{
return Object->TableCODE_SIMPORTED;
}
//---------------------------------------------------------------
void TDMSprImportEdImpl::set_TableCODE_SIMPORTED(TFIBWideStringField * TableCODE_SIMPORTED)
{
Object->TableCODE_SIMPORTED=TableCODE_SIMPORTED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprImportEdImpl::get_TableNAME_SIMPORTED(void)
{
return Object->TableNAME_SIMPORTED;
}
//---------------------------------------------------------------
void TDMSprImportEdImpl::set_TableNAME_SIMPORTED(TFIBWideStringField * TableNAME_SIMPORTED)
{
Object->TableNAME_SIMPORTED=TableNAME_SIMPORTED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprImportEdImpl::get_ElementBARCODE_SIMPORTED(void)
{
return Object->ElementBARCODE_SIMPORTED;
}
//---------------------------------------------------------------
void TDMSprImportEdImpl::set_ElementBARCODE_SIMPORTED(TFIBWideStringField * ElementBARCODE_SIMPORTED)
{
Object->ElementBARCODE_SIMPORTED=ElementBARCODE_SIMPORTED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprImportEdImpl::get_ElementCODE_SIMPORTED(void)
{
return Object->ElementCODE_SIMPORTED;
}
//---------------------------------------------------------------
void TDMSprImportEdImpl::set_ElementCODE_SIMPORTED(TFIBWideStringField * ElementCODE_SIMPORTED)
{
Object->ElementCODE_SIMPORTED=ElementCODE_SIMPORTED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprImportEdImpl::get_ElementNAME_SIMPORTED(void)
{
return Object->ElementNAME_SIMPORTED;
}
//---------------------------------------------------------------
void TDMSprImportEdImpl::set_ElementNAME_SIMPORTED(TFIBWideStringField * ElementNAME_SIMPORTED)
{
Object->ElementNAME_SIMPORTED=ElementNAME_SIMPORTED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprImportEdImpl::get_ElementNAMEKLIENT(void)
{
return Object->ElementNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMSprImportEdImpl::set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT)
{
Object->ElementNAMEKLIENT=ElementNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMSprImportEdImpl::OpenTable(__int64 id_ed)
{
return Object->OpenTable(id_ed);
}
//---------------------------------------------------------------
int TDMSprImportEdImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TDMSprImportEdImpl::NewElement(__int64 id_nom,__int64 id_ed)
{
return Object->NewElement(id_nom,id_ed);
}
//---------------------------------------------------------------
bool TDMSprImportEdImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprImportEdImpl::DeleteElement(__int64 dd)
{
return Object->DeleteElement(dd);
}
//---------------------------------------------------------------
