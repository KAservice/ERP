#include <vcl.h>
#pragma hdrstop


#include "UDMSprSezKFImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprSezKFImpl::TDMSprSezKFImpl()           
{                                            
Object=new TDMSprSezKF(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprSezKFImpl::~TDMSprSezKFImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprSezKFImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprSezKFImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprSezKF)                        
   {                                                                     
   *ppv=static_cast<IDMSprSezKF*> (this);                                
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
int TDMSprSezKFImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprSezKFImpl::kanRelease(void)                                  
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
int  TDMSprSezKFImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprSezKFImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprSezKFImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprSezKFImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprSezKFImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMSprSezKFImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprSezKFImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprSezKFImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprSezKFImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprSezKFImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprSezKFImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprSezKFImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprSezKFImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprSezKFImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprSezKFImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprSezKFImpl::get_TableMONTH_SSEZKF(void)
{
return Object->TableMONTH_SSEZKF;
}
//---------------------------------------------------------------
void TDMSprSezKFImpl::set_TableMONTH_SSEZKF(TFIBIntegerField * TableMONTH_SSEZKF)
{
Object->TableMONTH_SSEZKF=TableMONTH_SSEZKF;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprSezKFImpl::get_TableVALUE_SSEZKF(void)
{
return Object->TableVALUE_SSEZKF;
}
//---------------------------------------------------------------
void TDMSprSezKFImpl::set_TableVALUE_SSEZKF(TFIBBCDField * TableVALUE_SSEZKF)
{
Object->TableVALUE_SSEZKF=TableVALUE_SSEZKF;
}
//---------------------------------------------------------------
TIntegerField * TDMSprSezKFImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprSezKFImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprSezKFImpl::get_TableID_SSEZKF(void)
{
return Object->TableID_SSEZKF;
}
//---------------------------------------------------------------
void TDMSprSezKFImpl::set_TableID_SSEZKF(TFIBBCDField * TableID_SSEZKF)
{
Object->TableID_SSEZKF=TableID_SSEZKF;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprSezKFImpl::get_TableIDNOM_SSEZKF(void)
{
return Object->TableIDNOM_SSEZKF;
}
//---------------------------------------------------------------
void TDMSprSezKFImpl::set_TableIDNOM_SSEZKF(TFIBBCDField * TableIDNOM_SSEZKF)
{
Object->TableIDNOM_SSEZKF=TableIDNOM_SSEZKF;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSezKFImpl::get_TableGID_SSEZKF(void)
{
return Object->TableGID_SSEZKF;
}
//---------------------------------------------------------------
void TDMSprSezKFImpl::set_TableGID_SSEZKF(TFIBWideStringField * TableGID_SSEZKF)
{
Object->TableGID_SSEZKF=TableGID_SSEZKF;
}
//---------------------------------------------------------------
__int64 TDMSprSezKFImpl::get_IdNom(void)
{
return Object->IdNom;
}
//---------------------------------------------------------------
void TDMSprSezKFImpl::set_IdNom(__int64 IdNom)
{
Object->IdNom=IdNom;
}
//---------------------------------------------------------------
float TDMSprSezKFImpl::get_KolEdProd(void)
{
return Object->KolEdProd;
}
//---------------------------------------------------------------
void TDMSprSezKFImpl::set_KolEdProd(float KolEdProd)
{
Object->KolEdProd=KolEdProd;
}
//---------------------------------------------------------------
float TDMSprSezKFImpl::get_KFEdProd(void)
{
return Object->KFEdProd;
}
//---------------------------------------------------------------
void TDMSprSezKFImpl::set_KFEdProd(float KFEdProd)
{
Object->KFEdProd=KFEdProd;
}
//---------------------------------------------------------------
void TDMSprSezKFImpl::OpenTable(__int64 Nom)
{
return Object->OpenTable(Nom);
}
//---------------------------------------------------------------
void TDMSprSezKFImpl::NewElement(__int64 Nom)
{
return Object->NewElement(Nom);
}
//---------------------------------------------------------------
void TDMSprSezKFImpl::DeleteElement()
{
return Object->DeleteElement();
}
//---------------------------------------------------------------
void TDMSprSezKFImpl::SaveIsmen()
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
void TDMSprSezKFImpl::CancelIsmen()
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
