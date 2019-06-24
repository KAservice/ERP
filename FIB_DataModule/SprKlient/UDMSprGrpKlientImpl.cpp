#include <vcl.h>
#pragma hdrstop


#include "UDMSprGrpKlientImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprGrpKlientImpl::TDMSprGrpKlientImpl()           
{                                            
Object=new TDMSprGrpKlient(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprGrpKlientImpl::~TDMSprGrpKlientImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprGrpKlientImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprGrpKlientImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprGrpKlient)                        
   {                                                                     
   *ppv=static_cast<IDMSprGrpKlient*> (this);                                
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
int TDMSprGrpKlientImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprGrpKlientImpl::kanRelease(void)                                  
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
int  TDMSprGrpKlientImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprGrpKlientImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprGrpKlientImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprGrpKlientImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprGrpKlientImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMSprGrpKlientImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprGrpKlientImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprGrpKlientImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprGrpKlientImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprGrpKlientImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprGrpKlientImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprGrpKlientImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprGrpKlientImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprGrpKlientImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprGrpKlientImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprGrpKlientImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprGrpKlientImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprGrpKlientImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprGrpKlientImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMSprGrpKlientImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprGrpKlientImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrpKlientImpl::get_TableIDGRPKL(void)
{
return Object->TableIDGRPKL;
}
//---------------------------------------------------------------
void TDMSprGrpKlientImpl::set_TableIDGRPKL(TFIBBCDField * TableIDGRPKL)
{
Object->TableIDGRPKL=TableIDGRPKL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrpKlientImpl::get_TableGRPKL(void)
{
return Object->TableGRPKL;
}
//---------------------------------------------------------------
void TDMSprGrpKlientImpl::set_TableGRPKL(TFIBBCDField * TableGRPKL)
{
Object->TableGRPKL=TableGRPKL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrpKlientImpl::get_ElementIDGRPKL(void)
{
return Object->ElementIDGRPKL;
}
//---------------------------------------------------------------
void TDMSprGrpKlientImpl::set_ElementIDGRPKL(TFIBBCDField * ElementIDGRPKL)
{
Object->ElementIDGRPKL=ElementIDGRPKL;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrpKlientImpl::get_ElementGRPKL(void)
{
return Object->ElementGRPKL;
}
//---------------------------------------------------------------
void TDMSprGrpKlientImpl::set_ElementGRPKL(TFIBBCDField * ElementGRPKL)
{
Object->ElementGRPKL=ElementGRPKL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpKlientImpl::get_TableNAMEGRPKL(void)
{
return Object->TableNAMEGRPKL;
}
//---------------------------------------------------------------
void TDMSprGrpKlientImpl::set_TableNAMEGRPKL(TFIBWideStringField * TableNAMEGRPKL)
{
Object->TableNAMEGRPKL=TableNAMEGRPKL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpKlientImpl::get_TableGID_SGRPKL(void)
{
return Object->TableGID_SGRPKL;
}
//---------------------------------------------------------------
void TDMSprGrpKlientImpl::set_TableGID_SGRPKL(TFIBWideStringField * TableGID_SGRPKL)
{
Object->TableGID_SGRPKL=TableGID_SGRPKL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpKlientImpl::get_ElementNAMEGRPKL(void)
{
return Object->ElementNAMEGRPKL;
}
//---------------------------------------------------------------
void TDMSprGrpKlientImpl::set_ElementNAMEGRPKL(TFIBWideStringField * ElementNAMEGRPKL)
{
Object->ElementNAMEGRPKL=ElementNAMEGRPKL;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpKlientImpl::get_ElementGID_SGRPKL(void)
{
return Object->ElementGID_SGRPKL;
}
//---------------------------------------------------------------
void TDMSprGrpKlientImpl::set_ElementGID_SGRPKL(TFIBWideStringField * ElementGID_SGRPKL)
{
Object->ElementGID_SGRPKL=ElementGID_SGRPKL;
}
//---------------------------------------------------------------
bool TDMSprGrpKlientImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprGrpKlientImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
void TDMSprGrpKlientImpl::NewElement(__int64 IdGrp)
{
return Object->NewElement(IdGrp);
}
//---------------------------------------------------------------
bool TDMSprGrpKlientImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprGrpKlientImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
